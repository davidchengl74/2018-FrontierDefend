#include "pch.h"
#include "../../GameCore/CGame.h"

int CGame::_auto_block_frame = 0;
int CGame::_last_auto_key = -1;
bool TDGame::_auto_wheel = true;
bool has_new_quest = false;

void TDGame::UpdateAndRenderPrestige()
{
	int row = _user._user_level_reset;
	if (_user._user_level_reset >= _game_design.General.SheetReset_Design.int32Value._totalData-1 || _user._is_new_user_ver15)
	{
		return;
	}
	int battle_limit = _game_design.General.SheetReset_Design.int32Value.getValue(row, CGameDesign::FileGeneral::CSheetReset_Design::Battle_Reset);
	//if (_battle_current < battle_limit - 1 || _user._user_battle_just_reset >= _battle_current)
	//{
	//	while (_user._user_battle_just_reset >= battle_limit)
	//	{
	//		row++;
	//		battle_limit = _game_design.General.SheetReset_Design.int32Value.getValue(row, CGameDesign::FileGeneral::CSheetReset_Design::Battle_Reset);
	//	}
	//	GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 7, 0, 0);
	//	int mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(7, 0);
	//	int my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(7, 0);
	//	//G()->SetColorMask(0xffD3D8D6);
	//	GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), mx - 20, my+60, _HCENTER, "(Require Battle %d)", battle_limit);
	//	//G()->ClearColorMask();
	//}
	//else
	{
#ifdef MAC_OS
		float randomX =(Device::IsIpadDevice() ? 128 : 0);
#else
		float randomX =0;
#endif
		float randomY = 0;
		if (_prestige_touch_id == -1)
		{
			GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 5, randomX, randomY);
		}
		else
		{
			GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 6, randomX, randomY);
		}
		int mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(7, 0) + randomX;
		int my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(7, 0) + randomY;
		if (battle_limit - 1 > _battle_current)
		{
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), mx - 15, my + 60, _HCENTER, "(Require Battle %d)", battle_limit);
		}
		
		if (_auto_hold_key >= 0 || _ingame_fill_opac > 0 || _dialogMng.isOpenDialog() || _tutorial_step != TUTORIAL_STEP_FREE || k_GS_PLAYGAME != _current_state)
		{
			return;
		}
		for (int i = 0; i < GAME()->_num_touches; i++)
		{
			int w = 140;
			int h = 100;
			int x = randomX + GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleX(5, 0);
			int y = randomY + GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleY(5, 0);

			//G()->FillRect(x,y,w,h);
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{

				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (_prestige_touch_id == -1)
					{
						_prestige_touch_id = TOUCHS(i)->_id;
						GAME()->PlaySFX(SFX_BUTTON);
						_auto_hold_key = -1;
						ResetInit();
						if (!_dialogMng.isOpenDialog())
						{
							
							char text[256];
							sprintf(text, "Require Battle %d", battle_limit);
							if (_battle_current < battle_limit - 1 || _user._user_battle_just_reset >= _battle_current)
							{
								_dialogMng.Add(DIALOG_CONTEXT_VIEW_PRESTIGE, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
							}
							else
							{
								_dialogMng.Add(DIALOG_CONTEXT_PRESTIGE, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
							}
							
							GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
						}
					}
				}
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (TOUCHS(i)->_id == _prestige_touch_id)
					{
						_prestige_touch_id = -1;
					}
				}
			}
			else
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (TOUCHS(i)->_id == _prestige_touch_id)
					{
						_prestige_touch_id = -1;
					}
				}
			}
		}
	}
}

void TDGame::UpdateAndRenderPinePromo()
{
	if (!_user._has_show_pine_promo && _pine_promo_render_x >= 300)
	{
		return;
	}
	if (k_GS_PLAYGAME != _current_state)
	{
		_pine_promo_touch_id = -1;
	}
	if (_pine_promo_star_timer > 0)
	{
		_pine_promo_star_timer--;
		if (_pine_promo_star_timer<= 0)
		{
			_pine_promo_star_timer = CMath::RANDOM(1, 6) * 60;
			_pine_promo_star_index = CMath::RANDOM(1,4);
			_pine_promo_star_rotate = CMath::RANDOM(3,360);
			_pine_promo_star_scale = 0;
			_pine_promo_star_state = 0;
		}
	}
	_pine_promo_star_rotate += 1;
	if (_pine_promo_star_rotate >= 360)
	{
		_pine_promo_star_rotate -= 360;
	}
	switch (_pine_promo_star_state)
	{
	case 0:
		_pine_promo_star_scale += 0.05f;
		if (_pine_promo_star_scale >= 1.3f)
		{
			_pine_promo_star_state++;
			_pine_promo_star_scale = 1.3f;
		}
		break;
	case 1:
		_pine_promo_star_scale += -0.03f;
		if (_pine_promo_star_scale <= 0)
		{
			_pine_promo_star_state++;
			_pine_promo_star_scale = 0;
		}
		break;
	default:
		break;
	}
	if (!_user._has_show_pine_promo)
	{
		if (_pine_promo_render_x < 300)
		{
			_pine_promo_render_x += 20;
			if (_pine_promo_render_x >= 300)
			{
				_pine_promo_render_x = 300;
			}
		}
	}
#ifdef MAC_OS
	float randomX = -_pine_promo_render_x + (Device::IsIpadDevice() ? -128 : 0);
#else
	float randomX = -_pine_promo_render_x;
#endif
	float randomY = 0;
	GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->DrawFrame(G(), 5, randomX, randomY);
	if (_pine_promo_star_scale > 0)
	{
		float mx = GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->GetFModuleX(5, _pine_promo_star_index);
		float my = GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->GetFModuleY(5, _pine_promo_star_index);
		G()->SetScale(_pine_promo_star_scale, _pine_promo_star_scale, mx -_pine_promo_render_x, my);
		G()->SetRotate(_pine_promo_star_rotate, mx - _pine_promo_render_x, my);
		GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->DrawFrame(G(), 6, mx - _pine_promo_render_x, my);
		G()->ClearRotate();
		G()->ClearScale();
	}
	
	if (_auto_hold_key >= 0 ||_menu_button_active || _ingame_fill_opac > 0 || _dialogMng.isOpenDialog() || _tutorial_step != TUTORIAL_STEP_FREE || k_GS_PLAYGAME != _current_state)
	{
		_pine_promo_touch_id = -1;
		return;
	}

	for (int i = 0; i < GAME()->_num_touches; i++)
	{
		int w = 140;
		int h = 120;
		int x = randomX + GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->GetFModuleX(5,0);
		int y = randomY + GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME)->GetFModuleY(5, 0);

		//G()->FillRect(x,y,w,h);
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{

			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_pine_promo_touch_id == -1)
				{
#if defined (MAC_OS)
					PineSocial::OpenURL("https://goo.gl/NPLuvu");
					GAME()->_is_cancel_show_ads_on_resume = true;
#elif defined (ANDROID_OS)
					PineSocial::OpenURL("https://goo.gl/EPt90G");
					GAME()->_is_cancel_show_ads_on_resume = true;
#endif

					_user._has_show_pine_promo = false;
					_user.UserDataSave();
					_pine_promo_touch_id = TOUCHS(i)->_id;
					GAME()->PlaySFX(SFX_BUTTON);
					_auto_hold_key = -1;
				}
			}
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (TOUCHS(i)->_id == _pine_promo_touch_id)
				{
					_pine_promo_touch_id = -1;
				}
			}
		}
		else
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (TOUCHS(i)->_id == _pine_promo_touch_id)
				{
					_pine_promo_touch_id = -1;
				}
			}
		}
	}
}

void TDGame::UpdateAndRenderIAPDis()
{
	if ((_iap_dis_100_timer == 0 && _iap_dis_cur_timer == 0 ) || !_user._tutorial_completed)
	{
		return;
	}
#ifdef MAC_OS
	float randomX = 0 + (Device::IsIpadDevice() ? 128 : 0);
#else
	float randomX = 0;
#endif

	float randomY = 0;
	float angle = (GAME()->_frame_counter * 3) % 180;
	float zoom = 0.8 + CMath::SIN(angle)*0.1f;
	int type_iap_dis = DIALOG_CONTEXT_IAP_DISCOUNT_SPEC;
	randomY += 150;
	if (_iap_dis_100_timer != 0)
	{
#if defined (ANDROID_OS)
		switch (_user._user_iap_level)
		{
		case CUser::enumiAPLevel::iAP_LEVEL_FREE:
			sprintf(_iap_dis_idstr, "%s", "nfd_0_99_promo");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_PREMIUM:
			sprintf(_iap_dis_idstr, "%s", "nfd_4_99_promo");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_ROYAL:
			sprintf(_iap_dis_idstr, "%s", "ndf_9_99_promo");
			break;
		default:
			break;
		}
		//sprintf(_iap_dis_idstr, "%s", "nfd_0_99_promo");
#else
		//sprintf(_iap_dis_idstr, "%s", "NFD_0.99_PROMO");
		switch (_user._user_iap_level)
		{
		case CUser::enumiAPLevel::iAP_LEVEL_FREE:
			sprintf(_iap_dis_idstr, "%s", "NFD_0.99_PROMO");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_PREMIUM:
			sprintf(_iap_dis_idstr, "%s", "NFD_4.99_PROMO");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_ROYAL:
			sprintf(_iap_dis_idstr, "%s", "NFD_9.99_PROMO_2");
			break;
		default:
			break;
		}
#endif
		

		type_iap_dis = DIALOG_CONTEXT_IAP_DISCOUNT_OFF;
		G()->SetScale(zoom*1.5, zoom*1.5, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		G()->SetRotate(_iap_glow_rotate, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		G()->ClearRotate();

		G()->SetScale(zoom, zoom, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 40, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		G()->ClearScale();

		int sec = ((_iap_dis_100_timer / 60)) % 60;
		int min = ((_iap_dis_100_timer / 60) / 60) % 60;
		int hour = ((_iap_dis_100_timer / 60) / 60) / 60;

		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 42, k_SCREEN_WIDTH / 2 + randomX, randomY);
		float posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(42, 0);
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(42, 0);
		int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 3;
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2 + randomX + posx, randomY + posy, _HCENTER | _VCENTER, "%02d:%02d:%02d", hour, min, sec);
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
		
	}
	else if (_iap_dis_cur_timer != 0)
	{
		sprintf(_iap_dis_idstr, "%s", _user._iap_dis_current);
		G()->SetScale(zoom*1.5, zoom*1.5, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		G()->SetRotate(_iap_glow_rotate, k_SCREEN_WIDTH  / 2 + randomX,  randomY);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, k_SCREEN_WIDTH  / 2 + randomX,  randomY);
		G()->ClearRotate();

		G()->SetScale(zoom, zoom, k_SCREEN_WIDTH / 2 + randomX,  randomY);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 41, k_SCREEN_WIDTH  / 2 + randomX,  randomY);
		G()->ClearScale();

		int sec = ((_iap_dis_cur_timer / 60)) % 60;
		int min = ((_iap_dis_cur_timer / 60) / 60) % 60;
		int hour = ((_iap_dis_cur_timer / 60) / 60) / 60;

		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 42, k_SCREEN_WIDTH / 2 + randomX, randomY);
		float posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(42, 0);
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(42, 0);
		int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 3;
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2 + randomX + posx, randomY + posy, _HCENTER | _VCENTER, "%02d:%02d:%02d", hour, min, sec);
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;

	}
	if (_auto_hold_key >= 0 || k_GS_PLAYGAME != _current_state || _ingame_fill_opac > 0 || _dialogMng.isOpenDialog() || _tutorial_step != TUTORIAL_STEP_FREE)
	{
		return;
	}
	for (int i = 0; i < GAME()->_num_touches; i++)
	{
		int w = 120;
		int h = 120;
		int x = k_SCREEN_WIDTH/2 + randomX - w/2;
		int y = randomY - h/2;
		
		//G()->FillRect(x,y,w,h);
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{

			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_iap_dis_button_id == -1)
				{
					_auto_hold_key = -1;
					_iap_dis_button_id = TOUCHS(i)->_id;
					GAME()->PlaySFX(SFX_BUTTON);
				}
			}
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				//TOUCHS(i)->_flag = false;
				if (TOUCHS(i)->_id == _iap_dis_button_id)
				{
					
					_iap_dis_button_id = -1;
					GetValueIapDis(_iap_dis_idstr);
					_dialogMng.Add(type_iap_dis, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "title", "body", 0, 0);
					char title[128];
					char decs[1024];
					sprintf(title, "%s View", _iap_dis_idstr);
					sprintf(decs, "%s View", _iap_dis_idstr);
					char type[128];
					sprintf(type, "%s", "iap_promo_logs");
#if defined (MAC_OS) || (ANDROID_OS)
					PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs,type);
					Device::GA_LogContents(title, decs, type);
#endif
				}
			}
		}
		else
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (TOUCHS(i)->_id == _iap_dis_button_id)
				{
					_iap_dis_button_id = -1;
				}
			}
		}
	}
}
void TDGame::FreeGiftRewardActive()
{
	_user._watch_ad_time = time(NULL) + _time_waiting_free_gift;
	_free_gift_type = enumFreeGiftType::FREE_GIFT_TYPE_GEM;
	//PDEBUG("\n\n\n ads_time reset : %d -- _time_waiting_free_gift:%d  \n\n\n", distime, _time_waiting_free_gift);
	int param_type = CGameDesign::FileGeneral::CSheetFree_Gift::Type;
	int param_value = CGameDesign::FileGeneral::CSheetFree_Gift::Value;
	int type = GetDesignFreeGift(_user._watch_ad_times, param_type);
	int value = GetDesignFreeGift(_user._watch_ad_times, param_value);
	char text[256];
	char tittle[128];
	switch (type)
	{
	case WATCH_ADS_REWARD_TYPE_COIN:
	{
		if (value <= 10)
		{
			_free_gift_type = enumFreeGiftType::FREE_GIFT_TYPE_COIN1;
		}
		else if (value <= 20)
		{
			_free_gift_type = enumFreeGiftType::FREE_GIFT_TYPE_COIN2;
		}
		else
		{
			_free_gift_type = enumFreeGiftType::FREE_GIFT_TYPE_COIN3;
		}
		int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
		int reward_coin = GetDesignTreasure(_battle_current, param_coin, false);
		value *= reward_coin;
		char valuetext[128];
		ConvertMoneyInbalace(value, valuetext);
		sprintf(text, "%s", valuetext);
		sprintf(tittle, "YOU HAVE RECEIVED");
	}
	break;
	case WATCH_ADS_REWARD_TYPE_GEM:
	{
		/*char valuetext[128];
		ConvertMoneyInbalace(value, valuetext);
		sprintf(text, "%s :", valuetext);*/
		sprintf(text, "%d", value);
		sprintf(tittle, "YOU HAVE RECEIVED");

	}
	break;
	case WATCH_ADS_REWARD_TYPE_AUTO_ATT:
		sprintf(tittle, "Auto Attack");
		sprintf(text, "x%d", value);
		break;
	case WATCH_ADS_REWARD_TYPE_AUTO_SKILL:
		sprintf(tittle, "Auto Skill");
		sprintf(text, "x%d", value);
		break;
	case WATCH_ADS_REWARD_TYPE_DOUBLE_COIN:
		sprintf(tittle, "Double Coin");
		sprintf(text, "in %d seconds", value);
		break;
	default:
		break;
	}
	GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
	_dialogMng.Add(DIALOG_CONTEXT_WATCH_ADS, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, tittle, text, 0, 0);
}

