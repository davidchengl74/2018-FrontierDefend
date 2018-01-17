#include "pch.h"
#include "../../GameCore/CGame.h"
extern "C" void PurchaseProduct(const char *indentify);
extern "C" void IapRestore();
#if defined (ANDROID_OS)
extern "C" void			PurchaseProductWithType(const char *indentify, int type = 1);
#endif

void TDGame::IngameMenuRender(float x, float y, int opac)
{

	G()->SetOpacity(_ingame_menu_fill_opac);
	G()->SetColor(0xff000000);
	G()->FillFullScreen(true);
	G()->SetOpacity(opac);
	int boardframe = 236;
	if (_ingame_menu_type == MENU_INGAME_BUTTON_GATE)
	{
		//CastleInfoRender(x, y, opac);
	}
	else if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		HeroDeployRender(x, y, opac);
		boardframe = 57;
	}
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), boardframe, x, y + _ingame_menu_scrolly);
	int my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(boardframe);
	switch (_ingame_menu_type)
	{
	case MENU_INGAME_BUTTON_GATE:
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 37, x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_GATE].Render(x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_GATE].Update();
		break;
	case MENU_INGAME_BUTTON_HEROES:
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 39, x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_HEROES].Render(x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_HEROES].Update();
		break;
	case MENU_INGAME_BUTTON_RELICS:
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 41, x, y - my + _ingame_menu_scrolly);
		break;
	case MENU_INGAME_BUTTON_SHOP:
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 43, x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_SHOP].Render(x, y - my + _ingame_menu_scrolly);
		_notify_new[MENU_INGAME_BUTTON_SHOP].Update();
		break;
	default:
		break;
	}
	int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(boardframe, 0);
	G()->SetClip(0, menu_my + 19 + _ingame_menu_scrolly, k_SCREEN_WIDTH, my - 81);
	for (int i = 0; i < _ingame_menu_num_item; i++)
	{
		_menu_info_arr[i].Render(0, _ingame_menu_scrolly + y + menu_my - _ingame_menu_scroll.GetCurrent());
	}
	G()->ClearClip();
#if !DISABLE_ONLINE_FEATURE
    if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		if (!_user._has_pass_invitation && _user._tutorial_completed && HasEventAvailable(EVENT_TYPE_AVAILABLE))
		{
			int input_mx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(41, 0) + 3;
			int input_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(41, 0) + 10;
			InputCodeRender(input_mx, _ingame_menu_scrolly + y + input_my - my);
		}
	}
#endif
	IapRender(-_point_o.X, _point_o.Y);
	if (_user._tutorial_step >= TUTORIAL_STEP_BUILD_TOWER)
	{
		TutorialRender(0, 0);
	}
}
void TDGame::IngameMenuUpdate()
{
	if (_sub_state == k_INIT)
	{
#if defined(_WINDOWS)
		sprintf(_user._ivitation_code, "WINDOW");
#endif
		IngameMenuInit();
#if defined (_WINDOWS)
		GAME()->_serverThread._isNetworkAvailable = true;
#endif
			for (int i = 0; i < INPUT_CODE_BUTTON_NUM; i++)
			{
				_input_code_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
				_input_code_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 153 + i * 4);
				_input_code_button[i].SetPos(0,0);
			}
		_ingame_menu_frame_idle = 15;
		_has_watched_ads = false;
		_notify_new[_ingame_menu_type].Disable();
		_sub_state = k_LOOP;
	}
	if (GAME()->_purchase_procesing_opac > 0)
	{
		return;
	}
#if ADD_ADVERT
	if (GAME()->_advert.HasPopup())
	{
		return;
	}
#endif
	if (_ingame_menu_close)
	{
		int mkhight = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(236);
		if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
		{
			mkhight = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(57);
		}
		if (_ingame_menu_scrolly < mkhight)
		{
			_ingame_menu_scrolly += _ingame_menu_scroll_speed;
		}
		if (_ingame_menu_scrolly >= mkhight)
		{
			_ingame_menu_scrolly = mkhight;
			SetState(k_GS_PLAYGAME);
			_sub_state = k_LOOP;
            ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
			ClearAllTouchUp(TOUCH_TYPE_INGAME);
			ClearAllTouchUp(TOUCH_TYPE_MENU_INFO);
			
			
			_user.UserDataSave();
		}
		_ingame_menu_fill_opac -= 7;
		if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
		{
			int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
			for (int i = 0; i < totalhero; i++)
			{
				if (_hero_inbattle_arr[i]._is_new)
				{
					_hero_inbattle_arr[i]._is_new = false;
				}
			}
			if (_notify_new[MENU_INGAME_BUTTON_HEROES]._state == NOTIFY_STATE_ACTIVE)
			{
				_notify_new[MENU_INGAME_BUTTON_HEROES].Disable();
			}
		}
	}
	else
	{
		if (_ingame_menu_scrolly > 0)
		{
			_ingame_menu_scrolly -= _ingame_menu_scroll_speed;
		}
		if (_ingame_menu_scrolly <= 0)
		{
			_ingame_menu_scrolly = 0;
			if (!_user._tutorial_completed)
			{
				if (_user._tutorial_step == TUTORIAL_STEP_MENU_CASTLE)
				{
					_tutorial_step = TUTORIAL_STEP_BUILD_TOWER;
				}
				else if (_user._tutorial_step == TUTORIAL_STEP_MENU_HERO)
				{
					_tutorial_step = TUTORIAL_STEP_BUY_HERO;
				}
			}
			else
			{
				if (_user._tutorial_step == TUTORIAL_STEP_BUY_RELIC)
				{
					_tutorial_step = TUTORIAL_STEP_BUY_RELIC;
				}
			}
		}
		_ingame_menu_fill_opac += 7;
		if (_ingame_menu_fill_opac > 75)
		{
			_ingame_menu_fill_opac = 75;
		}
	}
	if (_rate_us_time != -1)
	{
		PDEBUG("_rate_us_type = %d", _rate_us_type);
		if (_rate_us_type == RATE_US_TYPE_TW_FOLLOW)
		{
			if (_rate_us_time <= time(NULL))
			{
				if (!_dialogMng.isOpenDialog())
				{
					_rate_us_time = -1;
					char text[256];
					sprintf(text, "%d :", TW_FOLLOW_REWARD);
					GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
					_dialogMng.Add(DIALOG_CONTEXT_TW_FOLLOW, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
				}
			}
			else
			{
				_rate_us_time = -1;
			}

		}
		else if (_rate_us_type == RATE_US_TYPE_FB_LIKE)
		{
			if (_rate_us_time <= time(NULL))
			{
				if (!_dialogMng.isOpenDialog())
				{
					_rate_us_time = -1;
					char text[256];
					sprintf(text, "%d :", FB_LIKE_REWARD);
					GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
					_dialogMng.Add(DIALOG_CONTEXT_FB_LIKE, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
				}
#if defined (ANDROID_OS)
				_rate_us_time = -1;
#endif

			}
#if !defined (ANDROID_OS)
			else
			{
				_rate_us_time = -1;
			}
#endif
		}
	}
	TutorialUpdate();
	if (_ingame_menu_type == MENU_INGAME_BUTTON_GATE)
	{
		CastleInfoUpdate();
	}
	else if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		HeroDeployUpdate();
	}
	if (_ingame_menu_frame_idle>0)
	{
		_ingame_menu_frame_idle--;
	}
	if (_ingame_menu_scrolly != 0 )
	{
		return;
	}
	
	if (_current_state == k_GS_INGAME_MENU)
	{
		IapUpdate();
	}
	bool has_touch_input = false;
#if !DISABLE_ONLINE_FEATURE
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		if (!_user._has_pass_invitation && _user._tutorial_completed && HasEventAvailable(EVENT_TYPE_AVAILABLE))
		{
			has_touch_input = InputCodeUpdateTouch();
		}
	}
#endif
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		if (!HeroDeployUpdateTouch())
		{
			if (_user._tutorial_completed)
			{
				if (!has_touch_input)
				{
					IngameMenuUpdateTouch();
				}
			}
		}
	}
	else
	{
		if (_user._tutorial_completed)
		{
			if (!has_touch_input)
			{
				if (_ingame_menu_type == MENU_INGAME_BUTTON_RELICS)
				{
					if (_user._tutorial_step != TUTORIAL_STEP_BUY_RELIC)
					{
						IngameMenuUpdateTouch();
					}
				}
				else
				{
					IngameMenuUpdateTouch();
				}
				
			}
		}
		else
		{
			if (_tutorial_step == TUTORIAL_STEP_FREE)
			{
				if (!has_touch_input)
				{
					IngameMenuUpdateTouch();
				}
			}
		}
	}

	for (int i = 0; i < _ingame_menu_num_item; i++)
	{
		_menu_info_arr[i].Update();
	}
	if (_ingame_menu_frame_idle > 0)
	{
		return;
	}
	
	int boardframe = 236;
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		boardframe = 57;
	}
	if (_ingame_menu_scroll._isScroll )
	{
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			
			int x = 0;
			int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(boardframe, 0);
			int w = k_SCREEN_WIDTH;
			int h = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(boardframe);
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DRAG)
				{

					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						float deltaY = TOUCHS(i)->y - _ingame_menu_scroll._last_touch_y;
						_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
						_ingame_menu_scroll.AddOffset(-deltaY);
						_ingame_menu_scroll.ValidateRangeExt();
						_ingame_menu_scroll.ForceToTarget();
						_ingame_menu_scroll.SetState(1);
						if (_ingame_menu_scroll._offset_y < CMath::ABSOLUTE_VALUE(deltaY))
						{
							_ingame_menu_scroll._offset_y = CMath::ABSOLUTE_VALUE(deltaY);
						}
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						_ingame_menu_scroll_touch_id = -1;
						if (_ingame_menu_scroll._offset_y > 2)
						{
							_ingame_menu_scroll._offset_y = 0;
						}
						if (!_ingame_menu_scroll._collided)
						{
							_ingame_menu_scroll.End();
						}
						_ingame_menu_scroll.SetState(2);
						_ingame_menu_scroll._isScroll = false;
						_ingame_menu_scroll._touch_id = -1;
					}
				}
			}
			else
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						_ingame_menu_scroll_touch_id = -1;
						if (_ingame_menu_scroll._offset_y > 2)
						{
							_ingame_menu_scroll._offset_y = 0;
						}
						if (!_ingame_menu_scroll._collided)
						{
							_ingame_menu_scroll.End();
						}
						_ingame_menu_scroll.SetState(2);
						_ingame_menu_scroll._isScroll = false;
						_ingame_menu_scroll._touch_id = -1;
					}
				}
			}
		}
	}
	else
	{
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			int x = 0;
			int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(boardframe, 0);
			int w = k_SCREEN_WIDTH;
			int h = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(boardframe);
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{

					if (_ingame_menu_scroll._touch_id == -1)
					{
						_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
						_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						if (_ingame_menu_scroll._isScroll)
						{
							float deltaY = TOUCHS(i)->y - _ingame_menu_scroll._last_touch_y;
							_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
							_ingame_menu_scroll.AddOffset(-deltaY);
							_ingame_menu_scroll.ValidateRangeExt();
							_ingame_menu_scroll.ForceToTarget();
							_ingame_menu_scroll.SetState(1);
							if (_ingame_menu_scroll._offset_y < CMath::ABSOLUTE_VALUE(deltaY))
							{
								_ingame_menu_scroll._offset_y = CMath::ABSOLUTE_VALUE(deltaY);
							}
						}
						else
						{
							if (CMath::ABSOLUTE_VALUE(TOUCHS(i)->y - _ingame_menu_scroll._last_touch_y) >= 5)
							{
								_ingame_menu_scroll._isScroll = true;
								_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
								_ingame_menu_scroll.Set();
								_ingame_menu_scroll.SetState(0);
								_ingame_menu_scroll._offset_y = 0;
								_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
							}


						}
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						_ingame_menu_scroll_touch_id = -1;
					}
				}
			}
			else
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_ingame_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						_ingame_menu_scroll_touch_id = -1;
					}
				}
			}
		}
	}
	_ingame_menu_scroll.Update();
}
void TDGame::IngameMenuInit()
{
	int boardframe = 236;
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		boardframe = 57;
	}
	_ingame_menu_scrolly = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(boardframe);
	_ingame_menu_scroll_speed = _ingame_menu_scrolly/13.0f;
	_ingame_menu_close = false;
	_ingame_menu_fill_opac = 0;
	_ingame_menu_close_touch_id = -1;
	_ingame_menu_scroll_touch_id = -1;
	_castle_info_scroll_speed = _ingame_menu_scroll_speed;
	_castle_info_scrolly = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(82);
	_ingame_menu_max_item_scroll = 1;

	ClearAllTouchUp(TOUCH_TYPE_MENU_INGAME);
	switch (_ingame_menu_type)
	{
	case MENU_INGAME_BUTTON_GATE:
		for (int i = 0; i < NUM_MAX_WEAPON; i++)
		{
			_ingame_menu_max_item_scroll++;
			if (_weapon[i].IsLock())
			{
				break;
			}
		}
		_ingame_menu_num_item = NUM_MAX_WEAPON+1;
		break;
	case MENU_INGAME_BUTTON_HEROES:
	{
									  for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
									  {
										  int posx = 140 + i * (210 + 25);
										  int posy = 460;
										  bool hasinit = false;
										  for (int j = 0; j < NUM_MAX_HERO; j++)
										  {
											  if (_user._hero_arr[j]._heroid >= 0)
											  {
												  int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[j]._heroid);
												  if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed && _user._hero_arr[j]._slot_deploy_number == i)
												  {
													  _heroes_deploy_arr[i].Init(posx, posy, _hero_inbattle_arr[index_inbattle].GetSpriteID(), _hero_inbattle_arr[index_inbattle].GetHeroID(), _hero_inbattle_arr[index_inbattle].GetDamage());
													  hasinit = true;
													  break;
												  }
											  }
										  }
										  if (!hasinit)
										  {
											  _heroes_deploy_arr[i].Init(posx, posy, 0, -1, 0);
										  }
									  }
        ClearAllHeroDeploy();
	}
		break;
	case MENU_INGAME_BUTTON_RELICS:
	{
									  _ingame_menu_max_item_scroll = _relics_num_of;
									  //_ingame_menu_max_item_scroll = _user._quest_num_relics_own + 1;
									  _ingame_menu_num_item = _ingame_menu_max_item_scroll;
	}

		break;
	case MENU_INGAME_BUTTON_SHOP:
	{

									_ingame_menu_num_item = NUM_MAX_ITEM_SHOP;// _game_design.General.SheetiAP_design.int32Value._totalData;
									if (_user._iap_starter_time_reset < time(NULL))
									{
										_ingame_menu_num_item--;
									}
									_ingame_menu_max_item_scroll = _ingame_menu_num_item;

	}
		break;
	default:
		break;
	}
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		int count_menu_info = 0;
		int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
#if !DISABLE_ONLINE_FEATURE
		if (HasEventAvailable(EVENT_TYPE_AVAILABLE))
		{
			if (!_user.CheckHeroColleted(EVENT_HERO_ID_AVAILABLE) && _user._tutorial_completed)
			{
				if(strcmp(_user._ivitation_code, "NULL") != 0)
				{
					int index_inbattle = CheckHeroIDInBattle(EVENT_HERO_ID_AVAILABLE);
                    if(index_inbattle >= 0)
                    {
                        int x = k_SCREEN_WIDTH / 2;
                        int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
                        _menu_info_arr[count_menu_info].Init(x, y, index_inbattle, false);
                        count_menu_info++;
                    }
				}
			}
		}
