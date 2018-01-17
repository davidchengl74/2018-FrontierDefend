#include "pch.h"
#include "../../GameCore/CGame.h"

CShadow::CShadow()
{
}

CShadow::~CShadow()
{
}
void CShadow::Init(int sprite, int frame, float scalespeed, int opacspeed)
{
	_spriteid = sprite;
	_frame = frame;
	_speed_scale = scalespeed;
	_speed_opac = opacspeed;
	_x = 0;
	_y = 0;
	_scale = 1;
	_opac = 100;
	_state = SHADOW_STATE_NORMAL;
	_opac_max = false;
}
void CShadow::Active(float x, float y, float scale, float opac)
{
	_x = x;
	_y = y;
	_scale = scale;
	_opac = opac;
	_state = SHADOW_STATE_START;
	_opac_max = false;
}
void CShadow::Render(float x, float y)
{
	if (_state == SHADOW_STATE_NORMAL)
	{
		return;
	}
	G()->SetOpacity(_opac);
	G()->SetScale(_scale, _scale, _x + x, _y + y);
	GET_SPRITE(_spriteid)->DrawFrame(G(), _frame, _x + x, _y + y);
	G()->ClearScale();
	G()->SetOpacity(100);
}
void CShadow::Update()
{
	if (_state == SHADOW_STATE_NORMAL)
	{
		return;
	}
	if (!_opac_max)
	{
		_opac += _speed_opac;
		if (_opac >= 120)
		{
			_opac_max = true;
		}
		_scale += _speed_scale;
	}
	else
	{
		_opac -= _speed_opac;
		if (_opac <= 0)
		{
			_state = SHADOW_STATE_NORMAL;
		}
		_scale += _speed_scale / 2;
	}
	if (_scale <= 0)
	{
		_scale = 0;
	}
}

bool CShadow::IsFree()
{
	if (_state == SHADOW_STATE_NORMAL || _state == SHADOW_STATE_FREE)
	{
		return true;
	}
	return false;
}