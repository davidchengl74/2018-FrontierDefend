#include "pch.h"
#include "../../GameCore/CGame.h"

CSkillRobo::CSkillRobo()
{
}

CSkillRobo::~CSkillRobo()
{
}

void CSkillRobo::Init(int sprite, int frame, float speed)
{
	_x = _y = 0;
	_tarx = _tary = 0;
	_posx = _posy = 0;
	_centerx = _centery = 0;
	_speed = speed;
	_rotate = 0;
	_speed_att = 0;
	_time = 0;
	_opac = 100;
	_frameid = frame;
	_spriteid = sprite;
	_count_frame_att = 0;
	_state = ROBO_STATE_NONE;
	_orien = ROBO_ORIEN_LEFT;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(0, false);
	_anim.SetPos(0, 0);
	InitAttackFrame();
	_enemy_index = 0;
}
void CSkillRobo::Render(float x, float y)
{
	RenderAttackFrame();
	if (_state == ROBO_STATE_NONE)
	{
		return;
	}
	_anim.SetPos(_x, _y);
	if (_orien == ROBO_ORIEN_RIGHT)
	{
		_rotate = _rotate - 180;
	}
	G()->SetRotate(_rotate, _x, _y);
	_anim.DrawAnimObject(G());
	G()->ClearRotate();
}
void CSkillRobo::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	UpdateAttackFrame();
	if (_state == ROBO_STATE_NONE)
	{
		return;
	}
	_anim.UpdateAnimObject();
	_time--;
	if (_x < _tarx)
	{
		_orien = ROBO_ORIEN_LEFT;
	}
	else if (_x > _tarx)
	{
		_orien = ROBO_ORIEN_RIGHT;
	}
	if (_orien == ROBO_ORIEN_LEFT)
	{
		if (_anim.GetCurrentAnim() > ROBO_NUM_ANIM)
		{
			_anim.SetAnim(_anim.GetCurrentAnim() - ROBO_NUM_ANIM, false);
		}
	}
	else
	{
		if (_anim.GetCurrentAnim() <= ROBO_NUM_ANIM)
		{
			_anim.SetAnim(_anim.GetCurrentAnim() + ROBO_NUM_ANIM, false);
		}
	}
	
	if (_time <= 0 && _state != ROBO_STATE_END)
	{
		_state = ROBO_STATE_END;
		_anim.SetAnim(ROBO_ANIM_END, false);
	}
	switch (_state)
	{
	case ROBO_STATE_ACTIVE:
		if (_anim.IsCurrentAnimStop())
		{
			_state = ROBO_STATE_FLY;
			if (_orien == ROBO_ORIEN_LEFT)
			{
				_anim.SetAnim(ROBO_ANIM_FLY, false);
			}
			else
			{
				_anim.SetAnim(ROBO_ANIM_FLY + ROBO_NUM_ANIM, false);
			}
		}
		break;
	case ROBO_STATE_FLY:
		//_rotate = CMath::ANGLE(_x, _y, _posx, _posy);
		if (CHECK_POINT_IN_CIRCLE(_x,_y,_posx,_posy,_speed))
		{
			_state = ROBO_STATE_IDLE;
			_x = _posx;
			_y = _posy;
		}
		else
		{
			float angle = CMath::ANGLE(_x, _y, _posx, _posy);
			_x += _speed*CMath::COS(angle);
			_y += _speed*CMath::SIN(angle);
			if (_anim.IsCurrentAnimStop())
			{
				if (_orien == ROBO_ORIEN_LEFT)
				{
					_anim.SetAnim(ROBO_ANIM_FLY, false);
				}
				else
				{
					_anim.SetAnim(ROBO_ANIM_FLY + ROBO_NUM_ANIM, false);
				}
			}
		}
		
		break;
	case ROBO_STATE_IDLE:
		_rotate = CMath::ANGLE(_x, _y, _tarx, _tary);
		_count_frame_att++;
		if (_count_frame_att >= _speed_att)
		{
			_enemy_index = game->GetEnemyIndexNearest(true);
			if (_enemy_index >= 0)
			{
				_tarx = game->_enemy[_enemy_index].GetPosX();
				if (_tarx < game->_screen_width)
				{
					_state = ROBO_STATE_ATTACK;
					if (_orien == ROBO_ORIEN_LEFT)
					{
						_anim.SetAnim(ROBO_ANIM_ATTACK, false);
					}
					else
					{
						_anim.SetAnim(ROBO_ANIM_ATTACK + ROBO_NUM_ANIM, false);
					}

					_count_frame_att = 0;
				}
			}
		}
		if (_anim.IsCurrentAnimStop())
		{
			if (_orien == ROBO_ORIEN_LEFT)
			{
				_anim.SetAnim(ROBO_ANIM_FLY, false);
			}
			else
			{
				_anim.SetAnim(ROBO_ANIM_FLY + ROBO_NUM_ANIM, false);
			}
		}
		break;
	case ROBO_STATE_ATTACK:
		_rotate = CMath::ANGLE(_x, _y, _tarx, _tary);
		if (_anim.IsCurrentAnimStop())
		{
			float tarx = CMath::RANDOM(-5, 10) * 20;
			float tary = 0;
			_state = ROBO_STATE_FLY;
			//_enemy_index = game->GetEnemyIndexNearest(true);
			if (_enemy_index >= 0)
			{
				_tarx = game->_enemy[_enemy_index].GetPosX();
				_tary = game->_enemy[_enemy_index].GetPosY() - game->_enemy[_enemy_index]._size_h / 2;
				_centerx = _tarx - 50;
				_centery = _tary - CMath::RANDOM(10,15)*10;
				AddAttackFrame(_enemy_index);
			}
			_posx = _centerx + tarx;
			_posy = _centery + tary;
			if (_posx > game->_screen_width - 50)
			{
				_posx = game->_screen_width - 50;
			}
			if (_orien == ROBO_ORIEN_LEFT)
			{
				_anim.SetAnim(ROBO_ANIM_FLY, false);
			}
			else
			{
				_anim.SetAnim(ROBO_ANIM_FLY + ROBO_NUM_ANIM, false);
			}
		}
		break;
	case ROBO_STATE_END:
		if (_anim.IsCurrentAnimStop())
		{
			_state = ROBO_STATE_NONE;
		}

		break;
	default:
		break;
	}
}
void CSkillRobo::Active(float x, float y, float posx, float posy, float speedatt, int time, int damage, int critical)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_x = x;
	_y = y;
	_centerx = posx;
	_centery = posy;
	_posx = posx;
	_posy = posy;
	_time = time;
	//printf("\n _time = %d", _time);
	_damage = damage;
	_critical = critical;
	_speed_att = speedatt;
	int enemyindex = game->GetEnemyIndexNearest(true);
	if (enemyindex >= 0)
	{
		_tarx = game->_enemy[enemyindex].GetPosX();
		_tary = game->_enemy[enemyindex].GetPosY() - game->_enemy[_enemy_index]._size_h / 2;
	}
	_anim.SetAnim(ROBO_ANIM_INIT, false);
	_state = ROBO_STATE_ACTIVE;
	_rotate = 0;
	GAME()->PlaySFX(SFX_ROBO_SKILL);
}
void CSkillRobo::ForceEnd()
{
	_state = ROBO_STATE_END;
	_anim.SetAnim(ROBO_ANIM_END, false);
}
bool CSkillRobo::IsFree()
{
	if (_state == ROBO_STATE_NONE)
	{
		return true;
	}
	return false;
}