#endif
		for (int i = 0; i < totalhero; i++)
		{
			if (!_hero_inbattle_arr[i]._is_lock)
			{
				int x = k_SCREEN_WIDTH / 2;
				int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
				_menu_info_arr[count_menu_info].Init(x, y, i, false);
				count_menu_info++;
			}
		}
		for (int i = 0; i < totalhero; i++)
		{
			if (_hero_inbattle_arr[i]._is_lock)
			{
				int heroid = _hero_inbattle_arr[i].GetHeroID();
				if (/*heroid == HERO_ID_SANTA || */
                    heroid == HERO_ID_WOLF_RANGER
                    //|| heroid == HERO_ID_ACHEMIST
                    )
				{
					continue;
				}
				int x = k_SCREEN_WIDTH / 2;
				int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
				_menu_info_arr[count_menu_info].Init(x, y, i, false);
				count_menu_info++;
			}
		}
		_ingame_menu_num_item = count_menu_info;
		if (_user._tutorial_step == TUTORIAL_STEP_MENU_HERO)
		{
			_ingame_menu_max_item_scroll = 3;
		}
		else
		{
			_ingame_menu_max_item_scroll = _ingame_menu_num_item;
		}
	}
	else if (_ingame_menu_type == MENU_INGAME_BUTTON_RELICS)
	{
		int count_relic_fix = 0;
		_ingame_num_item_relics = 0;
		int interactive_id = 0;
		AddMenuInfo(ITEMRELIC_GROUP_WEAPON, 0);
		count_relic_fix = _ingame_num_item_relics;
		for (int i = 0; i < NUM_MAX_WEAPON; i++)
		{
			if (_weapon[i].IsLock())
			{
				continue;
			}
			interactive_id = i + 2;
			AddMenuInfo(ITEMRELIC_GROUP_WEAPON, interactive_id);
		}
		
		
		AddMenuInfo(ITEMRELIC_GROUP_HERO, 0);
		int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
		for (int i = 0; i < totalhero; i++)
		{
			int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
			interactive_id = GetDesignHeroGeneral(i, paramid);
			/*if (!_user.CheckHeroColleted(HERO_ID_ACHEMIST))
			{
			if (interactive_id == HERO_ID_ACHEMIST)
			{
			continue;
			}
			}*/
			if (!_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
			{
				if (interactive_id == HERO_ID_WOLF_RANGER)
				{
					continue;
				}
			}
			/*if (!_user.CheckHeroColleted(HERO_ID_SANTA))
			{
			if (interactive_id == HERO_ID_SANTA)
			{
			continue;
			}
			}*/
			AddMenuInfo(ITEMRELIC_GROUP_HERO, interactive_id);
		}
		AddMenuInfo(ITEMRELIC_GROUP_ENEMY, 0);
		if (_user._tutorial_step != TUTORIAL_STEP_BUY_RELIC)
		{
			count_relic_fix = _ingame_num_item_relics;
		}
        //printf("\n Init _ingame_num_item_relics = %d", _ingame_num_item_relics);
		_ingame_menu_max_item_scroll = count_relic_fix;
		_ingame_menu_num_item = _ingame_num_item_relics;
	}
	else if (_ingame_menu_type == MENU_INGAME_BUTTON_SHOP)
	{
		int count_menu_info = 0;

		int x = 0;
		int y = 0;
		bool has_bought_starter = false;
		if (_user._iap_starter_time_reset < time(NULL))
		{
			has_bought_starter = true;
		}
        
        for (int i = 0; i < _ingame_menu_num_item; i++)
        {
            int iap_id = GetDesignIAP(i + has_bought_starter, CGameDesign::FileGeneral::CSheetiAP_design::id, false);
            if (SHOP_ID_OPEN_BOX == iap_id)
            {
                //printf("\n iap_id[%d] = %d", i, iap_id);
                x = k_SCREEN_WIDTH / 2;
                y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
                //printf("\n Init x = %d,y = %d", x, y);
                _menu_info_arr[count_menu_info].Init(x, y, i, false);
                count_menu_info++;
            }
           
        }
        
		if (HasDownLoadMoreGame())
		{
			x = k_SCREEN_WIDTH / 2;
			y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_DOWN_MOREGAME, false);
			count_menu_info++;
		}
		//x = k_SCREEN_WIDTH / 2;
		//y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
		//int iap_index = GetDesignIapIndex(SHOP_ID_WATCH_ADD, 0, false);
		//_menu_info_arr[count_menu_info].Init(x, y, iap_index - has_bought_starter, false);
		//count_menu_info++;
        /*
		if (!_user._has_follow_tw)
		{
			x = k_SCREEN_WIDTH / 2;
			y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_FOLLOW_TW, false);
			count_menu_info++;
		}*/

		if (!_user._has_liked_fb)
		{
			x = k_SCREEN_WIDTH / 2;
			y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_LIKE_FB, false);
			count_menu_info++;
		}
		for (int i = 0; i < _ingame_menu_num_item; i++)
		{
			int iap_id = GetDesignIAP(i + has_bought_starter, CGameDesign::FileGeneral::CSheetiAP_design::id, false);
			if (iap_id == SHOP_ID_DOUBLE_COIN  || SHOP_ID_OPEN_BOX == iap_id || SHOP_ID_STARTER_PACK == iap_id
                || iap_id == SHOP_ID_REFILL_HP_CASTLE || iap_id == SHOP_ID_AUTO_ATT || iap_id == SHOP_ID_AUTO_SKILL)
			{
                continue;
                
			}
			if (iap_id != SHOP_ID_WATCH_ADD)
			{
				//printf("\n iap_id[%d] = %d", i, iap_id);
				x = k_SCREEN_WIDTH / 2;
				y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
				//printf("\n Init x = %d,y = %d", x, y);
				_menu_info_arr[count_menu_info].Init(x, y, i, false);
				count_menu_info++;
			}
		}
		x = k_SCREEN_WIDTH / 2;
		y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
		_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_RESTORE, false);
		count_menu_info++;
		_ingame_menu_max_item_scroll = count_menu_info;
		_ingame_menu_num_item = _ingame_menu_max_item_scroll;
	}
	else
	{
		for (int i = 0; i < _ingame_menu_num_item; i++)
		{
			int x = k_SCREEN_WIDTH / 2;
			int y = 100 + i * (INGAME_MENU_ITEM_HEIGHT + 5);
			
			_menu_info_arr[i].Init(x, y, i, false);
		}
	}
	int numitem = 7;
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		numitem = 3;
	}
	_ingame_menu_scroll.Init(0, _ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - numitem * INGAME_MENU_ITEM_HEIGHT, 3);
    if(_openShopFromGate)
    {
		//_ingame_menu_scroll.Init(0, _ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - numitem * INGAME_MENU_ITEM_HEIGHT, 3);
        _ingame_menu_scroll.SetCurrent(8*(5 + INGAME_MENU_ITEM_HEIGHT) - numitem * INGAME_MENU_ITEM_HEIGHT - 8);
        _openShopFromGate = false;
    }
}
bool TDGame::IngameMenuUpdateTouch()
{
#if !defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		_ingame_menu_close = true;
		GAME()->_isBackkeyPress = false;
		return true;
	}
#endif
	bool ret = false;
	if (_dialogMng.isOpenDialog() || _invitation_active)
	{
		return false;
	}
	if (_ingame_menu_frame_idle > 0)
	{
		return false;
	}
	bool pressed = false;
	int boardframe = 236;
	if (_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
	{
		boardframe = 57;
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		int x = _point_o.X;
		int y = _point_o.Y;
		int w = _screen_width;
		int h = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(boardframe, 0) + 20;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN /*|| TOUCHS(i)->_state == TOUCH_DRAG*/)
			{
				_ingame_menu_close = true;
				pressed = true;
			}
		}
		x = _point_o.X;
		y = _point_o.Y;
		w = CMath::ABSOLUTE_VALUE(_point_o.X);
		h = _screen_height;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN /*|| TOUCHS(i)->_state == TOUCH_DRAG*/)
			{
				_ingame_menu_close = true;
				pressed = true;
			}
		}
		x = k_SCREEN_WIDTH;
		y = _point_o.Y;
		w = CMath::ABSOLUTE_VALUE(_point_o.X);
		h = _screen_height;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN /*|| TOUCHS(i)->_state == TOUCH_DRAG*/)
			{
				_ingame_menu_close = true;
				pressed = true;
			}
		}
	}
	return pressed;
}
void TDGame::ReInitShop()
{
	int count_menu_info = 0;

	int x = 0;
	int y = 0;
	bool has_bought_starter = false;
	_ingame_menu_num_item = NUM_MAX_ITEM_SHOP;// _game_design.General.SheetiAP_design.int32Value._totalData;
	if (_user._iap_starter_time_reset < time(NULL))
	{
		_ingame_menu_num_item--;
		has_bought_starter = true;
	}
    
    for (int i = 0; i < _ingame_menu_num_item; i++)
    {
        int iap_id = GetDesignIAP(i + has_bought_starter, CGameDesign::FileGeneral::CSheetiAP_design::id, false);
        if (SHOP_ID_OPEN_BOX == iap_id)
        {
            //printf("\n iap_id[%d] = %d", i, iap_id);
            x = k_SCREEN_WIDTH / 2;
            y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
            //printf("\n Init x = %d,y = %d", x, y);
            _menu_info_arr[count_menu_info].Init(x, y, i, false);
            count_menu_info++;
        }
        
    }
    
	if (HasDownLoadMoreGame())
	{
		x = k_SCREEN_WIDTH / 2;
		y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
		_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_DOWN_MOREGAME, false);
		count_menu_info++;
	}
	//x = k_SCREEN_WIDTH / 2;
    //y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
	//int iap_index = GetDesignIapIndex(SHOP_ID_WATCH_ADD, 0, false);
	//_menu_info_arr[count_menu_info].Init(x, y, iap_index - has_bought_starter, false);
	//count_menu_info++;
    /*
	if (!_user._has_follow_tw)
	{
		x = k_SCREEN_WIDTH / 2;
		y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
		_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_FOLLOW_TW, false);
		count_menu_info++;
	}*/

	if (!_user._has_liked_fb)
	{
		x = k_SCREEN_WIDTH / 2;
		y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
		_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_LIKE_FB, false);
		count_menu_info++;
	}
	for (int i = 0; i < _ingame_menu_num_item; i++)
	{
		int iap_id = GetDesignIAP(i + has_bought_starter, CGameDesign::FileGeneral::CSheetiAP_design::id, false);
		if (iap_id == SHOP_ID_DOUBLE_COIN || SHOP_ID_OPEN_BOX == iap_id || SHOP_ID_STARTER_PACK == iap_id
			|| iap_id == SHOP_ID_REFILL_HP_CASTLE || iap_id == SHOP_ID_AUTO_ATT || iap_id == SHOP_ID_AUTO_SKILL)
		{
			//if (_user._has_double_coin)
			//{
				continue;
			//}
			
		}
		if (iap_id != SHOP_ID_WATCH_ADD)
		{
			x = k_SCREEN_WIDTH / 2;
			y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			//printf("\n Init x = %d,y = %d", x, y);
			_menu_info_arr[count_menu_info].Init(x, y, i, false);
			count_menu_info++;
		}

	}

	
	x = k_SCREEN_WIDTH / 2;
	y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
	_menu_info_arr[count_menu_info].Init(x, y, SHOP_ID_RESTORE, false);
	count_menu_info++;
	_ingame_menu_max_item_scroll = count_menu_info;
	_ingame_menu_num_item = _ingame_menu_max_item_scroll;
	_ingame_menu_scroll.Init(0, _ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 7 * INGAME_MENU_ITEM_HEIGHT, 3);
}
void TDGame::ReInitHero()
{
	_ingame_menu_scroll._touch_id = -1;
	_ingame_menu_scroll._isScroll = false;
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;

	int count_hero_range = 0;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		int heroid = _user._hero_arr[i]._heroid;
		int level = _user._hero_arr[i]._level;
		bool deployed = _user._hero_arr[i]._is_deployed;
		int slot = _user._hero_arr[i]._slot_deploy_number;
		if (heroid > 0)
		{
			int index_inbattle = CheckHeroIDInBattle(heroid);
			if (index_inbattle >= 0)
			{
				//_hero_inbattle_arr[i].Modify(_hero_inbattle_arr[index_inbattle].GetHeroID(), 1, _hero_inbattle_arr[index_inbattle]._deployed, false, _hero_inbattle_arr[index_inbattle].GetPowerAttack(), _hero_inbattle_arr[index_inbattle].GetPowerSkill());
				_hero_inbattle_arr[index_inbattle].Modify(_hero_inbattle_arr[index_inbattle].GetPosX(), _hero_inbattle_arr[index_inbattle].GetPosY(), false, _hero_inbattle_arr[index_inbattle].GetPowerAttack(), _hero_inbattle_arr[index_inbattle].GetPowerSkill());
				//_hero_inbattle_arr[i].SetPos(110 + count_hero_range * 30, _hero_inbattle_arr[i].GetPosY() - count_hero_range * 15);
				if (_hero_inbattle_arr[index_inbattle].GetTypeRange() == HERO_TYPE_RANGE_RANGE)
				{
					_hero_inbattle_arr[i].SetPos(110 + count_hero_range * 30 + _point_o.X, ROAD_POSY + 15 - count_hero_range * 15 + _point_o.Y);
					count_hero_range++;
				}
			}
		}
	}
	int count_menu_info = 0;
#if !DISABLE_ONLINE_FEATURE
	if (HasEventAvailable(EVENT_TYPE_AVAILABLE))
	{
		if (!_user.CheckHeroColleted(EVENT_HERO_ID_AVAILABLE) && _user._tutorial_completed)
		{
			if (strcmp(_user._ivitation_code, "NULL") != 0)
			{
				int index_inbattle = CheckHeroIDInBattle(EVENT_HERO_ID_AVAILABLE);
                if(index_inbattle >= 0)
                {
                    int x = k_SCREEN_WIDTH / 2;
                    int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
                    _menu_info_arr[count_menu_info].Init(x, y, index_inbattle, false);
                    count_menu_info++;
                }
			}
		}
	}
