#include "pch.h"
#include "../../GameCore/CGame.h"

CItemRelic::CItemRelic()
{
}

CItemRelic::~CItemRelic()
{
}

void CItemRelic::Init(int spriteid, int group, int id, float x, float y, bool lock)
{
	TDGame*game = (TDGame*)(GAME()->_current_game);
	_x = x;
	_y = y;
	_id = id;
	_group = group;
	_spriteid = spriteid;
	_frameid = 0;
	_bg_frameid = 0;
	sprintf( _name,"RELIC NAME");
	sprintf(_descript, "Description");
	_interactive_id = 0;
	_price = 1;
	_duration = 0;
	_attack = 0;
	_attack_speed = 0;
	_mana = 0;
	_critical = 0;
	_aoe = 0;
	_cost_decrease = 0;
	_unit_bounce = 0;
	_speed_move = 0;
	_hp = 0;
	_duration_skill = 0;
	_is_lock = lock;
	_attack_point = 0;
	_pet_id = -1;
	int param_frameid = CGameDesign::FileSpriteManager::CSheetSprite_Relic::SpriteId;
	int param_bg_frame = CGameDesign::FileSpriteManager::CSheetSprite_Relic::BackgroundID;
	int relicindex = game->GetDesignRelicIndex(_id, _group);
	switch (_group)
	{
	case ITEMRELIC_GROUP_HERO:
	{
								 int param_name = CGameDesign::FileRelics_design::CSheetHero_Relics::Name;
								 int param_price = CGameDesign::FileRelics_design::CSheetHero_Relics::Price;
								 int param_duration = CGameDesign::FileRelics_design::CSheetHero_Relics::Duration;
								 int param_attack = CGameDesign::FileRelics_design::CSheetHero_Relics::Attack;
								 int param_mana = CGameDesign::FileRelics_design::CSheetHero_Relics::Mana;
								 int param_critical = CGameDesign::FileRelics_design::CSheetHero_Relics::Critical;
								 int param_cost_decrease = CGameDesign::FileRelics_design::CSheetHero_Relics::Cost_Decrease;
								 int param_desc = CGameDesign::FileRelics_design::CSheetHero_Relics::Description;
								 int param_skill_dur = CGameDesign::FileRelics_design::CSheetHero_Relics::Duration_skill;
								 int param_interactive = CGameDesign::FileRelics_design::CSheetHero_Relics::Hero_ID;
								 int param_att_point = CGameDesign::FileRelics_design::CSheetHero_Relics::Attack_Points;
								 int param_unit_bounce = CGameDesign::FileRelics_design::CSheetHero_Relics::Unit__Bounce;
								 int param_subgroup = CGameDesign::FileRelics_design::CSheetHero_Relics::Sub_Group;
								 sprintf(_name, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_HERO, param_name));
								 sprintf(_descript, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_HERO, param_desc));
								 _price = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_price);
								 _duration = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_duration);
								 _attack = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_attack);
								 _mana = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_mana);
								 _critical = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_critical);
								 _cost_decrease = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_cost_decrease);
								 int spriteindex = game->GetDesignRelicsSpriteIndex(_name);
								 _frameid = game->GetDesignRelicsSprite(spriteindex, param_frameid);
								 _bg_frameid = game->GetDesignRelicsSprite(spriteindex, param_bg_frame);
								 _duration_skill = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_skill_dur);
								 _interactive_id = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_interactive);
								 _attack_point = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_att_point);
								 _unit_bounce = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_unit_bounce);
								 _sub_group = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_HERO, param_subgroup);
	}
		break;
	case ITEMRELIC_GROUP_WEAPON:
	{
								   int param_name = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Name;
								   int param_price = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Price;
								   int param_attack = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Attack;
								   int param_attspeed = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Attack_Speed;
								   int param_critical = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Critical;
								   int param_aoe = CGameDesign::FileRelics_design::CSheetWeapon_Relics::AOE;
								   int param_cost_decrease = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Cost_Decrease;
								   int param_unit_bounce = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Unit__Bounce;
								   int param_desc = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Description;
								   int param_interactive = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Weapon_ID;
								   int param_att_point = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Attack_Points;
								   int param_subgroup = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Sub_Group;
								   sprintf(_name, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_WEAPON, param_name));
								   sprintf(_descript, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_WEAPON, param_desc));
								   _price = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_price);
								   _attack = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_attack);
								   _attack_speed = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_attspeed);
								   _critical = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_critical);
								   _aoe = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_aoe);
								   _cost_decrease = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_cost_decrease);
								   _unit_bounce = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_unit_bounce);
								   int spriteindex = game->GetDesignRelicsSpriteIndex(_name);
								   _frameid = game->GetDesignRelicsSprite(spriteindex, param_frameid);
								   _bg_frameid = game->GetDesignRelicsSprite(spriteindex, param_bg_frame);
								   _interactive_id = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_interactive);
								   _attack_point = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_att_point);
								   _sub_group = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_WEAPON, param_subgroup);
	}
		break;
	case ITEMRELIC_GROUP_ENEMY:
	{
								  int param_name = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Name;
								  int param_price = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Price;
								  int param_attack = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Attack;
								  int param_attspeed = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Attack_Speed;
								  int param_cost_increase = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Cost_Increase;
								  int param_speed_move = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Speed_Move;
								  int param_hp = CGameDesign::FileRelics_design::CSheetEnemy_Relics::HP;
								  int param_desc = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Description;
								  int param_interactive = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Enemy_ID;
								  int param_subgroup = CGameDesign::FileRelics_design::CSheetEnemy_Relics::Sub_Group;
								  sprintf(_name, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_ENEMY, param_name));
								  sprintf(_descript, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_ENEMY, param_desc));
								  _price = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_price);
								  _attack = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_attack);
								  _attack_speed = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_attspeed);
								  _cost_decrease = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_cost_increase);
								  _speed_move = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_speed_move);
								  _hp = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_hp);
								  int spriteindex = game->GetDesignRelicsSpriteIndex(_name);
								  _frameid = game->GetDesignRelicsSprite(spriteindex, param_frameid);
								  _bg_frameid = game->GetDesignRelicsSprite(spriteindex, param_bg_frame);
								  _interactive_id = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_interactive);
								  _sub_group = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_ENEMY, param_subgroup);
	}
		break;
	case ITEMRELIC_GROUP_PET:
	{
								int param_name = CGameDesign::FileRelics_design::CSheetPet_Relics::Name;
								int param_price = CGameDesign::FileRelics_design::CSheetPet_Relics::Price;
								int param_duration = CGameDesign::FileRelics_design::CSheetPet_Relics::Duration;
								int param_attack = CGameDesign::FileRelics_design::CSheetPet_Relics::Attack;
								int param_mana = CGameDesign::FileRelics_design::CSheetPet_Relics::Mana;
								int param_critical = CGameDesign::FileRelics_design::CSheetPet_Relics::Critical;
								int param_cost_decrease = CGameDesign::FileRelics_design::CSheetPet_Relics::Cost_Decrease;
								int param_desc = CGameDesign::FileRelics_design::CSheetPet_Relics::Description;
								int param_pet_id = CGameDesign::FileRelics_design::CSheetPet_Relics::Pet_ID;
								int param_interactive = CGameDesign::FileRelics_design::CSheetPet_Relics::Hero_ID;
								int param_att_point = CGameDesign::FileRelics_design::CSheetPet_Relics::Attack_Points;
								int param_subgroup = CGameDesign::FileRelics_design::CSheetPet_Relics::Sub_Group;
								sprintf(_name, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_PET, param_name));
								sprintf(_descript, "%s", game->GetDesignRelicsString(relicindex, ITEMRELIC_GROUP_PET, param_desc));
								_price = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_price);
								_duration = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_duration);
								_attack = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_attack);
								_mana = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_mana);
								_critical = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_critical);
								_cost_decrease = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_cost_decrease);
								int spriteindex = game->GetDesignRelicsSpriteIndex(_name);
								_frameid = game->GetDesignRelicsSprite(spriteindex, param_frameid);
								_bg_frameid = game->GetDesignRelicsSprite(spriteindex, param_bg_frame);
								_pet_id = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_pet_id);
								_interactive_id = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_interactive);
								_attack_point = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_att_point);
								_sub_group = game->GetDesignRelics(relicindex, ITEMRELIC_GROUP_PET, param_subgroup);
								//_group = ITEMRELIC_GROUP_HERO;
	}
		break;
	default:
		break;
	}
	//printf("\n relic name = %s - _bg_frameid = %d - _frameid = %d", _name, _bg_frameid, _frameid);
}
void CItemRelic::Render(float x, float y)
{
	if (_id < 0)
	{
		return;
	}
	TDGame*game = (TDGame*)GAME()->_current_game;
	GET_SPRITE(_spriteid)->DrawFrame(G(), _bg_frameid, _x + x, _y + y);
	GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
	//int mw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(58);
	//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 59, _x + x, _y + y);
	//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, _x + x - mw / 2 + 73, _y + y + 3);
	//int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	//GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	//GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, _LEFT, "%s", _name);
	//GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	//int line_space = GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing;
	//GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = 3;
	//spacing = GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing;
	//GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = 2;
	//GET_SPRITE(SPRITEID_FONT_SKILL)->DrawAnsiPageFormat(G(), _x + x - mw / 2 + 146, _y + y + 20, 330, _LEFT, "%s", _descript);
	//GET_SPRITE(SPRITEID_FONT_SKILL)->_char_spacing = spacing;
	//GET_SPRITE(SPRITEID_FONT_SKILL)->_line_spacing = line_space;
	////GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
	//GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
}
void CItemRelic::Update()
{

}
void CItemRelic::AddNew(int group, int id)
{
	Init(SPRITEID_HUD_ITEM, group, id, 0, 0,false);
}
void CItemRelic::Reset()
{
	_x = 0;
	_y = 0;
	_id = -1;
	_group = -1;
	_spriteid = 0;
	_frameid = 0;
	_bg_frameid = 0;
	sprintf(_name, "RELIC NAME");
	sprintf(_descript, "Description");
	_interactive_id = 0;
	_price = 1;
	_duration = 0;
	_attack = 0;
	_attack_speed = 0;
	_mana = 0;
	_critical = 0;
	_aoe = 0;
	_cost_decrease = 0;
	_unit_bounce = 0;
	_speed_move = 0;
	_hp = 0;
	_duration_skill = 0;
	_is_lock = true;
	_attack_point = 0;
	_pet_id = -1;
}