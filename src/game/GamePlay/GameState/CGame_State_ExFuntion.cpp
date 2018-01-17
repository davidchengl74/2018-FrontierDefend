#include "pch.h"
#include "../../GameCore/CGame.h"
#include <ctype.h>
extern "C" void	GoToReviewInItune();
/*NOT SURE*/		extern "C" void				OS_Rating();//open rating page



void TDGame::WeaponInit()
{
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		_weapon[i].Init(i, 1, true);
	}
}

void TDGame::WeaponResetLevel()
{
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		if (!_weapon[i].IsLock())
		{
			_weapon[i].Init(i, 1, false);
		}
		else
		{
			_weapon[i].Init(i, 1, true);
		}
	}
}

void TDGame::WeaponRender(float x, float y)
{
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		_weapon[i].Render(x, y,100);
	}
}
void TDGame::WeaponUpdate()
{
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		_weapon[i].Update();
	}
}

void TDGame::CharacterInit(int level)
{
	float tarx = ENEMY_TARGETX + _point_o.X;
	float tary = ENEMY_TARGETY + _point_o.Y;
	int param_hp = CGameDesign::FileEnemy_design::CSheetBattle_1::HP;
	int param_damage = CGameDesign::FileEnemy_design::CSheetBattle_1::Damage;
	int param_coin = CGameDesign::FileEnemy_design::CSheetBattle_1::Coin;
	int param_size = CGameDesign::FileEnemy_design::CSheetBattle_1::Enemy_Size;
	int param_skill = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Skill;
	int param_num_enemy = CGameDesign::FileEnemy_design::CSheetBattle_1::Quantity;
	int param_repawn = CGameDesign::FileEnemy_design::CSheetBattle_1::Respawn;
	int param_ID = CGameDesign::FileEnemy_design::CSheetBattle_1::Enemy_ID;
	int param_row_repawn = CGameDesign::FileEnemy_design::CSheetBattle_1::Delay_after_spawn;
	int _num_row_inwave = GetNumEnemyInWave(_battle_current, _wave_current);
	int _num_enemy_inwave_old = _num_enemy_inwave;
	_num_enemy_inwave = 0;
	if (_num_row_inwave <= 0)
	{
		printf("\n khong co data");
		return;
	}
	
	for (int i = 0; i < _num_row_inwave; i++)
	{
		int timerepawn = 0;
		float x = _screen_width + 200;
		float y = 0;
		char id[10];
		sprintf(id, "%s", GetDesignBattleString(_battle_current, i + _row_start_inwave, param_ID));
		INT_TIME hp = GetDesignBattleHPandDamage(_battle_current,i + _row_start_inwave,param_hp);
		
		INT_TIME damage = GetDesignBattleHPandDamage(_battle_current, i + _row_start_inwave, param_damage);
		int coin = GetDesignBattleGeneral(_battle_current, i + _row_start_inwave, param_coin);
		int size = GetDesignBattleGeneral(_battle_current, i + _row_start_inwave, param_size);
		int index_enemy = GetEnemyCreationIndex(id);
		int skill = CHARACTER_TYPE_SKILL_NONE;
		if (index_enemy >=0)
		{
			skill = GetDesignEnemyCreationGeneral(index_enemy, param_skill);
		}
		int num_enemy = GetDesignBattleGeneral(_battle_current, i + _row_start_inwave, param_num_enemy);
		int total_enemy = _num_enemy_inwave;
		timerepawn += GetDesignBattleGeneral(_battle_current, i + _row_start_inwave, param_row_repawn);
        //printf("\n timerepawn 111 = %d",timerepawn);
		for (int j = total_enemy; j < total_enemy + num_enemy; j++)
		{
			y = ROAD_POSY + CMath::RANDOM(-1, 6) * 3+ _point_o.Y;
			tary = y;
			timerepawn += GetDesignBattleGeneral(_battle_current, i + _row_start_inwave, param_repawn);
			_enemy[j].Init(id, x, y, tarx, tary, hp, damage, coin, size, skill, timerepawn);
			_num_enemy_inwave++;
			if (skill == CHARACTER_SKILL_FLYING)
			{
				y = WEAPON_ACHER_POSY + CMath::RANDOM(-5, 5) * 3 + _point_o.Y;
				char fly_id[10];
				sprintf(fly_id, "FM1");
				_enemy[j + num_enemy].Init(fly_id, x, y, tarx + 100, y, hp/2, damage, 0, 0, 0, timerepawn);
				_enemy[j]._enemy_bird_index = j + num_enemy;
				_num_enemy_inwave++;
				
			}
		}
	}
	/*for (int i = _num_enemy_inwave; i < _num_enemy_inwave_old; i++)
	{
		_enemy[i].Init(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		_enemy[i].SetState(CHARACTER_STATE_DIE);
	}*/
}
void TDGame::CharacterRender(float x, float y)
{
	_draw_manager_able.Init();
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		_enemy[i].Render(x, y, 100);
	}
	//_draw_manager_able.Render(0, 0,0);

	//_draw_manager_hero_able.Init();
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed)
			{
				//printf("\n index_inbattle = %d,name = %s", index_inbattle, _hero_inbattle_arr[index_inbattle].GetName());
				_hero_inbattle_arr[index_inbattle].Render(x, y);
			}
		}
		
	}
	_draw_manager_able.Render(0, 0, 0);
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		if (_enemy[i].GetSprite() == SPRITEID_MONSTER_FLYING)
		{
			_enemy[i]._anim.DrawAnimObject(G());
		}
	}
    for (int i = 0; i < _num_enemy_inwave; i++)
    {
        _enemy[i].RenderEffect(x, y, 100);
    }
	//_draw_manager_hero_able.Render(0, 0,1);
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			int skillid = _hero_inbattle_arr[index_inbattle]._skill_id;
			if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed)
			{
				if (skillid != HERO_SKILL_NONE)
				{
					_hero_inbattle_arr[index_inbattle]._skill.Render(0, 0);
				}
				if (_hero_inbattle_arr[index_inbattle].GetHeroID() == HERO_ID_WOLF_RANGER)
				{
					_hero_inbattle_arr[index_inbattle]._pet_bird.Render(0, 0);
				}
			}
		}
	}
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		EnemyEffectBeHitRender(i);
	}
}
void TDGame::EnemyEffectBeHitRender(int index)
{
	//for (int i = 0; i < _num_enemy_inwave;i++)
	{
		_enemy[index].RenderEffectBehit();
	}
}
void TDGame::CharacterUpdate()
{
	if (!_user._tutorial_completed || _user._tutorial_step < TUTORIAL_STEP_COMPLETED_2)
	{
		if (_tutorial_step != TUTORIAL_STEP_FREE)
		{
			return;
		}
	}
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed)
			{
				//if (_enemy[_hero_inbattle_arr[index_inbattle]._index_enemy_target].GetState() >= CHARACTER_STATE_DIE)
				if (!_enemy[_hero_inbattle_arr[index_inbattle]._index_enemy_target].IsLive())
				{
					_hero_inbattle_arr[index_inbattle].CancelTarget();
				}
				int enemy_index = GetEnemyIndexNearest(false);
				if (enemy_index >= 0 && _enemy[enemy_index].GetPosX() < _screen_width + _point_o.X)
				{
					_hero_inbattle_arr[index_inbattle].SetEnemyIndexTarget(enemy_index);
				}
				if (!_user._tutorial_completed)
				{
					if (_tutorial_step == TUTORIAL_STEP_FREE)
					{
						_hero_inbattle_arr[index_inbattle].Update();
					}
				}
				else
				{
					_hero_inbattle_arr[index_inbattle].Update();
				}
				
			}
		}
	}
	if (_is_changing_background)
	{
		return;
	}
	/*if (!_user._tutorial_completed || _user._tutorial_step < TUTORIAL_STEP_COMPLETED_2)
	{
		if (_tutorial_step != TUTORIAL_STEP_FREE)
		{
			return;
		}
	}*/
	EnemySetTargetFocus();
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		_enemy[i].Update();
	}
}

void TDGame::EnemySetTargetFocus()
{
	bool hastarget = false;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed)
			{
				if (_hero_inbattle_arr[index_inbattle].GetSkill() == HERO_SKILL_CAT_NINJA)
				{
					if (_hero_inbattle_arr[index_inbattle].SkillHasStatue())
					{
						hastarget = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		if (hastarget)
		{
			
			if (_enemy[i]._status < CHARACTER_STATUS_FLY && _enemy[i].GetTypeAttack() == CHARACTER_TYPE_ATTACK_MELEE)
			{
				if (_enemy[i].GetPosX() - _enemy[i]._size_w / 4 > k_SCREEN_WIDTH / 2)
				{
					_enemy[i]._target_focus = CHARACTER_TARGET_STATUE;
				}
			}
			else
			{
				_enemy[i]._target_focus = CHARACTER_TARGET_CASTLE;
			}
			printf("\n hastarget = %d - _enemy[%d]._status = %d,_enemy[i]._target_focus = %d", hastarget, i, _enemy[i]._status, _enemy[i]._target_focus);
		}
		else
		{
			if (_enemy[i]._target_focus == CHARACTER_TARGET_STATUE)
			{
				_enemy[i]._target_focus = CHARACTER_TARGET_CASTLE;
			}
		}
	}
}
void TDGame::AddHPStatue(INT_TIME hp)
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_user._hero_arr[i]._heroid >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_user._hero_arr[i]._heroid);
			if (index_inbattle >= 0 && _hero_inbattle_arr[index_inbattle]._deployed)
			{
				if (_hero_inbattle_arr[index_inbattle].GetSkill() == HERO_SKILL_CAT_NINJA)
				{
					if (_hero_inbattle_arr[index_inbattle].SkillHasStatue())
					{
						_hero_inbattle_arr[index_inbattle].AddHPStatue(hp);
					}
				}
			}
		}
	}
}


int TDGame::GetEnemyIndexNearest(bool bird)
{
	int indexmin = -1;
	bool alldie = true;
	int bird_index = -1;
	int bird_index_min = -1;
	int index_force_run = -1;
	if (_victory_active)
	{
		return indexmin;
	}
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		int enemy_state = _enemy[i].GetState();
		if (!_enemy[i].IsLive() && enemy_state != CHARACTER_STATE_DIE_START)
		{
			continue;
		}
		int sprite = _enemy[i].GetSprite();
		if (!bird)
		{
			bool conti = false;
			if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status <= CHARACTER_STATUS_RUNAWAY)
				|| _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_WEAPON
				|| _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_HERO)
			{
				alldie = false;
				conti = true;
			}
			if (!_enemy[i].HasAvailable())
			{
				if (index_force_run == -1)
				{
					index_force_run = i;
				}
				alldie = false;
				conti = true;
			}
			if (conti)
			{
				continue;
			}
		}

		if (enemy_state == CHARACTER_STATE_DIE_START)
		{
			alldie = false;
			continue;
		}

		if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status < CHARACTER_STATUS_RUNAWAY) && bird && _enemy[i].IsLive() && _enemy[i].GetPosX() < _screen_width + _point_o.X)
		{
			bird_index = i;
			if (bird_index_min == -1)
			{
				bird_index_min = i;
			}

		}
		if (alldie)
		{
			indexmin = i;
		}
		if (indexmin == -1)
		{
			indexmin = i;
			continue;
		}
		alldie = false;
		if (bird)
		{
			if (bird_index >= 0)
			{

				if (_enemy[bird_index_min].GetPosX() > _enemy[bird_index].GetPosX())
				{
					bird_index_min = bird_index;
				}
				indexmin = bird_index_min;
			}
			else
			{
				if (_enemy[indexmin].GetPosX() > _enemy[i].GetPosX())
				{
					indexmin = i;
				}
			}
		}
		else
		{
			if (_enemy[indexmin].GetPosX() > _enemy[i].GetPosX())
			{
				indexmin = i;
			}
		}

	}
	if (!alldie && indexmin == -1)
	{
		for (int i = 0; i < _num_enemy_inwave; i++)
		{
			if (!_enemy[i].HasAvailable())
			{
				_enemy[i]._count_frame_repawn = _enemy[i].GetTimeRespawn();
				break;
			}
			else
			{
				if (_enemy[i].IsLive())
				{
					break;
				}
			}
		}
	}
	
	if (alldie && indexmin == -1)
	{
		if (_boss_reward._state == EFFECT_REWARD_JUMP_STATE_NONE)
		{
			_wave_current++;
			

			if (_wave_current > NUM_WAVE_INBATTLE)
			{

				if (_battle_current < NUM_MAX_BATTLE - 1)
				{
					_user._has_completed_battle_max = false;
				}
				_victory_active = true;
				if (!_user._has_completed_battle_max)
				{
					_battle_current++;
					_user.ActiveIapPackDiscount(false);
				}

                _hight_score = _battle_current+1;
                _new_hight_score = true;
				if (!_user._daily_quest_completed)
				{
					DailyQuestAdd(DAILY_QUEST_GROUP_BATTLE_FINISH);
				}
				_bg_change_music = true;
				UnlockNewHero(HEROES_UNLOCK_TYPE_NORMAL);
				_wave_current = 1;
				_user.UserDataSave();
#if defined (ANDROID_OS)
				//if (GAME()->_async_task_manager._is_login_google)
				{
					TDGame *game = (TDGame*)GAME()->_current_game;
					GAME()->_gameBoardScoreItem.Score = game->_battle_current + 1;
					GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_POST_SCORE);
				}
#endif
				VictoryReInit();
				if (_castle.GetHP() < _castle._hp_max/2)
				{
					_just_lose = true;
				}
				ResetFlagNotifyNew(_just_lose);
				if (_user._tutorial_step == TUTORIAL_STEP_MENU_RELIC)
				{
					if (_battle_current >= 10)
					{
						_tutorial_buy_relic_ready = true;

					}
				}
			}
			if (!_victory_active)
			{
				_has_revive_in_battle = false;
				InitBattle(_battle_current, _wave_current);
			}
		}
		else
		{
			if (_boss_reward._state == EFFECT_REWARD_JUMP_STATE_HOLDING)
			{
				_boss_reward.SetState(EFFECT_REWARD_JUMP_STATE_OPENNING);
			}
		}
	}
	if (indexmin != -1)
	{
		if (!_enemy[indexmin].IsLive())
		{
			indexmin = -1;
		}
	}
	
	return indexmin;
}