#endif
	for (int i = 0; i < totalhero; i++)
	{
		if (!_hero_inbattle_arr[i]._is_lock)
		{
			int x = k_SCREEN_WIDTH / 2;
			int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			_menu_info_arr[count_menu_info].Init(x, y, i, false);
			count_menu_info++;
		}
	}
	for (int i = 0; i < totalhero; i++)
	{
		if (_hero_inbattle_arr[i]._is_lock)
		{
			int heroid = _hero_inbattle_arr[i].GetHeroID();
			if (/*heroid == HERO_ID_SANTA || */
                heroid == HERO_ID_WOLF_RANGER
                //|| heroid == HERO_ID_ACHEMIST
                )
			{
				continue;
			}
			int x = k_SCREEN_WIDTH / 2;
			int y = 100 + count_menu_info * (INGAME_MENU_ITEM_HEIGHT + 5);
			_menu_info_arr[count_menu_info].Init(x, y, i, false);
			count_menu_info++;
		}
	}
	_ingame_menu_num_item = count_menu_info;// _user._num_heroes_collected + 1;
	_ingame_menu_max_item_scroll = _ingame_menu_num_item;
	_ingame_menu_scroll.SetMax(_ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 3 * INGAME_MENU_ITEM_HEIGHT);
	//_ingame_menu_scroll.Init(0, _ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 3 * INGAME_MENU_ITEM_HEIGHT, 3);
}
void TDGame::ReInitRelics()
{
	int total_relics = 0;
	_ingame_menu_scroll._touch_id = -1;
	_ingame_menu_scroll._isScroll = false;
	int group = 0;
	int count_relic = 0;
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		if (_user._item_relics[i]._id > 0)
		{
			_items_relics[count_relic].Init(SPRITEID_HUD_ITEM, _user._item_relics[i]._group, _user._item_relics[i]._id, 0, 0, false);
			count_relic++;
		}
	}
	total_relics = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
	group = ITEMRELIC_GROUP_WEAPON;
	for (int i = 0; i < total_relics; i++)
	{
		int paramid = CGameDesign::FileRelics_design::CSheetWeapon_Relics::ID;
		int relicid = GetDesignRelics(i, group, paramid);
		if (!_user.CheckRelicsCollected(group, relicid))
		{
			_items_relics[count_relic].Init(SPRITEID_HUD_ITEM, group, relicid, 0, 0, true);
			count_relic++;
		}
	}

	total_relics = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
	group = ITEMRELIC_GROUP_HERO;
	for (int i = 0; i < total_relics; i++)
	{
		int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
		int relicid = GetDesignRelics(i, group, paramid);
		if (!_user.CheckRelicsCollected(group, relicid))
		{
			_items_relics[count_relic].Init(SPRITEID_HUD_ITEM, group, relicid, 0, 0, true);
			count_relic++;
		}
	}

	total_relics = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;
	group = ITEMRELIC_GROUP_ENEMY;
	for (int i = 0; i < total_relics; i++)
	{
		int paramid = CGameDesign::FileRelics_design::CSheetEnemy_Relics::ID;
		int relicid = GetDesignRelics(i, group, paramid);
		if (!_user.CheckRelicsCollected(group, relicid))
		{
			_items_relics[count_relic].Init(SPRITEID_HUD_ITEM, group, relicid, 0, 0, true);
			count_relic++;
		}
	}
	total_relics = _game_design.Relics_design.SheetPet_Relics.int32Value._totalData;
	group = ITEMRELIC_GROUP_PET;
	for (int i = 0; i < total_relics; i++)
	{
		int paramid = CGameDesign::FileRelics_design::CSheetPet_Relics::ID;
		int relicid = GetDesignRelics(i, group, paramid);
		if (!_user.CheckRelicsCollected(group, relicid))
		{
			_items_relics[count_relic].Init(SPRITEID_HUD_ITEM, group, relicid, 0, 0, true);
			count_relic++;
		}
	}
	_ingame_num_item_relics = 0;
	int interactive_id = 0;
	AddMenuInfo(ITEMRELIC_GROUP_WEAPON, 0);
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		if (_weapon[i].IsLock())
		{
			continue;
		}
		interactive_id = i + 2;
		AddMenuInfo(ITEMRELIC_GROUP_WEAPON, interactive_id);
	}
	AddMenuInfo(ITEMRELIC_GROUP_HERO, 0);
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	for (int i = 0; i < totalhero; i++)
	{

		int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		interactive_id = GetDesignHeroGeneral(i, paramid);

		/*if (!_user.CheckHeroColleted(HERO_ID_ACHEMIST))
		{
			if (interactive_id == HERO_ID_ACHEMIST)
			{
				continue;
			}
		}*/
		if (!_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
		{
			if (interactive_id == HERO_ID_WOLF_RANGER)
			{
				continue;
			}
		}
		/*if (!_user.CheckHeroColleted(HERO_ID_SANTA))
		{
			if (interactive_id == HERO_ID_SANTA)
			{
				continue;
			}
		}*/

		AddMenuInfo(ITEMRELIC_GROUP_HERO, interactive_id);
	}
	AddMenuInfo(ITEMRELIC_GROUP_ENEMY, 0);
	_ingame_menu_max_item_scroll = _ingame_num_item_relics;
	_ingame_menu_num_item = _ingame_menu_max_item_scroll;
	_ingame_menu_scroll.SetMax(_ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 7 * INGAME_MENU_ITEM_HEIGHT);
	//_ingame_menu_scroll.Init(0, _ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 7 * INGAME_MENU_ITEM_HEIGHT, 3);
}
void TDGame::MenuInfo::Init(float x, float y, int indexitem, bool banner)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	_x = x;
	_y = y;
	_index = indexitem;
	_card_touch_id = -1;
	_touch_y = 0;
	_touch_x = 0;
	_card_touch_block = false;
	_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
	_scale_text_button = 1.0f;
	_has_touch = false;
	_notify_new.Init(SPRITEID_HUD_MAINMENU, -1, 95, 0, _y - 45, 0);
	_effect_levelup.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
	_effect_levelup.SetAnim(96, false);
	_effect_levelup.SetPos(0, 0);
	_effect_levelup_start = false;
	_is_new = false;
	_price = 0;
	_id = -1;
	_value_plus = 0;
	_level_unlock = 0;
	_banner = banner;
	_unit_bounce = 0;
	sprintf(_id_string, "string_id");
	sprintf(_coin_text, "???");
	sprintf(_value_plus_text, "???");
	sprintf(_value_up_text, "???");
	sprintf(_value_text, "???");
	switch (game->_ingame_menu_type)
	{
	case MENU_INGAME_BUTTON_GATE:
	{

									if (_index == 0)
									{
										int param_valueup = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
										_level = game->_castle.GetLevel();
										INT_TIME hp_normal = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_valueup);
										_value = hp_normal;
										_value_plus = game->_castle._hp_max - hp_normal;
										_cost_upgrade = game->_castle.GetCostUpgrade();
										_value_up = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level + 1, param_valueup) - hp_normal;
										
										_is_lock = false;
										_spriteid = SPRITEID_HUD_CASTLE_00;
										_frameid = 0;
										if (game->_castle._level_max)
										{
											_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
											_button_buy.SetPos(_x, _y);
										}
										else
										{
											_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
											_button_buy.SetPos(_x, _y);
										}

									}
									else
									{
										//int param_valueup = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
										_level = game->_weapon[_index - 1].GetLevel();
										INT_TIME damage_normal = game->_weapon[_index - 1].GetDamageBasic();
										_value = damage_normal;
										_value_plus = game->_weapon[_index - 1].GetDamageExtra();
										_cost_upgrade = game->_weapon[_index - 1].GetCostUpgrade();
										_value_up = game->_weapon[_index - 1].GetDamageLevelUp() - damage_normal;
										_is_lock = game->_weapon[_index - 1].IsLock();
										_spriteid = game->_weapon[_index - 1].GetSpriteID();
										_frameid = 0;
										_unit_bounce = game->GetRelicsUnitBounce(ITEMRELIC_GROUP_WEAPON, game->_weapon[_index - 1].GetType() + 2);
										if (game->_weapon[_index - 1]._level_max)
										{
											_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
											_button_buy.SetPos(_x, _y);
										}
										else
										{
											_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
											_button_buy.SetPos(_x, _y);
										}
										_level_unlock = game->_weapon[_index - 1]._level_limited;
									}
									int param_name = CGameDesign::FileCastle_design::CSheetCastle_General::Name;
									sprintf(_name, "%s", game->GetDesignCastleName(_index, param_name));
        
                                    int param_decs = CGameDesign::FileCastle_design::CSheetCastle_General::Description;
                                    sprintf(_descript,"%s",game->GetDesignCastleName(_index, param_decs));
									if (game->_weapon[_index - 1].GetType() == WEAPON_ELECTRIC)
									{
										sprintf(_descript, "Great damage in %d targets", 5 + _unit_bounce);
									}
									_value2 = 0;
									_deployed = true;
									game->ConvertMoneyInbalace(_value_plus, _value_plus_text);
									game->ConvertMoneyInbalace(_value, _value_text);
									game->ConvertMoneyInbalace(_cost_upgrade, _coin_text);
									game->ConvertMoneyInbalace(_value_up, _value_up_text);
	}

		break;
	case MENU_INGAME_BUTTON_HEROES:
	{
									  _level = 0;
									  _value = 0;
									  _cost_upgrade = 0;
									  _value2 = 0;
									  _value_up = 0;
									  _is_lock = false;
									  _deployed = false;
									  /*if (_index == 0)
									  {
									  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
									  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 82);
									  _button_buy.SetPos(_x, _y);
									  _cost_upgrade = 10;
									  }
									  else*/
									  {

										  int param_valueup = CGameDesign::FileHero_design::CSheetArcher::Attack;

										  int design_hero_index = 0;
										  int param_id = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;

										  /*if (_index >= game->_user._num_heroes_collected)
										  {
										  _level = 1;
										  int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
										  int param_skill = CGameDesign::FileHero_design::CSheetHero_General::Skill;
										  int param_id = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
										  int param_descript = CGameDesign::FileSkill_design::CSheetSheet1::Description;
										  int heroid = game->GetDesignHeroGeneral(_index, param_id);
										  int skillid = game->GetDesignHeroGeneral(heroid - 1, param_skill) - 1;
										  _value = game->GetDesignHeroInfo(heroid - 1, _level, param_damage);
										  _cost_upgrade = 10;
										  _value2 = 0;
										  _value_up = 0;
										  sprintf(_name, "%s", game->GetDesignHeroName(heroid - 1));
										  sprintf(_descript, "%s", game->GetDesignSkillString(skillid, param_descript));
										  _is_lock = true;
										  _deployed = false;
										  _spriteid = game->_hero_sprite[heroid - 1];
										  game->LoadSpriteOptimize(_spriteid);
										  _frameid = 4;
										  _id = heroid;
										  }
										  else*/
										  {
											  int heroindex = _index - 1;
											  heroindex = _index;
											  //printf("\n hero heroindex = %d", heroindex);
											  _level = game->_hero_inbattle_arr[heroindex].GetLevel();
											  _id = game->_hero_inbattle_arr[heroindex].GetHeroID();
											  INT_TIME damage_normal = game->_hero_inbattle_arr[heroindex].GetDamageNormal();
											  _value = damage_normal;
											  _value_plus = (int)game->_hero_inbattle_arr[heroindex].GetDamageExtra();
											  _cost_upgrade = (int)game->_hero_inbattle_arr[heroindex].GetCostUpgrade();
											  _value2 = 0;
											  _value_up = game->_hero_inbattle_arr[heroindex].GetDamageLevelUp() - damage_normal;
											  sprintf(_name, "%s", game->_hero_inbattle_arr[heroindex].GetName());
											  sprintf(_descript, "%s", game->_hero_inbattle_arr[heroindex]._skill.GetDescript());
											  _is_lock = game->_hero_inbattle_arr[heroindex]._is_lock;
											  _level_unlock = game->_hero_inbattle_arr[heroindex].GetLevelUnlock();
                                              //_stars = game->_hero_inbattle_arr[heroindex].GetStars();
											  _stars = game->_hero_inbattle_arr[heroindex].GetNumStars();
											  if (_is_lock)
											  {
												  _cost_upgrade = game->_hero_inbattle_arr[heroindex].GetCostUnlock();
											  }
											  _is_new = game->_hero_inbattle_arr[heroindex]._is_new;
											  _deployed = game->_hero_inbattle_arr[heroindex]._deployed;
											  _spriteid = game->_hero_inbattle_arr[heroindex].GetSpriteID();
											  _frameid = 4;
											  if (game->_hero_inbattle_arr[heroindex]._level_max)
											  {
												  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
												  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
												  _button_buy.SetPos(_x, _y);
											  }
											  else
											  {
												  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
												  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
												  _button_buy.SetPos(_x, _y);
												 
											  }
											  game->ConvertMoneyInbalace(_value_plus, _value_plus_text);
											  game->ConvertMoneyInbalace(_value, _value_text);
											  game->ConvertMoneyInbalace(_value_up, _value_up_text);
											  game->ConvertMoneyInbalace(_cost_upgrade, _coin_text);
										  }
									  }
	}
		_card_touch_block = false;
		break;
	case MENU_INGAME_BUTTON_RELICS:
	{
									  _level = 0;
									  _value = 0;
									  _cost_upgrade = 0;
									  _value2 = 0;
									  _value_up = 0;
									  _is_lock = false;
									  _deployed = true;
									  int relicindex = _index - 1;
									  relicindex = _index;
									  /*if (_index == 0)
									  {
									  int param_price = CGameDesign::FileRelics_design::CSheetHero_Relics::Price;
									  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
									  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 82);
									  _button_buy.SetPos(_x, _y);
									  _cost_upgrade = game->GetDesignRelics(0,ITEMRELIC_GROUP_HERO,param_price);
									  }
									  else*/
									  {
										  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
										  _button_buy.SetPos(_x, _y);
										  //_button_buy.SetState(BUTTON_STATE_HIDE);
										  if (_banner)
										  {

											  if (game->_items_relics[relicindex]._group == ITEMRELIC_GROUP_HERO || game->_items_relics[relicindex]._group == ITEMRELIC_GROUP_PET)
											  {
												  if (game->_items_relics[relicindex]._interactive_id == 0)
												  {
													  sprintf(_name, "%s", "All Heroes");
												  }
												  else
												  {
													  int relic_inter_index = game->GetHeroIndex(game->_items_relics[relicindex]._interactive_id);
													  sprintf(_name, "%s", game->_hero_inbattle_arr[relic_inter_index].GetName());
													  _frameid = 13 + game->_items_relics[relicindex]._interactive_id - 1;
												  }

											  }
											  else if (game->_items_relics[relicindex]._group == ITEMRELIC_GROUP_WEAPON)
											  {
												  if (game->_items_relics[relicindex]._interactive_id == 0)
												  {
													  sprintf(_name, "%s", "All Towers");
												  }
												  else
												  {
													  int param_name = CGameDesign::FileCastle_design::CSheetCastle_General::Name;
													  sprintf(_name, "%s", game->GetDesignCastleName(game->_items_relics[relicindex]._interactive_id - 1, param_name));
													  _frameid = 3 + game->_items_relics[relicindex]._interactive_id - 2;
												  }
											  }
											  else
											  {
												  sprintf(_name, "%s", "Misc.");
											  }
											  sprintf(_descript, "%s", "Null");
											  _is_lock = true;
											  _cost_upgrade = 0;
											  _spriteid = SPRITEID_ICON_RELIC;
										  }
										  else
										  {
											  sprintf(_name, "%s", game->_items_relics[relicindex]._name);
											  sprintf(_descript, "%s", game->_items_relics[relicindex]._descript);
											  _is_lock = game->_items_relics[relicindex]._is_lock;
											  _cost_upgrade = game->_items_relics[relicindex]._price;
											  if (game->_items_relics[relicindex]._frameid == 164)
											  {
												  _stars = game->_user._user_level_reset;
											  }
											  else
											  {
												  _stars = -1;
											  }
										  }
										  game->ConvertMoneyInbalace(_value_plus, _value_plus_text);
										  game->ConvertMoneyInbalace(_value, _value_text);
										  game->ConvertMoneyInbalace(_value_up, _value_up_text);
										  game->ConvertMoneyInbalace(_cost_upgrade, _coin_text);
									  }
	}
		break;
	case MENU_INGAME_BUTTON_SHOP:
	{
									int param_id = CGameDesign::FileGeneral::CSheetiAP_design::id;
									int param_value = CGameDesign::FileGeneral::CSheetiAP_design::Value;
									int param_price = CGameDesign::FileGeneral::CSheetiAP_design::price;
									int param_name = CGameDesign::FileGeneral::CSheetiAP_design::name;
#if defined (ANDROID_OS)
									int param_idPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::GG_ID;
#else
									int param_idPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::ID_Store;
#endif
									_level = 0;
									_value = 0;
									_cost_upgrade = 0;
									_value2 = 0;
									_value_up = 0;
									_is_lock = false;
									_deployed = true;
									int iap_index = _index;

									if (game->_user._iap_starter_time_reset < time(NULL))
									{
										iap_index++;
									}
									bool has_discount = false;
									_id = game->GetDesignIAP(iap_index, param_id, has_discount);
                                    /*
									if (!game->_iap_discount_time.isNullDay())
									{
										has_discount = true;
										//iap_index += 7;
									}*/
									if (_index == SHOP_ID_FOLLOW_TW)
									{
										_id = _index;
										sprintf(_name, "%s", "Follow on Twitter\nFollow us to get reward");
										sprintf(_descript, "%s", "NULL");
										_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
										_button_buy.SetPos(_x, _y);
										_value = TW_FOLLOW_REWARD;
										_price = 0;
									}
									else if (_index == SHOP_ID_LIKE_FB)
									{
										_id = _index;
										sprintf(_name, "%s", "Like on Facebook\nLike us to get reward");
										sprintf(_descript, "%s", "NULL");
										_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
										_button_buy.SetPos(_x, _y);
										_value = FB_LIKE_REWARD;
										_price = 0;
									}
									else if (_index == SHOP_ID_RESTORE)
									{
										_id = _index;
										sprintf(_name, "%s", "Restore all purchases");
										sprintf(_descript, "%s", "NULL");
										_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
										_button_buy.SetPos(_x, _y);
										_value = 0;
										_price = 0;
									}
									else if (_index == SHOP_ID_DOWN_MOREGAME)
									{
										_id = _index;
										sprintf(_name, "%s", "NEW GAME!");
										sprintf(_descript, "%s", "Download to get reward");
										_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 144);
										_button_buy.SetPos(_x, _y);
										_value = DOWN_MOREGAME_REWARD;
										_price = 0;
										game->_down_moregame_glow.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
										game->_down_moregame_glow.SetAnim(152, true);
										game->_down_moregame_glow.SetPos(0, 0);
										
									}
									else
									{

										sprintf(_id_string, "%s", game->GetDesignIAPString(iap_index, param_idPurcharse, has_discount));
										sprintf(_name, "%s", game->GetDesignIAPString(iap_index, param_name, has_discount));
										sprintf(_descript, "%s", game->GetDesignIAPString(iap_index, param_price, has_discount));
										_price = atoi(_descript);
										_value = game->GetDesignIAP(iap_index, param_value, has_discount);
										_id = game->GetDesignIAP(iap_index, param_id, has_discount);
										_button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
										_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
										_button_buy.SetPos(_x, _y);
										printf("\n init has_discount = %d - _id_string = %s", has_discount, _id_string);
										if (_id == SHOP_ID_WATCH_ADD)
										{
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 126);
										}
										_index = iap_index;
									}
									_anim_network.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
									_anim_network.SetAnim(125, true);
									_anim_network.SetPos(0, 0);
									if (_id == SHOP_ID_WATCH_ADD)
									{
										_notify_new.Init(SPRITEID_HUD_MAINMENU, -1, 98, 0, _y - 45, 0);
									}
									else
									{
										_notify_new.Init(SPRITEID_HUD_MAINMENU, -1, 107, 0, _y - 45, 0);
									}
									

	}

		break;
	default:
		break;
	}
}

