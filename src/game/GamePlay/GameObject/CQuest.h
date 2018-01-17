#ifndef _QUEST_
#define _QUEST_

#define EFFECT_STAR_STATE_NORMAL		-1
#define EFFECT_STAR_STATE_END			0
#define EFFECT_STAR_STATE_START			1
#define EFFECT_STAR_STATE_ZOOM_IN		2
#define EFFECT_STAR_STATE_ZOOM_OUT		3
#define EFFECT_STAR_STATE_HOLD			4


class CQuest
{
public:
	CQuest();
	~CQuest();

	float _x, _y;
	int _level;
	INT_TIME _value1;
	INT_TIME _value2;
	char _value1_text[128];
	char _value2_text[128];
	int _reward_coin;
	int _reward_gem;
	char _reward_coin_text[128];
	char _reward_gem_text[128];
	bool _completed;
	int _index;
	int _type;
	char _name[256];
    char _archivement[256];
	int _quest_id;
	int _num_quest;
	int _quest_group_id;
	Button _button_reward;
	bool _is_completed;
	bool _has_daily_quest;
	void Init(int id, int group, int nummax, float x, float y, bool completed, bool daily);
	void Render(float x, float y, int opac);
	void Modify();
	void Modify(int id, int group, int nummax, bool completed, bool daily);
	void Update();
	bool UpdateTouch();
	void Reset();
	float _scale_text_button;
	int _scale_text_button_state;
	bool _has_touch;
	int _spriteid;
	int _frameid;
	int _bg_id;
	float _touch_y;
	float _touch_x;
	CEffectNotify _notify_reward;
	bool _is_new;
	
	struct Star
	{
		float _x, _y;
		int _state;
		float _scale;
		int _opac;
		int _count_frame_hold;
		void Init(float x, float y, int state);
		void Render(float x, float y, int opac);
		void Update();
		void Active();
		void SetPos(float x, float y);
	};
	Star _star_list[NUM_MAX_QUEST_IN_GROUP];
	void SetPos(float x, float y);
	int _shake_x;
	int _shake_y;
	
};


#endif