int TDGame::GetEnemyIndexHPLower()
{
	int indexmin = -1;
	bool alldie = true;
	int bird_index = -1;
	int index_pos_min = -1;
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		int enemy_state = _enemy[i].GetState();
		//if (enemy_state == CHARACTER_STATE_DIE_END)
		if (!_enemy[i].IsLive() && enemy_state != CHARACTER_STATE_DIE_START)
		{
			continue;
		}
		if (enemy_state == CHARACTER_STATE_DIE_START || _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_WEAPON
			|| _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_HERO || !_enemy[i].HasAvailable())
		{
			alldie = false;
			continue;
		}
		if (_enemy[i].GetPosX() >= _screen_width + _point_o.X)
		{
			continue;
		}
		if (indexmin == -1)
		{
			indexmin = i;
			index_pos_min = i;
			continue;
		}
		int sprite = _enemy[i].GetSprite();
		//if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status < CHARACTER_STATUS_RUNAWAY) && enemy_state < CHARACTER_STATE_DIE && _enemy[i].GetPosX() < _screen_width + _point_o.X)
		if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status < CHARACTER_STATUS_RUNAWAY) && _enemy[i].IsLive() && _enemy[i].GetPosX() < _screen_width + _point_o.X)
		{
			bird_index = i;
		}
		alldie = false;
		
		if (bird_index >= 0)
		{
			if (_enemy[indexmin]._hp_max > _enemy[bird_index]._hp_max)
			{
				indexmin = bird_index;
			}
			else if (_enemy[indexmin]._hp_max == _enemy[bird_index]._hp_max)
			{
				if (_enemy[index_pos_min].GetPosX() > _enemy[bird_index].GetPosX())
				{
					index_pos_min = bird_index;
					indexmin = index_pos_min;
				}
			}
			//printf("\n _enemy[i]._status = %d", _enemy[i]._status);
		}
		else
		{
			if (_enemy[indexmin]._hp_max > _enemy[i]._hp_max)
			{
				indexmin = i;
			}
			else if (_enemy[indexmin]._hp_max == _enemy[i]._hp_max)
			{
				if (_enemy[index_pos_min].GetPosX() > _enemy[i].GetPosX())
				{
					index_pos_min = i;
					indexmin = index_pos_min;
				}
			}
		}
	}
	
	if (indexmin != -1)
	{
		//if (_enemy[indexmin].GetState() >= CHARACTER_STATE_DIE)
		if (!_enemy[indexmin].IsLive())
		{
			indexmin = -1;
		}
		/*if (_enemy[bird_index].GetState() < CHARACTER_STATE_DIE && bird_index != -1)
		{
			indexmin = bird_index;
		}*/
	}
	return indexmin;
}
int TDGame::GetEnemyIndexHPUpper()
{
	int indexmax = -1;
	bool alldie = true;
	int bird_index = -1;
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		int enemy_state = _enemy[i].GetState();
		//if (enemy_state == CHARACTER_STATE_DIE)
		if (!_enemy[i].IsLive() && enemy_state != CHARACTER_STATE_DIE_START)
		{
			continue;
		}
		if (enemy_state == CHARACTER_STATE_DIE_START || _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_WEAPON 
			|| _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_HERO || !_enemy[i].HasAvailable())
		{
			alldie = false;
			continue;
		}
		if (_enemy[i].GetPosX() >= _screen_width + _point_o.X)
		{
			continue;
		}
		if (indexmax == -1)
		{
			indexmax = i;
			continue;
		}
		int sprite = _enemy[i].GetSprite();
		//if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status < CHARACTER_STATUS_RUNAWAY) && enemy_state < CHARACTER_STATE_DIE && _enemy[i].GetPosX() < _screen_width + _point_o.X)
		if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status < CHARACTER_STATUS_RUNAWAY) && _enemy[i].IsLive() && _enemy[i].GetPosX() < _screen_width + _point_o.X)
		{
			bird_index = i;
		}
		alldie = false;
		if (_enemy[indexmax]._hp_max < _enemy[i]._hp_max)
		{
			indexmax = i;
		}
	}

	if (indexmax != -1)
	{
		//if (_enemy[indexmax].GetState() >= CHARACTER_STATE_DIE)
		if (!_enemy[indexmax].IsLive())
		{
			indexmax = -1;
		}
		else
		{
			if (bird_index != -1)
			{
				indexmax = bird_index;
			}
		}
		
	}
	return indexmax;
}
int TDGame::GetEnemyIndexRandom(int index)
{
	int indexmin = 0;
	bool alldie = true;
	for (int i = 0; i < _num_enemy_inwave; i++)
	{
		//if (_enemy[i].GetState() >= CHARACTER_STATE_DIE || i == index || _enemy[i].GetPosX() >= _screen_width + _point_o.X)
		if (!_enemy[i].IsLive() || i == index || _enemy[i].GetPosX() >= _screen_width + _point_o.X)
		{
			continue;
		}
		/*if (_enemy[i].GetSprite() == SPRITEID_MONSTER_FLYING || (_enemy[i].GetPosY() <= ROAD_POSY - 20 && _enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING)
			|| _enemy[i]._be_skill_id == BE_SKILL_BURN)*/
		if ((_enemy[i]._status >= CHARACTER_STATUS_FLY && _enemy[i]._status <= CHARACTER_STATUS_RUNAWAY)
			|| _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_WEAPON || _enemy[i]._be_skill_id == BE_SKILL_BURN_BY_HERO
			|| !_enemy[i].HasAvailable())
		{
			continue;
		}
		if (alldie)
		{
			indexmin = i;
		}
		alldie = false;
	}
	if (alldie)
	{
		indexmin = -1;
	}
	else
	{
		int rand_index = CMath::RANDOM(0, _num_enemy_inwave-1);
		/*while (_enemy[rand_index].GetState() >= CHARACTER_STATE_DIE || rand_index == index || _enemy[rand_index].GetPosX() >= _screen_width + _point_o.X ||
			(_enemy[rand_index]._status >= CHARACTER_STATUS_FLY && _enemy[rand_index]._status <= CHARACTER_STATUS_RUNAWAY))*/
		while (!_enemy[rand_index].IsLive() || rand_index == index || _enemy[rand_index].GetPosX() >= _screen_width + _point_o.X ||
		(_enemy[rand_index]._status >= CHARACTER_STATUS_FLY && _enemy[rand_index]._status <= CHARACTER_STATUS_RUNAWAY))
		{
			rand_index = CMath::RANDOM(0, _num_enemy_inwave-1);
		}
		indexmin = rand_index;
	}
	return indexmin;
}
void TDGame::LoadSpriteOptimize(int sprite,bool alias,bool color)
{
	GAME()->LoadSpriteCurrentVer(sprite,alias,color);
}
void TDGame::HeroButton::Init(float x, float y, int herosprite, int heroid, float poweratt, float powerskill, float limitbreak)
{
	int cliph_att = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(32);
	int cliph_skill = 110;
	_x = x;
	_y = y;
	_hero_sprite = herosprite;
	_heroID = heroid;
	_clip_pa_target = (int)((poweratt / (MAX_POWER_NUM_TAP*1.0f))*cliph_att);
	_clip_pa_current = _clip_pa_target;
	_clip_ps_target = (int)((powerskill / (limitbreak*1.0f))*cliph_skill);
	_clip_ps_current = _clip_ps_target;
	_active = false;
	_effect_zoom_scale = 1.0f;
	_anim.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
	_anim.SetAnim(77, false);
	_anim.SetPos(_x, _y);
	_auto_attack = false;
	for (int i = 0; i < NUM_MAX_EFFECT_MOON; i++)
	{
		_effect_moon[i].Init(SPRITEID_HUD_MAINMENU, 83, 0, 0, 10, 10, 200);
	}
	_speed_ps_clip = 0;
	_full_power_effect_fire.Init(SPRITEID_HUD_MAINMENU, 84,1, 30,0, true,1.5f);
	_full_power_skill_fire.Init(SPRITEID_HUD_MAINMENU, 84, 1, 90, 0, false, 1.5f);
	_effect_full_ps_scale = 1.0f;
	_effect_full_ps_scale_start = false;
	_effect_full_ps_scale_max = false;
	_effect_full_skill_rotate = 0;
	_is_use_auto_att = -1;
	_is_use_auto_skill = -1;
}

void TDGame::HeroButton::Modify(int herosprite, int heroid, float poweratt, float powerskill, float limitbreak)
{
	int cliph_att = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(32);
	int cliph_skill = 110;
	_hero_sprite = herosprite;
	_heroID = heroid;
	
	_clip_pa_target = (int)((poweratt / (MAX_POWER_NUM_TAP*1.0f))*cliph_att);
	_clip_pa_current = _clip_pa_target;
	_clip_ps_target = (int)((powerskill / (limitbreak*1.0f))*cliph_skill);
	_clip_ps_current = _clip_ps_target;
	_active = false;
	_effect_zoom_scale = 1.0f;
	_auto_attack = false;
	_speed_ps_clip = 0;
	_effect_full_ps_scale = 1.0f;
	_effect_full_ps_scale_start = false;
	_effect_full_ps_scale_max = false;
	_effect_active_ps_scale_start = false;
	_is_use_auto_att = -1;
	_is_use_auto_skill = -1;
}
void TDGame::HeroButton::RenderSkill(float x, float y, int opacity)
{
    G()->SetOpacity(opacity);
	
    TDGame *game = (TDGame*)GAME()->_current_game;
    if (_heroID >= 0 && (game->_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT || game->_user._tutorial_completed))
    {
        G()->SetScale(_effect_full_ps_scale, _effect_full_ps_scale, _x, 815 + y);
        GET_SPRITE(_hero_sprite)->DrawFrame(G(), 3, _x + x, 815 + y);
        int clipy = 815 + 55;
        int cliph_skill = 110;
        if (_clip_ps_current < cliph_skill)
        {
            G()->SetClip(0 + x, clipy - _clip_ps_current + y, game->_screen_width, _clip_ps_current);
        }
        GET_SPRITE(_hero_sprite)->DrawFrame(G(), 2, _x + x, 815 + y );
        
        G()->ClearScale();
        float scale = CMath::ABSOLUTE_VALUE(55 - _clip_ps_current) / 55.0f;
        G()->SetScale(1 - scale*scale*scale, 1 - scale*scale*scale, _x + x, clipy - _clip_ps_current + y);
        GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 86, _x + x, clipy - _clip_ps_current + y);
        G()->ClearScale();
        G()->ClearClip();
        _full_power_effect_fire.Render(0, 0, opacity);
    }
	G()->SetOpacity(opacity);
}
void TDGame::HeroButton::Render(float x, float y, int opac)
{

    G()->SetOpacity(opac);
	TDGame *game = (TDGame*)GAME()->_current_game;
	G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
    if (_heroID >= 0)
    {
        for (int i = 0; i < NUM_MAX_EFFECT_MOON; i++)
        {
            _effect_moon[i].Render(_x + x, _y + y, opac);
        }
    }
	G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
	//_anim.SetPos(_x + x, _y + y);
    //printf("\n _hero_sprite = %d,_heroID = %d",_hero_sprite,_heroID);
	G()->SetScale(_effect_zoom_scale, _effect_zoom_scale, _x + x, _y + y);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 48, _x + x, _y + y);
	if (_heroID >= 0 && (game->_user._tutorial_step >= TUTORIAL_STEP_TAP_ATT || game->_user._tutorial_completed))
	{
		GET_SPRITE(_hero_sprite)->DrawFrame(G(), 0, _x + x, _y + y);
	}
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 49, _x + x, _y + y);
	if (_active)
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 52, _x + x, _y + y);
	}
	//_anim.DrawAnimObject(G());
    /*
    if(_auto_attack)
    {
        G()->SetOpacity(100);
        
        GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224, _x, _y);
        
    }*/
	G()->ClearScale();
  

}

void TDGame::HeroButton::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_heroID == -1)
	{
		return;
	}
	
	int cliph_att = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(32);
	int cliph_skill = 110;
	//printf("\n cliph = %d", cliph);
	for (int j = 0; j < NUM_MAX_HERO; j++)
	{
		if (game->_user._hero_arr[j]._heroid >= 0)
		{
			int index_inbattle = game->CheckHeroIDInBattle(game->_user._hero_arr[j]._heroid);
			if (index_inbattle >= 0 && game->_hero_inbattle_arr[index_inbattle].GetHeroID() == _heroID)
			{
				bool pw_att_reset = false;
				bool pw_skill_reset = false;
				if (_is_use_auto_att != -1 && game->_hero_inbattle_arr[index_inbattle].GetPowerAttack() <= 0)
				{
					pw_att_reset = true;
					game->_hero_inbattle_arr[index_inbattle].AddPowerAttack(game->_hero_inbattle_arr[index_inbattle]._power_att_catch);
				}
				_auto_attack = game->_hero_inbattle_arr[index_inbattle]._is_auto_attack;
				_clip_pa_target = (int)((game->_hero_inbattle_arr[index_inbattle].GetPowerAttack() / (MAX_POWER_NUM_TAP*1.0f))*cliph_att);
				if (_clip_pa_target >= cliph_att)
				{
					_clip_pa_target = cliph_att;
				}
				
				_clip_ps_target = (int)((game->_hero_inbattle_arr[index_inbattle].GetPowerSkill() / (game->_hero_inbattle_arr[index_inbattle].GetLimitBreak()*1.0f))*cliph_skill);
				int skill = game->_hero_inbattle_arr[index_inbattle]._skill.GetID();
				int duration = game->_hero_inbattle_arr[index_inbattle]._skill.GetDurarion();
				_speed_ps_clip = 5;
				if (_is_use_auto_skill != -1 && _clip_ps_current <= 0 && _clip_ps_target <= 0)
				{
					pw_skill_reset = true;
					game->_hero_inbattle_arr[index_inbattle].AddPowerSkill(game->_hero_inbattle_arr[index_inbattle]._power_skill_catch);
				}
				if (/*skill == HERO_SKILL_GREATCLASH ||*/ skill == HERO_SKILL_WOLF_RANGER)
				{
					if (_clip_ps_target == 0 && _clip_ps_current != 0)
					{
						_speed_ps_clip = cliph_skill / (duration* 1.0f);
					}
				}
				if (pw_skill_reset)
				{
					_is_use_auto_skill = -1;
					_clip_ps_current = _clip_ps_target;
				}
				if (_clip_ps_target >= cliph_skill)
				{
					_clip_ps_target = cliph_skill;
				}
				if (pw_att_reset)
				{
					_is_use_auto_att = -1;
					_effect_hight_light_opac = 100;
					_clip_pa_current = _clip_pa_target;
					_auto_attack = false;
				}
			}
		}
	}

	//printf("\n _clip_pa_target = %d", _clip_pa_target);
	if (_clip_pa_target != _clip_pa_current)
	{
		if (_clip_pa_target > _clip_pa_current)
		{
			if (_is_use_auto_att != -1)
			{
				_clip_pa_current+=10;
			}
			else
			{
				_clip_pa_current++;
			}
			
			if (_clip_pa_current >= _clip_pa_target)
			{
				_clip_pa_current = _clip_pa_target;
			}
		}
		else if (_clip_pa_current > _clip_pa_target)
		{
			_clip_pa_current-=3;
			if (_clip_pa_current <= _clip_pa_target)
			{
				_clip_pa_current = _clip_pa_target;
			}
		}
	}
	if (_clip_ps_target != _clip_ps_current)
	{
		if (_clip_ps_target > _clip_ps_current)
		{
			_speed_ps_clip = 1;
			if (_is_use_auto_skill != -1 || (!game->_user._tutorial_completed && game->_tutorial_step == TUTORIAL_STEP_USE_SKILL))
			{
				_clip_ps_current += 4;
			}
			else
			{
				_clip_ps_current += _speed_ps_clip;
			}
			
			if (_clip_ps_current >= _clip_ps_target)
			{
				_clip_ps_current = _clip_ps_target;
				if (_clip_ps_current >= cliph_skill)
				{
					_effect_full_ps_scale_start = true;
					_effect_full_skill_rotate = 0;
				}
			}
		}
		else if (_clip_ps_current > _clip_ps_target)
		{
			_clip_ps_current -= _speed_ps_clip;
			if (_clip_ps_current <= _clip_ps_target)
			{
				_clip_ps_current = _clip_ps_target;
			}
			//if (_is_use_auto_skill != -1)
			//{
			//	_is_use_auto_skill = -1;
			//	//_effect_hight_light_opac = 100;
			//}
		}
	}
	if (_clip_ps_current >= cliph_skill)
	{
		_full_ps = true;
	}
	else
	{
		_full_ps = false;
	}
	if (_clip_pa_current >= cliph_att)
	{
		_full_pa = true;
		if (_effect_hight_light_opac_max)
		{
			_effect_hight_light_opac -= 2;
			if (_effect_hight_light_opac <= 20)
			{
				_effect_hight_light_opac = 20;
				_effect_hight_light_opac_max = false;
			}
		}
		else
		{
			_effect_hight_light_opac += 2;
			if (_effect_hight_light_opac >= 100)
			{
				_effect_hight_light_opac = 100;
				_effect_hight_light_opac_max = true;
			}
		}
	}
	else
	{
		if (_effect_hight_light_opac > 0)
		{
			_effect_hight_light_opac -= 10;
		}
		if (_effect_hight_light_opac <= 0)
		{
			_effect_hight_light_opac = 0;
		}
		_effect_hight_light_opac_max = false;
		_full_pa = false;
	}
	if (_active)
	{
		_effect_zoom_scale -= 0.05f;
		if (_effect_zoom_scale <= 0.7f)
		{
			_active = false;
			_effect_zoom_scale = 1.0f;
		}
	}
	for (int i = 0; i < NUM_MAX_EFFECT_MOON; i++)
	{
		_effect_moon[i].Update();
	}
	if (_effect_full_ps_scale_start && _is_use_auto_skill != -1)
	{
		if (!_effect_full_ps_scale_max)
		{
			if (_effect_full_ps_scale < 1.5f)
			{
				_effect_full_ps_scale += 0.08;
				if (_effect_full_ps_scale >= 1.5f)
				{
					_effect_full_ps_scale_max = true;
				}
			}
		}
		else
		{
			if (_effect_full_ps_scale >1.0f)
			{
				_effect_full_ps_scale -= 0.1;
				if (_effect_full_ps_scale <= 1.0f)
				{
					_effect_full_ps_scale_max = false;
					_effect_full_ps_scale_start = false;
				}
			}
		}
	}
	/*else
	{
		if (_effect_active_ps_scale_start)
		{
			if (!_effect_full_ps_scale_max)
			{
				if (_effect_full_ps_scale > 0.9f)
				{
					_effect_full_ps_scale += 0.05;
					if (_effect_full_ps_scale <= 0.9f)
					{
						_effect_full_ps_scale_max = true;
					}
				}
			}
			else
			{
				if (_effect_full_ps_scale < 1.0f)
				{
					_effect_full_ps_scale += 0.5f;
					if (_effect_full_ps_scale >= 1.0f)
					{
						_effect_full_ps_scale_max = false;
						_effect_active_ps_scale_start = false;
					}
				}
			}
		}
	}*/
	_effect_full_skill_rotate += 6;
	if (_effect_full_skill_rotate>=360)
	{
		_effect_full_skill_rotate -= 360;
	}
	_anim.UpdateAnimObject();
	_full_power_effect_fire.Update();
	_full_power_skill_fire.Update();
}

