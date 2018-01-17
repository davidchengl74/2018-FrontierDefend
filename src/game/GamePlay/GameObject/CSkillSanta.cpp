#include "pch.h"
#include "../../GameCore/CGame.h"


CSanta::CSanta()
{
}

CSanta::~CSanta()
{
}
void CSanta::Init(float x, float y, float speed, int sprite)
{
	_x = x;
	_y = y;
	_tarx = x;
	_tary = y;
	_speed = speed;
	_spriteid = sprite;
	_santax = _x;
	_santay = _y;
	_santa_tarx = _tarx;
	_santa_tary = _tary;
	_angle = 80;
	_anim_ani1.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_ani1.SetAnim(1, true);
	_anim_ani1.SetPos(_x, _y);
	_anim_ani2.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_ani2.SetAnim(1, true);
	_anim_ani2.SetPos(_x, _y);
	_anim_santa_cart.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim_santa_cart.SetAnim(0, true);
	_anim_santa_cart.SetPos(_santax, _santay);
	_state = SKILL_SANTA_STATE_NONE;
	_count_frame_add_gift = 0;
	for (int i = 0; i < GIFT_PARTICAL_NUM_MAX; i++)
	{
		_gift_partical[i].Init(_spriteid, CMath::RANDOM(9, 11), _x, _y, 5.0f);
	}
}
void CSanta::Render(float x, float y)
{
	if (_state == SKILL_SANTA_STATE_NONE)
	{
		return;
	}
	for (int i = 0; i < GIFT_PARTICAL_NUM_MAX; i++)
	{
		_gift_partical[i].Render(x, y);
	}
	float posx = 15 /** CMath::COS(_angle)*/;
	float posy = -10 /** CMath::SIN(_angle)*/;
	switch (_state)
	{
	case SKILL_SANTA_STATE_ACTIVE:
		_anim_ani1.SetPos(_x + x + posx, _y + y + posy);
		G()->SetRotate(_angle, _x + x + posx, _y + y + posy);
		_anim_ani1.DrawAnimObject(G());
		G()->ClearRotate();
		_anim_santa_cart.SetPos(_santax + x, _santay + y);
		G()->SetRotate(_angle, _santax + x, _santay + y);
		_anim_santa_cart.DrawAnimObject(G());
		G()->ClearRotate();
		posx = -10 /** CMath::COS(_angle)*/;
		posy = 10 /** CMath::SIN(_angle)*/;
		_anim_ani2.SetPos(_x + x + posx, _y + y + posy);
		G()->SetRotate(_angle, _x + x + posx, _y + y + posy);
		_anim_ani2.DrawAnimObject(G());
		G()->ClearRotate();
		break;
	case SKILL_SANTA_STATE_COMEBACK:
		posx = -10 /** CMath::COS(_angle)*/;
		posy = -10 /** CMath::SIN(_angle)*/;
		_anim_ani1.SetPos(_x + x + posx, _y + y + posy);
		G()->SetRotate(_angle, _x + x + posx, _y + y + posy);
		_anim_ani1.DrawAnimObject(G());
		G()->ClearRotate();
		_anim_santa_cart.SetPos(_santax + x, _santay + y);
		G()->SetRotate(_angle, _santax + x, _santay + y);
		_anim_santa_cart.DrawAnimObject(G());
		G()->ClearRotate();
		posx = 15 /** CMath::COS(_angle)*/;
		posy = 10 /** CMath::SIN(_angle)*/;
		_anim_ani2.SetPos(_x + x + posx, _y + y + posy);
		G()->SetRotate(_angle, _x + x + posx, _y + y + posy);
		_anim_ani2.DrawAnimObject(G());
		G()->ClearRotate();
		break;
	default:
		break;
	}
	
	
}
void CSanta::Update()
{
	if (_state == SKILL_SANTA_STATE_NONE)
	{
		return;
	}
	TDGame * game = (TDGame*)GAME()->_current_game;
	switch (_state)
	{
	case SKILL_SANTA_STATE_ACTIVE:
		if (_angle > 0)
		{
			if (_angle >= 72)
			{
				_angle -= 0.7f;
			}
			else
			{
				_angle -= 0.8f;
			}
		}
		if (_angle < 30)
		{
			_count_frame_add_gift--;
			if (_count_frame_add_gift <= 0)
			{
				_count_frame_add_gift = CMath::RANDOM(5, 15);
				AddGiftPartical(_santax - CMath::RANDOM(1, 10) * 2, _santay - 20);
			}
			/*if (_count_frame_add_gift%2 == 0)
			{
				AddGiftPartical(_santax - CMath::RANDOM(1,10)*2, _santay - 20);
			}*/
		}
		_x += _speed*CMath::COS(_angle);
		_y += _speed*CMath::SIN(_angle);
		_santax = _x - (120 + _speed)*CMath::COS(_angle);
		_santay = _y - (120 + _speed)*CMath::SIN(_angle);
		if (_x >= game->_screen_width + 300)
		{
			_state = SKILL_SANTA_STATE_COMEBACK;
			_y -= CMath::RANDOM(4, 10) * 10;
			_anim_ani1.SetAnim(3, true);
			_anim_ani2.SetAnim(3, true);
			_anim_santa_cart.SetAnim(2, true);
		}
		break;
	case SKILL_SANTA_STATE_COMEBACK:
	{
									   bool has_partical = false;
									   for (int i = 0; i < GIFT_PARTICAL_NUM_MAX; i++)
									   {
										   if (!_gift_partical[i].IsFree())
										   {
											   has_partical = true;
										   }
									   }
									   if (!has_partical && _x <= game->_point_o.X - 100)
									   {
										   _state = SKILL_SANTA_STATE_END;
									   }
									   if (_angle < 30 && _x >= game->_point_o.X)
									   {
										   _count_frame_add_gift--;
										   if (_count_frame_add_gift <= 0)
										   {
											   _count_frame_add_gift = CMath::RANDOM(5, 15);
											   AddGiftPartical(_santax - CMath::RANDOM(1, 10) * 2, _santay - 20);
										   }
										   /*if (_count_frame_add_gift%2 == 0)
										   {
										   AddGiftPartical(_santax - CMath::RANDOM(1,10)*2, _santay - 20);
										   }*/
									   }
									   _x -= _speed*CMath::COS(_angle);
									   _y -= _speed*CMath::SIN(_angle);
									   _santax = _x + (120 + _speed)*CMath::COS(_angle);
									   _santay = _y + (120 + _speed)*CMath::SIN(_angle);
	}
		break;
	case SKILL_SANTA_STATE_END:
		_state = SKILL_SANTA_STATE_NONE;
		break;
	default:
		break;
	}
	_anim_ani1.UpdateAnimObject();
	_anim_ani2.UpdateAnimObject();
	_anim_santa_cart.UpdateAnimObject();
	for (int i = 0; i < GIFT_PARTICAL_NUM_MAX; i++)
	{
		_gift_partical[i].Update();
	}
}

