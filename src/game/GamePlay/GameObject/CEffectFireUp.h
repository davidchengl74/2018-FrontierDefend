#ifndef _EFFECT_FIREUP_
#define _EFFECT_FIREUP_

#define NUM_MAX_PARTICAL_FIREUP			100

#define EFFECT_FIREUP_STATE_NORMAL			0
#define EFFECT_FIREUP_STATE_START			1
#define EFFECT_FIREUP_STATE_END				2
#define EFFECT_FIREUP_STATE_FREE			3


#include "../../Lib/DataType/CType.h"

class CEffectFireUP
{
public:
	CEffectFireUP();
	~CEffectFireUP();
	void Init(int sprite, int frame, int numframe, int num, float scale, int opac, float speed);
	void Active(float x, float y, float tarx, float tary,int rangex,int rangey, float speedscale,int speedopac);
	void Render(float x, float y);
	void Update();
	void ForceEnd();
	void Reset();
	bool IsFree();
	int _spriteid;
	int _frameid[NUM_MAX_PARTICAL_FIREUP];
	float _x[NUM_MAX_PARTICAL_FIREUP], _y[NUM_MAX_PARTICAL_FIREUP];
	float _targetx[NUM_MAX_PARTICAL_FIREUP], _targety[NUM_MAX_PARTICAL_FIREUP];
	int _state[NUM_MAX_PARTICAL_FIREUP];
	float _alphax[NUM_MAX_PARTICAL_FIREUP];
	float _alphay[NUM_MAX_PARTICAL_FIREUP];
	int _speed[NUM_MAX_PARTICAL_FIREUP];
	int _delta[NUM_MAX_PARTICAL_FIREUP];
	int _speedy[NUM_MAX_PARTICAL_FIREUP];
	int _opac[NUM_MAX_PARTICAL_FIREUP];
	float _opac_speed[NUM_MAX_PARTICAL_FIREUP];
	float _scale[NUM_MAX_PARTICAL_FIREUP];
	float _speed_scale[NUM_MAX_PARTICAL_FIREUP];
	float _rotate[NUM_MAX_PARTICAL_FIREUP];
	int _num;
private:

};

#endif;