void TDGame::HeroButton::AddEffect()
{
	for (int i = 0; i < NUM_MAX_EFFECT_MOON; i++)
	{
		if (_effect_moon[i]._state == 0)
		{
			_effect_moon[i].Add(0, 0, 0);
			break;
		}
	}
}

void TDGame::AddEffectHPLost(INT_TIME damage, float x, float y, int damagetype)
{
	if (_num_effect_hp_lost >= NUM_EFFECT_HP_LOST)
	{
		RemoveEffectHPLost(0);
	}
	_effect_hp_lost[_num_effect_hp_lost]._damage = damage;
	_effect_hp_lost[_num_effect_hp_lost]._x = x;
	_effect_hp_lost[_num_effect_hp_lost]._y = y;
	_effect_hp_lost[_num_effect_hp_lost]._damage_type = damagetype;
	_effect_hp_lost[_num_effect_hp_lost]._count_frame = 0;
	_effect_hp_lost[_num_effect_hp_lost]._opac = 140;
	_effect_hp_lost[_num_effect_hp_lost]._scale = 1.0f;
	if (damagetype == EFFECT_HP_LOST_TYPE_CRITICAL)
	{
		_effect_hp_lost[_num_effect_hp_lost]._opac = 100;
		_effect_hp_lost[_num_effect_hp_lost]._scale = 0.0f;
	}
	_num_effect_hp_lost++;
}
void TDGame::RenderEffectHPLost()
{
	for (int i = 0; i < _num_effect_hp_lost; i++)
	{
		if (_effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_NORMAL || _effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_CASTLE)
		{
			
			int sprite_font = SPRITEID_FONT_HITDAME;
			if (_effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_CASTLE)
			{
				sprite_font = SPRITEID_FONT_HITDAME_CASTLE;
			}
			G()->SetOpacity(_effect_hp_lost[i]._opac);
			int char_space = GET_SPRITE(sprite_font)->_char_spacing;
			GET_SPRITE(sprite_font)->_char_spacing = 0;
			//G()->SetScale(0.75f, 0.75f, _effect_hp_lost[i]._x, _effect_hp_lost[i]._y);
			GET_SPRITE(sprite_font)->DrawAnsiTextFormat(G(), _effect_hp_lost[i]._x, _effect_hp_lost[i]._y, _HCENTER, "%lld", _effect_hp_lost[i]._damage);
			//G()->ClearScale();
			GET_SPRITE(sprite_font)->_char_spacing = char_space;
			G()->SetOpacity(100);
		}
	}
	for (int i = 0; i < _num_effect_hp_lost; i++)
	{
		if (_effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_CRITICAL)
		{
			G()->SetScale(_effect_hp_lost[i]._scale, _effect_hp_lost[i]._scale, _effect_hp_lost[i]._x, _effect_hp_lost[i]._y);
			G()->SetOpacity(_effect_hp_lost[i]._opac);
			int char_space = GET_SPRITE(SPRITEID_FONT_CRITICALDAME)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_CRITICALDAME)->_char_spacing = 0;
			GET_SPRITE(SPRITEID_FONT_CRITICALDAME)->DrawAnsiTextFormat(G(), _effect_hp_lost[i]._x, _effect_hp_lost[i]._y - 35, _HCENTER, ":");
			GET_SPRITE(SPRITEID_FONT_CRITICALDAME)->DrawAnsiTextFormat(G(), _effect_hp_lost[i]._x, _effect_hp_lost[i]._y, _HCENTER, "%lld", _effect_hp_lost[i]._damage);
			GET_SPRITE(SPRITEID_FONT_CRITICALDAME)->_char_spacing = char_space;
			G()->SetOpacity(100);
			G()->ClearScale();
		}
	}
}

void TDGame::UpdateEffectHpLost()
{
	for (int i = 0; i < _num_effect_hp_lost; i++)
	{
		if (_effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_NORMAL || _effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_CASTLE)
		{
			_effect_hp_lost[i]._count_frame+=2;
			if (_effect_hp_lost[i]._count_frame >= 35)
			{
				_effect_hp_lost[i]._opac -= 20;
			}
			if (_effect_hp_lost[i]._count_frame < 15)
			{
				_effect_hp_lost[i]._y -= 4;
			}
			if (_effect_hp_lost[i]._opac <= 0)
			{
				_effect_hp_lost[i]._opac = 0;
				RemoveEffectHPLost(i);
			}
			_effect_hp_lost[i]._y -= 2;
		}
		else if (_effect_hp_lost[i]._damage_type == EFFECT_HP_LOST_TYPE_CRITICAL)
		{
			_effect_hp_lost[i]._scale += 0.15f;
			if (_effect_hp_lost[i]._scale >= 1.0f)
			{
				if (_effect_hp_lost[i]._scale >= 1.0f)
				{
					_effect_hp_lost[i]._scale = 1.0f;
				}
				_effect_hp_lost[i]._count_frame+=2;
				if (_effect_hp_lost[i]._count_frame >= 45)
				{
					_effect_hp_lost[i]._opac -= 20;
					/*_effect_hp_lost[i]._scale -= 0.1;
					if (_effect_hp_lost[i]._scale <= 1.0f)
					{
						_effect_hp_lost[i]._scale = 1.0f;
					}*/
				}
				if (_effect_hp_lost[i]._count_frame < 15)
				{
					_effect_hp_lost[i]._y -= 4;
				}
				if (_effect_hp_lost[i]._opac <= 0)
				{
					_effect_hp_lost[i]._opac = 0;
					RemoveEffectHPLost(i);
				}
			}
			else
			{
				_effect_hp_lost[i]._opac += 10;
			}
			//printf("\n _effect_hp_lost[%d]._opac = %d --- scale = %f", i,_effect_hp_lost[i]._opac, _effect_hp_lost[i]._scale);
			_effect_hp_lost[i]._y -= 2;
		}
	}
}

void TDGame::RemoveEffectHPLost(int index)
{
	for (int i = index; i < _num_effect_hp_lost - 1; i++)
	{
		_effect_hp_lost[i]._damage = _effect_hp_lost[i + 1]._damage;
		_effect_hp_lost[i]._x = _effect_hp_lost[i + 1]._x;
		_effect_hp_lost[i]._y = _effect_hp_lost[i + 1]._y;
		_effect_hp_lost[i]._damage_type = _effect_hp_lost[i + 1]._damage_type;
		_effect_hp_lost[i]._count_frame = _effect_hp_lost[i + 1]._count_frame;
		_effect_hp_lost[i]._opac = _effect_hp_lost[i + 1]._opac;
		_effect_hp_lost[i]._scale = _effect_hp_lost[i + 1]._scale;
	}
	_effect_hp_lost[_num_effect_hp_lost - 1]._damage = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._x = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._y = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._damage_type = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._count_frame = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._opac = 0;
	_effect_hp_lost[_num_effect_hp_lost - 1]._scale = 0;
	_num_effect_hp_lost--;
	if (_num_effect_hp_lost <= 0)
	{
		_num_effect_hp_lost = 0;
	}
}
void TDGame::EffectScrollMoon::Init(int sprite, int frame, float x, float y, float speedscroll, float speedopac, int maxtary)
{
	_spriteid = sprite;
	_frameid = frame;
	_x = x;
	_y = y;
	_speed_scroll = speedscroll;
	_speed_opac = speedopac;
	_state = 0;
	_opac = 100;
	_max_target_y = maxtary;
}
void TDGame::EffectScrollMoon::Add(float x, float y, int opac)
{
	_x = x;
	_y = y;
	_opac = opac;
	_state = 1;
}
void TDGame::EffectScrollMoon::Render(float x, float y, int opac)
{
	if (_state == 0)
	{
		return;
	}
	G()->SetOpacity(_opac);
	GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, -_y + y);
	G()->SetOpacity(opac);
}
void TDGame::EffectScrollMoon::Update()
{
	if (_state == 0)
	{
		return;
	}
	if (_y < _max_target_y)
	{
		_y += _speed_scroll;
		if (_opac < 100)
		{
			_opac += _speed_opac;
			if (_opac >= 100)
			{
				_opac = 100;
			}
		}
	}
	else
	{
		_y = _max_target_y;
		if (_opac > 0)
		{
			_opac -= _speed_opac;
		}
		else
		{
			_state = 0;
		}
	}
}

void TDGame::TouchEffectFireInit()
{
	for (int i = 0; i < NUM_MAX_EFFECT_TOUCH_FIRE; i++)
	{
		_touch_effect_fire[i].Init(SPRITEID_HUD_MAINMENU, 84, 1, 15, 0, false, 1.5f);
	}
}
void TDGame::TouchEffectFireRender(float x, float y, int opac)
{
	for (int i = 0; i < NUM_MAX_EFFECT_TOUCH_FIRE; i++)
	{
		_touch_effect_fire[i].Render(x, y, opac);
	}
}
void TDGame::TouchEffectFireUpdate()
{
	for (int i = 0; i < NUM_MAX_EFFECT_TOUCH_FIRE; i++)
	{
		_touch_effect_fire[i].Update();
	}
}
void TDGame::TouchEffectFireAdd(float x, float y)
{
	for (int i = 0; i < NUM_MAX_EFFECT_TOUCH_FIRE; i++)
	{
		if (_touch_effect_fire[i].IsFree())
		{
			_touch_effect_fire[i].Active(x, y, 5, 5, 1, 0, 1.0f, 50);
			break;
		}
	}
}
void TDGame::StarAnim::Init(float x, float y, int sprite, int frame, float scalemax, int holdframe)
{
	_state = 0;
	_x = x;
	_y = y;
	_spriteid = sprite;
	_frameid = frame;
	_scale_max = scalemax;
	_hold_frame = holdframe;
	_is_scale_max = false;
	_count_frame_hold = 0;
	_scale = 0;
	_rotate = 0;
}
void TDGame::StarAnim::Active(float x, float y, float speedscale, float speedrotate)
{
	_state = 1;
	_x = x;
	_y = y;
	_speed_scale = speedscale;
	_speed_rotate = speedrotate;
}
void TDGame::StarAnim::Render(float x, float y)
{
	if (_state == 0)
	{
		return;
	}
	G()->SetScale(_scale, _scale, _x + x, _y + y);
	G()->SetRotate(_rotate, _x + x, _y + y);
	GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
	G()->ClearRotate();
	G()->ClearScale();
}
void TDGame::StarAnim::Update()
{
	if (_state == 0)
	{
		return;
	}
	_rotate += _speed_rotate;
	if (_rotate >= 360)
	{
		_rotate -= 360;
	}
	if (_is_scale_max)
	{
		if (_count_frame_hold < _hold_frame)
		{
			_count_frame_hold++;
		}
		else
		{
			_scale -= _speed_scale;
			if (_scale <= 0)
			{
				_scale = 0;
				_is_scale_max = false;
				_count_frame_hold = 0;
			}
		}
		
	}
	else
	{
		if (_count_frame_hold < _hold_frame)
		{
			_count_frame_hold++;
		}
		else
		{
			_scale += _speed_scale;
			if (_scale >= _scale_max)
			{
				_is_scale_max = true;
				_count_frame_hold = _hold_frame;
			}
		}
	}
}
void TDGame::StarAnim::Disable()
{
	_state = 0;
}
void TDGame::StarAnimInit()
{
	for (int i = 0; i < NUM_MAX_EFFECT_STAR_ANIM; i++)
	{
		int frame = CMath::RANDOM(0, 1);
		int holdframe = CMath::RANDOM(60, 180);
		float maxscale = CMath::RANDOM(15, 22)/10.0f;
		_effect_star_anim[i].Init(0, 0, SPRITEID_HUD_MAINMENU, 84 + frame, maxscale, holdframe);
	}
}
void TDGame::StarAnimRender(float x, float y)
{
	for (int i = 0; i < NUM_MAX_EFFECT_STAR_ANIM; i++)
	{
		_effect_star_anim[i].Render(x, y);
	}
}
void TDGame::StarAnimUpdate()
{
	for (int i = 0; i < NUM_MAX_EFFECT_STAR_ANIM; i++)
	{
		_effect_star_anim[i].Update();
	}
}
void TDGame::StarAnimActive(int index, float x, float y, float speedscale, float speedrotate)
{
	_effect_star_anim[index].Active(x, y, speedscale, speedrotate);
}

void TDGame::StarAnimDisable(int index)
{
	_effect_star_anim[index].Disable();
}

