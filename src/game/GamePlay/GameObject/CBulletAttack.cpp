#include "pch.h"
#include "../../GameCore/CGame.h"


CBulletAttack::CBulletAttack()
{
}

CBulletAttack::~CBulletAttack()
{
}
void CBulletAttack::Init(float x, float y, int sprite, int frame, int damage, float critical)
{
	_x = x;
	_y = y;
	_targetx = _x;
	_targety = _y;
	_frame = frame;
	_speed = 0;
	_enemy_target = 0;
	_sprite = sprite;
	_damage = damage;
	_critical = critical;
	_state = -1;
	_aoe = 0;
}
void  CBulletAttack::Add(float x, float y, float speed, int enemytarget, int damage, int aoe, int critical)
{
	_x = x;
	_y = y;
	_targetx = _x;
	_targety = _y;
	_speed = speed;
	_enemy_target = enemytarget;
	_state = 0;
	_damage = damage;
	_aoe = aoe;
	_critical = critical;
}
void CBulletAttack::Render(float x, float y)
{
	if (_state == -1)
	{
		return;
	}
	GET_SPRITE(_sprite)->DrawFrame(G(), _frame, _x + x, _y + y);
}
void CBulletAttack::Update(bool lose)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_state == -1)
	{
		return;
	}
	if (_enemy_target >= 0)
	{
		_targetx = game->_enemy[_enemy_target].GetPosX() - game->_enemy[_enemy_target]._size_w / 2;
		if (lose)
		{
			_targetx = game->_enemy[_enemy_target].GetPosX();
		}		
	}
	else 
	{
		if (!lose)
		{
			_targetx = k_SCREEN_WIDTH * 2;
		}
	}
	if (lose)
	{
		_targety = game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h / 2;
	}
	INT_TIME damage = _damage;
	int rand = CMath::RANDOM(1, 100);
	if (_aoe > 0)
	{
		bool hit = false;
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			int enemy_posx = game->_enemy[i].GetPosX() /*- game->_enemy[i]._size_w/2*/;
			int enemy_posy = game->_enemy[i].GetPosY();
			//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || enemy_posx >= game->_screen_width)
			if (!game->_enemy[i].IsLive() || enemy_posx >= game->_screen_width)
			{
				if (_enemy_target == i)
				{
					if (!lose)
					{
						_targetx = k_SCREEN_WIDTH * 2;
					}
				}
				continue;
			}
			
			float dis = CMath::DISTANCE(_x, _y, enemy_posx, enemy_posy);
			/*if ((enemy_posx <= _x + _range_damage_aoe && enemy_posx >= _x && _oritation == HERO_ORITATION_RIGHT) ||
			(enemy_posx >= _x - _range_damage_aoe && enemy_posx <= _x && _oritation == HERO_ORITATION_LEFT))*/
			if (dis <= _aoe / 2 + game->_enemy[i]._size_w / 2)
			{
				if (rand <= _critical)
				{
					game->_user._quest_num_critical_hit++;
					damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
					game->AddEffectHPLost(damage, game->_enemy[i].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[i].GetPosY() - game->_enemy[i]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
				}
				else
				{
					game->AddEffectHPLost(damage, game->_enemy[i].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[i].GetPosY() - game->_enemy[i]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
				}
				hit = true;
				game->_enemy[i].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_SKILL_SWORDMAN_02, false);
			}
			
		}
		if (hit)
		{
			_state = -1;
		}
		else
		{
			float angle = CMath::ANGLE(_x, _y, _targetx, _targety);
			_x += _speed*CMath::COS(angle);
			_y += _speed*CMath::SIN(angle);
			if (_x > game->_screen_width)
			{
				_state = -1;
			}
		}
	}
	else
	{
		if (CHECK_POINT_IN_CIRCLE(_x, _y, _targetx, _targety, _speed))
		{
			if (_enemy_target >= 0)
			{
				int rand = CMath::RANDOM(1, 100);
				INT_TIME damage = _damage;
				if (rand <= _critical)
				{
					game->_user._quest_num_critical_hit++;
					damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
					game->AddEffectHPLost(damage, game->_enemy[_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
				}
				else
				{
					game->AddEffectHPLost(damage, game->_enemy[_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
				}
				game->_enemy[_enemy_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
			}

			_state = -1;
		}
		else
		{
			float angle = CMath::ANGLE(_x, _y, _targetx, _targety);
			_x += _speed*CMath::COS(angle);
			_y += _speed*CMath::SIN(angle);
			if (_x > game->_screen_width)
			{
				_state = -1;
			}
		}
	}

	
}
bool CBulletAttack::IsFree()
{
	if (_state == -1)
	{
		return true;
	}
	return false;
}