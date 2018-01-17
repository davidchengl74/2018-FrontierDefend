#include "pch.h"
#include "../../GameCore/CGame.h"

const int TDGame::_character_sprite[NUM_MAX_ENEMY] =
{
	SPRITEID_MONSTER_ORC_01,		//0
	SPRITEID_MONSTER_ORC_02,		//1
	SPRITEID_MONSTER_ORC_03,		//2
	SPRITEID_MONSTER_WOLF_01,		//3
	SPRITEID_MONSTER_WOLF_02,		//4
	SPRITEID_MONSTER_WOLF_03,		//5
	SPRITEID_MONSTER_THIEF_01,		//6
	SPRITEID_MONSTER_ORC_05,		//7
	SPRITEID_MONSTER_ORC_04,		//8
	SPRITEID_MONSTER_ORC_06,		//9
	SPRITEID_MONSTER_BOSS_LORDJARAXXUS,		//10
	SPRITEID_MONSTER_SHAMAN,		//11
	SPRITEID_MONSTER_SKELETON_01,		//12
	SPRITEID_MONSTER_SKELETON_02,		//13
	SPRITEID_MONSTER_SPIDERS_01,		//14
	SPRITEID_MONSTER_SPIDERS_02,		//15
	SPRITEID_MONSTER_SPIDERS_03,		//16
	SPRITEID_MONSTER_SPIDERS_04,		//17
	SPRITEID_MONSTER_TECHIES,		//18
	SPRITEID_MONSTER_ORC_MAGI,		//19
	SPRITEID_MONSTER_SKELETON_03,		//20
	SPRITEID_MONSTER_SKELETON_04,		//21
	SPRITEID_MONSTER_SKELETON_05,		//22
	SPRITEID_MONSTER_FLYING,		//23
	SPRITEID_MONSTER_FLYING_01,		//24
	SPRITEID_MONSTER_SHAMAN_01,		//25
	SPRITEID_MONSTER_SKELETON_06,		//26
	SPRITEID_MONSTER_BOSS_PIRATE_KING,		//27
	SPRITEID_MONSTER_GARGOYLE,			//28
	SPRITEID_MONSTER_BOSS_BALROG,		//29
	SPRITEID_MONSTER_CATAPULT,		//30
	SPRITEID_MONSTER_IMP,			//31
	SPRITEID_MONSTER_LAVA_01,		//32
	SPRITEID_MONSTER_LAVA_02,		//33
	SPRITEID_MONSTER_RHINO,			//34
	SPRITEID_MONSTER_BOSS_RAZOR,		//35
	SPRITEID_MONSTER_BOSS_SKELETON,			//36
};

const int TDGame::_hero_sprite[NUM_MAX_HERO] =
{
	SPRITEID_HERO_SWORDSMAN_01,	//0
	SPRITEID_HERO_ARCHER_01,   //1
	SPRITEID_HERO_MAGE_01,//2
	SPRITEID_HERO_BEASTMASTER_01,//3
	SPRITEID_HERO_MAGELIGHTING_01,//4
	SPRITEID_HERO_ACHEMIST_01,//5
	SPRITEID_HERO_ROBOT_01,//6
	SPRITEID_HERO_CAT_NINJA_01,//7
	SPRITEID_HERO_WOLFGIRL_01,//8
	SPRITEID_HERO_SANTA_01,//9
};							   
const int TDGame::_weapon_sprite[NUM_MAX_WEAPON+1] =
{							   
	SPRITEID_CASTLE_LV1_01,   
	SPRITEID_CASTLE_LV2_01,   
	SPRITEID_CASTLE_LV3_01,
	SPRITEID_CASTLE_LV4_01,
	SPRITEID_CASTLE_LV5_01,
	SPRITEID_CASTLE_LV6_01,
	SPRITEID_CASTLE_LV7_01,
	SPRITEID_CASTLE_LV8_01,
	SPRITEID_CASTLE_LV9_01,
	SPRITEID_CASTLE_LV10_01,
};
const int TDGame::_skill_sprite[NUM_MAX_SKILL] =
{
	SPRITEID_EFFECT_SKILL_SWORDMAN_01,
	SPRITEID_EFFECT_SKILL_ARCHER,
	SPRITEID_EFFECT_SKILL_ARCHER,
	SPRITEID_EFFECT_SKILL_MAGELIGHTING_01,
	SPRITEID_EFFECT_SKILL_WOLFGIRL_01,
	SPRITEID_EFFECT_SKILL_ACHEMIST_01,
	SPRITEID_EFFECT_SKILL_BEASTMASTER_01,
	SPRITEID_EFFECT_SKILL_ROBOT_01,
	SPRITEID_EFFECT_SKILL_CAT_NINJA_01,
	SPRITEID_EFFECT_SANTA_01,
};

const int TDGame::_castle_sprite[NUM_MAX_CASTLE_LEVEL] =
{
	SPRITEID_HUD_CASTLE_00,
	SPRITEID_HUD_CASTLE_01,
	SPRITEID_HUD_CASTLE_02,
	SPRITEID_HUD_CASTLE_03,
	SPRITEID_HUD_CASTLE_04,
	SPRITEID_HUD_CASTLE_05,
	SPRITEID_HUD_CASTLE_06,
	SPRITEID_HUD_CASTLE_07,
	SPRITEID_HUD_CASTLE_08,
	SPRITEID_HUD_CASTLE_09,
	SPRITEID_HUD_CASTLE_10,
};

const int TDGame::_background_sprite[NUM_MAX_BACKGROUND] =
{
	SPRITEID_BACKGROUND_01,
	SPRITEID_BACKGROUND_02,
	SPRITEID_BACKGROUND_03,
	SPRITEID_BACKGROUND_04,
	SPRITEID_BACKGROUND_05,
	SPRITEID_BACKGROUND_06,
	SPRITEID_BACKGROUND_07,
	SPRITEID_BACKGROUND_08,
	SPRITEID_BACKGROUND_09,
	SPRITEID_BACKGROUND_10,
	SPRITEID_BACKGROUND_11,
	SPRITEID_BACKGROUND_12,
	SPRITEID_BACKGROUND_13,
	SPRITEID_BACKGROUND_14,
	SPRITEID_BACKGROUND_15,
};

const int TDGame::_background_dark_sprite[NUM_MAX_BACKGROUND] =
{
	SPRITEID_BACKGROUND_DARK_01,
	SPRITEID_BACKGROUND_DARK_02,
	SPRITEID_BACKGROUND_DARK_03,
	SPRITEID_BACKGROUND_DARK_04,
	SPRITEID_BACKGROUND_DARK_05,
	SPRITEID_BACKGROUND_DARK_06,
	SPRITEID_BACKGROUND_DARK_07,
	SPRITEID_BACKGROUND_DARK_08,
	SPRITEID_BACKGROUND_DARK_09,
	SPRITEID_BACKGROUND_DARK_10,
	SPRITEID_BACKGROUND_DARK_11,
	SPRITEID_BACKGROUND_12,
	SPRITEID_BACKGROUND_13,
	SPRITEID_BACKGROUND_14,
	SPRITEID_BACKGROUND_DARK_15,
};

const int TDGame::_underground_sprite[NUM_MAX_BACKGROUND] =
{
	SPRITEID_BG_UNDERGROUND_01,
	SPRITEID_BG_UNDERGROUND_02,
	SPRITEID_BG_UNDERGROUND_03,
	SPRITEID_BG_UNDERGROUND_04,
	SPRITEID_BG_UNDERGROUND_05,
	SPRITEID_BG_UNDERGROUND_06,
	SPRITEID_BG_UNDERGROUND_07,
	SPRITEID_BG_UNDERGROUND_08,
	SPRITEID_BG_UNDERGROUND_09,
	SPRITEID_BG_UNDERGROUND_10,
	SPRITEID_BG_UNDERGROUND_11,
	SPRITEID_BG_UNDERGROUND_12,
	SPRITEID_BG_UNDERGROUND_13,
	SPRITEID_BG_UNDERGROUND_14,
	SPRITEID_BG_UNDERGROUND_15,
};



int TDGame::GetDesignCastleGeneral(int id, int param)
{
	return _game_design.Castle_design.SheetCastle_General.int32Value.getValue(id, param);
}
float TDGame::GetDesignCastleFormulaFloat(int id, int level)
{
	level--;
	if (level >= _game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData)
	{
		return 0;
	}
	int param = CGameDesign::FileCastle_design::CSheetArcher_Upgrade::Formula;
	switch (id)
	{
	case WEAPON_ARCHER:
		return _game_design.Castle_design.SheetArcher_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_FIRE_MAGE:
		return _game_design.Castle_design.SheetFire_Mage_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_CANNON:
		return _game_design.Castle_design.SheetCanon_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_ELECTRIC:
		return _game_design.Castle_design.SheetElectric_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_FROST_MAGE:
		return _game_design.Castle_design.SheetFrost_Mage_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_TWIN:
		return _game_design.Castle_design.SheetTwin_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_HOLY:
		return _game_design.Castle_design.SheetHoly_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_DARKNESS:
		return _game_design.Castle_design.SheetDarkness_Tower_Upgrarde.floatValue.getValue(level, param);
		break;
	case WEAPON_DRAGON:
		return _game_design.Castle_design.SheetDragon_Tower_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_CASTLE:
		return _game_design.Castle_design.SheetCastle_Upgrade.floatValue.getValue(level, param);
		break;
	case WEAPON_CHIMERA:
		return _game_design.Castle_design.SheetChimera_Tower_Upgrade.floatValue.getValue(level, param);
		break;

	default:
		return _game_design.Castle_design.SheetCastle_Upgrade.floatValue.getValue(level, param);
		break;
	}
}
const char* TDGame::GetDesignCastleName(int id, int param)
{
	return _game_design.Castle_design.SheetCastle_General.stringValue.getValue(id, param);
}
INT_TIME TDGame::GetDesignCastleUpgradeInfo(int id, int level, int param)
{
	level--;
	if (level >= _game_design.Castle_design.SheetArcher_Upgrade.int64Value._totalData)
	{
		return 0;
	}
	switch (id)
	{
	case WEAPON_ARCHER:
		return _game_design.Castle_design.SheetArcher_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_FIRE_MAGE:
		return _game_design.Castle_design.SheetFire_Mage_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_CANNON:
		return _game_design.Castle_design.SheetCanon_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_ELECTRIC:
		return _game_design.Castle_design.SheetElectric_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_FROST_MAGE:
		return _game_design.Castle_design.SheetFrost_Mage_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_TWIN:
		return _game_design.Castle_design.SheetTwin_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_HOLY:
		return _game_design.Castle_design.SheetHoly_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_DARKNESS:
		return _game_design.Castle_design.SheetDarkness_Tower_Upgrarde.int64Value.getValue(level, param);
		break;
	case WEAPON_DRAGON:
		return _game_design.Castle_design.SheetDragon_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_CASTLE:
		return _game_design.Castle_design.SheetCastle_Upgrade.int64Value.getValue(level, param);
		break;
	case WEAPON_CHIMERA:
		return _game_design.Castle_design.SheetChimera_Tower_Upgrade.int64Value.getValue(level, param);
		break;
	default:
		return _game_design.Castle_design.SheetCastle_Upgrade.int64Value.getValue(level, param);
		break;
	}
}
int TDGame::GetDesignEnemyCreationGeneral(int id, int param)
{
	return _game_design.Enemy_Creation.SheetEnemy_Design.int32Value.getValue(id, param);
}
int TDGame::GetDesignEnemySkillGeneral(int id, int param)
{
	return _game_design.Enemy_Creation.SheetSkill.int32Value.getValue(id, param);
}
float TDGame::GetDesignEnemyCreationGeneralFLoat(int id, int param)
{
	return _game_design.Enemy_Creation.SheetEnemy_Design.floatValue.getValue(id, param);
}
const char* TDGame::GetDesignEnemyCreationString(int id, int param)
{
	return _game_design.Enemy_Creation.SheetEnemy_Design.stringValue.getValue(id, param);
}

