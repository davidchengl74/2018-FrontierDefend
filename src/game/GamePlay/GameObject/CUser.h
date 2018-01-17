#ifndef _USER_
#define _USER_

#include "../../Lib/DataType/CType.h"

#define SAVE_FILE_NAME									"TDGame.pine"
#if defined (ANDROID_OS)
#define CLOUD_SAVE_FILE_NAME							"clouddata.pine"
#endif

#define SAVE_BACKUP_FILE_NAME							"TDGameBK.pine"

#define NUM_MAX_QUEST_GROUP			50
#define NUM_MAX_QUEST_IN_GROUP		10

#define SAVE_VERSION_FIRST_VERSION						0
#define SAVE_CURRENT_VERSION							0

#define GAME_CURRENT_VERSION_1							6//31/10/2015
#define GAME_CURRENT_VERSION_2							13//3/12/2015
#define GAME_CURRENT_VERSION_3							15//15/12/2015
#define GAME_CURRENT_VERSION_4							16//14/01/2016
#define GAME_CURRENT_VERSION_5							20//25/05/2017
#define GAME_CURRENT_VERSION_6							22//26/05/2017
#define GAME_CURRENT_VERSION_7							25//7/06/2017
#define GAME_CURRENT_VERSION_8							26//14/06/2017
#define GAME_CURRENT_VERSION_9							27//3/08/2017
#define GAME_CURRENT_VERSION_10							28//8/08/2017
#define GAME_CURRENT_VERSION_11							29//21/08/2017
#define GAME_CURRENT_VERSION_12							30//24/08/2017
#define GAME_CURRENT_VERSION_13							31//28/08/2017
#define GAME_CURRENT_VERSION_14							32//19/10/2017
#define GAME_CURRENT_VERSION_15							33//7/12/2017
#define GAME_CURRENT_VERSION_16							34//16/1/2018
#define GAME_CURRENT_VERSION							GAME_CURRENT_VERSION_16

#define SAVE_FORMAT_CURRENT_VERSION						0
#define SAVE_FORMAT_USER_ID					(SAVE_FORMAT_CURRENT_VERSION+8)
#define SAVE_FORMAT_USER_NAME				(SAVE_FORMAT_USER_ID + 128)
#define SAVE_FORMAT_NUM_HEROES_COLLECTED	(SAVE_FORMAT_USER_NAME + 128)

#define SAVE_FORMAT_BATTLE_CURRENT			(SAVE_FORMAT_NUM_HEROES_COLLECTED + 2)
#define SAVE_FORMAT_COIN					(SAVE_FORMAT_BATTLE_CURRENT + 4)
#define SAVE_FORMAT_GEM						(SAVE_FORMAT_COIN + 8)

#define SAVE_FORMAT_CASTLE_LEVEL			(SAVE_FORMAT_GEM + 4)
#define SAVE_FORMAT_WEAPON_LEVEL			(SAVE_FORMAT_CASTLE_LEVEL + 2)

#define SAVE_FORMAT_HERO_ID					(SAVE_FORMAT_WEAPON_LEVEL + 2*NUM_MAX_WEAPON)
#define SAVE_FORMAT_HERO_LEVEL				(SAVE_FORMAT_HERO_ID + 2*NUM_MAX_HERO)
#define SAVE_FORMAT_HERO_SLOT_NUMBER		(SAVE_FORMAT_HERO_LEVEL + 2*NUM_MAX_HERO)
#define SAVE_FORMAT_HERO_DEPLOYED			(SAVE_FORMAT_HERO_SLOT_NUMBER + 2*NUM_MAX_HERO)

