#ifndef _EFFECT_SHADOW_
#define _EFFECT_SHADOW_
#include "../../Lib/DataType/CType.h"

#define SHADOW_STATE_NORMAL			0
#define SHADOW_STATE_START			1
#define SHADOW_STATE_END			2
#define SHADOW_STATE_FREE			3

class CShadow
{
public:
	CShadow();
	~CShadow();
	float _x, _y;
	float _speed_scale;
	float _scale;
	float _opac;
	float _speed_opac;
	int _frame;
	int _spriteid;
	int _state;
	bool _opac_max;
	void Init(int sprite, int frame, float scalespeed, int opacspeed);
	void Active(float x, float y, float scale, float opac);
	void Render(float x, float y);
	void Update();
	bool IsFree();
private:

};

#endif;