void TDGame::UpdateAndRenderFreeGift()
{

    if(k_GS_PLAYGAME != _current_state)
    {
       
        //_has_ads_free_gift = false;
        _auto_hold_key = -1;
    }
    //if(PineAdBox::showAdState == SHOW_AD_PROCESSING )
    //{
    //     CGame::_this->_auto_hold_key = -1;
    //}

	if (_need_log_freegift)
	{
		char title[128];
		char decs[1024];
		sprintf(title, "%s Click", "Free-Gift");
		sprintf(decs, "%s Click", "Free-Gift");
		char type[128];
		sprintf(type, "%s", "common_events");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
		Device::GA_LogContents(title, decs, type);
#endif
		_need_log_freegift = false;
	}
	
#if defined (ANDROID_OS)
	if (_has_ads_free_gift && GAME()->_on_video_ads_reward && _skipframe_show_reward<=0)
	{
		_button_free_gift_touch_id = -1;
		_auto_hold_key = -1;
		if (!_dialogMng.isOpenDialog())
		{
			GAME()->_on_video_ads_reward = false;
			_has_ads_free_gift = false;
			FreeGiftRewardActive();
		}
		return;
	}
#elif defined(MAC_OS)
    if ((PineAdBox::showAdState == SHOW_AD_PROCESSING || PineAdBox::showAdState == SHOW_AD_COMPLETED) && _has_ads_free_gift)
    {
		_button_free_gift_touch_id = -1;
		_auto_hold_key = -1;
        if (PineAdBox::showAdState == SHOW_AD_COMPLETED)
        {

            if (!_dialogMng.isOpenDialog())
            {
                PineAdBox::showAdState = SHOW_AD_NONE;
                _has_ads_free_gift = false;
				FreeGiftRewardActive();
            }
        }
        return;
    }
#endif
#ifdef MAC_OS
    float randomX = -130 + (Device::IsIpadDevice()?128:0);
#else
    float randomX = -130;
#endif
    float randomY = -20;
    float angle = (GAME()->_frame_counter*3)%180;
    float zoom = 0.8 + CMath::SIN(angle)*0.1f;
    if (_has_double_coin_timer > 0 || _user._has_double_coin)
    {
        randomX -= 100;
    }
    bool gift_available = false;
	INT_TIME time_cur = time(NULL);
	/*PDEBUG("\n ads_time : %lld -- _time_waiting_free_gift:%d", _user._watch_ad_time - time_cur, _time_waiting_free_gift);
	PDEBUG("\n _auto_hold_key : %d", _auto_hold_key);*/
#if defined (ANDROID_OS)
		//GAME()->HasAds())
	if (_user._tutorial_completed && _user._watch_ad_time <= time_cur && Device::IsNetworkAvailable() /*&& GAME()->HasVideoSkippableAds()*/)

#elif defined(MAC_OS)
	if (_user._tutorial_completed &&_user._watch_ad_time <= time_cur && Device::IsNetworkAvailable() && PineAdBox::HasVideoAds(true) >= 0)
#else 
	if(_user._tutorial_completed)
#endif
    {

        G()->SetScale(zoom*1.5, zoom*1.5, k_SCREEN_WIDTH-135/2 + randomX,240 + randomY);
        G()->SetRotate(angle/2, k_SCREEN_WIDTH-135/2 + randomX,240 + randomY);
        GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(),22,k_SCREEN_WIDTH-135/2 + randomX,240 + randomY);
        G()->ClearRotate();
        G()->SetScale(zoom, zoom, k_SCREEN_WIDTH-135/2 + randomX,240 + randomY);
        GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(),23,k_SCREEN_WIDTH-135/2 + randomX,240 + randomY);
        G()->ClearScale();
        gift_available = true;
    }
	else
	{
		return;
	}
	if (_auto_hold_key >= 0 || k_GS_PLAYGAME != _current_state || !gift_available 
		|| _dialogMng.isOpenDialog() || _tutorial_step != TUTORIAL_STEP_FREE
		|| _daily_reward_active)
	{
		return;
	}
    for(int i = 0; i < GAME()->_num_touches; i++)
    {
		int w = 100;
		int h = 100;
        int x = k_SCREEN_WIDTH-135 + randomX;
        int y = 180 + randomY;
        
        //G()->FillRect(x,y,w,h);
        if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
        {
            
            if (TOUCHS(i)->_state == TOUCH_DOWN)
            {
				if (_button_free_gift_touch_id == -1)
				{
					TOUCHS(i)->_state = TOUCH_DRAG;
					GAME()->PlaySFX(SFX_BUTTON);
					_button_free_gift_touch_id = TOUCHS(i)->_id;
				}
            }
            if (TOUCHS(i)->_state == TOUCH_UP)
            {
                //TOUCHS(i)->_flag = false;
				
				//PDEBUG("\n _button_free_gift_touch_id:%d -- TOUCHS(i)->_id:%d", _button_free_gift_touch_id, TOUCHS(i)->_id);
                if(TOUCHS(i)->_id == _button_free_gift_touch_id)
                {
                    _button_free_gift_touch_id = -1;
                    if (!_has_ads_free_gift)
                    {
                        
#if defined (ANDROID_OS)
						//PDEBUG("\n GAME()->HasAds():%d", GAME()->HasAds());
						//if (GAME()->HasAds())
						//{
						//	_has_ads_free_gift = true;
						//	GAME()->ShowAds();
						//	//_skipframe_show_reward = 60;
						//}
						//if (GAME()->HasVideoSkippableAds())
						//if(GAME()->HasVideoAds())
						{
							//GAME()->ShowSkippableVideoAds();

							GAME()->ShowVideoAds();
							_has_ads_free_gift = true;
							GAME()->_is_waiting_for_reward = true;
							//GAME()->_on_video_ads_reward = true;
							_skipframe_show_reward = 60;
							GAME()->is_showing_ads = true;
						}
#elif defined (MAC_OS)
						int adboxtype = PineAdBox::HasVideoAds(true);
						if (adboxtype >= 0)
						{
							_has_ads_free_gift = true;
							
							PineAdBox::ShowVideoAds(adboxtype);
							
						}
#endif
						if (_has_ads_free_gift)
						{
							_need_log_freegift = true;
						}
                        break;
                    }
                    
                }
            }
            
        }
		else
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (TOUCHS(i)->_id == _button_free_gift_touch_id)
				{
					_button_free_gift_touch_id = -1;
				}
			}
		}
    }
}
void TDGame::GamePlayRender(float x, float y, int opac)
{
	//G()->SetColor(0xffff0000);
	//G()->FillFullScreen();
	G()->SetScale(GAME()->_game_context.ScaleOut, GAME()->_game_context.ScaleOut, k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT/2 - 50);

	

	if (_is_night)
	{
		GET_SPRITE(_background_dark_sprite[_bg_spriteid])->DrawFrame(G(), 0, _shake_effectx, _shake_effecty);
		if (_is_changing_background_night)
 		{
			G()->SetOpacity(_changing_background_night_opac);
			GET_SPRITE(_background_sprite[_bg_spriteid])->DrawFrame(G(), 0, _shake_effectx, _shake_effecty);
			G()->SetOpacity(100);
		}
	}
	else
	{
		GET_SPRITE(_background_sprite[_bg_spriteid])->DrawFrame(G(), 0, _shake_effectx, _shake_effecty);
		if (_is_changing_background_night)
		{
			G()->SetOpacity(_changing_background_night_opac);
			GET_SPRITE(_background_dark_sprite[_bg_spriteid])->DrawFrame(G(), 0, _shake_effectx, _shake_effecty);
			G()->SetOpacity(100);
		}
	}    
	GET_SPRITE(_bg_underground_spriteid)->DrawFrame(G(), 0, _shake_effectx, _shake_effecty);
	G()->ClearScale();
    
	_castle.Render(_shake_effectx + _effect_castle_die_shakex + _point_o.X, _shake_effecty + _effect_castle_die_shakey + _effect_castle_die_scrolly + _point_o.Y, 100);
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		_weapon[i].RenderEffectShadow(x, y);
	}
	
    _boss_reward.Render(0, 0);
	CharacterRender(0, 0);
	WeaponRender(0, 0);
    UpdateAndRenderFreeGift();
	UpdateAndRenderIAPDis();
	UpdateAndRenderPrestige();
	//UpdateAndRenderPinePromo();
	MassAutoRender(x, y - 54, _mass_opac_full);
	IngameButtonRender(0, 40);
    MenuIngameRender(0, 0);
	RenderEffectHPLost();
    /*
#pragma region TOPEBOX_PROMO_GAME
	if (_user._has_show_pine_promo)
	{
		if (_topebox_game.GamePromoIsReady() && _user._tutorial_completed)
		{
			if (!_topebox_game.GamePromoHasTouchDown())
			{
				if (_topebox_game_scrollEff > 0)
				{
					_topebox_game_scrollEff += -10;
					if (_topebox_game_scrollEff <= 0)
					{
						_topebox_game_scrollEff = 0;
					}
				}
			}
		}
	}
	else
	{
		float max = _topebox_game._icon_w*2.5f;
		if (_topebox_game_scrollEff < max)
		{
			_topebox_game_scrollEff += 7.5f;
			if (_topebox_game_scrollEff >= max)
			{
				_topebox_game_scrollEff = max;
				_topebox_game.ResetGamePromoInfo();
				_topebox_game.SetDeviceID(_user._game_promo_deviceID);
			}
		}
	}
	char textname[128];
	int lenght = sprintf(textname, "%s", _topebox_game._des);
	float text_w = GET_SPRITE(SPRITEID_FONT_HUD)->GetAnsiTextWidth(textname, 0, lenght);
	float scalex = text_w / GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFrameWidth(19) + 0.2f;
	G()->SetScale(scalex, 1.65f, GAME_PROMO_RENDER_X + -_topebox_game_scrollEff - 20 + _point_o.X, GAME_PROMO_RENDER_Y- 5 + _point_o.Y);
	GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 19, GAME_PROMO_RENDER_X + -_topebox_game_scrollEff - 20 + _point_o.X, GAME_PROMO_RENDER_Y - 5 + _point_o.Y);
	G()->ClearScale();
	_topebox_game.RenderGamePromo(GAME_PROMO_RENDER_X + -_topebox_game_scrollEff + _point_o.X, GAME_PROMO_RENDER_Y + _point_o.Y);
#pragma endregion
*/
/***Topebox promo**/
	if (GAME()->is_config_downloaded && !_user._has_remove_ads_pop_up)
	{
		if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON)
		{
			GAME()->is_disable_promo = false;
		}
		if (/*GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER || */GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON)
		{
			GAME()->is_renderd_promo = true;
		}

		if (GAME()->is_renderd_promo)
		{

			if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON)
			{
				GAME()->_topebox_game.is_rendered = true;
			}
#pragma region TOPEBOX_PROMO_GAME
			//PDEBUG("\n _game->_game_promo_has_show:%d -- GAME()->_topebox_game.render_banner_topebox:%d", _user._game_promo_has_show, GAME()->_topebox_game.render_banner_topebox);
			if (_user._game_promo_has_show)
			{

				if (GAME()->is_disable_promo)
				{
					float max = GAME()->_topebox_game._icon_w*2.5f;
					if (GAME()->_topebox_game._topebox_game_scrollEff < max)
					{
						GAME()->_topebox_game._topebox_game_scrollEff += 10;
						if (GAME()->_topebox_game._topebox_game_scrollEff >= max)
						{
							GAME()->_topebox_game._topebox_game_scrollEff = max;
						}
					}

				}
				else {
					if (GAME()->_topebox_game.GamePromoIsReady())
					{
						//PDEBUG("\n _game->_user._topebox_game_scrollEff: %f", GAME()->_topebox_game_scrollEff);
						if (!GAME()->_topebox_game.GamePromoHasTouchDown())
						{
							float max = GAME()->_topebox_game._icon_w*2.5f;
							if (GAME()->_topebox_game._topebox_game_scrollEff > 0)
							{
								GAME()->_topebox_game._topebox_game_scrollEff += -10;
								if (GAME()->_topebox_game._topebox_game_scrollEff <= 0)
								{
									GAME()->_topebox_game._topebox_game_scrollEff = 0;
								}
							}
						}
					}
				}
				//PDEBUG("\n _game->_user.GamePromoIsReady: %d", _game->_user._game_promo_has_show);
			}
			else
			{
				float max = GAME()->_topebox_game._icon_w*2.5f;
				if (GAME()->_topebox_game._topebox_game_scrollEff < max)
				{
					GAME()->_topebox_game._topebox_game_scrollEff += 10;
					if (GAME()->_topebox_game._topebox_game_scrollEff >= max)
					{
						GAME()->_topebox_game._topebox_game_scrollEff = max;
						GAME()->_topebox_game.ResetGamePromoInfo();
					}
				}

				GAME()->_topebox_game.show_banner_topebox_active = false;
				//PDEBUG("\n _game->_topebox_game.show_banner_topebox_active  => Gameplay render");
			}
			int fw = 165;//GET_SPRITE(SPRITEID_HUD_PAUSE_01)->GetFrameWidth(82);
			char textname[128];
			if (GAME()->_topebox_game.GamePromoIsReady())
			{
				int lenght = sprintf(textname, "%s", GAME()->_topebox_game._des);
				float text_w = GET_SPRITE(SPRITEID_FONT_TOPEBOX_ADS)->GetAnsiTextWidth(textname, 0, lenght);

				float scalex = text_w / fw + 0.2f;
				//PDEBUG("\n _game->_topebox_game._des:%s -- lenght:%d -- text_w:%f -- scalex:%f", _game->_topebox_game._des, lenght, text_w, scalex);
				G()->SetColor(0xff000000);
				G()->SetOpacity(90);
				G()->SetScale(1.0f, 1.0f, GAME_PROMO_RENDER_X + -GAME()->_topebox_game._topebox_game_scrollEff + 0 - 35, GAME_PROMO_RENDER_Y - GAME()->_topebox_game._icon_h + 0 - 20);
				//GET_SPRITE(SPRITEID_HUD_PAUSE_01)->DrawFrame(G(), 82, GAME_PROMO_RENDER_X + -_game->_topebox_game_scrollEff + x - 30, GAME_PROMO_RENDER_Y - _game->_topebox_game._icon_h + y - 20);
				if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON && GAME()->_topebox_game.is_rendered)
				{
					G()->SetOpacity(40);
					//if (GAME()->is_map)
					{
						G()->FillRect(GAME_PROMO_RENDER_X + -GAME()->_topebox_game._topebox_game_scrollEff + 0 - 25, GAME_PROMO_RENDER_Y + -GAME()->_topebox_game._icon_h + 0 + 10 + 30, fw, fw, true);
					}

				}
				//else if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER && GAME()->_topebox_game.render_banner_topebox) {
				//	//_gp->FillRect(0, 0, k_SCREEN_WIDTH, k_SCREEN_HEIGHT, true);
				//	G()->FillFullScreen(true);
				//}

				G()->ClearScale();
				G()->SetOpacity(100);
			}
			//PDEBUG("\n GAME()->_topebox_game.is_rendered:%d -- GAME()->_topebox_game.typeAds:%d", GAME()->_topebox_game.is_rendered, GAME()->_topebox_game.typeAds);
			if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON && GAME()->_topebox_game.is_rendered)
			{
				//if (GAME()->is_map)
				{
					GAME()->_topebox_game.RenderGamePromo(GAME_PROMO_RENDER_X + -GAME()->_topebox_game._topebox_game_scrollEff + 0 - 20, GAME_PROMO_RENDER_Y - GAME()->_topebox_game._icon_h + 30);
				}
			}
			/*else if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER && GAME()->_topebox_game.render_banner_topebox)
			{
				GAME()->_topebox_game.RenderGamePromo(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
			}*/
		}




#pragma endregion
	}

	
	/******End Topebox promo*****/

	_wheel_has_value = WheelIsReady();
	StarAnimRender(0,0);
	_gift_box.Render(0, 0);
	GiftRewardRender(0, 0);
	TouchEffectFireRender(x, y, opac);
	InterfaceRender(-_point_o.X, _point_o.Y);
	ItemsRender(-_shake_effectx, -_shake_effecty);
	
	VictoryRender(0, 0);
	if (!_menu_button_active && !_menu_button_scrolling)
	{
		MenuRender(_point_o.X, _point_o.Y);
	}

	if (_rate_us_active || _invitation_active)
	{
		if (_menu_button_active || _menu_button_scrolling)
		{
			MenuRender(_point_o.X, _point_o.Y);
		}
		IapRender(-_point_o.X, _point_o.Y);
		G()->SetOpacity(_ingame_fill_opac*0.8f);
		G()->SetColor(0xff000000);
		G()->FillFullScreen(true);
		G()->SetOpacity(opac);
        if(_rate_us_active)
        {
            RateUsRender(0, 0);
        }
		else
        {
            //InvitationRender(0, 0);
        }
	}
	else
	{
		G()->SetOpacity(_ingame_fill_opac*0.8f);
		G()->SetColor(0xff000000);
		G()->FillFullScreen(true);
		G()->SetOpacity(opac);
		if (_menu_button_active || _menu_button_scrolling)
		{
			MenuRender(_point_o.X, _point_o.Y);
		}
		IapRender(-_point_o.X, _point_o.Y);
	}
	
	ChangeBackgroundRender();
	if (_user._tutorial_step != TUTORIAL_STEP_BUILD_TOWER && _user._tutorial_step != TUTORIAL_STEP_BUY_HERO && _user._tutorial_step != TUTORIAL_STEP_BUY_RELIC)
	{
		TutorialRender(0, 0);
	}
    _be_damage_opacity -= 3;
    if(_be_damage_opacity < 0)
    {
        _be_damage_opacity = 0;
    }
    if(_be_damage_opacity > 0)
    {
        int opacity = 200*_be_damage_opacity/256;
        opacity = (opacity<<24)|0x00ff0000;
        G()->SetColor(opacity);
        G()->FillFullScreen(true);
    }
    if(_castle.GetPercentHP() <= 20)
    {
        int opacity = 10 + 30*CMath::SIN(CGame::_this->_frame_counter*6%180);
        G()->SetOpacity(opacity);
        float scalex = _screen_width/k_SCREEN_WIDTH;
        float scaley = _screen_height/k_SCREEN_HEIGHT;
        G()->SetScale(scalex, scaley, k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT/2);
        CGame::_this->_red_warning.DrawImageWithRect(G(),0,0);
        G()->ClearScale();
    }
    
    
    
    //tutorial
    int index_inbattle = 0;
    
    
    //game->_user._tutorial_attack_auto_enable = false;
    //game->_user._tutorial_auto_attack_complete = false;
    if(!_user._tutorial_completed && _user._tutorial_step != TUTORIAL_STEP_MENU_CASTLE && _tutorial_step == TUTORIAL_STEP_FREE)
    {
        if(!_user._tutorial_auto_attack_complete &&
           _ingame_hero_button[index_inbattle]._heroID >= 0
           &&_ingame_hero_button[index_inbattle]._full_pa && k_GS_PLAYGAME == _current_state)
        {
            _user._tutorial_attack_auto_enable = true;
            _auto_hold_key = -1;
            float ww = _ingame_button[INGAME_BUTTON_AUTO1].TZ_GetWidth();
            float hh = _ingame_button[INGAME_BUTTON_AUTO1].TZ_GetHeight();
            float xx = _ingame_button[INGAME_BUTTON_AUTO1].TZ_GetX() + ww/2;
            float yy = _ingame_button[INGAME_BUTTON_AUTO1].TZ_GetY() + hh/2;
            G()->SetOpacity(50);
            GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + xx, y + yy);
            G()->SetOpacity(100);
            GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0-150);
            int linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
            GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
            GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(),k_SCREEN_WIDTH/2, y + TUTORIAL_TEXT_POSY - 150, k_SCREEN_WIDTH*0.8f, _HCENTER | _VCENTER, "Tap Auto to mad attack\n without holding the button!");
            GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
            _tutorial_anim_hand.SetPos(x + xx, y + yy);
            _tutorial_anim_hand.DrawAnimObject(G());
            _tutorial_anim_hand.UpdateAnimObject();
        }
    }
    
    
    if(CGame::_this->IsAndroidVersion)
    {
        //_isOpenGooglePlay = true;
        if(_isOpenGooglePlay)
        {
#if !defined (MAC_OS)
			if (GAME()->_isBackkeyPress)
			{
				_isOpenGooglePlay = false;
				GAME()->_isBackkeyPress = false;
				for (int k = 0; k < 3; k++)
				{
					_google_play_menu[k]._touch_id = -1;
				}
				_exit_google_touch_id = -1;
			}
#endif
            G()->SetColor(0xa0000000);
            G()->FillFullScreen(true);
            GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 32, k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT/2);
            for(int  i = 0; i < 3; i++)
            {
                _google_play_menu[i].Render(G());
                _google_play_menu[i].Update();
                
            }
            bool ret = false;
            for(int touch = 0; touch < CGame::_this->_num_touches; touch++)
                
                
            {
                if(TOUCHS(touch)->_id < 0)
                {
                    continue;
                }

                for(int button = 0; button < 3; button++)
                {
                    float x = _google_play_menu[button].TZ_GetX();
                    float y = _google_play_menu[button].TZ_GetY();
                    float ww = _google_play_menu[button].TZ_GetWidth();
                    float hh = _google_play_menu[button].TZ_GetHeight();
                    if(CHECK_POINT_IN_RECT(TOUCHS(touch)->x, TOUCHS(touch)->y,x,y,ww,hh))
                    {
                        switch(TOUCHS(touch)->_state)
                        {
                            case TOUCH_DOWN:
								//PDEBUG("_google_play_menu._touch_id = %d, current touch down id = %d", _google_play_menu[button]._touch_id, TOUCHS(touch)->_id);
                                if(_google_play_menu[button]._touch_id != TOUCHS(touch)->_id)
                                {
                                    _google_play_menu[button]._touch_id = TOUCHS(touch)->_id;
                                    ret = true;
                                }
                                break;
                            case TOUCH_DRAG:
								//PDEBUG("_google_play_menu._touch_id = %d, current touch drag id = %d", _google_play_menu[button]._touch_id, TOUCHS(touch)->_id);
                                if(_google_play_menu[button]._touch_id == TOUCHS(touch)->_id)
                                {
                                    ret = true;
                                }
                                break;
                            case TOUCH_UP:
								//PDEBUG("_google_play_menu._touch_id = %d, current touch up id = %d", _google_play_menu[button]._touch_id, TOUCHS(touch)->_id);
                                if(_google_play_menu[button]._touch_id == TOUCHS(touch)->_id)
                                {
                                    switch(button)
                                    {
                                        case 0://android leaderboard
                                            printf("\nandroid leaderboard");
                                            CGame::_this->GooglePlayShowLeaderBoard();
                                            break;
                                        case 1:
                                            CGame::_this->GooglePlayShowAchievement();
                                            printf("\n android achievement");
                                            break;
                                        case 2:
                                            printf("\n android google driver sync");
                                            CGame::_this->GooglePlaySynDriver();
                                            break;
                                    }
                                    for(int k = 0; k < 3; k++)
                                    {
                                        _google_play_menu[k]._touch_id = -1;
                                    }
                                    ret = true;
                                }
                                break;
                           
                                
                        }
                    }
                    else
                    {
                        if(TOUCHS(touch)->_id == TOUCH_UP)
                        {
                            if(_google_play_menu[button]._touch_id == TOUCHS(touch)->_id)
                            {
                                _google_play_menu[button]._touch_id = -1;
                                ret = true;
                            }
                        }
                    }
                }
                
                
                
                
            }
            
            if(!ret)
            {
                for(int touch = 0; touch < CGame::_this->_num_touches; touch++)     
                {
                    if(TOUCHS(touch)->_id < 0)
                    {
                        continue;
                    }
                    switch(TOUCHS(touch)->_state)
                    {
                        case TOUCH_DOWN:
							//PDEBUG("touch down _exit_google_touch_id = %d", TOUCHS(touch)->_id);
                            _exit_google_touch_id = TOUCHS(touch)->_id;
                            break;
                        case TOUCH_DRAG:
                            break;
                        case TOUCH_UP:
							//PDEBUG("touch up _exit_google_touch_id = %d, touch id = %d", _exit_google_touch_id, TOUCHS(touch)->_id);
                            if(_exit_google_touch_id == TOUCHS(touch)->_id)
                            {
								//PDEBUG("Disable menu google 1");
                                _isOpenGooglePlay = false;
                                for(int k = 0; k < 3; k++)
                                {
                                    _google_play_menu[k]._touch_id = -1;
                                }
								_exit_google_touch_id = -1;
                            }
                            break;
                    }
                }
                
            }
            else
            {
                _exit_google_touch_id = -1;
            }
        
        }
    }

	G()->SetOpacity(100);
    


}
void TDGame::GamePlayUpdate()
{

	if (_sub_state == k_INIT)
	{
#if defined(_WINDOWS)
		//_iap_dis_cur_timer = 1.2 * 60 * 60;
#endif
		
		_auto_hold_key = -1;
		MassAutoInit();
		_prestige_touch_id = -1;
		_skipframe_show_reward = 0;
		if (!_user._has_show_pine_promo)
		{
			_pine_promo_render_x = 300;
		}
		else
		{
			_pine_promo_star_timer = CMath::RANDOM(1, 10) * 60;
			_pine_promo_star_index = 0;
			_pine_promo_star_rotate = 0;
			_pine_promo_star_scale = 0;
			_pine_promo_star_state = 0;
			_pine_promo_render_x = 0;
		}

		_pine_promo_touch_id = -1;
		_button_free_gift_touch_id = -1;
		_user.ActiveIapPackDiscount(false);
		_iap_glow_rotate = 0;
		_iap_dis_button_id = -1;
		_count_frame_check_quest = 0;
		_has_ads_free_gift = false;
		_be_damage_opacity = 0;
#if defined MAC_OS
		PineAdBox::SetSkipAdvert();
#endif
		IapInit();
		_castle.Modify();
		for (int i = 0; i < NUM_MAX_WEAPON; i++)
		{
			_weapon[i].Modify();
		}
		for (int i = 0; i < NUM_MAX_HERO; i++)
		{
			int heroid = _user._hero_arr[i]._heroid;
			int level = _user._hero_arr[i]._level;
			bool deployed = _user._hero_arr[i]._is_deployed;
			if (heroid > 0)
			{
				int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
				if (index_inbattle >= 0)
				{
					_hero_inbattle_arr[index_inbattle].Modify(heroid, level, deployed, false, _hero_inbattle_arr[index_inbattle].GetPowerAttack(), _hero_inbattle_arr[index_inbattle].GetPowerSkill(), _hero_inbattle_arr[index_inbattle]._rar_level, _hero_inbattle_arr[index_inbattle]._has_promo);
				}
			}
		}
		int wheel_min = _user._wheel_time_reset - time(NULL);
		if (wheel_min > 0)
		{
			//wheel_min /= 60 + 1;
			_wheel_time.setDateBYSecond(wheel_min);
		}
		else
		{
			_wheel_time.setDateBYSecond(0);
		}
		_anim_network.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
		_anim_network.SetAnim(125, true);
		_anim_network.SetPos(0, 0);
		_has_double_coin_timer = 0;
		_effect_castle_die_shakex = 0;
		_effect_castle_die_shakey = 0;
		_effect_castle_die_scrolly = 0;
		_wheel_has_value = false;
		TutorialInit();
		_level_current = 0;
		if (_reward_earning_off_type >= 1)
		{
			_wave_current = 10;
		}
		else
		{
			_wave_current = 1;
		}
#if defined (MAC_OS) || defined (ANDROID_OS)
#else
		//_user.AddCoin(80000000,true);
		//_battle_current = 69;
		//_user.AddGem(100);
#endif
		_is_use_auto_attack_free = -1;
		_is_use_auto_skill_free = -1;
		_boss_reward.Init(0);
		_num_max_hero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
		int total_hero_relic = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
		int total_weapon_relic = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
		int total_enemy_relic = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;
		_num_max_item_relics = total_enemy_relic + total_weapon_relic + total_hero_relic;

		_is_changing_background_night = false;
		_changing_background_night_opac = 100;
		_is_night = false;
		_num_effect_hp_lost = 0;
		_bg_spriteid = -1;
		_bg_spriteid_next = -1;
		_ingame_fill_opac = 0;

		_is_changing_background = false;
		_changing_background_opac_max = false;
		_changing_background_opac = 0;
		_battle_old = _battle_current;
#if defined (MAC_OS)
#else
		/*_battle_current = 149;
		_wave_current = 10;*/
		//_user.AddCoin(1000000000, true);
		//_user.AddGem(10000);
		/*_user._daily_quest_num = 1000000;
		_user._has_completed_battle_max = false;*/

#endif

		InitBattle(_battle_current, _wave_current);
		int posx = 0;
		int posy = 0;
		
		int count_hero_range = 0;
		_num_hero_deployed = 0;
		_gift_box.Init(GIFT_BOX_TYPE_AUTO_ATT, 1, 10, 3, NUM_MAX_HERO_INBATTLE);
		for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
		{
			posx = 140 + i * (210 + 25) /*+ (1 - i)*_point_o.X*/;
			posy = 1075;
			bool has_init = false;
			for (int j = 0; j < NUM_MAX_HERO; j++)
			{
				if (_user._hero_arr[j]._heroid >= 0)
				{
					if (_user._hero_arr[j]._is_deployed && _user._hero_arr[j]._slot_deploy_number == i)
					{
						int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[j]._heroid);
						if (index_inbattle >= 0)
						{
							if (_reward_earning_off_type >= 1 || _has_revive_in_battle)
							{
								_hero_inbattle_arr[index_inbattle].AddPowerAttack(_hero_inbattle_arr[index_inbattle]._power_attack_max);
								_hero_inbattle_arr[index_inbattle].AddPowerSkill(_hero_inbattle_arr[index_inbattle].GetLimitBreak());
							}
							_ingame_hero_button[i].Init(posx, posy, _hero_inbattle_arr[index_inbattle].GetSpriteID(), _hero_inbattle_arr[index_inbattle].GetHeroID(), _hero_inbattle_arr[index_inbattle].GetPowerAttack(), _hero_inbattle_arr[index_inbattle].GetPowerSkill(), _hero_inbattle_arr[index_inbattle].GetLimitBreak());

							if (_hero_inbattle_arr[index_inbattle].GetTypeRange() == HERO_TYPE_RANGE_RANGE)
							{
								_hero_inbattle_arr[index_inbattle].SetPos(110 + count_hero_range * 30 + _point_o.X, _hero_inbattle_arr[index_inbattle].GetPosY() - count_hero_range * 15 + _point_o.Y);
								count_hero_range++;
							}
							_num_hero_deployed++;
							_num_hero_inbattle++;
							
						}
						has_init = true;
						
						break;
					}
				}
			}

			if (!has_init)
			{
				_ingame_hero_button[i].Init(posx, posy, 0, -1, 0, 0, 1);
			}
			_effect_skill_add_energy[i] = 0;
		}
		IngameButtonInit();
		MenuIngameInit();
		TouchEffectFireInit();
		MenuInit();
		StarAnimInit();

		EffectHeroSkillInit();
		_castle.ChangeCastle();
		ItemsInit();
		_shake_effectx = 0;
		_shake_effecty = 0;
		InitNotifyNew();
		_tutorial_step_ready = true;
		if (!_user._tutorial_completed)
		{
			_tutorial_step_ready = false;
		}

		_num_tap_in_second = 0;
		_time_tap_in_second = 0;
		_num_kill_monster_in_second = 0;
		_time_kill_monster_in_second = 0;
		_sub_state = k_LOOP;
		_rate_us_active = false;
		//InvitationInit();
		VictoryInit();
		_event_notify = false;
		if (strcmp(_user._ivitation_code, "NULL") == 0)
		{
			_event_notify = true;
		}
		UnlockNewHero(HEROES_UNLOCK_TYPE_NORMAL);
	}
	/*if (_user._tutorial_step < TUTORIAL_STEP_MENU_HERO)
	{
		bool empty_hero = true;

		for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
		{
			if (_ingame_hero_button[i]._heroID != -1)
			{
				empty_hero = false;
				break;
			}
		}
		_num_hero_deployed = 0;
		HeroDeployActive(_user._hero_arr[0]._heroid, _num_hero_deployed);
		_num_hero_deployed++;
	}*/
