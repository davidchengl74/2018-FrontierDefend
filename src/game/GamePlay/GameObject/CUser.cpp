#include "pch.h"
#include "../../GameCore/CGame.h"
#include "../../GameCore/Os_Functions.h"

CUser::CUser()
{
}

CUser::~CUser()
{
}

void CUser::UserDefault()
{
	_version = GAME_CURRENT_VERSION;
	Init();
}
void CUser::UserDataSave()
{
	SaveToBuffer();

#if defined(MAC_OS) || defined(ANDROID_OS)
	OS_SaveAppData(SAVE_FILE_NAME, _buffer, MAX_SAVE_BUFFER_CACHE, false);
#else

	FILE * stream = NULL;

	stream = fopen(SAVE_FILE_NAME, "wb");

	if (stream != NULL)
	{
		fwrite((void *)_buffer, sizeof(BYTE), MAX_SAVE_BUFFER_CACHE, stream);
	}

	if (stream != NULL)
	{
		fclose(stream);
	}
#endif
}
void CUser::UserDataLoad()
{
	int saved = 0;
	Buffer* buff = OS_LoadAppData(SAVE_FILE_NAME);
	if (buff != NULL)
	{
		saved = buff->Length();
		memcpy(_buffer, buff->Data(), saved);
		delete buff;
	}
    printf("Load data saved = %d",saved);
	if (saved == 0)
	{
		UserDefault();
		UserDataSave();
	}
	else
	{
		LoadFromBuffer();
		if (_version < SAVE_CURRENT_VERSION)
		{
			//xu ly syn server
			UserDataSave();
		}
	}
}

void CUser::Init()
{
    printf("\n User Data Default");
	TDGame *game = (TDGame*)GAME()->_current_game;
	sprintf(_user_id, "%s", "user_id");
	sprintf(_name, "%s", "User Name");
	game->_battle_current = 0;
	AddCoin(game->GetDesignGeneralInfo(DESIGN_GENERAL_COIN_START), true);
	AddGem(game->GetDesignGeneralInfo(DESIGN_GENERAL_GEM_START));
	InitHeroes();
    game->HeroesReset();
	int count_hero_init = 0;
	game->_hero_inbattle_arr[count_hero_init].Init(game->GetDesignHeroGeneral(count_hero_init, CGameDesign::FileHero_design::CSheetHero_General::ID_Hero), 1, true, false,false);
	_hero_arr[count_hero_init]._slot_deploy_number = count_hero_init;
	count_hero_init++;
	for (int i = 0; i < NUM_MAX_QUEST_GROUP; i++)
	{
		for (int j = 0; j < NUM_MAX_QUEST_IN_GROUP; j++)
		{
			_quest_completed[i][j] = false;
			_quest_current[i] = 0;
		}
	}
	
	game->QuestReset();
	_quest_battle_passed = 0;
	_quest_num_battle_in_day = 0;
	_quest_num_coin_collected = 0;
	_quest_num_critical_hit = 0;
	_quest_num_enemy_bekill_weapon = 0;
	_quest_num_kill_monster = 0;
	_quest_num_relics_own = 0;
	_quest_num_tap = 0;
	_quest_num_upgrade_heroes = 0;
	_quest_num_upgrade_weapons = 0;
	_quest_num_use_skill = 0;
	_tutorial_completed = false;
	_tutorial_step = TUTORIAL_STEP_WELCOME;
	game->_battle_loop_from = 0;
	_quest_num_tap_in_second = 0;
	_quest_num_kill_monster_in_second = 0;
	_quest_num_kill_boss = 0;
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		_item_relics[i]._group = -1;
		_item_relics[i]._id = -1;
	}
	
	game->RelicsReset();
    game->_castle.Init(1);
    game->WeaponInit();
	_auto_attack_free = 0;
	_auto_skill_free = 0;
	_has_double_coin = false;
	_fairy_times_init = 0;
	_is_hack = false;
	game->_daily_quest_current = 0;
	DailyQuestInit();
	//DailyQuestReset();
	_iap_discount_time_reset = time(NULL);
	_iap_starter_time_reset = time(NULL) + IAP_STARTER_TIME;
	IapDiscountReset();
	_wheel_time_reset = time(NULL);
	_wheel_lucky = 0;
	_has_rated_us_type = RATE_US_TYPE_NONE;
	_rate_trigger = RATE_US_TRIGGER_1;
	_watch_ad_time = time(NULL);
	_watch_ad_times = 0;
	_has_follow_tw = false;
	_has_liked_fb = false;
	_iap_starter_double_coin_time = 0;
	_gem_collected = 0;
	_play_times_retry = 0;
	_num_use_auto_attack = 0;
	_has_completed_battle_max = false;
	sprintf(_ivitation_code, "%s", "NULL");
	_invitation_num = 0;
	_has_pass_invitation = false;
	_invitation_reward_current = 0;
	_download_moregame_trigger = time(NULL);
    _stateAppDownload = 0;
	//Update Ver12/2015
	_num_get_free_wheel = 0;
	_time_offline = time(NULL);
	_user_revision = 0;
	_is_notify = false;
	_daily_reward_day = -1;
	_daily_reward_num = 0;
    game->_play_game_num = 1;
    
    //quoc.nguyen update ver13 date: 13/10/2016
    _timeBuyOpenBox = time(NULL);

	//Lam Update ver5
	printf(_iap_dis_current, "%s", "NULL");
	_iap_dis_time = time(NULL);
	_iap_dis_100_time = time(NULL);
	_num_gem_used = 0;
	_has_bought_iap_dis_100 = false;
	_has_bought_iap_dis_cur = false;
	_has_remove_ads_pop_up = false;
	_has_show_pine_promo = true;
	_iap_dis_cur_trigger = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(0, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
	game->_time_out_game = -1;
	sprintf(_game_promo_icon_id, "%s", "gameID");
	sprintf(_game_promo_link_store, "%s", "linkStore");
	_user_level_reset = 0;
	_user_battle_just_reset = 0;
	_sync_version = 0;
	sprintf(_game_promo_deviceID, "%s", "deviceID");
	_game_promo_revision = 0;
	_iAPs_numpack_spend = 0;
	_user_iap_level = 0;
	_iap_dis_100_time_skip_return = time(NULL);
	_iap_100_gem_use_trigger = 100;
	_iap_100_min_trigger = 15;
	_hero_promo_time_delay = time(NULL);
	_num_mass_auto_free = MASS_AUTO_FOR_NEW;
	_num_wheel_spin_free = 0;
	_num_wheel_spin_premium = 0;
	_game_promo_delay_show = time(NULL);
	_game_promo_order = 0;
	_is_new_user_ver15 = true;

	//Kha update promo
	sprintf(_game_promo_icon_id, "%s", "gameID");
	sprintf(_game_promo_link_store, "%s", "linkStore");
	sprintf(_game_promo_deviceID, "%s", "deviceID");
	_game_promo_revision = 0;
	_game_promo_has_show = true;
	_game_promo_delay_show = time(NULL);
	_game_promo_order = 0;
	_has_touch_promo = false;
}

