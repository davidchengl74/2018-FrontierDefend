#include "pch.h"
#include "../../GameCore/CGame.h"

CCastle::CCastle()
{
}

CCastle::~CCastle()
{
}

void CCastle::Init(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_hp = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::Upgrade_Cost;
	_level = level;
	_level_max = false;
	if (_level >= game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData)
	{
		_level = game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData;
		_level_max = true;
	}
	_hp = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_hp);
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level+1, param_cost_upgrade);
	_hp_max = _hp;
	_spriteid = game->_castle_sprite[0];
	game->LoadSpriteOptimize(_spriteid,true,!CGame::_this->_isNeedOptimize);
	_clip_hp_target = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(46);
	_clip_hp_current = _clip_hp_target;
	_count_frame_playsound = 0;
	_clip_hp_scroll_speed = 1;
}
void CCastle::Modify()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_hp = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::Upgrade_Cost;
	_hp = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_hp);
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level + 1, param_cost_upgrade);
	_hp_max = _hp;
	_spriteid = game->_castle_sprite[0];
	game->LoadSpriteOptimize(_spriteid,true,!CGame::_this->_isNeedOptimize);
	_clip_hp_target = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(46);
	_clip_hp_current = _clip_hp_target;
	_count_frame_playsound = 0;
	_clip_hp_scroll_speed = 1;
}
void CCastle::Render(float x, float y, int opac)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	bool game_over = false;
	if (game->_current_state == k_GS_GAME_OVER && game->_sub_state == k_LOOP)
	{
		game_over = true;
	}
	if (game_over)
	{
		G()->SetClip(0 + game->_point_o.X, 0 + game->_point_o.Y, k_SCREEN_WIDTH , 590);
	}
	GET_SPRITE(_spriteid)->DrawFrame(G(), 1, x, y);
	if (!game->_weapon[WEAPON_CHIMERA].IsLock())
	{
		game->_weapon[WEAPON_CHIMERA].RenderAnim(x, y, 100);
	}
	if (!game->_weapon[WEAPON_DARKNESS].IsLock())
	{
		game->_weapon[WEAPON_DARKNESS].RenderAnim(x, y, 100);
	}
	if (!game->_weapon[WEAPON_HOLY].IsLock())
	{
		game->_weapon[WEAPON_HOLY].RenderAnim(x, y, 100);
	}
	if (!game->_weapon[WEAPON_FROST_MAGE].IsLock())
	{
		game->_weapon[WEAPON_FROST_MAGE].RenderAnim(x, y, 100);
	}
	GET_SPRITE(_spriteid)->DrawFrame(G(), 5, x, y);
	if (!game->_weapon[WEAPON_FIRE_MAGE].IsLock())
	{
		game->_weapon[WEAPON_FIRE_MAGE].RenderAnim(x, y, 100);
	}
	GET_SPRITE(_spriteid)->DrawFrame(G(), 4, x, y);
	
	if (!game->_weapon[WEAPON_ELECTRIC].IsLock())
	{
		game->_weapon[WEAPON_ELECTRIC].RenderAnim(x, y, 100);
	}
	GET_SPRITE(_spriteid)->DrawFrame(G(), 2, x, y);
	if (!game->_weapon[WEAPON_TWIN].IsLock())
	{
		game->_weapon[WEAPON_TWIN].RenderAnim(x, y, 100);
	}
	
	for (int i = 0; i < NUM_MAX_WEAPON; i++)
	{
		int wptype = game->_weapon[i].GetType();
		if (wptype == WEAPON_ARCHER || wptype == WEAPON_CANNON)
		{
			if (!game->_weapon[i].IsLock())
			{
				game->_weapon[i].RenderAnim(x, y, 100);
			}
		}
	}
	GET_SPRITE(_spriteid)->DrawFrame(G(), 3, x, y);
	if (!game->_weapon[WEAPON_DRAGON].IsLock())
	{
		game->_weapon[WEAPON_DRAGON].RenderAnim(x, y, 100);
	}
	if (game_over)
	{
		G()->ClearClip();
	}
	if (game_over)
	{
		G()->SetOpacity(100 - game->_gameover_fill_opac);
		game->_gameover_anim_castle_die_stone.DrawAnimObject(G());
		if (game->_gameover_anim_castle_die_stone.IsCurrentAnimStop())
		{
			game->_gameover_anim_castle_die_stone.SetAnim(CMath::RANDOM(0, 1), false);
			game->_gameover_anim_castle_die_stone.SetPos(125 + CMath::RANDOM(-10, 10) * 3 + game->_point_o.X, 500 + CMath::RANDOM(0, 10) * 5 + game->_point_o.Y);
		}
		game->_gameover_anim_castle_die_stone.UpdateAnimObject();
		game->_gameover_anim_castle_die_stone1.DrawAnimObject(G());
		if (game->_gameover_anim_castle_die_stone1.IsCurrentAnimStop())
		{
			game->_gameover_anim_castle_die_stone1.SetAnim(CMath::RANDOM(0, 1), false);
			game->_gameover_anim_castle_die_stone1.SetPos(125 + CMath::RANDOM(-10, 10) * 3 + game->_point_o.X, 500 + CMath::RANDOM(0, 10) * 5 + game->_point_o.Y);
		}
		game->_gameover_anim_castle_die_stone1.UpdateAnimObject();
		//G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
		//G()->SetScale(2.5f, 2.5f, 125, 590);
		if (game->_gameover_frame_render_anim >= 30)
		{
			game->_gameover_anim_castle_die_smoke2.DrawAnimObject(G());
			game->_gameover_anim_castle_die_smoke2.UpdateAnimObject();
		}
		if (game->_gameover_frame_render_anim >= 20)
		{
			game->_gameover_anim_castle_die_smoke1.DrawAnimObject(G());
			game->_gameover_anim_castle_die_smoke1.UpdateAnimObject();
		}
		game->_gameover_anim_castle_die_smoke.DrawAnimObject(G());
		game->_gameover_anim_castle_die_smoke.UpdateAnimObject();
		//G()->ClearScale();

		//G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
		G()->SetOpacity(opac);
	}

	
	int clipx = 0;
	int clipy = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleY(46,0);
	int clipw = k_SCREEN_WIDTH;
	int cliph = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(46);
	//_clip_hp_target = cliph * _hp / (_hp_max*1.0f);
	if (_clip_hp_current >  _clip_hp_target)
	{
		_clip_hp_current -= _clip_hp_scroll_speed;
		if (_clip_hp_current <= _clip_hp_target)
		{
			_clip_hp_current = _clip_hp_target;
		}
	}
	else if(_clip_hp_current <  _clip_hp_target)
	{
		_clip_hp_current += _clip_hp_scroll_speed;
		if (_clip_hp_current >= _clip_hp_target)
		{
			_clip_hp_current = _clip_hp_target;
		}
	}
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 45, game->_point_o.X, game->_point_o.Y);
	G()->SetClip(clipx + game->_point_o.X, clipy + (cliph - _clip_hp_current) + game->_point_o.Y, clipw, _clip_hp_current);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 47, game->_point_o.X, game->_point_o.Y);
	G()->ClearClip();
	G()->SetClip(clipx + game->_point_o.X, clipy + (cliph - _clip_hp_target) + game->_point_o.Y, clipw, _clip_hp_target);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 46, game->_point_o.X, game->_point_o.Y);
	G()->ClearClip();
	if (_count_frame_playsound > 0)
	{
		_count_frame_playsound--;
	}
	/*G()->SetColor(0xffff0000);
	G()->FillRect(WEAPON_CHIMERA_POSX, WEAPON_CHIMERA_POSY, 10, 10);*/
}
INT_TIME CCastle::GetCostUpgrade()
{
	return _cost_upgrade;
}
void CCastle::Update()
{
	
}
void CCastle::SetLevel(int level)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_hp = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
	_level = level;
	_level_max = false;
	if (_level >= game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData)
	{
		_level = game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData;
		_level_max = true;
	}
	_hp = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_hp);
	_hp_max = _hp;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::Upgrade_Cost;
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level + 1, param_cost_upgrade);
	AddHp(_hp_max);
}
void CCastle::LevelUp()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_hp = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::HP;
	_level++;
	/*if (_level > CASTLE_MAX_LEVEL-1)
	{
		_level = CASTLE_MAX_LEVEL-1;
	}*/
	_level_max = false;
	if (_level >= game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData)
	{
		_level = game->_game_design.Castle_design.SheetCastle_Upgrade.int64Value._totalData;
		_level_max = true;
	}
	_hp = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level, param_hp);
	_hp_max = _hp;
	int param_cost_upgrade = CGameDesign::FileCastle_design::CSheetCastle_Upgrade::Upgrade_Cost;
	_cost_upgrade = game->GetDesignCastleUpgradeInfo(WEAPON_CASTLE, _level + 1, param_cost_upgrade);
	GAME()->PlaySFX(SFX_PURCHASE);
	AddHp(_hp_max);
}
int CCastle::GetLevel()
{
	return _level;
}
int CCastle::GetPercentHP()
{
    return _hp*100/_hp_max;
}
INT_TIME CCastle::GetHP()
{
	return _hp;
}

