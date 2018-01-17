#include "pch.h"
#include "../../GameCore/CGame.h"
#include "../../GameCore/Os_Functions.h"
//extern "C" void InitADManager();
//extern "C" void InitADBanner();
//extern "C" void InitTakePicture();
//extern "C" void takeAPicture();
//extern "C" void LoadImageToPngFile(const char* url,const char *file_name);
extern "C" void AuthTwitter();
extern "C" void CaptureScreenshot();
extern "C" void PostScreenToTwitter();
extern "C" void charboostShowVideoReward(const char* title);
extern "C" void ShowAdmobFullScreen();
extern "C" void OS_InitCaptureViewVideo();
extern "C" void OS_ScreenCaptureVideoStart();
extern "C" void OS_ScreenCaptureVideoStop();
extern "C" int OS_GetCaptureVideoState();
extern "C" void OS_SetCaptureVideoState(int state);
extern "C" void OS_VideoPostSocial(const char* feed);
extern "C" void OS_ShowWebPage(const char* url, bool isOffline);
extern "C" bool checkServerRealIsAble();

#define LOGO_STATE_DEFAULT			0
#define LOGO_STATE_INIT_INFO		1
#define LOGO_STATE_CHECK_NETWORK	2
#define LOGO_STATE_SYNC_SAVE		3
#define LOGO_STATE_LOAD_FROM_SV		4
#define LOGO_STATE_SYNC_TO_SV		5
#define LOGO_STATE_LOAD_RES			50
#define LOGO_STATE_END				100

void TDGame::UpdateLogo()
{
	if (_sub_state == k_INIT)
	{
		_wheel_free_battle_target = 0;
		_wave_current = 1;
		showadtutorial = false;
        CGame::_this->_logo.CreateImageFromPNGinBundle(G(), "pinelogopng");
        CGame::_this->_isNeedOptimize = Device::IsDeviceWeak();
        printf("\n CGame::_this->_isNeedOptimize = %d",CGame::_this->_isNeedOptimize);
        //Device::InitDeviceMotion(k_SCREEN_WIDTH/2,k_SCREEN_HEIGHT/2,k_SCREEN_WIDTH,k_SCREEN_HEIGHT);
		GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_LOADING,true,!CGame::_this->_isNeedOptimize);
		GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_MAINMENU,true,!CGame::_this->_isNeedOptimize);
		GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_SKILL_MAGE,true,!CGame::_this->_isNeedOptimize);
		GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_LOGO,true,!CGame::_this->_isNeedOptimize);
        GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_BATTLE,true,!CGame::_this->_isNeedOptimize);
        //GAME()->LoadSpriteCurrentVer(SPRITEID_HERO_SWORDSMAN_01);
		GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_ABOUT,true,!CGame::_this->_isNeedOptimize);
		GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_LOGO,true,!CGame::_this->_isNeedOptimize);
		GAME()->LoadSpriteCurrentVer(SPRITEID_BG_LOADING);
		GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_COIN_GEM, true, !CGame::_this->_isNeedOptimize);
		for (int i = SPRITEID_HERO_SWORDSMAN_01; i <= SPRITEID_HERO_SANTA_01; i++)
		{
			GAME()->LoadSpriteCurrentVer(i,true,!CGame::_this->_isNeedOptimize);
		}
		for (int i = SPRITEID_EFFECT_SKILL_ARCHER; i <= SPRITEID_EFFECT_SKILL_WOLFGIRL_02; i++)
		{
			GAME()->LoadSpriteCurrentVer(i,true,!CGame::_this->_isNeedOptimize);
		}
		GAME()->LoadSpriteCurrentVer(SPRITEID_MONSTER_ORC_06,true,false);
        GAME()->_anim_loading.SetAnimSprite(GET_SPRITE(SPRITEID_HERO_SWORDSMAN_01), SPRITEID_HERO_SWORDSMAN_01);
        GAME()->_anim_loading.SetAnim(HERO_ANIM_WALK,true);
        GAME()->_anim_loading.SetPos(k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT/3);
		_anim_logo_loading.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_LOGO), SPRITEID_EFFECT_LOGO);
		_anim_logo_loading.SetAnim(0, true);
		_anim_logo_loading.SetPos(0, 0);
		_loading_step = 0;
		_auto_loading = true;
		_game_design.Castle_design.Load();
		_game_design.Enemy_Creation.Load();
		_game_design.Enemy_design.Load();
		
		_game_design.Hero_design.Load();
		_game_design.Skill_design.Load();
		_game_design.background.Load();
		_game_design.Quest.Load();
		_game_design.Relics_design.Load();
		_game_design.SpriteManager.Load();
		_game_design.Treasure.Load();
		_game_design.Pet.Load();
		_num_hero_inbattle = 0;
		_num_tap_in_agame = 0;
		_bg_music_current = -1;
		_bg_music_volum = 100;
		_anim_loading_char1.SetAnimSprite(GET_SPRITE(SPRITEID_HERO_SWORDSMAN_01), SPRITEID_HERO_SWORDSMAN_01);
		_anim_loading_char1.SetAnim(HERO_ANIM_RUN, true);
		_anim_loading_char1.SetPos(0, k_SCREEN_HEIGHT/3 - 30);

		_anim_loading_char2.SetAnimSprite(GET_SPRITE(SPRITEID_MONSTER_ORC_06), SPRITEID_MONSTER_ORC_06);
		_anim_loading_char2.SetAnim(CHARACTER_ANIM_RUN + 8, true);
		_anim_loading_char2.SetPos(0, k_SCREEN_HEIGHT / 3 - 30);
		_anim_loading_char1_x = -250 + _point_o.X;
		_anim_loading_char2_x = -100 + _point_o.X;
		_anim_loading_toleft = false;
		_logo_loading_frame_hold = CMath::RANDOM(5, 100);
		_logo_loading_frame_hold_percent = 5;
		_logo_loading_render_credit_time = CMath::RANDOM(5, 6)*60;
		_logo_loading_credit_x = _screen_width;
		_logo_loading_about_x = 0;
		_relics_num_of = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData 
			+ _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData 
			+ _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData 
			+ _game_design.Relics_design.SheetPet_Relics.int32Value._totalData;
        _offline_reward_collected = false;
		_coin_interface.Init(SPRITEID_FONT_COIN_GEM, 0, 10);
		//_topebox_game.InitGamePromo(0, 0, 96, 96);
		//_topebox_game_scrollEff = 96 * 1.5f;
