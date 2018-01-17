#include "pch.h"
#include "../../GameCore/CGame.h"

CHero::CHero()
{
}

CHero::~CHero()
{
}

void CHero::Init(int id, int level, bool deployed, bool lock, bool haspromo)
{
	_damage_extra = 0;
	_count_frame_playsound = 0;
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_speed = CGameDesign::FileHero_design::CSheetHero_General::Speed_Move;
	int param_speedatt = CGameDesign::FileHero_design::CSheetHero_General::Speed_Attack;
	int param_type_range = CGameDesign::FileHero_design::CSheetHero_General::Range;
	int param_limit = CGameDesign::FileHero_design::CSheetHero_General::Limit_Break;
	int param_critical = CGameDesign::FileHero_design::CSheetHero_General::Critical;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	int param_skill = CGameDesign::FileHero_design::CSheetHero_General::Skill;
	int param_id = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
	int param_level_unlock = CGameDesign::FileHero_design::CSheetHero_General::Unlock;
	int param_cost_unlock = CGameDesign::FileHero_design::CSheetHero_General::Price_Unlock;
    int param_stars = CGameDesign::FileHero_design::CSheetHero_General::Rarity;
	
	_id = id;
	_level = level;
	_is_lock = lock;
	_level_max = false;
	_has_promo = haspromo;
	if (_level >= game->_game_design.Hero_design.SheetArcher.int32Value._totalData)
	{
		_level = game->_game_design.Hero_design.SheetArcher.int32Value._totalData;
		_level_max = true;
	}
	int heroindex = game->GetDesignHeroIndex(_id);
	sprintf(_name, "%s", game->GetDesignHeroName(heroindex));
	_cost_unlock = game->GetDesignHeroGeneral(heroindex, param_cost_unlock);
	_level_unlock = game->GetDesignHeroGeneral(heroindex, param_level_unlock);
	_speed = game->GetDesignHeroGeneralFloat(heroindex, param_speed);
	_speed_attack = game->GetDesignHeroGeneral(heroindex, param_speedatt);
	_type_range = game->GetDesignHeroGeneral(heroindex, param_type_range);
	_limit_break = game->GetDesignHeroGeneral(heroindex, param_limit);
	_critical = game->GetDesignHeroGeneralFloat(heroindex, param_critical);
    _stars = game->GetDesignHeroGeneral(heroindex, param_stars);
	_rar_level = 0;
	_deployed = deployed;
	UpdateRarity();
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	if (_level_max)
	{
		/*_cost_upgrade = GetCostUpgradeEndless(_level + 1);
		_damage = GetDamageEndless(_level);*/
	}
	else
	{
		_cost_upgrade = game->GetDesignHeroInfo(_id, _level + 1, param_costupgrade,GetNumStars());
		_damage = game->GetDesignHeroInfo(_id, _level, param_damage, GetNumStars());
	}
	_had_unlock = true;
	_spriteid = game->_hero_sprite[_id - 1];
	//game->LoadSpriteOptimize(_spriteid);
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	if (_type_range == HERO_TYPE_RANGE_MELEE)
	{
		_range = HERO_RANGE_DIS_MELEE;
		SetPos(CMath::RANDOM(2, 8) * 5 + 150 + game->_point_o.X, ROAD_POSY + CMath::RANDOM(0, 2) * 5);
		
	}
	else
	{
		_range = game->_screen_width;
		SetPos(40 + 100 + game->_point_o.X, ROAD_POSY + 15);
		
	}
	_count_frame_attack = 0;
	_count_frame_refill = 0;
	SetTarget(_x, _y);
    _oritation = HERO_ORITATION_RIGHT;
	SetState(HERO_STATE_IDLE);
	_power_attack = 0;
	_is_auto_attack = false;
	_power_skill = 0;
    _index_enemy_target = -1;
	InitAttackFrame();
	_skill_id = game->GetDesignHeroGeneral(heroindex, param_skill) - 1;
	if (_skill_id != HERO_SKILL_NONE)
	{
		float posy = _y;
		if (_skill_id == HERO_SKILL_ELECTRIC_BALL)
		{
			posy -= 100;
		}
		_skill.Init(_skill_id, _x, posy, GetDamageBasic());
	}
	_is_play_skill = false;
	
	_range_damage_aoe = 0;
	_skill_duration = 0;
	_is_lock = lock;
	_is_new = false;
	if (!_is_lock)
	{
		game->_user.AddNewHeroes(_id, _level, deployed,_rar_level);
		_is_new = true;
	}
	
	_anim_marker.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_marker.SetAnim(16, false);
	_anim_marker.SetPos(0, 0);
	_power_attack_max = MAX_POWER_NUM_TAP;
	GetRelicsBonus();
	if (_id == HERO_ID_WOLF_RANGER)
	{
		_pet_bird.Init(SPRITEID_EFFECT_SKILL_WOLFGIRL_02, PET_ID_BIRD, 200, 200, GetTotalDamage());
	}
	_power_att_catch = _power_attack;
	_power_skill_catch = _power_skill;
	_is_use_auto_att = false;
	_is_use_auto_skill = false;
	_count_frame_mass_auto_att = 0;
	_auto_being_active = false;
}
void CHero::Modify(int id, int level, bool deployed, bool lock, int poweratt, int powerskill, int rarlv, bool haspromo)
{
	_damage_extra = 0;
	_count_frame_playsound = 0;
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_speed = CGameDesign::FileHero_design::CSheetHero_General::Speed_Move;
	int param_speedatt = CGameDesign::FileHero_design::CSheetHero_General::Speed_Attack;
	int param_type_range = CGameDesign::FileHero_design::CSheetHero_General::Range;
	int param_limit = CGameDesign::FileHero_design::CSheetHero_General::Limit_Break;
	int param_critical = CGameDesign::FileHero_design::CSheetHero_General::Critical;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	int param_skill = CGameDesign::FileHero_design::CSheetHero_General::Skill;
	int param_level_unlock = CGameDesign::FileHero_design::CSheetHero_General::Unlock;
	int param_cost_unlock = CGameDesign::FileHero_design::CSheetHero_General::Price_Unlock;
    int param_stars = CGameDesign::FileHero_design::CSheetHero_General::Rarity;
	_id = id;
	_level = level;
	_is_lock = lock;
	_level_max = false;
	_has_promo = haspromo;
	if (_level >= game->_game_design.Hero_design.SheetArcher.int32Value._totalData)
	{
		_level = game->_game_design.Hero_design.SheetArcher.int32Value._totalData;
		_level_max = true;
	}
	int heroindex = game->GetDesignHeroIndex(_id);
	sprintf(_name, "%s", game->GetDesignHeroName(heroindex));
	_cost_unlock = game->GetDesignHeroGeneral(heroindex, param_cost_unlock);
	_level_unlock = game->GetDesignHeroGeneral(heroindex, param_level_unlock);
	_speed = game->GetDesignHeroGeneralFloat(heroindex, param_speed);
	_speed_attack = game->GetDesignHeroGeneral(heroindex, param_speedatt);
	_type_range = game->GetDesignHeroGeneral(heroindex, param_type_range);
	_limit_break = game->GetDesignHeroGeneral(heroindex, param_limit);
	_critical = game->GetDesignHeroGeneralFloat(heroindex, param_critical);
    _stars = game->GetDesignHeroGeneral(heroindex, param_stars);
	_rar_level = rarlv;
	_deployed = deployed;
	UpdateRarity();
    printf("\n _stars = %d",_stars);
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	if (_level_max)
	{
		/*_cost_upgrade = GetCostUpgradeEndless(_level + 1);
		_damage = GetDamageEndless(_level);*/
	}
	else
	{
		_cost_upgrade = game->GetDesignHeroInfo(_id, _level + 1, param_costupgrade, GetNumStars());
		_damage = game->GetDesignHeroInfo(_id, _level, param_damage, GetNumStars());
	}
	
	_had_unlock = true;
	_spriteid = game->_hero_sprite[_id - 1];
	//game->LoadSpriteOptimize(_spriteid);
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	if (_type_range == HERO_TYPE_RANGE_MELEE)
	{
		_range = HERO_RANGE_DIS_MELEE;
		SetPos(60 + 100 + game->_point_o.X, ROAD_POSY + CMath::RANDOM(0, 2) * 5);
	}
	else
	{
		_range = game->_screen_width;
		SetPos(30 + 100 + game->_point_o.X, ROAD_POSY + 15);
	}
	_count_frame_attack = 0;
	_count_frame_refill = 0;
	SetTarget(_x, _y);
	_oritation = HERO_ORITATION_RIGHT;
	SetState(HERO_STATE_IDLE);
	_power_attack = poweratt;
	_is_auto_attack = false;
	_power_skill = powerskill;
    _index_enemy_target = -1;
	InitAttackFrame();
	_skill_id = game->GetDesignHeroGeneral(heroindex, param_skill) - 1;
	if (_skill_id != HERO_SKILL_NONE)
	{
		float posy = _y;
		if (_skill_id == HERO_SKILL_ELECTRIC_BALL)
		{
			posy -= 100;
		}
		_skill.Init(_skill_id, _x, posy, GetDamageBasic());
	}	
	_is_play_skill = false;
	
	_range_damage_aoe = 0;
	if (!_is_lock)
	{
		game->_user.AddNewHeroes(_id, _level, deployed,_rar_level);
		//game->_user.ModifyNewHeroes(_id, _level, deployed, -1);
	}
	_anim_marker.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_marker.SetAnim(16, false);
	_anim_marker.SetPos(0, 0);
	_power_attack_max = MAX_POWER_NUM_TAP;
	_power_att_catch = _power_attack;
	_power_skill_catch = _power_skill;
	_is_use_auto_att = false;
	_is_use_auto_skill = false;
	
	GetRelicsBonus();
	if (_id == HERO_ID_WOLF_RANGER)
	{
		_pet_bird.Init(SPRITEID_EFFECT_SKILL_WOLFGIRL_02, PET_ID_BIRD, 200, 200, GetTotalDamage());
	}
	_is_new = false;
	_auto_being_active = false;
	_count_frame_mass_auto_att = 0;
	//printf("\n hero name = %s,id = %d", _name, _id);
}

