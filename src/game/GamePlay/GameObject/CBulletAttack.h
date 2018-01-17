#ifndef _BULLET_ATTACK_
#define _BULLET_ATTACK_

#include "../../Lib/DataType/CType.h"
class CBulletAttack
{
public:
	CBulletAttack();
	~CBulletAttack();
	float _x, _y;
	float _targetx, _targety;
	int _enemy_target;
	float _speed;
	int _frame;
	int _sprite;
	int _damage;
	float _critical;
	int _aoe;
	int _state;
	void Init(float x, float y, int sprite, int frame, int damage, float critical);
	void Add(float x, float y, float speed, int enemytarget, int damage, int aoe, int critical);
	void Render(float x, float y);
	void Update(bool lose);
	bool IsFree();
private:

};

#endif;