void CUser::SaveToBuffer()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_CURRENT_VERSION, _version);
	for (int i = 0; i < 128; i++)
	{
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_USER_NAME + i, _name[i]);
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_USER_ID + i, _user_id[i]);
	}

	GAME()->SetInt64At(_buffer, SAVE_FORMAT_COIN, _coin);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_GEM, _gem);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_BATTLE_CURRENT, game->_battle_current);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_CASTLE_LEVEL, game->_castle.GetLevel());
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_NUM_HEROES_COLLECTED, _num_heroes_collected);
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		
		int level = game->_weapon[i].GetLevel();
		if (game->_weapon[i].IsLock())
		{
			level = 0;
		}
		//printf("\n game->_weapon[%d].GetLevel() = %d", i, level);
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_WEAPON_LEVEL + i * 2, level);
	}
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		int heroid = -1;
		int level = 0;
		bool deployed = false;
		int slot = -1;
		int rar_level = 0;
		bool has_promo = false;
		heroid = _hero_arr[i]._heroid;
		if (heroid > 0)
		{
			level = _hero_arr[i]._level;
			deployed = _hero_arr[i]._is_deployed;
			slot = _hero_arr[i]._slot_deploy_number;
			rar_level = _hero_arr[i]._rarity_level;
			has_promo = _hero_arr[i]._has_promo;
		}
		else
		{
			heroid = -1;
		}

		GAME()->SetInt16At(_buffer, SAVE_FORMAT_HERO_ID + i * 2, heroid);
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_HERO_LEVEL + i * 2, level);
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_HERO_SLOT_NUMBER + i * 2, slot);
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_HERO_DEPLOYED + i, deployed);
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_GAME_HERO_RARITY_LEVEL + i*2, rar_level);
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_HERO_HAS_PROMO + i, has_promo);
	}
	for (int i = 0; i < NUM_MAX_QUEST_GROUP; i++)
	{
		for (int j = 0; j < NUM_MAX_QUEST_IN_GROUP; j++)
		{
			GAME()->SetByteAt(_buffer, SAVE_FORMAT_QUEST_COMPLETED + i*NUM_MAX_QUEST_IN_GROUP*1 + j, _quest_completed[i][j]);
		}
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_QUEST_CURRENT + i*2, _quest_current[i]);
	}
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_BATTLE_INDAY, _quest_num_battle_in_day);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_BATTLE_PASSED, _quest_battle_passed);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED, _quest_num_coin_collected);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_CRITICAL_HIT, _quest_num_critical_hit);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_ENEMY_BEKILL_WP, _quest_num_enemy_bekill_weapon);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_MONSTER, _quest_num_kill_monster);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_RELICS_OWN, _quest_num_relics_own);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_TAP, _quest_num_tap);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_UPGRADE_HEROES, _quest_num_upgrade_heroes);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_UPGRADE_WEAPONS, _quest_num_upgrade_weapons);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_USE_SKILL, _quest_num_use_skill);
	if (_tutorial_step < TUTORIAL_STEP_MENU_CASTLE)
	{
		_tutorial_step = TUTORIAL_STEP_WELCOME;
	}
	PDEBUG("\n save _tutorial_step:%d", _tutorial_step);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_TUTORIAL_STEP, _tutorial_step);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_TUTORIAL_COMPLETED , _tutorial_completed);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_BATTLE_LOOP_FROM, game->_battle_loop_from);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_QUEST_NUM_TAP_IN_SECOND, _quest_num_tap_in_second);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_MONSTER_IN_SECOND, _quest_num_kill_monster_in_second);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_BOSS, _quest_num_kill_boss);
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_ITEM_RELIC_GROUP + i * 2, _item_relics[i]._group);
		GAME()->SetInt16At(_buffer, SAVE_FORMAT_ITEM_RELIC_ID + i * 2, _item_relics[i]._id);
	}
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_AUTO_ATTACK_FREE, _auto_attack_free);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_AUTO_SKILL_FREE, _auto_skill_free);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_DOUBLE_COIN, _has_double_coin);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_FAIRY_TIMES_INIT, _fairy_times_init);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_SOUND_ENABLE, GAME()->_soundEnable);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_MUSIC_ENABLE, GAME()->_musicEnable);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_DAILY_QUEST_COMPLETED, _daily_quest_completed);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_DAILY_QUEST_NUM, _daily_quest_num);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_DAILY_QUEST_GROUP_CURRENT, _daily_quest_group_current);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_DAILY_QUEST_TIME_RESET, _time_reset_daily_quest);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_IS_HACK, _is_hack);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_TIME_CHECK_HACK, _time_check_hack);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TIME_RESET, _iap_discount_time_reset);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_IAP_STARTER_TIME_RESET, _iap_starter_time_reset);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TRIGER, _iap_triger_discount);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_WHEEL_TIME_RESET, _wheel_time_reset);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_WHEEL_LUCKY, _wheel_lucky);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_HAS_RATED_TYPE, _has_rated_us_type);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_TRIGGER_RATE, _rate_trigger);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_WATCH_AD_TIME, _watch_ad_time);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_WATCH_AD_TIMES, _watch_ad_times);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_DAILY_QUEST_CURRENT, game->_daily_quest_current);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_FOLLOW_TW, _has_follow_tw);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_LIKE_FB, _has_liked_fb);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_STARTER_DB_COIN_TIME, _iap_starter_double_coin_time);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_GEM_COLLECTED, _gem_collected);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_PLAY_TIMES, _play_times_retry);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_NUM_USE_AUTO_ATT, _num_use_auto_attack);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_COMPLETED_ALL_BATTLE, _has_completed_battle_max);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_INVITATION_PASS, _has_pass_invitation);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_INVITATION_NUM, _invitation_num);
	for (int i = 0; i < 24; i++)
	{
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_INVITATION_CODE + i, _ivitation_code[i]);
	}
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_INVITATION_REWARD_CURRENT, _invitation_reward_current);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_DOWNLOAD_MOREGAME_TRIGGER, _download_moregame_trigger);
    GAME()->SetInt16At(_buffer, SAVE_FORMAT_DOWNLOAD_MOREGAME_STATE,_stateAppDownload);
	//Update Ver12/2015
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_GET_FREE_WHEEL, _num_get_free_wheel);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_TIME_OFFLINE, _time_offline);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_USER_REVISION, _user_revision);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_IS_NOTIFY, _is_notify);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_DAILY_REWARD_NUM, _daily_reward_num);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_DAILY_REWARD_DAY, _daily_reward_day);
    GAME()->SetInt16At(_buffer, SAVE_FORMAT_PLAY_GAME_NUM, game->_play_game_num);
    
    //quoc.nguyen update ver13 date: 13/10/2016
    GAME()->SetInt64At(_buffer, SAVE_FORMAT_TIME_BUY_OPEN_BOX, _timeBuyOpenBox);

	//Lam Update ver5
	for (int i = 0; i < 64; i++)
	{
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_IAP_DISCOUNT_CURRENT + i, _iap_dis_current[i]);
	}
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TIME, _iap_dis_time);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_100_TIME, _iap_dis_100_time);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_COUNT_GEM_USED, _num_gem_used);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_BOUGHT_IAP_100, _has_bought_iap_dis_100);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_BOUGHT_IAP_DIS, _has_bought_iap_dis_cur);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_IAP_DIS_CUR_TRIGGER, _iap_dis_cur_trigger);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_REMOVE_ADS_POPUP, _has_remove_ads_pop_up);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_HAS_SHOW_PINE_PROMO, _has_show_pine_promo);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_TIME_OUT_GAME, game->_time_out_game);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_WAVE_CURRENT, game->_wave_current);
	/*for (int i = 0; i < 128; i++)
	{
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_GAME_PROMO_ICON_ID + i, _game_promo_icon_id[i]);
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_GAME_LINK_STORE + i, _game_promo_link_store[i]);
		GAME()->SetByteAt(_buffer, SAVE_FORMAT_GAME_DEVICEID + i, _game_promo_deviceID[i]);
	}*/
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_GAME_USER_LEVEL_RESET, _user_level_reset);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_GAME_USER_BATTLE_JUST_RESET, _user_battle_just_reset);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_GAME_SYNC_VERSION, _sync_version);
	//GAME()->SetInt32At(_buffer, SAVE_FORMAT_GAME_PROMO_REVISION, _game_promo_revision);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_IAP_NUMPACK_SPEND, _iAPs_numpack_spend);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_IAP_100_TIME_RETURN, _iap_dis_100_time_skip_return);
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_HERO_PROMO_TIME_DELAY, _hero_promo_time_delay);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_NUM_MASS_AUTO_FREE, _num_mass_auto_free);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_NUM_WHEEL_SPIN_FREE, _num_wheel_spin_free);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_NUM_WHEEL_SPIN_PREMIUM, _num_wheel_spin_premium);
	//GAME()->SetInt64At(_buffer, SAVE_FORMAT_GAME_PROMO_DELAYTIME, _game_promo_delay_show);
	//GAME()->SetInt16At(_buffer, SAVE_FORMAT_GAME_PROMO_ORDER, _game_promo_order);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_GAME_IS_NEW_USER_VER15, _is_new_user_ver15);

	//Kha update promo
	for (int i = 0; i<128; i++)
	{
		_game_promo_deviceID[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_DEVICEID + i);
		_game_promo_icon_id[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_PROMO_ICON_ID + i);
		_game_promo_link_store[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_LINK_STORE + i);
	}
	GAME()->SetInt64At(_buffer, SAVE_FORMAT_GAME_PROMO_DELAYTIME, _game_promo_delay_show);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_USER_GAME_PROMO_HAS_SHOW, _game_promo_has_show);
	GAME()->SetInt16At(_buffer, SAVE_FORMAT_GAME_PROMO_ORDER, _game_promo_order);
	GAME()->SetInt32At(_buffer, SAVE_FORMAT_GAME_PROMO_REVISION, _game_promo_revision);
	GAME()->SetByteAt(_buffer, SAVE_FORMAT_USER_HAS_TOUCH_PROMO, _has_touch_promo);
}

