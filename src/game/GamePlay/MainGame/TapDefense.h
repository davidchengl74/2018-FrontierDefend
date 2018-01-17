#include "../../GameCore/PineGame.h"
#include "../../GamePlay/GameObject/CThrowObject.h"

#ifndef __PineEntertainment__TAPDEF__
#define __PineEntertainment__TAPDEF__

#include <stdio.h>


class TDGame : public PineGame
{
public:
	int _loading_step;
	void UpdateAndRender();
	void Init();
	CAnimObject _anim_logo_loading;
	CAnimObject _anim_loading_char1;
	float _anim_loading_char1_x;
	CAnimObject _anim_loading_char2;
	float _anim_loading_char2_x;
	bool _anim_loading_toleft;
	int _logo_loading_frame_hold;
	int _logo_loading_frame_hold_percent;
	float _logo_loading_credit_x;
	float _logo_loading_about_x;
	int _logo_loading_render_credit_time;
	//////////////////////IMPLEMENT GAMEPLAY
	//--------------------Logo--------------------//
	bool _optimize_data;
	bool _auto_loading;
	void UpdateLogo();
	void RenderLogo();

	//--------------------Game Play--------------------//
	int _main_opac_change_state;
	void GamePlayRender(float x, float y, int opac);
	void GamePlayUpdate();
	bool GamePlayUpdateTouch();
    void UpdateAndRenderFreeGift();
	void FreeGiftRewardActive();
	void InitBattle(int battle,int wave);
	int _battle_current;
    int _hight_score;
    bool _new_hight_score;
	int _battle_old;
	int _wave_current;
	int _wave_max;
	int _battle_loop_from;

	CCastle _castle;
	int _level_current;
	void InterfaceRender(float x, float y);
	CDrawableManager _draw_manager_able;
	CDrawableManager _draw_manager_hero_able;
	CDrawableManager _draw_manager_enemy_effect;
	CHero _hero_inbattle_arr[NUM_MAX_HERO];
	int _num_hero_inbattle;
	int _num_enemy_inwave;
	int _is_use_auto_attack_free;
	int _is_use_auto_skill_free;
	struct EffectScrollMoon
	{
		float _x, _y;
		float _speed_scroll;
		float _speed_opac;
		int _opac;
		int _frameid;
		int _spriteid;
		int _state;
		int _max_target_y;
		void Init(int sprite, int frame, float x, float y, float speedscroll, float speedopac,int maxtary);
		void Add(float x,float y,int opac);
		void Render(float x, float y, int opac);
		void Update();
	};

#define NUM_MAX_EFFECT_MOON		10
	struct HeroButton
	{
		float _x, _y;
		int _hero_sprite;
		int _heroID;
		void Init(float x, float y, int herosprite, int heroid, float poweratt, float powerskill, float limitbreak);
		void Modify(int herosprite, int heroid, float poweratt, float powerskill, float limitbreak);
		void Render(float x, float y, int opac);
        void RenderSkill(float x, float y, int opacity);
		void Update();
		int _power_skill;
		int _power_attack;
		int _clip_pa_current;
		int _clip_pa_target;
		float _clip_ps_current;
		int _clip_ps_target;
		float _speed_ps_clip;
		int _effect_hight_light_opac;
		bool _effect_hight_light_opac_max;
		int _effect_hight_light_auto;
		bool _effect_hight_light_auto_max;
		bool _auto_attack;
		bool _full_pa;
		bool _full_ps;
		int _is_use_auto_att;
		int _is_use_auto_skill;
		CAnimObject _anim;
		bool _active;
		float _effect_zoom_scale;
		float _effect_full_ps_scale;
		bool _effect_full_ps_scale_start;
		bool _effect_full_ps_scale_max;
		bool _effect_active_ps_scale_start;
		EffectScrollMoon _effect_moon[NUM_MAX_EFFECT_MOON];
		CEffectFire _full_power_effect_fire;
		CEffectFire _full_power_skill_fire;
		float _effect_full_skill_rotate;
		void AddEffect();
	};
	HeroButton _ingame_hero_button[NUM_MAX_HERO_INBATTLE];
	void HeroButtonActive(int index,int type);
    
	int _effect_skill_add_energy[3];

	int _ingame_coin;
	int _ingame_gem;
	CUser _user;
	void AddHeroesDeploy(int heroid);
	void ModifyHeroesDeploy(int heroid);
	CScrollNumber _coin_interface;
	float _effect_scale_icon_coin;
	bool _effect_scale_icon_coin_start;
	float _effect_scale_icon_gem;
	bool _effect_scale_icon_gem_start;
	CItemFly _effect_item_coin_fly;
	int _bg_spriteid;
	int _bg_underground_spriteid;
	int _bg_spriteid_next;
	bool _is_night;
	int _num_tap_in_agame;
	void UnlockNewHero(int event_type);
	void ArchievementSubmit();
	int _has_double_coin_timer;
	Pine_Date_Time _fairy_double_coin_time;
	Pine_Date_Time _starter_double_coin_time;
	Pine_Date_Time _starter_pack_time;
	CAnimObject _anim_network;
	
	CAnimObject _anim_network_quest;
	int _bg_music_current;
	int _bg_music_volum;
	bool _bg_change_music;