void CSanta::Active(float x, float y)
{
	_x = x;
	_y = y;
	_state = SKILL_SANTA_STATE_ACTIVE;
	_angle = 80;
	_count_frame_add_gift = CMath::RANDOM(5, 15);
	_anim_ani1.SetAnim(1, true);
	_anim_ani2.SetAnim(1, true);
	_anim_santa_cart.SetAnim(0, true);
	GAME()->PlaySFX(SFX_SANTA_KILL_1);
}
bool CSanta::IsFree()
{
	bool ret = false;
	if (_state == SKILL_SANTA_STATE_NONE)
	{
		ret = true;
	}
	return ret;
}
void CSanta::AddShadow(float x, float y, int type)
{
	switch (type)
	{
	case 0:
		for (int i = 0; i < SKILL_SANTA_NUM_PARTICAL_SHADOW; i++)
		{
			if (_partical_line1[i].IsFree())
			{
				_partical_line1[i].Active(x, y, 0.7f, 100);
				break;
			}
		}
		break;
	case 1:
		for (int i = 0; i < SKILL_SANTA_NUM_PARTICAL_SHADOW; i++)
		{
			if (_partical_line2[i].IsFree())
			{
				_partical_line2[i].Active(x, y, 0.7f, 100);
				break;
			}
		}
		break;
	default:
		break;
	}
}
void CSanta::AddGiftPartical(float x, float y)
{
	for (int i = 0; i < GIFT_PARTICAL_NUM_MAX; i++)
	{
		if (_gift_partical[i].IsFree())
		{
			float speed = CMath::RANDOM(50, 80)/10.0f;
			_gift_partical[i].Active(x, y, speed);
			break;
		}
	}
}
void CSanta::CheckEnemyAround( int damage, float aoe, float critical)
{
	for (int i = 0; i < GIFT_PARTICAL_NUM_MAX;i++)
	{
		if (!_gift_partical[i].IsFree())
		{
			_gift_partical[i].CheckEnemyAround(damage, aoe, critical);
		}
	}
}

