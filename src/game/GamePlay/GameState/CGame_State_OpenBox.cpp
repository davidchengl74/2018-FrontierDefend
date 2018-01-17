#include "pch.h"
#include "../../GameCore/PineGame.h"

bool _has_collected_item_force = false;
#define TIME_OPEN_BOX_ADS			(5*60)

void TDGame::OpenBoxRender(float x, float y, int opac)
{
	G()->SetOpacity(_open_box_fill_opac);
	G()->SetColor(0xff000000);
	G()->FillFullScreen(true);
	G()->SetOpacity(opac);
	float opacmain = opac / 100.0f;
	GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 20, 0, 0);
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		if (!_arr_box_item[i]._choosen)
		{
			_arr_box_item[i].Render(opac);
			//GET_SPRITE(SPRITEID_FONT_COINGEM)->DrawAnsiTextFormat(G(), _arr_box_item[i].GetPosX(), _arr_box_item[i].GetPosY(), _RIGHT, "%d", i);
		}
	}
	if (_open_box_force_open)
	{
		//G()->SetOpacity(_openning_opac);
       // _open_box_count_complete = 200;
		if (_open_box_count_complete >= 90)
		{
			_openning_opac += 5;
			if (_openning_opac >= 70)
			{
				_openning_opac = 70;
			}
			_open_box_count_complete++;
		}
		G()->SetOpacity(_openning_opac*opacmain);
		G()->SetColor(0x99000000);
		G()->FillFullScreen(true);
		G()->SetOpacity(opac);
		if (_open_box_count_complete >= 200)
		{
			if (_openbox_button[0]._state == BUTTON_STATE_HIDE)
			{
				_openbox_button[0].SetState(BUTTON_STATE_NORMAL);
			}
			G()->SetOpacity(_open_box_count_complete - 200);
			//GET_SPRITE(SPRITEID_HUD_CHEST)->DrawFrame(G(), 32, 0, 0);
			for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
			{
				_openbox_button[i].Render(G());
				_openbox_button[i].Update();
			}
			G()->SetOpacity(opac);
		}
		_open_box_text_opac -= 5;
		if (_open_box_text_opac <= 0)
		{
			_open_box_text_opac = 0;
		}
	}
	else
	{
        
		_open_box_text_opac += 5;
		if (_open_box_text_opac >= 100)
		{
			_open_box_text_opac = 100;
		}
		
	}
	//new feature
	/*int bt_opac = 0;
	if (_time_openbox_countdown > 0)
	{
		bt_opac = 70;
	}
	else
	{
		bt_opac = 70 - _time_openbox_countdown;
		if (bt_opac >= 100)
		{
			bt_opac = 100;
		}
		for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
		{
			if (_openbox_button[i]._state == BUTTON_STATE_LOCK)
			{
				_openbox_button[i].SetState(BUTTON_STATE_NORMAL);
			}
		}
	}
	G()->SetOpacity(bt_opac);
	for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
	{
		_openbox_button[i].Render(G());
		_openbox_button[i].Update();
	}
	G()->SetOpacity(opac);*/
	G()->SetOpacity(_open_box_text_opac);
	GET_SPRITE(SPRITEID_FONT_SELECT_YOUR_REWARDS)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2, 3 * k_SCREEN_HEIGHT / 4 + 60, _HCENTER, "SELECT YOUR REWARDS");
	GET_SPRITE(SPRITEID_FONT_SELECT_YOUR_REWARDS)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2, 3 * k_SCREEN_HEIGHT / 4 + 110, _HCENTER, "(%d/3 CHESTS)", _item_box_count_reward);
	G()->SetOpacity(opac);
	int count = 0;
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{

		if (_arr_box_item[i]._choosen && _arr_box_item[i].GetState() == ITEM_STATE_END)
		{
			count++;
			_arr_box_item[i].Render(opac);
             G()->ClearScale();
			if (count >= 3)
			{
				_open_box_force_open = true;
			}
		}
	}
    _frame_double_box -= 6;
    if(_frame_double_box < 0)
    {
        _frame_double_box = 0;
        //printf("\n_frame_double_box = %d",_frame_double_box);
    }
    
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		if (_arr_box_item[i]._choosen)
		{
			if (_arr_box_item[i].GetState() < ITEM_STATE_END)
			{
				//printf("\n _openning_opac = %d", _openning_opac);
                
                
				G()->SetOpacity(_openning_opac*opacmain);
				G()->SetColor(0xff000000);
				G()->FillFullScreen(true);
				G()->SetOpacity(opac);
                //G()->SetScale(1.0f+_frame_double_box/100.0f, 1.0f+_frame_double_box/100.0f,_arr_box_item[i].GetPosX(),_arr_box_item[i].GetPosY());
                
				_arr_box_item[i].Render(opac);
               
			}
		}
	}
	int count_update = 0;
	//_effect_open_box_item.Render(0 ,0,100);
	bool can_retry = true;
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		if (i>0)
		{
			if (_arr_box_item[_item_box_index[i-1]]._scale >= 0.4)
			{
				count_update++;
				_arr_box_item[_item_box_index[i]].Update();
			}
		}
		else
		{
			_arr_box_item[_item_box_index[i]].Update();
		}
		if (_arr_box_item[i]._scale <= 0.6)
		{
			can_retry = false;
		}
	}
	if (can_retry && _retry_open_state == 1)
	{
		if (_shuffle_item_current > 0)
		{
			/*printf("\n is_scroll = %d", _arr_box_item[_item_box_index[_shuffle_item_current - 1]]._is_scrolling);*/
			//printf("\n _shuffly_speed = %f", _arr_box_item[_item_box_index[_shuffle_item_current - 1]]._dis_with_screen_center);
			if (_shuffly_speed < 5 && !_arr_box_item[_item_box_index[_shuffle_item_current-1]]._is_scrolling)
			{
				_arr_box_item[_item_box_index[_shuffle_item_current - 1]]._scale_center_x = _arr_box_item[_item_box_index[_shuffle_item_current - 1]].GetTargetX();
				_arr_box_item[_item_box_index[_shuffle_item_current - 1]]._scale_center_y = _arr_box_item[_item_box_index[_shuffle_item_current - 1]].GetTargetY();
				_arr_box_item[_shuffle_index_be_call]._scale_center_x = _arr_box_item[_shuffle_index_be_call].GetTargetX();
				_arr_box_item[_shuffle_index_be_call]._scale_center_y = _arr_box_item[_shuffle_index_be_call].GetTargetY();
				BoxItemShuffle();
			}
		}
		else
		{
			BoxItemShuffle();
		}
		
		//_retry_open_state = 2;
		
	}
	G()->SetOpacity(100);
}
int  TDGame::OPENBOX_NUM_BUTTON = 2;
void TDGame::OpenBoxUpdate()
{
	if (_sub_state == k_INIT)
	{
		
        _frame_double_box = 0;
		_main_opac_change_state = 100;
		_open_box_text_opac = 0;
		_game_state_changing = true;
		_opac_change_game_state = 0;
		_open_box_count_complete = 200;
		_item_box_count_reward = 0;
		_retry_open_state = 0;
		_open_box_fill_opac = 0;
		_open_box_close = false;
		_openning_opac = 0;
		

        //if ()
        {
            
			int adboxtype = 0;
#if defined (ANDROID_OS)
			if (Device::IsNetworkAvailable() /*&& GAME()->HasVideoAds()*/)
#else
			adboxtype = PineAdBox::HasVideoAds(true);
			//printf("\n adboxtype: %d", adboxtype);
            if (adboxtype >= 0 && Device::IsNetworkAvailable())
#endif
            {
                 OPENBOX_NUM_BUTTON = 2;
                for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
                {
                    _openbox_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
                    _openbox_button[i].SetAnim(SPRITEID_HUD_CHESTS, 4*i + 4);
                    //_openbox_button[i].SetPos(0, 0);
                    //_openbox_button[i].SetState(BUTTON_STATE_HIDE);
                }
                //PineAdBox::ShowVideoAds(adboxtype);
                //_has_watched_ads = true;
				_time_openbox_countdown = TIME_OPEN_BOX_ADS;
            }
            else
            {
                OPENBOX_NUM_BUTTON = 1;
                for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
                {
                    _openbox_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
                    _openbox_button[i].SetAnim(SPRITEID_HUD_CHESTS, 13);
                    _openbox_button[i].SetPos(0, 0);
                    //_openbox_button[i].SetState(BUTTON_STATE_HIDE);
                }
                
            }
            
        }
		_has_collected_item_force = false;
		if (_open_box_state_old == k_GS_PLAYGAME)
		{
			BoxItemInit(true);
		}
		else
		{
			BoxItemInit(false);
		}
		
		//_effect_open_box_item.Init(SPRITEID_HUD_CHESTS, 0, 13, 16, TYPE_RENDER_ANIM);
		for (int i = 0; i < 3;i++)
		{
			_arr_item_reward[i].Reset();
		}
		_sub_state = k_LOOP;
		_has_retry_openbox = false;
	}
	if (_sub_state == k_LOOP)
	{
		if (_need_log_double_chest)
		{
			char title[128];
			char decs[1024];
			sprintf(title, "%s Click", "Double-Chects");
			sprintf(decs, "%s Click", "Double-Chects");
			char type[128];
			sprintf(type, "%s", "common_events");
#if defined (MAC_OS) || (ANDROID_OS)
			PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
			Device::GA_LogContents(title, decs, type);
#endif
			_need_log_double_chest = false;
		}
		if (_open_box_close)
		{
			if (_open_box_fill_opac > 0)
			{
				_open_box_fill_opac -= 7;
				if (_open_box_fill_opac <= 0)
				{
					if (_open_box_state_old == k_GS_PLAYGAME)
					{
						_boss_reward._state = EFFECT_REWARD_JUMP_STATE_END;
					}
					SetState(_open_box_state_old);
					_sub_state = k_LOOP;
					ClearAllTouchUp(TOUCH_TYPE_INGAME);
					_main_opac_change_state = 0;
				}
			}
			_main_opac_change_state -= 10;
		}
		else
		{
			if (_open_box_fill_opac < 85)
			{
				_open_box_fill_opac += 7;
				if (_open_box_fill_opac >= 85)
				{
					_open_box_fill_opac = 85;

#if defined (ANDROID_OS)
					if (_battle_current >= 2)
					{
						if (GAME()->_async_task_manager._is_login_google)
						{
							_user.CheckLocalAndCloudSaveFile(true);
							GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_SYNC_SAVE;
							GAME()->_loading_count_frame = 0;
							GAME()->_processing_time_out = PROCESSING_TIME_OUT;
						}
					}
#endif
					if (_battle_current + 1 >= BATTLE_START_SHOWADS && _battle_current + 1 != _user._rate_trigger && !_user._has_remove_ads_pop_up)
					{
						if (_open_box_state_old == k_GS_PLAYGAME)
						{
#if defined (ANDROID_OS)
							//if (GAME()->HasVideoSkippableAds())
							{
								//GAME()->ShowSkippableVideoAds();
								PDEBUG("\n open box update");
								GAME()->ShowAds();
							}
							
#elif defined(MAC_OS)
							PineAdBox::ShowAdvertFullScreen();
#endif
						}
					}
					else
					{
						if (_battle_current == 0 && showadtutorial)
						{
							showadtutorial = false;
							//printf("\n _user _tutorial_step:%d -- showadtutorial:%d", _user._tutorial_step, showadtutorial);
//#if defined (ANDROID_OS)
//							if (GAME()->HasVideoSkippableAds())
//							{
//								GAME()->ShowSkippableVideoAds();
//							}
//#elif defined (MAC_OS)
//							PineAdBox::ShowAdvertFullScreen();
//#endif
						}
					}
				}
			}
		}
		if (_open_box_force_open)
		{
			_open_box_count_complete++;
			if (_open_box_count_complete >= 90)
			{
				for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
				{
					if (!_arr_box_item[i]._choosen)
					{
						_arr_box_item[i].SetState(ITEM_STATE_FORCE_OPEN);
						_arr_box_item[i].ForceOpenBox();
					}
				}
			}
		}
		/*if (_user.GetGem() < 1)
		{
			if (_openbox_button[0]._state != BUTTON_STATE_LOCK)
			{
				_openbox_button[0].SetState(BUTTON_STATE_LOCK);
			}
		}*/
		
		//new feature
		/*if (_item_box_count_reward >= 2)
		{
			_time_openbox_countdown--;
			if (_time_openbox_countdown <= 0)
			{
				OpenBoxUpdateTouch();
			}
			if (_item_box_count_reward < 3)
			{
				OpenBoxUpdateTouchItem();
				for (int button = 0; button < OPENBOX_NUM_BUTTON; button++)
				{
					_openbox_button[button]._touch_id = -1;
				}
			}
		}
		else
		{
			OpenBoxUpdateTouchItem();
			for (int button = 0; button < OPENBOX_NUM_BUTTON; button++)
			{
				_openbox_button[button]._touch_id = -1;
			}
		}*/
        if(_item_box_count_reward >= 3)
        {
            OpenBoxUpdateTouch();
        }
        else
        {
                
            OpenBoxUpdateTouchItem();
            for (int button = 0; button < OPENBOX_NUM_BUTTON; button++)
            {
                _openbox_button[button]._touch_id = -1;
            }
        }
	}
}
bool TDGame::OpenBoxUpdateTouch()
{
    //printf("\n _retry_open_state = %d",_retry_open_state);
	if (_retry_open_state == 1 || _open_box_fill_opac < 80)
	{
		return true;
	}
	bool button_touched = false;
	int index = 0;
	for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
	{
		if (_openbox_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			button_touched = true;
			index = i;
			break;
		}
	}
    if (_has_watched_ads &&
#if defined (ANDROID_OS)
		GAME()->_on_video_ads_reward)
#else
		PineAdBox::showAdState == SHOW_AD_COMPLETED)
