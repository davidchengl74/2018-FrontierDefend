#ifndef _SKILL_NINJA_STATUE_
#define _SKILL_NINJA_STATUE_

#include "../../Lib/DataType/CType.h"

#define SKILL_NINJA_STATUE_STATE_NONE			0
#define SKILL_NINJA_STATUE_STATE_START			1
#define SKILL_NINJA_STATUE_STATE_ACTIVE			2
#define SKILL_NINJA_STATUE_STATE_DIE			3
#define SKILL_NINJA_STATUE_STATE_END			4

#define SKILL_NINJA_STATUE_ANIM_INIT			0
#define SKILL_NINJA_STATUE_ANIM_IDLE			1
#define SKILL_NINJA_STATUE_ANIM_DIE				2
#define SKILL_NINJA_STATUE_ANIM_DIE_READY		5

class CNinjaStatue
{
public:
	CNinjaStatue();
	~CNinjaStatue();
	float _x;
	float _y;
	float _shakex;
	float _shakey;
	int _count_frame_shake;
	float _aoe;
	INT_TIME _damage;
	int _critical;
	INT_TIME _hp;
	INT_TIME _hp_max;
	INT_TIME _time_live;
	CAnimObject _anim;
	int _state;
	int _spriteid;
	void Init(int sprite, INT_TIME timelive, INT_TIME hp);
	void Active(float x, float y, INT_TIME hp, INT_TIME timelive, INT_TIME damage, float aoe, int critical);
	void Render(float x, float y);
	void Update();
	void AddHP(INT_TIME hp);
	void RenderHealthBar(float x, float y);
	bool IsFree();
	void CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical);
	void AddDrawManager(float x, float y);
private:

};


#endif