	int _mass_auto_timing,_mass_auto_opac,_mass_auto_time;
	float _mass_auto_scale;
	bool _mass_auto_active;
	int _mass_auto_touch_id;
	void MassAutoRender(float x, float y, int opac);
	void MassAutoUpdate();
	void MassAutoInit();
	void MassAutoActive();
	Button _mass_auto_button;
	int _mass_opac_full;

	//--------------------Ex Function--------------------//
	CWeapon _weapon[NUM_MAX_WEAPON];
	void WeaponInit();
	void WeaponRender(float x, float y);
	void WeaponUpdate();
	void WeaponResetLevel();

	CCharacter _enemy[NUM_MAX_ENEMY];
	void CharacterInit(int level);
	void CharacterRender(float x, float y);
	void CharacterUpdate();

	int GetEnemyIndexNearest(bool bird);
	int GetEnemyIndexHPLower();
	int GetEnemyIndexHPUpper();
	int GetEnemyIndexRandom(int index);
	void LoadSpriteOptimize(int sprite,bool alias,bool color);
	static const int _character_sprite[NUM_MAX_ENEMY];
	static const int _hero_sprite[NUM_MAX_HERO];
	static const int _weapon_sprite[NUM_MAX_WEAPON+1];
	static const int _skill_sprite[NUM_MAX_SKILL];
	static const int _castle_sprite[NUM_MAX_CASTLE_LEVEL];
	static const int _background_sprite[NUM_MAX_BACKGROUND];
	static const int _background_dark_sprite[NUM_MAX_BACKGROUND];
	static const int _underground_sprite[NUM_MAX_BACKGROUND];
	struct EffectHPLost
	{
		float _x, _y;
		INT_TIME _damage;
		int _damage_type;
		int _count_frame;
		int _opac;
		float _scale;
	};

#if defined (ANDROID_OS)
#define NUM_EFFECT_HP_LOST      15
#else
#define NUM_EFFECT_HP_LOST      40
#endif
	EffectHPLost _effect_hp_lost[NUM_EFFECT_HP_LOST];
	void AddEffectHPLost(INT_TIME damage, float x, float y, int damagetype);
	void RenderEffectHPLost();
	void UpdateEffectHpLost();
	void RemoveEffectHPLost(int index);
	int _num_effect_hp_lost;

	void MultitouchOnWin(int key);
	float _effect_hero_skill_scale[NUM_MAX_HERO];
	int  _effect_hero_skill_id[NUM_MAX_HERO];
	int  _effect_hero_skill_state[NUM_MAX_HERO];
	void EffectHeroSkillInit();
	void EffectHeroSkillActive(int skillid);
	void EffectHeroSkillUpdate();
	void EffectHeroSkillEnd(int skillid);

#define NUM_MAX_EFFECT_TOUCH_FIRE		10
	CEffectFire _touch_effect_fire[NUM_MAX_EFFECT_TOUCH_FIRE];
	
	void TouchEffectFireInit();
	void TouchEffectFireRender(float x,float y,int opac);
	void TouchEffectFireUpdate();
	void TouchEffectFireAdd(float x,float y);
	void EnemyEffectBeHitRender(int index);
	void ChangeBackgroundUpdate();
	void ChangeBackgroundRender();
	bool _is_changing_background;
	int _changing_background_opac;
	bool _changing_background_opac_max;
	bool _is_changing_background_night;
	int _changing_background_night_opac;
	int GetBackground();
#define NUM_MAX_NOTIFY_OBJETC		4

#define NOTIFY_TYPE_NEW				0
#define NOTIFY_TYPE_ALERT			1
	struct Notify
	{
		float _x, _y;
		float _scale;
		CAnimObject _anim;
		int _state;
		int _spriteid;
		int _frameid;
		bool _just_lose;

		void Init(int sprite, int frame, int anim, float x, float y, float scale);
		void Render(float x, float y);
		void Update();
		void Active();
		void Disable();
		void SetType(int type);
	};
	Notify _notify_new[NUM_MAX_NOTIFY_OBJETC];
	void SetNotifyNew();
	void InitNotifyNew();
	void RenderNotifyNew(float x, float y);
	void UpdateNotifyNew();
	int _num_hero_deployed;
	void ResetFlagNotifyNew(bool justlose);

	int GetNumWeaponUnlock();
	int GetDamageWeaponBasic();
	int GetDamageHeroesBasic();
	CGiftBox _gift_box;

	CEffectFireUP _gift_box_line;
#define GIFT_REWARD_NUM_PARTICAL		100
#define GIFT_REWARD_NUM_MAX				5
#define GIFT_REWARD_STATE_NORMAL		0
#define GIFT_REWARD_STATE_START			1
#define GIFT_REWARD_STATE_END			2
#define GIFT_REWARD_STATE_FREE			3
	struct GiftReward
	{
		float _x, _y;
		float _tarx, _tary;
		float _angle;
		float _speed_angle;
		int _state;
		int _spriteid;
		int _frame;
		int _num_frame;
		int _value;
		bool _dir;
		float _speed;
		float _deltax;
		float _speed_deltax;
		float _deltay;
		float _speed_deltay;
		int _type;
		CShadow _partical[GIFT_REWARD_NUM_PARTICAL];
		void Init(int type, int sprite, int frame, int numframe, float deltaspeed);
		void Render(float x, float y);
		void Active(float x, float y, float tarx, float tary, int value);
		void Update();
		bool IsFree();
		void AddParticel(float x, float y);
	};