#endif
    {
        PineAdBox::showAdState = SHOW_AD_NONE;
        _frame_double_box = 100;
        _reward_coin *= 2;
        _reward_gem *= 2;
        
        for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
        {
            if (_arr_box_item[i]._choosen)
            {
                int value = _arr_box_item[i].GetValue();
                _arr_box_item[i].SetValue(value*2);
            }
        }
		OPENBOX_NUM_BUTTON = 1;
		for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
		{
			_openbox_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
			_openbox_button[i].SetAnim(SPRITEID_HUD_CHESTS, 13);
			_openbox_button[i].SetPos(0, 0);
			//_openbox_button[i].SetState(BUTTON_STATE_HIDE);
		}
        _has_watched_ads = false;
		
#if defined (ANDROID_OS)
		PDEBUG("On double reward");
		GAME()->_on_video_ads_reward = false;
#endif
        
    } else if(_has_watched_ads &&
#if defined (ANDROID_OS)
		!GAME()->_is_waiting_for_reward && !GAME()->_on_video_ads_reward)
#else
		PineAdBox::showAdState == SHOW_AD_CANCEL)
#endif
    {
		PDEBUG("Set watched ads to false");
        _has_watched_ads = false;
    }
	if (button_touched)
	{
		printf("\n setting index = %d", index);
		if (_openbox_button[index].NeedAction())
		{
			switch (index)
			{
			case 0://claim
				_user.AddCoin(_reward_coin, true);
				_user.AddGem(_reward_gem);
				_open_box_close = true;
				for (int i = 0; i < 3; i++)
				{
					if (_arr_item_reward[i]._id != -1)
					{
						//_items_relics[_user._quest_num_relics_own].Init(SPRITEID_HUD_ITEM, _arr_item_reward[i]._group, _arr_item_reward[i]._id, 0, 0,false);
						ModifyRelicItems(_arr_item_reward[i]._group, _arr_item_reward[i]._id,false);
						_user.AddNewRelics(_arr_item_reward[i]._id, _arr_item_reward[i]._group);
						ModifyInfo(_arr_item_reward[i]._group, _arr_item_reward[i]._id);
						//AddItem(_arr_item_reward[i]._id, _arr_item_reward[i]._num);
						_arr_item_reward[i].Reset();
					}
				}
				_user.UserDataSave();
				
				
				break;
			case 1://retry
			{
                
                if (Device::IsNetworkAvailable() && !_has_watched_ads)
                {
                    
					bool hasShowads = false;
#if defined (ANDROID_OS)
					//if (GAME()->HasVideoAds())
					//if(GAME()->HasAdmobRewardedVideo())
					{
						GAME()->ShowVideoAds();
						//GAME()->ShowAdmobRewardedVideo();
						_has_watched_ads = true;
						hasShowads = true;
					}
					//else
					{
						//_has_watched_ads = true;
						//GAME()->_on_video_ads_reward = true;
					}
#else
					int adboxtype = PineAdBox::HasVideoAds(true);
					//printf("\n adboxtype: %d", adboxtype);
					if (adboxtype >= 0)
					{
						PineAdBox::ShowVideoAds(adboxtype);
						_has_watched_ads = true;
						hasShowads = true;
					}
#endif
					if (hasShowads)
					{
						_need_log_double_chest = true;
					}
					
					//if (_has_watched_ads && !hasShowads)
					//{
					//	OPENBOX_NUM_BUTTON = 1;
					//	for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
					//	{
					//		_openbox_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
					//		_openbox_button[i].SetAnim(SPRITEID_HUD_CHESTS, 13);
					//		_openbox_button[i].SetPos(0, 0);
					//		//_openbox_button[i].SetState(BUTTON_STATE_HIDE);
					//	}
					//}
                }
                
					   /*_has_retry_openbox = true;
					   _open_box_force_open = false;
					   _open_box_count_complete = 0;
					   _item_box_count_reward = 0;
					   _open_box_text_opac = 0;
					   _openning_opac = 0;
					   _user.AddGem(-1);
					   ResetHeroesCollected();
					   _reward_coin = 0;
					   _reward_gem = 0;
					   _xp_reward = 0;
					   ResetItemObject();
					   //BoxItem_Init();
					   for (int i = 0; i < BOX_ITEM_NUM; i++)
					   {
					   if (_arr_box_item[i]._choosen)
					   {

					   _arr_box_item[i]._choosen = false;

					   }
					   _arr_box_item[i].SetPos(_arr_box_item[i]._scale_center_x, _arr_box_item[i]._scale_center_y);
					   _arr_box_item[i].SetTarget(_arr_box_item[i]._scale_center_x, _arr_box_item[i]._scale_center_y);
					   _arr_box_item[i]._scale_max = false;
					   _arr_box_item[i].SetState(ITEM_STATE_FORCE_CLOSE);
					   }
					   _shuffle_item_current = 0;
					   _shuffly_speed = 1;
					   //printf("\n _shuffly_speed = %d", _shuffly_speed);
					   _retry_open_state = 1;
					   for (int i = 0; i < 3; i++)
					   {
					   _arr_item_reward[i].Reset();
					   }*/
			}
				break;
			default:
				break;
			}
			for (int i = 0; i < OPENBOX_NUM_BUTTON; i++)
			{
				if (_openbox_button[i]._state != BUTTON_STATE_LOCK && _openbox_button[i]._state != BUTTON_STATE_HIDE)
				{
					_openbox_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
		}
		return true;
	}
	bool ret = false;
	for (int i = 0; i < GAME()->_num_touches; i++)
	{
		for (int button = 0; button < OPENBOX_NUM_BUTTON; button++)
		{
			if (_openbox_button[button]._state == BUTTON_STATE_LOCK || _openbox_button[button]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _openbox_button[button].TZ_GetX();
			int y = _openbox_button[button].TZ_GetY();
			int w = _openbox_button[button].TZ_GetWidth();
			int h = _openbox_button[button].TZ_GetHeight();
			Button *bt = &_openbox_button[button];
            //printf("\nTOUCHS(i)->_state = %d",TOUCHS(i)->_state);
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (bt->_touch_id == -1)
					{
						bt->_touch_id = TOUCHS(i)->_id;
						bt->SetState(BUTTON_STATE_SELECT);
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					/*if (bt->IsAction(TOUCHS(i)->_id))
					{
					bt->SetState(BUTTON_STATE_SELECT);
					}*/
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (bt->IsAction(TOUCHS(i)->_id))
					{
						bt->SetState(BUTTON_STATE_ACTIVE);
						GAME()->PlaySFX(SFX_BUTTON);
					}
				}
				if (bt->IsAction(TOUCHS(i)->_id) && _upgrade_count_frame_add_coin >= 0)
				{
					ret = true;
				}
			}
			else
			{
				if (bt->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
                        //CGame::_this->SetTouchComlete(i);
						bt->_touch_id = -1;
						bt->SetState(BUTTON_STATE_NORMAL);
					}
				}
			}
		}
	}
    
	return ret;
}

