#include "pch.h"
#include "../../GameCore/CGame.h"

CCharacter::CCharacter()
{
}

CCharacter::~CCharacter()
{
}

void CCharacter::Init(char* id, float x, float y, float tarx, float tary, INT_TIME hp, INT_TIME damage, int coin, int size, int skill, int timerepawn)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_speed = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Move_Speed;
	int param_att_speed = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Attack_Speed;
	int param_type_att = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Range;
	int param_sprite = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::SpriteID;
	int param_aoe = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::AOE;
	sprintf(_id, "%s", id);
	_targetx = tarx;
	_targety = tary;
	_hp = hp;
	
	_damage = damage;
	_coin = coin;
	_size = size;
	_skill = skill;
	_creation_index = game->GetEnemyCreationIndex(_id);
	_speed = game->GetDesignEnemyCreationGeneralFLoat(_creation_index, param_speed);
	
	_attack_speed = game->GetDesignEnemyCreationGeneral(_creation_index,param_att_speed);
	
	_range = game->GetDesignEnemyCreationGeneral(_creation_index, param_type_att);
	if (_range > 0)
	{
		_type_attack = CHARACTER_TYPE_ATTACK_RANGE;
		_range += CMath::ABSOLUTE_VALUE( game->_point_o.X);
	}
	else
	{
		_type_attack = CHARACTER_TYPE_ATTACK_MELEE;
		_range = CHARACTER_RANGE_ATTACK_MELEE + CMath::RANDOM(0,5)*3;
	}
	int index = game->GetDesignEnemyCreationGeneral(_creation_index, param_sprite);
	_spriteid = game->_character_sprite[index];
	game->LoadSpriteOptimize(_spriteid,true,!CGame::_this->_isNeedOptimize);
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(CHARACTER_ANIM_IDLE, false);
	_anim.SetPos(0, 0);
	_count_frame_attack = 0;
	SetPos(x, y);	
	_time_repawn = timerepawn;
	_count_frame_repawn = 0;
	_is_ready = false;
	_num_hit_attacked = 0;
	SetState(CHARACTER_STATE_RUN);
	_aoe = game->GetDesignEnemyCreationGeneralFLoat(_creation_index, param_aoe);
	_effect_behit_count_render = 30;
	_anim_effect_behit.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_HIT), SPRITEID_EFFECT_HIT);
	_anim_effect_behit.SetAnim(0, false);
	_anim_effect_behit.SetPos(_x, _y - 30);
	_anim_height = GET_SPRITE(_spriteid)->GetFrameHeight(0);
	_skill_active = false;
	_anim_marker.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_marker.SetAnim(9, false);
	_anim_marker.SetPos(0, 0);
	_effect_start_in.Init(EFFECT_STARTIN_TYPE_JUMP);
	_be_skill_id = BE_SKILL_NONE;
	_be_skill_time = 0;
	_be_skill_value = 0;
	_effect_be_skill.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_effect_be_skill.SetAnim(9, false);
	_effect_be_skill.SetPos(0, 0);
	_num_coin_collect = 0;
	_size_h = GET_SPRITE(_spriteid)->GetFModuleHeight(0,1);
	_size_w = GET_SPRITE(_spriteid)->GetFModuleWidth(0, 1);
	if (_spriteid == SPRITEID_MONSTER_THIEF_01 || _spriteid == SPRITEID_MONSTER_TECHIES)
	{
		SetPos(x, ROAD_POSY + 6*3);
	}
	GetRelicsBonus(true,0);
	_hp_max = _hp;
	_enemy_bird_index = -1;
	_count_frame_has_fired = 0;
	_count_frame_has_acid = 0;
	_effect_rotate = 0;
	_speed_fly = 0;
	_fly_up = false;
	_speed_rotate = 0;
	_status = CHARACTER_STATUS_NORMAL;
	if (_spriteid == SPRITEID_MONSTER_FLYING || _spriteid == SPRITEID_MONSTER_FLYING_01)
	{
		_status = CHARACTER_STATUS_CARRY_FLY;
		if (_spriteid == SPRITEID_MONSTER_FLYING_01)
		{
			_y = WEAPON_ACHER_POSY + CMath::RANDOM(-5, 5) * 3 ;
			_targety = _y;
		}
	}
	_target_focus = CHARACTER_TARGET_CASTLE;
	_be_stun_available = false;
	_heathbar_count_frame_render = 0;
	_heathbar_opac = 0;
	_beskill_beatmaster_time = 0;
	if (_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
	{
		int param_att_speed_mul = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Attack_Speed_If_boss;
		_attack_speed *= (game->GetDesignEnemyCreationGeneral(_creation_index, param_att_speed_mul)/100.0f);
	}
}
void CCharacter::RenderEffect(float x, float y, int opac)
{
	if (_state == CHARACTER_STATE_DIE_END)
	{
		return;
	}
	if (!HasAvailable())
	{
		return;
	}
	
    float offset = 0;
    if(_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
    {
        offset = _size_h;
    }
    if (_state < CHARACTER_STATE_DIE)
    {
        RenderHealthBar(0, 0-offset);
        BeSkillRender(0, 0);
        BeStunRender(0, 0);
    }
    else
    {
        if (!_anim.IsCurrentAnimStop())
        {
            RenderHealthBar(0, 0);
        }
    }
}
void CCharacter::Render(float x, float y, int opac)
{
	if (_state == CHARACTER_STATE_DIE_END)
	{
		return;
	}
	if (!HasAvailable())
	{
		return;
	}

	TDGame *game = (TDGame*)GAME()->_current_game;
	
	int type = DRAWABLE_TYPE_NORMAL;
	if (_state == CHARACTER_STATE_BEHIT || _state == CHARACTER_STATE_DIE_START)
	{
		type = DRAWABLE_TYPE_BEHIT;
	}
	if (_be_skill_time > 0)
	{
		switch (_be_skill_id)
		{
		case BE_SKILL_NONE:
			break;
		case BE_SKILL_SLOW:
			type = DRAWABLE_TYPE_BESKILL_ICE;
			break;
		default:
			break;
		}
	}
    float offset = 0;
    if(_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
    {
        offset = _size_h;
    }
	if (_state < CHARACTER_STATE_DIE)
	{
		/*RenderHealthBar(0, 0-offset);
		BeSkillRender(0, 0);
		BeStunRender(0, 0);*/
	}
	else
	{
		/*if (!_anim.IsCurrentAnimStop())
		{
			RenderHealthBar(0, 0);
		}*/
		type = DRAWABLE_TYPE_NORMAL;
	}
    float zoom = 1.0f;
    if(_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
    {
        zoom = 2.0f;
    }
	if (_spriteid == SPRITEID_MONSTER_TECHIES)
	{
		zoom = 1.3f;
	}
	if (_spriteid != SPRITEID_MONSTER_FLYING)
	{
		if (_status >= CHARACTER_STATUS_FLY && _status <= CHARACTER_STATUS_CARRY_FLY)
		{
			if (_state != CHARACTER_STATE_DIE)
			{
				game->_draw_manager_able.Add(&_anim, _x + x, _y + y, type, _effect_rotate,zoom);
			}
		}
		else
		{
			if (_spriteid == SPRITEID_MONSTER_TECHIES)
			{
				if (_state > CHARACTER_STATE_DIE_START)
				{
					game->_draw_manager_able.Add(&_anim, _x + x, _y + y, DRAWABLE_TYPE_NORMAL, _effect_rotate, zoom);
				}
				else
				{
					game->_draw_manager_able.Add(&_anim, _x + x, _y + y, type, _effect_rotate, zoom);
				}
			}
			else
			{
				game->_draw_manager_able.Add(&_anim, _x + x, _y + y, type, _effect_rotate, zoom);
			}
			
		}
	}
}
void CCharacter::Update()
{
	
	if (_state == CHARACTER_STATE_DIE_END)
	{
		return;
	}
	if (!HasAvailable())
	{
		_count_frame_repawn++;
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim.UpdateAnimObject();
	if (_state == CHARACTER_STATE_DIE)
	{
		if (_anim.IsCurrentAnimStop())
		{
			_state = CHARACTER_STATE_DIE_END;
		}
	}
	if (_beskill_beatmaster_time > 0)
	{
		_beskill_beatmaster_time--;
	}
	UpdateSkill();
	_effect_start_in.Update();
	if (_effect_behit_count_render < 30)
	{
		_effect_behit_count_render++;
		_anim_effect_behit.UpdateAnimObject();
	}
	BeSkillUpdate();
	BeStunUpdate();
    if (_effect_start_in._state != EFFECT_STARTIN_STATE_NONE)
    {
        _x = _effect_start_in._x;
        _y = _effect_start_in._y;
    }
	if (_count_frame_has_fired > 0)
	{
		_count_frame_has_fired--;
	}
	if (_count_frame_has_acid > 0)
	{
		_count_frame_has_acid--;
	}
	if (_count_frame_has_tornado > 0)
	{
		_count_frame_has_tornado--;
	}
	
	if (_enemy_bird_index >= 0)
	{
		if (game->_enemy[_enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
		{
			int bird_sprite = game->_enemy[_enemy_bird_index].GetSprite();
			int mposx = 0;
			int mposy = 0;
			int frame_index = game->_enemy[_enemy_bird_index]._anim._anim_sprite->_aframe_id[game->_enemy[_enemy_bird_index]._anim._current_aframes];
			mposx = GET_SPRITE(bird_sprite)->GetFModuleCenterX(frame_index, 2) + game->_enemy[_enemy_bird_index].GetPosX();
			mposy = GET_SPRITE(bird_sprite)->GetFModuleCenterY(frame_index, 2) + game->_enemy[_enemy_bird_index].GetPosY() - 12 + _size_h;
			_x = mposx;
			_y = mposy;
			if (_anim.IsCurrentAnimStop() || _state != CHARACTER_STATE_IDLE)
			{
				SetState(CHARACTER_STATE_IDLE);
				_anim.SetAnim(10, false);
			}
			_status = CHARACTER_STATUS_CARRY_FLY;
		}
		else
		{
			_y += 20;
			if (_y >= _targety)
			{
				_y = _targety + 1;
				_status = CHARACTER_STATUS_NORMAL;
			}
		}
	}
	if (!IsLive() || _hp <= 0)
	{
		if (_anim.IsCurrentAnimStop())
		{
			if (_state == CHARACTER_STATE_DIE_START)
			{
				SetState(CHARACTER_STATE_DIE);
				if (_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
				{
					int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
					int param_gem = CGameDesign::FileTreasure::CSheetSheet1::gem;
					int param_type = CGameDesign::FileTreasure::CSheetSheet1::Type;
					game->_boss_reward_type = game->GetDesignTreasure(game->_battle_current, param_type,false);
					game->_boss_reward_coin = game->GetDesignTreasure(game->_battle_current, param_coin,false);
					game->_boss_reward_gem = game->GetDesignTreasure(game->_battle_current, param_gem,false);
					if (game->_user._iap_starter_double_coin_time > 0)
					{
						game->_boss_reward_coin *= 2;
					}
					if (game->_user._has_double_coin)
					{
						game->_boss_reward_coin *= 2;
					}
					if (game->_boss_reward_type != 0)
					{
						game->_boss_reward.Active(SPRITEID_HUD_CHESTS, 1, game->_boss_reward_coin, _x, _y - 50, _x,  ROAD_POSY );
						//PLAY_SFX(SFX_CHEST_ACQUIRED);
					}
					else
					{
						game->_boss_reward.Active(SPRITEID_HUD_CHESTS_01, 0, game->_boss_reward_coin, _x, _y - 50, _x,  ROAD_POSY );
						//PLAY_SFX(SFX_CHEST_ACQUIRED);
					}
				}
			}
		}
        if (_y < _targety)
        {
            _y += 20;
            if (_y >= _targety)
            {
                _y = _targety;
            }
            SetPos(_x, _y);
        }
		return;
	}
	if (_be_stun_available)
	{
		return;
	}
	
	//printf("\n _state = %d,_count_frame_attack = %d,_effect_start_in._state = %d", _state,_count_frame_attack,_effect_start_in._state);
	switch (_target_focus)
	{
	case CHARACTER_TARGET_CASTLE:
		_targetx = ENEMY_TARGETX + game->_point_o.X;
		break;
	case CHARACTER_TARGET_STATUE:
		_targetx = k_SCREEN_WIDTH / 2 + 20;
		break;
	case CHARACTER_TARGET_HOME:
		break;
	default:
		break;
	}
	if (_y < ROAD_POSY - 50)
	{
		if (_status == CHARACTER_STATUS_NORMAL)
		{
			_status = CHARACTER_STATUS_FORCE_FLY;
		}
	}
	else
	{
		if (_status == CHARACTER_STATUS_FORCE_FLY)
		{
			_status = CHARACTER_STATUS_NORMAL;
		}
	}
	float dis = CMath::DISTANCE(_x, _y, _targetx, _targety);
	_is_ready = true;
	if (_num_hit_attacked >= 1)
	{
		if (_x + _speed >= _targetx)
		{
			SetState(CHARACTER_STATE_DIE);
			_coin = 0;
		}
		else
		{
			if (!_be_stun_available)
			{
				_x += _speed;
			}
			_anim.UpdateAnimObject();
			if (_anim.IsCurrentAnimStop())
			{
				SetState(CHARACTER_STATE_RUN);
				_anim.SetAnim(CHARACTER_ANIM_RUN + HERO_ANIM_NUM_MAX, false);
			}
		}
		SetPos(_x, _y);
		return;
	}
	if (_be_skill_id == BE_SKILL_BURN_BY_WEAPON || _be_skill_id == BE_SKILL_BURN_BY_HERO || _be_skill_id == BE_SKILL_TORNADO)
	{
		if (_anim.IsCurrentAnimStop())
		{
			_anim.SetAnim(_anim.GetCurrentAnim(), false);
		}
		return;
	}
	if (_y < _targety)
	{
		_y += 20;
		if (_y >= _targety)
		{
			_y = _targety;
		}
	}
    _count_frame_attack++;
	if (dis > _range)
	{
		float speed = _speed;
		if (_x >= game->_screen_width + game->_point_o.X*2 - 50)
		{
			speed = 5;
		}

		if (/*_state != CHARACTER_STATE_BEHIT &&*/ _x >= _targetx && !_be_stun_available)
		{
			_x -= speed;
		}
		SetPos(_x, _y);
		if (_anim.IsCurrentAnimStop())
		{
			if (_state == CHARACTER_STATE_RUN && speed == _speed)
			{
				SetState(CHARACTER_STATE_RUN);
			}
			else
			{
				SetState(CHARACTER_STATE_WALK);
			}
			ReActiveSkill();
		}
		//SetState(CHARACTER_STATE_WALK);
	}
	if (dis <= _range)
	{
        float angle = CMath::ANGLE(_x, _y, _targetx, _targety);
        if (_x < _targetx + _range*CMath::COS(angle))
		{
			_x = _targetx + _range*CMath::COS(angle);
		}
        SetPos(_x, _y);
		
		if (_state == CHARACTER_STATE_ATTACK)
		{
			if (_anim._current_aframes_time == 1)
			{
				if (CheckHitDamage(_anim._anim_sprite->_aframe_id[_anim._current_aframes]))
				{
					if (_target_focus == CHARACTER_TARGET_CASTLE)
					{
						game->AddEffectHPLost(_damage, ENEMY_TARGETX + game->_point_o.X - 30 + CMath::RANDOM(-3, 3) * 3, ENEMY_TARGETY - 120 + CMath::RANDOM(-5, 0) * 5, EFFECT_HP_LOST_TYPE_CASTLE);
						game->_castle.AddHp(-_damage);
                       if( game->_be_damage_opacity < 50)
                       {
                           game->_be_damage_opacity = 100;
                       }

					}
					else if (_target_focus == CHARACTER_TARGET_STATUE)
					{
						game->AddEffectHPLost(_damage, k_SCREEN_WIDTH / 2 + CMath::RANDOM(-3, 3) * 3, ENEMY_TARGETY - 120 + CMath::RANDOM(-5, 0) * 5, EFFECT_HP_LOST_TYPE_CASTLE);
						game->AddHPStatue(-_damage);
					}
				}
			}
		}
		if (_count_frame_attack >= _attack_speed)
		{
			if (_state == CHARACTER_STATE_ATTACK)
			{
				while (!_anim.IsCurrentAnimStop())
				{
					_anim.UpdateAnimObject();
					return;
				}
			}
			if (_spriteid == SPRITEID_MONSTER_THIEF_01 || _spriteid == SPRITEID_MONSTER_FLYING)
			{
				_num_hit_attacked++;
				if (_num_hit_attacked == 1)
				{
					_speed *= 2;
					_targetx = game->_screen_width + 100;
					_targety = _y;
					_target_focus = CHARACTER_TARGET_HOME;
					SetState(CHARACTER_STATE_RUN);
					_anim.SetAnim(CHARACTER_STATE_RUN + 8, false);
					if (_spriteid == SPRITEID_MONSTER_FLYING)
					{
						_speed *= 10;
						_status = CHARACTER_STATUS_RUNAWAY;
					}
					_count_frame_attack = 0;
					return;
				}
			}
			else
			{
				SetState(CHARACTER_STATE_ATTACK);
				_count_frame_attack = 0;
			}
		}
		else
		{
			if (_state == CHARACTER_STATE_WALK || _state == CHARACTER_STATE_RUN )
			{
				SetState(CHARACTER_STATE_IDLE);
			}
			if (_anim.IsCurrentAnimStop())
			{
				if (_state == CHARACTER_STATE_ATTACK)
				{
					if (_spriteid == SPRITEID_MONSTER_THIEF_01 || _spriteid == SPRITEID_MONSTER_FLYING)
					{
						if (_num_hit_attacked == 1)
						{
							_speed *= 2;
							_targetx = game->_screen_width + 100;
							_targety = _y;
							_target_focus = CHARACTER_TARGET_HOME;
							SetState(CHARACTER_STATE_RUN);
							_anim.SetAnim(CHARACTER_STATE_RUN + 8, false);
							if (_spriteid == SPRITEID_MONSTER_FLYING)
							{
								_speed *= 10;
								_status = CHARACTER_STATUS_RUNAWAY;
							}
							return;
						}
					}
				}
				SetState(CHARACTER_STATE_IDLE);
			}
		}
	}
}
void CCharacter::AddHP(INT_TIME hp, int animeffect, int sprite, bool weapon)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (hp > 0)
	{
		printf("\n bug damage");
        return;
	}
	if (_hp <= 0)
	{
		//if(_state < CHARACTER_STATE_DIE)
		if (IsLive())
		{
			SetState(CHARACTER_STATE_DIE_START);
		}
		_hp = 0;
		return;
	}
	if (hp < 0 )
	{
		_heathbar_count_frame_render = 120;
        _effect_behit_count_render = 0;
		_anim_effect_behit.SetAnimSprite(GET_SPRITE(sprite), sprite);
		_anim_effect_behit.SetAnim(animeffect, false);
		_anim_effect_behit.SetPos(_x, _y - 30);
		//if (_be_skill_id != BE_SKILL_BURN_BY_WEAPON )
		{
			//if (_state < CHARACTER_STATE_DIE &&  _state != CHARACTER_STATE_ATTACK && _state != CHARACTER_STATE_RUN && _state != CHARACTER_STATE_BE_STUN)
			if (IsLive() &&  _state != CHARACTER_STATE_ATTACK && _state != CHARACTER_STATE_RUN && _state != CHARACTER_STATE_BE_STUN)
			{
				if (_state == CHARACTER_STATE_WALK)
				{
					int random = CMath::RANDOM(1, 100);
					if (_size < CHARACTER_TYPE_SIZE_BIG)
					{
						SetState(CHARACTER_STATE_BEHIT);
					}
					else if (random % 25 == 0)
					{
						SetState(CHARACTER_STATE_BEHIT);
					}
				}
				else if (_state == CHARACTER_STATE_IDLE)
				{
					SetState(CHARACTER_STATE_BEHIT);
				}
			}
		}
		
		//if (_state < CHARACTER_STATE_DIE)
		if (IsLive())
		{
			_effect_frame_behit = CMath::RANDOM(0, 3);
		}
		if (game->_count_frame_playsound_ore_damaged <= 0)
		{
			game->_count_frame_playsound_ore_damaged = 8;
			GAME()->PlaySFX(SFX_ORC_DAMAGED);
		}
	}
	_hp += hp;
	if (_hp <= 0)
	{
		//if (_state < CHARACTER_STATE_DIE)
		if (_state < CHARACTER_STATE_DIE_START)
		{
			if (_spriteid == SPRITEID_MONSTER_FLYING)
			{
				SetState(CHARACTER_STATE_DIE);
			}
			else
			{
				SetState(CHARACTER_STATE_DIE_START);
			}
			
			if (weapon)
			{
				game->_user._quest_num_enemy_bekill_weapon++;
			}
            
        
			if (game->_time_kill_monster_in_second <= 0)
			{
				game->_time_kill_monster_in_second = 60;
				game->_num_kill_monster_in_second = 0;
			}
			else
			{
				game->_num_kill_monster_in_second++;
			}
		}
	}
}
void CCharacter::SetSpeed(int speed)
{
	_speed = speed;
}
INT_TIME CCharacter::GetDamage()
{
	return _damage;
}
INT_TIME CCharacter::GetHP()
{
	return _hp;
}
int CCharacter::GetCoin()
{
	return _coin;
}
int CCharacter::GetTypeAttack()
{
	return _type_attack;
}
float CCharacter::GetPosX()
{
	return _x;
}
float CCharacter::GetPosY()
{
	return _y;
}
void CCharacter::SetPos(float x, float y)
{
	_x = x;
	_y = y;
	_anim.SetPos(_x, _y);
}
void CCharacter::SetState(int state)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_hp <= 0 && state != CHARACTER_STATE_DIE && state != CHARACTER_STATE_DIE_START)
	{
		return;
	}
	_state = state;
	switch (_state)
	{
	case CHARACTER_STATE_IDLE:
		if (_status != CHARACTER_STATUS_FLY)
		{
			_anim.SetAnim(CHARACTER_ANIM_IDLE, false);
		}
		else
		{
			_anim.SetAnim(CHARACTER_ANIM_SKILL2, false);
		}
		
		break;
	case CHARACTER_STATE_WALK:
		if (_status != CHARACTER_STATUS_FLY)
		{
			_anim.SetAnim(CHARACTER_ANIM_WALK, false);
		}
		else
		{
			_anim.SetAnim(CHARACTER_ANIM_SKILL2, false);
		}
		break;
	case CHARACTER_STATE_BEHIT:
		if (_status != CHARACTER_STATUS_FLY)
		{
			//_anim.SetAnim(CHARACTER_ANIM_BEHIT, false);
		}
		break;
	case CHARACTER_STATE_BE_STUN:
		_anim.SetAnim(CHARACTER_ANIM_BE_STUNE, true);
		break;
	case CHARACTER_STATE_ATTACK:
		_anim.SetAnim(CHARACTER_ANIM_ATTACK, false);
		if (_status == CHARACTER_STATUS_FLY || _status == CHARACTER_STATUS_FORCE_FLY)
		{
			_anim.SetAnim(11, false);
		}
		break;
	case CHARACTER_STATE_DIE:
	{
		_hp = 0;
		if (_status != CHARACTER_STATUS_CARRY_FLY && _status != CHARACTER_STATUS_FLY)
		{
			_anim.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DIE), SPRITEID_EFFECT_DIE);
			_anim.SetAnim(0, false);
			_anim.SetPos(_x, _y);
		}
		else
		{
			_anim.SetAnim(CHARACTER_ANIM_DIE, false);
		}
		_effect_behit_count_render = 30;
		
	}
		break;
	case CHARACTER_STATE_RUN:
		if (_status != CHARACTER_STATUS_FLY)
		{
			_anim.SetAnim(CHARACTER_ANIM_RUN, false);
		}
		else
		{
			_anim.SetAnim(CHARACTER_ANIM_SKILL2, false);
		}
		
		break;
	case CHARACTER_STATE_DIE_START:
		_hp = 0;
		if (_size >= CHARACTER_TYPE_SIZE_BIG)
		{
			//PLAY_SFX(SFX_BOSS_DIE);
			GAME()->PlaySFX(SFX_BOSS_DIE);
			game->_user._quest_num_kill_boss++;
		}
		else
		{
			//int sound = CMath::RANDOM(SFX_ORC_DIE_1, SFX_ORC_DIE_2);
			if (game->_count_frame_playsound_orc_die <= 0)
			{
				game->_count_frame_playsound_orc_die = 5;
				GAME()->PlaySFX(SFX_ORC_DIE);
			}
            //CGame::_this->PlaySFX(CMath::RANDOM(SFX_ORC_DIE_1, SFX_ORC_DIE_2));
			game->_user._quest_num_kill_monster++;
			if (!game->_user._daily_quest_completed)
			{
				game->DailyQuestAdd(DAILY_QUEST_GROUP_KILL_MONSTER);
			}
		}
		if (_coin > 0)
		{
            int mul = 1;
            if (game->_user._iap_starter_double_coin_time > 0)
            {
                mul += 1;
            }
            if (game->_user._has_double_coin)
            {
                //printf("\n x2 coin _coin = %d",_coin);
                mul += 1;
            }
            if (game->_has_double_coin_timer > 0)
            {
                mul += 1;
            }
            _coin = _coin*mul;
			int mky = GET_SPRITE(_spriteid)->GetFModuleY(0, 0);
			int coinadd = _coin;
			int coin_min = game->_items_coin_min;
            if(_num_coin_collect <= 0)
            {
                _num_coin_collect = 1;
            }
            if(_num_coin_collect > 3)
            {
                _num_coin_collect = 3;
            }
            _num_coin_collect *= mul;
            
			if (_num_coin_collect > 0)
			{
				coin_min = _coin / _num_coin_collect;
                if(coin_min <= 0 && _coin >0)
                {
                    coin_min = 1;
                }
			}
            //printf("\ncoinadd = %d mul = %d",coinadd,mul);
			while (coinadd > coin_min && coin_min > 0)
			{
				game->ItemsAddNew(ITEMS_TYPE_COIN, _x + CMath::RANDOM(-3, 3) * 5, _y + mky, _x, ROAD_POSY + CMath::RANDOM(-1, 5) * 3, coin_min);
				coinadd -= coin_min;
			}
			if (coinadd > 0)
			{
				game->ItemsAddNew(ITEMS_TYPE_COIN, _x + CMath::RANDOM(-3, 3) * 5, _y + mky, _x, ROAD_POSY + CMath::RANDOM(-1, 5) * 3, coinadd);
			}
		}
		_anim.SetAnim(CHARACTER_ANIM_DIE, false);
		break;
	default:
		break;
	}
}
int CCharacter::GetState()
{
	return _state;
}

int CCharacter::GetSpeed()
{
	return _speed;
}

int CCharacter::GetSprite()
{
	return _spriteid;
}

bool CCharacter::IsReady()
{
	return _is_ready;
}
void CCharacter::RenderHealthBar(float x, float y)
{

	if ((_hp <= 0 && _state == CHARACTER_STATE_DIE))
	{
		return;
	}
	int clipx = _x - GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(55) / 2;
	int clipy = _y + GET_SPRITE(_spriteid)->GetFModuleY(0, 0);
	if (_size >= CHARACTER_TYPE_SIZE_BIG_REWARD)
	{
		GET_SPRITE(SPRITEID_EFFECT_CROWN_01)->DrawFrame(G(), 0, _x + x, clipy + y - 25);
	}
	if (_hp >= _hp_max || (_heathbar_count_frame_render <= 0 && _heathbar_opac <= 0))
	{
		return;
	}
	if (_heathbar_count_frame_render > 0)
	{
		_heathbar_count_frame_render--;
		if (_heathbar_opac < 100)
		{
			_heathbar_opac += 10;
			if (_heathbar_opac >= 100)
			{
				_heathbar_opac = 100;
			}
		}
	}
	else
	{
		if (_heathbar_opac > 0)
		{
			_heathbar_opac += -5;
			if (_heathbar_opac <= 0)
			{
				_heathbar_opac = 0;
			}
		}
	}
	int mainopac = G()->GetCurrentOpacity();
	G()->SetOpacity(mainopac*0.01f*_heathbar_opac);
	
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
	
	G()->SetOpacity(mainopac);
}

void CCharacter::RenderEffectBehit()
{
	if (_state == CHARACTER_STATE_DIE_END)
	{
		return;
	}
	if (_effect_behit_count_render < 30)
	{
		//G()->SetScale(0.5f, 0.5f, _x, _y - 30);
		_anim_effect_behit.DrawAnimObject(G());
		//G()->ClearScale();
		/*_effect_behit_count_render++;
		GET_SPRITE(SPRITEID_EFFECT_HIT)->DrawFrame(G(), _effect_frame_behit, _x, _y - 30);*/
	}
}
const char* CCharacter::GetID()
{
	return _id;
}
int CCharacter::GetSkillID()
{
	return _skill;
}
void CCharacter::UpdateSkill()
{
	if (_skill == CHARACTER_SKILL_NONE || _skill_active)
	{
		return;
	}
	
	TDGame *game = (TDGame*)GAME()->_current_game;
	
	int param_ability = CGameDesign::FileEnemy_Creation::CSheetSkill::Ability;
	int param_hp = CGameDesign::FileEnemy_Creation::CSheetSkill::HP;
	int ability = game->GetDesignEnemySkillGeneral(_skill - 1, param_ability);
	int hp = game->GetDesignEnemySkillGeneral(_skill - 1, param_hp);
	switch (_skill)
	{
	case CHARACTER_SKILL_PUSH_SPEED:
		if (_hp <= hp*_hp_max / 100.0f)
		{
			SetState(CHARACTER_STATE_RUN);
			SetSpeed(ability);
			_skill_active = true;
#if !defined (ANDROID_OS)
			//GAME()->PlaySFX(SFX_CENTUAR_PUSH);
#endif
		}
		break;
	case CHARACTER_SKILL_LAY_EGGS:
	case CHARACTER_SKILL_LAY_EGGS2:
		//printf("\n 000 _skill=  %d,id = %s,_num_enemy_inwave = %d", _skill, _id, game->_num_enemy_inwave);
		if (_state == CHARACTER_STATE_DIE_START)
		{
			if (_anim._current_aframes - GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim.GetCurrentAnim()) == 20)
			{
				int numenemy = game->_num_enemy_inwave;
				INT_TIME damage_decrease = _damage / 5;
				INT_TIME hp_decrease = _hp_max / ability;
				float tarx = ENEMY_TARGETX + game->_point_o.X;
				float tary = ENEMY_TARGETY;
				char id[10];
				int skill = 0;
				int posx = _x;
				int posy = _y;
				if (strcmp(_id, "SP4") == 0)
				{
					posx += 20;
					posy -= 50;
					sprintf(id, "SP3");
				}
				else if (strcmp(_id, "SP3") == 0)
				{
					posx += 15;
					posy -= 35;
					sprintf(id, "SP2");
				}
				/*else if (strcmp(_id, "SP2") == 0)
				{
					posx += 10;
					posy -= 20;
					sprintf(id, "SP1");
				}*/
				int index_enemy = game->GetEnemyCreationIndex(id);
				int param_skill = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Skill;
				if (index_enemy >= 0)
				{
					skill = game->GetDesignEnemyCreationGeneral(index_enemy, param_skill);
				}
				for (int i = 0; i < ability; i++)
				{
					int x = CMath::RANDOM(-5, 5) * 5 + _x;
					int y = CMath::RANDOM(-5, 5) * 3 + _y;
					game->_enemy[numenemy + i].Init(id, x, y, tarx, tary, hp_decrease, damage_decrease, 0, 0, skill, 0);
					game->_enemy[numenemy + i]._effect_start_in.Active(posx, posy, _x + CMath::RANDOM(-5, 5) * 5, ROAD_POSY);
					game->_num_enemy_inwave++;
				}
				if (game->_count_frame_playsound_spide_born <= 0)
				{
					game->_count_frame_playsound_spide_born = 5;
					GAME()->PlaySFX(SFX_SPIDER_SPAWN);
				}
				_skill_active = true;
			}
		}
		break;
	case CHARACTER_SKILL_ROB:
		//if (_state < CHARACTER_STATE_DIE)
		if (IsLive())
		{
			for (int i = 0; i < game->_num_item_collected; i++)
			{
				if (game->_arr_item[i]._state == ITEMS_DROP)
				{
					if (CHECK_POINT_IN_CIRCLE(_x, _y, game->_arr_item[i]._x, game->_arr_item[i]._y, ability))
					{
						game->_arr_item[i]._state = ITEMS_FLY_ROBED;
						game->_arr_item[i]._targetx = _x;
						game->_arr_item[i]._targety = _y - 50;
						_coin += game->_arr_item[i]._value;
						if (_num_coin_collect == 0)
						{
							GAME()->PlaySFX(SFX_GLOBLIN_LOOTED);
						}
						_num_coin_collect++;
					}
				}
				if (game->_arr_item[i]._state == ITEMS_FLY_ROBED)
				{
					game->_arr_item[i]._targetx = _x + 17;
					game->_arr_item[i]._targety = _y - 35;
				}
			}
		}
		break;
	case CHARACTER_SKILL_BOOM:
	{
								 float dis = CMath::DISTANCE(_x, _y, _targetx, _targety);
								 //if (dis < _range && _state < CHARACTER_STATE_DIE)
								 if (dis < _range && IsLive())
								 {
									 SetState(CHARACTER_STATE_DIE_START);
									 _anim.SetAnim(CHARACTER_ANIM_SKILL1, false);
									 GAME()->PlaySFX(SFX_BOMB_SUICIDE);
								 }
								 if (_state == CHARACTER_STATE_DIE_START)
								 {
									 if (_anim._current_aframes_time == 1)
									 {
										 if (CheckHitDamage(_anim._anim_sprite->_aframe_id[_anim._current_aframes]))
										 {
											 if (_target_focus == CHARACTER_TARGET_CASTLE)
											 {
												 game->AddEffectHPLost(_damage, ENEMY_TARGETX + game->_point_o.X - 30 + CMath::RANDOM(-3, 3) * 3, ENEMY_TARGETY - 120 + CMath::RANDOM(-5, 0) * 5, EFFECT_HP_LOST_TYPE_CASTLE);
												 
												 game->_castle.AddHp(-_damage);

											 }
											 else if (_target_focus == CHARACTER_TARGET_STATUE)
											 {
												 game->AddEffectHPLost(_damage, k_SCREEN_WIDTH / 2 + CMath::RANDOM(-3, 3) * 3, ENEMY_TARGETY - 120 + CMath::RANDOM(-5, 0) * 5, EFFECT_HP_LOST_TYPE_CASTLE);
												 game->AddHPStatue(-_damage);
											 }
											 
											 _skill_active = true;
										 }
									 }
								 }
	}

		break;
	case CHARACTER_SKILL_TOFLY:
	{
		if (_hp <= hp*_hp_max / 100.0f )
		{
			if (_status == CHARACTER_STATUS_NORMAL)
			{
				_anim.SetAnim(CHARACTER_ANIM_SKILL1, true);
				GAME()->PlaySFX(SFX_GAGO_FLY);
			}
			
			if (_anim.GetCurrentAnim() == CHARACTER_ANIM_SKILL1 || _y > WEAPON_ACHER_POSY + 50)
			{
				if (_anim._current_aframes - GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim.GetCurrentAnim()) >= 5)
				{
					_y -= 5;
					_targety -= 5;
					_count_frame_attack = 0;
				}
				
				if (_y < WEAPON_ACHER_POSY + 50)
				{
					_count_frame_attack = _attack_speed;
					SetState(CHARACTER_STATE_IDLE);
					_anim.SetAnim(CHARACTER_ANIM_SKILL2, false);
					_skill_active = true;
				}
				else
				{
					if (_anim.IsCurrentAnimStop())
					{
						_anim.SetAnim(CHARACTER_ANIM_SKILL1, true);
					}
				}
			}
			_status = CHARACTER_STATUS_FLY;
		}
		
	}
		break;
	default:
		break;
	}
}
void CCharacter::ReActiveSkill()
{
	switch (_skill)
	{
	case CHARACTER_SKILL_PUSH_SPEED:
		if (_skill_active)
		{
			SetState(CHARACTER_STATE_RUN);
		}
		break;
	default:
		break;
	}
}


