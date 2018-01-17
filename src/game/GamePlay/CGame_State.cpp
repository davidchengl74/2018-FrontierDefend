#include "pch.h"
#include "../GameCore/CGame.h"
#include "../GameCore/Os_Functions.h"
#include <stdio.h>
#include <PineEngine.h>
PE_USING_ENGINE;
extern "C" void ServerADVERTStart();
extern "C" void DataSeverStart();
extern "C" void PurchaseProduct(const char *indentify);
extern "C" bool isChartboostAvailable();
extern "C" bool checkServerRealIsAble();
extern "C" void LoadInAppStore();
extern "C" INT_TIME GetMilisecondOld();
extern "C" INT_TIME GetCurrentMilisecond();

void CGame::OnScreenChange(PineSize size)
{
	///////////////////////////////////////////
	// INIT CONTEXT
	///////////////////////////////////////////

	//define support version
#if defined(_WINDOWS_PHONE8)
	ResVersion support_version[] = {
		{ SupportVersion::RESVER_1280_768, Orientation::Portrait },
		{ SupportVersion::RESVER_800_480, Orientation::Portrait }
	};
	int support_version_num = 2;
#elif defined(_WIN8)
	ResVersion support_version[] = {
		{ SupportVersion::RESVER_1366_768, Orientation::Portrait }
	};
	int support_version_num = 1;
#elif defined(MAC_OS)
	ResVersion support_version[] = {
		//{ SupportVersion::RESVER_960_640, Orientation::Portrait },
		//{ SupportVersion::RESVER_1024_768, Orientation::Portrait },
		//{ SupportVersion::RESVER_1136_640, Orientation::Portrait },
        { SupportVersion::RESVER_1334_750, Orientation::Portrait },
	};
	int support_version_num = 1;
#elif defined(ANDROID_OS)
	ResVersion support_version[] = {
		//{ SupportVersion::RESVER_960_640, Orientation::Portrait },
		//{ SupportVersion::RESVER_1024_768, Orientation::Portrait },
		//{ SupportVersion::RESVER_1136_640, Orientation::Portrait },
		//{ SupportVersion::RESVER_800_480, Orientation::Portrait },
		{SupportVersion::RESVER_1334_750, Orientation::Portrait},
	};
	int support_version_num = 1;
#else //windows
	ResVersion support_version[] = {
		//{ SupportVersion::RESVER_1280_768, Orientation::Landscape_90 },
		//{ SupportVersion::RESVER_800_480, Orientation::Landscape_90 },
		//{ SupportVersion::RESVER_1366_768, Orientation::Landscape_90 },
		//{ SupportVersion::RESVER_960_640, Orientation::Landscape_90 },
		//{ SupportVersion::RESVER_1024_768, Orientation::Landscape_90 },
		//{ SupportVersion::RESVER_1136_640, Orientation::Landscape_90 },
		{ SupportVersion::RESVER_1334_750, Orientation::Portrait },
	};
	int support_version_num = 1;
#endif
    //detect device version
    /*{
        ResVersion device_support_version[] = {
            { SupportVersion::RESVER_960_640, Orientation::Portrait },
            { SupportVersion::RESVER_1024_768, Orientation::Portrait },
           // { SupportVersion::RESVER_1136_640, Orientation::Landscape_90 },
           // { SupportVersion::RESVER_800_480, Orientation::Landscape_90 },
			{ SupportVersion::RESVER_1334_750, Orientation::Portrait },
        };
        PineSize dvsize = { _device.ScreenSize.W, _device.ScreenSize.H };
        _device._version = (GetAppropriateVersion(dvsize, device_support_version, 3)).Version;
    }*/
	/*if (support_version_num > 0){
		PineSize dvsize = { _device.ScreenSize.W, _device.ScreenSize.H };
		ResVersion curr_ver = GetAppropriateVersion(dvsize, support_version, support_version_num);
		Alignment game_align = { HorizontalAlign::Center, VerticalAlign::Middle };
		AlignmentContext(game_align, dvsize, curr_ver, true, _HCENTER);

		switch (curr_ver.Version)
		{
		case SupportVersion::RESVER_1024_768:
			//_current_version = VERSION_768x1024;
			break;
		case SupportVersion::RESVER_1334_750:
			_current_version = VERSION_750x1334;
			break;
		default:
			_current_version = VERSION_750x1334;
			break;
		}
	}*/
	if (support_version_num > 0)
	{
		PineSize dvsize = { _device.ScreenSize.W, _device.ScreenSize.H };
		ResVersion curr_ver = GetAppropriateVersion(dvsize, support_version, support_version_num);
		Alignment game_align = { HorizontalAlign::Center, VerticalAlign::Middle };
		AlignmentContext(game_align, dvsize, curr_ver, true, _HCENTER);
		_current_version = VERSION_750x1334;
	}
    
    //switch (curr_ver.Version)
    //{
    //    /*case SupportVersion::RESVER_1024_768:
    //        _current_version = VERSION_768x1024;
    //        break;*/
    //    case SupportVersion::RESVER_1334_750:
    //        _current_version = VERSION_750x1334;
    //        break;
    //    default:
    //        _current_version = VERSION_750x1334;
    //        break;
    //}

}
int CGame::_frame_to_show_ads_after_interupt = -1;
void CGame::InitEx()
{
#if defined (ANDROID_OS)
	IsAndroidVersion = true;
#else
    IsAndroidVersion = false;
#endif
   _will_show_dialog_ask_save = false;
    _frame_to_show_ads_after_interupt = -1;
	LoadSFX(SFX_ARCHER_ATTACK);
    LoadMusic(BGM_BATTLE_2);
	InitBuff(UNZIP_BUFFER_LENGTH_HIGH);


	_main_game = new TDGame();
	_main_game->Init();
	_main_game->SetState(k_GS_LOGO);
	_main_game->_game_id = APPLE_ID;
	_current_game = _main_game;
	TDGame *game = (TDGame*)GAME()->_current_game;
     game->_system_popup_showed = false;
#if !defined (ANDROID_OS)
	_serverThread._gcSocial = NULL;
#endif
	_server_time.setNullDay();
	_current_time.setDateByLocalDate();
#if defined (MAC_OS)
	DataSeverStart();
#endif
	setUseOptimizeDrawModule(false);
	_musicEnable = true;
	_soundEnable = true;
	_call_submit_score = true;
	_check_syn_save_complete = false;
	_syn_save_step = 0;
	_syn_save_state = SYN_SAVE_NONE;
	_processing_view_type = PROCESSING_VIEW_TYPE_NONE;
	_purchase_procesing_opac = 0;
	_is_purchase_procesing = false;
	game->_is_hacked_time = false;
	game->_rate_us_time = -1;
	//game->_iap_discount_time.setNullDay();
	game->_iap_starter_time.setNullDay();
	game->_wheel_time.setNullDay();
    game->_game_design.General.Load();
	game->_watch_ads_time.setNullDay();
	game->_fairy_double_coin_time.setNullDay();
	game->_starter_double_coin_time.setNullDay();
	game->_rate_us_type = RATE_US_TYPE_NONE;
	game->_invitation_active = false;
	game->_warning_notify_hacker = false;
	game->_daily_reward_active = false;
	game->_local_time_cach = 0;
	game->_victory_active = false;

	game->_iap_dis_cur_timer = 0;
	game->_iap_dis_100_timer = 0;
	game->_iap_dis_autoatt = 0;
	game->_iap_dis_autoskill = 0;
	game->_iap_dis_coin = 0;
	game->_iap_dis_gem = 0;
	sprintf(game->_iap_dis_price, "%d", 0); 
	sprintf(game->_iap_dis_idstr, "NONE");

    //quoc.nguyen
    game->_timeBuyOpenBox.setNullDay();
    game->_countTimeShowVideoAds = 0;
	game->_show_popup_offline = false;
	game->_offline_earning_received = false;
#ifdef MAC_OS
    //LoadInAppStore();
#endif
	for(int i = 0; i<game->_game_design.General.SheetiAP_design.int32Value._totalData;i++)
	{
#if defined (ANDROID_OS)
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::GG_ID;
#else
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_design::ID_Store;
#endif
		char iapPurcharseID[128];
		sprintf(iapPurcharseID, "%s", game->GetDesignIAPString(i, param_iapPurcharse, false));
		if (strcmp(iapPurcharseID,"NONE") != 0)
		{
			_pineStore.AddNewProduct(iapPurcharseID);
		}
	}
    
	for(int i = 0; i<game->_game_design.General.SheetiAP_design_discount.int32Value._totalData;i++)
	{
#if defined (ANDROID_OS)
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_design_discount::GG_ID;
#else
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_design_discount::ID_Store;
#endif
		char iapPurcharseID[128];
		sprintf(iapPurcharseID, "%s", game->_game_design.General.SheetiAP_design_discount.stringValue.getValue(i,param_iapPurcharse));
		if (strcmp(iapPurcharseID, "NONE") != 0)
		{
			_pineStore.AddNewProduct(iapPurcharseID);
		}
	}

	//Lam Update Ver5
	for (int i = 0; i<game->_game_design.General.SheetiAP_instant_design_discount.int32Value._totalData; i++)
	{
#if defined (ANDROID_OS)
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::GG_ID;
#else
		int param_iapPurcharse = CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::ID;
#endif
		char iapPurcharseID[128];
		sprintf(iapPurcharseID, "%s", game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(i, param_iapPurcharse));
		if (strcmp(iapPurcharseID, "NONE") != 0)
		{
			_pineStore.AddNewProduct(iapPurcharseID);
		}
	}

#if defined (ANDROID_OS)
	_pineStore.AddNewProduct("nfd_0_99_promo");
#else
	_pineStore.AddNewProduct("NFD_0.99_PROMO");
#endif


    //quoc.nguyen
#ifdef MAC_OS
    _oldMillisecond = GetMilisecondOld();
    _sys_millisecond = GetCurrentMilisecond()*1000;
    _oldLastTimeFrame = GetMilisecondOld();
    _oldFrameDT = 0;
#endif
    game->_user._tutorial_attack_auto_enable = false;
    game->_user._tutorial_auto_attack_complete = false;
#if !defined (MAC_OS)
	_isBackkeyPress = false;
	_waitForProcessBackkeyCount = 0;
#if defined (ANDROID_OS)
	GAME()->_gameBoardScoreItem.AccountType = PineAccountType::GooglePlay;
	sprintf(GAME()->_gameBoardScoreItem.BoardId, "%s", GP_LEADERBOARD_ID);
#endif
#endif
	is_showing_ads = false;
}