void TDGame::BoxItemShuffle()
{
	bool shuffling = true;
	if (_shuffle_item_current >= NUM_MAX_BOX_ITEM)
	{
		_shuffle_item_current = 0;
		_shuffly_speed++;
	}
	if (_shuffly_speed >= 2 && _shuffle_item_current >= 5)
	{
		_retry_open_state = 2;
		return;
	}
	float x = 0;
	float y = 0;
	float tar_x = 0;
	float tar_y = 0;
	int index = 0;
	int index2 = 0;
	ItemBox temp;
	if (_shuffle_item_current > 0)
	{
		
		index = _item_box_index[_shuffle_item_current-1];
		float dis = CMath::DISTANCE(_arr_box_item[index].GetPosX(), _arr_box_item[index].GetPosY(), k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2 - 50);
		_arr_box_item[index]._dis_with_screen_center = dis;
		//_arr_box_item[index].SetTarget(_arr_box_item[index2].GetTargetX(), _arr_box_item[index2].GetTargetY());
		//_arr_box_item[index2].SetTarget(temp.GetTargetX(), temp.GetTargetY());
		index = _item_box_index[_shuffle_item_current];
		index2 = _item_box_index[CMath::RANDOM(0,8)];
		_shuffle_index_be_call = index2;
		_retry_open_state = 1;
			
		float dis1 = 200;//CMath::DISTANCE(_arr_box_item[index].GetPosX(), _arr_box_item[index].GetPosY(), _arr_box_item[index2].GetPosX(), _arr_box_item[index2].GetPosY());
		temp.SetTarget(_arr_box_item[index].GetTargetX(), _arr_box_item[index].GetTargetY());
		temp.SetScaleCenter(_arr_box_item[index].GetTargetX(), _arr_box_item[index].GetTargetY());
		_arr_box_item[index]._dis_with_screen_center = dis1  * _shuffly_speed + _shuffle_item_current * 20;
		_arr_box_item[index2]._dis_with_screen_center = dis1  * _shuffly_speed + _shuffle_item_current * 20;
		_arr_box_item[index].SetTarget(_arr_box_item[index2].GetTargetX(), _arr_box_item[index2].GetTargetY());
		//_arr_box_item[index].SetScaleCenter(_arr_box_item[index2].GetTargetX(), _arr_box_item[index2].GetTargetY());
		_arr_box_item[index2].SetTarget(temp.GetTargetX(), temp.GetTargetY());
		//_arr_box_item[index2].SetScaleCenter(temp.GetTargetX(), temp.GetTargetY());
		_shuffle_item_current++;
	}
	else
	{
		index = _item_box_index[_shuffle_item_current];
		index2 = _item_box_index[CMath::RANDOM(0, 8)];
		_shuffle_index_be_call = index2;
		x = _arr_box_item[index].GetPosX();
		y = _arr_box_item[index].GetPosY();
		tar_x = _arr_box_item[index].GetTargetX();
		tar_y = _arr_box_item[index].GetTargetY();
		float dis1 = 200;// CMath::DISTANCE(_arr_box_item[index].GetPosX(), _arr_box_item[index].GetPosY(), _arr_box_item[index2].GetPosX(), _arr_box_item[index2].GetPosY());
		temp.SetTarget(_arr_box_item[index].GetTargetX(), _arr_box_item[index].GetTargetY());
		temp.SetScaleCenter(_arr_box_item[index].GetTargetX(), _arr_box_item[index].GetTargetY());
		_arr_box_item[index]._dis_with_screen_center = dis1  * _shuffly_speed + _shuffle_item_current*20;
		_arr_box_item[index2]._dis_with_screen_center = dis1  * _shuffly_speed + _shuffle_item_current * 20;
		_arr_box_item[index].SetTarget(_arr_box_item[index2].GetTargetX(), _arr_box_item[index2].GetTargetY());
		//_arr_box_item[index].SetScaleCenter(_arr_box_item[index2].GetTargetX(), _arr_box_item[index2].GetTargetY());
		_arr_box_item[index2].SetTarget(temp.GetTargetX(), temp.GetTargetY());
		//_arr_box_item[index2].SetScaleCenter(temp.GetTargetX(), temp.GetTargetY());
		_shuffle_item_current++;
	}
}

