#ifndef _GIFT_BOX_
#define _GIFT_BOX_

#define GIFT_BOX_TYPE_NONE				-1
#define GIFT_BOX_TYPE_AUTO_ATT			0
#define GIFT_BOX_TYPE_AUTO_SKILL		1
#define GIFT_BOX_TYPE_COIN				2
#define GIFT_BOX_TYPE_GEM				3
#define GIFT_BOX_TYPE_DOUBLE_COIN		4

#define GIFT_BOX_NUM_TYPE				5

#define GIFT_BOX_STATE_NORMAL			0
#define GIFT_BOX_STATE_START			1
#define GIFT_BOX_STATE_OPEN				2
#define GIFT_BOX_STATE_END				3
#define GIFT_BOX_STATE_FREE				4



#define GIFT_BOX_NUM_PARTICAL_SHADOW		50

#include "../../Lib/DataType/CType.h"

class CGiftBox
{
public:
	CGiftBox();
	~CGiftBox();
	struct Gift
	{
		int _type;
		int _value;
	};
	Gift _gift[GIFT_BOX_NUM_TYPE];
	float _x, _y;
	float _tarx, _tary;
	bool _fly_with_sin;
	float _angle;
	float _speed;
	//int _type;
	//int _value;
	int _count_frame_hold;
	int _gift_touch_id;
	int _num_gift_target;
	CAnimObject _anim;
	int _state;
	float _speed_angle;
	bool _has_is_screem;
	void Init(int type, int value, int timehold, float speed,int num);
	void Active(float tarx,float tary);
	void Render(float x, float y);
	void Update();
	bool UpdateTouch();
	void Reset();
	void AddShadow(float x, float y, int type);
	CShadow _partical_end[GIFT_BOX_NUM_PARTICAL_SHADOW];
	CShadow _partical_gift[GIFT_BOX_NUM_PARTICAL_SHADOW];
	int RandomRewardIndex();
	bool _has_live;
private:

};



#endif;