void CUser::LoadFromBuffer()
{
	
	TDGame *game = (TDGame*)GAME()->_current_game;
	_quest_num_relics_own = 0;
	_user_iap_level = 0;
	_version = GAME()->GetInt64At(_buffer, SAVE_FORMAT_CURRENT_VERSION);
	for (int i = 0; i < 128; i++)
	{
		_name[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_USER_NAME + i);
		_user_id[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_USER_ID + i);
	}
	_coin = GAME()->GetInt64At(_buffer, SAVE_FORMAT_COIN);
	_gem = GAME()->GetInt32At(_buffer, SAVE_FORMAT_GEM);
	_num_heroes_collected = GAME()->GetInt16At(_buffer, SAVE_FORMAT_NUM_HEROES_COLLECTED);
	game->_battle_current = GAME()->GetInt32At(_buffer, SAVE_FORMAT_BATTLE_CURRENT);
	game->_castle.SetLevel(GAME()->GetInt16At(_buffer, SAVE_FORMAT_CASTLE_LEVEL));
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		_item_relics[i]._group = GAME()->GetInt16At(_buffer, SAVE_FORMAT_ITEM_RELIC_GROUP + i * 2);
		_item_relics[i]._id = GAME()->GetInt16At(_buffer, SAVE_FORMAT_ITEM_RELIC_ID + i * 2);
		if (_item_relics[i]._id > 0)
		{
			//game->_items_relics[_quest_num_relics_own].Init(SPRITEID_HUD_ITEM, _item_relics[i]._group, _item_relics[i]._id, 0, 0,false);
			_quest_num_relics_own++;
		}
	}
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		int level = GAME()->GetInt16At(_buffer, SAVE_FORMAT_WEAPON_LEVEL + i * 2);
		if (level > 0)
		{
			game->_weapon[i].Unlock();
			game->_weapon[i].SetLevel(level);
		}
	}
	_num_heroes_collected = 0;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		int heroid = GAME()->GetInt16At(_buffer, SAVE_FORMAT_HERO_ID + i * 2);
		int level = GAME()->GetInt16At(_buffer, SAVE_FORMAT_HERO_LEVEL + i * 2);
		bool deployed = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HERO_DEPLOYED + i);
		int slot = GAME()->GetInt16At(_buffer, SAVE_FORMAT_HERO_SLOT_NUMBER + i * 2);
		int rar_level = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_HERO_RARITY_LEVEL + i * 2);
		bool has_promo = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HERO_HAS_PROMO + i);
		_hero_arr[i]._heroid = heroid;
		_hero_arr[i]._level = level;
		_hero_arr[i]._is_deployed = deployed;
		_hero_arr[i]._slot_deploy_number = slot;
		_hero_arr[i]._rarity_level = rar_level;
		_hero_arr[i]._has_promo = has_promo;
		int num_hero = 0;
		if (heroid > 0)
		{
			_num_heroes_collected++;
			game->_hero_inbattle_arr[i].Modify(heroid, level, deployed, false, 0, 0, rar_level,has_promo);
		}
	}
	for (int i = 0; i < NUM_MAX_QUEST_GROUP; i++)
	{
		for (int j = 0; j < NUM_MAX_QUEST_IN_GROUP; j++)
		{
			_quest_completed[i][j] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_QUEST_COMPLETED + i*NUM_MAX_QUEST_IN_GROUP * 1 + j);
		}
		_quest_current[i] = GAME()->GetInt16At(_buffer, SAVE_FORMAT_QUEST_CURRENT + i*2);
	}
	_quest_num_battle_in_day = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_BATTLE_INDAY);
	_quest_battle_passed = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_BATTLE_PASSED);
	_quest_num_coin_collected = GAME()->GetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED);
	_quest_num_critical_hit = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_CRITICAL_HIT);
	_quest_num_enemy_bekill_weapon = GAME()->GetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_ENEMY_BEKILL_WP);
	_quest_num_kill_monster = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_MONSTER);
	_quest_num_relics_own = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_RELICS_OWN);
	_quest_num_tap = GAME()->GetInt64At(_buffer, SAVE_FORMAT_QUEST_NUM_TAP);
	_quest_num_upgrade_heroes = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_UPGRADE_HEROES);
	_quest_num_upgrade_weapons = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_UPGRADE_WEAPONS);
	_quest_num_use_skill = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_USE_SKILL);
	_tutorial_step = GAME()->GetInt16At(_buffer, SAVE_FORMAT_TUTORIAL_STEP);
	_tutorial_completed = GAME()->GetByteAt(_buffer, SAVE_FORMAT_TUTORIAL_COMPLETED);
	game->_battle_loop_from = GAME()->GetInt32At(_buffer, SAVE_FORMAT_BATTLE_LOOP_FROM);
	_quest_num_tap_in_second = GAME()->GetInt16At(_buffer, SAVE_FORMAT_QUEST_NUM_TAP_IN_SECOND);
	_quest_num_kill_monster_in_second = GAME()->GetInt16At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_MONSTER_IN_SECOND);
	_quest_num_kill_boss = GAME()->GetInt32At(_buffer, SAVE_FORMAT_QUEST_NUM_KILL_BOSS);
	_auto_attack_free = GAME()->GetInt16At(_buffer, SAVE_FORMAT_AUTO_ATTACK_FREE);
	_auto_skill_free = GAME()->GetInt16At(_buffer, SAVE_FORMAT_AUTO_SKILL_FREE);
	_has_double_coin = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_DOUBLE_COIN);
	_fairy_times_init = GAME()->GetInt16At(_buffer, SAVE_FORMAT_FAIRY_TIMES_INIT);
	GAME()->_soundEnable = GAME()->GetByteAt(_buffer, SAVE_FORMAT_SOUND_ENABLE );
	GAME()->_musicEnable = GAME()->GetByteAt(_buffer, SAVE_FORMAT_MUSIC_ENABLE);
	
	_daily_quest_completed = GAME()->GetByteAt(_buffer, SAVE_FORMAT_DAILY_QUEST_COMPLETED);
	_daily_quest_num = GAME()->GetInt32At(_buffer, SAVE_FORMAT_DAILY_QUEST_NUM);
	_daily_quest_group_current = GAME()->GetInt16At(_buffer, SAVE_FORMAT_DAILY_QUEST_GROUP_CURRENT);
	_time_reset_daily_quest = GAME()->GetInt64At(_buffer, SAVE_FORMAT_DAILY_QUEST_TIME_RESET);
	_is_hack = GAME()->GetByteAt(_buffer, SAVE_FORMAT_IS_HACK);
	_time_check_hack = GAME()->GetInt64At(_buffer, SAVE_FORMAT_TIME_CHECK_HACK);
	_iap_discount_time_reset = GAME()->GetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TIME_RESET);
	_iap_starter_time_reset = GAME()->GetInt64At(_buffer, SAVE_FORMAT_IAP_STARTER_TIME_RESET);
	_iap_triger_discount = GAME()->GetInt32At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TRIGER);
	_wheel_time_reset = GAME()->GetInt64At(_buffer, SAVE_FORMAT_WHEEL_TIME_RESET);
	_wheel_lucky = GAME()->GetInt32At(_buffer, SAVE_FORMAT_WHEEL_LUCKY);
	_has_rated_us_type = GAME()->GetInt16At(_buffer, SAVE_FORMAT_HAS_RATED_TYPE);
	_rate_trigger = GAME()->GetInt16At(_buffer, SAVE_FORMAT_TRIGGER_RATE);
	_watch_ad_time = GAME()->GetInt64At(_buffer, SAVE_FORMAT_WATCH_AD_TIME);
	_watch_ad_times = GAME()->GetInt16At(_buffer, SAVE_FORMAT_WATCH_AD_TIMES);
	game->_daily_quest_current = GAME()->GetInt16At(_buffer, SAVE_FORMAT_DAILY_QUEST_CURRENT);
	_daily_quest_group_current = game->GetDesignQuestValue(game->_daily_quest_current, CGameDesign::FileQuest::CSheetDaily_Quest::Group, true);
	_has_follow_tw = GAME()->GetByteAt(_buffer, SAVE_FORMAT_FOLLOW_TW);
	_has_liked_fb = GAME()->GetByteAt(_buffer, SAVE_FORMAT_LIKE_FB);
	_iap_starter_double_coin_time = GAME()->GetInt64At(_buffer, SAVE_FORMAT_STARTER_DB_COIN_TIME);
	_gem_collected = GAME()->GetInt32At(_buffer, SAVE_FORMAT_GEM_COLLECTED);
	_play_times_retry = GAME()->GetInt32At(_buffer, SAVE_FORMAT_PLAY_TIMES);
	_num_use_auto_attack = GAME()->GetInt32At(_buffer, SAVE_FORMAT_NUM_USE_AUTO_ATT);
	_has_completed_battle_max = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_COMPLETED_ALL_BATTLE);
	_has_pass_invitation = GAME()->GetByteAt(_buffer, SAVE_FORMAT_INVITATION_PASS);
	_invitation_num = GAME()->GetInt16At(_buffer, SAVE_FORMAT_INVITATION_NUM);
	for (int i = 0; i < 24; i++)
	{
		_ivitation_code[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_INVITATION_CODE + i);
	}
	_invitation_reward_current = GAME()->GetInt16At(_buffer, SAVE_FORMAT_INVITATION_REWARD_CURRENT);
	_download_moregame_trigger = GAME()->GetInt64At(_buffer, SAVE_FORMAT_DOWNLOAD_MOREGAME_TRIGGER);
    _stateAppDownload = GAME()->GetInt16At(_buffer, SAVE_FORMAT_DOWNLOAD_MOREGAME_STATE);
	//Update Ver12/2015
	_num_get_free_wheel = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GET_FREE_WHEEL);
	_time_offline = GAME()->GetInt64At(_buffer, SAVE_FORMAT_TIME_OFFLINE);
	_user_revision = GAME()->GetInt16At(_buffer, SAVE_FORMAT_USER_REVISION);
	_is_notify = GAME()->GetByteAt(_buffer, SAVE_FORMAT_IS_NOTIFY);
	_daily_reward_num = GAME()->GetInt16At(_buffer, SAVE_FORMAT_DAILY_REWARD_NUM);
	_daily_reward_day = GAME()->GetInt32At(_buffer, SAVE_FORMAT_DAILY_REWARD_DAY);
    game->_play_game_num = GAME()->GetInt16At(_buffer, SAVE_FORMAT_PLAY_GAME_NUM);
    
    //quoc.nguyen update ver13 date: 13/10/2016
   _timeBuyOpenBox =  GAME()->GetInt64At(_buffer, SAVE_FORMAT_TIME_BUY_OPEN_BOX);

   //Lam Update ver5
   for (int i = 0; i < 64; i++)
   {
	   _iap_dis_current[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_IAP_DISCOUNT_CURRENT + i);
   }
   _iap_dis_100_time = GAME()->GetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_100_TIME);
   _iap_dis_time = GAME()->GetInt64At(_buffer, SAVE_FORMAT_IAP_DISCOUNT_TIME);
   _num_gem_used = GAME()->GetInt16At(_buffer, SAVE_FORMAT_COUNT_GEM_USED);
   _has_bought_iap_dis_100 = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_BOUGHT_IAP_100);
   _has_bought_iap_dis_cur = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_BOUGHT_IAP_DIS);
   _iap_dis_cur_trigger = GAME()->GetInt16At(_buffer, SAVE_FORMAT_IAP_DIS_CUR_TRIGGER);
   _has_remove_ads_pop_up = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_REMOVE_ADS_POPUP);
   _has_show_pine_promo = GAME()->GetByteAt(_buffer, SAVE_FORMAT_HAS_SHOW_PINE_PROMO);
   game->_time_out_game = GAME()->GetInt64At(_buffer, SAVE_FORMAT_TIME_OUT_GAME);
   game->_wave_current = GAME()->GetByteAt(_buffer, SAVE_FORMAT_WAVE_CURRENT);

   /*for (int i = 0; i < 128; i++)
   {
	   _game_promo_icon_id[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_PROMO_ICON_ID + i);
	   _game_promo_link_store[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_LINK_STORE + i);
	   _game_promo_deviceID[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_DEVICEID + i);
   }*/
   _user_level_reset = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_USER_LEVEL_RESET);
   _user_battle_just_reset = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_USER_BATTLE_JUST_RESET);
   _sync_version = GAME()->GetInt64At(_buffer, SAVE_FORMAT_GAME_SYNC_VERSION);
   //_game_promo_revision = GAME()->GetInt32At(_buffer, SAVE_FORMAT_GAME_PROMO_REVISION);
   _iAPs_numpack_spend = GAME()->GetInt16At(_buffer, SAVE_FORMAT_IAP_NUMPACK_SPEND);
   _iap_dis_100_time_skip_return = GAME()->GetInt64At(_buffer, SAVE_FORMAT_IAP_100_TIME_RETURN);
   _hero_promo_time_delay = GAME()->GetInt64At(_buffer, SAVE_FORMAT_HERO_PROMO_TIME_DELAY);
   _num_mass_auto_free = GAME()->GetInt16At(_buffer, SAVE_FORMAT_NUM_MASS_AUTO_FREE);
   _num_wheel_spin_free = GAME()->GetInt16At(_buffer, SAVE_FORMAT_NUM_WHEEL_SPIN_FREE);
   _num_wheel_spin_premium = GAME()->GetInt16At(_buffer, SAVE_FORMAT_NUM_WHEEL_SPIN_PREMIUM);
   //_game_promo_delay_show = GAME()->GetInt64At(_buffer, SAVE_FORMAT_GAME_PROMO_DELAYTIME);
   //_game_promo_order = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_PROMO_ORDER);

   _is_new_user_ver15 =  GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_IS_NEW_USER_VER15);


   //Kha update promo
   for (int i = 0; i<128; i++)
   {
	   _game_promo_deviceID[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_DEVICEID + i);
	   _game_promo_icon_id[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_PROMO_ICON_ID + i);
	   _game_promo_link_store[i] = GAME()->GetByteAt(_buffer, SAVE_FORMAT_GAME_LINK_STORE + i);
   }
   _game_promo_delay_show = GAME()->GetInt64At(_buffer, SAVE_FORMAT_GAME_PROMO_DELAYTIME);
   _game_promo_has_show = GAME()->GetByteAt(_buffer, SAVE_FORMAT_USER_GAME_PROMO_HAS_SHOW);
   _game_promo_order = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_PROMO_ORDER);
   _game_promo_revision = GAME()->GetInt16At(_buffer, SAVE_FORMAT_GAME_PROMO_REVISION);
   _has_touch_promo = GAME()->GetByteAt(_buffer, SAVE_FORMAT_USER_HAS_TOUCH_PROMO);