void TDGame::IapRender(float x, float y)
{
	for (int i = 0; i < NUM_BUTTON_IAP; i++)
	{
		if (i == IAP_BUTTON_COIN)
		{
			int posx = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(0, 0);
			int posy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
			if (_iap_button[i]._state != BUTTON_STATE_LOCK)
			{
				_iap_button[i].SetState(BUTTON_STATE_LOCK);
			}
			
			G()->SetScale(_effect_scale_icon_coin, _effect_scale_icon_coin, posx + x, posy + y);
		}
		_iap_button[i].SetPos(x, y);
		_iap_button[i].Render(G());
		_iap_button[i].Update();
		if (i == IAP_BUTTON_COIN)
		{
			G()->ClearScale();
		}
	}
	int mky = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
	int spacing = GET_SPRITE(SPRITEID_FONT_COIN_GEM)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_COIN_GEM)->_char_spacing = -2;
	int mkx_c = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleX(0, 0);
	int mkx_g = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleX(4, 0);
	_coin_interface.Render(x + mkx_c - 5, y + mky + 10, _RIGHT);
	_coin_interface.Update();
	//GET_SPRITE(SPRITEID_FONT_COIN_GEM)->DrawAnsiTextFormat(G(), x + 82, y + mky + 10, _LEFT, "%d", _ingame_coin);
	mky = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(4, 0);
	GET_SPRITE(SPRITEID_FONT_COIN_GEM)->DrawAnsiTextFormat(G(), x + mkx_g - 12, y + mky + 10, _RIGHT, "%s", _user._gem_text);
	GET_SPRITE(SPRITEID_FONT_COIN_GEM)->_char_spacing = spacing;

}
void TDGame::IapUpdate()
{
	if (_effect_scale_icon_coin_start)
	{
		_effect_scale_icon_coin += 0.1;
		if (_effect_scale_icon_coin >= 1.5)
		{
			_effect_scale_icon_coin_start = false;
			_effect_scale_icon_coin = 1;
		}
	}
	if (_effect_scale_icon_gem_start)
	{
		_effect_scale_icon_gem += 0.1;
		if (_effect_scale_icon_gem >= 1.5)
		{
			_effect_scale_icon_gem_start = false;
			_effect_scale_icon_gem = 1;
		}
	}
	IapUpdateTouch();
}
void TDGame::IapInit()
{
	for (int i = 0; i < NUM_BUTTON_IAP; i++)
	{
		_iap_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_iap_button[i].SetAnim(SPRITEID_HUD_MAINMENU, i * 4);
		_iap_button[i].SetPos(0, 0);
	}
	_effect_scale_icon_coin_start = false;
	_effect_scale_icon_gem_start = false;
	_effect_scale_icon_coin = 1.0f;
	_effect_scale_icon_gem = 1.0f;
	
}
bool TDGame::IapUpdateTouch()
{
	if (!_user._tutorial_completed)
	{
		return false;
	}
	bool ret = false;
	int index = -1;
	for (int i = 0; i < NUM_BUTTON_IAP; i++)
	{
		if (_iap_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_iap_button[index].NeedAction())
		{
			//printf("\n index iap = %d ", index);
			switch (index)
			{
			case IAP_BUTTON_COIN:
				_ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
				SetState(k_GS_INGAME_MENU);
				break;
			case IAP_BUTTON_GEM:
				_ingame_menu_type = MENU_INGAME_BUTTON_SHOP;
				SetState(k_GS_INGAME_MENU);
				break;
			default:
				break;
			}
			for (int i = 0; i < NUM_BUTTON_IAP; i++)
			{
				if (_iap_button[i]._state != BUTTON_STATE_LOCK && _iap_button[i]._state != BUTTON_STATE_HIDE)
				{
					_iap_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < NUM_BUTTON_IAP; touch++)
		{
			if (_iap_button[touch]._state == BUTTON_STATE_LOCK || _iap_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _iap_button[touch].TZ_GetX();
			int y = _iap_button[touch].TZ_GetY();
			int w = _iap_button[touch].TZ_GetWidth();
			int h = _iap_button[touch].TZ_GetHeight();
			Button *button = &_iap_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}

				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
					}
				}
				if (button->_touch_id != -1)
				{
					pressed = true;
				}
			}
			else
			{

				if (button->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}

			}
		}
	}
	return pressed;
}
void TDGame::EffectHeroSkillInit()
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		_effect_hero_skill_state[i] = 1;
		_effect_hero_skill_id[i] = -1;
		_effect_hero_skill_scale[i] = 1.0f;
	}
}
void TDGame::EffectHeroSkillActive(int skillid)
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_effect_hero_skill_id[i] == -1)
		{
			_effect_hero_skill_id[i] = skillid;
			_effect_hero_skill_state[i] = 0;
			break;
		}
	}
}
void TDGame::EffectHeroSkillUpdate()
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_effect_hero_skill_state[i] == -1)
		{
			continue;
		}
		switch (_effect_hero_skill_id[i])
		{
		case HERO_SKILL_GREATCLASH:
			/*if (_effect_hero_skill_state[i] != 1)
			{
				if (_effect_hero_skill_scale[i] < 1.5f)
				{
					_effect_hero_skill_scale[i] += 0.05f;
					if (_effect_hero_skill_scale[i] >= 1.5f)
					{
						_effect_hero_skill_scale[i] = 1.5f;
					}
				}
			}
			else
			{
				if (_effect_hero_skill_scale[i] > 1.0f)
				{
					_effect_hero_skill_scale[i] -= 0.05;
					if (_effect_hero_skill_scale[i] <= 1.0f)
					{
						_effect_hero_skill_scale[i] = 1.0f;
						_effect_hero_skill_state[i] = -1;
						_effect_hero_skill_id[i] = -1;
					}
				}
			}*/
			break;
		case HERO_SKILL_WOLF_RANGER:
			if (_effect_hero_skill_state[i] != 1)
			{
				if (_effect_hero_skill_scale[i] < 1.5f)
				{
					_effect_hero_skill_scale[i] += 0.05f;
					if (_effect_hero_skill_scale[i] >= 1.5f)
					{
						_effect_hero_skill_scale[i] = 1.5f;
					}
				}
			}
			else
			{
				if (_effect_hero_skill_scale[i] > 1.0f)
				{
					_effect_hero_skill_scale[i] -= 0.05;
					if (_effect_hero_skill_scale[i] <= 1.0f)
					{
						_effect_hero_skill_scale[i] = 1.0f;
						_effect_hero_skill_state[i] = -1;
						_effect_hero_skill_id[i] = -1;
					}
				}
			}

			break;
		default:
			break;
		}
	}
}

void TDGame::EffectHeroSkillEnd(int skillid)
{
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_effect_hero_skill_id[i] == skillid)
		{
			_effect_hero_skill_state[i] = 1;
			break;
		}
	}
}

void TDGame::ItemsAddNew(int type, float x, float y, float tarx, float tary, int value)
{
	//printf("\n type = %d -- value = %d", type, value);
	for (int i = 0; i < MAX_ITEMS_DROP_INGAME; i++)
	{
		if (_arr_item[i]._state == ITEMS_EMPTY || _arr_item[i]._state == ITEMS_NULL)
		{
			_arr_item[i]._type = type;
			_arr_item[i]._x = x;
			_arr_item[i]._y = y;
			_arr_item[i]._value = value;
			_arr_item[i]._count_frame_hold = 0;
			_arr_item[i]._alphax = CMath::RANDOM(80, 100);
			_arr_item[i]._alphay = CMath::RANDOM(330, 340);
			_arr_item[i]._speed = CMath::RANDOM(15, 20);
			_arr_item[i]._delta = 0;
			_arr_item[i]._targetx = CMath::RANDOM(tarx + 10, tarx + 50);
			_arr_item[i]._targety = CMath::RANDOM(tary , tary + CMath::RANDOM(0,3)*5);
			_arr_item[i]._alpha_knock = 30;
			_arr_item[i]._rotate = 0;
			if (_arr_item[i]._state == ITEMS_NULL)
			{
				_num_item_collected++;
				if (_num_item_collected >= MAX_ITEMS_DROP_INGAME)
				{
					_num_item_collected = MAX_ITEMS_DROP_INGAME;
					//printf("\n fullllllllllllllllllllllllll \n fullllllllllllllllllll");
				}
			}
			_arr_item[i]._state = ITEMS_DROP;
			_arr_item[i]._scale = 1.0f;
			
			break;
		}
	}
}
void TDGame::ItemsRemove(int index)
{
	_arr_item[index]._state = ITEMS_EMPTY;
}
void TDGame::ItemsRender(float x, float y)
{
	int count = 0;
	for (int i = 0; i < _num_item_collected; i++)
	{
		if (_arr_item[i]._state >= ITEMS_DROP)
		{
			if (_arr_item[i]._state == ITEMS_FLY_ROBED)
			{
                float zoom = 1.0f;
                if (_arr_item[i]._type == ITEMS_TYPE_COIN )
                {
                    zoom = 1.0f + 0.1*_arr_item[i]._value/5;
                    if(zoom >= 2.5f)
                    {
                        zoom = 2.5f;
                    }
                }
				G()->SetScale(_arr_item[i]._scale*zoom, _arr_item[i]._scale*zoom, _arr_item[i]._x + x, _arr_item[i]._y + y);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 110 + _arr_item[i]._type, _arr_item[i]._x + x, _arr_item[i]._y + y);
				G()->ClearScale();
			}
			else
			{
				if (_arr_item[i]._type == ITEMS_TYPE_GEM )
				{
					G()->SetRotate(_arr_item[i]._rotate, _arr_item[i]._x + x, _arr_item[i]._y + y);
					G()->SetScale(0.3f*_arr_item[i]._scale, 0.3f*_arr_item[i]._scale, _arr_item[i]._x + x, _arr_item[i]._y + y);
					GET_SPRITE(SPRITEID_HUD_EFFECT_CHEST_01)->DrawFrame(G(), 0, _arr_item[i]._x + x, _arr_item[i]._y + y);
					G()->ClearScale();
					G()->ClearRotate();
				}
                float zoom = 1.0f;
                if (_arr_item[i]._type == ITEMS_TYPE_COIN )
                {
                    zoom = 1.0f + 0.1*_arr_item[i]._value/5;
                    if(zoom >= 2.5f)
                    {
                        zoom = 2.5f;
                    }
                }
                G()->SetScale(zoom,zoom, _arr_item[i]._x + x, _arr_item[i]._y + y);
				GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 110 + _arr_item[i]._type, _arr_item[i]._x + x, _arr_item[i]._y + y);
				G()->ClearScale();
			}
		}
	}
}

void TDGame::ItemsUpdate()
{
	if ((!_user._tutorial_completed || _user._tutorial_step < TUTORIAL_STEP_COMPLETED_2) && _tutorial_step != TUTORIAL_STEP_FREE)
	{
		return;
	}
	int count = 0;
	for (int i = 0; i < _num_item_collected; i++)
	{
		if (_arr_item[i]._type == ITEMS_TYPE_GEM)
		{
			_arr_item[i]._rotate += 2;
			if (_arr_item[i]._rotate >= 360)
			{
				_arr_item[i]._rotate -= 360;
			}

		}
		switch (_arr_item[i]._state)
		{
		case ITEMS_DROP:
		{

						   if (_arr_item[i]._alphax < 85)
						   {
							   _arr_item[i]._alphax += 1;
						   }
						   else if (_arr_item[i]._alphax > 100)
						   {
							   _arr_item[i]._alphax -= 1;
						   }
						   _arr_item[i]._alphay += 2;
						   if (_arr_item[i]._alphay >= 360)
						   {
							   _arr_item[i]._alphay = 0;
						   }
						   if (_arr_item[i]._alphay == 0)
						   {
							   _arr_item[i]._delta += 2;
						   }
						   _arr_item[i]._y += _arr_item[i]._speed*CMath::SIN(_arr_item[i]._alphay + _arr_item[i]._delta / 4);
						   if (_arr_item[i]._y >= _arr_item[i]._targety - _arr_item[i]._speed || _arr_item[i]._count_frame_hold > 0)
						   {
							   count++;
							   if (_arr_item[i]._count_frame_hold < 5)
							   {
								   _arr_item[i]._alpha_knock -= 8;
							   }
							   else
							   {
								   _arr_item[i]._alpha_knock += 8;
								   if (_arr_item[i]._alpha_knock >= 20)
								   {
									   _arr_item[i]._alpha_knock = 20;
								   }
							   }
							   if (_arr_item[i]._count_frame_hold == 0)
							   {
                                   //PLAY_SFX(CMath::RANDOM(SFX_ORC_DIE_1,SFX_ORC_DIE_2));
							   }
							   _arr_item[i]._count_frame_hold++;
							   _arr_item[i]._y = _arr_item[i]._targety + _arr_item[i]._speed*CMath::SIN(_arr_item[i]._alpha_knock);
							   if (_arr_item[i]._count_frame_hold >= 60)
							   {
								   _arr_item[i]._state = ITEMS_FLY;
								   if (_arr_item[i]._type == ITEMS_TYPE_COIN)
								   {
									   int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(0, 0);
									   int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
									   _arr_item[i]._targetx = x - _point_o.X;
									   _arr_item[i]._targety = y;
								   }
								   if (_arr_item[i]._type == ITEMS_TYPE_GEM)
								   {
									   int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(4, 0);
									   int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(4, 0);
									   _arr_item[i]._targetx = x - _point_o.X;
									   _arr_item[i]._targety = y;
								   }
							   }
						   }
						   else
						   {
							   _arr_item[i]._x += _arr_item[i]._speed*CMath::COS(_arr_item[i]._alphax);
						   }
		}
			break;
		case ITEMS_FLY:
		{
						  float angle = CMath::ANGLE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety);
						  _arr_item[i]._x += 20 * CMath::COS(angle);
						  _arr_item[i]._y += 20 * CMath::SIN(angle);
						  if (_arr_item[i]._type == ITEMS_TYPE_GEM)
						  {
							  _arr_item[i]._scale -= 0.03f;
						  }
						  if (CHECK_POINT_IN_CIRCLE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety, 20))
						  {
							  if (_arr_item[i]._type == ITEMS_TYPE_COIN)
							  {
								  _user.AddCoin(_arr_item[i]._value,false);
								  _effect_scale_icon_coin_start = true;
								  if (_count_frame_playsound_coin_colleted <= 0)
								  {
									  _count_frame_playsound_coin_colleted = 5;
									  GAME()->PlaySFX(SFX_COIN_DROP);
								  }
							  }
							  if (_arr_item[i]._type == ITEMS_TYPE_GEM)
							  {
								  _user.AddGem(_arr_item[i]._value);
								  _effect_scale_icon_gem_start = true;
							  }

							  _arr_item[i]._state = ITEMS_EMPTY;
						  }
		}
			break;
		case ITEMS_FLY_ROBED:
		{
								float dis = CMath::DISTANCE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety);
								_arr_item[i]._scale = dis / 50.0f;
								if (_arr_item[i]._scale >= 2.0f)
								{
									_arr_item[i]._scale = 2.0f;
								}
								//_arr_item[i]._speed = CMath::DISTANCE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety) / 5.0f;
								float angle = CMath::ANGLE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety);
								_arr_item[i]._x += 10 * CMath::COS(angle);
								_arr_item[i]._y += 10 * CMath::SIN(angle);
								if (CHECK_POINT_IN_CIRCLE(_arr_item[i]._x, _arr_item[i]._y, _arr_item[i]._targetx, _arr_item[i]._targety, 20))
								{
									_arr_item[i]._state = ITEMS_EMPTY;
								}
		}
			
			break;
		default:
			break;
		}
	}
	if (count > 10)
	{
		for (int i = 0; i < _num_item_collected; i++)
		{
			if (_arr_item[i]._state == ITEMS_DROP && _arr_item[i]._count_frame_hold >= 10)
			{
				if (_arr_item[i]._type == ITEMS_TYPE_COIN)
				{
					_arr_item[i]._state = ITEMS_FLY;
					int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(0, 0);
					int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
					_arr_item[i]._targetx = x - _point_o.X;
					_arr_item[i]._targety = y;
				}
				/*if (_arr_item[i]._type == ITEMS_TYPE_GEM)
				{
					int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(4, 0);
					int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(4, 0);
					_arr_item[i]._targetx = x - _point_o.X;
					_arr_item[i]._targety = y;
				}*/
			}
		}
	}
}

void TDGame::ItemForceEnd()
{
	for (int i = 0; i < _num_item_collected; i++)
	{
		if (_arr_item[i]._state != ITEMS_FLY)
		{
			_arr_item[i]._state = ITEMS_FLY;
			if (_arr_item[i]._type == ITEMS_TYPE_COIN)
			{
				int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(0, 0);
				int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
				_arr_item[i]._targetx = x - _point_o.X;
				_arr_item[i]._targety = y;
			}
			if (_arr_item[i]._type == ITEMS_TYPE_GEM /*&& _arr_item[i]._count_frame_hold >= 250*/)
			{
				int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(4, 0);
				int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(4, 0);
				_arr_item[i]._targetx = x - _point_o.X;
				_arr_item[i]._targety = y;
			}
		}
	}
}

