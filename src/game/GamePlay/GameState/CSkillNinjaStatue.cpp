#include "pch.h"
#include "../../GameCore/CGame.h"

CNinjaStatue::CNinjaStatue()
{
}

CNinjaStatue::~CNinjaStatue()
{
}
void CNinjaStatue::Init(int sprite, INT_TIME timelive, INT_TIME hp)
{
	_spriteid = sprite;
	_state = SKILL_NINJA_STATUE_STATE_NONE;
	_x = 0;
	_y = 0;
	_time_live = timelive;
	_hp = hp;
	_hp_max = hp;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_INIT, false);
	_anim.SetPos(_x, _y);
	_aoe = 0;
	_damage = 0;
	_critical = 0;
	_shakex = 0;
	_shakey = 0;
	_count_frame_shake = 0;
}

void CNinjaStatue::Active(float x, float y, INT_TIME hp, INT_TIME timelive, INT_TIME damage, float aoe, int critical)
{
	_x = x;
	_y = y;
	_hp = hp;
	_hp_max = hp;
	_state = SKILL_NINJA_STATUE_STATE_START;
	_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_INIT, false);
	_anim.SetPos(_x, _y);
	_time_live = timelive;
	_damage = damage;
	_aoe = aoe;
	_critical = critical;
	_shakex = 0;
	_shakey = 0;
	_count_frame_shake = 0;
}
void CNinjaStatue::AddDrawManager(float x, float y)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	game->_draw_manager_able.Add(&_anim, _x + x + _shakex, _y + y + _shakey, DRAWABLE_TYPE_NORMAL, 0);
}
void CNinjaStatue::Render(float x, float y)
{
	if (_state == SKILL_NINJA_STATUE_STATE_NONE)
	{
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim.SetPos(_x + x + _shakex, _y + y + _shakey);
	//_anim.DrawAnimObject(G());
	//game->_draw_manager_able.Add(&_anim, _x + x + _shakex, _y + y + _shakey, DRAWABLE_TYPE_NORMAL, 0);
	RenderHealthBar(0, 0);
}
void CNinjaStatue::Update()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	if (_state == SKILL_NINJA_STATUE_STATE_NONE)
	{
		return;
	}
	if (_count_frame_shake > 0)
	{
		_count_frame_shake--;
		_shakex = CMath::RANDOM(-3, 3);
		_shakey = CMath::RANDOM(-3, 3);
	}
	if (_count_frame_shake <= 0)
	{
		_count_frame_shake = 0;
		_shakex = 0;
		_shakey = 0;
	}
	_anim.UpdateAnimObject();
	_time_live--;
	if (_state < SKILL_NINJA_STATUE_STATE_DIE && _time_live <= 0)
	{
		_state = SKILL_NINJA_STATUE_STATE_DIE;
		_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_DIE, false);
	}
	switch (_state)
	{
	case SKILL_NINJA_STATUE_STATE_START:
		if (_anim.IsCurrentAnimStop())
		{
			_state = SKILL_NINJA_STATUE_STATE_ACTIVE;
		}
		break;
	case SKILL_NINJA_STATUE_STATE_ACTIVE:
		if (_anim.IsCurrentAnimStop())
		{
			float hp_percent = ((float)_hp / (float)_hp_max) * 100;
			if (hp_percent > 20 && _time_live >= 5 * 60)
			{
				_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_IDLE, false);
			}
			else
			{
				_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_DIE_READY, false);
			}
		}
		break;
	case SKILL_NINJA_STATUE_STATE_DIE:
		if (_anim._current_aframes - GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim.GetCurrentAnim()) == 4)
		{
			for (int i = 0; i < game->_num_enemy_inwave; i++)
			{
				//INT_TIME damage = _damage;
				//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE)
				if (game->_enemy[i].IsLive())
				{
					CheckEnemyAround(i, _aoe, _damage, _critical);
				}
			}
		}
		if (_anim.IsCurrentAnimStop())
		{
			_state = SKILL_NINJA_STATUE_STATE_END;
		}
		break;
	case SKILL_NINJA_STATUE_STATE_END:
		_state = SKILL_NINJA_STATUE_STATE_NONE;
		break;
	default:
		break;
	}
}
void CNinjaStatue::AddHP(INT_TIME hp)
{
	_hp += hp;
	if (hp < 0)
	{
		_count_frame_shake = 10;
	}
	if (_hp <= 0 )
	{
		if (_state < SKILL_NINJA_STATUE_STATE_DIE && _state > SKILL_NINJA_STATUE_STATE_NONE)
		{
			_state = SKILL_NINJA_STATUE_STATE_DIE;
			_anim.SetAnim(SKILL_NINJA_STATUE_ANIM_DIE, false);
		}
	}
}

void CNinjaStatue::RenderHealthBar(float x, float y)
{
	int clipx = _x - GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(55) / 2;
	int clipy = _y - 150;
	//printf("\n _anim_height = %d", _anim_height);
	int clipw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(55);
	int cliph = k_SCREEN_HEIGHT;
	int clip_current = _hp / (_hp_max*1.0f)*clipw;
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 53, _x + x, clipy + y);
	G()->SetClip(clipx + (clipw - clip_current), 0, clipw, cliph);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 53, _x + x, clipy + y);
	G()->ClearClip();
	G()->SetClip(clipx + (clipw - clip_current), 0, clipw, cliph);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 54, _x + x, clipy + y);
	G()->ClearClip();
}

bool CNinjaStatue::IsFree()
{
	if (_state == SKILL_NINJA_STATUE_STATE_NONE)
	{
		return true;
	}
	return false;
}

void CNinjaStatue::CheckEnemyAround(int enemyindex, float aoe, INT_TIME damage, float critical)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	float posx = game->_enemy[enemyindex].GetPosX();
	float posy = game->_enemy[enemyindex].GetPosY();
	float dis = CMath::DISTANCE(k_SCREEN_WIDTH/2, ROAD_POSY, posx, posy);
	int rand = CMath::RANDOM(1, 100);
	if (dis <= (game->_enemy[enemyindex]._size_w / 2 + aoe / 2) && CMath::ABSOLUTE_VALUE(ROAD_POSY - posy) <= aoe / 2)
	{
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
		game->_enemy[enemyindex]._count_frame_has_fired = 5;
	}
}