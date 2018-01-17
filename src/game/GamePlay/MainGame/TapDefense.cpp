#include "pch.h"
#include "../../GameCore/CGame.h"
#include <ctime>

#if defined(MAC_OS)
extern "C" void OS_BasicPostSocial(const char* feed);
extern "C" bool isChartboostAvailable();
extern "C" void IapRestore();
extern "C" bool OS_GC_HasOpenning();
extern "C" void RequestRegisterNotificationSetting();
extern "C" void PurchaseProduct(const char *indentify);
#else
extern "C" void OS_BasicPostSocial(const char* feed){};
extern "C" bool isChartboostAvailable(){ return true; };
extern "C" bool OS_GC_HasOpenning(){ return false; };

#endif
#if defined (ANDROID_OS)
extern "C" void			OS_SetLocalNotification(int id, const char *message, const char * ticker, int second);
extern "C" void			PurchaseProductWithType(const char *indentify, int type = 1);
#endif


void TDGame::Init()
{
	PineGame::Init();
	//port game//
	_point_o = GAME()->_game_context.MeasureAnchor(0, 0, ANCHOR_LEFT | ANCHOR_TOP);
	_point_right_bottom = GAME()->_game_context.MeasureAnchor(0, 0, ANCHOR_RIGHT | ANCHOR_BOTTOM);
	_screen_width = _point_right_bottom.X - _point_o.X;
	_screen_height = _point_right_bottom.Y - _point_o.Y;
	//printf("\n _point_o.X: %f, _point_o.Y: %f, point_right_bottom.X: %f, point_right_bottom.Y: %f", _point_o.X, _point_o.Y, _point_right_bottom.X, _point_right_bottom.Y);
	//printf("\n ScaleOutX: %f, ScaleOutY: %f, scaleX: %f, scaleY: %f, ScaleOut: %f, TranslateX: %f, TranslateY: %f", GAME()->_game_context.ScaleOutX, GAME()->_game_context.ScaleOutY, GAME()->_game_context.ScaleX, GAME()->_game_context.ScaleY, GAME()->_game_context.ScaleOut, GAME()->_game_context.TranslateX, GAME()->_game_context.TranslateY);
	GAME()->_typeOtimizeDrawModule = true;
	_bg_change_music = false;
	////port game////
	_count_frame_playsound_orc_die = 0;
	_count_frame_playsound_ore_damaged = 0;
	_count_frame_playsound_coin_colleted = 0;
	_count_frame_playsound_spide_born = 0;
    _openShopFromGate= false;
	_reward_earning_off_type = -1;
	_count_frame_GetRewardOff = 0;
	_reward_earning_off = 0;
	_time_waiting_show_ads = 0;
	_time_waiting_free_gift = 0;
	_has_revive_in_battle = false;
	_relic_special_id = -1;
	_auto_hold_key = -1;
}