#define SAVE_FORMAT_QUEST_COMPLETED				(SAVE_FORMAT_HERO_DEPLOYED + 1*NUM_MAX_HERO)
#define SAVE_FORMAT_QUEST_CURRENT				(SAVE_FORMAT_QUEST_COMPLETED + 1*NUM_MAX_QUEST_GROUP*NUM_MAX_QUEST_IN_GROUP)
#define SAVE_FORMAT_QUEST_NUM_KILL_MONSTER		(SAVE_FORMAT_QUEST_CURRENT + 2*NUM_MAX_QUEST_GROUP)
#define SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED	(SAVE_FORMAT_QUEST_NUM_KILL_MONSTER + 4)
#define SAVE_FORMAT_QUEST_NUM_BATTLE_PASSED		(SAVE_FORMAT_QUEST_NUM_COIN_COLLECTED + 8)
#define SAVE_FORMAT_QUEST_NUM_RELICS_OWN		(SAVE_FORMAT_QUEST_NUM_BATTLE_PASSED + 4)
#define SAVE_FORMAT_QUEST_NUM_TAP				(SAVE_FORMAT_QUEST_NUM_RELICS_OWN + 4)
#define SAVE_FORMAT_QUEST_NUM_UPGRADE_HEROES	(SAVE_FORMAT_QUEST_NUM_TAP + 8)
#define SAVE_FORMAT_QUEST_NUM_UPGRADE_WEAPONS	(SAVE_FORMAT_QUEST_NUM_UPGRADE_HEROES + 4)
#define SAVE_FORMAT_QUEST_NUM_USE_SKILL			(SAVE_FORMAT_QUEST_NUM_UPGRADE_WEAPONS + 4)
#define SAVE_FORMAT_QUEST_NUM_CRITICAL_HIT		(SAVE_FORMAT_QUEST_NUM_USE_SKILL + 4)
#define SAVE_FORMAT_QUEST_NUM_ENEMY_BEKILL_WP	(SAVE_FORMAT_QUEST_NUM_CRITICAL_HIT + 4)
#define SAVE_FORMAT_QUEST_NUM_BATTLE_INDAY		(SAVE_FORMAT_QUEST_NUM_ENEMY_BEKILL_WP + 8)
#define SAVE_FORMAT_QUEST_NUM_TAP_IN_SECOND		(SAVE_FORMAT_QUEST_NUM_BATTLE_INDAY + 4)
#define SAVE_FORMAT_QUEST_NUM_KILL_MONSTER_IN_SECOND		(SAVE_FORMAT_QUEST_NUM_TAP_IN_SECOND + 2)
#define SAVE_FORMAT_QUEST_NUM_KILL_BOSS						(SAVE_FORMAT_QUEST_NUM_KILL_MONSTER_IN_SECOND + 2)

#define SAVE_FORMAT_ITEM_RELIC_GROUP			(SAVE_FORMAT_QUEST_NUM_KILL_BOSS + 4)
#define SAVE_FORMAT_ITEM_RELIC_ID				(SAVE_FORMAT_ITEM_RELIC_GROUP + 2*NUM_MAX_ITEM_RELICS)

#define SAVE_FORMAT_BATTLE_LOOP_FROM			(SAVE_FORMAT_ITEM_RELIC_ID + 2*NUM_MAX_ITEM_RELICS)

#define SAVE_FORMAT_TUTORIAL_STEP				(SAVE_FORMAT_BATTLE_LOOP_FROM + 4)
#define SAVE_FORMAT_TUTORIAL_COMPLETED			(SAVE_FORMAT_TUTORIAL_STEP + 2)
#define SAVE_FORMAT_AUTO_ATTACK_FREE			(SAVE_FORMAT_TUTORIAL_COMPLETED + 1)
#define SAVE_FORMAT_AUTO_SKILL_FREE				(SAVE_FORMAT_AUTO_ATTACK_FREE + 2)
#define SAVE_FORMAT_HAS_DOUBLE_COIN				(SAVE_FORMAT_AUTO_SKILL_FREE + 2)

#define SAVE_FORMAT_FAIRY_TIMES_INIT			(SAVE_FORMAT_HAS_DOUBLE_COIN + 1)
#define SAVE_FORMAT_SOUND_ENABLE			(SAVE_FORMAT_FAIRY_TIMES_INIT + 2)
#define SAVE_FORMAT_MUSIC_ENABLE			(SAVE_FORMAT_SOUND_ENABLE + 1)

#define SAVE_FORMAT_DAILY_QUEST_NUM					(SAVE_FORMAT_MUSIC_ENABLE + 1)
#define SAVE_FORMAT_DAILY_QUEST_COMPLETED			(SAVE_FORMAT_DAILY_QUEST_NUM + 4)
#define SAVE_FORMAT_DAILY_QUEST_GROUP_CURRENT		(SAVE_FORMAT_DAILY_QUEST_COMPLETED + 1)
#define SAVE_FORMAT_DAILY_QUEST_TIME_RESET			(SAVE_FORMAT_DAILY_QUEST_GROUP_CURRENT + 2)
#define SAVE_FORMAT_TIME_CHECK_HACK					(SAVE_FORMAT_DAILY_QUEST_TIME_RESET + 8)
#define SAVE_FORMAT_IS_HACK							(SAVE_FORMAT_TIME_CHECK_HACK + 8)