void CGame::ReleaseEx()
{
	
}

void CGame::PauseEx()
{
    printf("\n pause game");
	TDGame *game = (TDGame*)GAME()->_current_game;
    printf("\n 0000 pause _wheel_has_value:%d",game->_wheel_has_value);
    printf("\n _user._num_wheel_spin_premium:%d",game->_user._num_wheel_spin_premium);
    printf("\n _user._num_wheel_spin_free:%d",game->_user._num_wheel_spin_free);
	game->PushNotify();
	if (game->_offline_reward_collected != OFFLINE_RW_COLLECTED_TYPE_WAITING)
	{
        INT_TIME temp = time(NULL);
        if(game->_user._time_offline < temp)
        {
            
            game->_user._time_offline = temp;
            //printf("\n game->_user._time_offline:%lld",game->_user._time_offline);
        }
	}
   
    if(game->_current_state != k_GS_WHEEL)
    {
        TDGame::_auto_wheel = true;
    }
	
	if (game->_user._tutorial_completed && game->_current_state > k_GS_LOGO && game->_current_state != k_GS_MAIN_MENU)
	{
		if (game->_reward_earning_off_type == -1)
		{
			game->_time_out_game = time(NULL);
		}
		game->_user.UserDataSave();
	}
    printf("\n pause _wheel_has_value:%d",game->_wheel_has_value);
    printf("\n _user._num_wheel_spin_premium:%d",game->_user._num_wheel_spin_premium);
    printf("\n _user._num_wheel_spin_free:%d",game->_user._num_wheel_spin_free);
	Sleep(1000);
}
void CGame::ResumeEx()
{
	/*_serverThread._timeDelaySynSaveToServer = 0;
#if defined (MAC_OS)
	_serverThread._isNetworkAvailable = checkServerRealIsAble();
#endif*/
	TDGame *game = (TDGame*)GAME()->_current_game;
	game->_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_WAITING;
	//game->_ingame_menu_type == MENU_INGAME_BUTTON_SHOP;
	//printf("\ngame->_ingame_menu_type = %d, _current_state = %d",game->_ingame_menu_type,game->_current_state);
#if !defined (ANDROID_OS)
	bool Inshop = (game->_ingame_menu_type == MENU_INGAME_BUTTON_SHOP && game->_current_state == k_GS_INGAME_MENU);
	if (!(game->_system_popup_showed || Inshop || game->_has_watched_ads || game->_has_ads_free_gift))
	{
		if (!_is_cancel_show_ads_on_resume)
		{
			CGame::_this->_frame_to_show_ads_after_interupt = 60;
			game->_user._watch_ad_time = time(NULL) + game->_time_waiting_free_gift;
		}
		else
		{
			_is_cancel_show_ads_on_resume = false;
		}
	}


#else
	game->_auto_hold_key = -1;
	bool Inshop = (game->_ingame_menu_type == MENU_INGAME_BUTTON_SHOP && game->_current_state == k_GS_INGAME_MENU);
	if (!(game->_system_popup_showed || Inshop || game->_has_watched_ads || game->_has_ads_free_gift))
	{
		if (!_is_cancel_show_ads_on_resume)
		{
			CGame::_this->_frame_to_show_ads_after_interupt = 60;
			game->_user._watch_ad_time = time(NULL) + game->_time_waiting_free_gift;

		}
		else
		{
			_is_cancel_show_ads_on_resume = false;
		}
	}
	else if (GAME()->_on_show_video_ads)
	{
		GAME()->_on_show_video_ads = false;
	}
	game->ClearAllTouchUp(TOUCH_TYPE_INGAME);
#endif
	if ((game->_current_state > k_GS_LOGO && game->_current_state == k_GS_MAIN_MENU) || !game->_user._tutorial_completed)
	{
		CGame::_this->_frame_to_show_ads_after_interupt = 0;
	}
	game->_system_popup_showed = false;
	bool getoffearning = true;
#if defined (ANDROID_OS)
	//GAME()->FreeAllSFX();
	if (!GAME()->_is_waiting_for_reward)
#else
	if (PineAdBox::showAdState != SHOW_AD_COMPLETED)
#endif
	{
		PDEBUG("On resume set _has_watched_ads = false");
		game->_has_watched_ads = false;
		game->_has_ads_free_gift = false;
        game->_button_free_gift_touch_id = -1;
		
	}
	else
	{
		getoffearning = false;
	}
	INT_TIME time_cur = time(NULL);
	if (game->_user._iap_dis_time > time_cur)
	{
		game->_iap_dis_cur_timer = 60 * (game->_user._iap_dis_time - time_cur);
	}
	else
	{
		game->_iap_dis_cur_timer = 0;
	}
	if (game->_user._iap_dis_100_time > time_cur)
	{
		game->_iap_dis_100_timer = 60 * (game->_user._iap_dis_100_time - time_cur);
	}
	else
	{
		game->_iap_dis_100_timer = 0;
	}
	
	if (time(NULL) - game->_time_out_game >= 30 * 60)
	{
		game->SetState(k_GS_LOGO);
	}
	else
	{
		if (getoffearning)
		{
			game->_count_frame_GetRewardOff = 30;
		}
	}
#if defined (ANDROID_OS)
	GAME()->ClearAllSFX();
#else
    //PDEBUG(" pine ads state: %d -- _has_ads_free_gift:%d -- _has_watched_ads:%d",PineAdBox::showAdState,game->_has_ads_free_gift,game->_has_watched_ads);
	PDEBUG("\n ------------------------reload sound------------------------\n");
    printf("\n _wheel_has_value:%d",game->_wheel_has_value);
    printf("\n _user._num_wheel_spin_premium:%d",game->_user._num_wheel_spin_premium);
    printf("\n _user._num_wheel_spin_free:%d",game->_user._num_wheel_spin_free);
    //GAME()->FreeAllSFX();
    /*for (int i = SFX__SKILL_PALADIN_ATTACK; i <= SFX_POISION_SKILL; i++)
	{
		GAME()->LoadSFX(i);
	}*/
#endif
    
}
bool CGame::OnBackKeyPress(){
	//Implement function when
#if !defined (MAC_OS)
	CGame::_this->_isBackkeyPress = true;
	CGame::_this->_waitForProcessBackkeyCount = 0;
	return true;
#else
	return false;
#endif
}