#if !GAME_SUPPORT
	if (_version <= 0)
	{
		_has_rated_us_type = RATE_US_TYPE_NONE;
		_rate_trigger = RATE_US_TRIGGER_1;
		_version = 1;
	}
	if (_version <= 1)
	{
		_watch_ad_time = time(NULL);
		_watch_ad_times = 0;
		_version = 2;
	}
	if (_version <= 2)
	{
		game->_daily_quest_current = 0;
		_daily_quest_num = 0;
		DailyQuestInit();
		_version = 3;
	}
	if (_version <= 3)
	{
		_has_follow_tw = false;
		_has_liked_fb = false;
		_iap_starter_double_coin_time = 0;
		_gem_collected = 0;
		_play_times_retry = 0;
		_num_use_auto_attack = 0;
		
		_version = 4;
	}
	if (_version<= 4)
	{
		IapDiscountReset();
		_version = 5;
	}
	if (_version <= 5)
	{
		_has_completed_battle_max = false;
		_version = 6;
	}
	if (_version <= 6)
	{
		sprintf(_ivitation_code, "%s", "NULL");
		_invitation_num = 3;
		_has_pass_invitation = true;
		_invitation_reward_current = 3;
		_version = 7;
	}
	if (_version <= 7)
	{
		_download_moregame_trigger = time(NULL);
		_version = 8;
	}
    if(_version <= 8)
    {
        _stateAppDownload = 0;
        _version = 9;
    }
    if(_version <= 9)
    {
        sprintf(_ivitation_code, "%s", "NULL");
        _invitation_num = 3;
        _has_pass_invitation = true;
        _invitation_reward_current = 3;
        _version = 10;
    }
	if (_version <= 10)
	{
		if (_tutorial_completed)
		{
			sprintf(_ivitation_code, "%s", "NULL");
			_invitation_num = 0;
			_has_pass_invitation = true;
			_invitation_reward_current = 0;
		}
		else
		{
			sprintf(_ivitation_code, "%s", "NULL");
			_invitation_num = 0;
			_has_pass_invitation = false;
			_invitation_reward_current = 0;
		}
		_version = 11;
	}
	if (_version <= 11)
	{
		_num_get_free_wheel = 0;
		_time_offline = time(NULL);
		_version = 12;
	}
	if (_version <= 12)
	{
		_has_completed_battle_max = false;
		_user_revision = 0;
		_version = 13;
	}
	if (_version <= 13)
	{
		_is_notify = false;
		_version = 14;
	}
	if (_version <= 14)
	{
		_daily_reward_day = -1;
		_daily_reward_num = 0;
		sprintf(_ivitation_code, "%s", "NULL");
		_invitation_num = 0;
		_has_pass_invitation = false;
		_invitation_reward_current = 0;
		_version = 15;
	}
	if (_version <= 15)
	{
		_has_pass_invitation = false;
		_version = 16;
	}
    if(_version <= 16)
    {
        _invitation_num = 0;
        _invitation_reward_current = 0;
        _has_pass_invitation = false;
        _version = 17;
    }
    if(_version <= 17)
    {
        game->_play_game_num = 1;
        _version = 18;
    }
    if(_version <= 18)
    {
        _timeBuyOpenBox = time(NULL);
        _version = 19;
    }
	if (_version < GAME_CURRENT_VERSION_5)
	{
		//Lam Update ver5
		printf(_iap_dis_current, "%s", "NULL");
		_iap_dis_time = time(NULL);
		_iap_dis_100_time = time(NULL);
		_num_gem_used = 0;
		_version = GAME_CURRENT_VERSION_5;
		_has_bought_iap_dis_100 = false;
		_has_bought_iap_dis_cur = false;
		
	}
	if (_version < GAME_CURRENT_VERSION_6)
	{
		int total = game->_game_design.General.SheetiAP_instant_design_discount.int32Value._totalData;
		int indexdis = -1;
		for (int i = 0; i < total; i++)
		{
			int battle_trigg = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
			if (game->_battle_current >= battle_trigg)
			{
				indexdis = i;
			}
		}
		if (indexdis >= 0)
		{
			if (indexdis < total - 1)
			{
				_iap_dis_cur_trigger = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
				
			}
			else
			{
				_iap_dis_cur_trigger = 1000;
			}
		}
		else
		{
			_iap_dis_cur_trigger = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(0, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
		}
		_version = GAME_CURRENT_VERSION_6;
	}
	if (_version < GAME_CURRENT_VERSION_7)
	{
		_has_remove_ads_pop_up = false;
		_has_show_pine_promo = true;
		_version = GAME_CURRENT_VERSION_7;
	}
	if (_version < GAME_CURRENT_VERSION_8)
	{
		_version = GAME_CURRENT_VERSION_8;
		game->_time_out_game = -1;
	}

	if (_version < GAME_CURRENT_VERSION_9)
	{
		_version = GAME_CURRENT_VERSION_9;
		sprintf(_game_promo_icon_id, "%s","gameID");
		sprintf(_game_promo_link_store, "%s", "linkStore");
	}
	if (_version < GAME_CURRENT_VERSION_10)
	{
		_version = GAME_CURRENT_VERSION_10;
		_user_level_reset = 0;
		_user_battle_just_reset = 0;
		if (_quest_num_relics_own <= 0)
		{
			if (_tutorial_step == TUTORIAL_STEP_COMPLETED)
			{
				_tutorial_completed = false;
				_tutorial_step = TUTORIAL_STEP_MENU_RELIC;
			}
		}
	}
	if (_version < GAME_CURRENT_VERSION_11)
	{
		_version = GAME_CURRENT_VERSION_11;
		_sync_version = 0;
		sprintf(_game_promo_deviceID, "%s", "deviceID");
	}
	if (_version < GAME_CURRENT_VERSION_12)
	{
		_version = GAME_CURRENT_VERSION_12;
		_game_promo_revision = 0;
		_iAPs_numpack_spend = 0;
		_iap_dis_100_time_skip_return = time(NULL);
	}
	if (_version < GAME_CURRENT_VERSION_13)
	{
		_version = GAME_CURRENT_VERSION_13;
		for (int i = 0; i < NUM_MAX_HERO; i++)
		{
			_hero_arr[i]._has_promo = false;
		}
		_hero_promo_time_delay = time(NULL);
		_num_mass_auto_free = MASS_AUTO_FOR_NEW;
		_num_wheel_spin_free = 0;
		_num_wheel_spin_premium = 0;
	}
	if (_version < GAME_CURRENT_VERSION_14)
	{
		_version = GAME_CURRENT_VERSION_14;
		_game_promo_delay_show = time(NULL);
		_game_promo_order = 0;
	}
	if (_version < GAME_CURRENT_VERSION_15)
	{
		_version = GAME_CURRENT_VERSION_15;
		_is_new_user_ver15 = false;
	}
	if (_version < GAME_CURRENT_VERSION_16)
	{
		_version = GAME_CURRENT_VERSION_16;
		_game_promo_has_show = true;
		_has_touch_promo = false;
	}
#endif
	if (_num_heroes_collected > 1)
	{
		_tutorial_completed = true;
		if (_tutorial_step < TUTORIAL_STEP_MASS_AUTO)
		{
			_tutorial_step = TUTORIAL_STEP_MASS_AUTO;
		}
	}
	
	game->_coin_interface.StartTo(_coin);
	game->ConvertMoneyInbalace(_gem, _gem_text);
}
void CUser::SetUserID(char* userid)
{
    sprintf(_user_id, "%s",userid);
}
const char* CUser::GetUserID()
{
	return _user_id;
}
void CUser::SetUserName(char *username)
{
    sprintf(_name, "%s",username);
}
const char* CUser::GetName()
{
	return _name;
}
void CUser::AddCoin(INT_TIME coin, bool reward)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
    //printf("\n add coin = %lld",coin);
	_coin += coin;
	if (_coin <= 0)
	{
		_coin = 0;
	}
	
	if (coin > 0 && !reward)
	{
		_quest_num_coin_collected += coin;
		if (!_daily_quest_completed && _daily_quest_group_current == DAILY_QUEST_GROUP_COIN_COLLECT)
		{
			_daily_quest_num += coin;
		}
	}
	game->_coin_interface.StartTo(_coin);
	/*if (_coin >= game->_weapon[WEAPON_ARCHER].GetCostUpgrade())
	{
		if (!_tutorial_completed && _tutorial_step == TUTORIAL_STEP_USE_SKILL)
		{
			game->_tutorial_step = TUTORIAL_STEP_MENU_CASTLE;
		}
	}*/
	if (!_tutorial_completed && _tutorial_step == TUTORIAL_STEP_USE_SKILL)
	{
		if (_quest_num_coin_collected >= 300)
		{
			game->_tutorial_step = TUTORIAL_STEP_MENU_CASTLE;
		}
	}
}
void CUser::SetCoin(INT_TIME coin)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
    _coin = coin;
	game->_coin_interface.StartTo(_coin);
}
INT_TIME CUser::GetCoin()
{
	return _coin;
}
void CUser::AddGem(int gem)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_gem += gem;
	if (_gem <= 0)
	{
		_gem = 0;
	}
	if (gem > 0)
	{
		_gem_collected += gem;
	}
	if (gem < 0)
	{
		_num_gem_used += CMath::ABSOLUTE_VALUE(gem);
		if (_num_gem_used >= _iap_100_gem_use_trigger && _gem < _iap_100_min_trigger)
		{
			ActiveIapPackDiscount(true);
		}
	}
	game->ConvertMoneyInbalace(_gem, _gem_text);
	UserDataSave();
}
void CUser::SetGem(int gem)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
    _gem = gem;
	game->ConvertMoneyInbalace(_gem, _gem_text);
}
int CUser::GetGem()
{
	return _gem;
}