void TDGame::UpdateAndRender()
{
	GAME()->setUseOptimizeDrawModule(true);
    //update
	if (_current_state != k_GS_LOGO)
	{
		if (_count_frame_GetRewardOff > 0)
		{
			_count_frame_GetRewardOff--;
			if (_count_frame_GetRewardOff <= 0)
			{
				GetRewardEarnOffline();
			}
		}
	}
	if (_current_state == k_GS_PLAYGAME)
	{
		if (!_daily_reward_active && !_dialogMng.isOpenDialog() && !_victory_active)
		{
			if (HasDailyReward())
			{
				DailyRewardInit();
			}
		}
		if (_daily_reward_active)
		{
			DailyRewardUpdate();
		}
	}
	switch (_current_state)
	{
	case k_GS_LOGO:
        if(!PineSocial::HasloggingSystem)
        {
            UpdateLogo();
        }
		RenderLogo();
		break;
	case k_GS_PLAYGAME:
        
        GamePlayUpdate();
		GamePlayRender(0, 0, 100);
		if (_mainmenu_just_in)
		{
			MainMenuRender(0, 0, 100 - _main_opac_change_state);
			_main_opac_change_state += 5;
			if (_main_opac_change_state >= 100)
			{
				_main_opac_change_state = 100;
				_mainmenu_just_in = false;
			}
		}
		if (_daily_reward_active)
		{
			DailyRewardRender(0, 0);
		}
            if(CGame::_this->_will_show_dialog_ask_save)
            {
                if(!_dialogMng.isOpenDialog())
                {
                    CGame::_this->_will_show_dialog_ask_save = false;
                    //printf("\nICLOUD_STATE_NEW_VERSION");
                    char text[256];
                    sprintf(text, "%s", "Do you want to play with the latest iCloud Backup?\n Warning!!! This current progress will be overwritten!");
                    _dialogMng.Add(DIALOG_CONTEXT_CONFIRM_LOADDATA, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
                }
            }
            
		break;
	case k_GS_INGAME_MENU:
            IngameMenuUpdate();
		GamePlayRender(0, 0, 100);
		IngameMenuRender(0, 0, 100);
		break;
	case k_GS_MENU:
		break;
	case k_GS_QUEST:
        QuestUpdate();
		GamePlayRender(0, 0, 100);
		QuestRender(0, 0, _main_opac_change_state);
		break;
	case k_GS_OPEN_BOX:
        OpenBoxUpdate();
		if (_open_box_state_old == k_GS_PLAYGAME)
		{
			GamePlayRender(0, 0, 100);
		}
		else if (_open_box_state_old == k_GS_INGAME_MENU)
		{
			GamePlayRender(0, 0, 100);
			IngameMenuRender(0, 0, 100);
		}
		OpenBoxRender(0, 0, _main_opac_change_state);
		break;
	case k_GS_WHEEL:
            WheelUpdate();
		GamePlayRender(0, 0, 100);
		WheelRender(0, 0, _main_opac_change_state);
		break;
	case k_GS_GAME_OVER:
        GameOverUpdate();
		GamePlayRender(0, 0, 100);
		GameOverRender(0, 0, 100);
		break;
	case k_GS_MAIN_MENU:
		MainMenuUpdate();
		MainMenuRender(0,0,100);
		break;
	default:
		break;
	}
	Device::UpdateAndPlayQueueSFX();
	if (_invitation_active)
	{
		InvitationUpdate();
		InvitationRender(0, 0);
	}
	if (_dialogMng.isOpenDialog())
	{
		_dialogMng.Update();
		_dialogMng.Render(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
		//IapRender(-_point_o.X, _point_o.Y);
	}
#if ADD_ADVERT
	if (GAME()->_advert.HasPopup())
	{
		GAME()->_advert.Render();
		GAME()->_advert.Update();
	}
	
    if(_user._stateAppDownload == 1)
    {
        if (CGame::_this->_advert.GetAppInstallState() == PINEADS_INSTALL_STATE_DOWNLOAD_DONE)
        {
            if(!_dialogMng.isOpenDialog())
            {
                char text[256];
                sprintf(text, "%d :", DOWN_MOREGAME_REWARD);
				GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
                _dialogMng.Add(DIALOG_CONTEXT_DOWN_MOREGAME, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
            }
        }
    }
#endif
	if (_count_frame_playsound_coin_colleted > 0)
	{
		_count_frame_playsound_coin_colleted--;
	}
	if (_count_frame_playsound_orc_die > 0)
	{
		_count_frame_playsound_orc_die--;
	}
	if (_count_frame_playsound_ore_damaged > 0)
	{
		_count_frame_playsound_ore_damaged--;
	}
	if (_count_frame_playsound_spide_born > 0)
	{
		_count_frame_playsound_spide_born--;
	}
	if (_time_showads_count > 0)
	{
		_time_showads_count--;
	}
	if (_skipframe_show_reward > 0)
	{
		_skipframe_show_reward--;
	}
    if (GAME()->_purchase_procesing_opac > 0)
    {
        GAME()->RenderLoadingPurchase(0, 0);
    }
    
    if (_current_state > k_GS_LOGO)
	{
#if defined (MAC_OS)
        if(GAME()->_device.IsNetworkAvailable())
        {
            bool pinead_pop;
            pinead_pop = true;
            /*if(_current_state == k_GS_PLAYGAME)
            {
                pinead_pop = false;
            }*/
            //printf("\n GAME()->_advert.HasPopup():%d,GAME()->_advert.IsAvailable():%d",GAME()->_advert.HasPopup(),GAME()->_advert.IsAvailable());
            if (!GAME()->_advert.HasPopup() && GAME()->_advert.IsAvailable() && _play_game_num <= 0 && pinead_pop)
            {
                GAME()->_advert.Init();
                _stateAppDownload = 1;
                _count_times_showAds = 0;
            }
        }
#endif
		if (_user.CheckHeroColleted(EVENT_HERO_ID_AVAILABLE))
        {
            _user._has_pass_invitation = true;
            _user._invitation_num = 3;
            _user._invitation_reward_current = _user._invitation_num;
        }
		/*if (_user._time_reset_daily_quest <= time(NULL) && !_is_hacked_time)
		{
			_user.DailyQuestReset();
		}*/
		INT_TIME time_cur = time(NULL);
		if (_user._time_check_hack <= time_cur)
		{
			_user._time_check_hack = time_cur;
		}
		else
		{
			_user._is_hack = true;
		}
        /*
		if (_user._iap_triger_discount <= _battle_current)
		{
			if (_user._iap_discount_time_reset <= time_cur)
			{
				_user._iap_discount_time_reset = time_cur + IAP_DISCOUNT_TIME;
			}
			else
			{
				_user.IapDiscountReset();
			}
		}*/
        /*
		if (_user._iap_discount_time_reset > time_cur)
		{
			if (_iap_discount_time.isNullDay())
			{
				_iap_discount_time.setDateBYSecond(_user._iap_discount_time_reset - time_cur);
			}
		}
		else
		{
			_iap_discount_time.setDateBYSecond(0);
		}*/
		GAME()->CheckAndSynSave();
        /*if (GAME()->UpdateSynSave())
        {
        }*/
        /*if(!GAME()->_server_time.isNullDay())
        {
            INT_TIME svtime = GAME()->_server_time.getMilisecond();
            svtime+=DT();
            GAME()->_server_time.setDateBYMilisecond(svtime);
        }*/

		if (GAME()->_musicEnable)
		{
			if (_bg_music_current != -1)
			{
				if (_bg_change_music)
				{
					if (_bg_music_volum > 0)
					{
						_bg_music_volum -= 2;
					}
					if (_bg_music_volum <= 0)
					{
						_bg_music_volum = 0;
						_bg_change_music = false;
						int music_random = BGM_BATTLE_2;//CMath::RANDOM(BGM_BATTLE_1, BGM_BATTLE_3);
						/*while (music_random == _bg_music_current)
						{
							music_random = BGM_BATTLE_2;//CMath::RANDOM(BGM_BATTLE_1, BGM_BATTLE_3);
						}*/
						_bg_music_current = music_random;
						GAME()->StopCurrentMusic();
						GAME()->LoadMusic(_bg_music_current);
						GAME()->PlayCurrentMusic(-1);
					}
				}
				else
				{
					if (_bg_music_volum < 100)
					{
						_bg_music_volum += 2;
					}
					if (_bg_music_volum > 100)
					{
						_bg_music_volum = 100;
					}
				}
				GAME()->SetVolume(_bg_music_volum);
			}
		}
		/*if (_user._watch_ad_time > time_cur)
		{
			if (_watch_ads_time.isNullDay())
			{
				_watch_ads_time.setDateBYSecond(_user._watch_ad_time - time_cur);
			}
		}
		if (_has_double_coin_timer > 0)
		{
			if (_fairy_double_coin_time.isNullDay())
			{
				_fairy_double_coin_time.setDateBYSecond(_has_double_coin_timer);
			}
		}
		
		if (_user._iap_starter_double_coin_time > 0)
		{
			if (_starter_double_coin_time.isNullDay())
			{
				_starter_double_coin_time.setDateBYSecond(_user._iap_starter_double_coin_time);
			}
		}
		if (_user._iap_starter_time_reset > time_cur)
		{
			if (_starter_pack_time.isNullDay())
			{
				_iap_starter_time.setDateBYSecond(_user._iap_starter_time_reset - time_cur);
			}
		}
        if (_user._timeBuyOpenBox > time_cur)
        {
            if (_timeBuyOpenBox.isNullDay())
            {
                _timeBuyOpenBox.setDateBYSecond(_user._timeBuyOpenBox - time_cur);
            }
        }*/
		if (_user._iap_dis_time > time_cur)
		{
			if (_iap_dis_cur_timer == 0 && !_user._has_bought_iap_dis_cur)
			{
				_iap_dis_cur_timer = 60*(_user._iap_dis_time - time_cur);
			}
		}
		if (_user._iap_dis_100_time > time_cur)
		{
			if (_iap_dis_100_timer == 0 && !_user._has_bought_iap_dis_100)
			{
				_iap_dis_100_timer = 60*(_user._iap_dis_100_time - time_cur);
			}
		}
		else
		{
			_user._has_bought_iap_dis_100 = true;
		}
		if (_user._has_bought_iap_dis_100)
		{
			if (_user._iap_dis_100_time_skip_return <= time(NULL))
			{
				_user._has_bought_iap_dis_100 = false;
			}
		}
		if (_user._num_gem_used >= _user._iap_100_gem_use_trigger && _user.GetGem() < _user._iap_100_min_trigger)
		{
			_user.ActiveIapPackDiscount(true);
		}
		bool all_touch_release = true;
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			if (TOUCHS(i)->_state != TOUCH_UP)
			{
				all_touch_release = false;
			}
		}
		if (all_touch_release)
		{
			for (int j = 0; j < NUM_BUTTON_INGAME; j++)
			{
				_ingame_button[j]._touch_id = -1;
			}
			_auto_hold_key = -1;
		}

		

    }
    /*
	if(!_iap_discount_time.isNullDay())
	{
		if(_iap_discount_time.UpdateCountDown())
		{
			_iap_discount_time.setNullDay();
		}
	}*/
	/*if(!_iap_starter_time.isNullDay())
	{
		if (_iap_starter_time.UpdateCountDown())
		{
			_iap_starter_time.setNullDay();
			_user._iap_starter_time_reset = time(NULL);
		}

	}*/
	/*if(!_wheel_time.isNullDay())
	{
		if (_wheel_time.UpdateCountDown())
		{
			_wheel_time.setNullDay();
		}
	}
	if(!_watch_ads_time.isNullDay())
	{
		if(_watch_ads_time.UpdateCountDown())
		{
			_watch_ads_time.setNullDay();
			_has_ads_free_gift = false;
		}
	}*/
#if ADD_ADVERT
    if(_stateAppDownload == 1 && CGame::_this->_advert.GetAppInstallState() == PINEADS_INSTALL_STATE_DOWNLOAD_DONE)
    {
        _stateAppDownload = 0;
        CGame::_this->_advert.SetDownloadCompete();
        CGame::_this->_advert._popup_state = PINEADS_POPUP_STATE_NONE;
    }
    if(CGame::_this->_advert.GetAppInstallState() == PINEADS_INSTALL_STATE_DOWNLOAD_CANCEL && _stateAppDownload == 1)
    {
        _stateAppDownload = 0;
        _play_game_num = 1;
    }
#endif

    //quoc.nguyen
    /*if(!_timeBuyOpenBox.isNullDay())
    {
        if(_timeBuyOpenBox.UpdateCountDown())
        {
            _timeBuyOpenBox.setNullDay();
        }
    }*/

	if (_iap_dis_100_timer > 0)
	{
		_iap_dis_100_timer--;
		if (_iap_dis_100_timer <= 0)
		{
			_iap_dis_100_timer = 0;
			_user._iap_dis_100_time = time(NULL);
			_user._iap_dis_100_time_skip_return = time(NULL) + 24 * 60 * 60;
		}
	}
	if (_iap_dis_cur_timer > 0)
	{
		_iap_dis_cur_timer--;
		if (_iap_dis_cur_timer <=0)
		{
			_iap_dis_cur_timer = 0;
			_user._iap_dis_time = time(NULL);
		}
	}

#if defined (MAC_OS)
	/*if(GAME()->_processing_time_out > 0)
	{
		GAME()->_processing_time_out--;
	}
	else
	{
		GAME()->_processing_time_out = 0;
		if(GAME()->_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
		{

		}

		GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_NONE;
	}*/
	if(!OS_GC_HasOpenning())
	{
		if(GAME()->_processing_view_type == PROCESSING_VIEW_TYPE_GC)
		{
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_NONE;
		}
	}
	if(PineSocial::HasloggingSystem )
    {
        GAME()->_purchase_procesing_opac += 3;
        if(GAME()->_purchase_procesing_opac > 100)
        {
            GAME()->_purchase_procesing_opac = 100;
        }
    }
    else
	if (GAME()->_is_purchase_procesing || GAME()->_processing_view_type != PROCESSING_VIEW_TYPE_NONE)
	{
		GAME()->_purchase_procesing_opac += 3;
		if(GAME()->_purchase_procesing_opac > 100)
		{
			GAME()->_purchase_procesing_opac = 100;
		}
	}
	else
	{
		GAME()->_purchase_procesing_opac -= 10;
		if (GAME()->_purchase_procesing_opac <= 0)
		{
			GAME()->_purchase_procesing_opac = 0;
			GAME()->_loading_count_frame = 0;
		}
	}
#else
#endif  
	GAME()->setUseOptimizeDrawModule(false);

	/***********************/
	if (!_user._has_remove_ads_pop_up)
	{
#pragma region TOPEBOX_PROMO_GAME
		if (_user._game_promo_has_show)
		{

#if defined (ANDROID_OS)
			if (GAME()->_topebox_game._is_close_ads)
			{
				GAME()->_topebox_game.render_banner_topebox = false;
				if (GAME()->_topebox_game.count_skip_banner >= 3)
				{
					_user._game_promo_has_show = false;
					_user._game_promo_delay_show = time(NULL) + TIME_DELAY_SHOW_TOPEBOX_ADS;
					GAME()->_topebox_game.show_banner_topebox_active = false;
					GAME()->_topebox_game.count_skip_banner = 3;
					_user.UserDataSave();
					PDEBUG("\n ###########Skip 3 lan");
				}
			}
#endif
			//PDEBUG("\n _topebox_game.GamePromoHasTouchDown():%d -- _canTouch:%d", _topebox_game.GamePromoHasTouchDown(), _canTouch);
			if (GAME()->_topebox_game.count_show_close_banner_topebox > 0)
			{
				GAME()->_topebox_game.count_show_close_banner_topebox--;
				//PDEBUG("\n --------------------->_topebox_game.count_show_close_banner_topebox:%d", _topebox_game.count_show_close_banner_topebox);
				if (GAME()->_topebox_game.count_show_close_banner_topebox <= 0)
				{
					GAME()->_topebox_game.count_show_close_banner_topebox = -10;
				}
			}
			if (GAME()->_topebox_game.GamePromoHasTouchDown())
			{
#if !defined (_WINDOWS)
				if (Device::IsNetworkAvailable())
#endif
				{
					GAME()->_can_showads = false;
					_user._game_promo_has_show = false;
					GAME()->_topebox_game.show_banner_topebox_active = false;
					GAME()->_topebox_game.render_banner_topebox = false;
					_user._game_promo_order++;
					_user._game_promo_delay_show = time(NULL) + TIME_DELAY_SHOW_TOPEBOX_ADS;
					//_topebox_game.ResponseRequest();
					//PDEBUG("\n ##### Open URL:_link_store = %s \n", GAME()->_topebox_game._link_store); 
#if defined (ANDROID_OS) || defined (MAC_OS)
					PDEBUG("\n ##### Open URL:linkStore = %s \n", GAME()->_topebox_game._link_store);
					PineSocial::OpenURL(GAME()->_topebox_game._link_store);


#endif
					/*char title[128];
					char decs[1024];
					sprintf(title, "%s Click", "Topebox-Ads");
					sprintf(decs, "%s Click", "Topebox-Ads");
					char type[128];
					sprintf(type, "%s", "topebox_ads");
					#if defined (MAC_OS) || (ANDROID_OS)
					PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
					Device::GA_LogContents(title, decs, type);
					#endif*/
					_user.UserDataSave();
				}
			}
		}

		if (_user._game_promo_has_show)
		{
			if (GAME()->_topebox_game.UpdateTouchGamePromo())
			{
				//return true;
			}
		}
#pragma endregion
	}
	/*************************/

	/***Topebox promo**/
	if (GAME()->is_config_downloaded && !_user._has_remove_ads_pop_up)
	{
		//if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON)
		//{
		//	GAME()->is_disable_promo = false;
		//}
		if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER /*|| GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON*/)
		{
			GAME()->is_renderd_promo = true;
		}

		if (GAME()->is_renderd_promo)
		{

			/*if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON)
			{
				GAME()->_topebox_game.is_rendered = true;
			}*/
#pragma region TOPEBOX_PROMO_GAME
			//PDEBUG("\n _game->_game_promo_has_show:%d -- GAME()->_topebox_game.render_banner_topebox:%d", _user._game_promo_has_show, GAME()->_topebox_game.render_banner_topebox);
			//if (_user._game_promo_has_show)
			//{

			//	if (GAME()->is_disable_promo)
			//	{
			//		float max = GAME()->_topebox_game._icon_w*2.5f;
			//		if (GAME()->_topebox_game._topebox_game_scrollEff < max)
			//		{
			//			GAME()->_topebox_game._topebox_game_scrollEff += 10;
			//			if (GAME()->_topebox_game._topebox_game_scrollEff >= max)
			//			{
			//				GAME()->_topebox_game._topebox_game_scrollEff = max;
			//			}
			//		}

			//	}
			//	else {
			//		if (GAME()->_topebox_game.GamePromoIsReady())
			//		{
			//			//PDEBUG("\n _game->_user._topebox_game_scrollEff: %f", GAME()->_topebox_game_scrollEff);
			//			if (!GAME()->_topebox_game.GamePromoHasTouchDown())
			//			{
			//				float max = GAME()->_topebox_game._icon_w*2.5f;
			//				if (GAME()->_topebox_game._topebox_game_scrollEff > 0)
			//				{
			//					GAME()->_topebox_game._topebox_game_scrollEff += -10;
			//					if (GAME()->_topebox_game._topebox_game_scrollEff <= 0)
			//					{
			//						GAME()->_topebox_game._topebox_game_scrollEff = 0;
			//					}
			//				}
			//			}
			//		}
			//	}
			//	//PDEBUG("\n _game->_user.GamePromoIsReady: %d", _game->_user._game_promo_has_show);
			//}
			//else
			//{
			//	float max = GAME()->_topebox_game._icon_w*2.5f;
			//	if (GAME()->_topebox_game._topebox_game_scrollEff < max)
			//	{
			//		GAME()->_topebox_game._topebox_game_scrollEff += 10;
			//		if (GAME()->_topebox_game._topebox_game_scrollEff >= max)
			//		{
			//			GAME()->_topebox_game._topebox_game_scrollEff = max;
			//			GAME()->_topebox_game.ResetGamePromoInfo();
			//		}
			//	}

			//	GAME()->_topebox_game.show_banner_topebox_active = false;
			//	//PDEBUG("\n _game->_topebox_game.show_banner_topebox_active  => Gameplay render");
			//}
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
				//if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON && GAME()->_topebox_game.is_rendered)
				//{
				//	G()->SetOpacity(40);
				//	//if (GAME()->is_map)
				//	{
				//		G()->FillRect(GAME_PROMO_RENDER_X + -GAME()->_topebox_game._topebox_game_scrollEff + 0 - 25, GAME_PROMO_RENDER_Y + -GAME()->_topebox_game._icon_h + 0 + 10 + 30, fw, fw, true);
				//	}

				//}
				//else 
				if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER && GAME()->_topebox_game.render_banner_topebox) {
					//_gp->FillRect(0, 0, k_SCREEN_WIDTH, k_SCREEN_HEIGHT, true);
					G()->FillFullScreen(true);
				}

				G()->ClearScale();
				G()->SetOpacity(100);
			}
			//PDEBUG("\n GAME()->_topebox_game.is_rendered:%d -- GAME()->_topebox_game.typeAds:%d", GAME()->_topebox_game.is_rendered, GAME()->_topebox_game.typeAds);
			//if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_ICON && GAME()->_topebox_game.is_rendered)
			//{
			//	//if (GAME()->is_map)
			//	{
			//		GAME()->_topebox_game.RenderGamePromo(GAME_PROMO_RENDER_X + -GAME()->_topebox_game._topebox_game_scrollEff + 0 - 20, GAME_PROMO_RENDER_Y - GAME()->_topebox_game._icon_h + 30);
			//	}
			//}
			//else 
			if (GAME()->_topebox_game.typeAds == TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER && GAME()->_topebox_game.render_banner_topebox)
			{
				GAME()->_topebox_game.RenderGamePromo(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
			}
		}




#pragma endregion
	}


	/******End Topebox promo*****/
}