void CGame::SynDTtimeOldFunction()
{
    INT_TIME cur_millisecond = GetMilisecondOld() - _oldMillisecond;
    _sys_millisecond += cur_millisecond;
    //printf("\n _sys_millisecond = %lld, cur_millisecond = %lld",_sys_millisecond,cur_millisecond);
    _oldMillisecond = GetMilisecondOld();
    
    /////////
    _oldFrameDT = GetMilisecondOld() - _oldLastTimeFrame;
    _oldLastTimeFrame = GetMilisecondOld();
    
#if !defined(_WINDOWS_PHONE8) && !defined(_WIN8) && !defined(ANDROID_OS)
    if(!(_isExit || _isPause))
    {
        if (_oldFrameDT < FPS_DELAY_TIME)
        {
            int sleep = FPS_DELAY_TIME - _oldFrameDT;
            _oldFrameDT += sleep;
            _oldLastTimeFrame += sleep;
        }
    }
#endif
    
    //printf("\n _oldFrameDT = %lld",_oldFrameDT);
}
void CGame::UpdateAndRender()
{
	G()->ClearClip();
	G()->SetOpacity(100);
	if(!LoadGameForceground())
	{
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (CGame::_this->_frame_to_show_ads_after_interupt > 0)
	{
		CGame::_this->_frame_to_show_ads_after_interupt--;
		if (CGame::_this->_frame_to_show_ads_after_interupt == 0)
		{
			//PineAdBox::ShowAdvertFullScreen();
			
#if defined (ANDROID_OS)
			PDEBUG("_on_show_video_ads = %d", _on_show_video_ads);
			if (!_on_show_video_ads && !game->_user._has_remove_ads_pop_up)
			{
				if (game->_current_state != k_GS_PLAYGAME)
				{
					PDEBUG("GAME()->_topebox_game.show_banner_topebox_active = %d", GAME()->_topebox_game.show_banner_topebox_active);
					if (GAME()->_topebox_game.show_banner_topebox_active)
					{
						GAME()->_topebox_game._is_close_ads = false;
						GAME()->_topebox_game.count_show_close_banner_topebox = 0;
						GAME()->_topebox_game.render_banner_topebox = true;
					}
					else
					{
						//if (GAME()->HasVideoSkippableAds())
						{
							//GAME()->ShowSkippableVideoAds();
							GAME()->ShowAds();
							PDEBUG("\n show intertitial");
						}
					}
					
				}
			}
			else
			{
				_on_show_video_ads = false;
			}
#endif
        }
    }
#ifdef MAC_OS
    SynDTtimeOldFunction();
#endif
	_main_game->UpdateAndRender();
#if !defined (MAC_OS)
	if (CGame::_this->_isBackkeyPress)
	{
		if (CGame::_this->_waitForProcessBackkeyCount >= 1)
		{
			CGame::_this->_isBackkeyPress = false;
			CGame::_this->_waitForProcessBackkeyCount = 0;
			OS_Exit(false);
		}
		else
		{
			CGame::_this->_waitForProcessBackkeyCount++;
		}
	}
#if defined (ANDROID_OS)
	UpdateAds();
	_async_task_manager.Run();
#endif
#endif


}



void CGame::UpdateTouch(int xx, int yy, int touch_state, int touch_id, int tap_count)
{
	/*switch (_GameState)
	{
	
	}*/
}



void CGame::PurchaseIAP(const char* iapID, enumIAPResponseStatus status)
{
    TDGame *game = (TDGame*)GAME()->_current_game;
    printf("\n IAP id = %s, success = %d", iapID, status);
    if (status == enumIAPResponseStatus::IAP_RESPONSE_STATUS_SUCCESS )
    {
        bool hasFound = false;
        for (int i = 0; i < game->_game_design.General.SheetiAP_design.stringValue._totalData; i++)
        {
#if defined (ANDROID_OS)
			if (strcmp(game->_game_design.General.SheetiAP_design.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design::enumString::GG_ID), iapID) == 0)
#else
            if (strcmp(game->_game_design.General.SheetiAP_design.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design::enumString::ID_Store), iapID) == 0)
#endif
            {
                //xu li completed
				game->_user._has_remove_ads_pop_up = true;
                game->ShopIAPFuncActive(game->_game_design.General.SheetiAP_design.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design::enumInt32::id),false);
                hasFound = true;
                break;
            }
        }
        
        if (!hasFound)
        {
            for (int i = 0; i < game->_game_design.General.SheetiAP_design_discount.stringValue._totalData; i++)
            {
#if defined (ANDROID_OS)
				if (strcmp(game->_game_design.General.SheetiAP_design_discount.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design_discount::enumString::GG_ID), iapID) == 0)
#else
                if (strcmp(game->_game_design.General.SheetiAP_design_discount.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design_discount::enumString::ID_Store), iapID) == 0)
