#ifndef _SKILL_WORD_FLASH_
#define _SKILL_WORD_FLASH_

#include "../../Lib/DataType/CType.h"

#define SKILL_WORD_FLASH_STATE_NORMAL			0
#define SKILL_WORD_FLASH_STATE_START			1
#define SKILL_WORD_FLASH_STATE_ACTIVE			2
#define SKILL_WORD_FLASH_STATE_END				3

#define SKILL_WORD_FLASH_MAX_ANIM_EFFECT		3

class CSkillWordFlash
{
public:
	CSkillWordFlash();
	~CSkillWordFlash();
	float _x, _y;
	int _state;
	int _count_frame_hold;
	float _speed;
	CAnimObject _anim;
	int _list_target[NUM_MAX_ENEMY];
	float _effect_x, _effect_y;
	void Init(float x, float y, int sprite, float speed);
	void Render(float x, float y, int opac);
	void Update();
	void Active(float x, float y, int countframe, float speed);
	void CheckEnemyAround(int enemyindex, float aoe, int damage, float critical);
	bool IsFree();
private:

};



#endif;