void TDGame::ItemsInit()
{
	_num_item_collected = 0;
	for (int i = 0; i < MAX_ITEMS_DROP_INGAME; i++)
	{
		_arr_item[i]._state = ITEMS_NULL;
	}
}

void TDGame::ChangeBackgroundUpdate()
{
	if (_is_changing_background)
	{
		if (!_changing_background_opac_max)
		{
			_changing_background_opac += 4;
			if (_changing_background_opac >= 140)
			{
				if (_background_dark_sprite[_bg_spriteid] != _background_sprite[_bg_spriteid])
				{
					GAME()->UnloadSpriteVer(_background_dark_sprite[_bg_spriteid]);
					GAME()->UnloadSpriteVer(_background_sprite[_bg_spriteid]);
				}
				GAME()->UnloadSpriteVer(_bg_underground_spriteid);
				_changing_background_opac_max = true;
				_bg_spriteid = _bg_spriteid_next;
				_bg_underground_spriteid = _underground_sprite[_bg_spriteid_next];
				LoadSpriteOptimize(_background_sprite[_bg_spriteid],true,true);
				_is_night = false;
				LoadSpriteOptimize(_bg_underground_spriteid,false,false);
			}
		}
		else
		{
			_changing_background_opac -= 4;
			if (_changing_background_opac <= 0)
			{
				_is_changing_background = false;
			}
		}
	}
}

void TDGame::ChangeBackgroundRender()
{
	if (_is_changing_background)
	{
		G()->SetOpacity(_changing_background_opac);
		G()->SetColor(0xffffffff);
		G()->FillFullScreen(true);
		G()->SetOpacity(100);
	}
}

int TDGame::GetBackground()
{
	char temp[10];
	int total = _game_design.background.SheetSheet1.int32Value._totalData;
	int param_id = CGameDesign::Filebackground::CSheetSheet1::SpriteID;
	int param_battle = CGameDesign::Filebackground::CSheetSheet1::From;
	int bgid = 0;
	int battle_from = 0;
	int battle_end = 0;
	for (int i = 0; i < total; i++)
	{
		int bat = GetDesignBackground(i, param_battle);
		if (bat <= _battle_current + 1)
		{
			bgid = GetDesignBackground(i, param_id) - 1;
			battle_from = bat;
		}
		else
		{
			battle_end = bat;
			break;
		}
	}
	int num_battle = (int)((battle_end - battle_from) / 2.0f + 0.5f);
	if (battle_end <= battle_from)
	{
		num_battle = battle_from/4;
	}
	if (battle_from + num_battle > _battle_current+1 )
	{
		if (_is_night)
		{
			_is_night = false;
			if (_bg_spriteid_next != -1)
			{
				_is_changing_background_night = true;
				_changing_background_night_opac = 100;
			}
			LoadSpriteOptimize(_background_sprite[bgid],true,true);
		}
	}
	else
	{
		if (!_is_night )
		{
			_is_night = true;
			if (_bg_spriteid_next != -1)
			{
				_is_changing_background_night = true;
				_changing_background_night_opac = 100;
				
			}
			LoadSpriteOptimize(_background_dark_sprite[bgid],true,true);
		}
	}
    //printf("\n getbg = %d",bgid);
	int bg_spriteid = _background_sprite[bgid];
	if (_bg_spriteid_next != bgid && _bg_spriteid_next != -1)
	{
		_is_changing_background = true;
		_changing_background_opac_max = false;
		_changing_background_opac = 0;
		_is_night = true;
		LoadSpriteOptimize(_background_sprite[_bg_spriteid],true,true);
		_is_changing_background_night = false;
		_changing_background_night_opac = 0;
	}
	if (_bg_spriteid_next == -1)
	{
		LoadSpriteOptimize(bg_spriteid,true,true);
		LoadSpriteOptimize(_underground_sprite[bgid],true,true);
	}

	return bgid;
}
void TDGame::InitNotifyNew()
{
	int posx = 0;
	int posy = 0;
	for (int i = 0; i < NUM_BUTTON_MENU_INGAME; i++)
	{
		int x = _menu_ingame_button[i].TZ_GetX();
		int y = _menu_ingame_button[i].TZ_GetY();
		int w = _menu_ingame_button[i].TZ_GetWidth();
		int h = _menu_ingame_button[i].TZ_GetHeight();
		posx = x + w - 25;
		posy = y + h / 2 - 15;
		if (!_just_lose)
		{	
			_notify_new[i].Init(SPRITEID_HUD_MAINMENU, -1, 95, posx, posy, 0);
		}
		else
		{
			_notify_new[i].Init(SPRITEID_HUD_PROMO_PINEGAME, -1, 0, posx, posy, 0);
		}
		_notify_new[i]._just_lose = _just_lose;
	}
	_just_lose = false;
}
void TDGame::SetNotifyNew()
{
    //for weapon
	int  hasnew = -1;
	if (!_user._tutorial_completed)
	{
		if (_user._tutorial_step == TUTORIAL_STEP_MENU_CASTLE)
		{
			for (int i = 0; i < NUM_MAX_WEAPON; i++)
			{
				//rem notify upgrade
				/*if (_weapon[i].GetCostUpgrade() <= _user.GetCoin())
				{
				hasnew = NOTIFY_TYPE_ALERT;
				}*/
				if (_weapon[i].GetCostUpgrade() <= _user.GetCoin() && _weapon[i].IsLock() && _weapon[i]._level_limited <= _battle_current)
				{
					hasnew = NOTIFY_TYPE_NEW;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < NUM_MAX_WEAPON; i++)
		{
			if (_weapon[i].IsLock())
			{
				if (_weapon[i].GetCostUpgrade() <= _user.GetCoin() /*&& _weapon[i].IsLock() */&& _weapon[i]._level_limited <= _battle_current)
				{
					hasnew = NOTIFY_TYPE_NEW;
				}
			}
			else//rem notify upgrade
			{
				if (_weapon[i].GetCostUpgrade() <= _user.GetCoin())
				{
					if (hasnew != NOTIFY_TYPE_NEW)
					{
						hasnew = NOTIFY_TYPE_ALERT;
					}
				}
			}
		}
	}
	if (hasnew != -1)
	{
		_notify_new[MENU_INGAME_BUTTON_GATE].SetType(hasnew);
		if (_notify_new[MENU_INGAME_BUTTON_GATE]._state == NOTIFY_STATE_NONE)
		{
			_notify_new[MENU_INGAME_BUTTON_GATE].Active();
		}
	}
	else
	{
		if (_notify_new[MENU_INGAME_BUTTON_GATE]._state == NOTIFY_STATE_ACTIVE)
		{
			_notify_new[MENU_INGAME_BUTTON_GATE].Disable();
		}
	}
    
    //for hero: only hero deloyed in battle
	hasnew = -1;
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	if (_user._tutorial_step >= TUTORIAL_STEP_MENU_HERO)
	{
		for (int i = 0; i < totalhero; i++)
		{
			if (_hero_inbattle_arr[i].GetCostUpgrade() <= _user.GetCoin()
                && !_hero_inbattle_arr[i]._is_lock
                && _hero_inbattle_arr[i]._deployed)
			{
				hasnew = NOTIFY_TYPE_ALERT;
			}
			if (_hero_inbattle_arr[i]._is_new)
			{
				hasnew = NOTIFY_TYPE_NEW;
				break;
			}
            if(strcmp(_user._ivitation_code, "NULL") != 0)
            {
                if(_event_notify)
                {
                    hasnew = NOTIFY_TYPE_NEW;
                }
                _event_notify = false;
            }
		}
	}
	if (hasnew != -1)
	{
		
		_notify_new[MENU_INGAME_BUTTON_HEROES].SetType(hasnew);
		if (_notify_new[MENU_INGAME_BUTTON_HEROES]._state == NOTIFY_STATE_NONE)
		{
			_notify_new[MENU_INGAME_BUTTON_HEROES].Active();
		}
	}
	else
	{
		if (_notify_new[MENU_INGAME_BUTTON_HEROES]._state == NOTIFY_STATE_ACTIVE)
		{
			_notify_new[MENU_INGAME_BUTTON_HEROES].Disable();
		}
	}
    
    //for shop
	hasnew = -1;
    
	if (hasnew != -1)
	{
		_notify_new[MENU_INGAME_BUTTON_SHOP].SetType(hasnew);
		if (_notify_new[MENU_INGAME_BUTTON_SHOP]._state == NOTIFY_STATE_NONE)
		{
			_notify_new[MENU_INGAME_BUTTON_SHOP].Active();
		}
	}
	else
	{
		if (_notify_new[MENU_INGAME_BUTTON_SHOP]._state == NOTIFY_STATE_ACTIVE)
		{
			_notify_new[MENU_INGAME_BUTTON_SHOP].Disable();
		}
	}
}
void TDGame::ResetFlagNotifyNew(bool justlose)
{
	for (int i = 0; i < NUM_MAX_NOTIFY_OBJETC; i++)
	{
		if (_notify_new[i]._state == NOTIFY_STATE_ACTIVE)
		{
			_notify_new[i].Disable();
			_notify_new[i]._just_lose = justlose;
		}
	}
	_just_lose = false;
}
void TDGame::RenderNotifyNew(float x, float y)
{
	for (int i = 0; i < NUM_MAX_NOTIFY_OBJETC; i++)
	{
		_notify_new[i].Render(x, y);
	}
}
void TDGame::UpdateNotifyNew()
{
	SetNotifyNew();
	for (int i = 0; i < NUM_MAX_NOTIFY_OBJETC; i++)
	{
		_notify_new[i].Update();
	}
}

void TDGame::Notify::Init(int sprite, int frame, int anim, float x, float y, float scale)
{
	_x = x;
	_y = y;
	_scale = scale;
	_spriteid = sprite;
	_frameid = frame;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(anim, true);
	_anim.SetPos(0, 0);
	_state = NOTIFY_STATE_NONE;
	_just_lose = false;
}
void TDGame::Notify::Render(float x, float y)
{
	if (_state == NOTIFY_STATE_NONE)
	{
		return;
	}
	if (_frameid >= 0)
	{

	}
	else
	{
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		_anim.SetPos(_x + x, _y + y);
		_anim.DrawAnimObject(G());
		G()->ClearScale();
	}
}
void TDGame::Notify::Update()
{
	switch (_state)
	{
	case NOTIFY_STATE_NONE:
		break;
	case NOTIFY_STATE_START:
		if (_scale < 1.15f)
		{
			_scale += 0.08f;
			if (_scale >= 1.15f)
			{
				_state = NOTIFY_STATE_ACTIVE;
			}
		}
		_anim.UpdateAnimObject();
		break;
	case NOTIFY_STATE_ACTIVE:
		if (_scale > 1.0f)
		{
			_scale -= 0.05f;
			if (_scale <= 1.0f)
			{
				_scale = 1.0f;
			}
		}
		_anim.UpdateAnimObject();
		break;
	case NOTIFY_STATE_END:
		if (_scale > 0)
		{
			_scale -= 0.2f;
			if (_scale <= 0)
			{
				_scale = 0;
				_state = NOTIFY_STATE_NONE;
			}
		}
		_anim.UpdateAnimObject();
		break;
	default:
		break;
	}
}
void TDGame::Notify::Active()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_state = NOTIFY_STATE_START;
	if (!_just_lose)
	{
		if (_frameid == -1)
		{
			if (_spriteid == SPRITEID_HUD_PROMO_PINEGAME)
			{
				_spriteid = SPRITEID_HUD_MAINMENU;
				_anim.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), _spriteid);
				_anim.SetAnim(95, true);
				_anim.SetPos(0, 0);
			}
		}
	}
	else
	{
		if (_frameid == -1)
		{
			if (_spriteid == SPRITEID_HUD_MAINMENU)
			{
				_spriteid = SPRITEID_HUD_PROMO_PINEGAME;
				_anim.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_PROMO_PINEGAME), _spriteid);
				_anim.SetAnim(0, true);
				_anim.SetPos(0, 0);
			}
		}
	}
}
void TDGame::Notify::Disable()
{
	_state = NOTIFY_STATE_END;
	_just_lose = false;
}
void TDGame::Notify::SetType(int type)
{
	switch (type)
	{
	case NOTIFY_TYPE_NEW:
		if (_anim.GetCurrentAnim() != 95)
		{
			_anim.SetAnim(95, true);
		}
		
		
		break;
	case NOTIFY_TYPE_ALERT:
		if (_anim.GetCurrentAnim() != 98)
		{
			_anim.SetAnim(98, true);
		}
		break;
	default:
		break;
	}
	_anim.SetPos(0, 0);
}

