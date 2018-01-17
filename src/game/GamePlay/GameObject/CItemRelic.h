#ifndef _ITEM_RELIC_
#define _ITEM_RELIC_

#include "../../Lib/DataType/CType.h"

#define ITEMRELIC_GROUP_HERO		0
#define ITEMRELIC_GROUP_WEAPON		1
#define ITEMRELIC_GROUP_ENEMY		2
#define ITEMRELIC_GROUP_PET			3

class CItemRelic
{
public:
	CItemRelic();
	~CItemRelic();

	float _x, _y;
	int _id;
	int _group;
	int _spriteid;
	int _frameid;
	int _bg_frameid;
	char _name[64];
	char _descript[256];
	int _interactive_id;
	int _price;
	int _duration;
	int _duration_skill;
	int _attack;
	int _attack_speed;
	int _attack_point;
	int _mana;
	int _critical;
	int _aoe;
	int _cost_decrease;
	int _unit_bounce;
	float _speed_move;
	int _hp;
	bool _is_lock;
	int _pet_id;
	int _sub_group;
	void Init(int spriteid, int group, int id, float x, float y, bool lock);
	void Render(float x, float y);
	void Update();
	void AddNew(int group, int id);
	void Reset();
private:

};



#endif