#if defined MAC_OS
    PineAdBox::shouldAppPopup = false;
#endif
    if(PineAdBox::showAdState == SHOW_AD_PROCESSING || PineAdBox::showAdState == SHOW_AD_WAIT_REWARD || PineAdBox::showAdState ==SHOW_AD_SHOWING)
    {
        return;
    }
#if ADD_ADVERT
    if (GAME()->_advert.HasPopup())
    {
        return;
    }
#endif
    if (GAME()->_purchase_procesing_opac > 0 || _current_state != k_GS_PLAYGAME)
    {
        return;
    }
    /*if(!_user._has_pass_invitation && _user._tutorial_completed)
    {
        if(!_invitation_active)
        {
            InvitationInit();
        }
    }*/
	if (_daily_reward_active)
	{
		return;
	}
    if(_invitation_active)
    {
        return;
    }
	if (_rate_us_active)
	{
		RateUsUpdate();
		return;
	}
    
    if(CGame::_this->IsAndroidVersion)
    {
        //_isOpenGooglePlay = true;
        if(_isOpenGooglePlay)
        {
            return;
        }
    }
    
#if !DISABLE_ONLINE_FEATURE
	if (_offline_reward_collected == OFFLINE_RW_COLLECTED_TYPE_NONE && _user._tutorial_completed)
	{
		GetRewardOffline();
	}
#endif
#if !DISABLE_ONLINE_FEATURE
	if (_is_hacked_time && _warning_notify_hacker)
	{
		if (!_dialogMng.isOpenDialog())
		{
			char text[256];
			sprintf(text, "%s", "Please make sure that your device has network connectivity and the date and time settings are accurate to enable Frontier Defense online features.");
			_dialogMng.Add(DIALOG_CONTEXT_WARNING_HACKER, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "Warning!", text, 0, 0);
		}
	}
#endif
	ChangeBackgroundUpdate();
	if(_dialogMng.isOpenDialog())
    {
        return;
    }
	
/*
#pragma region TOPEBOX_PROMO_GAME
	if (_user._has_show_pine_promo)
	{
		if (_topebox_game.GamePromoHasTouchDown())
		{
#if !defined (_WINDOWS)
			if (Device::IsNetworkAvailable())
#endif
			{
				GAME()->_is_cancel_show_ads_on_resume = true;
				_user._has_show_pine_promo = false;
				_user._game_promo_delay_show = time(NULL) + TIME_DELAY_SHOW_TOPEBOX_ADS;
				printf("\n tmcur:%lld --- user_time:%lld", time(NULL), _user._game_promo_delay_show);
				_user._game_promo_order++;
				_topebox_game.ResponseRequest();
#if defined (ANDROID_OS) || defined (MAC_OS)
				PDEBUG("\n ##### Open URL: %s \n", _topebox_game._link_store);
				PineSocial::OpenURL(_topebox_game._link_store);

#endif
				char title[128];
				char decs[1024];
				sprintf(title, "%s Click", "Topebox-Ads");
				sprintf(decs, "%s Click", "Topebox-Ads");
				char type[128];
				sprintf(type, "%s", "topebox_ads");
#if defined (MAC_OS) || (ANDROID_OS)
				PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
				Device::GA_LogContents(title, decs, type);
#endif
				//_user.UserDataSave();
			}
		}
	}
	if (!(_menu_button_active || _menu_button_scrolling))
	{
		if (_user._has_show_pine_promo && _tutorial_step_ready && _auto_hold_key == -1)
		{
			if (_topebox_game.UpdateTouchGamePromo())
			{
				return;
			}
		}
	}
	
#pragma endregion
*/
	if (_user._tutorial_step >= TUTORIAL_STEP_MASS_AUTO)
	{
		if (_mass_opac_full < 100)
		{
			_mass_opac_full += 10;
		}
	}
	if (_reward_earning_off_type >= 0 && !_dialogMng.isOpenDialog())
	{
		char text[256];
		ConvertMoneyInbalace(_reward_earning_off, _reward_earning_off_text);
		if (_reward_earning_off_type <= 1)
		{
			sprintf(text, "Your team earned %s coins.", _reward_earning_off_text);
		}
		else
		{
			sprintf(text, "Your team earned %s coins and reached Boss Battle!", _reward_earning_off_text);
		}

		_dialogMng.Add(DIALOG_CONTEXT_REWARD_EARNING_OFF, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "While you were away...", text, 0, 0);
		GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
	}
	_iap_glow_rotate += 2;
	if (_iap_glow_rotate>=360)
	{
		_iap_glow_rotate -= 360;
	}
	/*if (!_fairy_double_coin_time.isNullDay())
	{
		if (_fairy_double_coin_time.UpdateCountDown())
		{
			_fairy_double_coin_time.setNullDay();
			_has_double_coin_timer = 0;
		}
		else
		{
			_has_double_coin_timer = _fairy_double_coin_time.GetTotalSecond();
		}
	}
	if (!_starter_double_coin_time.isNullDay())
	{
		if (_starter_double_coin_time.UpdateCountDown())
		{
			_starter_double_coin_time.setNullDay();
			_user._iap_starter_double_coin_time = 0;
		}
		else
		{
			_user._iap_starter_double_coin_time = _starter_double_coin_time.GetTotalSecond();
		}
	}*/
	
	if (_ingame_fill_opac <= 0 && _user._num_mass_auto_free > 0)
	{
		if (_user._tutorial_step == TUTORIAL_STEP_MASS_AUTO && _tutorial_step == TUTORIAL_STEP_FREE)
		{
			_tutorial_step = TUTORIAL_STEP_MASS_AUTO;
		}
	}
	if (_battle_current >= _user._rate_trigger && _user._has_rated_us_type == RATE_US_TYPE_NONE)
	{
		//rate us
		if (!_rate_us_active && !_victory_active && _user._tutorial_step >= TUTORIAL_STEP_COMPLETED_2)
		{
			RateUsInit();
		}
	}
	if (_is_changing_background_night)
	{
		if (_changing_background_night_opac > 0)
		{
			_changing_background_night_opac -= 2;
			if (_changing_background_night_opac <= 0)
			{
				_changing_background_night_opac = 0;
				_is_changing_background_night = false;
				if (_is_night)
				{
					if (_background_sprite[_bg_spriteid] != _background_dark_sprite[_bg_spriteid])
					{
						GAME()->UnloadSpriteVer(_background_sprite[_bg_spriteid]);
					}
				}
				else
				{
					if (_background_sprite[_bg_spriteid] != _background_dark_sprite[_bg_spriteid])
					{
						GAME()->UnloadSpriteVer(_background_dark_sprite[_bg_spriteid]);
					}
				}
			}
		}
	}
	if (_time_tap_in_second <= 0)
	{
		_num_tap_in_second = 0;
		_time_tap_in_second = 0;
	}
	else
	{
		_time_tap_in_second--;
	}
	if (_time_kill_monster_in_second <= 0)
	{
		_num_kill_monster_in_second = 0;
		_time_kill_monster_in_second = 0;
	}
	else
	{
		_time_kill_monster_in_second--;
	}
	
	UpdatePoupReward();
	MenuUpdateTouch();
	has_new_quest = false;
	_count_frame_check_quest++;
	if (_count_frame_check_quest >= 5)
	{
		
		_count_frame_check_quest = 0;
		for (int i = 0; i < _num_max_quest; i++)
		{
			if (_user.CheckQuestCompleted(i, _user._quest_current[i], false))
			{
				has_new_quest = true;
			}
		}
		if (!_user._daily_quest_completed)
		{
			if (_user.CheckQuestCompleted(_user._daily_quest_group_current, _daily_quest_current, true))
			{
				has_new_quest = true;
			}
		}
	}
	
	if (has_new_quest)
	{
		if (_effect_notify_menu_button[MENU_BUTTON_OPTIONS]._state == NOTIFY_STATE_NONE)
		{
			_effect_notify_menu_button[MENU_BUTTON_OPTIONS].Active();
		}
		if (_effect_notify_menu_button[MENU_BUTTON_ACHIEVEMENT]._state == NOTIFY_STATE_NONE)
		{
			_effect_notify_menu_button[MENU_BUTTON_ACHIEVEMENT].Active();
		}
	}
	else
	{
		if (_effect_notify_menu_button[MENU_BUTTON_OPTIONS]._state == NOTIFY_STATE_ACTIVE)
		{
			_effect_notify_menu_button[MENU_BUTTON_OPTIONS].Disable();
		}
		if (_effect_notify_menu_button[MENU_BUTTON_ACHIEVEMENT]._state == NOTIFY_STATE_ACTIVE)
		{
			_effect_notify_menu_button[MENU_BUTTON_ACHIEVEMENT].Disable();
		}
	}
	if (_menu_button_active || _menu_button_scrolling)
	{
		if (_menu_button_active)
		{
			_ingame_fill_opac += 10;
			if (_ingame_fill_opac >= 100)
			{
				_ingame_fill_opac = 100;
			}
		}
		else
		{
			_ingame_fill_opac -= 10;
			if (_ingame_fill_opac <= 0)
			{
				_ingame_fill_opac = 0;
				ClearAllTouchUp(TOUCH_TYPE_INGAME);
				
			}
		}
		return;
	}
	else
	{
		if (!_rate_us_active && !_daily_reward_active)
		{
			if (_ingame_fill_opac > 0)
			{
				_ingame_fill_opac -= 10;
				if (_ingame_fill_opac <= 0)
				{
					_ingame_fill_opac = 0;
				}
				return;
			}
		}		
	}
	if (_current_state == k_GS_PLAYGAME)
	{
		IapUpdate();
	}
	
	IngameButtonUpdateTouch();
	MenuIngameUpdateTouch();
	TutorialUpdate();
	_boss_reward.Update();
	ItemsUpdate();
	EffectHeroSkillUpdate();
	_gift_box.Update();
	GiftRewardUpdate();
	VictoryUpdate();
    if (_ingame_fill_opac <= 0 && _tutorial_buy_relic_ready && !_is_changing_background && !_victory_active)
    {
        if (_user._quest_num_relics_own <= 0)
        {
            if (_user._tutorial_step == TUTORIAL_STEP_MENU_RELIC && _tutorial_step == TUTORIAL_STEP_FREE)
            {
                _tutorial_step = TUTORIAL_STEP_MENU_RELIC;
                for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
                {
                    if (i != MENU_INGAME_BUTTON_RELICS)
                    {
                        _menu_ingame_button[i].SetState(BUTTON_STATE_LOCK);
                    }
                }
            }
        }
        else
        {
            _user._tutorial_step = TUTORIAL_STEP_COMPLETED_2;
        }
    }
    if(!_victory_active && _reward_earning_off_type == -1 && _tutorial_step == TUTORIAL_STEP_FREE && _current_state == k_GS_PLAYGAME && !_is_changing_background && !_rate_us_active)
    {
        if(TDGame::_auto_wheel && _wheel_has_value)
        {
            
            TDGame::_auto_wheel = false;
            SetState(k_GS_WHEEL);
            
        }
    }
	if (_show_popup_offline)
	{
		if (!_dialogMng.isOpenDialog())
		{
			char text[256];
			sprintf(text, "%s","If you're busy, we can handle the enemies while you're away! We will collect all coins to but please come back in boss battle.");
			_dialogMng.Add(DIALOG_CONTEXT_OFFLINE_EARNING_PRO, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "NULL", text, 0, 0);
			_show_popup_offline = false;
			_offline_earning_received = true;
		}
	}
    /*//REMVOE fairy
	if (!_gift_box._has_live && (_user._fairy_times_init >= GetDesignGeneralInfo(DESIGN_GENERAL_FAIRY_INIT) ||
		_num_tap_in_agame >= GetDesignGeneralInfo(DESIGN_GENERAL_FAIRY_NUM_TAP))
		&& _user._auto_attack_free < 10 && _user._auto_skill_free < 10 && _battle_current >= 4)
	{
		
        if(_gift_box._state == GIFT_BOX_STATE_FREE || _gift_box._state == GIFT_BOX_STATE_NORMAL)
        {
            _gift_box.Init(GIFT_BOX_TYPE_AUTO_ATT, 1, 10, 3, NUM_MAX_HERO_INBATTLE);
            _user._fairy_times_init = 0;
			_num_tap_in_agame = 0;
        }
		_gift_box._has_live = true;
	}*/
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
		_ingame_hero_button[i].Update();
		int cliph = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(32);
		if (_ingame_hero_button[i]._full_pa && _ingame_hero_button[i]._heroID >= 0)
		{
			//if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state == BUTTON_STATE_LOCK)
			if(_effect_star_anim[i * 2]._state == 0)
			{
				_ingame_button[INGAME_BUTTON_AUTO1 + i].SetState(BUTTON_STATE_NORMAL);
				_ingame_hero_button[i]._effect_hight_light_opac = 0;
				_ingame_hero_button[i]._effect_hight_light_opac_max = false;
				int mx = _ingame_button[INGAME_BUTTON_AUTO1 + i].TZ_GetX();
				int my = _ingame_button[INGAME_BUTTON_AUTO1 + i].TZ_GetY();
				int mw = _ingame_button[INGAME_BUTTON_AUTO1 + i].TZ_GetWidth();
				int mh = _ingame_button[INGAME_BUTTON_AUTO1 + i].TZ_GetHeight();
				_ingame_hero_button[i]._full_power_effect_fire.Active(mx + mw / 2, my + mh / 2, 8, 5, 1, 0, 1.0f, 100);
				GAME()->PlaySFX(SFX_AUTO_FULL);
				StarAnimActive(i * 2, mx + CMath::RANDOM(12, mw - 10), my + 7, 0.1f, 2.0f);
				StarAnimActive(i * 2 + 1, mx + CMath::RANDOM(12, mw -10), my + mh - 10, 0.08f, 1.5f);
			}
			if (_ingame_hero_button[i]._is_use_auto_att != -1)
			{
				int index_heroactive = -1;
				for (int j = 0; j < NUM_MAX_HERO; j++)
				{
					if (_hero_inbattle_arr[j].GetHeroID() == _ingame_hero_button[i]._heroID)
					{
						index_heroactive = j;
						break;
					}
				}
				if (index_heroactive != -1)
				{
					_hero_inbattle_arr[index_heroactive].ActiveAutoAttack(false);
					_is_use_auto_attack_free = -1;
					_user._num_use_auto_attack++;
					//_ingame_hero_button[i]._is_use_auto_att = false;
				}
			}
		}
		cliph = 110;
		if (_ingame_hero_button[i]._clip_ps_current >= cliph && _ingame_hero_button[i]._heroID >= 0)
		{
			//if (_ingame_button[INGAME_BUTTON_SKILL1 + i]._state == BUTTON_STATE_LOCK)
			if (_effect_star_anim[6 + i * 2]._state == 0)
			{
				_ingame_button[INGAME_BUTTON_SKILL1 + i].SetState(BUTTON_STATE_NORMAL);
				int mx = _ingame_button[INGAME_BUTTON_SKILL1 + i].TZ_GetX()+4;
				int my = _ingame_button[INGAME_BUTTON_SKILL1 + i].TZ_GetY();
				int mw = _ingame_button[INGAME_BUTTON_SKILL1 + i].TZ_GetWidth();
				int mh = _ingame_button[INGAME_BUTTON_SKILL1 + i].TZ_GetHeight();
				int angle1 = CMath::RANDOM(30, 90);
				int angle2 = CMath::RANDOM(200, 270);
				StarAnimActive(6+i * 2, mx + mw / 2 + CMath::COS(angle1) * 60, my + mh / 2 + CMath::SIN(angle1) * 60, 0.1f, 2.0f);
				StarAnimActive(6+i * 2 + 1, mx + mw / 2 + CMath::COS(angle2) * 60, my + mh / 2 + CMath::SIN(angle2) * 60, 0.08f, 1.5f);
				_ingame_hero_button[i]._full_power_skill_fire.Active(mx + mw / 2, my + mh / 2, 6, 10, 1, 0, 1.0f, 100);
				GAME()->PlaySFX(SFX_SKILL_FULL);
			}
			if (_ingame_hero_button[i]._is_use_auto_skill != -1)
			{
				int index_heroactive = -1;
				for (int j = 0; j < NUM_MAX_HERO; j++)
				{
					if (_hero_inbattle_arr[j].GetHeroID() == _ingame_hero_button[i]._heroID )
					{
						index_heroactive = j;
						break;
					}
				}
				if (index_heroactive != -1)
				{
					_hero_inbattle_arr[index_heroactive].SkillActive();
					_user._quest_num_use_skill++;
					_is_use_auto_skill_free = -1;
					//_ingame_hero_button[i]._is_use_auto_skill = false;
				}
				
			}
		}
	}
	/*if (_user._iap_starter_double_coin_time > 0)
	{
		_user._iap_starter_double_coin_time--;
		if (_user._iap_starter_double_coin_time <= 0)
		{
			_user._iap_starter_double_coin_time = 0;
		}
	}
	printf("\n _has_double_coin_timer = %d", _has_double_coin_timer);
	if (_has_double_coin_timer > 0)
	{
		_has_double_coin_timer--;
		if (_has_double_coin_timer <=0)
		{
			_has_double_coin_timer = 0;
		}
	}*/
    
    if(_user._tutorial_attack_auto_enable)
    {
        return;
    }
    
	WeaponUpdate();
	CharacterUpdate();
	UpdateEffectHpLost();
	TouchEffectFireUpdate();
	StarAnimUpdate();
	UpdateNotifyNew();
	UpdateShowRelicSpecial();
	MassAutoUpdate();