	GiftReward _gift_reward[GIFT_REWARD_NUM_MAX];
	void GiftRewardInit();
	void GiftRewardRender(float x,float y);
	void GiftRewardUpdate();
	void GiftRewardActive(float x, float y, float tarx, float tary, int value);
	void EnemySetTargetFocus();
	void AddHPStatue(INT_TIME hp);
	bool HasEventAvailable(int event_type);
#define TOUCH_TYPE_INGAME			0
#define TOUCH_TYPE_MENU_INGAME		1
#define TOUCH_TYPE_MENU_INFO		2
#define TOUCH_TYPE_QUEST			3
#define TOUCH_TYPE_SETTING			4
#define TOUCH_TYPE_FREE_GIFT        5
	void ClearAllTouchUp(int type);
	//--------------------Design Function--------------------//
	CGameDesign _game_design;
	int GetDesignCastleGeneral(int id, int param);
	float GetDesignCastleFormulaFloat(int id,int level);
	const char* GetDesignCastleName(int id, int param);
	INT_TIME GetDesignCastleUpgradeInfo(int id, int level, int param);
	int GetDesignEnemyCreationGeneral(int id, int param);
	int GetDesignEnemySkillGeneral(int id, int param);
	float GetDesignEnemyCreationGeneralFLoat(int id, int param);
	const char* GetDesignEnemyCreationString(int id, int param);
	int GetDesignBattleGeneral(int battle, int wave, int param);
	INT_TIME GetDesignBattleHPandDamage(int battle, int wave, int param);
	const char* GetDesignBattleString(int battle, int id, int param);
	int GetDesignGeneralInfo(int id);
	int GetDesignHeroGeneral(int id, int param);
	float GetDesignHeroGeneralFloat(int id, int param);
	int GetDesignHeroIndex(int id);
	const char* GetDesignHeroName(int id);
	INT_TIME GetDesignHeroInfo(int id,int level, int param, int rarity);
	float GetDesignHeroFormulaFloat(int id, int level);
	int GetEnemyCreationIndex(const char* enemyID);
	int GetNumEnemyInWave(int battle, int wave);
	int GetDesignSkillInfo(int id, int param);
	const char* GetDesignSkillString(int id, int param);
	int _row_start_inwave;
	int GetDesignBackground(int id, int param);
	int GetDesignQuestValue(int id, int param, bool daily);
	const char* GetDesignQuestString(int id, int param, bool daily);
	int GetDesignRelics(int id, int group, int param);
	const char* GetDesignRelicsString(int id, int group, int param);
	int GetDesignRelicIndex(int id, int group);
	int GetDesignRelicsSprite(int id, int param);
	const char* GetDesignRelicsSpriteString(int id, int param);
	int GetDesignRelicsSpriteIndex(const char* relicName);
	int GetDesignQuestSprite(int id, int param);
	const char* GetDesignQuestSpriteString(int id, int param);
	int GetDesignQuestSpriteIndex(const char* questName);
	int GetDesignIAP(int id, int param, bool discount);
    int GetDesignIapIndex(int id, int param, bool discount);
	float GetDesignIAPPrice(int id, int param,bool discount);
	const char* GetDesignIAPString(int id, int param, bool discount);
	int GetDesignTreasure(int id, int param, bool chest);
	float GetDesignTreasureInfo(int id, int param, bool chest);
	int GetDesignChest(int id, int param);
	float GetDesignChestFloat(int id, int param);
	int GetDesignFairyReward(int id, int param);
	int GetQuestIndex(int group, int id, bool daily);
	int GetNumOfQuest(int group);
	int GetNumOfGroupQuest();
	int GetDailyQuestRandom();
	void DailyQuestAdd(int group);
	int GetDesignWheelInfo(int id, int param);
	int GetDesignFreeGift(int id, int param);
	int GetDesignIapTrigger(int id,int param);
	int GetDesignWheelTime(int id);
	int GetDesignPetInfo(int id, int param);
	int GetDesignDailyReward(int id, int param);
	struct StarAnim
	{
		float _x, _y;
		float _rotate;
		float _speed_rotate;
		float _scale;
		float _speed_scale;
		bool _is_scale_max;
		float _scale_max;
		int _count_frame_hold;
		int _hold_frame;
		int _spriteid;
		int _frameid;
		int _state;
		void Init(float x, float y, int sprite, int frame, float scalemax, int holdframe);
		void Active(float x, float y, float speedscale, float speedrotate);
		void Render(float x, float y);
		void Update();
		void Disable();
	};
#define NUM_MAX_EFFECT_STAR_ANIM		12
	StarAnim _effect_star_anim[NUM_MAX_EFFECT_STAR_ANIM];
	void StarAnimInit();
	void StarAnimRender(float x,float y);
	void StarAnimUpdate();
	void StarAnimActive(int index, float x, float y, float speedscale, float speedrotate);
	void StarAnimDisable(int index);
	
