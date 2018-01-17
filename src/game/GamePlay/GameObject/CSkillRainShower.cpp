#include "pch.h"
#include "../../GameCore/CGame.h"

CRainShower::CRainShower()
{
}

CRainShower::~CRainShower()
{
}

void CRainShower::Init(int type, int num, int sprite, int frame, float speed, float speedscale, float scale)
{
	_num = num;
	_spriteid = sprite;
	_frameid = frame;
	for (int i = 0; i < _num; i++)
	{
		_shower_object[i].Init(_spriteid, _frameid, speed, speedscale, scale);
	}
	
	_type = type;
	
}
void CRainShower::Render(float x, float y)
{
	for (int i = 0; i < _num; i++)
	{
		_shower_object[i].Render(x, y);
	}
}
void CRainShower::Update()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < _num; i++)
	{
		_shower_object[i].Update();
	}
}
void CRainShower::Active(float x, float y, float tarx, float tary, int rotate)
{
	for (int i = 0; i < _num; i++)
	{
		_shower_object[i].Active(i, x, y, tarx, tary, rotate);
	}
}
void CRainShower::ForceEnd()
{
	for (int i = 0; i < _num; i++)
	{
		_shower_object[i].ForceEnd();
	}
}

bool CRainShower::IsFree()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < _num; i++)
	{
		if (!_shower_object[i].IsFree())
		{
			return false;
		}
	}
	game->_shake_effectx = 0;
	game->_shake_effecty = 0;
	return true;
}

