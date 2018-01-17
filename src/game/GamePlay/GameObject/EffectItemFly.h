#ifndef _C_ITEM_FLY_
#define _C_ITEM_FLY_
#include "../../Lib/DataType/CType.h"
#include "../../GameCore/CAnimObject.h"

#define MAX_ITEMS_DROP_INGAME		500
#define ITEMS_NULL		-1
#define ITEMS_EMPTY		0
#define ITEMS_DROP		1
#define ITEMS_FLY		2

#define ITEMS_TYPE_COIN		0
#define ITEMS_TYPE_ENERGY	1
#define ITEMS_TYPE_GEM		2

class CItemFly
{
public:
	CItemFly();
	~CItemFly();
	void Init(int sprite, int frame, int valmin, float speed);
	void Active(int type, float x, float y, float tarx, float tary, int value);
	void Render();
	void Update();
	void ForceEnd();
	int _spriteid;
	int _frameid;
	float _x, _y;
	int _count_frame_hold;
	float _targetx, _targety;
	int _type;
	int _state;
	float _alphax;
	float _alphay;
	int _speed;
	int _delta;
	int _speedy;
	int _value;
	int _opac;
	int _value_min;
};

#endif