	//--------------------Menu BUTTON Function--------------------//
#define NUM_BUTTON_MENU				8

#define MENU_BUTTON_LEADERBOARD		0
#define MENU_BUTTON_ACHIEVEMENT		1
#define MENU_BUTTON_SOUND			2
#define MENU_BUTTON_MUSIC			3
#define MENU_BUTTON_LINK_TW			4
#define MENU_BUTTON_LINK_FB			5
#define MENU_BUTTON_OPTIONS			6
#define MENU_BUTTON_WHEEL			7

	Button _menu_button[NUM_BUTTON_MENU];
    Button _google_play_menu[3];
    int _exit_google_touch_id;
	void MenuRender(float x, float y);
	void MenuInit();
	bool MenuUpdateTouch();
	float _menu_button_scrolly;
	bool _menu_button_active;
    bool _menu_button_scrolling;

#define NUM_BUTTON_MENU_INGAME			4
#define MENU_INGAME_BUTTON_GATE			0
#define MENU_INGAME_BUTTON_HEROES		1
#define MENU_INGAME_BUTTON_RELICS		2
#define MENU_INGAME_BUTTON_SHOP			3
	Button _menu_ingame_button[NUM_BUTTON_MENU_INGAME];
	void MenuIngameRender(float x, float y);
	void MenuIngameInit();
	bool MenuIngameUpdateTouch();
#define NUM_BUTTON_INGAME			9
#define INGAME_BUTTON_TAP1			0
#define INGAME_BUTTON_TAP2			1
#define INGAME_BUTTON_TAP3			2
#define INGAME_BUTTON_AUTO1			3
#define INGAME_BUTTON_AUTO2			4
#define INGAME_BUTTON_AUTO3			5
#define INGAME_BUTTON_SKILL1			6
#define INGAME_BUTTON_SKILL2			7
#define INGAME_BUTTON_SKILL3			8

	Button _ingame_button[NUM_BUTTON_INGAME];
	void IngameButtonRender(float x, float y);
	void IngameButtonInit();
	bool IngameButtonUpdateTouch();
#define NUM_BUTTON_IAP		2
#define IAP_BUTTON_COIN			0
#define IAP_BUTTON_GEM				1
	Button _iap_button[NUM_BUTTON_IAP];
	void IapRender(float x, float y);
	void IapUpdate();
	void IapInit();
	bool IapUpdateTouch();
	//--------------------Ingame Menu--------------------//
	void IngameMenuRender(float x, float y, int opac);
	void IngameMenuUpdate();
	void IngameMenuInit();
	bool IngameMenuUpdateTouch();
	int _ingame_menu_scrolly;
	int _ingame_menu_frame_idle;
	float _ingame_menu_scroll_speed;
	bool _ingame_menu_close;
	int _ingame_menu_type;
	int _ingame_fill_opac;
	int _ingame_menu_fill_opac;
	int _ingame_menu_close_touch_id;
	int _ingame_menu_num_item;
	int _ingame_menu_max_item_scroll;
	CScrollBar _ingame_menu_scroll;
	int _ingame_menu_scroll_touch_id;
#define EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL		-1
#define EFFECT_SCALE_TEXT_BUTTON_STATE_START		0
#define EFFECT_SCALE_TEXT_BUTTON_STATE_END			1
#define EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END	2
	struct MenuInfo
	{
		float _x, _y;
		int _level;
		INT_TIME _value;
		char _value_text[128];
        int _stars;
		INT_TIME _value_plus;
		char _value_plus_text[128];
		int _cost_upgrade;
		INT_TIME _value_up;
		char _value_up_text[128];
		int _price;
		int _id;
		int _value2;
		bool _is_lock;
		bool _deployed;
		int _index;
		int _level_unlock;
		char _name[128];
		char _descript[256];
		char _id_string[64];
		char _coin_text[128];
		Button _button_buy;
		bool _banner;
		int _unit_bounce;
		void Init(float x, float y, int indexitem, bool banner);
		
		void Render(float x, float y);
		void Modify(int indexitem);
		void Update();
		bool UpdateTouch();
		int _card_touch_id;
		bool _card_touch_block;
		int _touch_y;
		int _touch_x;
		float _scale_text_button;
		int _scale_text_button_state;
		bool _has_touch;
		int _spriteid;
		int _frameid;
		Notify _notify_new;
		CAnimObject _effect_levelup;
		CAnimObject _anim_network;
		bool _effect_levelup_start;
		bool _is_new;
		void AddNew(float x, float y, int indexitem);
	};
#define NUM_MAX_MENU_ITEM		300
	MenuInfo _menu_info_arr[NUM_MAX_MENU_ITEM];
	void CastleInfoRender(float x, float y, int opac);
	void CastleInfoUpdate();
	bool MenuInfoUpdateTouch();
	float _castle_info_scrolly;
	float _castle_info_scroll_speed;
	float _castle_info_scroll_speed_delta;

	void HeroesButtonRender(float x, float y);
	void HeroesButtonUpdate();
	bool HeroesButtonUpdateTouch();

	struct HeroesDeploy
	{
		float _x, _y;
		int _hero_sprite;
		int _heroID;
		void Init(float x, float y, int herosprite, int heroid, INT_TIME damage);
		void Modify(int herosprite, int heroid, INT_TIME damage);
		void Render(float x, float y, int opac);
		void Update();
		bool UpdateTouch();
		float _effect_zoom_scale;
		bool _active;
		int _touch_id;
		INT_TIME _damage;
	};
	HeroesDeploy _heroes_deploy_arr[NUM_MAX_HERO_INBATTLE];
	void HeroDeployRender(float x, float y, int opac);
	void HeroDeployUpdate();
	bool HeroDeployUpdateTouch();
	void HeroDeployRemove(int heroid);
	void HeroDeployActive(int heroid, int slotnumber);