void CUser::InitHeroes()
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		_hero_arr[i]._heroid = -1;
		_hero_arr[i]._level = 0;
		_hero_arr[i]._is_deployed = false;
		_hero_arr[i]._slot_deploy_number = -1;
		_hero_arr[i]._rarity_level = 0;
		_hero_arr[i]._has_promo = false;
	}
}
void CUser::AddNewHeroes(int id, int level, bool deploy, int rarlv)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	bool isnew = true;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_arr[i]._heroid == id)
		{
			isnew = false;
			break;
		}
	}
	if (isnew)
	{
		for (int i = 0; i < NUM_MAX_HERO; i++)
		{
			if (_hero_arr[i]._heroid == -1)
			{
				_hero_arr[i]._heroid = id;
				_hero_arr[i]._level = level;
				_hero_arr[i]._is_deployed = deploy;
				_hero_arr[i]._rarity_level = 0;
				_num_heroes_collected++;
				game->_num_hero_inbattle++;
				break;
			}
		}
	}
	else
	{
		ModifyNewHeroes(id, level, deploy, -1, rarlv);
	}
	
}
void CUser::ModifyNewHeroes(int id, int level, bool deploy, int slotnumber, int rarlv)
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_arr[i]._heroid == id)
		{
			_hero_arr[i]._level = level;
			_hero_arr[i]._is_deployed = deploy;
			_hero_arr[i]._rarity_level = rarlv;
			if (!deploy)
			{
				_hero_arr[i]._slot_deploy_number = -1;
			}
			if (slotnumber != -1)
			{
				_hero_arr[i]._slot_deploy_number = slotnumber;
			}
			
			break;
		}
	}
}