INT_TIME TDGame::GetDesignBattleHPandDamage(int battle, int wave, int param)
{
#if GAME_DEBUG
#if define MAC_OS
#else
	battle = GAME_DEBUG_BATTLE_FIX - 1;
#endif
#endif
	switch (battle)
	{
	case 0:
		return _game_design.Enemy_design.SheetBattle_1.int64Value.getValue(wave, param);
		break;
	case 1:
		return _game_design.Enemy_design.SheetBattle_2.int64Value.getValue(wave, param);
		break;
	case 2:
		return _game_design.Enemy_design.SheetBattle_3.int64Value.getValue(wave, param);
		break;
	case 3:
		return _game_design.Enemy_design.SheetBattle_4.int64Value.getValue(wave, param);
		break;
	case 4:
		return _game_design.Enemy_design.SheetBattle_5.int64Value.getValue(wave, param);
		break;
	case 5:
		return _game_design.Enemy_design.SheetBattle_6.int64Value.getValue(wave, param);
		break;
	case 6:
		return _game_design.Enemy_design.SheetBattle_7.int64Value.getValue(wave, param);
		break;
	case 7:
		return _game_design.Enemy_design.SheetBattle_8.int64Value.getValue(wave, param);
		break;
	case 8:
		return _game_design.Enemy_design.SheetBattle_9.int64Value.getValue(wave, param);
		break;
	case 9:
		return _game_design.Enemy_design.SheetBattle_10.int64Value.getValue(wave, param);
		break;
	case 10:
		return _game_design.Enemy_design.SheetBattle_11.int64Value.getValue(wave, param);
		break;
	case 11:
		return _game_design.Enemy_design.SheetBattle_12.int64Value.getValue(wave, param);
		break;
	case 12:
		return _game_design.Enemy_design.SheetBattle_13.int64Value.getValue(wave, param);
		break;
	case 13:
		return _game_design.Enemy_design.SheetBattle_14.int64Value.getValue(wave, param);
		break;
	case 14:
		return _game_design.Enemy_design.SheetBattle_15.int64Value.getValue(wave, param);
		break;
	case 15:
		return _game_design.Enemy_design.SheetBattle_16.int64Value.getValue(wave, param);
		break;
	case 16:
		return _game_design.Enemy_design.SheetBattle_17.int64Value.getValue(wave, param);
		break;
	case 17:
		return _game_design.Enemy_design.SheetBattle_18.int64Value.getValue(wave, param);
		break;
	case 18:
		return _game_design.Enemy_design.SheetBattle_19.int64Value.getValue(wave, param);
		break;
	case 19:
		return _game_design.Enemy_design.SheetBattle_20.int64Value.getValue(wave, param);
		break;
	case 20:
		return _game_design.Enemy_design.SheetBattle_21.int64Value.getValue(wave, param);
		break;
	case 21:
		return _game_design.Enemy_design.SheetBattle_22.int64Value.getValue(wave, param);
		break;
	case 22:
		return _game_design.Enemy_design.SheetBattle_23.int64Value.getValue(wave, param);
		break;
	case 23:
		return _game_design.Enemy_design.SheetBattle_24.int64Value.getValue(wave, param);
		break;
	case 24:
		return _game_design.Enemy_design.SheetBattle_25.int64Value.getValue(wave, param);
		break;
	case 25:
		return _game_design.Enemy_design.SheetBattle_26.int64Value.getValue(wave, param);
		break;
	case 26:
		return _game_design.Enemy_design.SheetBattle_27.int64Value.getValue(wave, param);
		break;
	case 27:
		return _game_design.Enemy_design.SheetBattle_28.int64Value.getValue(wave, param);
		break;
	case 28:
		return _game_design.Enemy_design.SheetBattle_29.int64Value.getValue(wave, param);
		break;
	case 29:
		return _game_design.Enemy_design.SheetBattle_30.int64Value.getValue(wave, param);
		break;
	case 30:
		return _game_design.Enemy_design.SheetBattle_31.int64Value.getValue(wave, param);
		break;
	case 31:
		return _game_design.Enemy_design.SheetBattle_32.int64Value.getValue(wave, param);
		break;
	case 32:
		return _game_design.Enemy_design.SheetBattle_33.int64Value.getValue(wave, param);
		break;
	case 33:
		return _game_design.Enemy_design.SheetBattle_34.int64Value.getValue(wave, param);
		break;
	case 34:
		return _game_design.Enemy_design.SheetBattle_35.int64Value.getValue(wave, param);
		break;
	case 35:
		return _game_design.Enemy_design.SheetBattle_36.int64Value.getValue(wave, param);
		break;
	case 36:
		return _game_design.Enemy_design.SheetBattle_37.int64Value.getValue(wave, param);
		break;
	case 37:
		return _game_design.Enemy_design.SheetBattle_38.int64Value.getValue(wave, param);
		break;
	case 38:
		return _game_design.Enemy_design.SheetBattle_39.int64Value.getValue(wave, param);
		break;
	case 39:
		return _game_design.Enemy_design.SheetBattle_40.int64Value.getValue(wave, param);
		break;
	case 40:
		return _game_design.Enemy_design.SheetBattle_41.int64Value.getValue(wave, param);
		break;
	case 41:
		return _game_design.Enemy_design.SheetBattle_42.int64Value.getValue(wave, param);
		break;
	case 42:
		return _game_design.Enemy_design.SheetBattle_43.int64Value.getValue(wave, param);
		break;
	case 43:
		return _game_design.Enemy_design.SheetBattle_44.int64Value.getValue(wave, param);
		break;
	case 44:
		return _game_design.Enemy_design.SheetBattle_45.int64Value.getValue(wave, param);
		break;
	case 45:
		return _game_design.Enemy_design.SheetBattle_46.int64Value.getValue(wave, param);
		break;
	case 46:
		return _game_design.Enemy_design.SheetBattle_47.int64Value.getValue(wave, param);
		break;
	case 47:
		return _game_design.Enemy_design.SheetBattle_48.int64Value.getValue(wave, param);
		break;
	case 48:
		return _game_design.Enemy_design.SheetBattle_49.int64Value.getValue(wave, param);
		break;
	case 49:
		return _game_design.Enemy_design.SheetBattle_50.int64Value.getValue(wave, param);
		break;
	case 50:
		return _game_design.Enemy_design.SheetBattle_51.int64Value.getValue(wave, param);
		break;
	case 51:
		return _game_design.Enemy_design.SheetBattle_52.int64Value.getValue(wave, param);
		break;
	case 52:
		return _game_design.Enemy_design.SheetBattle_53.int64Value.getValue(wave, param);
		break;
	case 53:
		return _game_design.Enemy_design.SheetBattle_54.int64Value.getValue(wave, param);
		break;
	case 54:
		return _game_design.Enemy_design.SheetBattle_55.int64Value.getValue(wave, param);
		break;
	case 55:
		return _game_design.Enemy_design.SheetBattle_56.int64Value.getValue(wave, param);
		break;
	case 56:
		return _game_design.Enemy_design.SheetBattle_57.int64Value.getValue(wave, param);
		break;
	case 57:
		return _game_design.Enemy_design.SheetBattle_58.int64Value.getValue(wave, param);
		break;
	case 58:
		return _game_design.Enemy_design.SheetBattle_59.int64Value.getValue(wave, param);
		break;
	case 59:
		return _game_design.Enemy_design.SheetBattle_60.int64Value.getValue(wave, param);
		break;
	case 60:
		return _game_design.Enemy_design.SheetBattle_61.int64Value.getValue(wave, param);
		break;
	case 61:
		return _game_design.Enemy_design.SheetBattle_62.int64Value.getValue(wave, param);
		break;
	case 62:
		return _game_design.Enemy_design.SheetBattle_63.int64Value.getValue(wave, param);
		break;
	case 63:
		return _game_design.Enemy_design.SheetBattle_64.int64Value.getValue(wave, param);
		break;
	case 64:
		return _game_design.Enemy_design.SheetBattle_65.int64Value.getValue(wave, param);
		break;
	case 65:
		return _game_design.Enemy_design.SheetBattle_66.int64Value.getValue(wave, param);
		break;
	case 66:
		return _game_design.Enemy_design.SheetBattle_67.int64Value.getValue(wave, param);
		break;
	case 67:
		return _game_design.Enemy_design.SheetBattle_68.int64Value.getValue(wave, param);
		break;
	case 68:
		return _game_design.Enemy_design.SheetBattle_69.int64Value.getValue(wave, param);
		break;
	case 69:
		return _game_design.Enemy_design.SheetBattle_70.int64Value.getValue(wave, param);
		break;
	case 70:
		return _game_design.Enemy_design.SheetBattle_71.int64Value.getValue(wave, param);
		break;
	case 71:
		return _game_design.Enemy_design.SheetBattle_72.int64Value.getValue(wave, param);
		break;
	case 72:
		return _game_design.Enemy_design.SheetBattle_73.int64Value.getValue(wave, param);
		break;
	case 73:
		return _game_design.Enemy_design.SheetBattle_74.int64Value.getValue(wave, param);
		break;
	case 74:
		return _game_design.Enemy_design.SheetBattle_75.int64Value.getValue(wave, param);
		break;
	case 75:
		return _game_design.Enemy_design.SheetBattle_76.int64Value.getValue(wave, param);
		break;
	case 76:
		return _game_design.Enemy_design.SheetBattle_77.int64Value.getValue(wave, param);
		break;
	case 77:
		return _game_design.Enemy_design.SheetBattle_78.int64Value.getValue(wave, param);
		break;
	case 78:
		return _game_design.Enemy_design.SheetBattle_79.int64Value.getValue(wave, param);
		break;
	case 79:
		return _game_design.Enemy_design.SheetBattle_80.int64Value.getValue(wave, param);
		break;
	case 80:
		return _game_design.Enemy_design.SheetBattle_81.int64Value.getValue(wave, param);
		break;
	case 81:
		return _game_design.Enemy_design.SheetBattle_82.int64Value.getValue(wave, param);
		break;
	case 82:
		return _game_design.Enemy_design.SheetBattle_83.int64Value.getValue(wave, param);
		break;
	case 83:
		return _game_design.Enemy_design.SheetBattle_84.int64Value.getValue(wave, param);
		break;
	case 84:
		return _game_design.Enemy_design.SheetBattle_85.int64Value.getValue(wave, param);
		break;
	case 85:
		return _game_design.Enemy_design.SheetBattle_86.int64Value.getValue(wave, param);
		break;
	case 86:
		return _game_design.Enemy_design.SheetBattle_87.int64Value.getValue(wave, param);
		break;
	case 87:
		return _game_design.Enemy_design.SheetBattle_88.int64Value.getValue(wave, param);
		break;
	case 88:
		return _game_design.Enemy_design.SheetBattle_89.int64Value.getValue(wave, param);
		break;
	case 89:
		return _game_design.Enemy_design.SheetBattle_90.int64Value.getValue(wave, param);
		break;
	case 90:
		return _game_design.Enemy_design.SheetBattle_91.int64Value.getValue(wave, param);
		break;
	case 91:
		return _game_design.Enemy_design.SheetBattle_92.int64Value.getValue(wave, param);
		break;
	case 92:
		return _game_design.Enemy_design.SheetBattle_93.int64Value.getValue(wave, param);
		break;
	case 93:
		return _game_design.Enemy_design.SheetBattle_94.int64Value.getValue(wave, param);
		break;
	case 94:
		return _game_design.Enemy_design.SheetBattle_95.int64Value.getValue(wave, param);
		break;
	case 95:
		return _game_design.Enemy_design.SheetBattle_96.int64Value.getValue(wave, param);
		break;
	case 96:
		return _game_design.Enemy_design.SheetBattle_97.int64Value.getValue(wave, param);
		break;
	case 97:
		return _game_design.Enemy_design.SheetBattle_98.int64Value.getValue(wave, param);
		break;
	case 98:
		return _game_design.Enemy_design.SheetBattle_99.int64Value.getValue(wave, param);
		break;
	case 99:
		return _game_design.Enemy_design.SheetBattle_100.int64Value.getValue(wave, param);
		break;
	case 100:
		return _game_design.Enemy_design.SheetBattle_101.int64Value.getValue(wave, param);
		break;
	case 101:
		return _game_design.Enemy_design.SheetBattle_102.int64Value.getValue(wave, param);
		break;
	case 102:
		return _game_design.Enemy_design.SheetBattle_103.int64Value.getValue(wave, param);
		break;
	case 103:
		return _game_design.Enemy_design.SheetBattle_104.int64Value.getValue(wave, param);
		break;
	case 104:
		return _game_design.Enemy_design.SheetBattle_105.int64Value.getValue(wave, param);
		break;
	case 105:
		return _game_design.Enemy_design.SheetBattle_106.int64Value.getValue(wave, param);
		break;
	case 106:
		return _game_design.Enemy_design.SheetBattle_107.int64Value.getValue(wave, param);
		break;
	case 107:
		return _game_design.Enemy_design.SheetBattle_108.int64Value.getValue(wave, param);
		break;
	case 108:
		return _game_design.Enemy_design.SheetBattle_109.int64Value.getValue(wave, param);
		break;
	case 109:
		return _game_design.Enemy_design.SheetBattle_110.int64Value.getValue(wave, param);
		break;
	case 110:
		return _game_design.Enemy_design.SheetBattle_111.int64Value.getValue(wave, param);
		break;
	case 111:
		return _game_design.Enemy_design.SheetBattle_112.int64Value.getValue(wave, param);
		break;
	case 112:
		return _game_design.Enemy_design.SheetBattle_113.int64Value.getValue(wave, param);
		break;
	case 113:
		return _game_design.Enemy_design.SheetBattle_114.int64Value.getValue(wave, param);
		break;
	case 114:
		return _game_design.Enemy_design.SheetBattle_115.int64Value.getValue(wave, param);
		break;
	case 115:
		return _game_design.Enemy_design.SheetBattle_116.int64Value.getValue(wave, param);
		break;
	case 116:
		return _game_design.Enemy_design.SheetBattle_117.int64Value.getValue(wave, param);
		break;
	case 117:
		return _game_design.Enemy_design.SheetBattle_118.int64Value.getValue(wave, param);
		break;
	case 118:
		return _game_design.Enemy_design.SheetBattle_119.int64Value.getValue(wave, param);
		break;
	case 119:
		return _game_design.Enemy_design.SheetBattle_120.int64Value.getValue(wave, param);
		break;
	case 120:
		return _game_design.Enemy_design.SheetBattle_121.int64Value.getValue(wave, param);
		break;
	case 121:
		return _game_design.Enemy_design.SheetBattle_122.int64Value.getValue(wave, param);
		break;
	case 122:
		return _game_design.Enemy_design.SheetBattle_123.int64Value.getValue(wave, param);
		break;
	case 123:
		return _game_design.Enemy_design.SheetBattle_124.int64Value.getValue(wave, param);
		break;
	case 124:
		return _game_design.Enemy_design.SheetBattle_125.int64Value.getValue(wave, param);
		break;
	case 125:
		return _game_design.Enemy_design.SheetBattle_126.int64Value.getValue(wave, param);
		break;
	case 126:
		return _game_design.Enemy_design.SheetBattle_127.int64Value.getValue(wave, param);
		break;
	case 127:
		return _game_design.Enemy_design.SheetBattle_128.int64Value.getValue(wave, param);
		break;
	case 128:
		return _game_design.Enemy_design.SheetBattle_129.int64Value.getValue(wave, param);
		break;
	case 129:
		return _game_design.Enemy_design.SheetBattle_130.int64Value.getValue(wave, param);
		break;
	case 130:
		return _game_design.Enemy_design.SheetBattle_131.int64Value.getValue(wave, param);
		break;
	case 131:
		return _game_design.Enemy_design.SheetBattle_132.int64Value.getValue(wave, param);
		break;
	case 132:
		return _game_design.Enemy_design.SheetBattle_133.int64Value.getValue(wave, param);
		break;
	case 133:
		return _game_design.Enemy_design.SheetBattle_134.int64Value.getValue(wave, param);
		break;
	case 134:
		return _game_design.Enemy_design.SheetBattle_135.int64Value.getValue(wave, param);
		break;
	case 135:
		return _game_design.Enemy_design.SheetBattle_136.int64Value.getValue(wave, param);
		break;
	case 136:
		return _game_design.Enemy_design.SheetBattle_137.int64Value.getValue(wave, param);
		break;
	case 137:
		return _game_design.Enemy_design.SheetBattle_138.int64Value.getValue(wave, param);
		break;
	case 138:
		return _game_design.Enemy_design.SheetBattle_139.int64Value.getValue(wave, param);
		break;
	case 139:
		return _game_design.Enemy_design.SheetBattle_140.int64Value.getValue(wave, param);
		break;
	case 140:
		return _game_design.Enemy_design.SheetBattle_141.int64Value.getValue(wave, param);
		break;
	case 141:
		return _game_design.Enemy_design.SheetBattle_142.int64Value.getValue(wave, param);
		break;
	case 142:
		return _game_design.Enemy_design.SheetBattle_143.int64Value.getValue(wave, param);
		break;
	case 143:
		return _game_design.Enemy_design.SheetBattle_144.int64Value.getValue(wave, param);
		break;
	case 144:
		return _game_design.Enemy_design.SheetBattle_145.int64Value.getValue(wave, param);
		break;
	case 145:
		return _game_design.Enemy_design.SheetBattle_146.int64Value.getValue(wave, param);
		break;
	case 146:
		return _game_design.Enemy_design.SheetBattle_147.int64Value.getValue(wave, param);
		break;
	case 147:
		return _game_design.Enemy_design.SheetBattle_148.int64Value.getValue(wave, param);
		break;
	case 148:
		return _game_design.Enemy_design.SheetBattle_149.int64Value.getValue(wave, param);
		break;
	case 149:
		return _game_design.Enemy_design.SheetBattle_150.int64Value.getValue(wave, param);
		break;
	case 150:
		return _game_design.Enemy_design.SheetBattle_151.int64Value.getValue(wave, param);
		break;
	case 151:
		return _game_design.Enemy_design.SheetBattle_152.int64Value.getValue(wave, param);
		break;
	case 152:
		return _game_design.Enemy_design.SheetBattle_153.int64Value.getValue(wave, param);
		break;
	case 153:
		return _game_design.Enemy_design.SheetBattle_154.int64Value.getValue(wave, param);
		break;
	case 154:
		return _game_design.Enemy_design.SheetBattle_155.int64Value.getValue(wave, param);
		break;
	case 155:
		return _game_design.Enemy_design.SheetBattle_156.int64Value.getValue(wave, param);
		break;
	case 156:
		return _game_design.Enemy_design.SheetBattle_157.int64Value.getValue(wave, param);
		break;
	case 157:
		return _game_design.Enemy_design.SheetBattle_158.int64Value.getValue(wave, param);
		break;
	case 158:
		return _game_design.Enemy_design.SheetBattle_159.int64Value.getValue(wave, param);
		break;
	case 159:
		return _game_design.Enemy_design.SheetBattle_160.int64Value.getValue(wave, param);
		break;
	case 160:
		return _game_design.Enemy_design.SheetBattle_161.int64Value.getValue(wave, param);
		break;
	case 161:
		return _game_design.Enemy_design.SheetBattle_162.int64Value.getValue(wave, param);
		break;
	case 162:
		return _game_design.Enemy_design.SheetBattle_163.int64Value.getValue(wave, param);
		break;
	case 163:
		return _game_design.Enemy_design.SheetBattle_164.int64Value.getValue(wave, param);
		break;
	case 164:
		return _game_design.Enemy_design.SheetBattle_165.int64Value.getValue(wave, param);
		break;
	case 165:
		return _game_design.Enemy_design.SheetBattle_166.int64Value.getValue(wave, param);
		break;
	case 166:
		return _game_design.Enemy_design.SheetBattle_167.int64Value.getValue(wave, param);
		break;
	case 167:
		return _game_design.Enemy_design.SheetBattle_168.int64Value.getValue(wave, param);
		break;
	case 168:
		return _game_design.Enemy_design.SheetBattle_169.int64Value.getValue(wave, param);
		break;
	case 169:
		return _game_design.Enemy_design.SheetBattle_170.int64Value.getValue(wave, param);
		break;
	case 170:
		return _game_design.Enemy_design.SheetBattle_171.int64Value.getValue(wave, param);
		break;
	case 171:
		return _game_design.Enemy_design.SheetBattle_172.int64Value.getValue(wave, param);
		break;
	case 172:
		return _game_design.Enemy_design.SheetBattle_173.int64Value.getValue(wave, param);
		break;
	case 173:
		return _game_design.Enemy_design.SheetBattle_174.int64Value.getValue(wave, param);
		break;
	case 174:
		return _game_design.Enemy_design.SheetBattle_175.int64Value.getValue(wave, param);
		break;
	case 175:
		return _game_design.Enemy_design.SheetBattle_176.int64Value.getValue(wave, param);
		break;
	case 176:
		return _game_design.Enemy_design.SheetBattle_177.int64Value.getValue(wave, param);
		break;
	case 177:
		return _game_design.Enemy_design.SheetBattle_178.int64Value.getValue(wave, param);
		break;
	case 178:
		return _game_design.Enemy_design.SheetBattle_179.int64Value.getValue(wave, param);
		break;
	case 179:
		return _game_design.Enemy_design.SheetBattle_180.int64Value.getValue(wave, param);
		break;
	case 180:
		return _game_design.Enemy_design.SheetBattle_181.int64Value.getValue(wave, param);
		break;
	case 181:
		return _game_design.Enemy_design.SheetBattle_182.int64Value.getValue(wave, param);
		break;
	case 182:
		return _game_design.Enemy_design.SheetBattle_183.int64Value.getValue(wave, param);
		break;
	case 183:
		return _game_design.Enemy_design.SheetBattle_184.int64Value.getValue(wave, param);
		break;
	case 184:
		return _game_design.Enemy_design.SheetBattle_185.int64Value.getValue(wave, param);
		break;
	case 185:
		return _game_design.Enemy_design.SheetBattle_186.int64Value.getValue(wave, param);
		break;
	case 186:
		return _game_design.Enemy_design.SheetBattle_187.int64Value.getValue(wave, param);
		break;
	case 187:
		return _game_design.Enemy_design.SheetBattle_188.int64Value.getValue(wave, param);
		break;
	case 188:
		return _game_design.Enemy_design.SheetBattle_189.int64Value.getValue(wave, param);
		break;
	case 189:
		return _game_design.Enemy_design.SheetBattle_190.int64Value.getValue(wave, param);
		break;
	case 190:
		return _game_design.Enemy_design.SheetBattle_191.int64Value.getValue(wave, param);
		break;
	case 191:
		return _game_design.Enemy_design.SheetBattle_192.int64Value.getValue(wave, param);
		break;
	case 192:
		return _game_design.Enemy_design.SheetBattle_193.int64Value.getValue(wave, param);
		break;
	case 193:
		return _game_design.Enemy_design.SheetBattle_194.int64Value.getValue(wave, param);
		break;
	case 194:
		return _game_design.Enemy_design.SheetBattle_195.int64Value.getValue(wave, param);
		break;
	case 195:
		return _game_design.Enemy_design.SheetBattle_196.int64Value.getValue(wave, param);
		break;
	case 196:
		return _game_design.Enemy_design.SheetBattle_197.int64Value.getValue(wave, param);
		break;
	case 197:
		return _game_design.Enemy_design.SheetBattle_198.int64Value.getValue(wave, param);
		break;
	case 198:
		return _game_design.Enemy_design.SheetBattle_199.int64Value.getValue(wave, param);
		break;
	case 199:
		return _game_design.Enemy_design.SheetBattle_200.int64Value.getValue(wave, param);
		break;
	case 200:
		return _game_design.Enemy_design.SheetBattle_201.int64Value.getValue(wave, param);
		break;
	case 201:
		return _game_design.Enemy_design.SheetBattle_202.int64Value.getValue(wave, param);
		break;
	case 202:
		return _game_design.Enemy_design.SheetBattle_203.int64Value.getValue(wave, param);
		break;
	case 203:
		return _game_design.Enemy_design.SheetBattle_204.int64Value.getValue(wave, param);
		break;
	case 204:
		return _game_design.Enemy_design.SheetBattle_205.int64Value.getValue(wave, param);
		break;
	case 205:
		return _game_design.Enemy_design.SheetBattle_206.int64Value.getValue(wave, param);
		break;
	case 206:
		return _game_design.Enemy_design.SheetBattle_207.int64Value.getValue(wave, param);
		break;
	case 207:
		return _game_design.Enemy_design.SheetBattle_208.int64Value.getValue(wave, param);
		break;
	case 208:
		return _game_design.Enemy_design.SheetBattle_209.int64Value.getValue(wave, param);
		break;
	case 209:
		return _game_design.Enemy_design.SheetBattle_210.int64Value.getValue(wave, param);
		break;
	case 210:
		return _game_design.Enemy_design.SheetBattle_211.int64Value.getValue(wave, param);
		break;
	case 211:
		return _game_design.Enemy_design.SheetBattle_212.int64Value.getValue(wave, param);
		break;
	case 212:
		return _game_design.Enemy_design.SheetBattle_213.int64Value.getValue(wave, param);
		break;
	case 213:
		return _game_design.Enemy_design.SheetBattle_214.int64Value.getValue(wave, param);
		break;
	case 214:
		return _game_design.Enemy_design.SheetBattle_215.int64Value.getValue(wave, param);
		break;
	case 215:
		return _game_design.Enemy_design.SheetBattle_216.int64Value.getValue(wave, param);
		break;
	case 216:
		return _game_design.Enemy_design.SheetBattle_217.int64Value.getValue(wave, param);
		break;
	case 217:
		return _game_design.Enemy_design.SheetBattle_218.int64Value.getValue(wave, param);
		break;
	case 218:
		return _game_design.Enemy_design.SheetBattle_219.int64Value.getValue(wave, param);
		break;
	case 219:
		return _game_design.Enemy_design.SheetBattle_220.int64Value.getValue(wave, param);
		break;
	case 220:
		return _game_design.Enemy_design.SheetBattle_221.int64Value.getValue(wave, param);
		break;
	case 221:
		return _game_design.Enemy_design.SheetBattle_222.int64Value.getValue(wave, param);
		break;
	case 222:
		return _game_design.Enemy_design.SheetBattle_223.int64Value.getValue(wave, param);
		break;
	case 223:
		return _game_design.Enemy_design.SheetBattle_224.int64Value.getValue(wave, param);
		break;
	case 224:
		return _game_design.Enemy_design.SheetBattle_225.int64Value.getValue(wave, param);
		break;
	case 225:
		return _game_design.Enemy_design.SheetBattle_226.int64Value.getValue(wave, param);
		break;
	case 226:
		return _game_design.Enemy_design.SheetBattle_227.int64Value.getValue(wave, param);
		break;
	case 227:
		return _game_design.Enemy_design.SheetBattle_228.int64Value.getValue(wave, param);
		break;
	case 228:
		return _game_design.Enemy_design.SheetBattle_229.int64Value.getValue(wave, param);
		break;
	case 229:
		return _game_design.Enemy_design.SheetBattle_230.int64Value.getValue(wave, param);
		break;
	case 230:
		return _game_design.Enemy_design.SheetBattle_231.int64Value.getValue(wave, param);
		break;
	case 231:
		return _game_design.Enemy_design.SheetBattle_232.int64Value.getValue(wave, param);
		break;
	case 232:
		return _game_design.Enemy_design.SheetBattle_233.int64Value.getValue(wave, param);
		break;
	case 233:
		return _game_design.Enemy_design.SheetBattle_234.int64Value.getValue(wave, param);
		break;
	case 234:
		return _game_design.Enemy_design.SheetBattle_235.int64Value.getValue(wave, param);
		break;
	case 235:
		return _game_design.Enemy_design.SheetBattle_236.int64Value.getValue(wave, param);
		break;
	case 236:
		return _game_design.Enemy_design.SheetBattle_237.int64Value.getValue(wave, param);
		break;
	case 237:
		return _game_design.Enemy_design.SheetBattle_238.int64Value.getValue(wave, param);
		break;
	case 238:
		return _game_design.Enemy_design.SheetBattle_239.int64Value.getValue(wave, param);
		break;
	case 239:
		return _game_design.Enemy_design.SheetBattle_240.int64Value.getValue(wave, param);
		break;
	case 240:
		return _game_design.Enemy_design.SheetBattle_241.int64Value.getValue(wave, param);
		break;
	case 241:
		return _game_design.Enemy_design.SheetBattle_242.int64Value.getValue(wave, param);
		break;
	case 242:
		return _game_design.Enemy_design.SheetBattle_243.int64Value.getValue(wave, param);
		break;
	case 243:
		return _game_design.Enemy_design.SheetBattle_244.int64Value.getValue(wave, param);
		break;
	case 244:
		return _game_design.Enemy_design.SheetBattle_245.int64Value.getValue(wave, param);
		break;
	case 245:
		return _game_design.Enemy_design.SheetBattle_246.int64Value.getValue(wave, param);
		break;
	case 246:
		return _game_design.Enemy_design.SheetBattle_247.int64Value.getValue(wave, param);
		break;
	case 247:
		return _game_design.Enemy_design.SheetBattle_248.int64Value.getValue(wave, param);
		break;
	case 248:
		return _game_design.Enemy_design.SheetBattle_249.int64Value.getValue(wave, param);
		break;
	case 249:
		return _game_design.Enemy_design.SheetBattle_250.int64Value.getValue(wave, param);
		break;
	case 250:
		return _game_design.Enemy_design.SheetBattle_251.int64Value.getValue(wave, param);
		break;
	case 251:
		return _game_design.Enemy_design.SheetBattle_252.int64Value.getValue(wave, param);
		break;
	case 252:
		return _game_design.Enemy_design.SheetBattle_253.int64Value.getValue(wave, param);
		break;
	case 253:
		return _game_design.Enemy_design.SheetBattle_254.int64Value.getValue(wave, param);
		break;
	case 254:
		return _game_design.Enemy_design.SheetBattle_255.int64Value.getValue(wave, param);
		break;
	case 255:
		return _game_design.Enemy_design.SheetBattle_256.int64Value.getValue(wave, param);
		break;
	case 256:
		return _game_design.Enemy_design.SheetBattle_257.int64Value.getValue(wave, param);
		break;
	case 257:
		return _game_design.Enemy_design.SheetBattle_258.int64Value.getValue(wave, param);
		break;
	case 258:
		return _game_design.Enemy_design.SheetBattle_259.int64Value.getValue(wave, param);
		break;
	case 259:
		return _game_design.Enemy_design.SheetBattle_260.int64Value.getValue(wave, param);
		break;
	case 260:
		return _game_design.Enemy_design.SheetBattle_261.int64Value.getValue(wave, param);
		break;
	case 261:
		return _game_design.Enemy_design.SheetBattle_262.int64Value.getValue(wave, param);
		break;
	case 262:
		return _game_design.Enemy_design.SheetBattle_263.int64Value.getValue(wave, param);
		break;
	case 263:
		return _game_design.Enemy_design.SheetBattle_264.int64Value.getValue(wave, param);
		break;
	case 264:
		return _game_design.Enemy_design.SheetBattle_265.int64Value.getValue(wave, param);
		break;
	case 265:
		return _game_design.Enemy_design.SheetBattle_266.int64Value.getValue(wave, param);
		break;
	case 266:
		return _game_design.Enemy_design.SheetBattle_267.int64Value.getValue(wave, param);
		break;
	case 267:
		return _game_design.Enemy_design.SheetBattle_268.int64Value.getValue(wave, param);
		break;
	case 268:
		return _game_design.Enemy_design.SheetBattle_269.int64Value.getValue(wave, param);
		break;
	case 269:
		return _game_design.Enemy_design.SheetBattle_270.int64Value.getValue(wave, param);
		break;
	case 270:
		return _game_design.Enemy_design.SheetBattle_271.int64Value.getValue(wave, param);
		break;
	case 271:
		return _game_design.Enemy_design.SheetBattle_272.int64Value.getValue(wave, param);
		break;
	case 272:
		return _game_design.Enemy_design.SheetBattle_273.int64Value.getValue(wave, param);
		break;
	case 273:
		return _game_design.Enemy_design.SheetBattle_274.int64Value.getValue(wave, param);
		break;
	case 274:
		return _game_design.Enemy_design.SheetBattle_275.int64Value.getValue(wave, param);
		break;
	case 275:
		return _game_design.Enemy_design.SheetBattle_276.int64Value.getValue(wave, param);
		break;
	case 276:
		return _game_design.Enemy_design.SheetBattle_277.int64Value.getValue(wave, param);
		break;
	case 277:
		return _game_design.Enemy_design.SheetBattle_278.int64Value.getValue(wave, param);
		break;
	case 278:
		return _game_design.Enemy_design.SheetBattle_279.int64Value.getValue(wave, param);
		break;
	case 279:
		return _game_design.Enemy_design.SheetBattle_280.int64Value.getValue(wave, param);
		break;
	case 280:
		return _game_design.Enemy_design.SheetBattle_281.int64Value.getValue(wave, param);
		break;
	case 281:
		return _game_design.Enemy_design.SheetBattle_282.int64Value.getValue(wave, param);
		break;
	case 282:
		return _game_design.Enemy_design.SheetBattle_283.int64Value.getValue(wave, param);
		break;
	case 283:
		return _game_design.Enemy_design.SheetBattle_284.int64Value.getValue(wave, param);
		break;
	case 284:
		return _game_design.Enemy_design.SheetBattle_285.int64Value.getValue(wave, param);
		break;
	case 285:
		return _game_design.Enemy_design.SheetBattle_286.int64Value.getValue(wave, param);
		break;
	case 286:
		return _game_design.Enemy_design.SheetBattle_287.int64Value.getValue(wave, param);
		break;
	case 287:
		return _game_design.Enemy_design.SheetBattle_288.int64Value.getValue(wave, param);
		break;
	case 288:
		return _game_design.Enemy_design.SheetBattle_289.int64Value.getValue(wave, param);
		break;
	case 289:
		return _game_design.Enemy_design.SheetBattle_290.int64Value.getValue(wave, param);
		break;
	case 290:
		return _game_design.Enemy_design.SheetBattle_291.int64Value.getValue(wave, param);
		break;
	case 291:
		return _game_design.Enemy_design.SheetBattle_292.int64Value.getValue(wave, param);
		break;
	case 292:
		return _game_design.Enemy_design.SheetBattle_293.int64Value.getValue(wave, param);
		break;
	case 293:
		return _game_design.Enemy_design.SheetBattle_294.int64Value.getValue(wave, param);
		break;
	case 294:
		return _game_design.Enemy_design.SheetBattle_295.int64Value.getValue(wave, param);
		break;
	case 295:
		return _game_design.Enemy_design.SheetBattle_296.int64Value.getValue(wave, param);
		break;
	case 296:
		return _game_design.Enemy_design.SheetBattle_297.int64Value.getValue(wave, param);
		break;
	case 297:
		return _game_design.Enemy_design.SheetBattle_298.int64Value.getValue(wave, param);
		break;
	case 298:
		return _game_design.Enemy_design.SheetBattle_299.int64Value.getValue(wave, param);
		break;
	case 299:
		return _game_design.Enemy_design.SheetBattle_300.int64Value.getValue(wave, param);
		break;
	case 300:
		return _game_design.Enemy_design.SheetBattle_301.int64Value.getValue(wave, param);
		break;
	case 301:
		return _game_design.Enemy_design.SheetBattle_302.int64Value.getValue(wave, param);
		break;
	case 302:
		return _game_design.Enemy_design.SheetBattle_303.int64Value.getValue(wave, param);
		break;
	case 303:
		return _game_design.Enemy_design.SheetBattle_304.int64Value.getValue(wave, param);
		break;
	case 304:
		return _game_design.Enemy_design.SheetBattle_305.int64Value.getValue(wave, param);
		break;
	case 305:
		return _game_design.Enemy_design.SheetBattle_306.int64Value.getValue(wave, param);
		break;
	case 306:
		return _game_design.Enemy_design.SheetBattle_307.int64Value.getValue(wave, param);
		break;
	case 307:
		return _game_design.Enemy_design.SheetBattle_308.int64Value.getValue(wave, param);
		break;
	case 308:
		return _game_design.Enemy_design.SheetBattle_309.int64Value.getValue(wave, param);
		break;
	case 309:
		return _game_design.Enemy_design.SheetBattle_310.int64Value.getValue(wave, param);
		break;
	case 310:
		return _game_design.Enemy_design.SheetBattle_311.int64Value.getValue(wave, param);
		break;
	case 311:
		return _game_design.Enemy_design.SheetBattle_312.int64Value.getValue(wave, param);
		break;
	case 312:
		return _game_design.Enemy_design.SheetBattle_313.int64Value.getValue(wave, param);
		break;
	case 313:
		return _game_design.Enemy_design.SheetBattle_314.int64Value.getValue(wave, param);
		break;
	case 314:
		return _game_design.Enemy_design.SheetBattle_315.int64Value.getValue(wave, param);
		break;
	case 315:
		return _game_design.Enemy_design.SheetBattle_316.int64Value.getValue(wave, param);
		break;
	case 316:
		return _game_design.Enemy_design.SheetBattle_317.int64Value.getValue(wave, param);
		break;
	case 317:
		return _game_design.Enemy_design.SheetBattle_318.int64Value.getValue(wave, param);
		break;
	case 318:
		return _game_design.Enemy_design.SheetBattle_319.int64Value.getValue(wave, param);
		break;
	case 319:
		return _game_design.Enemy_design.SheetBattle_320.int64Value.getValue(wave, param);
		break;
	case 320:
		return _game_design.Enemy_design.SheetBattle_321.int64Value.getValue(wave, param);
		break;
	case 321:
		return _game_design.Enemy_design.SheetBattle_322.int64Value.getValue(wave, param);
		break;
	case 322:
		return _game_design.Enemy_design.SheetBattle_323.int64Value.getValue(wave, param);
		break;
	case 323:
		return _game_design.Enemy_design.SheetBattle_324.int64Value.getValue(wave, param);
		break;
	case 324:
		return _game_design.Enemy_design.SheetBattle_325.int64Value.getValue(wave, param);
		break;
	case 325:
		return _game_design.Enemy_design.SheetBattle_326.int64Value.getValue(wave, param);
		break;
	case 326:
		return _game_design.Enemy_design.SheetBattle_327.int64Value.getValue(wave, param);
		break;
	case 327:
		return _game_design.Enemy_design.SheetBattle_328.int64Value.getValue(wave, param);
		break;
	case 328:
		return _game_design.Enemy_design.SheetBattle_329.int64Value.getValue(wave, param);
		break;
	case 329:
		return _game_design.Enemy_design.SheetBattle_330.int64Value.getValue(wave, param);
		break;
	case 330:
		return _game_design.Enemy_design.SheetBattle_331.int64Value.getValue(wave, param);
		break;
	case 331:
		return _game_design.Enemy_design.SheetBattle_332.int64Value.getValue(wave, param);
		break;
	case 332:
		return _game_design.Enemy_design.SheetBattle_333.int64Value.getValue(wave, param);
		break;
	case 333:
		return _game_design.Enemy_design.SheetBattle_334.int64Value.getValue(wave, param);
		break;
	case 334:
		return _game_design.Enemy_design.SheetBattle_335.int64Value.getValue(wave, param);
		break;
	case 335:
		return _game_design.Enemy_design.SheetBattle_336.int64Value.getValue(wave, param);
		break;
	case 336:
		return _game_design.Enemy_design.SheetBattle_337.int64Value.getValue(wave, param);
		break;
	case 337:
		return _game_design.Enemy_design.SheetBattle_338.int64Value.getValue(wave, param);
		break;
	case 338:
		return _game_design.Enemy_design.SheetBattle_339.int64Value.getValue(wave, param);
		break;
	case 339:
		return _game_design.Enemy_design.SheetBattle_340.int64Value.getValue(wave, param);
		break;
	case 340:
		return _game_design.Enemy_design.SheetBattle_341.int64Value.getValue(wave, param);
		break;
	case 341:
		return _game_design.Enemy_design.SheetBattle_342.int64Value.getValue(wave, param);
		break;
	case 342:
		return _game_design.Enemy_design.SheetBattle_343.int64Value.getValue(wave, param);
		break;
	case 343:
		return _game_design.Enemy_design.SheetBattle_344.int64Value.getValue(wave, param);
		break;
	case 344:
		return _game_design.Enemy_design.SheetBattle_345.int64Value.getValue(wave, param);
		break;
	case 345:
		return _game_design.Enemy_design.SheetBattle_346.int64Value.getValue(wave, param);
		break;
	case 346:
		return _game_design.Enemy_design.SheetBattle_347.int64Value.getValue(wave, param);
		break;
	case 347:
		return _game_design.Enemy_design.SheetBattle_348.int64Value.getValue(wave, param);
		break;
	case 348:
		return _game_design.Enemy_design.SheetBattle_349.int64Value.getValue(wave, param);
		break;
	case 349:
		return _game_design.Enemy_design.SheetBattle_350.int64Value.getValue(wave, param);
		break;
	case 350:
		return _game_design.Enemy_design.SheetBattle_351.int64Value.getValue(wave, param);
		break;
	case 351:
		return _game_design.Enemy_design.SheetBattle_352.int64Value.getValue(wave, param);
		break;
	case 352:
		return _game_design.Enemy_design.SheetBattle_353.int64Value.getValue(wave, param);
		break;
	case 353:
		return _game_design.Enemy_design.SheetBattle_354.int64Value.getValue(wave, param);
		break;
	case 354:
		return _game_design.Enemy_design.SheetBattle_355.int64Value.getValue(wave, param);
		break;
	case 355:
		return _game_design.Enemy_design.SheetBattle_356.int64Value.getValue(wave, param);
		break;
	case 356:
		return _game_design.Enemy_design.SheetBattle_357.int64Value.getValue(wave, param);
		break;
	case 357:
		return _game_design.Enemy_design.SheetBattle_358.int64Value.getValue(wave, param);
		break;
	case 358:
		return _game_design.Enemy_design.SheetBattle_359.int64Value.getValue(wave, param);
		break;
	case 359:
		return _game_design.Enemy_design.SheetBattle_360.int64Value.getValue(wave, param);
		break;
	case 360:
		return _game_design.Enemy_design.SheetBattle_361.int64Value.getValue(wave, param);
		break;
	case 361:
		return _game_design.Enemy_design.SheetBattle_362.int64Value.getValue(wave, param);
		break;
	case 362:
		return _game_design.Enemy_design.SheetBattle_363.int64Value.getValue(wave, param);
		break;
	case 363:
		return _game_design.Enemy_design.SheetBattle_364.int64Value.getValue(wave, param);
		break;
	case 364:
		return _game_design.Enemy_design.SheetBattle_365.int64Value.getValue(wave, param);
		break;
	case 365:
		return _game_design.Enemy_design.SheetBattle_366.int64Value.getValue(wave, param);
		break;
	case 366:
		return _game_design.Enemy_design.SheetBattle_367.int64Value.getValue(wave, param);
		break;
	case 367:
		return _game_design.Enemy_design.SheetBattle_368.int64Value.getValue(wave, param);
		break;
	case 368:
		return _game_design.Enemy_design.SheetBattle_369.int64Value.getValue(wave, param);
		break;
	case 369:
		return _game_design.Enemy_design.SheetBattle_370.int64Value.getValue(wave, param);
		break;
	case 370:
		return _game_design.Enemy_design.SheetBattle_371.int64Value.getValue(wave, param);
		break;
	case 371:
		return _game_design.Enemy_design.SheetBattle_372.int64Value.getValue(wave, param);
		break;
	case 372:
		return _game_design.Enemy_design.SheetBattle_373.int64Value.getValue(wave, param);
		break;
	case 373:
		return _game_design.Enemy_design.SheetBattle_374.int64Value.getValue(wave, param);
		break;
	case 374:
		return _game_design.Enemy_design.SheetBattle_375.int64Value.getValue(wave, param);
		break;
	case 375:
		return _game_design.Enemy_design.SheetBattle_376.int64Value.getValue(wave, param);
		break;
	case 376:
		return _game_design.Enemy_design.SheetBattle_377.int64Value.getValue(wave, param);
		break;
	case 377:
		return _game_design.Enemy_design.SheetBattle_378.int64Value.getValue(wave, param);
		break;
	case 378:
		return _game_design.Enemy_design.SheetBattle_379.int64Value.getValue(wave, param);
		break;
	case 379:
		return _game_design.Enemy_design.SheetBattle_380.int64Value.getValue(wave, param);
		break;
	case 380:
		return _game_design.Enemy_design.SheetBattle_381.int64Value.getValue(wave, param);
		break;
	case 381:
		return _game_design.Enemy_design.SheetBattle_382.int64Value.getValue(wave, param);
		break;
	case 382:
		return _game_design.Enemy_design.SheetBattle_383.int64Value.getValue(wave, param);
		break;
	case 383:
		return _game_design.Enemy_design.SheetBattle_384.int64Value.getValue(wave, param);
		break;
	case 384:
		return _game_design.Enemy_design.SheetBattle_385.int64Value.getValue(wave, param);
		break;
	case 385:
		return _game_design.Enemy_design.SheetBattle_386.int64Value.getValue(wave, param);
		break;
	case 386:
		return _game_design.Enemy_design.SheetBattle_387.int64Value.getValue(wave, param);
		break;
	case 387:
		return _game_design.Enemy_design.SheetBattle_388.int64Value.getValue(wave, param);
		break;
	case 388:
		return _game_design.Enemy_design.SheetBattle_389.int64Value.getValue(wave, param);
		break;
	case 389:
		return _game_design.Enemy_design.SheetBattle_390.int64Value.getValue(wave, param);
		break;
	case 390:
		return _game_design.Enemy_design.SheetBattle_391.int64Value.getValue(wave, param);
		break;
	case 391:
		return _game_design.Enemy_design.SheetBattle_392.int64Value.getValue(wave, param);
		break;
	case 392:
		return _game_design.Enemy_design.SheetBattle_393.int64Value.getValue(wave, param);
		break;
	case 393:
		return _game_design.Enemy_design.SheetBattle_394.int64Value.getValue(wave, param);
		break;
	case 394:
		return _game_design.Enemy_design.SheetBattle_395.int64Value.getValue(wave, param);
		break;
	case 395:
		return _game_design.Enemy_design.SheetBattle_396.int64Value.getValue(wave, param);
		break;
	case 396:
		return _game_design.Enemy_design.SheetBattle_397.int64Value.getValue(wave, param);
		break;
	case 397:
		return _game_design.Enemy_design.SheetBattle_398.int64Value.getValue(wave, param);
		break;
	case 398:
		return _game_design.Enemy_design.SheetBattle_399.int64Value.getValue(wave, param);
		break;
	case 399:
		return _game_design.Enemy_design.SheetBattle_400.int64Value.getValue(wave, param);
		break;
	case 400:
		return _game_design.Enemy_design.SheetBattle_401.int64Value.getValue(wave, param);
		break;
	case 401:
		return _game_design.Enemy_design.SheetBattle_402.int64Value.getValue(wave, param);
		break;
	case 402:
		return _game_design.Enemy_design.SheetBattle_403.int64Value.getValue(wave, param);
		break;
	case 403:
		return _game_design.Enemy_design.SheetBattle_404.int64Value.getValue(wave, param);
		break;
	case 404:
		return _game_design.Enemy_design.SheetBattle_405.int64Value.getValue(wave, param);
		break;
	case 405:
		return _game_design.Enemy_design.SheetBattle_406.int64Value.getValue(wave, param);
		break;
	case 406:
		return _game_design.Enemy_design.SheetBattle_407.int64Value.getValue(wave, param);
		break;
	case 407:
		return _game_design.Enemy_design.SheetBattle_408.int64Value.getValue(wave, param);
		break;
	case 408:
		return _game_design.Enemy_design.SheetBattle_409.int64Value.getValue(wave, param);
		break;
	case 409:
		return _game_design.Enemy_design.SheetBattle_410.int64Value.getValue(wave, param);
		break;
	case 410:
		return _game_design.Enemy_design.SheetBattle_411.int64Value.getValue(wave, param);
		break;
	case 411:
		return _game_design.Enemy_design.SheetBattle_412.int64Value.getValue(wave, param);
		break;
	case 412:
		return _game_design.Enemy_design.SheetBattle_413.int64Value.getValue(wave, param);
		break;
	case 413:
		return _game_design.Enemy_design.SheetBattle_414.int64Value.getValue(wave, param);
		break;
	case 414:
		return _game_design.Enemy_design.SheetBattle_415.int64Value.getValue(wave, param);
		break;
	case 415:
		return _game_design.Enemy_design.SheetBattle_416.int64Value.getValue(wave, param);
		break;
	case 416:
		return _game_design.Enemy_design.SheetBattle_417.int64Value.getValue(wave, param);
		break;
	case 417:
		return _game_design.Enemy_design.SheetBattle_418.int64Value.getValue(wave, param);
		break;
	case 418:
		return _game_design.Enemy_design.SheetBattle_419.int64Value.getValue(wave, param);
		break;
	case 419:
		return _game_design.Enemy_design.SheetBattle_420.int64Value.getValue(wave, param);
		break;
	case 420:
		return _game_design.Enemy_design.SheetBattle_421.int64Value.getValue(wave, param);
		break;
	case 421:
		return _game_design.Enemy_design.SheetBattle_422.int64Value.getValue(wave, param);
		break;
	case 422:
		return _game_design.Enemy_design.SheetBattle_423.int64Value.getValue(wave, param);
		break;
	case 423:
		return _game_design.Enemy_design.SheetBattle_424.int64Value.getValue(wave, param);
		break;
	case 424:
		return _game_design.Enemy_design.SheetBattle_425.int64Value.getValue(wave, param);
		break;
	case 425:
		return _game_design.Enemy_design.SheetBattle_426.int64Value.getValue(wave, param);
		break;
	case 426:
		return _game_design.Enemy_design.SheetBattle_427.int64Value.getValue(wave, param);
		break;
	case 427:
		return _game_design.Enemy_design.SheetBattle_428.int64Value.getValue(wave, param);
		break;
	case 428:
		return _game_design.Enemy_design.SheetBattle_429.int64Value.getValue(wave, param);
		break;
	case 429:
		return _game_design.Enemy_design.SheetBattle_430.int64Value.getValue(wave, param);
		break;
	case 430:
		return _game_design.Enemy_design.SheetBattle_431.int64Value.getValue(wave, param);
		break;
	case 431:
		return _game_design.Enemy_design.SheetBattle_432.int64Value.getValue(wave, param);
		break;
	case 432:
		return _game_design.Enemy_design.SheetBattle_433.int64Value.getValue(wave, param);
		break;
	case 433:
		return _game_design.Enemy_design.SheetBattle_434.int64Value.getValue(wave, param);
		break;
	case 434:
		return _game_design.Enemy_design.SheetBattle_435.int64Value.getValue(wave, param);
		break;
	case 435:
		return _game_design.Enemy_design.SheetBattle_436.int64Value.getValue(wave, param);
		break;
	case 436:
		return _game_design.Enemy_design.SheetBattle_437.int64Value.getValue(wave, param);
		break;
	case 437:
		return _game_design.Enemy_design.SheetBattle_438.int64Value.getValue(wave, param);
		break;
	case 438:
		return _game_design.Enemy_design.SheetBattle_439.int64Value.getValue(wave, param);
		break;
	case 439:
		return _game_design.Enemy_design.SheetBattle_440.int64Value.getValue(wave, param);
		break;
	case 440:
		return _game_design.Enemy_design.SheetBattle_441.int64Value.getValue(wave, param);
		break;
	case 441:
		return _game_design.Enemy_design.SheetBattle_442.int64Value.getValue(wave, param);
		break;
	case 442:
		return _game_design.Enemy_design.SheetBattle_443.int64Value.getValue(wave, param);
		break;
	case 443:
		return _game_design.Enemy_design.SheetBattle_444.int64Value.getValue(wave, param);
		break;
	case 444:
		return _game_design.Enemy_design.SheetBattle_445.int64Value.getValue(wave, param);
		break;
	case 445:
		return _game_design.Enemy_design.SheetBattle_446.int64Value.getValue(wave, param);
		break;
	case 446:
		return _game_design.Enemy_design.SheetBattle_447.int64Value.getValue(wave, param);
		break;
	case 447:
		return _game_design.Enemy_design.SheetBattle_448.int64Value.getValue(wave, param);
		break;
	case 448:
		return _game_design.Enemy_design.SheetBattle_449.int64Value.getValue(wave, param);
		break;
	case 449:
		return _game_design.Enemy_design.SheetBattle_450.int64Value.getValue(wave, param);
		break;
	case 450:
		return _game_design.Enemy_design.SheetBattle_451.int64Value.getValue(wave, param);
		break;
	case 451:
		return _game_design.Enemy_design.SheetBattle_452.int64Value.getValue(wave, param);
		break;
	case 452:
		return _game_design.Enemy_design.SheetBattle_453.int64Value.getValue(wave, param);
		break;
	case 453:
		return _game_design.Enemy_design.SheetBattle_454.int64Value.getValue(wave, param);
		break;
	case 454:
		return _game_design.Enemy_design.SheetBattle_455.int64Value.getValue(wave, param);
		break;
	case 455:
		return _game_design.Enemy_design.SheetBattle_456.int64Value.getValue(wave, param);
		break;
	case 456:
		return _game_design.Enemy_design.SheetBattle_457.int64Value.getValue(wave, param);
		break;
	case 457:
		return _game_design.Enemy_design.SheetBattle_458.int64Value.getValue(wave, param);
		break;
	case 458:
		return _game_design.Enemy_design.SheetBattle_459.int64Value.getValue(wave, param);
		break;
	case 459:
		return _game_design.Enemy_design.SheetBattle_460.int64Value.getValue(wave, param);
		break;
	case 460:
		return _game_design.Enemy_design.SheetBattle_461.int64Value.getValue(wave, param);
		break;
	case 461:
		return _game_design.Enemy_design.SheetBattle_462.int64Value.getValue(wave, param);
		break;
	case 462:
		return _game_design.Enemy_design.SheetBattle_463.int64Value.getValue(wave, param);
		break;
	case 463:
		return _game_design.Enemy_design.SheetBattle_464.int64Value.getValue(wave, param);
		break;
	case 464:
		return _game_design.Enemy_design.SheetBattle_465.int64Value.getValue(wave, param);
		break;
	case 465:
		return _game_design.Enemy_design.SheetBattle_466.int64Value.getValue(wave, param);
		break;
	case 466:
		return _game_design.Enemy_design.SheetBattle_467.int64Value.getValue(wave, param);
		break;
	case 467:
		return _game_design.Enemy_design.SheetBattle_468.int64Value.getValue(wave, param);
		break;
	case 468:
		return _game_design.Enemy_design.SheetBattle_469.int64Value.getValue(wave, param);
		break;
	case 469:
		return _game_design.Enemy_design.SheetBattle_470.int64Value.getValue(wave, param);
		break;
	case 470:
		return _game_design.Enemy_design.SheetBattle_471.int64Value.getValue(wave, param);
		break;
	case 471:
		return _game_design.Enemy_design.SheetBattle_472.int64Value.getValue(wave, param);
		break;
	case 472:
		return _game_design.Enemy_design.SheetBattle_473.int64Value.getValue(wave, param);
		break;
	case 473:
		return _game_design.Enemy_design.SheetBattle_474.int64Value.getValue(wave, param);
		break;
	case 474:
		return _game_design.Enemy_design.SheetBattle_475.int64Value.getValue(wave, param);
		break;
	case 475:
		return _game_design.Enemy_design.SheetBattle_476.int64Value.getValue(wave, param);
		break;
	case 476:
		return _game_design.Enemy_design.SheetBattle_477.int64Value.getValue(wave, param);
		break;
	case 477:
		return _game_design.Enemy_design.SheetBattle_478.int64Value.getValue(wave, param);
		break;
	case 478:
		return _game_design.Enemy_design.SheetBattle_479.int64Value.getValue(wave, param);
		break;
	case 479:
		return _game_design.Enemy_design.SheetBattle_480.int64Value.getValue(wave, param);
		break;
	case 480:
		return _game_design.Enemy_design.SheetBattle_481.int64Value.getValue(wave, param);
		break;
	case 481:
		return _game_design.Enemy_design.SheetBattle_482.int64Value.getValue(wave, param);
		break;
	case 482:
		return _game_design.Enemy_design.SheetBattle_483.int64Value.getValue(wave, param);
		break;
	case 483:
		return _game_design.Enemy_design.SheetBattle_484.int64Value.getValue(wave, param);
		break;
	case 484:
		return _game_design.Enemy_design.SheetBattle_485.int64Value.getValue(wave, param);
		break;
	case 485:
		return _game_design.Enemy_design.SheetBattle_486.int64Value.getValue(wave, param);
		break;
	case 486:
		return _game_design.Enemy_design.SheetBattle_487.int64Value.getValue(wave, param);
		break;
	case 487:
		return _game_design.Enemy_design.SheetBattle_488.int64Value.getValue(wave, param);
		break;
	case 488:
		return _game_design.Enemy_design.SheetBattle_489.int64Value.getValue(wave, param);
		break;
	case 489:
		return _game_design.Enemy_design.SheetBattle_490.int64Value.getValue(wave, param);
		break;
	case 490:
		return _game_design.Enemy_design.SheetBattle_491.int64Value.getValue(wave, param);
		break;
	case 491:
		return _game_design.Enemy_design.SheetBattle_492.int64Value.getValue(wave, param);
		break;
	case 492:
		return _game_design.Enemy_design.SheetBattle_493.int64Value.getValue(wave, param);
		break;
	case 493:
		return _game_design.Enemy_design.SheetBattle_494.int64Value.getValue(wave, param);
		break;
	case 494:
		return _game_design.Enemy_design.SheetBattle_495.int64Value.getValue(wave, param);
		break;
	case 495:
		return _game_design.Enemy_design.SheetBattle_496.int64Value.getValue(wave, param);
		break;
	case 496:
		return _game_design.Enemy_design.SheetBattle_497.int64Value.getValue(wave, param);
		break;
	case 497:
		return _game_design.Enemy_design.SheetBattle_498.int64Value.getValue(wave, param);
		break;
	case 498:
		return _game_design.Enemy_design.SheetBattle_499.int64Value.getValue(wave, param);
		break;
	case 499:
		return _game_design.Enemy_design.SheetBattle_500.int64Value.getValue(wave, param);
		break;
	default:
		return _game_design.Enemy_design.SheetBattle_500.int64Value.getValue(wave, param);
		break;
	}

}