bool CCharacter::CheckHitDamage(int frame_id)
{
	bool ret = false;
	int num_frame = _anim_marker.getMaxAframe();
	for (int i = 0; i < num_frame; i++)
	{
		//printf("\n frameid = %d - frame_id = %d", _anim_marker._anim_sprite->_aframe_id[_anim_marker._current_aframes + i], frame_id);
		if (_anim_marker._anim_sprite->_aframe_id[_anim_marker._current_aframes + i] == frame_id)
		{
			ret = true;
		}
	}
	return ret;
}

void CCharacter::EffectInit::Init(int type)
{
	_x = _y = 0;
	_targetx = _targety = 0;
	_alphax = 0;
	_alphay = 0;
	_state = EFFECT_STARTIN_STATE_NONE;
	_speed = 0;
	_delta = 0;
	_speedy = 0;
	_type = type;
	_alpha_knock = 0;
	_count_frame_hold = 0;
}
void CCharacter::EffectInit::Active(float x, float y, float tarx, float tary)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_x = x;
	_y = y;
	_alphax = CMath::RANDOM(77, 103);
	_alphay = CMath::RANDOM(330, 340);
	_speed = CMath::RANDOM(20, 30);
	_delta = 0;
	_targetx = CMath::RANDOM(tarx + 10, tarx + 50);
	if (_targetx <= ENEMY_TARGETX + 200 + game->_point_o.X)
	{
		_alphax = CMath::RANDOM(77, 90);
	}
	_targety = CMath::RANDOM(tary, tary + CMath::RANDOM(0, 3) * 5);
	_alpha_knock = 30;
	_count_frame_hold = 0;
	_state = EFFECT_STARTIN_STATE_START;
}
void CCharacter::EffectInit::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_state == EFFECT_STARTIN_STATE_NONE)
	{
		return;
	}
	if (_alphax < 85)
	{
		_alphax += 1;
	}
	else if (_alphax > 100)
	{
		_alphax -= 1;
	}
	_alphay += 2;
	if (_alphay >= 360)
	{
		_alphay = 0;
	}
	if (_alphay == 0)
	{
		_delta += 2;
	}
	_y += _speed*CMath::SIN(_alphay + _delta / 4);
	if (_y >= _targety - _speed || _count_frame_hold > 0)
	{
		if (_count_frame_hold < 5)
		{
			_alpha_knock -= 8;
		}
		else
		{
			_alpha_knock += 8;
			if (_alpha_knock >= 20)
			{
				_alpha_knock = 20;
			}
		}
		_count_frame_hold++;
		_y = _targety + _speed*CMath::SIN(_alpha_knock);
		if (_count_frame_hold >= 20)
		{
			_state = EFFECT_STARTIN_STATE_NONE;
            _y = _targety;
		}
	}
	else
	{
		_x += _speed*CMath::COS(_alphax);
	}
}

