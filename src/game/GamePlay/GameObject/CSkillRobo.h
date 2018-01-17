#ifndef _SKILL_ROBO_
#define _SKILL_ROBO_

#include "../../Lib/DataType/CType.h"

#define ROBO_ORIEN_LEFT			0
#define ROBO_ORIEN_RIGHT		1

#define ROBO_STATE_NONE			0
#define ROBO_STATE_ACTIVE		1
#define ROBO_STATE_FLY			2
#define ROBO_STATE_IDLE			3
#define ROBO_STATE_ATTACK		4
#define ROBO_STATE_END			5

#define ROBO_ANIM_INIT			0
#define ROBO_ANIM_FLY			1
#define ROBO_ANIM_ATTACK		2
#define ROBO_ANIM_END			5

#define ROBO_NUM_ANIM			2
#define ROBO_NUM_FRAME_ATTACK		10

class CSkillRobo
{
public:
	CSkillRobo();
	~CSkillRobo();
	float _x, _y;
	float _tarx, _tary;
	float _posx, _posy;
	float _centerx, _centery;
	float _speed;
	float _rotate;
	int _speed_att;
	int _time;
	int _opac;
	int _frameid;
	int _spriteid;
	int _state;
	int _orien;
	int _count_frame_att;
	int _damage;
	int _critical;
	CAnimObject _anim;
	int _enemy_index;
	void Init(int sprite, int frame, float speed);
	void Render(float x, float y);
	void Update();
	void Active(float x, float y, float posx, float posy, float speedatt, int time, int damage, int critical);
	void ForceEnd();
	bool IsFree();
	void AddShadow(float x, float y);
	CBulletAttack _frame_attack[ROBO_NUM_FRAME_ATTACK];
	void InitAttackFrame();
	void AddAttackFrame(int enemy_index);
	void RenderAttackFrame();
	void UpdateAttackFrame();
	void ResetAttackFrame();
private:

};


#endif;