void CSanta::GiftPartical::Init(int sprite, int frame, float x, float y, float speed)
{
	_spriteid = sprite;
	_frameid = frame;
	_x = x;
	_y = y;
	_speed = speed;
	_state = GIFT_PARTICAL_STATE_NONE;
	_effect_fire.Init(_spriteid, 14, 1, 10, 0, true, 1.5f);
}
void CSanta::GiftPartical::Render(float x, float y)
{
	if (_state == GIFT_PARTICAL_STATE_NONE)
	{
		return;
	}
	_effect_fire.Render(0, 0,100);
	if (_state < GIFT_PARTICAL_STATE_FIRE)
	{
		G()->SetRotate(_rotate, _x + x, _y + y);
		GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x, _y + y);
		G()->ClearRotate();
	}
}
void CSanta::GiftPartical::Update()
{
	if (_state == GIFT_PARTICAL_STATE_NONE)
	{
		return;
	}
	switch (_state)
	{
	case GIFT_PARTICAL_STATE_ACTIVE:
		_y += _speed;
		if (_y >= _tary)
		{
			_y = _tary;
			_state = GIFT_PARTICAL_STATE_FIRE;
			//_effect_fire.Active(_x, _y, 5, 5, 1, 0, 1.0f, 50);
		}
		else
		{
			_rotate += 1;
			if (_rotate >= 360)
			{
				_rotate -= 360;
			}
		}
		break;
	case GIFT_PARTICAL_STATE_FIRE:
		
		break;
	case GIFT_PARTICAL_STATE_FIRE_EFFECT:
		_effect_fire.Update();
		if (_effect_fire.IsFree())
		{
			_state = GIFT_PARTICAL_STATE_END;
		}
		break;
	case GIFT_PARTICAL_STATE_END:
		_state = GIFT_PARTICAL_STATE_NONE;
		break;
	default:
		break;
	}
}
void CSanta::GiftPartical::Active(float x, float y, float speed)
{
	_x = x;
	_y = y;
	_speed = speed;
	_tary = CMath::RANDOM(0, 5) * 2 + ROAD_POSY;
	_state = GIFT_PARTICAL_STATE_ACTIVE;
	_rotate = CMath::RANDOM(0, 360);
}
void CSanta::GiftPartical::CheckEnemyAround( int damage, float aoe, float critical)
{
	if (_state > GIFT_PARTICAL_STATE_FIRE)
	{
		return;
	}
	
	int enemyindex;
	TDGame *game = (TDGame*)GAME()->_current_game;
	if (_state < GIFT_PARTICAL_STATE_FIRE)
	{
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			enemyindex = i;
			float enemy_x = game->_enemy[enemyindex].GetPosX();
			float enemy_y = game->_enemy[enemyindex].GetPosY();
			float enemy_w = game->_enemy[enemyindex]._size_w;
			float dis = CMath::DISTANCE(_x, _y, enemy_x, enemy_y);
			//if (enemy_x > game->_screen_width || game->_enemy[enemyindex].GetState() >= CHARACTER_STATE_DIE)
			if (enemy_x > game->_screen_width || !game->_enemy[enemyindex].IsLive())
			{
				continue;
			}
			if (dis <= ( aoe / 2))
			{
				_state = GIFT_PARTICAL_STATE_FIRE;
			}
		}
	}
	
	if (_state == GIFT_PARTICAL_STATE_FIRE)
	{
		float efposx = _x;
		float efposy = _y;
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			enemyindex = i;
			float enemy_x = game->_enemy[enemyindex].GetPosX();
			float enemy_y = game->_enemy[enemyindex].GetPosY();
			float enemy_w = game->_enemy[enemyindex]._size_w;
			//if (enemy_x > game->_screen_width || game->_enemy[enemyindex].GetState() >= CHARACTER_STATE_DIE)
			if (enemy_x > game->_screen_width || !game->_enemy[enemyindex].IsLive())
			{
				continue;
			}
			float dis = CMath::DISTANCE(_x, _y, enemy_x, enemy_y - game->_enemy[enemyindex]._size_h/2);
			if (dis <= (enemy_w / 2 + aoe / 2))
			{
				int rand = CMath::RANDOM(1, 100);
				float posx = enemy_x + CMath::RANDOM(-3, 3) * 3;
				float posy = enemy_y - game->_enemy[enemyindex]._size_h + CMath::RANDOM(-5, 0) * 10;
				if (rand <= critical)
				{
					damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
					game->_enemy[enemyindex].AddHP(-damage, 1, SPRITEID_EFFECT_HIT, false);
					game->AddEffectHPLost(damage, posx, posy, EFFECT_HP_LOST_TYPE_CRITICAL);
				}
				else
				{
					game->_enemy[enemyindex].AddHP(-damage, 1, SPRITEID_EFFECT_HIT, false);
					game->AddEffectHPLost(damage, posx, posy, EFFECT_HP_LOST_TYPE_NORMAL);
				}
				game->_enemy[enemyindex].BeStunActive();
				efposy = enemy_y - game->_enemy[enemyindex]._size_h;
			}
		}
		GAME()->PlaySFX(SFX_SANTA_KILL_2);
		_state = GIFT_PARTICAL_STATE_FIRE_EFFECT;
		_effect_fire.Active(efposx, efposy, 5, 5, 1, 0, 1.0f, 50);
	}
}
bool CSanta::GiftPartical::IsFree()
{
	bool ret = false;
	if (_state == GIFT_PARTICAL_STATE_NONE)
	{
		ret = true;
	}
	return ret;
}