void CGame::RenderLoadingPurchase(float x, float y)
{
    G()->SetOpacity(_purchase_procesing_opac);
    G()->SetColor(0xdd000000);
    G()->FillFullScreen(true);
    GAME()->_anim_loading.DrawAnimObject(G());
    GAME()->_anim_loading.UpdateAnimObject();
    GAME()->_anim_loading.UpdateAnimObject();
    GAME()->_anim_loading.UpdateAnimObject();
    GAME()->_anim_loading.UpdateAnimObject();
    _loading_count_frame++;
    GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawFrame(G(), 13, k_SCREEN_WIDTH/2 - 15, k_SCREEN_HEIGHT/3 + 30);
    if(_loading_count_frame >= 10)
    {
        GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawFrame(G(), 13, k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT/3 + 30);
    }
    if(_loading_count_frame >=20)
    {
        GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawFrame(G(), 13, k_SCREEN_WIDTH/2 + 15, k_SCREEN_HEIGHT/3 + 30);
    }
    if(_loading_count_frame >= 30)
    {
        _loading_count_frame = 0;
    }
    
    G()->SetOpacity(100);
}

//Lam --- Port function

void TDGame::MeasureButtonTemp(HeroButton* button)
{
	PinePoint btpos;
	btpos.X = button->_x;
	btpos.Y = button->_y;
	float btn_width = 210;
	float btn_height = 210;
	btpos = GAME()->_game_context.MeasureDensity(btpos, btn_width, btn_height);
	button->_x = btpos.X ;
	button->_y = btpos.Y ;
}
void TDGame::MeasureButton(Button* button)
{
	PinePoint btpos;
	btpos.X = button->_posX + button->TZ_GetX();
	btpos.Y = button->_posY + button->TZ_GetY();
	float btn_width = button->TZ_GetWidth();
	float btn_height = button->TZ_GetHeight();
	btpos = GAME()->_game_context.MeasureDensity(btpos, btn_width, btn_height);
	button->_posX = btpos.X - button->TZ_GetX();
	button->_posY = btpos.Y - button->TZ_GetY();
	button->_posX_con = button->_posX;
	button->_posY_con = button->_posY;
}