int TDGame::GetNumWeaponUnlock()
{
	int num = 0;
	for (int i = 0; i < NUM_MAX_WEAPON;i++)
	{
		if (!_weapon[i].IsLock())
		{
			num++;
		}
		else
		{
			break;
		}
	}
	return num;
}
int TDGame::GetDamageWeaponBasic()
{
	int damage = 0;
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		if (!_weapon[i].IsLock())
		{
			damage += _weapon[i].GetDamage();
		}
	}
	return damage;
}
int TDGame::GetDamageHeroesBasic()
{
	int hero_total_damage = 0;
	for (int i = 0; i < NUM_MAX_HERO; i++)
	{
		if (_hero_inbattle_arr[i]._deployed && _hero_inbattle_arr[i].GetHeroID() > 0)
		{
			hero_total_damage += _hero_inbattle_arr[i].GetDamage();
		}
	}
	return hero_total_damage;
}
void TDGame::GiftReward::Init(int type, int sprite, int frame, int numframe, float deltaspeed)
{
	_spriteid = sprite;
	_frame = frame;
	_num_frame = numframe;
	_value = 0;
	_x = _y = _tarx = _tary = 0;
	_angle = 0;
	_speed = 0;
	_speed_angle = 0;
	_type = type;
	_state = GIFT_REWARD_STATE_NORMAL;
	_speed_deltax = deltaspeed;
	_deltax = 1.0f;
	_dir = CMath::RANDOM(0, 1);
	for (int i = 0; i < GIFT_REWARD_NUM_PARTICAL; i++)
	{
		_partical[i].Init(_spriteid, _frame + CMath::RANDOM(0, _num_frame - 1), -0.01f, 10);
	}
}
void TDGame::GiftReward::Render(float x, float y)
{
	if (_state == GIFT_REWARD_STATE_NORMAL)
	{
		return;
	}
	for (int i = 0; i < GIFT_REWARD_NUM_PARTICAL; i++)
	{
		_partical[i].Render(x , y );
	}
}
void TDGame::GiftReward::Active(float x, float y, float tarx, float tary, int value)
{
	_state = GIFT_REWARD_STATE_START;
	_x = x;
	_y = y;
	_tarx = tarx;
	_tary = tary;
	_value = value;
	float dis = CMath::DISTANCE(_x, _y, _tarx, _tary);
	_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
	_speed = dis / 600.0f;
	if (_speed < 0.5)
	{
		_speed = 0.5f;
	}
	//printf("\n _speed = %f", _speed);
	float disx = CMath::ABSOLUTE_VALUE(_x -  _tarx);
	float disy = CMath::ABSOLUTE_VALUE(_y - _tary);
	_speed_deltax = disx / 20.0f;
	_speed_deltay = disy / 20.0f;
	if (_x < k_SCREEN_WIDTH/3)
	{
		_dir = 0;
	}
	else if(_x > 2*k_SCREEN_WIDTH/3)
	{
		_dir = 1;
	}
	else
	{
		_dir = CMath::RANDOM(0, 1);
	}
	//_dir = CMath::RANDOM(0, 1);
	_deltax = 0;
	_deltay = 0;
	if (_dir == 0)
	{
		_deltax = 0.8f;
	}
	else
	{
		_deltax = 0.2f;
	}
	_speed_angle = (CMath::RANDOM(0, 1) * 2 - 1) / 2.0f;
}
void TDGame::GiftReward::Update()
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	if (_state == GIFT_REWARD_STATE_NORMAL)
	{
		return;
	}
	for (int i = 0; i < GIFT_REWARD_NUM_PARTICAL; i++)
	{
		_partical[i].Update();
	}
	
	switch (_state)
	{
		
	case GIFT_REWARD_STATE_START:
		AddParticel(_x + CMath::RANDOM(-4, 4) * 1, _y + CMath::RANDOM(-4, 4) * 1);
		AddParticel(_x + CMath::RANDOM(-4, 4) * 2, _y + CMath::RANDOM(-4, 4) * 2);
		AddParticel(_x + CMath::RANDOM(-4, 4) * 3, _y + CMath::RANDOM(-4, 4) * 3);
		AddParticel(_x + CMath::RANDOM(-4, 4) * 4, _y + CMath::RANDOM(-4, 4) * 4);
		AddParticel(_x + CMath::RANDOM(-4, 4) * 3, _y + CMath::RANDOM(-4, 4) * 3);
		if (!CHECK_POINT_IN_CIRCLE(_x, _y, _tarx, _tary, _speed))
		{
			if (_dir == 0)
			{
				if (_deltax > 0)
				{
					_deltax -= _speed_deltax;
				}
				else
				{
					_deltax = 0;
				}
			}
			else
			{
				if (_deltax < 1.0f)
				{
					_deltax += _speed_deltax;
				}
				else
				{
					_deltax = 1.0f;
				}
			}
			_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
			float disx = _tarx - _x;
			float disy = _tary - _y;
			_speed_deltax = disx * 4 / 40.0f;
			_speed_deltay = disy / 40.0f;
			_x += _speed*CMath::COS(_angle) + _speed_deltax;
			_y += _speed*CMath::SIN(_angle) + _speed_deltay;
		}
		if (CHECK_POINT_IN_CIRCLE(_x, _y, _tarx, _tary, _speed))
		{
			_x = _tarx;
			_y = _tary;
			_state = GIFT_REWARD_STATE_END;
			for (int i = 0; i < GIFT_BOX_NUM_TYPE; i++)
			{
				//printf("\n _type = %d , game->_gift_box._gift[i]._type = %d", _type, game->_gift_box._gift[i]._type);
				//switch (game->_gift_box._gift[i]._type)
				if (game->_gift_box._gift[i]._value > 0)
				{
					switch (game->_gift_box._gift[i]._type)
					{
					case GIFT_BOX_TYPE_AUTO_ATT:
						game->_user._auto_attack_free += game->_gift_box._gift[i]._value;
						game->_gift_box._gift[i]._value = 0;
						break;
					case GIFT_BOX_TYPE_AUTO_SKILL:
						game->_user._auto_skill_free += game->_gift_box._gift[i]._value;
						game->_gift_box._gift[i]._value = 0;
						break;
					case GIFT_BOX_TYPE_COIN:
						game->_user.AddCoin(game->_gift_box._gift[i]._value,false);
						game->_gift_box._gift[i]._value = 0;
						break;
					case GIFT_BOX_TYPE_GEM:
						game->_user.AddCoin(game->_gift_box._gift[i]._value,false);
						game->_gift_box._gift[i]._value = 0;
						break;
					case GIFT_BOX_TYPE_DOUBLE_COIN:
						game->_has_double_coin_timer += game->_gift_box._gift[i]._value;
						game->_gift_box._gift[i]._value = 0;
                        game->_fairy_double_coin_time.setDateBYSecond(game->_has_double_coin_timer);
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	case GIFT_REWARD_STATE_END:
		_state = GIFT_REWARD_STATE_FREE;
		break;
	case GIFT_REWARD_STATE_FREE:
		break;
	default:
		break;
	}
	
	
}
bool TDGame::GiftReward::IsFree()
{
	if (_state == GIFT_REWARD_STATE_NORMAL || _state == GIFT_REWARD_STATE_FREE)
	{
		return true;
	}
	return false;
}
void TDGame::GiftReward::AddParticel(float x, float y)
{
	for (int i = 0; i < GIFT_REWARD_NUM_PARTICAL; i++)
	{
		if (_partical[i].IsFree())
		{
			_partical[i].Active(x, y, CMath::RANDOM(5, 8) / 10.0f, 100);
			_partical[i]._frame = _frame + CMath::RANDOM(0, _num_frame - 1);
			break;
		}
	}
}

void TDGame::GiftRewardInit()
{
	for (int i = 0; i < GIFT_REWARD_NUM_MAX; i++)
	{
		_gift_reward[i].Init(i,SPRITEID_FAIRY_01, 6, 2, 0);
	}
}
void TDGame::GiftRewardRender(float x, float y)
{
	for (int i = 0; i < GIFT_REWARD_NUM_MAX; i++)
	{
		_gift_reward[i].Render(x,y);
	}
}
void TDGame::GiftRewardUpdate()
{
	for (int i = 0; i < GIFT_REWARD_NUM_MAX; i++)
	{
		_gift_reward[i].Update();
	}
}
void TDGame::GiftRewardActive(float x, float y, float tarx, float tary, int value)
{
	for (int i = 0; i < GIFT_REWARD_NUM_MAX; i++)
	{
		if (_gift_reward[i].IsFree())
		{
			_gift_reward[i].Active(x, y, tarx, tary, value);
			break;
		}
	}
}

void TDGame::ArchievementSubmit()
{
	int count_quest = 0;
	for (int i = 0; i < _num_max_quest + 1; i++)
	{
		if (!_quest_info[i]._has_daily_quest)
		{
			int percent = (int)(((float)_quest_info[count_quest]._value1 / (float)_quest_info[count_quest]._value2) * 100);
            //printf("\n percent = %d",percent);
            if(_quest_info[count_quest]._quest_group_id == 8)
            {
                percent = 0;
            }
			if (percent < 100 && percent > 0)
			{
				//submit
                
#if defined (MAC_OS)
                // disable achivement ios
                /*if(strcmp(_quest_info[count_quest]._archivement, "NONE") != 0)
                {
                    PineGameCenterController::SubmitAchivement(percent, _quest_info[count_quest]._archivement, true);
                }*/
                
#else
#endif
			}
			count_quest++;
		}
	}
}

void TDGame::RelicsReset()
{
	for (int i = 0; i < _relics_num_of; i++)
	{
		_items_relics[i].Reset();
	}
}

void TDGame::HeroesReset()
{
	int totalhero = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	int num_heroes = 0;
    for (int i = 0; i < totalhero; i++)
    {
		int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		int heroid = GetDesignHeroGeneral(i, paramid);
		if (!_user.CheckHeroColleted(heroid))
        {
            _hero_inbattle_arr[i].Init(heroid, 1, false, true,false);
        }
    }
}
void TDGame::RateUsInit()
{
	_rate_us_scale = 0;
	_rate_us_active = true;
	_rate_us_close = false;
	_rate_us_scale_max = false;
	for (int i = 0; i < RATEUS_NUM_BUTTON; i++)
	{
		_rate_us_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_rate_us_button[i].SetAnim(SPRITEID_HUD_RATEUS, 4 + i * 4);
		_rate_us_button[i].SetPos(0, 0);
	}
}
void TDGame::RateUsRender(float x, float y)
{
	G()->SetScale(_rate_us_scale, _rate_us_scale, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
	GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(),0, x, y);

#if defined (ANDROID_OS)
//#if defined(ANDROID_RATE_REWARD)
//		GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 5, x, y);
//#else
//		GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 20, x, y);
//#endif
		GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 20, x, y);
#else
	GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 5, x, y);
#endif
	for (int i = 0; i < RATEUS_NUM_BUTTON; i++)
	{
		_rate_us_button[i].Render(G());
		_rate_us_button[i].Update();
	}
	G()->ClearScale();
}
void TDGame::RateUsUpdate()
{
	if (_rate_us_close)
	{
		_rate_us_scale -= 0.1f;
		_ingame_fill_opac -= 10;
		if (_ingame_fill_opac <= 0)
		{
			_ingame_fill_opac = 0;
		}
		if (_rate_us_scale <= 0)
		{
			_rate_us_active = false;
			ClearAllTouchUp(TOUCH_TYPE_INGAME);
		}
	}
	else
	{
		_ingame_fill_opac += 10;
		if (_ingame_fill_opac >= 100)
		{
			_ingame_fill_opac = 100;
		}
		if (!_rate_us_scale_max)
		{
			_rate_us_scale += 0.1f;
			if (_rate_us_scale >1.2f)
			{
				_rate_us_scale_max = true;
			}
		}
		else
		{
			_rate_us_scale -= 0.05f;
			if (_rate_us_scale <= 1.0f)
			{
				_rate_us_scale = 1.0f;
			}
		}
        if(_rate_us_time != -1 )
        {
            if(_rate_us_time <= time(NULL))
            {
                if(!_dialogMng.isOpenDialog())
                {
                    char text[256];
                    sprintf(text, "%d :", RATE_US_REWARD);
					GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
                    _dialogMng.Add(DIALOG_CONTEXT_RATE_US, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
                    _rate_us_time = -1;
                }
            }
            else
            {
                _rate_us_time = -1;
            }
        }
	}
    
	RateUsUpdateTouch();
}
bool TDGame::RateUsUpdateTouch()
{
	bool ret = false;
	int index = -1;
	if (_dialogMng.isOpenDialog())
	{
		return ret;
	}
	for (int i = 0; i < RATEUS_NUM_BUTTON; i++)
	{
		if (_rate_us_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_rate_us_button[index].NeedAction())
		{
			switch (index)
			{
			case RATEUS_BUTTON_SKIP:
			{
									   if (_user._rate_trigger == RATE_US_TRIGGER_1)
									   {
										   _user._rate_trigger = _battle_current + 10;
									   }
                                       else
                                       {
                                           _user._has_rated_us_type = RATE_US_TYPE_CANCEL;
                                       }
									   _rate_us_close = true;
			}
				_user.UserDataSave();
				break;
			case RATEUS_BUTTON_RATE:
#if defined (MAC_OS)
					GAME()->_is_cancel_show_ads_on_resume = true;
                    GoToReviewInItune();
                    _rate_us_time = time(NULL) + 5;
					_rate_us_type = RATE_US_TYPE_RATE_APP;
#elif defined (ANDROID_OS)
//#if defined(ANDROID_RATE_REWARD)
//				OS_Rating();
//				GAME()->_is_cancel_show_ads_on_resume = true;
//				_rate_us_time = time(NULL) + 5;
//				_rate_us_type = RATE_US_TYPE_RATE_APP;
//#else
//				OS_Rating();
//				GAME()->_is_cancel_show_ads_on_resume = true;
//				_user._has_rated_us_type = RATE_US_TYPE_RATED;
//				_rate_us_type = RATE_US_TYPE_NONE;
//				_user.UserDataSave();
//				_rate_us_close = true;
//#endif
				OS_Rating();
				GAME()->_is_cancel_show_ads_on_resume = true;
				_user._has_rated_us_type = RATE_US_TYPE_RATED;
				_rate_us_type = RATE_US_TYPE_NONE;
				_user.UserDataSave();
				_rate_us_close = true;
					
#else
				if (!_dialogMng.isOpenDialog())
				{

					char text[256];
					sprintf(text, "%d :", RATE_US_REWARD);
					GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
					_dialogMng.Add(DIALOG_CONTEXT_RATE_US, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "YOU HAVE RECEIVED", text, 0, 0);
				}
#endif
				
				break;
			default:
				break;
			}

			for (int i = 0; i < RATEUS_NUM_BUTTON; i++)
			{
				if (_rate_us_button[i]._state != BUTTON_STATE_LOCK && _rate_us_button[i]._state != BUTTON_STATE_HIDE)
				{
					_rate_us_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < RATEUS_NUM_BUTTON; touch++)
		{
			if (_rate_us_button[touch]._state == BUTTON_STATE_LOCK || _rate_us_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _rate_us_button[touch].TZ_GetX();
			int y = _rate_us_button[touch].TZ_GetY();
			int w = _rate_us_button[touch].TZ_GetWidth();
			int h = _rate_us_button[touch].TZ_GetHeight();
			Button *button = &_rate_us_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						GAME()->PlaySFX(SFX_BUTTON);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
					}
				}
				if (button->_touch_id != -1)
				{
					pressed = true;
				}
			}
			else
			{

				if (button->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void TDGame::InvitationInit()
{
	_invitation_scale = 0;
	_invitation_active = true;
	_invitation_close = false;
	_invitation_scale_max = false;
	for (int i = 0; i < INVITATION_NUM_BUTTON; i++)
	{
		_invitation_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_invitation_button[i].SetAnim(SPRITEID_HUD_RATEUS, 8 + i * 4);
		_invitation_button[i].SetPos(0, 0);
	}
    sprintf(_ivitation_code_input, "");
}
void TDGame::InvitationRender(float x, float y)
{
	G()->SetScale(_invitation_scale, _invitation_scale, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
	GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 0, x, y);
	GET_SPRITE(SPRITEID_HUD_RATEUS)->DrawFrame(G(), 6, x, y);
    int markerX = GET_SPRITE(SPRITEID_HUD_RATEUS)->GetFModuleCenterX(6, 1);
    int markerY = GET_SPRITE(SPRITEID_HUD_RATEUS)->GetFModuleCenterY(6, 1);
    GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + markerX, y + markerY, _HCENTER | _VCENTER, "%s", _ivitation_code_input);
	for (int i = 0; i < INVITATION_NUM_BUTTON; i++)
	{
		_invitation_button[i].Render(G());
		_invitation_button[i].Update();
	}
	G()->ClearScale();
}
void TDGame::InvitationUpdate()
{
	if (_invitation_close)
	{
		_invitation_scale -= 0.1f;
		_ingame_fill_opac -= 10;
		if (_ingame_fill_opac <= 0)
		{
			_ingame_fill_opac = 0;
		}
		if (_invitation_scale <= 0)
		{
			_invitation_active = false;
			ClearAllTouchUp(TOUCH_TYPE_INGAME);
		}
	}
	else
	{
		_ingame_fill_opac += 10;
		if (_ingame_fill_opac >= 100)
		{
			_ingame_fill_opac = 100;
		}
		if (!_invitation_scale_max)
		{
			_invitation_scale += 0.1f;
			if (_invitation_scale >1.2f)
			{
				_invitation_scale_max = true;
                Device::ShowKeyboard(0, 0, 0, 0);
                Device::DisableReturnKey(true);
                Device::SetTextBufferMax(EVENT_INVITE_CODE_LENGTH);
			}
		}
		else
		{
			_invitation_scale -= 0.05f;
			if (_invitation_scale <= 1.0f)
			{
				_invitation_scale = 1.0f;
			}
		}
	}
    printf("\n device text = %s",Device::_keyboard_character);
#ifdef MAC_OS
				sprintf(_ivitation_code_input, "%s", Device::_keyboard_character);
#else
				sprintf(_ivitation_code_input, "%s", "PINEID");
#endif
				for (int i = 0; i < strlen(_ivitation_code_input); i++)
                {
                    _ivitation_code_input[i] = toupper(_ivitation_code_input[i]);
                    /*if(_ivitation_code_input[i] >= 97 && _ivitation_code_input[i] <= 122)
                    {
                        _ivitation_code_input[i] = _ivitation_code_input[i]-32;
                    }*/
                }
    
				if (strlen(_ivitation_code_input) >= EVENT_INVITE_CODE_LENGTH)
                {
                    if (_invitation_button[INVITATION_BUTTON_OK]._state == BUTTON_STATE_LOCK)
                    {
                        _invitation_button[INVITATION_BUTTON_OK].SetState(BUTTON_STATE_NORMAL);
                    }
                }
                else
                {
                    if (_invitation_button[INVITATION_BUTTON_OK]._state != BUTTON_STATE_LOCK)
                    {
                        _invitation_button[INVITATION_BUTTON_OK].SetState(BUTTON_STATE_LOCK);
                    }
                }
	InvitationUpdateTouch();
}
bool TDGame::InvitationUpdateTouch()
{
	bool ret = false;
	int index = -1;
	if (_dialogMng.isOpenDialog())
	{
		return ret;
	}
	for (int i = 0; i < INVITATION_NUM_BUTTON; i++)
	{
		if (_invitation_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_invitation_button[index].NeedAction())
		{
			switch (index)
			{
			case INVITATION_BUTTON_OK:
			{
#if !defined (ANDROID_OS)
                GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_POST_INVITATION_CODE);
#endif
                Device::CloseKeyboard();
				GAME()->_processing_view_type = PROCESSING_VIEW_TYPE_IAP;
				GAME()->_loading_count_frame = 0;
				GAME()->_processing_time_out = PROCESSING_TIME_OUT;
			}
				break;
			case INVITATION_BUTTON_SKIP:
                    if(!_dialogMng.isOpenDialog())
                    {
                        char text[256];
                        sprintf(text, "%s", "Are you sure to skip this without helping your friend?");
                        _dialogMng.Add(DIALOG_CONTEXT_INVITATION_EXIT, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "Are you sure?", text, 0, 0);
                        Device::CloseKeyboard();
                    }
				break;
			default:
				break;
			}

			for (int i = 0; i < INVITATION_NUM_BUTTON; i++)
			{
				if (_invitation_button[i]._state != BUTTON_STATE_LOCK && _invitation_button[i]._state != BUTTON_STATE_HIDE)
				{
					_invitation_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < INVITATION_NUM_BUTTON; touch++)
		{
			if (_invitation_button[touch]._state == BUTTON_STATE_LOCK || _invitation_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _invitation_button[touch].TZ_GetX();
			int y = _invitation_button[touch].TZ_GetY();
			int w = _invitation_button[touch].TZ_GetWidth();
			int h = _invitation_button[touch].TZ_GetHeight();
			Button *button = &_invitation_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						GAME()->PlaySFX(SFX_BUTTON);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
					}
				}
				if (button->_touch_id != -1)
				{
					pressed = true;
				}
			}
			else
			{

				if (button->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void TDGame::UpdatePoupReward()
{
	if (!_dialogMng.isOpenDialog())
	{
		while (_user._invitation_reward_current < _user._invitation_num)
		{
			if (_user._invitation_reward_current == 0)
			{
                if(!_dialogMng.isOpenDialog())
                {
                    char text[256];
					if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_ACHEMIST)
					{
						if (RandomRelics())
						{
							sprintf(text, "Special Relic= %s", _wheel_relic._name);
						}
						else
						{
							_wheel_relic._id = -1;
							sprintf(text, "%d :", 20);
						}
					}
					else if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_XMAS)
					{
						sprintf(text, "%d ;", EVENT_INVITE_REWARD_COIN);
					}
					
                    _dialogMng.Add(DIALOG_CONTEXT_INVITATION_GIFT_1, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "You've received the reward for the 1st friend", text, 0, 0);
                }
                break;
			}
			else if (_user._invitation_reward_current == 1)
			{
                if(!_dialogMng.isOpenDialog())
                {
                    char text[256];
					if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_ACHEMIST)
					{
						if (RandomRelics())
						{
							sprintf(text, "Special Relic= %s", _wheel_relic._name);
						}
						else
						{
							_wheel_relic._id = -1;
							sprintf(text, "%d :", 20);
						}
					}
					else if (EVENT_TYPE_AVAILABLE == EVENT_TYPE_XMAS)
					{
						sprintf(text, "%d :", EVENT_INVITE_REWARD_GEM);
					}
                    _dialogMng.Add(DIALOG_CONTEXT_INVITATION_GIFT_2, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "You've received the reward for the 2nd friend", text, 0, 0);
                }
                break;
			}
			else if (_user._invitation_reward_current == 2)
			{
                if(!_dialogMng.isOpenDialog())
                {
                    char text[256];
					sprintf(text, "Hero= %s", EVENT_HERO_NAME_AVAILABLE);
                    _dialogMng.Add(DIALOG_CONTEXT_INVITATION_GIFT_3, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "You've received the reward for the 3rd friend", text, 0, 0);
                }
                break;
			}
		}
	}
}

bool TDGame::HasEventAvailable(int event_type)
{
	bool ret = false;
	switch (event_type)
	{
	case EVENT_TYPE_XMAS:
		if (!_is_hacked_time)
		{
			Pine_Date_Time time_local;
			time_local.setDateByLocalDate();
			if (time_local.GetCurrentMonth() == 12)
			{
				ret = true;
			}
		}
		break;
	case EVENT_TYPE_ACHEMIST:
		if (!_is_hacked_time)
		{
			Pine_Date_Time time_local;
			time_local.setDateByLocalDate();
            ////printf("\n time_local.GetCurrentMonth() = %d",time_local.GetCurrentMonth());
            //printf("\n _has_pass_invitation = %d",_user._has_pass_invitation);
			//if (time_local.GetCurrentMonth() == 12)
			ret = true;
			//if (time_local.GetCurrentMonth() <= 2)
			//{
			//	//if (time_local.GetCurrentDay() > 1)
			//	{
			//		ret = true;
			//	}
			//}
		}
		break;
	default:
		break;
	}
	return ret;
}

void TDGame::ClearAllTouchUp(int type)
{
#if !defined (ANDROID_OS)
	return;
#endif
	switch (type)
	{
    case TOUCH_TYPE_FREE_GIFT:
           
            for (int i = GAME()->_num_touches - 1; i >= 0; i--)
            {
                if (_button_free_gift_touch_id == TOUCHS(i)->_id)
                {
                    TOUCHS(i)->_state = TOUCH_UP;
                }
            }
            _button_free_gift_touch_id = -1;
            break;
	case TOUCH_TYPE_INGAME:
		for (int j = 0; j < NUM_BUTTON_INGAME; j++)
		{
			for (int i = GAME()->_num_touches - 1; i >= 0; i--)
			{
				if (_ingame_button[j]._touch_id == TOUCHS(i)->_id)
				{
					TOUCHS(i)->_state = TOUCH_UP;
				}
			}
			_ingame_button[j]._touch_id = -1;
		}
		_auto_hold_key = -1;
		break;
	case TOUCH_TYPE_MENU_INFO:
		for (int j = 0; j < _ingame_menu_num_item; j++)
		{
			for (int i = GAME()->_num_touches - 1; i >= 0; i--)
			{
				if (_menu_info_arr[j]._button_buy._touch_id == TOUCHS(i)->_id)
				{
					TOUCHS(i)->_state = TOUCH_UP;
				}
			}
			_menu_info_arr[j]._button_buy._touch_id = -1;
		}
		_ingame_menu_scroll.SetState(2);
		_ingame_menu_scroll._isScroll = false;
		_ingame_menu_scroll._touch_id = -1;
		break;
	case TOUCH_TYPE_MENU_INGAME:
		
		break;
	case TOUCH_TYPE_QUEST:
		break;
	case TOUCH_TYPE_SETTING:
		/*for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				for (int j = 0; j < NUM_BUTTON_MENU; j++)
				{
					if (_menu_button[j]._touch_id == TOUCHS(i)->_id && _menu_button[j]._touch_id != -1)
					{
						_menu_button[j]._touch_id = -1;
						TOUCHS(i)->_state = TOUCH_UP;
					}

				}
			}
		}*/
		break;
	default:
		break;
	}
    _auto_hold_key = -1;
}

bool TDGame::HasDownLoadMoreGame()
{
    return false;
	int ret = false;
    /*DOWN_MOREGAME_TRIGGER_BATTLE*/
    //printf("\n _user._download_moregame_trigger = %lld",_user._download_moregame_trigger);
	if (_battle_current >= DOWN_MOREGAME_TRIGGER_BATTLE && _user._download_moregame_trigger < time(NULL))
	{
        //printf("\n GAME()->_advert.IsAvailable() = %d",GAME()->_advert.IsAvailable());
#if ADD_ADVERT
		if (GAME()->_advert.IsAvailable() && !_is_hacked_time)
		{
			ret = true;
		}
#endif
	}
#if defined (_WINDOWS)
	ret = true;
#endif
	return ret;
}

void TDGame::GetRewardOffline()
{
#if GAME_SUPPORT
    return;
#endif

    printf("\n get reward off _user._time_offline:%lld",_user._time_offline);
	INT_TIME localtime = time(NULL);
	INT_TIME off_time = (INT_TIME)((localtime - _user._time_offline));
	int hour = int((off_time / 60) / 60);
	int total_wheeltime = _game_design.General.SheetWheel_time.int32Value._totalData;
    int min = (int)(off_time / 60);
	if (min >= GetDesignWheelTime(total_wheeltime-1))
	{
        int max = _game_design.General.SheetWheel_time.int32Value._totalData;
        if(_user._num_get_free_wheel > max)
        {
            _user._num_get_free_wheel = max;
        }
		else
        {
            _user._num_get_free_wheel = 0;
        }
	}
	int day = hour / 24;
	printf("\n day = %d,hour = %d,off_time = %lld,localtime = %lld,_user._time_offline = %lld", day, hour, off_time, localtime, _user._time_offline);
#if !defined (ANDROID_OS)
    printf("\n hack time = %d, network = %d", _is_hacked_time,GAME()->_serverThread._isNetworkAvailable);
#endif
    if(day < 1)
    {
        _offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_DONE;
        return;
    }
#if defined (_WINDOWS)
    GAME()->_serverThread._isNetworkAvailable = false;
#endif
#if !DISABLE_ONLINE_FEATURE
    if(_is_hacked_time || !GAME()->_serverThread._isNetworkAvailable)
    {
		if (!_dialogMng.isOpenDialog() && !GAME()->_serverThread._isNetworkAvailable)
		{
			char text[256];
			sprintf(text, "%s", "Please make sure that your device has network connectivity to receive gifts");
			_dialogMng.Add(DIALOG_CONTEXT_NO_NETWORK, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "Warning!", text, 0, 0);
			_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_WAITING;
			_daily_reward_collected = OFFLINE_RW_COLLECTED_TYPE_WAITING;
		}
        return;
    }
#endif
	
	if (day >= 10)
	{
		if (!_dialogMng.isOpenDialog())
		{
			char text[256];
            if(RandomRelics())
            {
                sprintf(text, "You have received\n80k ;, 30 :\nA special relic= %s.", _wheel_relic._name);
            }
            else
            {
				sprintf(text, "%s", "You have received\n80k ;, 30 :");
                _wheel_relic._id = -1;
            }
			GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
			_dialogMng.Add(DIALOG_CONTEXT_OFFLINE_REWARD1, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "CONGRATULATIONS!", text, 0, 0);
		}
	}
	else
	if (day >= 5)
	{
		if (!_dialogMng.isOpenDialog())
		{
            char text[256];
            if(RandomRelics())
            {
				sprintf(text, "You have received\n50k ;, 20 :\nA special relic= %s.", _wheel_relic._name);
            }
			else
            {
				sprintf(text, "%s", "You have received\n50k ;, 20 :");
                _wheel_relic._id = -1;
            }
			GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
			_dialogMng.Add(DIALOG_CONTEXT_OFFLINE_REWARD2, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "CONGRATULATIONS!", text, 0, 0);
		}
	}
	else
	if (day >= 2)
	{
		if (!_dialogMng.isOpenDialog())
		{
			char text[256];
			sprintf(text, "%s", "You have received\n20k ;, 10 :");
			GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
			_dialogMng.Add(DIALOG_CONTEXT_OFFLINE_REWARD3, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "CONGRATULATIONS!", text, 0, 0);
		}
	}
	else
	if (day >= 1)
	{
		if (!_dialogMng.isOpenDialog())
		{
			char text[256];
			sprintf(text, "%s", "You have received\n10k ;");
			GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
			_dialogMng.Add(DIALOG_CONTEXT_OFFLINE_REWARD4, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "CONGRATULATIONS!", text, 0, 0);
		}
	}
}

bool TDGame::HasDailyReward()
{
    //return true;
	if (!_user._tutorial_completed)
	{
		return false;
	}
	bool ret = false;
	Pine_Date_Time localday;
	localday.setDateByLocalDate();
	if (_battle_current < DAILY_REWARD_TRIGGER_BATTLE)
	{
		return ret;
	}
	else
	{
		if (_user._daily_reward_day == -1)
		{
			ret = true;
		}
		else
		{
            
			int dis_day = localday.GetTotalDay() - _user._daily_reward_day;
			if (dis_day == 1)
			{
				if (_local_time_cach != localday.GetTotalDay())
				{
					_daily_reward_collected = OFFLINE_RW_COLLECTED_TYPE_NONE;
					_local_time_cach = localday.GetTotalDay();
				}
				
				ret = true;
			}
			else if (dis_day >= 2)
			{
				if (_local_time_cach != localday.GetTotalDay())
				{
					_daily_reward_collected = OFFLINE_RW_COLLECTED_TYPE_NONE;
					_local_time_cach = localday.GetTotalDay();
				}
				//_user._daily_reward_num = 0;
				ret = true;
			}
		}
	}
	return ret;
}
void TDGame::DailyRewardInit()
{
#if GAME_SUPPORT
    return;
#endif
#if defined (_WINDOWS)
	GAME()->_serverThread._isNetworkAvailable = false;
#endif
#if !DISABLE_ONLINE_FEATURE
	if (_is_hacked_time || !GAME()->_serverThread._isNetworkAvailable)
	{
		if (_daily_reward_collected == OFFLINE_RW_COLLECTED_TYPE_NONE)
		{
			if (!_dialogMng.isOpenDialog() && !GAME()->_serverThread._isNetworkAvailable)
			{
				printf("\n daily notify");
				char text[256];
				sprintf(text, "%s", "Please make sure that your device has network connectivity to receive gifts");
				_dialogMng.Add(DIALOG_CONTEXT_NO_NETWORK, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "Warning!", text, 0, 0);
				_offline_reward_collected = OFFLINE_RW_COLLECTED_TYPE_WAITING;
				_daily_reward_collected = OFFLINE_RW_COLLECTED_TYPE_WAITING;
			}
		}
		return;
	}
#endif
	if (_user._daily_reward_num >= _game_design.General.SheetDaily_Event.int32Value._totalData)
	{
		_user._daily_reward_num = _game_design.General.SheetDaily_Event.int32Value._totalData - 1;
	}
	
	for (int i = 0; i <DAILY_REWARD_NUM_BUTTON; i++)
	{
		_daily_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
		_daily_button[i].SetAnim(SPRITEID_HUD_DAILY_REWARD, i * 4);
		_daily_button[i].SetPos(0, 0);
	}
	_daily_reward_effect_scale = 0;
	_daily_reward_close = false;
	_daily_reward_big_rw = true;
	_daily_reward_coin = 0;
	_daily_reward_gem = 0;
	_daily_reward_active = true;
	
	if (!RandomRelics())
	{
		_wheel_relic._id = -1;
	}
	int count_coin = 0;
	int count_gem = 0;
	for (int i = 0; i < DAILY_REWARD_NUM; i++)
	{
		int param_type = CGameDesign::FileGeneral::CSheetDaily_Event::Type;
		int param_value = CGameDesign::FileGeneral::CSheetDaily_Event::Value;
		int type = GetDesignDailyReward(i, param_type);
		INT_TIME reward = GetDesignDailyReward(i, param_value);
		INT_TIME coin = 0;
		int gem = 0;
		int frame = 15 + i;
		char text[32];
		sprintf(text, "%lld", reward);
		switch (type)
		{
		case DAILY_REWARD_TYPE_COIN:
		{
									   int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
									   INT_TIME reward_coin = GetDesignTreasure(_battle_current, param_coin, false);
									   reward *= reward_coin;
									   //sprintf(text, "%lld", reward);
									   ConvertMoneyInbalace(reward, text);
									   coin = reward;
									   
									   if (count_coin == 0)
									   {
										   frame = 15;
									   }
									   else if (count_coin == 1)
									   {
										   frame = 18;
									   }
									   else if (count_coin == 2)
									   {
										   frame = 45;
									   }
									   count_coin++;
		}
			break;
		case DAILY_REWARD_TYPE_GEM:
			sprintf(text, "%lld", reward);
			gem = reward;
			if (count_gem < 3)
			{
				frame = 16;
			}
			else if (count_gem < 5)
			{
				frame = 19;
			}
			else
			{
				frame = 46;
			}
			count_gem++;
			//frame = 19;
			break;
		case DAILY_REWARD_TYPE_RELIC:
			if (_wheel_relic._id == -1)
			{
				frame--;
				reward = 2 * GetDesignDailyReward(i-1, param_value);
				type = DAILY_REWARD_TYPE_GEM;
				sprintf(text, "%lld", reward);
				gem = reward;
			}
			else
			{
				frame = 17;
				sprintf(text, "%s", "RELIC");
			}
			break;
		case DAILY_REWARD_TYPE_BIG:
			if (!_user.CheckHeroColleted(HERO_ID_WOLF_RANGER))
			{
				type = DAILY_REWARD_TYPE_HERO;
				frame = 9;
			}
			else
			{
				reward = GetDesignDailyReward(3, param_value);
				int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
				INT_TIME reward_coin = GetDesignTreasure(_battle_current, param_coin, false);
				reward *= reward_coin;
				coin = reward;
				gem = GetDesignDailyReward(4, param_value);
				frame = 10;
			}
			break;
		default:
			break;
		}
		_daily_reward[i].Init(type,coin,gem,frame,text);
	}
	GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
}
void TDGame::DailyRewardRender(float x, float y)
{
	if (!_daily_reward_active)
	{
		return;
	}
    double angle = GAME()->_frame_counter;
    G()->SetScale(_daily_reward_effect_scale*5, _daily_reward_effect_scale*5, k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
    G()->SetRotate(angle, k_SCREEN_WIDTH/2 + x,k_SCREEN_HEIGHT/2+y);
    GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(),22,k_SCREEN_WIDTH/2 + x,k_SCREEN_HEIGHT/2+y);
    G()->ClearRotate();
    
    angle = GAME()->_frame_counter/2.0f;
    G()->SetScale(_daily_reward_effect_scale*6, _daily_reward_effect_scale*6, k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
    G()->SetRotate(-angle, k_SCREEN_WIDTH/2 + x,k_SCREEN_HEIGHT/2+y);
    GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(),22,k_SCREEN_WIDTH/2 + x,k_SCREEN_HEIGHT/2+y);
    G()->ClearRotate();
    
	G()->SetScale(_daily_reward_effect_scale, _daily_reward_effect_scale, k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
	GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 0, x, y);
	GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 28, x, y);
    float zoom = (CMath::SIN(CGame::_this->_frame_counter*3%180)*0.1f+1.0f)*_daily_reward_effect_scale;
    int mkx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(1 + _user._daily_reward_num, 0);
    int mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(1 + _user._daily_reward_num, 0) ;
    G()->SetScale(zoom,zoom, mkx, mky);
	GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 1 + _user._daily_reward_num, x, y);
    
    G()->SetScale(_daily_reward_effect_scale, _daily_reward_effect_scale, k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
	//GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 8, x, y);
    int title_mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleY(1 , 0) - 40;
    int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
    GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
    GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(),  x + k_SCREEN_WIDTH / 2, y + title_mky,300, _HCENTER , "Come back everyday for even better rewards!");
    
    GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
    //_user._daily_reward_num = 6;
    
	for (int i = 0; i < DAILY_REWARD_NUM; i++)
	{
        G()->SetScale(_daily_reward_effect_scale, _daily_reward_effect_scale, k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
		if (i < 6)
		{
			int mkx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(1 + i, 0);
			int mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(1 + i, 0) - 10;
            if(_user._daily_reward_num == i)
            {
                G()->SetScale(zoom,zoom, mkx, mky);
                
            }
            GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 21+i,x,y);
			GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), _daily_reward[i]._frameid, x + mkx, y + mky);
			if (i < _user._daily_reward_num)
			{
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 20, x + mkx, y + mky);
			}
            
			int text_mkx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(8, i + 7);
			int text_mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(8, i + 7);
			spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), text_mkx + x, text_mky + y + 2, _HCENTER | _VCENTER, "%s", _daily_reward[i]._text);
			GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
            G()->ClearScale();
            
		}
		else
		{
            int mkx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(7, 0);
            int mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(7, 0);
			if (_daily_reward[i]._type == DAILY_REWARD_TYPE_BIG)
			{
                if(_user._daily_reward_num == i)
                {
                    float zoom = (CMath::SIN(CGame::_this->_frame_counter*3%180)*0.1f+0.9f)*_daily_reward_effect_scale;
                    G()->SetScale(zoom,zoom, mkx, mky);
                }
                GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 21+i,x,y);
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 10, x, y);
                 G()->ClearScale();
                title_mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleY(7 , 0) - 10;
                GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(),  x + k_SCREEN_WIDTH / 2, y + title_mky,550, _HCENTER , "The reward of 7th Day will be a big reward");
			}
			if (_daily_reward[i]._type == DAILY_REWARD_TYPE_HERO)
			{
                if(_user._daily_reward_num == i)
                {
                   float zoom = (CMath::SIN(CGame::_this->_frame_counter*3%180)*0.1f+0.9f)*_daily_reward_effect_scale;
                     G()->SetScale(zoom,zoom, mkx, mky);
                }
                GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 21+i,x,y);
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 9, x, y);
                title_mky = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleY(7 , 0) - 10;
                G()->ClearScale();
                GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(),  x + k_SCREEN_WIDTH / 2, y + title_mky,550, _HCENTER , "The reward of 7th Day will be a legendary Hero");
			}
		}
	}
	for (int i = 0; i <DAILY_REWARD_NUM_BUTTON; i++)
	{
		_daily_button[i].Render(G());
		_daily_button[i].Update();
	}
	G()->ClearScale();
}
void TDGame::DailyRewardUpdate()
{
	if (!_daily_reward_active)
	{
		return;
	}
	if (!_daily_reward_close)
	{
		_daily_reward_effect_scale += 0.08f;
		if (_daily_reward_effect_scale >= 1.0f)
		{
			_daily_reward_effect_scale = 1.0f;
		}
		_ingame_fill_opac += 10;
		if (_ingame_fill_opac >= 100)
		{
			_ingame_fill_opac = 100;
		}
	}
	else
	{
		_daily_reward_effect_scale -= 0.1f;
		if (_daily_reward_effect_scale <= 0)
		{
			_daily_reward_effect_scale = 0;
			_daily_reward_active = false;
			ClearAllTouchUp(TOUCH_TYPE_INGAME);
		}
		if (_ingame_fill_opac > 0)
		{
			_ingame_fill_opac -= 10;
			if (_ingame_fill_opac <= 0)
			{
				_ingame_fill_opac = 0;
			}
		}
	}
	DailyRewardUpdateTouch();
}
bool TDGame::DailyRewardUpdateTouch()
{
	bool ret = false;
	int index = -1;
	if (_dialogMng.isOpenDialog())
	{
		return ret;
	}
	for (int i = 0; i < DAILY_REWARD_NUM_BUTTON; i++)
	{
		if (_daily_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_daily_button[index].NeedAction())
		{
			switch (index)
			{
			case DAILY_REWARD_BUTTON_CLAIM:
			{
											  char text[256];
											  switch (_daily_reward[_user._daily_reward_num]._type)
											  {
											  case DAILY_REWARD_TYPE_COIN:
											  {
												  char cointext[128];
												  ConvertMoneyInbalace(_daily_reward[_user._daily_reward_num]._coin, cointext);
													sprintf(text, "You have received\n%s ;", cointext);
													//sprintf(text, "You have received\n%lld ;", _daily_reward[_user._daily_reward_num]._coin);
											  }
												  break;
											  case DAILY_REWARD_TYPE_GEM:
											  {
												  char gemtext[128];
												  ConvertMoneyInbalace(_daily_reward[_user._daily_reward_num]._gem, gemtext);
												  sprintf(text, "You have received\n%s :", gemtext);
												  //sprintf(text, "You have received\n%d :", _daily_reward[_user._daily_reward_num]._gem);
											  }
												  
												  break;
											  case DAILY_REWARD_TYPE_RELIC:
													  sprintf(text, "You have received\nRelic= %s", _wheel_relic._name);
												  break;
											  case DAILY_REWARD_TYPE_BIG:
											  {
												  char cointext[128], gemtext[128];
												  ConvertMoneyInbalace(_daily_reward[_user._daily_reward_num]._coin, cointext);
												  ConvertMoneyInbalace(_daily_reward[_user._daily_reward_num]._gem, gemtext);
												  sprintf(text, "You have received\n%s ;, %s :", cointext, gemtext);
												  //sprintf(text, "You have received\n%lld ;, %d :", _daily_reward[_user._daily_reward_num]._coin, _daily_reward[_user._daily_reward_num]._gem);
											  }
												  
												  break;
											  case DAILY_REWARD_TYPE_HERO:
												  sprintf(text, "You have received\nHero= %s", "Mia");
												  break;
											  default:
												  break;
											  }
											  _user._has_bought_iap_dis_100 = false;
											  GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
											  _dialogMng.Add(DIALOG_CONTEXT_DAILY_REWARD, DIALOGTYPE_OK, ZOOM_IN_OUT_TRANSACTION, "DAILY LOGIN BONUS!", text, 0, 0);
											  
			}

				break;

			default:
				break;
			}

			for (int i = 0; i < DAILY_REWARD_NUM_BUTTON; i++)
			{
				if (_daily_button[i]._state != BUTTON_STATE_LOCK && _daily_button[i]._state != BUTTON_STATE_HIDE)
				{
					_daily_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < DAILY_REWARD_NUM_BUTTON; touch++)
		{
			if (_daily_button[touch]._state == BUTTON_STATE_LOCK || _daily_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _daily_button[touch].TZ_GetX();
			int y = _daily_button[touch].TZ_GetY();
			int w = _daily_button[touch].TZ_GetWidth();
			int h = _daily_button[touch].TZ_GetHeight();
			Button *button = &_daily_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						GAME()->PlaySFX(SFX_BUTTON);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
					}
				}
				if (button->_touch_id != -1)
				{
					pressed = true;
				}
			}
			else
			{

				if (button->IsAction(TOUCHS(i)->_id))
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void TDGame::DailyReward::Init(int type, INT_TIME value, int value2, int frame, char*text)
{
	_type = type;
	_coin = value;
	_gem = value2;
	_frameid = frame;
	sprintf(_text, "%s", text);
}




void CGame::GooglePlayShowLeaderBoard()
{
    if(IsAndroidVersion)
    {
#if defined (ANDROID_OS)
		if (!GAME()->_async_task_manager._on_process_show_leaderBoard)
		{
			TDGame *game = (TDGame*)GAME()->_current_game;
			GAME()->_gameBoardScoreItem.Score = game->_battle_current + 1;
			GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_POST_SCORE);

			GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_SHOW_LEADERBOARD);
			GAME()->_async_task_manager._on_process_show_leaderBoard = true;
		}
#endif
    }
    
}
void CGame::GooglePlayShowAchievement()
{
    if(IsAndroidVersion)
    {
#if defined (ANDROID_OS)
		if (!GAME()->_async_task_manager._on_process_show_achievement)
		{
			GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_SHOW_ACHIEVEMENTS);
			GAME()->_async_task_manager._on_process_show_achievement = true;
		}
#endif
    }

}
void CGame::GooglePlaySynDriver()
{
    if(IsAndroidVersion)
    {
#if defined (ANDROID_OS)
		if (!GAME()->_async_task_manager._on_process_sync_cloud)
		{
			//PDEBUG("Press SETTING_BUTTON_ICLOUD\n");
			TDGame *game = (TDGame*)GAME()->_current_game;
			game->_user.CheckLocalAndCloudSaveFile(false);
		}
#endif
    }

}
void CGame::GooglePlaySubmitAchievement(int index)
{
    if(IsAndroidVersion)
    {
#if defined (ANDROID_OS)
		GAME()->_async_task_manager._list_id_group_achievement_need_check_unlock[index-1] = true;
		GAME()->_async_task_manager.AddCommand(CAsyncTasks::enumTypeCommand::COMMAND_TYPE_ASYN_GOOGLE_PLAY_UNLOCK_ACHIEVEMENT);
#endif
    }

}
void TDGame::GetValueIapDis(char *idstr)
{
	if (strcmp(idstr, "NONE") == 0)
	{
		_iap_dis_autoskill = 0;
		_iap_dis_autoatt = 0;
		_iap_dis_gem = 0;
		_iap_dis_coin = 0;
		return;
	}
#if defined (ANDROID_OS)
	if (strcmp(idstr, "nfd_0_99_promo") == 0)
	{
		_iap_dis_gem = 100;
		sprintf(_iap_dis_price, "$0.99");
	}
	else if (strcmp(idstr, "nfd_4_99_promo") == 0)
	{
		_iap_dis_gem = 600;
		sprintf(_iap_dis_price, "$4.99");
	}
	else if (strcmp(idstr, "ndf_9_99_promo") == 0)
	{
		_iap_dis_gem = 1400;
		sprintf(_iap_dis_price, "$9.99");
	}
#else
	if (strcmp(idstr, "NFD_0.99_PROMO") == 0)
	{
		_iap_dis_gem = 100;
		sprintf(_iap_dis_price, "$0.99");
	}
	else if (strcmp(idstr, "NFD_4.99_PROMO") == 0)
	{
		_iap_dis_gem = 600;
		sprintf(_iap_dis_price, "$4.99");
	}
	else if (strcmp(idstr, "NFD_9.99_PROMO_2") == 0)
	{
		_iap_dis_gem = 1400;
		sprintf(_iap_dis_price, "$9.99");
	}
#endif
	else
	{
		for (int i = 0; i < _game_design.General.SheetiAP_instant_design_discount.stringValue._totalData; i++)
		{
#if defined (ANDROID_OS)
			if (strcmp(_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumString::GG_ID), idstr) == 0)
#else
			if (strcmp(_game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumString::ID), idstr) == 0)
#endif
			{
				_iap_dis_coin = _game_design.General.SheetiAP_instant_design_discount.int64Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumInt64::Coin);
				_iap_dis_gem = _game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumInt32::Gem);
				_iap_dis_autoatt = _game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumInt32::Auto_Attack);
				_iap_dis_autoskill = _game_design.General.SheetiAP_instant_design_discount.int32Value.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumInt32::Instant_Skill);
				sprintf(_iap_dis_price, "$%s", _game_design.General.SheetiAP_instant_design_discount.stringValue.getValue(i, CGameDesign::FileGeneral::CSheetiAP_instant_design_discount::enumString::Price));
			}
		}
	}

#if defined (MAC_OS)
	if (GAME()->_pineStore.IsSynPriceForProduct(idstr))
	{
		sprintf(_iap_dis_price, "%s", GAME()->_pineStore.GetPriceForProduct(idstr));
	}
	
#endif
	ConvertMoneyInbalace(_iap_dis_coin, _iap_dis_coin_text);
}