void TDGame::BoxItemInit(bool free)
{
	_open_box_force_open = false;
	int y_begin = 370;
	_reward_coin = 0;
	_reward_gem = 0;
	int count_hero = 0;
	int arr[9];
	int arr_suffle[9];
	int num = NUM_MAX_BOX_ITEM;
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		arr[i] = i;
		arr_suffle[i] = i;
	}
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		int rand = CMath::RANDOM(0, num - 1);
		arr_suffle[i] = arr[rand];
		for (int j = rand; j < num - 1; j++)
		{
			arr[j] = arr[j+1];
		}
		num--;
	}
	if (free)
	{
		int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
		int param_value = CGameDesign::FileTreasure::CSheetSheet2::Value;
		int param_rate = CGameDesign::FileTreasure::CSheetSheet2::Rate;
		int param_type = CGameDesign::FileTreasure::CSheetSheet2::Type;
        int param_size = CGameDesign::FileTreasure::CSheetSheet2::size_id;
		int battle_cur = _battle_current;
		int coin_start = GetDesignTreasure(battle_cur, param_coin, false);
		for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
		{
			float x = i % 3 * (BOX_ITEM_WIDTH + 60) + 140;
			float y = y_begin + i / 3 * (BOX_ITEM_HEIGHT + 80);
			if (NUM_MAX_BOX_ITEM <= 1)
			{
				x = k_SCREEN_WIDTH / 2;
				y = k_SCREEN_HEIGHT / 2;
			}
			else
			{
				x = i % 3 * (BOX_ITEM_WIDTH + 60) + 140;
				y = y_begin + i / 3 * (BOX_ITEM_HEIGHT + 80);
			}

			int sprite = SPRITEID_HUD_CHESTS;
			int type = GetDesignTreasure(arr_suffle[i], param_type,true);
			float value = GetDesignTreasureInfo(arr_suffle[i], param_value, true);
            int size = GetDesignTreasure(arr_suffle[i], param_size, true);
			int itemid = 0;
			int group = 0;
			int frame = 0;
			int rate = 0;
			rate = (GetDesignTreasure(arr_suffle[i], param_rate,true));
			//printf("\n rate = %d - value = %d", rate, value);
			//printf("\n open box level design = %d", (_user._location_current) / 5);
			
			if (type == ITEM_BOX_TYPE_GEM)
			{
				sprite = SPRITEID_HUD_CHESTS;
				//frame = 21;
			}
			else if (type == ITEM_BOX_TYPE_COIN)
			{
				sprite = SPRITEID_HUD_CHESTS;
				value *= coin_start;
				//frame = 13;
			}
            frame = size + 26;

			_item_box_index[i] = i;
			_arr_box_item[i].Init(sprite, frame, type, itemid, group, rate, (int)value, x, y, x, y);
			printf("\n index = %d rate = %d - type = %d",i, rate, type);
		}
	}
	else
	{
		int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
		int param_value = CGameDesign::FileGeneral::CSheetLoterry_design::Value;
		int param_rate = CGameDesign::FileGeneral::CSheetLoterry_design::Rate;
		int param_type = CGameDesign::FileGeneral::CSheetLoterry_design::Type;
		int battle_cur = _battle_current;
		int coin_start = GetDesignTreasure(battle_cur, param_coin, false);
		for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
		{
			float x = i % 3 * (BOX_ITEM_WIDTH + 60) + 140;
			float y = y_begin + i / 3 * (BOX_ITEM_HEIGHT + 80);
			if (NUM_MAX_BOX_ITEM <= 1)
			{
				x = k_SCREEN_WIDTH / 2;
				y = k_SCREEN_HEIGHT / 2;
			}
			else
			{
				x = i % 3 * (BOX_ITEM_WIDTH + 60) + 140;
				y = y_begin + i / 3 * (BOX_ITEM_HEIGHT + 80);
			}

			int sprite = SPRITEID_HUD_CHESTS;
			int type = GetDesignChest(arr_suffle[i], param_type);
			int value = GetDesignChest(arr_suffle[i], param_value);
			int itemid = 0;
			int group = 0;
			int frame = 0;
			int rate = 0;
			rate = (int)(GetDesignChestFloat(arr_suffle[i], param_rate));
			//printf("\n rate = %d - value = %d", rate, value);
			//printf("\n open box level design = %d", (_user._location_current) / 5);
			if (type == ITEM_BOX_TYPE_ITEMS)
			{
				int total_hero_relic = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
				int total_weapon_relic = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
				int total_enemy_relic = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;

				int arr_relic_id[NUM_MAX_ITEM_RELICS];
				int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
				int id = 0;
				int num_relic = 0;
				for (int i = 0; i < total_hero_relic; i++)
				{
					id = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, paramid);
					int paraminterid = CGameDesign::FileRelics_design::CSheetHero_Relics::Hero_ID;
					int interactive_id = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, paraminterid);
					if (interactive_id == HERO_ID_SANTA || interactive_id == HERO_ID_WOLF_RANGER
                        //|| interactive_id == HERO_ID_ACHEMIST
                        )
					{
						continue;
					}
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
				itemid = id_summon;
				group = group_summon;
				int param_frameid = CGameDesign::FileSpriteManager::CSheetSprite_Relic::SpriteId;
				int param_name = CGameDesign::FileRelics_design::CSheetHero_Relics::Name;
				int spriteindex = GetDesignRelicsSpriteIndex(GetDesignRelicsString(itemid - 1, group, param_name));
				sprite = SPRITEID_HUD_ITEM;
				frame = GetDesignRelicsSprite(spriteindex, param_frameid);

			}
			else if (type == ITEM_BOX_TYPE_COIN)
			{
				sprite = SPRITEID_HUD_CHESTS;
				value *= coin_start;
				frame = 30;
			}

			_item_box_index[i] = i;
			_arr_box_item[i].Init(sprite, frame, type, itemid, group, rate, value, x, y, x, y);
			//printf("\n index = %d rate = %d - type = %d",i, rate, type);
		}
	}
	
	//SwapIndexBox();
	//BoxItem_Shuffle();
}