void CHero::SetStar(int star)
{
	_stars = star;
}
int CHero::GetNumStars()
{
	return _stars + _rar_level;
}
void CHero::Modify( float x, float y, bool lock, int poweratt, int powerskill)
{
	_is_lock = lock;
	_had_unlock = true;
	SetPos(x, y);
	_power_attack = poweratt;
	_power_skill = powerskill;
	_is_new = false;
}
void CHero::RarityLevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_rar_level++;
	game->_user.ModifyNewHeroes(_id, _level, _deployed,-1, _rar_level);
}

void CHero::Render(float x, float y)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	game->_draw_manager_able.Add(&_anim, _x + x, _y + y, DRAWABLE_TYPE_NORMAL,0);
	RenderAttackFrame();
    if(_is_auto_attack || _is_max_speed)
    {
        float zoom = 0.5f + 0.1*CMath::SIN(GAME()->_frame_counter%180);
        long frame_counter = GAME()->_frame_counter;
        G()->SetRotate(frame_counter*6%360, _x+x, _y + y - 40);
        G()->SetOpacity(frame_counter%10+90);
        G()->SetScale(zoom, zoom,_x+x, _y + y - 40);
        GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 15, _x+x, _y + y - 40);
        G()->SetRotate(-frame_counter*3%360, _x+x, _y + y - 40);
        G()->SetOpacity(100-frame_counter%10);
        GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 14, _x+x, _y + y - 40);
        G()->ClearRotate();
        G()->ClearScale();
    }
	if (_skill.GetID() == HERO_SKILL_CAT_NINJA || _skill.GetID() == HERO_SKILL_ACHEMIST)
	{
		_skill.AddDrawAnim(x, y);
	}

	//_anim.DrawAnimObject(G());
}
void CHero::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	float dis = CMath::DISTANCE(_x, _y, _targetx, _targety);
	float angle = CMath::ANGLE(_x, _y, _targetx, _targety);
	if (_count_frame_playsound > 0)
	{
		_count_frame_playsound--;
	}
		
	if (_id == HERO_ID_PALADIN && _state == HERO_STATE_SKILL)
	{
		if (_range < dis)
		{
			_x += 50 * CMath::COS(angle);
			_y += 50 * CMath::SIN(angle);

			return;
		}
	}
	_anim.UpdateAnimObject();
	if (_id == HERO_ID_WOLF_RANGER)
	{
		_pet_bird.Update();
	}
	//printf("\n update hero");
	if (_range < dis )
	{
		_count_frame_attack++;
		if (_state != HERO_STATE_SKILL)
		{
			if (_count_frame_attack >= _speed_attack)
			{
				float speed = _speed;
				if (_state == HERO_STATE_RUN)
				{
					speed = 50;
				}
				if (_type_range != HERO_TYPE_RANGE_RANGE)
				{
					_x += speed*CMath::COS(angle);
					_y += speed*CMath::SIN(angle);
					if (_y <= _targety)
					{
						_y += speed / 10.0f;
					}
				}


				if (_anim.IsCurrentAnimStop())
				{
					if (_state == HERO_STATE_RUN)
					{
						SetState(HERO_STATE_RUN);
					}
					else
					{
						SetState(HERO_STATE_WALK);
					}
				}
			}
			else
			{
				if (_anim.IsCurrentAnimStop())
				{
					SetState(HERO_STATE_IDLE);
				}
			}
		}
		
		SetPos(_x, _y);
		//printf("\n not attack");
	}
	else
	{
		if (_type_range != HERO_TYPE_RANGE_RANGE)
		{
			if (_y <= _targety)
			{
				_y += _speed;
			}
			else if (_y >= _targety + 20)
			{
				_y -= _speed;
			}
			if (_y >= ROAD_POSY + game->_point_o.Y + 30)
			{
				_y = ROAD_POSY + game->_point_o.Y + 30;
			}
			if (_y <= ROAD_POSY + game->_point_o.Y - 20)
			{
				_y = ROAD_POSY + game->_point_o.Y - 20;
			}
		}
		if (!game->_user._tutorial_completed && game->_tutorial_step != TUTORIAL_STEP_FREE)
		{
			_count_frame_attack = 0;
		}
		_count_frame_attack++;
		//printf("\n can attack -- _state = %d", _state);
		if (_state == HERO_STATE_ATTACK)
		{
			if (_anim._current_aframes_time == 1)
			{
				if (CheckHitDamage(_anim._anim_sprite->_aframe_id[_anim._current_aframes]))
				{
					if (_type_range == HERO_TYPE_RANGE_MELEE)
					{
						if (_index_enemy_target >= 0)
						{
							HitDamageActive();
						}
					}
				}
			}
		}
		_count_frame_refill++;
		if (_count_frame_refill % NUM_FRAME_AUTO_REFILL_ATTACK == 0 && !_is_auto_attack)
		{
			AddPowerAttack(1);
			_count_frame_refill = 0;
		}
        //printf("\n_speed_attack = %d",_speed_attack);
        if (_count_frame_attack >= _speed_attack /*&& _index_enemy_target != -1*/)
		{
			_count_frame_attack = 0;
			if (_state == HERO_STATE_ATTACK)
			{
				AddAttackFrame();
			}
			if (_state != HERO_STATE_SKILL)
			{
				SetState(HERO_STATE_ATTACK);
				if (game->_user._tutorial_step < TUTORIAL_STEP_TAP_ATT)
				{
					game->_num_hit_tutorial++;
				}
			}
			else
			{
				printf("\n play skill _skill_duration = %d", _skill_duration);
			}
		}
		else
		{
			if (_anim.IsCurrentAnimStop())
			{
				if (_state != HERO_STATE_SKILL)
				{
					if (_state == HERO_STATE_ATTACK)
					{
						AddAttackFrame();
					}
					SetState(HERO_STATE_IDLE);
				}
			}
		}
	}
	//printf("\n _skill_duration = %d", _skill_duration);
	if (_is_auto_attack)
	{
		int speed_auto = FPS_MAX / game->GetDesignGeneralInfo(DESIGN_GENERAL_AUTO_ATTACK_SPEED);
		if (speed_auto > _speed_attack)
		{
			speed_auto = _speed_attack - 1;
		}
		UpdateAutoAttack(speed_auto,false);
	}
	if (_skill_duration > 1)
	{
		_skill_duration--;
		if (_skill_duration == 15)
		{
			game->EffectHeroSkillEnd(_skill_id);
		}

	}
	else if (_skill_duration == 1)
	{
		_spriteid = game->_hero_sprite[_id - 1];
		_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
		//_anim.SetAnim(_anim.GetCurrentAnim(), false);
		//_anim.setToAFrame(_anim._current_aframes, 1);
		_range_damage_aoe = 0;
		_skill_duration = 0;
		_critical -= _skill._critical;
		if (_anim.IsCurrentAnimStop())
		{
			SetState(HERO_STATE_IDLE);
		}
	}
	if (_skill_id != HERO_SKILL_NONE)
	{
		_skill.Update();
		if (_skill.GetState() == SKILL_STATE_ACTIVE)
		{
			_is_play_skill = true;
		}
		else
		{
			_is_play_skill = false;
		}
	}
	if (_state == HERO_STATE_SKILL)
	{
		_is_play_skill = true;
		UpdatePlaySkill();
	}
	UpdateAttackFrame();
}
void CHero::SetLevel(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	_level = level;
	if (_level >= game->_game_design.Hero_design.SheetArcher.int32Value._totalData)
	{
		_level = game->_game_design.Hero_design.SheetArcher.int32Value._totalData;
		_level_max = true;
	}
	_damage = game->GetDesignHeroInfo(_id, _level, param_damage, GetNumStars());
	_cost_upgrade = game->GetDesignHeroInfo(_id, _level + 1, param_costupgrade, GetNumStars());
}
int CHero::GetLevel()
{
	return _level;
}
const char* CHero::GetName()
{
	return _name;
}
INT_TIME CHero::GetDamage()
{
	return GetTotalDamage();
}

