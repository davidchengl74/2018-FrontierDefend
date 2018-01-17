#ifndef _SKILL_RAIN_SHOWER_
#define _SKILL_RAIN_SHOWER_

#include "../../Lib/DataType/CType.h"

#define RAIN_SHOWER_NUM_OBJECT		50
#define RAIN_SHOWER_TYPE_FRAME		0
#define RAIN_SHOWER_TYPE_ANIM		1

#define RAIN_SHOWER_STATE_NONE				0
#define RAIN_SHOWER_STATE_START				1
#define RAIN_SHOWER_STATE_HIT_TARGET		2
#define RAIN_SHOWER_STATE_END				3

#define RAIN_SHOWER_NUM_SHADOW			50
#define RAIN_SHOWER_SHADOW_STATE_NONE		0
#define RAIN_SHOWER_SHADOW_STATE_ACTIVE		1
#define RAIN_SHOWER_SHADOW_STATE_END		2

class CRainShower
{
public:
	CRainShower();
	~CRainShower();
	struct RObject
	{
		float _x, _y;
		float _tarx, _tary;
		float _speed;
		float _speed_scale;
		float _scale;
		float _scale_start;
		float _rotate;
		int _count_frame_hold;
		int _opac;
		int _frameid;
		int _spriteid;
		int _state;
		CAnimObject _anim;
		CShadow _smoke[RAIN_SHOWER_NUM_SHADOW];
		void Init(int sprite, int frame, float speed, float speedscale, float scale);
		void Render(float x, float y);
		void Update();
		void Active(int index, float x, float y, float tarx, float tary, int rotate);
		void ForceEnd();
		bool IsFree();
		void AddShadow(float x, float y);
	};
	RObject _shower_object[RAIN_SHOWER_NUM_OBJECT];
	int _spriteid;
	int _frameid;
	int _type;
	int _num;
	void Init(int type, int num, int sprite, int frame, float speed, float speedscale, float scale);
	void Render(float x, float y);
	void Update();
	void Active(float x,float y,float tarx,float tary,int rotate);
	void ForceEnd();
	bool IsFree();
	int CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical);

private:

};



#endif