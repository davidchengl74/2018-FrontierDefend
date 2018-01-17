
#include "pch.h"
#include "../../GameCore/CGame.h"
#include "string.h"
#include <ctype.h>
#include "CScrollbar.h"

void CScrollBar::SetTarget(float target)
{
    _target = target;
}
float CScrollBar::GetDistace()
{
    return CMath::ABSOLUTE_VALUE(_target-_current);
}
void CScrollBar::ForceToTarget()
{
    _current = _target;
}
void CScrollBar::ReduceOffset(float mul)
{
    _sub_speed *= mul;
}
void CScrollBar::Init(int min,int max,float speed,float mul)
{
    _state = -1;
	if (max <= 0)
	{
		max = 1;
	}
    _min = min;
    _max = max;

	_noLimit = 0;
	if(min == max && min == 0)
	{
		_noLimit = 1;
	}
    _target = min;
    _current = min;
    _speed = speed;
    _speed_pined = _speed;
    _mul_speed = mul;
    _accel = 0.90f;
    _limit_speed_min = 0.8f;

	_isScroll = false;
    _isInit = true;
	_snapDelta = 0;

	_deltaMax = 40;
	_deltaMin = 40;

	_snapBegin = -1;
	_snapEnd = -1;
	_snapSpeed = _speed_pined;
	_byPassBouceEffect = false;

	_last_touch_y = 0;
	_offset_y = 0;

	_last_touch_x = 0;
	_offset_x = 0;
	_touch_id = -1;
}
void CScrollBar::AddOffset(float offset)
{
    _speed = _speed_pined;
	_offset = offset;
	_target += offset;
    _sub_speed = CMath::ABSOLUTE_VALUE(offset);
    //ValidateRange();
    
   
}
void CScrollBar::Set()
{
    _target = _current;
    _offset = 0;
    _collided = false;
}

void CScrollBar::SetExt(float current)
{
	_current = current;
    _target = _current;
    _offset = 0;
    _collided = false;
}

void CScrollBar::Pause()
{
	_target = _current;
    _offset = 0;
    _state = 0;
    
}
void CScrollBar::Resume()
{
	ValidateRange();
}
void CScrollBar::End()
{
    if(_offset == 0)
    {
        return;
    }
    float dis = CMath::ABSOLUTE_VALUE(_offset);
    float offset = ((_offset)>0?1:-1)*6*dis;
    //printf("\noffset = %f",offset);
    AddOffset(offset);
    _sub_speed = dis*_mul_speed;
}
void CScrollBar::ValidateRange()
{
	if(_noLimit)
	{
		return;
	}
	if(_target > _max)
	{
		_target = _max;
	}
    else
	if(_target < _min)
	{
		_target = _min;
	}
}
void CScrollBar::ValidateRangeExt()
{
	if(_noLimit)
	{
		return;
	}
	if (_target > _max + _deltaMax)
    {
        
		_target = _max + _deltaMax;
        if(_current > _target)
        {
            _current = _target;
        }
    }
    else
	if (_target < _min - _deltaMin)
    {
       
		_target = _min - _deltaMin;
        if(_current < _target)
        {
            _current = _target;
        }
    }
    
    if(_current > _max)
	{
         _collided = true;
	}
    else
    if(_current < _min)
    {
         _collided = true;
    }
    else
    {
        _collided = false;
    }
    
    //printf("\n _target = %f",_target);
}