float CHero::GetSpeed()
{
	return _speed;
}
void CHero::SetSpeed(float speed)
{
	_speed = speed;
}
int CHero::GetTypeRange()
{
	return _type_range;
}
int CHero::GetLimitBreak()
{
	return _limit_break;
}
int CHero::GetCritical()
{
	return _critical;
}

int CHero::GetLevelUnlock()
{
	return _level_unlock;
}

INT_TIME CHero::GetCostUpgrade()
{
	return _cost_upgrade;
}
void CHero::SetState(int state)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_state = state;
	switch (state)
	{
	case HERO_STATE_IDLE:
		if (_oritation == HERO_ORITATION_RIGHT)
		{
			_anim.SetAnim(HERO_ANIM_IDLE, false);
		}
		else
		{
			_anim.SetAnim(HERO_ANIM_IDLE + HERO_ANIM_NUM_MAX, false);
		}
		
		break;
	case HERO_STATE_ATTACK:
	{
		/*if (_index_enemy_target == -1)
		{
			break;
		}*/
		PlaySound();
		if (_oritation == HERO_ORITATION_RIGHT)
		{
			_anim.SetAnim(HERO_ANIM_ATTACK1, false);
		}
		else
		{
			_anim.SetAnim(HERO_ANIM_ATTACK1 + HERO_ANIM_NUM_MAX, false);
		}
		if (!game->_user._tutorial_completed && (game->_user._tutorial_step >= TUTORIAL_STEP_BATTLE_START || game->_num_hit_tutorial > 0))
		{
			if (game->_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT)
			{
				game->_num_hit_tutorial++;
			}
			if (game->_num_hit_tutorial >= 4 )
			{
				//printf("\n game->_user._quest_num_kill_monster:%d", game->_user._quest_num_kill_monster);
				if (game->_user._tutorial_step < TUTORIAL_STEP_TAP_ATT)
				{
					game->_tutorial_step = TUTORIAL_STEP_TAP_ATT;
				}
				else if (game->_user._tutorial_step == TUTORIAL_STEP_TAP_ATT /*&& game->_num_hit_tutorial >= 20*/)
				{
					if (game->_user._quest_num_kill_monster >= 32)
					{
						game->_tutorial_step = TUTORIAL_STEP_USE_SKILL;
						AddPowerSkill(_limit_break);
					}
					else
					{
						if (_power_skill >= _limit_break)
						{
							_power_skill = _limit_break-1;
						}
					}
					
				}
				
			}
		}
	}
		break;
	case HERO_STATE_WALK:
		if (_oritation == HERO_ORITATION_RIGHT)
		{
			_anim.SetAnim(HERO_ANIM_WALK, false);
		}
		else
		{
			_anim.SetAnim(HERO_ANIM_WALK + HERO_ANIM_NUM_MAX, false);
		}
		break;
	case HERO_STATE_RUN:
	{
		float dis = CMath::DISTANCE(_x, _y, _targetx, _targety);
		int anim = HERO_ANIM_RUN;
		if (_range >= dis)
		{
			anim = HERO_ANIM_WALK;
		}
        //_anim.SetAnim(anim, false);
		if (_oritation == HERO_ORITATION_RIGHT)
		{
			_anim.SetAnim(anim, false);
		}
		else
		{
			_anim.SetAnim(anim + HERO_ANIM_NUM_MAX, false);
		}
	}
		
		break;
	case HERO_STATE_BESKILL:
		
		if (_oritation == HERO_ORITATION_RIGHT)
		{
			_anim.SetAnim(HERO_ANIM_BESKILL, false);
		}
		else
		{
			_anim.SetAnim(HERO_ANIM_BESKILL + HERO_ANIM_NUM_MAX, false);
		}
		break;
	case HERO_STATE_SKILL:
		_is_play_skill = true;
		if (_id == HERO_ID_PALADIN || _id == HERO_ID_WOLF_RANGER)
		{
			game->EffectHeroSkillActive(_skill_id);
		}
		if (_oritation == HERO_ORITATION_RIGHT || _id == HERO_ID_PALADIN)
		{
			_anim.SetAnim(HERO_ANIM_SKILL1, false);
		}
		else
		{
			_anim.SetAnim(HERO_ANIM_SKILL1 + HERO_ANIM_NUM_MAX, false);
		}
		break;
	default:
		break;
	}
}
int CHero::GetState()
{
	return _state;
}
int CHero::GetSkill()
{
	return _skill.GetID();
}
bool CHero::HasUnlock()
{
	return _had_unlock;
}
void CHero::UnlockActive()
{
	_had_unlock = true;
}
void CHero::SetPos(float x, float y)
{
	_x = x;
	_y = y;
	_anim.SetPos(_x, _y);
}
float CHero::GetPosX()
{
	return _x;
}
float CHero::GetPosY()
{
	return _y;
}