int TDGame::GetDesignBattleGeneral(int battle, int wave, int param)
{
#if GAME_DEBUG
#if define MAC_OS
#else
	battle = GAME_DEBUG_BATTLE_FIX - 1;
#endif
#endif
	switch (battle)
	{
	case 0:
		return _game_design.Enemy_design.SheetBattle_1.int32Value.getValue(wave, param);
		break;
	case 1:
		return _game_design.Enemy_design.SheetBattle_2.int32Value.getValue(wave, param);
		break;
	case 2:
		return _game_design.Enemy_design.SheetBattle_3.int32Value.getValue(wave, param);
		break;
	case 3:
		return _game_design.Enemy_design.SheetBattle_4.int32Value.getValue(wave, param);
		break;
	case 4:
		return _game_design.Enemy_design.SheetBattle_5.int32Value.getValue(wave, param);
		break;
	case 5:
		return _game_design.Enemy_design.SheetBattle_6.int32Value.getValue(wave, param);
		break;
	case 6:
		return _game_design.Enemy_design.SheetBattle_7.int32Value.getValue(wave, param);
		break;
	case 7:
		return _game_design.Enemy_design.SheetBattle_8.int32Value.getValue(wave, param);
		break;
	case 8:
		return _game_design.Enemy_design.SheetBattle_9.int32Value.getValue(wave, param);
		break;
	case 9:
		return _game_design.Enemy_design.SheetBattle_10.int32Value.getValue(wave, param);
		break;
	case 10:
		return _game_design.Enemy_design.SheetBattle_11.int32Value.getValue(wave, param);
		break;
	case 11:
		return _game_design.Enemy_design.SheetBattle_12.int32Value.getValue(wave, param);
		break;
	case 12:
		return _game_design.Enemy_design.SheetBattle_13.int32Value.getValue(wave, param);
		break;
	case 13:
		return _game_design.Enemy_design.SheetBattle_14.int32Value.getValue(wave, param);
		break;
	case 14:
		return _game_design.Enemy_design.SheetBattle_15.int32Value.getValue(wave, param);
		break;
	case 15:
		return _game_design.Enemy_design.SheetBattle_16.int32Value.getValue(wave, param);
		break;
	case 16:
		return _game_design.Enemy_design.SheetBattle_17.int32Value.getValue(wave, param);
		break;
	case 17:
		return _game_design.Enemy_design.SheetBattle_18.int32Value.getValue(wave, param);
		break;
	case 18:
		return _game_design.Enemy_design.SheetBattle_19.int32Value.getValue(wave, param);
		break;
	case 19:
		return _game_design.Enemy_design.SheetBattle_20.int32Value.getValue(wave, param);
		break;
	case 20:
		return _game_design.Enemy_design.SheetBattle_21.int32Value.getValue(wave, param);
		break;
	case 21:
		return _game_design.Enemy_design.SheetBattle_22.int32Value.getValue(wave, param);
		break;
	case 22:
		return _game_design.Enemy_design.SheetBattle_23.int32Value.getValue(wave, param);
		break;
	case 23:
		return _game_design.Enemy_design.SheetBattle_24.int32Value.getValue(wave, param);
		break;
	case 24:
		return _game_design.Enemy_design.SheetBattle_25.int32Value.getValue(wave, param);
		break;
	case 25:
		return _game_design.Enemy_design.SheetBattle_26.int32Value.getValue(wave, param);
		break;
	case 26:
		return _game_design.Enemy_design.SheetBattle_27.int32Value.getValue(wave, param);
		break;
	case 27:
		return _game_design.Enemy_design.SheetBattle_28.int32Value.getValue(wave, param);
		break;
	case 28:
		return _game_design.Enemy_design.SheetBattle_29.int32Value.getValue(wave, param);
		break;
	case 29:
		return _game_design.Enemy_design.SheetBattle_30.int32Value.getValue(wave, param);
		break;
	case 30:
		return _game_design.Enemy_design.SheetBattle_31.int32Value.getValue(wave, param);
		break;
	case 31:
		return _game_design.Enemy_design.SheetBattle_32.int32Value.getValue(wave, param);
		break;
	case 32:
		return _game_design.Enemy_design.SheetBattle_33.int32Value.getValue(wave, param);
		break;
	case 33:
		return _game_design.Enemy_design.SheetBattle_34.int32Value.getValue(wave, param);
		break;
	case 34:
		return _game_design.Enemy_design.SheetBattle_35.int32Value.getValue(wave, param);
		break;
	case 35:
		return _game_design.Enemy_design.SheetBattle_36.int32Value.getValue(wave, param);
		break;
	case 36:
		return _game_design.Enemy_design.SheetBattle_37.int32Value.getValue(wave, param);
		break;
	case 37:
		return _game_design.Enemy_design.SheetBattle_38.int32Value.getValue(wave, param);
		break;
	case 38:
		return _game_design.Enemy_design.SheetBattle_39.int32Value.getValue(wave, param);
		break;
	case 39:
		return _game_design.Enemy_design.SheetBattle_40.int32Value.getValue(wave, param);
		break;
	case 40:
		return _game_design.Enemy_design.SheetBattle_41.int32Value.getValue(wave, param);
		break;
	case 41:
		return _game_design.Enemy_design.SheetBattle_42.int32Value.getValue(wave, param);
		break;
	case 42:
		return _game_design.Enemy_design.SheetBattle_43.int32Value.getValue(wave, param);
		break;
	case 43:
		return _game_design.Enemy_design.SheetBattle_44.int32Value.getValue(wave, param);
		break;
	case 44:
		return _game_design.Enemy_design.SheetBattle_45.int32Value.getValue(wave, param);
		break;
	case 45:
		return _game_design.Enemy_design.SheetBattle_46.int32Value.getValue(wave, param);
		break;
	case 46:
		return _game_design.Enemy_design.SheetBattle_47.int32Value.getValue(wave, param);
		break;
	case 47:
		return _game_design.Enemy_design.SheetBattle_48.int32Value.getValue(wave, param);
		break;
	case 48:
		return _game_design.Enemy_design.SheetBattle_49.int32Value.getValue(wave, param);
		break;
	case 49:
		return _game_design.Enemy_design.SheetBattle_50.int32Value.getValue(wave, param);
		break;
	case 50:
		return _game_design.Enemy_design.SheetBattle_51.int32Value.getValue(wave, param);
		break;
	case 51:
		return _game_design.Enemy_design.SheetBattle_52.int32Value.getValue(wave, param);
		break;
	case 52:
		return _game_design.Enemy_design.SheetBattle_53.int32Value.getValue(wave, param);
		break;
	case 53:
		return _game_design.Enemy_design.SheetBattle_54.int32Value.getValue(wave, param);
		break;
	case 54:
		return _game_design.Enemy_design.SheetBattle_55.int32Value.getValue(wave, param);
		break;
	case 55:
		return _game_design.Enemy_design.SheetBattle_56.int32Value.getValue(wave, param);
		break;
	case 56:
		return _game_design.Enemy_design.SheetBattle_57.int32Value.getValue(wave, param);
		break;
	case 57:
		return _game_design.Enemy_design.SheetBattle_58.int32Value.getValue(wave, param);
		break;
	case 58:
		return _game_design.Enemy_design.SheetBattle_59.int32Value.getValue(wave, param);
		break;
	case 59:
		return _game_design.Enemy_design.SheetBattle_60.int32Value.getValue(wave, param);
		break;
	case 60:
		return _game_design.Enemy_design.SheetBattle_61.int32Value.getValue(wave, param);
		break;
	case 61:
		return _game_design.Enemy_design.SheetBattle_62.int32Value.getValue(wave, param);
		break;
	case 62:
		return _game_design.Enemy_design.SheetBattle_63.int32Value.getValue(wave, param);
		break;
	case 63:
		return _game_design.Enemy_design.SheetBattle_64.int32Value.getValue(wave, param);
		break;
	case 64:
		return _game_design.Enemy_design.SheetBattle_65.int32Value.getValue(wave, param);
		break;
	case 65:
		return _game_design.Enemy_design.SheetBattle_66.int32Value.getValue(wave, param);
		break;
	case 66:
		return _game_design.Enemy_design.SheetBattle_67.int32Value.getValue(wave, param);
		break;
	case 67:
		return _game_design.Enemy_design.SheetBattle_68.int32Value.getValue(wave, param);
		break;
	case 68:
		return _game_design.Enemy_design.SheetBattle_69.int32Value.getValue(wave, param);
		break;
	case 69:
		return _game_design.Enemy_design.SheetBattle_70.int32Value.getValue(wave, param);
		break;
	case 70:
		return _game_design.Enemy_design.SheetBattle_71.int32Value.getValue(wave, param);
		break;
	case 71:
		return _game_design.Enemy_design.SheetBattle_72.int32Value.getValue(wave, param);
		break;
	case 72:
		return _game_design.Enemy_design.SheetBattle_73.int32Value.getValue(wave, param);
		break;
	case 73:
		return _game_design.Enemy_design.SheetBattle_74.int32Value.getValue(wave, param);
		break;
	case 74:
		return _game_design.Enemy_design.SheetBattle_75.int32Value.getValue(wave, param);
		break;
	case 75:
		return _game_design.Enemy_design.SheetBattle_76.int32Value.getValue(wave, param);
		break;
	case 76:
		return _game_design.Enemy_design.SheetBattle_77.int32Value.getValue(wave, param);
		break;
	case 77:
		return _game_design.Enemy_design.SheetBattle_78.int32Value.getValue(wave, param);
		break;
	case 78:
		return _game_design.Enemy_design.SheetBattle_79.int32Value.getValue(wave, param);
		break;
	case 79:
		return _game_design.Enemy_design.SheetBattle_80.int32Value.getValue(wave, param);
		break;
	case 80:
		return _game_design.Enemy_design.SheetBattle_81.int32Value.getValue(wave, param);
		break;
	case 81:
		return _game_design.Enemy_design.SheetBattle_82.int32Value.getValue(wave, param);
		break;
	case 82:
		return _game_design.Enemy_design.SheetBattle_83.int32Value.getValue(wave, param);
		break;
	case 83:
		return _game_design.Enemy_design.SheetBattle_84.int32Value.getValue(wave, param);
		break;
	case 84:
		return _game_design.Enemy_design.SheetBattle_85.int32Value.getValue(wave, param);
		break;
	case 85:
		return _game_design.Enemy_design.SheetBattle_86.int32Value.getValue(wave, param);
		break;
	case 86:
		return _game_design.Enemy_design.SheetBattle_87.int32Value.getValue(wave, param);
		break;
	case 87:
		return _game_design.Enemy_design.SheetBattle_88.int32Value.getValue(wave, param);
		break;
	case 88:
		return _game_design.Enemy_design.SheetBattle_89.int32Value.getValue(wave, param);
		break;
	case 89:
		return _game_design.Enemy_design.SheetBattle_90.int32Value.getValue(wave, param);
		break;
	case 90:
		return _game_design.Enemy_design.SheetBattle_91.int32Value.getValue(wave, param);
		break;
	case 91:
		return _game_design.Enemy_design.SheetBattle_92.int32Value.getValue(wave, param);
		break;
	case 92:
		return _game_design.Enemy_design.SheetBattle_93.int32Value.getValue(wave, param);
		break;
	case 93:
		return _game_design.Enemy_design.SheetBattle_94.int32Value.getValue(wave, param);
		break;
	case 94:
		return _game_design.Enemy_design.SheetBattle_95.int32Value.getValue(wave, param);
		break;
	case 95:
		return _game_design.Enemy_design.SheetBattle_96.int32Value.getValue(wave, param);
		break;
	case 96:
		return _game_design.Enemy_design.SheetBattle_97.int32Value.getValue(wave, param);
		break;
	case 97:
		return _game_design.Enemy_design.SheetBattle_98.int32Value.getValue(wave, param);
		break;
	case 98:
		return _game_design.Enemy_design.SheetBattle_99.int32Value.getValue(wave, param);
		break;
	case 99:
		return _game_design.Enemy_design.SheetBattle_100.int32Value.getValue(wave, param);
		break;
	case 100:
		return _game_design.Enemy_design.SheetBattle_101.int32Value.getValue(wave, param);
		break;
	case 101:
		return _game_design.Enemy_design.SheetBattle_102.int32Value.getValue(wave, param);
		break;
	case 102:
		return _game_design.Enemy_design.SheetBattle_103.int32Value.getValue(wave, param);
		break;
	case 103:
		return _game_design.Enemy_design.SheetBattle_104.int32Value.getValue(wave, param);
		break;
	case 104:
		return _game_design.Enemy_design.SheetBattle_105.int32Value.getValue(wave, param);
		break;
	case 105:
		return _game_design.Enemy_design.SheetBattle_106.int32Value.getValue(wave, param);
		break;
	case 106:
		return _game_design.Enemy_design.SheetBattle_107.int32Value.getValue(wave, param);
		break;
	case 107:
		return _game_design.Enemy_design.SheetBattle_108.int32Value.getValue(wave, param);
		break;
	case 108:
		return _game_design.Enemy_design.SheetBattle_109.int32Value.getValue(wave, param);
		break;
	case 109:
		return _game_design.Enemy_design.SheetBattle_110.int32Value.getValue(wave, param);
		break;
	case 110:
		return _game_design.Enemy_design.SheetBattle_111.int32Value.getValue(wave, param);
		break;
	case 111:
		return _game_design.Enemy_design.SheetBattle_112.int32Value.getValue(wave, param);
		break;
	case 112:
		return _game_design.Enemy_design.SheetBattle_113.int32Value.getValue(wave, param);
		break;
	case 113:
		return _game_design.Enemy_design.SheetBattle_114.int32Value.getValue(wave, param);
		break;
	case 114:
		return _game_design.Enemy_design.SheetBattle_115.int32Value.getValue(wave, param);
		break;
	case 115:
		return _game_design.Enemy_design.SheetBattle_116.int32Value.getValue(wave, param);
		break;
	case 116:
		return _game_design.Enemy_design.SheetBattle_117.int32Value.getValue(wave, param);
		break;
	case 117:
		return _game_design.Enemy_design.SheetBattle_118.int32Value.getValue(wave, param);
		break;
	case 118:
		return _game_design.Enemy_design.SheetBattle_119.int32Value.getValue(wave, param);
		break;
	case 119:
		return _game_design.Enemy_design.SheetBattle_120.int32Value.getValue(wave, param);
		break;
	case 120:
		return _game_design.Enemy_design.SheetBattle_121.int32Value.getValue(wave, param);
		break;
	case 121:
		return _game_design.Enemy_design.SheetBattle_122.int32Value.getValue(wave, param);
		break;
	case 122:
		return _game_design.Enemy_design.SheetBattle_123.int32Value.getValue(wave, param);
		break;
	case 123:
		return _game_design.Enemy_design.SheetBattle_124.int32Value.getValue(wave, param);
		break;
	case 124:
		return _game_design.Enemy_design.SheetBattle_125.int32Value.getValue(wave, param);
		break;
	case 125:
		return _game_design.Enemy_design.SheetBattle_126.int32Value.getValue(wave, param);
		break;
	case 126:
		return _game_design.Enemy_design.SheetBattle_127.int32Value.getValue(wave, param);
		break;
	case 127:
		return _game_design.Enemy_design.SheetBattle_128.int32Value.getValue(wave, param);
		break;
	case 128:
		return _game_design.Enemy_design.SheetBattle_129.int32Value.getValue(wave, param);
		break;
	case 129:
		return _game_design.Enemy_design.SheetBattle_130.int32Value.getValue(wave, param);
		break;
	case 130:
		return _game_design.Enemy_design.SheetBattle_131.int32Value.getValue(wave, param);
		break;
	case 131:
		return _game_design.Enemy_design.SheetBattle_132.int32Value.getValue(wave, param);
		break;
	case 132:
		return _game_design.Enemy_design.SheetBattle_133.int32Value.getValue(wave, param);
		break;
	case 133:
		return _game_design.Enemy_design.SheetBattle_134.int32Value.getValue(wave, param);
		break;
	case 134:
		return _game_design.Enemy_design.SheetBattle_135.int32Value.getValue(wave, param);
		break;
	case 135:
		return _game_design.Enemy_design.SheetBattle_136.int32Value.getValue(wave, param);
		break;
	case 136:
		return _game_design.Enemy_design.SheetBattle_137.int32Value.getValue(wave, param);
		break;
	case 137:
		return _game_design.Enemy_design.SheetBattle_138.int32Value.getValue(wave, param);
		break;
	case 138:
		return _game_design.Enemy_design.SheetBattle_139.int32Value.getValue(wave, param);
		break;
	case 139:
		return _game_design.Enemy_design.SheetBattle_140.int32Value.getValue(wave, param);
		break;
	case 140:
		return _game_design.Enemy_design.SheetBattle_141.int32Value.getValue(wave, param);
		break;
	case 141:
		return _game_design.Enemy_design.SheetBattle_142.int32Value.getValue(wave, param);
		break;
	case 142:
		return _game_design.Enemy_design.SheetBattle_143.int32Value.getValue(wave, param);
		break;
	case 143:
		return _game_design.Enemy_design.SheetBattle_144.int32Value.getValue(wave, param);
		break;
	case 144:
		return _game_design.Enemy_design.SheetBattle_145.int32Value.getValue(wave, param);
		break;
	case 145:
		return _game_design.Enemy_design.SheetBattle_146.int32Value.getValue(wave, param);
		break;
	case 146:
		return _game_design.Enemy_design.SheetBattle_147.int32Value.getValue(wave, param);
		break;
	case 147:
		return _game_design.Enemy_design.SheetBattle_148.int32Value.getValue(wave, param);
		break;
	case 148:
		return _game_design.Enemy_design.SheetBattle_149.int32Value.getValue(wave, param);
		break;
	case 149:
		return _game_design.Enemy_design.SheetBattle_150.int32Value.getValue(wave, param);
		break;
	case 150:
		return _game_design.Enemy_design.SheetBattle_151.int32Value.getValue(wave, param);
		break;
	case 151:
		return _game_design.Enemy_design.SheetBattle_152.int32Value.getValue(wave, param);
		break;
	case 152:
		return _game_design.Enemy_design.SheetBattle_153.int32Value.getValue(wave, param);
		break;
	case 153:
		return _game_design.Enemy_design.SheetBattle_154.int32Value.getValue(wave, param);
		break;
	case 154:
		return _game_design.Enemy_design.SheetBattle_155.int32Value.getValue(wave, param);
		break;
	case 155:
		return _game_design.Enemy_design.SheetBattle_156.int32Value.getValue(wave, param);
		break;
	case 156:
		return _game_design.Enemy_design.SheetBattle_157.int32Value.getValue(wave, param);
		break;
	case 157:
		return _game_design.Enemy_design.SheetBattle_158.int32Value.getValue(wave, param);
		break;
	case 158:
		return _game_design.Enemy_design.SheetBattle_159.int32Value.getValue(wave, param);
		break;
	case 159:
		return _game_design.Enemy_design.SheetBattle_160.int32Value.getValue(wave, param);
		break;
	case 160:
		return _game_design.Enemy_design.SheetBattle_161.int32Value.getValue(wave, param);
		break;
	case 161:
		return _game_design.Enemy_design.SheetBattle_162.int32Value.getValue(wave, param);
		break;
	case 162:
		return _game_design.Enemy_design.SheetBattle_163.int32Value.getValue(wave, param);
		break;
	case 163:
		return _game_design.Enemy_design.SheetBattle_164.int32Value.getValue(wave, param);
		break;
	case 164:
		return _game_design.Enemy_design.SheetBattle_165.int32Value.getValue(wave, param);
		break;
	case 165:
		return _game_design.Enemy_design.SheetBattle_166.int32Value.getValue(wave, param);
		break;
	case 166:
		return _game_design.Enemy_design.SheetBattle_167.int32Value.getValue(wave, param);
		break;
	case 167:
		return _game_design.Enemy_design.SheetBattle_168.int32Value.getValue(wave, param);
		break;
	case 168:
		return _game_design.Enemy_design.SheetBattle_169.int32Value.getValue(wave, param);
		break;
	case 169:
		return _game_design.Enemy_design.SheetBattle_170.int32Value.getValue(wave, param);
		break;
	case 170:
		return _game_design.Enemy_design.SheetBattle_171.int32Value.getValue(wave, param);
		break;
	case 171:
		return _game_design.Enemy_design.SheetBattle_172.int32Value.getValue(wave, param);
		break;
	case 172:
		return _game_design.Enemy_design.SheetBattle_173.int32Value.getValue(wave, param);
		break;
	case 173:
		return _game_design.Enemy_design.SheetBattle_174.int32Value.getValue(wave, param);
		break;
	case 174:
		return _game_design.Enemy_design.SheetBattle_175.int32Value.getValue(wave, param);
		break;
	case 175:
		return _game_design.Enemy_design.SheetBattle_176.int32Value.getValue(wave, param);
		break;
	case 176:
		return _game_design.Enemy_design.SheetBattle_177.int32Value.getValue(wave, param);
		break;
	case 177:
		return _game_design.Enemy_design.SheetBattle_178.int32Value.getValue(wave, param);
		break;
	case 178:
		return _game_design.Enemy_design.SheetBattle_179.int32Value.getValue(wave, param);
		break;
	case 179:
		return _game_design.Enemy_design.SheetBattle_180.int32Value.getValue(wave, param);
		break;
	case 180:
		return _game_design.Enemy_design.SheetBattle_181.int32Value.getValue(wave, param);
		break;
	case 181:
		return _game_design.Enemy_design.SheetBattle_182.int32Value.getValue(wave, param);
		break;
	case 182:
		return _game_design.Enemy_design.SheetBattle_183.int32Value.getValue(wave, param);
		break;
	case 183:
		return _game_design.Enemy_design.SheetBattle_184.int32Value.getValue(wave, param);
		break;
	case 184:
		return _game_design.Enemy_design.SheetBattle_185.int32Value.getValue(wave, param);
		break;
	case 185:
		return _game_design.Enemy_design.SheetBattle_186.int32Value.getValue(wave, param);
		break;
	case 186:
		return _game_design.Enemy_design.SheetBattle_187.int32Value.getValue(wave, param);
		break;
	case 187:
		return _game_design.Enemy_design.SheetBattle_188.int32Value.getValue(wave, param);
		break;
	case 188:
		return _game_design.Enemy_design.SheetBattle_189.int32Value.getValue(wave, param);
		break;
	case 189:
		return _game_design.Enemy_design.SheetBattle_190.int32Value.getValue(wave, param);
		break;
	case 190:
		return _game_design.Enemy_design.SheetBattle_191.int32Value.getValue(wave, param);
		break;
	case 191:
		return _game_design.Enemy_design.SheetBattle_192.int32Value.getValue(wave, param);
		break;
	case 192:
		return _game_design.Enemy_design.SheetBattle_193.int32Value.getValue(wave, param);
		break;
	case 193:
		return _game_design.Enemy_design.SheetBattle_194.int32Value.getValue(wave, param);
		break;
	case 194:
		return _game_design.Enemy_design.SheetBattle_195.int32Value.getValue(wave, param);
		break;
	case 195:
		return _game_design.Enemy_design.SheetBattle_196.int32Value.getValue(wave, param);
		break;
	case 196:
		return _game_design.Enemy_design.SheetBattle_197.int32Value.getValue(wave, param);
		break;
	case 197:
		return _game_design.Enemy_design.SheetBattle_198.int32Value.getValue(wave, param);
		break;
	case 198:
		return _game_design.Enemy_design.SheetBattle_199.int32Value.getValue(wave, param);
		break;
	case 199:
		return _game_design.Enemy_design.SheetBattle_200.int32Value.getValue(wave, param);
		break;
	case 200:
		return _game_design.Enemy_design.SheetBattle_201.int32Value.getValue(wave, param);
		break;
	case 201:
		return _game_design.Enemy_design.SheetBattle_202.int32Value.getValue(wave, param);
		break;
	case 202:
		return _game_design.Enemy_design.SheetBattle_203.int32Value.getValue(wave, param);
		break;
	case 203:
		return _game_design.Enemy_design.SheetBattle_204.int32Value.getValue(wave, param);
		break;
	case 204:
		return _game_design.Enemy_design.SheetBattle_205.int32Value.getValue(wave, param);
		break;
	case 205:
		return _game_design.Enemy_design.SheetBattle_206.int32Value.getValue(wave, param);
		break;
	case 206:
		return _game_design.Enemy_design.SheetBattle_207.int32Value.getValue(wave, param);
		break;
	case 207:
		return _game_design.Enemy_design.SheetBattle_208.int32Value.getValue(wave, param);
		break;
	case 208:
		return _game_design.Enemy_design.SheetBattle_209.int32Value.getValue(wave, param);
		break;
	case 209:
		return _game_design.Enemy_design.SheetBattle_210.int32Value.getValue(wave, param);
		break;
	case 210:
		return _game_design.Enemy_design.SheetBattle_211.int32Value.getValue(wave, param);
		break;
	case 211:
		return _game_design.Enemy_design.SheetBattle_212.int32Value.getValue(wave, param);
		break;
	case 212:
		return _game_design.Enemy_design.SheetBattle_213.int32Value.getValue(wave, param);
		break;
	case 213:
		return _game_design.Enemy_design.SheetBattle_214.int32Value.getValue(wave, param);
		break;
	case 214:
		return _game_design.Enemy_design.SheetBattle_215.int32Value.getValue(wave, param);
		break;
	case 215:
		return _game_design.Enemy_design.SheetBattle_216.int32Value.getValue(wave, param);
		break;
	case 216:
		return _game_design.Enemy_design.SheetBattle_217.int32Value.getValue(wave, param);
		break;
	case 217:
		return _game_design.Enemy_design.SheetBattle_218.int32Value.getValue(wave, param);
		break;
	case 218:
		return _game_design.Enemy_design.SheetBattle_219.int32Value.getValue(wave, param);
		break;
	case 219:
		return _game_design.Enemy_design.SheetBattle_220.int32Value.getValue(wave, param);
		break;
	case 220:
		return _game_design.Enemy_design.SheetBattle_221.int32Value.getValue(wave, param);
		break;
	case 221:
		return _game_design.Enemy_design.SheetBattle_222.int32Value.getValue(wave, param);
		break;
	case 222:
		return _game_design.Enemy_design.SheetBattle_223.int32Value.getValue(wave, param);
		break;
	case 223:
		return _game_design.Enemy_design.SheetBattle_224.int32Value.getValue(wave, param);
		break;
	case 224:
		return _game_design.Enemy_design.SheetBattle_225.int32Value.getValue(wave, param);
		break;
	case 225:
		return _game_design.Enemy_design.SheetBattle_226.int32Value.getValue(wave, param);
		break;
	case 226:
		return _game_design.Enemy_design.SheetBattle_227.int32Value.getValue(wave, param);
		break;
	case 227:
		return _game_design.Enemy_design.SheetBattle_228.int32Value.getValue(wave, param);
		break;
	case 228:
		return _game_design.Enemy_design.SheetBattle_229.int32Value.getValue(wave, param);
		break;
	case 229:
		return _game_design.Enemy_design.SheetBattle_230.int32Value.getValue(wave, param);
		break;
	case 230:
		return _game_design.Enemy_design.SheetBattle_231.int32Value.getValue(wave, param);
		break;
	case 231:
		return _game_design.Enemy_design.SheetBattle_232.int32Value.getValue(wave, param);
		break;
	case 232:
		return _game_design.Enemy_design.SheetBattle_233.int32Value.getValue(wave, param);
		break;
	case 233:
		return _game_design.Enemy_design.SheetBattle_234.int32Value.getValue(wave, param);
		break;
	case 234:
		return _game_design.Enemy_design.SheetBattle_235.int32Value.getValue(wave, param);
		break;
	case 235:
		return _game_design.Enemy_design.SheetBattle_236.int32Value.getValue(wave, param);
		break;
	case 236:
		return _game_design.Enemy_design.SheetBattle_237.int32Value.getValue(wave, param);
		break;
	case 237:
		return _game_design.Enemy_design.SheetBattle_238.int32Value.getValue(wave, param);
		break;
	case 238:
		return _game_design.Enemy_design.SheetBattle_239.int32Value.getValue(wave, param);
		break;
	case 239:
		return _game_design.Enemy_design.SheetBattle_240.int32Value.getValue(wave, param);
		break;
	case 240:
		return _game_design.Enemy_design.SheetBattle_241.int32Value.getValue(wave, param);
		break;
	case 241:
		return _game_design.Enemy_design.SheetBattle_242.int32Value.getValue(wave, param);
		break;
	case 242:
		return _game_design.Enemy_design.SheetBattle_243.int32Value.getValue(wave, param);
		break;
	case 243:
		return _game_design.Enemy_design.SheetBattle_244.int32Value.getValue(wave, param);
		break;
	case 244:
		return _game_design.Enemy_design.SheetBattle_245.int32Value.getValue(wave, param);
		break;
	case 245:
		return _game_design.Enemy_design.SheetBattle_246.int32Value.getValue(wave, param);
		break;
	case 246:
		return _game_design.Enemy_design.SheetBattle_247.int32Value.getValue(wave, param);
		break;
	case 247:
		return _game_design.Enemy_design.SheetBattle_248.int32Value.getValue(wave, param);
		break;
	case 248:
		return _game_design.Enemy_design.SheetBattle_249.int32Value.getValue(wave, param);
		break;
	case 249:
		return _game_design.Enemy_design.SheetBattle_250.int32Value.getValue(wave, param);
		break;
	case 250:
		return _game_design.Enemy_design.SheetBattle_251.int32Value.getValue(wave, param);
		break;
	case 251:
		return _game_design.Enemy_design.SheetBattle_252.int32Value.getValue(wave, param);
		break;
	case 252:
		return _game_design.Enemy_design.SheetBattle_253.int32Value.getValue(wave, param);
		break;
	case 253:
		return _game_design.Enemy_design.SheetBattle_254.int32Value.getValue(wave, param);
		break;
	case 254:
		return _game_design.Enemy_design.SheetBattle_255.int32Value.getValue(wave, param);
		break;
	case 255:
		return _game_design.Enemy_design.SheetBattle_256.int32Value.getValue(wave, param);
		break;
	case 256:
		return _game_design.Enemy_design.SheetBattle_257.int32Value.getValue(wave, param);
		break;
	case 257:
		return _game_design.Enemy_design.SheetBattle_258.int32Value.getValue(wave, param);
		break;
	case 258:
		return _game_design.Enemy_design.SheetBattle_259.int32Value.getValue(wave, param);
		break;
	case 259:
		return _game_design.Enemy_design.SheetBattle_260.int32Value.getValue(wave, param);
		break;
	case 260:
		return _game_design.Enemy_design.SheetBattle_261.int32Value.getValue(wave, param);
		break;
	case 261:
		return _game_design.Enemy_design.SheetBattle_262.int32Value.getValue(wave, param);
		break;
	case 262:
		return _game_design.Enemy_design.SheetBattle_263.int32Value.getValue(wave, param);
		break;
	case 263:
		return _game_design.Enemy_design.SheetBattle_264.int32Value.getValue(wave, param);
		break;
	case 264:
		return _game_design.Enemy_design.SheetBattle_265.int32Value.getValue(wave, param);
		break;
	case 265:
		return _game_design.Enemy_design.SheetBattle_266.int32Value.getValue(wave, param);
		break;
	case 266:
		return _game_design.Enemy_design.SheetBattle_267.int32Value.getValue(wave, param);
		break;
	case 267:
		return _game_design.Enemy_design.SheetBattle_268.int32Value.getValue(wave, param);
		break;
	case 268:
		return _game_design.Enemy_design.SheetBattle_269.int32Value.getValue(wave, param);
		break;
	case 269:
		return _game_design.Enemy_design.SheetBattle_270.int32Value.getValue(wave, param);
		break;
	case 270:
		return _game_design.Enemy_design.SheetBattle_271.int32Value.getValue(wave, param);
		break;
	case 271:
		return _game_design.Enemy_design.SheetBattle_272.int32Value.getValue(wave, param);
		break;
	case 272:
		return _game_design.Enemy_design.SheetBattle_273.int32Value.getValue(wave, param);
		break;
	case 273:
		return _game_design.Enemy_design.SheetBattle_274.int32Value.getValue(wave, param);
		break;
	case 274:
		return _game_design.Enemy_design.SheetBattle_275.int32Value.getValue(wave, param);
		break;
	case 275:
		return _game_design.Enemy_design.SheetBattle_276.int32Value.getValue(wave, param);
		break;
	case 276:
		return _game_design.Enemy_design.SheetBattle_277.int32Value.getValue(wave, param);
		break;
	case 277:
		return _game_design.Enemy_design.SheetBattle_278.int32Value.getValue(wave, param);
		break;
	case 278:
		return _game_design.Enemy_design.SheetBattle_279.int32Value.getValue(wave, param);
		break;
	case 279:
		return _game_design.Enemy_design.SheetBattle_280.int32Value.getValue(wave, param);
		break;
	case 280:
		return _game_design.Enemy_design.SheetBattle_281.int32Value.getValue(wave, param);
		break;
	case 281:
		return _game_design.Enemy_design.SheetBattle_282.int32Value.getValue(wave, param);
		break;
	case 282:
		return _game_design.Enemy_design.SheetBattle_283.int32Value.getValue(wave, param);
		break;
	case 283:
		return _game_design.Enemy_design.SheetBattle_284.int32Value.getValue(wave, param);
		break;
	case 284:
		return _game_design.Enemy_design.SheetBattle_285.int32Value.getValue(wave, param);
		break;
	case 285:
		return _game_design.Enemy_design.SheetBattle_286.int32Value.getValue(wave, param);
		break;
	case 286:
		return _game_design.Enemy_design.SheetBattle_287.int32Value.getValue(wave, param);
		break;
	case 287:
		return _game_design.Enemy_design.SheetBattle_288.int32Value.getValue(wave, param);
		break;
	case 288:
		return _game_design.Enemy_design.SheetBattle_289.int32Value.getValue(wave, param);
		break;
	case 289:
		return _game_design.Enemy_design.SheetBattle_290.int32Value.getValue(wave, param);
		break;
	case 290:
		return _game_design.Enemy_design.SheetBattle_291.int32Value.getValue(wave, param);
		break;
	case 291:
		return _game_design.Enemy_design.SheetBattle_292.int32Value.getValue(wave, param);
		break;
	case 292:
		return _game_design.Enemy_design.SheetBattle_293.int32Value.getValue(wave, param);
		break;
	case 293:
		return _game_design.Enemy_design.SheetBattle_294.int32Value.getValue(wave, param);
		break;
	case 294:
		return _game_design.Enemy_design.SheetBattle_295.int32Value.getValue(wave, param);
		break;
	case 295:
		return _game_design.Enemy_design.SheetBattle_296.int32Value.getValue(wave, param);
		break;
	case 296:
		return _game_design.Enemy_design.SheetBattle_297.int32Value.getValue(wave, param);
		break;
	case 297:
		return _game_design.Enemy_design.SheetBattle_298.int32Value.getValue(wave, param);
		break;
	case 298:
		return _game_design.Enemy_design.SheetBattle_299.int32Value.getValue(wave, param);
		break;
	case 299:
		return _game_design.Enemy_design.SheetBattle_300.int32Value.getValue(wave, param);
		break;
	case 300:
		return _game_design.Enemy_design.SheetBattle_301.int32Value.getValue(wave, param);
		break;
	case 301:
		return _game_design.Enemy_design.SheetBattle_302.int32Value.getValue(wave, param);
		break;
	case 302:
		return _game_design.Enemy_design.SheetBattle_303.int32Value.getValue(wave, param);
		break;
	case 303:
		return _game_design.Enemy_design.SheetBattle_304.int32Value.getValue(wave, param);
		break;
	case 304:
		return _game_design.Enemy_design.SheetBattle_305.int32Value.getValue(wave, param);
		break;
	case 305:
		return _game_design.Enemy_design.SheetBattle_306.int32Value.getValue(wave, param);
		break;
	case 306:
		return _game_design.Enemy_design.SheetBattle_307.int32Value.getValue(wave, param);
		break;
	case 307:
		return _game_design.Enemy_design.SheetBattle_308.int32Value.getValue(wave, param);
		break;
	case 308:
		return _game_design.Enemy_design.SheetBattle_309.int32Value.getValue(wave, param);
		break;
	case 309:
		return _game_design.Enemy_design.SheetBattle_310.int32Value.getValue(wave, param);
		break;
	case 310:
		return _game_design.Enemy_design.SheetBattle_311.int32Value.getValue(wave, param);
		break;
	case 311:
		return _game_design.Enemy_design.SheetBattle_312.int32Value.getValue(wave, param);
		break;
	case 312:
		return _game_design.Enemy_design.SheetBattle_313.int32Value.getValue(wave, param);
		break;
	case 313:
		return _game_design.Enemy_design.SheetBattle_314.int32Value.getValue(wave, param);
		break;
	case 314:
		return _game_design.Enemy_design.SheetBattle_315.int32Value.getValue(wave, param);
		break;
	case 315:
		return _game_design.Enemy_design.SheetBattle_316.int32Value.getValue(wave, param);
		break;
	case 316:
		return _game_design.Enemy_design.SheetBattle_317.int32Value.getValue(wave, param);
		break;
	case 317:
		return _game_design.Enemy_design.SheetBattle_318.int32Value.getValue(wave, param);
		break;
	case 318:
		return _game_design.Enemy_design.SheetBattle_319.int32Value.getValue(wave, param);
		break;
	case 319:
		return _game_design.Enemy_design.SheetBattle_320.int32Value.getValue(wave, param);
		break;
	case 320:
		return _game_design.Enemy_design.SheetBattle_321.int32Value.getValue(wave, param);
		break;
	case 321:
		return _game_design.Enemy_design.SheetBattle_322.int32Value.getValue(wave, param);
		break;
	case 322:
		return _game_design.Enemy_design.SheetBattle_323.int32Value.getValue(wave, param);
		break;
	case 323:
		return _game_design.Enemy_design.SheetBattle_324.int32Value.getValue(wave, param);
		break;
	case 324:
		return _game_design.Enemy_design.SheetBattle_325.int32Value.getValue(wave, param);
		break;
	case 325:
		return _game_design.Enemy_design.SheetBattle_326.int32Value.getValue(wave, param);
		break;
	case 326:
		return _game_design.Enemy_design.SheetBattle_327.int32Value.getValue(wave, param);
		break;
	case 327:
		return _game_design.Enemy_design.SheetBattle_328.int32Value.getValue(wave, param);
		break;
	case 328:
		return _game_design.Enemy_design.SheetBattle_329.int32Value.getValue(wave, param);
		break;
	case 329:
		return _game_design.Enemy_design.SheetBattle_330.int32Value.getValue(wave, param);
		break;
	case 330:
		return _game_design.Enemy_design.SheetBattle_331.int32Value.getValue(wave, param);
		break;
	case 331:
		return _game_design.Enemy_design.SheetBattle_332.int32Value.getValue(wave, param);
		break;
	case 332:
		return _game_design.Enemy_design.SheetBattle_333.int32Value.getValue(wave, param);
		break;
	case 333:
		return _game_design.Enemy_design.SheetBattle_334.int32Value.getValue(wave, param);
		break;
	case 334:
		return _game_design.Enemy_design.SheetBattle_335.int32Value.getValue(wave, param);
		break;
	case 335:
		return _game_design.Enemy_design.SheetBattle_336.int32Value.getValue(wave, param);
		break;
	case 336:
		return _game_design.Enemy_design.SheetBattle_337.int32Value.getValue(wave, param);
		break;
	case 337:
		return _game_design.Enemy_design.SheetBattle_338.int32Value.getValue(wave, param);
		break;
	case 338:
		return _game_design.Enemy_design.SheetBattle_339.int32Value.getValue(wave, param);
		break;
	case 339:
		return _game_design.Enemy_design.SheetBattle_340.int32Value.getValue(wave, param);
		break;
	case 340:
		return _game_design.Enemy_design.SheetBattle_341.int32Value.getValue(wave, param);
		break;
	case 341:
		return _game_design.Enemy_design.SheetBattle_342.int32Value.getValue(wave, param);
		break;
	case 342:
		return _game_design.Enemy_design.SheetBattle_343.int32Value.getValue(wave, param);
		break;
	case 343:
		return _game_design.Enemy_design.SheetBattle_344.int32Value.getValue(wave, param);
		break;
	case 344:
		return _game_design.Enemy_design.SheetBattle_345.int32Value.getValue(wave, param);
		break;
	case 345:
		return _game_design.Enemy_design.SheetBattle_346.int32Value.getValue(wave, param);
		break;
	case 346:
		return _game_design.Enemy_design.SheetBattle_347.int32Value.getValue(wave, param);
		break;
	case 347:
		return _game_design.Enemy_design.SheetBattle_348.int32Value.getValue(wave, param);
		break;
	case 348:
		return _game_design.Enemy_design.SheetBattle_349.int32Value.getValue(wave, param);
		break;
	case 349:
		return _game_design.Enemy_design.SheetBattle_350.int32Value.getValue(wave, param);
		break;
	case 350:
		return _game_design.Enemy_design.SheetBattle_351.int32Value.getValue(wave, param);
		break;
	case 351:
		return _game_design.Enemy_design.SheetBattle_352.int32Value.getValue(wave, param);
		break;
	case 352:
		return _game_design.Enemy_design.SheetBattle_353.int32Value.getValue(wave, param);
		break;
	case 353:
		return _game_design.Enemy_design.SheetBattle_354.int32Value.getValue(wave, param);
		break;
	case 354:
		return _game_design.Enemy_design.SheetBattle_355.int32Value.getValue(wave, param);
		break;
	case 355:
		return _game_design.Enemy_design.SheetBattle_356.int32Value.getValue(wave, param);
		break;
	case 356:
		return _game_design.Enemy_design.SheetBattle_357.int32Value.getValue(wave, param);
		break;
	case 357:
		return _game_design.Enemy_design.SheetBattle_358.int32Value.getValue(wave, param);
		break;
	case 358:
		return _game_design.Enemy_design.SheetBattle_359.int32Value.getValue(wave, param);
		break;
	case 359:
		return _game_design.Enemy_design.SheetBattle_360.int32Value.getValue(wave, param);
		break;
	case 360:
		return _game_design.Enemy_design.SheetBattle_361.int32Value.getValue(wave, param);
		break;
	case 361:
		return _game_design.Enemy_design.SheetBattle_362.int32Value.getValue(wave, param);
		break;
	case 362:
		return _game_design.Enemy_design.SheetBattle_363.int32Value.getValue(wave, param);
		break;
	case 363:
		return _game_design.Enemy_design.SheetBattle_364.int32Value.getValue(wave, param);
		break;
	case 364:
		return _game_design.Enemy_design.SheetBattle_365.int32Value.getValue(wave, param);
		break;
	case 365:
		return _game_design.Enemy_design.SheetBattle_366.int32Value.getValue(wave, param);
		break;
	case 366:
		return _game_design.Enemy_design.SheetBattle_367.int32Value.getValue(wave, param);
		break;
	case 367:
		return _game_design.Enemy_design.SheetBattle_368.int32Value.getValue(wave, param);
		break;
	case 368:
		return _game_design.Enemy_design.SheetBattle_369.int32Value.getValue(wave, param);
		break;
	case 369:
		return _game_design.Enemy_design.SheetBattle_370.int32Value.getValue(wave, param);
		break;
	case 370:
		return _game_design.Enemy_design.SheetBattle_371.int32Value.getValue(wave, param);
		break;
	case 371:
		return _game_design.Enemy_design.SheetBattle_372.int32Value.getValue(wave, param);
		break;
	case 372:
		return _game_design.Enemy_design.SheetBattle_373.int32Value.getValue(wave, param);
		break;
	case 373:
		return _game_design.Enemy_design.SheetBattle_374.int32Value.getValue(wave, param);
		break;
	case 374:
		return _game_design.Enemy_design.SheetBattle_375.int32Value.getValue(wave, param);
		break;
	case 375:
		return _game_design.Enemy_design.SheetBattle_376.int32Value.getValue(wave, param);
		break;
	case 376:
		return _game_design.Enemy_design.SheetBattle_377.int32Value.getValue(wave, param);
		break;
	case 377:
		return _game_design.Enemy_design.SheetBattle_378.int32Value.getValue(wave, param);
		break;
	case 378:
		return _game_design.Enemy_design.SheetBattle_379.int32Value.getValue(wave, param);
		break;
	case 379:
		return _game_design.Enemy_design.SheetBattle_380.int32Value.getValue(wave, param);
		break;
	case 380:
		return _game_design.Enemy_design.SheetBattle_381.int32Value.getValue(wave, param);
		break;
	case 381:
		return _game_design.Enemy_design.SheetBattle_382.int32Value.getValue(wave, param);
		break;
	case 382:
		return _game_design.Enemy_design.SheetBattle_383.int32Value.getValue(wave, param);
		break;
	case 383:
		return _game_design.Enemy_design.SheetBattle_384.int32Value.getValue(wave, param);
		break;
	case 384:
		return _game_design.Enemy_design.SheetBattle_385.int32Value.getValue(wave, param);
		break;
	case 385:
		return _game_design.Enemy_design.SheetBattle_386.int32Value.getValue(wave, param);
		break;
	case 386:
		return _game_design.Enemy_design.SheetBattle_387.int32Value.getValue(wave, param);
		break;
	case 387:
		return _game_design.Enemy_design.SheetBattle_388.int32Value.getValue(wave, param);
		break;
	case 388:
		return _game_design.Enemy_design.SheetBattle_389.int32Value.getValue(wave, param);
		break;
	case 389:
		return _game_design.Enemy_design.SheetBattle_390.int32Value.getValue(wave, param);
		break;
	case 390:
		return _game_design.Enemy_design.SheetBattle_391.int32Value.getValue(wave, param);
		break;
	case 391:
		return _game_design.Enemy_design.SheetBattle_392.int32Value.getValue(wave, param);
		break;
	case 392:
		return _game_design.Enemy_design.SheetBattle_393.int32Value.getValue(wave, param);
		break;
	case 393:
		return _game_design.Enemy_design.SheetBattle_394.int32Value.getValue(wave, param);
		break;
	case 394:
		return _game_design.Enemy_design.SheetBattle_395.int32Value.getValue(wave, param);
		break;
	case 395:
		return _game_design.Enemy_design.SheetBattle_396.int32Value.getValue(wave, param);
		break;
	case 396:
		return _game_design.Enemy_design.SheetBattle_397.int32Value.getValue(wave, param);
		break;
	case 397:
		return _game_design.Enemy_design.SheetBattle_398.int32Value.getValue(wave, param);
		break;
	case 398:
		return _game_design.Enemy_design.SheetBattle_399.int32Value.getValue(wave, param);
		break;
	case 399:
		return _game_design.Enemy_design.SheetBattle_400.int32Value.getValue(wave, param);
		break;
	case 400:
		return _game_design.Enemy_design.SheetBattle_401.int32Value.getValue(wave, param);
		break;
	case 401:
		return _game_design.Enemy_design.SheetBattle_402.int32Value.getValue(wave, param);
		break;
	case 402:
		return _game_design.Enemy_design.SheetBattle_403.int32Value.getValue(wave, param);
		break;
	case 403:
		return _game_design.Enemy_design.SheetBattle_404.int32Value.getValue(wave, param);
		break;
	case 404:
		return _game_design.Enemy_design.SheetBattle_405.int32Value.getValue(wave, param);
		break;
	case 405:
		return _game_design.Enemy_design.SheetBattle_406.int32Value.getValue(wave, param);
		break;
	case 406:
		return _game_design.Enemy_design.SheetBattle_407.int32Value.getValue(wave, param);
		break;
	case 407:
		return _game_design.Enemy_design.SheetBattle_408.int32Value.getValue(wave, param);
		break;
	case 408:
		return _game_design.Enemy_design.SheetBattle_409.int32Value.getValue(wave, param);
		break;
	case 409:
		return _game_design.Enemy_design.SheetBattle_410.int32Value.getValue(wave, param);
		break;
	case 410:
		return _game_design.Enemy_design.SheetBattle_411.int32Value.getValue(wave, param);
		break;
	case 411:
		return _game_design.Enemy_design.SheetBattle_412.int32Value.getValue(wave, param);
		break;
	case 412:
		return _game_design.Enemy_design.SheetBattle_413.int32Value.getValue(wave, param);
		break;
	case 413:
		return _game_design.Enemy_design.SheetBattle_414.int32Value.getValue(wave, param);
		break;
	case 414:
		return _game_design.Enemy_design.SheetBattle_415.int32Value.getValue(wave, param);
		break;
	case 415:
		return _game_design.Enemy_design.SheetBattle_416.int32Value.getValue(wave, param);
		break;
	case 416:
		return _game_design.Enemy_design.SheetBattle_417.int32Value.getValue(wave, param);
		break;
	case 417:
		return _game_design.Enemy_design.SheetBattle_418.int32Value.getValue(wave, param);
		break;
	case 418:
		return _game_design.Enemy_design.SheetBattle_419.int32Value.getValue(wave, param);
		break;
	case 419:
		return _game_design.Enemy_design.SheetBattle_420.int32Value.getValue(wave, param);
		break;
	case 420:
		return _game_design.Enemy_design.SheetBattle_421.int32Value.getValue(wave, param);
		break;
	case 421:
		return _game_design.Enemy_design.SheetBattle_422.int32Value.getValue(wave, param);
		break;
	case 422:
		return _game_design.Enemy_design.SheetBattle_423.int32Value.getValue(wave, param);
		break;
	case 423:
		return _game_design.Enemy_design.SheetBattle_424.int32Value.getValue(wave, param);
		break;
	case 424:
		return _game_design.Enemy_design.SheetBattle_425.int32Value.getValue(wave, param);
		break;
	case 425:
		return _game_design.Enemy_design.SheetBattle_426.int32Value.getValue(wave, param);
		break;
	case 426:
		return _game_design.Enemy_design.SheetBattle_427.int32Value.getValue(wave, param);
		break;
	case 427:
		return _game_design.Enemy_design.SheetBattle_428.int32Value.getValue(wave, param);
		break;
	case 428:
		return _game_design.Enemy_design.SheetBattle_429.int32Value.getValue(wave, param);
		break;
	case 429:
		return _game_design.Enemy_design.SheetBattle_430.int32Value.getValue(wave, param);
		break;
	case 430:
		return _game_design.Enemy_design.SheetBattle_431.int32Value.getValue(wave, param);
		break;
	case 431:
		return _game_design.Enemy_design.SheetBattle_432.int32Value.getValue(wave, param);
		break;
	case 432:
		return _game_design.Enemy_design.SheetBattle_433.int32Value.getValue(wave, param);
		break;
	case 433:
		return _game_design.Enemy_design.SheetBattle_434.int32Value.getValue(wave, param);
		break;
	case 434:
		return _game_design.Enemy_design.SheetBattle_435.int32Value.getValue(wave, param);
		break;
	case 435:
		return _game_design.Enemy_design.SheetBattle_436.int32Value.getValue(wave, param);
		break;
	case 436:
		return _game_design.Enemy_design.SheetBattle_437.int32Value.getValue(wave, param);
		break;
	case 437:
		return _game_design.Enemy_design.SheetBattle_438.int32Value.getValue(wave, param);
		break;
	case 438:
		return _game_design.Enemy_design.SheetBattle_439.int32Value.getValue(wave, param);
		break;
	case 439:
		return _game_design.Enemy_design.SheetBattle_240.int32Value.getValue(wave, param);
		break;
	case 440:
		return _game_design.Enemy_design.SheetBattle_441.int32Value.getValue(wave, param);
		break;
	case 441:
		return _game_design.Enemy_design.SheetBattle_442.int32Value.getValue(wave, param);
		break;
	case 442:
		return _game_design.Enemy_design.SheetBattle_443.int32Value.getValue(wave, param);
		break;
	case 443:
		return _game_design.Enemy_design.SheetBattle_444.int32Value.getValue(wave, param);
		break;
	case 444:
		return _game_design.Enemy_design.SheetBattle_445.int32Value.getValue(wave, param);
		break;
	case 445:
		return _game_design.Enemy_design.SheetBattle_446.int32Value.getValue(wave, param);
		break;
	case 446:
		return _game_design.Enemy_design.SheetBattle_447.int32Value.getValue(wave, param);
		break;
	case 447:
		return _game_design.Enemy_design.SheetBattle_448.int32Value.getValue(wave, param);
		break;
	case 448:
		return _game_design.Enemy_design.SheetBattle_449.int32Value.getValue(wave, param);
		break;
	case 449:
		return _game_design.Enemy_design.SheetBattle_450.int32Value.getValue(wave, param);
		break;
	case 450:
		return _game_design.Enemy_design.SheetBattle_451.int32Value.getValue(wave, param);
		break;
	case 451:
		return _game_design.Enemy_design.SheetBattle_452.int32Value.getValue(wave, param);
		break;
	case 452:
		return _game_design.Enemy_design.SheetBattle_453.int32Value.getValue(wave, param);
		break;
	case 453:
		return _game_design.Enemy_design.SheetBattle_454.int32Value.getValue(wave, param);
		break;
	case 454:
		return _game_design.Enemy_design.SheetBattle_455.int32Value.getValue(wave, param);
		break;
	case 455:
		return _game_design.Enemy_design.SheetBattle_456.int32Value.getValue(wave, param);
		break;
	case 456:
		return _game_design.Enemy_design.SheetBattle_457.int32Value.getValue(wave, param);
		break;
	case 457:
		return _game_design.Enemy_design.SheetBattle_458.int32Value.getValue(wave, param);
		break;
	case 458:
		return _game_design.Enemy_design.SheetBattle_459.int32Value.getValue(wave, param);
		break;
	case 459:
		return _game_design.Enemy_design.SheetBattle_460.int32Value.getValue(wave, param);
		break;
	case 460:
		return _game_design.Enemy_design.SheetBattle_461.int32Value.getValue(wave, param);
		break;
	case 461:
		return _game_design.Enemy_design.SheetBattle_462.int32Value.getValue(wave, param);
		break;
	case 462:
		return _game_design.Enemy_design.SheetBattle_463.int32Value.getValue(wave, param);
		break;
	case 463:
		return _game_design.Enemy_design.SheetBattle_464.int32Value.getValue(wave, param);
		break;
	case 464:
		return _game_design.Enemy_design.SheetBattle_465.int32Value.getValue(wave, param);
		break;
	case 465:
		return _game_design.Enemy_design.SheetBattle_466.int32Value.getValue(wave, param);
		break;
	case 466:
		return _game_design.Enemy_design.SheetBattle_467.int32Value.getValue(wave, param);
		break;
	case 467:
		return _game_design.Enemy_design.SheetBattle_468.int32Value.getValue(wave, param);
		break;
	case 468:
		return _game_design.Enemy_design.SheetBattle_469.int32Value.getValue(wave, param);
		break;
	case 469:
		return _game_design.Enemy_design.SheetBattle_470.int32Value.getValue(wave, param);
		break;
	case 470:
		return _game_design.Enemy_design.SheetBattle_471.int32Value.getValue(wave, param);
		break;
	case 471:
		return _game_design.Enemy_design.SheetBattle_472.int32Value.getValue(wave, param);
		break;
	case 472:
		return _game_design.Enemy_design.SheetBattle_473.int32Value.getValue(wave, param);
		break;
	case 473:
		return _game_design.Enemy_design.SheetBattle_474.int32Value.getValue(wave, param);
		break;
	case 474:
		return _game_design.Enemy_design.SheetBattle_475.int32Value.getValue(wave, param);
		break;
	case 475:
		return _game_design.Enemy_design.SheetBattle_476.int32Value.getValue(wave, param);
		break;
	case 476:
		return _game_design.Enemy_design.SheetBattle_477.int32Value.getValue(wave, param);
		break;
	case 477:
		return _game_design.Enemy_design.SheetBattle_478.int32Value.getValue(wave, param);
		break;
	case 478:
		return _game_design.Enemy_design.SheetBattle_479.int32Value.getValue(wave, param);
		break;
	case 479:
		return _game_design.Enemy_design.SheetBattle_480.int32Value.getValue(wave, param);
		break;
	case 480:
		return _game_design.Enemy_design.SheetBattle_481.int32Value.getValue(wave, param);
		break;
	case 481:
		return _game_design.Enemy_design.SheetBattle_482.int32Value.getValue(wave, param);
		break;
	case 482:
		return _game_design.Enemy_design.SheetBattle_483.int32Value.getValue(wave, param);
		break;
	case 483:
		return _game_design.Enemy_design.SheetBattle_484.int32Value.getValue(wave, param);
		break;
	case 484:
		return _game_design.Enemy_design.SheetBattle_485.int32Value.getValue(wave, param);
		break;
	case 485:
		return _game_design.Enemy_design.SheetBattle_486.int32Value.getValue(wave, param);
		break;
	case 486:
		return _game_design.Enemy_design.SheetBattle_487.int32Value.getValue(wave, param);
		break;
	case 487:
		return _game_design.Enemy_design.SheetBattle_488.int32Value.getValue(wave, param);
		break;
	case 488:
		return _game_design.Enemy_design.SheetBattle_489.int32Value.getValue(wave, param);
		break;
	case 489:
		return _game_design.Enemy_design.SheetBattle_490.int32Value.getValue(wave, param);
		break;
	case 490:
		return _game_design.Enemy_design.SheetBattle_491.int32Value.getValue(wave, param);
		break;
	case 491:
		return _game_design.Enemy_design.SheetBattle_492.int32Value.getValue(wave, param);
		break;
	case 492:
		return _game_design.Enemy_design.SheetBattle_493.int32Value.getValue(wave, param);
		break;
	case 493:
		return _game_design.Enemy_design.SheetBattle_494.int32Value.getValue(wave, param);
		break;
	case 494:
		return _game_design.Enemy_design.SheetBattle_495.int32Value.getValue(wave, param);
		break;
	case 495:
		return _game_design.Enemy_design.SheetBattle_496.int32Value.getValue(wave, param);
		break;
	case 496:
		return _game_design.Enemy_design.SheetBattle_497.int32Value.getValue(wave, param);
		break;
	case 497:
		return _game_design.Enemy_design.SheetBattle_498.int32Value.getValue(wave, param);
		break;
	case 498:
		return _game_design.Enemy_design.SheetBattle_499.int32Value.getValue(wave, param);
		break;
	case 499:
		return _game_design.Enemy_design.SheetBattle_500.int32Value.getValue(wave, param);
		break;
	default:
		return _game_design.Enemy_design.SheetBattle_500.int32Value.getValue(wave, param);
		break;
	}
	
}
const char* TDGame::GetDesignBattleString(int battle, int id, int param)
{
#if GAME_DEBUG
#if define MAC_OS
#else
	battle = GAME_DEBUG_BATTLE_FIX - 1;
#endif
#endif
	switch (battle)
	{
	case 0:
		return _game_design.Enemy_design.SheetBattle_1.stringValue.getValue(id, param);
		break;
	case 1:
		return _game_design.Enemy_design.SheetBattle_2.stringValue.getValue(id, param);
		break;
	case 2:
		return _game_design.Enemy_design.SheetBattle_3.stringValue.getValue(id, param);
		break;
	case 3:
		return _game_design.Enemy_design.SheetBattle_4.stringValue.getValue(id, param);
		break;
	case 4:
		return _game_design.Enemy_design.SheetBattle_5.stringValue.getValue(id, param);
		break;
	case 5:
		return _game_design.Enemy_design.SheetBattle_6.stringValue.getValue(id, param);
		break;
	case 6:
		return _game_design.Enemy_design.SheetBattle_7.stringValue.getValue(id, param);
		break;
	case 7:
		return _game_design.Enemy_design.SheetBattle_8.stringValue.getValue(id, param);
		break;
	case 8:
		return _game_design.Enemy_design.SheetBattle_9.stringValue.getValue(id, param);
		break;
	case 9:
		return _game_design.Enemy_design.SheetBattle_10.stringValue.getValue(id, param);
		break;
	case 10:
		return _game_design.Enemy_design.SheetBattle_11.stringValue.getValue(id, param);
		break;
	case 11:
		return _game_design.Enemy_design.SheetBattle_12.stringValue.getValue(id, param);
		break;
	case 12:
		return _game_design.Enemy_design.SheetBattle_13.stringValue.getValue(id, param);
		break;
	case 13:
		return _game_design.Enemy_design.SheetBattle_14.stringValue.getValue(id, param);
		break;
	case 14:
		return _game_design.Enemy_design.SheetBattle_15.stringValue.getValue(id, param);
		break;
	case 15:
		return _game_design.Enemy_design.SheetBattle_16.stringValue.getValue(id, param);
		break;
	case 16:
		return _game_design.Enemy_design.SheetBattle_17.stringValue.getValue(id, param);
		break;
	case 17:
		return _game_design.Enemy_design.SheetBattle_18.stringValue.getValue(id, param);
		break;
	case 18:
		return _game_design.Enemy_design.SheetBattle_19.stringValue.getValue(id, param);
		break;
	case 19:
		return _game_design.Enemy_design.SheetBattle_20.stringValue.getValue(id, param);
		break;
	case 20:
		return _game_design.Enemy_design.SheetBattle_21.stringValue.getValue(id, param);
		break;
	case 21:
		return _game_design.Enemy_design.SheetBattle_22.stringValue.getValue(id, param);
		break;
	case 22:
		return _game_design.Enemy_design.SheetBattle_23.stringValue.getValue(id, param);
		break;
	case 23:
		return _game_design.Enemy_design.SheetBattle_24.stringValue.getValue(id, param);
		break;
	case 24:
		return _game_design.Enemy_design.SheetBattle_25.stringValue.getValue(id, param);
		break;
	case 25:
		return _game_design.Enemy_design.SheetBattle_26.stringValue.getValue(id, param);
		break;
	case 26:
		return _game_design.Enemy_design.SheetBattle_27.stringValue.getValue(id, param);
		break;
	case 27:
		return _game_design.Enemy_design.SheetBattle_28.stringValue.getValue(id, param);
		break;
	case 28:
		return _game_design.Enemy_design.SheetBattle_29.stringValue.getValue(id, param);
		break;
	case 29:
		return _game_design.Enemy_design.SheetBattle_30.stringValue.getValue(id, param);
		break;
	case 30:
		return _game_design.Enemy_design.SheetBattle_31.stringValue.getValue(id, param);
		break;
	case 31:
		return _game_design.Enemy_design.SheetBattle_32.stringValue.getValue(id, param);
		break;
	case 32:
		return _game_design.Enemy_design.SheetBattle_33.stringValue.getValue(id, param);
		break;
	case 33:
		return _game_design.Enemy_design.SheetBattle_34.stringValue.getValue(id, param);
		break;
	case 34:
		return _game_design.Enemy_design.SheetBattle_35.stringValue.getValue(id, param);
		break;
	case 35:
		return _game_design.Enemy_design.SheetBattle_36.stringValue.getValue(id, param);
		break;
	case 36:
		return _game_design.Enemy_design.SheetBattle_37.stringValue.getValue(id, param);
		break;
	case 37:
		return _game_design.Enemy_design.SheetBattle_38.stringValue.getValue(id, param);
		break;
	case 38:
		return _game_design.Enemy_design.SheetBattle_39.stringValue.getValue(id, param);
		break;
	case 39:
		return _game_design.Enemy_design.SheetBattle_40.stringValue.getValue(id, param);
		break;
	case 40:
		return _game_design.Enemy_design.SheetBattle_41.stringValue.getValue(id, param);
		break;
	case 41:
		return _game_design.Enemy_design.SheetBattle_42.stringValue.getValue(id, param);
		break;
	case 42:
		return _game_design.Enemy_design.SheetBattle_43.stringValue.getValue(id, param);
		break;
	case 43:
		return _game_design.Enemy_design.SheetBattle_44.stringValue.getValue(id, param);
		break;
	case 44:
		return _game_design.Enemy_design.SheetBattle_45.stringValue.getValue(id, param);
		break;
	case 45:
		return _game_design.Enemy_design.SheetBattle_46.stringValue.getValue(id, param);
		break;
	case 46:
		return _game_design.Enemy_design.SheetBattle_47.stringValue.getValue(id, param);
		break;
	case 47:
		return _game_design.Enemy_design.SheetBattle_48.stringValue.getValue(id, param);
		break;
	case 48:
		return _game_design.Enemy_design.SheetBattle_49.stringValue.getValue(id, param);
		break;
	case 49:
		return _game_design.Enemy_design.SheetBattle_50.stringValue.getValue(id, param);
		break;
	case 50:
		return _game_design.Enemy_design.SheetBattle_51.stringValue.getValue(id, param);
		break;
	case 51:
		return _game_design.Enemy_design.SheetBattle_52.stringValue.getValue(id, param);
		break;
	case 52:
		return _game_design.Enemy_design.SheetBattle_53.stringValue.getValue(id, param);
		break;
	case 53:
		return _game_design.Enemy_design.SheetBattle_54.stringValue.getValue(id, param);
		break;
	case 54:
		return _game_design.Enemy_design.SheetBattle_55.stringValue.getValue(id, param);
		break;
	case 55:
		return _game_design.Enemy_design.SheetBattle_56.stringValue.getValue(id, param);
		break;
	case 56:
		return _game_design.Enemy_design.SheetBattle_57.stringValue.getValue(id, param);
		break;
	case 57:
		return _game_design.Enemy_design.SheetBattle_58.stringValue.getValue(id, param);
		break;
	case 58:
		return _game_design.Enemy_design.SheetBattle_59.stringValue.getValue(id, param);
		break;
	case 59:
		return _game_design.Enemy_design.SheetBattle_60.stringValue.getValue(id, param);
		break;
	case 60:
		return _game_design.Enemy_design.SheetBattle_61.stringValue.getValue(id, param);
		break;
	case 61:
		return _game_design.Enemy_design.SheetBattle_62.stringValue.getValue(id, param);
		break;
	case 62:
		return _game_design.Enemy_design.SheetBattle_63.stringValue.getValue(id, param);
		break;
	case 63:
		return _game_design.Enemy_design.SheetBattle_64.stringValue.getValue(id, param);
		break;
	case 64:
		return _game_design.Enemy_design.SheetBattle_65.stringValue.getValue(id, param);
		break;
	case 65:
		return _game_design.Enemy_design.SheetBattle_66.stringValue.getValue(id, param);
		break;
	case 66:
		return _game_design.Enemy_design.SheetBattle_67.stringValue.getValue(id, param);
		break;
	case 67:
		return _game_design.Enemy_design.SheetBattle_68.stringValue.getValue(id, param);
		break;
	case 68:
		return _game_design.Enemy_design.SheetBattle_69.stringValue.getValue(id, param);
		break;
	case 69:
		return _game_design.Enemy_design.SheetBattle_70.stringValue.getValue(id, param);
		break;
	case 70:
		return _game_design.Enemy_design.SheetBattle_71.stringValue.getValue(id, param);
		break;
	case 71:
		return _game_design.Enemy_design.SheetBattle_72.stringValue.getValue(id, param);
		break;
	case 72:
		return _game_design.Enemy_design.SheetBattle_73.stringValue.getValue(id, param);
		break;
	case 73:
		return _game_design.Enemy_design.SheetBattle_74.stringValue.getValue(id, param);
		break;
	case 74:
		return _game_design.Enemy_design.SheetBattle_75.stringValue.getValue(id, param);
		break;
	case 75:
		return _game_design.Enemy_design.SheetBattle_76.stringValue.getValue(id, param);
		break;
	case 76:
		return _game_design.Enemy_design.SheetBattle_77.stringValue.getValue(id, param);
		break;
	case 77:
		return _game_design.Enemy_design.SheetBattle_78.stringValue.getValue(id, param);
		break;
	case 78:
		return _game_design.Enemy_design.SheetBattle_79.stringValue.getValue(id, param);
		break;
	case 79:
		return _game_design.Enemy_design.SheetBattle_80.stringValue.getValue(id, param);
		break;
	case 80:
		return _game_design.Enemy_design.SheetBattle_81.stringValue.getValue(id, param);
		break;
	case 81:
		return _game_design.Enemy_design.SheetBattle_82.stringValue.getValue(id, param);
		break;
	case 82:
		return _game_design.Enemy_design.SheetBattle_83.stringValue.getValue(id, param);
		break;
	case 83:
		return _game_design.Enemy_design.SheetBattle_84.stringValue.getValue(id, param);
		break;
	case 84:
		return _game_design.Enemy_design.SheetBattle_85.stringValue.getValue(id, param);
		break;
	case 85:
		return _game_design.Enemy_design.SheetBattle_86.stringValue.getValue(id, param);
		break;
	case 86:
		return _game_design.Enemy_design.SheetBattle_87.stringValue.getValue(id, param);
		break;
	case 87:
		return _game_design.Enemy_design.SheetBattle_88.stringValue.getValue(id, param);
		break;
	case 88:
		return _game_design.Enemy_design.SheetBattle_89.stringValue.getValue(id, param);
		break;
	case 89:
		return _game_design.Enemy_design.SheetBattle_90.stringValue.getValue(id, param);
		break;
	case 90:
		return _game_design.Enemy_design.SheetBattle_91.stringValue.getValue(id, param);
		break;
	case 91:
		return _game_design.Enemy_design.SheetBattle_92.stringValue.getValue(id, param);
		break;
	case 92:
		return _game_design.Enemy_design.SheetBattle_93.stringValue.getValue(id, param);
		break;
	case 93:
		return _game_design.Enemy_design.SheetBattle_94.stringValue.getValue(id, param);
		break;
	case 94:
		return _game_design.Enemy_design.SheetBattle_95.stringValue.getValue(id, param);
		break;
	case 95:
		return _game_design.Enemy_design.SheetBattle_96.stringValue.getValue(id, param);
		break;
	case 96:
		return _game_design.Enemy_design.SheetBattle_97.stringValue.getValue(id, param);
		break;
	case 97:
		return _game_design.Enemy_design.SheetBattle_98.stringValue.getValue(id, param);
		break;
	case 98:
		return _game_design.Enemy_design.SheetBattle_99.stringValue.getValue(id, param);
		break;
	case 99:
		return _game_design.Enemy_design.SheetBattle_100.stringValue.getValue(id, param);
		break;
	case 100:
		return _game_design.Enemy_design.SheetBattle_101.stringValue.getValue(id, param);
		break;
	case 101:
		return _game_design.Enemy_design.SheetBattle_102.stringValue.getValue(id, param);
		break;
	case 102:
		return _game_design.Enemy_design.SheetBattle_103.stringValue.getValue(id, param);
		break;
	case 103:
		return _game_design.Enemy_design.SheetBattle_104.stringValue.getValue(id, param);
		break;
	case 104:
		return _game_design.Enemy_design.SheetBattle_105.stringValue.getValue(id, param);
		break;
	case 105:
		return _game_design.Enemy_design.SheetBattle_106.stringValue.getValue(id, param);
		break;
	case 106:
		return _game_design.Enemy_design.SheetBattle_107.stringValue.getValue(id, param);
		break;
	case 107:
		return _game_design.Enemy_design.SheetBattle_108.stringValue.getValue(id, param);
		break;
	case 108:
		return _game_design.Enemy_design.SheetBattle_109.stringValue.getValue(id, param);
		break;
	case 109:
		return _game_design.Enemy_design.SheetBattle_110.stringValue.getValue(id, param);
		break;
	case 110:
		return _game_design.Enemy_design.SheetBattle_111.stringValue.getValue(id, param);
		break;
	case 111:
		return _game_design.Enemy_design.SheetBattle_112.stringValue.getValue(id, param);
		break;
	case 112:
		return _game_design.Enemy_design.SheetBattle_113.stringValue.getValue(id, param);
		break;
	case 113:
		return _game_design.Enemy_design.SheetBattle_114.stringValue.getValue(id, param);
		break;
	case 114:
		return _game_design.Enemy_design.SheetBattle_115.stringValue.getValue(id, param);
		break;
	case 115:
		return _game_design.Enemy_design.SheetBattle_116.stringValue.getValue(id, param);
		break;
	case 116:
		return _game_design.Enemy_design.SheetBattle_117.stringValue.getValue(id, param);
		break;
	case 117:
		return _game_design.Enemy_design.SheetBattle_118.stringValue.getValue(id, param);
		break;
	case 118:
		return _game_design.Enemy_design.SheetBattle_119.stringValue.getValue(id, param);
		break;
	case 119:
		return _game_design.Enemy_design.SheetBattle_120.stringValue.getValue(id, param);
		break;
	case 120:
		return _game_design.Enemy_design.SheetBattle_121.stringValue.getValue(id, param);
		break;
	case 121:
		return _game_design.Enemy_design.SheetBattle_122.stringValue.getValue(id, param);
		break;
	case 122:
		return _game_design.Enemy_design.SheetBattle_123.stringValue.getValue(id, param);
		break;
	case 123:
		return _game_design.Enemy_design.SheetBattle_124.stringValue.getValue(id, param);
		break;
	case 124:
		return _game_design.Enemy_design.SheetBattle_125.stringValue.getValue(id, param);
		break;
	case 125:
		return _game_design.Enemy_design.SheetBattle_126.stringValue.getValue(id, param);
		break;
	case 126:
		return _game_design.Enemy_design.SheetBattle_127.stringValue.getValue(id, param);
		break;
	case 127:
		return _game_design.Enemy_design.SheetBattle_128.stringValue.getValue(id, param);
		break;
	case 128:
		return _game_design.Enemy_design.SheetBattle_129.stringValue.getValue(id, param);
		break;
	case 129:
		return _game_design.Enemy_design.SheetBattle_130.stringValue.getValue(id, param);
		break;
	case 130:
		return _game_design.Enemy_design.SheetBattle_131.stringValue.getValue(id, param);
		break;
	case 131:
		return _game_design.Enemy_design.SheetBattle_132.stringValue.getValue(id, param);
		break;
	case 132:
		return _game_design.Enemy_design.SheetBattle_133.stringValue.getValue(id, param);
		break;
	case 133:
		return _game_design.Enemy_design.SheetBattle_134.stringValue.getValue(id, param);
		break;
	case 134:
		return _game_design.Enemy_design.SheetBattle_135.stringValue.getValue(id, param);
		break;
	case 135:
		return _game_design.Enemy_design.SheetBattle_136.stringValue.getValue(id, param);
		break;
	case 136:
		return _game_design.Enemy_design.SheetBattle_137.stringValue.getValue(id, param);
		break;
	case 137:
		return _game_design.Enemy_design.SheetBattle_138.stringValue.getValue(id, param);
		break;
	case 138:
		return _game_design.Enemy_design.SheetBattle_139.stringValue.getValue(id, param);
		break;
	case 139:
		return _game_design.Enemy_design.SheetBattle_140.stringValue.getValue(id, param);
		break;
	case 140:
		return _game_design.Enemy_design.SheetBattle_141.stringValue.getValue(id, param);
		break;
	case 141:
		return _game_design.Enemy_design.SheetBattle_142.stringValue.getValue(id, param);
		break;
	case 142:
		return _game_design.Enemy_design.SheetBattle_143.stringValue.getValue(id, param);
		break;
	case 143:
		return _game_design.Enemy_design.SheetBattle_144.stringValue.getValue(id, param);
		break;
	case 144:
		return _game_design.Enemy_design.SheetBattle_145.stringValue.getValue(id, param);
		break;
	case 145:
		return _game_design.Enemy_design.SheetBattle_146.stringValue.getValue(id, param);
		break;
	case 146:
		return _game_design.Enemy_design.SheetBattle_147.stringValue.getValue(id, param);
		break;
	case 147:
		return _game_design.Enemy_design.SheetBattle_148.stringValue.getValue(id, param);
		break;
	case 148:
		return _game_design.Enemy_design.SheetBattle_149.stringValue.getValue(id, param);
		break;
	case 149:
		return _game_design.Enemy_design.SheetBattle_150.stringValue.getValue(id, param);
		break;
	case 150:
		return _game_design.Enemy_design.SheetBattle_151.stringValue.getValue(id, param);
		break;
	case 151:
		return _game_design.Enemy_design.SheetBattle_152.stringValue.getValue(id, param);
		break;
	case 152:
		return _game_design.Enemy_design.SheetBattle_153.stringValue.getValue(id, param);
		break;
	case 153:
		return _game_design.Enemy_design.SheetBattle_154.stringValue.getValue(id, param);
		break;
	case 154:
		return _game_design.Enemy_design.SheetBattle_155.stringValue.getValue(id, param);
		break;
	case 155:
		return _game_design.Enemy_design.SheetBattle_156.stringValue.getValue(id, param);
		break;
	case 156:
		return _game_design.Enemy_design.SheetBattle_157.stringValue.getValue(id, param);
		break;
	case 157:
		return _game_design.Enemy_design.SheetBattle_158.stringValue.getValue(id, param);
		break;
	case 158:
		return _game_design.Enemy_design.SheetBattle_159.stringValue.getValue(id, param);
		break;
	case 159:
		return _game_design.Enemy_design.SheetBattle_160.stringValue.getValue(id, param);
		break;
	case 160:
		return _game_design.Enemy_design.SheetBattle_161.stringValue.getValue(id, param);
		break;
	case 161:
		return _game_design.Enemy_design.SheetBattle_162.stringValue.getValue(id, param);
		break;
	case 162:
		return _game_design.Enemy_design.SheetBattle_163.stringValue.getValue(id, param);
		break;
	case 163:
		return _game_design.Enemy_design.SheetBattle_164.stringValue.getValue(id, param);
		break;
	case 164:
		return _game_design.Enemy_design.SheetBattle_165.stringValue.getValue(id, param);
		break;
	case 165:
		return _game_design.Enemy_design.SheetBattle_166.stringValue.getValue(id, param);
		break;
	case 166:
		return _game_design.Enemy_design.SheetBattle_167.stringValue.getValue(id, param);
		break;
	case 167:
		return _game_design.Enemy_design.SheetBattle_168.stringValue.getValue(id, param);
		break;
	case 168:
		return _game_design.Enemy_design.SheetBattle_169.stringValue.getValue(id, param);
		break;
	case 169:
		return _game_design.Enemy_design.SheetBattle_170.stringValue.getValue(id, param);
		break;
	case 170:
		return _game_design.Enemy_design.SheetBattle_171.stringValue.getValue(id, param);
		break;
	case 171:
		return _game_design.Enemy_design.SheetBattle_172.stringValue.getValue(id, param);
		break;
	case 172:
		return _game_design.Enemy_design.SheetBattle_173.stringValue.getValue(id, param);
		break;
	case 173:
		return _game_design.Enemy_design.SheetBattle_174.stringValue.getValue(id, param);
		break;
	case 174:
		return _game_design.Enemy_design.SheetBattle_175.stringValue.getValue(id, param);
		break;
	case 175:
		return _game_design.Enemy_design.SheetBattle_176.stringValue.getValue(id, param);
		break;
	case 176:
		return _game_design.Enemy_design.SheetBattle_177.stringValue.getValue(id, param);
		break;
	case 177:
		return _game_design.Enemy_design.SheetBattle_178.stringValue.getValue(id, param);
		break;
	case 178:
		return _game_design.Enemy_design.SheetBattle_179.stringValue.getValue(id, param);
		break;
	case 179:
		return _game_design.Enemy_design.SheetBattle_180.stringValue.getValue(id, param);
		break;
	case 180:
		return _game_design.Enemy_design.SheetBattle_181.stringValue.getValue(id, param);
		break;
	case 181:
		return _game_design.Enemy_design.SheetBattle_182.stringValue.getValue(id, param);
		break;
	case 182:
		return _game_design.Enemy_design.SheetBattle_183.stringValue.getValue(id, param);
		break;
	case 183:
		return _game_design.Enemy_design.SheetBattle_184.stringValue.getValue(id, param);
		break;
	case 184:
		return _game_design.Enemy_design.SheetBattle_185.stringValue.getValue(id, param);
		break;
	case 185:
		return _game_design.Enemy_design.SheetBattle_186.stringValue.getValue(id, param);
		break;
	case 186:
		return _game_design.Enemy_design.SheetBattle_187.stringValue.getValue(id, param);
		break;
	case 187:
		return _game_design.Enemy_design.SheetBattle_188.stringValue.getValue(id, param);
		break;
	case 188:
		return _game_design.Enemy_design.SheetBattle_189.stringValue.getValue(id, param);
		break;
	case 189:
		return _game_design.Enemy_design.SheetBattle_190.stringValue.getValue(id, param);
		break;
	case 190:
		return _game_design.Enemy_design.SheetBattle_191.stringValue.getValue(id, param);
		break;
	case 191:
		return _game_design.Enemy_design.SheetBattle_192.stringValue.getValue(id, param);
		break;
	case 192:
		return _game_design.Enemy_design.SheetBattle_193.stringValue.getValue(id, param);
		break;
	case 193:
		return _game_design.Enemy_design.SheetBattle_194.stringValue.getValue(id, param);
		break;
	case 194:
		return _game_design.Enemy_design.SheetBattle_195.stringValue.getValue(id, param);
		break;
	case 195:
		return _game_design.Enemy_design.SheetBattle_196.stringValue.getValue(id, param);
		break;
	case 196:
		return _game_design.Enemy_design.SheetBattle_197.stringValue.getValue(id, param);
		break;
	case 197:
		return _game_design.Enemy_design.SheetBattle_198.stringValue.getValue(id, param);
		break;
	case 198:
		return _game_design.Enemy_design.SheetBattle_199.stringValue.getValue(id, param);
		break;
	case 199:
		return _game_design.Enemy_design.SheetBattle_200.stringValue.getValue(id, param);
		break;
	case 200:
		return _game_design.Enemy_design.SheetBattle_201.stringValue.getValue(id, param);
		break;
	case 201:
		return _game_design.Enemy_design.SheetBattle_202.stringValue.getValue(id, param);
		break;
	case 202:
		return _game_design.Enemy_design.SheetBattle_203.stringValue.getValue(id, param);
		break;
	case 203:
		return _game_design.Enemy_design.SheetBattle_204.stringValue.getValue(id, param);
		break;
	case 204:
		return _game_design.Enemy_design.SheetBattle_205.stringValue.getValue(id, param);
		break;
	case 205:
		return _game_design.Enemy_design.SheetBattle_206.stringValue.getValue(id, param);
		break;
	case 206:
		return _game_design.Enemy_design.SheetBattle_207.stringValue.getValue(id, param);
		break;
	case 207:
		return _game_design.Enemy_design.SheetBattle_208.stringValue.getValue(id, param);
		break;
	case 208:
		return _game_design.Enemy_design.SheetBattle_209.stringValue.getValue(id, param);
		break;
	case 209:
		return _game_design.Enemy_design.SheetBattle_210.stringValue.getValue(id, param);
		break;
	case 210:
		return _game_design.Enemy_design.SheetBattle_211.stringValue.getValue(id, param);
		break;
	case 211:
		return _game_design.Enemy_design.SheetBattle_212.stringValue.getValue(id, param);
		break;
	case 212:
		return _game_design.Enemy_design.SheetBattle_213.stringValue.getValue(id, param);
		break;
	case 213:
		return _game_design.Enemy_design.SheetBattle_214.stringValue.getValue(id, param);
		break;
	case 214:
		return _game_design.Enemy_design.SheetBattle_215.stringValue.getValue(id, param);
		break;
	case 215:
		return _game_design.Enemy_design.SheetBattle_216.stringValue.getValue(id, param);
		break;
	case 216:
		return _game_design.Enemy_design.SheetBattle_217.stringValue.getValue(id, param);
		break;
	case 217:
		return _game_design.Enemy_design.SheetBattle_218.stringValue.getValue(id, param);
		break;
	case 218:
		return _game_design.Enemy_design.SheetBattle_219.stringValue.getValue(id, param);
		break;
	case 219:
		return _game_design.Enemy_design.SheetBattle_220.stringValue.getValue(id, param);
		break;
	case 220:
		return _game_design.Enemy_design.SheetBattle_221.stringValue.getValue(id, param);
		break;
	case 221:
		return _game_design.Enemy_design.SheetBattle_222.stringValue.getValue(id, param);
		break;
	case 222:
		return _game_design.Enemy_design.SheetBattle_223.stringValue.getValue(id, param);
		break;
	case 223:
		return _game_design.Enemy_design.SheetBattle_224.stringValue.getValue(id, param);
		break;
	case 224:
		return _game_design.Enemy_design.SheetBattle_225.stringValue.getValue(id, param);
		break;
	case 225:
		return _game_design.Enemy_design.SheetBattle_226.stringValue.getValue(id, param);
		break;
	case 226:
		return _game_design.Enemy_design.SheetBattle_227.stringValue.getValue(id, param);
		break;
	case 227:
		return _game_design.Enemy_design.SheetBattle_228.stringValue.getValue(id, param);
		break;
	case 228:
		return _game_design.Enemy_design.SheetBattle_229.stringValue.getValue(id, param);
		break;
	case 229:
		return _game_design.Enemy_design.SheetBattle_230.stringValue.getValue(id, param);
		break;
	case 230:
		return _game_design.Enemy_design.SheetBattle_231.stringValue.getValue(id, param);
		break;
	case 231:
		return _game_design.Enemy_design.SheetBattle_232.stringValue.getValue(id, param);
		break;
	case 232:
		return _game_design.Enemy_design.SheetBattle_233.stringValue.getValue(id, param);
		break;
	case 233:
		return _game_design.Enemy_design.SheetBattle_234.stringValue.getValue(id, param);
		break;
	case 234:
		return _game_design.Enemy_design.SheetBattle_235.stringValue.getValue(id, param);
		break;
	case 235:
		return _game_design.Enemy_design.SheetBattle_236.stringValue.getValue(id, param);
		break;
	case 236:
		return _game_design.Enemy_design.SheetBattle_237.stringValue.getValue(id, param);
		break;
	case 237:
		return _game_design.Enemy_design.SheetBattle_238.stringValue.getValue(id, param);
		break;
	case 238:
		return _game_design.Enemy_design.SheetBattle_239.stringValue.getValue(id, param);
		break;
	case 239:
		return _game_design.Enemy_design.SheetBattle_240.stringValue.getValue(id, param);
		break;
	case 240:
		return _game_design.Enemy_design.SheetBattle_241.stringValue.getValue(id, param);
		break;
	case 241:
		return _game_design.Enemy_design.SheetBattle_242.stringValue.getValue(id, param);
		break;
	case 242:
		return _game_design.Enemy_design.SheetBattle_243.stringValue.getValue(id, param);
		break;
	case 243:
		return _game_design.Enemy_design.SheetBattle_244.stringValue.getValue(id, param);
		break;
	case 244:
		return _game_design.Enemy_design.SheetBattle_245.stringValue.getValue(id, param);
		break;
	case 245:
		return _game_design.Enemy_design.SheetBattle_246.stringValue.getValue(id, param);
		break;
	case 246:
		return _game_design.Enemy_design.SheetBattle_247.stringValue.getValue(id, param);
		break;
	case 247:
		return _game_design.Enemy_design.SheetBattle_248.stringValue.getValue(id, param);
		break;
	case 248:
		return _game_design.Enemy_design.SheetBattle_249.stringValue.getValue(id, param);
		break;
	case 249:
		return _game_design.Enemy_design.SheetBattle_250.stringValue.getValue(id, param);
		break;
	case 250:
		return _game_design.Enemy_design.SheetBattle_251.stringValue.getValue(id, param);
		break;
	case 251:
		return _game_design.Enemy_design.SheetBattle_252.stringValue.getValue(id, param);
		break;
	case 252:
		return _game_design.Enemy_design.SheetBattle_253.stringValue.getValue(id, param);
		break;
	case 253:
		return _game_design.Enemy_design.SheetBattle_254.stringValue.getValue(id, param);
		break;
	case 254:
		return _game_design.Enemy_design.SheetBattle_255.stringValue.getValue(id, param);
		break;
	case 255:
		return _game_design.Enemy_design.SheetBattle_256.stringValue.getValue(id, param);
		break;
	case 256:
		return _game_design.Enemy_design.SheetBattle_257.stringValue.getValue(id, param);
		break;
	case 257:
		return _game_design.Enemy_design.SheetBattle_258.stringValue.getValue(id, param);
		break;
	case 258:
		return _game_design.Enemy_design.SheetBattle_259.stringValue.getValue(id, param);
		break;
	case 259:
		return _game_design.Enemy_design.SheetBattle_260.stringValue.getValue(id, param);
		break;
	case 260:
		return _game_design.Enemy_design.SheetBattle_261.stringValue.getValue(id, param);
		break;
	case 261:
		return _game_design.Enemy_design.SheetBattle_262.stringValue.getValue(id, param);
		break;
	case 262:
		return _game_design.Enemy_design.SheetBattle_263.stringValue.getValue(id, param);
		break;
	case 263:
		return _game_design.Enemy_design.SheetBattle_264.stringValue.getValue(id, param);
		break;
	case 264:
		return _game_design.Enemy_design.SheetBattle_265.stringValue.getValue(id, param);
		break;
	case 265:
		return _game_design.Enemy_design.SheetBattle_266.stringValue.getValue(id, param);
		break;
	case 266:
		return _game_design.Enemy_design.SheetBattle_267.stringValue.getValue(id, param);
		break;
	case 267:
		return _game_design.Enemy_design.SheetBattle_268.stringValue.getValue(id, param);
		break;
	case 268:
		return _game_design.Enemy_design.SheetBattle_269.stringValue.getValue(id, param);
		break;
	case 269:
		return _game_design.Enemy_design.SheetBattle_270.stringValue.getValue(id, param);
		break;
	case 270:
		return _game_design.Enemy_design.SheetBattle_271.stringValue.getValue(id, param);
		break;
	case 271:
		return _game_design.Enemy_design.SheetBattle_272.stringValue.getValue(id, param);
		break;
	case 272:
		return _game_design.Enemy_design.SheetBattle_273.stringValue.getValue(id, param);
		break;
	case 273:
		return _game_design.Enemy_design.SheetBattle_274.stringValue.getValue(id, param);
		break;
	case 274:
		return _game_design.Enemy_design.SheetBattle_275.stringValue.getValue(id, param);
		break;
	case 275:
		return _game_design.Enemy_design.SheetBattle_276.stringValue.getValue(id, param);
		break;
	case 276:
		return _game_design.Enemy_design.SheetBattle_277.stringValue.getValue(id, param);
		break;
	case 277:
		return _game_design.Enemy_design.SheetBattle_278.stringValue.getValue(id, param);
		break;
	case 278:
		return _game_design.Enemy_design.SheetBattle_279.stringValue.getValue(id, param);
		break;
	case 279:
		return _game_design.Enemy_design.SheetBattle_280.stringValue.getValue(id, param);
		break;
	case 280:
		return _game_design.Enemy_design.SheetBattle_281.stringValue.getValue(id, param);
		break;
	case 281:
		return _game_design.Enemy_design.SheetBattle_282.stringValue.getValue(id, param);
		break;
	case 282:
		return _game_design.Enemy_design.SheetBattle_283.stringValue.getValue(id, param);
		break;
	case 283:
		return _game_design.Enemy_design.SheetBattle_284.stringValue.getValue(id, param);
		break;
	case 284:
		return _game_design.Enemy_design.SheetBattle_285.stringValue.getValue(id, param);
		break;
	case 285:
		return _game_design.Enemy_design.SheetBattle_286.stringValue.getValue(id, param);
		break;
	case 286:
		return _game_design.Enemy_design.SheetBattle_287.stringValue.getValue(id, param);
		break;
	case 287:
		return _game_design.Enemy_design.SheetBattle_288.stringValue.getValue(id, param);
		break;
	case 288:
		return _game_design.Enemy_design.SheetBattle_289.stringValue.getValue(id, param);
		break;
	case 289:
		return _game_design.Enemy_design.SheetBattle_290.stringValue.getValue(id, param);
		break;
	case 290:
		return _game_design.Enemy_design.SheetBattle_291.stringValue.getValue(id, param);
		break;
	case 291:
		return _game_design.Enemy_design.SheetBattle_292.stringValue.getValue(id, param);
		break;
	case 292:
		return _game_design.Enemy_design.SheetBattle_293.stringValue.getValue(id, param);
		break;
	case 293:
		return _game_design.Enemy_design.SheetBattle_294.stringValue.getValue(id, param);
		break;
	case 294:
		return _game_design.Enemy_design.SheetBattle_295.stringValue.getValue(id, param);
		break;
	case 295:
		return _game_design.Enemy_design.SheetBattle_296.stringValue.getValue(id, param);
		break;
	case 296:
		return _game_design.Enemy_design.SheetBattle_297.stringValue.getValue(id, param);
		break;
	case 297:
		return _game_design.Enemy_design.SheetBattle_298.stringValue.getValue(id, param);
		break;
	case 298:
		return _game_design.Enemy_design.SheetBattle_299.stringValue.getValue(id, param);
		break;
	case 299:
		return _game_design.Enemy_design.SheetBattle_300.stringValue.getValue(id, param);
		break;
	case 300:
		return _game_design.Enemy_design.SheetBattle_301.stringValue.getValue(id, param);
		break;
	case 301:
		return _game_design.Enemy_design.SheetBattle_302.stringValue.getValue(id, param);
		break;
	case 302:
		return _game_design.Enemy_design.SheetBattle_303.stringValue.getValue(id, param);
		break;
	case 303:
		return _game_design.Enemy_design.SheetBattle_304.stringValue.getValue(id, param);
		break;
	case 304:
		return _game_design.Enemy_design.SheetBattle_305.stringValue.getValue(id, param);
		break;
	case 305:
		return _game_design.Enemy_design.SheetBattle_306.stringValue.getValue(id, param);
		break;
	case 306:
		return _game_design.Enemy_design.SheetBattle_307.stringValue.getValue(id, param);
		break;
	case 307:
		return _game_design.Enemy_design.SheetBattle_308.stringValue.getValue(id, param);
		break;
	case 308:
		return _game_design.Enemy_design.SheetBattle_309.stringValue.getValue(id, param);
		break;
	case 309:
		return _game_design.Enemy_design.SheetBattle_310.stringValue.getValue(id, param);
		break;
	case 310:
		return _game_design.Enemy_design.SheetBattle_311.stringValue.getValue(id, param);
		break;
	case 311:
		return _game_design.Enemy_design.SheetBattle_312.stringValue.getValue(id, param);
		break;
	case 312:
		return _game_design.Enemy_design.SheetBattle_313.stringValue.getValue(id, param);
		break;
	case 313:
		return _game_design.Enemy_design.SheetBattle_314.stringValue.getValue(id, param);
		break;
	case 314:
		return _game_design.Enemy_design.SheetBattle_315.stringValue.getValue(id, param);
		break;
	case 315:
		return _game_design.Enemy_design.SheetBattle_316.stringValue.getValue(id, param);
		break;
	case 316:
		return _game_design.Enemy_design.SheetBattle_317.stringValue.getValue(id, param);
		break;
	case 317:
		return _game_design.Enemy_design.SheetBattle_318.stringValue.getValue(id, param);
		break;
	case 318:
		return _game_design.Enemy_design.SheetBattle_319.stringValue.getValue(id, param);
		break;
	case 319:
		return _game_design.Enemy_design.SheetBattle_320.stringValue.getValue(id, param);
		break;
	case 320:
		return _game_design.Enemy_design.SheetBattle_321.stringValue.getValue(id, param);
		break;
	case 321:
		return _game_design.Enemy_design.SheetBattle_322.stringValue.getValue(id, param);
		break;
	case 322:
		return _game_design.Enemy_design.SheetBattle_323.stringValue.getValue(id, param);
		break;
	case 323:
		return _game_design.Enemy_design.SheetBattle_324.stringValue.getValue(id, param);
		break;
	case 324:
		return _game_design.Enemy_design.SheetBattle_325.stringValue.getValue(id, param);
		break;
	case 325:
		return _game_design.Enemy_design.SheetBattle_326.stringValue.getValue(id, param);
		break;
	case 326:
		return _game_design.Enemy_design.SheetBattle_327.stringValue.getValue(id, param);
		break;
	case 327:
		return _game_design.Enemy_design.SheetBattle_328.stringValue.getValue(id, param);
		break;
	case 328:
		return _game_design.Enemy_design.SheetBattle_329.stringValue.getValue(id, param);
		break;
	case 329:
		return _game_design.Enemy_design.SheetBattle_330.stringValue.getValue(id, param);
		break;
	case 330:
		return _game_design.Enemy_design.SheetBattle_331.stringValue.getValue(id, param);
		break;
	case 331:
		return _game_design.Enemy_design.SheetBattle_332.stringValue.getValue(id, param);
		break;
	case 332:
		return _game_design.Enemy_design.SheetBattle_333.stringValue.getValue(id, param);
		break;
	case 333:
		return _game_design.Enemy_design.SheetBattle_334.stringValue.getValue(id, param);
		break;
	case 334:
		return _game_design.Enemy_design.SheetBattle_335.stringValue.getValue(id, param);
		break;
	case 335:
		return _game_design.Enemy_design.SheetBattle_336.stringValue.getValue(id, param);
		break;
	case 336:
		return _game_design.Enemy_design.SheetBattle_337.stringValue.getValue(id, param);
		break;
	case 337:
		return _game_design.Enemy_design.SheetBattle_338.stringValue.getValue(id, param);
		break;
	case 338:
		return _game_design.Enemy_design.SheetBattle_339.stringValue.getValue(id, param);
		break;
	case 339:
		return _game_design.Enemy_design.SheetBattle_340.stringValue.getValue(id, param);
		break;
	case 340:
		return _game_design.Enemy_design.SheetBattle_341.stringValue.getValue(id, param);
		break;
	case 341:
		return _game_design.Enemy_design.SheetBattle_342.stringValue.getValue(id, param);
		break;
	case 342:
		return _game_design.Enemy_design.SheetBattle_343.stringValue.getValue(id, param);
		break;
	case 343:
		return _game_design.Enemy_design.SheetBattle_344.stringValue.getValue(id, param);
		break;
	case 344:
		return _game_design.Enemy_design.SheetBattle_345.stringValue.getValue(id, param);
		break;
	case 345:
		return _game_design.Enemy_design.SheetBattle_346.stringValue.getValue(id, param);
		break;
	case 346:
		return _game_design.Enemy_design.SheetBattle_347.stringValue.getValue(id, param);
		break;
	case 347:
		return _game_design.Enemy_design.SheetBattle_348.stringValue.getValue(id, param);
		break;
	case 348:
		return _game_design.Enemy_design.SheetBattle_349.stringValue.getValue(id, param);
		break;
	case 349:
		return _game_design.Enemy_design.SheetBattle_350.stringValue.getValue(id, param);
		break;
	case 350:
		return _game_design.Enemy_design.SheetBattle_351.stringValue.getValue(id, param);
		break;
	case 351:
		return _game_design.Enemy_design.SheetBattle_352.stringValue.getValue(id, param);
		break;
	case 352:
		return _game_design.Enemy_design.SheetBattle_353.stringValue.getValue(id, param);
		break;
	case 353:
		return _game_design.Enemy_design.SheetBattle_354.stringValue.getValue(id, param);
		break;
	case 354:
		return _game_design.Enemy_design.SheetBattle_355.stringValue.getValue(id, param);
		break;
	case 355:
		return _game_design.Enemy_design.SheetBattle_356.stringValue.getValue(id, param);
		break;
	case 356:
		return _game_design.Enemy_design.SheetBattle_357.stringValue.getValue(id, param);
		break;
	case 357:
		return _game_design.Enemy_design.SheetBattle_358.stringValue.getValue(id, param);
		break;
	case 358:
		return _game_design.Enemy_design.SheetBattle_359.stringValue.getValue(id, param);
		break;
	case 359:
		return _game_design.Enemy_design.SheetBattle_360.stringValue.getValue(id, param);
		break;
	case 360:
		return _game_design.Enemy_design.SheetBattle_361.stringValue.getValue(id, param);
		break;
	case 361:
		return _game_design.Enemy_design.SheetBattle_362.stringValue.getValue(id, param);
		break;
	case 362:
		return _game_design.Enemy_design.SheetBattle_363.stringValue.getValue(id, param);
		break;
	case 363:
		return _game_design.Enemy_design.SheetBattle_364.stringValue.getValue(id, param);
		break;
	case 364:
		return _game_design.Enemy_design.SheetBattle_365.stringValue.getValue(id, param);
		break;
	case 365:
		return _game_design.Enemy_design.SheetBattle_366.stringValue.getValue(id, param);
		break;
	case 366:
		return _game_design.Enemy_design.SheetBattle_367.stringValue.getValue(id, param);
		break;
	case 367:
		return _game_design.Enemy_design.SheetBattle_368.stringValue.getValue(id, param);
		break;
	case 368:
		return _game_design.Enemy_design.SheetBattle_369.stringValue.getValue(id, param);
		break;
	case 369:
		return _game_design.Enemy_design.SheetBattle_370.stringValue.getValue(id, param);
		break;
	case 370:
		return _game_design.Enemy_design.SheetBattle_371.stringValue.getValue(id, param);
		break;
	case 371:
		return _game_design.Enemy_design.SheetBattle_372.stringValue.getValue(id, param);
		break;
	case 372:
		return _game_design.Enemy_design.SheetBattle_373.stringValue.getValue(id, param);
		break;
	case 373:
		return _game_design.Enemy_design.SheetBattle_374.stringValue.getValue(id, param);
		break;
	case 374:
		return _game_design.Enemy_design.SheetBattle_375.stringValue.getValue(id, param);
		break;
	case 375:
		return _game_design.Enemy_design.SheetBattle_376.stringValue.getValue(id, param);
		break;
	case 376:
		return _game_design.Enemy_design.SheetBattle_377.stringValue.getValue(id, param);
		break;
	case 377:
		return _game_design.Enemy_design.SheetBattle_378.stringValue.getValue(id, param);
		break;
	case 378:
		return _game_design.Enemy_design.SheetBattle_379.stringValue.getValue(id, param);
		break;
	case 379:
		return _game_design.Enemy_design.SheetBattle_380.stringValue.getValue(id, param);
		break;
	case 380:
		return _game_design.Enemy_design.SheetBattle_381.stringValue.getValue(id, param);
		break;
	case 381:
		return _game_design.Enemy_design.SheetBattle_382.stringValue.getValue(id, param);
		break;
	case 382:
		return _game_design.Enemy_design.SheetBattle_383.stringValue.getValue(id, param);
		break;
	case 383:
		return _game_design.Enemy_design.SheetBattle_384.stringValue.getValue(id, param);
		break;
	case 384:
		return _game_design.Enemy_design.SheetBattle_385.stringValue.getValue(id, param);
		break;
	case 385:
		return _game_design.Enemy_design.SheetBattle_386.stringValue.getValue(id, param);
		break;
	case 386:
		return _game_design.Enemy_design.SheetBattle_387.stringValue.getValue(id, param);
		break;
	case 387:
		return _game_design.Enemy_design.SheetBattle_388.stringValue.getValue(id, param);
		break;
	case 388:
		return _game_design.Enemy_design.SheetBattle_389.stringValue.getValue(id, param);
		break;
	case 389:
		return _game_design.Enemy_design.SheetBattle_390.stringValue.getValue(id, param);
		break;
	case 390:
		return _game_design.Enemy_design.SheetBattle_391.stringValue.getValue(id, param);
		break;
	case 391:
		return _game_design.Enemy_design.SheetBattle_392.stringValue.getValue(id, param);
		break;
	case 392:
		return _game_design.Enemy_design.SheetBattle_393.stringValue.getValue(id, param);
		break;
	case 393:
		return _game_design.Enemy_design.SheetBattle_394.stringValue.getValue(id, param);
		break;
	case 394:
		return _game_design.Enemy_design.SheetBattle_395.stringValue.getValue(id, param);
		break;
	case 395:
		return _game_design.Enemy_design.SheetBattle_396.stringValue.getValue(id, param);
		break;
	case 396:
		return _game_design.Enemy_design.SheetBattle_397.stringValue.getValue(id, param);
		break;
	case 397:
		return _game_design.Enemy_design.SheetBattle_398.stringValue.getValue(id, param);
		break;
	case 398:
		return _game_design.Enemy_design.SheetBattle_399.stringValue.getValue(id, param);
		break;
	case 399:
		return _game_design.Enemy_design.SheetBattle_400.stringValue.getValue(id, param);
		break;
	case 400:
		return _game_design.Enemy_design.SheetBattle_401.stringValue.getValue(id, param);
		break;
	case 401:
		return _game_design.Enemy_design.SheetBattle_402.stringValue.getValue(id, param);
		break;
	case 402:
		return _game_design.Enemy_design.SheetBattle_403.stringValue.getValue(id, param);
		break;
	case 403:
		return _game_design.Enemy_design.SheetBattle_404.stringValue.getValue(id, param);
		break;
	case 404:
		return _game_design.Enemy_design.SheetBattle_405.stringValue.getValue(id, param);
		break;
	case 405:
		return _game_design.Enemy_design.SheetBattle_406.stringValue.getValue(id, param);
		break;
	case 406:
		return _game_design.Enemy_design.SheetBattle_407.stringValue.getValue(id, param);
		break;
	case 407:
		return _game_design.Enemy_design.SheetBattle_408.stringValue.getValue(id, param);
		break;
	case 408:
		return _game_design.Enemy_design.SheetBattle_409.stringValue.getValue(id, param);
		break;
	case 409:
		return _game_design.Enemy_design.SheetBattle_410.stringValue.getValue(id, param);
		break;
	case 410:
		return _game_design.Enemy_design.SheetBattle_411.stringValue.getValue(id, param);
		break;
	case 411:
		return _game_design.Enemy_design.SheetBattle_412.stringValue.getValue(id, param);
		break;
	case 412:
		return _game_design.Enemy_design.SheetBattle_413.stringValue.getValue(id, param);
		break;
	case 413:
		return _game_design.Enemy_design.SheetBattle_414.stringValue.getValue(id, param);
		break;
	case 414:
		return _game_design.Enemy_design.SheetBattle_415.stringValue.getValue(id, param);
		break;
	case 415:
		return _game_design.Enemy_design.SheetBattle_416.stringValue.getValue(id, param);
		break;
	case 416:
		return _game_design.Enemy_design.SheetBattle_417.stringValue.getValue(id, param);
		break;
	case 417:
		return _game_design.Enemy_design.SheetBattle_418.stringValue.getValue(id, param);
		break;
	case 418:
		return _game_design.Enemy_design.SheetBattle_419.stringValue.getValue(id, param);
		break;
	case 419:
		return _game_design.Enemy_design.SheetBattle_420.stringValue.getValue(id, param);
		break;
	case 420:
		return _game_design.Enemy_design.SheetBattle_421.stringValue.getValue(id, param);
		break;
	case 421:
		return _game_design.Enemy_design.SheetBattle_422.stringValue.getValue(id, param);
		break;
	case 422:
		return _game_design.Enemy_design.SheetBattle_423.stringValue.getValue(id, param);
		break;
	case 423:
		return _game_design.Enemy_design.SheetBattle_424.stringValue.getValue(id, param);
		break;
	case 424:
		return _game_design.Enemy_design.SheetBattle_425.stringValue.getValue(id, param);
		break;
	case 425:
		return _game_design.Enemy_design.SheetBattle_426.stringValue.getValue(id, param);
		break;
	case 426:
		return _game_design.Enemy_design.SheetBattle_427.stringValue.getValue(id, param);
		break;
	case 427:
		return _game_design.Enemy_design.SheetBattle_428.stringValue.getValue(id, param);
		break;
	case 428:
		return _game_design.Enemy_design.SheetBattle_429.stringValue.getValue(id, param);
		break;
	case 429:
		return _game_design.Enemy_design.SheetBattle_430.stringValue.getValue(id, param);
		break;
	case 430:
		return _game_design.Enemy_design.SheetBattle_431.stringValue.getValue(id, param);
		break;
	case 431:
		return _game_design.Enemy_design.SheetBattle_432.stringValue.getValue(id, param);
		break;
	case 432:
		return _game_design.Enemy_design.SheetBattle_433.stringValue.getValue(id, param);
		break;
	case 433:
		return _game_design.Enemy_design.SheetBattle_434.stringValue.getValue(id, param);
		break;
	case 434:
		return _game_design.Enemy_design.SheetBattle_435.stringValue.getValue(id, param);
		break;
	case 435:
		return _game_design.Enemy_design.SheetBattle_436.stringValue.getValue(id, param);
		break;
	case 436:
		return _game_design.Enemy_design.SheetBattle_437.stringValue.getValue(id, param);
		break;
	case 437:
		return _game_design.Enemy_design.SheetBattle_438.stringValue.getValue(id, param);
		break;
	case 438:
		return _game_design.Enemy_design.SheetBattle_439.stringValue.getValue(id, param);
		break;
	case 439:
		return _game_design.Enemy_design.SheetBattle_440.stringValue.getValue(id, param);
		break;
	case 440:
		return _game_design.Enemy_design.SheetBattle_441.stringValue.getValue(id, param);
		break;
	case 441:
		return _game_design.Enemy_design.SheetBattle_442.stringValue.getValue(id, param);
		break;
	case 442:
		return _game_design.Enemy_design.SheetBattle_443.stringValue.getValue(id, param);
		break;
	case 443:
		return _game_design.Enemy_design.SheetBattle_444.stringValue.getValue(id, param);
		break;
	case 444:
		return _game_design.Enemy_design.SheetBattle_445.stringValue.getValue(id, param);
		break;
	case 445:
		return _game_design.Enemy_design.SheetBattle_446.stringValue.getValue(id, param);
		break;
	case 446:
		return _game_design.Enemy_design.SheetBattle_447.stringValue.getValue(id, param);
		break;
	case 447:
		return _game_design.Enemy_design.SheetBattle_448.stringValue.getValue(id, param);
		break;
	case 448:
		return _game_design.Enemy_design.SheetBattle_449.stringValue.getValue(id, param);
		break;
	case 449:
		return _game_design.Enemy_design.SheetBattle_450.stringValue.getValue(id, param);
		break;
	case 450:
		return _game_design.Enemy_design.SheetBattle_451.stringValue.getValue(id, param);
		break;
	case 451:
		return _game_design.Enemy_design.SheetBattle_452.stringValue.getValue(id, param);
		break;
	case 452:
		return _game_design.Enemy_design.SheetBattle_453.stringValue.getValue(id, param);
		break;
	case 453:
		return _game_design.Enemy_design.SheetBattle_454.stringValue.getValue(id, param);
		break;
	case 454:
		return _game_design.Enemy_design.SheetBattle_455.stringValue.getValue(id, param);
		break;
	case 455:
		return _game_design.Enemy_design.SheetBattle_456.stringValue.getValue(id, param);
		break;
	case 456:
		return _game_design.Enemy_design.SheetBattle_457.stringValue.getValue(id, param);
		break;
	case 457:
		return _game_design.Enemy_design.SheetBattle_458.stringValue.getValue(id, param);
		break;
	case 458:
		return _game_design.Enemy_design.SheetBattle_459.stringValue.getValue(id, param);
		break;
	case 459:
		return _game_design.Enemy_design.SheetBattle_460.stringValue.getValue(id, param);
		break;
	case 460:
		return _game_design.Enemy_design.SheetBattle_461.stringValue.getValue(id, param);
		break;
	case 461:
		return _game_design.Enemy_design.SheetBattle_462.stringValue.getValue(id, param);
		break;
	case 462:
		return _game_design.Enemy_design.SheetBattle_463.stringValue.getValue(id, param);
		break;
	case 463:
		return _game_design.Enemy_design.SheetBattle_464.stringValue.getValue(id, param);
		break;
	case 464:
		return _game_design.Enemy_design.SheetBattle_465.stringValue.getValue(id, param);
		break;
	case 465:
		return _game_design.Enemy_design.SheetBattle_466.stringValue.getValue(id, param);
		break;
	case 466:
		return _game_design.Enemy_design.SheetBattle_467.stringValue.getValue(id, param);
		break;
	case 467:
		return _game_design.Enemy_design.SheetBattle_468.stringValue.getValue(id, param);
		break;
	case 468:
		return _game_design.Enemy_design.SheetBattle_469.stringValue.getValue(id, param);
		break;
	case 469:
		return _game_design.Enemy_design.SheetBattle_470.stringValue.getValue(id, param);
		break;
	case 470:
		return _game_design.Enemy_design.SheetBattle_471.stringValue.getValue(id, param);
		break;
	case 471:
		return _game_design.Enemy_design.SheetBattle_472.stringValue.getValue(id, param);
		break;
	case 472:
		return _game_design.Enemy_design.SheetBattle_473.stringValue.getValue(id, param);
		break;
	case 473:
		return _game_design.Enemy_design.SheetBattle_474.stringValue.getValue(id, param);
		break;
	case 474:
		return _game_design.Enemy_design.SheetBattle_475.stringValue.getValue(id, param);
		break;
	case 475:
		return _game_design.Enemy_design.SheetBattle_476.stringValue.getValue(id, param);
		break;
	case 476:
		return _game_design.Enemy_design.SheetBattle_477.stringValue.getValue(id, param);
		break;
	case 477:
		return _game_design.Enemy_design.SheetBattle_478.stringValue.getValue(id, param);
		break;
	case 478:
		return _game_design.Enemy_design.SheetBattle_479.stringValue.getValue(id, param);
		break;
	case 479:
		return _game_design.Enemy_design.SheetBattle_480.stringValue.getValue(id, param);
		break;
	case 480:
		return _game_design.Enemy_design.SheetBattle_481.stringValue.getValue(id, param);
		break;
	case 481:
		return _game_design.Enemy_design.SheetBattle_482.stringValue.getValue(id, param);
		break;
	case 482:
		return _game_design.Enemy_design.SheetBattle_483.stringValue.getValue(id, param);
		break;
	case 483:
		return _game_design.Enemy_design.SheetBattle_484.stringValue.getValue(id, param);
		break;
	case 484:
		return _game_design.Enemy_design.SheetBattle_485.stringValue.getValue(id, param);
		break;
	case 485:
		return _game_design.Enemy_design.SheetBattle_486.stringValue.getValue(id, param);
		break;
	case 486:
		return _game_design.Enemy_design.SheetBattle_487.stringValue.getValue(id, param);
		break;
	case 487:
		return _game_design.Enemy_design.SheetBattle_488.stringValue.getValue(id, param);
		break;
	case 488:
		return _game_design.Enemy_design.SheetBattle_489.stringValue.getValue(id, param);
		break;
	case 489:
		return _game_design.Enemy_design.SheetBattle_490.stringValue.getValue(id, param);
		break;
	case 490:
		return _game_design.Enemy_design.SheetBattle_491.stringValue.getValue(id, param);
		break;
	case 491:
		return _game_design.Enemy_design.SheetBattle_492.stringValue.getValue(id, param);
		break;
	case 492:
		return _game_design.Enemy_design.SheetBattle_493.stringValue.getValue(id, param);
		break;
	case 493:
		return _game_design.Enemy_design.SheetBattle_494.stringValue.getValue(id, param);
		break;
	case 494:
		return _game_design.Enemy_design.SheetBattle_495.stringValue.getValue(id, param);
		break;
	case 495:
		return _game_design.Enemy_design.SheetBattle_496.stringValue.getValue(id, param);
		break;
	case 496:
		return _game_design.Enemy_design.SheetBattle_497.stringValue.getValue(id, param);
		break;
	case 497:
		return _game_design.Enemy_design.SheetBattle_498.stringValue.getValue(id, param);
		break;
	case 498:
		return _game_design.Enemy_design.SheetBattle_499.stringValue.getValue(id, param);
		break;
	case 499:
		return _game_design.Enemy_design.SheetBattle_500.stringValue.getValue(id, param);
		break;
	default:
		return _game_design.Enemy_design.SheetBattle_500.stringValue.getValue(id, param);
		break;
	}
}

