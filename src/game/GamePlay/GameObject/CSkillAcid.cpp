#include "pch.h"
#include "../../GameCore/CGame.h"

CSkillAcid::CSkillAcid()
{
}

CSkillAcid::~CSkillAcid()
{
}
void CSkillAcid::Init(int sprite, int speedatt)
{
	_spriteid = sprite;
	_state = SKILL_ACID_STATE_NONE;
	_x = 0;
	_y = 0;
	_time_live = 0;
	_anim_tower.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_tower.SetAnim(SKILL_ACID_ANIM_INIT, false);
	_anim_tower.SetPos(_x, _y);
	_anim1.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim1.SetAnim(3, true);
	_anim1.SetPos(_x, _y);
	_anim2.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim2.SetAnim(3, true);
	_anim2.SetPos(_x, _y);
	_aoe = 0;
	_damage = 0;
	_critical = 0;
	_speed_att = speedatt;
	_count_frame_att = 0;
	_effposx = 0;
	_effposy = 0;
}

void CSkillAcid::Active(float x, float y, INT_TIME timelive, INT_TIME damage, float aoe, int critical)
{
	_x = x;
	_y = y;
	_state = SKILL_ACID_STATE_START;
	_anim_tower.SetAnim(SKILL_ACID_ANIM_INIT, false);
	_anim_tower.SetPos(_x, _y);
	_effposx = CMath::RANDOM(2, 3) * 10;
	_effposy = 45;
	_anim1.SetAnim(CMath::RANDOM(4,5), false);
	_anim1.SetPos(_x - _effposx, _y + _effposy);
	_anim2.SetAnim(CMath::RANDOM(4, 5), false);
	_anim2.SetPos(_x + _effposx, _y + _effposy);
	_time_live = timelive;
	_damage = damage;
	_aoe = aoe;
	_critical = critical;
	_count_frame_att = 0;
	_opac = 100;
}

void CSkillAcid::AddDrawManager(float x, float y)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_state == SKILL_ACID_STATE_NONE)
	{
		return;
	}
	printf("\n acid render x = %f, y = %f", _x + x, _y + y);
	game->_draw_manager_able.Add(&_anim_tower, _x + x, _y + y, DRAWABLE_TYPE_NORMAL, 0);
}

void CSkillAcid::Render(float x, float y)
{
	if (_state == SKILL_ACID_STATE_NONE)
	{
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim1.SetPos(_x + x - _effposx, _y + y + _effposy);
	_anim2.SetPos(_x + x + _effposx, _y + y + _effposy);
	_anim_tower.SetPos(_x + x, _y + y);
	//_anim_tower.DrawAnimObject(G());
	if (_state >= SKILL_ACID_STATE_ACTIVE)
	{
		G()->SetOpacity(_opac);
		_anim1.DrawAnimObject(G());
		_anim2.DrawAnimObject(G());
		G()->SetOpacity(100);
	}
}
void CSkillAcid::Update()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	if (_state == SKILL_ACID_STATE_NONE)
	{
		return;
	}
	_anim1.UpdateAnimObject();
	_anim2.UpdateAnimObject();
	_anim_tower.UpdateAnimObject();
	_time_live--;
	if (_state < SKILL_ACID_STATE_DIE && _time_live <= 0)
	{
		_state = SKILL_ACID_STATE_DIE;
		_anim_tower.SetAnim(SKILL_ACID_ANIM_DIE, false);
	}
	switch (_state)
	{
	case SKILL_ACID_STATE_START:
	{
		int anim_frame_cur = GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim_tower.GetCurrentAnim());
		if (_anim_tower.IsCurrentAnimStop())
		{
			_state = SKILL_ACID_STATE_ACTIVE;
			_anim_tower.SetAnim(SKILL_ACID_ANIM_IDLE, false);
			GAME()->PlaySFX(SFX_POISION_SKILL);
		}

		if (_anim_tower._current_aframes - anim_frame_cur > 11
			&& _anim_tower._current_aframes - anim_frame_cur <= 20)
		{
			game->_shake_effectx = CMath::RANDOM(-3, 3);
			game->_shake_effecty = CMath::RANDOM(-3, 3);
		}
	}
		break;
	case SKILL_ACID_STATE_ACTIVE:
		_count_frame_att++;
		if (_count_frame_att >= _speed_att)
		{
			_state = SKILL_ACID_STATE_HITDAMAGE;
			_anim_tower.SetAnim(SKILL_ACID_ANIM_ATTACK, false);
			_effposx = CMath::RANDOM(2, 3) * 10;
			_effposy = 30;
			_anim1.SetAnim(CMath::RANDOM(4, 5), false);
			_anim1.SetPos(_x - _effposx, _y + _effposy);
			_anim2.SetAnim(CMath::RANDOM(4, 5), false);
			_anim2.SetPos(_x + _effposx, _y + _effposy);
		}
		if (_anim_tower.IsCurrentAnimStop())
		{
			_anim_tower.SetAnim(SKILL_ACID_ANIM_IDLE, false);
		}
		game->_shake_effectx = 0;
		game->_shake_effecty = 0;
		break;
	case SKILL_ACID_STATE_HITDAMAGE:
		_count_frame_att++;
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE)
			if (game->_enemy[i].IsLive())
			{
				if (_count_frame_att <= _speed_att + 5)
				{
					CheckEnemyAround(i, _aoe, _damage, _critical);
				}
			}
		}
		if (_anim_tower.IsCurrentAnimStop())
		{
			_state = SKILL_ACID_STATE_ACTIVE;
			_anim_tower.SetAnim(SKILL_ACID_ANIM_IDLE, false);
			_count_frame_att = 0;
		}
		break;
	case SKILL_ACID_STATE_DIE:
		_opac -= 10;
		if (_anim_tower.IsCurrentAnimStop())
		{
			_state = SKILL_ACID_STATE_END;
		}
		break;
	case SKILL_ACID_STATE_END:
		_state = SKILL_ACID_STATE_NONE;
		break;
	default:
		break;
	}
}

bool CSkillAcid::IsFree()
{
	if (_state == SKILL_ACID_STATE_NONE)
	{
		return true;
	}
	return false;
}

bool CSkillAcid::CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical)
{
	bool ret = false;
	TDGame * game = (TDGame*)GAME()->_current_game;
	float posx = game->_enemy[enemyindex].GetPosX();
	float posy = game->_enemy[enemyindex].GetPosY();
	float dis = CMath::DISTANCE(_x, _y, posx, posy);
	int rand = CMath::RANDOM(1, 100);
	if (game->_enemy[enemyindex]._count_frame_has_acid > 0)
	{
		return ret;
	}
	if (dis <= (game->_enemy[enemyindex]._size_w / 2 + aoe / 2) && CMath::ABSOLUTE_VALUE(ROAD_POSY - posy) <= aoe / 2)
	{
		ret = true;
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
		game->_enemy[enemyindex]._count_frame_has_acid = 1;
	}
	return ret;
}