void CHero::SetTarget(float tarx, float tary)
{
	if (_x < tarx)
	{
		_oritation = HERO_ORITATION_RIGHT;
	}
	else if(_x > tarx )
	{
		tarx = tarx - 200;
		_oritation = HERO_ORITATION_LEFT;
	}
	_targetx = tarx;
	_targety = tary;
}

void CHero::SetEnemyIndexTarget(int index)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_index_enemy_target = index;
    if(_index_enemy_target < 0)
    {
        return;
    }
	SetTarget(game->_enemy[_index_enemy_target].GetPosX() - game->_enemy[_index_enemy_target]._size_w/2, game->_enemy[_index_enemy_target].GetPosY());
}
void CHero::SetHeroID(int id)
{
	_id = id;
}
int CHero::GetHeroID()
{
	return _id;
}
void CHero::ForceAttack(bool addpower)
{
    TDGame *game = (TDGame*)GAME()->_current_game;
	
	if (_count_frame_attack < 0 /*|| _index_enemy_target < 0*/ || _is_play_skill)
    {
        return;
    }
	//if (posx < k_SCREEN_WIDTH)
    {
        _count_frame_attack = _speed_attack;
		if (!_is_auto_attack && addpower)
        {
            AddPowerAttack(1);
        }
		//printf("\nforce attack _skill_duration:%d", _skill_duration);
		if (_skill_duration <= 0)
		{
			AddPowerSkill(1);
		}
		if (_state == HERO_STATE_ATTACK)
		{
			AddAttackFrame();
		}
		while (!_anim.IsCurrentAnimStop())
		{
			_anim.UpdateAnimObject();
			//_anim.DrawAnimObject(G());
			if (_type_range == HERO_TYPE_RANGE_MELEE)
			{
				if (_anim._current_aframes_time == 1)
				{
					if (CheckHitDamage(_anim._anim_sprite->_aframe_id[_anim._current_aframes]))
					{
						if (_index_enemy_target >= 0)
						{
							HitDamageActive();
						}
					}
				}
			}
		}
        SetState(HERO_STATE_RUN);
    }
	
}