#define SAVE_FORMAT_IAP_STARTER_TIME_RESET			(SAVE_FORMAT_IS_HACK + 1)
#define SAVE_FORMAT_IAP_DISCOUNT_TIME_RESET			(SAVE_FORMAT_IAP_STARTER_TIME_RESET + 8)
#define SAVE_FORMAT_IAP_DISCOUNT_TRIGER				(SAVE_FORMAT_IAP_DISCOUNT_TIME_RESET + 8)

#define SAVE_FORMAT_WHEEL_LUCKY						(SAVE_FORMAT_IAP_DISCOUNT_TRIGER + 4)
#define SAVE_FORMAT_WHEEL_TIME_RESET				(SAVE_FORMAT_WHEEL_LUCKY + 4)

#define SAVE_FORMAT_HAS_RATED_TYPE				(SAVE_FORMAT_WHEEL_TIME_RESET + 8)
#define SAVE_FORMAT_TRIGGER_RATE                (SAVE_FORMAT_HAS_RATED_TYPE + 2)

#define SAVE_FORMAT_WATCH_AD_TIME				(SAVE_FORMAT_TRIGGER_RATE + 2)
#define SAVE_FORMAT_WATCH_AD_TIMES				(SAVE_FORMAT_WATCH_AD_TIME + 8)
#define SAVE_FORMAT_DAILY_QUEST_CURRENT			(SAVE_FORMAT_WATCH_AD_TIMES + 2)

#define SAVE_FORMAT_FOLLOW_TW					(SAVE_FORMAT_DAILY_QUEST_CURRENT + 2)
#define SAVE_FORMAT_LIKE_FB						(SAVE_FORMAT_FOLLOW_TW + 1)
#define SAVE_FORMAT_STARTER_DB_COIN_TIME		(SAVE_FORMAT_LIKE_FB + 1)
#define SAVE_FORMAT_GEM_COLLECTED				(SAVE_FORMAT_STARTER_DB_COIN_TIME + 8)
#define SAVE_FORMAT_PLAY_TIMES					(SAVE_FORMAT_GEM_COLLECTED + 4)
#define SAVE_FORMAT_NUM_USE_AUTO_ATT			(SAVE_FORMAT_PLAY_TIMES + 4)
#define SAVE_FORMAT_HAS_COMPLETED_ALL_BATTLE	(SAVE_FORMAT_NUM_USE_AUTO_ATT + 4)

#define SAVE_FORMAT_INVITATION_CODE				(SAVE_FORMAT_HAS_COMPLETED_ALL_BATTLE + 1)
#define SAVE_FORMAT_INVITATION_NUM				(SAVE_FORMAT_INVITATION_CODE + 24)
#define SAVE_FORMAT_INVITATION_PASS				(SAVE_FORMAT_INVITATION_NUM + 2)
#define SAVE_FORMAT_INVITATION_REWARD_CURRENT	(SAVE_FORMAT_INVITATION_PASS + 1)
#define SAVE_FORMAT_DOWNLOAD_MOREGAME_TRIGGER	(SAVE_FORMAT_INVITATION_REWARD_CURRENT + 2)
#define SAVE_FORMAT_DOWNLOAD_MOREGAME_STATE     (SAVE_FORMAT_DOWNLOAD_MOREGAME_TRIGGER + 8)

//Update Ver12/2015
#define SAVE_FORMAT_GET_FREE_WHEEL				(SAVE_FORMAT_DOWNLOAD_MOREGAME_STATE + 2)
#define SAVE_FORMAT_TIME_OFFLINE				(SAVE_FORMAT_GET_FREE_WHEEL + 2)
#define SAVE_FORMAT_USER_REVISION				(SAVE_FORMAT_TIME_OFFLINE + 8)
#define SAVE_FORMAT_IS_NOTIFY					(SAVE_FORMAT_USER_REVISION + 2)
#define SAVE_FORMAT_DAILY_REWARD_NUM			(SAVE_FORMAT_IS_NOTIFY + 1)
#define SAVE_FORMAT_DAILY_REWARD_DAY			(SAVE_FORMAT_DAILY_REWARD_NUM + 2)
#define SAVE_FORMAT_PLAY_GAME_NUM               (SAVE_FORMAT_DAILY_REWARD_DAY + 4)