#if defined (MAC_OS)
	
	//GAME()->_serverThread.UpdateTimeSynSaveToserver();
#endif

//	/***********************/
//	if (!_user._has_remove_ads_pop_up)
//	{
//#pragma region TOPEBOX_PROMO_GAME
//		if (_user._game_promo_has_show)
//		{
//
//#if defined (ANDROID_OS)
//			if (GAME()->_topebox_game._is_close_ads)
//			{
//				GAME()->_topebox_game.render_banner_topebox = false;
//				if (GAME()->_topebox_game.count_skip_banner >= 3)
//				{
//					_user._game_promo_has_show = false;
//					_user._game_promo_delay_show = time(NULL) + TIME_DELAY_SHOW_TOPEBOX_ADS;
//					GAME()->_topebox_game.show_banner_topebox_active = false;
//					GAME()->_topebox_game.count_skip_banner = 3;
//					_user.UserDataSave();
//					PDEBUG("\n ###########Skip 3 lan");
//				}
//			}
//#endif
//			//PDEBUG("\n _topebox_game.GamePromoHasTouchDown():%d -- _canTouch:%d", _topebox_game.GamePromoHasTouchDown(), _canTouch);
//			if (GAME()->_topebox_game.count_show_close_banner_topebox > 0)
//			{
//				GAME()->_topebox_game.count_show_close_banner_topebox--;
//				//PDEBUG("\n --------------------->_topebox_game.count_show_close_banner_topebox:%d", _topebox_game.count_show_close_banner_topebox);
//				if (GAME()->_topebox_game.count_show_close_banner_topebox <= 0)
//				{
//					GAME()->_topebox_game.count_show_close_banner_topebox = -10;
//				}
//			}
//			if (GAME()->_topebox_game.GamePromoHasTouchDown())
//			{
//#if !defined (_WINDOWS)
//				if (Device::IsNetworkAvailable())
//#endif
//				{
//					GAME()->_can_showads = false;
//					_user._game_promo_has_show = false;
//					GAME()->_topebox_game.show_banner_topebox_active = false;
//					GAME()->_topebox_game.render_banner_topebox = false;
//					_user._game_promo_order++;
//					_user._game_promo_delay_show = time(NULL) + TIME_DELAY_SHOW_TOPEBOX_ADS;
//					//_topebox_game.ResponseRequest();
//					//PDEBUG("\n ##### Open URL:_link_store = %s \n", GAME()->_topebox_game._link_store); 
//#if defined (ANDROID_OS) || defined (MAC_OS)
//					PDEBUG("\n ##### Open URL:linkStore = %s \n", GAME()->_topebox_game._link_store);
//					PineSocial::OpenURL(GAME()->_topebox_game._link_store);
//
//
//#endif
//					/*char title[128];
//					char decs[1024];
//					sprintf(title, "%s Click", "Topebox-Ads");
//					sprintf(decs, "%s Click", "Topebox-Ads");
//					char type[128];
//					sprintf(type, "%s", "topebox_ads");
//					#if defined (MAC_OS) || (ANDROID_OS)
//					PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
//					Device::GA_LogContents(title, decs, type);
//					#endif*/
//					_user.UserDataSave();
//				}
//			}
//		}
//
//		if (_user._game_promo_has_show)
//		{
//			if (GAME()->_topebox_game.UpdateTouchGamePromo())
//			{
//				//return true;
//			}
//		}
//#pragma endregion
//			}
//	/*************************/
}
bool TDGame::GamePlayUpdateTouch()
{
	return false;
}

void TDGame::InitBattle(int battle, int wave)
{
	if (_battle_current >= 4)
	{
		_user._fairy_times_init++;
	}
	if (_has_revive_in_battle)
	{
		_wave_current = 10;
	}
	_bg_spriteid_next = GetBackground();
	_battle_old = _battle_current;
	if (_bg_spriteid == -1)
	{
		_bg_spriteid = _bg_spriteid_next;
		_bg_underground_spriteid = _underground_sprite[_bg_spriteid_next];
	}
	_level_current = battle * NUM_WAVE_INBATTLE + wave;
	CharacterInit(_level_current);
	_items_coin_min = (_battle_current/10 + 1)*4;
	if (!_user._tutorial_completed)
	{
		if (_wave_current >= 10 && _user._tutorial_step == TUTORIAL_STEP_BUILD_TOWER)
		{
			_tutorial_step = TUTORIAL_STEP_MENU_HERO;
		}
	}
	
}
void TDGame::InterfaceRender(float x, float y)
{
	/*int spacing = GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 230 + x, 120 + y, _LEFT, "Battle %d", _battle_current + 1);
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = 1;
	GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 230 + x, 160 + y, _LEFT, "wave");
	GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = spacing;
	char temp[20];
	int _text_lenght = sprintf(temp, "%d/", _wave_current);
	int text_w = (GET_SPRITE(SPRITEID_FONT_WAVE_WHITE))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->StringToUnichar(temp), 0, _text_lenght);
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 145+x, 154+y, _LEFT | _VCENTER, "%d/", _wave_current);
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 145 + text_w+x, 154+y, _LEFT | _VCENTER, "%d", NUM_WAVE_INBATTLE);
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing = spacing;*/
	char temp[20];
	int text_lenght = sprintf(temp, "  %d", _battle_current + 1);
	int text_w = (GET_SPRITE(SPRITEID_FONT_WAVE_WHITE))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->StringToUnichar(temp), 0, text_lenght);
	int spacing = GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 15 + x, 120 + y, _RIGHT, "Battle %d", _battle_current + 1);
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = spacing;

	text_lenght = sprintf(temp, "  %d/%d", _wave_current, NUM_WAVE_INBATTLE);
	text_w = (GET_SPRITE(SPRITEID_FONT_WAVE_WHITE))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->StringToUnichar(temp), 0, text_lenght);
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = 1;
	GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 15 + x - text_w, 160 + y, _RIGHT, "wave");
	GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = spacing;
	text_lenght = sprintf(temp, "%d", NUM_WAVE_INBATTLE);
	text_w = (GET_SPRITE(SPRITEID_FONT_WAVE_WHITE))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->StringToUnichar(temp), 0, text_lenght);
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 15 + x - text_w, 154 + y, _RIGHT | _VCENTER, "%d/", _wave_current);
	GET_SPRITE(SPRITEID_FONT_WAVE_WHITE)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH - 15  + x, 154 + y, _RIGHT | _VCENTER, "%d", NUM_WAVE_INBATTLE);
	GET_SPRITE(SPRITEID_FONT_WAVE_YELLOW)->_char_spacing = spacing;
	//printf("\n _has_double_coin_timer = %d", _has_double_coin_timer);
	int hour = 0;
	int min = 0;
	int sec = 0;
	int db_coin_posx = k_SCREEN_WIDTH - 45 + x;
	int db_coin_posy = 220 + y;
	if (_user._has_double_coin)
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 182, db_coin_posx, db_coin_posy);
		db_coin_posx -= 90;
	}
	/*if (_user._iap_starter_double_coin_time > 0)
	{
		if (!_starter_double_coin_time.isNullDay())
		{
			hour = _starter_double_coin_time.getHour();
			min = _starter_double_coin_time.getMinute();
			sec = _starter_double_coin_time.getSecond();
		}
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 182, db_coin_posx, db_coin_posy);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 163, db_coin_posx, db_coin_posy);
		int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), db_coin_posx, db_coin_posy + 52, _HCENTER, "%02d:%02d:%02d", hour, min, sec);
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
		db_coin_posx -= 90;
	}
	if (_has_double_coin_timer > 0)
	{
		if (!_fairy_double_coin_time.isNullDay())
		{
			hour = _fairy_double_coin_time.getHour();
			min = _fairy_double_coin_time.getMinute();
			sec = _fairy_double_coin_time.getSecond();
		}
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 149, db_coin_posx, db_coin_posy);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 163, db_coin_posx, db_coin_posy);
		int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), db_coin_posx, db_coin_posy + 52, _HCENTER, "%02d:%02d", min, sec);
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	}*/
}

