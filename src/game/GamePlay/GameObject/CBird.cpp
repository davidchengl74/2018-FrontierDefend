#include "pch.h"
#include "../../GameCore/CGame.h"

CBird::CBird()
{
}

CBird::~CBird()
{
}

void CBird::Init(int sprite, int id, float x, float y, INT_TIME damage)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_speed = CGameDesign::FilePet::CSheetPet_General::Speed_Move;
	int param_spatt = CGameDesign::FilePet::CSheetPet_General::Speed_Attack;
	int param_dam = CGameDesign::FilePet::CSheetPet_General::Damage;
	int param_cri = CGameDesign::FilePet::CSheetPet_General::Critical;
	int param_aoe = CGameDesign::FilePet::CSheetPet_General::Range;
	int param_heroid = CGameDesign::FilePet::CSheetPet_General::ID_Hero;
	_spriteid = sprite;
	_id = id;
	_x = x;
	_y = y;
	_cenx = _x;
	_ceny = _y;
	_tarx = _x;
	_tary = _y;
	_damage = (INT_TIME)(damage*(game->GetDesignPetInfo(_id, param_dam)/100.0f));
	_speed = game->GetDesignPetInfo(_id, param_speed);
	_speed_att = game->GetDesignPetInfo(_id, param_spatt);
	_critical = game->GetDesignPetInfo(_id, param_cri);
	_heroid = game->GetDesignPetInfo(_id, param_heroid);
	_aoe = game->GetDesignPetInfo(_id, param_aoe);
	_enemy_target = -1;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(BIRD_ANIM_IDLE, false);
	_anim.SetPos(_x, _y);
	SetState(BIRD_STATE_IDLE);
	_count_frame_att = 0;
	GetRelicsBonus();
}
void CBird::Modify(INT_TIME damage)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int param_dam = CGameDesign::FilePet::CSheetPet_General::Damage;
	_damage = (INT_TIME)(damage*(game->GetDesignPetInfo(_id, param_dam) / 100.0f));
	GetRelicsBonus();
}
void CBird::Render(float x, float y)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim.SetPos(_x + x, _y + y);
	_anim.DrawAnimObject(G());
	//game->_draw_manager_able.Add(&_anim, _x + x, _y + y, DRAWABLE_TYPE_NORMAL, 0);
}
void CBird::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_count_frame_att++;
	_anim.UpdateAnimObject();
	if (_count_frame_att >= _speed_att)
	{
		_enemy_target = game->GetEnemyIndexNearest(true);
		if (_enemy_target >= 0 && game->_enemy[_enemy_target].GetPosX() < game->_screen_width)
		{
			_tarx = game->_enemy[_enemy_target].GetPosX();
			_tary = game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h / 2;
			SetState(BIRD_STATE_ATTACK);
			_count_frame_att = 0;
		}
	}
	if (_anim.IsCurrentAnimStop())
	{
		switch (_state)
		{
		case BIRD_STATE_IDLE:
			SetState(BIRD_STATE_IDLE);
			break;
		case BIRD_STATE_ATTACK:
			SetState(BIRD_STATE_ATTACK);
			break;
		case BIRD_STATE_BACK:
			SetState(BIRD_STATE_BACK);
			break;
		default:
			break;
		}
	}
	float speed = _speed;
	if (_state == BIRD_STATE_ATTACK)
	{
		speed *= 4;
	}
	if (CHECK_POINT_IN_CIRCLE(_x, _y, _tarx, _tary, speed))
	{
		_x = _tarx;
		_y = _tary;
		if (_state == BIRD_STATE_ATTACK)
		{
			HitDamage();
			_cenx = game->_enemy[_enemy_target].GetPosX();
			_ceny = game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h;
			_tarx = _cenx - 70;
			_tary = _ceny - CMath::RANDOM(12, 17) * 10;
			SetState(BIRD_STATE_BACK);
		}
	}
	else
	{
		
		float angle = CMath::ANGLE(_x, _y, _tarx, _tary);
		_x += speed*CMath::COS(angle);
		_y += speed*CMath::SIN(angle);
	}
}
void CBird::SetState(int state)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_state = state;
	switch (_state)
	{
	case BIRD_STATE_IDLE:
		_anim.SetAnim(BIRD_ANIM_IDLE, false);
		if (_x > _tarx)
		{
			_anim.SetAnim(BIRD_ANIM_IDLE + BIRD_NUM_ANIM, false);
		}
		break;
	case BIRD_STATE_ATTACK:
		if (_y > _tary)
		{
			_anim.SetAnim(BIRD_ANIM_ATTACK2, false);
			if (_x > _tarx)
			{
				_anim.SetAnim(BIRD_ANIM_ATTACK2 + BIRD_NUM_ANIM, false);
			}
		}
		else
		{
			_anim.SetAnim(BIRD_ANIM_ATTACK1, false);
			if (_x > _tarx)
			{
				_anim.SetAnim(BIRD_ANIM_ATTACK1 + BIRD_NUM_ANIM, false);
			}
		}
		break;
	case BIRD_STATE_BACK:
		_anim.SetAnim(BIRD_ANIM_IDLE, false);
		/*if (_x > _tarx)
		{
			_anim.SetAnim(BIRD_ANIM_IDLE + BIRD_NUM_ANIM, false);
		}*/
		break;
	default:
		break;
	}
}

void CBird::HitDamage()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	int rand = CMath::RANDOM(1, 100);
	INT_TIME damage = _damage;
	if (rand <= _critical)
	{
		game->_user._quest_num_critical_hit++;
		damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
		game->AddEffectHPLost(damage, game->_enemy[_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
	}
	else
	{
		game->AddEffectHPLost(damage, game->_enemy[_enemy_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_target].GetPosY() - game->_enemy[_enemy_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
	}
	game->_enemy[_enemy_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, false);
}

void CBird::GetRelicsBonus()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_damage += (INT_TIME)(_damage*(game->GetRelicsAttack(ITEMRELIC_GROUP_PET, _heroid)) / 100.0f);
	_damage += game->GetRelicsAttackPoint(ITEMRELIC_GROUP_PET, _heroid);
	//_speed_att /= (_speed_att*(game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_PET, _heroid)) / 100.0f);
	float att_mul = (game->GetRelicsAttackSpeed(ITEMRELIC_GROUP_PET, _heroid)) / 100.0f;
	if (att_mul > 0)
	{
		_speed_att /= att_mul;
	}
	_critical += game->GetRelicsCritical(ITEMRELIC_GROUP_PET, _heroid);
	_aoe += game->GetRelicsAOE(ITEMRELIC_GROUP_PET, _heroid);
}