	CItemRelic _items_relics[NUM_MAX_ITEM_RELICS];
	bool SummonRelics();
	void ModifyInfo(int group, int id);
	int _num_max_item_relics;
	int _num_max_hero;
	int GetRelicsAttackPoint(int group, int interactiveid);
	int GetRelicsAttackBasic(int group, int interactiveid);
	int GetRelicsAttack(int group, int interactiveid);
	int GetRelicsAttackSpeed(int group, int interactiveid);
	int GetRelicsMana(int group, int interactiveid);
	int GetRelicsDuration(int group, int interactiveid);
	int GetRelicsSkillDuration(int group, int interactiveid);
	int GetRelicsCritical(int group, int interactiveid);
	int GetRelicsAOE(int group, int interactiveid);
	int GetRelicsCostDecrease(int group, int interactiveid);
	int GetRelicsUnitBounce(int group, int interactiveid);
	int GetRelicsMoveSpeed(int group, int interactiveid);
	int GetRelicsHP(int group, int interactiveid);
	//Lam Update
	int GetRelicsUpgradeRarity(int interactiveid);
	int GetHeroSummonRandom();
	void ShopFuncActive(int id, int value);
    void ShopIAPFuncActive(int id, bool discount);
	void ReInitHero();
	void ReInitRelics();
	void ReInitShop();
	int CheckHeroIDInBattle(int heroid);
    //Pine_Date_Time _iap_discount_time;
    Pine_Date_Time _iap_starter_time;
	void RelicsReset();
	void HeroesReset();
    CPushNotification _pushNotification;
	int _ingame_num_item_relics;
	void AddMenuInfo(int group, int id);
	int GetHeroIndex(int heroid);
	Pine_Date_Time _watch_ads_time;
    Pine_Date_Time _timeBuyOpenBox;
	CDialogManager _dialogMng;
	void ProcessingDialogYesNo(int context, int index);
	int _dialog_process_type;
	void ProcessingDialogOK(int context);
	CAnimObject _ingame_menu_anim_border;
	//--------------------Effect--------------------//
#define ITEMS_NULL			-1
#define ITEMS_EMPTY			0
#define ITEMS_DROP			1
#define ITEMS_FLY			2
#define ITEMS_FLY_ROBED		3

#define ITEMS_TYPE_COIN		0
#define ITEMS_TYPE_GEM		1
    
#ifndef MAX_ITEMS_DROP_INGAME
#define MAX_ITEMS_DROP_INGAME		500
#endif
	struct Item
	{
		int _count_frame_hold;
		float _x, _y;
		float _targetx, _targety;
		int _type;
		int _state;
		float _alphax;
		float _alphay;
		int _speed;
		int _delta;
		int _speedy;
		int _value;
		int _opac;
		float _alpha_knock;
		float _scale;
		int _rotate;
	};
	int _num_item_collected;
	int _items_coin_min;
	Item _arr_item[MAX_ITEMS_DROP_INGAME];
	void ItemsInit();
	void ItemsAddNew(int type, float x, float y, float tarx, float tary, int value);
	void ItemsRemove(int index);
	void ItemsRender(float x, float y);
	void ItemsUpdate();
	void ItemForceEnd();
	int _shake_effectx;
	int _shake_effecty;
	
	//--------------------Quest--------------------//
#define NUM_BUTTON_QUEST			1
#define QUEST_BUTTON_CLOSE			0
	Button _quest_button[NUM_BUTTON_QUEST];
	CQuest _quest_info[NUM_MAX_QUEST_GROUP];
	void QuestRender(float x, float y, int opac);
	void QuestUpdate();
	bool QuestUpdateTouch();
	void QuestRemoveIndex(int group, bool daily);
	int _quest_info_num;
	CScrollBar _quest_menu_scroll;
	int _num_max_quest;
	int _daily_quest_current;
	CEffectNotify _effect_notify_menu_button[NUM_BUTTON_MENU];
	int _num_tap_in_second;
	int _time_tap_in_second;
	int _num_kill_monster_in_second;
	int _time_kill_monster_in_second;
	bool _is_hacked_time;
	void QuestReset();
	//--------------------EFFECT--------------------//
	void EffectRewardRender(float x, float y);
	void EffectRewardUpdate();
	INT_TIME _boss_reward_coin;
	int _boss_reward_type;
	int _boss_reward_gem;
	int _effect_reward_count_frame;
#define EFFECT_REWARD_JUMP_STATE_NONE			0
#define EFFECT_REWARD_JUMP_STATE_END			1
#define EFFECT_REWARD_JUMP_STATE_HOLDING		2
#define EFFECT_REWARD_JUMP_STATE_START			3
#define EFFECT_REWARD_JUMP_STATE_OPENNING		4
#define EFFECT_REWARD_JUMP_STATE_OPENED			5