void CCharacter::BeSkillActive(int skill, int timeslow)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_be_skill_id == BE_SKILL_BURN_BY_HERO || _be_skill_id == BE_SKILL_BURN_BY_WEAPON)
	{
		if (skill != BE_SKILL_BURN_BY_HERO)
		{
			return;
		}
	}
	if (_be_skill_id == BE_SKILL_TORNADO)
	{
		if (skill == BE_SKILL_TORNADO)
		{
			if (_speed_fly < 0)
			{
				_speed_fly = 0;
			}
			_fly_up = true;
			_be_skill_time = 10;
			return;
		}
	}
	_be_skill_id = skill;
	switch (_be_skill_id)
	{
	case BE_SKILL_NONE:
		break;
	case BE_SKILL_SLOW:
		if (timeslow == 0)
		{
			_be_skill_time = game->GetDesignGeneralInfo(DESIGN_GENERAL_SLOW_TIME);
		}
		else
		{
			_be_skill_time = timeslow;
		}
		
		_be_skill_value = 30;
		/*_effect_be_skill.SetAnimSprite(GET_SPRITE(SPRITEID_CASTLE_LV5_01), SPRITEID_CASTLE_LV5_01);
		_effect_be_skill.SetAnim(17, true);
		_effect_be_skill.SetPos(0, 0);*/
		break;
	case BE_SKILL_BURN_BY_WEAPON:
		_effect_rotate = 0;
		_speed_rotate = CMath::RANDOM(-3, 3);
		_speed_fly = CMath::RANDOM(10, 16);
		_fly_up = true;
		_be_skill_time = 10;
		break;
	case BE_SKILL_BURN_BY_HERO:
		/*_effect_rotate = 0;
		_speed_rotate = CMath::RANDOM(-5, 5);
		_speed_fly = CMath::RANDOM(7, 30);
		_fly_up = true;
		_be_skill_time = 10;*/
		_effect_rotate = 0;
		SetPos(GetPosX() + 25, GetPosY());
		_beskill_beatmaster_time = 10;
		break;
	case BE_SKILL_STUN:
		//_be_skill_time = game->GetDesignGeneralInfo(DESIGN_GENERAL_SLOW_TIME);
		break;
	case BE_SKILL_TORNADO:
		_effect_rotate = 0;
		_speed_fly = 10;
		_fly_up = true;
		_be_skill_time = 15;
		break;
	default:
		break;
	}
}