int CRainShower::CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	int hit = 0;
	for (int i = 0; i < _num; i++)
	{
		if (_shower_object[i]._state == RAIN_SHOWER_STATE_END)
		{
			continue;
		}
		float posx = game->_enemy[enemyindex].GetPosX();
		float posy = game->_enemy[enemyindex].GetPosY();
		float dis = CMath::DISTANCE(_shower_object[i]._x, _shower_object[i]._y, posx, posy);
		if (dis <= (game->_enemy[enemyindex]._size_w / 2 + aoe / 2) && CMath::ABSOLUTE_VALUE(_shower_object[i]._y - posy) <= aoe / 2 && game->_enemy[enemyindex]._count_frame_has_fired <= 0)
		{
			hit++;
			int rand = CMath::RANDOM(1, 100);
			if (rand <= critical)
			{
				game->_user._quest_num_critical_hit++;
				damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
				game->_enemy[enemyindex].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
				game->AddEffectHPLost(damage, posx + CMath::RANDOM(-3, 3) * 3, posy - game->_enemy[enemyindex]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
			}
			else
			{
				game->_enemy[enemyindex].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
				game->AddEffectHPLost(damage, posx + CMath::RANDOM(-3, 3) * 3, posy - game->_enemy[enemyindex]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
			}
			game->_enemy[enemyindex]._count_frame_has_fired = 10;
			if (_shower_object[i]._state == RAIN_SHOWER_STATE_HIT_TARGET)
			{
				_shower_object[i]._state = RAIN_SHOWER_STATE_END;
			}
		}
	}
	return hit;
}

void CRainShower::RObject::Init(int sprite, int frame, float speed, float speedscale, float scale)
{
	_speed = speed + CMath::RANDOM(0, speed);
	_speed_scale = speedscale;
	_scale_start = scale;
	_scale = _scale_start + CMath::RANDOM(0, 7) / 10.0f;
	_x = _y = 0;
	_tarx = _tary = 0;
	_rotate= 0;
	_spriteid = sprite;
	_frameid = frame;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(1, false);
	_anim.SetPos(0, 0);
	_state = RAIN_SHOWER_STATE_NONE;
	_count_frame_hold = 0;
	_frameid = frame;
	_opac = 100;
	for (int i = 0; i < RAIN_SHOWER_NUM_SHADOW; i++)
	{
		_smoke[i].Init(_spriteid,CMath::RANDOM(18, 20), 0.05f, 8);
	}
}
void CRainShower::RObject::Render(float x, float y)
{
	for (int i = 0; i < RAIN_SHOWER_NUM_SHADOW; i++)
	{
		_smoke[i].Render(x, y);
	}
	if (_state == RAIN_SHOWER_STATE_NONE)
	{
		return;
	}
	float angle = CMath::ANGLE(_x, _y, _tarx, _tary) - 90;
	
	switch (_state)
	{
	case RAIN_SHOWER_STATE_START:

		G()->SetRotate(angle, _x + x, _y + y);
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		if (_frameid == -1)
		{
			GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
		}
		else
		{
			_anim.SetPos(_x + x, _y + y);
			_anim.DrawAnimObject(G());
		}
		G()->ClearScale();
		G()->ClearRotate();
		break;
	case RAIN_SHOWER_STATE_HIT_TARGET:
	case RAIN_SHOWER_STATE_END:
		if (_frameid == -1)
		{
			GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
		}
		else
		{
			_anim.SetPos(_x + x, _y + y);
			_anim.DrawAnimObject(G());
		}
		break;
	default:
		break;
	}
}
void CRainShower::RObject::Update()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < RAIN_SHOWER_NUM_SHADOW; i++)
	{
		_smoke[i].Update();
	}
	if (_state == RAIN_SHOWER_STATE_NONE)
	{
		return;
	}
	if (_opac <= 0)
	{
		_opac = 0;
	}
	_count_frame_hold--;
	if (_count_frame_hold > 0)
	{
		return;
	}
	
	if (_frameid != -1)
	{
		_anim.UpdateAnimObject();
	}
	float angle = 0;
	switch (_state)
	{
	case RAIN_SHOWER_STATE_START:
		if (_y + _speed >= _tary)
		{
			_state = RAIN_SHOWER_STATE_HIT_TARGET;
			_anim.SetAnim(0, false);
			GAME()->PlaySFX(SFX_MAGE_METEOR);
			//_anim[i].UpdateAnimObject();
		}
		else
		{
			angle = CMath::ANGLE(_x, _y, _tarx, _tary);
			_x += _speed * CMath::COS(angle);
			_y += _speed * CMath::SIN(angle);
			if (_anim.IsCurrentAnimStop())
			{
				_anim.SetAnim(1, false);
			}
		}
		//_scale[i] += _speed_scale[i];
		//if (_count_frame_hold %2 == 0)
		{
			AddShadow(_x + CMath::RANDOM(-5, 5), _y + CMath::RANDOM(0, 5));
			AddShadow(_x + CMath::RANDOM(-5, 5), _y + CMath::RANDOM(-10, 15));
		}
		if (_scale >= 1.5f)
		{
			_scale = 1.5f;
		}
		break;
	case RAIN_SHOWER_STATE_HIT_TARGET:
		_opac -= 1;
		game->_shake_effectx = CMath::RANDOM(-5, 5);
		game->_shake_effecty = CMath::RANDOM(-5, 5);
		if (_anim.IsCurrentAnimStop())
		{
			_state = RAIN_SHOWER_STATE_NONE;
		}
		break;
	case RAIN_SHOWER_STATE_END:
		_opac -= 1;
		game->_shake_effectx = CMath::RANDOM(-5, 5);
		game->_shake_effecty = CMath::RANDOM(-5, 5);
		if (_anim.IsCurrentAnimStop())
		{
			_state = RAIN_SHOWER_STATE_NONE;
		}
		break;
	default:
		break;
	}
}
void CRainShower::RObject::Active(int index, float x, float y, float tarx, float tary, int rotate)
{
	_x = CMath::RANDOM(-9, 3) * 50 + x;
	_y = -index*5 + y;
	_count_frame_hold = index / 5 * 15;
	_tarx = _x + tarx;
	_tary = tary + CMath::RANDOM(0, 10) * 3;
	_state = RAIN_SHOWER_STATE_START;
	_anim.SetAnim(1, false);
}
void CRainShower::RObject::ForceEnd()
{
	_state = RAIN_SHOWER_STATE_END;
}
bool CRainShower::RObject::IsFree()
{
	if (_state != RAIN_SHOWER_STATE_NONE)
	{
		return false;
	}
	return true;
}
void CRainShower::RObject::AddShadow(float x, float y)
{
	for (int i = 0; i < RAIN_SHOWER_NUM_SHADOW; i++)
	{
		if (_smoke[i]._state == RAIN_SHOWER_STATE_NONE)
		{
			_smoke[i].Active(x, y, 0.3, 100);
			break;
		}
	}
}