bool CUser::CheckQuestCompleted(int group, int quest, bool daily)
{
	bool ret = false;
	TDGame*game = (TDGame*)GAME()->_current_game;
	int param_value = CGameDesign::FileQuest::CSheetNormal_Quest::Value;
	int questindex = game->GetQuestIndex(group + 1, quest, daily);
	int numquest = game->GetNumOfQuest(group+1);
	if (daily)
	{
		numquest = game->_game_design.Quest.SheetDaily_Quest.int32Value._totalData;
	}
	if (_quest_num_tap_in_second < game->_num_tap_in_second)
	{
		_quest_num_tap_in_second = game->_num_tap_in_second;
	}
	if (_quest_num_kill_monster_in_second < game->_num_kill_monster_in_second)
	{
		_quest_num_kill_monster_in_second = game->_num_kill_monster_in_second;
	}
	if (numquest <= quest)
	{
		return false;
	}
	int quest_design = game->GetDesignQuestValue(questindex, param_value, daily);
	if (daily)
	{
		quest_design = game->GetDesignQuestValue(game->_daily_quest_current, param_value, daily);
		if (!_daily_quest_completed && quest_design <= _daily_quest_num)
		{
			ret = true;
		}
	}
	else
	{
		switch (group)
		{
		case 0:
			if (quest_design <= _quest_num_kill_monster && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 1:
			if (quest_design <= _quest_num_coin_collected && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 2:
			if (quest_design <= game->_battle_current && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 3:
			if (quest_design <= _quest_num_relics_own && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 4:
			if (quest_design <= _quest_num_tap && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 5:
			if (quest_design <= _num_heroes_collected && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 6:
			if (quest_design <= _quest_num_upgrade_heroes && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 7:
		{
				  int weapon_unlock = game->GetNumWeaponUnlock();
				  if (!game->_weapon[quest_design - 2].IsLock() && !_quest_completed[group][quest])
				  {
					  ret = true;
				  }
		}

			break;
		case 8:
			if (quest_design <= _quest_num_upgrade_weapons && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 9:
			if (quest_design <= _quest_num_use_skill && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 10:
			if (quest_design <= _quest_num_critical_hit && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 11:
			if (quest_design <= _quest_num_enemy_bekill_weapon && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 12:

			if (quest_design <= game->GetDamageHeroesBasic() && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 13:
			if (quest_design <= game->GetDamageWeaponBasic() && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 14:
                
			/*if (_tutorial_completed && !_quest_completed[group][quest])
			{
			ret = true;
			}*/
            /*
			if (quest_design <= _quest_num_tap_in_second && !_quest_completed[group][quest])
			{
				ret = true;
			}*/
			break;
		case 15:
			/*if (quest_design <= _quest_num_battle_in_day && !_quest_completed[group][quest])
			{
			ret = true;
			}*/
			if (quest_design <= _quest_num_kill_monster_in_second && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 16:
			if (quest_design <= _quest_num_kill_boss && !_quest_completed[group][quest])
			{
				ret = true;
			}
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		case 25:
			break;
		case 26:
			break;
		case 27:
			break;
		case 28:
			break;
		case 29:
			break;
		default:
			break;
		}
	}
	return ret;
}

INT_TIME CUser::GetQuestCurrentValue(int group, int quest, bool daily)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int group_real = group;
	if (daily)
	{
		return _daily_quest_num;
	}
	else
	{
		switch (group_real)
		{
		case 0:
			return _quest_num_kill_monster;
			break;
		case 1:
			return _quest_num_coin_collected;
			break;
		case 2:
			return game->_battle_current;
			break;
		case 3:
			return _quest_num_relics_own;
			break;
		case 4:
			return _quest_num_tap;
			break;
		case 5:
			return _num_heroes_collected;
			break;
		case 6:
			return _quest_num_upgrade_heroes;
			break;
		case 7:
			return game->GetNumWeaponUnlock();
			break;
		case 8:
			return _quest_num_upgrade_weapons;
			break;
		case 9:
			return _quest_num_use_skill;
			break;
		case 10:
			return _quest_num_critical_hit;
			break;
		case 11:
			return _quest_num_enemy_bekill_weapon;
			break;
		case 12:
			return game->GetDamageHeroesBasic();
			break;
		case 13:
			return game->GetDamageWeaponBasic();
			break;
		case 14:
			return _quest_num_tap_in_second;
			break;
		case 15:
			return _quest_num_kill_monster_in_second;
			break;
		case 16:
			return _quest_num_kill_boss;
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		default:
			return 0;
			break;
		}
	}
}

void CUser::SetQuestComplete(int group, bool daily)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	if(daily)
	{
		_daily_quest_completed = true;
		game->_daily_quest_current++;
		if (game->_daily_quest_current < game->_game_design.Quest.SheetDaily_Quest.int32Value._totalData)
		{
			DailyQuestInit();
		}
	}
	else
	{
		_quest_completed[group][_quest_current[group]] = true;
		_quest_current[group]++;
	}
	
}


void CUser::AddNewRelics(int id, int group)
{
	for (int i = 0; i < NUM_MAX_ITEM_RELICS; i++)
	{
		if (_item_relics[i]._id == -1)
		{
			_item_relics[i]._id = id;
			_item_relics[i]._group = group;
			_quest_num_relics_own++;
			break;
		}
	}
}

bool CUser::CheckHeroColleted(int heroid)
{
	for (int i = 0; i < _num_heroes_collected; i++)
	{
		if (_hero_arr[i]._heroid == heroid)
		{
			return true;
		}
	}
	return false;
}

bool CUser::CheckRelicsCollected(int group, int relicid)
{
	for (int i = 0; i < _quest_num_relics_own; i++)
	{
		if (_item_relics[i]._id == relicid && _item_relics[i]._group == group)
		{
			return true;
		}
	}
	return false;
}
void CUser::DailyQuestInit()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int param_group = CGameDesign::FileQuest::CSheetNormal_Quest::Group;
	_daily_quest_group_current = game->GetDesignQuestValue(game->_daily_quest_current, param_group, true);
	_daily_quest_num = 0;
	_daily_quest_completed = false;
	UserDataSave();
}
void CUser::DailyQuestReset()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	game->_daily_quest_current = game->GetDailyQuestRandom();
	_daily_quest_num = 0;
	_daily_quest_completed = false;
	Pine_Date_Time timeLocal;
	timeLocal.setDateByLocalDate();
	int param_group = CGameDesign::FileQuest::CSheetNormal_Quest::Group;
	_daily_quest_group_current = game->GetDesignQuestValue(game->_daily_quest_current, param_group, true);
	int hour = timeLocal.getHour();
	int min = timeLocal.getMinute();
	int sec = timeLocal.getSecond();
	INT_TIME time_next = (23 - hour) * 60 * 60 + (59 - min) * 60 + sec;
	_time_reset_daily_quest = time(NULL) + time_next;
	UserDataSave();
}
void CUser::WheelReset()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	
	//Update Ver12/2015
	//_wheel_time_reset = time(NULL) + WHEEL_TIME_RESET;
	int max = game->_game_design.General.SheetWheel_time.int32Value._totalData;
    INT_TIME local_time = time(NULL);
	if (_num_get_free_wheel < max)
	{
		_wheel_time_reset = local_time + game->GetDesignWheelTime(_num_get_free_wheel)*60;
	}
	else 
	{
		if (_num_get_free_wheel >= 2*max)
		{
			_num_get_free_wheel = max;
		}
		_wheel_time_reset = local_time + game->GetDesignWheelTime(_num_get_free_wheel-max)*60;
	}
	_num_get_free_wheel++;
	int wheel_min = int(_wheel_time_reset - local_time);
    //printf("\n 000 wheelmin = %d",wheel_min);
	if (wheel_min > 0)
	{
		//wheel_min /= 60;
        game->_wheel_time.setDateBYSecond(wheel_min);
	}
    //printf("\n wheelmin = %d",wheel_min);
	
}

void CUser::IapDiscountReset()
{
	_iap_triger_discount = GetTriggerIapDiscount();
}

int CUser::GetTriggerIapDiscount()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int total = game->_game_design.General.SheetDiscount.int32Value._totalData;
	int param_battle = CGameDesign::FileGeneral::CSheetDiscount::Level;
	int battle_trigger = 10;
	for (int i = 0; i < total;i++)
	{
		int trigger = game->GetDesignIapTrigger(i, param_battle);
		if (game->_battle_current < trigger)
		{
			battle_trigger = trigger;
			break;
		}
	}
	return battle_trigger;
}

void CUser::ActiveIapPackDiscount(bool is_pack100)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	INT_TIME time_cur = time(NULL);
	if (_iap_dis_100_time > time_cur || _iap_dis_time > time_cur)
	{
		return;
	}
	if (is_pack100)
	{
		if (!_has_bought_iap_dis_100)
		{
			if (_num_gem_used >= _iap_100_gem_use_trigger && _gem < _iap_100_min_trigger)
			{
				_iap_dis_100_time = time_cur + 8 * 60 * 60;
				game->FirebaseLogIapPack(game->enumiAPType::iAP_TYPE_100);
			}
		}
	}
	else
	{
		if (game->_battle_current < _iap_dis_cur_trigger || game->_battle_current < _user_battle_just_reset)
		{
			return;
		}
		int total = game->_game_design.General.SheetiAP_instant_design_discount.int32Value._totalData;
		int indexdis = -1;
		for (int i = 0; i < total; i++)
		{
			int battle_trigg = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
			if (_iap_dis_cur_trigger == battle_trigg)
			{
				indexdis = i;
			}
		}
		if (indexdis >= 0)
		{
			if (_has_bought_iap_dis_cur)
			{
				if (strcmp(_iap_dis_current, game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::ID)) != 0)
				{
					if (indexdis < total -1)
					{
						_iap_dis_cur_trigger = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(indexdis+1, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
					}
					else
					{
						_iap_dis_cur_trigger = 1000;
					}
					_has_bought_iap_dis_cur = false;
					_iap_dis_time = time_cur + game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Lasting) * 60;
#if defined (ANDROID_OS)
					sprintf(_iap_dis_current, "%s", game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::GG_ID));
					
#else
					sprintf(_iap_dis_current, "%s", game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::ID));
					
#endif
					game->FirebaseLogIapPack(game->enumiAPType::iAP_TYPE_BATTLE);
				}
			}
			else
			{
				if (indexdis < total - 1)
				{
					_iap_dis_cur_trigger = game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(indexdis+1, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Battle_Unlock);
				}
				else
				{
					_iap_dis_cur_trigger = 1000;
				}
				_iap_dis_time = time_cur + game->_game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::Lasting) * 60;
#if defined (ANDROID_OS)
				sprintf(_iap_dis_current, "%s", game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::GG_ID));
				
#else
				sprintf(_iap_dis_current, "%s", game->_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(indexdis, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::ID));
				
#endif
				game->FirebaseLogIapPack(game->enumiAPType::iAP_TYPE_BATTLE);
			}
		}
	}
}

#if defined (ANDROID_OS)
void CUser::CheckUnlockAllAchievements()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int count = (game->_battle_current + 1) / 10;
	bool has_achievement_need_unlock = false;
	//int total = GAME()->_poker_flat_game->_game_design.leveldesign.SheetAchievement.int32Value._totalData;
	if (GAME()->_async_task_manager._need_check_unlock_all_achievement)
	{
		GAME()->_async_task_manager._need_check_unlock_all_achievement = false;
		for (int i = 0; i < count; i++)
		{
			has_achievement_need_unlock = true;
			GAME()->_async_task_manager._list_id_group_achievement_need_check_unlock[i] = true;
		}
	}
	if (has_achievement_need_unlock && GAME()->_async_task_manager._is_login_google)
	{
		GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_UNLOCK_ACHIEVEMENT);
	}
}

