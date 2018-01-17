#ifndef _SKILL_ACID_
#define _SKILL_ACID_

#include "../../Lib/DataType/CType.h"

#define SKILL_ACID_STATE_NONE			0
#define SKILL_ACID_STATE_START			1
#define SKILL_ACID_STATE_ACTIVE			2
#define SKILL_ACID_STATE_HITDAMAGE		3
#define SKILL_ACID_STATE_DIE			4
#define SKILL_ACID_STATE_END			5

#define SKILL_ACID_ANIM_INIT			0
#define SKILL_ACID_ANIM_IDLE			1
#define SKILL_ACID_ANIM_ATTACK			2
#define SKILL_ACID_ANIM_DIE				3

class CSkillAcid
{
public:
	CSkillAcid();
	~CSkillAcid();
	float _x;
	float _y;
	int _speed_att;
	int _count_frame_att;
	float _aoe;
	INT_TIME _damage;
	int _critical;
	int _opac;
	INT_TIME _time_live;
	CAnimObject _anim;
	CAnimObject _anim1;
	CAnimObject _anim2;
	CAnimObject _anim_tower;
	float _effposx, _effposy;
	int _state;
	int _spriteid;
	void Init(int sprite, int speedatt);
	void Active(float x, float y, INT_TIME timelive, INT_TIME damage, float aoe, int critical);
	void Render(float x, float y);
	void Update();
	bool IsFree();
	bool CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical);
	void AddDrawManager(float x, float y);
private:

};

#endif;