#endif
                {
                    //xu li completed
					game->_user._has_remove_ads_pop_up = true;
                    game->ShopIAPFuncActive(game->_game_design.General.SheetiAP_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_design::enumInt32::id),true);
                    hasFound = true;
                    break;
                }
            }
        }
		if (strcmp(iapID,game->_user._iap_dis_current)==0)
		{
			if (game->_iap_dis_gem < 100)
			{
				game->_user._iAPs_numpack_spend += 1;
			}
			else if (game->_iap_dis_gem < 250)
			{
				game->_user._iAPs_numpack_spend += 2;
			}
			else if (game->_iap_dis_gem < 600)
			{
				game->_user._iAPs_numpack_spend += 4;
			}
			else
			{
				game->_user._iAPs_numpack_spend += 8;
			}
			game->_user._has_remove_ads_pop_up = true;
			game->_user.AddCoin(game->_iap_dis_coin, true);
			game->_user.AddGem(game->_iap_dis_gem);
			game->_user._auto_attack_free += game->_iap_dis_autoatt;
			game->_user._auto_skill_free += game->_iap_dis_autoskill;
			game->_user._iap_dis_time = time(NULL);
			game->_user._has_bought_iap_dis_cur = true;
			game->_user._num_gem_used = 0;
			game->_iap_dis_cur_timer = 0;
			game->_user.UserDataSave();
			game->GetValueIapDis("NONE");
		}
