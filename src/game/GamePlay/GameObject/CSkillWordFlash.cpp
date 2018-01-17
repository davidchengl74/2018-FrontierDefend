#include "pch.h"
#include "../../GameCore/CGame.h"

CSkillWordFlash::CSkillWordFlash()
{
}

CSkillWordFlash::~CSkillWordFlash()
{
}
void CSkillWordFlash::Init(float x, float y, int sprite, float speed)
{
	_x = x;
	_y = y;
	_anim.SetAnimSprite(GET_SPRITE(sprite), sprite);
	_anim.SetAnim(0, false);
	_anim.SetPos(_x, _y);
	_state = SKILL_WORD_FLASH_STATE_NORMAL;
	_speed = speed;
}
void CSkillWordFlash::Render(float x, float y, int opac)
{
	if (_state == SKILL_WORD_FLASH_STATE_NORMAL)
	{
		return;
	}
	if (_count_frame_hold > 0)
	{
		return;
	}
	_anim.SetPos(_x + x, _y + y);
	_anim.DrawAnimObject(G());
}
void CSkillWordFlash::Update()
{
	if (_state == SKILL_WORD_FLASH_STATE_NORMAL)
	{
		return;
	}
	
	TDGame *game = (TDGame*)GAME()->_current_game;
	
	//printf("\n _count_frame_hold = %d", _count_frame_hold);
	if (_count_frame_hold > 0)
	{
		_count_frame_hold--;
		if (_count_frame_hold <= 0)
		{
			_count_frame_hold = 0;
			GAME()->PlaySFX(SFX_SWORDMAN_SKILL);
		}
		else
		{
			return;
		}
	}
	_anim.UpdateAnimObject();
	if (_anim.IsCurrentAnimStop())
	{
		if (_anim.GetCurrentAnim() == 0)
		{
			_anim.SetAnim(1, false);
		}
		else
		{
			_anim.SetAnim(1, false);
		}
	}
	switch (_state)
	{
	case SKILL_WORD_FLASH_STATE_START:

		break;
	case SKILL_WORD_FLASH_STATE_ACTIVE:
		_x += _speed;
		if (_x >= game->_screen_width + 200)
		{
			_state = SKILL_WORD_FLASH_STATE_END;
		}
		break;
	case SKILL_WORD_FLASH_STATE_END:
		_state = SKILL_WORD_FLASH_STATE_NORMAL;
		break;
	default:
		break;
	}
}
void CSkillWordFlash::Active(float x, float y, int countframe, float speed)
{
	_count_frame_hold = countframe;
	_x = x;
	_y = y;
	_anim.SetAnim(0, false);
	_anim.SetPos(_x, _y);
	_state = SKILL_WORD_FLASH_STATE_ACTIVE;
	_speed = speed;
	for (int i = 0; i < NUM_MAX_ENEMY;i++)
	{
		_list_target[i] = -1;
	}
}
void CSkillWordFlash::CheckEnemyAround(int enemyindex, float aoe, int damage, float critical)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	float enemy_x = game->_enemy[enemyindex].GetPosX();
	float enemy_y = game->_enemy[enemyindex].GetPosY();
	float enemy_w = game->_enemy[enemyindex]._size_w;
	//if (game->_enemy[enemyindex].GetState() < CHARACTER_STATE_DIE && enemy_x < game->_screen_width)
	if (game->_enemy[enemyindex].IsLive() && enemy_x < game->_screen_width)
	{
		if (_list_target[enemyindex] == -1)
		{
			//if (CheckEnemyAround(enemy_x, enemy_y, enemy_w))
			float angle = CMath::ANGLE(_x - k_SCREEN_WIDTH / 2, _y - 150, enemy_x, enemy_y);
			if (enemy_x <= _x*CMath::COS(angle) && enemy_x >= _x - 150)
			{
				int rand = CMath::RANDOM(1, 100);
				INT_TIME damage_real = damage;
				float posx = enemy_x + CMath::RANDOM(-3, 3) * 3;
				float posy = enemy_y - game->_enemy[enemyindex]._size_h + CMath::RANDOM(-5, 0) * 10;
				game->_enemy[enemyindex].SetState(CHARACTER_STATE_BEHIT);
				game->_enemy[enemyindex].SetPos(enemy_x + 50, game->_enemy[enemyindex].GetPosY());
				if (rand <= critical)
				{
					damage_real *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
					game->_enemy[enemyindex].AddHP(-damage_real, 1, SPRITEID_EFFECT_HIT, false);
					game->AddEffectHPLost(damage_real, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
					game->_user._quest_num_critical_hit++;
				}
				else
				{
					game->_enemy[enemyindex].AddHP(-damage_real, 1, SPRITEID_EFFECT_HIT, false);
					game->AddEffectHPLost(damage_real, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
				}
				_list_target[enemyindex] = 1000;
			}
		}
		else
		{
			_list_target[enemyindex] --;
			if (_list_target[enemyindex] <= 0)
			{
				_list_target[enemyindex] = -1;
			}
		}
	}
}

bool CSkillWordFlash::IsFree()
{
	if (_state == SKILL_WORD_FLASH_STATE_END || _state == SKILL_WORD_FLASH_STATE_NORMAL)
	{
		return true;
	}
	return false;
}