void CCharacter::BeSkillUpdate()
{
	if (_be_skill_time <= 0)
	{
		_be_skill_id = BE_SKILL_NONE;
		return;
	}
	//if (_state >= CHARACTER_STATE_DIE)
	if(!IsLive())
	{
		return;
	}
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_speed = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Move_Speed;
	float speed_normal = game->GetDesignEnemyCreationGeneralFLoat(_creation_index, param_speed);
	switch (_be_skill_id)
	{
	case BE_SKILL_NONE:
		break;
	case BE_SKILL_SLOW:
		if (_state == CHARACTER_STATE_RUN && _skill == CHARACTER_SKILL_PUSH_SPEED)
		{
			TDGame *game = (TDGame*)GAME()->_current_game;
			int param_ability = CGameDesign::FileEnemy_Creation::CSheetSkill::Ability;
			int param_hp = CGameDesign::FileEnemy_Creation::CSheetSkill::HP;
			int ability = game->GetDesignEnemySkillGeneral(_skill - 1, param_ability);
			speed_normal = ability;
		}
		if (_spriteid != SPRITEID_MONSTER_FLYING)
		{
			_speed = speed_normal*_be_skill_value / 100.0f;
		}
		else
		{
			if (_status != CHARACTER_STATUS_RUNAWAY)
			{
				_speed = speed_normal*_be_skill_value / 100.0f;
			}
		}
		
		_be_skill_time--;
		if (_be_skill_time <= 0)
		{
			_speed = speed_normal;
		}
		break;
	case BE_SKILL_BURN_BY_WEAPON:
		if (_anim.IsCurrentAnimStop() || _state != CHARACTER_STATE_IDLE )
		{
			//if (_state < CHARACTER_STATE_DIE)
			if(IsLive())
			{
				SetState(CHARACTER_STATE_IDLE);
				_anim.SetAnim(10, false);
			}
		}
		if (!_fly_up)
		{
			if (_y > _targety - _speed_fly / 3)
			{
				_be_skill_id = BE_SKILL_NONE;
				_y = _targety;
				_effect_rotate = 0;
				SetState(CHARACTER_STATE_WALK);
				_be_skill_time = 0;
			}
			else
			{
				_y += _speed_fly/2;
				_effect_rotate -= _speed_rotate/2;
				_speed_fly += 0.6f;
			}
		}
		else
		{
			_y -= _speed_fly;
			
			_speed_fly -= 0.4f;
			if (_speed_fly <= 0)
			{
				_fly_up = false;
			}
			_effect_rotate += _speed_rotate;
			if (CMath::ABSOLUTE_VALUE( _effect_rotate) >= 360)
			{
				_effect_rotate += 360;
			}
		}
		break;
	case BE_SKILL_BURN_BY_HERO:
		if (_be_skill_time > 0)
		{
			_be_skill_time--;
		}
		/*if (_anim.IsCurrentAnimStop() || _state != CHARACTER_STATE_IDLE)
		{
			//if (_state < CHARACTER_STATE_DIE)
			if (IsLive())
			{
				SetState(CHARACTER_STATE_IDLE);
				_anim.SetAnim(10, false);
			}
		}
		if (!_fly_up)
		{
			if (_y > _targety - _speed_fly / 3)
			{
				_be_skill_id = BE_SKILL_NONE;
				_y = _targety;
				_effect_rotate = 0;
				SetState(CHARACTER_STATE_WALK);
				_be_skill_time = 0;
			}
			else
			{
				_y += _speed_fly / 2;
				_effect_rotate -= _speed_rotate / 2;
				_speed_fly += 0.6f;
			}
		}
		else
		{
			_y -= _speed_fly;
			_speed_fly -= 1.2f;
			if (_speed_fly <= 0)
			{
				_fly_up = false;
			}
			_effect_rotate += _speed_rotate;
			if (CMath::ABSOLUTE_VALUE(_effect_rotate) >= 360)
			{
				_effect_rotate += 360;
			}
		}*/
		break;
	case BE_SKILL_STUN:

		break;
	case BE_SKILL_TORNADO:
		if (_anim.IsCurrentAnimStop() || _state != CHARACTER_STATE_IDLE)
		{
			//if (_state < CHARACTER_STATE_DIE)
			if (IsLive())
			{
				SetState(CHARACTER_STATE_IDLE);
				_anim.SetAnim(10, false);
			}
		}
		if (!_fly_up)
		{
			if (_y >= ROAD_POSY )
			{
				_be_skill_id = BE_SKILL_NONE;
				_y = ROAD_POSY + CMath::RANDOM(0, 6) * 3 + game->_point_o.Y;
				_targety = _y;
				_effect_rotate = 0;
				SetState(CHARACTER_STATE_WALK);
				_be_skill_time = 0;
				_status = CHARACTER_STATUS_NORMAL;
			}
			else
			{
				_y += ( 5 - _speed_fly) ;
				_speed_fly -= 0.6f;
				if (_speed_fly <= -5)
				{
					_speed_fly = -5;
				}
			}
		}
		else
		{
			_y -= _speed_fly;
			
			_speed_fly -= 0.3f;
			if (_speed_fly <= 0)
			{
				_speed_fly = 0;
				_be_skill_time--;
			}
			if (_be_skill_time <= 0)
			{
				_speed_fly = 0;
				_fly_up = false;
			}
			if (_y < ROAD_POSY - 160)
			{
				_y = ROAD_POSY - 130;
				//_speed_fly = 3.0f;
			}
		}
		break;
	default:
		break;
	}
}