#if defined (ANDROID_OS)
		if (strcmp(iapID, "nfd_0_99_promo") == 0)
#else
		if (strcmp(iapID, "NFD_0.99_PROMO") == 0)
#endif
		{
			game->_user._iAPs_numpack_spend += 1;
			game->_user._has_remove_ads_pop_up = true;
			game->_user._has_bought_iap_dis_100 = true;
			game->_user._iap_dis_100_time = time(NULL);
			game->_user._iap_dis_100_time_skip_return = time(NULL) + 24 * 60 * 60;
			game->_iap_dis_100_timer = 0;
			game->_user._num_gem_used = 0;
			game->_user.AddGem(game->_iap_dis_gem);
			game->_user.UserDataSave();
			game->GetValueIapDis("NONE");
		}
#if defined (ANDROID_OS)
		if (strcmp(iapID, "nfd_4_99_promo") == 0)
#else
		if (strcmp(iapID, "NFD_4.99_PROMO") == 0)
#endif
		{
			game->_user._iAPs_numpack_spend += 5;
			game->_user._has_remove_ads_pop_up = true;
			game->_user._has_bought_iap_dis_100 = true;
			game->_user._iap_dis_100_time = time(NULL);
			game->_user._iap_dis_100_time_skip_return = time(NULL) + 24 * 60 * 60;
			game->_iap_dis_100_timer = 0;
			game->_user.AddGem(game->_iap_dis_gem);
			game->_user.UserDataSave();
			game->GetValueIapDis("NONE");
		}
#if defined (ANDROID_OS)
		if (strcmp(iapID, "ndf_9_99_promo") == 0)
#else
		if (strcmp(iapID, "NFD_9.99_PROMO_2") == 0)
#endif
		{
			game->_user._iAPs_numpack_spend += 10;
			game->_user._has_remove_ads_pop_up = true;
			game->_user._has_bought_iap_dis_100 = true;
			game->_user._iap_dis_100_time = time(NULL);
			game->_user._iap_dis_100_time_skip_return = time(NULL) + 24 * 60 * 60;
			game->_iap_dis_100_timer = 0;
			game->_user.AddGem(game->_iap_dis_gem);
			game->_user.UserDataSave();
			game->GetValueIapDis("NONE");
		}
#if defined (ANDROID_OS)
		if (strcmp(iapID, "nfd_0_99_premium_wheel") == 0)
#else
		if (strcmp(iapID, "NFD_0.99_PREMIUM_WHEEL_2") == 0)