void TDGame::SwapItem(int index1, int index2)
{
	ItemBox temp;
	temp._frame_id = _arr_box_item[index1]._frame_id;
	temp._group = _arr_box_item[index1]._group;
	temp._sprite_id = _arr_box_item[index1]._sprite_id;
	temp.SetType(_arr_box_item[index1].GetType());
	temp.SetValue(_arr_box_item[index1].GetValue());
	temp._scale_center_x = _arr_box_item[index1]._scale_center_x;
	temp._scale_center_y = _arr_box_item[index1]._scale_center_y;
	temp._dis_with_screen_center = _arr_box_item[index1]._dis_with_screen_center;

	_arr_box_item[index1]._frame_id = _arr_box_item[index2]._frame_id;
	_arr_box_item[index1]._group = _arr_box_item[index2]._group;
	_arr_box_item[index1]._sprite_id = _arr_box_item[index2]._sprite_id;
	_arr_box_item[index1].SetType(_arr_box_item[index2].GetType());
	_arr_box_item[index1].SetValue(_arr_box_item[index2].GetValue());
	_arr_box_item[index1]._scale_center_x = _arr_box_item[index2]._scale_center_x;
	_arr_box_item[index1]._scale_center_y = _arr_box_item[index2]._scale_center_y;
	_arr_box_item[index1]._dis_with_screen_center = _arr_box_item[index2]._dis_with_screen_center;

	_arr_box_item[index2].SetType(temp.GetType());
	_arr_box_item[index2].SetValue(temp.GetValue());
	_arr_box_item[index2]._scale_center_x = temp._scale_center_x;
	_arr_box_item[index2]._scale_center_y = temp._scale_center_y;
	_arr_box_item[index2]._dis_with_screen_center = temp._dis_with_screen_center;
	_arr_box_item[index2]._frame_id = temp._frame_id;
	_arr_box_item[index2]._group = temp._group;
	_arr_box_item[index2]._sprite_id = temp._sprite_id;

}