void TDGame::MenuInfo::Render(float x, float y)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int mw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(58);
	int spacing = 0;
	int line_space = 0;
	bool enought_coin = true;
	int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(72, 0);
	bool has_level_max = false;
	switch (game->_ingame_menu_type)
	{
	case MENU_INGAME_BUTTON_GATE:
	{
		bool level_limited = false;
		if (_level_unlock > game->_battle_current)
		{
			level_limited = true;
		}
		if (_cost_upgrade > game->_user.GetCoin())
		{
			/*if (!game->_timeBuyOpenBox.isNullDay() || game->_is_hacked_time)
			{
				if (_button_buy._state != BUTTON_STATE_LOCK)
				{
					_button_buy.SetState(BUTTON_STATE_LOCK);
				}
			}
			else
			{
				if (_button_buy._state == BUTTON_STATE_LOCK)
				{
					_button_buy.SetState(BUTTON_STATE_NORMAL);
				}
			}*/
			enought_coin = false;
		}
		else
		{
			if (_button_buy._state == BUTTON_STATE_LOCK)
			{
				_button_buy.SetState(BUTTON_STATE_NORMAL);
			}
		}

		if (_index > 1)
		{
			if (!game->_weapon[_index - 2].IsLock())
			{
				if (_button_buy._state == BUTTON_STATE_HIDE)
				{
					_button_buy.SetState(BUTTON_STATE_NORMAL);
				}
			}
			else
			{
				if (_button_buy._state != BUTTON_STATE_HIDE)
				{
					_button_buy.SetState(BUTTON_STATE_HIDE);
				}
			}

		}
		if (_is_lock && level_limited)
		{
			if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
			{
				_button_buy.SetState(BUTTON_STATE_LOCK);
			}
		}
		else
		{
			if (_button_buy._state == BUTTON_STATE_LOCK)
			{
				_button_buy.SetState(BUTTON_STATE_NORMAL);
			}
		}
		if (!game->_user._tutorial_completed)
		{
			if (game->_tutorial_step == TUTORIAL_STEP_BUILD_TOWER)
			{
				if (_index - 1 != WEAPON_ARCHER)
				{
					if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
					{
						_button_buy.SetState(BUTTON_STATE_LOCK);
					}
				}
			}
		}
		else
		{

		}
		if (_button_buy._state == BUTTON_STATE_HIDE)
		{
			break;
		}
		if (_cost_upgrade <= game->_user.GetCoin() && _button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE && _is_lock)
		{
			if (_notify_new._state == NOTIFY_STATE_NONE)
			{
				_notify_new.Active();
			}
		}
		else
		{
			if (_notify_new._state == NOTIFY_STATE_ACTIVE)
			{
				_notify_new.Disable();
			}
		}
		
		if (!_is_lock)
		{
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
		}
		else
		{
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 60, _x + x, _y + y);
		}
		if (_index == 0)
		{
			has_level_max = game->_castle._level_max;
		}
		else
		{
			has_level_max = game->_weapon[_index - 1]._level_max;
		}
		if (has_level_max)
		{
			if (_button_buy._state != BUTTON_STATE_LOCK)
			{
				_button_buy.SetState(BUTTON_STATE_LOCK);
			}
		}

		_button_buy.SetPos(_x + x, _y + y);
		_button_buy.Render(G());
		_button_buy.Update();
		spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);

		if (_index == 0)
		{
			//GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 24 + y, _LEFT, "HP: %lld", _value);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 24 + y, _LEFT, "HP: %s", _value_text);
			if (_value_plus > 0 && !_is_lock)
			{
				char text[56];
				int lenght = sprintf(text, "HP: %s", _value_text);
				int text_w = (GET_SPRITE(SPRITEID_FONT_HUD))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_HUD)->StringToUnichar(text), 0, lenght) + 2;
				//GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y + 24 + y, _LEFT, "+%d", _value_plus);
				GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y + 24 + y, _LEFT, "+%s", _value_plus_text);
			}
			spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
			G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
			
			if (!has_level_max)
			{
				//GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %lld HP", _value_up);
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %s HP", _value_up_text);
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Up");
			}
			else
			{
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Max");
			}
			G()->ClearScale();
			GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
			GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
		}
		else
		{
			
			
			/*if (_is_lock)
			{
				GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 24 + y, _LEFT, "DMG: ???");
			}
			else*/
			{
				//GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 24 + y, _LEFT, "DMG: %lld", _value);
				GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 24 + y, _LEFT, "DMG: %s", _value_text);
			}
			if (_value_plus > 0 && !_is_lock)
			{
				char text[128];
				int lenght = sprintf(text, "DMG: %s", _value_text);
				int text_w = (GET_SPRITE(SPRITEID_FONT_HUD))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_HUD)->StringToUnichar(text), 0, lenght) + 2;
				//GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y + 24 + y, _LEFT, "+%d", _value_plus);
				
				GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y + 24 + y, _LEFT, "+%s", _value_plus_text);
			}
			spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
			G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);

			if (_is_lock)
			{
				if (level_limited)
				{
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Unlockable after");
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "Battle %d", _level_unlock);
				}
				else
				{
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Unlock this");
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "Tower");
				}

			}
			else
			{
				if (!has_level_max)
				{
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Up");
					//GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %lld DMG", _value_up);
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %s DMG", _value_up_text);
				}
				else
				{
					GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Max");

				}

			}
			G()->ClearScale();
			GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
			GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
		}
		spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
		/*if (_is_lock)
		{
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "%s", _name);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 4 + y, _LEFT, "Lv. ???");
		}
		else*/
		{
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "%s", _name);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 4 + y, _LEFT, "Lv. %d", _level);
		}
		GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
		G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
		spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 1;
		if (!has_level_max)
		{
			if (level_limited && _is_lock)
			{
				GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": ???");
			}
			else
			{
				if (enought_coin)
				{
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %s", _coin_text);
					//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %d", _cost_upgrade);
				}
				else
				{
					char text[128];
					//int lenght = sprintf(text, "%s", _coin_text);
					int lenght = sprintf(text, "%d", _cost_upgrade);
					int text_w = (GET_SPRITE(SPRITEID_FONT_SHOPCOIN))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->StringToUnichar(text), 0, lenght) + 8;
					int icon_w = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->GetFModuleWidth(26, 0);
					G()->SetColorMask(0xffc90000);
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%s", _coin_text);
					//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%d", _cost_upgrade);
					G()->ClearColorMask();
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - text_w / 2 - 110 + x, _y - 34 + y, _HCENTER, ":");
				}
			}
		}
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
		G()->ClearScale();

		GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing = spacing;
		line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 3;
		spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
		G()->SetColorMask(0xffff00);
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y + 50, 330, _LEFT, "%s", _descript);
		G()->ClearColorMask();
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
		_notify_new.Render(_x + x - mw / 2 + 23, y);
	}
		break;
	case MENU_INGAME_BUTTON_HEROES:
		
	{

									  int heroindex = _index - 1;
									  heroindex = _index;
									  if (!_is_lock)
									  {
										  if (_cost_upgrade > game->_user.GetCoin())
										  {
                                              /*if (!game->_timeBuyOpenBox.isNullDay() || game->_is_hacked_time)
                                              {
                                                  if (_button_buy._state != BUTTON_STATE_LOCK)
                                                  {
                                                      _button_buy.SetState(BUTTON_STATE_LOCK);
                                                  }
                                              }
                                              else
                                              {
                                                  if (_button_buy._state == BUTTON_STATE_LOCK)
                                                  {
                                                      _button_buy.SetState(BUTTON_STATE_NORMAL);
                                                  }
                                              }*/
											  enought_coin = false;
										  }
										  else
										  {
											  if (_button_buy._state == BUTTON_STATE_LOCK)
											  {
												  _button_buy.SetState(BUTTON_STATE_NORMAL);
											  }
										  }
										  if (_is_new)
										  {
											  if (_notify_new._state == NOTIFY_STATE_NONE)
											  {
												  _notify_new.Active();
											  }
										  }
										  else
										  {
											  if (_notify_new._state == NOTIFY_STATE_ACTIVE)
											  {
												  _notify_new.Disable();
											  }
										  }
										  if (_notify_new._state >= NOTIFY_STATE_START)
										  {
											  if (game->_notify_new[1]._state == NOTIFY_STATE_NONE)
											  {
												  game->_notify_new[1].Active();
											  }
										  }
										  if (!game->_user._tutorial_completed)
										  {
											  if (game->_tutorial_step == TUTORIAL_STEP_BUY_HERO)
											  {
												  if (heroindex != 1)///archer hero
												  {
													  if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
													  {
														  _button_buy.SetState(BUTTON_STATE_LOCK);
													  }
												  }
											  }
										  }
										  if (game->_hero_inbattle_arr[heroindex]._level_max)
										  {

											  if (_button_buy._state != BUTTON_STATE_LOCK)
											  {
												  _button_buy.SetState(BUTTON_STATE_LOCK);
											  }
										  }
										  _deployed = game->_hero_inbattle_arr[heroindex]._deployed;
										  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
										  _button_buy.SetPos(_x + x, _y + y);
										  _button_buy.Render(G());
										  _button_buy.Update();
										  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);
										  if (_deployed)
										  {
											  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 73, _x + x, _y + y);
										  }
										  else
										  {
											  if (_card_touch_id == -1)
											  {
												  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 74, _x + x, _y + y);
											  }
											  else
											  {
												  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 75, _x + x, _y + y);
											  }
										  }
										  spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
										  GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
										  //GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 8 + y, _LEFT, "DMG: %lld", _value);
										  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 8 + y, _LEFT, "DMG: %s", _value_text);
										  if (_value_plus > 0)
										  {
											  char text[128];
											  int lenght = sprintf(text, "DMG: %s", _value_text);
											  int text_w = (GET_SPRITE(SPRITEID_FONT_HUD))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_HUD)->StringToUnichar(text), 0, lenght) + 2;
											  //GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y - 8 + y, _LEFT, "+%d", _value_plus);
											  GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x + text_w, _y - 8 + y, _LEFT, "+%s", _value_plus_text);
										  }
										  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "Lv. %d", _level);
										  GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
										  G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
										  spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
										  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 1;
										  if (!game->_hero_inbattle_arr[heroindex]._level_max)
										  {
											  if (enought_coin)
											  {
												  //GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %d", _cost_upgrade);
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %s", _coin_text);
											  }
											  else
											  {
												  char text[20];
												  //int lenght = sprintf(text, "%s", _coin_text);
												  int lenght = sprintf(text, "%d", _cost_upgrade);
												  int text_w = (GET_SPRITE(SPRITEID_FONT_SHOPCOIN))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->StringToUnichar(text), 0, lenght) + 8;
												  int icon_w = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->GetFModuleWidth(25, 0);
												  G()->SetColorMask(0xffc90000);
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%s", _coin_text);
												  //GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%d", _cost_upgrade);
												  G()->ClearColorMask();
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - text_w / 2 - 110 + x, _y - 34 + y, _HCENTER, ": ");
											  }

											  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
											  spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Up");
											  //GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %lld DMG", _value_up);
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "+ %s DMG", _value_up_text);
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
										  }
										  else
										  {
											  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
											  spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Level Max");
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
										  }
										  G()->ClearScale();
										  GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
										  if (_effect_levelup_start)
										  {
											  _effect_levelup.SetPos(_x + x - mw / 2 + 73, _y + y);
											  _effect_levelup.DrawAnimObject(G());
										  }
										  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
										  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 80, _x + x - mw / 2 + 73, _y + y + 3);
                                          GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224+_stars, _x + x - mw / 2 + 73, _y + y + 3- 55);
										  spacing = GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing;
										  GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing = 2;
										  GET_SPRITE(SPRITEID_FONT_HERONAME)->DrawAnsiTextFormat(G(), _x + x - mw / 2 + 73, _y + y + 59, _HCENTER, "%s", _name);
										  GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing = spacing;
										  line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
										  GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 3;
										  spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
										  GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
										  GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y + 12, 330, _LEFT, "%s", _descript);
										  GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
										  GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
										  
									  }
									  else
									  {
										 
										  {
											  if (_cost_upgrade > game->_user.GetGem())
											  {
												  /*if (_button_buy._state != BUTTON_STATE_LOCK)
												  {
													  _button_buy.SetState(BUTTON_STATE_LOCK);
												  }*/
												  enought_coin = false;
											  }
											  else
											  {
												  if (_button_buy._state == BUTTON_STATE_LOCK)
												  {
													  _button_buy.SetState(BUTTON_STATE_NORMAL);
												  }
											  }
											  if (!game->_user._tutorial_completed)
											  {
												  if (game->_tutorial_step == TUTORIAL_STEP_BUY_HERO)
												  {
													  if (heroindex != 1)///archer hero
													  {
														  if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
														  {
															  _button_buy.SetState(BUTTON_STATE_LOCK);
														  }
													  }
												  }
											  }
											  else
											  {

											  }
											  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 60, _x + x, _y + y);
											  _button_buy.SetPos(_x + x, _y + y);
											  _button_buy.Render(G());
											  _button_buy.Update();
											  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);
											  spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
                                              if(_is_lock)
                                              {
                                                  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 8 + y, _LEFT, "DMG: ???");
                                                  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "Lv. ???");
                                              }
                                              else
                                              {
                                                  //GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 8 + y, _LEFT, "DMG: %lld", _value);
												  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 8 + y, _LEFT, "DMG: %s", _value_text);
                                                  GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "Lv. %d", _level);
                                              }
											
											  GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
											  G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
											  spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 1;
											  if (enought_coin)
											  {
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, "; %s", _coin_text);
												  //GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, "; %d", _cost_upgrade);
											  }
											  else
											  {
												  char text[20];
												  //int lenght = sprintf(text, "%s", _coin_text);
												  int lenght = sprintf(text, "%d", _cost_upgrade);
												  int text_w = (GET_SPRITE(SPRITEID_FONT_SHOPCOIN))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->StringToUnichar(text), 0, lenght) + 8;
												  int icon_w = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->GetFModuleWidth(25, 0);
												  G()->SetColorMask(0xffc90000);
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%s", _coin_text);
												  //GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%d", _cost_upgrade);
												  G()->ClearColorMask();
												  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - text_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "; ");
											  }

											  GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
											  spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 115 + x, _y + y + 4, _HCENTER, "Buy");
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 115 + x, _y + y + 24, _HCENTER, "This Hero");
											 // GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 44, _HCENTER, "Battle %d", _level_unlock);
											  GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
											  G()->ClearScale();
											  GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);

											  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
											  GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 80, _x + x - mw / 2 + 73, _y + y + 3);
                                              //_stars =
                                              GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224+_stars, _x + x - mw / 2 + 73, _y + y + 3- 55);
                                              
											  spacing = GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing = 2;
											  GET_SPRITE(SPRITEID_FONT_HERONAME)->DrawAnsiTextFormat(G(), _x + x - mw / 2 + 73, _y + y + 59, _HCENTER, "%s", _name);
											  GET_SPRITE(SPRITEID_FONT_HERONAME)->_char_spacing = spacing;
											  line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
											  GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 3;
											  spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
											  GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
											  GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y + 12, 330, _LEFT, "%s", _descript);
											  GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
											  GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
										  }
									  }
									  _notify_new.Render(_x + x - mw / 2 + 23, y);
	}
		break;
	case MENU_INGAME_BUTTON_RELICS:
		/*if (_index == 0)
		{
		if (_cost_upgrade > game->_user.GetGem())
		{
		if (_button_buy._state != BUTTON_STATE_LOCK)
		{
		_button_buy.SetState(BUTTON_STATE_LOCK);
		}
		enought_coin = false;
		}
		else
		{
		if (_button_buy._state == BUTTON_STATE_LOCK)
		{
		_button_buy.SetState(BUTTON_STATE_NORMAL);
		}
		}
		if (game->_user._quest_num_relics_own >= game->_num_max_item_relics)
		{
		if (_button_buy._state != BUTTON_STATE_LOCK)
		{
		_button_buy.SetState(BUTTON_STATE_LOCK);
		}
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 60, _x + x, _y + y);
		}
		else
		{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 59, _x + x, _y + y);
		}
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 77, _x + x, _y + y);
		_button_buy.SetPos(_x + x, _y + y);
		_button_buy.Render(G());
		_button_buy.Update();
		spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 0;
		G()->SetScale(_scale_text_button, _scale_text_button, _x + x, _y + y + 40);
		if (enought_coin)
		{
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + x, _y + y + 40, _HCENTER, "%d ;", _cost_upgrade);
		}
		else
		{
		char text[20];
		int lenght = sprintf(text, "%d", _cost_upgrade);
		int text_w = (GET_SPRITE(SPRITEID_FONT_SHOPCOIN))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->StringToUnichar(text), 0, lenght) + 8;
		int icon_w = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->GetFModuleWidth(26, 0);
		G()->SetColorMask(0xffc90000);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + x - icon_w / 2, _y + y + 40, _HCENTER, "%d", _cost_upgrade);
		G()->ClearColorMask();
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + x + text_w/2, _y + y + 40, _HCENTER, ";");
		}

		G()->ClearScale();
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
		}
		else*/
		if (_banner)
		{
			if (_button_buy._state != BUTTON_STATE_HIDE)
			{
				_button_buy.SetState(BUTTON_STATE_HIDE);
			}
			_button_buy.SetPos(_x + x, _y + y);
			if (strcmp(_name, "All Heroes") == 0)
			{
				GET_SPRITE(_spriteid)->DrawFrame(G(), 2, _x + x, _y + y);
			}
			else if (strcmp(_name, "All Towers") == 0)
			{
				GET_SPRITE(_spriteid)->DrawFrame(G(), 1, _x + x, _y + y);
			}
			else if (strcmp(_name, "Misc.") == 0)
			{
				GET_SPRITE(_spriteid)->DrawFrame(G(), 0, _x + x, _y + y);
			}
			else
			{
				GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
			}
			spacing = GET_SPRITE(SPRITEID_FONT_RELIC)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_RELIC)->_char_spacing = 2;
			GET_SPRITE(SPRITEID_FONT_RELIC)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 50, _y + y, _RIGHT | _VCENTER, "%s", _name);
			GET_SPRITE(SPRITEID_FONT_RELIC)->_char_spacing = spacing;
		}
		else
		{
			if (!_is_lock)
			{
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
				_button_buy.SetPos(_x + x, _y + y);
				//_button_buy.Render(G());
				_button_buy.Update();
				if (_button_buy._state != BUTTON_STATE_HIDE)
				{
					_button_buy.SetState(BUTTON_STATE_HIDE);
				}
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);
				spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "%s", _name);
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
				line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 5;
				spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y - 10, 480, _LEFT, "%s", _descript);
				GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
				//GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
				int heroindex = _index - 1;
				heroindex = _index;
                //printf("\n heroindex = %d",heroindex);
				game->_items_relics[heroindex].Render(_x + x - mw / 2 + 73, _y + y + 3);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
				//_stars =
				if (_stars >= 0)
				{
					GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224 + _stars, _x + x - mw / 2 + 73, _y + y + 3 - 55);
				}
			}
			else
			{
				if (_cost_upgrade > game->_user.GetGem())
				{
					/*if (_button_buy._state != BUTTON_STATE_LOCK)
					{
						_button_buy.SetState(BUTTON_STATE_LOCK);
					}*/
					enought_coin = false;
				}
				else
				{
					if (_button_buy._state == BUTTON_STATE_LOCK)
					{
						_button_buy.SetState(BUTTON_STATE_NORMAL);
					}
				}
				int relicindex = _index - 1;
				relicindex = _index;
				if (game->_tutorial_step == TUTORIAL_STEP_BUY_RELIC)
				{
					if (game->_items_relics[relicindex]._id != 1 || game->_items_relics[relicindex]._group != ITEMRELIC_GROUP_WEAPON)//blessing sword1
					{
						if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
						{
							_button_buy.SetState(BUTTON_STATE_LOCK);
						}
					}
				}
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 60, _x + x, _y + y);
				_button_buy.SetPos(_x + x, _y + y);
				_button_buy.Render(G());
				_button_buy.Update();
				G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
				spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 1;
				if (enought_coin)
				{
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ";%s", _coin_text);
					//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ";%d", _cost_upgrade);
				}
				else
				{
					char text[20];
					//int lenght = sprintf(text, "%s", _coin_text);
					int lenght = sprintf(text, "%d", _cost_upgrade);
					int text_w = (GET_SPRITE(SPRITEID_FONT_SHOPCOIN))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->StringToUnichar(text), 0, lenght) + 8;
					int icon_w = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->GetFModuleWidth(25, 0);
					G()->SetColorMask(0xffc90000);
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%s", _coin_text);
					//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 + icon_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "%d", _cost_upgrade);
					G()->ClearColorMask();
					GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - text_w / 2 - 110 + x, _y - 34 + y, _HCENTER, "; ");
				}

				GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
				spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 8, _HCENTER, "Buy");
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 38, _HCENTER, "This Relic");
				GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = spacing;
				G()->ClearScale();
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);
				spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "%s", _name);
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
				line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 5;
				spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y - 10, 330, _LEFT, "%s", _descript);
				GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
				GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
				//GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
				
				game->_items_relics[relicindex].Render(_x + x - mw / 2 + 73, _y + y + 3);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
			}
		}
		break;
	case MENU_INGAME_BUTTON_SHOP:
	{
									bool has_discount = false;
                                    /*
									if (!game->_iap_discount_time.isNullDay())
									{
										has_discount = true;
									}*/

									int param_price = CGameDesign::FileGeneral::CSheetiAP_design::price;
									int param_name = CGameDesign::FileGeneral::CSheetiAP_design::name;
#if defined (ANDROID_OS)
									int param_idPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::GG_ID;
#else
									int param_idPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::ID_Store;
#endif
									if (_id != SHOP_ID_FOLLOW_TW && _id != SHOP_ID_LIKE_FB && _id != SHOP_ID_RESTORE && _id != SHOP_ID_DOWN_MOREGAME)
									{
										if (strcmp(_id_string, "NONE") != 0)
										{
											sprintf(_id_string, "%s", game->GetDesignIAPString(_index, param_idPurcharse, has_discount));
											sprintf(_name, "%s", game->GetDesignIAPString(_index, param_name, has_discount));
											sprintf(_descript, "%s", game->GetDesignIAPString(_index, param_price, has_discount));
											//printf("\n 000 index = %d _id_string = %s, _descript = %s",_index,_id_string,_descript);
										}
									}
									else
									{
                                        if (!Device::IsNetworkAvailable())
										{

											if (_button_buy._state != BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_LOCK);
											}
										}
										else
										{
											if (_button_buy._state == BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_NORMAL);
											}
										}
									}
									if (strcmp(_id_string, "NONE") != 0)
									{
#if defined (MAC_OS)
										if (GAME()->_pineStore.IsSynPriceForProduct(_id_string))
										{
											sprintf(_descript, "%s", GAME()->_pineStore.GetPriceForProduct(_id_string));
										}
										else
#endif
										{
											if (_id != SHOP_ID_FOLLOW_TW && _id != SHOP_ID_LIKE_FB && _id != SHOP_ID_RESTORE && _id != SHOP_ID_DOWN_MOREGAME)
											{
												sprintf(_descript, "%s USD", game->GetDesignIAPString(_index, param_price, has_discount));
											}
										}
									}
									//printf("\n 000 _id_string = %s, _name = %s, _descript = %s",_id_string,_name,_descript);
									if (_id == SHOP_ID_DOUBLE_COIN)
									{
										if (!Device::IsNetworkAvailable())
										{
											if (_button_buy._state != BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_LOCK);
											}
										}
										else
										{
											if (_button_buy._state == BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_NORMAL);
											}
										}
										if (game->_user._has_double_coin)
										{
											if (_button_buy._state != BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_LOCK);
											}
											GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 60, _x + x, _y + y);
										}
										else
										{
											GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
										}
									}
									else
									{
										if (_id == SHOP_ID_DOWN_MOREGAME)
										{
											GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 192, _x + x, _y + y);
										}
										else
										{
											GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
										}
										
									}

									_button_buy.SetPos(_x + x, _y + y);
									_button_buy.Render(G());
									_button_buy.Update();
									GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 69, _x + x - mw / 2 + 73, _y + y + 3);
									spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
									GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
									line_space = GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing;
									GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing = 10;
									if (_id != SHOP_ID_RESTORE && _id != SHOP_ID_DOWN_MOREGAME)
									{
										GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, 350, _LEFT, "%s", _name);
									}
        
									GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing = line_space;
									GET_SPRITE(SPRITEID_HUD_GEMSHOP)->DrawFrame(G(), _id - 1, _x + x - mw / 2 + 73, _y + y + 3);

									if (_id < SHOP_ID_AUTO_ATT || _id == SHOP_ID_STARTER_PACK)
									{
										int hour = 0;
										int min = 0;
										int sec = 0;
										if (_id < SHOP_ID_AUTO_ATT)
										{
											if (has_discount)
											{
												if (_notify_new._state == NOTIFY_STATE_NONE)
												{
													_notify_new.Active();
												}
											}
											else
											{
												if (_notify_new._state == NOTIFY_STATE_ACTIVE)
												{
													_notify_new.Disable();
												}
											}
										}
										
										if (_id == SHOP_ID_STARTER_PACK)
										{
											if (!game->_iap_starter_time.isNullDay())
											{
												if (!Device::IsNetworkAvailable())
												{
													if (_button_buy._state != BUTTON_STATE_LOCK)
													{
														_button_buy.SetState(BUTTON_STATE_LOCK);
													}
												}
												else
												{
													if (_button_buy._state == BUTTON_STATE_LOCK)
													{
														_button_buy.SetState(BUTTON_STATE_LOCK);
													}
												}
												hour = game->_iap_starter_time.getHour();
												min = game->_iap_starter_time.getMinute();
												sec = game->_iap_starter_time.getSecond();
												if (game->_is_hacked_time)
												{
													hour = 255;
													min = 255;
													sec = 255;
												}
												spacing = GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "Special offer: %02dh%02dm%02ds", hour, min, sec);
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
											}
											else
											{
												if (_button_buy._state != BUTTON_STATE_LOCK)
												{
													_button_buy.SetState(BUTTON_STATE_LOCK);
												}
											}
											if (!Device::IsNetworkAvailable())
											{
												_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
												_anim_network.DrawAnimObject(G());
												_anim_network.UpdateAnimObject();
											}
										}
										else
										{
                                            /*
											if (!game->_iap_discount_time.isNullDay())
											{
												hour = game->_iap_discount_time.getHour();
												min = game->_iap_discount_time.getMinute();
												sec = game->_iap_discount_time.getSecond();
												if (game->_is_hacked_time)
												{
													hour = 255;
													min = 255;
													sec = 255;
												}
												spacing = GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "50%% OFF: %02dh%02dm%02ds", hour, min, sec);
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
											}
											else
											{
												//printf("\n end time");
											}*/
											if (!Device::IsNetworkAvailable())
											{
												_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
												_anim_network.DrawAnimObject(G());
												_anim_network.UpdateAnimObject();
												if (_button_buy._state != BUTTON_STATE_LOCK)
												{
													_button_buy.SetState(BUTTON_STATE_LOCK);
												}
											}
											else
											{
												if (_button_buy._state == BUTTON_STATE_LOCK)
												{
													_button_buy.SetState(BUTTON_STATE_LOCK);
												}
											}
										}
										
										//GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + y - 4, _LEFT, "+%lld GEMS", _value);
										G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
										//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 79, _x + x, _y + y + 56);
										spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y, _HCENTER | _VCENTER, "BUY");
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
										GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y - 35, _HCENTER, "%s", _descript);
										G()->ClearScale();
									}
									else if (_id == SHOP_ID_DOUBLE_COIN)
									{
										if (!Device::IsNetworkAvailable())
										{
											_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
											_anim_network.DrawAnimObject(G());
											_anim_network.UpdateAnimObject();
										}
                                        else if (!game->_user._has_double_coin)
                                        {
                                            if (_notify_new._state == NOTIFY_STATE_NONE)
                                            {
                                                if (_notify_new._anim.GetCurrentAnim() != 142)
                                                {
                                                    _notify_new._anim.SetAnim(142, true);
                                                }
                                                _notify_new.Active();
                                            }
                                        }
                                        else
                                        {
                                            if (_notify_new._state == NOTIFY_STATE_ACTIVE)
                                            {
                                                _notify_new.Disable();
                                            }
                                        }
                                        GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 120 + x, _y + y + 48, _RIGHT, "X2");
										//GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + y - 4, _LEFT, "x%lld COINS", _value);
										G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
										//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 79, _x + x, _y + y + 56);
										spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y, _HCENTER | _VCENTER, "BUY");
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
										GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y - 35, _HCENTER, "%s", _descript);
										//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 177, _x + x, _y + y - 4);
										G()->ClearScale();
									}
									else if (_id == SHOP_ID_WATCH_ADD)
									{
										//GAME()->_serverThread._isNetworkAvailable = true;
										if (!game->_watch_ads_time.isNullDay() || game->_is_hacked_time)
										{
											if (_button_buy._state != BUTTON_STATE_LOCK)
											{
												_button_buy.SetState(BUTTON_STATE_LOCK);
											}
											int hour = game->_watch_ads_time.getHour();
											int min = game->_watch_ads_time.getMinute();
											int sec = game->_watch_ads_time.getSecond();
											if (game->_is_hacked_time)
											{
												hour = 255;
												min = 255;
												sec = 255;
											}
											
											if (!Device::IsNetworkAvailable())
											{
												_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
												_anim_network.DrawAnimObject(G());
												_anim_network.UpdateAnimObject();
											}
											if (_notify_new._state == NOTIFY_STATE_ACTIVE)
											{
												_notify_new.Disable();
											}
											spacing = GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing;
											GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;
											GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "Next reward: %02dh%02dm%02ds", hour, min, sec);
											GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
										}
										else
										{
											if (!Device::IsNetworkAvailable())
											{
												if (_button_buy._state != BUTTON_STATE_LOCK)
												{
													_button_buy.SetState(BUTTON_STATE_LOCK);
												}
											}
											else
											{
												if (_button_buy._state == BUTTON_STATE_LOCK)
												{
													_button_buy.SetState(BUTTON_STATE_NORMAL);
												}
											}
											if (!Device::IsNetworkAvailable())
											{
												_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
												_anim_network.DrawAnimObject(G());
												_anim_network.UpdateAnimObject();
											}
                                            else
											if (_notify_new._state == NOTIFY_STATE_NONE)
											{
												_notify_new.Active();
											}
											spacing = GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing;
											GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;

											int param_type = CGameDesign::FileGeneral::CSheetFree_Gift::Type;
											int param_value = CGameDesign::FileGeneral::CSheetFree_Gift::Value;
											int type = game->GetDesignFreeGift(game->_user._watch_ad_times, param_type);
											int value = game->GetDesignFreeGift(game->_user._watch_ad_times, param_value);
											/*switch (type)
											{
											case WATCH_ADS_REWARD_TYPE_COIN:
											{
																			   int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
																			   int reward_coin = game->GetDesignTreasure(game->_battle_current, param_coin);
																			   value *= reward_coin;
																			   GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "+%d Coins", value);
											}
												break;
											case WATCH_ADS_REWARD_TYPE_GEM:
												if (value > 1)
												{
													GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "+%d Gems", value);
												}
												else
												{
													GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "+%d Gem", value);
												}

												break;
											case WATCH_ADS_REWARD_TYPE_AUTO_ATT:
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "+%d Auto attack", value);
												break;
											case WATCH_ADS_REWARD_TYPE_AUTO_SKILL:
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "+%d Auto skill", value);
												break;
											case WATCH_ADS_REWARD_TYPE_DOUBLE_COIN:
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "Double coin in %d seconds", value);
												break;
											default:
												break;
											}*/
											GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
											
										}
										G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
										spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y - 10, _HCENTER | _VCENTER, "VIEW ADS");
										GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
										G()->ClearScale();
									}
									else
									{
										if (_id != SHOP_ID_FOLLOW_TW && _id != SHOP_ID_LIKE_FB && _id != SHOP_ID_RESTORE && _id != SHOP_ID_DOWN_MOREGAME)
										{
#if defined (MAC_OS)
#else
											sprintf(_descript, "%s", game->GetDesignIAPString(_index, param_price, has_discount));
#endif
                                            //quoc.nguyen
                                            bool checkButton = false;
                                            if (_id == SHOP_ID_OPEN_BOX)
                                            {                                               
                                                if (!game->_timeBuyOpenBox.isNullDay() || game->_is_hacked_time)
                                                {
                                                    if (_button_buy._state != BUTTON_STATE_LOCK)
                                                    {
                                                        _button_buy.SetState(BUTTON_STATE_LOCK);
                                                    }
                                                    int hour = game->_timeBuyOpenBox.getHour();
                                                    int min = game->_timeBuyOpenBox.getMinute();
                                                    int sec = game->_timeBuyOpenBox.getSecond();
                                                    if (game->_is_hacked_time)
                                                    {
                                                        hour = 255;
                                                        min = 255;
                                                        sec = 255;
                                                    }
                                                    
                                                    int spacing = GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing;
                                                    GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;
                                                    GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + 56 + y, _LEFT, "%02dh%02dm%02ds", hour, min, sec);
                                                    GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
                                                }
                                                else
                                                {
                                                    checkButton = true;
                                                }
                                            }
                                            else
                                            {
                                                checkButton = true;
                                            }
                                            
                                            
                                            
											if (game->_user.GetGem() >= _price)
											{
                                                if (checkButton)
                                                {
                                                    if (_button_buy._state == BUTTON_STATE_LOCK)
                                                    {
                                                        _button_buy.SetState(BUTTON_STATE_NORMAL);
                                                    }
                                                }
												G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
												//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 79, _x + x, _y + y + 56);
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y, _HCENTER | _VCENTER, "BUY");
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
												GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y - 35, _HCENTER, "%d ;", _price);
												G()->ClearScale();
											}
											else
											{
                                                if (checkButton)
                                                {
                                                    /*if (_button_buy._state != BUTTON_STATE_LOCK)
                                                    {
                                                        _button_buy.SetState(BUTTON_STATE_LOCK);
                                                    }*/
                                                }
												
												char text[20];
												int lenght = sprintf(text, "%d", _price);
												int text_w = (GET_SPRITE(SPRITEID_FONT_IAP))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_IAP)->StringToUnichar(text), 0, lenght) + 8;
												int icon_w = GET_SPRITE(SPRITEID_FONT_IAP)->GetFModuleWidth(25, 0);
												G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
												G()->SetColorMask(0xffc90000);
												GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x - icon_w / 2, _y + y - 35, _HCENTER, "%d ", _price);
												G()->ClearColorMask();
												GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x + text_w / 2, _y + y - 35, _HCENTER, ";");
												//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 79, _x + x, _y + y + 56);
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y, _HCENTER | _VCENTER, "BUY");
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
												G()->ClearScale();
											}
										}
										else
										{
											if (_id == SHOP_ID_RESTORE)
											{
												G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y - 10, _HCENTER | _VCENTER, "RESTORE");
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
												G()->ClearScale();
												GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiPageFormat(G(), _x - mw / 2 + 146 + x, _y + y, 350, _LEFT | _VCENTER, "%s", _name);

												}
											else if (_id == SHOP_ID_DOWN_MOREGAME)
											{
												G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y - 10, _HCENTER | _VCENTER, "GET IT NOW!");
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
												G()->ClearScale();
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->DrawAnsiTextFormat(G(), _x + x - 55, _y + y - 32, _HCENTER, "%s", _name);
												GET_SPRITE(SPRITEID_FONT_DISCOUNT)->_char_spacing = spacing;
												spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
												GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x + x - 55, _y + y - 5, _HCENTER , "%s", _descript);
												GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
												GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + x - 72, _y + y + 28, _HCENTER, "+%d", _value);
												game->_down_moregame_glow.SetPos(_x + x, _y + y);
												game->_down_moregame_glow.DrawAnimObject(G());
												game->_down_moregame_glow.UpdateAnimObject();
											}
											else
											{
												G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
												spacing = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
												if (_id == SHOP_ID_FOLLOW_TW)
												{
													GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y - 10, _HCENTER | _VCENTER, "FOLLOW");
												}
												else
												{
													GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), _x + x + mw / 2 - 110, _y + y - 10, _HCENTER | _VCENTER, "LIKE");
												}
												
												GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = spacing;
												G()->ClearScale();
												GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + y + 35, _LEFT, "+%d ;", _value);

											}
                                            if (!Device::IsNetworkAvailable())
											{
												_anim_network.SetPos(_x + mw / 2 + x - 200, _y + y - 46);
												_anim_network.DrawAnimObject(G());
												_anim_network.UpdateAnimObject();
											}
										}
									}
									GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
									GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
									_notify_new.Render(_x + mw / 2 - 110 + x + 76, y);

	}
		break;
	default:
		break;
	}
	/*int bx = 50;
	int by = _button_buy.TZ_GetY();
	int bw = k_SCREEN_WIDTH - 100;
	int bh = _button_buy.TZ_GetHeight();
	G()->SetColor(0x90ff0000);
	G()->FillRect(bx, by, bw, bh, true);*/
}
void TDGame::MenuInfo::Modify(int indexitem)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	//_index = indexitem;
	switch (game->_ingame_menu_type)
	{
	case MENU_INGAME_BUTTON_GATE:
	{
									if (_index == 0)
									{
										int param_valueup = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
										_level = game->_castle.GetLevel();
										INT_TIME hp_normal = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_valueup);
										_value = hp_normal;
										_value_plus = game->_castle._hp_max - hp_normal;
										_cost_upgrade = game->_castle.GetCostUpgrade();
										_value_up = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level + 1, param_valueup) - hp_normal;
										if (game->_castle._level_max)
										{
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
											_button_buy.SetState(BUTTON_STATE_NORMAL);
											_button_buy.SetPos(_x, _y);
											game->_ingame_menu_scroll._touch_id = -1;
											_touch_y = 0;
											_touch_x = 0;
											_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
										}
									}
									else
									{
										//int param_valueup = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
										_level = game->_weapon[_index - 1].GetLevel();
										INT_TIME damage_normal = game->_weapon[_index - 1].GetDamageBasic();
										_value = damage_normal;
										_value_plus = game->_weapon[_index - 1].GetDamageExtra();
										_cost_upgrade = game->_weapon[_index - 1].GetCostUpgrade();
										_value_up = game->_weapon[_index - 1].GetDamageLevelUp() - damage_normal;
										_is_lock = game->_weapon[_index - 1].IsLock();
										if (game->_weapon[_index - 1]._level_max)
										{
											_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
											_button_buy.SetState(BUTTON_STATE_NORMAL);
											_button_buy.SetPos(_x, _y);
											game->_ingame_menu_scroll._touch_id = -1;
											_touch_y = 0;
											_touch_x = 0;
											_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
										}
									}
									game->ConvertMoneyInbalace(_value_plus, _value_plus_text);
									game->ConvertMoneyInbalace(_value, _value_text);
									game->ConvertMoneyInbalace(_value_up, _value_up_text);
									game->ConvertMoneyInbalace(_cost_upgrade, _coin_text);
									int param_name = CGameDesign::FileCastle_design::CSheetCastle_General::Name;
									sprintf(_name, "%s", game->GetDesignCastleName(_index, param_name));
        
                                    int param_decs = CGameDesign::FileCastle_design::CSheetCastle_General::Description;
                                    sprintf(_descript,"%s",game->GetDesignCastleName(_index, param_decs));
	}
		break;
	case MENU_INGAME_BUTTON_HEROES:
	{
									  //if (_index != 0)
		{
			int heroindex = _index - 1;
			heroindex = _index;
			int param_valueup = CGameDesign::FileHero_design::CSheetArcher::Attack;
			_level = game->_hero_inbattle_arr[heroindex].GetLevel();
			INT_TIME damage_normal = game->_hero_inbattle_arr[heroindex].GetDamageNormal();
			_value = damage_normal;
			_value_plus = game->_hero_inbattle_arr[heroindex].GetDamageExtra();
			_cost_upgrade = (int)game->_hero_inbattle_arr[heroindex].GetCostUpgrade();
			_value_up = game->_hero_inbattle_arr[heroindex].GetDamageLevelUp() - damage_normal;
            //_stars = game->_hero_inbattle_arr[heroindex].GetStars();
			_stars = game->_hero_inbattle_arr[heroindex].GetNumStars();
			sprintf(_name, "%s", game->_hero_inbattle_arr[heroindex].GetName());
			sprintf(_descript, "%s", game->_hero_inbattle_arr[heroindex]._skill.GetDescript());
			if (game->_hero_inbattle_arr[heroindex]._level_max)
			{
				_button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 138);
				_button_buy.SetState(BUTTON_STATE_NORMAL);
				_button_buy.SetPos(_x, _y);
				game->_ingame_menu_scroll._touch_id = -1;
				_touch_y = 0;
				_touch_x = 0;
				_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
			}
			game->ConvertMoneyInbalace(_value_plus, _value_plus_text);
			game->ConvertMoneyInbalace(_value, _value_text);
			game->ConvertMoneyInbalace(_value_up, _value_up_text);
			game->ConvertMoneyInbalace(_cost_upgrade, _coin_text);
		}
	}
		break;
	case MENU_INGAME_BUTTON_RELICS:
	{

	}
		break;
	case MENU_INGAME_BUTTON_SHOP:
		break;
	default:
		break;
	}
}
void TDGame::MenuInfo::AddNew(float x, float y, int indexitem)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	_x = x;
	_y = y;
	_index = indexitem;
	_card_touch_id = -1;
	_touch_y = 0;
	_touch_x = 0;
	_card_touch_block = true;
	_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
	_scale_text_button = 1.0f;
	_has_touch = false;
	_notify_new.Init(SPRITEID_HUD_MAINMENU, -1, 95, 0, _y - 45, 0);
	_effect_levelup.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
	_effect_levelup.SetAnim(96, false);
	_effect_levelup.SetPos(0, 0);
	_effect_levelup_start = false;
	_is_new = true;
	switch (game->_ingame_menu_type)
	{

	case MENU_INGAME_BUTTON_HEROES:
		//{
		//								  _level = 0;
		//								  _value = 0;
		//								  _cost_upgrade = 0;
		//								  _value2 = 0;
		//								  _value_up = 0;
		//								  _is_lock = false;
		//								  _deployed = false;
		//								  /*if (_index == 0)
		//								  {
		//								  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		//								  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 82);
		//								  _button_buy.SetPos(_x, _y);
		//								  _cost_upgrade = 10;
		//								  }
		//								  else*/
		//								  {

		//									  int param_valueup = CGameDesign::FileHero_design::CSheetArcher::Attack;
		//									  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		//									  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
		//									  _button_buy.SetPos(_x, _y);
		//									  if (_index >= game->_user._num_heroes_collected)
		//									  {
		//										  _level = 1;
		//										  int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
		//										  int param_skill = CGameDesign::FileHero_design::CSheetHero_General::Skill;
		//										  int param_id = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		//										  int param_descript = CGameDesign::FileSkill_design::CSheetSheet1::Description;
		//										  int heroid = game->GetDesignHeroGeneral(_index, param_id);
		//										  int skillid = game->GetDesignHeroGeneral(heroid - 1, param_skill) - 1;
		//										  _value = game->GetDesignHeroInfo(heroid, _level, param_damage);
		//										  _cost_upgrade = game->_hero_inbattle_arr[heroid - 1].GetCostUnlock();
		//										  _value2 = 0;
		//										  _value_up = 0;
		//										  sprintf(_name, "%s", game->GetDesignHeroName(heroid - 1));
		//										  sprintf(_descript, "%s", game->GetDesignSkillString(skillid, param_descript));
		//										  _is_lock = false;
		//										  _deployed = false;
		//										  _spriteid = game->_hero_sprite[heroid - 1];
		//										  _frameid = 4;
		//									  }
		//									  else
		//									  {
		//										  int heroindex = _index - 1;
		//										  heroindex = _index;
		//										  _level = game->_hero_inbattle_arr[heroindex].GetLevel();
		//										  INT_TIME damage_normal = game->_hero_inbattle_arr[heroindex].GetDamageNormal();
		//										  _cost_upgrade = (int)game->_hero_inbattle_arr[heroindex].GetCostUpgrade();
		//										  _value = damage_normal;
		//										  _value_plus = game->_hero_inbattle_arr[heroindex].GetDamage() - damage_normal;
		//										  _value_up = game->_hero_inbattle_arr[heroindex].GetDamageLevelUp() - damage_normal;
		//										  sprintf(_name, "%s", game->_hero_inbattle_arr[heroindex].GetName());
		//										  sprintf(_descript, "%s", game->_hero_inbattle_arr[heroindex]._skill.GetDescript());
		//										  _is_lock = false;
		//										  _deployed = game->_hero_inbattle_arr[heroindex]._deployed;
		//										  _spriteid = game->_hero_inbattle_arr[heroindex].GetSpriteID();
		//										  _frameid = 4;
		//									  }

		//								  }
		//}
		//	_card_touch_block = false;
		break;
	case MENU_INGAME_BUTTON_RELICS:
	{
									  _level = 0;
									  _value = 0;
									  _cost_upgrade = 0;
									  _value2 = 0;
									  _value_up = 0;
									  _is_lock = false;
									  _deployed = false;

									  _button_buy.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
									  _button_buy.SetAnim(SPRITEID_HUD_MAINMENU, 78);
									  _button_buy.SetPos(_x, _y);
									  _button_buy.SetState(BUTTON_STATE_HIDE);
									  sprintf(_name, "%s", game->_items_relics[_index - 1]._name);
									  sprintf(_descript, "%s", game->_items_relics[_index - 1]._descript);
									  _card_touch_block = false;
	}
		break;
	default:
		break;
	}
}
void TDGame::MenuInfo::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	switch (_scale_text_button_state)
	{
	case EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL:
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_START:
		if (_scale_text_button < 1.15f)
		{
			_scale_text_button = 1.15f;
		}
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_END:
		if (_scale_text_button > 1.0f)
		{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
			/*_scale_text_button -= 0.015f;
			if (_scale_text_button <= 1.0f)
			{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
			}*/
		}
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END:
		if (_scale_text_button > 1.0f)
		{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
		}
		break;
	default:
		break;
	}
	_notify_new.Update();
	_effect_levelup.UpdateAnimObject();
	if (game->_ingame_menu_scroll._isScroll)
	{
		_card_touch_id = -1;
		return;
	}
	_has_touch = UpdateTouch();
	if (!game->_user._tutorial_completed)
	{
		if (game->_tutorial_step != TUTORIAL_STEP_DEPLOY_HERO)
		{
			return;
		}
		else
		{
			_has_touch = false;
		}
	}

	if (!_has_touch)
	{
		//printf("\n debug touch ingame");
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			if (!_card_touch_block)
			{

				int x = 50;
				int y = _button_buy.TZ_GetY();
				int w = k_SCREEN_WIDTH - 100;
				int h = _button_buy.TZ_GetHeight();
				if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
				{
					if (TOUCHS(i)->_state == TOUCH_DOWN)
					{
						if (_card_touch_id == -1 && game->_ingame_menu_scroll._touch_id == -1)
						{
							if (!_deployed && !_is_lock)
							{
								GAME()->PlaySFX(SFX_BUTTON);
								_card_touch_id = TOUCHS(i)->_id;
								_touch_y = TOUCHS(i)->y;
								_touch_x = TOUCHS(i)->x;
								game->_ingame_menu_scroll._touch_id = -1;
							}
							else
							{
								if (game->_ingame_menu_scroll._touch_id == -1)
								{
									game->_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
									game->_ingame_menu_scroll.Set();
									game->_ingame_menu_scroll.SetState(0);
									game->_ingame_menu_scroll._offset_y = 0;
									game->_ingame_menu_scroll._isScroll = true;
									game->_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
								}
							}
							//printf("\n debug _card_touch_block[%d] = %d,_card_touch_id = %d,_is_lock = %d",_index, _card_touch_block, _card_touch_id, _is_lock);
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_DRAG)
					{
						if (_card_touch_id == TOUCHS(i)->_id)
						{

							float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
							if (dis >= 5)
							{
								if (game->_ingame_menu_scroll._touch_id == -1)
								{
									game->_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
									game->_ingame_menu_scroll.Set();
									game->_ingame_menu_scroll.SetState(0);
									game->_ingame_menu_scroll._offset_y = 0;
									game->_ingame_menu_scroll._isScroll = true;
									game->_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
									_card_touch_id = -1;
								}
							}
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_UP)
					{
						if (_card_touch_id == TOUCHS(i)->_id)
						{
							if (game->_ingame_menu_type == MENU_INGAME_BUTTON_HEROES)
							{
								if (game->_num_hero_deployed < NUM_MAX_HERO_INBATTLE)
								{
									_deployed = true;
									int heroindex = _index - 1;
									heroindex = _index;
									game->HeroDeployActive(game->_hero_inbattle_arr[heroindex].GetHeroID(), game->_num_hero_deployed);
									game->_num_hero_deployed++;
								}
							}
							game->_ingame_menu_scroll._touch_id = -1;
							_card_touch_id = -1;
						}
					}
				}
				else
				{
					if (_card_touch_id == TOUCHS(i)->_id)
					{
						if (TOUCHS(i)->_state == TOUCH_UP)
						{
							_touch_y = 0;
							_touch_x = 0;
							_card_touch_id = -1;
							game->_ingame_menu_scroll._touch_id = -1;
						}
						else if (TOUCHS(i)->_state == TOUCH_DRAG)
						{
							float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
							if (dis >= 5)
							{
								_touch_y = 0;
								_touch_x = 0;
								_card_touch_id = -1;
								if (game->_ingame_menu_scroll._touch_id == -1)
								{
									game->_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
									game->_ingame_menu_scroll.Set();
									game->_ingame_menu_scroll.SetState(0);
									game->_ingame_menu_scroll._offset_y = 0;
									game->_ingame_menu_scroll._isScroll = true;
									game->_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
								}
							}
						}
					}
				}
			}
			else
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_card_touch_id == TOUCHS(i)->_id)
					{
						_touch_y = 0;
						_touch_x = 0;
						_card_touch_id = -1;
						game->_ingame_menu_scroll._touch_id = -1;
					}
				}
			}
		}
	}
}
bool TDGame::MenuInfo::UpdateTouch()
{
	TDGame *game = (TDGame*)GAME()->_current_game;


	bool ret = false;
	int index = -1;
	bool pressed = false;
	if (game->_dialogMng.isOpenDialog())
	{
		return ret;
	}
  
	if (_button_buy._state == BUTTON_STATE_ACTIVE)
	{
		if (_button_buy.NeedAction())
		{
			switch (game->_ingame_menu_type)
			{
			case MENU_INGAME_BUTTON_GATE:
				if (_index == 0)
				{
					if (_cost_upgrade <= game->_user.GetCoin())
					{
						game->_castle.LevelUp();
						game->_user.AddCoin(-_cost_upgrade, false);
					}
                    else
                    {
						char text[256];
						sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
						game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
						/*game-> _openShopFromGate = true;
                        game-> _ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
                        game->SetState(k_GS_INGAME_MENU);*/
                    }
				}
				else
				{
					if (_cost_upgrade <= game->_user.GetCoin())
					{
						if (game->_weapon[_index - 1].IsLock())
						{
							game->_ingame_menu_max_item_scroll++;
							game->_ingame_menu_scroll.SetMax(game->_ingame_menu_max_item_scroll*(5 + INGAME_MENU_ITEM_HEIGHT) - 3 * INGAME_MENU_ITEM_HEIGHT);
						}
                        game->_weapon[_index - 1]._current_index = _index-1;
						game->_weapon[_index - 1].LevelUp();
                       
						game->_user.AddCoin(-_cost_upgrade, false);
						if (!game->_user._tutorial_completed)
						{
							if (game->_tutorial_step == TUTORIAL_STEP_BUILD_TOWER)
							{
								/*game->_user._tutorial_step = TUTORIAL_STEP_FREE;*/
								game->_tutorial_step = TUTORIAL_STEP_FREE;
							}
						}
					}
                    
                    else
                    {
						char text[256];
						sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
						game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
						/*game-> _openShopFromGate = true;
						game-> _ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
						game->SetState(k_GS_INGAME_MENU);*/
                    }
				}
				Modify(0);
				break;
			case MENU_INGAME_BUTTON_HEROES:
				/*if (_index == 0)
				{
				if (_cost_upgrade <= game->_user.GetGem())
				{
				int summon_hero_id = game->GetHeroSummonRandom();
				if (summon_hero_id >= 0)
				{
				GAME()->PlaySFX(SFX_PURCHASE);
				game->_user.AddGem(-_cost_upgrade);
				game->_hero_inbattle_arr[game->_user._num_heroes_collected].Init(summon_hero_id, 1, false);
				int sprite = game->_hero_inbattle_arr[game->_user._num_heroes_collected].GetSpriteID();
				int heroid = game->_hero_inbattle_arr[game->_user._num_heroes_collected].GetHeroID();
				game->_hero_inbattle_arr[game->_user._num_heroes_collected].SetPos(100 + 40, ROAD_POSY - 10);
				int x = k_SCREEN_WIDTH / 2;
				int y = 100 + game->_ingame_menu_num_item * (INGAME_MENU_ITEM_HEIGHT + 5);
				game->_menu_info_arr[game->_ingame_menu_num_item].AddNew(x, y, game->_ingame_menu_num_item);
				game->_ingame_menu_num_item++;
				game->_ingame_menu_scroll.SetMax(game->_ingame_menu_num_item*(5 + INGAME_MENU_ITEM_HEIGHT) - 3 * INGAME_MENU_ITEM_HEIGHT);
				}

				}
				}
				else*/
			{
											  int heroindex = _index - 1;
											  heroindex = _index;
											  if (!_is_lock)
                                              {
                                                  if (_cost_upgrade <= game->_user.GetCoin())
                                                  {
                                                      _effect_levelup_start = true;
                                                      _effect_levelup.SetAnim(96, false);
                                                      game->_hero_inbattle_arr[heroindex].LevelUp();
                                                      game->_user.AddCoin(-_cost_upgrade, false);
                                                      int heroid = game->_hero_inbattle_arr[heroindex].GetHeroID();
                                                      int level = game->_hero_inbattle_arr[heroindex].GetLevel();
                                                      bool deploy = game->_hero_inbattle_arr[heroindex]._deployed;
													  int rar = game->_hero_inbattle_arr[heroindex]._rar_level;
                                                      int slotnumber = game->_user._hero_arr[heroindex]._slot_deploy_number;
                                                      game->_user.ModifyNewHeroes(heroid, level, deploy, slotnumber,rar);
                                                  }
                                                  else
                                                  {
													  char text[256];
													  sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
													  game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
													  /*game-> _openShopFromGate = true;
													  game-> _ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
													  game->SetState(k_GS_INGAME_MENU);*/
                                                  }
                                                  Modify(0);
                                              }
											  else
											  {
                                                  /*
												  if (_id == EVENT_HERO_ID_AVAILABLE)
												  {
#if !defined (ANDROID_OS)
													  if (GAME()->_serverThread._isNetworkAvailable)
													  {
														  GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_GET_INVITATION_CODE);
                                                          GAME()->_processing_view_type = PROCESSING_VIEW_CHECK_NETWORK;
                                                          GAME()->_loading_count_frame = 0;
                                                          GAME()->_processing_time_out = PROCESSING_TIME_OUT;
													  }
#endif
												  }
												  else
                                                   */
												  {
													  if (_cost_upgrade <= game->_user.GetGem())
													  {
														  
														  GAME()->PlaySFX(SFX_PURCHASE);
														  _effect_levelup_start = true;
														  _effect_levelup.SetAnim(96, false);
														  game->_user.AddGem(-_cost_upgrade);
														  game->_hero_inbattle_arr[heroindex].Modify(_id, game->GetLevelUnlockNewHero(_stars), false, false, 0, 0, 0,false);
														  game->_hero_inbattle_arr[heroindex].SetPos(100 + 40, ROAD_POSY - 10);
														  game->ReInitHero();
														  if (!game->_user._tutorial_completed)
														  {
															  game->_tutorial_step = TUTORIAL_STEP_DEPLOY_HERO;
														  }
														  game->_user.UserDataSave();
													  }
													  else
													  {
														  char text[256];
														  sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
														  game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
														  /*game-> _openShopFromGate = true;
														  game-> _ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
														  game->SetState(k_GS_INGAME_MENU);*/
													  }
                                                      
												  }
											  }
			}
				break;
			case MENU_INGAME_BUTTON_RELICS:
			{
											  if (_cost_upgrade <= game->_user.GetGem())
											  {
												  GAME()->PlaySFX(SFX_PURCHASE);
												  int x = k_SCREEN_WIDTH / 2;
												  int y = 100 + game->_ingame_menu_num_item * (INGAME_MENU_ITEM_HEIGHT + 5);
												  //game->SummonRelics();
												  //game->_items_relics[game->_user._quest_num_relics_own].Init(SPRITEID_HUD_ITEM, game->_items_relics[_index]._group, game->_items_relics[_index]._id, 0, 0,false);
												  game->_user.AddNewRelics(game->_items_relics[_index]._id, game->_items_relics[_index]._group);
												  if (game->_tutorial_step == TUTORIAL_STEP_BUY_RELIC)
												  {
													  game->_tutorial_step = TUTORIAL_STEP_FREE;
													  game->_user._tutorial_step = TUTORIAL_STEP_BUY_RELIC_COMPLETED;
												  }
												  else
												  {
													  game->_user.AddGem(-_cost_upgrade);
													  game->_user._tutorial_step = TUTORIAL_STEP_COMPLETED_2;
												  }

												  //game->_menu_info_arr[game->_ingame_menu_num_item].AddNew(x, y, game->_ingame_menu_num_item);
												  /*game->_ingame_menu_max_item_scroll++;
												  game->_ingame_menu_num_item++;
												  if (game->_ingame_menu_max_item_scroll > 3)
												  {
												  game->_ingame_menu_scroll.SetMax(game->_ingame_menu_max_item_scroll*( 5 + INGAME_MENU_ITEM_HEIGHT) - 3 * INGAME_MENU_ITEM_HEIGHT);
												  }*/
												  
												  game->ReInitRelics();
												  game->ModifyInfo(game->_items_relics[_index]._group, game->_items_relics[_index]._id);
											  }
											  else
											  {
												  char text[256];
												  sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
												  game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
												  /*game-> _openShopFromGate = true;
												  game-> _ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
												  game->SetState(k_GS_INGAME_MENU);*/
											  }
			}


				break;
			case MENU_INGAME_BUTTON_SHOP:
				if (_id < SHOP_ID_AUTO_ATT || _id == SHOP_ID_DOUBLE_COIN || _id == SHOP_ID_STARTER_PACK)
				{
#if defined (MAC_OS)
					//purchase
                    if(Device::IsNetworkAvailable())
					{
						if (GAME()->_pineStore.IsSynPriceForProduct(_id_string))
						{
							PurchaseProduct(_id_string);
						}
						GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
						GAME()->_loading_count_frame = 0;
						GAME()->_processing_time_out = PROCESSING_TIME_OUT;
						GAME()->_is_purchase_procesing = true;
					}
					printf("\n iap id = %d",_id);
#elif defined (ANDROID_OS)
					if (Device::IsNetworkAvailable())
					{
						//if (GAME()->_pineStore.IsSynPriceForProduct(_id_string))
						{
							PurchaseProductWithType(_id_string, 3);
						}
						GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
						GAME()->_loading_count_frame = 0;
						GAME()->_processing_time_out = PROCESSING_TIME_OUT;
						GAME()->_is_purchase_procesing = true;
					}
					//PDEBUG("\n iap id = %d", _id);
#else
					
					/*bool has_discount = false;
					if (!game->_iap_discount_time.isNullDay())
					{
						has_discount = true;
					}
					game->ShopIAPFuncActive(_id, has_discount);*/
#endif
				}
				else
				{
					
					if (game->_user.GetGem() >= _price)
					{
						game->ShopFuncActive(_id, _value);
						game->_user.AddGem(-_price);
					}
					else
					{
						char text[256];
						sprintf(text, "Do you want to buy more Coins/Gems from the Shop?");
						game->_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_BUY_IAP, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "MORE COINS/GEMS?", text, 0, 0);
					}
					
				}
				game->_user.UserDataSave();
				break;
			default:
				break;
			}
			if (_button_buy._state != BUTTON_STATE_LOCK && _button_buy._state != BUTTON_STATE_HIDE)
			{
				_button_buy.SetState(BUTTON_STATE_NORMAL);
			}
			return true;
		}
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		if (_button_buy._state == BUTTON_STATE_LOCK || _button_buy._state == BUTTON_STATE_HIDE)
		{
			continue;
		}

		int x = _button_buy.TZ_GetX();
		int y = _button_buy.TZ_GetY();
		int w = _button_buy.TZ_GetWidth();
		int h = _button_buy.TZ_GetHeight();
		Button *button = &_button_buy;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				//printf("\n touch down buy button = %d", button->_touch_id);
				if (button->_touch_id == -1)
				{

					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_START;
					button->SetState(BUTTON_STATE_SELECT);
					button->_touch_id = TOUCHS(i)->_id;
					_touch_y = TOUCHS(i)->y;
					_touch_x = TOUCHS(i)->x;
					GAME()->PlaySFX(SFX_BUTTON);
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
				if (button->IsAction(TOUCHS(i)->_id))
				{
					/*float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
					if (dis >= 5)
					{
						button->_touch_id = -1;
						button->SetState(BUTTON_STATE_NORMAL);
						pressed = false;
						_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END;
						if (game->_ingame_menu_scroll._touch_id == -1)
						{
							game->_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
							game->_ingame_menu_scroll.Set();
							game->_ingame_menu_scroll.SetState(0);
							game->_ingame_menu_scroll._offset_y = 0;
							game->_ingame_menu_scroll._isScroll = true;
							game->_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
						}
					}
					_touch_y = TOUCHS(i)->y;
					_touch_x = TOUCHS(i)->x;*/
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (button->IsAction(TOUCHS(i)->_id))
				{
					button->SetState(BUTTON_STATE_ACTIVE);
					pressed = true;
					_touch_y = 0;
					_touch_x = 0;
					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
					_card_touch_id = -1;
					game->_ingame_menu_scroll._touch_id = -1;
				}
			}
			if (button->IsAction(TOUCHS(i)->_id))
			{
				pressed = true;
			}
		}
		else
		{
			if (button->IsAction(TOUCHS(i)->_id))
			{
				pressed = true;
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					button->SetState(BUTTON_STATE_NORMAL);
					button->_touch_id = -1;
					
					_touch_y = 0;
					_touch_x = 0;
					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
					_card_touch_id = -1;
					game->_ingame_menu_scroll._touch_id = -1;
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					/*float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
					if (dis >= 5)
					{
						button->_touch_id = -1;
						button->SetState(BUTTON_STATE_NORMAL);
						pressed = false;
						_touch_y = 0;
						_touch_x = 0;
						_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END;
						if (game->_ingame_menu_scroll._touch_id == -1)
						{
							game->_ingame_menu_scroll._last_touch_y = TOUCHS(i)->y;
							game->_ingame_menu_scroll.Set();
							game->_ingame_menu_scroll.SetState(0);
							game->_ingame_menu_scroll._offset_y = 0;
							game->_ingame_menu_scroll._isScroll = true;
							game->_ingame_menu_scroll._touch_id = TOUCHS(i)->_id;
						}
					}*/
				}
			}
		}
	}
	return pressed;
}

