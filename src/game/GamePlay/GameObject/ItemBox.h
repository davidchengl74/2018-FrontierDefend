#ifndef _C_ITEMBOX_
#define _C_ITEMBOX_

#define ITEM_STATE_INIT			-1
#define ITEM_STATE_NORMAL		0
#define ITEM_STATE_OPENNING		1
#define ITEM_STATE_OPENNED		2
#define ITEM_STATE_FLY_TO_END	3
#define ITEM_STATE_END			4
#define ITEM_STATE_FORCE_CLOSE	5
#define ITEM_STATE_FORCE_OPEN	6

#define ITEM_BOX_TYPE_NONE			0
#define ITEM_BOX_TYPE_COIN			1
#define ITEM_BOX_TYPE_ITEMS			2
#define ITEM_BOX_TYPE_GEM			3


class ItemBox
{
public:
	ItemBox();
	~ItemBox();
	int _touch_id;
	bool _choosen;
	float _scale;
	int _opac;
	int _sprite_id;
	int _frame_id;
	int _id_item;
	int _group;
	int _rate;
	void Init(int sprite, int frame, int type, int id, int group, int rate, int value, float x, float y, float targetx, float targety);
	void Render(int opac);
	void Update();
	bool _scale_max;
	void SetPos(float x, float y);
	void SetTarget(float x, float y);
	void SetScaleCenter(float x, float y);
	float GetPosX();
	float GetPosY();
	float GetTargetX();
	float GetTargetY();
	int GetType();
	int GetValue();
	void SetType(int type);
	void SetValue(int value);
	void SetState(int state);
	int GetState();
	CAnimObject _anim;
	CAnimObject _anim_light;
	float _scale_center_x;
	float _scale_center_y;
	float _dis_with_screen_center;
	int _count_frame_openning;
	float _reward_scale;
	float _reward_scale_x;
	float _reward_scale_y;
	float _reward_scroll_x;
	float _reward_scroll_y;
	float _reward_scroll_speed;
	float _glow1_rotate;
	float _glow2_rotate;
	float _font_reward_scale;
	bool _reward_scale_max;
	bool _reward_scale_min;
	int _glow_opac;
	float _glow_hero_scale;
	float _glow_hero_scale_y;
	void ForceOpenBox();
	bool _is_scrolling;

private:
	float _x, _y;
	int _type;
	int _value;
	float _target_x;
	float _target_y;
	int _state;
	char _value_text[128];
};


#endif