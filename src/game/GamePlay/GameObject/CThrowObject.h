#ifndef _THROWOBJECT_
#define _THROWOBJECT_

#include "../../Lib/DataType/CType.h"


#define THROWOBJECT_STATE_NONE		-1
#define THROWOBJECT_STATE_START		0
#define THROWOBJECT_STATE_END		1

#define THROWOBJECT_TYPE_AOE		0
#define THROWOBJECT_TYPE_FOCUS		1

#define NUM_TARGET_ELECTRIC_TOWER		(6 + ((TDGame*)CGame::_this->_current_game)->GetRelicsUnitBounce(ITEMRELIC_GROUP_WEAPON,WEAPON_ELECTRIC + 2))

class CThrowObject
{
public:
	CThrowObject();
	~CThrowObject();

	float _speed;
	float _speedx;
	float _speedy;
	float _angle;
	float _height;
	float _width;
	float _x, _y;
	float _startx, _starty;
	float _centerx, _centery;
	float _targetx, _targety;
	float _weight;
	int _frame;
	int _sprite;
	int _opac;
	int _time;
	int _time_speed;
	float _rotate;
	float _gravity;
	int _state;
	INT_TIME _damage;
	int _type;
	int _type_attack;
	int _range;
	int _critical;
	int _enemy_index_target;
	int _enemy_index_next_target;
	CAnimObject _anim;
	int _count_frame_hit;

	void Init(int sprite, int frame, float x, float y, float height, float width, float weight, int time, int type, int typeatt,int critical,int aoe);
	void Render(float x, float y, int opac);
	void Update();
	bool CheckHitPoint(float x, float y, float w, float h);
	bool IsEnd();
	void Active(float tarx, float tary, INT_TIME damage, int index, float aoe);
	float GetTimeToTarget(float tarx, float tary);
	void HitsDamage(bool isEnd);
	CAnimObject _anim_effect;
	CAnimObject _anim_effect1;
	CAnimObject _anim_effect2;
#define NUM_MAX_SHADOW		20

#define SHADOW_STATE_NORMAL			0
#define SHADOW_STATE_START			1
#define SHADOW_STATE_END			2

#define SHADOW_TYPE_FRAME			0
#define SHADOW_TYPE_ANIM			1
	struct Shadow
	{
		float _x, _y;
		float _opac;
		float _opac_speed;
		float _scale;
		float _scale_speed;
		int _spriteid;
		int _frame;
		int _state;
		int _type;
		int _count_frame_hold;
		CAnimObject _anim;
		void Init(int sprite, int frame, float speedopac, float speedscale, int type);
		void Active(float x, float y, int opac, float scale, int anim, int time);
		void Render(float x, float y);
		void Update();
		bool IsFree();
		void SetState(int state);
	};
	Shadow _shadow[NUM_MAX_SHADOW];
	CEffectFire _effect_fire;
	CEffectFireUP _effect_fireup;
	CShadow _effect_shadow[NUM_MAX_SHADOW];
	void InitShadow();
	void RenderShadow(float x, float y);
	void UpdateShadow();
	void AddShadow(float x,float y);
	int _num_target_focus;
	bool _is_frame1;
private:

};
#endif