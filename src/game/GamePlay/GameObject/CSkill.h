#ifndef _SKILL_
#define _SKILL_

#include "../../Lib/DataType/CType.h"

#define SKILL_STATE_NONE		0
#define SKILL_STATE_ACTIVE		1
#define SKILL_STATE_PLAYING		2
#define SKILL_STATE_READY		3
#define SKILL_STATE_END			4

#define NUM_MAX_TARGET			NUM_MAX_ENEMY

#define NUM_MAX_SKILL_STATUE		20
#define NUM_MAX_SKILL_BEAST_MASTER		10
#define NUM_MAX_SKILL_ROBO				50

class CSkill
{
public:
	CSkill();
	~CSkill();
	void Init(int id, float x, float y, int damage);
	void Render(float x, float y);
	void Update();
	void Active(float x, float y, float tarx, float tary, float speed, INT_TIME damage, int duration);
	void Reset();

	int GetID();
	const char* GetName();
	int GetDamageMulti();
	int GetDurarion();
	int GetNumHit();

	int GetHitDelay();
	int GetType();
	bool IsActived();
	int GetState();
	float GetPosX();
	float GetPosY();
	void SetPos(float x, float y);
	void SetTarget(float tarx, float tary);
	CAnimObject _anim;
	int _frame;
	int _sprite;
	float _speed;
	int _anim_index;
	void AddTarget(int index);
	int _list_target[2][NUM_MAX_TARGET];
	int  GetNumTarget();
	int _num_hitted;
	float _dis_fly;
	float _aoe;
	const char* GetDescript();
	CAnimObject _anim_effect;

	CRainShower _rainshower;
	CNinjaStatue _ninjastatue[NUM_MAX_SKILL_STATUE];
	CBeastMaster _beastmaster[NUM_MAX_SKILL_BEAST_MASTER];
	CSanta _santaskill;
	CSkillRobo _roboskill[NUM_MAX_SKILL_ROBO];
	CSkillAcid _acidskill;
	CSkillWordFlash _wordflashskill[NUM_MAX_SKILL_BEAST_MASTER];
	bool HasStatue();
	void AddHPStatue(INT_TIME hp);
	void SkillNinjaStatueUpdate();
	void SkillNinjaStatueRender(float x,float y);
	float _critical;
	bool _has_critical;
	bool CheckEnemyAround(float x, float y, int w);
	void AddDrawAnim(float x, float y);

	CPartical _partical[NUM_MAX_PARTICAL];
	int _num_partical;

	float _effect_hit_scale;
	float _effect_hit_scale_max;
	bool _effect_hit_scale_start;
	float _effect_fake_out_scale;
	float _effect_fake_out_opac;
	int _effect_fake_out_count_frame;
	bool IsFree();
private:
	float _x, _y;
	float _targetx, _targety;
	int _id;
	char _name[50];
	int _damage_multi;
	int _duration;
	int _hit;
	int _hit_delay;
	int _type;
	bool _active;
	int _state;
	int _damage;
	char _descript[256];
};
#endif