void TDGame::CastleInfoRender(float x, float y, int opac)
{
	y -= _castle_info_scrolly;
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 82, x, y);
	int castle_damage_basic = GetDamageWeaponBasic();
	int castle_damage_bonus = 0;
	int castle_damage_per = 0;
	int hero_total_damage = 0;
	int hero_damage_basic = 0;
	int hero_critical = 0;
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		if (!_weapon[i].IsLock())
		{
			castle_damage_per += _weapon[i].GetDamage() / (_weapon[i].GetAttackSpeed()*1.0f / FPS_MAX);
			castle_damage_bonus += _weapon[i].GetBonusDamage();
		}
	}
	int spacing = 0;
	int mx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleX(82, 1);
	int my1 = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(82, 1) + 15;
	int my2 = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(82, 2) + 15;
	spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + mx, y + my1, _LEFT, "Castle Status:");
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 20, _LEFT, "Basic DMG: %d", castle_damage_basic);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 40, _LEFT, "Bonus DMG: %d", castle_damage_bonus);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 60, _LEFT, "DMG per second: %d", castle_damage_per);
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	hero_total_damage = GetDamageHeroesBasic();
	spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + mx, y + my2, _LEFT, "Heroes Status:");
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + 20, _LEFT, "Total Basic DMG: %d", hero_total_damage);

	int hero_info_y = 0;
	int count_hero = 0;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			if (index_inbattle < 0 || !_hero_inbattle_arr[index_inbattle]._deployed)
			{
				continue;
			}
			hero_info_y = count_hero * 65 + 45;
			hero_damage_basic = _hero_inbattle_arr[index_inbattle].GetDamage();
			hero_critical = _hero_inbattle_arr[index_inbattle].GetCritical();
			GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + hero_info_y, _LEFT, "%s:", _hero_inbattle_arr[index_inbattle].GetName());
			GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + hero_info_y + 20, _LEFT, "Basic DMG: %d", hero_damage_basic);
			GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + hero_info_y + 40, _LEFT, "Critical chance: %d", hero_critical);
			count_hero++;
		}

	}
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	mx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleX(82, 4);
	my1 = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(82, 4) + 15;
	my2 = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(82, 5) + 15;
	spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + mx, y + my1, _LEFT, "Gameplay Statistics:");
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
	my1 += 5;
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 20, _LEFT, "Num. of taps: %d", _user._quest_num_tap);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 40, _LEFT, "Num. of killed units: %d", _user._quest_num_kill_monster);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 60, _LEFT, "Num. of defeats: %d", _user._play_times_retry);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 80, _LEFT, "Coin earned: %lld", _user._quest_num_coin_collected);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my1 + 100, _LEFT, "Gem earned: %d", _user._gem_collected);
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	hero_total_damage = GetDamageHeroesBasic();
	spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + mx, y + my2, _LEFT, "Heroes Statistics:");
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
	my2 += 5;
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + 20, _LEFT, "Num. of autos: %d", _user._num_use_auto_attack);
	GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + mx, y + my2 + 40, _LEFT, "Num. of skill triggered: %d", _user._quest_num_use_skill);
	GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
}
void TDGame::CastleInfoUpdate()
{
	if (_ingame_menu_close)
	{
		int mkhight = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(82);
		if (_castle_info_scrolly < mkhight)
		{
			_castle_info_scrolly += _castle_info_scroll_speed;
		}
		if (_castle_info_scrolly >= mkhight)
		{
			_castle_info_scrolly = mkhight;
		}
	}
	else
	{
		if (_castle_info_scrolly > 0)
		{
			_castle_info_scrolly -= _castle_info_scroll_speed;
			if (_castle_info_scrolly <= 0)
			{
				_castle_info_scrolly = 0;
			}
		}
	}
}