//quoc.nguyen update ver13 date: 13/10/2016
#define SAVE_FORMAT_TIME_BUY_OPEN_BOX           (SAVE_FORMAT_PLAY_GAME_NUM + 2)

//Lam Update ver5
#define SAVE_FORMAT_IAP_DISCOUNT_CURRENT		       (SAVE_FORMAT_TIME_BUY_OPEN_BOX + 8)
#define SAVE_FORMAT_IAP_DISCOUNT_TIME				   (SAVE_FORMAT_IAP_DISCOUNT_CURRENT + 64)
#define SAVE_FORMAT_IAP_DISCOUNT_100_TIME				(SAVE_FORMAT_IAP_DISCOUNT_TIME + 8)
#define SAVE_FORMAT_COUNT_GEM_USED						(SAVE_FORMAT_IAP_DISCOUNT_100_TIME + 8)
#define SAVE_FORMAT_HAS_BOUGHT_IAP_DIS					(SAVE_FORMAT_COUNT_GEM_USED + 2)
#define SAVE_FORMAT_HAS_BOUGHT_IAP_100					(SAVE_FORMAT_HAS_BOUGHT_IAP_DIS + 1)
#define SAVE_FORMAT_IAP_DIS_CUR_TRIGGER					(SAVE_FORMAT_HAS_BOUGHT_IAP_100 + 1)

#define SAVE_FORMAT_HAS_REMOVE_ADS_POPUP				(SAVE_FORMAT_IAP_DIS_CUR_TRIGGER + 2)
#define SAVE_FORMAT_HAS_SHOW_PINE_PROMO					(SAVE_FORMAT_HAS_REMOVE_ADS_POPUP + 1)
#define SAVE_FORMAT_TIME_OUT_GAME						(SAVE_FORMAT_HAS_SHOW_PINE_PROMO + 1)
#define SAVE_FORMAT_WAVE_CURRENT					(SAVE_FORMAT_TIME_OUT_GAME + 8)

#define SAVE_FORMAT_GAME_PROMO_ICON_ID				(SAVE_FORMAT_WAVE_CURRENT + 1)
#define SAVE_FORMAT_GAME_LINK_STORE					(SAVE_FORMAT_GAME_PROMO_ICON_ID + 128)
#define SAVE_FORMAT_GAME_HERO_RARITY_LEVEL			(SAVE_FORMAT_GAME_LINK_STORE + 128)
#define SAVE_FORMAT_GAME_USER_LEVEL_RESET			(SAVE_FORMAT_GAME_HERO_RARITY_LEVEL + 2*NUM_MAX_HERO)
#define SAVE_FORMAT_GAME_USER_BATTLE_JUST_RESET		(SAVE_FORMAT_GAME_USER_LEVEL_RESET + 2)
#define SAVE_FORMAT_GAME_DEVICEID					(SAVE_FORMAT_GAME_USER_BATTLE_JUST_RESET + 2)
#define SAVE_FORMAT_GAME_SYNC_VERSION				(SAVE_FORMAT_GAME_DEVICEID + 128)
#define SAVE_FORMAT_GAME_PROMO_REVISION				(SAVE_FORMAT_GAME_SYNC_VERSION + 8)
#define SAVE_FORMAT_IAP_NUMPACK_SPEND				(SAVE_FORMAT_GAME_PROMO_REVISION + 4)
#define SAVE_FORMAT_IAP_100_TIME_RETURN				(SAVE_FORMAT_IAP_NUMPACK_SPEND + 2)
#define SAVE_FORMAT_HERO_HAS_PROMO					(SAVE_FORMAT_IAP_100_TIME_RETURN + 8)
#define SAVE_FORMAT_HERO_PROMO_TIME_DELAY			(SAVE_FORMAT_HERO_HAS_PROMO + 1*NUM_MAX_HERO)
#define SAVE_FORMAT_NUM_MASS_AUTO_FREE				(SAVE_FORMAT_HERO_PROMO_TIME_DELAY + 8)
#define SAVE_FORMAT_NUM_WHEEL_SPIN_FREE				(SAVE_FORMAT_NUM_MASS_AUTO_FREE + 2)
#define SAVE_FORMAT_NUM_WHEEL_SPIN_PREMIUM			(SAVE_FORMAT_NUM_WHEEL_SPIN_FREE + 2)
#define SAVE_FORMAT_GAME_PROMO_DELAYTIME			(SAVE_FORMAT_NUM_WHEEL_SPIN_PREMIUM + 2)
#define SAVE_FORMAT_GAME_PROMO_ORDER				(SAVE_FORMAT_GAME_PROMO_DELAYTIME + 8)
#define SAVE_FORMAT_GAME_IS_NEW_USER_VER15			(SAVE_FORMAT_GAME_PROMO_ORDER + 2)

