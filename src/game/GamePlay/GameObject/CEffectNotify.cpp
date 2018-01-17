#include "pch.h"
#include "../../GameCore/CGame.h"

CEffectNotify::CEffectNotify()
{
}

CEffectNotify::~CEffectNotify()
{
}

void CEffectNotify::Init(int sprite, int frame, int anim, float x, float y, float scale)
{
	_x = x;
	_y = y;
	_scale = scale;
	_spriteid = sprite;
	_frameid = frame;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(anim, true);
	_anim.SetPos(0, 0);
	_state = NOTIFY_STATE_NONE;
}
void CEffectNotify::Render(float x, float y)
{
	if (_state == NOTIFY_STATE_NONE)
	{
		return;
	}
	if (_frameid >= 0)
	{

	}
	else
	{
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		_anim.SetPos(_x + x, _y + y);
		_anim.DrawAnimObject(G());
		G()->ClearScale();
	}
}
void CEffectNotify::Update()
{
	switch (_state)
	{
	case NOTIFY_STATE_NONE:
		break;
	case NOTIFY_STATE_START:
		if (_scale < 1.15f)
		{
			_scale += 0.08f;
			if (_scale >= 1.15f)
			{
				_state = NOTIFY_STATE_ACTIVE;
			}
		}
		_anim.UpdateAnimObject();
		break;
	case NOTIFY_STATE_ACTIVE:
		if (_scale > 1.0f)
		{
			_scale -= 0.05f;
			if (_scale <= 1.0f)
			{
				_scale = 1.0f;
			}
		}
		_anim.UpdateAnimObject();
		break;
	case NOTIFY_STATE_END:
		if (_scale > 0)
		{
			_scale -= 0.2f;
			if (_scale <= 0)
			{
				_scale = 0;
				_state = NOTIFY_STATE_NONE;
			}
		}
		_anim.UpdateAnimObject();
		break;
	default:
		break;
	}
}
void CEffectNotify::Active()
{
	_state = NOTIFY_STATE_START;
}
void CEffectNotify::Disable()
{
	_state = NOTIFY_STATE_END;
}