void CUser::CheckLocalAndCloudSaveFile(bool isauto)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (!Device::IsNetworkAvailable())
	{
		if (!isauto)
		{
			OS_ShowMessageBox("Error!", "Connection is not available!");
		}
		return;
	}
	if (!GAME()->_async_task_manager._is_login_google)
	{
		GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_IS_LOG_IN_GOOGLE_PLAY);
		GAME()->_async_task_manager._is_force_login_google_play = true;
		GAME()->_async_task_manager._on_process_sync_cloud = true;
		return;
	}
	Buffer * buff = OS_LoadAppData(CLOUD_SAVE_FILE_NAME);
	if (buff != NULL)
	{
		char* server_buff = (char*)buff->Data();
		if (!isauto)
		{
			GAME()->_async_task_manager._on_process_sync_cloud = true;
		}
		int battle_cur = GAME()->GetInt32At(server_buff, SAVE_FORMAT_BATTLE_CURRENT);
		int coin_collected = GAME()->GetInt32At(server_buff, SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED);
		printf("\nfrom cloud battle_cur = %d, coin = %d", battle_cur, coin_collected);
		int ver = (int)GAME()->GetInt64At(server_buff, SAVE_FORMAT_CURRENT_VERSION);
		int prestige_lv = GAME()->GetInt16At(server_buff, SAVE_FORMAT_GAME_USER_LEVEL_RESET);
		if (ver < GAME_CURRENT_VERSION)
		{
			prestige_lv = 0;
		}
		if (prestige_lv < _user_level_reset)
		{
			ConfirmSyncSaveToCloud(isauto);
		}
		else if (prestige_lv > _user_level_reset)
		{
			if (!isauto)
			{
				ConfirmSyncSaveFromCloud();
			}
		}
		else
		{
			//PDEBUG("\n #icloud save_version = %d, numPlay = %d", ver, time);
			if (battle_cur < game->_battle_current)
			{
				ConfirmSyncSaveToCloud(isauto);
			}
			else if (battle_cur == game->_battle_current)
			{
				if (!isauto)
				{
					if (coin_collected > _quest_num_coin_collected)
					{
						ConfirmSyncSaveFromCloud();
					}
					else
					{
						OS_ShowMessageBox("Congratulations!", "Your data has been saved!");
						GAME()->_async_task_manager._on_process_sync_cloud = false;
					}
				}
			}
			else if (battle_cur > game->_battle_current)
			{
				if (!isauto)
				{
					ConfirmSyncSaveFromCloud();
				}
			}
			if (ver < GAME_CURRENT_VERSION)
			{
				if (battle_cur > game->_battle_current)
				{
					if (!isauto)
					{
						ConfirmSyncSaveFromCloud();
					}
				}
				else
				{
					ConfirmSyncSaveToCloud(isauto);
				}
			}
		}
		buff->Release();
	}
	else
	{
		ConfirmSyncSaveToCloud(isauto);
	}
}