#define SAVE_FORMAT_USER_HAS_TOUCH_PROMO			(SAVE_FORMAT_GAME_IS_NEW_USER_VER15 + 2)
#define SAVE_FORMAT_USER_GAME_PROMO_HAS_SHOW		(SAVE_FORMAT_USER_HAS_TOUCH_PROMO + 2)

#define SAVE_FORMAT_END                         (SAVE_FORMAT_USER_GAME_PROMO_HAS_SHOW + 1)


#define SAVE_FORMAT_LENGTH					(SAVE_FORMAT_END)

#define SAVE_MAX_BUFFER				10000
#define MAX_SAVE_BUFFER_CACHE		10000


#define TUTORIAL_STEP_FREE					-1
#define TUTORIAL_STEP_WELCOME				0
#define TUTORIAL_STEP_BATTLE_START			1
#define TUTORIAL_STEP_TAP_ATT				2
#define TUTORIAL_STEP_USE_SKILL				3
#define TUTORIAL_STEP_MENU_CASTLE			4
#define TUTORIAL_STEP_BUILD_TOWER			5

#define TUTORIAL_STEP_MENU_HERO				7
#define TUTORIAL_STEP_BUY_HERO				8
#define TUTORIAL_STEP_DEPLOY_HERO			9

#define TUTORIAL_STEP_COMPLETED				10
#define TUTORIAL_STEP_TAP_SCREEN			11

#define TUTORIAL_STEP_MASS_AUTO				12
#define TUTORIAL_STEP_MENU_RELIC			13
#define TUTORIAL_STEP_BUY_RELIC				14
#define TUTORIAL_STEP_BUY_RELIC_COMPLETED	15
#define TUTORIAL_STEP_COMPLETED_2			100

#define RATE_US_TYPE_NONE                   0
#define RATE_US_TYPE_RATED                  1
#define RATE_US_TYPE_CANCEL                 2

#define RATE_US_TRIGGER_1                 10
#define RATE_US_TRIGGER_2                 19


class CUser
{
public:
	CUser();
	~CUser();
	struct Heroes
	{
		int _heroid;
		int _level;
		bool _is_deployed;
		int _slot_deploy_number;

		//Lam Update
		int _rarity_level;
		bool _has_promo;
	};
	Heroes _hero_arr[NUM_MAX_HERO];
	void InitHeroes();
	void AddNewHeroes(int id, int level, bool deploy, int rarlv);
	void ModifyNewHeroes(int id, int level, bool deploy, int slotnumber, int rarlv);

	struct ItemRelics
	{
		int _id;
		int _group;
	};
	ItemRelics _item_relics[NUM_MAX_ITEM_RELICS];
	void AddNewRelics(int id, int group);
	void Init();
	void UserDefault();
	void UserDataSave();
	void UserDataLoad();
	void LoadFromBuffer();
	void SaveToBuffer();
	char _buffer[SAVE_MAX_BUFFER];
	INT64 _version;

    void SetUserID(char* userid);
	const char* GetUserID();
    void SetUserName(char* username);
	const char* GetName();
	void AddCoin(INT_TIME coin,bool reward);
	INT_TIME GetCoin();
    void SetCoin(INT_TIME coin);
	void AddGem(int gem);
	int GetGem();
    void SetGem(int gem);
	int _num_heroes_collected;

	int _quest_completed[NUM_MAX_QUEST_GROUP][NUM_MAX_QUEST_IN_GROUP];
	int _quest_current[NUM_MAX_QUEST_GROUP];
	
