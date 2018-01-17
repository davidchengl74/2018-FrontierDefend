
#if !_CSCROLL_BAR_H
#define _CSCROLL_BAR_H 1
class CScrollBar
{
	void configAutoSnap(float &speed);
public:
    CScrollBar()
    {
        _isInit = false;
        _current = 0;
    };
	//use 
	float _last_touch_y, _offset_y;
	float _last_touch_x, _offset_x;

	bool _isScroll, _isInit;
	int _touch_id;

	float _max;
	float _min;
	float _speed;
    float _speed_pined;
	float _current;
	float _target;
	float _offset;
    float _sub_speed;
    float _accel;
    bool _collided;
    float _snapDelta, _snapSpeed;
	bool _byPassBouceEffect;
	float _deltaMax, _deltaMin;
	int _snapBegin, _snapEnd;

    float _mul_speed;
    int _state;
	bool _noLimit;
    bool _limit_speed_min;
    void SetAccelSpeed(float accel){_accel = accel;};
	void Init(int min,int max, float speed,float mul=1);
	void Update();
	void AddOffset(float offset);
	void SetTarget(float target);
	void ValidateRange();
    void ValidateRangeExt();
	void Pause();
    void Set();
	void SetExt(float current);
	void Resume();
    void End();
	void SetMax(float max);
    
	void SetCurrent(float value){ _current = value; };
    float GetCurrent(){return _current;}
    bool IsScrolling(){return _current == _target && _state != 0;};
    void ReduceOffset(float mul);
    void ForceToTarget();
    float GetDistace();
    void SetState(int state);

	void setCustomSnap(float snapBegin, float snapEnd)
	{
		_snapBegin = snapBegin;
		_snapEnd = snapEnd;
	};
	
	void setAutoSnapToTarget(float x);
};

#endif