#endif
		{
			game->_user._iAPs_numpack_spend += 1;
			game->_user._has_remove_ads_pop_up = true;
			game->_user._num_wheel_spin_premium += 3;
			game->_num_wheel_render = game->_user._num_wheel_spin_premium;
			game->_user.UserDataSave();
		}
        if(_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
        {
            _processing_view_type = PROCESSING_VIEW_TYPE_NONE;
        }
        _is_purchase_procesing = false;
		game->_user._user_iap_level = game->GetUseriAPsLevel();
    }
    else if (status == enumIAPResponseStatus::IAP_RESPONSE_STATUS_FAIL)
    {
        if(_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
        {
            _processing_view_type = PROCESSING_VIEW_TYPE_NONE;
        }
        _is_purchase_procesing = false;
    }
    else if (status == enumIAPResponseStatus::IAP_RESPONSE_STATUS_END_RESTORE)
    {
        if(_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
        {
            _processing_view_type = PROCESSING_VIEW_TYPE_NONE;
        }
        _is_purchase_procesing = false;
    }
    else if(status == enumIAPResponseStatus::IAP_RESPONSE_STATUS_SUCCESS_RESTORE)
    {
        if(_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
        {
            _processing_view_type = PROCESSING_VIEW_TYPE_NONE;
        }
        if(!game->_user._has_double_coin)
        {
            game->ReInitShop();
            game->_user._has_double_coin = true;
        }
        PineSocial::ShowMessageBox("Your purchases have been restore!","Thank you for your support");
        _is_purchase_procesing = false;
    }
    else if (status == enumIAPResponseStatus::IAP_RESPONSE_STATUS_FAIL_RESTORE)
    {
        if(_processing_view_type == PROCESSING_VIEW_TYPE_IAP)
        {
            _processing_view_type = PROCESSING_VIEW_TYPE_NONE;
        }
        _is_purchase_procesing = false;
    }
}

void CGame::CheckAndSynSave()
{

}

bool  CGame::UpdateSynSave()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined (MAC_OS)
    if (_syn_save_state)
    {
        _syn_time_out -= DT();
        printf("\n _syn_save_step = %d,_battle_current = %d",_syn_save_step,game->_hight_score);
        switch (_syn_save_step) {
            case 0:
                _syn_time_out = 5000;
                break;
            case 1:
                break;
            case 2:
                if (_syn_time_out < 0)
                {
                    _syn_save_state = SYN_SAVE_NONE;
                }
                else if (GAME()->_serverThread._gcSocial->GetState() != PINESOCIAL_STATE_COMPLETED)
                {
                    _syn_save_step--;
                }
                break;
            case 14:
                _online_score = (int)PineGameCenterController::GetMyScore("TTD_TopScore");
                printf("\n_online_score = %d, high_score = %d", _online_score, game->_hight_score);
                break;
            case 15:
                //new user and submit
                //syn save
                _can_submit = true;
                if(strcmp(game->_user.GetUserID(),"user_id") == 0)
                {
                    char userid[128];
                    GAME()->_serverThread._gcSocial->GetUserIdString(GAME()->_serverThread._gcSocial->GetIdString(), userid);
                    game->_user.SetUserID(userid);
                    char username[128];
                    sprintf(username,"%s", GAME()->_serverThread._gcSocial->GetUserName());
                    game->_user.SetUserName(username);
                    
                }
                else
                {
                    char userid[128];
                    GAME()->_serverThread._gcSocial->GetUserIdString(GAME()->_serverThread._gcSocial->GetIdString(), userid);
                    if(strcmp(game->_user.GetUserID(),userid) != 0)
                    {
                        if(_online_score > game->_battle_current)
                        {
                            //get save server
                            //game->_battle_current = _online_score;
                            //game->_user.UserDataSave();
                            printf("\n has save server");
                            _can_submit = false;
                        }
                    }
                }
                printf("\n id = %s, name = %s", game->_user.GetUserID(), game->_user.GetName());
                //printf("\n _can_submit = %d",_can_submit);
                if(_can_submit)
                {
                    PineGameCenterController::SubmitMyScore("TTD_TopScore", game->_hight_score);
                }
                break;
                
            case 30:
                _syn_save_state = SYN_SAVE_NONE;
                break;
                
                
                
            default:
                break;
        }
        _syn_save_step++;
    }
#else
#endif 
    return _syn_save_state != SYN_SAVE_NONE;
}

#if defined(_WINDOWS)
void CGame::ProcessCommandLine(const char* cmd)
{
}
#endif 

void callback(ECloudKeyValueChangeReason reason, std::vector<std::string> keys)
{
    switch (reason)
    {
        case ECloudKeyValueChangeReason::AccountChange:
            PDEBUG("ICloud Change reason Account Change\n");
            GAME()->_icloud_state = 1;
            break;
        case ECloudKeyValueChangeReason::InitialSyncChange:
            PDEBUG("ICloud Change reason InitialSyncChange\n");
            GAME()->_icloud_state = 2;
            break;
        case ECloudKeyValueChangeReason::QuotaViolationChange:
            PDEBUG("ICloud Change reason QuotaViolationChange\n");
            GAME()->_icloud_state = 3;
            break;
        case ECloudKeyValueChangeReason::ServerChange:
            PDEBUG("ICloud Change reason ServerChange\n");
            GAME()->_icloud_state = 4;
            break;
    }
    
    for (int i = 0; i < keys.size(); i++)
    {
        PDEBUG("key change:%s\n", keys[i].c_str());
    }
}

void CGame::CheckICloud()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined(MAC_OS)
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else
    {
        PDEBUG("icloud success\n");
        //if (_icloud_state == 0) {
        service->synchronize();
        int server_state = CheckCanPushDataSave();
        printf("\nserver_state: %d", server_state);
        
        if (server_state == ICLOUD_STATE_NEW_VERSION) {
            
            //Device::SetAppInstalled("confirm",100);
            if(!Device::HasAppInstalled("confirm",100))
            {
                _will_show_dialog_ask_save = true;
            }
            
            
            
        }
        else if(ICLOUD_STATE_OLD_VERSION == server_state || server_state == ICLOUD_STATE_NODATA)
        {
            GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_SYN_SAVE_TO_SERVER);
        }
    }
    //}
#endif
}

int CGame::CheckCanPushDataSave()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
    int state = -10;
#if defined(MAC_OS)
    
    if (!_device.IsNetworkAvailable())
    {
        state = ICLOUD_STATE_DISCONECT;
    }
    else
    {
        std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
        if (service == nullptr)
        {
            PDEBUG("icloud fail \n");
        }
        else {
            PDEBUG("icloud success\n");
            //if (_icloud_state == 0) {
            service->synchronize();
            std::vector<BYTE> data = service->readBytes("data");
            if (data.size() > 0)
            {
                //if (_icloud_state == 0) {
                service->synchronize();
                std::vector<BYTE> data = service->readBytes("data");
                if (data.size() > 0)
                {
                    char buffer[SAVE_MAX_BUFFER];
                    sprintf(buffer, "");
                    for (int i = 0; i < SAVE_FORMAT_LENGTH; i++)
                    {
                        buffer[i] = data[i];
                    }
                    int battle_cur = GAME()->GetInt32At(buffer, SAVE_FORMAT_BATTLE_CURRENT);
                    
                    int coin_collected = GAME()->GetInt32At(buffer, SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED);
                    printf("\nfrom cloud battle_cur = %d, coin = %d",battle_cur,coin_collected);
                    int ver = (int)GAME()->GetInt64At(buffer, SAVE_FORMAT_CURRENT_VERSION);
                    if (battle_cur < game->_battle_current)
                    {
                        state = ICLOUD_STATE_OLD_VERSION;
                    }
                    else if (battle_cur == game->_battle_current)
                    {
                        if(coin_collected > game->_user._quest_num_coin_collected)
                        {
                            state = ICLOUD_STATE_NEW_VERSION;
                        }
                        else
                        {
                            state = ICLOUD_STATE_READY_SYNS;
                        }
                        
                    }
                    else if (battle_cur > game->_battle_current)
                    {
                        state = ICLOUD_STATE_NEW_VERSION;
                    }
                    
                    if (ver < GAME_CURRENT_VERSION)
                    {
                        state = ICLOUD_STATE_OLD_VERSION;
                    }
                }
                //}
            }
            else
            {
                state = ICLOUD_STATE_NODATA;
            }
            //}
        }
    }
    