int  CHero::GetSpriteID()
{
	return _spriteid;
}

void CHero::AddPowerAttack(float power)
{
	if (power < 0)
	{
		if (_count_frame_mass_auto_att > 0)
		{
			_count_frame_mass_auto_att += power;
			if (_count_frame_mass_auto_att <= 0)
			{
				if (!_auto_being_active)
				{
					_is_auto_attack = false;
					_count_frame_mass_auto_att = 0;
				}
			}
			return;
		}
	}
	_power_attack += power;
	if (_power_attack >= _power_attack_max)
	{
		_power_attack = _power_attack_max;
	}
	
	if ((_power_attack <= 0 && _auto_being_active)&& _count_frame_mass_auto_att <= 0)
	{
		_power_attack = 0;
		_count_frame_mass_auto_att = 0;
		_is_auto_attack = false;
		_auto_being_active = false;
		//AddPowerAttack(_power_att_catch);
	}
}
float CHero::GetPowerAttack()
{
	return _power_attack;
}
bool CHero::IsFullPowerAttack()
{
	if (_power_attack >= _power_attack_max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CHero::AddPowerSkill(float power)
{
	_power_skill += power;
	if (_power_skill >= _limit_break)
	{
		_power_skill = _limit_break;
	}
	if (_power_skill <= 0)
	{
		_power_skill = 0;
		_power_skill = false;
		
	}
}
float CHero::GetPowerSkill()
{
	return _power_skill;
}
bool CHero::IsFullPowerSkill()
{
	if (_power_skill >= MAX_POWER_SKILL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CHero::ActiveAutoAttack(bool mass_auto)
{
	_count_frame_attack = 0;
	_is_auto_attack = true;
	if (!_auto_being_active)
	{
		_auto_being_active = !mass_auto;
	}
	
}
void CHero::UpdateAutoAttack(int speed, bool skill)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int duration = game->GetDesignGeneralInfo(DESIGN_GENERAL_TIME_AUTO_ATTACK);
	duration += (int)(duration*(game->GetRelicsDuration(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
	float power = _power_attack_max / (duration * 60.0f);
	_count_frame_attack++;
	if (!skill)
	{
		AddPowerAttack(-power);
	}
	//printf("\n _count_frame_attack: %d --- speed:%d",_count_frame_attack, speed);
	if (_count_frame_attack >= speed)
	{
		//_count_frame_attack = 0;
        for(int i = 0; i < 3; i++)
        {
            if(game->_ingame_hero_button[i]._heroID == GetHeroID())
            {
                game->_ingame_hero_button[i]._active = true;
                game->_ingame_hero_button[i]._effect_zoom_scale = 1.0f;
                game->_ingame_hero_button[i]._anim.SetAnim(77, false);
                game->_ingame_hero_button[i].AddEffect();
                //game->_effect_skill_add_energy[i] = 10;
            }
            
        }
        
		ForceAttack(false);
	}
}
void CHero::CancelTarget()
{
	_index_enemy_target = -1;
	SetTarget(_x, _y);
    ResetAttackFrame();
}

void CHero::InitAttackFrame()
{
	switch (_type_range)
	{
	case HERO_TYPE_RANGE_RANGE:
		_render_attack_frame = true;
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			_frame_attack[i].Init(_x, _y, _spriteid, 1, GetTotalDamage(), _critical);
		}
		break;
	default:
		break;
	}
}
void CHero::AddAttackFrame()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	switch (_id)
	{
	case HERO_ID_ARCHER:
		_render_attack_frame = true;
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			if (_frame_attack[i].IsFree())
			{
				_frame_attack[i].Add(_x, _y - 27, 40, _index_enemy_target, GetTotalDamage(), _range_damage_aoe, _critical);
				break;
			}
		}
		break;
	case HERO_ID_FIRE_MAGE:
		_render_attack_frame = true;
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			if (_frame_attack[i].IsFree())
			{
				_frame_attack[i].Add(_x + 45, _y - 40, 40, _index_enemy_target, GetTotalDamage(), _range_damage_aoe, _critical);
				break;
			}
		}
		break;
	case HERO_ID_ELECTRIC_MAGE:
		_render_attack_frame = true;
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			if (_frame_attack[i].IsFree())
			{
				_frame_attack[i].Add(_x + 25, _y - 27, 40, _index_enemy_target, GetTotalDamage(), _range_damage_aoe, _critical);
				break;
			}
		}
		break;
	case HERO_ID_WOLF_RANGER:
		_render_attack_frame = true;
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			if (_frame_attack[i].IsFree())
			{
				int posy = 27;
				if (_skill_duration > 0)
				{
					posy = 52;
					_frame_attack[i]._sprite = _skill._sprite;
				}
				else
				{
					if (_frame_attack[i]._sprite == _skill._sprite)
					{
						_frame_attack[i]._sprite = _spriteid;
					}
				}
				INT_TIME damage = GetTotalDamage()*(_skill.GetDamageMulti() / 100.0f);
				_frame_attack[i].Add(_x, _y - posy, 40, _index_enemy_target, damage, _range_damage_aoe, _critical);
				break;
			}
		}
		break;
	default:
		break;
	}
}
void CHero::RenderAttackFrame()
{
	switch (_type_range)
	{
	case HERO_TYPE_RANGE_RANGE:
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			_frame_attack[i].Render(0, 0);
		}
		break;
	default:
		break;
	}
}
void CHero::UpdateAttackFrame()
{
	switch (_type_range)
	{
	case HERO_TYPE_RANGE_RANGE:
		for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
			if (_id == HERO_ID_WOLF_RANGER)
			{
				if (_skill_duration > 0)
				{
					
				}
			}
			_frame_attack[i].Update(false);
		}
		break;
	default:
		break;
	}
}
void CHero::ResetAttackFrame()
{
	switch (_type_range)
	{
	case HERO_TYPE_RANGE_RANGE:
		/* for (int i = 0; i < NUM_FRAME_ATTACK; i++)
		{
		_frame_attack[i]. = -1;
		}*/
		break;
	default:
		break;
	}
}

