#ifndef _CGAME_DESIGN_H_
#define _CGAME_DESIGN_H_

#include "../../DataType/CType.h"

class DesignClassDataInt32
{
public:
	DesignClassDataInt32(){};

	int _beginByte;
	int *_data;
	int _totalAtribute, _totalData;

	void Load();
	void UnLoad();

	int getValue(int row, int atribute);
};

class DesignClassDataInt64
{
public:
	DesignClassDataInt64(){};

	int _beginByte;
	INT64 *_data;
	int _totalAtribute, _totalData;

	void Load();
	void UnLoad();

	INT64 getValue(int row, int atribute);
};

class DesignClassDataFloat
{
public:
	DesignClassDataFloat(){};

	int _beginByte;
	float *_data;
	int _totalAtribute, _totalData;

	void Load();
	void UnLoad();

	float getValue(int row, int atribute);
};

class DesignClassDataString
{
public:
	DesignClassDataString(){};

	int _beginByte;
	char **_data;
	int _totalAtribute, _totalData;

	void Load();
	void UnLoad();

	char *getValue(int row, int atribute);
};

class CGameDesign
{
public:
	CGameDesign(){};

	class FileCastle_design
	{
		public:
		FileCastle_design()
		{

		};

		void Load()
		{
			SheetCastle_General.Load();
			SheetCastle_Upgrade.Load();
			SheetArcher_Upgrade.Load();
			SheetFire_Mage_Tower_Upgrade.Load();
			SheetCanon_Upgrade.Load();
			SheetElectric_Tower_Upgrade.Load();
			SheetFrost_Mage_Tower_Upgrade.Load();
			SheetTwin_Tower_Upgrade.Load();
			SheetHoly_Tower_Upgrade.Load();
			SheetDarkness_Tower_Upgrarde.Load();
			SheetDragon_Tower_Upgrade.Load();
			SheetChimera_Tower_Upgrade.Load();

		};

		void UnLoad()
		{
			SheetCastle_General.UnLoad();
			SheetCastle_Upgrade.UnLoad();
			SheetArcher_Upgrade.UnLoad();
			SheetFire_Mage_Tower_Upgrade.UnLoad();
			SheetCanon_Upgrade.UnLoad();
			SheetElectric_Tower_Upgrade.UnLoad();
			SheetFrost_Mage_Tower_Upgrade.UnLoad();
			SheetTwin_Tower_Upgrade.UnLoad();
			SheetHoly_Tower_Upgrade.UnLoad();
			SheetDarkness_Tower_Upgrarde.UnLoad();
			SheetDragon_Tower_Upgrade.UnLoad();
			SheetChimera_Tower_Upgrade.UnLoad();

		};