#else
    
#endif
    return state;
}

void CGame::ResetValueICloud()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined(MAC_OS)
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else {
        PDEBUG("icloud success\n");
        if (_icloud_state == 0) {
            service->synchronize();
            std::vector<BYTE> data = service->readBytes("data");
            {
                game->_user.UserDefault();
                game->_user.UserDataSave();
                service->write("data", game->_user._buffer, SAVE_FORMAT_LENGTH);
                PDEBUG("\n\nicloud write data success\n\n");
            }
        }
    }
#endif
}

void CGame::SaveToICloud()
{
#if defined(MAC_OS)
    TDGame *game = (TDGame*)GAME()->_current_game;
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else {
        PDEBUG("icloud success\n");
        //if (_icloud_state == 0) {
        service->synchronize();
        int server_state = CheckCanPushDataSave();
        if (server_state == ICLOUD_STATE_READY_SYNS || server_state == ICLOUD_STATE_OLD_VERSION ||
            server_state == ICLOUD_STATE_NODATA)
        {
            game->_user.UserDataSave();
            service->write("data", game->_user._buffer, SAVE_FORMAT_LENGTH);
            PDEBUG("\n\nicloud write data success\n\n");
        }
        
        /*std::vector<BYTE> bytes = { 1,2,3,4,5 };
         
         if (service->write("test", (const char*)bytes.data(), bytes.size()))
         {
         PDEBUG("icloud write data success\n");
         std::vector<BYTE> data = service->readBytes("test");
         
         for (int i = 0; i< data.size(); i++)
         {
         PDEBUG("data: %d %d\n", i, data[i]);
         }
         }
         else {
         PDEBUG("icloud write data fail\n");
         }*/
        //}*/
    }
#endif
}

void CGame::RewriteToICloud()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined(MAC_OS)
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else {
        PDEBUG("icloud success\n");
        game->_user.UserDataSave();
        service->write("data", game->_user._buffer, SAVE_FORMAT_LENGTH);
        PDEBUG("\n\nicloud rewrite data success\n\n");
    }
#endif
}

void CGame::DefaultICloud()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined(MAC_OS)
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else {
        PDEBUG("icloud success\n");
        //if (_icloud_state == 0) {
        service->synchronize();
        std::vector<BYTE> data = service->readBytes("data");
        if (data.size() > 0) {
            PDEBUG("\n\nicloud read data success\n\n");
            for (int i = 0; i < SAVE_FORMAT_LENGTH; i++)
            {
                game->_user._buffer[i] = data[i];
            }
            game->_user.UserDataLoad();
        }
        else
        {
            game->_user.UserDataSave();
            service->write("data", game->_user._buffer, SAVE_FORMAT_LENGTH);
            PDEBUG("\n\nicloud write data success\n\n");
        }
        //}
    }
#endif
}

void CGame::LoadFromICloud()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
#if defined(MAC_OS)
    std::shared_ptr<CCloudKeyValueService> service = CCloud::regKeyValueService(ECloudProvider::AppleICloud, &callback);
    
    if (service == nullptr)
    {
        PDEBUG("icloud fail \n");
    }
    else {
        PDEBUG("icloud success\n");
        //if (_icloud_state == 0) {
        service->synchronize();
        std::vector<BYTE> data = service->readBytes("data");
        if (data.size() > 0) {
            PDEBUG("\n\nicloud read data success\n\n");
            for (int i = 0; i < SAVE_FORMAT_LENGTH; i++)
            {
                game->_user._buffer[i] = data[i];
            }
            game->_user.LoadFromBuffer();
            printf("\n_version_get_from_cloud: %lld", game->_user._version);
        }
        
        /*std::vector<BYTE> bytes = { 1,2,3,4,5 };
         
         if (service->write("test", (const char*)bytes.data(), bytes.size()))
         {
         PDEBUG("icloud write data success\n");
         std::vector<BYTE> data = service->readBytes("test");
         
         for (int i = 0; i< data.size(); i++)
         {
         PDEBUG("data: %d %d\n", i, data[i]);
         }
         }
         else {
         PDEBUG("icloud write data fail\n");
         }*/
        //}
    }
#endif
}


bool CGame::HasAds()
{
#if defined (ANDROID_OS)
	bool has_interstitial = _unity_manager.isAdsReady();
	PDEBUG("\n Call HasInterstitialAds: %s", has_interstitial ? "true" : "false");
	return has_interstitial;
#else
	return false;
#endif
}