bool TDGame::OpenBoxUpdateTouchItem()
{
    //printf("\n _openning_opac = %d,_item_box_count_reward = %d,_retry_open_state = %d",_openning_opac,_item_box_count_reward,_retry_open_state);
	if (_openning_opac > 0 || _item_box_count_reward >= 3 || _retry_open_state == 1)
	{
        for (int i = 0; i < GAME()->_num_touches; i++)
        {
            TOUCHS(i)->_state = TOUCH_UP;
        }
        for (int button = 0; button < NUM_MAX_BOX_ITEM; button++)
        {
            _arr_box_item[_item_box_index[button]]._touch_id = -1;
        }
		return false;
	}
	bool ret = false;
	for (int i = 0; i < GAME()->_num_touches; i++)
	{
		for (int button = 0; button < NUM_MAX_BOX_ITEM; button++)
		{
			int item_state = _arr_box_item[_item_box_index[button]].GetState();
			if (item_state >= ITEM_STATE_OPENNED ||
                item_state == ITEM_STATE_INIT)
			{
				continue;
			}
			int x = _arr_box_item[_item_box_index[button]].GetPosX() - BOX_ITEM_WIDTH / 2 - 20;
			int y = _arr_box_item[_item_box_index[button]].GetPosY() - BOX_ITEM_HEIGHT / 2 - 20;
			int w = BOX_ITEM_WIDTH + 40;
			int h = BOX_ITEM_HEIGHT + 40;
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (_arr_box_item[_item_box_index[button]]._touch_id == -1)
					{
						if (!_has_retry_openbox)
						{
							int rand = CMath::RANDOM(1, 100);
							bool isforce = false;
							if (_item_box_count_reward >= 2 && !_has_collected_item_force)
							{
								isforce = true;
							}
							int index = GetChestIndexRandom(rand, isforce);
							while (index == -1)
							{
								rand = CMath::RANDOM(1, 100);
								index = GetChestIndexRandom(rand, isforce);
							}
							if (button != index)
							{
								OpenBoxItemSwap(button, index);
							}
						}
						ret = true;
						_arr_box_item[_item_box_index[button]]._touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (_arr_box_item[_item_box_index[button]]._touch_id == TOUCHS(i)->_id)
					{
						ret = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_arr_box_item[_item_box_index[button]]._touch_id == TOUCHS(i)->_id)
					{
						int itembox_index = _item_box_index[button];
						_arr_box_item[itembox_index]._touch_id = -1;
						_arr_box_item[itembox_index]._choosen = true;
						//printf("\n item box index[%d] = %d", button, itembox_index);
						if (_arr_box_item[itembox_index].GetType() == ITEM_BOX_TYPE_COIN)
						{
							_reward_coin += _arr_box_item[itembox_index].GetValue();
						}
						else if (_arr_box_item[itembox_index].GetType() == ITEM_BOX_TYPE_ITEMS)
						{
							OpenBoxAddItem(_arr_box_item[itembox_index]._id_item, _arr_box_item[itembox_index].GetValue(), _arr_box_item[itembox_index]._group);
						}
						else if (_arr_box_item[itembox_index].GetType() == ITEM_BOX_TYPE_GEM)
						{
							_reward_gem += _arr_box_item[itembox_index].GetValue();
						}
						_openning_opac = 0;
						_item_box_count_reward++;
						_arr_box_item[itembox_index].SetTarget(k_SCREEN_WIDTH / 2 , k_SCREEN_HEIGHT / 2 - 50 );
						GAME()->PlaySFX(SFX_BUTTON);
						ret = true;
					}
				}
				if (_arr_box_item[_item_box_index[button]]._touch_id == TOUCHS(i)->_id)
				{
					ret = true;
				}
			}
			else
			{
				if (_arr_box_item[_item_box_index[button]]._touch_id == TOUCHS(i)->_id)
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						_arr_box_item[_item_box_index[button]]._touch_id = -1;
					}
				}
			}
			if (ret)
			{
				return ret;
			}
		}
	}
	return ret;
}

