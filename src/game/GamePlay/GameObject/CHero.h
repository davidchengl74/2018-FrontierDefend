#ifndef _HERO_
#define _HERO_

#include "../../Lib/DataType/CType.h"

#define HERO_TYPE_RANGE_MELEE		0
#define HERO_TYPE_RANGE_RANGE		1

#define HERO_SKILL_NONE					-1
#define HERO_SKILL_GREATCLASH			0
#define HERO_SKILL_WINDARROW			1
#define HERO_SKILL_METOER_SHOWER		2
#define HERO_SKILL_ELECTRIC_BALL		3
#define HERO_SKILL_WOLF_RANGER			4
#define HERO_SKILL_ACHEMIST				5
#define HERO_SKILL_BEAST_MASTER			6
#define HERO_SKILL_SENTINEL				7
#define HERO_SKILL_CAT_NINJA			8
#define HERO_SKILL_SANTA				9


#define HERO_STATE_IDLE				0
#define HERO_STATE_WALK				1
#define HERO_STATE_RUN				2
#define HERO_STATE_ATTACK			3
#define HERO_STATE_SKILL			4
#define HERO_STATE_BESKILL			5

#define HERO_ANIM_IDLE				0
#define HERO_ANIM_WALK				1
#define HERO_ANIM_RUN				2
#define HERO_ANIM_ATTACK1			3
#define HERO_ANIM_ATTACK2			4
#define HERO_ANIM_BESKILL			5
#define HERO_ANIM_SKILL1			6
#define HERO_ANIM_SKILL2			7

#define HERO_ANIM_NUM_MAX			8

#define HERO_ORITATION_LEFT			0
#define HERO_ORITATION_RIGHT		1

#define HERO_RANGE_DIS_MELEE		75
#define HERO_RANGE_DIS_RANGE		k_SCREEN_WIDTH

#define NUM_FRAME_ATTACK			50

#define HERO_SKILL_TYPE_NONE			0
#define HERO_SKILL_TYPE_STUN			1
#define HERO_SKILL_TYPE_KNOCKBACK		2
#define HERO_SKILL_TYPE_CRITICAL		3
#define HERO_SKILL_TYPE_BURN_AIR		4
#define HERO_SKILL_TYPE_ROBO			6
#define HERO_SKILL_TYPE_STATUE			7
#define HERO_SKILL_TYPE_SANTA			8
#define HERO_SKILL_TYPE_PALADIN			9


#define HERO_FORMULA_PARAM1				0
#define HERO_FORMULA_PARAM2				1
#define HERO_FORMULA_PARAM3				2
#define HERO_FORMULA_PARAM4				3
#define HERO_FORMULA_PARAM5				4
#define HERO_FORMULA_PARAM6				5

class CHero
{
public:
	CHero();
	~CHero();
	CAnimObject _anim;
	void Init(int id, int level, bool deployed, bool lock,bool haspromo);
	void Modify(float x, float y, bool lock, int poweratt, int powerskill);
	void Modify(int id, int level, bool deployed, bool lock, int poweratt, int powerskill, int rarlv, bool haspromo);
	void Render(float x, float y);
	void Update();
	void SetLevel(int level);
	int GetLevel();
	const char* GetName();
	INT_TIME GetDamage();
	int GetSkill();
	float GetSpeed();
	void SetSpeed(float speed);
	int GetTypeRange();
	int GetLimitBreak();
	int GetCritical();
	INT_TIME GetCostUpgrade();
	void SetState(int state);
	int GetState();
	bool HasUnlock();
	void UnlockActive();
	int GetSpriteID();
	void SetPos(float x, float y);
	float GetPosX();
	float GetPosY();
	void SetTarget(float tarx, float tary);
	int _count_frame_attack;
	void ForceAttack(bool addpower);
	int _index_enemy_target;
	void SetEnemyIndexTarget(int index);
	void SetHeroID(int id);
	int GetHeroID();
	void AddPowerAttack(float power);
	float GetPowerAttack();
	bool IsFullPowerAttack();
	void AddPowerSkill(float power);
	float GetPowerSkill();
	bool IsFullPowerSkill();
	bool _is_auto_attack;
    bool _is_max_speed;
	void ActiveAutoAttack(bool mass_auto);
	void UpdateAutoAttack(int speed, bool skill);
	int _count_frame_auto_attack;
	void CancelTarget();
	int _count_frame_refill;
	
	CBulletAttack _frame_attack[NUM_FRAME_ATTACK];
	void InitAttackFrame();
	void AddAttackFrame();
	void RenderAttackFrame();
	void UpdateAttackFrame();
    void ResetAttackFrame();
	bool _render_attack_frame;
	CSkill _skill;
	void SkillActive();
	void UpdatePlaySkill();
	int _skill_id;
	bool _is_play_skill;
	void LevelUp();
	bool _deployed;
	void HitDamageActive();
	int _range_damage_aoe;
	int _skill_duration;

	bool CheckHitDamage(int frame_id);
	CAnimObject _anim_marker;
	void PlaySound();
	void GetRelicsBonus();
	int _power_attack_max;
	bool _is_lock;
	float _power_att_catch;
	float _power_skill_catch;
	bool _is_use_auto_att;
	bool _is_use_auto_skill;
	int GetLevelUnlock();
	INT_TIME GetDamageEndless(int level);
	INT_TIME GetCostUpgradeEndless(int level);
	INT_TIME GetDamageLevelUp();
	INT_TIME GetDamageNormal();
    INT_TIME GetBonusDamage();
    int GetStars();
	int GetCostUnlock();
	bool _is_new;
	bool SkillHasStatue();
	void AddHPStatue(INT_TIME hp);
	bool _level_max;
	CBird _pet_bird;
    int _stars;
	int _rar_level;
	bool _has_promo;

	void SetStar(int star);
	int GetNumStars();
	void RarityLevelUp();
	void UpdateRarity();
	INT_TIME GetTotalDamage();
	INT_TIME GetDamageBasic();
	INT_TIME GetDamageExtra();
	INT_TIME GetTotalDamageHightRar();
	int _count_frame_mass_auto_att;
	bool _auto_being_active;
private:
	
	float _x, _y;
	float _targetx, _targety;
	int _id;
	char _name[20];
	int _level;
	INT_TIME _damage;
	INT_TIME _damage_extra;
	int _speed_attack;
	float _speed;
	int _type_range;
	int _limit_break;
	int _critical;
	int _cost_unlock;
	INT_TIME _cost_upgrade;
	int _state;
	bool _had_unlock;
	int _spriteid;
	int _oritation;
	float _range;
	float _power_attack;
	float _power_skill;
	int _level_unlock;
	int _count_frame_playsound;

};



#endif