void TDGame::MeasureButton(Button* button, int anchor)
{
	PinePoint btpos;
	btpos.X = button->_posX + button->TZ_GetX();
	btpos.Y = button->_posY + button->TZ_GetY();


	if ((anchor & ANCHOR_RIGHT) != 0){
		btpos.X = btpos.X - k_SCREEN_WIDTH;
	}

	if ((anchor & ANCHOR_BOTTOM) != 0){
		btpos.Y = btpos.Y - k_SCREEN_HEIGHT;
	}

	btpos = GAME()->_game_context.MeasureAnchor(btpos, anchor);
	button->_posX = btpos.X - button->TZ_GetX();
	button->_posY = btpos.Y - button->TZ_GetY();
}
void TDGame::MeasureButtonX(float posx, Button* button, BYTE anchor_horizonal){
	PinePoint btpos;
	btpos = GAME()->_game_context.MeasureAnchor(posx, 0, anchor_horizonal);
	float button_fixed_x = button->GetFixX();
	button->_posX = btpos.X - button_fixed_x;
}
void TDGame::MeasureButtonY(float posy, Button* button, BYTE anchor_vertical){
	PinePoint btpos;
	btpos = GAME()->_game_context.MeasureAnchor(posy, 0, anchor_vertical);
	float button_fixed_y = button->GetFixY();
	button->_posY = btpos.Y - button_fixed_y;
}
PinePoint TDGame::MeasureFrame(CSprite* sprite, UINT32 frameid){
	float framex = sprite->GetFModuleX(frameid, 0);
	float framey = sprite->GetFModuleY(frameid, 0);
	float framew = sprite->GetFModuleWidth(frameid, 0);
	float frameh = sprite->GetFModuleHeight(frameid, 0);
	return GAME()->_game_context.MeasureDensity(framex, framey, framew, frameh);
}
void TDGame::MeasureAnim(CAnimObject* obj){
	obj->CalculateCurrentAFrame();
	int fid = obj->_anim_sprite->GetFrameIDOfAFrame(obj->_current_aframes);
	PineRectangle bound = obj->_anim_sprite->GetFmoduleBound(fid, 0);
	PinePoint anim_pos = obj->_anim_sprite->GetAFramePos(obj->_current_aframes);
	PinePoint point = GAME()->_game_context.MeasureDensity(bound.X + anim_pos.X, bound.Y + anim_pos.Y, bound.W, bound.H);
	obj->_x = obj->_x + point.X - bound.X - anim_pos.X;
	obj->_y = obj->_y + point.Y - bound.Y - anim_pos.Y;

}

PinePoint TDGame::MeasureFrame(CSprite* sprite, UINT32 frameid, float scalex, float scaley)
{
	float framex = sprite->GetFModuleX(frameid, 0);
	float framey = sprite->GetFModuleY(frameid, 0);
	float framew = sprite->GetFModuleWidth(frameid, 0);
	float frameh = sprite->GetFModuleHeight(frameid, 0);
	float scale = scalex > scaley ? scalex : scaley;
	PinePoint point = GAME()->_game_context.MeasureDensity(framex - framex * (scale - 1), framey - framey * (scale - 1), framew * scale, frameh * scale);
	point.X -= framex;
	point.Y -= framey;
	return point;
}

PinePoint TDGame::MeasureFrame(CSprite* sprite, UINT32 frameid, BYTE anchor)
{
	PineRectangle bound = sprite->GetFrameBound(frameid);
	PinePoint btpos;
	if (anchor == ANCHOR_TOP)
	{
		btpos = GAME()->_game_context.MeasureAnchor(0, bound.Y, anchor);


	}

	return btpos;
}
//Lam End Port

void TDGame::ProcessingDialogYesNo(int context, int index)
{
	_dialog_process_type = index;
    switch (_dialog_process_type) {
        case 0://cancel
            switch (context)
        {
            case DIALOG_CONTEXT_INVITATION_EXIT:
                Device::ClearTextBuffer();
                Device::ShowKeyboard(0, 0, 0, 0);
                Device::DisableReturnKey(true);
                Device::SetTextBufferMax(EVENT_INVITE_CODE_LENGTH);
                break;
            case DIALOG_CONTEXT_CONFIRM_LOADDATA:
                Device::SetAppInstalled("confirm",100);
                break;
			case DIALOG_CONTEXT_CONFIRM_BUY_IAP:
				
				break;
			case DIALOG_CONTEXT_REVIVE_BY_ADS:
				_gameover_state = GAME_OVER_STATE_RUN;
				break;
			case DIALOG_CONTEXT_REVIVE_BY_GEM:
				_gameover_state = GAME_OVER_STATE_RUN;
				break;
			case DIALOG_CONTEXT_RELIC_SPECIAL:
				_user._hero_promo_time_delay = time(NULL) + 24 * 60 * 60;
				_user.UserDataSave();
				break;
            default:
                
                break;
        }
            break;
        case 1://ok
            switch (context)
        {
            case DIALOG_CONTEXT_INVITATION_EXIT:
                _invitation_close = true;
                //_user._has_pass_invitation = true;
                if (strcmp(_user._ivitation_code,"NULL") == 0)
                {
#if !defined (ANDROID_OS)
                    GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_GET_INVITATION_CODE);
#endif
                }
                _user.UserDataSave();
                break;
            case DIALOG_CONTEXT_CONFIRM_NOTIFY:
#if defined (MAC_OS)
                RequestRegisterNotificationSetting();
				_user._is_notify = true;
                _system_popup_showed = true;
#endif
                break;
            case DIALOG_CONTEXT_CONFIRM_LOADDATA:
#if !defined (ANDROID_OS)
                GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_SWAP_SAVE_FROM_SERVER);
#endif
                break;
			case DIALOG_CONTEXT_CONFIRM_BUY_IAP:
				if (_ingame_menu_type == MENU_INGAME_BUTTON_SHOP)
				{
					_ingame_menu_scroll.SetCurrent(0);
				}
				else
				{
					_ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
					SetState(k_GS_INGAME_MENU);
				}
				
				break;
			case DIALOG_CONTEXT_REVIVE_BY_ADS:
			{
				PDEBUG("\n DIALOG_CONTEXT_REVIVE_BY_ADS");
#if defined (ANDROID_OS)
				if (Device::IsNetworkAvailable() && !_has_watched_ads)
				{
					bool hasShowads = false;
					//if (GAME()->HasVideoAds())
						//if (GAME()->HasAdmobRewardedVideo())
					{
						GAME()->ShowVideoAds();
						//GAME()->ShowAdmobRewardedVideo();
						_has_watched_ads = true;
						hasShowads = true;
					}
					//else
					{
						_has_watched_ads = true;
						GAME()->_on_video_ads_reward = true;
					}
				}
#elif defined (MAC_OS)
				if (Device::IsNetworkAvailable() && !_has_watched_ads)
				{
					bool hasShowads = false;
					int adboxtype = PineAdBox::HasVideoAds(true);
					if (adboxtype >= 0)
					{
						PineAdBox::ShowVideoAds(adboxtype);
						_has_watched_ads = true;
						hasShowads = true;
					}
					else
					{
						PineAdBox::ShowAdvertFullScreen();
						_has_watched_ads = true;
						hasShowads = true;
						PineAdBox::showAdState = SHOW_AD_COMPLETED;
					}
				}
#else
				
				PineAdBox::showAdState = SHOW_AD_COMPLETED;
				_has_watched_ads = true;
#endif
				char title[128];
				char decs[1024];
				sprintf(title, "%s Click", "Revive");
				sprintf(decs, "%s Click", "Revive");
				char type[128];
				sprintf(type, "%s", "common_events");
#if defined (MAC_OS) || (ANDROID_OS)
				PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
				Device::GA_LogContents(title, decs, type);
#endif
			}
				break;
			case DIALOG_CONTEXT_REVIVE_BY_GEM:
				_user.AddGem(-1);
				_gameover_state = GAME_OVER_STATE_END;
				break;
			case DIALOG_CONTEXT_RELIC_SPECIAL:
			{
				int cost_dis = _relic_special_cost / 2;
				_user.AddGem(-cost_dis);
				_user._hero_promo_time_delay = time(NULL) + 24 * 60 * 60;
				_user.AddNewRelics(_relic_special_id, ITEMRELIC_GROUP_HERO);
				RelicsDefault();
				ModifyInfo(ITEMRELIC_GROUP_HERO, _relic_special_id);
				_user.UserDataSave();
			}
				break;
			case DIALOG_CONTEXT_PURCHASE_MORE_WHEEL:
			{
				char title[128];
				char decs[1024];
				sprintf(title, "%s", "Premium-Wheel Click");
				sprintf(decs, "%s", "Premium-Wheel Click");
				char type[128];
				sprintf(type, "%s", "iap_promo_logs");
#if defined (MAC_OS) || (ANDROID_OS)
				PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs,type);
				Device::GA_LogContents(title, decs,type);
#endif
#if defined (MAC_OS)
				//purchase
				if (Device::IsNetworkAvailable())
				{
					PurchaseProduct("NFD_0.99_PREMIUM_WHEEL_2");
					GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
					GAME()->_loading_count_frame = 0;
					GAME()->_processing_time_out = PROCESSING_TIME_OUT;
					GAME()->_is_purchase_procesing = true;
				}
				printf("\n iap id = NFD_0.99_PREMIUM_WHEEL_2");
#elif defined (ANDROID_OS)
				if (Device::IsNetworkAvailable())
				{
					//if (GAME()->_pineStore.IsSynPriceForProduct(_iap_dis_idstr))
					{
						PurchaseProductWithType("nfd_0_99_premium_wheel", 3);
					}
					GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
					GAME()->_loading_count_frame = 0;
					GAME()->_processing_time_out = PROCESSING_TIME_OUT;
					GAME()->_is_purchase_procesing = true;
				}
				//PDEBUG("\n iap id = %d", _id);
#else
				_user._num_wheel_spin_premium += 3;
				_num_wheel_render = _user._num_wheel_spin_premium;
				_user.UserDataSave();
#endif
			}
				break;
            default:
                break;
        }
            break;
        default:
            break;
    }
	
}