#if ADD_ADVERT
		/*while(!ADVERT().IsServerProssingComplete())
		{
			
		}
		ADVERT().SetOpen(PINE_ADVERT_SCROLL_TYPE);*/
#endif
		_sub_state = k_LOOP;
        GAME()->_frame_auto_stop = 10000;
        _count_times_showAds = 0;
		
		//topebox ads
		GAME()->_topebox_game.InitGamePromo(0, 0, 64, 64, TopeBox_PromoGame::enumTypeTopeboxAds::TOPEBOX_ADS_BANNER, TopeBox_PromoGame::enumTopeboxAdsPos::TOP_RIGHT);
		GAME()->_topebox_game._topebox_game_scrollEff = 0;
        
	}
	else if (_sub_state == k_LOOP)
	{
		GAME()->_frame_auto_stop -= DT();
		switch (_loading_step)
		{
		case LOGO_STATE_DEFAULT://Init data

			//if(GAME()->_force_start)
		{
			_loading_step = LOGO_STATE_INIT_INFO;
		}

		break;
		case LOGO_STATE_INIT_INFO:
			_castle.Init(1);
			WeaponInit();
			_num_max_quest = GetNumOfGroupQuest();
			_user.UserDataLoad();
			_new_hight_score = false;
#if !defined (ANDROID_OS)           
			GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_INIT_GC);
#endif
			_loading_step = LOGO_STATE_CHECK_NETWORK;

			break;
		case LOGO_STATE_CHECK_NETWORK:
#if defined (MAC_OS)
			if (GAME()->_serverThread.GameCenter.GetState() == PINESOCIAL_STATE_COMPLETED ||
				GAME()->_serverThread.GameCenter.GetState() == PINESOCIAL_STATE_SUCCESS)
			{
				_loading_step = LOGO_STATE_LOAD_RES;
				PineSocial::LoadIAP();
			}
            /*else{
                _loading_step = LOGO_STATE_LOAD_RES;
                PineSocial::LoadIAP();
            }*/
#elif defined (ANDROID_OS)
			GAME()->InitAds();
			_loading_step = LOGO_STATE_LOAD_RES;
#else
			_loading_step = LOGO_STATE_LOAD_RES;
#endif
			break;
		case LOGO_STATE_LOAD_RES:


			break;
		case 51:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SPIN_GOLD, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SPIN_GREEN, true, !CGame::_this->_isNeedOptimize);

			

			break;
		case 52:


			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_WAVE, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_WAVE_WHITE, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_WAVE_YELLOW, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_DIE, true, !CGame::_this->_isNeedOptimize);
			break;
		case 53:

			break;
		case 54:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_CRITICALDAME, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_HITDAME, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_HITDAME_CASTLE, true, !CGame::_this->_isNeedOptimize);
			break;
		case 55:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_ATK, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SKILL, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SHOPCOIN, true, !CGame::_this->_isNeedOptimize);
			break;
		case 56:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_HERONAME, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_LEVELUP, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SHOPCOINRED, true, !CGame::_this->_isNeedOptimize);
			break;
		case 57:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_HUD, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_IAP, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_HIT, true, !CGame::_this->_isNeedOptimize);
			//GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_SKILL_SWORDMAN_02);
			break;
		case 58:
			for (int i = SFX__SKILL_PALADIN_ATTACK; i <= SFX_POISION_SKILL; i++)
			{
				GAME()->LoadSFX(i);
			}
			break;
		case 59:
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_ITEM, false, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_RATEUS);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_CROWN_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_DAILY_REWARD);
			break;
		case 60:
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_CHESTS, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_CHESTS_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_EFFECT_CHEST_01, true, !CGame::_this->_isNeedOptimize);
			break;
		case 61:
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_GEMSHOP, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_SELECT_YOUR_REWARDS);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_PLUS_DAME);
			break;
		case 62:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FAIRY_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_TUTORIAL, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_TUTORIAL_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_TUTORIAL, true, !CGame::_this->_isNeedOptimize);
			break;
		case 63:
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_QUEST_ICON, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_LUCKY_WHEEL_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_SPLASH_SCREEN_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_LUCKY_WHEEL, true, false);
			break;
		case 64:
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_DEFEAT_CASTLE_02, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_LEVELUP_CASTLE_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_DEFEAT_CASTLE_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_DISCOUNT, true, !CGame::_this->_isNeedOptimize);
			break;
		case 65:
			GAME()->LoadSpriteCurrentVer(SPRITEID_ICON_RELIC, true, true);
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_VICTORY_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_RELIC, true, !CGame::_this->_isNeedOptimize);
			break;
		case 66:
			GAME()->LoadSpriteCurrentVer(SPRITEID_EFFECT_STUN_01, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_PROMO_PINEGAME, true, !CGame::_this->_isNeedOptimize);
			CGame::_this->_red_warning.CreateImageFromPNGinBundle(G(), "redcornerpng");
			break;
		case 72:
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_DATA_MENU_PRESTIGE, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_LV_GOD_BLESSED_I6, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_PRESTIGE_NUMBER_I6, true, !CGame::_this->_isNeedOptimize);
			break;
		case 73:
			GAME()->LoadSpriteCurrentVer(SPRITEID_FONT_TOPEBOX_ADS, true, !CGame::_this->_isNeedOptimize);
			GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_TOPEBOX_ADS, true, !CGame::_this->_isNeedOptimize);
			break;
		
		case 89:
