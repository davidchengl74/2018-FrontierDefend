#ifndef _EFFECT_NOTIFY_
#define _EFFECT_NOTIFY_

#define NOTIFY_STATE_NONE		0
#define NOTIFY_STATE_START		1
#define NOTIFY_STATE_ACTIVE		2
#define NOTIFY_STATE_END		3

class CEffectNotify
{
public:
	CEffectNotify();
	~CEffectNotify();
	float _x, _y;
	float _scale;
	CAnimObject _anim;
	int _state;
	int _spriteid;
	int _frameid;
	void Init(int sprite, int frame, int anim, float x, float y, float scale);
	void Render(float x, float y);
	void Update();
	void Active();
	void Disable();

};


#endif