void TDGame::HeroesDeploy::Init(float x, float y, int herosprite, int heroid, INT_TIME damage)
{
	_x = x;
	_y = y;
	_hero_sprite = herosprite;
	_heroID = heroid;
	_effect_zoom_scale = 0;
	_active = false;
	_touch_id = -1;
	_damage = damage;
}

void TDGame::HeroesDeploy::Modify(int herosprite, int heroid, INT_TIME damage)
{
	_hero_sprite = herosprite;
	_heroID = heroid;
	_damage = damage;
}

void TDGame::HeroesDeploy::Render(float x, float y, int opac)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	G()->SetScale(_effect_zoom_scale, _effect_zoom_scale, _x + x, _y + y);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 48, _x + x, _y + y);
	if (_heroID >= 0)
	{
		for (int i = 0; i < NUM_MAX_HERO; i++)
		{
			if (game->_hero_inbattle_arr[i].GetHeroID() == _heroID)
			{
				_damage = game->_hero_inbattle_arr[i].GetDamage();
				break;
			}
		}
		GET_SPRITE(_hero_sprite)->DrawFrame(G(), 0, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 52, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 81, _x + x, _y + y);

		int spacing = GET_SPRITE(SPRITEID_FONT_ATK)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_ATK)->_char_spacing = -1;
		GET_SPRITE(SPRITEID_FONT_ATK)->DrawAnsiTextFormat(G(), _x + x, _y + y + 74, _HCENTER, ": %lld", _damage);
		GET_SPRITE(SPRITEID_FONT_ATK)->_char_spacing = spacing;
		if (_active)
		{
			G()->ClearScale();
		}
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 56, _x + x, _y + y);
		G()->SetScale(_effect_zoom_scale, _effect_zoom_scale, _x + x, _y + y);
	}
	else
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 49, _x + x, _y + y);
	}
	/*if (_active)
	{
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 52, _x + x, _y + y);
	}*/

	G()->ClearScale();
}
void TDGame::HeroesDeploy::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (game->_ingame_menu_close)
	{
		if (_effect_zoom_scale > 0)
		{
			_effect_zoom_scale -= 0.1f;
			if (_effect_zoom_scale <= 0)
			{
				_effect_zoom_scale = 0;
			}
		}
	}
	else
	{
		if (_touch_id == -1)
		{
			if (_effect_zoom_scale < 1.0f)
			{
				_effect_zoom_scale += 0.1f;
				if (_effect_zoom_scale >= 1.0f)
				{
					_effect_zoom_scale = 1.0f;
					_active = false;
				}
			}
		}
		else
		{
			if (_effect_zoom_scale > 0.9f)
			{
				_effect_zoom_scale -= 0.05f;
				if (_effect_zoom_scale <= 0.9f)
				{
					_effect_zoom_scale = 0.9f;
				}
			}
		}

	}
}
bool TDGame::HeroesDeploy::UpdateTouch()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	bool pressed = false;
	if (_heroID == -1 )
	{
		return pressed;
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		int x = _x - HEROES_ICON_SIZE / 2;
		int y = _y - HEROES_ICON_SIZE / 2;
		int w = HEROES_ICON_SIZE;
		int h = HEROES_ICON_SIZE;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_touch_id == -1)
				{
					_active = true;
					_touch_id = TOUCHS(i)->_id;
					GAME()->PlaySFX(SFX_BUTTON);
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_touch_id == TOUCHS(i)->_id)
				{
					_touch_id = -1;
					pressed = true;
					game->HeroDeployRemove(_heroID);
					Modify(0, -1, 0);
				}
			}
			if (_touch_id == TOUCHS(i)->_id)
			{
				pressed = true;
			}
		}
		else
		{
			if (_touch_id == TOUCHS(i)->_id)
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					_touch_id = -1;
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void TDGame::HeroDeployRender(float x, float y, int opac)
{
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
		_heroes_deploy_arr[i].Render(x, y, opac);
	}
}
void TDGame::HeroDeployUpdate()
{
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
		_heroes_deploy_arr[i].Update();
	}
}
bool TDGame::HeroDeployUpdateTouch()
{
	if (_dialogMng.isOpenDialog() || _invitation_active)
	{
		return false;
	}
	if (!_user._tutorial_completed)
	{
		return false;
	}
	if (_ingame_menu_frame_idle > 0)
	{
		return false;
	}
	bool ret = false;
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
		if (_heroes_deploy_arr[i].UpdateTouch())
		{
			ret = true;
		}
	}
	return ret;
}