void CUser::UpdateCloudSaveFile()
{
	PDEBUG("UpdateCloudSaveFile with local");
	OS_SaveAppData(CLOUD_SAVE_FILE_NAME, _buffer, MAX_SAVE_BUFFER_CACHE, false);
}

void CUser::UpdateLocalSaveFile(Buffer* buffer)
{
	PDEBUG("UpdateLocalSaveFile with cloud");
	memcpy(_buffer, buffer->Data(), SAVE_FORMAT_END);
	LoadFromBuffer();
	SaveToBuffer();
	CheckUnlockAllAchievements();
	OS_SaveAppData(SAVE_FILE_NAME, _buffer, MAX_SAVE_BUFFER_CACHE, false);
	TDGame *game = (TDGame*)GAME()->_current_game;
	game->SetState(k_GS_PLAYGAME);
	game->ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
	game->ClearAllTouchUp(TOUCH_TYPE_INGAME);
	int totalhero = game->_game_design.Hero_design.SheetHero_General.int32Value._totalData;
	int count_hero = _num_heroes_collected;
	for (int i = 0; i < totalhero; i++)
	{
		int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		int heroid = game->GetDesignHeroGeneral(i, paramid);
		if (!CheckHeroColleted(heroid))
		{
			game->_hero_inbattle_arr[count_hero].Init(heroid, 1, false, true,false);
			count_hero++;
		}
	}
	game->RelicsDefault();
}

void CUser::ConfirmSyncSaveToCloud(bool isauto)
{
	if (isauto)
	{
		TDGame *game = (TDGame*)GAME()->_current_game;
		game->_user.UpdateCloudSaveFile();
		GAME()->_async_task_manager._is_force_sync_save_to_cloud = true;
		GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_UPDATE_CLOUND_SAVE);
	}
	else
	{
		sprintf(GAME()->_async_task_manager._message_box_title, "%s", "Google Drive sync");
		sprintf(GAME()->_async_task_manager._message_box_message, "%s", "Do you want to safeguard your progress to Google Drive?");
		GAME()->_async_task_manager._message_box_confirm_type = CAsyncTasks::enumCloudSaveConfirmType::USE_SAVE_FROM_LOCAL;
		GAME()->_async_task_manager._on_process_sync_cloud = true;
		GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_SHOW_MESSAGE_BOX);
	}
}

void CUser::ConfirmSyncSaveFromCloud()
{
	sprintf(GAME()->_async_task_manager._message_box_title, "%s", "Google Drive backup");
	sprintf(GAME()->_async_task_manager._message_box_message, "%s", "Do you want to play with your latest Google Drive Backup?");
	GAME()->_async_task_manager._message_box_confirm_type = CAsyncTasks::enumCloudSaveConfirmType::USE_SAVE_FROM_CLOUD;
	GAME()->_async_task_manager._on_process_sync_cloud = true;
	GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_SHOW_MESSAGE_BOX);
}
#endif
