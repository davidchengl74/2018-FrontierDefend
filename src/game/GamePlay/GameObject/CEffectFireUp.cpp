#include "pch.h"
#include "../../GameCore/CGame.h"

CEffectFireUP::CEffectFireUP()
{
}

CEffectFireUP::~CEffectFireUP()
{
}

void CEffectFireUP::Init(int sprite, int frame,int numframe, int num, float scale, int opac, float speed)
{
	_num = num;
	_spriteid = sprite;
	for (int i = 0; i < _num; i++)
	{
		_x[i] = 0;
		_y[i] = 0;
		_targetx[i] = 0;
		_targety[i] = 0;
		_alphax[i] =0;
		_alphay[i] = 0;
		_speed[i] = speed;
		_delta[i] = 0;
		_state[i] = EFFECT_FIREUP_STATE_NORMAL;
		_scale[i] = scale;
		_opac[i] = opac;
		_frameid[i] = frame + CMath::RANDOM(0, numframe - 1);
	}

}
void CEffectFireUP::Active(float x, float y, float tarx, float tary, int rangex, int rangey, float speedscale, int speedopac)
{
	
	for (int i = 0; i < _num; i++)
	{
		_x[i] = x;
		_y[i] = y;
		_targetx[i] = tarx + CMath::RANDOM(0,rangex);
		_targety[i] = tary + CMath::RANDOM(0, rangey*2);
		_alphax[i] = CMath::RANDOM(90-rangex, 90+rangex);
		_alphay[i] = 300 + CMath::RANDOM(rangey, rangey*2);
		_delta[i] = 0;
		_state[i] = EFFECT_FIREUP_STATE_START;
		_speed_scale[i] = speedscale*CMath::RANDOM(1, 10) / 100.0f;
		_opac_speed[i] = speedopac*CMath::RANDOM(1, 10) / 10.0f;
		_opac[i] = 100;
	}
}
void CEffectFireUP::Render(float x, float y)
{

	for (int i = 0; i < _num; i++)
	{
		if (_state[i] == 0)
		{
			return;
		}
		G()->SetOpacity(_opac[i]);
		G()->SetRotate(_rotate[i], _x[i] + x, _y[i] + y);
		G()->SetScale(_scale[i], _scale[i], _x[i] + x, _y[i] + y);
		GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid[i], _x[i] + x, _y[i] + y);
		G()->ClearScale();
		G()->ClearRotate();
		G()->SetOpacity(100);
	}
}
void CEffectFireUP::Update()
{
	for (int i = 0; i < _num; i++)
	{
		switch (_state[i])
		{
		case EFFECT_FIREUP_STATE_START:
		{
										  if (_alphax[i] < 90)
										  {
											  if (_alphax[i] < 85)
											  {
												  _alphax[i] += 0.5f;
											  }
											  else
											  {
												  _alphax[i] += 0.2f;
											  }
										  }
										  else if (_alphax[i] > 90)
										  {
											  if (_alphax[i] > 100)
											  {
												  _alphax[i] -= 0.5f;
											  }
											  else
											  {
												  _alphax[i] -= 0.2f;
											  }
										  }
						   
						   _alphay[i] += 2;
						   if (_alphay[i] >= 360)
						   {
							   _alphay[i] = 0;
						   }
						   if (_alphay[i] == 0)
						   {
							   _delta[i] += 2;
						   }

						   _y[i] += _speed[i] * CMath::SIN(_alphay[i] + _delta[i] / 4);
						   if (_y[i] >= _targety[i] - _speed[i])
						   {
							   _y[i] = _targety[i];
							   _state[i] = EFFECT_FIREUP_STATE_END;
						   }
						   else
						   {
							   
							   _x[i] += _speed[i] * CMath::COS(_alphax[i]);
						   }
		}
			break;
		case EFFECT_FIREUP_STATE_END:
		{
						  if (_opac[i]>0)
						  {
							  _opac[i] -= _opac_speed[i];
							  if (_opac[i] <= 0)
							  {
								  _state[i] = EFFECT_FIREUP_STATE_FREE;
							  }
						  }
		}
			break;
		default:
			break;
		}
	}
}
void CEffectFireUP::ForceEnd()
{
	for (int i = 0; i < _num; i++)
	{
		_state[i] = EFFECT_FIREUP_STATE_END;
	}
}

bool CEffectFireUP::IsFree()
{
	for (int i = 0; i < _num; i++)
	{
		if (_state[i] >= EFFECT_FIREUP_STATE_START)
		{
			return false;
		}
	}
	return true;
}

void CEffectFireUP::Reset()
{
	for (int i = 0; i < _num; i++)
	{
		_state[i] = EFFECT_FIREUP_STATE_NORMAL;
	}
	
}