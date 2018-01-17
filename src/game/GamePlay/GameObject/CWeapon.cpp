#include "pch.h"
#include "../../GameCore/CGame.h"

CWeapon::CWeapon()
{
}

CWeapon::~CWeapon()
{
	
}

void CWeapon::Init(int type, int level,bool block)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	int param_speedatt = CGameDesign::FileCastle_design::CSheetCastle_General::Speed;
	int param_critical = CGameDesign::FileCastle_design::CSheetCastle_General::Critical;
	int param_aoe = CGameDesign::FileCastle_design::CSheetCastle_General::AOE;
	int param_lv_limited = CGameDesign::FileCastle_design::CSheetCastle_General::Battle_Unlock;
	_type = type;
	_level = level;
	_is_block = block;
	_level_max = false;
	_level_limited = 1;
	_damage_extra = 0;
	if (_level >= game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData)
	{
		_level = game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData;
		_level_max = true;
	}
	_damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	if (_is_block)
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level, param_cost_upgrade);
	}
	else
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	}
	_level_limited = game->GetDesignCastleGeneral(_type + 1, param_lv_limited);
	_attack_speed = game->GetDesignCastleGeneral(_type+1,param_speedatt);
	_critical_percent = game->GetDesignCastleGeneral(_type + 1, param_critical);
	_aoe = game->GetDesignCastleGeneral(_type + 1, param_aoe);
	_count_frame_attack = 0;
	_num_throwobject_active = 0;
	
	int type_attack = THROWOBJECT_TYPE_FOCUS;
	int time_weapon = 10;
	float weight = 5;
	_anim_width = 0;
	_anim_height = 0;
	switch (_type)
	{
	case WEAPON_ARCHER:
		_x = WEAPON_ACHER_POSX + game->_point_o.X;
		_y = WEAPON_ACHER_POSY + game->_point_o.Y;
		_anim_height = 30;
		break;
	case WEAPON_FIRE_MAGE:
		type_attack = THROWOBJECT_TYPE_AOE;
		_x = WEAPON_FIRE_MAGE_POSX + game->_point_o.X;
		_y = WEAPON_FIRE_MAGE_POSY + game->_point_o.Y;
		_anim_width = 35;
		_anim_height = 30;
		break;
	case WEAPON_CANNON:
		type_attack = THROWOBJECT_TYPE_AOE;
		_x = WEAPON_CANNON_POSX + game->_point_o.X;
		_y = WEAPON_CANNON_POSY + game->_point_o.Y;
		weight = 10;
		_anim_width = 30;
		_anim_height = 50;
		time_weapon = 20;
		break;
	case WEAPON_ELECTRIC:
		_x = WEAPON_ELECTRIC_POSX + game->_point_o.X;
		_y = WEAPON_ELECTRIC_POSY + game->_point_o.Y;
		_anim_width = 25;
		_anim_height = 90;
		break;
	case WEAPON_FROST_MAGE:
		_x = WEAPON_FROST_MAGE_POSX + game->_point_o.X;
		_y = WEAPON_FROST_MAGE_POSY + game->_point_o.Y;
		_anim_width = 0;
		_anim_height = 40;
		type_attack = THROWOBJECT_TYPE_AOE;
		break;
	case WEAPON_TWIN:
		_x = WEAPON_TWIN_POSX + game->_point_o.X;
		_y = WEAPON_TWIN_POSY + game->_point_o.Y;
		_anim_width = 0;
		_anim_height = 65;
		time_weapon = 3;
		break;
	case WEAPON_HOLY:
		_x = WEAPON_HOLY_POSX + game->_point_o.X;
		_y = WEAPON_HOLY_POSY + game->_point_o.Y;
		_anim_width = 84;
		_anim_height = 315;
		type_attack = THROWOBJECT_TYPE_AOE;
		break;
	case WEAPON_DARKNESS:
		_x = WEAPON_DARKNESS_POSX + game->_point_o.X;
		_y = WEAPON_DARKNESS_POSY + game->_point_o.Y;
		_anim_width = 35;
		_anim_height = 130;
		break;
	case WEAPON_DRAGON:
		_x = WEAPON_DRAGON_POSX + game->_point_o.X;
		_y = WEAPON_DRAGON_POSY + game->_point_o.Y;
		_anim_width = 190;
		_anim_height = 65;
		break;
	case WEAPON_CHIMERA:
		_x = WEAPON_CHIMERA_POSX + game->_point_o.X;
		_y = WEAPON_CHIMERA_POSY + game->_point_o.Y;
		_anim_width = 124;
		_anim_height = 220;
		type_attack = THROWOBJECT_TYPE_AOE;
		break;
	default:
		break;
	}
	_num_unit_bounce = 0;
	_spriteid = game->_weapon_sprite[_type];
	game->LoadSpriteOptimize(_spriteid,false,false);
	int frame = 1;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(0, false);
	_anim.SetPos(_x - _anim_width, _y + _anim_height);
	GetRelicsBonus();
	for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
	{
		_throwObject[i].Init(_spriteid, frame, 0 + game->_point_o.X, ROAD_POSY + game->_point_o.Y, _y, _x, weight, time_weapon, _type, type_attack, _critical_percent, _aoe);
	}
	_throwObject_index_free = -1;
	//printf("\n damage = %lld", _damage);
}
void CWeapon::Modify()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	int param_speedatt = CGameDesign::FileCastle_design::CSheetCastle_General::Speed;
	int param_critical = CGameDesign::FileCastle_design::CSheetCastle_General::Critical;
	int param_aoe = CGameDesign::FileCastle_design::CSheetCastle_General::AOE;
	_damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	if (_is_block)
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level, param_cost_upgrade);
	}
	else
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	}

	_attack_speed = game->GetDesignCastleGeneral(_type + 1, param_speedatt);
	_critical_percent = game->GetDesignCastleGeneral(_type + 1, param_critical);
	_aoe = game->GetDesignCastleGeneral(_type + 1, param_aoe);
	_count_frame_attack = 0;
	_num_throwobject_active = 0;

	int type_attack = THROWOBJECT_TYPE_FOCUS;
	int time_weapon = 10;
	float weight = 5;
	_anim_width = 0;
	_anim_height = 0;
	switch (_type)
	{
	case WEAPON_ARCHER:
		_x = WEAPON_ACHER_POSX + game->_point_o.X;
		_y = WEAPON_ACHER_POSY + game->_point_o.Y;
		_anim_height = 30;
		break;
	case WEAPON_FIRE_MAGE:
		type_attack = THROWOBJECT_TYPE_AOE;
		_x = WEAPON_FIRE_MAGE_POSX + game->_point_o.X;
		_y = WEAPON_FIRE_MAGE_POSY + game->_point_o.Y;
		_anim_width = 35;
		_anim_height = 30;
		break;
	case WEAPON_CANNON:
		type_attack = THROWOBJECT_TYPE_AOE;
		_x = WEAPON_CANNON_POSX + game->_point_o.X;
		_y = WEAPON_CANNON_POSY + game->_point_o.Y;
		weight = 10;
		_anim_width = 30;
		_anim_height = 50;
		time_weapon = 20;
		break;
	case WEAPON_ELECTRIC:
		_x = WEAPON_ELECTRIC_POSX + game->_point_o.X;
		_y = WEAPON_ELECTRIC_POSY + game->_point_o.Y;
		_anim_width = 25;
		_anim_height = 90;
		break;
	case WEAPON_FROST_MAGE:
		_x = WEAPON_FROST_MAGE_POSX + game->_point_o.X;
		_y = WEAPON_FROST_MAGE_POSY + game->_point_o.Y;
		_anim_width = 0;
		_anim_height = 40;
		type_attack = THROWOBJECT_TYPE_AOE;
		break;
	case WEAPON_TWIN:
		_x = WEAPON_TWIN_POSX + game->_point_o.X;
		_y = WEAPON_TWIN_POSY + game->_point_o.Y;
		_anim_width = 0;
		_anim_height = 65;
		time_weapon = 3;
		break;
	case WEAPON_HOLY:
		_x = WEAPON_HOLY_POSX + game->_point_o.X;
		_y = WEAPON_HOLY_POSY + game->_point_o.Y;
		_anim_width = 84;
		_anim_height = 315;
		type_attack = THROWOBJECT_TYPE_AOE;
		break;
	case WEAPON_DARKNESS:
		_x = WEAPON_DARKNESS_POSX + game->_point_o.X;
		_y = WEAPON_DARKNESS_POSY + game->_point_o.Y;
		_anim_width = 35;
		_anim_height = 130;
		break;
	case WEAPON_DRAGON:
		_x = WEAPON_DRAGON_POSX + game->_point_o.X;
		_y = WEAPON_DRAGON_POSY + game->_point_o.Y;
		_anim_width = 190;
		_anim_height = 65;
		break;
	case WEAPON_CHIMERA:
		_x = WEAPON_CHIMERA_POSX + game->_point_o.X;
		_y = WEAPON_CHIMERA_POSY + game->_point_o.Y;
		_anim_width = 30;
		_anim_height = 35;
		break;
	default:
		break;
	}
	_spriteid = game->_weapon_sprite[_type];
	game->LoadSpriteOptimize(_spriteid,false,false);
	int frame = 1;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(0, false);
	_anim.SetPos(_x - _anim_width, _y + _anim_height);
	GetRelicsBonus();
	for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
	{
		_throwObject[i].Init(_spriteid, frame, 0 + game->_point_o.X, ROAD_POSY + game->_point_o.Y, _y, _x, weight, time_weapon, _type, type_attack, _critical_percent, _aoe);
	}
	_throwObject_index_free = -1;
}
void CWeapon::Render(float x, float y, int opac)
{
	if (_is_block)
	{
		return;
	}
	
	for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
	{
		_throwObject[i].Render(x , y, opac);
	}
}
void CWeapon::RenderEffectShadow(float x, float y)
{
	if (_is_block)
	{
		return;
	}
	for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
	{
		_throwObject[i].RenderShadow(x, y);
	}
}
void CWeapon::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_is_block)
	{
		return;
	}
	_anim.UpdateAnimObject();
	float pointx = game->_point_o.X / 2;
	float pointy = game->_point_o.Y;
	if (_anim.IsCurrentAnimStop())
	{
		if (_state == WEAPON_STATE_ATTACK)
		{
			if (_type != WEAPON_CANNON && _type != WEAPON_HOLY && _type != WEAPON_DARKNESS && _type != WEAPON_DRAGON && _type != WEAPON_CHIMERA)
			{
				if (_enemy_index_target >= 0)
				{
					int sizew = 20/*game->_enemy[_enemy_index_target]._size_w / 2*/;
					int sizeh = game->_enemy[_enemy_index_target]._size_h / 4;
					int tarx = game->_enemy[_enemy_index_target].GetPosX() - sizew + pointx;
					int tary = game->_enemy[_enemy_index_target].GetPosY() - sizeh + pointy;
					if (game->_enemy[_enemy_index_target].GetState() == CHARACTER_STATE_WALK)
					{
						tarx -= game->_enemy[_enemy_index_target].GetSpeed() * 30;
						if (tarx < ENEMY_TARGETX + pointx - sizew)
                        {
							tarx = ENEMY_TARGETX + pointx - sizew;
                        }
					}
					
					if (tarx >= game->_screen_width)
					{
						tarx = -CMath::RANDOM(5, 10) * 5 + game->_screen_width;
					}
					if (_throwObject_index_free >= 0)
					{
						_throwObject[_throwObject_index_free].Active(tarx, tary, GetDamageTotal(), _enemy_index_target,_aoe);
						
						if (_num_unit_bounce > 0 && _type == WEAPON_ARCHER)
						{
							for (int i = 0; i < _num_unit_bounce - 1; i++)
							{
								for (int k = 0; k < NUM_MAX_THROWOBJECT; k++)
								{
									if (_throwObject[k].IsEnd())
									{
										_enemy_index_target = game->GetEnemyIndexHPUpper();
										sizew = 20/*game->_enemy[_enemy_index_target]._size_w / 2*/;
										sizeh = game->_enemy[_enemy_index_target]._size_h / 4;
										tarx = game->_enemy[_enemy_index_target].GetPosX() - sizew + pointx;
										tary = game->_enemy[_enemy_index_target].GetPosY() - sizeh + pointy;
										_throwObject[k].Active(tarx, tary, GetDamageTotal(), _enemy_index_target, _aoe);
										break;
									}
								}
								
							}
						}
						_throwObject_index_free = -1;
					}
				}
			}
		}
		SetState(WEAPON_STATE_IDLE);
	}
	else
	{
		if (_state == WEAPON_STATE_ATTACK)
		{
			if (_type == WEAPON_CANNON || _type == WEAPON_HOLY || _type == WEAPON_DRAGON || _type == WEAPON_CHIMERA)
			{
				int frame_mk = 4;
				if (_type == WEAPON_HOLY)
				{
					frame_mk = 7;
				}
				if (_type == WEAPON_DRAGON)
				{
					frame_mk = 13;
				}
				if (_type == WEAPON_CHIMERA)
				{
					frame_mk = 9;
				}
				if (_anim._current_aframes - GET_SPRITE(_spriteid)->GetFirstAFrameID(_anim.GetCurrentAnim()) == frame_mk)
				{
					if (_enemy_index_target >= 0)
					{
						int sizew = 20/*game->_enemy[_enemy_index_target]._size_w / 2*/;
						int sizeh = game->_enemy[_enemy_index_target]._size_h / 4;
						int tarx = game->_enemy[_enemy_index_target].GetPosX() - sizew + pointx;
						int tary = game->_enemy[_enemy_index_target].GetPosY() - sizeh + pointy;
						if (game->_enemy[_enemy_index_target].GetState() == CHARACTER_STATE_WALK)
						{
							if (_type != WEAPON_ELECTRIC)
							{
								tarx -= game->_enemy[_enemy_index_target].GetSpeed() * 40 ;
							}
							if (tarx < ENEMY_TARGETX + pointx - sizew)
                            {
								tarx = ENEMY_TARGETX + pointx - sizew;
                            }
						}
						
						if (tarx >= game->_screen_width)
						{
							tarx = -CMath::RANDOM(5, 10) * 10 + game->_screen_width;
						}
						if (_throwObject_index_free >= 0)
						{
							_throwObject[_throwObject_index_free].Active(tarx, tary, GetDamageTotal(), _enemy_index_target,_aoe);
							_throwObject_index_free = -1;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
	{
		_throwObject[i].Update();
	}
	_count_frame_attack++;
	if (_count_frame_attack >= _attack_speed)
	{
		for (int i = 0; i < NUM_MAX_THROWOBJECT; i++)
		{
			if(_throwObject[i].IsEnd())
			{
				if (_type == WEAPON_ARCHER)
				{
					_enemy_index_target = game->GetEnemyIndexHPLower();
				}
				else if (_type == WEAPON_TWIN)
				{
					if (_throwObject[i]._is_frame1)
					{
						_enemy_index_target = game->GetEnemyIndexHPLower();
					}
					else
					{
						_enemy_index_target = game->GetEnemyIndexNearest(true);
					}
				}
				else
				{
					if (_type == WEAPON_ARCHER || _type == WEAPON_FROST_MAGE || _type == WEAPON_FIRE_MAGE)
					{
						_enemy_index_target = game->GetEnemyIndexNearest(true);
					}
					else
					{
						_enemy_index_target = game->GetEnemyIndexNearest(false);
					}
				}
				if (_type == WEAPON_DARKNESS)
				{
					_throwObject[i].Active(0, 0, GetDamageTotal(), 0, _aoe);
					_count_frame_attack = 0;
				}
				if (_enemy_index_target >= 0 && game->_enemy[_enemy_index_target].GetPosX() < game->_screen_width)
				{
					if (_state == WEAPON_STATE_ATTACK)
					{
						while (!_anim.IsCurrentAnimStop())
						{
							_anim.UpdateAnimObject();
							//return;
						}
						if (_enemy_index_target >= 0)
						{
							int sizew = 20/*game->_enemy[_enemy_index_target]._size_w / 2*/;
							int sizeh = game->_enemy[_enemy_index_target]._size_h / 4;
							int tarx = game->_enemy[_enemy_index_target].GetPosX() - sizew + pointx;
							int tary = game->_enemy[_enemy_index_target].GetPosY() - sizeh + pointy;
							if (game->_enemy[_enemy_index_target].GetState() == CHARACTER_STATE_WALK)
							{
								tarx -= game->_enemy[_enemy_index_target].GetSpeed() * 40 ;
								if (tarx < ENEMY_TARGETX + pointx - sizew)
                                {
									tarx = ENEMY_TARGETX + pointx - sizew;
                                }
							}
							
							if (tarx >= game->_screen_width)
							{
								tarx = -CMath::RANDOM(5, 10) * 5 + game->_screen_width;
							}
							if (tary < ENEMY_TARGETY - 100)
							{
								tary = ROAD_POSY;
							}
							_throwObject[i].Active(tarx, tary, GetDamageTotal(), _enemy_index_target,_aoe);
							if (_num_unit_bounce > 0 && _type == WEAPON_ARCHER)
							{
								for (int j = 0; j < _num_unit_bounce - 1; j++)
								{
									for (int k = 0; k < NUM_MAX_THROWOBJECT; k++)
									{
										if (_throwObject[k].IsEnd())
										{
											_enemy_index_target = game->GetEnemyIndexHPUpper();
											sizew = 20/*game->_enemy[_enemy_index_target]._size_w / 2*/;
											sizeh = game->_enemy[_enemy_index_target]._size_h / 4;
											tarx = game->_enemy[_enemy_index_target].GetPosX() - sizew + pointx;
											tary = game->_enemy[_enemy_index_target].GetPosY() - sizeh + pointy;
											_throwObject[k].Active(tarx, tary, GetDamageTotal(), _enemy_index_target, _aoe);
											break;
										}
									}
									
								}
							}
						}
					}
					if (_enemy_index_target >= 0)
					{
						SetState(WEAPON_STATE_ATTACK);
						_count_frame_attack = 0;
						_throwObject_index_free = i;
					}
				}
				break;
			}
		}
	}
	
}
int CWeapon::GetType()
{
	return _type;
}
int CWeapon::GetAttackSpeed()
{
	return _attack_speed;
}
void CWeapon::SetAttackSpeed(int speedatt)
{
	_attack_speed = speedatt;
}
INT_TIME CWeapon::GetDamage()
{
	return GetDamageTotal();
}
INT_TIME CWeapon::GetDamageExtra()
{
	return _damage_extra;
}

INT_TIME CWeapon::GetDamageTotal()
{
	return _damage + _damage_extra;
}
INT_TIME CWeapon::GetDamageBasic()
{
	return _damage;
}
int CWeapon::GetLevel()
{
	return _level;
}
void CWeapon::SetLevel(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_level = level;
	if (_level >= game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData)
	{
		_level = game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData;
		_level_max = true;
	}
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	//_damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	GetRelicsBonus();
}

void CWeapon::Unlock()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_is_block = false;
    _level = 1;
    /*if(_current_index > 0)
    {
        _level = game->_weapon[_current_index - 1]._level;
    }*/
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	GAME()->PlaySFX(SFX_CASTLE_LEVELUP);
}

INT_TIME CWeapon::GetCostUpgrade()
{
	return _cost_upgrade;
}

void CWeapon::SetState(int state)
{
	_state = state;
	switch (_state)
	{
	case WEAPON_STATE_IDLE:
		_anim.SetAnim(WEAPON_ANIM_IDLE, false);
		break;
	case WEAPON_STATE_ATTACK:
		_anim.SetAnim(WEAPON_ANIM_ATTACK, false);
		break;
	default:
		break;
	}
}
int CWeapon::GetState()
{
	return _state;
}
void CWeapon::RenderAnim(float x, float y, int opac)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	x -= game->_point_o.X;
	y -= game->_point_o.Y;
	_anim.SetPos(_x + x - _anim_width, _y + _anim_height + y);
	_anim.DrawAnimObject(G());
}
bool CWeapon::IsLock()
{
	return _is_block;
}

void CWeapon::LevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_is_block)
	{
		Unlock();
		game->_castle.ChangeCastle();
		
	}
	else
	{
		_level++;
		if (_level >= game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData)
		{
			_level = game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData;
			_level_max = true;
		}
		/*if (_level > CASTLE_MAX_LEVEL-1)
		{
			_level = CASTLE_MAX_LEVEL-1;
		}*/
		GAME()->PlaySFX(SFX_PURCHASE);
		game->_user._quest_num_upgrade_weapons++;
	}
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	//_damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	GetRelicsBonus();
}
void CWeapon::RenderAnimWeapon(float x, float y, int opac)
{

}
int CWeapon::GetSpriteID()
{
	return _spriteid;
}

void CWeapon::GetRelicsBonus()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Upgrade_Cost;
	int param_speedatt = CGameDesign::FileCastle_design::CSheetCastle_General::Speed;
	int param_critical = CGameDesign::FileCastle_design::CSheetCastle_General::Critical;
	int param_aoe = CGameDesign::FileCastle_design::CSheetCastle_General::AOE;
	_damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	if (_is_block)
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level, param_cost_upgrade);
	}
	else
	{
		_cost_upgrade = game->GetDesignCastleUpgradeInfo(_type, _level + 1, param_cost_upgrade);
	}
	_damage_extra = 0;
