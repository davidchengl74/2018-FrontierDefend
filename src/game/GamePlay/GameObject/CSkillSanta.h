#ifndef _SKILL_SANTA_
#define _SKILL_SANTA_

#include "../../Lib/DataType/CType.h"

#define SKILL_SANTA_STATE_NONE			0
#define SKILL_SANTA_STATE_ACTIVE		1
#define SKILL_SANTA_STATE_COMEBACK		2
#define SKILL_SANTA_STATE_END			3

#define SKILL_SANTA_NUM_PARTICAL_SHADOW		50

#define GIFT_PARTICAL_STATE_NONE			0
#define GIFT_PARTICAL_STATE_ACTIVE			1
#define GIFT_PARTICAL_STATE_FIRE			2
#define GIFT_PARTICAL_STATE_FIRE_EFFECT		3
#define GIFT_PARTICAL_STATE_END				4

#define GIFT_PARTICAL_NUM_MAX				50

class CSanta
{
public:
	CSanta();
	~CSanta();
	float _x, _y;
	float _tarx, _tary;
	float _angle;
	float _speed;
	int _state;
	float _santax, _santay;
	float _santa_tarx, _santa_tary;
	CAnimObject _anim_ani1;
	CAnimObject _anim_ani2;
	CAnimObject _anim_santa_cart;
	int _count_frame_add_gift;
	int _spriteid;
	void Init(float x, float y, float speed, int sprite);
	void Render(float x, float y);
	void Update();
	void Active(float x, float y);
	bool IsFree();
	struct GiftPartical
	{
		float _x, _y;
		float _tarx, _tary;
		float _speed;
		int _spriteid;
		int _frameid;
		int _state;
		float _rotate;
		void Init(int sprite, int frame, float x, float y, float speed);
		void Render(float x, float y);
		void Update();
		void Active(float x, float y, float speed);
		void CheckEnemyAround(int damage, float aoe, float critical);
		bool IsFree();
		CEffectFire _effect_fire;
	};
	GiftPartical _gift_partical[GIFT_PARTICAL_NUM_MAX];
	void AddGiftPartical(float x, float y);
	void CheckEnemyAround( int damage, float aoe, float critical);

	CShadow _partical_line1[SKILL_SANTA_NUM_PARTICAL_SHADOW];
	CShadow _partical_line2[SKILL_SANTA_NUM_PARTICAL_SHADOW];
	void AddShadow(float x, float y, int type);
private:

};


#endif;