void CCastle::AddHp(INT_TIME hp)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_hp += hp;
	if (_hp >= _hp_max)
	{
		_hp = _hp_max;
	}
	if (hp < 0)
	{
		if (_count_frame_playsound <= 0)
		{
			_count_frame_playsound = 5;
		}
		GAME()->PlaySFX(SFX_CASTLE_DAMAGED);	
	}
	if (_hp <= 0)
	{
		_hp = 0;
		game->SetState(k_GS_GAME_OVER);
		game->_user.UserDataSave();
		//you lose
	}
	int cliph = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameHeight(46);
	_clip_hp_target = cliph * _hp / (_hp_max*1.0f);
	_clip_hp_scroll_speed = CMath::ABSOLUTE_VALUE(_clip_hp_target - _clip_hp_current) / 30.0f;
	if (hp > 0)
	{
		_clip_hp_scroll_speed = 5;
	}
	else
	{
		if (_clip_hp_scroll_speed > 1)
		{
			_clip_hp_scroll_speed = 1;
		}
	}
}
void CCastle::ChangeCastle()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	for (int i = 0; i < NUM_MAX_WEAPON;i++)
	{
		if (!game->_weapon[i].IsLock())
		{
			_spriteid = game->_castle_sprite[i+1];
		}
	}
	game->LoadSpriteOptimize(_spriteid,true,!CGame::_this->_isNeedOptimize);
}
