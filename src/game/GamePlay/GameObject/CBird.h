#ifndef _SKILL_BIRD_
#define _SKILL_BIRD_

#define BIRD_STATE_IDLE		0
#define BIRD_STATE_ATTACK	1
#define BIRD_STATE_BACK		2

#define BIRD_ANIM_IDLE		0
#define BIRD_ANIM_ATTACK1	1
#define BIRD_ANIM_ATTACK2	2

#define BIRD_NUM_ANIM		2	


#include "../../Lib/DataType/CType.h"

class CBird
{
public:
	CBird();
	~CBird();

	float _x, _y;
	float _tarx, _tary;
	float _cenx, _ceny;
	float _range;
	int _speed_att;
	INT_TIME _damage;
	float _critical;
	float _speed;
	int _state;
	int _spriteid;
	int _id;
	int _count_frame_att;
	int _heroid;
	int _aoe;
	CAnimObject _anim;
	int _enemy_target;
	void Init(int sprite, int id, float x, float y,INT_TIME damage);
	void Modify(INT_TIME damage);
	void Render(float x, float y);
	void Update();
	void SetState(int state);
	void HitDamage();
	void GetRelicsBonus();
private:

};


#endif;