void TDGame::ProcessingDialogOK(int context)
{
	switch (context)
	{
	case DIALOG_CONTEXT_WHEEL_REWARD:
		break;
	case DIALOG_CONTEXT_WATCH_ADS:
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
			int reward_coin = GetDesignTreasure(_battle_current, param_coin, false);
			value *= reward_coin;
			_user.AddCoin(value, true);
		}
		break;
		case WATCH_ADS_REWARD_TYPE_GEM:
			_user.AddGem(value);
			break;
		case WATCH_ADS_REWARD_TYPE_AUTO_ATT:
			_user._auto_attack_free += value;
			break;
		case WATCH_ADS_REWARD_TYPE_AUTO_SKILL:
			_user._auto_skill_free += value;
			break;
		case WATCH_ADS_REWARD_TYPE_DOUBLE_COIN:
			_has_double_coin_timer += value;
			break;
		default:
			break;
		}
		_user._watch_ad_times++;
		if (_user._watch_ad_times >= _game_design.General.SheetFree_Gift.int32Value._totalData)
		{
			_user._watch_ad_times = 0;
		}
		//_user._watch_ad_time = time(NULL) + _time_waiting_free_gift;
		_user.UserDataSave();
		ClearAllTouchUp(TOUCH_TYPE_MENU_INFO);
	}
	break;
	case DIALOG_CONTEXT_TW_FOLLOW:
		_user.AddGem(TW_FOLLOW_REWARD);
		_user._has_follow_tw = true;
		_rate_us_type = RATE_US_TYPE_NONE;
		_rate_us_time = -1;
		ClearAllTouchUp(TOUCH_TYPE_MENU_INFO);
		ReInitShop();
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_FB_LIKE:
		_user.AddGem(FB_LIKE_REWARD);
		_user._has_liked_fb = true;
		_rate_us_type = RATE_US_TYPE_NONE;
		_rate_us_time = -1;
		ClearAllTouchUp(TOUCH_TYPE_MENU_INFO);
		ReInitShop();
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_RATE_US:
		_user.AddGem(RATE_US_REWARD);
		_rate_us_close = true;
		_user._has_rated_us_type = RATE_US_TYPE_RATED;
		_rate_us_type = RATE_US_TYPE_NONE;
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_100_BATTLE:
		_user._has_completed_battle_max = true;
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_INVITATION_MESSAGE:
		Device::ClearTextBuffer();
		Device::ShowKeyboard(0, 0, 0, 0);
		Device::DisableReturnKey(true);
		Device::SetTextBufferMax(EVENT_INVITE_CODE_LENGTH);
		break;
	case DIALOG_CONTEXT_INVITATION_CONFIRM:
		_invitation_close = true;
		_user._has_pass_invitation = true;
		Device::CloseKeyboard();

		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_INVITATION_GIFT_1:
		if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_ACHEMIST)
		{
			if (_wheel_relic._id != -1)
			{
				ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
				_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
				ModifyInfo(_wheel_relic._group, _wheel_relic._id);
			}
			else
			{
				_user.AddGem(20);
			}
		}
		else if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_XMAS)
		{
			_user.AddCoin(EVENT_INVITE_REWARD_COIN, true);
		}

		_user._invitation_reward_current = 1;
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_INVITATION_GIFT_2:
		if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_ACHEMIST)
		{
			if (_wheel_relic._id != -1)
			{
				ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
				_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
				ModifyInfo(_wheel_relic._group, _wheel_relic._id);
			}
			else
			{
				_user.AddGem(20);
			}
		}
		else if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_XMAS)
		{
			_user.AddGem(EVENT_INVITE_REWARD_GEM);
		}

		_user._invitation_reward_current = 2;
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_INVITATION_GIFT_3:
		UnlockNewHero(EVENT_HERO_UNLOCK_TYPE_AVAILABLE);
		_user._invitation_reward_current = 3;
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_DOWN_MOREGAME:
#if ADD_ADVERT
		CGame::_this->_advert.SetAppInstallState(PINEADS_INSTALL_STATE_NONE);
		CGame::_this->_advert.SetDownloadCompete();