int TDGame::GetDesignGeneralInfo(int id)
{
	int param = CGameDesign::FileGeneral::CSheetGeneral_design::value;
	return _game_design.General.SheetGeneral_design.int32Value.getValue(id, param);
}
int TDGame::GetDesignHeroGeneral(int id, int param)
{
	return _game_design.Hero_design.SheetHero_General.int32Value.getValue(id, param);
}
float TDGame::GetDesignHeroGeneralFloat(int id, int param)
{
	return _game_design.Hero_design.SheetHero_General.floatValue.getValue(id, param);
}
int TDGame::GetDesignHeroIndex(int id)
{
	int total = _game_design.Hero_design.SheetHero_General.int32Value._totalData;
	int index = 0;
	for (int i = 0; i < total;i++)
	{
		int paramid = CGameDesign::FileHero_design::CSheetHero_General::ID_Hero;
		int heroid = GetDesignHeroGeneral(i, paramid);
		if (heroid == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
const char* TDGame::GetDesignHeroName(int id)
{
	int param = CGameDesign::FileHero_design::CSheetHero_General::Name;
	return _game_design.Hero_design.SheetHero_General.stringValue.getValue(id, param);
}
float TDGame::GetDesignHeroFormulaFloat(int id, int level)
{
	int param = CGameDesign::FileHero_design::CSheetArcher::Formula;
	switch (id)
	{
	case HERO_ID_PALADIN:
		return _game_design.Hero_design.SheetPaladin.floatValue.getValue(level, param);
		break;
	case HERO_ID_ARCHER:
		return _game_design.Hero_design.SheetArcher.floatValue.getValue(level, param);
		break;
	case HERO_ID_FIRE_MAGE:
		return _game_design.Hero_design.SheetFire_Mage.floatValue.getValue(level, param);
		break;
	case HERO_ID_ELECTRIC_MAGE:
		return _game_design.Hero_design.SheetElecitric_Mage.floatValue.getValue(level, param);
		break;
	case HERO_ID_BEAST_MASTER:
		return _game_design.Hero_design.SheetBeast_Master.floatValue.getValue(level, param);
		break;
	case HERO_ID_WOLF_RANGER:
		return _game_design.Hero_design.SheetWolf_Ranger.floatValue.getValue(level, param);
		break;
	case HERO_ID_ACHEMIST:
		return _game_design.Hero_design.SheetAchemist.floatValue.getValue(level, param);
		break;
	case HERO_ID_ROBOT:
		return _game_design.Hero_design.SheetRobot.floatValue.getValue(level, param);
		break;
	case HERO_ID_CAT_NINJA:
		return _game_design.Hero_design.SheetCat_Ninja.floatValue.getValue(level, param);
		break;
	case HERO_ID_SANTA:
		return _game_design.Hero_design.SheetSanta.floatValue.getValue(level, param);
		break;
	default:
		printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
		return _game_design.Hero_design.SheetPaladin.floatValue.getValue(level, param);
		break;
	}
}
INT_TIME TDGame::GetDesignHeroInfo(int id, int level, int param, int rarity)
{
	level--;
	if (level >= _game_design.Hero_design.SheetPaladin.int32Value._totalData)
	{
		return 0;
	}
	if (rarity == 1)
	{
		switch (id)
		{
		case HERO_ID_PALADIN:
			return _game_design.Hero_design.SheetPaladin.int32Value.getValue(level, param);
			break;
		case HERO_ID_ARCHER:
			return _game_design.Hero_design.SheetArcher.int32Value.getValue(level, param);
			break;
		case HERO_ID_FIRE_MAGE:
			return _game_design.Hero_design.SheetFire_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_ELECTRIC_MAGE:
			return _game_design.Hero_design.SheetElecitric_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_BEAST_MASTER:
			return _game_design.Hero_design.SheetBeast_Master.int32Value.getValue(level, param);
			break;
		case HERO_ID_WOLF_RANGER:
			return _game_design.Hero_design.SheetWolf_Ranger.int32Value.getValue(level, param);
			break;
		case HERO_ID_ACHEMIST:
			return _game_design.Hero_design.SheetAchemist.int32Value.getValue(level, param);
			break;
		case HERO_ID_ROBOT:
			return _game_design.Hero_design.SheetRobot.int32Value.getValue(level, param);
			break;
		case HERO_ID_CAT_NINJA:
			return _game_design.Hero_design.SheetCat_Ninja.int32Value.getValue(level, param);
			break;
		case HERO_ID_SANTA:
			return _game_design.Hero_design.SheetSanta.int32Value.getValue(level, param);
			break;
		default:
			printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
			return _game_design.Hero_design.SheetPaladin.int32Value.getValue(level, param);
			break;
		}
	}
	else if (rarity == 2)
	{
		switch (id)
		{
		case HERO_ID_PALADIN:
			return _game_design.Hero_design.SheetPaladin_2.int32Value.getValue(level, param);
			break;
		case HERO_ID_ARCHER:
			return _game_design.Hero_design.SheetArcher.int32Value.getValue(level, param);
			break;
		case HERO_ID_FIRE_MAGE:
			return _game_design.Hero_design.SheetFire_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_ELECTRIC_MAGE:
			return _game_design.Hero_design.SheetElecitric_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_BEAST_MASTER:
			return _game_design.Hero_design.SheetBeast_Master.int32Value.getValue(level, param);
			break;
		case HERO_ID_WOLF_RANGER:
			return _game_design.Hero_design.SheetWolf_Ranger.int32Value.getValue(level, param);
			break;
		case HERO_ID_ACHEMIST:
			return _game_design.Hero_design.SheetAchemist.int32Value.getValue(level, param);
			break;
		case HERO_ID_ROBOT:
			return _game_design.Hero_design.SheetRobot.int32Value.getValue(level, param);
			break;
		case HERO_ID_CAT_NINJA:
			return _game_design.Hero_design.SheetCat_Ninja.int32Value.getValue(level, param);
			break;
		case HERO_ID_SANTA:
			return _game_design.Hero_design.SheetSanta.int32Value.getValue(level, param);
			break;
		default:
			printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
			return _game_design.Hero_design.SheetPaladin_2.int32Value.getValue(level, param);
			break;
		}
	}
	else if (rarity == 3)
	{
		switch (id)
		{
		case HERO_ID_PALADIN:
			return _game_design.Hero_design.SheetPaladin_3.int32Value.getValue(level, param);
			break;
		case HERO_ID_ARCHER:
			return _game_design.Hero_design.SheetArcher_3.int32Value.getValue(level, param);
			break;
		case HERO_ID_FIRE_MAGE:
			return _game_design.Hero_design.SheetFire_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_ELECTRIC_MAGE:
			return _game_design.Hero_design.SheetElecitric_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_BEAST_MASTER:
			return _game_design.Hero_design.SheetBeast_Master.int32Value.getValue(level, param);
			break;
		case HERO_ID_WOLF_RANGER:
			return _game_design.Hero_design.SheetWolf_Ranger.int32Value.getValue(level, param);
			break;
		case HERO_ID_ACHEMIST:
			return _game_design.Hero_design.SheetAchemist.int32Value.getValue(level, param);
			break;
		case HERO_ID_ROBOT:
			return _game_design.Hero_design.SheetRobot.int32Value.getValue(level, param);
			break;
		case HERO_ID_CAT_NINJA:
			return _game_design.Hero_design.SheetCat_Ninja.int32Value.getValue(level, param);
			break;
		case HERO_ID_SANTA:
			return _game_design.Hero_design.SheetSanta.int32Value.getValue(level, param);
			break;
		default:
			printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
			return _game_design.Hero_design.SheetPaladin_3.int32Value.getValue(level, param);
			break;
		}
	}
	else if (rarity == 4)
	{
		switch (id)
		{
		case HERO_ID_PALADIN:
			return _game_design.Hero_design.SheetPaladin_4.int32Value.getValue(level, param);
			break;
		case HERO_ID_ARCHER:
			return _game_design.Hero_design.SheetArcher_4.int32Value.getValue(level, param);
			break;
		case HERO_ID_FIRE_MAGE:
			return _game_design.Hero_design.SheetFire_Mage_4.int32Value.getValue(level, param);
			break;
		case HERO_ID_ELECTRIC_MAGE:
			return _game_design.Hero_design.SheetElecitric_Mage.int32Value.getValue(level, param);
			break;
		case HERO_ID_BEAST_MASTER:
			return _game_design.Hero_design.SheetBeast_Master_4.int32Value.getValue(level, param);
			break;
		case HERO_ID_WOLF_RANGER:
			return _game_design.Hero_design.SheetWolf_Ranger.int32Value.getValue(level, param);
			break;
		case HERO_ID_ACHEMIST:
			return _game_design.Hero_design.SheetAchemist.int32Value.getValue(level, param);
			break;
		case HERO_ID_ROBOT:
			return _game_design.Hero_design.SheetRobot.int32Value.getValue(level, param);
			break;
		case HERO_ID_CAT_NINJA:
			return _game_design.Hero_design.SheetCat_Ninja.int32Value.getValue(level, param);
			break;
		case HERO_ID_SANTA:
			return _game_design.Hero_design.SheetSanta.int32Value.getValue(level, param);
			break;
		default:
			printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
			return _game_design.Hero_design.SheetPaladin_4.int32Value.getValue(level, param);
			break;
		}
	}
	else//5
	{
		switch (id)
		{
		case HERO_ID_PALADIN:
			return _game_design.Hero_design.SheetPaladin_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_ARCHER:
			return _game_design.Hero_design.SheetArcher_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_FIRE_MAGE:
			return _game_design.Hero_design.SheetFire_Mage_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_ELECTRIC_MAGE:
			return _game_design.Hero_design.SheetElecitric_Mage_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_BEAST_MASTER:
			return _game_design.Hero_design.SheetBeast_Master_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_WOLF_RANGER:
			return _game_design.Hero_design.SheetWolf_Ranger_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_ACHEMIST:
			return _game_design.Hero_design.SheetAchemist.int32Value.getValue(level, param);
			break;
		case HERO_ID_ROBOT:
			return _game_design.Hero_design.SheetRobot.int32Value.getValue(level, param);
			break;
		case HERO_ID_CAT_NINJA:
			return _game_design.Hero_design.SheetCat_Ninja_5.int32Value.getValue(level, param);
			break;
		case HERO_ID_SANTA:
			return _game_design.Hero_design.SheetSanta.int32Value.getValue(level, param);
			break;
		default:
			printf("\n\n\n\n\n defaut info hero \n\n\n\n\n");
			return _game_design.Hero_design.SheetPaladin_5.int32Value.getValue(level, param);
			break;
		}
	}
}

int TDGame::GetEnemyCreationIndex(const char* enemyID)
{
	char temp[10];
	int total = _game_design.Enemy_Creation.SheetEnemy_Design.int32Value._totalData;
	int param_id = CGameDesign::FileEnemy_Creation::CSheetEnemy_Design::Enemy_ID;
	int enemyid = -1;
	for (int i = 0; i < total; i++)
	{
		sprintf(temp, "%s", GetDesignEnemyCreationString(i,param_id));
		//printf("\n temp = %s <> enemyID = %s", temp, enemyID);
		if (strcmp(temp, enemyID) == 0)
		{
			enemyid = i;
		}
	}
	return enemyid;
}

int TDGame::GetNumEnemyInWave(int battle, int wave)
{
	int num_data = 0;
	_row_start_inwave = -1;
	int total = _game_design.Enemy_design.SheetBattle_1.int32Value._totalData;
	int param_wave = CGameDesign::FileEnemy_design::CSheetBattle_1::Wave;
#if GAME_DEBUG
#if define MAC_OS
#else
	battle = GAME_DEBUG_BATTLE_FIX - 1;
#endif
#endif
	switch (battle)
	{
	case 0:
		total = _game_design.Enemy_design.SheetBattle_1.int32Value._totalData;
		break;
	case 1:
		total = _game_design.Enemy_design.SheetBattle_2.int32Value._totalData;
		break;
	case 2:
		total = _game_design.Enemy_design.SheetBattle_3.int32Value._totalData;
		break;
	case 3:
		total = _game_design.Enemy_design.SheetBattle_4.int32Value._totalData;
		break;
	case 4:
		total = _game_design.Enemy_design.SheetBattle_5.int32Value._totalData;
		break;
	case 5:
		total = _game_design.Enemy_design.SheetBattle_6.int32Value._totalData;
		break;
	case 6:
		total = _game_design.Enemy_design.SheetBattle_7.int32Value._totalData;
		break;
	case 7:
		total = _game_design.Enemy_design.SheetBattle_8.int32Value._totalData;
		break;
	case 8:
		total = _game_design.Enemy_design.SheetBattle_9.int32Value._totalData;
		break;
	case 9:
		total = _game_design.Enemy_design.SheetBattle_10.int32Value._totalData;
		break;
	case 10:
		total = _game_design.Enemy_design.SheetBattle_11.int32Value._totalData;
		break;
	case 11:
		total = _game_design.Enemy_design.SheetBattle_12.int32Value._totalData;
		break;
	case 12:
		total = _game_design.Enemy_design.SheetBattle_13.int32Value._totalData;
		break;
	case 13:
		total = _game_design.Enemy_design.SheetBattle_14.int32Value._totalData;
		break;
	case 14:
		total = _game_design.Enemy_design.SheetBattle_15.int32Value._totalData;
		break;
	case 15:
		total = _game_design.Enemy_design.SheetBattle_16.int32Value._totalData;
		break;
	case 16:
		total = _game_design.Enemy_design.SheetBattle_17.int32Value._totalData;
		break;
	case 17:
		total = _game_design.Enemy_design.SheetBattle_18.int32Value._totalData;
		break;
	case 18:
		total = _game_design.Enemy_design.SheetBattle_19.int32Value._totalData;
		break;
	case 19:
		total = _game_design.Enemy_design.SheetBattle_20.int32Value._totalData;
		break;
	case 20:
		total = _game_design.Enemy_design.SheetBattle_21.int32Value._totalData;
		break;
	case 21:
		total = _game_design.Enemy_design.SheetBattle_22.int32Value._totalData;
		break;
	case 22:
		total = _game_design.Enemy_design.SheetBattle_23.int32Value._totalData;
		break;
	case 23:
		total = _game_design.Enemy_design.SheetBattle_24.int32Value._totalData;
		break;
	case 24:
		total = _game_design.Enemy_design.SheetBattle_25.int32Value._totalData;
		break;
	case 25:
		total = _game_design.Enemy_design.SheetBattle_26.int32Value._totalData;
		break;
	case 26:
		total = _game_design.Enemy_design.SheetBattle_27.int32Value._totalData;
		break;
	case 27:
		total = _game_design.Enemy_design.SheetBattle_28.int32Value._totalData;
		break;
	case 28:
		total = _game_design.Enemy_design.SheetBattle_29.int32Value._totalData;
		break;
	case 29:
		total = _game_design.Enemy_design.SheetBattle_30.int32Value._totalData;
		break;
	case 30:
		total = _game_design.Enemy_design.SheetBattle_31.int32Value._totalData;
		break;
	case 31:
		total = _game_design.Enemy_design.SheetBattle_32.int32Value._totalData;
		break;
	case 32:
		total = _game_design.Enemy_design.SheetBattle_33.int32Value._totalData;
		break;
	case 33:
		total = _game_design.Enemy_design.SheetBattle_34.int32Value._totalData;
		break;
	case 34:
		total = _game_design.Enemy_design.SheetBattle_35.int32Value._totalData;
		break;
	case 35:
		total = _game_design.Enemy_design.SheetBattle_36.int32Value._totalData;
		break;
	case 36:
		total = _game_design.Enemy_design.SheetBattle_37.int32Value._totalData;
		break;
	case 37:
		total = _game_design.Enemy_design.SheetBattle_38.int32Value._totalData;
		break;
	case 38:
		total = _game_design.Enemy_design.SheetBattle_39.int32Value._totalData;
		break;
	case 39:
		total = _game_design.Enemy_design.SheetBattle_30.int32Value._totalData;
		break;
	case 40:
		total = _game_design.Enemy_design.SheetBattle_41.int32Value._totalData;
		break;
	case 41:
		total = _game_design.Enemy_design.SheetBattle_42.int32Value._totalData;
		break;
	case 42:
		total = _game_design.Enemy_design.SheetBattle_43.int32Value._totalData;
		break;
	case 43:
		total = _game_design.Enemy_design.SheetBattle_44.int32Value._totalData;
		break;
	case 44:
		total = _game_design.Enemy_design.SheetBattle_45.int32Value._totalData;
		break;
	case 45:
		total = _game_design.Enemy_design.SheetBattle_46.int32Value._totalData;
		break;
	case 46:
		total = _game_design.Enemy_design.SheetBattle_47.int32Value._totalData;
		break;
	case 47:
		total = _game_design.Enemy_design.SheetBattle_48.int32Value._totalData;
		break;
	case 48:
		total = _game_design.Enemy_design.SheetBattle_49.int32Value._totalData;
		break;
	case 49:
		total = _game_design.Enemy_design.SheetBattle_50.int32Value._totalData;
		break;
	case 50:
		total = _game_design.Enemy_design.SheetBattle_51.int32Value._totalData;
		break;
	case 51:
		total = _game_design.Enemy_design.SheetBattle_52.int32Value._totalData;
		break;
	case 52:
		total = _game_design.Enemy_design.SheetBattle_53.int32Value._totalData;
		break;
	case 53:
		total = _game_design.Enemy_design.SheetBattle_54.int32Value._totalData;
		break;
	case 54:
		total = _game_design.Enemy_design.SheetBattle_55.int32Value._totalData;
		break;
	case 55:
		total = _game_design.Enemy_design.SheetBattle_56.int32Value._totalData;
		break;
	case 56:
		total = _game_design.Enemy_design.SheetBattle_57.int32Value._totalData;
		break;
	case 57:
		total = _game_design.Enemy_design.SheetBattle_58.int32Value._totalData;
		break;
	case 58:
		total = _game_design.Enemy_design.SheetBattle_59.int32Value._totalData;
		break;
	case 59:
		total = _game_design.Enemy_design.SheetBattle_60.int32Value._totalData;
		break;
	case 60:
		total = _game_design.Enemy_design.SheetBattle_61.int32Value._totalData;
		break;
	case 61:
		total = _game_design.Enemy_design.SheetBattle_62.int32Value._totalData;
		break;
	case 62:
		total = _game_design.Enemy_design.SheetBattle_63.int32Value._totalData;
		break;
	case 63:
		total = _game_design.Enemy_design.SheetBattle_64.int32Value._totalData;
		break;
	case 64:
		total = _game_design.Enemy_design.SheetBattle_65.int32Value._totalData;
		break;
	case 65:
		total = _game_design.Enemy_design.SheetBattle_66.int32Value._totalData;
		break;
	case 66:
		total = _game_design.Enemy_design.SheetBattle_67.int32Value._totalData;
		break;
	case 67:
		total = _game_design.Enemy_design.SheetBattle_68.int32Value._totalData;
		break;
	case 68:
		total = _game_design.Enemy_design.SheetBattle_69.int32Value._totalData;
		break;
	case 69:
		total = _game_design.Enemy_design.SheetBattle_70.int32Value._totalData;
		break;
	case 70:
		total = _game_design.Enemy_design.SheetBattle_71.int32Value._totalData;
		break;
	case 71:
		total = _game_design.Enemy_design.SheetBattle_72.int32Value._totalData;
		break;
	case 72:
		total = _game_design.Enemy_design.SheetBattle_73.int32Value._totalData;
		break;
	case 73:
		total = _game_design.Enemy_design.SheetBattle_74.int32Value._totalData;
		break;
	case 74:
		total = _game_design.Enemy_design.SheetBattle_75.int32Value._totalData;
		break;
	case 75:
		total = _game_design.Enemy_design.SheetBattle_76.int32Value._totalData;
		break;
	case 76:
		total = _game_design.Enemy_design.SheetBattle_77.int32Value._totalData;
		break;
	case 77:
		total = _game_design.Enemy_design.SheetBattle_78.int32Value._totalData;
		break;
	case 78:
		total = _game_design.Enemy_design.SheetBattle_79.int32Value._totalData;
		break;
	case 79:
		total = _game_design.Enemy_design.SheetBattle_80.int32Value._totalData;
		break;
	case 80:
		total = _game_design.Enemy_design.SheetBattle_81.int32Value._totalData;
		break;
	case 81:
		total = _game_design.Enemy_design.SheetBattle_82.int32Value._totalData;
		break;
	case 82:
		total = _game_design.Enemy_design.SheetBattle_83.int32Value._totalData;
		break;
	case 83:
		total = _game_design.Enemy_design.SheetBattle_84.int32Value._totalData;
		break;
	case 84:
		total = _game_design.Enemy_design.SheetBattle_85.int32Value._totalData;
		break;
	case 85:
		total = _game_design.Enemy_design.SheetBattle_86.int32Value._totalData;
		break;
	case 86:
		total = _game_design.Enemy_design.SheetBattle_87.int32Value._totalData;
		break;
	case 87:
		total = _game_design.Enemy_design.SheetBattle_88.int32Value._totalData;
		break;
	case 88:
		total = _game_design.Enemy_design.SheetBattle_89.int32Value._totalData;
		break;
	case 89:
		total = _game_design.Enemy_design.SheetBattle_90.int32Value._totalData;
		break;
	case 90:
		total = _game_design.Enemy_design.SheetBattle_91.int32Value._totalData;
		break;
	case 91:
		total = _game_design.Enemy_design.SheetBattle_92.int32Value._totalData;
		break;
	case 92:
		total = _game_design.Enemy_design.SheetBattle_93.int32Value._totalData;
		break;
	case 93:
		total = _game_design.Enemy_design.SheetBattle_94.int32Value._totalData;
		break;
	case 94:
		total = _game_design.Enemy_design.SheetBattle_95.int32Value._totalData;
		break;
	case 95:
		total = _game_design.Enemy_design.SheetBattle_96.int32Value._totalData;
		break;
	case 96:
		total = _game_design.Enemy_design.SheetBattle_97.int32Value._totalData;
		break;
	case 97:
		total = _game_design.Enemy_design.SheetBattle_98.int32Value._totalData;
		break;
	case 98:
		total = _game_design.Enemy_design.SheetBattle_99.int32Value._totalData;
		break;
	case 99:
		total = _game_design.Enemy_design.SheetBattle_100.int32Value._totalData;
		break;
	case 100:
		total = _game_design.Enemy_design.SheetBattle_101.int32Value._totalData;
		break;
	case 101:
		total = _game_design.Enemy_design.SheetBattle_102.int32Value._totalData;
		break;
	case 102:
		total = _game_design.Enemy_design.SheetBattle_103.int32Value._totalData;
		break;
	case 103:
		total = _game_design.Enemy_design.SheetBattle_104.int32Value._totalData;
		break;
	case 104:
		total = _game_design.Enemy_design.SheetBattle_105.int32Value._totalData;
		break;
	case 105:
		total = _game_design.Enemy_design.SheetBattle_106.int32Value._totalData;
		break;
	case 106:
		total = _game_design.Enemy_design.SheetBattle_107.int32Value._totalData;
		break;
	case 107:
		total = _game_design.Enemy_design.SheetBattle_108.int32Value._totalData;
		break;
	case 108:
		total = _game_design.Enemy_design.SheetBattle_109.int32Value._totalData;
		break;
	case 109:
		total = _game_design.Enemy_design.SheetBattle_110.int32Value._totalData;
		break;
	case 110:
		total = _game_design.Enemy_design.SheetBattle_111.int32Value._totalData;
		break;
	case 111:
		total = _game_design.Enemy_design.SheetBattle_112.int32Value._totalData;
		break;
	case 112:
		total = _game_design.Enemy_design.SheetBattle_113.int32Value._totalData;
		break;
	case 113:
		total = _game_design.Enemy_design.SheetBattle_114.int32Value._totalData;
		break;
	case 114:
		total = _game_design.Enemy_design.SheetBattle_115.int32Value._totalData;
		break;
	case 115:
		total = _game_design.Enemy_design.SheetBattle_116.int32Value._totalData;
		break;
	case 116:
		total = _game_design.Enemy_design.SheetBattle_117.int32Value._totalData;
		break;
	case 117:
		total = _game_design.Enemy_design.SheetBattle_118.int32Value._totalData;
		break;
	case 118:
		total = _game_design.Enemy_design.SheetBattle_119.int32Value._totalData;
		break;
	case 119:
		total = _game_design.Enemy_design.SheetBattle_120.int32Value._totalData;
		break;
	case 120:
		total = _game_design.Enemy_design.SheetBattle_121.int32Value._totalData;
		break;
	case 121:
		total = _game_design.Enemy_design.SheetBattle_122.int32Value._totalData;
		break;
	case 122:
		total = _game_design.Enemy_design.SheetBattle_123.int32Value._totalData;
		break;
	case 123:
		total = _game_design.Enemy_design.SheetBattle_124.int32Value._totalData;
		break;
	case 124:
		total = _game_design.Enemy_design.SheetBattle_125.int32Value._totalData;
		break;
	case 125:
		total = _game_design.Enemy_design.SheetBattle_126.int32Value._totalData;
		break;
	case 126:
		total = _game_design.Enemy_design.SheetBattle_127.int32Value._totalData;
		break;
	case 127:
		total = _game_design.Enemy_design.SheetBattle_128.int32Value._totalData;
		break;
	case 128:
		total = _game_design.Enemy_design.SheetBattle_129.int32Value._totalData;
		break;
	case 129:
		total = _game_design.Enemy_design.SheetBattle_130.int32Value._totalData;
		break;
	case 130:
		total = _game_design.Enemy_design.SheetBattle_131.int32Value._totalData;
		break;
	case 131:
		total = _game_design.Enemy_design.SheetBattle_132.int32Value._totalData;
		break;
	case 132:
		total = _game_design.Enemy_design.SheetBattle_133.int32Value._totalData;
		break;
	case 133:
		total = _game_design.Enemy_design.SheetBattle_134.int32Value._totalData;
		break;
	case 134:
		total = _game_design.Enemy_design.SheetBattle_135.int32Value._totalData;
		break;
	case 135:
		total = _game_design.Enemy_design.SheetBattle_136.int32Value._totalData;
		break;
	case 136:
		total = _game_design.Enemy_design.SheetBattle_137.int32Value._totalData;
		break;
	case 137:
		total = _game_design.Enemy_design.SheetBattle_138.int32Value._totalData;
		break;
	case 138:
		total = _game_design.Enemy_design.SheetBattle_139.int32Value._totalData;
		break;
	case 139:
		total = _game_design.Enemy_design.SheetBattle_140.int32Value._totalData;
		break;
	case 140:
		total = _game_design.Enemy_design.SheetBattle_141.int32Value._totalData;
		break;
	case 141:
		total = _game_design.Enemy_design.SheetBattle_142.int32Value._totalData;
		break;
	case 142:
		total = _game_design.Enemy_design.SheetBattle_143.int32Value._totalData;
		break;
	case 143:
		total = _game_design.Enemy_design.SheetBattle_144.int32Value._totalData;
		break;
	case 144:
		total = _game_design.Enemy_design.SheetBattle_145.int32Value._totalData;
		break;
	case 145:
		total = _game_design.Enemy_design.SheetBattle_146.int32Value._totalData;
		break;
	case 146:
		total = _game_design.Enemy_design.SheetBattle_147.int32Value._totalData;
		break;
	case 147:
		total = _game_design.Enemy_design.SheetBattle_148.int32Value._totalData;
		break;
	case 148:
		total = _game_design.Enemy_design.SheetBattle_149.int32Value._totalData;
		break;
	case 149:
		total = _game_design.Enemy_design.SheetBattle_150.int32Value._totalData;
		break;
	case 150:
		total = _game_design.Enemy_design.SheetBattle_151.int32Value._totalData;
		break;
	case 151:
		total = _game_design.Enemy_design.SheetBattle_152.int32Value._totalData;
		break;
	case 152:
		total = _game_design.Enemy_design.SheetBattle_153.int32Value._totalData;
		break;
	case 153:
		total = _game_design.Enemy_design.SheetBattle_154.int32Value._totalData;
		break;
	case 154:
		total = _game_design.Enemy_design.SheetBattle_155.int32Value._totalData;
		break;
	case 155:
		total = _game_design.Enemy_design.SheetBattle_156.int32Value._totalData;
		break;
	case 156:
		total = _game_design.Enemy_design.SheetBattle_157.int32Value._totalData;
		break;
	case 157:
		total = _game_design.Enemy_design.SheetBattle_158.int32Value._totalData;
		break;
	case 158:
		total = _game_design.Enemy_design.SheetBattle_159.int32Value._totalData;
		break;
	case 159:
		total = _game_design.Enemy_design.SheetBattle_160.int32Value._totalData;
		break;
	case 160:
		total = _game_design.Enemy_design.SheetBattle_161.int32Value._totalData;
		break;
	case 161:
		total = _game_design.Enemy_design.SheetBattle_162.int32Value._totalData;
		break;
	case 162:
		total = _game_design.Enemy_design.SheetBattle_163.int32Value._totalData;
		break;
	case 163:
		total = _game_design.Enemy_design.SheetBattle_164.int32Value._totalData;
		break;
	case 164:
		total = _game_design.Enemy_design.SheetBattle_165.int32Value._totalData;
		break;
	case 165:
		total = _game_design.Enemy_design.SheetBattle_166.int32Value._totalData;
		break;
	case 166:
		total = _game_design.Enemy_design.SheetBattle_167.int32Value._totalData;
		break;
	case 167:
		total = _game_design.Enemy_design.SheetBattle_168.int32Value._totalData;
		break;
	case 168:
		total = _game_design.Enemy_design.SheetBattle_169.int32Value._totalData;
		break;
	case 169:
		total = _game_design.Enemy_design.SheetBattle_170.int32Value._totalData;
		break;
	case 170:
		total = _game_design.Enemy_design.SheetBattle_171.int32Value._totalData;
		break;
	case 171:
		total = _game_design.Enemy_design.SheetBattle_172.int32Value._totalData;
		break;
	case 172:
		total = _game_design.Enemy_design.SheetBattle_173.int32Value._totalData;
		break;
	case 173:
		total = _game_design.Enemy_design.SheetBattle_174.int32Value._totalData;
		break;
	case 174:
		total = _game_design.Enemy_design.SheetBattle_175.int32Value._totalData;
		break;
	case 175:
		total = _game_design.Enemy_design.SheetBattle_176.int32Value._totalData;
		break;
	case 176:
		total = _game_design.Enemy_design.SheetBattle_177.int32Value._totalData;
		break;
	case 177:
		total = _game_design.Enemy_design.SheetBattle_178.int32Value._totalData;
		break;
	case 178:
		total = _game_design.Enemy_design.SheetBattle_179.int32Value._totalData;
		break;
	case 179:
		total = _game_design.Enemy_design.SheetBattle_180.int32Value._totalData;
		break;
	case 180:
		total = _game_design.Enemy_design.SheetBattle_181.int32Value._totalData;
		break;
	case 181:
		total = _game_design.Enemy_design.SheetBattle_182.int32Value._totalData;
		break;
	case 182:
		total = _game_design.Enemy_design.SheetBattle_183.int32Value._totalData;
		break;
	case 183:
		total = _game_design.Enemy_design.SheetBattle_184.int32Value._totalData;
		break;
	case 184:
		total = _game_design.Enemy_design.SheetBattle_185.int32Value._totalData;
		break;
	case 185:
		total = _game_design.Enemy_design.SheetBattle_186.int32Value._totalData;
		break;
	case 186:
		total = _game_design.Enemy_design.SheetBattle_187.int32Value._totalData;
		break;
	case 187:
		total = _game_design.Enemy_design.SheetBattle_188.int32Value._totalData;
		break;
	case 188:
		total = _game_design.Enemy_design.SheetBattle_189.int32Value._totalData;
		break;
	case 189:
		total = _game_design.Enemy_design.SheetBattle_190.int32Value._totalData;
		break;
	case 190:
		total = _game_design.Enemy_design.SheetBattle_191.int32Value._totalData;
		break;
	case 191:
		total = _game_design.Enemy_design.SheetBattle_192.int32Value._totalData;
		break;
	case 192:
		total = _game_design.Enemy_design.SheetBattle_193.int32Value._totalData;
		break;
	case 193:
		total = _game_design.Enemy_design.SheetBattle_194.int32Value._totalData;
		break;
	case 194:
		total = _game_design.Enemy_design.SheetBattle_195.int32Value._totalData;
		break;
	case 195:
		total = _game_design.Enemy_design.SheetBattle_196.int32Value._totalData;
		break;
	case 196:
		total = _game_design.Enemy_design.SheetBattle_197.int32Value._totalData;
		break;
	case 197:
		total = _game_design.Enemy_design.SheetBattle_198.int32Value._totalData;
		break;
	case 198:
		total = _game_design.Enemy_design.SheetBattle_199.int32Value._totalData;
		break;
	case 199:
		total = _game_design.Enemy_design.SheetBattle_200.int32Value._totalData;
		break;
	case 200:
		total = _game_design.Enemy_design.SheetBattle_201.int32Value._totalData;
		break;
	case 201:
		total = _game_design.Enemy_design.SheetBattle_202.int32Value._totalData;
		break;
	case 202:
		total = _game_design.Enemy_design.SheetBattle_203.int32Value._totalData;
		break;
	case 203:
		total = _game_design.Enemy_design.SheetBattle_204.int32Value._totalData;
		break;
	case 204:
		total = _game_design.Enemy_design.SheetBattle_205.int32Value._totalData;
		break;
	case 205:
		total = _game_design.Enemy_design.SheetBattle_206.int32Value._totalData;
		break;
	case 206:
		total = _game_design.Enemy_design.SheetBattle_207.int32Value._totalData;
		break;
	case 207:
		total = _game_design.Enemy_design.SheetBattle_208.int32Value._totalData;
		break;
	case 208:
		total = _game_design.Enemy_design.SheetBattle_209.int32Value._totalData;
		break;
	case 209:
		total = _game_design.Enemy_design.SheetBattle_210.int32Value._totalData;
		break;
	case 210:
		total = _game_design.Enemy_design.SheetBattle_211.int32Value._totalData;
		break;
	case 211:
		total = _game_design.Enemy_design.SheetBattle_212.int32Value._totalData;
		break;
	case 212:
		total = _game_design.Enemy_design.SheetBattle_213.int32Value._totalData;
		break;
	case 213:
		total = _game_design.Enemy_design.SheetBattle_214.int32Value._totalData;
		break;
	case 214:
		total = _game_design.Enemy_design.SheetBattle_215.int32Value._totalData;
		break;
	case 215:
		total = _game_design.Enemy_design.SheetBattle_216.int32Value._totalData;
		break;
	case 216:
		total = _game_design.Enemy_design.SheetBattle_217.int32Value._totalData;
		break;
	case 217:
		total = _game_design.Enemy_design.SheetBattle_218.int32Value._totalData;
		break;
	case 218:
		total = _game_design.Enemy_design.SheetBattle_219.int32Value._totalData;
		break;
	case 219:
		total = _game_design.Enemy_design.SheetBattle_220.int32Value._totalData;
		break;
	case 220:
		total = _game_design.Enemy_design.SheetBattle_221.int32Value._totalData;
		break;
	case 221:
		total = _game_design.Enemy_design.SheetBattle_222.int32Value._totalData;
		break;
	case 222:
		total = _game_design.Enemy_design.SheetBattle_223.int32Value._totalData;
		break;
	case 223:
		total = _game_design.Enemy_design.SheetBattle_224.int32Value._totalData;
		break;
	case 224:
		total = _game_design.Enemy_design.SheetBattle_225.int32Value._totalData;
		break;
	case 225:
		total = _game_design.Enemy_design.SheetBattle_226.int32Value._totalData;
		break;
	case 226:
		total = _game_design.Enemy_design.SheetBattle_227.int32Value._totalData;
		break;
	case 227:
		total = _game_design.Enemy_design.SheetBattle_228.int32Value._totalData;
		break;
	case 228:
		total = _game_design.Enemy_design.SheetBattle_229.int32Value._totalData;
		break;
	case 229:
		total = _game_design.Enemy_design.SheetBattle_230.int32Value._totalData;
		break;
	case 230:
		total = _game_design.Enemy_design.SheetBattle_231.int32Value._totalData;
		break;
	case 231:
		total = _game_design.Enemy_design.SheetBattle_232.int32Value._totalData;
		break;
	case 232:
		total = _game_design.Enemy_design.SheetBattle_233.int32Value._totalData;
		break;
	case 233:
		total = _game_design.Enemy_design.SheetBattle_234.int32Value._totalData;
		break;
	case 234:
		total = _game_design.Enemy_design.SheetBattle_235.int32Value._totalData;
		break;
	case 235:
		total = _game_design.Enemy_design.SheetBattle_236.int32Value._totalData;
		break;
	case 236:
		total = _game_design.Enemy_design.SheetBattle_237.int32Value._totalData;
		break;
	case 237:
		total = _game_design.Enemy_design.SheetBattle_238.int32Value._totalData;
		break;
	case 238:
		total = _game_design.Enemy_design.SheetBattle_239.int32Value._totalData;
		break;
	case 239:
		total = _game_design.Enemy_design.SheetBattle_240.int32Value._totalData;
		break;
	case 240:
		total = _game_design.Enemy_design.SheetBattle_241.int32Value._totalData;
		break;
	case 241:
		total = _game_design.Enemy_design.SheetBattle_242.int32Value._totalData;
		break;
	case 242:
		total = _game_design.Enemy_design.SheetBattle_243.int32Value._totalData;
		break;
	case 243:
		total = _game_design.Enemy_design.SheetBattle_244.int32Value._totalData;
		break;
	case 244:
		total = _game_design.Enemy_design.SheetBattle_245.int32Value._totalData;
		break;
	case 245:
		total = _game_design.Enemy_design.SheetBattle_246.int32Value._totalData;
		break;
	case 246:
		total = _game_design.Enemy_design.SheetBattle_247.int32Value._totalData;
		break;
	case 247:
		total = _game_design.Enemy_design.SheetBattle_248.int32Value._totalData;
		break;
	case 248:
		total = _game_design.Enemy_design.SheetBattle_249.int32Value._totalData;
		break;
	case 249:
		total = _game_design.Enemy_design.SheetBattle_250.int32Value._totalData;
		break;
	case 250:
		total = _game_design.Enemy_design.SheetBattle_251.int32Value._totalData;
		break;
	case 251:
		total = _game_design.Enemy_design.SheetBattle_252.int32Value._totalData;
		break;
	case 252:
		total = _game_design.Enemy_design.SheetBattle_253.int32Value._totalData;
		break;
	case 253:
		total = _game_design.Enemy_design.SheetBattle_254.int32Value._totalData;
		break;
	case 254:
		total = _game_design.Enemy_design.SheetBattle_255.int32Value._totalData;
		break;
	case 255:
		total = _game_design.Enemy_design.SheetBattle_256.int32Value._totalData;
		break;
	case 256:
		total = _game_design.Enemy_design.SheetBattle_257.int32Value._totalData;
		break;
	case 257:
		total = _game_design.Enemy_design.SheetBattle_258.int32Value._totalData;
		break;
	case 258:
		total = _game_design.Enemy_design.SheetBattle_259.int32Value._totalData;
		break;
	case 259:
		total = _game_design.Enemy_design.SheetBattle_260.int32Value._totalData;
		break;
	case 260:
		total = _game_design.Enemy_design.SheetBattle_261.int32Value._totalData;
		break;
	case 261:
		total = _game_design.Enemy_design.SheetBattle_262.int32Value._totalData;
		break;
	case 262:
		total = _game_design.Enemy_design.SheetBattle_263.int32Value._totalData;
		break;
	case 263:
		total = _game_design.Enemy_design.SheetBattle_264.int32Value._totalData;
		break;
	case 264:
		total = _game_design.Enemy_design.SheetBattle_265.int32Value._totalData;
		break;
	case 265:
		total = _game_design.Enemy_design.SheetBattle_266.int32Value._totalData;
		break;
	case 266:
		total = _game_design.Enemy_design.SheetBattle_267.int32Value._totalData;
		break;
	case 267:
		total = _game_design.Enemy_design.SheetBattle_268.int32Value._totalData;
		break;
	case 268:
		total = _game_design.Enemy_design.SheetBattle_269.int32Value._totalData;
		break;
	case 269:
		total = _game_design.Enemy_design.SheetBattle_270.int32Value._totalData;
		break;
	case 270:
		total = _game_design.Enemy_design.SheetBattle_271.int32Value._totalData;
		break;
	case 271:
		total = _game_design.Enemy_design.SheetBattle_272.int32Value._totalData;
		break;
	case 272:
		total = _game_design.Enemy_design.SheetBattle_273.int32Value._totalData;
		break;
	case 273:
		total = _game_design.Enemy_design.SheetBattle_274.int32Value._totalData;
		break;
	case 274:
		total = _game_design.Enemy_design.SheetBattle_275.int32Value._totalData;
		break;
	case 275:
		total = _game_design.Enemy_design.SheetBattle_276.int32Value._totalData;
		break;
	case 276:
		total = _game_design.Enemy_design.SheetBattle_277.int32Value._totalData;
		break;
	case 277:
		total = _game_design.Enemy_design.SheetBattle_278.int32Value._totalData;
		break;
	case 278:
		total = _game_design.Enemy_design.SheetBattle_279.int32Value._totalData;
		break;
	case 279:
		total = _game_design.Enemy_design.SheetBattle_280.int32Value._totalData;
		break;
	case 280:
		total = _game_design.Enemy_design.SheetBattle_281.int32Value._totalData;
		break;
	case 281:
		total = _game_design.Enemy_design.SheetBattle_282.int32Value._totalData;
		break;
	case 282:
		total = _game_design.Enemy_design.SheetBattle_283.int32Value._totalData;
		break;
	case 283:
		total = _game_design.Enemy_design.SheetBattle_284.int32Value._totalData;
		break;
	case 284:
		total = _game_design.Enemy_design.SheetBattle_285.int32Value._totalData;
		break;
	case 285:
		total = _game_design.Enemy_design.SheetBattle_286.int32Value._totalData;
		break;
	case 286:
		total = _game_design.Enemy_design.SheetBattle_287.int32Value._totalData;
		break;
	case 287:
		total = _game_design.Enemy_design.SheetBattle_288.int32Value._totalData;
		break;
	case 288:
		total = _game_design.Enemy_design.SheetBattle_289.int32Value._totalData;
		break;
	case 289:
		total = _game_design.Enemy_design.SheetBattle_290.int32Value._totalData;
		break;
	case 290:
		total = _game_design.Enemy_design.SheetBattle_291.int32Value._totalData;
		break;
	case 291:
		total = _game_design.Enemy_design.SheetBattle_292.int32Value._totalData;
		break;
	case 292:
		total = _game_design.Enemy_design.SheetBattle_293.int32Value._totalData;
		break;
	case 293:
		total = _game_design.Enemy_design.SheetBattle_294.int32Value._totalData;
		break;
	case 294:
		total = _game_design.Enemy_design.SheetBattle_295.int32Value._totalData;
		break;
	case 295:
		total = _game_design.Enemy_design.SheetBattle_296.int32Value._totalData;
		break;
	case 296:
		total = _game_design.Enemy_design.SheetBattle_297.int32Value._totalData;
		break;
	case 297:
		total = _game_design.Enemy_design.SheetBattle_298.int32Value._totalData;
		break;
	case 298:
		total = _game_design.Enemy_design.SheetBattle_299.int32Value._totalData;
		break;
	case 299:
		total = _game_design.Enemy_design.SheetBattle_300.int32Value._totalData;
		break;
	case 300:
		total = _game_design.Enemy_design.SheetBattle_301.int32Value._totalData;
		break;
	case 301:
		total = _game_design.Enemy_design.SheetBattle_302.int32Value._totalData;
		break;
	case 302:
		total = _game_design.Enemy_design.SheetBattle_303.int32Value._totalData;
		break;
	case 303:
		total = _game_design.Enemy_design.SheetBattle_304.int32Value._totalData;
		break;
	case 304:
		total = _game_design.Enemy_design.SheetBattle_305.int32Value._totalData;
		break;
	case 305:
		total = _game_design.Enemy_design.SheetBattle_306.int32Value._totalData;
		break;
	case 306:
		total = _game_design.Enemy_design.SheetBattle_307.int32Value._totalData;
		break;
	case 307:
		total = _game_design.Enemy_design.SheetBattle_308.int32Value._totalData;
		break;
	case 308:
		total = _game_design.Enemy_design.SheetBattle_309.int32Value._totalData;
		break;
	case 309:
		total = _game_design.Enemy_design.SheetBattle_310.int32Value._totalData;
		break;
	case 310:
		total = _game_design.Enemy_design.SheetBattle_311.int32Value._totalData;
		break;
	case 311:
		total = _game_design.Enemy_design.SheetBattle_312.int32Value._totalData;
		break;
	case 312:
		total = _game_design.Enemy_design.SheetBattle_313.int32Value._totalData;
		break;
	case 313:
		total = _game_design.Enemy_design.SheetBattle_314.int32Value._totalData;
		break;
	case 314:
		total = _game_design.Enemy_design.SheetBattle_315.int32Value._totalData;
		break;
	case 315:
		total = _game_design.Enemy_design.SheetBattle_316.int32Value._totalData;
		break;
	case 316:
		total = _game_design.Enemy_design.SheetBattle_317.int32Value._totalData;
		break;
	case 317:
		total = _game_design.Enemy_design.SheetBattle_318.int32Value._totalData;
		break;
	case 318:
		total = _game_design.Enemy_design.SheetBattle_319.int32Value._totalData;
		break;
	case 319:
		total = _game_design.Enemy_design.SheetBattle_320.int32Value._totalData;
		break;
	case 320:
		total = _game_design.Enemy_design.SheetBattle_321.int32Value._totalData;
		break;
	case 321:
		total = _game_design.Enemy_design.SheetBattle_322.int32Value._totalData;
		break;
	case 322:
		total = _game_design.Enemy_design.SheetBattle_323.int32Value._totalData;
		break;
	case 323:
		total = _game_design.Enemy_design.SheetBattle_324.int32Value._totalData;
		break;
	case 324:
		total = _game_design.Enemy_design.SheetBattle_325.int32Value._totalData;
		break;
	case 325:
		total = _game_design.Enemy_design.SheetBattle_326.int32Value._totalData;
		break;
	case 326:
		total = _game_design.Enemy_design.SheetBattle_327.int32Value._totalData;
		break;
	case 327:
		total = _game_design.Enemy_design.SheetBattle_328.int32Value._totalData;
		break;
	case 328:
		total = _game_design.Enemy_design.SheetBattle_329.int32Value._totalData;
		break;
	case 329:
		total = _game_design.Enemy_design.SheetBattle_330.int32Value._totalData;
		break;
	case 330:
		total = _game_design.Enemy_design.SheetBattle_331.int32Value._totalData;
		break;
	case 331:
		total = _game_design.Enemy_design.SheetBattle_332.int32Value._totalData;
		break;
	case 332:
		total = _game_design.Enemy_design.SheetBattle_333.int32Value._totalData;
		break;
	case 333:
		total = _game_design.Enemy_design.SheetBattle_334.int32Value._totalData;
		break;
	case 334:
		total = _game_design.Enemy_design.SheetBattle_335.int32Value._totalData;
		break;
	case 335:
		total = _game_design.Enemy_design.SheetBattle_336.int32Value._totalData;
		break;
	case 336:
		total = _game_design.Enemy_design.SheetBattle_337.int32Value._totalData;
		break;
	case 337:
		total = _game_design.Enemy_design.SheetBattle_338.int32Value._totalData;
		break;
	case 338:
		total = _game_design.Enemy_design.SheetBattle_339.int32Value._totalData;
		break;
	case 339:
		total = _game_design.Enemy_design.SheetBattle_340.int32Value._totalData;
		break;
	case 340:
		total = _game_design.Enemy_design.SheetBattle_341.int32Value._totalData;
		break;
	case 341:
		total = _game_design.Enemy_design.SheetBattle_342.int32Value._totalData;
		break;
	case 342:
		total = _game_design.Enemy_design.SheetBattle_343.int32Value._totalData;
		break;
	case 343:
		total = _game_design.Enemy_design.SheetBattle_344.int32Value._totalData;
		break;
	case 344:
		total = _game_design.Enemy_design.SheetBattle_345.int32Value._totalData;
		break;
	case 345:
		total = _game_design.Enemy_design.SheetBattle_346.int32Value._totalData;
		break;
	case 346:
		total = _game_design.Enemy_design.SheetBattle_347.int32Value._totalData;
		break;
	case 347:
		total = _game_design.Enemy_design.SheetBattle_348.int32Value._totalData;
		break;
	case 348:
		total = _game_design.Enemy_design.SheetBattle_349.int32Value._totalData;
		break;
	case 349:
		total = _game_design.Enemy_design.SheetBattle_350.int32Value._totalData;
		break;
	case 350:
		total = _game_design.Enemy_design.SheetBattle_351.int32Value._totalData;
		break;
	case 351:
		total = _game_design.Enemy_design.SheetBattle_352.int32Value._totalData;
		break;
	case 352:
		total = _game_design.Enemy_design.SheetBattle_353.int32Value._totalData;
		break;
	case 353:
		total = _game_design.Enemy_design.SheetBattle_354.int32Value._totalData;
		break;
	case 354:
		total = _game_design.Enemy_design.SheetBattle_355.int32Value._totalData;
		break;
	case 355:
		total = _game_design.Enemy_design.SheetBattle_356.int32Value._totalData;
		break;
	case 356:
		total = _game_design.Enemy_design.SheetBattle_357.int32Value._totalData;
		break;
	case 357:
		total = _game_design.Enemy_design.SheetBattle_358.int32Value._totalData;
		break;
	case 358:
		total = _game_design.Enemy_design.SheetBattle_359.int32Value._totalData;
		break;
	case 359:
		total = _game_design.Enemy_design.SheetBattle_360.int32Value._totalData;
		break;
	case 360:
		total = _game_design.Enemy_design.SheetBattle_361.int32Value._totalData;
		break;
	case 361:
		total = _game_design.Enemy_design.SheetBattle_362.int32Value._totalData;
		break;
	case 362:
		total = _game_design.Enemy_design.SheetBattle_363.int32Value._totalData;
		break;
	case 363:
		total = _game_design.Enemy_design.SheetBattle_364.int32Value._totalData;
		break;
	case 364:
		total = _game_design.Enemy_design.SheetBattle_365.int32Value._totalData;
		break;
	case 365:
		total = _game_design.Enemy_design.SheetBattle_366.int32Value._totalData;
		break;
	case 366:
		total = _game_design.Enemy_design.SheetBattle_367.int32Value._totalData;
		break;
	case 367:
		total = _game_design.Enemy_design.SheetBattle_368.int32Value._totalData;
		break;
	case 368:
		total = _game_design.Enemy_design.SheetBattle_369.int32Value._totalData;
		break;
	case 369:
		total = _game_design.Enemy_design.SheetBattle_370.int32Value._totalData;
		break;
	case 370:
		total = _game_design.Enemy_design.SheetBattle_371.int32Value._totalData;
		break;
	case 371:
		total = _game_design.Enemy_design.SheetBattle_372.int32Value._totalData;
		break;
	case 372:
		total = _game_design.Enemy_design.SheetBattle_373.int32Value._totalData;
		break;
	case 373:
		total = _game_design.Enemy_design.SheetBattle_374.int32Value._totalData;
		break;
	case 374:
		total = _game_design.Enemy_design.SheetBattle_375.int32Value._totalData;
		break;
	case 375:
		total = _game_design.Enemy_design.SheetBattle_376.int32Value._totalData;
		break;
	case 376:
		total = _game_design.Enemy_design.SheetBattle_377.int32Value._totalData;
		break;
	case 377:
		total = _game_design.Enemy_design.SheetBattle_378.int32Value._totalData;
		break;
	case 378:
		total = _game_design.Enemy_design.SheetBattle_379.int32Value._totalData;
		break;
	case 379:
		total = _game_design.Enemy_design.SheetBattle_380.int32Value._totalData;
		break;
	case 380:
		total = _game_design.Enemy_design.SheetBattle_381.int32Value._totalData;
		break;
	case 381:
		total = _game_design.Enemy_design.SheetBattle_382.int32Value._totalData;
		break;
	case 382:
		total = _game_design.Enemy_design.SheetBattle_383.int32Value._totalData;
		break;
	case 383:
		total = _game_design.Enemy_design.SheetBattle_384.int32Value._totalData;
		break;
	case 384:
		total = _game_design.Enemy_design.SheetBattle_385.int32Value._totalData;
		break;
	case 385:
		total = _game_design.Enemy_design.SheetBattle_386.int32Value._totalData;
		break;
	case 386:
		total = _game_design.Enemy_design.SheetBattle_387.int32Value._totalData;
		break;
	case 387:
		total = _game_design.Enemy_design.SheetBattle_388.int32Value._totalData;
		break;
	case 388:
		total = _game_design.Enemy_design.SheetBattle_389.int32Value._totalData;
		break;
	case 389:
		total = _game_design.Enemy_design.SheetBattle_390.int32Value._totalData;
		break;
	case 390:
		total = _game_design.Enemy_design.SheetBattle_391.int32Value._totalData;
		break;
	case 391:
		total = _game_design.Enemy_design.SheetBattle_392.int32Value._totalData;
		break;
	case 392:
		total = _game_design.Enemy_design.SheetBattle_393.int32Value._totalData;
		break;
	case 393:
		total = _game_design.Enemy_design.SheetBattle_394.int32Value._totalData;
		break;
	case 394:
		total = _game_design.Enemy_design.SheetBattle_395.int32Value._totalData;
		break;
	case 395:
		total = _game_design.Enemy_design.SheetBattle_396.int32Value._totalData;
		break;
	case 396:
		total = _game_design.Enemy_design.SheetBattle_397.int32Value._totalData;
		break;
	case 397:
		total = _game_design.Enemy_design.SheetBattle_398.int32Value._totalData;
		break;
	case 398:
		total = _game_design.Enemy_design.SheetBattle_399.int32Value._totalData;
		break;
	case 399:
		total = _game_design.Enemy_design.SheetBattle_400.int32Value._totalData;
		break;
	case 400:
		total = _game_design.Enemy_design.SheetBattle_401.int32Value._totalData;
		break;
	case 401:
		total = _game_design.Enemy_design.SheetBattle_402.int32Value._totalData;
		break;
	case 402:
		total = _game_design.Enemy_design.SheetBattle_403.int32Value._totalData;
		break;
	case 403:
		total = _game_design.Enemy_design.SheetBattle_404.int32Value._totalData;
		break;
	case 404:
		total = _game_design.Enemy_design.SheetBattle_405.int32Value._totalData;
		break;
	case 405:
		total = _game_design.Enemy_design.SheetBattle_406.int32Value._totalData;
		break;
	case 406:
		total = _game_design.Enemy_design.SheetBattle_407.int32Value._totalData;
		break;
	case 407:
		total = _game_design.Enemy_design.SheetBattle_408.int32Value._totalData;
		break;
	case 408:
		total = _game_design.Enemy_design.SheetBattle_409.int32Value._totalData;
		break;
	case 409:
		total = _game_design.Enemy_design.SheetBattle_410.int32Value._totalData;
		break;
	case 410:
		total = _game_design.Enemy_design.SheetBattle_411.int32Value._totalData;
		break;
	case 411:
		total = _game_design.Enemy_design.SheetBattle_412.int32Value._totalData;
		break;
	case 412:
		total = _game_design.Enemy_design.SheetBattle_413.int32Value._totalData;
		break;
	case 413:
		total = _game_design.Enemy_design.SheetBattle_414.int32Value._totalData;
		break;
	case 414:
		total = _game_design.Enemy_design.SheetBattle_415.int32Value._totalData;
		break;
	case 415:
		total = _game_design.Enemy_design.SheetBattle_416.int32Value._totalData;
		break;
	case 416:
		total = _game_design.Enemy_design.SheetBattle_417.int32Value._totalData;
		break;
	case 417:
		total = _game_design.Enemy_design.SheetBattle_418.int32Value._totalData;
		break;
	case 418:
		total = _game_design.Enemy_design.SheetBattle_419.int32Value._totalData;
		break;
	case 419:
		total = _game_design.Enemy_design.SheetBattle_420.int32Value._totalData;
		break;
	case 420:
		total = _game_design.Enemy_design.SheetBattle_421.int32Value._totalData;
		break;
	case 421:
		total = _game_design.Enemy_design.SheetBattle_422.int32Value._totalData;
		break;
	case 422:
		total = _game_design.Enemy_design.SheetBattle_423.int32Value._totalData;
		break;
	case 423:
		total = _game_design.Enemy_design.SheetBattle_424.int32Value._totalData;
		break;
	case 424:
		total = _game_design.Enemy_design.SheetBattle_425.int32Value._totalData;
		break;
	case 425:
		total = _game_design.Enemy_design.SheetBattle_426.int32Value._totalData;
		break;
	case 426:
		total = _game_design.Enemy_design.SheetBattle_427.int32Value._totalData;
		break;
	case 427:
		total = _game_design.Enemy_design.SheetBattle_428.int32Value._totalData;
		break;
	case 428:
		total = _game_design.Enemy_design.SheetBattle_429.int32Value._totalData;
		break;
	case 429:
		total = _game_design.Enemy_design.SheetBattle_230.int32Value._totalData;
		break;
	case 430:
		total = _game_design.Enemy_design.SheetBattle_431.int32Value._totalData;
		break;
	case 431:
		total = _game_design.Enemy_design.SheetBattle_432.int32Value._totalData;
		break;
	case 432:
		total = _game_design.Enemy_design.SheetBattle_433.int32Value._totalData;
		break;
	case 433:
		total = _game_design.Enemy_design.SheetBattle_434.int32Value._totalData;
		break;
	case 434:
		total = _game_design.Enemy_design.SheetBattle_435.int32Value._totalData;
		break;
	case 435:
		total = _game_design.Enemy_design.SheetBattle_436.int32Value._totalData;
		break;
	case 436:
		total = _game_design.Enemy_design.SheetBattle_437.int32Value._totalData;
		break;
	case 437:
		total = _game_design.Enemy_design.SheetBattle_438.int32Value._totalData;
		break;
	case 438:
		total = _game_design.Enemy_design.SheetBattle_439.int32Value._totalData;
		break;
	case 439:
		total = _game_design.Enemy_design.SheetBattle_240.int32Value._totalData;
		break;
	case 440:
		total = _game_design.Enemy_design.SheetBattle_441.int32Value._totalData;
		break;
	case 441:
		total = _game_design.Enemy_design.SheetBattle_442.int32Value._totalData;
		break;
	case 442:
		total = _game_design.Enemy_design.SheetBattle_443.int32Value._totalData;
		break;
	case 443:
		total = _game_design.Enemy_design.SheetBattle_444.int32Value._totalData;
		break;
	case 444:
		total = _game_design.Enemy_design.SheetBattle_445.int32Value._totalData;
		break;
	case 445:
		total = _game_design.Enemy_design.SheetBattle_446.int32Value._totalData;
		break;
	case 446:
		total = _game_design.Enemy_design.SheetBattle_447.int32Value._totalData;
		break;
	case 447:
		total = _game_design.Enemy_design.SheetBattle_448.int32Value._totalData;
		break;
	case 448:
		total = _game_design.Enemy_design.SheetBattle_449.int32Value._totalData;
		break;
	case 449:
		total = _game_design.Enemy_design.SheetBattle_450.int32Value._totalData;
		break;
	case 450:
		total = _game_design.Enemy_design.SheetBattle_451.int32Value._totalData;
		break;
	case 451:
		total = _game_design.Enemy_design.SheetBattle_452.int32Value._totalData;
		break;
	case 452:
		total = _game_design.Enemy_design.SheetBattle_453.int32Value._totalData;
		break;
	case 453:
		total = _game_design.Enemy_design.SheetBattle_454.int32Value._totalData;
		break;
	case 454:
		total = _game_design.Enemy_design.SheetBattle_455.int32Value._totalData;
		break;
	case 455:
		total = _game_design.Enemy_design.SheetBattle_456.int32Value._totalData;
		break;
	case 456:
		total = _game_design.Enemy_design.SheetBattle_457.int32Value._totalData;
		break;
	case 457:
		total = _game_design.Enemy_design.SheetBattle_458.int32Value._totalData;
		break;
	case 458:
		total = _game_design.Enemy_design.SheetBattle_459.int32Value._totalData;
		break;
	case 459:
		total = _game_design.Enemy_design.SheetBattle_460.int32Value._totalData;
		break;
	case 460:
		total = _game_design.Enemy_design.SheetBattle_461.int32Value._totalData;
		break;
	case 461:
		total = _game_design.Enemy_design.SheetBattle_462.int32Value._totalData;
		break;
	case 462:
		total = _game_design.Enemy_design.SheetBattle_463.int32Value._totalData;
		break;
	case 463:
		total = _game_design.Enemy_design.SheetBattle_464.int32Value._totalData;
		break;
	case 464:
		total = _game_design.Enemy_design.SheetBattle_465.int32Value._totalData;
		break;
	case 465:
		total = _game_design.Enemy_design.SheetBattle_466.int32Value._totalData;
		break;
	case 466:
		total = _game_design.Enemy_design.SheetBattle_467.int32Value._totalData;
		break;
	case 467:
		total = _game_design.Enemy_design.SheetBattle_468.int32Value._totalData;
		break;
	case 468:
		total = _game_design.Enemy_design.SheetBattle_469.int32Value._totalData;
		break;
	case 469:
		total = _game_design.Enemy_design.SheetBattle_470.int32Value._totalData;
		break;
	case 470:
		total = _game_design.Enemy_design.SheetBattle_471.int32Value._totalData;
		break;
	case 471:
		total = _game_design.Enemy_design.SheetBattle_472.int32Value._totalData;
		break;
	case 472:
		total = _game_design.Enemy_design.SheetBattle_473.int32Value._totalData;
		break;
	case 473:
		total = _game_design.Enemy_design.SheetBattle_474.int32Value._totalData;
		break;
	case 474:
		total = _game_design.Enemy_design.SheetBattle_475.int32Value._totalData;
		break;
	case 475:
		total = _game_design.Enemy_design.SheetBattle_476.int32Value._totalData;
		break;
	case 476:
		total = _game_design.Enemy_design.SheetBattle_477.int32Value._totalData;
		break;
	case 477:
		total = _game_design.Enemy_design.SheetBattle_478.int32Value._totalData;
		break;
	case 478:
		total = _game_design.Enemy_design.SheetBattle_479.int32Value._totalData;
		break;
	case 479:
		total = _game_design.Enemy_design.SheetBattle_480.int32Value._totalData;
		break;
	case 480:
		total = _game_design.Enemy_design.SheetBattle_481.int32Value._totalData;
		break;
	case 481:
		total = _game_design.Enemy_design.SheetBattle_482.int32Value._totalData;
		break;
	case 482:
		total = _game_design.Enemy_design.SheetBattle_483.int32Value._totalData;
		break;
	case 483:
		total = _game_design.Enemy_design.SheetBattle_484.int32Value._totalData;
		break;
	case 484:
		total = _game_design.Enemy_design.SheetBattle_485.int32Value._totalData;
		break;
	case 485:
		total = _game_design.Enemy_design.SheetBattle_486.int32Value._totalData;
		break;
	case 486:
		total = _game_design.Enemy_design.SheetBattle_487.int32Value._totalData;
		break;
	case 487:
		total = _game_design.Enemy_design.SheetBattle_488.int32Value._totalData;
		break;
	case 488:
		total = _game_design.Enemy_design.SheetBattle_489.int32Value._totalData;
		break;
	case 489:
		total = _game_design.Enemy_design.SheetBattle_490.int32Value._totalData;
		break;
	case 490:
		total = _game_design.Enemy_design.SheetBattle_491.int32Value._totalData;
		break;
	case 491:
		total = _game_design.Enemy_design.SheetBattle_492.int32Value._totalData;
		break;
	case 492:
		total = _game_design.Enemy_design.SheetBattle_493.int32Value._totalData;
		break;
	case 493:
		total = _game_design.Enemy_design.SheetBattle_494.int32Value._totalData;
		break;
	case 494:
		total = _game_design.Enemy_design.SheetBattle_495.int32Value._totalData;
		break;
	case 495:
		total = _game_design.Enemy_design.SheetBattle_496.int32Value._totalData;
		break;
	case 496:
		total = _game_design.Enemy_design.SheetBattle_497.int32Value._totalData;
		break;
	case 497:
		total = _game_design.Enemy_design.SheetBattle_498.int32Value._totalData;
		break;
	case 498:
		total = _game_design.Enemy_design.SheetBattle_499.int32Value._totalData;
		break;
	case 499:
		total = _game_design.Enemy_design.SheetBattle_500.int32Value._totalData;
		break;
	default:
		total = _game_design.Enemy_design.SheetBattle_500.int32Value._totalData;
		break;
	}


	for (int i = 0; i < total; i++)
	{
		int des_wave = GetDesignBattleGeneral(battle, i, param_wave);
		if (des_wave == wave)
		{
			if (_row_start_inwave == -1)
			{
				_row_start_inwave = i;
			}
			num_data++;
		}
	}
	return num_data;
}

int TDGame::GetDesignSkillInfo(int id, int param)
{
	return _game_design.Skill_design.SheetSheet1.int32Value.getValue(id, param);
}
const char* TDGame::GetDesignSkillString(int id, int param)
{
	return _game_design.Skill_design.SheetSheet1.stringValue.getValue(id, param);
}
int TDGame::GetDesignBackground(int id, int param)
{
	return _game_design.background.SheetSheet1.int32Value.getValue(id, param);
}
int TDGame::GetDesignQuestValue(int id, int param, bool daily)
{
	if (daily)
	{
		return _game_design.Quest.SheetDaily_Quest.int32Value.getValue(id, param);
	}
	else
	{
		return _game_design.Quest.SheetNormal_Quest.int32Value.getValue(id, param);
	}
	
}
const char* TDGame::GetDesignQuestString(int id, int param, bool daily)
{
	if (daily)
	{
		return _game_design.Quest.SheetDaily_Quest.stringValue.getValue(id, param);
	}
	else
	{
		return _game_design.Quest.SheetNormal_Quest.stringValue.getValue(id, param);
	}
}

int TDGame::GetDesignRelics(int id, int group, int param)
{
	switch (group)
	{
	case ITEMRELIC_GROUP_HERO:
		return _game_design.Relics_design.SheetHero_Relics.int32Value.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_WEAPON:
		return _game_design.Relics_design.SheetWeapon_Relics.int32Value.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_ENEMY:
		return _game_design.Relics_design.SheetEnemy_Relics.int32Value.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_PET:
		return _game_design.Relics_design.SheetPet_Relics.int32Value.getValue(id, param);
		break;
	default:
		break;
	}
}
const char* TDGame::GetDesignRelicsString(int id, int group, int param)
{
	switch (group)
	{
	case ITEMRELIC_GROUP_HERO:
		return _game_design.Relics_design.SheetHero_Relics.stringValue.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_WEAPON:
		return _game_design.Relics_design.SheetWeapon_Relics.stringValue.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_ENEMY:
		return _game_design.Relics_design.SheetEnemy_Relics.stringValue.getValue(id, param);
		break;
	case ITEMRELIC_GROUP_PET:
		return _game_design.Relics_design.SheetPet_Relics.stringValue.getValue(id, param);
		break;
	default:
		break;
	}
}

int TDGame::GetDesignRelicIndex(int id, int group)
{
	int total = 0;
	int ret_id = -1;
	switch (group)
	{
	case ITEMRELIC_GROUP_HERO:
		total = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
		for (int i = 0; i < total; i++)
		{
			int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
			int relic_id = GetDesignRelics(i, group, paramid);
			if (id == relic_id)
			{
				ret_id = i;
				break;
			}
		}
		break;
	case ITEMRELIC_GROUP_WEAPON:
		total = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
		for (int i = 0; i < total; i++)
		{
			int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
			int relic_id = GetDesignRelics(i, group, paramid);
			if (id == relic_id)
			{
				ret_id = i;
				break;
			}
		}
		break;
	case ITEMRELIC_GROUP_ENEMY:
		total = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;
		for (int i = 0; i < total; i++)
		{
			int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
			int relic_id = GetDesignRelics(i, group, paramid);
			if (id == relic_id)
			{
				ret_id = i;
				break;
			}
		}
		break;
	case ITEMRELIC_GROUP_PET:
		total = _game_design.Relics_design.SheetPet_Relics.int32Value._totalData;
		for (int i = 0; i < total; i++)
		{
			int paramid = CGameDesign::FileRelics_design::CSheetPet_Relics::ID;
			int relic_id = GetDesignRelics(i, group, paramid);
			if (id == relic_id)
			{
				ret_id = i;
				break;
			}
		}
		break;
	default:
		break;
	}
	return ret_id;
}
int TDGame::GetDesignRelicsSprite(int id, int param)
{
	return _game_design.SpriteManager.SheetSprite_Relic.int32Value.getValue(id, param);
}
const char* TDGame::GetDesignRelicsSpriteString(int id, int param)
{
	return _game_design.SpriteManager.SheetSprite_Relic.stringValue.getValue(id, param);
}

int TDGame::GetDesignRelicsSpriteIndex(const char* relicName)
{
	char temp[64];
	int total = _game_design.SpriteManager.SheetSprite_Relic.int32Value._totalData;
	int param_name = CGameDesign::FileSpriteManager::CSheetSprite_Relic::Relic_Name;
	int index = -1;
	for (int i = 0; i < total; i++)
	{
		sprintf(temp, "%s", GetDesignRelicsSpriteString(i, param_name));
		if (strcmp(temp, relicName) == 0)
		{
			index = i;
		}
	}
	return index;
}

int TDGame::GetDesignQuestSprite(int id, int param)
{
	return _game_design.SpriteManager.SheetSprite_Quest.int32Value.getValue(id, param);
}
const char* TDGame::GetDesignQuestSpriteString(int id, int param)
{
	return _game_design.SpriteManager.SheetSprite_Quest.stringValue.getValue(id, param);
}
int TDGame::GetDesignQuestSpriteIndex(const char* questName)
{
	char temp[256];
	int total = _game_design.SpriteManager.SheetSprite_Quest.int32Value._totalData;
	int param_name = CGameDesign::FileSpriteManager::CSheetSprite_Relic::Relic_Name;
	int index = -1;
	for (int i = 0; i < total; i++)
	{
		sprintf(temp, "%s", GetDesignQuestSpriteString(i, param_name));
		if (strcmp(temp, questName) == 0)
		{
			index = i;
		}
	}
	return index;
}
int TDGame::GetQuestIndex(int group, int id,bool daily)
{
	int questindex = 0;
	int param_group = CGameDesign::FileQuest::CSheetNormal_Quest::Group;
	int total = _game_design.Quest.SheetNormal_Quest.int32Value._totalData;
	if (daily)
	{
		int total = _game_design.Quest.SheetDaily_Quest.int32Value._totalData;
	}
	for (int i = 0; i < total; i++)
	{
		int ds_group = GetDesignQuestValue(i, param_group,daily);
		if (ds_group == group)
		{
			questindex = i + id;
			break;
		}
	}
	return questindex;
}
float TDGame::GetDesignIAPPrice(int id, int param, bool discount)
{
	return 0;// _game_design.General.SheetiAP_design.floatValue.getValue(id, param);
}
int TDGame::GetDesignIapIndex(int id, int param, bool discount)
{
    int iapindex = 0;
    int param_id = CGameDesign::FileGeneral::CSheetiAP_design::id;
    int total = _game_design.General.SheetiAP_design.int32Value._totalData;

    for (int i = 0; i < total; i++)
    {
		int ds_iapid = _game_design.General.SheetiAP_design.int32Value.getValue(i, param);
        if (ds_iapid == id)
        {
            iapindex = i;
            break;
        }
    }
    return iapindex;
}
int TDGame::GetDesignIAP(int id, int param, bool discount)
{
    int paramid = CGameDesign::FileGeneral::CSheetiAP_design::id;
    int iapid = _game_design.General.SheetiAP_design.int32Value.getValue(id, paramid);
    if (iapid > 4)
    {
        return _game_design.General.SheetiAP_design.int32Value.getValue(id, param);
    }
	{
		if (discount)
		{
			return _game_design.General.SheetiAP_design_discount.int32Value.getValue(iapid - 1, param);
		}
		else
		{
			return _game_design.General.SheetiAP_design.int32Value.getValue(id, param);
		}
	}
}
const char* TDGame::GetDesignIAPString(int id, int param, bool discount)
{
    int paramid = CGameDesign::FileGeneral::CSheetiAP_design::id;
    int iapid = _game_design.General.SheetiAP_design.int32Value.getValue(id, paramid);
	if (iapid > 4)
	{
		return _game_design.General.SheetiAP_design.stringValue.getValue(id, param);
	}
	else
	{
		if (discount)
		{
            
			return _game_design.General.SheetiAP_design_discount.stringValue.getValue(iapid - 1, param);
		}
		else
		{
			return _game_design.General.SheetiAP_design.stringValue.getValue(id, param);
		}
	}
}
float TDGame::GetDesignTreasureInfo(int id, int param, bool chest)
{
	if (chest)
	{
		int total = _game_design.Treasure.SheetSheet2.floatValue._totalData - 1;
		if (id > total)
		{
			id = total;
		}
		return _game_design.Treasure.SheetSheet2.floatValue.getValue(id, param);
	}
	else
	{
		
		return 1;
	}
}
int TDGame::GetDesignTreasure(int id, int param, bool chest)
{
	if (chest)
	{
		int total = _game_design.Treasure.SheetSheet2.int32Value._totalData - 1;
		if (id > total)
		{
			id = total;
		}
		return _game_design.Treasure.SheetSheet2.int32Value.getValue(id, param);
	}
	else
	{
		int total = _game_design.Treasure.SheetSheet1.int32Value._totalData - 1;
		if (id > total)
		{
			id = total;
		}
		return _game_design.Treasure.SheetSheet1.int32Value.getValue(id, param);
	}
	
}

int TDGame::GetDesignChest(int id, int param)
{
	return _game_design.General.SheetLoterry_design.int32Value.getValue(id, param);
}
float TDGame::GetDesignChestFloat(int id, int param)
{
	return _game_design.General.SheetLoterry_design.floatValue.getValue(id, param);
}
int TDGame::GetDesignFairyReward(int id, int param)
{
	return _game_design.General.SheetFairy_design.int32Value.getValue(id, param);
}
int TDGame::GetNumOfQuest(int group)
{
	int total = _game_design.Quest.SheetNormal_Quest.int32Value._totalData;
	int param_group = CGameDesign::FileQuest::CSheetNormal_Quest::Group;
	int count = 0;
	for (int i = 0; i < total; i++)
	{
		int ds_group = GetDesignQuestValue(i, param_group,false);
		if (ds_group == group)
		{
			count++;
		}
	}
	return count;
}
int TDGame::GetNumOfGroupQuest()
{
	int total = _game_design.Quest.SheetNormal_Quest.int32Value._totalData;
	int param_group = CGameDesign::FileQuest::CSheetNormal_Quest::Group;
	int totalgroup = 0;
	totalgroup = GetDesignQuestValue(total - 1, param_group,false);
	return totalgroup;
}

int TDGame::GetDailyQuestRandom()
{
	int total = _game_design.Quest.SheetDaily_Quest.int32Value._totalData;
	int rand = CMath::RANDOM(0, total - 1);
	if (!_user._tutorial_completed)
	{
		rand = 0;
	}
	return rand;
}

int TDGame::GetDesignWheelInfo(int id, int param)
{
	return _game_design.General.SheetWheel.int32Value.getValue(id, param);
}

int TDGame::GetDesignFreeGift(int id, int param)
{
	return _game_design.General.SheetFree_Gift.int32Value.getValue(id, param);
}

int TDGame::GetDesignIapTrigger(int id, int param)
{
	return _game_design.General.SheetDiscount.int32Value.getValue(id, param);
}

int TDGame::GetDesignWheelTime(int id)
{
	int param_time = CGameDesign::FileGeneral::CSheetWheel_time::Time;
	return _game_design.General.SheetWheel_time.int32Value.getValue(id, param_time);
}
int TDGame::GetDesignPetInfo(int id, int param)
{
	int total = _game_design.Pet.SheetPet_General.int32Value._totalData;
	int index = -1;
	if (id > total)
	{
		id = total - 1;
	}
	for (int i = 0; i < total; i++)
	{
		int param_id = CGameDesign::FilePet::CSheetPet_General::ID_Pet;
		int petid = _game_design.Pet.SheetPet_General.int32Value.getValue(i, param_id);
		if (id == petid)
		{
			index = i;
			break;
		}
	}
	if (index >= 0)
	{
		return _game_design.Pet.SheetPet_General.int32Value.getValue(index, param);
	}
	else
	{
		printf("\n Pet no info");
		return -1;
	}
	
}
int TDGame::GetDesignDailyReward(int id, int param)
{
	return _game_design.General.SheetDaily_Event.int32Value.getValue(id, param);
}