	struct EffectRewardJump
	{
		float _x, _y;
		float _targetx, _targety;
		int _type;
		int _state;
		float _alphax;
		float _alphay;
		int _speed;
		int _delta;
		int _speedy;
		float _alpha_knock;
		int _spriteid;
		int _frameid;
		float _scale;
		void Init(int type);
		void Active(int sprite, int frame, INT_TIME value, float x, float y, float tarx, float tary);
		void Render(float x, float y);
		void Update();
		void SetState(int state);
		int _count_frame_hold;
		CAnimObject _anim1;
		CAnimObject _anim2;
		int _glow_rotate;
		INT_TIME _value;
		int _value_min;
		int _opac;
	};
	EffectRewardJump _boss_reward;
	//--------------------Treasure--------------------//
    static int  OPENBOX_NUM_BUTTON;
#define OPENBOX_NUM_BUTTON_MAX (2)
	Button _openbox_button[OPENBOX_NUM_BUTTON_MAX];
	void OpenBoxRender(float x,float y,int opac);
	void OpenBoxUpdate();
	bool OpenBoxUpdateTouch();
	void BoxItemShuffle();
	void BoxItemInit(bool free);
	void SwapItem(int index1, int index2);
	bool OpenBoxUpdateTouchItem();
    int _frame_double_box;
	struct ItemsReward
	{
		int _id; 
		int _num;
		int _group;
		void Init(int id,int num,int group);
		void Reset();
	};
	ItemsReward _arr_item_reward[3];
	void OpenBoxAddItem(int id, int num,int group);
	void OpenBoxItemSwap(int index1, int index2);
	int GetItemBoxIndex(int percent);
	ItemBox _arr_box_item[NUM_MAX_BOX_ITEM];
	int _item_box_index[NUM_MAX_BOX_ITEM];
	bool _open_box_force_open;
	int _open_box_count_complete;
	int _openning_opac;
	int _open_box_text_opac;
	int _item_box_count_reward;
	int _retry_open_state;
	int _shuffle_item_current;
	float _shuffly_speed;
	int _shuffle_index_be_call;
	bool _game_state_changing;
	int _opac_change_game_state;
	bool _has_retry_openbox;
	int _reward_coin;
	int _reward_gem;
	int _upgrade_count_frame_add_coin;
	int GetChestIndexRandom(int percent, bool forceitem);
	bool _open_box_close;
	int _open_box_fill_opac;
	int _open_box_state_old;
	void ModifyRelicItems(int group, int id,bool lock);
	int _relics_num_of;

	int _time_openbox_countdown;
	//--------------------Tutorial--------------------//
	void TutorialInit();
	void TutorialRender(float x, float y);
	void TutorialUpdate();
	bool TutorialUpdateTouch();
	CAnimObject _tutorial_anim_hand;
	int _tutorial_opac;
	int _tutorial_touch_id;
	int _tutorial_step;
	int _num_hit_tutorial;
	bool _tutorial_step_ready;

	//--------------------Wheel--------------------//
#define WHEEL_STATE_INIT		0
#define WHEEL_STATE_SPIN_START		1
#define WHEEL_STATE_SPIN_END		2
#define WHEEL_STATE_CLAIM			3
#define WHEEL_STATE_END				4
#define WHEEL_STATE_FORCE_END		5
#define WHEEL_STATE_POP_UP_END		6
#define WHEEL_STATE_REINIT			7
#define WHEEL_TYPE_REWARD_NONE		0

#define WHEEL_TYPE_REWARD_GEM				1
#define WHEEL_TYPE_REWARD_COIN				2
#define WHEEL_TYPE_REWARD_RELIC				3
#define WHEEL_TYPE_REWARD_AUTO_MASS			4
#define WHEEL_TYPE_REWARD_AUTO_ATT			5
#define WHEEL_TYPE_REWARD_AUTO_SKILL		6

#define WHEEL_NUM_BUTTON		2
#define WHEEL_BUTTON_SPIN		1
#define WHEEL_BUTTON_CLAIM		0

	Button _wheel_button[WHEEL_NUM_BUTTON];
	void WheelRender(float x,float y,int opac);
	void WheelUpdate();
	bool WheelUpdateTouch();
	bool WheelIsReady();
	int _wheel_free_battle_target;
	int _num_wheel_spin_available;
	int _num_wheel_render;
	int _wheel_count_frame_render;
	float _wheel_rotate_speed;
	float _wheel_rotate_delta;
	float _wheel_rotate;
	float _wheel_rotate_target;
	float _wheel_rotate_target_delta;
	float _wheel_scale;
	bool _wheel_scale_max;
	int _wheel_num_rotate;
	int _wheel_reward;
	char _wheel_reward_text[128];
	int _count_frame_hold_end;
	int _wheel_type_reward;
	int _wheel_state;
	int _wheel_touch_id;
	CItemRelic _wheel_relic;
	int WheelGetRandomReward();
	bool RandomRelics();
	bool _wheel_has_value;
    static bool _auto_wheel;
	CEffectFire _wheel_reward_fire;
    Pine_Date_Time _wheel_time;
	CAnimObject _wheel_light;
	//--------------------State GameOver--------------------//
#define GAME_OVER_STATE_INIT		0
#define GAME_OVER_STATE_RUN			1
#define GAME_OVER_STATE_DEFEAT		2
#define GAME_OVER_STATE_HOLD		3
#define GAME_OVER_STATE_END			4