		class CSheetCastle_General
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetCastle_General()
			{
				int32Value._beginByte = 0;
				stringValue._beginByte = 272;

			};
			enum enumInt32
			{
				Cost = 0,
				Speed = 1,
				Range = 2,
				Critical = 3,
				AOE = 4,
				Battle_Unlock = 5,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetCastle_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetCastle_Upgrade()
			{
				int64Value._beginByte = 810;
				floatValue._beginByte = 16834;

			};
			enum enumInt64
			{
				HP = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetArcher_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetArcher_Upgrade()
			{
				int64Value._beginByte = 20846;
				floatValue._beginByte = 36870;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetFire_Mage_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetFire_Mage_Tower_Upgrade()
			{
				int64Value._beginByte = 40882;
				floatValue._beginByte = 56906;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetCanon_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetCanon_Upgrade()
			{
				int64Value._beginByte = 60918;
				floatValue._beginByte = 76942;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetElectric_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetElectric_Tower_Upgrade()
			{
				int64Value._beginByte = 80954;
				floatValue._beginByte = 96978;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetFrost_Mage_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetFrost_Mage_Tower_Upgrade()
			{
				int64Value._beginByte = 100990;
				floatValue._beginByte = 117014;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetTwin_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetTwin_Tower_Upgrade()
			{
				int64Value._beginByte = 121026;
				floatValue._beginByte = 137050;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetHoly_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetHoly_Tower_Upgrade()
			{
				int64Value._beginByte = 141062;
				floatValue._beginByte = 157086;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetDarkness_Tower_Upgrarde
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetDarkness_Tower_Upgrarde()
			{
				int64Value._beginByte = 161098;
				floatValue._beginByte = 177122;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetDragon_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetDragon_Tower_Upgrade()
			{
				int64Value._beginByte = 181134;
				floatValue._beginByte = 197158;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetChimera_Tower_Upgrade
		{
			public:
			DesignClassDataInt64 int64Value;
			DesignClassDataFloat floatValue;

			CSheetChimera_Tower_Upgrade()
			{
				int64Value._beginByte = 201170;
				floatValue._beginByte = 217194;

			};
			enum enumInt64
			{
				Attack = 0,
				Upgrade_Cost = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int64Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int64Value.UnLoad();
				floatValue.UnLoad();

			};
		};

		CSheetCastle_General SheetCastle_General;
		CSheetCastle_Upgrade SheetCastle_Upgrade;
		CSheetArcher_Upgrade SheetArcher_Upgrade;
		CSheetFire_Mage_Tower_Upgrade SheetFire_Mage_Tower_Upgrade;
		CSheetCanon_Upgrade SheetCanon_Upgrade;
		CSheetElectric_Tower_Upgrade SheetElectric_Tower_Upgrade;
		CSheetFrost_Mage_Tower_Upgrade SheetFrost_Mage_Tower_Upgrade;
		CSheetTwin_Tower_Upgrade SheetTwin_Tower_Upgrade;
		CSheetHoly_Tower_Upgrade SheetHoly_Tower_Upgrade;
		CSheetDarkness_Tower_Upgrarde SheetDarkness_Tower_Upgrarde;
		CSheetDragon_Tower_Upgrade SheetDragon_Tower_Upgrade;
		CSheetChimera_Tower_Upgrade SheetChimera_Tower_Upgrade;

	};
	class FileEnemy_Creation
	{
		public:
		FileEnemy_Creation()
		{

		};

		void Load()
		{
			SheetEnemy_Design.Load();
			SheetSkill.Load();

		};

		void UnLoad()
		{
			SheetEnemy_Design.UnLoad();
			SheetSkill.UnLoad();

		};

		class CSheetEnemy_Design
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;
			DesignClassDataString stringValue;

			CSheetEnemy_Design()
			{
				int32Value._beginByte = 221206;
				floatValue._beginByte = 223470;
				stringValue._beginByte = 223854;

			};
			enum enumInt32
			{
				SpriteID = 0,
				Attack_Speed = 1,
				Range = 2,
				Skill = 3,
				AOE = 4,
				Attack_Speed_If_boss = 5,

			};
			enum enumFloat
			{
				Move_Speed = 0,

			};
			enum enumString
			{
				Enemy_ID = 0,
				Name = 1,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetSkill
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetSkill()
			{
				int32Value._beginByte = 225981;
				stringValue._beginByte = 226073;

			};
			enum enumInt32
			{
				ID = 0,
				Ability = 1,
				HP = 2,

			};
			enum enumString
			{
				Description = 0,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetEnemy_Design SheetEnemy_Design;
		CSheetSkill SheetSkill;

	};
	class FileEnemy_design
	{
		public:
		FileEnemy_design()
		{

		};

		void Load()
		{
			SheetBattle_1.Load();
			SheetBattle_2.Load();
			SheetBattle_3.Load();
			SheetBattle_4.Load();
			SheetBattle_5.Load();
			SheetBattle_6.Load();
			SheetBattle_7.Load();
			SheetBattle_8.Load();
			SheetBattle_9.Load();
			SheetBattle_10.Load();
			SheetBattle_11.Load();
			SheetBattle_12.Load();
			SheetBattle_13.Load();
			SheetBattle_14.Load();
			SheetBattle_15.Load();
			SheetBattle_16.Load();
			SheetBattle_17.Load();
			SheetBattle_18.Load();
			SheetBattle_19.Load();
			SheetBattle_20.Load();
			SheetBattle_21.Load();
			SheetBattle_22.Load();
			SheetBattle_23.Load();
			SheetBattle_24.Load();
			SheetBattle_25.Load();
			SheetBattle_26.Load();
			SheetBattle_27.Load();
			SheetBattle_28.Load();
			SheetBattle_29.Load();
			SheetBattle_30.Load();
			SheetBattle_31.Load();
			SheetBattle_32.Load();
			SheetBattle_33.Load();
			SheetBattle_34.Load();
			SheetBattle_35.Load();
			SheetBattle_36.Load();
			SheetBattle_37.Load();
			SheetBattle_38.Load();
			SheetBattle_39.Load();
			SheetBattle_40.Load();
			SheetBattle_41.Load();
			SheetBattle_42.Load();
			SheetBattle_43.Load();
			SheetBattle_44.Load();
			SheetBattle_45.Load();
			SheetBattle_46.Load();
			SheetBattle_47.Load();
			SheetBattle_48.Load();
			SheetBattle_49.Load();
			SheetBattle_50.Load();
			SheetBattle_51.Load();
			SheetBattle_52.Load();
			SheetBattle_53.Load();
			SheetBattle_54.Load();
			SheetBattle_55.Load();
			SheetBattle_56.Load();
			SheetBattle_57.Load();
			SheetBattle_58.Load();
			SheetBattle_59.Load();
			SheetBattle_60.Load();
			SheetBattle_61.Load();
			SheetBattle_62.Load();
			SheetBattle_63.Load();
			SheetBattle_64.Load();
			SheetBattle_65.Load();
			SheetBattle_66.Load();
			SheetBattle_67.Load();
			SheetBattle_68.Load();
			SheetBattle_69.Load();
			SheetBattle_70.Load();
			SheetBattle_71.Load();
			SheetBattle_72.Load();
			SheetBattle_73.Load();
			SheetBattle_74.Load();
			SheetBattle_75.Load();
			SheetBattle_76.Load();
			SheetBattle_77.Load();
			SheetBattle_78.Load();
			SheetBattle_79.Load();
			SheetBattle_80.Load();
			SheetBattle_81.Load();
			SheetBattle_82.Load();
			SheetBattle_83.Load();
			SheetBattle_84.Load();
			SheetBattle_85.Load();
			SheetBattle_86.Load();
			SheetBattle_87.Load();
			SheetBattle_88.Load();
			SheetBattle_89.Load();
			SheetBattle_90.Load();
			SheetBattle_91.Load();
			SheetBattle_92.Load();
			SheetBattle_93.Load();
			SheetBattle_94.Load();
			SheetBattle_95.Load();
			SheetBattle_96.Load();
			SheetBattle_97.Load();
			SheetBattle_98.Load();
			SheetBattle_99.Load();
			SheetBattle_100.Load();
			SheetBattle_101.Load();
			SheetBattle_102.Load();
			SheetBattle_103.Load();
			SheetBattle_104.Load();
			SheetBattle_105.Load();
			SheetBattle_106.Load();
			SheetBattle_107.Load();
			SheetBattle_108.Load();
			SheetBattle_109.Load();
			SheetBattle_110.Load();
			SheetBattle_111.Load();
			SheetBattle_112.Load();
			SheetBattle_113.Load();
			SheetBattle_114.Load();
			SheetBattle_115.Load();
			SheetBattle_116.Load();
			SheetBattle_117.Load();
			SheetBattle_118.Load();
			SheetBattle_119.Load();
			SheetBattle_120.Load();
			SheetBattle_121.Load();
			SheetBattle_122.Load();
			SheetBattle_123.Load();
			SheetBattle_124.Load();
			SheetBattle_125.Load();
			SheetBattle_126.Load();
			SheetBattle_127.Load();
			SheetBattle_128.Load();
			SheetBattle_129.Load();
			SheetBattle_130.Load();
			SheetBattle_131.Load();
			SheetBattle_132.Load();
			SheetBattle_133.Load();
			SheetBattle_134.Load();
			SheetBattle_135.Load();
			SheetBattle_136.Load();
			SheetBattle_137.Load();
			SheetBattle_138.Load();
			SheetBattle_139.Load();
			SheetBattle_140.Load();
			SheetBattle_141.Load();
			SheetBattle_142.Load();
			SheetBattle_143.Load();
			SheetBattle_144.Load();
			SheetBattle_145.Load();
			SheetBattle_146.Load();
			SheetBattle_147.Load();
			SheetBattle_148.Load();
			SheetBattle_149.Load();
			SheetBattle_150.Load();
			SheetBattle_151.Load();
			SheetBattle_152.Load();
			SheetBattle_153.Load();
			SheetBattle_154.Load();
			SheetBattle_155.Load();
			SheetBattle_156.Load();
			SheetBattle_157.Load();
			SheetBattle_158.Load();
			SheetBattle_159.Load();
			SheetBattle_160.Load();
			SheetBattle_161.Load();
			SheetBattle_162.Load();
			SheetBattle_163.Load();
			SheetBattle_164.Load();
			SheetBattle_165.Load();
			SheetBattle_166.Load();
			SheetBattle_167.Load();
			SheetBattle_168.Load();
			SheetBattle_169.Load();
			SheetBattle_170.Load();
			SheetBattle_171.Load();
			SheetBattle_172.Load();
			SheetBattle_173.Load();
			SheetBattle_174.Load();
			SheetBattle_175.Load();
			SheetBattle_176.Load();
			SheetBattle_177.Load();
			SheetBattle_178.Load();
			SheetBattle_179.Load();
			SheetBattle_180.Load();
			SheetBattle_181.Load();
			SheetBattle_182.Load();
			SheetBattle_183.Load();
			SheetBattle_184.Load();
			SheetBattle_185.Load();
			SheetBattle_186.Load();
			SheetBattle_187.Load();
			SheetBattle_188.Load();
			SheetBattle_189.Load();
			SheetBattle_190.Load();
			SheetBattle_191.Load();
			SheetBattle_192.Load();
			SheetBattle_193.Load();
			SheetBattle_194.Load();
			SheetBattle_195.Load();
			SheetBattle_196.Load();
			SheetBattle_197.Load();
			SheetBattle_198.Load();
			SheetBattle_199.Load();
			SheetBattle_200.Load();
			SheetBattle_201.Load();
			SheetBattle_202.Load();
			SheetBattle_203.Load();
			SheetBattle_204.Load();
			SheetBattle_205.Load();
			SheetBattle_206.Load();
			SheetBattle_207.Load();
			SheetBattle_208.Load();
			SheetBattle_209.Load();
			SheetBattle_210.Load();
			SheetBattle_211.Load();
			SheetBattle_212.Load();
			SheetBattle_213.Load();
			SheetBattle_214.Load();
			SheetBattle_215.Load();
			SheetBattle_216.Load();
			SheetBattle_217.Load();
			SheetBattle_218.Load();
			SheetBattle_219.Load();
			SheetBattle_220.Load();
			SheetBattle_221.Load();
			SheetBattle_222.Load();
			SheetBattle_223.Load();
			SheetBattle_224.Load();
			SheetBattle_225.Load();
			SheetBattle_226.Load();
			SheetBattle_227.Load();
			SheetBattle_228.Load();
			SheetBattle_229.Load();
			SheetBattle_230.Load();
			SheetBattle_231.Load();
			SheetBattle_232.Load();
			SheetBattle_233.Load();
			SheetBattle_234.Load();
			SheetBattle_235.Load();
			SheetBattle_236.Load();
			SheetBattle_237.Load();
			SheetBattle_238.Load();
			SheetBattle_239.Load();
			SheetBattle_240.Load();
			SheetBattle_241.Load();
			SheetBattle_242.Load();
			SheetBattle_243.Load();
			SheetBattle_244.Load();
			SheetBattle_245.Load();
			SheetBattle_246.Load();
			SheetBattle_247.Load();
			SheetBattle_248.Load();
			SheetBattle_249.Load();
			SheetBattle_250.Load();
			SheetBattle_251.Load();
			SheetBattle_252.Load();
			SheetBattle_253.Load();
			SheetBattle_254.Load();
			SheetBattle_255.Load();
			SheetBattle_256.Load();
			SheetBattle_257.Load();
			SheetBattle_258.Load();
			SheetBattle_259.Load();
			SheetBattle_260.Load();
			SheetBattle_261.Load();
			SheetBattle_262.Load();
			SheetBattle_263.Load();
			SheetBattle_264.Load();
			SheetBattle_265.Load();
			SheetBattle_266.Load();
			SheetBattle_267.Load();
			SheetBattle_268.Load();
			SheetBattle_269.Load();
			SheetBattle_270.Load();
			SheetBattle_271.Load();
			SheetBattle_272.Load();
			SheetBattle_273.Load();
			SheetBattle_274.Load();
			SheetBattle_275.Load();
			SheetBattle_276.Load();
			SheetBattle_277.Load();
			SheetBattle_278.Load();
			SheetBattle_279.Load();
			SheetBattle_280.Load();
			SheetBattle_281.Load();
			SheetBattle_282.Load();
			SheetBattle_283.Load();
			SheetBattle_284.Load();
			SheetBattle_285.Load();
			SheetBattle_286.Load();
			SheetBattle_287.Load();
			SheetBattle_288.Load();
			SheetBattle_289.Load();
			SheetBattle_290.Load();
			SheetBattle_291.Load();
			SheetBattle_292.Load();
			SheetBattle_293.Load();
			SheetBattle_294.Load();
			SheetBattle_295.Load();
			SheetBattle_296.Load();
			SheetBattle_297.Load();
			SheetBattle_298.Load();
			SheetBattle_299.Load();
			SheetBattle_300.Load();
			SheetBattle_301.Load();
			SheetBattle_302.Load();
			SheetBattle_303.Load();
			SheetBattle_304.Load();
			SheetBattle_305.Load();
			SheetBattle_306.Load();
			SheetBattle_307.Load();
			SheetBattle_308.Load();
			SheetBattle_309.Load();
			SheetBattle_310.Load();
			SheetBattle_311.Load();
			SheetBattle_312.Load();
			SheetBattle_313.Load();
			SheetBattle_314.Load();
			SheetBattle_315.Load();
			SheetBattle_316.Load();
			SheetBattle_317.Load();
			SheetBattle_318.Load();
			SheetBattle_319.Load();
			SheetBattle_320.Load();
			SheetBattle_321.Load();
			SheetBattle_322.Load();
			SheetBattle_323.Load();
			SheetBattle_324.Load();
			SheetBattle_325.Load();
			SheetBattle_326.Load();
			SheetBattle_327.Load();
			SheetBattle_328.Load();
			SheetBattle_329.Load();
			SheetBattle_330.Load();
			SheetBattle_331.Load();
			SheetBattle_332.Load();
			SheetBattle_333.Load();
			SheetBattle_334.Load();
			SheetBattle_335.Load();
			SheetBattle_336.Load();
			SheetBattle_337.Load();
			SheetBattle_338.Load();
			SheetBattle_339.Load();
			SheetBattle_340.Load();
			SheetBattle_341.Load();
			SheetBattle_342.Load();
			SheetBattle_343.Load();
			SheetBattle_344.Load();
			SheetBattle_345.Load();
			SheetBattle_346.Load();
			SheetBattle_347.Load();
			SheetBattle_348.Load();
			SheetBattle_349.Load();
			SheetBattle_350.Load();
			SheetBattle_351.Load();
			SheetBattle_352.Load();
			SheetBattle_353.Load();
			SheetBattle_354.Load();
			SheetBattle_355.Load();
			SheetBattle_356.Load();
			SheetBattle_357.Load();
			SheetBattle_358.Load();
			SheetBattle_359.Load();
			SheetBattle_360.Load();
			SheetBattle_361.Load();
			SheetBattle_362.Load();
			SheetBattle_363.Load();
			SheetBattle_364.Load();
			SheetBattle_365.Load();
			SheetBattle_366.Load();
			SheetBattle_367.Load();
			SheetBattle_368.Load();
			SheetBattle_369.Load();
			SheetBattle_370.Load();
			SheetBattle_371.Load();
			SheetBattle_372.Load();
			SheetBattle_373.Load();
			SheetBattle_374.Load();
			SheetBattle_375.Load();
			SheetBattle_376.Load();
			SheetBattle_377.Load();
			SheetBattle_378.Load();
			SheetBattle_379.Load();
			SheetBattle_380.Load();
			SheetBattle_381.Load();
			SheetBattle_382.Load();
			SheetBattle_383.Load();
			SheetBattle_384.Load();
			SheetBattle_385.Load();
			SheetBattle_386.Load();
			SheetBattle_387.Load();
			SheetBattle_388.Load();
			SheetBattle_389.Load();
			SheetBattle_390.Load();
			SheetBattle_391.Load();
			SheetBattle_392.Load();
			SheetBattle_393.Load();
			SheetBattle_394.Load();
			SheetBattle_395.Load();
			SheetBattle_396.Load();
			SheetBattle_397.Load();
			SheetBattle_398.Load();
			SheetBattle_399.Load();
			SheetBattle_400.Load();
			SheetBattle_401.Load();
			SheetBattle_402.Load();
			SheetBattle_403.Load();
			SheetBattle_404.Load();
			SheetBattle_405.Load();
			SheetBattle_406.Load();
			SheetBattle_407.Load();
			SheetBattle_408.Load();
			SheetBattle_409.Load();
			SheetBattle_410.Load();
			SheetBattle_411.Load();
			SheetBattle_412.Load();
			SheetBattle_413.Load();
			SheetBattle_414.Load();
			SheetBattle_415.Load();
			SheetBattle_416.Load();
			SheetBattle_417.Load();
			SheetBattle_418.Load();
			SheetBattle_419.Load();
			SheetBattle_420.Load();
			SheetBattle_421.Load();
			SheetBattle_422.Load();
			SheetBattle_423.Load();
			SheetBattle_424.Load();
			SheetBattle_425.Load();
			SheetBattle_426.Load();
			SheetBattle_427.Load();
			SheetBattle_428.Load();
			SheetBattle_429.Load();
			SheetBattle_430.Load();
			SheetBattle_431.Load();
			SheetBattle_432.Load();
			SheetBattle_433.Load();
			SheetBattle_434.Load();
			SheetBattle_435.Load();
			SheetBattle_436.Load();
			SheetBattle_437.Load();
			SheetBattle_438.Load();
			SheetBattle_439.Load();
			SheetBattle_440.Load();
			SheetBattle_441.Load();
			SheetBattle_442.Load();
			SheetBattle_443.Load();
			SheetBattle_444.Load();
			SheetBattle_445.Load();
			SheetBattle_446.Load();
			SheetBattle_447.Load();
			SheetBattle_448.Load();
			SheetBattle_449.Load();
			SheetBattle_450.Load();
			SheetBattle_451.Load();
			SheetBattle_452.Load();
			SheetBattle_453.Load();
			SheetBattle_454.Load();
			SheetBattle_455.Load();
			SheetBattle_456.Load();
			SheetBattle_457.Load();
			SheetBattle_458.Load();
			SheetBattle_459.Load();
			SheetBattle_460.Load();
			SheetBattle_461.Load();
			SheetBattle_462.Load();
			SheetBattle_463.Load();
			SheetBattle_464.Load();
			SheetBattle_465.Load();
			SheetBattle_466.Load();
			SheetBattle_467.Load();
			SheetBattle_468.Load();
			SheetBattle_469.Load();
			SheetBattle_470.Load();
			SheetBattle_471.Load();
			SheetBattle_472.Load();
			SheetBattle_473.Load();
			SheetBattle_474.Load();
			SheetBattle_475.Load();
			SheetBattle_476.Load();
			SheetBattle_477.Load();
			SheetBattle_478.Load();
			SheetBattle_479.Load();
			SheetBattle_480.Load();
			SheetBattle_481.Load();
			SheetBattle_482.Load();
			SheetBattle_483.Load();
			SheetBattle_484.Load();
			SheetBattle_485.Load();
			SheetBattle_486.Load();
			SheetBattle_487.Load();
			SheetBattle_488.Load();
			SheetBattle_489.Load();
			SheetBattle_490.Load();
			SheetBattle_491.Load();
			SheetBattle_492.Load();
			SheetBattle_493.Load();
			SheetBattle_494.Load();
			SheetBattle_495.Load();
			SheetBattle_496.Load();
			SheetBattle_497.Load();
			SheetBattle_498.Load();
			SheetBattle_499.Load();
			SheetBattle_500.Load();

		};

		void UnLoad()
		{
			SheetBattle_1.UnLoad();
			SheetBattle_2.UnLoad();
			SheetBattle_3.UnLoad();
			SheetBattle_4.UnLoad();
			SheetBattle_5.UnLoad();
			SheetBattle_6.UnLoad();
			SheetBattle_7.UnLoad();
			SheetBattle_8.UnLoad();
			SheetBattle_9.UnLoad();
			SheetBattle_10.UnLoad();
			SheetBattle_11.UnLoad();
			SheetBattle_12.UnLoad();
			SheetBattle_13.UnLoad();
			SheetBattle_14.UnLoad();
			SheetBattle_15.UnLoad();
			SheetBattle_16.UnLoad();
			SheetBattle_17.UnLoad();
			SheetBattle_18.UnLoad();
			SheetBattle_19.UnLoad();
			SheetBattle_20.UnLoad();
			SheetBattle_21.UnLoad();
			SheetBattle_22.UnLoad();
			SheetBattle_23.UnLoad();
			SheetBattle_24.UnLoad();
			SheetBattle_25.UnLoad();
			SheetBattle_26.UnLoad();
			SheetBattle_27.UnLoad();
			SheetBattle_28.UnLoad();
			SheetBattle_29.UnLoad();
			SheetBattle_30.UnLoad();
			SheetBattle_31.UnLoad();
			SheetBattle_32.UnLoad();
			SheetBattle_33.UnLoad();
			SheetBattle_34.UnLoad();
			SheetBattle_35.UnLoad();
			SheetBattle_36.UnLoad();
			SheetBattle_37.UnLoad();
			SheetBattle_38.UnLoad();
			SheetBattle_39.UnLoad();
			SheetBattle_40.UnLoad();
			SheetBattle_41.UnLoad();
			SheetBattle_42.UnLoad();
			SheetBattle_43.UnLoad();
			SheetBattle_44.UnLoad();
			SheetBattle_45.UnLoad();
			SheetBattle_46.UnLoad();
			SheetBattle_47.UnLoad();
			SheetBattle_48.UnLoad();
			SheetBattle_49.UnLoad();
			SheetBattle_50.UnLoad();
			SheetBattle_51.UnLoad();
			SheetBattle_52.UnLoad();
			SheetBattle_53.UnLoad();
			SheetBattle_54.UnLoad();
			SheetBattle_55.UnLoad();
			SheetBattle_56.UnLoad();
			SheetBattle_57.UnLoad();
			SheetBattle_58.UnLoad();
			SheetBattle_59.UnLoad();
			SheetBattle_60.UnLoad();
			SheetBattle_61.UnLoad();
			SheetBattle_62.UnLoad();
			SheetBattle_63.UnLoad();
			SheetBattle_64.UnLoad();
			SheetBattle_65.UnLoad();
			SheetBattle_66.UnLoad();
			SheetBattle_67.UnLoad();
			SheetBattle_68.UnLoad();
			SheetBattle_69.UnLoad();
			SheetBattle_70.UnLoad();
			SheetBattle_71.UnLoad();
			SheetBattle_72.UnLoad();
			SheetBattle_73.UnLoad();
			SheetBattle_74.UnLoad();
			SheetBattle_75.UnLoad();
			SheetBattle_76.UnLoad();
			SheetBattle_77.UnLoad();
			SheetBattle_78.UnLoad();
			SheetBattle_79.UnLoad();
			SheetBattle_80.UnLoad();
			SheetBattle_81.UnLoad();
			SheetBattle_82.UnLoad();
			SheetBattle_83.UnLoad();
			SheetBattle_84.UnLoad();
			SheetBattle_85.UnLoad();
			SheetBattle_86.UnLoad();
			SheetBattle_87.UnLoad();
			SheetBattle_88.UnLoad();
			SheetBattle_89.UnLoad();
			SheetBattle_90.UnLoad();
			SheetBattle_91.UnLoad();
			SheetBattle_92.UnLoad();
			SheetBattle_93.UnLoad();
			SheetBattle_94.UnLoad();
			SheetBattle_95.UnLoad();
			SheetBattle_96.UnLoad();
			SheetBattle_97.UnLoad();
			SheetBattle_98.UnLoad();
			SheetBattle_99.UnLoad();
			SheetBattle_100.UnLoad();
			SheetBattle_101.UnLoad();
			SheetBattle_102.UnLoad();
			SheetBattle_103.UnLoad();
			SheetBattle_104.UnLoad();
			SheetBattle_105.UnLoad();
			SheetBattle_106.UnLoad();
			SheetBattle_107.UnLoad();
			SheetBattle_108.UnLoad();
			SheetBattle_109.UnLoad();
			SheetBattle_110.UnLoad();
			SheetBattle_111.UnLoad();
			SheetBattle_112.UnLoad();
			SheetBattle_113.UnLoad();
			SheetBattle_114.UnLoad();
			SheetBattle_115.UnLoad();
			SheetBattle_116.UnLoad();
			SheetBattle_117.UnLoad();
			SheetBattle_118.UnLoad();
			SheetBattle_119.UnLoad();
			SheetBattle_120.UnLoad();
			SheetBattle_121.UnLoad();
			SheetBattle_122.UnLoad();
			SheetBattle_123.UnLoad();
			SheetBattle_124.UnLoad();
			SheetBattle_125.UnLoad();
			SheetBattle_126.UnLoad();
			SheetBattle_127.UnLoad();
			SheetBattle_128.UnLoad();
			SheetBattle_129.UnLoad();
			SheetBattle_130.UnLoad();
			SheetBattle_131.UnLoad();
			SheetBattle_132.UnLoad();
			SheetBattle_133.UnLoad();
			SheetBattle_134.UnLoad();
			SheetBattle_135.UnLoad();
			SheetBattle_136.UnLoad();
			SheetBattle_137.UnLoad();
			SheetBattle_138.UnLoad();
			SheetBattle_139.UnLoad();
			SheetBattle_140.UnLoad();
			SheetBattle_141.UnLoad();
			SheetBattle_142.UnLoad();
			SheetBattle_143.UnLoad();
			SheetBattle_144.UnLoad();
			SheetBattle_145.UnLoad();
			SheetBattle_146.UnLoad();
			SheetBattle_147.UnLoad();
			SheetBattle_148.UnLoad();
			SheetBattle_149.UnLoad();
			SheetBattle_150.UnLoad();
			SheetBattle_151.UnLoad();
			SheetBattle_152.UnLoad();
			SheetBattle_153.UnLoad();
			SheetBattle_154.UnLoad();
			SheetBattle_155.UnLoad();
			SheetBattle_156.UnLoad();
			SheetBattle_157.UnLoad();
			SheetBattle_158.UnLoad();
			SheetBattle_159.UnLoad();
			SheetBattle_160.UnLoad();
			SheetBattle_161.UnLoad();
			SheetBattle_162.UnLoad();
			SheetBattle_163.UnLoad();
			SheetBattle_164.UnLoad();
			SheetBattle_165.UnLoad();
			SheetBattle_166.UnLoad();
			SheetBattle_167.UnLoad();
			SheetBattle_168.UnLoad();
			SheetBattle_169.UnLoad();
			SheetBattle_170.UnLoad();
			SheetBattle_171.UnLoad();
			SheetBattle_172.UnLoad();
			SheetBattle_173.UnLoad();
			SheetBattle_174.UnLoad();
			SheetBattle_175.UnLoad();
			SheetBattle_176.UnLoad();
			SheetBattle_177.UnLoad();
			SheetBattle_178.UnLoad();
			SheetBattle_179.UnLoad();
			SheetBattle_180.UnLoad();
			SheetBattle_181.UnLoad();
			SheetBattle_182.UnLoad();
			SheetBattle_183.UnLoad();
			SheetBattle_184.UnLoad();
			SheetBattle_185.UnLoad();
			SheetBattle_186.UnLoad();
			SheetBattle_187.UnLoad();
			SheetBattle_188.UnLoad();
			SheetBattle_189.UnLoad();
			SheetBattle_190.UnLoad();
			SheetBattle_191.UnLoad();
			SheetBattle_192.UnLoad();
			SheetBattle_193.UnLoad();
			SheetBattle_194.UnLoad();
			SheetBattle_195.UnLoad();
			SheetBattle_196.UnLoad();
			SheetBattle_197.UnLoad();
			SheetBattle_198.UnLoad();
			SheetBattle_199.UnLoad();
			SheetBattle_200.UnLoad();
			SheetBattle_201.UnLoad();
			SheetBattle_202.UnLoad();
			SheetBattle_203.UnLoad();
			SheetBattle_204.UnLoad();
			SheetBattle_205.UnLoad();
			SheetBattle_206.UnLoad();
			SheetBattle_207.UnLoad();
			SheetBattle_208.UnLoad();
			SheetBattle_209.UnLoad();
			SheetBattle_210.UnLoad();
			SheetBattle_211.UnLoad();
			SheetBattle_212.UnLoad();
			SheetBattle_213.UnLoad();
			SheetBattle_214.UnLoad();
			SheetBattle_215.UnLoad();
			SheetBattle_216.UnLoad();
			SheetBattle_217.UnLoad();
			SheetBattle_218.UnLoad();
			SheetBattle_219.UnLoad();
			SheetBattle_220.UnLoad();
			SheetBattle_221.UnLoad();
			SheetBattle_222.UnLoad();
			SheetBattle_223.UnLoad();
			SheetBattle_224.UnLoad();
			SheetBattle_225.UnLoad();
			SheetBattle_226.UnLoad();
			SheetBattle_227.UnLoad();
			SheetBattle_228.UnLoad();
			SheetBattle_229.UnLoad();
			SheetBattle_230.UnLoad();
			SheetBattle_231.UnLoad();
			SheetBattle_232.UnLoad();
			SheetBattle_233.UnLoad();
			SheetBattle_234.UnLoad();
			SheetBattle_235.UnLoad();
			SheetBattle_236.UnLoad();
			SheetBattle_237.UnLoad();
			SheetBattle_238.UnLoad();
			SheetBattle_239.UnLoad();
			SheetBattle_240.UnLoad();
			SheetBattle_241.UnLoad();
			SheetBattle_242.UnLoad();
			SheetBattle_243.UnLoad();
			SheetBattle_244.UnLoad();
			SheetBattle_245.UnLoad();
			SheetBattle_246.UnLoad();
			SheetBattle_247.UnLoad();
			SheetBattle_248.UnLoad();
			SheetBattle_249.UnLoad();
			SheetBattle_250.UnLoad();
			SheetBattle_251.UnLoad();
			SheetBattle_252.UnLoad();
			SheetBattle_253.UnLoad();
			SheetBattle_254.UnLoad();
			SheetBattle_255.UnLoad();
			SheetBattle_256.UnLoad();
			SheetBattle_257.UnLoad();
			SheetBattle_258.UnLoad();
			SheetBattle_259.UnLoad();
			SheetBattle_260.UnLoad();
			SheetBattle_261.UnLoad();
			SheetBattle_262.UnLoad();
			SheetBattle_263.UnLoad();
			SheetBattle_264.UnLoad();
			SheetBattle_265.UnLoad();
			SheetBattle_266.UnLoad();
			SheetBattle_267.UnLoad();
			SheetBattle_268.UnLoad();
			SheetBattle_269.UnLoad();
			SheetBattle_270.UnLoad();
			SheetBattle_271.UnLoad();
			SheetBattle_272.UnLoad();
			SheetBattle_273.UnLoad();
			SheetBattle_274.UnLoad();
			SheetBattle_275.UnLoad();
			SheetBattle_276.UnLoad();
			SheetBattle_277.UnLoad();
			SheetBattle_278.UnLoad();
			SheetBattle_279.UnLoad();
			SheetBattle_280.UnLoad();
			SheetBattle_281.UnLoad();
			SheetBattle_282.UnLoad();
			SheetBattle_283.UnLoad();
			SheetBattle_284.UnLoad();
			SheetBattle_285.UnLoad();
			SheetBattle_286.UnLoad();
			SheetBattle_287.UnLoad();
			SheetBattle_288.UnLoad();
			SheetBattle_289.UnLoad();
			SheetBattle_290.UnLoad();
			SheetBattle_291.UnLoad();
			SheetBattle_292.UnLoad();
			SheetBattle_293.UnLoad();
			SheetBattle_294.UnLoad();
			SheetBattle_295.UnLoad();
			SheetBattle_296.UnLoad();
			SheetBattle_297.UnLoad();
			SheetBattle_298.UnLoad();
			SheetBattle_299.UnLoad();
			SheetBattle_300.UnLoad();
			SheetBattle_301.UnLoad();
			SheetBattle_302.UnLoad();
			SheetBattle_303.UnLoad();
			SheetBattle_304.UnLoad();
			SheetBattle_305.UnLoad();
			SheetBattle_306.UnLoad();
			SheetBattle_307.UnLoad();
			SheetBattle_308.UnLoad();
			SheetBattle_309.UnLoad();
			SheetBattle_310.UnLoad();
			SheetBattle_311.UnLoad();
			SheetBattle_312.UnLoad();
			SheetBattle_313.UnLoad();
			SheetBattle_314.UnLoad();
			SheetBattle_315.UnLoad();
			SheetBattle_316.UnLoad();
			SheetBattle_317.UnLoad();
			SheetBattle_318.UnLoad();
			SheetBattle_319.UnLoad();
			SheetBattle_320.UnLoad();
			SheetBattle_321.UnLoad();
			SheetBattle_322.UnLoad();
			SheetBattle_323.UnLoad();
			SheetBattle_324.UnLoad();
			SheetBattle_325.UnLoad();
			SheetBattle_326.UnLoad();
			SheetBattle_327.UnLoad();
			SheetBattle_328.UnLoad();
			SheetBattle_329.UnLoad();
			SheetBattle_330.UnLoad();
			SheetBattle_331.UnLoad();
			SheetBattle_332.UnLoad();
			SheetBattle_333.UnLoad();
			SheetBattle_334.UnLoad();
			SheetBattle_335.UnLoad();
			SheetBattle_336.UnLoad();
			SheetBattle_337.UnLoad();
			SheetBattle_338.UnLoad();
			SheetBattle_339.UnLoad();
			SheetBattle_340.UnLoad();
			SheetBattle_341.UnLoad();
			SheetBattle_342.UnLoad();
			SheetBattle_343.UnLoad();
			SheetBattle_344.UnLoad();
			SheetBattle_345.UnLoad();
			SheetBattle_346.UnLoad();
			SheetBattle_347.UnLoad();
			SheetBattle_348.UnLoad();
			SheetBattle_349.UnLoad();
			SheetBattle_350.UnLoad();
			SheetBattle_351.UnLoad();
			SheetBattle_352.UnLoad();
			SheetBattle_353.UnLoad();
			SheetBattle_354.UnLoad();
			SheetBattle_355.UnLoad();
			SheetBattle_356.UnLoad();
			SheetBattle_357.UnLoad();
			SheetBattle_358.UnLoad();
			SheetBattle_359.UnLoad();
			SheetBattle_360.UnLoad();
			SheetBattle_361.UnLoad();
			SheetBattle_362.UnLoad();
			SheetBattle_363.UnLoad();
			SheetBattle_364.UnLoad();
			SheetBattle_365.UnLoad();
			SheetBattle_366.UnLoad();
			SheetBattle_367.UnLoad();
			SheetBattle_368.UnLoad();
			SheetBattle_369.UnLoad();
			SheetBattle_370.UnLoad();
			SheetBattle_371.UnLoad();
			SheetBattle_372.UnLoad();
			SheetBattle_373.UnLoad();
			SheetBattle_374.UnLoad();
			SheetBattle_375.UnLoad();
			SheetBattle_376.UnLoad();
			SheetBattle_377.UnLoad();
			SheetBattle_378.UnLoad();
			SheetBattle_379.UnLoad();
			SheetBattle_380.UnLoad();
			SheetBattle_381.UnLoad();
			SheetBattle_382.UnLoad();
			SheetBattle_383.UnLoad();
			SheetBattle_384.UnLoad();
			SheetBattle_385.UnLoad();
			SheetBattle_386.UnLoad();
			SheetBattle_387.UnLoad();
			SheetBattle_388.UnLoad();
			SheetBattle_389.UnLoad();
			SheetBattle_390.UnLoad();
			SheetBattle_391.UnLoad();
			SheetBattle_392.UnLoad();
			SheetBattle_393.UnLoad();
			SheetBattle_394.UnLoad();
			SheetBattle_395.UnLoad();
			SheetBattle_396.UnLoad();
			SheetBattle_397.UnLoad();
			SheetBattle_398.UnLoad();
			SheetBattle_399.UnLoad();
			SheetBattle_400.UnLoad();
			SheetBattle_401.UnLoad();
			SheetBattle_402.UnLoad();
			SheetBattle_403.UnLoad();
			SheetBattle_404.UnLoad();
			SheetBattle_405.UnLoad();
			SheetBattle_406.UnLoad();
			SheetBattle_407.UnLoad();
			SheetBattle_408.UnLoad();
			SheetBattle_409.UnLoad();
			SheetBattle_410.UnLoad();
			SheetBattle_411.UnLoad();
			SheetBattle_412.UnLoad();
			SheetBattle_413.UnLoad();
			SheetBattle_414.UnLoad();
			SheetBattle_415.UnLoad();
			SheetBattle_416.UnLoad();
			SheetBattle_417.UnLoad();
			SheetBattle_418.UnLoad();
			SheetBattle_419.UnLoad();
			SheetBattle_420.UnLoad();
			SheetBattle_421.UnLoad();
			SheetBattle_422.UnLoad();
			SheetBattle_423.UnLoad();
			SheetBattle_424.UnLoad();
			SheetBattle_425.UnLoad();
			SheetBattle_426.UnLoad();
			SheetBattle_427.UnLoad();
			SheetBattle_428.UnLoad();
			SheetBattle_429.UnLoad();
			SheetBattle_430.UnLoad();
			SheetBattle_431.UnLoad();
			SheetBattle_432.UnLoad();
			SheetBattle_433.UnLoad();
			SheetBattle_434.UnLoad();
			SheetBattle_435.UnLoad();
			SheetBattle_436.UnLoad();
			SheetBattle_437.UnLoad();
			SheetBattle_438.UnLoad();
			SheetBattle_439.UnLoad();
			SheetBattle_440.UnLoad();
			SheetBattle_441.UnLoad();
			SheetBattle_442.UnLoad();
			SheetBattle_443.UnLoad();
			SheetBattle_444.UnLoad();
			SheetBattle_445.UnLoad();
			SheetBattle_446.UnLoad();
			SheetBattle_447.UnLoad();
			SheetBattle_448.UnLoad();
			SheetBattle_449.UnLoad();
			SheetBattle_450.UnLoad();
			SheetBattle_451.UnLoad();
			SheetBattle_452.UnLoad();
			SheetBattle_453.UnLoad();
			SheetBattle_454.UnLoad();
			SheetBattle_455.UnLoad();
			SheetBattle_456.UnLoad();
			SheetBattle_457.UnLoad();
			SheetBattle_458.UnLoad();
			SheetBattle_459.UnLoad();
			SheetBattle_460.UnLoad();
			SheetBattle_461.UnLoad();
			SheetBattle_462.UnLoad();
			SheetBattle_463.UnLoad();
			SheetBattle_464.UnLoad();
			SheetBattle_465.UnLoad();
			SheetBattle_466.UnLoad();
			SheetBattle_467.UnLoad();
			SheetBattle_468.UnLoad();
			SheetBattle_469.UnLoad();
			SheetBattle_470.UnLoad();
			SheetBattle_471.UnLoad();
			SheetBattle_472.UnLoad();
			SheetBattle_473.UnLoad();
			SheetBattle_474.UnLoad();
			SheetBattle_475.UnLoad();
			SheetBattle_476.UnLoad();
			SheetBattle_477.UnLoad();
			SheetBattle_478.UnLoad();
			SheetBattle_479.UnLoad();
			SheetBattle_480.UnLoad();
			SheetBattle_481.UnLoad();
			SheetBattle_482.UnLoad();
			SheetBattle_483.UnLoad();
			SheetBattle_484.UnLoad();
			SheetBattle_485.UnLoad();
			SheetBattle_486.UnLoad();
			SheetBattle_487.UnLoad();
			SheetBattle_488.UnLoad();
			SheetBattle_489.UnLoad();
			SheetBattle_490.UnLoad();
			SheetBattle_491.UnLoad();
			SheetBattle_492.UnLoad();
			SheetBattle_493.UnLoad();
			SheetBattle_494.UnLoad();
			SheetBattle_495.UnLoad();
			SheetBattle_496.UnLoad();
			SheetBattle_497.UnLoad();
			SheetBattle_498.UnLoad();
			SheetBattle_499.UnLoad();
			SheetBattle_500.UnLoad();

		};

		class CSheetBattle_1
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_1()
			{
				int32Value._beginByte = 226370;
				int64Value._beginByte = 226978;
				stringValue._beginByte = 227386;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_2
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_2()
			{
				int32Value._beginByte = 227544;
				int64Value._beginByte = 227960;
				stringValue._beginByte = 228240;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_3
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_3()
			{
				int32Value._beginByte = 228350;
				int64Value._beginByte = 229030;
				stringValue._beginByte = 229486;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_4
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_4()
			{
				int32Value._beginByte = 229665;
				int64Value._beginByte = 230369;
				stringValue._beginByte = 230841;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_5()
			{
				int32Value._beginByte = 231037;
				int64Value._beginByte = 231909;
				stringValue._beginByte = 232493;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_6
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_6()
			{
				int32Value._beginByte = 232728;
				int64Value._beginByte = 233792;
				stringValue._beginByte = 234504;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_7
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_7()
			{
				int32Value._beginByte = 234786;
				int64Value._beginByte = 235946;
				stringValue._beginByte = 236722;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_8
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_8()
			{
				int32Value._beginByte = 237034;
				int64Value._beginByte = 238146;
				stringValue._beginByte = 238890;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_9
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_9()
			{
				int32Value._beginByte = 239189;
				int64Value._beginByte = 240397;
				stringValue._beginByte = 241205;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_10
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_10()
			{
				int32Value._beginByte = 241532;
				int64Value._beginByte = 242860;
				stringValue._beginByte = 243748;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_11
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_11()
			{
				int32Value._beginByte = 244108;
				int64Value._beginByte = 245532;
				stringValue._beginByte = 246484;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_12
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_12()
			{
				int32Value._beginByte = 246869;
				int64Value._beginByte = 248029;
				stringValue._beginByte = 248805;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_13
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_13()
			{
				int32Value._beginByte = 249120;
				int64Value._beginByte = 250328;
				stringValue._beginByte = 251136;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_14
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_14()
			{
				int32Value._beginByte = 251462;
				int64Value._beginByte = 252694;
				stringValue._beginByte = 253518;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_15
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_15()
			{
				int32Value._beginByte = 253856;
				int64Value._beginByte = 255064;
				stringValue._beginByte = 255872;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_16
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_16()
			{
				int32Value._beginByte = 256200;
				int64Value._beginByte = 257096;
				stringValue._beginByte = 257696;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_17
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_17()
			{
				int32Value._beginByte = 257943;
				int64Value._beginByte = 258815;
				stringValue._beginByte = 259399;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_18
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_18()
			{
				int32Value._beginByte = 259636;
				int64Value._beginByte = 260820;
				stringValue._beginByte = 261612;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_19
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_19()
			{
				int32Value._beginByte = 261929;
				int64Value._beginByte = 262969;
				stringValue._beginByte = 263665;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_20
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_20()
			{
				int32Value._beginByte = 263950;
				int64Value._beginByte = 265110;
				stringValue._beginByte = 265886;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_21
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_21()
			{
				int32Value._beginByte = 266203;
				int64Value._beginByte = 267339;
				stringValue._beginByte = 268099;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_22
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_22()
			{
				int32Value._beginByte = 268408;
				int64Value._beginByte = 269376;
				stringValue._beginByte = 270024;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_23
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_23()
			{
				int32Value._beginByte = 270287;
				int64Value._beginByte = 271495;
				stringValue._beginByte = 272303;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_24
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_24()
			{
				int32Value._beginByte = 272629;
				int64Value._beginByte = 274053;
				stringValue._beginByte = 275005;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_25
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_25()
			{
				int32Value._beginByte = 275395;
				int64Value._beginByte = 276603;
				stringValue._beginByte = 277411;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_26
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_26()
			{
				int32Value._beginByte = 277739;
				int64Value._beginByte = 278899;
				stringValue._beginByte = 279675;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_27
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_27()
			{
				int32Value._beginByte = 280003;
				int64Value._beginByte = 281043;
				stringValue._beginByte = 281739;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_28
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_28()
			{
				int32Value._beginByte = 282029;
				int64Value._beginByte = 283021;
				stringValue._beginByte = 283685;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_29
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_29()
			{
				int32Value._beginByte = 283963;
				int64Value._beginByte = 285147;
				stringValue._beginByte = 285939;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_30
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_30()
			{
				int32Value._beginByte = 286263;
				int64Value._beginByte = 287543;
				stringValue._beginByte = 288399;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_31
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_31()
			{
				int32Value._beginByte = 288755;
				int64Value._beginByte = 290011;
				stringValue._beginByte = 290851;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_32
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_32()
			{
				int32Value._beginByte = 291191;
				int64Value._beginByte = 292231;
				stringValue._beginByte = 292927;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_33
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_33()
			{
				int32Value._beginByte = 293215;
				int64Value._beginByte = 294519;
				stringValue._beginByte = 295391;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_34
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_34()
			{
				int32Value._beginByte = 295745;
				int64Value._beginByte = 296857;
				stringValue._beginByte = 297601;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_35
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_35()
			{
				int32Value._beginByte = 297906;
				int64Value._beginByte = 299018;
				stringValue._beginByte = 299762;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_36
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_36()
			{
				int32Value._beginByte = 300071;
				int64Value._beginByte = 301183;
				stringValue._beginByte = 301927;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_37
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_37()
			{
				int32Value._beginByte = 302233;
				int64Value._beginByte = 303441;
				stringValue._beginByte = 304249;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_38
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_38()
			{
				int32Value._beginByte = 304579;
				int64Value._beginByte = 305739;
				stringValue._beginByte = 306515;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_39
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_39()
			{
				int32Value._beginByte = 306828;
				int64Value._beginByte = 308060;
				stringValue._beginByte = 308884;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_40
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_40()
			{
				int32Value._beginByte = 309222;
				int64Value._beginByte = 310574;
				stringValue._beginByte = 311478;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_41
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_41()
			{
				int32Value._beginByte = 311859;
				int64Value._beginByte = 313091;
				stringValue._beginByte = 313915;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_42
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_42()
			{
				int32Value._beginByte = 314277;
				int64Value._beginByte = 315245;
				stringValue._beginByte = 315893;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_43
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_43()
			{
				int32Value._beginByte = 316176;
				int64Value._beginByte = 317312;
				stringValue._beginByte = 318072;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_44
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_44()
			{
				int32Value._beginByte = 318404;
				int64Value._beginByte = 319444;
				stringValue._beginByte = 320140;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_45
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_45()
			{
				int32Value._beginByte = 320446;
				int64Value._beginByte = 321678;
				stringValue._beginByte = 322502;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_46
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_46()
			{
				int32Value._beginByte = 322863;
				int64Value._beginByte = 324119;
				stringValue._beginByte = 324959;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_47
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_47()
			{
				int32Value._beginByte = 325314;
				int64Value._beginByte = 326426;
				stringValue._beginByte = 327170;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_48
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_48()
			{
				int32Value._beginByte = 327497;
				int64Value._beginByte = 328729;
				stringValue._beginByte = 329553;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_49
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_49()
			{
				int32Value._beginByte = 329917;
				int64Value._beginByte = 331077;
				stringValue._beginByte = 331853;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_50
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_50()
			{
				int32Value._beginByte = 332194;
				int64Value._beginByte = 333522;
				stringValue._beginByte = 334410;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_51
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_51()
			{
				int32Value._beginByte = 334797;
				int64Value._beginByte = 335981;
				stringValue._beginByte = 336773;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_52
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_52()
			{
				int32Value._beginByte = 337121;
				int64Value._beginByte = 338521;
				stringValue._beginByte = 339457;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_53
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_53()
			{
				int32Value._beginByte = 339866;
				int64Value._beginByte = 341122;
				stringValue._beginByte = 341962;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_54
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_54()
			{
				int32Value._beginByte = 342329;
				int64Value._beginByte = 343489;
				stringValue._beginByte = 344265;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_55
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_55()
			{
				int32Value._beginByte = 344607;
				int64Value._beginByte = 346031;
				stringValue._beginByte = 346983;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_56
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_56()
			{
				int32Value._beginByte = 347399;
				int64Value._beginByte = 348511;
				stringValue._beginByte = 349255;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_57
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_57()
			{
				int32Value._beginByte = 349571;
				int64Value._beginByte = 350707;
				stringValue._beginByte = 351467;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_58
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_58()
			{
				int32Value._beginByte = 351800;
				int64Value._beginByte = 352984;
				stringValue._beginByte = 353776;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_59
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_59()
			{
				int32Value._beginByte = 354109;
				int64Value._beginByte = 355269;
				stringValue._beginByte = 356045;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_60
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_60()
			{
				int32Value._beginByte = 356387;
				int64Value._beginByte = 357595;
				stringValue._beginByte = 358403;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_61
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_61()
			{
				int32Value._beginByte = 358754;
				int64Value._beginByte = 360082;
				stringValue._beginByte = 360970;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_62
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_62()
			{
				int32Value._beginByte = 361354;
				int64Value._beginByte = 362514;
				stringValue._beginByte = 363290;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_63
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_63()
			{
				int32Value._beginByte = 363631;
				int64Value._beginByte = 364839;
				stringValue._beginByte = 365647;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_64
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_64()
			{
				int32Value._beginByte = 366003;
				int64Value._beginByte = 367451;
				stringValue._beginByte = 368419;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_65
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_65()
			{
				int32Value._beginByte = 368829;
				int64Value._beginByte = 370133;
				stringValue._beginByte = 371005;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_66
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_66()
			{
				int32Value._beginByte = 371373;
				int64Value._beginByte = 373109;
				stringValue._beginByte = 374269;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_67
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_67()
			{
				int32Value._beginByte = 374773;
				int64Value._beginByte = 376413;
				stringValue._beginByte = 377509;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_68
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_68()
			{
				int32Value._beginByte = 377989;
				int64Value._beginByte = 379077;
				stringValue._beginByte = 379805;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_69
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_69()
			{
				int32Value._beginByte = 380117;
				int64Value._beginByte = 381133;
				stringValue._beginByte = 381813;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_70
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_70()
			{
				int32Value._beginByte = 382108;
				int64Value._beginByte = 384060;
				stringValue._beginByte = 385364;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_71
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_71()
			{
				int32Value._beginByte = 385933;
				int64Value._beginByte = 387237;
				stringValue._beginByte = 388109;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_72
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_72()
			{
				int32Value._beginByte = 388477;
				int64Value._beginByte = 389685;
				stringValue._beginByte = 390493;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_73
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_73()
			{
				int32Value._beginByte = 390854;
				int64Value._beginByte = 392278;
				stringValue._beginByte = 393230;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_74
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_74()
			{
				int32Value._beginByte = 393654;
				int64Value._beginByte = 395678;
				stringValue._beginByte = 397030;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_75
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_75()
			{
				int32Value._beginByte = 397602;
				int64Value._beginByte = 399338;
				stringValue._beginByte = 400498;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_76
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_76()
			{
				int32Value._beginByte = 401000;
				int64Value._beginByte = 403216;
				stringValue._beginByte = 404696;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_77
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_77()
			{
				int32Value._beginByte = 405337;
				int64Value._beginByte = 407289;
				stringValue._beginByte = 408593;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_78
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_78()
			{
				int32Value._beginByte = 409157;
				int64Value._beginByte = 410269;
				stringValue._beginByte = 411013;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_79
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_79()
			{
				int32Value._beginByte = 411333;
				int64Value._beginByte = 413549;
				stringValue._beginByte = 415029;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_80
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_80()
			{
				int32Value._beginByte = 415671;
				int64Value._beginByte = 417743;
				stringValue._beginByte = 419127;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_81
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_81()
			{
				int32Value._beginByte = 419724;
				int64Value._beginByte = 421676;
				stringValue._beginByte = 422980;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_82
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_82()
			{
				int32Value._beginByte = 423539;
				int64Value._beginByte = 425443;
				stringValue._beginByte = 426715;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_83
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_83()
			{
				int32Value._beginByte = 427263;
				int64Value._beginByte = 429479;
				stringValue._beginByte = 430959;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_84
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_84()
			{
				int32Value._beginByte = 431601;
				int64Value._beginByte = 433577;
				stringValue._beginByte = 434897;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_85
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_85()
			{
				int32Value._beginByte = 435466;
				int64Value._beginByte = 437490;
				stringValue._beginByte = 438842;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_86
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_86()
			{
				int32Value._beginByte = 439409;
				int64Value._beginByte = 441625;
				stringValue._beginByte = 443105;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_87
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_87()
			{
				int32Value._beginByte = 443745;
				int64Value._beginByte = 445697;
				stringValue._beginByte = 447001;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_88
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_88()
			{
				int32Value._beginByte = 447574;
				int64Value._beginByte = 449526;
				stringValue._beginByte = 450830;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_89
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_89()
			{
				int32Value._beginByte = 451402;
				int64Value._beginByte = 452802;
				stringValue._beginByte = 453738;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_90
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_90()
			{
				int32Value._beginByte = 454155;
				int64Value._beginByte = 456371;
				stringValue._beginByte = 457851;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_91
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_91()
			{
				int32Value._beginByte = 458493;
				int64Value._beginByte = 460445;
				stringValue._beginByte = 461749;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_92
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_92()
			{
				int32Value._beginByte = 462321;
				int64Value._beginByte = 464297;
				stringValue._beginByte = 465617;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_93
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_93()
			{
				int32Value._beginByte = 466189;
				int64Value._beginByte = 468117;
				stringValue._beginByte = 469405;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_94
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_94()
			{
				int32Value._beginByte = 469960;
				int64Value._beginByte = 471096;
				stringValue._beginByte = 471856;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_95
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_95()
			{
				int32Value._beginByte = 472184;
				int64Value._beginByte = 474400;
				stringValue._beginByte = 475880;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_96
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_96()
			{
				int32Value._beginByte = 476519;
				int64Value._beginByte = 477919;
				stringValue._beginByte = 478855;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_97
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_97()
			{
				int32Value._beginByte = 479272;
				int64Value._beginByte = 481224;
				stringValue._beginByte = 482528;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_98
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_98()
			{
				int32Value._beginByte = 483100;
				int64Value._beginByte = 484500;
				stringValue._beginByte = 485436;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_99
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_99()
			{
				int32Value._beginByte = 485854;
				int64Value._beginByte = 488070;
				stringValue._beginByte = 489550;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_100
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_100()
			{
				int32Value._beginByte = 490193;
				int64Value._beginByte = 492145;
				stringValue._beginByte = 493449;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_101
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_101()
			{
				int32Value._beginByte = 494009;
				int64Value._beginByte = 495337;
				stringValue._beginByte = 496225;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_102
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_102()
			{
				int32Value._beginByte = 496599;
				int64Value._beginByte = 497807;
				stringValue._beginByte = 498615;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_103
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_103()
			{
				int32Value._beginByte = 498976;
				int64Value._beginByte = 500400;
				stringValue._beginByte = 501352;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_104
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_104()
			{
				int32Value._beginByte = 501776;
				int64Value._beginByte = 503800;
				stringValue._beginByte = 505152;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_105
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_105()
			{
				int32Value._beginByte = 505730;
				int64Value._beginByte = 507466;
				stringValue._beginByte = 508626;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_106
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_106()
			{
				int32Value._beginByte = 509130;
				int64Value._beginByte = 511346;
				stringValue._beginByte = 512826;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_107
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_107()
			{
				int32Value._beginByte = 513467;
				int64Value._beginByte = 515419;
				stringValue._beginByte = 516723;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_108
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_108()
			{
				int32Value._beginByte = 517287;
				int64Value._beginByte = 518399;
				stringValue._beginByte = 519143;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_109
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_109()
			{
				int32Value._beginByte = 519465;
				int64Value._beginByte = 521681;
				stringValue._beginByte = 523161;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_110
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_110()
			{
				int32Value._beginByte = 523803;
				int64Value._beginByte = 525875;
				stringValue._beginByte = 527259;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_111
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_111()
			{
				int32Value._beginByte = 527859;
				int64Value._beginByte = 529835;
				stringValue._beginByte = 531155;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_112
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_112()
			{
				int32Value._beginByte = 531721;
				int64Value._beginByte = 533649;
				stringValue._beginByte = 534937;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_113
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_113()
			{
				int32Value._beginByte = 535492;
				int64Value._beginByte = 537708;
				stringValue._beginByte = 539188;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_114
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_114()
			{
				int32Value._beginByte = 539829;
				int64Value._beginByte = 541805;
				stringValue._beginByte = 543125;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_115
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_115()
			{
				int32Value._beginByte = 543695;
				int64Value._beginByte = 545719;
				stringValue._beginByte = 547071;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_116
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_116()
			{
				int32Value._beginByte = 547638;
				int64Value._beginByte = 549854;
				stringValue._beginByte = 551334;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_117
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_117()
			{
				int32Value._beginByte = 551975;
				int64Value._beginByte = 553927;
				stringValue._beginByte = 555231;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_118
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_118()
			{
				int32Value._beginByte = 555804;
				int64Value._beginByte = 557756;
				stringValue._beginByte = 559060;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_119
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_119()
			{
				int32Value._beginByte = 559632;
				int64Value._beginByte = 561032;
				stringValue._beginByte = 561968;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_120
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_120()
			{
				int32Value._beginByte = 562384;
				int64Value._beginByte = 564600;
				stringValue._beginByte = 566080;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_121
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_121()
			{
				int32Value._beginByte = 566722;
				int64Value._beginByte = 568674;
				stringValue._beginByte = 569978;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_122
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_122()
			{
				int32Value._beginByte = 570549;
				int64Value._beginByte = 572525;
				stringValue._beginByte = 573845;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_123
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_123()
			{
				int32Value._beginByte = 574417;
				int64Value._beginByte = 576345;
				stringValue._beginByte = 577633;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_124
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_124()
			{
				int32Value._beginByte = 578188;
				int64Value._beginByte = 579324;
				stringValue._beginByte = 580084;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_125
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_125()
			{
				int32Value._beginByte = 580413;
				int64Value._beginByte = 582629;
				stringValue._beginByte = 584109;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_126
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_126()
			{
				int32Value._beginByte = 584748;
				int64Value._beginByte = 586148;
				stringValue._beginByte = 587084;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_127
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_127()
			{
				int32Value._beginByte = 587500;
				int64Value._beginByte = 589452;
				stringValue._beginByte = 590756;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_128
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_128()
			{
				int32Value._beginByte = 591329;
				int64Value._beginByte = 592729;
				stringValue._beginByte = 593665;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_129
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_129()
			{
				int32Value._beginByte = 594083;
				int64Value._beginByte = 596299;
				stringValue._beginByte = 597779;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_130
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_130()
			{
				int32Value._beginByte = 598422;
				int64Value._beginByte = 600374;
				stringValue._beginByte = 601678;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_131
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_131()
			{
				int32Value._beginByte = 602238;
				int64Value._beginByte = 604214;
				stringValue._beginByte = 605534;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_132
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_132()
			{
				int32Value._beginByte = 606100;
				int64Value._beginByte = 608172;
				stringValue._beginByte = 609556;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_133
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_133()
			{
				int32Value._beginByte = 610154;
				int64Value._beginByte = 612370;
				stringValue._beginByte = 613850;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_134
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_134()
			{
				int32Value._beginByte = 614492;
				int64Value._beginByte = 616468;
				stringValue._beginByte = 617788;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_135
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_135()
			{
				int32Value._beginByte = 618358;
				int64Value._beginByte = 620382;
				stringValue._beginByte = 621734;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_136
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_136()
			{
				int32Value._beginByte = 622301;
				int64Value._beginByte = 624541;
				stringValue._beginByte = 626037;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_137
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_137()
			{
				int32Value._beginByte = 626685;
				int64Value._beginByte = 628661;
				stringValue._beginByte = 629981;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_138
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_138()
			{
				int32Value._beginByte = 630560;
				int64Value._beginByte = 632536;
				stringValue._beginByte = 633856;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_139
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_139()
			{
				int32Value._beginByte = 634435;
				int64Value._beginByte = 635859;
				stringValue._beginByte = 636811;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_140
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_140()
			{
				int32Value._beginByte = 637235;
				int64Value._beginByte = 639451;
				stringValue._beginByte = 640931;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_141
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_141()
			{
				int32Value._beginByte = 641573;
				int64Value._beginByte = 643525;
				stringValue._beginByte = 644829;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_142
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_142()
			{
				int32Value._beginByte = 645401;
				int64Value._beginByte = 647401;
				stringValue._beginByte = 648737;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_143
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_143()
			{
				int32Value._beginByte = 649317;
				int64Value._beginByte = 651245;
				stringValue._beginByte = 652533;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_144
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_144()
			{
				int32Value._beginByte = 653088;
				int64Value._beginByte = 654224;
				stringValue._beginByte = 654984;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_145
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_145()
			{
				int32Value._beginByte = 655313;
				int64Value._beginByte = 657577;
				stringValue._beginByte = 659089;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_146
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_146()
			{
				int32Value._beginByte = 659742;
				int64Value._beginByte = 661190;
				stringValue._beginByte = 662158;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_147
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_147()
			{
				int32Value._beginByte = 662589;
				int64Value._beginByte = 664541;
				stringValue._beginByte = 665845;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_148
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_148()
			{
				int32Value._beginByte = 666418;
				int64Value._beginByte = 667866;
				stringValue._beginByte = 668834;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_149
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_149()
			{
				int32Value._beginByte = 669266;
				int64Value._beginByte = 671482;
				stringValue._beginByte = 672962;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_150
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_150()
			{
				int32Value._beginByte = 673604;
				int64Value._beginByte = 675676;
				stringValue._beginByte = 677060;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_151
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_151()
			{
				int32Value._beginByte = 677655;
				int64Value._beginByte = 679607;
				stringValue._beginByte = 680911;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_152
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_152()
			{
				int32Value._beginByte = 681483;
				int64Value._beginByte = 683483;
				stringValue._beginByte = 684819;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_153
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_153()
			{
				int32Value._beginByte = 685399;
				int64Value._beginByte = 687327;
				stringValue._beginByte = 688615;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_154
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_154()
			{
				int32Value._beginByte = 689170;
				int64Value._beginByte = 690306;
				stringValue._beginByte = 691066;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_155
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_155()
			{
				int32Value._beginByte = 691395;
				int64Value._beginByte = 693659;
				stringValue._beginByte = 695171;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_156
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_156()
			{
				int32Value._beginByte = 695824;
				int64Value._beginByte = 697272;
				stringValue._beginByte = 698240;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_157
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_157()
			{
				int32Value._beginByte = 698671;
				int64Value._beginByte = 700623;
				stringValue._beginByte = 701927;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_158
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_158()
			{
				int32Value._beginByte = 702500;
				int64Value._beginByte = 703948;
				stringValue._beginByte = 704916;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_159
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_159()
			{
				int32Value._beginByte = 705348;
				int64Value._beginByte = 707564;
				stringValue._beginByte = 709044;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_160
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_160()
			{
				int32Value._beginByte = 709687;
				int64Value._beginByte = 711759;
				stringValue._beginByte = 713143;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_161
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_161()
			{
				int32Value._beginByte = 713738;
				int64Value._beginByte = 715690;
				stringValue._beginByte = 716994;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_162
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_162()
			{
				int32Value._beginByte = 717566;
				int64Value._beginByte = 719566;
				stringValue._beginByte = 720902;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_163
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_163()
			{
				int32Value._beginByte = 721482;
				int64Value._beginByte = 723410;
				stringValue._beginByte = 724698;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_164
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_164()
			{
				int32Value._beginByte = 725253;
				int64Value._beginByte = 726389;
				stringValue._beginByte = 727149;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_165
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_165()
			{
				int32Value._beginByte = 727477;
				int64Value._beginByte = 729741;
				stringValue._beginByte = 731253;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_166
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_166()
			{
				int32Value._beginByte = 731906;
				int64Value._beginByte = 733354;
				stringValue._beginByte = 734322;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_167
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_167()
			{
				int32Value._beginByte = 734753;
				int64Value._beginByte = 736705;
				stringValue._beginByte = 738009;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_168
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_168()
			{
				int32Value._beginByte = 738582;
				int64Value._beginByte = 740030;
				stringValue._beginByte = 740998;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_169
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_169()
			{
				int32Value._beginByte = 741430;
				int64Value._beginByte = 743646;
				stringValue._beginByte = 745126;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_170
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_170()
			{
				int32Value._beginByte = 745769;
				int64Value._beginByte = 747841;
				stringValue._beginByte = 749225;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_171
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_171()
			{
				int32Value._beginByte = 749820;
				int64Value._beginByte = 751772;
				stringValue._beginByte = 753076;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_172
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_172()
			{
				int32Value._beginByte = 753648;
				int64Value._beginByte = 755648;
				stringValue._beginByte = 756984;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_173
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_173()
			{
				int32Value._beginByte = 757564;
				int64Value._beginByte = 759516;
				stringValue._beginByte = 760820;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_174
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_174()
			{
				int32Value._beginByte = 761392;
				int64Value._beginByte = 762528;
				stringValue._beginByte = 763288;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_175
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_175()
			{
				int32Value._beginByte = 763617;
				int64Value._beginByte = 765881;
				stringValue._beginByte = 767393;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_176
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_176()
			{
				int32Value._beginByte = 768045;
				int64Value._beginByte = 769493;
				stringValue._beginByte = 770461;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_177
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_177()
			{
				int32Value._beginByte = 770892;
				int64Value._beginByte = 772844;
				stringValue._beginByte = 774148;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_178
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_178()
			{
				int32Value._beginByte = 774721;
				int64Value._beginByte = 776169;
				stringValue._beginByte = 777137;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_179
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_179()
			{
				int32Value._beginByte = 777569;
				int64Value._beginByte = 779785;
				stringValue._beginByte = 781265;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_180
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_180()
			{
				int32Value._beginByte = 781908;
				int64Value._beginByte = 783980;
				stringValue._beginByte = 785364;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_181
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_181()
			{
				int32Value._beginByte = 785958;
				int64Value._beginByte = 787910;
				stringValue._beginByte = 789214;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_182
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_182()
			{
				int32Value._beginByte = 789786;
				int64Value._beginByte = 791786;
				stringValue._beginByte = 793122;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_183
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_183()
			{
				int32Value._beginByte = 793702;
				int64Value._beginByte = 795654;
				stringValue._beginByte = 796958;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_184
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_184()
			{
				int32Value._beginByte = 797529;
				int64Value._beginByte = 798665;
				stringValue._beginByte = 799425;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_185
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_185()
			{
				int32Value._beginByte = 799754;
				int64Value._beginByte = 802018;
				stringValue._beginByte = 803530;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_186
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_186()
			{
				int32Value._beginByte = 804182;
				int64Value._beginByte = 805630;
				stringValue._beginByte = 806598;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_187
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_187()
			{
				int32Value._beginByte = 807029;
				int64Value._beginByte = 808981;
				stringValue._beginByte = 810285;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_188
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_188()
			{
				int32Value._beginByte = 810858;
				int64Value._beginByte = 812306;
				stringValue._beginByte = 813274;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_189
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_189()
			{
				int32Value._beginByte = 813706;
				int64Value._beginByte = 815922;
				stringValue._beginByte = 817402;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_190
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_190()
			{
				int32Value._beginByte = 818045;
				int64Value._beginByte = 820117;
				stringValue._beginByte = 821501;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_191
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_191()
			{
				int32Value._beginByte = 822095;
				int64Value._beginByte = 824047;
				stringValue._beginByte = 825351;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_192
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_192()
			{
				int32Value._beginByte = 825923;
				int64Value._beginByte = 827923;
				stringValue._beginByte = 829259;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_193
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_193()
			{
				int32Value._beginByte = 829839;
				int64Value._beginByte = 831791;
				stringValue._beginByte = 833095;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_194
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_194()
			{
				int32Value._beginByte = 833667;
				int64Value._beginByte = 834803;
				stringValue._beginByte = 835563;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_195
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_195()
			{
				int32Value._beginByte = 835892;
				int64Value._beginByte = 838156;
				stringValue._beginByte = 839668;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_196
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_196()
			{
				int32Value._beginByte = 840321;
				int64Value._beginByte = 841769;
				stringValue._beginByte = 842737;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_197
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_197()
			{
				int32Value._beginByte = 843168;
				int64Value._beginByte = 845120;
				stringValue._beginByte = 846424;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_198
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_198()
			{
				int32Value._beginByte = 846997;
				int64Value._beginByte = 848445;
				stringValue._beginByte = 849413;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_199
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_199()
			{
				int32Value._beginByte = 849845;
				int64Value._beginByte = 852061;
				stringValue._beginByte = 853541;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_200
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_200()
			{
				int32Value._beginByte = 854184;
				int64Value._beginByte = 856256;
				stringValue._beginByte = 857640;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_201
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_201()
			{
				int32Value._beginByte = 858235;
				int64Value._beginByte = 860187;
				stringValue._beginByte = 861491;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_202
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_202()
			{
				int32Value._beginByte = 862063;
				int64Value._beginByte = 864063;
				stringValue._beginByte = 865399;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_203
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_203()
			{
				int32Value._beginByte = 865979;
				int64Value._beginByte = 867931;
				stringValue._beginByte = 869235;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_204
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_204()
			{
				int32Value._beginByte = 869807;
				int64Value._beginByte = 870943;
				stringValue._beginByte = 871703;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_205
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_205()
			{
				int32Value._beginByte = 872032;
				int64Value._beginByte = 874296;
				stringValue._beginByte = 875808;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_206
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_206()
			{
				int32Value._beginByte = 876461;
				int64Value._beginByte = 877909;
				stringValue._beginByte = 878877;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_207
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_207()
			{
				int32Value._beginByte = 879308;
				int64Value._beginByte = 881260;
				stringValue._beginByte = 882564;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_208
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_208()
			{
				int32Value._beginByte = 883137;
				int64Value._beginByte = 884585;
				stringValue._beginByte = 885553;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_209
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_209()
			{
				int32Value._beginByte = 885985;
				int64Value._beginByte = 888249;
				stringValue._beginByte = 889761;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_210
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_210()
			{
				int32Value._beginByte = 890418;
				int64Value._beginByte = 892490;
				stringValue._beginByte = 893874;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_211
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_211()
			{
				int32Value._beginByte = 894469;
				int64Value._beginByte = 896421;
				stringValue._beginByte = 897725;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_212
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_212()
			{
				int32Value._beginByte = 898297;
				int64Value._beginByte = 900297;
				stringValue._beginByte = 901633;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_213
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_213()
			{
				int32Value._beginByte = 902213;
				int64Value._beginByte = 904165;
				stringValue._beginByte = 905469;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_214
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_214()
			{
				int32Value._beginByte = 906041;
				int64Value._beginByte = 907177;
				stringValue._beginByte = 907937;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_215
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_215()
			{
				int32Value._beginByte = 908266;
				int64Value._beginByte = 910530;
				stringValue._beginByte = 912042;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_216
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_216()
			{
				int32Value._beginByte = 912695;
				int64Value._beginByte = 914143;
				stringValue._beginByte = 915111;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_217
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_217()
			{
				int32Value._beginByte = 915542;
				int64Value._beginByte = 917494;
				stringValue._beginByte = 918798;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_218
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_218()
			{
				int32Value._beginByte = 919371;
				int64Value._beginByte = 920819;
				stringValue._beginByte = 921787;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_219
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_219()
			{
				int32Value._beginByte = 922219;
				int64Value._beginByte = 924483;
				stringValue._beginByte = 925995;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_220
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_220()
			{
				int32Value._beginByte = 926652;
				int64Value._beginByte = 928724;
				stringValue._beginByte = 930108;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_221
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_221()
			{
				int32Value._beginByte = 930703;
				int64Value._beginByte = 932655;
				stringValue._beginByte = 933959;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_222
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_222()
			{
				int32Value._beginByte = 934531;
				int64Value._beginByte = 936531;
				stringValue._beginByte = 937867;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_223
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_223()
			{
				int32Value._beginByte = 938447;
				int64Value._beginByte = 940399;
				stringValue._beginByte = 941703;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_224
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_224()
			{
				int32Value._beginByte = 942274;
				int64Value._beginByte = 943410;
				stringValue._beginByte = 944170;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_225
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_225()
			{
				int32Value._beginByte = 944499;
				int64Value._beginByte = 946763;
				stringValue._beginByte = 948275;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_226
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_226()
			{
				int32Value._beginByte = 948928;
				int64Value._beginByte = 950376;
				stringValue._beginByte = 951344;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_227
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_227()
			{
				int32Value._beginByte = 951775;
				int64Value._beginByte = 953727;
				stringValue._beginByte = 955031;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_228
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_228()
			{
				int32Value._beginByte = 955604;
				int64Value._beginByte = 957052;
				stringValue._beginByte = 958020;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_229
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_229()
			{
				int32Value._beginByte = 958452;
				int64Value._beginByte = 960716;
				stringValue._beginByte = 962228;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_230
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_230()
			{
				int32Value._beginByte = 962885;
				int64Value._beginByte = 964957;
				stringValue._beginByte = 966341;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_231
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_231()
			{
				int32Value._beginByte = 966936;
				int64Value._beginByte = 968888;
				stringValue._beginByte = 970192;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_232
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_232()
			{
				int32Value._beginByte = 970764;
				int64Value._beginByte = 972764;
				stringValue._beginByte = 974100;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_233
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_233()
			{
				int32Value._beginByte = 974680;
				int64Value._beginByte = 976632;
				stringValue._beginByte = 977936;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_234
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_234()
			{
				int32Value._beginByte = 978508;
				int64Value._beginByte = 979644;
				stringValue._beginByte = 980404;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_235
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_235()
			{
				int32Value._beginByte = 980733;
				int64Value._beginByte = 982997;
				stringValue._beginByte = 984509;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_236
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_236()
			{
				int32Value._beginByte = 985162;
				int64Value._beginByte = 986610;
				stringValue._beginByte = 987578;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_237
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_237()
			{
				int32Value._beginByte = 988009;
				int64Value._beginByte = 989961;
				stringValue._beginByte = 991265;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_238
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_238()
			{
				int32Value._beginByte = 991838;
				int64Value._beginByte = 993286;
				stringValue._beginByte = 994254;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_239
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_239()
			{
				int32Value._beginByte = 994686;
				int64Value._beginByte = 996950;
				stringValue._beginByte = 998462;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_240
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_240()
			{
				int32Value._beginByte = 999119;
				int64Value._beginByte = 1001191;
				stringValue._beginByte = 1002575;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_241
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_241()
			{
				int32Value._beginByte = 1003170;
				int64Value._beginByte = 1005122;
				stringValue._beginByte = 1006426;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_242
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_242()
			{
				int32Value._beginByte = 1006998;
				int64Value._beginByte = 1008998;
				stringValue._beginByte = 1010334;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_243
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_243()
			{
				int32Value._beginByte = 1010914;
				int64Value._beginByte = 1012866;
				stringValue._beginByte = 1014170;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_244
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_244()
			{
				int32Value._beginByte = 1014742;
				int64Value._beginByte = 1015878;
				stringValue._beginByte = 1016638;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_245
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_245()
			{
				int32Value._beginByte = 1016967;
				int64Value._beginByte = 1019231;
				stringValue._beginByte = 1020743;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_246
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_246()
			{
				int32Value._beginByte = 1021396;
				int64Value._beginByte = 1022844;
				stringValue._beginByte = 1023812;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_247
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_247()
			{
				int32Value._beginByte = 1024243;
				int64Value._beginByte = 1026195;
				stringValue._beginByte = 1027499;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_248
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_248()
			{
				int32Value._beginByte = 1028072;
				int64Value._beginByte = 1029520;
				stringValue._beginByte = 1030488;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_249
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_249()
			{
				int32Value._beginByte = 1030920;
				int64Value._beginByte = 1033184;
				stringValue._beginByte = 1034696;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_250
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_250()
			{
				int32Value._beginByte = 1035353;
				int64Value._beginByte = 1037425;
				stringValue._beginByte = 1038809;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_251
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_251()
			{
				int32Value._beginByte = 1039404;
				int64Value._beginByte = 1041356;
				stringValue._beginByte = 1042660;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_252
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_252()
			{
				int32Value._beginByte = 1043232;
				int64Value._beginByte = 1045232;
				stringValue._beginByte = 1046568;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_253
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_253()
			{
				int32Value._beginByte = 1047148;
				int64Value._beginByte = 1049100;
				stringValue._beginByte = 1050404;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_254
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_254()
			{
				int32Value._beginByte = 1050976;
				int64Value._beginByte = 1052112;
				stringValue._beginByte = 1052872;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_255
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_255()
			{
				int32Value._beginByte = 1053201;
				int64Value._beginByte = 1055465;
				stringValue._beginByte = 1056977;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_256
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_256()
			{
				int32Value._beginByte = 1057630;
				int64Value._beginByte = 1059078;
				stringValue._beginByte = 1060046;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_257
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_257()
			{
				int32Value._beginByte = 1060477;
				int64Value._beginByte = 1062429;
				stringValue._beginByte = 1063733;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_258
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_258()
			{
				int32Value._beginByte = 1064306;
				int64Value._beginByte = 1065754;
				stringValue._beginByte = 1066722;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_259
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_259()
			{
				int32Value._beginByte = 1067154;
				int64Value._beginByte = 1069418;
				stringValue._beginByte = 1070930;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_260
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_260()
			{
				int32Value._beginByte = 1071587;
				int64Value._beginByte = 1073659;
				stringValue._beginByte = 1075043;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_261
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_261()
			{
				int32Value._beginByte = 1075638;
				int64Value._beginByte = 1077590;
				stringValue._beginByte = 1078894;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_262
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_262()
			{
				int32Value._beginByte = 1079466;
				int64Value._beginByte = 1081466;
				stringValue._beginByte = 1082802;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_263
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_263()
			{
				int32Value._beginByte = 1083382;
				int64Value._beginByte = 1085334;
				stringValue._beginByte = 1086638;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_264
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_264()
			{
				int32Value._beginByte = 1087210;
				int64Value._beginByte = 1088346;
				stringValue._beginByte = 1089106;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_265
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_265()
			{
				int32Value._beginByte = 1089435;
				int64Value._beginByte = 1091699;
				stringValue._beginByte = 1093211;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_266
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_266()
			{
				int32Value._beginByte = 1093864;
				int64Value._beginByte = 1095312;
				stringValue._beginByte = 1096280;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_267
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_267()
			{
				int32Value._beginByte = 1096711;
				int64Value._beginByte = 1098663;
				stringValue._beginByte = 1099967;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_268
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_268()
			{
				int32Value._beginByte = 1100540;
				int64Value._beginByte = 1101988;
				stringValue._beginByte = 1102956;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_269
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_269()
			{
				int32Value._beginByte = 1103388;
				int64Value._beginByte = 1105652;
				stringValue._beginByte = 1107164;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_270
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_270()
			{
				int32Value._beginByte = 1107821;
				int64Value._beginByte = 1109893;
				stringValue._beginByte = 1111277;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_271
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_271()
			{
				int32Value._beginByte = 1111872;
				int64Value._beginByte = 1113824;
				stringValue._beginByte = 1115128;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_272
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_272()
			{
				int32Value._beginByte = 1115700;
				int64Value._beginByte = 1117700;
				stringValue._beginByte = 1119036;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_273
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_273()
			{
				int32Value._beginByte = 1119616;
				int64Value._beginByte = 1121568;
				stringValue._beginByte = 1122872;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_274
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_274()
			{
				int32Value._beginByte = 1123444;
				int64Value._beginByte = 1124580;
				stringValue._beginByte = 1125340;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_275
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_275()
			{
				int32Value._beginByte = 1125669;
				int64Value._beginByte = 1127933;
				stringValue._beginByte = 1129445;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_276
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_276()
			{
				int32Value._beginByte = 1130098;
				int64Value._beginByte = 1131546;
				stringValue._beginByte = 1132514;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_277
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_277()
			{
				int32Value._beginByte = 1132945;
				int64Value._beginByte = 1134897;
				stringValue._beginByte = 1136201;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_278
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_278()
			{
				int32Value._beginByte = 1136774;
				int64Value._beginByte = 1138222;
				stringValue._beginByte = 1139190;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_279
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_279()
			{
				int32Value._beginByte = 1139622;
				int64Value._beginByte = 1141886;
				stringValue._beginByte = 1143398;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_280
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_280()
			{
				int32Value._beginByte = 1144055;
				int64Value._beginByte = 1146127;
				stringValue._beginByte = 1147511;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_281
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_281()
			{
				int32Value._beginByte = 1148106;
				int64Value._beginByte = 1150058;
				stringValue._beginByte = 1151362;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_282
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_282()
			{
				int32Value._beginByte = 1151934;
				int64Value._beginByte = 1153934;
				stringValue._beginByte = 1155270;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_283
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_283()
			{
				int32Value._beginByte = 1155850;
				int64Value._beginByte = 1157802;
				stringValue._beginByte = 1159106;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_284
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_284()
			{
				int32Value._beginByte = 1159678;
				int64Value._beginByte = 1160814;
				stringValue._beginByte = 1161574;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_285
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_285()
			{
				int32Value._beginByte = 1161903;
				int64Value._beginByte = 1164167;
				stringValue._beginByte = 1165679;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_286
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_286()
			{
				int32Value._beginByte = 1166332;
				int64Value._beginByte = 1167780;
				stringValue._beginByte = 1168748;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_287
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_287()
			{
				int32Value._beginByte = 1169179;
				int64Value._beginByte = 1171131;
				stringValue._beginByte = 1172435;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_288
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_288()
			{
				int32Value._beginByte = 1173008;
				int64Value._beginByte = 1174456;
				stringValue._beginByte = 1175424;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_289
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_289()
			{
				int32Value._beginByte = 1175856;
				int64Value._beginByte = 1178120;
				stringValue._beginByte = 1179632;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_290
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_290()
			{
				int32Value._beginByte = 1180289;
				int64Value._beginByte = 1182361;
				stringValue._beginByte = 1183745;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_291
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_291()
			{
				int32Value._beginByte = 1184340;
				int64Value._beginByte = 1186292;
				stringValue._beginByte = 1187596;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_292
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_292()
			{
				int32Value._beginByte = 1188168;
				int64Value._beginByte = 1190168;
				stringValue._beginByte = 1191504;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_293
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_293()
			{
				int32Value._beginByte = 1192084;
				int64Value._beginByte = 1194036;
				stringValue._beginByte = 1195340;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_294
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_294()
			{
				int32Value._beginByte = 1195912;
				int64Value._beginByte = 1197048;
				stringValue._beginByte = 1197808;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_295
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_295()
			{
				int32Value._beginByte = 1198137;
				int64Value._beginByte = 1200401;
				stringValue._beginByte = 1201913;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_296
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_296()
			{
				int32Value._beginByte = 1202566;
				int64Value._beginByte = 1204014;
				stringValue._beginByte = 1204982;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_297
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_297()
			{
				int32Value._beginByte = 1205413;
				int64Value._beginByte = 1207365;
				stringValue._beginByte = 1208669;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_298
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_298()
			{
				int32Value._beginByte = 1209242;
				int64Value._beginByte = 1210690;
				stringValue._beginByte = 1211658;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_299
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_299()
			{
				int32Value._beginByte = 1212090;
				int64Value._beginByte = 1214354;
				stringValue._beginByte = 1215866;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_300
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_300()
			{
				int32Value._beginByte = 1216523;
				int64Value._beginByte = 1218595;
				stringValue._beginByte = 1219979;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_301
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_301()
			{
				int32Value._beginByte = 1220574;
				int64Value._beginByte = 1222526;
				stringValue._beginByte = 1223830;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_302
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_302()
			{
				int32Value._beginByte = 1224402;
				int64Value._beginByte = 1226402;
				stringValue._beginByte = 1227738;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_303
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_303()
			{
				int32Value._beginByte = 1228318;
				int64Value._beginByte = 1230270;
				stringValue._beginByte = 1231574;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_304
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_304()
			{
				int32Value._beginByte = 1232146;
				int64Value._beginByte = 1233282;
				stringValue._beginByte = 1234042;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_305
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_305()
			{
				int32Value._beginByte = 1234371;
				int64Value._beginByte = 1236635;
				stringValue._beginByte = 1238147;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_306
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_306()
			{
				int32Value._beginByte = 1238800;
				int64Value._beginByte = 1240248;
				stringValue._beginByte = 1241216;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_307
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_307()
			{
				int32Value._beginByte = 1241647;
				int64Value._beginByte = 1243599;
				stringValue._beginByte = 1244903;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_308
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_308()
			{
				int32Value._beginByte = 1245476;
				int64Value._beginByte = 1246924;
				stringValue._beginByte = 1247892;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_309
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_309()
			{
				int32Value._beginByte = 1248324;
				int64Value._beginByte = 1250588;
				stringValue._beginByte = 1252100;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_310
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_310()
			{
				int32Value._beginByte = 1252757;
				int64Value._beginByte = 1254829;
				stringValue._beginByte = 1256213;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_311
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_311()
			{
				int32Value._beginByte = 1256808;
				int64Value._beginByte = 1258760;
				stringValue._beginByte = 1260064;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_312
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_312()
			{
				int32Value._beginByte = 1260636;
				int64Value._beginByte = 1262636;
				stringValue._beginByte = 1263972;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_313
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_313()
			{
				int32Value._beginByte = 1264552;
				int64Value._beginByte = 1266504;
				stringValue._beginByte = 1267808;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_314
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_314()
			{
				int32Value._beginByte = 1268380;
				int64Value._beginByte = 1269516;
				stringValue._beginByte = 1270276;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_315
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_315()
			{
				int32Value._beginByte = 1270605;
				int64Value._beginByte = 1272869;
				stringValue._beginByte = 1274381;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_316
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_316()
			{
				int32Value._beginByte = 1275034;
				int64Value._beginByte = 1276482;
				stringValue._beginByte = 1277450;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_317
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_317()
			{
				int32Value._beginByte = 1277881;
				int64Value._beginByte = 1279833;
				stringValue._beginByte = 1281137;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_318
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_318()
			{
				int32Value._beginByte = 1281710;
				int64Value._beginByte = 1283158;
				stringValue._beginByte = 1284126;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_319
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_319()
			{
				int32Value._beginByte = 1284558;
				int64Value._beginByte = 1286822;
				stringValue._beginByte = 1288334;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_320
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_320()
			{
				int32Value._beginByte = 1288991;
				int64Value._beginByte = 1291063;
				stringValue._beginByte = 1292447;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_321
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_321()
			{
				int32Value._beginByte = 1293042;
				int64Value._beginByte = 1294994;
				stringValue._beginByte = 1296298;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_322
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_322()
			{
				int32Value._beginByte = 1296870;
				int64Value._beginByte = 1298870;
				stringValue._beginByte = 1300206;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_323
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_323()
			{
				int32Value._beginByte = 1300786;
				int64Value._beginByte = 1302738;
				stringValue._beginByte = 1304042;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_324
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_324()
			{
				int32Value._beginByte = 1304614;
				int64Value._beginByte = 1305750;
				stringValue._beginByte = 1306510;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_325
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_325()
			{
				int32Value._beginByte = 1306839;
				int64Value._beginByte = 1309103;
				stringValue._beginByte = 1310615;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_326
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_326()
			{
				int32Value._beginByte = 1311268;
				int64Value._beginByte = 1312716;
				stringValue._beginByte = 1313684;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_327
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_327()
			{
				int32Value._beginByte = 1314115;
				int64Value._beginByte = 1316067;
				stringValue._beginByte = 1317371;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_328
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_328()
			{
				int32Value._beginByte = 1317944;
				int64Value._beginByte = 1319392;
				stringValue._beginByte = 1320360;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_329
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_329()
			{
				int32Value._beginByte = 1320792;
				int64Value._beginByte = 1323056;
				stringValue._beginByte = 1324568;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_330
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_330()
			{
				int32Value._beginByte = 1325225;
				int64Value._beginByte = 1327297;
				stringValue._beginByte = 1328681;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_331
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_331()
			{
				int32Value._beginByte = 1329276;
				int64Value._beginByte = 1331228;
				stringValue._beginByte = 1332532;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_332
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_332()
			{
				int32Value._beginByte = 1333104;
				int64Value._beginByte = 1335104;
				stringValue._beginByte = 1336440;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_333
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_333()
			{
				int32Value._beginByte = 1337020;
				int64Value._beginByte = 1338972;
				stringValue._beginByte = 1340276;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_334
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_334()
			{
				int32Value._beginByte = 1340848;
				int64Value._beginByte = 1341984;
				stringValue._beginByte = 1342744;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_335
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_335()
			{
				int32Value._beginByte = 1343073;
				int64Value._beginByte = 1345337;
				stringValue._beginByte = 1346849;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_336
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_336()
			{
				int32Value._beginByte = 1347503;
				int64Value._beginByte = 1348951;
				stringValue._beginByte = 1349919;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_337
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_337()
			{
				int32Value._beginByte = 1350350;
				int64Value._beginByte = 1352302;
				stringValue._beginByte = 1353606;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_338
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_338()
			{
				int32Value._beginByte = 1354179;
				int64Value._beginByte = 1355627;
				stringValue._beginByte = 1356595;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_339
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_339()
			{
				int32Value._beginByte = 1357027;
				int64Value._beginByte = 1359291;
				stringValue._beginByte = 1360803;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_340
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_340()
			{
				int32Value._beginByte = 1361460;
				int64Value._beginByte = 1363532;
				stringValue._beginByte = 1364916;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_341
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_341()
			{
				int32Value._beginByte = 1365511;
				int64Value._beginByte = 1367463;
				stringValue._beginByte = 1368767;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_342
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_342()
			{
				int32Value._beginByte = 1369339;
				int64Value._beginByte = 1371339;
				stringValue._beginByte = 1372675;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_343
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_343()
			{
				int32Value._beginByte = 1373255;
				int64Value._beginByte = 1375207;
				stringValue._beginByte = 1376511;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_344
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_344()
			{
				int32Value._beginByte = 1377083;
				int64Value._beginByte = 1378219;
				stringValue._beginByte = 1378979;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_345
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_345()
			{
				int32Value._beginByte = 1379308;
				int64Value._beginByte = 1381572;
				stringValue._beginByte = 1383084;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_346
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_346()
			{
				int32Value._beginByte = 1383737;
				int64Value._beginByte = 1385185;
				stringValue._beginByte = 1386153;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_347
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_347()
			{
				int32Value._beginByte = 1386584;
				int64Value._beginByte = 1388536;
				stringValue._beginByte = 1389840;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_348
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_348()
			{
				int32Value._beginByte = 1390413;
				int64Value._beginByte = 1391861;
				stringValue._beginByte = 1392829;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_349
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_349()
			{
				int32Value._beginByte = 1393261;
				int64Value._beginByte = 1395525;
				stringValue._beginByte = 1397037;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_350
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_350()
			{
				int32Value._beginByte = 1397694;
				int64Value._beginByte = 1399766;
				stringValue._beginByte = 1401150;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_351
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_351()
			{
				int32Value._beginByte = 1401747;
				int64Value._beginByte = 1403699;
				stringValue._beginByte = 1405003;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_352
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_352()
			{
				int32Value._beginByte = 1405575;
				int64Value._beginByte = 1407575;
				stringValue._beginByte = 1408911;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_353
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_353()
			{
				int32Value._beginByte = 1409491;
				int64Value._beginByte = 1411443;
				stringValue._beginByte = 1412747;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_354
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_354()
			{
				int32Value._beginByte = 1413319;
				int64Value._beginByte = 1414455;
				stringValue._beginByte = 1415215;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_355
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_355()
			{
				int32Value._beginByte = 1415544;
				int64Value._beginByte = 1417808;
				stringValue._beginByte = 1419320;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_356
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_356()
			{
				int32Value._beginByte = 1419973;
				int64Value._beginByte = 1421421;
				stringValue._beginByte = 1422389;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_357
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_357()
			{
				int32Value._beginByte = 1422820;
				int64Value._beginByte = 1424772;
				stringValue._beginByte = 1426076;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_358
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_358()
			{
				int32Value._beginByte = 1426649;
				int64Value._beginByte = 1428097;
				stringValue._beginByte = 1429065;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_359
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_359()
			{
				int32Value._beginByte = 1429496;
				int64Value._beginByte = 1431760;
				stringValue._beginByte = 1433272;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_360
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_360()
			{
				int32Value._beginByte = 1433929;
				int64Value._beginByte = 1436001;
				stringValue._beginByte = 1437385;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_361
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_361()
			{
				int32Value._beginByte = 1437980;
				int64Value._beginByte = 1439932;
				stringValue._beginByte = 1441236;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_362
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_362()
			{
				int32Value._beginByte = 1441808;
				int64Value._beginByte = 1443808;
				stringValue._beginByte = 1445144;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_363
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_363()
			{
				int32Value._beginByte = 1445724;
				int64Value._beginByte = 1447676;
				stringValue._beginByte = 1448980;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_364
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_364()
			{
				int32Value._beginByte = 1449552;
				int64Value._beginByte = 1450688;
				stringValue._beginByte = 1451448;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_365
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_365()
			{
				int32Value._beginByte = 1451777;
				int64Value._beginByte = 1454041;
				stringValue._beginByte = 1455553;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_366
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_366()
			{
				int32Value._beginByte = 1456206;
				int64Value._beginByte = 1457654;
				stringValue._beginByte = 1458622;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_367
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_367()
			{
				int32Value._beginByte = 1459053;
				int64Value._beginByte = 1461005;
				stringValue._beginByte = 1462309;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_368
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_368()
			{
				int32Value._beginByte = 1462882;
				int64Value._beginByte = 1464330;
				stringValue._beginByte = 1465298;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_369
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_369()
			{
				int32Value._beginByte = 1465730;
				int64Value._beginByte = 1467994;
				stringValue._beginByte = 1469506;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_370
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_370()
			{
				int32Value._beginByte = 1470163;
				int64Value._beginByte = 1472235;
				stringValue._beginByte = 1473619;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_371
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_371()
			{
				int32Value._beginByte = 1474214;
				int64Value._beginByte = 1476166;
				stringValue._beginByte = 1477470;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_372
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_372()
			{
				int32Value._beginByte = 1478042;
				int64Value._beginByte = 1480042;
				stringValue._beginByte = 1481378;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_373
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_373()
			{
				int32Value._beginByte = 1481958;
				int64Value._beginByte = 1483910;
				stringValue._beginByte = 1485214;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_374
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_374()
			{
				int32Value._beginByte = 1485786;
				int64Value._beginByte = 1486922;
				stringValue._beginByte = 1487682;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_375
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_375()
			{
				int32Value._beginByte = 1488011;
				int64Value._beginByte = 1490275;
				stringValue._beginByte = 1491787;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_376
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_376()
			{
				int32Value._beginByte = 1492440;
				int64Value._beginByte = 1493888;
				stringValue._beginByte = 1494856;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_377
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_377()
			{
				int32Value._beginByte = 1495287;
				int64Value._beginByte = 1497239;
				stringValue._beginByte = 1498543;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_378
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_378()
			{
				int32Value._beginByte = 1499116;
				int64Value._beginByte = 1500564;
				stringValue._beginByte = 1501532;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_379
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_379()
			{
				int32Value._beginByte = 1501964;
				int64Value._beginByte = 1504228;
				stringValue._beginByte = 1505740;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_380
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_380()
			{
				int32Value._beginByte = 1506397;
				int64Value._beginByte = 1508469;
				stringValue._beginByte = 1509853;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_381
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_381()
			{
				int32Value._beginByte = 1510448;
				int64Value._beginByte = 1512400;
				stringValue._beginByte = 1513704;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_382
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_382()
			{
				int32Value._beginByte = 1514276;
				int64Value._beginByte = 1516276;
				stringValue._beginByte = 1517612;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_383
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_383()
			{
				int32Value._beginByte = 1518192;
				int64Value._beginByte = 1520144;
				stringValue._beginByte = 1521448;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_384
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_384()
			{
				int32Value._beginByte = 1522020;
				int64Value._beginByte = 1523156;
				stringValue._beginByte = 1523916;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_385
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_385()
			{
				int32Value._beginByte = 1524245;
				int64Value._beginByte = 1526509;
				stringValue._beginByte = 1528021;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_386
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_386()
			{
				int32Value._beginByte = 1528675;
				int64Value._beginByte = 1530123;
				stringValue._beginByte = 1531091;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_387
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_387()
			{
				int32Value._beginByte = 1531522;
				int64Value._beginByte = 1533474;
				stringValue._beginByte = 1534778;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_388
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_388()
			{
				int32Value._beginByte = 1535351;
				int64Value._beginByte = 1536799;
				stringValue._beginByte = 1537767;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_389
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_389()
			{
				int32Value._beginByte = 1538199;
				int64Value._beginByte = 1540463;
				stringValue._beginByte = 1541975;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_390
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_390()
			{
				int32Value._beginByte = 1542632;
				int64Value._beginByte = 1544704;
				stringValue._beginByte = 1546088;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_391
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_391()
			{
				int32Value._beginByte = 1546683;
				int64Value._beginByte = 1548635;
				stringValue._beginByte = 1549939;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_392
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_392()
			{
				int32Value._beginByte = 1550511;
				int64Value._beginByte = 1552511;
				stringValue._beginByte = 1553847;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_393
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_393()
			{
				int32Value._beginByte = 1554427;
				int64Value._beginByte = 1556379;
				stringValue._beginByte = 1557683;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_394
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_394()
			{
				int32Value._beginByte = 1558255;
				int64Value._beginByte = 1559391;
				stringValue._beginByte = 1560151;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_395
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_395()
			{
				int32Value._beginByte = 1560480;
				int64Value._beginByte = 1562744;
				stringValue._beginByte = 1564256;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_396
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_396()
			{
				int32Value._beginByte = 1564909;
				int64Value._beginByte = 1566357;
				stringValue._beginByte = 1567325;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_397
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_397()
			{
				int32Value._beginByte = 1567756;
				int64Value._beginByte = 1569708;
				stringValue._beginByte = 1571012;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_398
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_398()
			{
				int32Value._beginByte = 1571585;
				int64Value._beginByte = 1573033;
				stringValue._beginByte = 1574001;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_399
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_399()
			{
				int32Value._beginByte = 1574433;
				int64Value._beginByte = 1576697;
				stringValue._beginByte = 1578209;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_400
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_400()
			{
				int32Value._beginByte = 1578866;
				int64Value._beginByte = 1580938;
				stringValue._beginByte = 1582322;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_401
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_401()
			{
				int32Value._beginByte = 1582919;
				int64Value._beginByte = 1584871;
				stringValue._beginByte = 1586175;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_402
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_402()
			{
				int32Value._beginByte = 1586747;
				int64Value._beginByte = 1588747;
				stringValue._beginByte = 1590083;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_403
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_403()
			{
				int32Value._beginByte = 1590663;
				int64Value._beginByte = 1592615;
				stringValue._beginByte = 1593919;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_404
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_404()
			{
				int32Value._beginByte = 1594491;
				int64Value._beginByte = 1595627;
				stringValue._beginByte = 1596387;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_405
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_405()
			{
				int32Value._beginByte = 1596716;
				int64Value._beginByte = 1598980;
				stringValue._beginByte = 1600492;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_406
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_406()
			{
				int32Value._beginByte = 1601145;
				int64Value._beginByte = 1602593;
				stringValue._beginByte = 1603561;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_407
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_407()
			{
				int32Value._beginByte = 1603992;
				int64Value._beginByte = 1605944;
				stringValue._beginByte = 1607248;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_408
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_408()
			{
				int32Value._beginByte = 1607821;
				int64Value._beginByte = 1609269;
				stringValue._beginByte = 1610237;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_409
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_409()
			{
				int32Value._beginByte = 1610669;
				int64Value._beginByte = 1612933;
				stringValue._beginByte = 1614445;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_410
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_410()
			{
				int32Value._beginByte = 1615102;
				int64Value._beginByte = 1617174;
				stringValue._beginByte = 1618558;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_411
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_411()
			{
				int32Value._beginByte = 1619153;
				int64Value._beginByte = 1621105;
				stringValue._beginByte = 1622409;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_412
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_412()
			{
				int32Value._beginByte = 1622981;
				int64Value._beginByte = 1624981;
				stringValue._beginByte = 1626317;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_413
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_413()
			{
				int32Value._beginByte = 1626897;
				int64Value._beginByte = 1628849;
				stringValue._beginByte = 1630153;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_414
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_414()
			{
				int32Value._beginByte = 1630725;
				int64Value._beginByte = 1631861;
				stringValue._beginByte = 1632621;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_415
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_415()
			{
				int32Value._beginByte = 1632950;
				int64Value._beginByte = 1635214;
				stringValue._beginByte = 1636726;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_416
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_416()
			{
				int32Value._beginByte = 1637379;
				int64Value._beginByte = 1638827;
				stringValue._beginByte = 1639795;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_417
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_417()
			{
				int32Value._beginByte = 1640226;
				int64Value._beginByte = 1642178;
				stringValue._beginByte = 1643482;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_418
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_418()
			{
				int32Value._beginByte = 1644055;
				int64Value._beginByte = 1645503;
				stringValue._beginByte = 1646471;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_419
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_419()
			{
				int32Value._beginByte = 1646903;
				int64Value._beginByte = 1649167;
				stringValue._beginByte = 1650679;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_420
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_420()
			{
				int32Value._beginByte = 1651336;
				int64Value._beginByte = 1653408;
				stringValue._beginByte = 1654792;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_421
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_421()
			{
				int32Value._beginByte = 1655387;
				int64Value._beginByte = 1657339;
				stringValue._beginByte = 1658643;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_422
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_422()
			{
				int32Value._beginByte = 1659215;
				int64Value._beginByte = 1661215;
				stringValue._beginByte = 1662551;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_423
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_423()
			{
				int32Value._beginByte = 1663131;
				int64Value._beginByte = 1665083;
				stringValue._beginByte = 1666387;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_424
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_424()
			{
				int32Value._beginByte = 1666959;
				int64Value._beginByte = 1668095;
				stringValue._beginByte = 1668855;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_425
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_425()
			{
				int32Value._beginByte = 1669184;
				int64Value._beginByte = 1671448;
				stringValue._beginByte = 1672960;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_426
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_426()
			{
				int32Value._beginByte = 1673613;
				int64Value._beginByte = 1675061;
				stringValue._beginByte = 1676029;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_427
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_427()
			{
				int32Value._beginByte = 1676460;
				int64Value._beginByte = 1678412;
				stringValue._beginByte = 1679716;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_428
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_428()
			{
				int32Value._beginByte = 1680289;
				int64Value._beginByte = 1681737;
				stringValue._beginByte = 1682705;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_429
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_429()
			{
				int32Value._beginByte = 1683137;
				int64Value._beginByte = 1685401;
				stringValue._beginByte = 1686913;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_430
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_430()
			{
				int32Value._beginByte = 1687570;
				int64Value._beginByte = 1689642;
				stringValue._beginByte = 1691026;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_431
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_431()
			{
				int32Value._beginByte = 1691621;
				int64Value._beginByte = 1693573;
				stringValue._beginByte = 1694877;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_432
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_432()
			{
				int32Value._beginByte = 1695449;
				int64Value._beginByte = 1697449;
				stringValue._beginByte = 1698785;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_433
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_433()
			{
				int32Value._beginByte = 1699365;
				int64Value._beginByte = 1701317;
				stringValue._beginByte = 1702621;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_434
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_434()
			{
				int32Value._beginByte = 1703193;
				int64Value._beginByte = 1704329;
				stringValue._beginByte = 1705089;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_435
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_435()
			{
				int32Value._beginByte = 1705418;
				int64Value._beginByte = 1707682;
				stringValue._beginByte = 1709194;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_436
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_436()
			{
				int32Value._beginByte = 1709848;
				int64Value._beginByte = 1711296;
				stringValue._beginByte = 1712264;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_437
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_437()
			{
				int32Value._beginByte = 1712695;
				int64Value._beginByte = 1714647;
				stringValue._beginByte = 1715951;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_438
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_438()
			{
				int32Value._beginByte = 1716524;
				int64Value._beginByte = 1717972;
				stringValue._beginByte = 1718940;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_439
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_439()
			{
				int32Value._beginByte = 1719372;
				int64Value._beginByte = 1721636;
				stringValue._beginByte = 1723148;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_440
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_440()
			{
				int32Value._beginByte = 1723805;
				int64Value._beginByte = 1725877;
				stringValue._beginByte = 1727261;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_441
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_441()
			{
				int32Value._beginByte = 1727856;
				int64Value._beginByte = 1729808;
				stringValue._beginByte = 1731112;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_442
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_442()
			{
				int32Value._beginByte = 1731684;
				int64Value._beginByte = 1733684;
				stringValue._beginByte = 1735020;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_443
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_443()
			{
				int32Value._beginByte = 1735600;
				int64Value._beginByte = 1737552;
				stringValue._beginByte = 1738856;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_444
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_444()
			{
				int32Value._beginByte = 1739428;
				int64Value._beginByte = 1740564;
				stringValue._beginByte = 1741324;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_445
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_445()
			{
				int32Value._beginByte = 1741653;
				int64Value._beginByte = 1743917;
				stringValue._beginByte = 1745429;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_446
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_446()
			{
				int32Value._beginByte = 1746082;
				int64Value._beginByte = 1747530;
				stringValue._beginByte = 1748498;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_447
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_447()
			{
				int32Value._beginByte = 1748929;
				int64Value._beginByte = 1750881;
				stringValue._beginByte = 1752185;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_448
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_448()
			{
				int32Value._beginByte = 1752758;
				int64Value._beginByte = 1754206;
				stringValue._beginByte = 1755174;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_449
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_449()
			{
				int32Value._beginByte = 1755606;
				int64Value._beginByte = 1757870;
				stringValue._beginByte = 1759382;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_450
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_450()
			{
				int32Value._beginByte = 1760039;
				int64Value._beginByte = 1762111;
				stringValue._beginByte = 1763495;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_451
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_451()
			{
				int32Value._beginByte = 1764092;
				int64Value._beginByte = 1766044;
				stringValue._beginByte = 1767348;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_452
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_452()
			{
				int32Value._beginByte = 1767920;
				int64Value._beginByte = 1769920;
				stringValue._beginByte = 1771256;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_453
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_453()
			{
				int32Value._beginByte = 1771836;
				int64Value._beginByte = 1773788;
				stringValue._beginByte = 1775092;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_454
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_454()
			{
				int32Value._beginByte = 1775664;
				int64Value._beginByte = 1776800;
				stringValue._beginByte = 1777560;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_455
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_455()
			{
				int32Value._beginByte = 1777888;
				int64Value._beginByte = 1780152;
				stringValue._beginByte = 1781664;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_456
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_456()
			{
				int32Value._beginByte = 1782317;
				int64Value._beginByte = 1783765;
				stringValue._beginByte = 1784733;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_457
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_457()
			{
				int32Value._beginByte = 1785164;
				int64Value._beginByte = 1787116;
				stringValue._beginByte = 1788420;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_458
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_458()
			{
				int32Value._beginByte = 1788993;
				int64Value._beginByte = 1790441;
				stringValue._beginByte = 1791409;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_459
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_459()
			{
				int32Value._beginByte = 1791841;
				int64Value._beginByte = 1794105;
				stringValue._beginByte = 1795617;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_460
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_460()
			{
				int32Value._beginByte = 1796274;
				int64Value._beginByte = 1798346;
				stringValue._beginByte = 1799730;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_461
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_461()
			{
				int32Value._beginByte = 1800325;
				int64Value._beginByte = 1802277;
				stringValue._beginByte = 1803581;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_462
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_462()
			{
				int32Value._beginByte = 1804153;
				int64Value._beginByte = 1806153;
				stringValue._beginByte = 1807489;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_463
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_463()
			{
				int32Value._beginByte = 1808069;
				int64Value._beginByte = 1810021;
				stringValue._beginByte = 1811325;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_464
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_464()
			{
				int32Value._beginByte = 1811897;
				int64Value._beginByte = 1813033;
				stringValue._beginByte = 1813793;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_465
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_465()
			{
				int32Value._beginByte = 1814122;
				int64Value._beginByte = 1816386;
				stringValue._beginByte = 1817898;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_466
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_466()
			{
				int32Value._beginByte = 1818551;
				int64Value._beginByte = 1819999;
				stringValue._beginByte = 1820967;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_467
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_467()
			{
				int32Value._beginByte = 1821398;
				int64Value._beginByte = 1823350;
				stringValue._beginByte = 1824654;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_468
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_468()
			{
				int32Value._beginByte = 1825227;
				int64Value._beginByte = 1826675;
				stringValue._beginByte = 1827643;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_469
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_469()
			{
				int32Value._beginByte = 1828075;
				int64Value._beginByte = 1830339;
				stringValue._beginByte = 1831851;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_470
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_470()
			{
				int32Value._beginByte = 1832508;
				int64Value._beginByte = 1834580;
				stringValue._beginByte = 1835964;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_471
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_471()
			{
				int32Value._beginByte = 1836559;
				int64Value._beginByte = 1838511;
				stringValue._beginByte = 1839815;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_472
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_472()
			{
				int32Value._beginByte = 1840387;
				int64Value._beginByte = 1842387;
				stringValue._beginByte = 1843723;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_473
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_473()
			{
				int32Value._beginByte = 1844303;
				int64Value._beginByte = 1846255;
				stringValue._beginByte = 1847559;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_474
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_474()
			{
				int32Value._beginByte = 1848131;
				int64Value._beginByte = 1849267;
				stringValue._beginByte = 1850027;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_475
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_475()
			{
				int32Value._beginByte = 1850356;
				int64Value._beginByte = 1852620;
				stringValue._beginByte = 1854132;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_476
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_476()
			{
				int32Value._beginByte = 1854785;
				int64Value._beginByte = 1856233;
				stringValue._beginByte = 1857201;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_477
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_477()
			{
				int32Value._beginByte = 1857632;
				int64Value._beginByte = 1859584;
				stringValue._beginByte = 1860888;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_478
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_478()
			{
				int32Value._beginByte = 1861461;
				int64Value._beginByte = 1862909;
				stringValue._beginByte = 1863877;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_479
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_479()
			{
				int32Value._beginByte = 1864309;
				int64Value._beginByte = 1866573;
				stringValue._beginByte = 1868085;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_480
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_480()
			{
				int32Value._beginByte = 1868742;
				int64Value._beginByte = 1870814;
				stringValue._beginByte = 1872198;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_481
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_481()
			{
				int32Value._beginByte = 1872793;
				int64Value._beginByte = 1874745;
				stringValue._beginByte = 1876049;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_482
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_482()
			{
				int32Value._beginByte = 1876621;
				int64Value._beginByte = 1878621;
				stringValue._beginByte = 1879957;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_483
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_483()
			{
				int32Value._beginByte = 1880537;
				int64Value._beginByte = 1882489;
				stringValue._beginByte = 1883793;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_484
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_484()
			{
				int32Value._beginByte = 1884365;
				int64Value._beginByte = 1885501;
				stringValue._beginByte = 1886261;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_485
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_485()
			{
				int32Value._beginByte = 1886590;
				int64Value._beginByte = 1888854;
				stringValue._beginByte = 1890366;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_486
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_486()
			{
				int32Value._beginByte = 1891020;
				int64Value._beginByte = 1892468;
				stringValue._beginByte = 1893436;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_487
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_487()
			{
				int32Value._beginByte = 1893867;
				int64Value._beginByte = 1895819;
				stringValue._beginByte = 1897123;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_488
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_488()
			{
				int32Value._beginByte = 1897696;
				int64Value._beginByte = 1899144;
				stringValue._beginByte = 1900112;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_489
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_489()
			{
				int32Value._beginByte = 1900544;
				int64Value._beginByte = 1902808;
				stringValue._beginByte = 1904320;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_490
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_490()
			{
				int32Value._beginByte = 1904977;
				int64Value._beginByte = 1907049;
				stringValue._beginByte = 1908433;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_491
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_491()
			{
				int32Value._beginByte = 1909028;
				int64Value._beginByte = 1910980;
				stringValue._beginByte = 1912284;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_492
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_492()
			{
				int32Value._beginByte = 1912856;
				int64Value._beginByte = 1914856;
				stringValue._beginByte = 1916192;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_493
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_493()
			{
				int32Value._beginByte = 1916772;
				int64Value._beginByte = 1918724;
				stringValue._beginByte = 1920028;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_494
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_494()
			{
				int32Value._beginByte = 1920600;
				int64Value._beginByte = 1921736;
				stringValue._beginByte = 1922496;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_495
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_495()
			{
				int32Value._beginByte = 1922825;
				int64Value._beginByte = 1925089;
				stringValue._beginByte = 1926601;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_496
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_496()
			{
				int32Value._beginByte = 1927254;
				int64Value._beginByte = 1928702;
				stringValue._beginByte = 1929670;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_497
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_497()
			{
				int32Value._beginByte = 1930101;
				int64Value._beginByte = 1932053;
				stringValue._beginByte = 1933357;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_498
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_498()
			{
				int32Value._beginByte = 1933930;
				int64Value._beginByte = 1935378;
				stringValue._beginByte = 1936346;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_499
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_499()
			{
				int32Value._beginByte = 1936778;
				int64Value._beginByte = 1939042;
				stringValue._beginByte = 1940554;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetBattle_500
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetBattle_500()
			{
				int32Value._beginByte = 1941211;
				int64Value._beginByte = 1943283;
				stringValue._beginByte = 1944667;

			};
			enum enumInt32
			{
				Wave = 0,
				Quantity = 1,
				Enemy_Size = 2,
				Coin = 3,
				Respawn = 4,
				Delay_after_spawn = 5,

			};
			enum enumInt64
			{
				HP = 0,
				Damage = 1,

			};
			enum enumString
			{
				Enemy_ID = 0,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetBattle_1 SheetBattle_1;
		CSheetBattle_2 SheetBattle_2;
		CSheetBattle_3 SheetBattle_3;
		CSheetBattle_4 SheetBattle_4;
		CSheetBattle_5 SheetBattle_5;
		CSheetBattle_6 SheetBattle_6;
		CSheetBattle_7 SheetBattle_7;
		CSheetBattle_8 SheetBattle_8;
		CSheetBattle_9 SheetBattle_9;
		CSheetBattle_10 SheetBattle_10;
		CSheetBattle_11 SheetBattle_11;
		CSheetBattle_12 SheetBattle_12;
		CSheetBattle_13 SheetBattle_13;
		CSheetBattle_14 SheetBattle_14;
		CSheetBattle_15 SheetBattle_15;
		CSheetBattle_16 SheetBattle_16;
		CSheetBattle_17 SheetBattle_17;
		CSheetBattle_18 SheetBattle_18;
		CSheetBattle_19 SheetBattle_19;
		CSheetBattle_20 SheetBattle_20;
		CSheetBattle_21 SheetBattle_21;
		CSheetBattle_22 SheetBattle_22;
		CSheetBattle_23 SheetBattle_23;
		CSheetBattle_24 SheetBattle_24;
		CSheetBattle_25 SheetBattle_25;
		CSheetBattle_26 SheetBattle_26;
		CSheetBattle_27 SheetBattle_27;
		CSheetBattle_28 SheetBattle_28;
		CSheetBattle_29 SheetBattle_29;
		CSheetBattle_30 SheetBattle_30;
		CSheetBattle_31 SheetBattle_31;
		CSheetBattle_32 SheetBattle_32;
		CSheetBattle_33 SheetBattle_33;
		CSheetBattle_34 SheetBattle_34;
		CSheetBattle_35 SheetBattle_35;
		CSheetBattle_36 SheetBattle_36;
		CSheetBattle_37 SheetBattle_37;
		CSheetBattle_38 SheetBattle_38;
		CSheetBattle_39 SheetBattle_39;
		CSheetBattle_40 SheetBattle_40;
		CSheetBattle_41 SheetBattle_41;
		CSheetBattle_42 SheetBattle_42;
		CSheetBattle_43 SheetBattle_43;
		CSheetBattle_44 SheetBattle_44;
		CSheetBattle_45 SheetBattle_45;
		CSheetBattle_46 SheetBattle_46;
		CSheetBattle_47 SheetBattle_47;
		CSheetBattle_48 SheetBattle_48;
		CSheetBattle_49 SheetBattle_49;
		CSheetBattle_50 SheetBattle_50;
		CSheetBattle_51 SheetBattle_51;
		CSheetBattle_52 SheetBattle_52;
		CSheetBattle_53 SheetBattle_53;
		CSheetBattle_54 SheetBattle_54;
		CSheetBattle_55 SheetBattle_55;
		CSheetBattle_56 SheetBattle_56;
		CSheetBattle_57 SheetBattle_57;
		CSheetBattle_58 SheetBattle_58;
		CSheetBattle_59 SheetBattle_59;
		CSheetBattle_60 SheetBattle_60;
		CSheetBattle_61 SheetBattle_61;
		CSheetBattle_62 SheetBattle_62;
		CSheetBattle_63 SheetBattle_63;
		CSheetBattle_64 SheetBattle_64;
		CSheetBattle_65 SheetBattle_65;
		CSheetBattle_66 SheetBattle_66;
		CSheetBattle_67 SheetBattle_67;
		CSheetBattle_68 SheetBattle_68;
		CSheetBattle_69 SheetBattle_69;
		CSheetBattle_70 SheetBattle_70;
		CSheetBattle_71 SheetBattle_71;
		CSheetBattle_72 SheetBattle_72;
		CSheetBattle_73 SheetBattle_73;
		CSheetBattle_74 SheetBattle_74;
		CSheetBattle_75 SheetBattle_75;
		CSheetBattle_76 SheetBattle_76;
		CSheetBattle_77 SheetBattle_77;
		CSheetBattle_78 SheetBattle_78;
		CSheetBattle_79 SheetBattle_79;
		CSheetBattle_80 SheetBattle_80;
		CSheetBattle_81 SheetBattle_81;
		CSheetBattle_82 SheetBattle_82;
		CSheetBattle_83 SheetBattle_83;
		CSheetBattle_84 SheetBattle_84;
		CSheetBattle_85 SheetBattle_85;
		CSheetBattle_86 SheetBattle_86;
		CSheetBattle_87 SheetBattle_87;
		CSheetBattle_88 SheetBattle_88;
		CSheetBattle_89 SheetBattle_89;
		CSheetBattle_90 SheetBattle_90;
		CSheetBattle_91 SheetBattle_91;
		CSheetBattle_92 SheetBattle_92;
		CSheetBattle_93 SheetBattle_93;
		CSheetBattle_94 SheetBattle_94;
		CSheetBattle_95 SheetBattle_95;
		CSheetBattle_96 SheetBattle_96;
		CSheetBattle_97 SheetBattle_97;
		CSheetBattle_98 SheetBattle_98;
		CSheetBattle_99 SheetBattle_99;
		CSheetBattle_100 SheetBattle_100;
		CSheetBattle_101 SheetBattle_101;
		CSheetBattle_102 SheetBattle_102;
		CSheetBattle_103 SheetBattle_103;
		CSheetBattle_104 SheetBattle_104;
		CSheetBattle_105 SheetBattle_105;
		CSheetBattle_106 SheetBattle_106;
		CSheetBattle_107 SheetBattle_107;
		CSheetBattle_108 SheetBattle_108;
		CSheetBattle_109 SheetBattle_109;
		CSheetBattle_110 SheetBattle_110;
		CSheetBattle_111 SheetBattle_111;
		CSheetBattle_112 SheetBattle_112;
		CSheetBattle_113 SheetBattle_113;
		CSheetBattle_114 SheetBattle_114;
		CSheetBattle_115 SheetBattle_115;
		CSheetBattle_116 SheetBattle_116;
		CSheetBattle_117 SheetBattle_117;
		CSheetBattle_118 SheetBattle_118;
		CSheetBattle_119 SheetBattle_119;
		CSheetBattle_120 SheetBattle_120;
		CSheetBattle_121 SheetBattle_121;
		CSheetBattle_122 SheetBattle_122;
		CSheetBattle_123 SheetBattle_123;
		CSheetBattle_124 SheetBattle_124;
		CSheetBattle_125 SheetBattle_125;
		CSheetBattle_126 SheetBattle_126;
		CSheetBattle_127 SheetBattle_127;
		CSheetBattle_128 SheetBattle_128;
		CSheetBattle_129 SheetBattle_129;
		CSheetBattle_130 SheetBattle_130;
		CSheetBattle_131 SheetBattle_131;
		CSheetBattle_132 SheetBattle_132;
		CSheetBattle_133 SheetBattle_133;
		CSheetBattle_134 SheetBattle_134;
		CSheetBattle_135 SheetBattle_135;
		CSheetBattle_136 SheetBattle_136;
		CSheetBattle_137 SheetBattle_137;
		CSheetBattle_138 SheetBattle_138;
		CSheetBattle_139 SheetBattle_139;
		CSheetBattle_140 SheetBattle_140;
		CSheetBattle_141 SheetBattle_141;
		CSheetBattle_142 SheetBattle_142;
		CSheetBattle_143 SheetBattle_143;
		CSheetBattle_144 SheetBattle_144;
		CSheetBattle_145 SheetBattle_145;
		CSheetBattle_146 SheetBattle_146;
		CSheetBattle_147 SheetBattle_147;
		CSheetBattle_148 SheetBattle_148;
		CSheetBattle_149 SheetBattle_149;
		CSheetBattle_150 SheetBattle_150;
		CSheetBattle_151 SheetBattle_151;
		CSheetBattle_152 SheetBattle_152;
		CSheetBattle_153 SheetBattle_153;
		CSheetBattle_154 SheetBattle_154;
		CSheetBattle_155 SheetBattle_155;
		CSheetBattle_156 SheetBattle_156;
		CSheetBattle_157 SheetBattle_157;
		CSheetBattle_158 SheetBattle_158;
		CSheetBattle_159 SheetBattle_159;
		CSheetBattle_160 SheetBattle_160;
		CSheetBattle_161 SheetBattle_161;
		CSheetBattle_162 SheetBattle_162;
		CSheetBattle_163 SheetBattle_163;
		CSheetBattle_164 SheetBattle_164;
		CSheetBattle_165 SheetBattle_165;
		CSheetBattle_166 SheetBattle_166;
		CSheetBattle_167 SheetBattle_167;
		CSheetBattle_168 SheetBattle_168;
		CSheetBattle_169 SheetBattle_169;
		CSheetBattle_170 SheetBattle_170;
		CSheetBattle_171 SheetBattle_171;
		CSheetBattle_172 SheetBattle_172;
		CSheetBattle_173 SheetBattle_173;
		CSheetBattle_174 SheetBattle_174;
		CSheetBattle_175 SheetBattle_175;
		CSheetBattle_176 SheetBattle_176;
		CSheetBattle_177 SheetBattle_177;
		CSheetBattle_178 SheetBattle_178;
		CSheetBattle_179 SheetBattle_179;
		CSheetBattle_180 SheetBattle_180;
		CSheetBattle_181 SheetBattle_181;
		CSheetBattle_182 SheetBattle_182;
		CSheetBattle_183 SheetBattle_183;
		CSheetBattle_184 SheetBattle_184;
		CSheetBattle_185 SheetBattle_185;
		CSheetBattle_186 SheetBattle_186;
		CSheetBattle_187 SheetBattle_187;
		CSheetBattle_188 SheetBattle_188;
		CSheetBattle_189 SheetBattle_189;
		CSheetBattle_190 SheetBattle_190;
		CSheetBattle_191 SheetBattle_191;
		CSheetBattle_192 SheetBattle_192;
		CSheetBattle_193 SheetBattle_193;
		CSheetBattle_194 SheetBattle_194;
		CSheetBattle_195 SheetBattle_195;
		CSheetBattle_196 SheetBattle_196;
		CSheetBattle_197 SheetBattle_197;
		CSheetBattle_198 SheetBattle_198;
		CSheetBattle_199 SheetBattle_199;
		CSheetBattle_200 SheetBattle_200;
		CSheetBattle_201 SheetBattle_201;
		CSheetBattle_202 SheetBattle_202;
		CSheetBattle_203 SheetBattle_203;
		CSheetBattle_204 SheetBattle_204;
		CSheetBattle_205 SheetBattle_205;
		CSheetBattle_206 SheetBattle_206;
		CSheetBattle_207 SheetBattle_207;
		CSheetBattle_208 SheetBattle_208;
		CSheetBattle_209 SheetBattle_209;
		CSheetBattle_210 SheetBattle_210;
		CSheetBattle_211 SheetBattle_211;
		CSheetBattle_212 SheetBattle_212;
		CSheetBattle_213 SheetBattle_213;
		CSheetBattle_214 SheetBattle_214;
		CSheetBattle_215 SheetBattle_215;
		CSheetBattle_216 SheetBattle_216;
		CSheetBattle_217 SheetBattle_217;
		CSheetBattle_218 SheetBattle_218;
		CSheetBattle_219 SheetBattle_219;
		CSheetBattle_220 SheetBattle_220;
		CSheetBattle_221 SheetBattle_221;
		CSheetBattle_222 SheetBattle_222;
		CSheetBattle_223 SheetBattle_223;
		CSheetBattle_224 SheetBattle_224;
		CSheetBattle_225 SheetBattle_225;
		CSheetBattle_226 SheetBattle_226;
		CSheetBattle_227 SheetBattle_227;
		CSheetBattle_228 SheetBattle_228;
		CSheetBattle_229 SheetBattle_229;
		CSheetBattle_230 SheetBattle_230;
		CSheetBattle_231 SheetBattle_231;
		CSheetBattle_232 SheetBattle_232;
		CSheetBattle_233 SheetBattle_233;
		CSheetBattle_234 SheetBattle_234;
		CSheetBattle_235 SheetBattle_235;
		CSheetBattle_236 SheetBattle_236;
		CSheetBattle_237 SheetBattle_237;
		CSheetBattle_238 SheetBattle_238;
		CSheetBattle_239 SheetBattle_239;
		CSheetBattle_240 SheetBattle_240;
		CSheetBattle_241 SheetBattle_241;
		CSheetBattle_242 SheetBattle_242;
		CSheetBattle_243 SheetBattle_243;
		CSheetBattle_244 SheetBattle_244;
		CSheetBattle_245 SheetBattle_245;
		CSheetBattle_246 SheetBattle_246;
		CSheetBattle_247 SheetBattle_247;
		CSheetBattle_248 SheetBattle_248;
		CSheetBattle_249 SheetBattle_249;
		CSheetBattle_250 SheetBattle_250;
		CSheetBattle_251 SheetBattle_251;
		CSheetBattle_252 SheetBattle_252;
		CSheetBattle_253 SheetBattle_253;
		CSheetBattle_254 SheetBattle_254;
		CSheetBattle_255 SheetBattle_255;
		CSheetBattle_256 SheetBattle_256;
		CSheetBattle_257 SheetBattle_257;
		CSheetBattle_258 SheetBattle_258;
		CSheetBattle_259 SheetBattle_259;
		CSheetBattle_260 SheetBattle_260;
		CSheetBattle_261 SheetBattle_261;
		CSheetBattle_262 SheetBattle_262;
		CSheetBattle_263 SheetBattle_263;
		CSheetBattle_264 SheetBattle_264;
		CSheetBattle_265 SheetBattle_265;
		CSheetBattle_266 SheetBattle_266;
		CSheetBattle_267 SheetBattle_267;
		CSheetBattle_268 SheetBattle_268;
		CSheetBattle_269 SheetBattle_269;
		CSheetBattle_270 SheetBattle_270;
		CSheetBattle_271 SheetBattle_271;
		CSheetBattle_272 SheetBattle_272;
		CSheetBattle_273 SheetBattle_273;
		CSheetBattle_274 SheetBattle_274;
		CSheetBattle_275 SheetBattle_275;
		CSheetBattle_276 SheetBattle_276;
		CSheetBattle_277 SheetBattle_277;
		CSheetBattle_278 SheetBattle_278;
		CSheetBattle_279 SheetBattle_279;
		CSheetBattle_280 SheetBattle_280;
		CSheetBattle_281 SheetBattle_281;
		CSheetBattle_282 SheetBattle_282;
		CSheetBattle_283 SheetBattle_283;
		CSheetBattle_284 SheetBattle_284;
		CSheetBattle_285 SheetBattle_285;
		CSheetBattle_286 SheetBattle_286;
		CSheetBattle_287 SheetBattle_287;
		CSheetBattle_288 SheetBattle_288;
		CSheetBattle_289 SheetBattle_289;
		CSheetBattle_290 SheetBattle_290;
		CSheetBattle_291 SheetBattle_291;
		CSheetBattle_292 SheetBattle_292;
		CSheetBattle_293 SheetBattle_293;
		CSheetBattle_294 SheetBattle_294;
		CSheetBattle_295 SheetBattle_295;
		CSheetBattle_296 SheetBattle_296;
		CSheetBattle_297 SheetBattle_297;
		CSheetBattle_298 SheetBattle_298;
		CSheetBattle_299 SheetBattle_299;
		CSheetBattle_300 SheetBattle_300;
		CSheetBattle_301 SheetBattle_301;
		CSheetBattle_302 SheetBattle_302;
		CSheetBattle_303 SheetBattle_303;
		CSheetBattle_304 SheetBattle_304;
		CSheetBattle_305 SheetBattle_305;
		CSheetBattle_306 SheetBattle_306;
		CSheetBattle_307 SheetBattle_307;
		CSheetBattle_308 SheetBattle_308;
		CSheetBattle_309 SheetBattle_309;
		CSheetBattle_310 SheetBattle_310;
		CSheetBattle_311 SheetBattle_311;
		CSheetBattle_312 SheetBattle_312;
		CSheetBattle_313 SheetBattle_313;
		CSheetBattle_314 SheetBattle_314;
		CSheetBattle_315 SheetBattle_315;
		CSheetBattle_316 SheetBattle_316;
		CSheetBattle_317 SheetBattle_317;
		CSheetBattle_318 SheetBattle_318;
		CSheetBattle_319 SheetBattle_319;
		CSheetBattle_320 SheetBattle_320;
		CSheetBattle_321 SheetBattle_321;
		CSheetBattle_322 SheetBattle_322;
		CSheetBattle_323 SheetBattle_323;
		CSheetBattle_324 SheetBattle_324;
		CSheetBattle_325 SheetBattle_325;
		CSheetBattle_326 SheetBattle_326;
		CSheetBattle_327 SheetBattle_327;
		CSheetBattle_328 SheetBattle_328;
		CSheetBattle_329 SheetBattle_329;
		CSheetBattle_330 SheetBattle_330;
		CSheetBattle_331 SheetBattle_331;
		CSheetBattle_332 SheetBattle_332;
		CSheetBattle_333 SheetBattle_333;
		CSheetBattle_334 SheetBattle_334;
		CSheetBattle_335 SheetBattle_335;
		CSheetBattle_336 SheetBattle_336;
		CSheetBattle_337 SheetBattle_337;
		CSheetBattle_338 SheetBattle_338;
		CSheetBattle_339 SheetBattle_339;
		CSheetBattle_340 SheetBattle_340;
		CSheetBattle_341 SheetBattle_341;
		CSheetBattle_342 SheetBattle_342;
		CSheetBattle_343 SheetBattle_343;
		CSheetBattle_344 SheetBattle_344;
		CSheetBattle_345 SheetBattle_345;
		CSheetBattle_346 SheetBattle_346;
		CSheetBattle_347 SheetBattle_347;
		CSheetBattle_348 SheetBattle_348;
		CSheetBattle_349 SheetBattle_349;
		CSheetBattle_350 SheetBattle_350;
		CSheetBattle_351 SheetBattle_351;
		CSheetBattle_352 SheetBattle_352;
		CSheetBattle_353 SheetBattle_353;
		CSheetBattle_354 SheetBattle_354;
		CSheetBattle_355 SheetBattle_355;
		CSheetBattle_356 SheetBattle_356;
		CSheetBattle_357 SheetBattle_357;
		CSheetBattle_358 SheetBattle_358;
		CSheetBattle_359 SheetBattle_359;
		CSheetBattle_360 SheetBattle_360;
		CSheetBattle_361 SheetBattle_361;
		CSheetBattle_362 SheetBattle_362;
		CSheetBattle_363 SheetBattle_363;
		CSheetBattle_364 SheetBattle_364;
		CSheetBattle_365 SheetBattle_365;
		CSheetBattle_366 SheetBattle_366;
		CSheetBattle_367 SheetBattle_367;
		CSheetBattle_368 SheetBattle_368;
		CSheetBattle_369 SheetBattle_369;
		CSheetBattle_370 SheetBattle_370;
		CSheetBattle_371 SheetBattle_371;
		CSheetBattle_372 SheetBattle_372;
		CSheetBattle_373 SheetBattle_373;
		CSheetBattle_374 SheetBattle_374;
		CSheetBattle_375 SheetBattle_375;
		CSheetBattle_376 SheetBattle_376;
		CSheetBattle_377 SheetBattle_377;
		CSheetBattle_378 SheetBattle_378;
		CSheetBattle_379 SheetBattle_379;
		CSheetBattle_380 SheetBattle_380;
		CSheetBattle_381 SheetBattle_381;
		CSheetBattle_382 SheetBattle_382;
		CSheetBattle_383 SheetBattle_383;
		CSheetBattle_384 SheetBattle_384;
		CSheetBattle_385 SheetBattle_385;
		CSheetBattle_386 SheetBattle_386;
		CSheetBattle_387 SheetBattle_387;
		CSheetBattle_388 SheetBattle_388;
		CSheetBattle_389 SheetBattle_389;
		CSheetBattle_390 SheetBattle_390;
		CSheetBattle_391 SheetBattle_391;
		CSheetBattle_392 SheetBattle_392;
		CSheetBattle_393 SheetBattle_393;
		CSheetBattle_394 SheetBattle_394;
		CSheetBattle_395 SheetBattle_395;
		CSheetBattle_396 SheetBattle_396;
		CSheetBattle_397 SheetBattle_397;
		CSheetBattle_398 SheetBattle_398;
		CSheetBattle_399 SheetBattle_399;
		CSheetBattle_400 SheetBattle_400;
		CSheetBattle_401 SheetBattle_401;
		CSheetBattle_402 SheetBattle_402;
		CSheetBattle_403 SheetBattle_403;
		CSheetBattle_404 SheetBattle_404;
		CSheetBattle_405 SheetBattle_405;
		CSheetBattle_406 SheetBattle_406;
		CSheetBattle_407 SheetBattle_407;
		CSheetBattle_408 SheetBattle_408;
		CSheetBattle_409 SheetBattle_409;
		CSheetBattle_410 SheetBattle_410;
		CSheetBattle_411 SheetBattle_411;
		CSheetBattle_412 SheetBattle_412;
		CSheetBattle_413 SheetBattle_413;
		CSheetBattle_414 SheetBattle_414;
		CSheetBattle_415 SheetBattle_415;
		CSheetBattle_416 SheetBattle_416;
		CSheetBattle_417 SheetBattle_417;
		CSheetBattle_418 SheetBattle_418;
		CSheetBattle_419 SheetBattle_419;
		CSheetBattle_420 SheetBattle_420;
		CSheetBattle_421 SheetBattle_421;
		CSheetBattle_422 SheetBattle_422;
		CSheetBattle_423 SheetBattle_423;
		CSheetBattle_424 SheetBattle_424;
		CSheetBattle_425 SheetBattle_425;
		CSheetBattle_426 SheetBattle_426;
		CSheetBattle_427 SheetBattle_427;
		CSheetBattle_428 SheetBattle_428;
		CSheetBattle_429 SheetBattle_429;
		CSheetBattle_430 SheetBattle_430;
		CSheetBattle_431 SheetBattle_431;
		CSheetBattle_432 SheetBattle_432;
		CSheetBattle_433 SheetBattle_433;
		CSheetBattle_434 SheetBattle_434;
		CSheetBattle_435 SheetBattle_435;
		CSheetBattle_436 SheetBattle_436;
		CSheetBattle_437 SheetBattle_437;
		CSheetBattle_438 SheetBattle_438;
		CSheetBattle_439 SheetBattle_439;
		CSheetBattle_440 SheetBattle_440;
		CSheetBattle_441 SheetBattle_441;
		CSheetBattle_442 SheetBattle_442;
		CSheetBattle_443 SheetBattle_443;
		CSheetBattle_444 SheetBattle_444;
		CSheetBattle_445 SheetBattle_445;
		CSheetBattle_446 SheetBattle_446;
		CSheetBattle_447 SheetBattle_447;
		CSheetBattle_448 SheetBattle_448;
		CSheetBattle_449 SheetBattle_449;
		CSheetBattle_450 SheetBattle_450;
		CSheetBattle_451 SheetBattle_451;
		CSheetBattle_452 SheetBattle_452;
		CSheetBattle_453 SheetBattle_453;
		CSheetBattle_454 SheetBattle_454;
		CSheetBattle_455 SheetBattle_455;
		CSheetBattle_456 SheetBattle_456;
		CSheetBattle_457 SheetBattle_457;
		CSheetBattle_458 SheetBattle_458;
		CSheetBattle_459 SheetBattle_459;
		CSheetBattle_460 SheetBattle_460;
		CSheetBattle_461 SheetBattle_461;
		CSheetBattle_462 SheetBattle_462;
		CSheetBattle_463 SheetBattle_463;
		CSheetBattle_464 SheetBattle_464;
		CSheetBattle_465 SheetBattle_465;
		CSheetBattle_466 SheetBattle_466;
		CSheetBattle_467 SheetBattle_467;
		CSheetBattle_468 SheetBattle_468;
		CSheetBattle_469 SheetBattle_469;
		CSheetBattle_470 SheetBattle_470;
		CSheetBattle_471 SheetBattle_471;
		CSheetBattle_472 SheetBattle_472;
		CSheetBattle_473 SheetBattle_473;
		CSheetBattle_474 SheetBattle_474;
		CSheetBattle_475 SheetBattle_475;
		CSheetBattle_476 SheetBattle_476;
		CSheetBattle_477 SheetBattle_477;
		CSheetBattle_478 SheetBattle_478;
		CSheetBattle_479 SheetBattle_479;
		CSheetBattle_480 SheetBattle_480;
		CSheetBattle_481 SheetBattle_481;
		CSheetBattle_482 SheetBattle_482;
		CSheetBattle_483 SheetBattle_483;
		CSheetBattle_484 SheetBattle_484;
		CSheetBattle_485 SheetBattle_485;
		CSheetBattle_486 SheetBattle_486;
		CSheetBattle_487 SheetBattle_487;
		CSheetBattle_488 SheetBattle_488;
		CSheetBattle_489 SheetBattle_489;
		CSheetBattle_490 SheetBattle_490;
		CSheetBattle_491 SheetBattle_491;
		CSheetBattle_492 SheetBattle_492;
		CSheetBattle_493 SheetBattle_493;
		CSheetBattle_494 SheetBattle_494;
		CSheetBattle_495 SheetBattle_495;
		CSheetBattle_496 SheetBattle_496;
		CSheetBattle_497 SheetBattle_497;
		CSheetBattle_498 SheetBattle_498;
		CSheetBattle_499 SheetBattle_499;
		CSheetBattle_500 SheetBattle_500;

	};
	class FileGeneral
	{
		public:
		FileGeneral()
		{

		};

		void Load()
		{
			SheetGeneral_design.Load();
			SheetiAP_design.Load();
			SheetLoterry_design.Load();
			SheetFairy_design.Load();
			SheetWheel.Load();
			SheetiAP_design_discount.Load();
			SheetiAP_instant_design_discount.Load();
			SheetFree_Gift.Load();
			SheetDiscount.Load();
			SheetWheel_time.Load();
			SheetDaily_Event.Load();
			SheetReset_Design.Load();

		};

		void UnLoad()
		{
			SheetGeneral_design.UnLoad();
			SheetiAP_design.UnLoad();
			SheetLoterry_design.UnLoad();
			SheetFairy_design.UnLoad();
			SheetWheel.UnLoad();
			SheetiAP_design_discount.UnLoad();
			SheetiAP_instant_design_discount.UnLoad();
			SheetFree_Gift.UnLoad();
			SheetDiscount.UnLoad();
			SheetWheel_time.UnLoad();
			SheetDaily_Event.UnLoad();
			SheetReset_Design.UnLoad();

		};

		class CSheetGeneral_design
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetGeneral_design()
			{
				int32Value._beginByte = 1945264;
				stringValue._beginByte = 1945340;

			};
			enum enumInt32
			{
				value = 0,

			};
			enum enumString
			{
				name = 0,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetiAP_design
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetiAP_design()
			{
				int32Value._beginByte = 1945775;
				stringValue._beginByte = 1945871;

			};
			enum enumInt32
			{
				id = 0,
				Value = 1,

			};
			enum enumString
			{
				price = 0,
				name = 1,
				ID_Store = 2,
				GG_ID = 3,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetLoterry_design
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;
			DesignClassDataString stringValue;

			CSheetLoterry_design()
			{
				int32Value._beginByte = 1946642;
				floatValue._beginByte = 1946722;
				stringValue._beginByte = 1946766;

			};
			enum enumInt32
			{
				Type = 0,
				Value = 1,

			};
			enum enumFloat
			{
				Rate = 0,

			};
			enum enumString
			{
				Description = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetFairy_design
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetFairy_design()
			{
				int32Value._beginByte = 1946846;

			};
			enum enumInt32
			{
				Rate = 0,
				Attack = 1,
				Skill = 2,
				Coin = 3,
				Gem = 4,
				Double_Coin = 5,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetWheel
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetWheel()
			{
				int32Value._beginByte = 1946950;

			};
			enum enumInt32
			{
				Type = 0,
				Value = 1,
				Rate = 2,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetiAP_design_discount
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetiAP_design_discount()
			{
				int32Value._beginByte = 1947066;
				stringValue._beginByte = 1947106;

			};
			enum enumInt32
			{
				id = 0,
				Value = 1,

			};
			enum enumString
			{
				price = 0,
				name = 1,
				ID_Store = 2,
				GG_ID = 3,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetiAP_instant_design_discount
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataInt64 int64Value;
			DesignClassDataString stringValue;

			CSheetiAP_instant_design_discount()
			{
				int32Value._beginByte = 1947342;
				int64Value._beginByte = 1947510;
				stringValue._beginByte = 1947582;

			};
			enum enumInt32
			{
				Auto_Attack = 0,
				Instant_Skill = 1,
				Gem = 2,
				Lasting = 3,
				Battle_Unlock = 4,

			};
			enum enumInt64
			{
				Coin = 0,

			};
			enum enumString
			{
				ID = 0,
				Item = 1,
				Price = 2,
				GG_ID = 3,

			};


			void Load()
			{
				int32Value.Load();
				int64Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				int64Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetFree_Gift
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetFree_Gift()
			{
				int32Value._beginByte = 1948484;

			};
			enum enumInt32
			{
				id = 0,
				Type = 1,
				Value = 2,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetDiscount
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetDiscount()
			{
				int32Value._beginByte = 1948852;

			};
			enum enumInt32
			{
				Level = 0,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetWheel_time
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetWheel_time()
			{
				int32Value._beginByte = 1948948;

			};
			enum enumInt32
			{
				Time = 0,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetDaily_Event
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetDaily_Event()
			{
				int32Value._beginByte = 1948976;

			};
			enum enumInt32
			{
				Type = 0,
				Value = 1,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetReset_Design
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetReset_Design()
			{
				int32Value._beginByte = 1949040;

			};
			enum enumInt32
			{
				Battle_Reset = 0,
				To_Battle = 1,
				Relic_ID = 2,
				Gem = 3,
				Coin = 4,
				Bonus_Gem_Battle = 5,
				WP_Relic_ID = 6,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};

		CSheetGeneral_design SheetGeneral_design;
		CSheetiAP_design SheetiAP_design;
		CSheetLoterry_design SheetLoterry_design;
		CSheetFairy_design SheetFairy_design;
		CSheetWheel SheetWheel;
		CSheetiAP_design_discount SheetiAP_design_discount;
		CSheetiAP_instant_design_discount SheetiAP_instant_design_discount;
		CSheetFree_Gift SheetFree_Gift;
		CSheetDiscount SheetDiscount;
		CSheetWheel_time SheetWheel_time;
		CSheetDaily_Event SheetDaily_Event;
		CSheetReset_Design SheetReset_Design;

	};
	class FileHero_design
	{
		public:
		FileHero_design()
		{

		};

		void Load()
		{
			SheetHero_General.Load();
			SheetPaladin.Load();
			SheetPaladin_2.Load();
			SheetPaladin_3.Load();
			SheetPaladin_4.Load();
			SheetPaladin_5.Load();
			SheetArcher.Load();
			SheetArcher_3.Load();
			SheetArcher_4.Load();
			SheetArcher_5.Load();
			SheetFire_Mage.Load();
			SheetFire_Mage_4.Load();
			SheetFire_Mage_5.Load();
			SheetBeast_Master.Load();
			SheetBeast_Master_4.Load();
			SheetBeast_Master_5.Load();
			SheetElecitric_Mage.Load();
			SheetElecitric_Mage_5.Load();
			SheetCat_Ninja.Load();
			SheetCat_Ninja_5.Load();
			SheetSanta.Load();
			SheetAchemist.Load();
			SheetRobot.Load();
			SheetWolf_Ranger.Load();
			SheetWolf_Ranger_5.Load();

		};

		void UnLoad()
		{
			SheetHero_General.UnLoad();
			SheetPaladin.UnLoad();
			SheetPaladin_2.UnLoad();
			SheetPaladin_3.UnLoad();
			SheetPaladin_4.UnLoad();
			SheetPaladin_5.UnLoad();
			SheetArcher.UnLoad();
			SheetArcher_3.UnLoad();
			SheetArcher_4.UnLoad();
			SheetArcher_5.UnLoad();
			SheetFire_Mage.UnLoad();
			SheetFire_Mage_4.UnLoad();
			SheetFire_Mage_5.UnLoad();
			SheetBeast_Master.UnLoad();
			SheetBeast_Master_4.UnLoad();
			SheetBeast_Master_5.UnLoad();
			SheetElecitric_Mage.UnLoad();
			SheetElecitric_Mage_5.UnLoad();
			SheetCat_Ninja.UnLoad();
			SheetCat_Ninja_5.UnLoad();
			SheetSanta.UnLoad();
			SheetAchemist.UnLoad();
			SheetRobot.UnLoad();
			SheetWolf_Ranger.UnLoad();
			SheetWolf_Ranger_5.UnLoad();

		};

		class CSheetHero_General
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;
			DesignClassDataString stringValue;

			CSheetHero_General()
			{
				int32Value._beginByte = 1949720;
				floatValue._beginByte = 1950088;
				stringValue._beginByte = 1950176;

			};
			enum enumInt32
			{
				ID_Hero = 0,
				Sprite_ID = 1,
				Unlock = 2,
				Speed_Attack = 3,
				Range = 4,
				Limit_Break = 5,
				Skill = 6,
				Price_Unlock = 7,
				Rarity = 8,

			};
			enum enumFloat
			{
				Speed_Move = 0,
				Critical = 1,

			};
			enum enumString
			{
				Name = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetPaladin
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetPaladin()
			{
				int32Value._beginByte = 1950272;
				floatValue._beginByte = 1958288;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetPaladin_2
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetPaladin_2()
			{
				int32Value._beginByte = 1962300;
				floatValue._beginByte = 1970316;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetPaladin_3
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetPaladin_3()
			{
				int32Value._beginByte = 1974328;
				floatValue._beginByte = 1982344;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetPaladin_4
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetPaladin_4()
			{
				int32Value._beginByte = 1986356;
				floatValue._beginByte = 1994372;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetPaladin_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetPaladin_5()
			{
				int32Value._beginByte = 1998384;
				floatValue._beginByte = 2006400;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetArcher
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetArcher()
			{
				int32Value._beginByte = 2010412;
				floatValue._beginByte = 2018428;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetArcher_3
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetArcher_3()
			{
				int32Value._beginByte = 2022440;
				floatValue._beginByte = 2030456;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetArcher_4
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetArcher_4()
			{
				int32Value._beginByte = 2034468;
				floatValue._beginByte = 2042484;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetArcher_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetArcher_5()
			{
				int32Value._beginByte = 2046496;
				floatValue._beginByte = 2054512;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetFire_Mage
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetFire_Mage()
			{
				int32Value._beginByte = 2058524;
				floatValue._beginByte = 2066540;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetFire_Mage_4
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetFire_Mage_4()
			{
				int32Value._beginByte = 2070552;
				floatValue._beginByte = 2078568;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetFire_Mage_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetFire_Mage_5()
			{
				int32Value._beginByte = 2082580;
				floatValue._beginByte = 2090596;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetBeast_Master
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetBeast_Master()
			{
				int32Value._beginByte = 2094608;
				floatValue._beginByte = 2102624;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetBeast_Master_4
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetBeast_Master_4()
			{
				int32Value._beginByte = 2106636;
				floatValue._beginByte = 2114652;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetBeast_Master_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetBeast_Master_5()
			{
				int32Value._beginByte = 2118664;
				floatValue._beginByte = 2126680;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetElecitric_Mage
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetElecitric_Mage()
			{
				int32Value._beginByte = 2130692;
				floatValue._beginByte = 2138708;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetElecitric_Mage_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetElecitric_Mage_5()
			{
				int32Value._beginByte = 2142720;
				floatValue._beginByte = 2150736;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetCat_Ninja
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetCat_Ninja()
			{
				int32Value._beginByte = 2154748;
				floatValue._beginByte = 2162764;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetCat_Ninja_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetCat_Ninja_5()
			{
				int32Value._beginByte = 2166776;
				floatValue._beginByte = 2174792;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetSanta
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetSanta()
			{
				int32Value._beginByte = 2178804;
				floatValue._beginByte = 2186820;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetAchemist
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetAchemist()
			{
				int32Value._beginByte = 2190832;
				floatValue._beginByte = 2198848;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetRobot
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetRobot()
			{
				int32Value._beginByte = 2202860;
				floatValue._beginByte = 2210876;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetWolf_Ranger
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetWolf_Ranger()
			{
				int32Value._beginByte = 2214888;
				floatValue._beginByte = 2222904;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetWolf_Ranger_5
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetWolf_Ranger_5()
			{
				int32Value._beginByte = 2226916;
				floatValue._beginByte = 2234932;

			};
			enum enumInt32
			{
				Attack = 0,
				Cost_Upgrade = 1,

			};
			enum enumFloat
			{
				Formula = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};

		CSheetHero_General SheetHero_General;
		CSheetPaladin SheetPaladin;
		CSheetPaladin_2 SheetPaladin_2;
		CSheetPaladin_3 SheetPaladin_3;
		CSheetPaladin_4 SheetPaladin_4;
		CSheetPaladin_5 SheetPaladin_5;
		CSheetArcher SheetArcher;
		CSheetArcher_3 SheetArcher_3;
		CSheetArcher_4 SheetArcher_4;
		CSheetArcher_5 SheetArcher_5;
		CSheetFire_Mage SheetFire_Mage;
		CSheetFire_Mage_4 SheetFire_Mage_4;
		CSheetFire_Mage_5 SheetFire_Mage_5;
		CSheetBeast_Master SheetBeast_Master;
		CSheetBeast_Master_4 SheetBeast_Master_4;
		CSheetBeast_Master_5 SheetBeast_Master_5;
		CSheetElecitric_Mage SheetElecitric_Mage;
		CSheetElecitric_Mage_5 SheetElecitric_Mage_5;
		CSheetCat_Ninja SheetCat_Ninja;
		CSheetCat_Ninja_5 SheetCat_Ninja_5;
		CSheetSanta SheetSanta;
		CSheetAchemist SheetAchemist;
		CSheetRobot SheetRobot;
		CSheetWolf_Ranger SheetWolf_Ranger;
		CSheetWolf_Ranger_5 SheetWolf_Ranger_5;

	};
	class FileSkill_design
	{
		public:
		FileSkill_design()
		{

		};

		void Load()
		{
			SheetSheet1.Load();

		};

		void UnLoad()
		{
			SheetSheet1.UnLoad();

		};

		class CSheetSheet1
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetSheet1()
			{
				int32Value._beginByte = 2238944;
				stringValue._beginByte = 2239272;

			};
			enum enumInt32
			{
				ID = 0,
				Damage = 1,
				Duration = 2,
				Hit = 3,
				Hit_delay = 4,
				Status = 5,
				AOE = 6,
				Critical = 7,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetSheet1 SheetSheet1;

	};
	class Filebackground
	{
		public:
		Filebackground()
		{

		};

		void Load()
		{
			SheetSheet1.Load();

		};

		void UnLoad()
		{
			SheetSheet1.UnLoad();

		};

		class CSheetSheet1
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetSheet1()
			{
				int32Value._beginByte = 2240360;

			};
			enum enumInt32
			{
				SpriteID = 0,
				From = 1,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};

		CSheetSheet1 SheetSheet1;

	};
	class FileQuest
	{
		public:
		FileQuest()
		{

		};

		void Load()
		{
			SheetNormal_Quest.Load();
			SheetDaily_Quest.Load();

		};

		void UnLoad()
		{
			SheetNormal_Quest.UnLoad();
			SheetDaily_Quest.UnLoad();

		};

		class CSheetNormal_Quest
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetNormal_Quest()
			{
				int32Value._beginByte = 2240768;
				stringValue._beginByte = 2244304;

			};
			enum enumInt32
			{
				ID = 0,
				Value = 1,
				Group = 2,
				Reward_coins = 3,
				Reward_gems = 4,
				Type = 5,

			};
			enum enumString
			{
				Quest_name = 0,
				Achievement_ID = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetDaily_Quest
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetDaily_Quest()
			{
				int32Value._beginByte = 2251276;
				stringValue._beginByte = 2253012;

			};
			enum enumInt32
			{
				ID = 0,
				Value = 1,
				Group = 2,
				Reward_coins = 3,
				Reward_gems = 4,
				Type = 5,

			};
			enum enumString
			{
				Quest_name = 0,
				Achievement_ID = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetNormal_Quest SheetNormal_Quest;
		CSheetDaily_Quest SheetDaily_Quest;

	};
	class FileRelics_design
	{
		public:
		FileRelics_design()
		{

		};

		void Load()
		{
			SheetWeapon_Relics.Load();
			SheetHero_Relics.Load();
			SheetEnemy_Relics.Load();
			SheetPet_Relics.Load();

		};

		void UnLoad()
		{
			SheetWeapon_Relics.UnLoad();
			SheetHero_Relics.UnLoad();
			SheetEnemy_Relics.UnLoad();
			SheetPet_Relics.UnLoad();

		};

		class CSheetWeapon_Relics
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetWeapon_Relics()
			{
				int32Value._beginByte = 2255504;
				stringValue._beginByte = 2260088;

			};
			enum enumInt32
			{
				ID = 0,
				Weapon_ID = 1,
				Price = 2,
				Duration = 3,
				Attack = 4,
				Attack_Speed = 5,
				Attack_Points = 6,
				Mana = 7,
				Critical = 8,
				AOE = 9,
				Cost_Decrease = 10,
				Unit__Bounce = 11,
				Sub_Group = 12,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetHero_Relics
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetHero_Relics()
			{
				int32Value._beginByte = 2266846;
				stringValue._beginByte = 2272790;

			};
			enum enumInt32
			{
				ID = 0,
				Hero_ID = 1,
				Price = 2,
				Duration = 3,
				Duration_skill = 4,
				Attack = 5,
				Attack_Speed = 6,
				Attack_Points = 7,
				Mana = 8,
				Critical = 9,
				AOE = 10,
				Cost_Decrease = 11,
				Unit__Bounce = 12,
				Sub_Group = 13,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetEnemy_Relics
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetEnemy_Relics()
			{
				int32Value._beginByte = 2279358;
				stringValue._beginByte = 2279846;

			};
			enum enumInt32
			{
				ID = 0,
				Enemy_ID = 1,
				Price = 2,
				Duration = 3,
				Attack = 4,
				Attack_Speed = 5,
				Attack_Points = 6,
				Mana = 7,
				Critical = 8,
				AOE = 9,
				Cost_Increase = 10,
				Unit__Bounce = 11,
				Speed_Move = 12,
				HP = 13,
				Sub_Group = 14,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetPet_Relics
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetPet_Relics()
			{
				int32Value._beginByte = 2280337;
				stringValue._beginByte = 2280569;

			};
			enum enumInt32
			{
				ID = 0,
				Pet_ID = 1,
				Hero_ID = 2,
				Price = 3,
				Duration = 4,
				Attack = 5,
				Attack_Speed = 6,
				Attack_Points = 7,
				Mana = 8,
				Critical = 9,
				AOE = 10,
				Cost_Decrease = 11,
				Unit__Bounce = 12,
				Sub_Group = 13,

			};
			enum enumString
			{
				Name = 0,
				Description = 1,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetWeapon_Relics SheetWeapon_Relics;
		CSheetHero_Relics SheetHero_Relics;
		CSheetEnemy_Relics SheetEnemy_Relics;
		CSheetPet_Relics SheetPet_Relics;

	};
	class FileSpriteManager
	{
		public:
		FileSpriteManager()
		{

		};

		void Load()
		{
			SheetSprite_Hero.Load();
			SheetSprite_Enemy.Load();
			SheetSprite_Relic.Load();
			SheetSprite_Quest.Load();
			SheetSprite_DailyQuest.Load();

		};

		void UnLoad()
		{
			SheetSprite_Hero.UnLoad();
			SheetSprite_Enemy.UnLoad();
			SheetSprite_Relic.UnLoad();
			SheetSprite_Quest.UnLoad();
			SheetSprite_DailyQuest.UnLoad();

		};

		class CSheetSprite_Hero
		{
			public:

			CSheetSprite_Hero()
			{

			};


			void Load()
			{

			};

			void UnLoad()
			{

			};
		};
		class CSheetSprite_Enemy
		{
			public:

			CSheetSprite_Enemy()
			{

			};


			void Load()
			{

			};

			void UnLoad()
			{

			};
		};
		class CSheetSprite_Relic
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetSprite_Relic()
			{
				int32Value._beginByte = 2280842;
				stringValue._beginByte = 2282242;

			};
			enum enumInt32
			{
				SpriteId = 0,
				BackgroundID = 1,

			};
			enum enumString
			{
				Relic_Name = 0,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetSprite_Quest
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetSprite_Quest()
			{
				int32Value._beginByte = 2285568;
				stringValue._beginByte = 2287248;

			};
			enum enumInt32
			{
				SpriteId = 0,
				BackgroundID = 1,

			};
			enum enumString
			{
				Quest_Name = 0,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};
		class CSheetSprite_DailyQuest
		{
			public:

			CSheetSprite_DailyQuest()
			{

			};


			void Load()
			{

			};

			void UnLoad()
			{

			};
		};

		CSheetSprite_Hero SheetSprite_Hero;
		CSheetSprite_Enemy SheetSprite_Enemy;
		CSheetSprite_Relic SheetSprite_Relic;
		CSheetSprite_Quest SheetSprite_Quest;
		CSheetSprite_DailyQuest SheetSprite_DailyQuest;

	};
	class FileTreasure
	{
		public:
		FileTreasure()
		{

		};

		void Load()
		{
			SheetSheet1.Load();
			SheetSheet2.Load();
			SheetOfflineEarning.Load();

		};

		void UnLoad()
		{
			SheetSheet1.UnLoad();
			SheetSheet2.UnLoad();
			SheetOfflineEarning.UnLoad();

		};

		class CSheetSheet1
		{
			public:
			DesignClassDataInt32 int32Value;

			CSheetSheet1()
			{
				int32Value._beginByte = 2293112;

			};
			enum enumInt32
			{
				Battle = 0,
				Type = 1,
				gem = 2,
				coins = 3,

			};


			void Load()
			{
				int32Value.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();

			};
		};
		class CSheetSheet2
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetSheet2()
			{
				int32Value._beginByte = 2301120;
				floatValue._beginByte = 2301236;

			};
			enum enumInt32
			{
				Type = 0,
				Rate = 1,
				size_id = 2,

			};
			enum enumFloat
			{
				Value = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};
		class CSheetOfflineEarning
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataFloat floatValue;

			CSheetOfflineEarning()
			{
				int32Value._beginByte = 2301280;
				floatValue._beginByte = 2301336;

			};
			enum enumInt32
			{
				Value = 0,

			};
			enum enumFloat
			{
				Hours = 0,

			};


			void Load()
			{
				int32Value.Load();
				floatValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				floatValue.UnLoad();

			};
		};

		CSheetSheet1 SheetSheet1;
		CSheetSheet2 SheetSheet2;
		CSheetOfflineEarning SheetOfflineEarning;

	};
	class FilePet
	{
		public:
		FilePet()
		{

		};

		void Load()
		{
			SheetPet_General.Load();

		};

		void UnLoad()
		{
			SheetPet_General.UnLoad();

		};

		class CSheetPet_General
		{
			public:
			DesignClassDataInt32 int32Value;
			DesignClassDataString stringValue;

			CSheetPet_General()
			{
				int32Value._beginByte = 2301392;
				stringValue._beginByte = 2301428;

			};
			enum enumInt32
			{
				ID_Pet = 0,
				ID_Hero = 1,
				Damage = 2,
				Speed_Attack = 3,
				Speed_Move = 4,
				Range = 5,
				Critical = 6,

			};
			enum enumString
			{
				Name = 0,

			};


			void Load()
			{
				int32Value.Load();
				stringValue.Load();

			};

			void UnLoad()
			{
				int32Value.UnLoad();
				stringValue.UnLoad();

			};
		};

		CSheetPet_General SheetPet_General;

	};

	FileCastle_design Castle_design;
	FileEnemy_Creation Enemy_Creation;
	FileEnemy_design Enemy_design;
	FileGeneral General;
	FileHero_design Hero_design;
	FileSkill_design Skill_design;
	Filebackground background;
	FileQuest Quest;
	FileRelics_design Relics_design;
	FileSpriteManager SpriteManager;
	FileTreasure Treasure;
	FilePet Pet;

};

#endif