#if defined (ANDROID_OS)
			if (!GAME()->_async_task_manager._on_process_sync_cloud)
			{
				_user.CheckLocalAndCloudSaveFile(true);
			}
			_loading_step++;
#endif
			break;

		case 94:
#if defined (ANDROID_OS)
			GAME()->_topebox_game.GetTopeboxAdsInfoRemoteConfig();
#endif
			break;
		case 95:
#if defined (ANDROID_OS)
			if (GAME()->is_config_downloaded)
			{
				_auto_loading = true;
				PDEBUG("\n configDownloaded:%d", GAME()->is_config_downloaded);
				_loading_step = 96;
					}
			else
			{
				_auto_loading = false;
			}
#endif
			break;
		case 99:
		{
				   int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
				   int count_hero = _user._num_heroes_collected;
				   for (int i = 0; i < totalhero; i++)
				   {
					   int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
					   int heroid = GetDesignHeroGeneral(i, paramid);
					   if (!_user.CheckHeroColleted(heroid))
					   {
						   _hero_inbattle_arr[count_hero].Init(heroid, 1, false, true,false);
						   count_hero++;
					   }
				   }
				   RelicsDefault();
		}
			break;
		default:
			break;
		}
		if (_auto_loading)
		{
			if (_loading_step >= LOGO_STATE_LOAD_RES && _loading_step< 70)
            {
                _loading_step++;
            }
			if (_loading_step >= 70)
			{
				_logo_loading_frame_hold--;
				if (_logo_loading_frame_hold <= 0)
				{
					_loading_step++;
					int rand = CMath::RANDOM(1, 100);
					if (rand <= _logo_loading_frame_hold_percent)
					{
						_logo_loading_frame_hold = CMath::RANDOM(5, 25) * 6;
						_logo_loading_frame_hold_percent = 0;
					}
					else
					{
						_logo_loading_frame_hold_percent += 5;
						_logo_loading_frame_hold = 0;
					}
				}
			}
          
			if(_loading_step >= 100)
			{
				_need_log_freegift = false;
				_need_log_mass_click = false;
				_need_log_daily_reward = false;
				_need_log_double_chest = false;
				_user._user_iap_level = GetUseriAPsLevel();
				_wheel_free_battle_target = ((_battle_current / 5) * 5) + 5;
				//_user._num_mass_auto_free = 1;
				GetRewardEarnOffline();
				_just_lose = false;
				SetState(k_GS_MAIN_MENU);

#if defined(_WINDOWS)
				if (_user._tutorial_completed)
				{
					//_battle_current = 199;
					
					_user.AddCoin(100000000000, true);
					_user.AddGem(10000);
					/*_user._user_level_reset = 0;
					_user._num_mass_auto_free = 1;
					_user._num_wheel_spin_premium = 1;*/
				}
#endif
				//_user._has_show_pine_promo = true;
				_tutorial_buy_relic_ready = false;
				/*_topebox_game.SetDeviceID(_user._game_promo_deviceID);
				PDEBUG("\n tmcur:%lld --- user_time:%lld", time(NULL), _user._game_promo_delay_show);
				if (time(NULL) - _user._game_promo_delay_show >= 0)
				{
					_topebox_game.GetTopeboxPromoGameInfo(_user._game_promo_revision, _user._game_promo_order);
				}*/
			}
		}
