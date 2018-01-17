#include "pch.h"
#include "../../GameCore/CGame.h"

CBeastMaster::CBeastMaster()
{
}

CBeastMaster::~CBeastMaster()
{
}

void CBeastMaster::Init(float x, float y, int sprite, float speed)
{
	_x = x;
	_y = y;
	_anim.SetAnimSprite(GET_SPRITE(sprite), sprite);
	_anim.SetAnim(0, true);
	_anim.SetPos(_x, _y);
	_anim_effect.SetAnimSprite(GET_SPRITE(sprite), sprite);
	_anim_effect.SetAnim(1, true);
	_anim_effect.SetPos(_x, _y);
	_state = SKILL_BEAST_MASTER_STATE_NORMAL;
	_speed = speed;
}
void CBeastMaster::Render(float x, float y, int opac)
{
	if (_state == SKILL_BEAST_MASTER_STATE_NORMAL)
	{
		return;
	}
	_anim.SetPos(_x + x, _y + y);
	_anim.DrawAnimObject(G());
	_anim_effect.SetPos(_effect_x + x, _effect_y + y);
	_anim_effect.DrawAnimObject(G());
}
void CBeastMaster::Update()
{
	if (_state == SKILL_BEAST_MASTER_STATE_NORMAL)
	{
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim.UpdateAnimObject();
	_anim_effect.UpdateAnimObject();
	//printf("\n _count_frame_hold = %d", _count_frame_hold);
	if (_count_frame_hold > 0)
	{
		_count_frame_hold--;
		if (_count_frame_hold <= 0)
		{
			_count_frame_hold = 0;
			GAME()->PlaySFX(SFX_BEASTMASTER_SKILL);
		}
		else
		{
			return;
		}
		
	}
	switch (_state)
	{
	case SKILL_BEAST_MASTER_STATE_START:
		
		break;
	case SKILL_BEAST_MASTER_STATE_ACTIVE:
		_x += _speed;
		_effect_x += _speed;
		if (_x >= game->_screen_width + 100)
		{
			_state = SKILL_BEAST_MASTER_STATE_END;
		}
		break;
	case SKILL_BEAST_MASTER_STATE_END:
		_state = SKILL_BEAST_MASTER_STATE_NORMAL;
		break;
	default:
		break;
	}
}
void CBeastMaster::Active(float x, float y, int countframe, float speed)
{
	_count_frame_hold = countframe;
	_x = x;
	_y = y;
	_anim.SetAnim(0, true);
	_anim.SetPos(_x, _y);
	_anim_effect.SetAnim(1, true);
	_effect_x = _x + CMath::RANDOM(-10, 10) * 5;
	_effect_y = _y + CMath::RANDOM(0,10)*3;
	_anim_effect.SetPos(_effect_x, _effect_y);
	_state = SKILL_BEAST_MASTER_STATE_ACTIVE;
	_speed = speed;
}
void CBeastMaster::CheckEnemyAround(int enemyindex, float aoe, int damage, float critical)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	float enemy_x = game->_enemy[enemyindex].GetPosX();
	float enemy_y = game->_enemy[enemyindex].GetPosY();
	float enemy_w = game->_enemy[enemyindex]._size_w;

	if (game->_enemy[enemyindex]._status >= CHARACTER_STATUS_FLY && game->_enemy[enemyindex]._status <= CHARACTER_STATUS_CARRY_FLY)
	{
		return;
	}
	float dis = CMath::ABSOLUTE_VALUE(_x - enemy_x);// CMath::DISTANCE(_x, _y, enemy_x, enemy_y);
	if (dis <= (enemy_w / 2 /*+ aoe / 2*/) && game->_enemy[enemyindex]._beskill_beatmaster_time <= 0 && _x < enemy_x)
	{
		int rand = CMath::RANDOM(1, 100);
		float posx = enemy_x + CMath::RANDOM(-3, 3) * 3;
		float posy = enemy_y - game->_enemy[enemyindex]._size_h + CMath::RANDOM(-5, 0) * 10;
		if (rand <= critical)
		{
			damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
			game->_enemy[enemyindex].AddHP(-damage, 1, SPRITEID_EFFECT_SKILL_MAGELIGHTING_01, false);
			game->AddEffectHPLost(damage, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
		}
		else
		{
			game->_enemy[enemyindex].AddHP(-damage, 1, SPRITEID_EFFECT_SKILL_MAGELIGHTING_01, false);
			game->AddEffectHPLost(damage, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
		}
		game->_enemy[enemyindex].BeSkillActive(BE_SKILL_BURN_BY_HERO);
	}
}

bool CBeastMaster::IsFree()
{
	if (_state == SKILL_BEAST_MASTER_STATE_END || _state == SKILL_BEAST_MASTER_STATE_NORMAL)
	{
		return true;
	}
	return false;
}