bool CGame::HasVideoAds()
{
#if defined (ANDROID_OS)
	bool has_video = _unity_manager.isVideoReady();
	PDEBUG("\n Call HasVideoAds: %s", has_video ? "true" : "false");
	return has_video;
#else
	return false;
#endif
}
bool CGame::HasVideoSkippableAds()
{
#if defined (ANDROID_OS)
	bool has_skip_video = _unity_manager.isVideoSkippalbeReady();
	PDEBUG("\n Call HasSkippableVideoAds: %s", has_skip_video ? "true" : "false");
	return has_skip_video;
#else
	return false;
#endif
}

bool CGame::InitAds()
{
#if defined (ANDROID_OS)
	PDEBUG("INIT ADS");

	//_unity_manager.prepareAds();
	_unity_manager.prepareVideo();
	//_unity_manager.prepareSkippableVideo();

	_on_show_video_ads = false;
	_admob_play_count = 0;
	return true;
#else
	return false;
#endif
}

void CGame::ShowAds()
{
#if defined (ANDROID_OS)
	_can_showads = false;
	_on_show_video_ads = true;
	_is_waiting_for_reward = true;
	_on_video_ads_reward = false;
	/*if (_unity_manager.isAdsReady())
	{
	PDEBUG("\nShow unity interstitial\n");
	_unity_manager.showAds();
	_on_video_ads_reward = true;
	}
	else*/
	{
		PDEBUG("\nShow tapdaq interstitial\n");
		PrepareAndShowInterstitial();
	}
#endif
}

void CGame::ShowVideoAds()
{
#if defined (ANDROID_OS)
	_can_showads = false;
	_on_show_video_ads = true;
	_is_waiting_for_reward = true;
	_on_video_ads_reward = false;
	if (_unity_manager.isVideoReady())
	{
		PDEBUG("\nSHOW Unity VIDEO\n");
		_unity_manager.showVideo();
	}
	else
	{
		PDEBUG("\nSHOW TAPDAQ VIDEO\n");
		PrepareAndShowVideoAds();
	}
#endif
}

void CGame::ShowSkippableVideoAds()
{
#if defined (ANDROID_OS)
	_can_showads = false;
	_on_show_video_ads = true;
	_is_waiting_for_reward = true;
	_on_video_ads_reward = false;
	if (_unity_manager.isVideoSkippalbeReady())
	{
		PDEBUG("\nShow unity skippable video\n");
		_unity_manager.showSkippableVideo();
	}
#endif
}

void CGame::PrepareAndShowVideoAds()
{
#if defined (ANDROID_OS)
	_on_show_video_ads = true;
	_is_waiting_for_reward = true;
	_on_video_ads_reward = false;
	_can_showads = false;
	_tapdaq_manager.prepareRewardedVideo(true);
#endif
}
void CGame::PrepareAndShowInterstitial()
{
#if defined (ANDROID_OS)
	_tapdaq_manager.prepareInterstitial(true);
#endif
}

void CGame::UpdateAds()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
#if defined (ANDROID_OS)
	if (OS_IsNetworkAvailable())
	{
		//Tapdaq
		PineTapdaqAsync::enumTapdaqUpdateResult result = _tapdaq_manager.update();
		switch (result)
		{
		case PineTapdaqAsync::enumTapdaqUpdateResult::SHOW_VIDEO_SUCCESS:
			if (_is_waiting_for_reward)
			{
				PDEBUG("\n Show Tapdaq success");
				_on_video_ads_reward = true;
				_is_waiting_for_reward = false;
			}
			_is_cancel_show_ads_on_resume = false;
			break;
		case PineTapdaqAsync::enumTapdaqUpdateResult::SHOW_ADS_SUCCESS:
		case PineTapdaqAsync::enumTapdaqUpdateResult::SHOW_ADS_FAIL:
		case PineTapdaqAsync::enumTapdaqUpdateResult::PREPARE_ADS_FAIL:
		case PineTapdaqAsync::enumTapdaqUpdateResult::SHOW_VIDEO_FAIL:
		case PineTapdaqAsync::enumTapdaqUpdateResult::PREPARE_VIDEO_FAIL:
			PDEBUG("\n Show Tapdaq false");
			_is_waiting_for_reward = false;
			break;
		default:
			break;
		}

		//Unity
		PineUnityAdsAsync::enumUnityAdsUpdateResult unity_result = _unity_manager.update();
		switch (unity_result)
		{
		case PineUnityAdsAsync::enumUnityAdsUpdateResult::SHOW_VIDEO_SUCCESS:
			if (_is_waiting_for_reward)
			{
				PDEBUG("\n Show unity success");
				_on_video_ads_reward = true;
				_is_waiting_for_reward = false;
				game->_has_watched_ads = true;
			}
			_is_cancel_show_ads_on_resume = false;
			break;
		case PineUnityAdsAsync::enumUnityAdsUpdateResult::SHOW_ADS_SUCCESS:
		case PineUnityAdsAsync::enumUnityAdsUpdateResult::SHOW_ADS_FAIL:
			//case PineUnityAdsAsync::enumUnityAdsUpdateResult::PREPARE_ADS_FAIL:
		case PineUnityAdsAsync::enumUnityAdsUpdateResult::SHOW_VIDEO_FAIL:
			//case PineUnityAdsAsync::enumUnityAdsUpdateResult::PREPARE_VIDEO_FAIL:
			PDEBUG("\n Show unity false");
			_is_waiting_for_reward = false;
			break;
		default:
			break;
		}
	}
	else {
		if (_is_waiting_for_reward)
		{
			_on_video_ads_reward = true;
		}
	}
#endif
}