void TDGame::HeroDeployRemove(int heroid)
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_inbattle_arr[i].GetHeroID() == heroid && heroid >= 0)
		{
			_hero_inbattle_arr[i]._deployed = false;
			_user.ModifyNewHeroes(_hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetLevel(), _hero_inbattle_arr[i]._deployed, -1, _hero_inbattle_arr[i]._rar_level);
		}
	}
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
		if (_ingame_hero_button[i]._heroID == heroid)
		{
			_ingame_hero_button[i].Modify(0, -1, 0, 0, 1);
		}
	}
	_num_hero_deployed--;
	if (_num_hero_deployed <= 0)
	{
		_num_hero_deployed = 0;
	}
	_user.UserDataSave();
}

void TDGame::HeroDeployActive(int heroid, int slotnumber)
{
	int herosprite = 0;
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	for (int i = 0; i < totalhero; i++)
	{
		if (_hero_inbattle_arr[i].GetHeroID() == heroid && heroid >= 0)
		{
			_hero_inbattle_arr[i]._deployed = true;
			_hero_inbattle_arr[i]._count_frame_mass_auto_att = 0;
			if (_mass_auto_timing > 0)
			{
				_hero_inbattle_arr[i]._count_frame_mass_auto_att = _mass_auto_timing;
				_hero_inbattle_arr[i].ActiveAutoAttack(true);
			}
			herosprite = _hero_inbattle_arr[i].GetSpriteID();
			int slot = 0;
			for (int j = 0; j < NUM_MAX_HERO_INBATTLE; j++)
			{
				if (_ingame_hero_button[j]._heroID == -1)
				{
					_ingame_hero_button[j].Modify(herosprite, heroid, _hero_inbattle_arr[i].GetPowerAttack(), _hero_inbattle_arr[i].GetPowerSkill(), _hero_inbattle_arr[i].GetLimitBreak());
					_heroes_deploy_arr[j].Modify(herosprite, heroid, 0);
					slot = j;
					break;
				}
			}
			_user.ModifyNewHeroes(_hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetLevel(), _hero_inbattle_arr[i]._deployed, slot, _hero_inbattle_arr[i]._rar_level);
			break;
		}
	}
	int count_hero_range = 0;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_inbattle_arr[i].GetTypeRange() == HERO_TYPE_RANGE_RANGE && _hero_inbattle_arr[i]._deployed)
		{
			_hero_inbattle_arr[i].SetPos(110 + count_hero_range * 30, ROAD_POSY + 15 - count_hero_range * 15);
			count_hero_range++;
		}
	}
	if (!_user._tutorial_completed && _user._tutorial_step == TUTORIAL_STEP_DEPLOY_HERO)
	{

		//_user._tutorial_step = TUTORIAL_STEP_COMPLETED;
		_tutorial_step = TUTORIAL_STEP_FREE;
	}
	_user.UserDataSave();
}

bool TDGame::MenuInfoUpdateTouch()
{
	bool ret = false;
	for (int i = 0; i < _ingame_menu_num_item; i++)
	{
		if (_menu_info_arr[i]._has_touch)
		{
			ret = true;
		}
	}
	return ret;
}

bool TDGame::SummonRelics()
{
	bool ret = true;
	int total_hero_relic = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
	int total_weapon_relic = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
	int total_enemy_relic = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;

	int arr_relic_id[NUM_MAX_ITEM_RELICS];
	int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
	int id = 0;
	int num_relic = 0;
	for (int i = 0; i < total_hero_relic; i++)
	{
		int param_interid = CGameDesign::FileRelics_design::CSheetHero_Relics::Hero_ID;
		int id_interactive = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, param_interid);
		if (!_user.CheckHeroColleted(HERO_ID_ACHEMIST))
		{
			continue;
		}
		/*if (id_interactive == HERO_ID_ACHEMIST)
		{
		if (!_user.CheckHeroColleted(HERO_ID_ACHEMIST))
		{
		continue;
		}
		}
		if (id_interactive == HERO_ID_WOLF_RANGER)
		{
		if (!_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
		{
		continue;
		}
		}
		if (id_interactive == HERO_ID_SANTA)
		{
		if (!_user.CheckHeroColleted(HERO_ID_SANTA))
		{
		continue;
		}
		}*/
		id = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, paramid);
		if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_HERO, id))
		{
			arr_relic_id[num_relic] = id;
			num_relic++;
		}
	}
	for (int i = 0; i < total_weapon_relic; i++)
	{
		id = GetDesignRelics(i, ITEMRELIC_GROUP_WEAPON, paramid);
		int param_interid = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Weapon_ID;
		int id_interactive = GetDesignRelics(i, ITEMRELIC_GROUP_WEAPON, param_interid);
		if (id_interactive>0)
		{
			if (_weapon[id_interactive - 2].IsLock())
			{
				continue;
			}
		}
		if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_WEAPON, id))
		{
			arr_relic_id[num_relic] = id + 1000;
			num_relic++;
		}
	}
	
	for (int i = 0; i < total_enemy_relic; i++)
	{
		id = GetDesignRelics(i, ITEMRELIC_GROUP_ENEMY, paramid);
		if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_ENEMY, id))
		{
			arr_relic_id[num_relic] = id + 10000;
			num_relic++;
		}
	}
	if (num_relic <= 0)
	{
		ret = false;
		return ret;
	}
	int index = CMath::RANDOM(0, num_relic - 1);
	int group_summon = 0;
	int id_summon = arr_relic_id[index];
	if (id_summon < 1000)
	{
		group_summon = ITEMRELIC_GROUP_HERO;
		id_summon;
	}
	else if (id_summon < 10000)
	{
		group_summon = ITEMRELIC_GROUP_WEAPON;
		id_summon -= 1000;
	}
	else
	{
		group_summon = ITEMRELIC_GROUP_ENEMY;
		id_summon -= 10000;
	}
	if (id_summon >= 0)
	{
		//_items_relics[_user._quest_num_relics_own].Init(SPRITEID_HUD_ITEM, group_summon, id_summon, 0, 0,false);
		ModifyRelicItems(group_summon, id_summon, false);
		_user.AddNewRelics(id_summon, group_summon);
		ModifyInfo(group_summon, id_summon);
		//printf("\n group_summon = %d,id_summon = %d", group_summon, id_summon);
	}
	return ret;
}

