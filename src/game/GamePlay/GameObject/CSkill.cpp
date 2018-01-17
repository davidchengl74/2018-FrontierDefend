#include "pch.h"
#include "../../GameCore/CGame.h"

CSkill::CSkill()
{
}

CSkill::~CSkill()
{
}

void CSkill::Init(int id, float x, float y, int damage)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	int param_xdamage = CGameDesign::FileSkill_design::CSheetSheet1::Damage;
	int param_duration = CGameDesign::FileSkill_design::CSheetSheet1::Duration;
	int param_hit = CGameDesign::FileSkill_design::CSheetSheet1::Hit;
	int param_hitdelay = CGameDesign::FileSkill_design::CSheetSheet1::Hit_delay;
	int param_type = CGameDesign::FileSkill_design::CSheetSheet1::Status;
	int param_name = CGameDesign::FileSkill_design::CSheetSheet1::Name;
	int param_aoe = CGameDesign::FileSkill_design::CSheetSheet1::AOE;
	int param_descript = CGameDesign::FileSkill_design::CSheetSheet1::Description;
	int param_crital = CGameDesign::FileSkill_design::CSheetSheet1::Critical;
	_id = id;
	sprintf(_name, "%s", game->GetDesignSkillString(_id, param_name));
	sprintf(_descript, "%s", game->GetDesignSkillString(_id, param_descript));
	_damage_multi = (game->GetDesignSkillInfo(_id,param_xdamage));
	_duration = game->GetDesignSkillInfo(_id, param_duration)*60;
	_hit = game->GetDesignSkillInfo(_id, param_hit);
	_hit_delay = game->GetDesignSkillInfo(_id, param_hitdelay);
	_type = game->GetDesignSkillInfo(_id, param_type);
	_aoe = game->GetDesignSkillInfo(_id, param_aoe);
	_active = false;
	_state = SKILL_STATE_NONE;
	SetPos(x, y);
	SetTarget(_x, _y);
	_sprite = game->_skill_sprite[_id];
	//game->LoadSpriteOptimize(_sprite);
	_anim.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_anim_effect.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_num_hitted = 0;
	_damage = 0;
	_critical = game->GetDesignSkillInfo(_id, param_crital);
	_has_critical = false;
	_num_partical = 5;
	_effect_fake_out_scale = 1.0f;
	_effect_fake_out_opac = 0;
	_effect_fake_out_count_frame = 0;
	_effect_hit_scale = 1.0f;
	_effect_hit_scale_max = false;
	_effect_hit_scale_start = false;
	switch (_id)
	{
	case HERO_SKILL_METOER_SHOWER:
		_frame = -1;
		_anim_index = 0;
		_rainshower.Init(RAIN_SHOWER_TYPE_ANIM, 50, SPRITEID_EFFECT_SKILL_MAGE, 0, 15, 0.02f, 0.75f);
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		break;
	case HERO_SKILL_ELECTRIC_BALL:
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, true);
		_num_partical = 20;
		for (int i = 0; i < _num_partical; i++)
		{
			int timemax = CMath::RANDOM(0, 45);
			_partical[i].Init(_sprite, 21, 2,  PARTICAL_TYPE_CIRCLE_CENTER, timemax,0.8f, true);
		}
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		break;
	case HERO_SKILL_BEAST_MASTER:
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, true);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index+1, true);
		_anim_effect.SetPos(_x, _y);
		for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
		{
			_beastmaster[i].Init(0, 0, _sprite, 13.0f);
		}
		break;
	case HERO_SKILL_CAT_NINJA:
	{
								 for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
								 {
									 _ninjastatue[i].Init(_sprite, _duration, _damage * HERO_SKILL_NIJA_X_HP);
								 }
								 
								 _frame = -1;
								 _anim_index = 0;
								 _anim.SetAnim(_anim_index, false);
								 _anim.SetPos(_x, _y);
								 _anim_effect.SetAnim(_anim_index, false);
								 _anim_effect.SetPos(_x, _y);
	}
		
		break;
	case HERO_SKILL_SANTA:
		_santaskill.Init(_x, _y, 7, _sprite);
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		break;
	case HERO_SKILL_SENTINEL:
		for (int i = 0; i < NUM_MAX_SKILL_ROBO; i++)
		{
			_roboskill[i].Init(_sprite, 13, 10.0f);
		}
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		break;
	case HERO_SKILL_ACHEMIST:
		_acidskill.Init(_sprite,_hit_delay);
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		break;
	case HERO_SKILL_GREATCLASH:
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index, false);
		_anim_effect.SetPos(_x, _y);
		for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
		{
			_wordflashskill[i].Init(0, 0, _sprite, 15.0f);
		}
		break;
	default:
		_frame = -1;
		_anim_index = 0;
		_anim.SetAnim(_anim_index, false);
		_anim.SetPos(_x, _y);
		_anim_effect.SetAnim(_anim_index , false);
		_anim_effect.SetPos(_x, _y);
		break;
	}
}
void CSkill::Render(float x, float y)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	//printf("\n render skill _state = %d", _state);
	if (_state == SKILL_STATE_NONE || _state == SKILL_STATE_END)
	{
		return;
	}
	if (_frame != -1)
	{
		GET_SPRITE(_sprite)->DrawFrame(G(), _frame, _x + x, _y + y);
	}
	else
	{
		switch (_id)
		{
		case HERO_SKILL_METOER_SHOWER:
			_rainshower.Render(x, y);
			break;
		case HERO_SKILL_ELECTRIC_BALL:
		{
										 int shakex = 0;
										 int shakey = 0;
										 // if (_effect_fake_out_count_frame % 2 == 0)
										 {
											 shakex = CMath::RANDOM(-3, 3);
											 shakey = CMath::RANDOM(-3, 3);
										 }
										 _anim.SetPos(_x + x + shakex, _y + y + shakey);
										 int render1 = _num_partical / 2;
										 for (int i = 0; i < render1; i++)
										 {
											 _partical[i].Render(_x + x, _y + y);
										 }
										 G()->SetScale(_effect_hit_scale, _effect_hit_scale, _x + x, _y + y);
										 _anim.DrawAnimObject(G());
										 G()->ClearScale();
										 G()->SetOpacity(_effect_fake_out_opac);
										 G()->SetScale(_effect_fake_out_scale, _effect_fake_out_scale, _x + x, _y + y);
										 _anim.DrawAnimObject(G());
										 G()->ClearScale();
										 G()->SetOpacity(100);
										 for (int i = render1; i < _num_partical; i++)
										 {
											 _partical[i].Render(_x + x, _y + y);
										 }


		}

			break;
		case HERO_SKILL_BEAST_MASTER:
		{
			int posx = 0;
			int posy = GET_SPRITE(_sprite)->GetFModuleCenterY(0, 0);
			_anim.SetPos(_x + x, _y + y);
			_anim_effect.SetPos(_x + x - 200, _y + y);
			int opac1 = 100;
			if (_state > SKILL_STATE_ACTIVE)
			{
				opac1 = _effect_fake_out_opac;
			}
			G()->SetScale(_effect_fake_out_scale, _effect_fake_out_scale, WEAPON_FROST_MAGE_POSX - 75 + x + posx + game->_point_o.X, ROAD_POSY + y + posy);
			G()->SetOpacity(opac1);
			GET_SPRITE(_sprite)->DrawFrame(G(), 1, WEAPON_FROST_MAGE_POSX - 75 + x + game->_point_o.X, ROAD_POSY + y);
			G()->SetOpacity(_effect_fake_out_opac);
			GET_SPRITE(_sprite)->DrawFrame(G(), 3, WEAPON_FROST_MAGE_POSX - 75 + x + game->_point_o.X, ROAD_POSY + y);
			G()->ClearScale();
			G()->SetOpacity(100);
			G()->SetClip(WEAPON_FROST_MAGE_POSX - 75 + game->_point_o.X, 0, game->_screen_width, k_SCREEN_HEIGHT);
			/*_anim.DrawAnimObject(G());
			_anim_effect.DrawAnimObject(G());*/
			for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
			{
				_beastmaster[i].Render(+game->_point_o.X, 0, 100);
			}
			G()->ClearClip();
			
			G()->SetScale(_effect_fake_out_scale, _effect_fake_out_scale, WEAPON_FROST_MAGE_POSX - 75 + x + posx + game->_point_o.X, ROAD_POSY + y + posy);
			G()->SetOpacity(opac1);
			GET_SPRITE(_sprite)->DrawFrame(G(), 0, WEAPON_FROST_MAGE_POSX - 75 + x + game->_point_o.X, ROAD_POSY + y);
			G()->SetOpacity(_effect_fake_out_opac);
			GET_SPRITE(_sprite)->DrawFrame(G(), 2, WEAPON_FROST_MAGE_POSX - 75 + x + game->_point_o.X, ROAD_POSY + y);
			G()->ClearScale();
			G()->SetOpacity(100);
		}
			break;
		case HERO_SKILL_CAT_NINJA:
			for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
			{
				_ninjastatue[i].Render(x, y);
			}
			
			break;
		case HERO_SKILL_SANTA:
			_santaskill.Render(x, y);
			break;
		case HERO_SKILL_SENTINEL:
			for (int i = 0; i < NUM_MAX_SKILL_ROBO; i++)
			{
				_roboskill[i].Render(x, y);
			}
			break;
		case HERO_SKILL_ACHEMIST:
			_acidskill.Render(x, y);
			break;
		case HERO_SKILL_GREATCLASH:
			for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
			{
				_wordflashskill[i].Render(0, 0,100);
			}
			break;
		default:
			_anim.SetPos(_x + x, _y + y);
			_anim.DrawAnimObject(G());
			break;
		}
	}
}
void CSkill::Update()
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	if (_state == SKILL_STATE_NONE || _state == SKILL_STATE_END)
	{
		return;
	}
	if (_frame == -1)
	{
		_anim.UpdateAnimObject();
		_anim_effect.UpdateAnimObject();
	}
	switch (_id)
	{
	case HERO_SKILL_GREATCLASH:
	{
		bool hasfree = false;
		int count_not_free = 0;
		int num_hit = 1;
		num_hit += game->GetRelicsUnitBounce(ITEMRELIC_GROUP_HERO, HERO_ID_PALADIN);
		for (int j = 0; j < num_hit; j++)
		{
			_wordflashskill[j].Update();
			if (_wordflashskill[j].IsFree())
			{
				continue;
			}
			count_not_free++;

			for (int i = 0; i < game->_num_enemy_inwave; i++)
			{
				float enemy_x = game->_enemy[i].GetPosX();
				//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE )
				if (game->_enemy[i].IsLive())
				{
					_wordflashskill[j].CheckEnemyAround(i, _aoe, _damage, _critical);
				}
			}
		}
		if (count_not_free > 0)
		{
			_state = SKILL_STATE_PLAYING;
		}
		else
		{
			_state = SKILL_STATE_END;
		}
	}
		break;
	case HERO_SKILL_METOER_SHOWER:
		_rainshower.Update();
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			//INT_TIME damage = _damage;
			//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE && game->_enemy[i].GetPosX() < k_SCREEN_WIDTH)
			if (game->_enemy[i].IsLive() && game->_enemy[i].GetPosX() < k_SCREEN_WIDTH)
			{
				_rainshower.CheckEnemyAround(i, _aoe, _damage, _critical);
			}
		}
		if (_rainshower.IsFree())
		{
			_state = SKILL_STATE_END;
		}
		break;
	case HERO_SKILL_ELECTRIC_BALL:
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			float enemy_x = game->_enemy[i].GetPosX();
			float enemy_y = game->_enemy[i].GetPosY();
			float enemy_w = game->_enemy[i]._size_w;
			//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE && enemy_x < game->_screen_width)
			if (game->_enemy[i].IsLive() && enemy_x < game->_screen_width)
			{
				if (_list_target[0][i] == -1)
				{
					if (CheckEnemyAround(enemy_x, enemy_y, enemy_w))
					{
						int rand = CMath::RANDOM(1, 100);
						INT_TIME damage = _damage;
						float posx = enemy_x + CMath::RANDOM(-3, 3) * 3;
						float posy = enemy_y - game->_enemy[i]._size_h + CMath::RANDOM(-5, 0) * 10;
						if (rand <= _critical)
						{
							damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
							game->_enemy[i].AddHP(-_damage, 1, SPRITEID_EFFECT_SKILL_MAGELIGHTING_01, false);
							game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
							game->_user._quest_num_critical_hit++;
						}
						else
						{
							game->_enemy[i].AddHP(-_damage, 1, SPRITEID_EFFECT_SKILL_MAGELIGHTING_01, false);
							game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
						}
						_list_target[0][i] = 10;
						_effect_hit_scale_start = true;
						_effect_hit_scale_max = false;
					}
				}
				else
				{
					_list_target[0][i] --;
					if (_list_target[0][i] <= 0)
					{
						_list_target[0][i] = -1;
					}
				}
			}
		}
		_x += _speed;
		_effect_fake_out_count_frame++;
		if (_effect_fake_out_count_frame >= 120)
		{
			_effect_fake_out_scale = 1.0f;
			_effect_fake_out_opac = 100;
			_effect_fake_out_count_frame = 0;
		}
		if (_effect_fake_out_opac > 0)
		{
			_effect_fake_out_opac -= 3;
			_effect_fake_out_scale += 0.03;
		}
		if (_effect_hit_scale_start)
		{
			if (_effect_hit_scale_max)
			{
				_effect_hit_scale -= 0.2f;
				if (_effect_hit_scale < 1.0f)
				{
					_effect_hit_scale = 1.0f;
					_effect_hit_scale_start = false;
				}
			}
			else
			{
				_effect_hit_scale += 0.3f;
				if (_effect_hit_scale >= 1.5f)
				{
					_effect_hit_scale_max = true;
					_effect_hit_scale = 1.5f;
				}
			}
		}
		for (int i = 0; i < _num_partical; i++)
		{
			if (_partical[i]._state == PARTICAL_STATE_END)
			{
				float speed = CMath::RANDOM(10, 50) / 100.0f;
				float speedrotate = CMath::RANDOM(5, 20) / 20.0f;
				float speedscale = CMath::RANDOM(1, 5) / 200.0f;
				_partical[i].Active(0, 0, 0, 0, speed, speedscale, 2, speedrotate);
			}
			_partical[i].Update();
		}
		_state = SKILL_STATE_PLAYING;
		if (_x >= game->_screen_width + 50)
		{
			_state = SKILL_STATE_END;
			for (int i = 0; i < _num_partical; i++)
			{
				_partical[i].ForceEnd();
			}

		}
		break;
	case HERO_SKILL_BEAST_MASTER:
	{
									bool hasfree = false;
									int count_not_free = 0;
		for (int j = 0; j < NUM_MAX_SKILL_BEAST_MASTER; j++)
		{
			_beastmaster[j].Update();
			if (_beastmaster[j].IsFree())
			{
				continue;
			}
			count_not_free++;
			
			for (int i = 0; i < game->_num_enemy_inwave; i++)
			{
				float enemy_x = game->_enemy[i].GetPosX();
				//if (game->_enemy[i].GetState() < CHARACTER_STATE_DIE && enemy_x < game->_screen_width && !game->_enemy[i]._fly_up)
				if (game->_enemy[i].IsLive() && enemy_x < game->_screen_width && !game->_enemy[i]._fly_up)
				{
					_beastmaster[j].CheckEnemyAround(i, _aoe, _damage, _critical);
				}
			}
		}
		if (count_not_free > 0)
		{
			_state = SKILL_STATE_PLAYING;
		}
		if (count_not_free < 2)
		{
			if (_effect_fake_out_opac > 0)
			{
				_effect_fake_out_opac -= 5;
				if (_effect_fake_out_opac <= 0)
				{
					_effect_fake_out_opac = 0;
				}
			}
		}
		else
		{
			if (_effect_hit_scale < 1.0f)
			{
				_effect_hit_scale += 0.2f;
				if (_effect_hit_scale >= 1.0f)
				{
					_effect_hit_scale = 1.0f;
				}
			}
			if (_effect_fake_out_opac < 100)
			{
				_effect_fake_out_opac += 2;
				if (_effect_hit_scale >= 1.0f)
				{
					_effect_fake_out_opac += 4;
				}

				if (_effect_fake_out_opac >= 100)
				{
					_effect_fake_out_opac = 100;
					//_state = SKILL_STATE_PLAYING;
				}
			}
		}
	}
		break;
	case HERO_SKILL_CAT_NINJA:
	{
		bool hasfree = false;
		for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
		{
			_ninjastatue[i].Update();
			if (!_ninjastatue[i].IsFree())
			{
				hasfree = true;
			}
		}
		if (hasfree)
		{
			_state = SKILL_STATE_PLAYING;
		}
	}
		break;
	case HERO_SKILL_SANTA:
		_santaskill.Update();
		if (_santaskill.IsFree())
		{
			_state = SKILL_STATE_END;
		}
		else
		{
			_state = SKILL_STATE_PLAYING;
		}
		_santaskill.CheckEnemyAround(_aoe, _damage, _critical);
		break;
	case HERO_SKILL_SENTINEL:
		_state = SKILL_STATE_END;
		for (int i = 0; i < NUM_MAX_SKILL_ROBO; i++)
		{
			_roboskill[i].Update();
			if (_roboskill[i].IsFree())
			{
				continue;
			}
			else
			{
				_state = SKILL_STATE_READY;
			}
		}
		
		break;
	case HERO_SKILL_ACHEMIST:
		_acidskill.Update();
		if (_acidskill.IsFree())
		{
			_state = SKILL_STATE_END;
		}
		else
		{
			_state = SKILL_STATE_PLAYING;
		}
		break;
	default:
		break;
	}
	switch (_type)
	{
	case HERO_SKILL_TYPE_PALADIN:
		break;
	case HERO_SKILL_TYPE_NONE:
		break;
	case HERO_SKILL_TYPE_BURN_AIR:
	{

									 bool hasfree = true;
									 for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
									 {
										 if (!_beastmaster[i].IsFree())
										 {
											 hasfree = false;
											 break;
										 }
									 }
									 if (hasfree)
									 {
										 _state = SKILL_STATE_END;

									 }
	}
		break;
	case HERO_SKILL_TYPE_STUN:
		/*if (GetNumTarget() <= 0)
		{
			_state = SKILL_STATE_END;
		}*/
		break;
	case HERO_SKILL_TYPE_KNOCKBACK:
		if (_anim.IsCurrentAnimStop())
		{
			_anim.SetAnim(_anim_index, false);
		}
		if (_dis_fly > 0)
		{
			_dis_fly += _speed;
		}
		for (int i = 0; i < NUM_MAX_TARGET; i++)
		{
			if (_list_target[1][i] != -1)
			{
				if (_dis_fly < _aoe)
				{
					//if (game->_enemy[_list_target[1][i]].GetState() < CHARACTER_STATE_DIE && game->_enemy[_list_target[1][i]].GetPosX() < game->_screen_width)
					if (game->_enemy[_list_target[1][i]].IsLive() && game->_enemy[_list_target[1][i]].GetPosX() < game->_screen_width)
					{
						int target = game->_enemy[_list_target[1][i]].GetPosX();
						float posy = game->_enemy[_list_target[1][i]].GetPosY();
						//printf("\n ")
						if (_x + 100 >= target && game->_enemy[_list_target[1][i]]._status < CHARACTER_STATUS_FLY)
						{
							game->_enemy[_list_target[1][i]].SetState(CHARACTER_STATE_BEHIT);
							game->_enemy[_list_target[1][i]].SetPos(_x + 100, game->_enemy[_list_target[1][i]].GetPosY());
							if (_list_target[0][i] == 0)
							{
								game->_enemy[_list_target[1][i]].AddHP(-_damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
								float posx = game->_enemy[_list_target[1][i]].GetPosX() + CMath::RANDOM(-3, 3) * 3;
								float posy = game->_enemy[_list_target[1][i]].GetPosY() - game->_enemy[_list_target[1][i]]._size_h + CMath::RANDOM(-5, 0) * 10;
								if (_has_critical)
								{
									
									game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
								}
								else
								{
									game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
								}
								
								_list_target[0][i] = -1;
							}
							if (_dis_fly == 0)
							{
								_dis_fly = _speed;
							}
						}
					}
				}
				else
				{
					//if (game->_enemy[_list_target[1][i]].GetState() < CHARACTER_STATE_DIE && game->_enemy[_list_target[1][i]].GetPosX() < game->_screen_width)
					if (game->_enemy[_list_target[1][i]].IsLive() && game->_enemy[_list_target[1][i]].GetPosX() < game->_screen_width)
					{
						int target = game->_enemy[_list_target[1][i]].GetPosX();
						float posy = game->_enemy[_list_target[1][i]].GetPosY();
						//printf("\n ")
						if (_x + 100 >= target && game->_enemy[_list_target[1][i]]._status < CHARACTER_STATUS_FLY)
						{
							game->_enemy[_list_target[1][i]].SetState(CHARACTER_STATE_BEHIT);
							game->_enemy[_list_target[1][i]].SetPos(_x + 100, game->_enemy[_list_target[1][i]].GetPosY());
							if (_list_target[0][i] == 0 && target <= game->_screen_width)
                            {
								float posx = game->_enemy[_list_target[1][i]].GetPosX() + CMath::RANDOM(-3, 3) * 3;
								float posy = game->_enemy[_list_target[1][i]].GetPosY() - game->_enemy[_list_target[1][i]]._size_h + CMath::RANDOM(-5, 0) * 10;
								game->_enemy[_list_target[1][i]].AddHP(-_damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
								if (_has_critical)
								{
									
									game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
								}
								else
								{
									game->AddEffectHPLost(_damage, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
								}
                                _list_target[0][i] = -1;
                            }
							_list_target[1][i] = -1;
						}
					}
				}
			}
		}
		_x += _speed;
		
		if (_x > game->_screen_width + 100)
		{
			_state = SKILL_STATE_END;
		}
		break;
	case HERO_SKILL_TYPE_CRITICAL:
		_state = SKILL_STATE_END;
		break;
	case HERO_SKILL_TYPE_STATUE:
	{

								   bool hasfree = true;
								   for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
								   {
									   if (!_ninjastatue[i].IsFree())
									   {
										   hasfree = false;
										   break;
									   }
								   }
								   if (hasfree)
								   {
									   _state = SKILL_STATE_END;
									   for (int i = 0; i < _num_partical; i++)
									   {
										   _partical[i].ForceEnd();
									   }
								   }
								   //printf("\n skill _state = %d", _state);
	}
		break;
	case HERO_SKILL_TYPE_SANTA:
		break;
	case HERO_SKILL_TYPE_ROBO:
		break;
	default:
		if (GetNumTarget() <= 0)
		{
			_state = SKILL_STATE_END;
		}
		break;
	}
	
}
void CSkill::Active(float x, float y, float tarx, float tary, float speed, INT_TIME damage, int duration)
{
	TDGame * game = (TDGame*)GAME()->_current_game;
	SetPos(x, y);
	SetTarget(tarx, tary);
	_state = SKILL_STATE_ACTIVE;
	_speed = speed;
	_dis_fly = 0;
	_damage = (_damage_multi/100.0f)*damage;
	switch (_id )
	{
	case HERO_SKILL_METOER_SHOWER:
		_rainshower.Active(k_SCREEN_WIDTH/2, 0, 200, ROAD_POSY, 0);
		break;
	case HERO_SKILL_ELECTRIC_BALL:
	{
									 for (int i = 0; i < _num_partical; i++)
									 {
										 float speed = (float)(CMath::RANDOM(10, 50) / 100.0f);
										 float speedrotate = (float)CMath::RANDOM(5, 20) / 20.0f;
										 float speedscale = (float)CMath::RANDOM(1, 5) / 200.0f;
										 _partical[i].Active(0, 0, tarx, tary, speed, speedscale, 2, speedrotate);
									 }
	}
	GAME()->PlaySFX(SFX__ELECTRICMAGE_SKILL);
		break;
	case HERO_SKILL_BEAST_MASTER:
	{
									int count_frame = 0;
									for (int i = 0; i < NUM_MAX_SKILL_BEAST_MASTER; i++)
									{
										if (_beastmaster[i].IsFree())
										{
											_beastmaster[i].Active(x, y + CMath::RANDOM(-5, 10) * 2, count_frame * 20 + CMath::RANDOM(0, 10) * 4, _speed);
											count_frame++;
										}
									}
									_effect_fake_out_opac = 0;
									_effect_hit_scale = 0;
	}
		break;
	case HERO_SKILL_CAT_NINJA:
		for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
		{
			if (_ninjastatue[i].IsFree())
			{
				_ninjastatue[i].Active(x, y, _damage * HERO_SKILL_NIJA_X_HP, _duration + duration, _damage, _aoe, _critical);
				break;
			}
		}
		GAME()->PlaySFX(SFX_CATNINJA_SKILL);
		break;
	case HERO_SKILL_SANTA:
		_santaskill.Active(0,0);
		break;
	case HERO_SKILL_SENTINEL:
		for (int i = 0; i < NUM_MAX_SKILL_ROBO; i++)
		{
			if (_roboskill[i].IsFree())
			{
				_roboskill[i].Active(x,y-120,x + CMath::RANDOM(-5, 5) * 10, y - CMath::RANDOM(15, 20) * 10, _hit_delay, _duration + duration, _damage, _critical);
				break;
			}
		}
		break;
	case HERO_SKILL_ACHEMIST:
		_acidskill.Active(x, y, _duration + duration, _damage, _aoe, _critical);
		break;
	case HERO_SKILL_GREATCLASH:
	{
									int count_frame = 0;
									int num_hit = 1;
									num_hit += game->GetRelicsUnitBounce(ITEMRELIC_GROUP_HERO, HERO_ID_PALADIN);
									if (num_hit >= NUM_MAX_SKILL_BEAST_MASTER)
									{
										num_hit = NUM_MAX_SKILL_BEAST_MASTER;
									}
									for (int i = 0; i < num_hit; i++)
									{
										if (_wordflashskill[i].IsFree())
										{
											_wordflashskill[i].Active(x, y , count_frame * 25 , _speed);
											count_frame++;
										}
									}
	}
		break;
	default:
		break;
	}
}
void CSkill::Reset()
{
	for (int i = 0; i < NUM_MAX_TARGET; i++)
	{
		_list_target[1][i] = -1;
		_list_target[0][i] = -1;
	}
	_state = SKILL_STATE_NONE;
}

int CSkill::GetID()
{
	return _id;
}
const char* CSkill::GetName()
{
	return _name;
}
int CSkill::GetDamageMulti()
{
	return _damage_multi;
}

int CSkill::GetDurarion()
{
	return _duration;
}
int CSkill::GetNumHit()
{
	return _hit;
}
int CSkill::GetHitDelay()
{
	return _hit_delay;
}
int CSkill::GetType()
{
	return _type;
}
bool CSkill::IsActived()
{
	return _active;
}
int CSkill::GetState()
{
	return _state;
}
float CSkill::GetPosX()
{
	return _x;
}
float CSkill::GetPosY()
{
	return _y;
}
void CSkill::SetPos(float x, float y)
{
	_x = x;
	_y = y;
}
void CSkill::SetTarget(float tarx, float tary)
{
	_targetx = tarx;
	_targety = tary;
}

void CSkill::AddTarget(int index)
{
	for (int i = 0; i < NUM_MAX_TARGET; i++)
	{
		if (_list_target[1][i] == -1)
		{
			_list_target[1][i] = index;
			_list_target[0][i] = 0;
			break;
		}
	}
}
int CSkill::GetNumTarget()
{
	int num = 0;
	for (int i = 0; i < NUM_MAX_TARGET; i++)
	{
		if (_list_target[1][i] != -1)
		{
			num++;
		}
	}
	return num;
}
const char* CSkill::GetDescript()
{
	return _descript;
}

bool CSkill::CheckEnemyAround(float x, float y, int w)
{
	float dis = CMath::DISTANCE(_x, _y, x, y);
	if (dis <= (w/2 + _aoe/2))
	{
		return true;
	}
	return false;
}

bool CSkill::IsFree()
{
	if (_state == SKILL_STATE_END || _state == SKILL_STATE_NONE || _state == SKILL_STATE_READY)
	{
		return true;
	}
	return false;
}

bool CSkill::HasStatue()
{
	for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
	{
		if (!_ninjastatue[i].IsFree())
		{
			return true;
		}
	}
	return false;
}

void CSkill::AddHPStatue(INT_TIME hp)
{
	for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
	{
		if (!_ninjastatue[i].IsFree())
		{
			_ninjastatue[i].AddHP(hp);
			break;
		}
	}
}
void CSkill::AddDrawAnim(float x, float y)
{
	switch (_id)
	{
	case HERO_SKILL_ACHEMIST:
		_acidskill.AddDrawManager(x, y);
		break;
	case HERO_SKILL_CAT_NINJA:
		for (int i = 0; i < NUM_MAX_SKILL_STATUE; i++)
		{
			if (!_ninjastatue[i].IsFree())
			{
				_ninjastatue[i].AddDrawManager(x, y);
				break;
			}
		}
		break;
	default:
		break;
	}
}