#if ADD_ADVERT
#if defined (MAC_OS)
		/*if(!ADVERT().UpdateADVERT())
		{
		}*/
#endif
#endif
		
	}
	else if (_sub_state == k_DESTROY)
	{
	}
}

void TDGame::RenderLogo()
{
	G()->SetScale(GAME()->_game_context.ScaleOut, GAME()->_game_context.ScaleOut, k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
	GET_SPRITE(SPRITEID_BG_LOADING)->DrawFrame(G(), 0, 0, 0);
	G()->ClearScale();
#if defined (ANDROID_OS)
	GET_SPRITE(SPRITEID_EFFECT_LOGO)->DrawFrame(G(), 0, k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT *0.66f - 75);
#else
	CGame::_this->_logo.DrawImageWithRect(G(), k_SCREEN_WIDTH / 2 - CGame::_this->_logo.GetWidth() / 2, 2 * k_SCREEN_HEIGHT / 3 - 75 - CGame::_this->_logo.GetHeight() / 2);
#endif
     
	
	if (!_anim_loading_toleft)
	{
		_anim_loading_char1_x += 10;
		_anim_loading_char2_x += 10;
		if (_anim_loading_char1_x >= _screen_width + 150)
		{
			_anim_loading_toleft = true;
			_anim_loading_char1.SetAnim(HERO_ANIM_RUN + HERO_ANIM_NUM_MAX, true);
			_anim_loading_char2.SetAnim(CHARACTER_ANIM_RUN, true);
		}
	}
	else
	{
		_anim_loading_char1_x -= 10;
		_anim_loading_char2_x -= 10;
		if (_anim_loading_char2_x < _point_o.X - 150)
		{
			_anim_loading_toleft = false;
			_anim_loading_char1.SetAnim(HERO_ANIM_RUN , true);
			_anim_loading_char2.SetAnim(CHARACTER_ANIM_RUN + 8, true);
		}
	}
	_anim_loading_char1.SetPos(_anim_loading_char1_x, k_SCREEN_HEIGHT / 2 + 38);
	_anim_loading_char1.DrawAnimObject(G());
	_anim_loading_char1.UpdateAnimObject();

	_anim_loading_char2.SetPos(_anim_loading_char2_x, k_SCREEN_HEIGHT / 2 + 38);
	_anim_loading_char2.DrawAnimObject(G());
	_anim_loading_char2.UpdateAnimObject();

	//_anim_logo_loading.SetPos(k_SCREEN_WIDTH / 2, 2 * k_SCREEN_HEIGHT / 3 - 75);
	//_anim_logo_loading.DrawAnimObject(G());
	//_anim_logo_loading.UpdateAnimObject();
	GET_SPRITE(SPRITEID_FONT_LOADING)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2, 2 * k_SCREEN_HEIGHT / 3 + 5, _HCENTER, "/", _loading_step);
	GET_SPRITE(SPRITEID_FONT_LOADING)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2, 2 * k_SCREEN_HEIGHT / 3 + 30, _HCENTER, "%d%%", _loading_step*100/100);
    
	if (_logo_loading_render_credit_time > 0)
	{
		_logo_loading_render_credit_time--;
	}
	if (_logo_loading_render_credit_time <= 0)
	{
		_logo_loading_render_credit_time = 0;
		_logo_loading_about_x -= 20;
		_logo_loading_credit_x -= 20;
		if (_logo_loading_about_x <= -_screen_width)
		{
			_logo_loading_about_x = _screen_width;
			_logo_loading_credit_x = 0;
			_logo_loading_render_credit_time = CMath::RANDOM(5, 6) * 60;
		}
		if (_logo_loading_credit_x <= -_screen_width)
		{
			_logo_loading_credit_x = _screen_width;
			_logo_loading_about_x = 0;
			_logo_loading_render_credit_time = CMath::RANDOM(5, 6) * 60;
		}
	}
    
    GET_SPRITE(SPRITEID_HUD_ABOUT)->DrawFrame(G(), 2, k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT*3/4);
	GET_SPRITE(SPRITEID_HUD_ABOUT)->DrawFrame(G(), 0, _logo_loading_about_x+k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT*3/4+k_SCREEN_HEIGHT/8);
	GET_SPRITE(SPRITEID_HUD_ABOUT)->DrawFrame(G(), 1, _logo_loading_credit_x+k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT*3/4+k_SCREEN_HEIGHT/8);
     
}