	void GameOverRender(float x, float y, int opac);
	void GameOverUpdate();
	bool GameOverUpdateTouch();
	bool _gameover_close;
	int _gameover_state;
	int _gameover_defeat_rotate_frame_speed;
	int _gameover_change_state_opac;
	float _gameover_defeat_posy;
	float _gameover_defeat_posy_scrollback;
	float _gameover_defeat_rotate;
	float _gameover_defeat_rotate_speed;
	float _gameover_character_posx1;
	float _gameover_character_posx2;
	float _gameover_character_posy;
	CAnimObject _gameover_character1;
	CAnimObject _gameover_character2;
	CAnimObject _gameover_defeat_smoke;
	CAnimObject _gameover_defeat_smoke_left;
	CAnimObject _gameover_defeat_smoke_right;
	int _gameover_touch_id;
	int _gameover_touch_opac;
	float _effect_castle_die_shakex;
	float _effect_castle_die_shakey;
	float _effect_castle_die_scrolly;
	int _gameover_fill_opac;
	CAnimObject _gameover_anim_castle_die_stone;
	CAnimObject _gameover_anim_castle_die_stone1;
	CAnimObject _gameover_anim_castle_die_smoke;
	CAnimObject _gameover_anim_castle_die_smoke1;
	CAnimObject _gameover_anim_castle_die_smoke2;
	int _gameover_frame_render_anim;
	//--------------------State MainMenu--------------------//
#define MAIN_MENU_NUM_BUTTON		1
#define MAIN_MENU_BUTTON_START		0

	Button _mainmenu_button[MAIN_MENU_NUM_BUTTON];
	void MainMenuRender(float x, float y, int opac);
	void MainMenuUpdate();
	bool MainMenuUpdateTouch();
	bool _mainmenu_just_in;
	CAnimObject _anim_logo;

	//////////////////////PORT GAME/////////
	PinePoint _point_o, _point_right_bottom;
	void MeasureButtonTemp(HeroButton* button);
	void MeasureButton(Button* button);
	void MeasureButton(Button* button, int anchor);
	void MeasureButtonX(float posx, Button* button, BYTE anchor_horizonal);
	void MeasureButtonY(float posy, Button* button, BYTE anchor_vertical);
	PinePoint MeasureFrame(CSprite* sprite, UINT32 frameid);
	void MeasureAnim(CAnimObject* obj);
	PinePoint MeasureFrame(CSprite* sprite, UINT32 frameid, float scalex, float scaley);
	PinePoint MeasureFrame(CSprite* sprite, UINT32 frameid, BYTE anchor);
	float _screen_width;
	float _screen_height;
	float _port_scale_x;
	float _port_scale_y;
	//////////////////////PORT GAME/////////
	//--------------------Rate Us--------------------//
#define RATEUS_NUM_BUTTON			2
#define RATEUS_BUTTON_RATE			0
#define RATEUS_BUTTON_SKIP			1

#define RATE_US_TYPE_NONE			0
#define RATE_US_TYPE_RATE_APP		1
#define RATE_US_TYPE_TW_FOLLOW		2
#define RATE_US_TYPE_FB_LIKE		3

	Button _rate_us_button[RATEUS_NUM_BUTTON];
	void RateUsInit();
	void RateUsRender(float x, float y);
	void RateUsUpdate();
	bool RateUsUpdateTouch();
	float _rate_us_scale;
	bool _rate_us_scale_max;
	bool _rate_us_active;
	bool _rate_us_close;
    INT_TIME _rate_us_time;
	Pine_Date_Time _iap_time_out;
	int _rate_us_type;
	//--------------------Victory--------------------//
	void VictoryInit();
	void VictoryReInit();
	void VictoryActive();
	void VictoryRender(float x, float y);
	void VictoryUpdate();
	CAnimObject _anim_victory;
	int _victory_opac;
	bool _victory_active;
	int _victory_active_effect_fire;
#define NUM_MAX_EFFECT_VICTORY_FIRE		6
	CEffectFire _victory_effect_fire[NUM_MAX_EFFECT_VICTORY_FIRE];
    bool _has_watched_ads;
    bool _has_ads_free_gift;
    bool _system_popup_showed;
	int _skipframe_show_reward;
	int _free_gift_type;

	enum enumFreeGiftType
	{
		FREE_GIFT_TYPE_COIN1,
		FREE_GIFT_TYPE_COIN2,
		FREE_GIFT_TYPE_COIN3,
		FREE_GIFT_TYPE_GEM,
	};

	//--------------------Invitation Input--------------------//
#define INVITATION_NUM_BUTTON			2
#define INVITATION_BUTTON_SKIP			0
#define INVITATION_BUTTON_OK			1

	Button _invitation_button[INVITATION_NUM_BUTTON];
	bool _invitation_active;
	float _invitation_scale;
	bool _invitation_scale_max;
	bool _invitation_close;
	void InvitationInit();
	void InvitationRender(float x, float y);
	void InvitationUpdate();
	bool InvitationUpdateTouch();
    char _ivitation_code_input[24];
	void UpdatePoupReward();
	bool HasDownLoadMoreGame();

	CAnimObject _down_moregame_glow;
    bool _event_notify;