void CCharacter::BeSkillRender(float x, float y)
{
	int posx = _x;
	int posy = _y + GET_SPRITE(_spriteid)->GetFModuleY(0, 0) + 15;
	if (_be_skill_time <= 0)
	{
		_be_skill_id = BE_SKILL_NONE;
		return;
	}
	switch (_be_skill_id)
	{
	case BE_SKILL_NONE:
		break;
	case BE_SKILL_SLOW:
		/*_effect_be_skill.SetPos(posx + x, posy + y);
		_effect_be_skill.DrawAnimObject(G());
		_effect_be_skill.UpdateAnimObject();*/
		break;
	default:
		break;
	}
}

void CCharacter::BeStunActive(int timestun)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_be_stun_available = true;
	if (timestun == 0)
	{
		_be_stun_time = game->GetDesignGeneralInfo(DESIGN_GENERAL_SLOW_TIME);
	}
	else
	{
		_be_stun_time = timestun;
	}
	
	_effect_be_skill.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_STUN_01), SPRITEID_EFFECT_STUN_01);
	_effect_be_skill.SetAnim(0, true);
	_effect_be_skill.SetPos(0, 0);
	if (_hp > 0)
	{
		SetState(CHARACTER_STATE_BE_STUN);
	}
}
void CCharacter::BeStunUpdate()
{
	if (!_be_stun_available)
	{
		return;
	}
	_be_stun_time--;
	if (_be_stun_time <= 0)
	{
		_be_stun_available = false;
		if (_hp > 0)
		{
			SetState(CHARACTER_STATE_IDLE);
		}
		
	}
}
void CCharacter::BeStunRender(float x, float y)
{
	if (!_be_stun_available)
	{
		return;
	}
	int posx = _x;
	int posy = _y + GET_SPRITE(_spriteid)->GetFModuleY(0, 0) + 30;
	_effect_be_skill.SetPos(posx + x, posy + y);
	_effect_be_skill.DrawAnimObject(G());
	_effect_be_skill.UpdateAnimObject();
}
void CCharacter::GetRelicsBonus(bool init, int id)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (init)
	{
		_damage -= (INT_TIME)(_damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
		_speed -= (int)(_speed*(game->GetRelicsMoveSpeed(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
		_coin += (int)(_coin*(game->GetRelicsCostDecrease(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
		_hp -= (int)(_hp*(game->GetRelicsHP(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
	}
	else
	{
		switch (id)
		{
		case 4://damage
			_damage -= (INT_TIME)(_damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
			break;
		case 2://speed move
			_speed -= (int)(_speed*(game->GetRelicsMoveSpeed(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
			break;
		case 1://cost increase
			_coin += (int)(_coin*(game->GetRelicsCostDecrease(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
			break;
		case 3:// hp
			_hp -= (int)(_hp*(game->GetRelicsHP(ITEMRELIC_GROUP_ENEMY, 0)) / 100.0f);
			break;
		default:
			break;
		}
	}
	
}
bool CCharacter::IsLive()
{
	return (_state < CHARACTER_STATE_DIE_START);
}

bool CCharacter::HasAvailable()
{
	return _count_frame_repawn >= _time_repawn;
}

int CCharacter::GetTimeRespawn()
{
	return _time_repawn;
}