void CGame::UnloadGameBackground()
{
	//printf("\nUnload Game Back ground");
	if(!_compete_backup_stock)
	{
		_step_force_loading = 0;
		BackupAnimStock();
		for(int i = 0; i < TOTAL_SPRITE_INGAME; i++)
		{
			if(_sprite_loaded[i])
			{
				//printf("\nUnload SpriteID = %d",i);
				UnloadSpriteVer(i);
				_sprite_loaded[i] = 1;
			}
		}
		_compete_backup_stock = true;
		printf("\nUnload background");
	}
	
}
bool CGame::LoadGameForceground()
{
   
	if(_step_force_loading >= TOTAL_SPRITE_INGAME+10)
	{
		return true;
	}
	
	_compete_backup_stock = false;
	//printf("\nloading force ground = %d",_step_force_loading);
	//G()->SetColor(0);
	//G()->FillRect(0,0,k_SCREEN_WIDTH,k_SCREEN_HEIGHT);
	

	if(_step_force_loading >= 10)
	{
		for(int i = 0; i < 100; i++)
		{
			
			if(_sprite_loaded[_step_force_loading-10])
			{
				//printf("\n_step_force_loading-10 = %d",(_step_force_loading-10));
				LoadSpriteCurrentVer(_step_force_loading-10,_sprite_antialias_loaded[_step_force_loading-10],_sprite_optimized_loaded[_step_force_loading-10]);
			}
			_step_force_loading++;
			if(_step_force_loading >= TOTAL_SPRITE_INGAME+10)
			{
				RestoreAnimStock();
				
				return true;
			}
			
		}
	}
	else
	{
		_step_force_loading++;
	}
	return false;
}