void TDGame::ItemsReward::Init(int id, int num, int group)
{
	_id = id;
	_num = num;
	_group = group;
}
void TDGame::ItemsReward::Reset()
{
	_id = -1;
	_num = 0;
}

void TDGame::OpenBoxAddItem(int id, int num, int group)
{
	//printf("\n open add item id = %d - num =%d", id, num);
	for (int i = 0; i < 3; i++)
	{
		if (_arr_item_reward[i]._id == -1)
		{
			_arr_item_reward[i].Init(id, num,group);
			break;
		}
	}
}

void TDGame::OpenBoxItemSwap(int index1, int index2)
{
	//printf("\n index1 = %d -- index2 = %d", index1, index2);
	int tempindex = _item_box_index[index1];
	int swap_index1 = _item_box_index[index1];
	int swap_index2 = _item_box_index[index2];
	_item_box_index[index1] = _item_box_index[index2];
	_item_box_index[index2] = tempindex;
	
	ItemBox temp;
	temp.SetTarget(_arr_box_item[swap_index1].GetTargetX(), _arr_box_item[swap_index1].GetTargetY());
	temp.SetScaleCenter(_arr_box_item[swap_index1].GetTargetX(), _arr_box_item[swap_index1].GetTargetY());
	temp._dis_with_screen_center = _arr_box_item[swap_index1]._dis_with_screen_center;
	_arr_box_item[swap_index1].SetTarget(_arr_box_item[swap_index2].GetTargetX(), _arr_box_item[swap_index2].GetTargetY());
	_arr_box_item[swap_index1].SetPos(_arr_box_item[swap_index2].GetTargetX(), _arr_box_item[swap_index2].GetTargetY());
	_arr_box_item[swap_index1].SetScaleCenter(_arr_box_item[swap_index2].GetTargetX(), _arr_box_item[swap_index2].GetTargetY());
	_arr_box_item[swap_index1]._dis_with_screen_center = _arr_box_item[swap_index2]._dis_with_screen_center;
	_arr_box_item[swap_index2].SetTarget(temp.GetTargetX(), temp.GetTargetY());
	_arr_box_item[swap_index2].SetPos(temp.GetTargetX(), temp.GetTargetY());
	_arr_box_item[swap_index2].SetScaleCenter(temp.GetTargetX(), temp.GetTargetY());
	_arr_box_item[swap_index2]._dis_with_screen_center = temp._dis_with_screen_center;
	
}