void CScrollBar::configAutoSnap(float &speed)
{
	if (_snapBegin != _snapEnd)//check special snap
	{
		speed = _snapSpeed;
		_sub_speed = _snapSpeed;
		float checkCurrent = CMath::ABSOLUTE_VALUE(_current);
		float newTarget = _target;

		float d1 = checkCurrent - _snapBegin;
		float d2 = _snapEnd - checkCurrent;

		if (d1 > d2)
		{
			newTarget = _snapEnd;
		}
		else
		{
			newTarget = _snapBegin;
		}

		if (_target == newTarget)
		{
			speed = 0;
			Pause();
			_state = -1;
		}
		else
		{
			_target = newTarget;
			_state = 3;
		}
	}
	else if (_snapDelta > 0) //check need snap
	{
		speed = _snapSpeed;
		_sub_speed = _snapSpeed;
		float checkCurrent = CMath::ABSOLUTE_VALUE(_current);
		float newTarget = _target;
		while (checkCurrent >= _snapDelta)
		{
			checkCurrent -= _snapDelta;
		}

		if (_current > 0)
		{
			if (checkCurrent < _snapDelta*0.5f)
			{
				newTarget = _current - checkCurrent;
			}
			else
			{
				newTarget = _current - checkCurrent + _snapDelta;
			}
		}
		else if (_current < 0)
		{
			if (checkCurrent > _snapDelta*0.5f)
			{
				newTarget = _current + checkCurrent - _snapDelta;
			}
			else
			{
				newTarget = _current + checkCurrent;
			}
		}
		else
		{
			_current = newTarget;
		}

		if (_target == newTarget)
		{
			speed = 0;
			Pause();
			_state = -1;
		}
		else
		{
			_target = newTarget;
			_state = 3;
		}
	}
	else
	{
		speed = 0;
		Pause();
	}
}

void CScrollBar::setAutoSnapToTarget(float x)
{
	_target = x;
	if (_target == _current)
	{
		Pause();
		_state = -1;
	}
	else
	{
		_state = 3;
	}
}


void CScrollBar::Update()
{
    //printf("\n_state = %d",_state);
	if(_state == 1)
    {
        return;
    }
	
    //_sub_speed = _sub_speed*_accel;
	if (_state == 3)
	{
		_sub_speed = _sub_speed*1.1f;
		if (_sub_speed > _snapSpeed)
		{
			_sub_speed = _snapSpeed;
		}
	}
	else
	{
		_sub_speed = _sub_speed*_accel;
	}
    
    
    float speed = _sub_speed;

	if (_state == 2)
	{
		if (_byPassBouceEffect)
		{
			configAutoSnap(_speed);
		}
	}

    if (_state == 3)
    {
		speed = _sub_speed;
    }
    if(_collided)
    {
        speed = _speed_pined;
        if(_current > _target)
        {
            _current = _current - speed;
            if(_current < _target)
            {
                _current = _target;
                _collided = false;
                _sub_speed = 0;
            }
        }
        else if(_current < _target)
        {
            _current = _current + speed;
            if(_current > _target)
            {
                _current = _target;
                _collided = false;
                _sub_speed = 0;
            }
        }
        ValidateRange();
        return;
    }

    if (_state == 3) //state auto snap
    {
        
    }
    else
    {
        if(speed < _limit_speed_min)
        {
			configAutoSnap(speed);
        }
    }


	if(_current > _target)
	{
		_current = _current - speed;
		if(_current < _target)
		{
			_current = _target;
            if (_state == 3)
            {
                speed = _limit_speed_min;
            }
            if(speed > _limit_speed_min)
            {
                _target += (2*speed*((_offset)>0?1:-1));
            }
		}
	}
	else if(_current < _target)
	{
		_current = _current + speed;
		if(_current > _target)
		{
			_current = _target;
            if (_state == 3)
            {
                speed = _limit_speed_min;

            }
			if(speed > _limit_speed_min)
            {
                _target += (2*speed*((_offset)>0?1:-1));
            }
		}
	}
    else
    {
        if (_state == 3)
        {
            _state = -1;
			/*if (_snapBegin != _snapEnd)
			{
				_current = _snapBegin;
			}*/
        }
        ValidateRange();
    }
    ValidateRangeExt();
}

void CScrollBar::SetMax(float max)
{
	if (max <= 0)
	{
		max = 1;
	}
	_max = max;
}

void CScrollBar::SetState(int state)
{
	_state = state;
}