	int _play_times_retry;
	int _num_use_auto_attack;
	int _quest_num_kill_monster;
	INT_TIME _quest_num_coin_collected;
	int _gem_collected;
	int _quest_battle_passed;
	int _quest_num_relics_own;
	INT_TIME _quest_num_tap;
	int _quest_num_upgrade_heroes;
	int _quest_num_upgrade_weapons;
	int _quest_num_use_skill;
	int _quest_num_critical_hit;
	int _quest_num_tap_in_second;
	int _quest_num_kill_monster_in_second;
	int _quest_num_kill_boss;
	INT_TIME _quest_num_enemy_bekill_weapon;
	int _quest_num_battle_in_day;

	int _daily_quest_num;
	bool _daily_quest_completed;
	int _daily_quest_group_current;
	INT_TIME _time_reset_daily_quest;
	INT_TIME _time_check_hack;
	bool _is_hack;
	void DailyQuestReset();
	void DailyQuestInit();
	void WheelReset();
	void IapDiscountReset();

	bool CheckQuestCompleted(int group, int quest, bool daily);
	INT_TIME GetQuestCurrentValue(int group, int quest, bool daily);
	int _tutorial_step;
	bool _tutorial_completed;
    bool _tutorial_attack_auto_enable;
    bool _tutorial_auto_attack_complete;
	void SetQuestComplete(int group, bool daily);

	int _auto_attack_free;
	int _auto_skill_free;
	bool _has_double_coin;
	bool CheckHeroColleted(int heroid);
	bool CheckRelicsCollected(int group, int relicid);
	int _fairy_times_init;

	bool _iap_starter_has_bought;
	INT_TIME _iap_starter_time_reset;
	INT_TIME _iap_discount_time_reset;
	int _iap_triger_discount;
	float _wheel_lucky;
	INT_TIME _wheel_time_reset;
    char _identityString[128];
	int _has_rated_us_type;
	int _rate_trigger;
	INT_TIME _watch_ad_time;
	int _watch_ad_times;
	bool _has_liked_fb;
	bool _has_follow_tw;
	INT_TIME _iap_starter_double_coin_time;
	int GetTriggerIapDiscount();
	bool _has_completed_battle_max;
	char _ivitation_code[24];
	int _invitation_num;
	bool _has_pass_invitation;
	int _invitation_reward_current;
	INT_TIME _download_moregame_trigger;
    int _stateAppDownload;
	//Update Ver12/2015
	int _num_get_free_wheel;
	INT_TIME _time_offline;
	int _user_revision;
	bool _is_notify;
	int _daily_reward_num;
	int _daily_reward_day;
    
    //quoc.nguyen update ver13 date: 13/10/2016
    INT_TIME _timeBuyOpenBox;

	//Lam Update ver5
	char _iap_dis_current[64];
	INT_TIME _iap_dis_time;
	INT_TIME _iap_dis_100_time;
	int _iap_dis_cur_trigger;
	bool _has_bought_iap_dis_cur,_has_bought_iap_dis_100;
	int _num_gem_used;
	void ActiveIapPackDiscount(bool is_pack100);
	bool _has_remove_ads_pop_up;
	bool _has_show_pine_promo;
	char _gem_text[128];


	//Kha update promo
	bool _has_touch_promo;
	char _game_promo_icon_id[128], _game_promo_link_store[128];
	int _game_promo_revision;
	bool _game_promo_has_show;
	int _game_promo_order;
	char _game_promo_deviceID[128];
	INT_TIME _game_promo_delay_show;


	int _user_level_reset;
	int _user_battle_just_reset;

	INT_TIME _sync_version;
	int _iAPs_numpack_spend;
	int _user_iap_level;
	enum enumiAPLevel {
		iAP_LEVEL_FREE,
		iAP_LEVEL_PREMIUM,
		iAP_LEVEL_ROYAL,
	};
	INT_TIME _iap_dis_100_time_skip_return;
	int _iap_100_min_trigger,_iap_100_gem_use_trigger;
	INT_TIME _hero_promo_time_delay;
	int _num_mass_auto_free;
	int _num_wheel_spin_free,_num_wheel_spin_premium;
	bool _is_new_user_ver15;

#if defined (ANDROID_OS)
	void CheckUnlockAllAchievements();

	void CheckLocalAndCloudSaveFile(bool isauto);
	void UpdateCloudSaveFile();
	void UpdateLocalSaveFile(Buffer* buffer);
	void ConfirmSyncSaveToCloud(bool isauto);
	void ConfirmSyncSaveFromCloud();
#endif
private:
	char _user_id[128];
	char _name[128];
	INT_TIME _coin;
	int _gem;
	
};


#endif