	//Update Ver12/2015
#define OFFLINE_RW_COLLECTED_TYPE_NONE			0
#define OFFLINE_RW_COLLECTED_TYPE_WAITING		1
#define OFFLINE_RW_COLLECTED_TYPE_DONE			2
	void GetRewardOffline();
	int _offline_reward_collected;
	int _daily_reward_collected;
	bool _warning_notify_hacker;
#define INPUT_CODE_BUTTON_NUM			1
#define INPUT_CODE_BUTTON_ENTER			0
	Button _input_code_button[INPUT_CODE_BUTTON_NUM];
	void InputCodeRender(float x, float y);
	void InputCodeUpdate();
	bool InputCodeUpdateTouch();
    void ClearAllHeroDeploy();

#define DAILY_REWARD_NUM_BUTTON			1
#define DAILY_REWARD_BUTTON_CLAIM		0

#define DAILY_REWARD_NUM				7
    int _button_free_gift_touch_id;
	Button _daily_button[DAILY_REWARD_NUM_BUTTON];
	bool HasDailyReward();
	bool _daily_reward_active;
	void DailyRewardInit();
	void DailyRewardRender(float x,float y);
	void DailyRewardUpdate();
	bool DailyRewardUpdateTouch();
	float _daily_reward_effect_scale;
	bool _daily_reward_close;
	bool _daily_reward_big_rw;
	int _daily_reward_type;
	INT_TIME _daily_reward_coin;
	int _daily_reward_gem;
	int _daily_reward_frameid;
	CItemRelic _daily_reward_relic;
	struct DailyReward
	{
		int _type;
		INT_TIME _coin;
		int _gem;
		int _frameid;
		char _text[32];
		void Init(int type, INT_TIME coin, int gem, int frame, char*text);
	};
	DailyReward _daily_reward[DAILY_REWARD_NUM];
	int _local_time_cach;
    int _count_times_showAds;
    int _stateAppDownload;
    int _play_game_num;
    
    //quoc.nguyen
    int _countTimeShowVideoAds;
    bool _openShopFromGate;
    int  _be_damage_opacity;
    
    bool _isOpenGooglePlay;
    void GooglePlayUpdate();
    void GooglePlayRender();

	bool showadtutorial;

	int _time_showads_count;
	void ConvertCoinToString(INT_TIME coin, char* string);
	int _count_frame_check_quest;
	void ConvertMoneyInbalace(INT_TIME money, char* string, INT_TIME min_money = 1000000, int len_mod = 1);

	//Lam Update ver5
	void UpdateAndRenderIAPDis();
	INT_TIME _iap_dis_cur_timer,_iap_dis_100_timer;
	int _iap_dis_button_id;
	void UpdateAndRenderPinePromo();
	int _pine_promo_touch_id;
	float _pine_promo_render_x;

	void UpdateAndRenderPrestige();
	int _prestige_touch_id;

	INT_TIME _iap_dis_coin;
	int _iap_dis_gem, _iap_dis_autoatt, _iap_dis_autoskill;
	char _iap_dis_price[64];
	char _iap_dis_idstr[64];
	char _iap_dis_coin_text[64];
	void GetValueIapDis(char *idstr);
	float _iap_glow_rotate;
	int _count_frame_playsound_orc_die;
	int _count_frame_playsound_ore_damaged;
	int _count_frame_playsound_coin_colleted;
	int _count_frame_playsound_spide_born;
	int _pine_promo_star_timer;
	int _pine_promo_star_index;
	float _pine_promo_star_rotate;
	float _pine_promo_star_scale;
	int _pine_promo_star_state;
	bool _just_lose;
	
	INT_TIME _time_out_game;
	void GetRewardEarnOffline();
	INT_TIME _reward_earning_off;
	char _reward_earning_off_text[128];
	int _reward_earning_off_type;
	int GetLevelUnlockNewHero(int rar);

	//TopeBox_PromoGame _topebox_game;
	//float _topebox_game_scrollEff;

	void ResetInit();
	void ResetActive();
	int _reset_gem_reward, _reset_coin_reward;
	int _reset_hero_relicid_reward;
	int _reset_weapon_relicid_reward;
	int _reset_battle_target, _reset_level_skip_next;
	char _reset_gem_reward_text[128], _reset_coin_reward_text[128];
	void RelicsDefault();

	char _reset_des[1024];
	void UpgradeRarity(int heroID);
	bool _tutorial_buy_relic_ready;
	int _count_frame_GetRewardOff;
	void PushNotify();
	int _time_waiting_show_ads;
	int _time_waiting_free_gift;
	bool ReviveActive();
	bool _has_revive_in_battle;
	int GetUseriAPsLevel();
	
	int _relic_special_id, _relic_special_frameid, _relic_special_cost;
	int _relic_special_heroindex;

	void GetRelicSpecialDiscount();
	void RelicSpecialActive();
	void UpdateShowRelicSpecial();
	int _auto_hold_key;
	bool _show_popup_offline;
	bool _offline_earning_received;
	void FirebaseLogIapPack(int type);
	enum enumiAPType {
		iAP_TYPE_100,
		iAP_TYPE_BATTLE,
	};
	bool _need_log_double_chest, _need_log_freegift, _need_log_mass_click, _need_log_daily_reward;
};
#endif  // __PineEntertainment__TAPDEF__ //