#if RELIC_PRESTIGE_ADD_DMG_BASIC
	_damage += (INT_TIME)(_damage*((game->GetRelicsAttackBasic(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f));
#else
	_damage_extra += (INT_TIME)(_damage*((game->GetRelicsAttackBasic(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f));
#endif
	_damage_extra += (INT_TIME)(_damage*((game->GetRelicsAttack(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f));
	_damage_extra += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_WEAPON, _type + 2);


	_attack_speed = game->GetDesignCastleGeneral(_type + 1, param_speedatt);
	_critical_percent = game->GetDesignCastleGeneral(_type + 1, param_critical);
	_aoe = game->GetDesignCastleGeneral(_type + 1, param_aoe);
	/*_damage += (INT_TIME)(_damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
	_damage += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_WEAPON, _type + 2);*/
	float att_mul = (game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f;
	if (att_mul > 0)
	{
		_attack_speed /= att_mul;
	}
	//_attack_speed -= (_attack_speed*(game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
	_critical_percent += game->GetRelicsCritical(ITEMRELIC_GROUP_WEAPON, _type + 2);
	if (!_is_block)
	{
		_cost_upgrade -= (int)(_cost_upgrade*(game->GetRelicsCostDecrease(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
	}
	_aoe += (int)(_aoe*(game->GetRelicsAOE(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
	_num_unit_bounce = game->GetRelicsUnitBounce(ITEMRELIC_GROUP_WEAPON, _type + 2);
}

INT_TIME CWeapon::GetBonusDamage()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	/*int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	INT_TIME damage = game->GetDesignCastleUpgradeInfo(_type, _level, param_damage);
	INT_TIME damage_bonus = (INT_TIME)(damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
	damage_bonus += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_WEAPON, _type + 2);*/
	return GetDamageExtra();
}
INT_TIME CWeapon::GetDamageLevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_damage = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Attack;
	int levelmax = game->_game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData;
	INT_TIME damage = 0;
	if (_level + 1 < levelmax)
	{
		damage = game->GetDesignCastleUpgradeInfo(_type, _level+1, param_damage);
#if RELIC_PRESTIGE_ADD_DMG_BASIC
		damage += (INT_TIME)(damage*(game->GetRelicsAttackBasic(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
#endif
		return damage;
	}
	else
	{
		damage = game->GetDesignCastleUpgradeInfo(_type, levelmax - 1, param_damage);
#if RELIC_PRESTIGE_ADD_DMG_BASIC
		damage += (INT_TIME)(damage*(game->GetRelicsAttackBasic(ITEMRELIC_GROUP_WEAPON, _type + 2)) / 100.0f);
#endif
		return damage;
	}
}