void CHero::SkillActive()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_skill_id == HERO_SKILL_NONE)
	{
		return;
	}
	AddPowerSkill(-_limit_break);
	for (int i = 0; i < NUM_MAX_TARGET; i++)
	{
		_skill._list_target[0][i] = -1;
		_skill._list_target[1][i] = -1;
	}
	SetState(HERO_STATE_SKILL);
	if (_id == HERO_ID_PALADIN)
	{
		int enemyindex = game->GetEnemyIndexNearest(false);
		if (enemyindex >= 0 && _x > game->_enemy[enemyindex].GetPosX())
		{
			SetTarget(game->_enemy[enemyindex].GetPosX() - game->_enemy[enemyindex]._size_w, game->_enemy[enemyindex].GetPosY());
		}
	}
	GAME()->PlaySFX(SFX_SKILL_CAST);
}

void CHero::UpdatePlaySkill()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int rand = CMath::RANDOM(1, 100);
	INT_TIME damage = GetTotalDamage();
	int duration = 0;
	if (_anim.IsCurrentAnimStop())
	{
		int anim = _anim.GetCurrentAnim();
		if (anim == HERO_ANIM_SKILL1 || anim == HERO_ANIM_SKILL1 + HERO_ANIM_NUM_MAX)
		{
			_anim.SetAnim(anim + 1, false);
		}
		else if (anim == HERO_ANIM_SKILL2 || anim == HERO_ANIM_SKILL2 + HERO_ANIM_NUM_MAX)
		{
			float speed = 0;
			int posx = _x;
			int posy = _y;
			_skill.Reset();
			switch (_skill.GetID())
			{
			case HERO_SKILL_GREATCLASH:
				//if (_spriteid == SPRITEID_HERO_SWORDSMAN_01)
				//{
				//	_spriteid = SPRITEID_EFFECT_SKILL_SWORDMAN_01;
				//	//game->LoadSpriteOptimize(_spriteid);
				//	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
				//	SetState(HERO_STATE_IDLE);
				//}
				/*_range_damage_aoe = 150;
				_skill_duration = _skill.GetDurarion();
				_skill_duration += (int)(_skill_duration*(game->GetRelicsSkillDuration(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);*/
				_skill_duration = 1;
				_critical += _skill._critical;
				speed = 15.0f;
				posx += 140;
				//_is_play_skill = false;
				break;
			case HERO_SKILL_WINDARROW:
				speed = 30;
				posy -= 25;
				for (int i = 0; i < game->_num_enemy_inwave; i++)
				{
					//printf("\n num = %d", i);
					_skill.AddTarget(i);
				}
				_skill._has_critical = false;
				if (rand <= _skill._critical)
				{
					game->_user._quest_num_critical_hit++;
					_skill._has_critical = true;
					damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
				}
				GAME()->PlaySFX(SFX_ARCHER_SKILL);
				break;
			case HERO_SKILL_ELECTRIC_BALL:
				posy -= 36;
				posx += 36;
				_skill._has_critical = false;
				_skill._critical = _critical;
				speed = 0.5f;
				break;
			case HERO_SKILL_BEAST_MASTER:
				posy = ROAD_POSY;
				posx = WEAPON_FROST_MAGE_POSX - 300;
				_skill._has_critical = false;
				_skill._critical = _critical;
				speed = 13.0f;
				break;
			case HERO_SKILL_CAT_NINJA:
				posy = ROAD_POSY + 15 + game->_point_o.Y;
				posx = k_SCREEN_WIDTH/2;
				_skill._has_critical = false;
				_skill._critical = _critical;
				speed = 0.0f;
				break;
			case HERO_SKILL_SENTINEL:
				_skill_duration = _skill.GetDurarion();
				duration = (int)(_skill_duration*(game->GetRelicsSkillDuration(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
				_skill_duration = 0;
				break;
			case HERO_SKILL_ACHEMIST:
				_skill_duration = _skill.GetDurarion();
				duration = (int)(_skill_duration*(game->GetRelicsSkillDuration(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
				_skill_duration = 0;
				posy = ROAD_POSY-20;
				posx = 2*k_SCREEN_WIDTH/3 + 30;
				break;
			case HERO_SKILL_WOLF_RANGER:
				if (_spriteid == SPRITEID_HERO_WOLFGIRL_01)
				{
					_spriteid = SPRITEID_EFFECT_SKILL_WOLFGIRL_01;
					_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
					SetState(HERO_STATE_IDLE);
				}
				_range_damage_aoe = 150;
				_skill_duration = _skill.GetDurarion();
				_skill_duration += (int)(_skill_duration*(game->GetRelicsSkillDuration(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
                if(_skill_duration < 1)
                {
                    _skill_duration = 1;
                }
				_critical += _skill._critical;
				break;
			default:
				break;
			}
			_skill.Active(posx, posy, 0, 0, speed, damage, duration);
			SetState(HERO_STATE_IDLE);
		}
	}
}
void CHero::LevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	//int heroindex = game->GetDesignHeroIndex(_id);
	UpdateRarity();
	_level++;
	if (_level >= levelmax)
	{
		_level = levelmax;
		_level_max = true;
	}
	if (!_level_max)
	{
		_cost_upgrade = game->GetDesignHeroInfo(_id, _level + 1, param_costupgrade, GetNumStars());
	}
	
	GAME()->PlaySFX(SFX_HERO_LEVELUP);
	game->_user._quest_num_upgrade_heroes++;
	GetRelicsBonus();
}

void CHero::HitDamageActive()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int rand = CMath::RANDOM(1, 100);
	INT_TIME damage = GetTotalDamage();
	if (_range_damage_aoe > 0)
	{
		for (int i = 0; i < game->_num_enemy_inwave;i++)
		{
			int enemy_posx = game->_enemy[i].GetPosX() /*- game->_enemy[i]._size_w/2*/;
			int enemy_posy = game->_enemy[i].GetPosY();
			//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || enemy_posx >= game->_screen_width)
			if (!game->_enemy[i].IsLive() || enemy_posx >= game->_screen_width)
			{
				continue;
			}
			damage = damage*(_skill.GetDamageMulti() / 100.0f);
			float dis = CMath::DISTANCE(_x, _y, enemy_posx, enemy_posy);
			/*if ((enemy_posx <= _x + _range_damage_aoe && enemy_posx >= _x && _oritation == HERO_ORITATION_RIGHT) ||
				(enemy_posx >= _x - _range_damage_aoe && enemy_posx <= _x && _oritation == HERO_ORITATION_LEFT))*/
				if (dis <= _range_damage_aoe / 2 + game->_enemy[i]._size_w / 2)
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
				game->_enemy[i].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_SKILL_SWORDMAN_02, false);
			}
		}
	}
	else
	{
		if (rand <= _critical)
		{
			game->_user._quest_num_critical_hit++;
			damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
			game->AddEffectHPLost(damage, game->_enemy[_index_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_index_enemy_target].GetPosY() - game->_enemy[_index_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
		}
		else
		{
			game->AddEffectHPLost(damage, game->_enemy[_index_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_index_enemy_target].GetPosY() - game->_enemy[_index_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
		}
		game->_enemy[_index_enemy_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
	}
	
	
	_index_enemy_target = -1;
}

bool CHero::CheckHitDamage(int frame_id)
{
	bool ret = false;
	int num_frame = _anim_marker.getMaxAframe();
	for (int i = 0; i < num_frame; i++)
	{
		if (_anim_marker._anim_sprite->_aframe_id[_anim_marker._current_aframes + i] == frame_id)
		{
			ret = true;
		}
	}
	return ret;
}
void CHero::PlaySound()
{
	if (_count_frame_playsound > 0)
	{
		return;
	}
	_count_frame_playsound = 8;
	switch (_spriteid)
	{
	case SPRITEID_EFFECT_SKILL_SWORDMAN_01:
		//PLAY_SFX(SFX__SKILL_PALADIN_ATTACK);
		GAME()->PlaySFX(SFX__SKILL_PALADIN_ATTACK);
		break;
	case SPRITEID_HERO_SWORDSMAN_01:
		//PLAY_SFX(SFX_SWORD_ATTACK);
		GAME()->PlaySFX(SFX_SWORD_ATTACK);
		break;
	case SPRITEID_HERO_SANTA_01:
		//PLAY_SFX(SFX_SWORD_ATTACK);
		GAME()->PlaySFX(SFX_SWORD_ATTACK);
		break;
	case SPRITEID_HERO_BEASTMASTER_01:
		//PLAY_SFX(SFX_SWORD_ATTACK);
		GAME()->PlaySFX(SFX_SWORD_ATTACK);
		break;
	case SPRITEID_HERO_CAT_NINJA_01:
		//PLAY_SFX(SFX_SWORD_ATTACK);
		GAME()->PlaySFX(SFX_SWORD_ATTACK);
		break;
	case SPRITEID_HERO_ARCHER_01:
		//PLAY_SFX(SFX_ARCHER_ATTACK);
		GAME()->PlaySFX(SFX_ARCHER_ATTACK);
		break;
	case SPRITEID_HERO_MAGE_01:
		//PLAY_SFX(SFX_MAGIC_ATTACK);
		GAME()->PlaySFX(SFX_MAGIC_ATTACK);
		break;
	case SPRITEID_HERO_MAGELIGHTING_01:
		//PLAY_SFX(SFX_MAGIC_ATTACK);
		GAME()->PlaySFX(SFX_MAGIC_ATTACK);
		break;
	case SPRITEID_HERO_WOLFGIRL_01:
		//PLAY_SFX(SFX_MAGIC_ATTACK);
		GAME()->PlaySFX(SFX_MAGIC_ATTACK);
		break;
	default:
		break;
	}
}

void CHero::UpdateRarity()
{
	_rar_level = 0;
	TDGame *game = (TDGame*)GAME()->_current_game;
	int num = game->GetRelicsUpgradeRarity(_id);
	while (num > 0)
	{
		RarityLevelUp();
		num--;
	}
}

INT_TIME CHero::GetDamageExtra()
{
	return _damage_extra;
}

INT_TIME CHero::GetTotalDamage()
{
	return _damage + _damage_extra;
}
INT_TIME CHero::GetDamageBasic()
{
	return _damage;
}

INT_TIME CHero::GetTotalDamageHightRar()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	int heroindex = game->GetDesignHeroIndex(_id);
	INT_TIME dmg = 0;
	if (_level >= levelmax)
	{
		dmg = game->GetDesignHeroInfo(_id, levelmax - 1, param_damage, GetNumStars() + 1);
	}
	else
	{
		dmg = game->GetDesignHeroInfo(_id, _level, param_damage, GetNumStars() + 1);
	}
	INT_TIME dmg_extra = 0;
	dmg += (INT_TIME)(dmg*((game->GetRelicsAttackBasic(ITEMRELIC_GROUP_HERO, _id)) / 100.0f));

	dmg_extra += (INT_TIME)(dmg*((game->GetRelicsAttack(ITEMRELIC_GROUP_HERO, _id)) / 100.0f));
	dmg_extra += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_HERO, _id);
	return dmg + dmg_extra;
}

void CHero::GetRelicsBonus()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_speedatt = CGameDesign::FileHero_design::CSheetHero_General::Speed_Attack;
	int param_limit = CGameDesign::FileHero_design::CSheetHero_General::Limit_Break;
	int param_critical = CGameDesign::FileHero_design::CSheetHero_General::Critical;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	int heroindex = game->GetDesignHeroIndex(_id);
	if (_level >= levelmax)
	{
		/*_cost_upgrade = GetCostUpgradeEndless(_level+1);
		_damage = GetDamageEndless(_level);*/
		_damage = game->GetDesignHeroInfo(_id, levelmax-1, param_damage, GetNumStars());
	}
	else
	{
		_cost_upgrade = game->GetDesignHeroInfo(_id, _level + 1, param_costupgrade, GetNumStars());
		_damage = game->GetDesignHeroInfo(_id, _level, param_damage, GetNumStars());
	}
	_damage_extra = 0;
	_speed_attack = game->GetDesignHeroGeneral(heroindex, param_speedatt);
	_limit_break = game->GetDesignHeroGeneral(heroindex, param_limit);
	_critical = game->GetDesignHeroGeneralFloat(heroindex, param_critical);
#if RELIC_PRESTIGE_ADD_DMG_BASIC
	_damage += (INT_TIME)(_damage*((game->GetRelicsAttackBasic(ITEMRELIC_GROUP_HERO, _id)) / 100.0f));
#else
	_damage_extra += (INT_TIME)(_damage*((game->GetRelicsAttackBasic(ITEMRELIC_GROUP_HERO, _id)) / 100.0f));
#endif
	

	_damage_extra += (INT_TIME)(_damage*((game->GetRelicsAttack(ITEMRELIC_GROUP_HERO, _id)) / 100.0f));
	_damage_extra += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_HERO, _id);
	float att_mul = (game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_HERO, _id)) / 100.0f;
	if (att_mul > 0)
	{
		_speed_attack /= att_mul;
	}
	//_speed_attack /= (_speed_attack*(game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
	_critical += game->GetRelicsCritical(ITEMRELIC_GROUP_HERO, _id);
	_cost_upgrade -= (int)(_cost_upgrade*(game->GetRelicsCostDecrease(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
	_limit_break -= (int)(_limit_break*(game->GetRelicsMana(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
	if (_id == HERO_ID_WOLF_RANGER)
	{
		_pet_bird.Modify( GetTotalDamage());
	}
	//UpdateRarity();
	
}

INT_TIME CHero::GetDamageEndless(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int heroindex = game->GetDesignHeroIndex(_id);
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	float param1 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM1);
	float param2 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM2);
	float param3 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM3);
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData - 1;
	//printf("\n level - levelmax = %d", level - levelmax);
	INT_TIME damage_ret = INT_TIME(param1 + param1*param2*(level - levelmax) + (level - levelmax)*param3 + (level - levelmax));
	return damage_ret;
}

INT_TIME CHero::GetCostUpgradeEndless(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int heroindex = game->GetDesignHeroIndex(_id);
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int param_costupgrade = CGameDesign::FileHero_design::CSheetPaladin::Cost_Upgrade;
	float param1 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM1);
	float param2 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM2);
	float param3 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM3);
	float param4 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM4);
	float param5 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM5);
	float param6 = game->GetDesignHeroFormulaFloat(heroindex, HERO_FORMULA_PARAM6);
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData - 1;
	INT_TIME damage = INT_TIME(param1 + param1*param2*(level - levelmax) + (level - levelmax)*param3 + (level - levelmax));
	INT_TIME cost = INT_TIME(param6*damage + param4*param5);
	return cost;
}
INT_TIME CHero::GetDamageLevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileHero_design::CSheetPaladin::Attack;
	int levelmax = game->_game_design.Hero_design.SheetPaladin.int32Value._totalData;
	int heroindex = game->GetDesignHeroIndex(_id);
	int damage = 0;
	if (_level+1 < levelmax)
	{
		damage = game->GetDesignHeroInfo(_id, _level + 1, param_damage, GetNumStars());
#if RELIC_PRESTIGE_ADD_DMG_BASIC
		damage += (INT_TIME)(damage*(game->GetRelicsAttackBasic(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
#endif
		return damage;
	}
	else
	{
		damage = game->GetDesignHeroInfo(_id, levelmax - 1, param_damage, GetNumStars());
#if RELIC_PRESTIGE_ADD_DMG_BASIC
		damage += (INT_TIME)(damage*(game->GetRelicsAttackBasic(ITEMRELIC_GROUP_HERO, _id)) / 100.0f);
#endif
		return damage;
	}
}
int CHero::GetStars()
{
    TDGame *game = (TDGame*)GAME()->_current_game;
     int param_stars = CGameDesign::FileHero_design::CSheetHero_General::Rarity;
    int heroindex = game->GetDesignHeroIndex(_id);
    _stars = game->GetDesignHeroGeneral(heroindex, param_stars);
	return _stars;
}
INT_TIME CHero::GetDamageNormal()
{
	return GetDamageBasic();
}
INT_TIME CHero::GetBonusDamage()
{
    /*TDGame *game = (TDGame*)GAME()->_current_game;
    int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
    INT_TIME damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
    INT_TIME damage_bonus = (INT_TIME)(damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
    damage_bonus += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_WEAPON, _type + 2);
    return damage_bonus;*/
    return 0;
}
int CHero::GetCostUnlock()
{
	return _cost_unlock;
}

bool CHero::SkillHasStatue()
{
	return _skill.HasStatue();
}

void CHero::AddHPStatue(INT_TIME hp)
{
	_skill.AddHPStatue(hp);
}