#endif
		_user._stateAppDownload = 0;
		_user._download_moregame_trigger = time(NULL) + DOWN_MOREGAME_TIME;
		_user.AddGem(DOWN_MOREGAME_REWARD);
		ClearAllTouchUp(TOUCH_TYPE_MENU_INFO);
		ReInitShop();
		_user.UserDataSave();
		break;
	case DIALOG_CONTEXT_OFFLINE_REWARD1:
		_user.AddCoin(80000, true);
		_user.AddGem(30);
		if (_wheel_relic._id != -1)
		{
			ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
			_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
			ModifyInfo(_wheel_relic._group, _wheel_relic._id);
		}
		_user.UserDataSave();
		_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_DONE;
		break;
	case DIALOG_CONTEXT_OFFLINE_REWARD2:
		_user.AddCoin(50000, true);
		_user.AddGem(20);
		if (_wheel_relic._id != -1)
		{
			ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
			_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
			ModifyInfo(_wheel_relic._group, _wheel_relic._id);
		}

		_user.UserDataSave();
		_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_DONE;
		break;
	case DIALOG_CONTEXT_OFFLINE_REWARD3:
		_user.AddCoin(20000, true);
		_user.AddGem(10);
		_user.UserDataSave();
		_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_DONE;
		break;
	case DIALOG_CONTEXT_OFFLINE_REWARD4:
		_user.AddCoin(10000, true);
		_user.UserDataSave();
		_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_DONE;
		break;
	case DIALOG_CONTEXT_CONFIRM_NOTIFY:
		break;

	case DIALOG_CONTEXT_WARNING_HACKER:
		_warning_notify_hacker = false;
		break;
	case DIALOG_CONTEXT_NO_NETWORK:
		break;
	case DIALOG_CONTEXT_DAILY_REWARD:
	{
		if (_user._daily_reward_num < 7 && !_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
		{
			char title[128];
			char decs[1024];
			sprintf(title, "Daily-Reward %d", _user._daily_reward_num+1);
			sprintf(decs, "Daily-Reward %d", _user._daily_reward_num+1);
			char type[128];
			sprintf(type, "%s", "daily_rewards_logs");
#if defined (MAC_OS) || (ANDROID_OS)
			PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
			Device::GA_LogContents(title, decs, type);
#endif
		}
		switch (_daily_reward[_user._daily_reward_num]._type)
		{
		case DAILY_REWARD_TYPE_COIN:
		{
			_user.AddCoin(_daily_reward[_user._daily_reward_num]._coin, true);
		}
		break;
		case DAILY_REWARD_TYPE_GEM:
			_user.AddGem(_daily_reward[_user._daily_reward_num]._gem);
			break;
		case DAILY_REWARD_TYPE_RELIC:
			if (_wheel_relic._id != -1)
			{
				ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
				_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
				ModifyInfo(_wheel_relic._group, _wheel_relic._id);
			}

			break;
		case DAILY_REWARD_TYPE_BIG:
			_user.AddCoin(_daily_reward[_user._daily_reward_num]._coin, true);
			_user.AddGem(_daily_reward[_user._daily_reward_num]._gem);
			break;
		case DAILY_REWARD_TYPE_HERO:
			UnlockNewHero(HEROES_UNLOCK_TYPE_EVENT_DAILY_REWARD);

			break;
		default:
			break;
		}

		_user._daily_reward_num++;
		
		if (_user._daily_reward_num >= _game_design.General.SheetDaily_Event.int32Value._totalData)
		{
			_user._daily_reward_num = 0;
		}
		Pine_Date_Time local_day;
		local_day.setDateByLocalDate();
		_user._daily_reward_day = local_day.GetTotalDay();
		_daily_reward_close = true;
		_user.UserDataSave();
	}
	break;
	case DIALOG_CONTEXT_IAP_DISCOUNT_SPEC:
	{
		char title[128];
		char decs[1024];
		sprintf(title, "%s Click", _iap_dis_idstr);
		sprintf(decs, "%s Click", _iap_dis_idstr);
		char type[128];
		sprintf(type, "%s", "iap_promo_logs");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs,type);
		Device::GA_LogContents(title, decs,type);
#endif
#if defined (MAC_OS)
		//purchase
		if (Device::IsNetworkAvailable())
		{
			if (GAME()->_pineStore.IsSynPriceForProduct(_iap_dis_idstr))
			{
				PurchaseProduct(_iap_dis_idstr);
			}
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
			GAME()->_loading_count_frame = 0;
			GAME()->_processing_time_out = PROCESSING_TIME_OUT;
			GAME()->_is_purchase_procesing = true;
		}
		printf("\n iap id = %s", _iap_dis_idstr);
#elif defined (ANDROID_OS)
		if (Device::IsNetworkAvailable())
		{
			//if (GAME()->_pineStore.IsSynPriceForProduct(_iap_dis_idstr))
			{
				PurchaseProductWithType(_iap_dis_idstr, 3);
			}
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
			GAME()->_loading_count_frame = 0;
			GAME()->_processing_time_out = PROCESSING_TIME_OUT;
			GAME()->_is_purchase_procesing = true;
		}
		//PDEBUG("\n iap id = %d", _id);
#else

		_user.AddCoin(_iap_dis_coin, true);
		_user.AddGem(_iap_dis_gem);
		_user._auto_attack_free += _iap_dis_autoatt;
		_is_use_auto_skill_free += _iap_dis_autoskill;
		_user._iap_dis_time = time(NULL);
		_user._has_bought_iap_dis_cur = true;
		_user._num_gem_used = 0;
		_iap_dis_cur_timer = 0;
		_user.UserDataSave();
		GetValueIapDis("NONE");
#endif
	}
	break;
	case DIALOG_CONTEXT_IAP_DISCOUNT_OFF:
	{
		char title[128];
		char decs[1024];
		sprintf(title, "%s Click", _iap_dis_idstr);
		sprintf(decs, "%s Click", _iap_dis_idstr);
		char type[128];
		sprintf(type, "%s", "iap_promo_logs");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
		Device::GA_LogContents(title, decs, type);
#endif
#if defined (MAC_OS)
		//purchase
		if (Device::IsNetworkAvailable())
		{
			if (GAME()->_pineStore.IsSynPriceForProduct(_iap_dis_idstr))
			{
				PurchaseProduct(_iap_dis_idstr);
			}
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
			GAME()->_loading_count_frame = 0;
			GAME()->_processing_time_out = PROCESSING_TIME_OUT;
			GAME()->_is_purchase_procesing = true;
		}
		printf("\n iap id = %s", _iap_dis_idstr);
#elif defined (ANDROID_OS)
		if (Device::IsNetworkAvailable())
		{
			//if (GAME()->_pineStore.IsSynPriceForProduct(_iap_dis_idstr))
			{
				PurchaseProductWithType(_iap_dis_idstr, 3);
			}
			GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
			GAME()->_loading_count_frame = 0;
			GAME()->_processing_time_out = PROCESSING_TIME_OUT;
			GAME()->_is_purchase_procesing = true;
		}
		//PDEBUG("\n iap id = %d", _id);
#else
		_user._has_bought_iap_dis_100 = true;
		_user._iap_dis_100_time = time(NULL);
		_user._num_gem_used = 0;
		_user.AddGem(_iap_dis_gem);
		_iap_dis_100_timer = 0;
		_user.UserDataSave();
		GetValueIapDis("NONE");
#endif
	}
	break;
	case DIALOG_CONTEXT_REWARD_EARNING_OFF:
	{
		_user.AddCoin(_reward_earning_off, true);
		_reward_earning_off = 0;
		_time_out_game = time(NULL);
		_reward_earning_off_type = -1;
		_user.UserDataSave();
		char title[128];
		char decs[1024];
		sprintf(title, "%s", "OE Collect");
		sprintf(decs, "%s", "OE Collect");
		char type[128];
		sprintf(type, "%s", "common_events");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
		Device::GA_LogContents(title, decs, type);
#endif
	}
		break;
	case DIALOG_CONTEXT_PRESTIGE:
	{
		ResetActive();
		PLAY_SFX(SFX_MIA_SKILL);
		char title[128];
		char decs[1024];
		sprintf(title, "Prestige %d", _user._user_level_reset);
		sprintf(decs, "Prestige %d", _user._user_level_reset);
		char type[128];
		sprintf(type, "%s", "prestige_logs");
#if defined (MAC_OS) || (ANDROID_OS)
		PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
		Device::GA_LogContents(title, decs, type);
#endif
	}
		break;
	case DIALOG_CONTEXT_REVIVE_BY_ADS:

		break;
	default:
		break;
	}
}
void TDGame::ConvertCoinToString(INT_TIME coin, char* string)
{
	char coinstr[128];
	char coinstr2[128];
	int length = sprintf(coinstr, "%lld", coin);
	int count = 0;
	int count3 = 0;
	for (int i = length-1; i >= 0; i--)
	{
		coinstr2[count] = coinstr[i];
		count3++;
		if (count3 % 3 == 0 && count3 < length)
		{
			count++;
			coinstr2[count] = '.';
		}
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		string[count - 1 - i] = coinstr2[i];
	}
	string[count] = '\0';
}

void TDGame::ConvertMoneyInbalace(INT_TIME money, char* string, INT_TIME min_money, int len_mod)
{
	int count = 0;
	INT_TIME temp_money = money;
	INT_TIME div;
	INT_TIME mod;
	int len_div;
	int lenght_max;
	if (money < min_money)
	{
		ConvertCoinToString(money, string);
	}
	else
	{
		while (temp_money >= min_money && count < 1)
		{
			temp_money = temp_money / min_money;
			count++;
		}
		char ch;
		char ch_mod;
		if (count >= 1)
		{
			ch = 'M';//thay ky tu K
		}
		/*else if (count >= 2)
		{
			ch = 'M';//thay ky tu M
		}
		else if (count == 3)
		{
			ch = 'B';
		}
		else if (count >= 4)
		{
			ch = 'T';
		}*/
		ConvertCoinToString(temp_money, string);
		//sprintf(_string_convert, "%s", ConvertScoreToStringWithCommas(temp_money));
		len_div = strlen(string);
		char str_mod[1024];
		char str_temp[1024];
		int len = sprintf(str_temp, "%lld", money);
		count = 0;
		for (int i = len_div; i < len; i++)
		{
			str_mod[count] = str_temp[i];
			count++;
		}
		lenght_max = len_div + 3 + len_mod;
		for (int i = 0; i < len_mod; i++)
		{
			ch_mod = str_mod[i];
			int res = len_mod - i - 1;
			string[lenght_max - (3 + res)] = ch_mod;
		}
		string[lenght_max - (3 + len_mod)] = ',';

		string[lenght_max - 2] = ch;
		string[lenght_max - 1] = '\0';

		for (int i = lenght_max - 3; i>len_div; i--)
		{
			if (string[i] == '0')
			{
				string[i] = string[i + 1];
				string[i + 1] = '\0';
			}
			else
			{
				string[lenght_max] = '\0';
			}
		}
	}
	int len = strlen(string);
	if (string[len - 2] == ',')
	{
		string[len - 2] = string[len - 1];
		string[len - 1] = '\0';
	}
}

