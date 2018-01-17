#ifndef _PARTICAL_
#define _PARTICAL_

#include "../../Lib/DataType/CType.h"

#define NUM_MAX_PARTICAL		200
#define PARTICAL_STATE_NONE			0
#define PARTICAL_STATE_END			1
#define PARTICAL_STATE_START		2

#define PARTICAL_TYPE_CIRCLE_CENTER		0

class CPartical
{
public:
	CPartical();
	~CPartical();

	int _spriteid;
	int _frameid;
	float _x, _y;
	float _tarx, _tary;
	float _speed;
	float _scale;
	float _scale_speed;
	float _opac;
	float _opac_speed;
	float _rotate;
	float _rotate_speed;
	int _state;
	float _angle;
	int _count_frame;
	int _type;
	float _max_scale;

	void Init(int sprite, int frame, int numframe, int type, int timemax,float maxscale, bool loop);
	void Active(float x, float y, float tarx, float tary, float speed, float speedscale, float speedopac, float speedrotate);
	void Render(float x, float y);
	void Update();
	bool IsEnd();
	void ForceEnd();
private:

};



#endif