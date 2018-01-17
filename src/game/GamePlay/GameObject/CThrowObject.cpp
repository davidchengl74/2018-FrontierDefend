#include "pch.h"
#include "../../GameCore/CGame.h"


CThrowObject::CThrowObject()
{
}

CThrowObject::~CThrowObject()
{
}

void CThrowObject::Init(int sprite, int frame, float x, float y, float height, float width, float weight, int timespeed, int type, int typeatt, int critical, int aoe)
{
	_sprite = sprite;
	_frame = frame;
	_x = x;
	_y = y;
	_startx = 0;
	_starty = 0;
	_centerx = x;
	_centery = y;
	_height = height;
	_width = width;
	_gravity = 10.0f;
	_time_speed = timespeed;
	_weight = weight;
	_opac = 100;
	_time = 1;
	_state = THROWOBJECT_STATE_NONE;
	_speed = 10.0f;
	_speedx = 3.0f;
	_speedy = 10.0f;
	_angle = 0;
	_rotate = 0;
	_damage = 0;
	_range = aoe;
	_type = type;
	
	_type_attack = typeatt;
	_critical = critical;
	_anim.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_anim.SetAnim(0, false);
	_anim.SetPos(0, 0);
	if (_type == WEAPON_CANNON)
	{
		_anim.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
		_anim.SetAnim(17, true);
		_anim.SetPos(0, 0);
	}
	else if (_type == WEAPON_FROST_MAGE)
	{
		_anim.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
		_anim.SetAnim(18, true);
		_anim.SetPos(0, 0);
	}

	_anim_effect.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_anim_effect.SetAnim(0, false);
	_anim_effect.SetPos(0, 0);
	_anim_effect1.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_anim_effect1.SetAnim(0, false);
	_anim_effect1.SetPos(0, 0);
	_anim_effect2.SetAnimSprite(GET_SPRITE(_sprite), _sprite);
	_anim_effect2.SetAnim(0, false);
	_anim_effect2.SetPos(0, 0);
	_num_target_focus = 0;
	_enemy_index_next_target = -1;
	_is_frame1 = CMath::RANDOM(0, 1);
	_count_frame_hit = 0;
	InitShadow();
	_effect_fire.Init(_sprite, 76,2, 40,0.7f, false,5.0f);
	/*for (int i = 0; i < NUM_MAX_SHADOW; i++)
	{
		_effect_shadow[i].Init(_sprite, CMath::RANDOM(76, 78), -0.05f, 8);
	}*/
	//_effect_fireup.Init(_sprite,76,4,20,1.0f,100,10);
}
void CThrowObject::Render(float x, float y, int opac)
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	//GET_SPRITE(_sprite)->DrawFrame(G(), _frame, _x+ 100,  _height - _y);
	if (_state == THROWOBJECT_STATE_NONE)
	{
		return;
	}
	if (_type == WEAPON_DARKNESS)
	{
		if (_state != THROWOBJECT_STATE_END)
		{
			float x1 = _targetx;
			float y1 = _targety;
			float dis1 = CMath::DISTANCE(x1, y1, _width, _height);

			_rotate = CMath::ANGLE(_width, _height, x1, y1);
			int frame_h1 = GET_SPRITE(_sprite)->GetFrameWidth(1);
			float scale1 = dis1 / (frame_h1*1.0f);
			float scale2 = 1.0f;

			if (_targetx > k_SCREEN_WIDTH)
			{
				scale2 = (200 - (_targetx - k_SCREEN_WIDTH)) / 200.0f;
			}
			G()->ClearClip();
			G()->SetScale(scale1, scale2, _width, _height);
			G()->SetRotate(_rotate, _width, _height);
			GET_SPRITE(_sprite)->DrawFrame(G(), _frame, _width, _height);
			G()->ClearRotate();
			G()->ClearScale();
			_anim_effect.SetPos(_targetx, _targety);
			_anim_effect.DrawAnimObject(G());
			_anim_effect.UpdateAnimObject();
			G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
			G()->SetOpacity(50);
			_anim_effect1.SetPos(_width+5, _height);
			_anim_effect1.DrawAnimObject(G());
			_anim_effect1.UpdateAnimObject();
			G()->SetOpacity(100);
			G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
			
		}
	}
	else if (_type == WEAPON_DRAGON)
	{
		if (_state != THROWOBJECT_STATE_END)
		{
			G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
			_anim_effect.SetPos(_width + _x,_height);
			_anim_effect.DrawAnimObject(G());
			_anim_effect.UpdateAnimObject();
			G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);

		}
	}
	else if (_type == WEAPON_ELECTRIC)
	{
		if (_state == THROWOBJECT_STATE_START)
		{
			float alpha = CMath::ANGLE(_width, _height, _targetx, _targety) - 90;
			float dis = CMath::DISTANCE(_width, _height, _targetx, _targety);
			int frame_h = GET_SPRITE(_sprite)->GetFrameHeight(72);
			float scale = dis / (frame_h*1.0f);
			G()->SetScale(1.0f, scale, _width, _height);
			G()->SetRotate(alpha, _width , _height );
			_anim_effect.SetPos(_width, _height);
			_anim_effect.DrawAnimObject(G());
			_anim_effect.UpdateAnimObject();
			G()->ClearRotate();
			G()->ClearScale();

			if (_enemy_index_target >= 0)
			{
				
				if (_num_target_focus == 0)
				{
					int rand = CMath::RANDOM(1, 100);
					INT_TIME damage = _damage;
					if (rand <= _critical)
					{
						game->_user._quest_num_critical_hit++;
						damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
						game->AddEffectHPLost(damage, game->_enemy[_enemy_index_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_target].GetPosY() - game->_enemy[_enemy_index_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
					}
					else
					{
						game->AddEffectHPLost(damage, game->_enemy[_enemy_index_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_target].GetPosY() - game->_enemy[_enemy_index_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
					}
					game->_enemy[_enemy_index_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
					_enemy_index_next_target = game->GetEnemyIndexRandom(_enemy_index_target);
					if (_enemy_index_next_target >= 0)
					{
						int rand = CMath::RANDOM(1, 100);
						INT_TIME damage = _damage;
						if (rand <= _critical)
						{
							game->_user._quest_num_critical_hit++;
							damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
							game->AddEffectHPLost(damage, game->_enemy[_enemy_index_next_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_next_target].GetPosY() - game->_enemy[_enemy_index_next_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
						}
						else
						{
							game->AddEffectHPLost(damage, game->_enemy[_enemy_index_next_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_next_target].GetPosY() - game->_enemy[_enemy_index_next_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
						}
						game->_enemy[_enemy_index_next_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
						_anim_effect1.SetAnim(18, false);
						_anim_effect2.SetAnim(17, false);
						_num_target_focus++;
					}
					else
					{
						_num_target_focus = NUM_TARGET_ELECTRIC_TOWER;
					}
				}
				else if (_num_target_focus < NUM_TARGET_ELECTRIC_TOWER)
				{
					if (_enemy_index_next_target >= 0)
					{
						float x1 = game->_enemy[_enemy_index_target].GetPosX();
						float y1 = game->_enemy[_enemy_index_target].GetPosY() - 20;
						float x2 = game->_enemy[_enemy_index_next_target].GetPosX();
						float y2 = game->_enemy[_enemy_index_next_target].GetPosY() - 20;
						float alpha1 = CMath::ANGLE(x1, y1, x2, y2) - 90;
						float dis1 = CMath::DISTANCE(x1, y1, x2, y2);
						int frame_h1 = GET_SPRITE(_sprite)->GetFrameHeight(79);
						float scale1 = dis1 / (frame_h1*1.0f);
						G()->SetScale(1.0f, scale1, x1, y1);
						G()->SetRotate(alpha1, x1, y1);
						_anim_effect1.SetPos(x1, y1);
						_anim_effect1.DrawAnimObject(G());
						_anim_effect1.UpdateAnimObject();
						G()->ClearRotate();
						G()->ClearScale();
						_anim_effect2.SetPos(x1, y1);
						_anim_effect2.DrawAnimObject(G());
						_anim_effect2.UpdateAnimObject();
					}
					else
					{
						_num_target_focus = NUM_TARGET_ELECTRIC_TOWER;
					}
					if (_anim_effect2.IsCurrentAnimStop())
					{
						_enemy_index_target = _enemy_index_next_target;
						_enemy_index_next_target = game->GetEnemyIndexRandom(_enemy_index_target);
						if (_enemy_index_next_target >= 0)
						{
							int rand = CMath::RANDOM(1, 100);
							INT_TIME damage = _damage;
							if (rand <= _critical)
							{
								game->_user._quest_num_critical_hit++;
								damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
								game->AddEffectHPLost(damage, game->_enemy[_enemy_index_next_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_next_target].GetPosY() - game->_enemy[_enemy_index_next_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
							}
							else
							{
								game->AddEffectHPLost(damage, game->_enemy[_enemy_index_next_target].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[_enemy_index_next_target].GetPosY() - game->_enemy[_enemy_index_next_target]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
							}
							game->_enemy[_enemy_index_next_target].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
							_anim_effect1.SetAnim(18, false);
							_anim_effect2.SetAnim(17, false);
							_num_target_focus++;
						}
						else
						{
							_num_target_focus = NUM_TARGET_ELECTRIC_TOWER;
							
						}
					}
				}
			}
			if (_num_target_focus >= NUM_TARGET_ELECTRIC_TOWER && _anim_effect.IsCurrentAnimStop())
			{
				_enemy_index_target = -1;
				_enemy_index_next_target = -1;
				_num_target_focus = 0;
				_state = THROWOBJECT_STATE_END;
			}
		}
	}
	else
	{
		if (_state == THROWOBJECT_STATE_START)
		{
			if (_type == WEAPON_FROST_MAGE)
			{
				/*for (int i = 0; i < NUM_MAX_SHADOW; i++)
				{
					_effect_shadow[i].Render(x, y);
				}*/
			}
			G()->SetRotate(-_rotate, _x + _width, _height - _y);
			if (_type == WEAPON_CANNON)
			{
				_anim.SetPos(_x + _width, _height - _y);
				_anim.DrawAnimObject(G());
			}
			else if (_type == WEAPON_CHIMERA)
			{
				if (_anim.GetCurrentAnim() == 16)
				{
					_anim.SetPos(_x + _width, _height - _y);
					_anim.DrawAnimObject(G());
					_anim.UpdateAnimObject();
				}
			}
			else
			{
				GET_SPRITE(_sprite)->DrawFrame(G(), _frame, _x + _width, _height - _y);
			}

			G()->ClearRotate();
			if (_type == WEAPON_CHIMERA)
			{
				if (_anim.GetCurrentAnim() != 16)
				{
					//G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_LIGHT);
					_anim.SetPos(_x , _y);
					_anim.DrawAnimObject(G());
					_anim.UpdateAnimObject();
					//G()->SetFillterMode(BLEND_MODE::ALPHA_FILLTER_NORMAL);
				}
			}
		}

		if (_state == THROWOBJECT_STATE_END)
		{
			if (_type != WEAPON_ARCHER)
			{
				int frame_w = GET_SPRITE(_sprite)->GetFrameWidth(_frame) / 2;
				int effect_x = frame_w*CMath::COS(-_rotate);
				int effect_y = frame_w*CMath::SIN(-_rotate);
				/*if (_type == WEAPON_TWIN)
				{
					effect_x = 0;
					effect_y = 0;
				}*/
				_anim_effect.SetPos(_x + _width + effect_x, _height - _y + effect_y);
				if (_type == WEAPON_FROST_MAGE)
				{
					if (_effect_fire._status == EFFECT_FIRE_STATE_NORMAL)
					{
						_effect_fire.Active(_x + _width + effect_x, _height - _y + effect_y, 6, 8, 0.2, -0.01f, 0.7f, 50);
					}
					_effect_fire.Render(0, 0, 100);
					/*if (_effect_fireup.IsFree())
					{
						_effect_fireup.Active(_x + _width + effect_x, _height - _y + effect_y, _x + _width + effect_x, ROAD_POSY + CMath::RANDOM(-1,5)*3,20,20,0,2);
					}
					_effect_fireup.Render(0, 0);*/
				}
				else
				{
					_anim_effect.DrawAnimObject(G());
				}
			}
		}
	}
	
	/*G()->SetColor(0x90ff0000);
	if (_type == WEAPON_FIRE_MAGE)
	{
		G()->SetColor(0x9000ff00);
	}
	G()->FillRect(_targetx, _targety, 50, 50, true);*/
}
void CThrowObject::Update()
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	if (_state == THROWOBJECT_STATE_END)
	{
		_anim_effect.UpdateAnimObject();
	}
	_effect_fire.Update();
	_effect_fireup.Update();
	UpdateShadow();
	if (_state != THROWOBJECT_STATE_START)
	{
		return;
	}
	if (_type == WEAPON_CANNON || _type == WEAPON_CHIMERA)
	{
		_anim.UpdateAnimObject();
	}
	/*for (int i = 0; i < NUM_MAX_SHADOW; i++)
	{
		_effect_shadow[i].Update();
	}*/
	if (_type == WEAPON_FROST_MAGE)
	{
		AddShadow(_x + _width + CMath::RANDOM(-10, 10), _height - _y + CMath::RANDOM(-5, 10));
	}
	_time++;
	if (_height - _y < _targety || _height - _y < ROAD_POSY - 50)
	{
		float xold = _x;
		float yold = _y;
		switch (_type)
		{
		case WEAPON_ELECTRIC:
			break;
		case WEAPON_DARKNESS:
			_targetx += 5;
			if (_targetx >= k_SCREEN_WIDTH)
			{
				//_targety -= 2;
				_targetx += 8;
			}
			if (_targetx >= k_SCREEN_WIDTH + 200)
			{
				_state = THROWOBJECT_STATE_END;
			}
			break;
		case WEAPON_TWIN:
			_x = _speed*CMath::COS(_angle)*((_time / (float)_time_speed));
			_y = _speed*CMath::SIN(_angle)*((_time / (float)_time_speed));
			break;
		case WEAPON_HOLY:
			_x = _speed*CMath::COS(_angle)*((_time / (float)_time_speed));
			_y = _speed*CMath::SIN(_angle)*((_time / (float)_time_speed));
			break;
		case WEAPON_CHIMERA:
			if (_anim.GetCurrentAnim() == 16)
			{
				_x = _speed*CMath::COS(_angle)*((_time / (float)_time_speed));
				_y = _speed*CMath::SIN(_angle)*((_time / (float)_time_speed));
			}
			else
			{
				if (_anim.IsCurrentAnimStop())
				{
					if (_anim.GetCurrentAnim() == 17)
					{
						_anim.SetAnim(18, true);
					}
				}
				_x += 2;
				if (_x >= game->_screen_width + 100)
				{
					_x = game->_screen_width + 100;
					_state = THROWOBJECT_STATE_END;
				}
				//_y = _speed*CMath::SIN(_angle)*((_time / (float)_time_speed));
			}
			
			break;
			
			case WEAPON_DRAGON:
				_x += 15;
				if (_x >= game->_screen_width + 10)
				{
					_x = game->_screen_width + 10;
					_state = THROWOBJECT_STATE_END;
				}
				break;
		default:
			_x = _speed*CMath::COS(_angle)*((_time / (float)_time_speed));
			_y = _speed*CMath::SIN(_angle)*(_time / (float)_time_speed) - 0.5f * _gravity * _weight*((_time / (float)_time_speed)*(_time / (float)_time_speed));
			break;
		}
		if (_time > 2 && _type != WEAPON_DARKNESS)
		{
			_rotate = CMath::ANGLE(xold, yold, _x, _y);
		}
		HitsDamage(false);
	}
	if (_height - _y >= _targety && _state != THROWOBJECT_STATE_END)
	{
		_y = _height - _targety;
		HitsDamage(true);
		if (_type == WEAPON_CANNON)
		{
			//PLAY_SFX(SFX_TOWER_CANNON_EXPLODE);
            GAME()->PlaySFX(SFX_TOWER_CANNON_EXPLODE);
		}
		if (_type == WEAPON_FROST_MAGE)
		{
			GAME()->PlaySFX(SFX_TOWER_FROST);
			//PLAY_SFX(SFX_TOWER_FROST);
		}
		_state = THROWOBJECT_STATE_END;
	}
}

bool CThrowObject::CheckHitPoint(float x, float y, float w, float h)
{
	if (_type_attack == THROWOBJECT_TYPE_FOCUS)
	{
		if (CHECK_POINT_IN_RECT(_x + _width - _range/2, _height - _y, x - w/2, y, w + _range, h))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		float dis = CMath::DISTANCE(_x + _width, _height - _y, x, y);
		//if (x >= _x + _width - _range / 2 && x <= _x + _width + _range / 2 && y >= _height - _y - h && y <= _height - _y + h)
		if (dis <= _range / 2 + w / 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool CThrowObject::IsEnd()
{
	if (_state == THROWOBJECT_STATE_END || _state == THROWOBJECT_STATE_NONE)
	{
		return true;
	}
	return false;
}

void CThrowObject::Active(float tarx, float tary, INT_TIME damage, int index, float aoe)
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	float deltax = 3.0f;
	float deltaymax = 0;
	if (_type == WEAPON_CANNON)
	{
		deltax = 2.0f;
		deltaymax = (_height - _y) /4;
	}
	//if (game->_enemy[index].GetSprite() == SPRITEID_MONSTER_FLYING || (game->_enemy[index].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[index].GetPosY() < ROAD_POSY - 50))
	if (game->_enemy[index]._status == CHARACTER_STATUS_FLY || game->_enemy[index]._status == CHARACTER_STATUS_CARRY_FLY)
	{
		deltax = 1.7f;
	}
	_x = _centerx ;
	_y = _centery;

	_targetx = tarx;
	_targety = tary;
	_time = 1;
	_speed = CMath::DISTANCE(_x, _y, _targetx, _targety) / 10.0f;
	_speedx = CMath::ABSOLUTE_VALUE(_x - _targetx) / deltax;
	_speedy = CMath::ABSOLUTE_VALUE(_y - _targety) / 10.0f;
	float disx = CMath::ABSOLUTE_VALUE(_x - _targetx);
	float ymax = _y - deltaymax;
	
	float x_ymax = _speedx*_speedx*CMath::SIN(45)*CMath::COS(45) / _gravity;
	float alpha = CMath::ANGLE(_x+_width, _height - _y, x_ymax, ymax);
	if (alpha > 83)
	{
		alpha = 83;
	}
	_speed = CMath::SQRT((disx * _gravity / (CMath::SIN(alpha)*CMath::COS(alpha))));
	_angle = alpha;
	_rotate = alpha;
	_anim_effect.SetAnim(16, false);
	switch (_type)
	{
	case WEAPON_ARCHER:
		//if (game->_enemy[index].GetSprite() == SPRITEID_MONSTER_FLYING || (game->_enemy[index].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[index].GetPosY() < ROAD_POSY - 50))
		if (game->_enemy[index]._status == CHARACTER_STATUS_FLY || game->_enemy[index]._status == CHARACTER_STATUS_CARRY_FLY)
		{
			x_ymax = _speedx*_speedx*CMath::SIN(45)*CMath::COS(45) / _gravity;
			ymax = _y - _targety*CMath::SIN(45);
			alpha = 60;
			_speed = CMath::SQRT((disx * _gravity * 2 / (CMath::SIN(alpha)*CMath::COS(alpha))));
			_angle = alpha;
			_rotate = -alpha;
		}
		break;
	case WEAPON_FIRE_MAGE:
		x_ymax = _speedx*_speedx*CMath::COS(0) / _gravity;
		_targety -= 20;
		alpha = CMath::ANGLE(_x + _width, _height - _y, x_ymax, _targety);
		_speed = CMath::SQRT((disx * _gravity / (CMath::SIN(alpha)*CMath::COS(alpha))));
		_angle = -alpha;
		_rotate = -alpha;
		//PLAY_SFX(SFX_TOWER_FIREMAGE);
		GAME()->PlaySFX(SFX_TOWER_FIREMAGE);
		break;
	case WEAPON_CANNON:
	{
						  alpha = CMath::ANGLE(_x + _width, _height - _y, _targetx, _targety);
						  float scale_port = GAME()->_game_context.ScaleOut - 1.0f;
						  if (scale_port < 0)
						  {
							  scale_port = 0;
						  }
						  _speed = 200 + CMath::ABSOLUTE_VALUE(_x - _targetx)*scale_port / 8.0f;
						  //printf("\n cannon speed = %f", _speed);
						  _angle = alpha;
						  _rotate = alpha;
						  _anim.SetAnim(17, true);
						  GAME()->PlaySFX(SFX_TOWER_CANNON);
						  //PLAY_SFX(SFX_TOWER_CANNON);
	}

		break;
	case WEAPON_ELECTRIC:
		_targetx = game->_enemy[index].GetPosX();
		_targety = game->_enemy[index].GetPosY();
		_anim_effect.SetAnim(16, false);
		_anim_effect1.SetAnim(18, false);
		_anim_effect2.SetAnim(17, false);
		_num_target_focus = 0;
		GAME()->PlaySFX(SFX_TOWER_ELECTRIC);
		//PLAY_SFX(SFX_TOWER_ELECTRIC);
		break;
	case WEAPON_FROST_MAGE:
		//if (game->_enemy[index].GetSprite() == SPRITEID_MONSTER_FLYING || (game->_enemy[index].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[index].GetPosY() < ROAD_POSY - 50))
		if (game->_enemy[index]._status == CHARACTER_STATUS_FLY || game->_enemy[index]._status == CHARACTER_STATUS_CARRY_FLY)
		{
			_targety -= game->_enemy[index]._size_h;
			//x_ymax = _speedx*_speedx*CMath::COS(60) / _gravity;
		}
		else
		{
			_targety -= game->_enemy[index]._size_h / 2;
			x_ymax = _speedx*_speedx*CMath::COS(40) / _gravity;
		}

		//_targety -= 20;
		alpha = CMath::ANGLE(_x + _width, _height - _y, x_ymax, _targety);
		_speed = CMath::SQRT((disx * _gravity / (CMath::SIN(alpha)*CMath::COS(alpha))));
		_angle = -alpha;
		_rotate = -alpha;
		_effect_fire._status = EFFECT_FIRE_STATE_NORMAL;
		_effect_fireup.Reset();

		break;
	case WEAPON_TWIN:
		_x = 0;
		_y = 0;
		_targetx = game->_enemy[index].GetPosX();
		_targety = game->_enemy[index].GetPosY() - 20;
		alpha = CMath::ANGLE(_x + _width, _height - _y, _targetx, _targety);
		_speed = CMath::DISTANCE(_x + _width, _height - _y, _targetx, _targety) / 6.0f;
		_angle = -alpha;
		_rotate = -alpha;
		//if (_is_frame1)
		{
			_frame = 1;
			_is_frame1 = false;
			_anim_effect.SetAnim(16, false);
		}
		/*else
		{
		_frame = 2;
		_is_frame1 = true;
		_anim_effect.SetAnim(17, false);
		}*/
		//GAME()->PlaySFX(SFX_TOWER_STWIN);
		break;
	case WEAPON_HOLY:
	{
						_x = _width;
						_y = _height;
						_targetx = game->_enemy[index].GetPosX();
						_targety = ROAD_POSY - 50 + game->_point_o.Y;
						if (_targetx < ENEMY_TARGETX + game->_point_o.X)
						{
							_targetx = ENEMY_TARGETX + game->_point_o.X;
						}
						alpha = CMath::ANGLE(_x, _y, _targetx, _targety);
						_speed = CMath::DISTANCE(_x, _y, _targetx, _targety) / 1.2f;
						_angle = -alpha;
						_rotate = -alpha;
						int rand = CMath::RANDOM(1, 100);
						_frame = 1;
						if (rand <= game->GetDesignGeneralInfo(DESIGN_GENERAL_HOLY_SLAM_PERCENT))
						{
							_frame = 57;
						}
						GAME()->PlaySFX(SFX_TOWER_SLAM);
						//PLAY_SFX(SFX_TOWER_SLAM);
	}

		break;
	case WEAPON_DARKNESS:
		_targetx = ENEMY_TARGETX + game->_point_o.X;
		_targety = ROAD_POSY + 20;
		_rotate = 90;
		_anim_effect1.SetAnim(16, true);
		_anim_effect.SetAnim(17, true);
		_count_frame_hit = 0;
		GAME()->PlaySFX(SFX_TOWER_PHOENIX);
		//PLAY_SFX(SFX_TOWER_PHOENIX);
		//_anim_effect1.SetAnim(18, false);
		break;
	case WEAPON_DRAGON:
		_anim_effect.SetAnim(16, true);
		_count_frame_hit = 0;
		GAME()->PlaySFX(SFX_TOWER_DRAGON);
		//PLAY_SFX(SFX_TOWER_DRAGON);
		break;
	case WEAPON_CHIMERA:
	{
		_x = _width;
		_y = _height;
		_targetx = game->_enemy[index].GetPosX();
		_targety = ROAD_POSY - 50 + game->_point_o.Y;
		if (_targetx < ENEMY_TARGETX + game->_point_o.X)
		{
			_targetx = ENEMY_TARGETX + game->_point_o.X;
		}
		alpha = CMath::ANGLE(_x, _y, _targetx, _targety);
		_speed = CMath::DISTANCE(_x, _y, _targetx, _targety) / 2.0f;
		_angle = -alpha;
		_rotate = -alpha;
		_anim_effect.SetAnim(20, false);
		_frame = 1;
		int rand = CMath::RANDOM(1, 100);
		if (rand <= game->GetDesignGeneralInfo(DESIGN_GENERAL_CHIMERA_TOR_PER))
		{
			float damagex = game->GetDesignGeneralInfo(DESIGN_GENERAL_CHIMERA_TOR_DMG) / 100.0f;
			damage *= damagex;
			_anim.SetAnim(17, false);
			_x = WEAPON_ACHER_POSX + 30;
			_y = ROAD_POSY + 20;
			_type_attack = THROWOBJECT_TYPE_FOCUS;
			aoe = 80;
			_targety = _y;
		}
		else
		{
			_type_attack = THROWOBJECT_TYPE_AOE;
			_anim.SetAnim(16, true);
			GAME()->PlaySFX(SFX_TOWER_CHIMERA);
			//PLAY_SFX(SFX_TOWER_CHIMERA);
		}
	}
		break;
	default:
		break;
	}
	if (_targety >= ROAD_POSY + 40 + game->_point_o.Y)
	{
		_targety = ROAD_POSY + 40 + game->_point_o.Y;
	}
	_damage = damage;
	_state = THROWOBJECT_STATE_START;
	_enemy_index_target = index;
	_range = aoe;
}

void CThrowObject::HitsDamage(bool isEnd)
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	if (_state == THROWOBJECT_STATE_END)
	{
		return;
	}
	if (_type_attack == THROWOBJECT_TYPE_FOCUS)
	{
		if (_type != WEAPON_ELECTRIC && _type != WEAPON_DARKNESS && _type != WEAPON_DRAGON && _type != WEAPON_CHIMERA)
		{
			int rand = CMath::RANDOM(1, 100);
			for (int i = 0; i < game->_num_enemy_inwave; i++)
			{
				//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
				if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
				{
					continue;
				}
				float posx = game->_enemy[i].GetPosX();
				float posy = game->_enemy[i].GetPosY();
				int w = game->_enemy[i]._size_w + 20;
				int h = game->_enemy[i]._size_h;
				float tarx = posx - 20;
				float tary = posy - 80;

				//printf("\n x = %f,y=%f,posx=%f,posy=%f", _width+_x,_height-_y,posx,posy);
				if (CheckHitPoint(tarx, tary, w, h))
				{
					INT_TIME damage = _damage;
					int index = i;
					if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
					{
						index = game->_enemy[i]._enemy_bird_index;
					}
					if (rand <= _critical)
					{
						game->_user._quest_num_critical_hit++;
						damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
						game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
					}
					else
					{
						game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
					}
					game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);

					_state = THROWOBJECT_STATE_END;
					break;
				}
			}
		}
		else
		{
			if (_type == WEAPON_DARKNESS)
			{
				_count_frame_hit++;
				if (_count_frame_hit % 15 == 0)
				{
					for (int i = 0; i < game->_num_enemy_inwave; i++)
					{

						//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
						if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
						{
							continue;
						}
						int rand = CMath::RANDOM(1, 100);
						float posx = game->_enemy[i].GetPosX();
						float posy = game->_enemy[i].GetPosY();
						int w = game->_enemy[i]._size_w + 20;
						int h = game->_enemy[i]._size_h;
						float tarx = posx - 20;
						float tary = posy - 80;
						float dis = CMath::DISTANCE(_targetx, _targety, posx, posy);
						if (dis <= _range / 2 + w / 2)
						{
							INT_TIME damage = _damage;
							int index = i;
							if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
							{
								index = game->_enemy[i]._enemy_bird_index;
							}
							if (rand <= _critical)
							{
								game->_user._quest_num_critical_hit++;
								damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
							}
							else
							{
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
							}
							game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
						}
					}
				}
			}
			else if (_type == WEAPON_DRAGON)
			{

				//if (_count_frame_hit % 120 == 0)
				if (_count_frame_hit % 6 == 0)
				{
					AddShadow(_x + _width, _height + 46);
				}
				_count_frame_hit++;
				{
					for (int i = 0; i < game->_num_enemy_inwave; i++)
					{

						//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
						if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
						{
							continue;
						}
						int rand = CMath::RANDOM(1, 100);
						float posx = game->_enemy[i].GetPosX();
						float posy = game->_enemy[i].GetPosY();
						if (_x + 15 + _width >= posx && _x + _width <= posx && CMath::ABSOLUTE_VALUE(posy - _height) <= _range)
						{
							INT_TIME damage = _damage;
							int index = i;
							if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
							{
								index = game->_enemy[i]._enemy_bird_index;
							}
							if (rand <= _critical)
							{
								game->_user._quest_num_critical_hit++;
								damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
							}
							else
							{
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
							}
							game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
						}
					}
				}
			}
			else if (_type == WEAPON_CHIMERA)
			{
				_count_frame_hit++;
				//if (_count_frame_hit % 30 == 0)
				{
					for (int i = 0; i < game->_num_enemy_inwave; i++)
					{
						//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width	|| (game->_enemy[i]._status >= CHARACTER_STATUS_FLY && game->_enemy[i]._status <= CHARACTER_STATUS_CARRY_FLY))
						if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width	|| (game->_enemy[i]._status >= CHARACTER_STATUS_FLY && game->_enemy[i]._status <= CHARACTER_STATUS_CARRY_FLY))
						{
							continue;
						}
						int rand = CMath::RANDOM(1, 100);
						float posx = game->_enemy[i].GetPosX();
						float posy = game->_enemy[i].GetPosY();
						int w = game->_enemy[i]._size_w + 20;
						int h = game->_enemy[i]._size_h;
						float tarx = posx - 20;
						float tary = posy - 80;
						float dis = CMath::DISTANCE(_x, _y, posx, posy);
						float disx = CMath::ABSOLUTE_VALUE(_x - posx);
						if ((disx <= _range / 2 + w /4) && (game->_enemy[i]._status < CHARACTER_STATUS_FLY || game->_enemy[i]._status > CHARACTER_STATUS_CARRY_FLY))
						{
							game->_enemy[i].BeSkillActive(BE_SKILL_TORNADO);
						}
						if (game->_enemy[i]._count_frame_has_tornado > 0)
						{
							continue;
						}
						if (dis <= _range / 2 + w / 2)
						{
							INT_TIME damage = _damage;
							int index = i;
							if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
							{
								index = game->_enemy[i]._enemy_bird_index;
							}
							if (rand <= _critical)
							{
								game->_user._quest_num_critical_hit++;
								damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
							}
							else
							{
								game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
							}
							game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
							game->_enemy[i]._count_frame_has_tornado = 30;
							
						}
					}
				}
				
			}
		}
	}
	if (_type != WEAPON_CANNON && _type != WEAPON_HOLY && _type != WEAPON_FROST_MAGE && _type != WEAPON_CHIMERA)
	{
		int rand = CMath::RANDOM(1, 100);
		bool hit = false;
		for (int i = 0; i < game->_num_enemy_inwave; i++)
		{
			//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
			if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
			{
				continue;
			}
			float tarx = game->_enemy[i].GetPosX() - 20;
			float tary = game->_enemy[i].GetPosY();
			int w = game->_enemy[i]._size_w + 20;
			int h = game->_enemy[i]._size_h;
			if (CheckHitPoint(tarx - 5, tary, w, h / 2))
			{
				hit = true;
				INT_TIME damage = _damage;
				int index = i;
				if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
				{
					index = game->_enemy[i]._enemy_bird_index;
				}
				if (rand <= _critical)
				{
					game->_user._quest_num_critical_hit++;
					damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
					game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
				}
				else
				{
					game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
				}
				game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);

				
				if (_type == WEAPON_FROST_MAGE)
				{
					game->_enemy[index].BeSkillActive(BE_SKILL_SLOW);
				}
			}
		}
		if (hit)
		{
			_state = THROWOBJECT_STATE_END;
			
		}
	}
	else/* (_type_attack == THROWOBJECT_TYPE_AOE)*/
	{
		if (isEnd)
		{
			int rand = CMath::RANDOM(1, 100);
			for (int i = 0; i < game->_num_enemy_inwave; i++)
			{
				//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
				if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
				{
					continue;
				}
				float tarx = game->_enemy[i].GetPosX() - 20;
				float tary = game->_enemy[i].GetPosY() - 80;
				int w = game->_enemy[i]._size_w + 20;
				int h = game->_enemy[i]._size_h;
				if (CheckHitPoint(tarx - 5, tary, w, _range + h))
				{
					INT_TIME damage = _damage;
					int index = i;
					if (game->_enemy[i].GetSkillID() == CHARACTER_SKILL_FLYING && game->_enemy[game->_enemy[i]._enemy_bird_index].GetState() < CHARACTER_STATE_RUN)
					{
						index = game->_enemy[i]._enemy_bird_index;
					}
					if (rand <= _critical)
					{
						game->_user._quest_num_critical_hit++;
						damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
						game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
					}
					else
					{
						game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
					}
					game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
					if (_type == WEAPON_FROST_MAGE)
					{
						game->_enemy[index].BeSkillActive(BE_SKILL_SLOW);
					}
					else if (_type == WEAPON_HOLY && _frame == 57)
					{
						game->_enemy[index].BeSkillActive(BE_SKILL_BURN_BY_WEAPON);
						
					}
					else if (_type == WEAPON_CHIMERA && _anim.GetCurrentAnim() != 16)
					{
						game->_enemy[index].BeSkillActive(BE_SKILL_TORNADO);
					}
					if (_type == WEAPON_HOLY)
					{
						game->_enemy[index].BeStunActive(2*60);
					}
				}
			}
		}
	}
}

float CThrowObject::GetTimeToTarget(float tarx, float tary)
{
	float dis = CMath::DISTANCE(_centerx, _centery, tarx, tary)/3.0f;
	return dis/(_speed*1.0f);
}

void CThrowObject::RenderShadow(float x, float y)
{
	for (int i = 0; i < NUM_MAX_SHADOW; i++)
	{
		_shadow[i].Render(x, y);
	}
}
void CThrowObject::UpdateShadow()
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	switch (_type)
	{
	case WEAPON_DRAGON:
		for (int j = 0; j < NUM_MAX_SHADOW; j++)
		{
			_shadow[j].Update();
			if (_shadow[j]._state == SHADOW_STATE_START)
			{
				for (int i = 0; i < game->_num_enemy_inwave; i++)
				{
					//if (game->_enemy[i].GetState() >= CHARACTER_STATE_DIE || game->_enemy[i].GetPosX() >= game->_screen_width)
					if (!game->_enemy[i].IsLive() || game->_enemy[i].GetPosX() >= game->_screen_width)
					{
						continue;
					}
					int rand = CMath::RANDOM(1, 100);
					float posx = game->_enemy[i].GetPosX();
					float posy = game->_enemy[i].GetPosY();
					if (_shadow[j]._x + 70 >= posx && _shadow[j]._x - 70 <= posx && posy >= ROAD_POSY - 20 && game->_enemy[i]._count_frame_has_fired <= 0)
					{
						INT_TIME damage = _damage/10;
						int index = i;
						/*if (rand <= _critical)
						{
							game->_user._quest_num_critical_hit++;
							damage *= game->GetDesignGeneralInfo(DESIGN_GENERAL_X_CRITICAL);
							game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - 120 + CMath::RANDOM(-5, 1) * 10, EFFECT_HP_LOST_TYPE_CRITICAL);
						}
						else*/
						{
							game->AddEffectHPLost(damage, game->_enemy[index].GetPosX() + CMath::RANDOM(-3, 3) * 3, game->_enemy[index].GetPosY() - game->_enemy[index]._size_h + CMath::RANDOM(-5, 0) * 10, EFFECT_HP_LOST_TYPE_NORMAL);
						}
						game->_enemy[index]._count_frame_has_fired = 30;
						game->_enemy[index].AddHP(-damage, CMath::RANDOM(0, 2), SPRITEID_EFFECT_HIT, true);
					}
				}
			}
		}
		break;
	default:
		for (int i = 0; i < NUM_MAX_SHADOW; i++)
		{
			_shadow[i].Update();
		}
		break;
	}
	
}
void CThrowObject::InitShadow()
{
	switch (_type)
	{
	case WEAPON_DRAGON:
		for (int i = 0; i < NUM_MAX_SHADOW; i++)
		{
			_shadow[i].Init(_sprite, 0, 5, 0, SHADOW_TYPE_ANIM);
		}
		break;
	default:
		for (int i = 0; i < NUM_MAX_SHADOW; i++)
		{
			_shadow[i].Init(_sprite, 0, 1, 0, SHADOW_TYPE_FRAME);
		}
		break;
	}
	
}
void CThrowObject::AddShadow(float x, float y)
{
	switch (_type)
	{
	case WEAPON_DRAGON:
		
		for (int i = 0; i < NUM_MAX_SHADOW; i++)
		{
			if (_shadow[i].IsFree())
			{
				_shadow[i].Active(x, y, 0, 1.0f, 17,300);
				break;
			}
		}
		break;
	case WEAPON_FROST_MAGE:
		for (int i = 0; i < NUM_MAX_SHADOW; i++)
		{
			if (_effect_shadow[i].IsFree())
			{
				_effect_shadow[i].Active(x, y, CMath::RANDOM(4,8)/10.0f, 100);
				break;
			}
		}
		break;
	default:
		break;
	}
	
}

void CThrowObject::Shadow::Init(int sprite, int frame, float speedopac, float speedscale, int type)
{
	_x = 0; _y = 0;
	_opac = 100;
	_scale = 1.0f;
	_opac_speed = speedopac;
	_scale_speed = speedscale;
	_spriteid = sprite;
	_frame = frame;
	_state = SHADOW_STATE_NORMAL;
	_type = type;
	_anim.SetAnimSprite(GET_SPRITE(_spriteid), _spriteid);
	_anim.SetAnim(0, true);
	_anim.SetPos(0,0);
}
void CThrowObject::Shadow::Active(float x, float y, int opac, float scale, int anim, int time)
{
	_x = x;
	_y = y;
	_opac = opac;
	_scale = scale;
	_state = SHADOW_STATE_START;
	_anim.SetAnim(anim, true);
	_anim.SetPos(_x, _y);
	_count_frame_hold = time;
}
void CThrowObject::Shadow::Render(float x, float y)
{
	if (_state == SHADOW_STATE_NORMAL)
	{
		return;
	}
	G()->SetScale(_scale, _scale, _x + x, _y + y);
	G()->SetOpacity(_opac);
	if (_type == SHADOW_TYPE_FRAME)
	{
		GET_SPRITE(_spriteid)->DrawFrame(G(), _frame, _x + x, _y + y);
	}
	else
	{
		_anim.SetPos(_x + x, _y + y);
		_anim.DrawAnimObject(G());
	}
	G()->SetOpacity(100);
	G()->ClearScale();
}
void CThrowObject::Shadow::Update()
{
	if (_state == SHADOW_STATE_NORMAL)
	{
		return;
	}
	if (_type == SHADOW_TYPE_ANIM)
	{
		_anim.UpdateAnimObject();
	}
	_scale += _scale_speed;
	_count_frame_hold--;
	switch (_state)
	{
	case SHADOW_STATE_NORMAL:
		break;
	case SHADOW_STATE_START:
		_opac += _opac_speed;
		if (_opac >= 100)
		{
			_opac = 100;
		}
		if (_count_frame_hold <= 0)
		{
			_state = SHADOW_STATE_END;
		}
		break;
	case SHADOW_STATE_END:
		_opac -= _opac_speed;
		if (_opac <= 0)
		{
			_state = SHADOW_STATE_NORMAL;
		}
		break;
	default:
		break;
	}
	
}
bool CThrowObject::Shadow::IsFree()
{
	if (_state == SHADOW_STATE_NORMAL)
	{
		return true;
	}
	return false;
}
void CThrowObject::Shadow::SetState(int state)
{
	_state = state;
}