int TDGame::GetItemBoxIndex(int percent)
{
	int index = -1;
	for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
	{
		if (_arr_box_item[_item_box_index[i]]._rate == percent)
		{
			index = i;
			break;
		}
	}
	return index;
}
int TDGame::GetChestIndexRandom(int percent, bool forceitem)
{
	//printf("\n ---- percent = %d -- forceitem:%d  -- _has_collected_item_force: %d-----", percent, forceitem, _has_collected_item_force);
	int index = -1;
	int index_min = -1;
	int min_rate = -1;
	int rate_real = 0;
	if (forceitem)
	{
		for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
		{
			if (_arr_box_item[_item_box_index[i]].GetState() < ITEM_STATE_OPENNED)
			{
				if (min_rate == -1)
				{
					min_rate = _arr_box_item[_item_box_index[i]]._rate;
				}
				if (_arr_box_item[_item_box_index[i]]._rate + rate_real > percent && rate_real <= percent
					&& (_arr_box_item[_item_box_index[i]]._frame_id == 29 || _arr_box_item[_item_box_index[i]]._frame_id == 30))
				{
					index = i;
					break;

				}
			}
			rate_real += _arr_box_item[_item_box_index[i]]._rate;
		}
	}
	else
	{
		for (int i = 0; i < NUM_MAX_BOX_ITEM; i++)
		{
			if (_arr_box_item[_item_box_index[i]].GetState() < ITEM_STATE_OPENNED)
			{
				if (min_rate == -1)
				{
					min_rate = _arr_box_item[_item_box_index[i]]._rate;
				}
				if (_arr_box_item[_item_box_index[i]]._rate + rate_real > percent && rate_real <= percent)
				{
					index = i;
					break;

				}
			}
			rate_real += _arr_box_item[_item_box_index[i]]._rate;
		}
	}
	
	if (index == -1)
	{
		int per = CMath::RANDOM(1, 100);
		GetChestIndexRandom(per,forceitem);
		//printf("\n Retry GetChestIndexRandom");
		//index = index_min;
	}
	if (_arr_box_item[_item_box_index[index]]._frame_id == 29 || _arr_box_item[_item_box_index[index]]._frame_id == 30)
	{
		_has_collected_item_force = true;
	}
	return index;
}
void TDGame::ModifyRelicItems(int group, int id, bool lock)
{
	for (int i = 0; i < _relics_num_of;i++)
	{
		if (_items_relics[i]._group == group && _items_relics[i]._id == id)
		{
			_items_relics[i]._is_lock = lock;
		}
	}
}