void TDGame::IngameButtonRender(float x, float y)
{

	for (int i = 0; i < INGAME_BUTTON_AUTO1; i++)
	{
        int opacity = 100;
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[i]._heroID);
        
        if(index_inbattle >= 0)
        {
            if((_auto_hold_key >= 0 && (i) != _auto_hold_key) /*&&
               !_hero_inbattle_arr[index_inbattle]._is_auto_attack*/)
            {
                //G()->SetColorMask(0xff000000);
                 opacity = 15;
            }
            //printf("\n i = %d id=%d", i, _hero_inbattle_arr[index_inbattle].GetHeroID());
            if(_hero_inbattle_arr[index_inbattle].GetHeroID() <= 0)
            {
                
                opacity = 15;
                
            }
        }
        else
        {
            opacity = 15;
        }
		if (_mass_auto_timing > 0)
		{
			opacity = 30;
		}
        G()->SetOpacity(opacity);
		_ingame_button[i].SetPos(x, y);
		_ingame_button[i].Render(G());
		_ingame_button[i].Update();
        
	}
  
    //G()->SetOpacity(100);
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
        
		int posy = 937 ;
		int clipy = 937 + 262 ;
		int heroindex = -1;
		int cliphatt = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(29);
		int cliphskill = 110;
		
       
		for (int j = 0; j <= NUM_MAX_HERO; j++)
		{
			if (_user._hero_arr[j]._heroid >= 0)
			{
				int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[j]._heroid);
				if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle].GetHeroID() == _ingame_hero_button[i]._heroID)
				{
					if (_ingame_hero_button[i]._clip_pa_current + 14 < cliphatt)
					{
						if (_user._auto_attack_free <= 0)
						{
							if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state != BUTTON_STATE_LOCK)
							{
								int touch_id = _ingame_button[INGAME_BUTTON_AUTO1 + i]._touch_id;
								_ingame_button[INGAME_BUTTON_AUTO1 + i].SetState(BUTTON_STATE_LOCK);
								if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._anim->GetCurrentAnim() != 36 + i * 4)
								{
									_ingame_button[INGAME_BUTTON_AUTO1 + i].SetAnim(SPRITEID_HUD_MAINMENU, 36 + i * 4);
								}
								_ingame_button[INGAME_BUTTON_AUTO1 + i].SetAnim(SPRITEID_HUD_MAINMENU, 109 + i * 4);
								_ingame_button[INGAME_BUTTON_AUTO1 + i]._touch_id = touch_id;
								StarAnimDisable(i * 2);
								StarAnimDisable(i * 2 + 1);
							}
						}
						else
						{
							if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state == BUTTON_STATE_NORMAL)
							{
								if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._anim->GetCurrentAnim() != 109 + i * 4)
								{
									_ingame_button[INGAME_BUTTON_AUTO1 + i].SetAnim(SPRITEID_HUD_MAINMENU, 109 + i * 4);
								}
							}
							if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state == BUTTON_STATE_LOCK)
							{
								_ingame_button[INGAME_BUTTON_AUTO1 + i].SetState(BUTTON_STATE_NORMAL);
							}
							if (_effect_star_anim[i * 2]._state > 0 && _ingame_hero_button[i]._clip_pa_current <= 0)
							{
								StarAnimDisable(i * 2);
								StarAnimDisable(i * 2 + 1);
							}
						}
					}
					else
					{
						clipy -= 5;
						if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state == BUTTON_STATE_NORMAL)
						{
							if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._anim->GetCurrentAnim() != 36 + i * 4)
							{
								_ingame_button[INGAME_BUTTON_AUTO1 + i].SetAnim(SPRITEID_HUD_MAINMENU, 36 + i * 4);
							}
						}
					}
					if (_ingame_hero_button[i]._clip_ps_current < cliphskill)
					{
						if (_user._auto_skill_free <= 0)
						{
							int touch_id = _ingame_button[INGAME_BUTTON_SKILL1 + i]._touch_id;
							if (_ingame_button[INGAME_BUTTON_SKILL1 + i]._state != BUTTON_STATE_LOCK)
							{
								_ingame_button[INGAME_BUTTON_SKILL1 + i].SetState(BUTTON_STATE_LOCK);
								StarAnimDisable(6 + i * 2);
								StarAnimDisable(6 + i * 2 + 1);
							}
							_ingame_button[INGAME_BUTTON_SKILL1 + i]._touch_id = touch_id;
						}
						else
						{
							if (_ingame_button[INGAME_BUTTON_SKILL1 + i]._state == BUTTON_STATE_LOCK)
							{
								_ingame_button[INGAME_BUTTON_SKILL1 + i].SetState(BUTTON_STATE_NORMAL);
							}
							if (_effect_star_anim[6 + i * 2]._state > 0 && _ingame_hero_button[i]._clip_ps_current <= 0)
							{
								StarAnimDisable(6 + i * 2);
								StarAnimDisable(6 + i * 2 + 1);
							}
						}
					}
				}
			}
		}
        
        int opacity = 100;
        int index = i;
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[index]._heroID);
         if(index_inbattle >= 0)
         {
            if((_auto_hold_key >= 0 && (index) != _auto_hold_key)
               )
            {
                opacity = 15;
            }
            
            /*if(_hero_inbattle_arr[index_inbattle]._is_auto_attack)
            {
                
                opacity = 100;
                
            }*/
         }
        else
        {
             opacity = 15;
        }
		 if (_mass_auto_timing > 0)
		 {
			 opacity = 30;
		 }
        G()->SetOpacity(opacity);
		G()->SetClip(x, clipy - _ingame_hero_button[i]._clip_pa_current - 8 + y, _screen_width, _ingame_hero_button[i]._clip_pa_current + 8);
		if (_ingame_hero_button[i]._auto_attack)
		{
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 31, _ingame_hero_button[i]._x + x, posy + y);
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 30, _ingame_hero_button[i]._x + x, posy + y);
		}
		else
		{
            if(opacity == 100)
            {
                G()->SetOpacity(0.5f*(100 - _ingame_hero_button[i]._effect_hight_light_opac));
            }
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 31, _ingame_hero_button[i]._x + x, posy + y);
            if(opacity == 100)
            {
                G()->SetOpacity((100 - _ingame_hero_button[i]._effect_hight_light_opac));
            }
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 32, _ingame_hero_button[i]._x + x, posy + y);
			
			if (_ingame_hero_button[i]._full_pa && opacity == 100)
			{
				G()->SetOpacity(2 * _ingame_hero_button[i]._effect_hight_light_opac);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 31, _ingame_hero_button[i]._x + x, posy + y);
				G()->SetOpacity(_ingame_hero_button[i]._effect_hight_light_opac);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 30, _ingame_hero_button[i]._x + x, posy + y);
			}
		}
		if (_ingame_hero_button[i]._clip_pa_current > 7 && _ingame_hero_button[i]._clip_pa_current < cliphatt - 14 && opacity == 100)
		{
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 78, _ingame_hero_button[i]._x + x, clipy - _ingame_hero_button[i]._clip_pa_current + y - 13);
		}
		
 
		G()->ClearClip();
		
	}
    G()->SetOpacity(100);
    //auto button
	for (int i = INGAME_BUTTON_AUTO1; i < INGAME_BUTTON_SKILL1; i++)
	{
    
        int opacity = 100;
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[i-INGAME_BUTTON_AUTO1]._heroID);
         if(index_inbattle >= 0)
         {
            if((_auto_hold_key >= 0 && (i-INGAME_BUTTON_AUTO1) != _auto_hold_key))
            {
                opacity = 15;
            }
            if(_hero_inbattle_arr[index_inbattle].GetHeroID() <= 0)
            {
                
                opacity = 15;
                
            }
         }
        else
        {
            opacity = 15;
        }
		if (_mass_auto_timing > 0)
		{
			opacity = 30;
		}
        G()->SetOpacity(opacity);
		_ingame_button[i].SetPos(x, y);
		_ingame_button[i].Render(G());
		_ingame_button[i].Update();
		int mx = _ingame_button[i].GetCenterX();
		int my = _ingame_button[i].GetCenterY();
		int mw = 0;
		int mh = 30;
		if (_user._auto_attack_free > 0 && _ingame_hero_button[i - INGAME_BUTTON_AUTO1]._heroID >= 0)
		{
            
			int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 127, mx + mw / 2, my + mh+5);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), mx + mw / 2, my + mh+10, _HCENTER, "x%d", _user._auto_attack_free);
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
		}
       
	}
    
	G()->SetOpacity(100);
    //button character and inner skill
	for (int i = 0; i < NUM_MAX_HERO_INBATTLE; i++)
	{
        
        if (_ingame_hero_button[i]._heroID == -1)
        {
			int touch_id = _ingame_button[INGAME_BUTTON_SKILL1 + i]._touch_id;
            if (_ingame_button[INGAME_BUTTON_SKILL1 + i]._state != BUTTON_STATE_LOCK)
            {
                _ingame_button[INGAME_BUTTON_SKILL1 + i].SetState(BUTTON_STATE_LOCK);
            }
			_ingame_button[INGAME_BUTTON_SKILL1 + i]._touch_id = touch_id;
			touch_id = _ingame_button[INGAME_BUTTON_TAP1 + i]._touch_id;
			if (_ingame_button[INGAME_BUTTON_TAP1 + i]._state != BUTTON_STATE_LOCK)
			{
				_ingame_button[INGAME_BUTTON_TAP1 + i].SetState(BUTTON_STATE_LOCK);
			}
			_ingame_button[INGAME_BUTTON_TAP1 + i]._touch_id = touch_id;

			touch_id = _ingame_button[INGAME_BUTTON_AUTO1 + i]._touch_id;
			if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state != BUTTON_STATE_LOCK)
			{
				_ingame_button[INGAME_BUTTON_AUTO1 + i].SetState(BUTTON_STATE_LOCK);
			}
			_ingame_button[INGAME_BUTTON_AUTO1 + i]._touch_id = touch_id;
        }
		else
		{
			if (!_mass_auto_active)
			{
				if (_ingame_button[INGAME_BUTTON_SKILL1 + i]._state == BUTTON_STATE_LOCK)
				{
					_ingame_button[INGAME_BUTTON_SKILL1 + i].SetState(BUTTON_STATE_NORMAL);
				}
				if (_ingame_button[INGAME_BUTTON_TAP1 + i]._state == BUTTON_STATE_LOCK)
				{
					_ingame_button[INGAME_BUTTON_TAP1 + i].SetState(BUTTON_STATE_NORMAL);
				}
				if (_ingame_button[INGAME_BUTTON_AUTO1 + i]._state == BUTTON_STATE_LOCK)
				{
					_ingame_button[INGAME_BUTTON_AUTO1 + i].SetState(BUTTON_STATE_NORMAL);
				}
			}
		}
        
     
        
        
        int opacity = 100;
        int index = i;
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[index]._heroID);
         if(index_inbattle >= 0)
         {
            if((_auto_hold_key >= 0 && (index) != _auto_hold_key)
               )
            {
                opacity = 15;
            }
            
            if(_hero_inbattle_arr[index_inbattle].GetHeroID() <= 0 /*|| _hero_inbattle_arr[index_inbattle]._is_auto_attack*/)
            {
                
                opacity = 15;
                
            }
         }
        else
        {
            opacity = 15;
        }

        
        if(_hero_inbattle_arr[index_inbattle].GetHeroID() > 0 )
        {
            _ingame_hero_button[i].Render(x, y, opacity);
            
            
            //if(index_inbattle >= 0 /*&& _hero_inbattle_arr[index_inbattle]._is_auto_attack*/)
            //{
            //    opacity = 100;
            //}
			//printf("\n opacity[%d]:%d", i, opacity);
            _ingame_hero_button[i].RenderSkill(x, y, opacity);
            
            if(_hero_inbattle_arr[index_inbattle]._is_auto_attack)
            {
                //G()->SetOpacity(100);
                GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224, _ingame_hero_button[i]._x + x, _ingame_hero_button[i]._y + y);
            }
            else
            {
                GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 230, _ingame_hero_button[i]._x + x, _ingame_hero_button[i]._y + y);
            }
        }
        G()->SetOpacity(100);
        //CGame::_this->_auto_hold_key = index;
        //CGame::_this->_auto_block_frame = 0;
       
	}
    
    //button border skill
	for (int i = INGAME_BUTTON_SKILL1; i < NUM_BUTTON_INGAME; i++)
	{
       
		float scale = _ingame_hero_button[i - INGAME_BUTTON_SKILL1]._effect_full_ps_scale;
		int mx = _ingame_button[i].TZ_GetX() + 4;
		int my = _ingame_button[i].TZ_GetY();
		int mw = _ingame_button[i].TZ_GetWidth();
		int mh = _ingame_button[i].TZ_GetHeight();
        
        int opacity = 100;
        int index = i - INGAME_BUTTON_SKILL1;
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[index]._heroID);
         if(index_inbattle >= 0)
         {
            if((_auto_hold_key >= 0 && (index) != _auto_hold_key)
               )
            {
                opacity = 15;
               /* if(_hero_inbattle_arr[index_inbattle]._is_auto_attack)
                {
                    opacity = 100;
                }*/
            }
            
            if(_hero_inbattle_arr[index_inbattle].GetHeroID() <= 0)
            {
                
                opacity = 15;
                
            }
         }
        else
        {
            opacity = 15;
        }
        
        G()->SetOpacity(opacity);
		G()->SetScale(scale, scale, mx + mw / 2, my + mh / 2);
		_ingame_button[i].SetPos(x, y);
		_ingame_button[i].Render(G());
		_ingame_button[i].Update();
		
		if (!_ingame_hero_button[i - INGAME_BUTTON_SKILL1]._full_ps)
		{
			if (_effect_skill_add_energy[i - INGAME_BUTTON_SKILL1] > 0)
			{
				G()->SetOpacity(_effect_skill_add_energy[i - INGAME_BUTTON_SKILL1] * 10);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 36, mx + mw / 2, my + mh / 2);
				G()->SetOpacity(100);
				_effect_skill_add_energy[i - INGAME_BUTTON_SKILL1]--;
			}
		}
        else
        {
            _ingame_hero_button[i - INGAME_BUTTON_SKILL1]._full_power_skill_fire.Render(0, 0, opacity);
        }
		if (_ingame_hero_button[i - INGAME_BUTTON_SKILL1]._full_ps && _ingame_hero_button[i - INGAME_BUTTON_SKILL1]._heroID >= 0 )
		{
			G()->SetRotate(_ingame_hero_button[i - INGAME_BUTTON_SKILL1]._effect_full_skill_rotate, mx + mw / 2, my + mh / 2);
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 128, mx + mw / 2, my + mh / 2);
			G()->ClearRotate();
		}
		
		G()->ClearScale();
		if (_user._auto_skill_free > 0 && _ingame_hero_button[i - INGAME_BUTTON_SKILL1]._heroID >= 0)
		{
			int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 127, mx + mw / 2, my + mh + 5);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), mx + mw / 2, my + mh + 10, _HCENTER, "x%d", _user._auto_skill_free);
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
		}
        G()->SetOpacity(100);
	}
    
    G()->SetOpacity(100);
}
void TDGame::IngameButtonInit()
{
	for (int i = 0; i < NUM_BUTTON_INGAME; i++)
	{
		_ingame_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_ingame_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 24 + i*4);
		_ingame_button[i].SetPos(0, 0);
		if (i >= INGAME_BUTTON_AUTO1 && i <= INGAME_BUTTON_AUTO3)
		{
			_ingame_button[i].SetState(BUTTON_STATE_LOCK);
		}
	}
	for (int i = 0; i < NUM_BUTTON_INGAME; i++)
	{
		//MeasureButton(&_ingame_button[i]);
	}
}
bool TDGame::IngameButtonUpdateTouch()
{
	if (!_tutorial_step_ready && _tutorial_step != TUTORIAL_STEP_TAP_ATT
		&& _tutorial_step != TUTORIAL_STEP_USE_SKILL)
	{
		return false;
	}
	bool ret = false;
	int index = -1;
	for (int i = 0; i < NUM_BUTTON_INGAME; i++)
	{
		if (_ingame_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	
	if (CGame::_this->HasKey1Press())
	{
		if (!_user._tutorial_completed)
		{
			if (_tutorial_step != TUTORIAL_STEP_FREE)
			{
				if (_tutorial_step == TUTORIAL_STEP_TAP_ATT && _tutorial_opac >= 100)
				{
					/*_user._tutorial_step = TUTORIAL_STEP_FREE;*/
					_tutorial_step = TUTORIAL_STEP_FREE;
				}
				if (_user._tutorial_step < TUTORIAL_STEP_USE_SKILL)
				{
					HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
				}

			}
			else
			{
				if (_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT)
				{
					HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
				}
			}
		}
		else
		{
			HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
		}
		CGame::_this->ResetKey1();
	}
	if (CGame::_this->HasKey2Press())
	{
		HeroButtonActive(1, HEROBUTTON_TYPE_ATTACK);
		CGame::_this->ResetKey2();
	}
	if (CGame::_this->HasKey3Press())
	{
		HeroButtonActive(2, HEROBUTTON_TYPE_ATTACK);
		CGame::_this->ResetKey3();
	}
    int speed_autox_max =  5;
    int speed_auto = speed_autox_max*2;
    
    if(CGame::_this->_auto_block_frame >= 0 && CGame::_this->_auto_block_frame <= 60*3)
    {
        speed_auto = speed_autox_max*2 - CGame::_this->_auto_block_frame*speed_autox_max/(60*3);
            
    }
    else
    {
        speed_auto = speed_autox_max;
    }
    
  
    if(_auto_hold_key >= 0 && _auto_hold_key < 3 && speed_auto == speed_autox_max)
    {
        int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[_auto_hold_key]._heroID);
		if (index_inbattle >= 0 && index_inbattle < 50)
		{
			_hero_inbattle_arr[index_inbattle]._is_max_speed = true;
		}
        
    }
    
    
    
    if(speed_auto <= 0)
    {
        speed_auto = 1;
    }
    //printf("\n_auto_block_frame = %d",CGame::_this->_auto_block_frame);
    
    //printf("\nCGame::_this->_auto_hold_key = %d",CGame::_this->_auto_hold_key);
    if(_auto_hold_key < 0)
    {
        CGame::_this->_auto_block_frame = 0;
    }
    else
    if(CGame::_this->_frame_counter % speed_auto == 0)
    {
        switch (_auto_hold_key)
        {
            case INGAME_BUTTON_TAP1:
                if (!_user._tutorial_completed )
                {
                    if (_tutorial_step != TUTORIAL_STEP_FREE)
                    {
                        if (_tutorial_step == TUTORIAL_STEP_TAP_ATT && _tutorial_opac >= 100)
                        {
                            /*_user._tutorial_step = TUTORIAL_STEP_FREE;*/
                            _tutorial_step = TUTORIAL_STEP_FREE;
                        }
                        if (_user._tutorial_step < TUTORIAL_STEP_USE_SKILL)
                        {
                            HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
                        }
                        
                    }
                    else
                    {
                        if (_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT)
                        {
                            HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
                        }
                    }
                }
                else
                {
                    HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
                    
                }
                
                break;
            case INGAME_BUTTON_TAP2:
                HeroButtonActive(1, HEROBUTTON_TYPE_ATTACK);
                break;
            case INGAME_BUTTON_TAP3:
                HeroButtonActive(2, HEROBUTTON_TYPE_ATTACK);
                break;
        }
    }
	if (ret)
	{
		if (_ingame_button[index].NeedAction())
		{
            //printf("\n index = %d",index);
            if((index == INGAME_BUTTON_TAP1 ||index == INGAME_BUTTON_TAP2 ||index == INGAME_BUTTON_TAP3) &&
               index != _auto_hold_key)
            {
                //int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[CGame::_this->_auto_hold_key]._heroID);
                //if(!_hero_inbattle_arr[index_inbattle]._is_auto_attack)
                {
                    //CGame::_this->_last_auto_key = index;
                    _auto_hold_key = index;
                    CGame::_this->_auto_block_frame = 0;
                }
            }
			switch (index)
			{
			case INGAME_BUTTON_TAP1:
				if (!_user._tutorial_completed )
				{
					if (_tutorial_step != TUTORIAL_STEP_FREE)
					{
						if (_tutorial_step == TUTORIAL_STEP_TAP_ATT && _tutorial_opac >= 100)
						{
							/*_user._tutorial_step = TUTORIAL_STEP_FREE;*/
							_tutorial_step = TUTORIAL_STEP_FREE;
						}
						if (_user._tutorial_step < TUTORIAL_STEP_USE_SKILL)
						{
							HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
						}
						
					}
					else
					{
						if (_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT)
						{
							HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
						}
					}
				}
				else
				{
					HeroButtonActive(0, HEROBUTTON_TYPE_ATTACK);
                    
				}
				
				break;
			case INGAME_BUTTON_TAP2:
				HeroButtonActive(1, HEROBUTTON_TYPE_ATTACK);
				break;
			case INGAME_BUTTON_TAP3:
				HeroButtonActive(2, HEROBUTTON_TYPE_ATTACK);
				break;
			case INGAME_BUTTON_SKILL1:
				if (!_user._tutorial_completed)
				{
					if (_tutorial_step == TUTORIAL_STEP_USE_SKILL)
					{
						/*_user._tutorial_step = TUTORIAL_STEP_FREE;*/
						_tutorial_step = TUTORIAL_STEP_FREE;
					}
				}
				HeroButtonActive(0, HEROBUTTON_TYPE_SKILL);
				break;
			case INGAME_BUTTON_SKILL2:
				HeroButtonActive(1, HEROBUTTON_TYPE_SKILL);
				break;
			case INGAME_BUTTON_SKILL3:
				HeroButtonActive(2, HEROBUTTON_TYPE_SKILL);
				break;
			case INGAME_BUTTON_AUTO1:
                _user._tutorial_attack_auto_enable = false;
                _user._tutorial_auto_attack_complete = true;
				GAME()->PlaySFX(SFX_BUTTON);
				HeroButtonActive(0, HEROBUTTON_TYPE_AUTO);
				break;
			case INGAME_BUTTON_AUTO2:
				GAME()->PlaySFX(SFX_BUTTON);
				HeroButtonActive(1, HEROBUTTON_TYPE_AUTO);
				break;
			case INGAME_BUTTON_AUTO3:
				GAME()->PlaySFX(SFX_BUTTON);
				HeroButtonActive(2, HEROBUTTON_TYPE_AUTO);
				break;
			}
			if (_ingame_button[index]._state != BUTTON_STATE_LOCK && _ingame_button[index]._state != BUTTON_STATE_HIDE)
			{
				_ingame_button[index].SetState(BUTTON_STATE_NORMAL);
			}
			if (_auto_hold_key < 0)
			{
				return true;
			}
			
		}
	}
	bool pressed = false;
    
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < NUM_BUTTON_INGAME; touch++)
		{
			if (_ingame_button[touch]._state == BUTTON_STATE_LOCK || _ingame_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
           
			int y_plus = 0;
			if (touch < INGAME_BUTTON_AUTO1)
			{
				y_plus = 245;
			}
			int x = _ingame_button[touch].TZ_GetX() - 20;
			int y = _ingame_button[touch].TZ_GetY() + y_plus - 20;
			int w = _ingame_button[touch].TZ_GetWidth() + 40;
			int h = _ingame_button[touch].TZ_GetHeight() - y_plus + 40 ;
			Button *button = &_ingame_button[touch];
			if (touch >= INGAME_BUTTON_TAP1 && touch <= INGAME_BUTTON_TAP3)
			{
				h -= 40;
			}
			if (_mass_auto_timing > 0)
			{
				if (touch == INGAME_BUTTON_AUTO1 || touch == INGAME_BUTTON_AUTO2 || touch == INGAME_BUTTON_AUTO1)
				{
					continue;
				}
			}
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
                if((_user._tutorial_attack_auto_enable && touch != INGAME_BUTTON_AUTO1) || _user._tutorial_step < TUTORIAL_STEP_TAP_ATT)
                {
                    continue;
                }
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					//printf("\n touch = %d,button->_touch_id = %d", touch, button->_touch_id);
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d", touch);
						//PLAY_SFX(SFX_BUTTON);
                        if(_auto_hold_key < 0)
                        {
                            TouchEffectFireAdd(TOUCHS(i)->x, TOUCHS(i)->y);
                            button->SetState(BUTTON_STATE_ACTIVE);
                            button->_touch_id = TOUCHS(i)->_id;
                        }
						else
						{
							if (touch >= INGAME_BUTTON_SKILL1 && touch <= INGAME_BUTTON_SKILL3 && _auto_hold_key == touch-6)
							{
								TouchEffectFireAdd(TOUCHS(i)->x, TOUCHS(i)->y);
								button->SetState(BUTTON_STATE_ACTIVE);
								button->_touch_id = TOUCHS(i)->_id;
							}
						}
                        //TOUCHS(i)->_state = TOUCH_DRAG;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
                    
					if (button->IsAction(TOUCHS(i)->_id))
					{
                        if(touch == _auto_hold_key)
                        {
                            CGame::_this->_auto_block_frame++;
                        }
						pressed = true;
					}

				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
                        if(_auto_hold_key == touch)
                        {
                            if(_auto_hold_key >= 0 && _auto_hold_key < 3)
                            {
                                int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[_auto_hold_key]._heroID);
								if (index_inbattle >= 0 && index_inbattle < 50)
								{
									_hero_inbattle_arr[index_inbattle]._is_max_speed = false;
								}
                                _auto_hold_key = -1;
                            }
                           
                        }
//#if defined (ANDROID_OS)
//						else if (CGame::_this->_auto_hold_key >= 0 && CGame::_this->_auto_hold_key < 3)
//						{
//							CGame::_this->_auto_hold_key = -1;
//						}
//#endif
						//button->SetState(BUTTON_STATE_ACTIVE);
						button->_touch_id = -1;
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
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
                   
                    if (button->IsAction(TOUCHS(i)->_id))
                    {
                        
                        if(_auto_hold_key == touch)
                        {
							if (_auto_hold_key >= 0 && _auto_hold_key < 3)
							{
								int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[_auto_hold_key]._heroID);
								if (index_inbattle >= 0 && index_inbattle < 50)
								{
									_hero_inbattle_arr[index_inbattle]._is_max_speed = false;
								}
                                 _auto_hold_key = -1;
                            }
                        }
//#if defined (ANDROID_OS)
//						else if (CGame::_this->_auto_hold_key >= 0 && CGame::_this->_auto_hold_key < 3)
//						{
//							CGame::_this->_auto_hold_key = -1;
//						}
//#endif
                        button->SetState(BUTTON_STATE_NORMAL);
                        button->_touch_id = -1;
                        pressed = true;
                    }
				}
					
			}
		}
	}
	return pressed;
}

