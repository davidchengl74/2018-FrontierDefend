#ifndef _WEAPON_
#define _WEAPON_

#include "../../Lib/DataType/CType.h"

#define NUM_MAX_THROWOBJECT			20

#define WEAPON_STATE_IDLE			0
#define WEAPON_STATE_ATTACK			1

#define WEAPON_ANIM_IDLE			0
#define WEAPON_ANIM_ATTACK			3

#define WEAPON_FORMULA_PARAM1				0
#define WEAPON_FORMULA_PARAM2				1
#define WEAPON_FORMULA_PARAM3				2
#define WEAPON_FORMULA_PARAM4				3
#define WEAPON_FORMULA_PARAM5				4
#define WEAPON_FORMULA_PARAM6				5

class CWeapon
{
public:
	CWeapon();
	~CWeapon();

	void Init(int type, int level, bool block);
	void Modify();
	void Render(float x, float y, int opac);
	void RenderEffectShadow(float x, float y);
	void RenderAnim(float x, float y, int opac);
	void Update();
	int GetType();
	int GetAttackSpeed();
	void SetAttackSpeed(int speedatt);
	INT_TIME GetDamage();
	int GetLevel();
	void SetLevel(int level);
	CAnimObject _anim;
	int _anim_width;
	int _anim_height;

	CThrowObject _throwObject[NUM_MAX_THROWOBJECT];
	int _num_throwobject_active;
	void Unlock();
	bool IsLock();
	void LevelUp();
	INT_TIME GetCostUpgrade();
	void SetState(int state);
	int GetState();
	int _enemy_index_target;
	int _throwObject_index_free;
	int _aoe;
	void RenderAnimWeapon(float x, float y, int opac);
	int GetSpriteID();
	void GetRelicsBonus();
	INT_TIME GetBonusDamage();
	bool _level_max;
    int _current_index;
	//update
	int _level_limited;
	INT_TIME GetDamageBasic();
	INT_TIME GetDamageExtra();
	INT_TIME GetDamageTotal();
	INT_TIME GetDamageLevelUp();
private:
	int _type;
	int _attack_speed;
	INT_TIME _damage;
	INT_TIME _damage_extra;
	int _level;
	int _count_frame_attack;
	bool _is_block;
	INT_TIME _cost_upgrade;
	int _state;
	int _critical_percent;
	int _spriteid;
	float _x, _y;
	int _num_unit_bounce;
	
    
};
#endif
