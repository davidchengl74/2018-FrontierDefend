#include "pch.h"
#include "../../GameCore/CGame.h"

CPartical::CPartical()
{
}

CPartical::~CPartical()
{
}

void CPartical::Init(int sprite, int frame, int numframe, int type, int timemax, float maxscale, bool loop)
{
	_spriteid = sprite;
	_frameid = frame + CMath::RANDOM(0,numframe-1);
	_type = type;
	_state = PARTICAL_STATE_NONE;
	_x = 0;
	_y = 0;
	_tarx = 0;
	_tary = 0;
	_speed = 0;
	_scale = 0;
	_scale_speed = 0;
	_opac = 0;
	_opac_speed= 0;
	_rotate= 0;
	_rotate_speed = 0;
	_count_frame = timemax;
	_max_scale = maxscale;
}
void CPartical::Active(float x, float y, float tarx, float tary, float speed, float speedscale, float speedopac, float speedrotate)
{
		_state = PARTICAL_STATE_START;
		_x = x;
		_y = y;
		_tarx= tarx;
		_tary = tary;
		_angle = CMath::RANDOM(1, 360);
		_speed = speed;
		_scale = 1.0f;
		_scale_speed = speedscale;
		_opac = 0;
		_opac_speed = speedopac;
		_rotate = 0;
		_rotate_speed = speedrotate;
		if (_type == PARTICAL_TYPE_CIRCLE_CENTER)
		{
			_scale = 0.0f;
			_opac_speed = speedscale * 100;
		}
}
void CPartical::Render(float x, float y)
{
		if (_state == PARTICAL_STATE_NONE)
		{
			return;
		}
		G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
		G()->SetOpacity(_opac);
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		G()->SetRotate(_rotate, _x + x, _y + y);
		GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
		G()->ClearRotate();
		G()->ClearScale();
		G()->SetOpacity(100);
		G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
}
void CPartical::Update()
{
	if (_state == PARTICAL_STATE_NONE )
	{
		return;
	}
	/*if (_count_frame > 0 )
	{
		return;
	}
	else
	{
		_count_frame--;
	}*/
	_x += _speed * CMath::COS(_angle);
	_y += _speed * CMath::SIN(_angle);
	_rotate += _rotate_speed;
	if (_rotate >= 360)
	{
		_rotate -= 360;
	}
	_scale += _scale_speed;
	
	if (_scale < _max_scale)
	{
		_opac += _opac_speed;
		if (_opac>= 100)
		{
			_opac = 100;
		}
	}
	else
	{
		_opac -= _opac_speed*4;
		if (_opac<=0)
		{
			_opac = 0;
			_state = PARTICAL_STATE_END;
		}
	}
}
bool CPartical::IsEnd()
{
	if (_state > PARTICAL_STATE_END)
	{
		return false;
	}
	return true;
}
void CPartical::ForceEnd()
{
	if (_state > PARTICAL_STATE_END)
	{
		_state = PARTICAL_STATE_END;
	}
}