void TDGame::GetRewardEarnOffline()
{
	//printf("\n\n GetRewardEarnOffline \n\n");
	if (_reward_earning_off_type >= 0)
	{
		return;
	}
	_reward_earning_off = 0;
	_reward_earning_off_type = -1;
	if (_time_out_game == -1)
	{
		return;
	}
	int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
	INT_TIME sec = time(NULL) - _time_out_game;
	int min = sec / 60;
	int coin_start = GetDesignTreasure(_battle_current, param_coin, false);
	int total = _game_design.Treasure.SheetOfflineEarning.int32Value._totalData;
	int index = -1;
	for (int i = 0; i < total; i++)
	{
		float hour = _game_design.Treasure.SheetOfflineEarning.floatValue.getValue(i, CGameDesign::FileTreasure::CSheetOfflineEarning::enumFloat::Hours);
		int minute = hour * 60;
		if (min > minute)
		{
			index = i;
		}
	}
	if (index != -1)
	{
		_reward_earning_off_type = 1;
		_reward_earning_off = coin_start*_game_design.Treasure.SheetOfflineEarning.int32Value.getValue(index, CGameDesign::FileTreasure::CSheetOfflineEarning::enumInt32::Value);
		if (min > 4 * 60)
		{
			_reward_earning_off_type = 2;
			_wave_current = 10;
			if (_current_state == k_GS_PLAYGAME)
			{
				_has_revive_in_battle = false;
				InitBattle(_battle_current, _wave_current);
			}
		}
	}
	else
	{
		float hour = _game_design.Treasure.SheetOfflineEarning.floatValue.getValue(0, CGameDesign::FileTreasure::CSheetOfflineEarning::enumFloat::Hours);
		int minute = hour * 60;
		int reward = _game_design.Treasure.SheetOfflineEarning.int32Value.getValue(0, CGameDesign::FileTreasure::CSheetOfflineEarning::enumInt32::Value);
		_reward_earning_off = (INT_TIME)(coin_start*(reward*(sec/(minute*60.0f))));
		if (_reward_earning_off > 0)
		{
			_reward_earning_off_type = 0;
		}
	}
	if (_reward_earning_off_type >= 0)
	{
		if (_reward_earning_off < 100)
		{
			_reward_earning_off = 100;
		}
	}
	_offline_earning_received = true;
}

int TDGame::GetLevelUnlockNewHero(int rar)
{
	int level_max = -1;
	int rar_max = -1;
	int indexmax = -1;
	for (int h = 0; h < NUM_MAX_HERO; h++)
	{
		int level = _hero_inbattle_arr[h].GetLevel();
		if (!_hero_inbattle_arr[h]._is_lock)
		{
			if (_hero_inbattle_arr[h].GetNumStars() > rar_max)
			{
				rar_max = _hero_inbattle_arr[h].GetNumStars();
				level_max = level;
				indexmax = h;
			}
			else if (_hero_inbattle_arr[h].GetNumStars() == rar_max)
			{
				if (level > level_max)
				{
					level_max = level;
					indexmax = h;
				}
			}
		}
	}
	int dis_rar = rar - _hero_inbattle_arr[indexmax].GetNumStars();
	if (dis_rar > 1)
	{
		level_max /= dis_rar;
	}
	if (level_max < 1)
	{
		level_max = 1;
	}
	return level_max;
}

void TDGame::ResetInit()
{
	_reset_gem_reward = 0;
	_reset_coin_reward = 0;
	_reset_hero_relicid_reward = -1;
	_reset_weapon_relicid_reward = -1;
	_reset_battle_target = 0;
	_reset_level_skip_next = _user._user_level_reset + 1;
	int gem_bonus = 0;
	int row = 0;
	int index_current = _user._user_level_reset;
	for (int i = index_current; i < _game_design.General.SheetReset_Design.int32Value._totalData; i++)
	{
		int battle = _game_design.General.SheetReset_Design.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetReset_Design::Battle_Reset);
		if (battle - 1 <= _battle_current)
		{
			index_current = i;
			_reset_level_skip_next = index_current + 1;
		}
	}
	int battle_limit = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::Battle_Reset);
	_reset_battle_target = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::To_Battle)-1;
	_reset_gem_reward = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::Gem);
	_reset_coin_reward = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::Coin);
	_reset_hero_relicid_reward = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::Relic_ID);
	_reset_weapon_relicid_reward = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::WP_Relic_ID);

	gem_bonus = _game_design.General.SheetReset_Design.int32Value.getValue(index_current, CGameDesign::FileGeneral::CSheetReset_Design::Bonus_Gem_Battle)*(_battle_current-battle_limit);
	if (gem_bonus < 0)
	{
		gem_bonus = 0;
	}
	_reset_gem_reward += gem_bonus;

	/*for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (!_hero_inbattle_arr[i]._is_lock)
		{
			_reset_gem_reward += _hero_inbattle_arr[i].GetCostUnlock();
		}
	}*/
	ConvertMoneyInbalace(_reset_gem_reward, _reset_gem_reward_text);
	ConvertMoneyInbalace(_reset_coin_reward, _reset_coin_reward_text);
}

void TDGame::RelicsDefault()
{
	int total_relics = 0;
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
}