void TDGame::MenuIngameRender(float x, float y)
{
	for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
	{
		if (_menu_ingame_button[i]._state != BUTTON_STATE_HIDE)
		{
			_menu_ingame_button[i].Render(G());
		}
		_menu_ingame_button[i].Update();
	}
	if (!_user._tutorial_completed)
	{
		if (_user._tutorial_step < TUTORIAL_STEP_MENU_CASTLE)
		{
			for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
			{
				if (_menu_ingame_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_HIDE);
				}
			}
		}
		else if (_user._tutorial_step < TUTORIAL_STEP_MENU_HERO)
		{
			for (int i = MENU_INGAME_BUTTON_HEROES; i < NUM_BUTTON_MENU_INGAME; i++)
			{
				if (_menu_ingame_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_HIDE);
				}
			}
			if (_menu_ingame_button[MENU_INGAME_BUTTON_GATE]._state == BUTTON_STATE_HIDE)
			{
				_menu_ingame_button[MENU_INGAME_BUTTON_GATE].SetState(BUTTON_STATE_NORMAL);
			}
		}
		else
		{
			for (int i = MENU_INGAME_BUTTON_RELICS; i < NUM_BUTTON_MENU_INGAME; i++)
			{
				if (_menu_ingame_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_HIDE);
				}
			}
			for (int i = 0; i <= MENU_INGAME_BUTTON_HEROES; i++)
			{
				if (i != MENU_INGAME_BUTTON_HEROES)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_LOCK);
				}
				else
				{
					if (_menu_ingame_button[i]._state == BUTTON_STATE_HIDE)
					{
						_menu_ingame_button[i].SetState(BUTTON_STATE_NORMAL);
					}
				}
			}
		}
	}
	else
	{
		if (_tutorial_step == TUTORIAL_STEP_FREE)
		{
			for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
			{
				if (_menu_ingame_button[i]._state == BUTTON_STATE_HIDE || _menu_ingame_button[i]._state == BUTTON_STATE_LOCK)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
		}
	}
	RenderNotifyNew(x, y);
}
void TDGame::MenuIngameInit()
{
	for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
	{
		_menu_ingame_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_menu_ingame_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 61 + i * 4);
		_menu_ingame_button[i].SetPos(0, 0);
	}
	/*for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
	{
		MeasureButton(&_menu_ingame_button[i]);
	}*/
}
bool TDGame::MenuIngameUpdateTouch()
{
	if (!_tutorial_step_ready && _tutorial_step != TUTORIAL_STEP_MENU_RELIC
		&& _tutorial_step != TUTORIAL_STEP_BUILD_TOWER
		&& _tutorial_step != TUTORIAL_STEP_MENU_HERO
		&& _tutorial_step != TUTORIAL_STEP_MENU_CASTLE)
	{
		return false;
	}
	if (_tutorial_step == TUTORIAL_STEP_FREE)
	{
		if (_auto_hold_key >= 0)
		{
			return false;
		}
	}
	bool ret = false;
	int index = -1;
	for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
	{
		if (_menu_ingame_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_menu_ingame_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case MENU_INGAME_BUTTON_GATE:
				
				break;
			case MENU_INGAME_BUTTON_HEROES:
				break;
			case MENU_INGAME_BUTTON_RELICS:
				break;
			case MENU_INGAME_BUTTON_SHOP:
				break;
			default:
				break;
			}
			if (!_user._tutorial_completed)
			{
				if (_tutorial_step == TUTORIAL_STEP_MENU_CASTLE)
				{
					if (MENU_INGAME_BUTTON_GATE == index)
					{
						_ingame_menu_type = index;
						SetState(k_GS_INGAME_MENU);
						_tutorial_step = TUTORIAL_STEP_FREE;
						showadtutorial = true;
					}
				}
				else if (_tutorial_step == TUTORIAL_STEP_MENU_HERO)
				{
					if (MENU_INGAME_BUTTON_HEROES == index)
					{
						_ingame_menu_type = index;
						SetState(k_GS_INGAME_MENU);
						_tutorial_step = TUTORIAL_STEP_FREE;
					}
				}
			}
			else
			{
				
				if (_tutorial_step == TUTORIAL_STEP_MENU_RELIC)
				{
					if (MENU_INGAME_BUTTON_RELICS == index)
					{
						if (_user.GetGem() < 3)
						{
							_user.SetGem(3);
						}
						_user._tutorial_step = TUTORIAL_STEP_BUY_RELIC;
						_tutorial_step = TUTORIAL_STEP_FREE;
						_ingame_menu_type = index;
						SetState(k_GS_INGAME_MENU);
					}
				}
				else
				{
					_ingame_menu_type = index;
					SetState(k_GS_INGAME_MENU);
				}
			}
			
			for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
			{
				if (_menu_ingame_button[i]._state != BUTTON_STATE_LOCK && _menu_ingame_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_ingame_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < NUM_BUTTON_MENU_INGAME; touch++)
		{
			if (_menu_ingame_button[touch]._state == BUTTON_STATE_LOCK || _menu_ingame_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _menu_ingame_button[touch].TZ_GetX();
			int y = _menu_ingame_button[touch].TZ_GetY();
			int w = _menu_ingame_button[touch].TZ_GetWidth();
			int h = _menu_ingame_button[touch].TZ_GetHeight();
			Button *button = &_menu_ingame_button[touch];
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

void TDGame::HeroButtonActive(int index,int type)
{
	int index_heroactive = -1;
	if (index >= NUM_MAX_HERO_INBATTLE)
	{
		return;
	}
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_inbattle_arr[i].GetHeroID() == _ingame_hero_button[index]._heroID)
		{
			index_heroactive = i;
            break;
		}
	}
	if (index_heroactive < 0)
	{
		return;
	}
	int cliph_att = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(32);
	int cliph_skill = 110;
	bool addpwatt = false;
	switch (type)
	{
	case HEROBUTTON_TYPE_ATTACK:
        if(_hero_inbattle_arr[index_heroactive]._is_auto_attack)
        {
            break;
        }
		if (_ingame_hero_button[index]._is_use_auto_att == -1)
		{
			addpwatt = true;
		}
		_hero_inbattle_arr[index_heroactive].ForceAttack(addpwatt);
		_ingame_hero_button[index]._active = true;
		_ingame_hero_button[index]._effect_zoom_scale = 1.0f;
		_ingame_hero_button[index]._anim.SetAnim(77, false);
		_ingame_hero_button[index].AddEffect();
		_effect_skill_add_energy[index] = 10;
		_user._quest_num_tap++;
		if (!_user._daily_quest_completed)
		{
			DailyQuestAdd(DAILY_QUEST_GROUP_NUM_TAP);
		}
		if (_time_tap_in_second <= 0)
		{
			_time_tap_in_second = 60;
			_num_tap_in_second = 0;
		}
		else
		{
			_num_tap_in_second++;
		}
		_num_tap_in_agame++;
		break;
	case HEROBUTTON_TYPE_SKILL:
        //printf("\n index_heroactive = %d",index_heroactive);
		//if (!_hero_inbattle_arr[index_heroactive]._is_auto_attack)
		if ((_hero_inbattle_arr[index_heroactive]._skill_duration <= 0 && _hero_inbattle_arr[index_heroactive].GetState() != HERO_STATE_SKILL)
			&& _hero_inbattle_arr[index_heroactive]._skill.IsFree() && _ingame_hero_button[index]._is_use_auto_skill == -1)
		{
			if (!_ingame_hero_button[index]._full_ps )
			{
				//if (!_is_use_auto_skill_free)
				{
					_user._auto_skill_free--;
					if (_user._auto_skill_free <= 0)
					{
						_user._auto_skill_free = 0;
					}
					_hero_inbattle_arr[index_heroactive]._power_skill_catch = _hero_inbattle_arr[index_heroactive].GetPowerSkill();
					_hero_inbattle_arr[index_heroactive].AddPowerSkill(_hero_inbattle_arr[index_heroactive].GetLimitBreak());
					_ingame_hero_button[index]._is_use_auto_skill = 0;
					_is_use_auto_skill_free = index;
				}
			}
			else
			{
				_hero_inbattle_arr[index_heroactive]._power_skill_catch = 0;
				_hero_inbattle_arr[index_heroactive].SkillActive();
				_ingame_hero_button[index]._effect_full_ps_scale_start = true;
				_user._quest_num_use_skill++;
			}
			if (!_user._daily_quest_completed)
			{
				DailyQuestAdd(DAILY_QUEST_GROUP_USE_SKILL);
			}
		}
		
		break;
	case HEROBUTTON_TYPE_AUTO:
		if (!_hero_inbattle_arr[index_heroactive]._is_auto_attack && _ingame_hero_button[index]._is_use_auto_att == -1)
		{
			if (!_ingame_hero_button[index]._full_pa)
			{
				_user._auto_attack_free--;
				if (_user._auto_attack_free <= 0)
				{
					_user._auto_attack_free = 0;
				}
				_hero_inbattle_arr[index_heroactive]._power_att_catch = _hero_inbattle_arr[index_heroactive].GetPowerAttack();
				_hero_inbattle_arr[index_heroactive].AddPowerAttack(_hero_inbattle_arr[index_heroactive]._power_attack_max);
				_ingame_hero_button[index]._is_use_auto_att = 0;
				_is_use_auto_attack_free = index;
			}
			else
			{
				_hero_inbattle_arr[index_heroactive]._power_att_catch = 0;
				_hero_inbattle_arr[index_heroactive].ActiveAutoAttack(false);
				_user._num_use_auto_attack++;
			}
			if (!_user._daily_quest_completed)
			{
				DailyQuestAdd(DAILY_QUEST_GROUP_USE_AUTO_ATT);
			}
			
		}
		
		break;
	default:
		break;
	}	
}

void TDGame::MenuRender(float x, float y)
{
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 94, x, y);
	int clipy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(95, 0);
	int cliph = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleHeight(95, 0) + 50;
	_menu_button[MENU_BUTTON_OPTIONS].SetPos(x, y);

	if (_battle_current < WHEEL_BATTLE_START)
	{
		if (_battle_current < WHEEL_BATTLE_START)
		{
			if (_menu_button[MENU_BUTTON_WHEEL]._state != BUTTON_STATE_HIDE)
			{
				_menu_button[MENU_BUTTON_WHEEL].SetState(BUTTON_STATE_HIDE);
			}
		}
		else
		{
			if (_menu_button[MENU_BUTTON_WHEEL]._state != BUTTON_STATE_LOCK)
			{
				_menu_button[MENU_BUTTON_WHEEL].SetState(BUTTON_STATE_LOCK);
			}
		}
	}
	else
	{
		if (_menu_button[MENU_BUTTON_WHEEL]._state == BUTTON_STATE_LOCK || _menu_button[MENU_BUTTON_WHEEL]._state == BUTTON_STATE_HIDE)
		{
			_menu_button[MENU_BUTTON_WHEEL].SetState(BUTTON_STATE_NORMAL);
		}
	}
	float y_plus = 0;
	if (_menu_button[MENU_BUTTON_LINK_TW]._state == BUTTON_STATE_HIDE)
	{
		y_plus = 80;
	}
	if (_menu_button_active)
	{
		if (_menu_button_scrolly > y_plus)
		{
			_menu_button_scrolly -= 20;
            _menu_button_scrolling = true;
			if (_menu_button_scrolly <= y_plus)
			{
				_menu_button_scrolly = y_plus;
                _menu_button_scrolling = false;
			}
		}
		G()->SetClip(_point_o.X, clipy, _screen_width, cliph - _menu_button_scrolly);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 95, x, y - _menu_button_scrolly);
		G()->ClearClip();
		for (int i = 0; i < NUM_BUTTON_MENU; i++)
		{
			if (i < MENU_BUTTON_OPTIONS && i >= MENU_BUTTON_SOUND)
			{
				G()->SetClip(_point_o.X, clipy, _screen_width, cliph - _menu_button_scrolly);
				if (i == MENU_BUTTON_LINK_FB)
				{
					_menu_button[i].SetPos(x, -_menu_button_scrolly + y);
				}
				else
				{
					_menu_button[i].SetPos(x, -_menu_button_scrolly + y + y_plus);
				}
			}
			_menu_button[i].Render(G());
			_menu_button[i].Update();
			if (!GAME()->_soundEnable)
			{
				int posx = _menu_button[MENU_BUTTON_SOUND].TZ_GetX() + _menu_button[MENU_BUTTON_SOUND].TZ_GetWidth() / 2;
				int posy = _menu_button[MENU_BUTTON_SOUND].TZ_GetY() + _menu_button[MENU_BUTTON_SOUND].TZ_GetHeight() / 2;
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 129, posx , posy );
			}
			if (!GAME()->_musicEnable)
			{
				int posx = _menu_button[MENU_BUTTON_MUSIC].TZ_GetX() + _menu_button[MENU_BUTTON_MUSIC].TZ_GetWidth() / 2;
				int posy = _menu_button[MENU_BUTTON_MUSIC].TZ_GetY() + _menu_button[MENU_BUTTON_MUSIC].TZ_GetHeight() / 2;
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 129, posx , posy );
			}
			if (i < MENU_BUTTON_OPTIONS)
			{
				G()->ClearClip();
			}
		}
	}
	else
	{
		cliph = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleHeight(95, 0) + 50;
		G()->SetClip(_point_o.X, clipy, _screen_width, cliph - _menu_button_scrolly + 50);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 95, x, y - _menu_button_scrolly + 62 * (_menu_button_scrolly/cliph*1.0f));
		G()->ClearClip();
		for (int i = MENU_BUTTON_SOUND; i < NUM_BUTTON_MENU - 2; i++)
		{
			_menu_button[i].SetPos(0 + x, -_menu_button_scrolly + y);
		}
		if (_menu_button_scrolly < cliph)
		{
			_menu_button_scrolly += 30;
            _menu_button_scrolling = true;
			if (_menu_button_scrolly >= cliph)
			{
				_menu_button_scrolly = cliph;
                _menu_button_scrolling = false;
			}
			G()->SetClip(_point_o.X, clipy, _screen_width, cliph - _menu_button_scrolly);
			for (int i = MENU_BUTTON_SOUND; i < NUM_BUTTON_MENU - 2; i++)
			{
				//_menu_button[i].SetPos(0 + x, -_menu_button_scrolly + y);
				_menu_button[i].Render(G());
				_menu_button[i].Update();
				
				if (!GAME()->_soundEnable)
				{
					int posx = _menu_button[MENU_BUTTON_SOUND].TZ_GetX() + _menu_button[MENU_BUTTON_SOUND].TZ_GetWidth() / 2;
					int posy = _menu_button[MENU_BUTTON_SOUND].TZ_GetY() + _menu_button[MENU_BUTTON_SOUND].TZ_GetHeight() / 2;
					GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 129, posx, posy);
				}
				if (!GAME()->_musicEnable)
				{
					int posx = _menu_button[MENU_BUTTON_MUSIC].TZ_GetX() + _menu_button[MENU_BUTTON_MUSIC].TZ_GetWidth() / 2;
					int posy = _menu_button[MENU_BUTTON_MUSIC].TZ_GetY() + _menu_button[MENU_BUTTON_MUSIC].TZ_GetHeight() / 2;
					GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 129, posx, posy);
				}
			}
			G()->ClearClip();
		}
		
		for (int i = 0; i < NUM_BUTTON_MENU; i++)
		{
			if (i < MENU_BUTTON_SOUND || i > MENU_BUTTON_LINK_FB)
			{
				if (_menu_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_button[i].Render(G());
				}
				_menu_button[i].Update();
			}
		}
		_menu_button[MENU_BUTTON_OPTIONS].Render(G());
		_menu_button[MENU_BUTTON_OPTIONS].Update();
	}

	for (int i = 0; i < NUM_BUTTON_MENU; i++)
	{
		if (i == MENU_BUTTON_ACHIEVEMENT || i == MENU_BUTTON_WHEEL)
		{
			int frameindex = 12;
			if (i == MENU_BUTTON_WHEEL)
			{
				frameindex = 144;
			}
			int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(frameindex, 0) + 15 ;
			int posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(frameindex, 0) - 20 ;
			_effect_notify_menu_button[i].Render(x + posx, y + posy);
			_effect_notify_menu_button[i].Update();
		}
	}
	/*int hour = 0;
	int min = 0;
	int sec = 0;
	bool has_wheel_time = _wheel_time.isNullDay();
	if (!has_wheel_time && _battle_current >= WHEEL_BATTLE_START)
	{
		hour = _wheel_time.getHour();
		min = _wheel_time.getMinute();
		sec = _wheel_time.getSecond();
		if (_is_hacked_time)
		{
			hour = 255;
			min = 255;
			sec = 255;
		}
		int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(144, 0) ;
		int posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(144, 0) + 46 ;
		int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiTextFormat(G(), x + posx, y + posy, _HCENTER, "%02d:%02d:%02d", hour, min,sec);
		GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	}*/
	if (_battle_current >= WHEEL_BATTLE_START)
	{
		int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(144, 0);
		int posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(144, 0) + 46;
		if (_user._num_wheel_spin_free <= 0 && _user._num_wheel_spin_premium <= 0)
		{
			int spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
			GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), x + posx, y + posy, 200, _HCENTER, "Battle %d", _wheel_free_battle_target + 1);
			GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
		}
	}
    /*
    else if(_battle_current < WHEEL_BATTLE_START)
    {
        GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(),222,x, y);
    }*/
#if !DISABLE_ONLINE_FEATURE
	if (!network && _battle_current >= WHEEL_BATTLE_START)
	{
		int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(144, 0) + 23;
		int posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(144, 0) - 10;
		_anim_network.SetPos(x + posx, y + posy);
		_anim_network.DrawAnimObject(G());
		_anim_network.UpdateAnimObject();
	}
#endif
}
void TDGame::MenuInit()
{
    //google button init
    //SPRITEID_HUD_LUCKY_WHEEL_01
	//PDEBUG("Disable menu google 2");
    _isOpenGooglePlay = false;
    for(int  i = 0; i < 3; i++)
    {
        _google_play_menu[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
        _google_play_menu[i].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01,21+i*4);
        _google_play_menu[i].SetPos(k_SCREEN_WIDTH/2,k_SCREEN_HEIGHT/2);
        
    }
	for (int i = 0; i < NUM_BUTTON_MENU; i++)
	{
		_menu_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 8 + i * 4);
		if (i == MENU_BUTTON_OPTIONS)
		{
			_menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 91);
		}
		if (i == MENU_BUTTON_WHEEL)
		{
			_menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 121);
		}
		if (i == MENU_BUTTON_LINK_TW)
		{
			_menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 130);
			_menu_button[i].SetState(BUTTON_STATE_HIDE);
		}
		if (i == MENU_BUTTON_LINK_FB)
		{
			_menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 134);
		}
        
        if(CGame::_this->IsAndroidVersion && i == MENU_BUTTON_LEADERBOARD)
        {
            _menu_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 157);
        }
		_menu_button[i].SetPos(_point_o.X, _point_o.Y);
		int posx = _menu_button[i].TZ_GetX() ;
		int posy = _menu_button[i].TZ_GetY() + 7;
		_effect_notify_menu_button[i].Init(SPRITEID_HUD_MAINMENU, -1, 98, 0, +7, 0);
	}
    
 
	for (int i = 0; i < NUM_BUTTON_MENU; i++)
	{
		//MeasureButton(&_menu_button[i]);
	}
	_menu_button_scrolly = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleHeight(95,0) + 50;
	_menu_button_active = false;
    _menu_button_scrolling = false;
}
bool TDGame::MenuUpdateTouch()
{
	if (!_tutorial_step_ready)
	{
		return false;
	}
    if(_menu_button_scrolling)
    {
        return false;
    }
	if (_auto_hold_key >= 0)
	{
		return false;
	}
#if !defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		if (_menu_button_active)
		{
            
			SetState(k_GS_PLAYGAME);
            //ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
			_sub_state = k_LOOP;
			_menu_button_active = false;
			GAME()->_isBackkeyPress = false;
			return true;
		}
	}
#endif
	bool ret = false;
	int index = -1;
	for (int i = 0; i < NUM_BUTTON_MENU; i++)
	{
		if (_menu_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_menu_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case MENU_BUTTON_LEADERBOARD:
				if (CGame::_this->IsAndroidVersion)
				{
#if defined (ANDROID_OS)
					if (GAME()->_async_task_manager._is_login_google && !_isOpenGooglePlay)
					{
						//PDEBUG("Set Open Google play menu");
						_isOpenGooglePlay = true;
						GAME()->_async_task_manager._on_process_show_leaderBoard = false;
						GAME()->_async_task_manager._on_process_show_achievement = false;
						GAME()->_async_task_manager._on_process_sync_cloud = false;
						/*for (int touch = 0; touch < CGame::_this->_num_touches; touch++)
						{
							TOUCHS(touch)->_id = -1;
						}*/
					}
					else
					{
						GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_IS_LOG_IN_GOOGLE_PLAY);
						GAME()->_async_task_manager._is_force_login_google_play = true;
						GAME()->_async_task_manager._is_show_game_services_menu = true;
					}
#endif
                }
					else
					{

#if defined (MAC_OS)
						GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_GC;
						GAME()->_loading_count_frame = 0;
						GAME()->_processing_time_out = PROCESSING_TIME_OUT;

						//PineGameCenterController::SubmitMyScore("TTD_TopScore", _hight_score+1);
						CGame::_this->Sleep(1000);
						PineGameCenterController::ShowLeaderBoard("TTD_TopScore");
#endif
					}
#if defined(_WINDOWS)
				//FreeGiftRewardActive();
				//_show_popup_offline = true;
#endif
				break;
			case MENU_BUTTON_ACHIEVEMENT:
				/*if (_time_showads_count <= 0 && !_user._has_remove_ads_pop_up)
				{
#if defined (ANDROID_OS)
					if (GAME()->HasVideoSkippableAds())
					{
						GAME()->ShowSkippableVideoAds();
						_time_showads_count = TIME_SHOWADS_ARCHIVE*60;
					}
#elif defined(MAC_OS)
					PineAdBox::ShowAdvertFullScreen();
					_time_showads_count = TIME_SHOWADS_ARCHIVE * 60;
#endif

				}*/
				GAME()->ShowAds();
				
				SetState(k_GS_QUEST);
				
				break;
			case MENU_BUTTON_WHEEL:
				
				SetState(k_GS_WHEEL);
				break;
			case MENU_BUTTON_SOUND:
				GAME()->_soundEnable = !GAME()->_soundEnable;
				break;
			case MENU_BUTTON_MUSIC:
				GAME()->_musicEnable = !GAME()->_musicEnable;
				if (!GAME()->_musicEnable)
				{
					GAME()->PauseCurrentMusic();
				}
				else
				{
					if (!GAME()->IsCurrentMusicPlaying())
					{
						GAME()->StopCurrentMusic();
						GAME()->LoadMusic(_bg_music_current);
						GAME()->PlayCurrentMusic(-1);
					}
					else
					{

						GAME()->PlayCurrentMusic(-1);
					}
					
				}
				break;
			case MENU_BUTTON_OPTIONS:
				_menu_button_active = !_menu_button_active;
				break;
			case MENU_BUTTON_LINK_TW:
				PineSocial::OpenURL(TWITTER_URL);
#if defined (ANDROID_OS ) || defined(MAC_OS)
				GAME()->_is_cancel_show_ads_on_resume = true;
#endif
				break;
			case MENU_BUTTON_LINK_FB:
				PineSocial::OpenURL(FACEBOOK_URL);
#if defined (ANDROID_OS)|| defined(MAC_OS)
				GAME()->_is_cancel_show_ads_on_resume = true;
#endif
				break;
			default:
				break;
			}
			for (int i = 0; i < NUM_BUTTON_MENU; i++)
			{
				if (_menu_button[i]._state != BUTTON_STATE_LOCK && _menu_button[i]._state != BUTTON_STATE_HIDE)
				{
					_menu_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < NUM_BUTTON_MENU; touch++)
		{
			if (_menu_button[touch]._state == BUTTON_STATE_LOCK || _menu_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _menu_button[touch].TZ_GetX() - 10;
			int y = _menu_button[touch].TZ_GetY() - 10;
			int w = _menu_button[touch].TZ_GetWidth() + 20;
			int h = _menu_button[touch].TZ_GetHeight() + 20;
			Button *button = &_menu_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						button->_touch_id = TOUCHS(i)->_id;
						GAME()->PlaySFX(SFX_BUTTON);
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
				else
				{
					if (_menu_button_active && touch == MENU_BUTTON_OPTIONS)
					{
						if (TOUCHS(i)->_state == TOUCH_DOWN)
						{
							SetState(k_GS_PLAYGAME);
                            ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
							_sub_state = k_LOOP;
							_menu_button_active = false;
							ClearAllTouchUp(TOUCH_TYPE_INGAME);
						}
					}
				}
			}
			if (pressed)
			{
				return pressed;
			}
		}
	}
	return pressed;
}

