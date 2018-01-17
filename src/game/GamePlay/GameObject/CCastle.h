#ifndef _CASTLE_
#define _CASTLE_

#include "../../Lib/DataType/CType.h"



class  CCastle
{
public:
	 CCastle();
	~ CCastle();

	
	void Init(int level);
	void Modify();
	void Render(float x, float y, int opac);
	void Update();
	void SetLevel(int level);
	void LevelUp();
	int GetLevel();
    int GetPercentHP();
	INT_TIME GetHP();
	void AddHp(INT_TIME hp);
	INT_TIME _hp_max;
	INT_TIME GetCostUpgrade();
	float _clip_hp_target;
	float _clip_hp_current;
	int _spriteid;
	void ChangeCastle();
	bool _level_max;
	int _count_frame_playsound;
	float _clip_hp_scroll_speed;
private:
	int _level;
	INT_TIME _cost_upgrade;
	INT_TIME _hp;
};



#endif