void CSkillRobo::InitAttackFrame()
{
	for (int i = 0; i < ROBO_NUM_FRAME_ATTACK; i++)
	{
		_frame_attack[i].Init(_x, _y, SPRITEID_EFFECT_SKILL_ROBOT_01, 13, _damage, _critical);
	}
}
void CSkillRobo::AddAttackFrame(int enemy_index)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < ROBO_NUM_FRAME_ATTACK; i++)
	{
		if (_frame_attack[i].IsFree())
		{
			_frame_attack[i].Add(_x, _y , 40, enemy_index, _damage,0,_critical);
			break;
		}
	}
}
void CSkillRobo::RenderAttackFrame()
{
	for (int i = 0; i < ROBO_NUM_FRAME_ATTACK; i++)
	{
		float rotate = CMath::ANGLE(_frame_attack[i]._x, _frame_attack[i]._y, _tarx, _tary);
		/*if (_orien == ROBO_ORIEN_RIGHT)
		{
			rotate = rotate;
		}*/
		G()->SetRotate(rotate, _frame_attack[i]._x, _frame_attack[i]._y);
		_frame_attack[i].Render(0, 0);
		G()->ClearRotate();
	}
}
void CSkillRobo::UpdateAttackFrame()
{
	//TDGame *game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < ROBO_NUM_FRAME_ATTACK; i++)
	{
		_frame_attack[i].Update(true);
	}
}
void CSkillRobo::ResetAttackFrame()
{

}