void TDGame::ModifyInfo(int group, int id)
{
	switch (group)
	{
	case ITEMRELIC_GROUP_HERO:
		for (int i = 0; i < _user._num_heroes_collected; i++)
		{
			_hero_inbattle_arr[i].UpdateRarity();
			_hero_inbattle_arr[i].GetRelicsBonus();
		}
		break;
	case ITEMRELIC_GROUP_WEAPON:
		for (int i = 0; i < NUM_MAX_WEAPON+1; i++)
		{
			if (i > 0)
			{
				_weapon[i-1].GetRelicsBonus();
			}

		}
		break;
	case ITEMRELIC_GROUP_ENEMY:
		for (int i = 0; i < _num_enemy_inwave; i++)
		{
			_enemy[i - 1].GetRelicsBonus(false, id);
		}
		break;
	default:
		break;
	}
}
int TDGame::GetHeroSummonRandom()
{
	int rand_heroid = -1;
	/*int arr_heroid[NUM_MAX_HERO];
	int total_hero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	int param_id = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
	int num_collected = 0;

	for (int i = 0; i < total_hero; i++)
	{
	int heroid = GetDesignHeroGeneral(i, param_id);
	bool has_collected = false;
	for (int j = 0; j < _user._num_heroes_collected; j++)
	{
	if (_user._hero_arr[j]._heroid == heroid)
	{
	has_collected = true;
	break;
	}
	}
	if (!has_collected)
	{
	arr_heroid[num_collected] = i;
	num_collected++;
	}
	}
	int rand_index = CMath::RANDOM(0, num_collected - 1);
	if (rand_index >= 0)
	{
	rand_heroid = arr_heroid[rand_index];
	return rand_heroid;
	}*/
	return rand_heroid;
}

void TDGame::ShopFuncActive(int id, int value)
{
	switch (id)
	{
	case SHOP_ID_AUTO_ATT://buy auto attack
		_user._auto_attack_free += value;
		break;
	case SHOP_ID_AUTO_SKILL://buy auto skill
		_user._auto_skill_free += value;
		break;
	case SHOP_ID_OPEN_BOX://goto minigame
		_open_box_state_old = k_GS_INGAME_MENU;
        _user._timeBuyOpenBox = time(NULL) + TIME_BUY_OPEN_BOX;
		SetState(k_GS_OPEN_BOX);

		break;
	case SHOP_ID_REFILL_HP_CASTLE:
		_castle.AddHp(_castle._hp_max);
		PLAY_SFX(SFX_GATE_PREPARE);
		_user.UserDataSave();
		break;
	case SHOP_ID_WATCH_ADD:
            /*
#if defined(MAC_OS)
        if (Device::IsNetworkAvailable())
		{
			int adboxtype = PineAdBox::HasVideoAds(true);
			//printf("\n adboxtype: %d", adboxtype);
			if (adboxtype >= 0)
			{
				PineAdBox::ShowVideoAds(adboxtype);
			}
			_user._watch_ad_time = time(NULL) + CMath::RANDOM(WATCH_ADS_NEXT_TIME1, WATCH_ADS_NEXT_TIME2);
			_has_watched_ads = true;
		}
#else
	{
		int param_type = CGameDesign::FileGeneral::CSheetFree_Gift::Type;
		int param_value = CGameDesign::FileGeneral::CSheetFree_Gift::Value;
		int type = GetDesignFreeGift(_user._watch_ad_times, param_type);
		int value = GetDesignFreeGift(_user._watch_ad_times, param_value);
		char text[256];
		switch (type)
		{
		case WATCH_ADS_REWARD_TYPE_COIN:
		{
										   int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
										   int reward_coin = GetDesignTreasure(_battle_current, param_coin,false);
										   value *= reward_coin;
										   sprintf(text, "%d ;", value);
		}
			break;
		case WATCH_ADS_REWARD_TYPE_GEM:
			sprintf(text, "%d :", value);
			break;
		case WATCH_ADS_REWARD_TYPE_AUTO_ATT:
			sprintf(text, "%d Auto Attack", value);
			break;
		case WATCH_ADS_REWARD_TYPE_AUTO_SKILL:
			sprintf(text, "%d Auto Skill", value);
			break;
		case WATCH_ADS_REWARD_TYPE_DOUBLE_COIN:
			sprintf(text, "Double Coin in %d seconds", value);
			break;
		default:
			break;
		}
		_user._watch_ad_time = time(NULL) + CMath::RANDOM(WATCH_ADS_NEXT_TIME1, WATCH_ADS_NEXT_TIME2);
		_has_watched_ads = true;
		_dialogMng.Add(DIALOG_CONTEXT_WATCH_ADS, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
	}
#endif
		break;*/
	
	/*case SHOP_ID_FOLLOW_TW:
	{
#if defined (MAC_OS)

							  _rate_us_time = time(NULL) + 3;
							  _rate_us_type = RATE_US_TYPE_TW_FOLLOW;
							  PineSocial::OpenURL(TWITTER_URL);
#else
							  if (!_dialogMng.isOpenDialog())
							  {
								  char text[256];
								  sprintf(text, "%d :", TW_FOLLOW_REWARD);
								  _dialogMng.Add(DIALOG_CONTEXT_TW_FOLLOW, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
							  }
#endif
	}
		break;*/
	case SHOP_ID_LIKE_FB:
	{
#if defined (MAC_OS)
							_rate_us_time = time(NULL) + 3;
							_rate_us_type = RATE_US_TYPE_FB_LIKE;
							PineSocial::OpenURL(FACEBOOK_URL);
#elif defined (ANDROID_OS)
							_rate_us_time = time(NULL) + 3;
							PDEBUG("_rate_us_time = %lld", _rate_us_time);
							_rate_us_type = RATE_US_TYPE_FB_LIKE;
							PineSocial::OpenURL(FACEBOOK_URL);
							GAME()->_is_cancel_show_ads_on_resume = true;
#else
							char text[256];
							sprintf(text, "%d :", FB_LIKE_REWARD);
							_dialogMng.Add(DIALOG_CONTEXT_FB_LIKE, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
#endif
	}
		break;
	case SHOP_ID_RESTORE:
#if defined (MAC_OS)
            IapRestore();
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
			GAME()->_loading_count_frame = 0;
			GAME()->_processing_time_out = PROCESSING_TIME_OUT;
            
#endif
		break;
	case SHOP_ID_DOWN_MOREGAME:
#if defined (MAC_OS)
		GAME()->_advert.Init();
        _user._stateAppDownload = 1;
#else
            _user._download_moregame_trigger = time(NULL) + DOWN_MOREGAME_TIME;
            _user.UserDataSave();
		
#endif
		
		break;
	default:
		break;
	}
}

void TDGame::ShopIAPFuncActive(int id, bool discount)
{
	int totaliap = 0;
	int value = 0;
	int iap_index = -1;
	/*if(discount)
	{
	totaliap = _game_design.General.SheetiAP_design_discount.int32Value._totalData;
	int paramid = CGameDesign::FileGeneral::CSheetiAP_design_discount::enumInt32::id;
	for(int i = 0; i< totaliap;i++)
	{
	if(id == GetDesignIAP(i, paramid, discount))
	{
	iap_index = i;
	}
	}
	}
	else*/
	{
		totaliap = _game_design.General.SheetiAP_design.int32Value._totalData;
		int paramid = CGameDesign::FileGeneral::CSheetiAP_design::enumInt32::id;
		for (int i = 0; i< totaliap; i++)
		{
			if (id == GetDesignIAP(i, paramid, discount))
			{
				iap_index = i;
			}
		}
	}
	if (iap_index == -1)
	{
		//printf("\n bug design iap not found");
		return;
	}
	int param_value = CGameDesign::FileGeneral::CSheetiAP_design::enumInt32::Value;
	value = GetDesignIAP(iap_index, param_value, discount);
	switch (id) {
	case SHOP_ID_STARTER_PACK:
		_user.AddGem(10);
		_user._iap_starter_double_coin_time = IAP_STARTER_TIME_DOUBLE_COIN;
		_user._iap_starter_time_reset = time(NULL) - 1;
		_iap_starter_time.setNullDay();
		/*game->_user._auto_attack_free += 10;
		game->_user._auto_skill_free += 5;*/
		if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_HERO, 6))
		{
			ModifyRelicItems(ITEMRELIC_GROUP_HERO, 6, false);
			_user.AddNewRelics(6, ITEMRELIC_GROUP_HERO);
			ModifyInfo(ITEMRELIC_GROUP_HERO, 6);
		}
		else if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_WEAPON, 5))
		{
			ModifyRelicItems(ITEMRELIC_GROUP_WEAPON, 5, false);
			_user.AddNewRelics(5, ITEMRELIC_GROUP_WEAPON);
			ModifyInfo(ITEMRELIC_GROUP_WEAPON, 5);
		}
		else if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_HERO, 8))
		{
			ModifyRelicItems(ITEMRELIC_GROUP_HERO, 8, false);
			_user.AddNewRelics(8, ITEMRELIC_GROUP_HERO);
			ModifyInfo(ITEMRELIC_GROUP_HERO, 8);
		}
		else
		{
			if (!SummonRelics())
			{
				printf("\n Full Relics");
			}
		}
		ReInitShop();
		break;
	case SHOP_ID_DOUBLE_COIN:
		_user._has_double_coin = true;
		ReInitShop();
		break;
	default:
		//printf("\n value = %d",value);
		if (id == 1)
		{
			_user._iAPs_numpack_spend += 1;
		}
		else if (id == 2)
		{
			_user._iAPs_numpack_spend += 5;
		}
		else if (id == 3)
		{
			_user._iAPs_numpack_spend += 10;
		}
		else if (id == 4)
		{
			_user._iAPs_numpack_spend += 20;
		}
		_user.AddGem(value);
		break;
	}
	_user.UserDataSave();

}

int TDGame::CheckHeroIDInBattle(int heroid)
{
	int ret = -1;
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	for (int i = 0; i < totalhero; i++)
	{
		//printf("\n _user._hero_arr[%d]._heroid = %d == heroid = %d", i, _hero_inbattle_arr[i].GetHeroID(), heroid);
		if (_hero_inbattle_arr[i].GetHeroID() == heroid)
		{
			ret = i;
		}
	}
	return ret;
}

void TDGame::AddMenuInfo(int group, int id)
{
	bool has_new_group = true;
	int sub_group[NUM_MAX_ITEM_RELICS];
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		sub_group[i] = -1;
	}
	
	int countsub = 0;
	if (group == ITEMRELIC_GROUP_HERO)
	{
		char relic_resetname[64];
		sprintf(relic_resetname, "Power of God Lv. %d", _user._user_level_reset);
		for (int i = 0; i < _relics_num_of; i++)
		{
			if (_items_relics[i]._interactive_id == id && (_items_relics[i]._group == group || _items_relics[i]._group == ITEMRELIC_GROUP_PET))
			{
				bool relic_rs_id = true;
				if (_items_relics[i]._frameid == 164)//relic reset
				{
					if (_items_relics[i]._is_lock)
					{
						relic_rs_id = false;
					}
					else
					{
						relic_rs_id = false;
						
						if (strcmp(relic_resetname, _items_relics[i]._name) == 0)
						{
							relic_rs_id = true;
						}
					}
					if (relic_rs_id)
					{
						int x = k_SCREEN_WIDTH / 2;
						int y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						if (has_new_group)
						{
							_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, true);
							_ingame_num_item_relics++;
							has_new_group = false;
						}
						y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, false);
						_ingame_num_item_relics++;
						if (_items_relics[i]._is_lock)
						{
							sub_group[countsub] = _items_relics[i]._sub_group;
							countsub++;
						}
					}
				}
			}
		}
		for (int i = 0; i < _relics_num_of; i++)
		{
			if (_items_relics[i]._interactive_id == id && (_items_relics[i]._group == group || _items_relics[i]._group == ITEMRELIC_GROUP_PET))
			{
				if (_items_relics[i]._frameid != 164)//not relic reset
				{
					bool hasgroup = false;
					for (int sb = 0; sb < NUM_MAX_ITEM_RELICS; sb++)
					{
						if (sub_group[sb] == _items_relics[i]._sub_group && _items_relics[i]._is_lock)
						{
							hasgroup = true;
							break;
						}
					}
					if (!hasgroup)
					{
						int x = k_SCREEN_WIDTH / 2;
						int y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						if (has_new_group)
						{
							_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, true);
							_ingame_num_item_relics++;
							has_new_group = false;
						}
						y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						
						_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, false);
						_ingame_num_item_relics++;
						if (_items_relics[i]._is_lock)
						{
							sub_group[countsub] = _items_relics[i]._sub_group;
							countsub++;
						}

					}
				}
			}
		}
	}
	else if (group == ITEMRELIC_GROUP_WEAPON)
	{
		char relic_resetname[64];
		sprintf(relic_resetname, "Power of God Lv. %d", _user._user_level_reset);
		for (int i = 0; i < _relics_num_of; i++)
		{
			if (_items_relics[i]._interactive_id == id && (_items_relics[i]._group == group ))
			{
				bool relic_rs_id = true;
				if (_items_relics[i]._frameid == 164)//relic reset
				{
					if (_items_relics[i]._is_lock)
					{
						relic_rs_id = false;
					}
					else
					{
						relic_rs_id = false;
						
						if (strcmp(relic_resetname, _items_relics[i]._name) == 0)
						{
							relic_rs_id = true;
						}
					}
					if (relic_rs_id)
					{
						int x = k_SCREEN_WIDTH / 2;
						int y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						if (has_new_group)
						{
							_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, true);
							_ingame_num_item_relics++;
							has_new_group = false;
						}
						y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, false);
						_ingame_num_item_relics++;
						if (_items_relics[i]._is_lock)
						{
							sub_group[countsub] = _items_relics[i]._sub_group;
							countsub++;
						}
					}
				}
			}
		}
		for (int i = 0; i < _relics_num_of; i++)
		{
			if (_items_relics[i]._interactive_id == id && (_items_relics[i]._group == group))
			{
				if (_items_relics[i]._frameid != 164)//not relic reset
				{
					bool hasgroup = false;
					for (int sb = 0; sb < NUM_MAX_ITEM_RELICS; sb++)
					{
						if (sub_group[sb] == _items_relics[i]._sub_group && _items_relics[i]._is_lock)
						{
							hasgroup = true;
							break;
						}
					}
					if (!hasgroup)
					{
						int x = k_SCREEN_WIDTH / 2;
						int y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						if (has_new_group)
						{
							_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, true);
							_ingame_num_item_relics++;
							has_new_group = false;
						}
						y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
						_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, false);
						_ingame_num_item_relics++;
						if (_items_relics[i]._is_lock)
						{
							sub_group[countsub] = _items_relics[i]._sub_group;
							countsub++;
						}

					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < _relics_num_of; i++)
		{
			if (_items_relics[i]._group == group && _items_relics[i]._interactive_id == id)
			{
				bool hasgroup = false;
				for (int sb = 0; sb < NUM_MAX_ITEM_RELICS; sb++)
				{
					if (sub_group[sb] == _items_relics[i]._sub_group && _items_relics[i]._is_lock)
					{
						hasgroup = true;
						break;
					}
				}
				if (!hasgroup)
				{
					int x = k_SCREEN_WIDTH / 2;
					int y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
					if (has_new_group)
					{
						_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, true);
						_ingame_num_item_relics++;
						has_new_group = false;
					}
					y = 100 + _ingame_num_item_relics * (INGAME_MENU_ITEM_HEIGHT + 5);
					_menu_info_arr[_ingame_num_item_relics].Init(x, y, i, false);
					_ingame_num_item_relics++;
					if (_items_relics[i]._is_lock)
					{
						sub_group[countsub] = _items_relics[i]._sub_group;
						countsub++;
					}
				}
			}
		}
	}
}
int TDGame::GetHeroIndex(int heroid)
{
	int index = -1;
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	for (int i = 0; i < totalhero; i++)
	{
		//printf("\n _user._hero_arr[%d]._heroid = %d == heroid = %d", i, _hero_inbattle_arr[i].GetHeroID(), heroid);
		if (_hero_inbattle_arr[i].GetHeroID() == heroid)
		{
			index = i;
			break;
		}
	}
	return index;
}
void TDGame::InputCodeRender(float x, float y)
{
	for (int i = 0; i < INPUT_CODE_BUTTON_NUM; i++)
	{
		_input_code_button[i].SetPos(x, y);
		_input_code_button[i].Render(G(), 0, 0);
		_input_code_button[i].Update();
	}
}
void TDGame::InputCodeUpdate()
{
	
}
bool TDGame::InputCodeUpdateTouch()
{
	bool ret = false;
	int index = -1;
	if (_dialogMng.isOpenDialog() || _invitation_active)
	{
		return false;
	}
	if (_ingame_menu_frame_idle > 0)
	{
		return false;
	}
	for (int i = 0; i < INPUT_CODE_BUTTON_NUM; i++)
	{
		if (_input_code_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_input_code_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case INPUT_CODE_BUTTON_ENTER:
			{

											if (!_invitation_active)
											{
												InvitationInit();
												_invitation_active = true;
											}
			}

				break;
			
			default:
				break;
			}

			for (int i = 0; i < INPUT_CODE_BUTTON_NUM; i++)
			{
				if (_input_code_button[i]._state != BUTTON_STATE_LOCK && _input_code_button[i]._state != BUTTON_STATE_HIDE)
				{
					_input_code_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < INPUT_CODE_BUTTON_NUM; touch++)
		{
			if (_input_code_button[touch]._state == BUTTON_STATE_LOCK || _input_code_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _input_code_button[touch].TZ_GetX();
			int y = _input_code_button[touch].TZ_GetY();
			int w = _input_code_button[touch].TZ_GetWidth();
			int h = _input_code_button[touch].TZ_GetHeight();
			Button *button = &_input_code_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						GAME()->PlaySFX(SFX_BUTTON);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
					}
				}
				if (button->_touch_id != -1)
				{
					pressed = true;
				}
			}
			else
			{

				if (button->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}
			}
		}
	}
	return pressed;
}
void TDGame::ClearAllHeroDeploy()
{
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	for (int j = 0; j<totalhero; j++)
	{
		int heroid = _hero_inbattle_arr[j].GetHeroID();
		if (heroid >= 0 && _hero_inbattle_arr[j]._deployed)
		{
			bool clear = true;
			for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
			{
				if (_heroes_deploy_arr[i]._heroID == heroid)
				{
					clear = false;
					break;
				}
			}
			if (clear)
			{
				_hero_inbattle_arr[j]._deployed = false;
				_user.ModifyNewHeroes(heroid, _hero_inbattle_arr[j].GetLevel(), _hero_inbattle_arr[j]._deployed, -1, _hero_inbattle_arr[j]._rar_level);
			}
		}
	}
}

