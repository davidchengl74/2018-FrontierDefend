#ifndef _CHARACTER_
#define _CHARACTER_

#include "../../Lib/DataType/CType.h"

#define CHARACTER_TYPE_ATTACK_MELEE		0
#define CHARACTER_TYPE_ATTACK_RANGE		1

#define CHARACTER_TYPE_SIZE_SMALL		0
#define CHARACTER_TYPE_SIZE_MIDIUM		1
#define CHARACTER_TYPE_SIZE_BIG			2
#define CHARACTER_TYPE_SIZE_BIG_REWARD	3

#define CHARACTER_TYPE_SKILL_NONE		0
#define CHARACTER_TYPE_SKILL_STUNE		1

#define CHARACTER_STATE_IDLE			0
#define CHARACTER_STATE_WALK			1
#define CHARACTER_STATE_BEHIT			2
#define CHARACTER_STATE_BE_STUN			3
#define CHARACTER_STATE_ATTACK			4
#define CHARACTER_STATE_RUN				5
#define CHARACTER_STATE_DIE				7
#define CHARACTER_STATE_DIE_START		6
#define CHARACTER_STATE_DIE_END			8


#define CHARACTER_ANIM_IDLE				0
#define CHARACTER_ANIM_BEHIT			1
#define CHARACTER_ANIM_WALK				2
#define CHARACTER_ANIM_RUN				3
#define CHARACTER_ANIM_ATTACK			4
#define CHARACTER_ANIM_BE_STUNE			5
#define CHARACTER_ANIM_DIE				6
#define CHARACTER_ANIM_SKILL1			7
#define CHARACTER_ANIM_SKILL2			8

#define CHARACTER_NUM_ANIM				8

#define CHARACTER_RANGE_ATTACK_MELEE	65
#define CHARACTER_RANGE_ATTACK_RANGE	k_SCREEN_WIDTH - 200

#define CHARACTER_SKILL_NONE			0
#define CHARACTER_SKILL_PUSH_SPEED		1
#define CHARACTER_SKILL_LAY_EGGS		2
#define CHARACTER_SKILL_ROB				3
#define CHARACTER_SKILL_BOOM			4
#define CHARACTER_SKILL_FLYING			5
#define CHARACTER_SKILL_LAY_EGGS2		6
#define CHARACTER_SKILL_TOFLY			7

#define EFFECT_STARTIN_TYPE_JUMP		0

#define EFFECT_STARTIN_STATE_NONE		0
#define EFFECT_STARTIN_STATE_START		1
#define EFFECT_STARTIN_STATE_END		2

#define CHARACTER_STATUS_NORMAL			0
#define CHARACTER_STATUS_WALK			1
#define CHARACTER_STATUS_RUN			2
#define CHARACTER_STATUS_FLY			3
#define CHARACTER_STATUS_FORCE_FLY		4
#define CHARACTER_STATUS_CARRY_FLY		5
#define CHARACTER_STATUS_RUNAWAY		6

#define CHARACTER_TARGET_CASTLE			0
#define CHARACTER_TARGET_STATUE			1
#define CHARACTER_TARGET_HOME			2

#define BE_SKILL_NONE			-1
#define BE_SKILL_SLOW					0
#define BE_SKILL_BURN_BY_WEAPON			1
#define BE_SKILL_BURN_BY_HERO			2
#define BE_SKILL_STUN					3
#define BE_SKILL_TORNADO				4


class CCharacter
{
public:
	CCharacter();
	~CCharacter();
	void Init(char* id, float x, float y, float tarx, float tary, INT_TIME hp, INT_TIME damage, int coin, int size, int skill,int timerepawn);
	void Render(float x, float y, int opac);
	void RenderHealthBar(float x, float y);
	void Update();
	void AddHP(INT_TIME hp, int animeffect, int sprite, bool weapon);
	void SetSpeed(int speed);
	INT_TIME GetDamage();
	INT_TIME GetHP();
	int GetCoin();
	int GetTypeAttack();
	float GetPosX();
	float GetPosY();
	void SetPos(float x, float y);
	CAnimObject _anim;
	void SetState(int state);
	int GetState();
	int _count_frame_attack;
	int GetSpeed();
	int GetSprite();
	int GetCreationIndex();
	int _count_frame_repawn;
	bool IsReady();
	int _num_hit_attacked;
	int _aoe;
	int _effect_frame_behit;
	int _effect_behit_count_render;
	CAnimObject _anim_effect_behit;
	void RenderEffectBehit();
	const char* GetID();
	int _anim_height;
	void UpdateSkill();
	void ReActiveSkill();
	bool _skill_active;
	bool CheckHitDamage(int frame_id);
	CAnimObject _anim_marker;
	void GetRelicsBonus(bool init, int id);
	int _count_frame_has_fired;
	int _count_frame_has_acid;
	int _count_frame_has_tornado;
	struct EffectInit
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
		void Init(int type);
		void Active(float x, float y, float tarx, float tary);
		void Update();
		int _count_frame_hold;
	};
	EffectInit _effect_start_in;
	int _be_skill_id;
	int _be_skill_time;
	int _be_skill_value;
	void BeSkillActive(int skill, int timeslow = 0);
	void BeSkillUpdate();
	void BeSkillRender(float x, float y);
	bool _be_stun_available;
	int _be_stun_time;
	void BeStunActive(int timestun = 0);
	void BeStunUpdate();
	void BeStunRender(float x, float y);
	CAnimObject _effect_be_skill;
	INT_TIME _hp_max;
	int _num_coin_collect;
	int _size_w;
	int _size_h;
	int _enemy_bird_index;
	int GetSkillID();
	float _effect_rotate;
	float _speed_rotate;
	float _speed_fly;
	bool _fly_up;
	int _status;
	int _target_focus;
    //Lam Update Ver5
    void RenderEffect(float x, float y, int opac);
	bool IsLive();
	int _heathbar_opac;
	int _heathbar_count_frame_render;
	bool HasAvailable();
	int _beskill_beatmaster_time;
	int GetTimeRespawn();
private:
	char _id[10];
	int _size;
	float _speed;
	int _attack_speed;
	INT_TIME _damage;
	INT_TIME _hp;
	
	int _coin;
	int _skill;
	int _state;
	int _type_attack;
	float _x, _y;
	float _targetx, _targety;
	float _range;
	int _spriteid;
	int _creation_index;
	int _time_repawn;
	bool _is_ready;
};
#endif