void TDGame::ResetActive()
{
	_battle_current = _reset_battle_target;
	_wave_current = 1;
	WeaponResetLevel();
	/*_castle.Init(1);*/
	_castle.AddHp(_castle._hp_max);
	bool has_heroDaily = false;
	if (_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
	{
		has_heroDaily = true;
	}
	
	//_user.SetCoin(0);
	_user.AddGem(_reset_gem_reward);
	_user.AddCoin(_reset_coin_reward, true);
	_user._user_level_reset = _reset_level_skip_next;
	int counthero = 0;
	/*_user.InitHeroes();
	HeroesReset();
	for (int i = 0; i < _game_design.Hero_design.SheetHero_General.int32Value._totalData; i++)
	{
		int heroid = GetDesignHeroGeneral(i, CGameDesign::FileHero_design::CSheetHero_General::ID_Hero);
		if (heroid == HERO_ID_PALADIN)
		{
			_hero_inbattle_arr[counthero].Init(heroid, 1, true, false,false);
			_hero_inbattle_arr[counthero]._is_new = false;
			_user._hero_arr[counthero]._slot_deploy_number = counthero;
			counthero++;
		}
		else if (heroid == HERO_ID_WOLF_RANGER)
		{
			if (has_heroDaily)
			{
				_hero_inbattle_arr[counthero].Init(heroid, 1, true, false,false);
				_hero_inbattle_arr[counthero]._is_new = false;
				_user._hero_arr[counthero]._slot_deploy_number = counthero;
				counthero++;
			}
		}
	}
	_user._num_heroes_collected = counthero;*/
	////reset all hero lv1
	for (int i = 0; i < _user._num_heroes_collected; i++)
	{
		_user._hero_arr[i]._level = 1;
		_hero_inbattle_arr[counthero].Init(_user._hero_arr[i]._heroid, _user._hero_arr[i]._level, _user._hero_arr[i]._is_deployed, false,false);
		_hero_inbattle_arr[counthero]._is_new = false;
		counthero++;
	}
	//reinit hero not colleted
	for (int i = 0; i < _game_design.Hero_design.SheetHero_General.int32Value._totalData; i++)
	{
		int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		int heroid = GetDesignHeroGeneral(i, paramid);
		if (!_user.CheckHeroColleted(heroid))
		{
			_hero_inbattle_arr[counthero].Init(heroid, 1, false, true,false);
			counthero++;
		}
	}
	_user.AddNewRelics(_reset_hero_relicid_reward, ITEMRELIC_GROUP_HERO);
	_user.AddNewRelics(_reset_weapon_relicid_reward, ITEMRELIC_GROUP_WEAPON);
	RelicsDefault();
	ModifyInfo(ITEMRELIC_GROUP_HERO, _reset_hero_relicid_reward);
	ModifyInfo(ITEMRELIC_GROUP_WEAPON, _reset_weapon_relicid_reward);
	_user.UserDataSave();
	_has_revive_in_battle = false;
	_castle.ChangeCastle();
	InitBattle(_battle_current, _wave_current);
	int posx = 0;
	int posy = 0;
	int count_hero_range = 0;
	_num_hero_deployed = 0;
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
	_is_night = false;
}
void TDGame::UpgradeRarity(int heroID)
{
	return;
	for (int i = 0; i < _user._num_heroes_collected; i++)
	{
		if (_hero_inbattle_arr[i].GetHeroID() == heroID)
		{
			_hero_inbattle_arr[i].RarityLevelUp();
		}
	}
}

void TDGame::PushNotify()
{
	PDEBUG("\n _user._is_notify:%d", _user._is_notify);
	time_t now = time(0);
	tm*local_time = localtime(&now);
	int h_cur = local_time->tm_hour + 1;
	int m_cur = local_time->tm_min + 1;
#if defined(MAC_OS)
	if (_user._is_notify)
	{
		Device::_current_num_notification = 0;
		if (_user._tutorial_completed)
		{
			/*INT64 time_wheel = _user._wheel_time_reset - time(NULL);
			if (time_wheel > 5)
			{
				Device::AddNotification("Wheel is ready! Come back and catch your luck now!", time_wheel, false);
			}*/
			Device::AddNotification("We can't carry more golds. Please collect!", 24 * 60 * 60, false);
			/*INT_TIME time_daily = (24 - h_cur) * 60 * 60 + (60 - m_cur) * 60 + 1 * 60;
			Device::AddNotification("Your daily reward is ready to collect!", time_daily, false);*/
		}
	}
#elif defined (ANDROID_OS)
	//if (_user._is_notify)
	{
		char message[128];
		if (_user._tutorial_completed)
		{
			/*INT64 time_wheel = _user._wheel_time_reset - time(NULL);
			if (time_wheel > 5)
			{
				sprintf(message, "%s", "Wheel is ready! Come back and catch your luck now!");
				OS_SetLocalNotification(1, message, message, time_wheel);
			}*/
			/*INT_TIME time_daily = (24 - h_cur) * 60 * 60 + (60 - m_cur) * 60 + 1 * 60;
			sprintf(message, "%s", "Your daily reward is ready to collect!");
			OS_SetLocalNotification(1, message, message, time_daily);*/
			sprintf(message, "%s", "We can not carry more golds. Please collect!");
			OS_SetLocalNotification(0, message, message, 24 * 60 * 60);
			//OS_SetLocalNotification(2, message, message, 1 * 60);
		}
	}
#endif
}

bool TDGame::ReviveActive()
{
	bool ret = false;
	bool revive_by_ads = false;
	if (!_dialogMng.isOpenDialog() && !_has_revive_in_battle)
	{
		ret = true;
		_has_revive_in_battle = true;
		_auto_hold_key = -1;
		char text[256];
		switch (_user._user_iap_level)
		{
		case CUser::enumiAPLevel::iAP_LEVEL_FREE:
			/*sprintf(text, "%s", "Do you want to revive by Ads?");
			_dialogMng.Add(DIALOG_CONTEXT_REVIVE_BY_ADS, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "REVIVE!", text, 0, 0);*/
			revive_by_ads = true;
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_PREMIUM:
			if (_user.GetGem() > 0)
			{
				
			}
			else
			{
				revive_by_ads = true;
				/*sprintf(text, "%s", "Do you want to revive by Ads?");
				_dialogMng.Add(DIALOG_CONTEXT_REVIVE_BY_ADS, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "REVIVE!", text, 0, 0);*/
			}
			
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_ROYAL:
			if (_user.GetGem() > 0)
			{
				/*sprintf(text, "%s", "Do you want to revive?");
				_dialogMng.Add(DIALOG_CONTEXT_REVIVE_BY_GEM, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "REVIVE!", text, 0, 0);*/
			}
			else
			{
				revive_by_ads = true;
				
			}
			break;
		default:
			break;
		}
		if (revive_by_ads)
		{
#if defined (ANDROID_OS)
			if (!Device::IsNetworkAvailable() || !GAME()->HasVideoAds())
#else
			int adboxtype = PineAdBox::HasVideoAds(true);
			if (!Device::IsNetworkAvailable() || adboxtype < 0)
#endif
			{
				ret = false;
			}
		}
	}
	if (ret)
	{
		char text[256];
		if (!revive_by_ads)
		{
			sprintf(text, "%s", "Do you want to revive?");
			_dialogMng.Add(DIALOG_CONTEXT_REVIVE_BY_GEM, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "REVIVE!", text, 0, 0);
		}
		else
		{
			sprintf(text, "%s", "Do you want to revive by Ads?");
			_dialogMng.Add(DIALOG_CONTEXT_REVIVE_BY_ADS, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "REVIVE!", text, 0, 0);
		}
	}
	return ret;
}

int TDGame::GetUseriAPsLevel()
{
	int ret = CUser::enumiAPLevel::iAP_LEVEL_FREE;
	if (_user._iAPs_numpack_spend < 1)
	{
		ret = CUser::enumiAPLevel::iAP_LEVEL_FREE;
		_user._iap_100_min_trigger = 15;
		_user._iap_100_gem_use_trigger = 100;
		_time_waiting_show_ads = 3*60;
		_time_waiting_free_gift = 5 * 60;
	}
	else if (_user._iAPs_numpack_spend < 5)
	{
		ret = CUser::enumiAPLevel::iAP_LEVEL_PREMIUM;
		_user._iap_100_min_trigger = 20;
		_user._iap_100_gem_use_trigger = 0;
		_time_waiting_show_ads = 5 * 60;
		_time_waiting_free_gift = 8 * 60;
	}
	else
	{
		ret = CUser::enumiAPLevel::iAP_LEVEL_ROYAL;
		_user._iap_100_min_trigger = 50;
		_user._iap_100_gem_use_trigger = 0;
		_time_waiting_show_ads = 10 * 60;
		_time_waiting_free_gift = 10 * 60;
	}
	return ret;
}

void TDGame::GetRelicSpecialDiscount()
{
	int max = 0;
	int index_max = -1;
	for (int i = 0; i < _user._num_heroes_collected; i++)
	{
		if (_user._hero_arr[i]._level > max)
		{
			max = _user._hero_arr[i]._level;
			index_max = i;
		}
	}

}

void TDGame::RelicSpecialActive()
{
	if (!_dialogMng.isOpenDialog())
	{
		char text[256];
		sprintf(text, "%s", "none");
		_dialogMng.Add(DIALOG_CONTEXT_RELIC_SPECIAL, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "NULL", text, 0, 0);
	}
}

void TDGame::UpdateShowRelicSpecial()
{
	if (_user._hero_promo_time_delay > time(NULL) || _battle_current < 20)
	{
		return;
	}
	
	int arr_index[NUM_MAX_HERO];
	int arr_hero_index[NUM_MAX_HERO];
	int count = 0;
	for (int i = 0; i < _num_hero_inbattle; i++)
	{
		int star = _hero_inbattle_arr[i].GetNumStars();
		if (!_hero_inbattle_arr[i]._has_promo && star < 5 && _hero_inbattle_arr[i]._deployed)
		{
			int relicid = -1;
			char str_cmp[64];
			int frameid = 0;
			int cost = 0;
			sprintf(str_cmp, "%d Stars Medal", star+1);
			for (int j = 0; j < _relics_num_of; j++)
			{
				if (_items_relics[j]._group != ITEMRELIC_GROUP_HERO || _items_relics[j]._interactive_id != _hero_inbattle_arr[i].GetHeroID())
				{
					continue;
				}
				if (strcmp(_items_relics[j]._name, str_cmp) == 0 && _items_relics[j]._price <= _user.GetGem())
				{
					/*relicid = _items_relics[j]._id;
					frameid = _items_relics[j]._frameid;
					cost = _items_relics[j]._price;*/
					arr_index[count] = j;
					arr_hero_index[count] = i;
					count++;
					break;
				}
			}
		}
	}
	if (count > 0)
	{
		int index = CMath::RANDOM(0, count - 1);
		_relic_special_id = _items_relics[arr_index[index]]._id;
		_relic_special_frameid = _items_relics[arr_index[index]]._frameid;
		_relic_special_cost = _items_relics[arr_index[index]]._price;
		_relic_special_heroindex = arr_hero_index[index];
		RelicSpecialActive();
	}
}

void TDGame::FirebaseLogIapPack(int iAPtype)
{
	char iAP_id_str[128];
	switch (iAPtype)
	{
	case iAP_TYPE_100:
#if defined (ANDROID_OS)
		switch (_user._user_iap_level)
		{
		case CUser::enumiAPLevel::iAP_LEVEL_FREE:
			sprintf(iAP_id_str, "%s", "nfd_0_99_promo");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_PREMIUM:
			sprintf(iAP_id_str, "%s", "nfd_4_99_promo");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_ROYAL:
			sprintf(iAP_id_str, "%s", "ndf_9_99_promo");
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
			sprintf(iAP_id_str, "%s", "NFD_0.99_PROMO");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_PREMIUM:
			sprintf(iAP_id_str, "%s", "NFD_4.99_PROMO");
			break;
		case CUser::enumiAPLevel::iAP_LEVEL_ROYAL:
			sprintf(iAP_id_str, "%s", "NFD_9.99_PROMO_2");
			break;
		default:
			break;
		}
#endif
		break;
	case iAP_TYPE_BATTLE:
		sprintf(iAP_id_str, "%s", _user._iap_dis_current);
		break;
	default:
		break;
	}
	char title[128];
	char decs[1024];
	sprintf(title, "%s Trigger", iAP_id_str);
	sprintf(decs, "%s Trigger", iAP_id_str);
	char type[128];
	sprintf(type, "%s", "iap_promo_logs");
#if defined (MAC_OS) || (ANDROID_OS)
	PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs, type);
	Device::GA_LogContents(title, decs, type);
#endif
}