void TDGame::AddHeroesDeploy( int heroid)
{
	
	int real_index = -1;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (heroid == _user._hero_arr[i]._heroid)
		{
			real_index = i;
			break;
		}
	}
	if (real_index < 0)
	{
		return;
	}
	int level = _user._hero_arr[real_index]._level;
	int id = _user._hero_arr[real_index]._heroid;
	bool deployed = _user._hero_arr[real_index]._is_deployed;
	int index = 0;
	_hero_inbattle_arr[index].Init(id, level, deployed,false, _user._hero_arr[real_index]._has_promo);
}
void TDGame::ModifyHeroesDeploy(int heroid)
{
	int real_index = -1;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (heroid == _hero_inbattle_arr[i].GetHeroID())
		{
			real_index = i;
			break;
		}
	}
	if (real_index < 0)
	{
		return;
	}
	int level = _hero_inbattle_arr[real_index].GetLevel();
	int id = _hero_inbattle_arr[real_index].GetHeroID();
	bool deployed = _hero_inbattle_arr[real_index]._deployed;
	_hero_inbattle_arr[real_index].Modify(id, level, deployed, false, _hero_inbattle_arr[real_index].GetPowerAttack(), _hero_inbattle_arr[real_index].GetPowerSkill(), _hero_inbattle_arr[real_index]._rar_level, _hero_inbattle_arr[real_index]._has_promo);

}
int TDGame::GetRelicsAttackPoint(int group, int interactiveid)
{
	int att = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				//printf("\n group = %d, _items_relics[i]._attack_point = %d", group, _items_relics[i]._attack_point);
				att += _items_relics[i]._attack_point;
			}
		}
	}
	return att;
}
int TDGame::GetRelicsAttack(int group, int interactiveid)
{
	int att = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock && _items_relics[i]._frameid != 164)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				//printf("\n group = %d, _items_relics[i]._interactive_id = %d", group, _items_relics[i]._interactive_id);
				att += _items_relics[i]._attack;
			}
		}
	}
	return att;
}

int TDGame::GetRelicsAttackBasic(int group, int interactiveid)
{
	int att = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock && _items_relics[i]._frameid == 164)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				if (att < _items_relics[i]._attack)
				{
					att = _items_relics[i]._attack;
				}
			}
		}
	}
	return att;
}

int TDGame::GetRelicsAttackSpeed(int group, int interactiveid)
{
	int attspeed = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				attspeed += _items_relics[i]._attack_speed;
			}
		}
	}
	return attspeed;
}
int TDGame::GetRelicsMana(int group, int interactiveid)
{
	int mana = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				mana += _items_relics[i]._mana;
			}
		}
	}
	return mana;
}
int TDGame::GetRelicsDuration(int group, int interactiveid)
{
	int duration = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				duration += _items_relics[i]._duration;
			}
		}
	}
	return duration;
}
int TDGame::GetRelicsSkillDuration(int group, int interactiveid)
{
	int duration = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				duration += _items_relics[i]._duration_skill;
			}
		}
	}
	return duration;
}
int TDGame::GetRelicsCritical(int group, int interactiveid)
{
	int critical = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				critical += _items_relics[i]._critical;
			}
		}
	}
	return critical;
}
int TDGame::GetRelicsAOE(int group, int interactiveid)
{
	int aoe = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				aoe += _items_relics[i]._aoe;
			}
		}
	}
	return aoe;
}
int TDGame::GetRelicsCostDecrease(int group, int interactiveid)
{
	int costdec = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				costdec += _items_relics[i]._cost_decrease;
			}
		}
	}
	return costdec;
}
int TDGame::GetRelicsUnitBounce(int group, int interactiveid)
{
	int unit = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				unit += _items_relics[i]._unit_bounce;
			}
		}
	}
	return unit;
}
int TDGame::GetRelicsMoveSpeed(int group, int interactiveid)
{
	int movespeed = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				movespeed += _items_relics[i]._speed_move;
			}
		}
	}
	return movespeed;
}
int TDGame::GetRelicsHP(int group, int interactiveid)
{
	int hp = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == group && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid || _items_relics[i]._interactive_id == 0)
			{
				hp += _items_relics[i]._hp;
			}
		}
	}
	return hp;
}

int TDGame::GetRelicsUpgradeRarity(int interactiveid)
{
	int num = 0;
	for (int i = 0; i < _relics_num_of; i++)
	{
		if (_items_relics[i]._group == ITEMRELIC_GROUP_HERO && !_items_relics[i]._is_lock)
		{
			if (_items_relics[i]._interactive_id == interactiveid)
			{
				char name[64];
				int length = sprintf(name, "%s", _items_relics[i]._name);
				char temp[64];
				for (int i = 0; i < length-2; i++)
				{
					temp[i] = name[i + 2];
				}
				temp[length - 2] = '\0';
				if (strcmp("Stars Medal", temp) == 0)
				{
					num++;
				}
			}
		}
	}
	return num;
}
void TDGame::EffectRewardJump::Init(int type)
{
	_x = _y = 0;
	_targetx = _targety = 0;
	_alphax = 0;
	_alphay = 0;
	_state = EFFECT_REWARD_JUMP_STATE_NONE;
	_speed = 0;
	_delta = 0;
	_speedy = 0;
	_type = type;
	_alpha_knock = 0;
	_count_frame_hold = 0;
	_glow_rotate = 0;
	_scale = 0;
	_value = 0;
	_value_min = 0;
	_opac = 100;
}
void TDGame::EffectRewardJump::Active(int sprite, int frame, INT_TIME value, float x, float y, float tarx, float tary)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_x = x;
	_y = y;
	_spriteid = sprite;
	_frameid = frame;
	if (_x > k_SCREEN_WIDTH/2)
	{
		_alphax = CMath::RANDOM(90, 103);
	}
	else
	{
		_alphax = CMath::RANDOM(77, 90);
	}
	
	_alphay = CMath::RANDOM(330, 340);
	_speed = CMath::RANDOM(20, 30);
	_delta = 0;
	_targetx = CMath::RANDOM(tarx + 10, tarx + 50);
	_targety = CMath::RANDOM(tary, tary + CMath::RANDOM(0, 5) * 3);
	_alpha_knock = 30;
	_count_frame_hold = 0;
	_state = EFFECT_REWARD_JUMP_STATE_START;
	_scale = 0;
	_anim1.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim1.SetAnim(0, true);
	_anim1.SetPos(0, 0);
	_anim2.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim2.SetAnim(3, true);
	_anim2.SetPos(0, 0);
	_value = value;
	_value_min = _value / 20;
	game->_effect_reward_count_frame = 0;
	_glow_rotate = 0;
	_opac = 100;
}
void TDGame::EffectRewardJump::Render(float x, float y)
{
	if (_state == EFFECT_REWARD_JUMP_STATE_NONE)
	{
		return;
	}
	G()->SetOpacity(_opac);
	G()->SetScale(_scale*0.35f, _scale*0.35f, _x + x, _y + y - 20);
	G()->SetRotate(_glow_rotate, _x + x, _y + y - 20);
	GET_SPRITE(SPRITEID_HUD_EFFECT_CHEST_01)->DrawFrame(G(), _frameid, _x + x, _y + y - 20);
	G()->ClearRotate();
	G()->ClearScale();
	G()->SetScale(_scale*0.5f, _scale*0.5f, _x + x, _y + y);
	_anim1.SetPos(_x + x, _y + y);
	_anim1.DrawAnimObject(G());
	if (_state >= EFFECT_REWARD_JUMP_STATE_OPENED)
	{
		_anim2.SetPos(_x + x, _y + y);
		G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
		_anim2.DrawAnimObject(G());
		G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
	}
	G()->ClearScale();
	G()->SetOpacity(100);
}
void TDGame::EffectRewardJump::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_state == EFFECT_REWARD_JUMP_STATE_NONE)
	{
		return;
	}
	_anim1.UpdateAnimObject();
	_anim2.UpdateAnimObject();
	_glow_rotate += 1;
	if (_glow_rotate >= 360)
	{
		_glow_rotate -= 360;
	}
	switch (_state)
	{
	case EFFECT_REWARD_JUMP_STATE_NONE:
		break;
	case EFFECT_REWARD_JUMP_STATE_START:
		if (_alphax < 85)
		{
			_alphax += 1;
		}
		else if (_alphax > 100)
		{
			_alphax -= 1;
		}
		_alphay += 2;
		if (_alphay >= 360)
		{
			_alphay = 0;
		}
		if (_alphay == 0)
		{
			_delta += 2;
		}
		
		if (_y >= _targety - _speed || _count_frame_hold > 0)
		{
			//if (_count_frame_hold < 5)
			//{
			//	_alpha_knock -= 8;
			//}
			//else
			//{
			//	_alpha_knock += 8;
			//	if (_alpha_knock >= 20)
			//	{
			//		_alpha_knock = 20;
			//	}
			//}
			//_count_frame_hold++;
			//_y = _targety + _speed*CMath::SIN(_alpha_knock);
			//if (_count_frame_hold >= 20)
			//{
			//	/*_state = EFFECT_REWARD_JUMP_STATE_OPENNING;
			//	_anim1.SetAnim(1, false);*/
			//}
			_state = EFFECT_REWARD_JUMP_STATE_HOLDING;
		}
		else
		{
			_y += _speed*CMath::SIN(_alphay + _delta / 4);
			_x += _speed*CMath::COS(_alphax);
		}
		if (_scale < 1.0f)
		{
			_scale += 0.05;
			if (_scale >= 1.0f)
			{
				_scale = 1.0f;
			}
		}
		break;
	case EFFECT_REWARD_JUMP_STATE_OPENNING:
		if (_anim1._current_aframes - GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim1.GetCurrentAnim()) == 7)
		{
			_state = EFFECT_REWARD_JUMP_STATE_OPENED;
			GAME()->PlaySFX(SFX_CHEST_ACQUIRED);

		}
		
		break;
	case EFFECT_REWARD_JUMP_STATE_OPENED:
		if (_anim1.IsCurrentAnimStop())
		{
			_anim1.SetAnim(2, true);
		}
		game->_effect_reward_count_frame++;
		if (game->_effect_reward_count_frame%2 == 0)
		{
			if (_value >= _value_min)
			{
				_value -= _value_min;
				//game->ItemsAddNew(ITEMS_TYPE_COIN, _x + CMath::RANDOM(-3, 3) * 5, _y - 65, _x, ROAD_POSY, _value_min);
			}
			else
			{
				//game->ItemsAddNew(ITEMS_TYPE_COIN, _x + CMath::RANDOM(-3, 3) * 5, _y - 65, _x, ROAD_POSY, _value);
				_value = 0;
			}
		}
		if (_value <= 0 && game->_current_state == k_GS_PLAYGAME)
		{
			if (game->_boss_reward_type == 1 )
			{
				game->ItemsAddNew(ITEMS_TYPE_GEM, _x + CMath::RANDOM(-3, 3) * 5, _y - 65, _x, ROAD_POSY, game->_boss_reward_gem);
			}
			game->_open_box_state_old = k_GS_PLAYGAME;
			game->SetState(k_GS_OPEN_BOX);
			//_state = EFFECT_REWARD_JUMP_STATE_END;
			_opac = 100;
		}
		break;
	case EFFECT_REWARD_JUMP_STATE_END:
		_opac -= 5;
		if (_opac <= 0)
		{
			_state = EFFECT_REWARD_JUMP_STATE_NONE;
		}
		
		break;
	default:
		break;
	}
}
void TDGame::EffectRewardJump::SetState(int state)
{
	_state = state;
	if (_state == EFFECT_REWARD_JUMP_STATE_OPENNING)
	{
		_anim1.SetAnim(1, false);
	}
}
void TDGame::TutorialRender(float x, float y)
{
	if (_user._tutorial_completed && _user._tutorial_step >= TUTORIAL_STEP_COMPLETED_2 )
	{
		return;
	}
	int posx = 0;
	int posy = 0;
	int text_posy = 0;
	
	//printf("\n _user._tutorial_step = %d", _tutorial_step);
	int linespac = 0;
	switch (_tutorial_step)
	{
	case TUTORIAL_STEP_WELCOME:
		posx = -200 + _point_o.X;
		posy = -200 + _point_o.Y;
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY ,k_SCREEN_WIDTH*0.8f, _LEFT|_VCENTER, "Welcome to Frontier Defense!\nWe're waiting for your command.");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		break;
	case TUTORIAL_STEP_BATTLE_START:
		posx = -200 + _point_o.X;
		posy = -200 + _point_o.Y;
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "We're being attacked by the evil force.\nLet's defend the Gate.");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		break;
	case TUTORIAL_STEP_TAP_ATT:
	{
								  int mx = _ingame_button[INGAME_BUTTON_TAP1].TZ_GetX() + 4;
								  int my = _ingame_button[INGAME_BUTTON_TAP1].TZ_GetY();
								  int mw = _ingame_button[INGAME_BUTTON_TAP1].TZ_GetWidth();
								  int mh = _ingame_button[INGAME_BUTTON_TAP1].TZ_GetHeight();
								  posx = mx + x + mw / 2;
								  posy = my + y + 3*mh / 4;
	}
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "Hold here to attack the enemy!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
		break;
	case TUTORIAL_STEP_USE_SKILL:
	{
									int mx = _ingame_button[INGAME_BUTTON_SKILL1].TZ_GetX() + 4;
									int my = _ingame_button[INGAME_BUTTON_SKILL1].TZ_GetY();
									int mw = _ingame_button[INGAME_BUTTON_SKILL1].TZ_GetWidth();
									int mh = _ingame_button[INGAME_BUTTON_SKILL1].TZ_GetHeight();
									posx = mx + x + mw / 2;
									posy = my + y + mh / 2;
	}
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "Tap here to trigger hero's Special Skill!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
		break;
	case TUTORIAL_STEP_MENU_CASTLE:
		posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(37,0);
		posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(37, 0);
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "The Evil Force is very strong.\nWe need an Archer Tower!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
		break;
	case TUTORIAL_STEP_BUILD_TOWER:
	{
									  int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(236, 0) - _ingame_menu_scroll.GetCurrent();
									  posx = k_SCREEN_WIDTH - 110;
									  posy = 100 + (INGAME_MENU_ITEM_HEIGHT + 5) + menu_my;
									  G()->SetOpacity(_tutorial_opac*0.8f);
									  GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
									  G()->SetOpacity(_tutorial_opac);
									  GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0 + 120);
									  linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
									  GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
									  GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY + 120, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "Tap here to build the Archer Tower!");
									  GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
									  _tutorial_anim_hand.SetPos(x + posx, y + posy);
									  _tutorial_anim_hand.DrawAnimObject(G());
	}
		
		break;
	case TUTORIAL_STEP_TAP_SCREEN:
		posx = -200 + _point_o.X;
		posy = -200 + _point_o.Y;
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "Let's defend our land from the evil force!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		break;
	case TUTORIAL_STEP_MENU_HERO:
		posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(39, 0);
		posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(39, 0);
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f, _LEFT | _VCENTER, "It seems we need more heroes to hold the gate!\nTap here to recruit a new hero!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
		break;
	case TUTORIAL_STEP_BUY_HERO:
	{
								   int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(57, 0) - _ingame_menu_scroll.GetCurrent();
								   posx = k_SCREEN_WIDTH - 100;
								   posy = 100 + (INGAME_MENU_ITEM_HEIGHT + 5) + menu_my;
								   G()->SetOpacity(_tutorial_opac*0.8f);
								   GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
								   G()->SetOpacity(_tutorial_opac);
								   _tutorial_anim_hand.SetPos(x + posx, y + posy);
								   _tutorial_anim_hand.DrawAnimObject(G());
	}
		
		break;
	case TUTORIAL_STEP_DEPLOY_HERO:
	{
									  int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(57, 0) - _ingame_menu_scroll.GetCurrent();
									  posx = k_SCREEN_WIDTH - 300;
									  posy = 100 + (INGAME_MENU_ITEM_HEIGHT + 5) + menu_my;
									  G()->SetOpacity(_tutorial_opac*0.8f);
									  GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
									  G()->SetOpacity(_tutorial_opac);
									  _tutorial_anim_hand.SetPos(x + posx, y + posy);
									  _tutorial_anim_hand.DrawAnimObject(G());
	}
		
		break;
	case TUTORIAL_STEP_MENU_RELIC:
	{
		posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(41, 0);
		posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(41, 0);
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0);
		linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), x + TUTORIAL_TEXT_POSX - 15, y + TUTORIAL_TEXT_POSY, k_SCREEN_WIDTH*0.8f , _LEFT | _VCENTER, "Have you ever heard of relics?\nThey will give your army the super power to defense the frontier!\nLet's purchase one of them!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
	}
		break;
	case TUTORIAL_STEP_BUY_RELIC:
	//case TUTORIAL_STEP_BUY_RELIC_COMPLETED:
	{
		int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(236, 0) - _ingame_menu_scroll.GetCurrent();
		posx = k_SCREEN_WIDTH - 120;
		posy = 100 + (INGAME_MENU_ITEM_HEIGHT + 5) + menu_my;
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
	}
		break;
	case TUTORIAL_STEP_MASS_AUTO:
	{
		float ww = _mass_auto_button.TZ_GetWidth();
		float hh = _mass_auto_button.TZ_GetHeight();
		float xx = _mass_auto_button.TZ_GetX() + ww / 2;
		float yy = _mass_auto_button.TZ_GetY() + hh / 2;
		G()->SetOpacity(_tutorial_opac*0.7f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + xx, y + yy);
		G()->SetOpacity(_tutorial_opac);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL_01)->DrawFrame(G(), 0, 0, 0 - 150);
		int linespac = GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = 12;
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->DrawAnsiPageFormat(G(), k_SCREEN_WIDTH / 2, y + TUTORIAL_TEXT_POSY - 150, k_SCREEN_WIDTH*0.8f, _HCENTER | _VCENTER, "Tap Mass. Auto to do a massive\n crazy attack!");
		GET_SPRITE(SPRITEID_FONT_TUTORIAL)->_line_spacing = linespac;
		_tutorial_anim_hand.SetPos(x + xx, y + yy);
		_tutorial_anim_hand.DrawAnimObject(G());
	}
		break;
	default:
		break;
	}
	if (_user._tutorial_step == TUTORIAL_STEP_BUY_RELIC_COMPLETED)
	{
		int menu_my = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(236, 0) - _ingame_menu_scroll.GetCurrent();
		posx = k_SCREEN_WIDTH - 120;
		posy = 100 + (INGAME_MENU_ITEM_HEIGHT + 5) + menu_my;
		G()->SetOpacity(_tutorial_opac*0.8f);
		GET_SPRITE(SPRITEID_HUD_TUTORIAL)->DrawFrame(G(), 0, x + posx, y + posy);
		G()->SetOpacity(_tutorial_opac);
		_tutorial_anim_hand.SetPos(x + posx, y + posy);
		_tutorial_anim_hand.DrawAnimObject(G());
	}
	G()->SetOpacity(100);
}
void TDGame::TutorialUpdate()
{
	if (_user._tutorial_completed&& _user._tutorial_step >= TUTORIAL_STEP_COMPLETED_2)
	{
		return;
	}
	_tutorial_anim_hand.UpdateAnimObject();
	_tutorial_step_ready = false;
	if (_tutorial_step == TUTORIAL_STEP_FREE)
	{
		_tutorial_step_ready = true;
		_tutorial_opac -= 5;
		if (_tutorial_opac <= 0)
		{
			_tutorial_opac = 0;
			if (_user._tutorial_step == TUTORIAL_STEP_DEPLOY_HERO)
			{
				_tutorial_step = TUTORIAL_STEP_TAP_SCREEN;
				
			}
			else if (_user._tutorial_step == TUTORIAL_STEP_TAP_SCREEN)
			{
				/*
				if(!_user._tutorial_completed)
				{
					PineAdBox::SetReactiveAdvert();
					PineAdBox::ShowAdvertFullScreen();
				}*/
				_user._tutorial_completed = true;
				_ingame_menu_close = true;
				_user._tutorial_step = TUTORIAL_STEP_MASS_AUTO;
				_user.UserDataSave();
				
			}
			else if (_user._tutorial_step == TUTORIAL_STEP_BUY_RELIC_COMPLETED)
			{
				_user._tutorial_completed = true;
				_user._tutorial_step = TUTORIAL_STEP_COMPLETED_2;
				_user.UserDataSave();
				for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
				{
					if (_menu_ingame_button[i]._state == BUTTON_STATE_LOCK)
					{
						_menu_ingame_button[i].SetState(BUTTON_STATE_NORMAL);
					}
				}
			}
		}
	}
	else
	{
		_tutorial_opac += 5;
		if (_tutorial_opac >= 100)
		{
			_tutorial_opac = 100;
			//_tutorial_step_ready = true;
		}
		if (_tutorial_step == TUTORIAL_STEP_BUY_RELIC 
			|| _tutorial_step == TUTORIAL_STEP_MENU_RELIC
			|| _tutorial_step == TUTORIAL_STEP_BUILD_TOWER
			|| _tutorial_step == TUTORIAL_STEP_MENU_HERO)
		{
			_tutorial_step_ready = false;

		}
		_user._tutorial_step = _tutorial_step;
	}
	if (_tutorial_opac >= 100)
	{
		switch (_tutorial_step)
		{
		case TUTORIAL_STEP_WELCOME:
			TutorialUpdateTouch();
			break;
		case TUTORIAL_STEP_BATTLE_START:
			TutorialUpdateTouch();
			break;
		case TUTORIAL_STEP_TAP_ATT:
			break;
		case TUTORIAL_STEP_USE_SKILL:
			break;
		case TUTORIAL_STEP_MENU_CASTLE:
			break;
		case TUTORIAL_STEP_BUILD_TOWER:
			break;
		case TUTORIAL_STEP_TAP_SCREEN:
			TutorialUpdateTouch();
			break;
		case TUTORIAL_STEP_MENU_HERO:
			break;
		case TUTORIAL_STEP_BUY_HERO:
			break;
		default:
			break;
		}
	}
}
void TDGame::TutorialInit()
{
	_tutorial_anim_hand.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_TUTORIAL_01), SPRITEID_HUD_TUTORIAL_01);
	_tutorial_anim_hand.SetAnim(0, true);
	_tutorial_anim_hand.SetPos(0, 0);
	_tutorial_opac = 0;
	_tutorial_touch_id = -1;
	_tutorial_step = TUTORIAL_STEP_FREE;
	if (!_user._tutorial_completed)
	{
		if (_user._tutorial_step >= TUTORIAL_STEP_MENU_HERO)
		{
			_tutorial_step = TUTORIAL_STEP_MENU_HERO;
		}
		else if (_user._tutorial_step >= TUTORIAL_STEP_MENU_CASTLE)
		{
			_tutorial_step = TUTORIAL_STEP_MENU_CASTLE;
			if (!_weapon[WEAPON_ARCHER].IsLock() || _user._tutorial_step == TUTORIAL_STEP_TAP_SCREEN)
			{
				_tutorial_step = TUTORIAL_STEP_FREE;
			}
		}
		else
		{
			_tutorial_step = _user._tutorial_step;
		}
	}
	_num_hit_tutorial = 0;
}

bool TDGame::TutorialUpdateTouch()
{
	/*if (!_tutorial_step_ready)
	{
		return false;
	}*/
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		int x = _point_o.X;
		int y = _point_o.Y;
		int w = _screen_width;
		int h = _screen_height;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_tutorial_touch_id == -1)
				{
					_tutorial_touch_id = TOUCHS(i)->_id;
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_tutorial_touch_id == TOUCHS(i)->_id)
				{
					if (_tutorial_step <= TUTORIAL_STEP_BATTLE_START)
					{
						if (_tutorial_step == TUTORIAL_STEP_BATTLE_START)
						{
							/*_user._tutorial_step = TUTORIAL_STEP_FREE;*/
							_tutorial_step = TUTORIAL_STEP_FREE;
						}
						else
						{
							//_user._tutorial_step++;
							_tutorial_step++;
						}
					}
					else
					{
						if (_tutorial_step == TUTORIAL_STEP_TAP_SCREEN)
						{
							_tutorial_step = TUTORIAL_STEP_FREE;
						}
					}
					_tutorial_touch_id = -1;
					pressed = true;
				}
			}
			if (_tutorial_touch_id != -1)
			{
				pressed = true;
			}
		}
		else
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_tutorial_touch_id == TOUCHS(i)->_id)
				{
					_tutorial_touch_id = -1;
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void TDGame::UnlockNewHero(int event_type)
{
#if GAME_SUPPORT
    if(SUPPORT_HERO_ID<0)
    {
        return;
    }
    
#endif
	switch (event_type)
	{
	case HEROES_UNLOCK_TYPE_NORMAL:
	{
									  int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
									  for (int i = 0; i < totalhero; i++)
									  {
										  int heroid = _hero_inbattle_arr[i].GetHeroID();
										  if (/*heroid == HERO_ID_SANTA || */
                                               heroid == HERO_ID_WOLF_RANGER
                                              //|| heroid == HERO_ID_ACHEMIST
                                              )
										  {
											  continue;
										  }
/*
										  if (_hero_inbattle_arr[i].GetLevelUnlock() <= _battle_current + 1)
										  {
											  if (_hero_inbattle_arr[i]._is_lock)
											  {
												  _hero_inbattle_arr[i].Init(_hero_inbattle_arr[i].GetHeroID(), 1, false, false);
												  //printf("\n unlock heroid = %d, name: %s", _hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetName());
											  }
										  }
 */
									  }
	}
		break;
	case HEROES_UNLOCK_TYPE_EVENT_XMAS://check server
	{
        
										   int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
										   for (int i = 0; i < totalhero; i++)
										   {
											   if (_hero_inbattle_arr[i].GetHeroID() == HERO_ID_SANTA)
											   {
												   //if (_hero_inbattle_arr[i].GetLevelUnlock() <= _battle_current + 1)//trigger invite
												   {
													   if (_hero_inbattle_arr[i]._is_lock)
													   {
														   int level_max = GetLevelUnlockNewHero(_hero_inbattle_arr[i].GetNumStars());
														   _hero_inbattle_arr[i].Init(_hero_inbattle_arr[i].GetHeroID(), level_max, false, false,false);
														   
														   //printf("\n unlock heroid = %d, name: %s", _hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetName());
													   }
												   }
											   }
										   }
	}
		break;
    /*
	case HEROES_UNLOCK_TYPE_EVENT_ACHEMIST://check server
	{
										   int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
										   for (int i = 0; i < totalhero; i++)
										   {
											   if (_hero_inbattle_arr[i].GetHeroID() == HERO_ID_ACHEMIST)
											   {
												   if (_hero_inbattle_arr[i].GetLevelUnlock() <= _battle_current + 1)//trigger invite
												   {
													   if (_hero_inbattle_arr[i]._is_lock)
													   {
														   _hero_inbattle_arr[i].Init(_hero_inbattle_arr[i].GetHeroID(), 1, false, false);
														   //printf("\n unlock heroid = %d, name: %s", _hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetName());
													   }
												   }
											   }
										   }
	}
		break;
    */
	case HEROES_UNLOCK_TYPE_EVENT_DAILY_REWARD://check server
	{
											int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
											
											for (int i = 0; i < totalhero; i++)
											{
												if (_hero_inbattle_arr[i].GetHeroID() == HERO_ID_WOLF_RANGER)
												{
													//if (_hero_inbattle_arr[i].GetLevelUnlock() <= _battle_current + 1)//trigger invite
													{
														if (_hero_inbattle_arr[i]._is_lock)
														{
															int level_max = GetLevelUnlockNewHero(_hero_inbattle_arr[i].GetNumStars());
															_hero_inbattle_arr[i].Init(_hero_inbattle_arr[i].GetHeroID(), level_max, false, false,false);
															//printf("\n unlock heroid = %d, name: %s", _hero_inbattle_arr[i].GetHeroID(), _hero_inbattle_arr[i].GetName());
														}
													}
												}
											}
	}
		break;
	default:
		break;
	}
	
}
void TDGame::VictoryInit()
{
	for (int i = 0; i < NUM_MAX_EFFECT_VICTORY_FIRE;i++)
	{
		int frame = CMath::RANDOM(0, 1);
		_victory_effect_fire[i].Init(SPRITEID_EFFECT_VICTORY_01, frame, 1, 40, 0, false, 1);
	}
	_victory_opac = 100;
	_anim_victory.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_VICTORY_01), SPRITEID_EFFECT_VICTORY_01);
	_anim_victory.SetAnim(0, false);
	_anim_victory.SetPos(0, 0);
	_victory_active_effect_fire = -1;
	_victory_active = false;
#if !defined (ANDROID_OS)
    GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_CHECK_SERVER_NETWORK);
#else

#endif
    //GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_SUBMIT_LEADERBOARD);

}
void TDGame::VictoryReInit()
{
	if (_battle_current < 100 && (_battle_current + 1) % 10 == 0)
	{
		CGame::_this->GooglePlaySubmitAchievement((_battle_current + 1) / 10);
	}
	_anim_victory.SetAnim(0, false);
	_victory_active_effect_fire = -1;
	_victory_opac = 100;
    //PineAdBox::SetReactiveAdvert();
    //PineAdBox::ShowAdvertFullScreen();
#if !defined (ANDROID_OS)
    GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_CHECK_SERVER_NETWORK);
#else

	
#endif
	GAME()->PlaySFX(SFX_VICTORY);
}
void TDGame::VictoryActive()
{
	for (int i = 0; i < NUM_MAX_EFFECT_VICTORY_FIRE; i++)
	{
		if (_victory_effect_fire[i].IsFree())
		{
			int posx = CMath::RANDOM(1, 10)*k_SCREEN_WIDTH / 10.0f;
			int posy = GET_SPRITE(SPRITEID_EFFECT_VICTORY_01)->GetFModuleCenterY(10,7) + CMath::RANDOM(-4, 4) * 10;
			_victory_effect_fire[i].Active(posx, posy, 4, 3, 1, 0.005f, 0.5f, 100);
			break;
		}
	}
}
void TDGame::VictoryRender(float x, float y)
{
	if (!_victory_active)
	{
		return;
	}
	G()->SetOpacity(_victory_opac);
	_anim_victory.DrawAnimObject(G());
	for (int i = 0; i < NUM_MAX_EFFECT_VICTORY_FIRE; i++)
	{
		_victory_effect_fire[i].Render(x, y, _victory_opac);
	}
	G()->SetOpacity(100);
}
void TDGame::VictoryUpdate()
{
	if (!_victory_active)
	{
		return;
	}
	if (_victory_active_effect_fire>= 0)
	{
		_victory_active_effect_fire++;
	}
	
	if (_victory_active_effect_fire %10==0)
	{
		VictoryActive();
	}
	_anim_victory.UpdateAnimObject();
	if (_anim_victory._current_aframes - GET_SPRITE(SPRITEID_EFFECT_VICTORY_01)->GetFirstAFrameID(_anim_victory.GetCurrentAnim()) == 6)
	{
		_victory_active_effect_fire = 0;
	}
	if (_anim_victory.IsCurrentAnimStop())
	{
		_victory_opac -= 5;
		if (_victory_opac <= 0)
		{
			_castle.AddHp(_castle._hp_max);
			_victory_active = false;
			
			if (!_user._has_completed_battle_max )
			{
				if (_battle_current >= NUM_MAX_BATTLE)
				{
					_battle_current = NUM_MAX_BATTLE - 1;
					char text[256];
					sprintf(text, "You have completed all %d battles.\nMore feature will coming soon!", NUM_MAX_BATTLE);
					_dialogMng.Add(DIALOG_CONTEXT_100_BATTLE, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "NULL", text, 0, 0);
					GAME()->PlaySFX(SFX_LAST_BATTLE_COMPLETED);
				}
			}
			else
			{
				_battle_current = NUM_MAX_BATTLE - 1;
			}
			if (_battle_current <= 200)
			{
				char title[128];
				char decs[1024];
				
				sprintf(title, "Complete Battle %d", _battle_current);
				sprintf(decs, "Complete Battle %d",_battle_current);
				char type[128];
				sprintf(type, "%s", "battle_logs");
#if defined (MAC_OS) || (ANDROID_OS)
				PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
				Device::GA_LogContents(title, decs,type);
#endif
			}
			_has_revive_in_battle = false;
			if (!_offline_earning_received && _battle_current == 11)
			{
				_show_popup_offline = true;
			}
			InitBattle(_battle_current, _wave_current);
		}
	}
	for (int i = 0; i < NUM_MAX_EFFECT_VICTORY_FIRE; i++)
	{
		_victory_effect_fire[i].Update();
	}
}

void TDGame::MassAutoRender(float x, float y, int opac)
{
	int main_opac = G()->GetCurrentOpacity();
	G()->SetOpacity(opac);
	int clipw = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFrameWidth(16) - 10;
	int makerx = _ingame_button[INGAME_BUTTON_TAP2].GetCenterX();
	int makery = _ingame_button[INGAME_BUTTON_TAP2].TZ_GetY();
	_mass_auto_button.SetPos(x + makerx, y + makery);
	_mass_auto_button.Render(G());
	_mass_auto_button.Update();
	int mx = _mass_auto_button.GetCenterX();
	int my = _mass_auto_button.GetCenterY();
	clipw = clipw*_mass_auto_scale;
	G()->SetScale(_mass_auto_scale, _mass_auto_scale, mx, my);
	if (_mass_auto_active)
	{
		G()->SetClip(mx - clipw / 2 - 7, 0, clipw, k_SCREEN_HEIGHT);
		float posx = (1 - ((_mass_auto_timing) / (_mass_auto_time*1.0f)))*clipw;
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 16, mx - posx, my);
		G()->ClearClip();
		G()->SetOpacity(_mass_auto_opac*opac);
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 17, mx + 1, my);
		G()->SetOpacity(opac);
	}
	else
	{
		if (_user._num_mass_auto_free > 0)
		{
			G()->SetOpacity(_mass_auto_opac*opac*0.01f);
			GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 16, mx, my);
			if (_mass_auto_button._state == BUTTON_STATE_SELECT)
			{
				G()->SetOpacity(_mass_auto_opac*opac*0.01f);
			}
			else
			{
				G()->SetOpacity(_mass_auto_opac*opac*0.005f);
			}
			GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 17, mx + 1, my);
			G()->SetOpacity(opac);
		}
	}
	GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 18, mx, my);
	if (_user._num_mass_auto_free > 0)
	{
		int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 127, mx + 105, my );
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), mx + 105, my + 5, _HCENTER, "x%d", _user._num_mass_auto_free);
		GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	}
	G()->ClearScale();
	G()->SetOpacity(main_opac);
}
void TDGame::MassAutoUpdate()
{
	if (_mass_auto_scale > 1.0f)
	{
		_mass_auto_scale += -0.02f;
		if (_mass_auto_scale <= 1.0f)
		{
			_mass_auto_scale = 1.0f;
		}
	}
	if (_need_log_mass_click)
	{
		char title[128];
		char decs[1024];
		sprintf(title, "%s Click", "Mass-Attack");
		sprintf(decs, "%s Click", "Mass-Attack");
		char type[128];
		sprintf(type, "%s", "common_events");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
		Device::GA_LogContents(title, decs, type);
#endif
		_need_log_mass_click = false;
	}
	if (_mass_auto_timing > 0)
	{
		_mass_auto_timing--;
		if (_mass_auto_timing <= 0)
		{
			_mass_auto_timing = 0;
			_mass_auto_active = false;
			_mass_auto_opac = 0;
			_mass_auto_touch_id = -1;
		}
		return;
	}
	
	if (_mass_auto_opac < 100)
	{
		_mass_auto_opac += 8;
	}
	if (_user._tutorial_step < TUTORIAL_STEP_MASS_AUTO)
	{
		return;
	}
	if (_auto_hold_key >= 0 || k_GS_PLAYGAME != _current_state || _dialogMng.isOpenDialog() || _user._num_mass_auto_free <= 0 || _mass_auto_active)
	{
		return;
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, _mass_auto_button.TZ_GetX(), _mass_auto_button.TZ_GetY(), _mass_auto_button.TZ_GetWidth(), _mass_auto_button.TZ_GetHeight()))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_mass_auto_touch_id == -1)
				{
					_mass_auto_touch_id = TOUCHS(i)->_id;
					TOUCHS(i)->_state = TOUCH_DRAG;
					MassAutoActive();
					_need_log_mass_click = true;
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{

			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_mass_auto_touch_id == TOUCHS(i)->_id)
				{
					_mass_auto_touch_id = -1;
				}
			}
		}
		else
		{
			if (_mass_auto_touch_id == TOUCHS(i)->_id)
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					_mass_auto_touch_id = -1;
				}
			}
		}
	}
}
void TDGame::MassAutoInit()
{
	_mass_auto_scale = 1.0f;
	_mass_opac_full = 0;
	_mass_auto_timing = 0;
	_mass_auto_opac = 100;
	_mass_auto_active = false;
	_mass_auto_touch_id = -1;
	_mass_auto_button.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER);
	_mass_auto_button.SetAnim(SPRITEID_HUD_DATA_MENU_PRESTIGE, 20);
	_mass_auto_button.SetPos(0, 0);
	_mass_auto_time = GetDesignGeneralInfo(DESIGN_GENERAL_TIME_AUTO_ATTACK)* 60;
}

void TDGame::MassAutoActive()
{
	_mass_auto_scale = 1.1f;
	_mass_auto_active = true;
	_mass_auto_timing = _mass_auto_time;
	_user._num_mass_auto_free--;
	if (_user._tutorial_step == TUTORIAL_STEP_MASS_AUTO)
	{
		_user._tutorial_step = TUTORIAL_STEP_MENU_RELIC;
		_tutorial_step = TUTORIAL_STEP_FREE;
	}
	PLAY_SFX(SFX_BUTTON);
	for (int i = 0; i < _num_hero_deployed; i++)
	{
		int heroindex = GetHeroIndex(_ingame_hero_button[i]._heroID);
		if (heroindex >= 0)
		{
			if (_hero_inbattle_arr[heroindex]._deployed)
			{
				_hero_inbattle_arr[heroindex]._count_frame_mass_auto_att = _mass_auto_timing;
				_hero_inbattle_arr[heroindex].ActiveAutoAttack(true);
			}
		}
	}
}
