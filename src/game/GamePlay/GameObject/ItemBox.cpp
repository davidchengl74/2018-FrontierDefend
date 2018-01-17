#include "pch.h"
#include "../../GameCore/CGame.h"
ItemBox::ItemBox()
{
}

ItemBox::~ItemBox()
{
}
void ItemBox::Init(int sprite, int frame, int type, int id, int group, int rate, int value, float x, float y, float targetx, float targety)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_sprite_id = sprite;
	game->LoadSpriteOptimize(_sprite_id,true,false);
	_frame_id = frame;
	_type = type;
	_value = value;
	game->ConvertMoneyInbalace(_value, _value_text);
	_scale = 0;
	_opac = 0;
	_choosen = false;
	_touch_id = -1;
	_scale_max = false;
	_state = ITEM_STATE_INIT;
	_anim.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_CHESTS), SPRITEID_HUD_CHESTS);
	_anim.SetAnim(ITEM_STATE_NORMAL, true);
	_anim_light.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_CHESTS), SPRITEID_HUD_CHESTS);
	_anim_light.SetAnim(3, true);
	_anim_light.SetPos(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2 - 50);
	SetPos(x, y);
	SetTarget(targetx, targety);
	_scale_center_x = x;
	_scale_center_y = y;
	_dis_with_screen_center = CMath::DISTANCE(x,y,k_SCREEN_WIDTH/2,k_SCREEN_HEIGHT/2-50);
	_count_frame_openning = 0;
	_reward_scroll_x = k_SCREEN_WIDTH / 2;
	_reward_scroll_y = k_SCREEN_HEIGHT / 2 - 50;
	_reward_scale_x = k_SCREEN_WIDTH / 2;
	_reward_scale_y = k_SCREEN_HEIGHT / 2 - 50;
	_reward_scale = 0;
	_glow_opac = 0;
	_glow1_rotate = 0;
	_glow2_rotate = 0;
	_reward_scale_max = false;
	_reward_scale_min = false;
	_glow_hero_scale = 0;
	_glow_hero_scale_y = 0;
	_is_scrolling = false;
	_group = group;
	_rate = rate;
	_id_item = id;
}
void ItemBox::Render(int opac)
{
    
	TDGame *game = (TDGame*)GAME()->_current_game;
    float subscale = 1.0f+(game->_frame_double_box/100.0f)*0.5f;
    if(!_choosen)
    {
        subscale = 1.0f;
    }
	float opacmain = opac / 100.0f;
	G()->SetOpacity(_opac*opacmain);
	G()->SetScale(_scale, _scale, _x, _y);
	switch (_state)
	{
	case ITEM_STATE_INIT:
		_anim.DrawAnimObject(G());
		break;
	case ITEM_STATE_NORMAL:
		_anim.DrawAnimObject(G());
		/*GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _x, _y);
		GET_SPRITE(SPRITEID_FONT_IAP)->DrawAnsiTextFormat(G(), _x, _y - 110, _HCENTER | _VCENTER, "%d", _value);*/
		break;
	case ITEM_STATE_OPENNING:
		_anim.DrawAnimObject(G()); 
		break;
	case ITEM_STATE_OPENNED:
		_anim.DrawAnimObject(G());
		_anim_light.DrawAnimObject(G());
		G()->ClearScale();
		G()->SetScale(_reward_scale, _reward_scale, _reward_scale_x, _reward_scale_y);
		GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _reward_scroll_x, _reward_scroll_y);
		G()->ClearScale();
		
		break;
	
	case ITEM_STATE_FLY_TO_END:
		_anim.DrawAnimObject(G());
		_anim_light.DrawAnimObject(G());
		G()->SetOpacity(opac);
		G()->SetScale(_reward_scale, _reward_scale, _reward_scale_x, _reward_scale_y);
		GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _reward_scroll_x, _reward_scroll_y);
		G()->ClearScale();		
		break;
	case ITEM_STATE_END:
		G()->SetOpacity(opac);
		G()->SetScale(_reward_scale, _reward_scale, _reward_scale_x, _reward_scale_y);
		GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _reward_scroll_x, _reward_scroll_y);
		G()->ClearScale();
		G()->SetScale(_font_reward_scale*subscale, _font_reward_scale*subscale, _scale_center_x, _scale_center_y);
		GET_SPRITE(SPRITEID_FONT_IAP)->DrawAnsiTextFormat(G(), _scale_center_x, _scale_center_y - 110, _HCENTER | _VCENTER, "%s", _value_text);
		//GET_SPRITE(SPRITEID_FONT_IAP)->DrawAnsiTextFormat(G(), _scale_center_x, _scale_center_y - 110, _HCENTER | _VCENTER, "%d", _value);
		G()->ClearScale();
		break;
	case ITEM_STATE_FORCE_OPEN:
		_anim.DrawAnimObject(G());
		G()->SetOpacity(opac);
		G()->SetScale(_reward_scale, _reward_scale, _scale_center_x, _scale_center_y);
			GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _scale_center_x, _scale_center_y);
        G()->SetScale(_reward_scale*subscale, _reward_scale*subscale, _scale_center_x, _scale_center_y);
			GET_SPRITE(SPRITEID_FONT_IAP)->DrawAnsiTextFormat(G(), _scale_center_x, _scale_center_y - 110, _HCENTER | _VCENTER, "%s", _value_text);
			//GET_SPRITE(SPRITEID_FONT_IAP)->DrawAnsiTextFormat(G(), _scale_center_x, _scale_center_y - 110, _HCENTER | _VCENTER, "%d", _value);
		G()->ClearScale();
		//G()->SetScale(_font_reward_scale, _font_reward_scale, _scale_center_x, _scale_center_y);
		
		//G()->ClearScale();
		break;
	case ITEM_STATE_FORCE_CLOSE:
		G()->SetOpacity(opac);
		_anim.DrawAnimObject(G());
		G()->SetOpacity(_opac*opacmain);
		G()->ClearScale();
		G()->SetScale(_reward_scale, _reward_scale, _scale_center_x, _scale_center_y);
		GET_SPRITE(_sprite_id)->DrawFrame(G(), _frame_id, _scale_center_x, _scale_center_y);
		G()->ClearScale();
		break;
	default:
		break;
	}
	G()->ClearScale();
	G()->SetOpacity(opac);
	if (_state > ITEM_STATE_OPENNED && _state < ITEM_STATE_FORCE_OPEN)
	{
		G()->SetOpacity(_glow_opac*opacmain);
		CMatrix4x4Util _glow_matrix;
		_glow_matrix.Scale(_reward_scale + _glow_hero_scale, _reward_scale + _glow_hero_scale, _reward_scale_x, _reward_scale_y + _glow_hero_scale_y);
		_glow_matrix.Rotate(-_glow2_rotate, _reward_scroll_x, _reward_scroll_y + _glow_hero_scale_y);
		G()->SetTransform(_glow_matrix.toPineTranform());
		GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 15, _reward_scroll_x, _reward_scroll_y + _glow_hero_scale_y);
		_glow_matrix.RevertTransform();
		_glow_matrix.Rotate(_glow1_rotate, _reward_scroll_x, _reward_scroll_y + _glow_hero_scale_y);
		G()->SetTransform(_glow_matrix.toPineTranform());
		GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 14, _reward_scroll_x, _reward_scroll_y + _glow_hero_scale_y);
		G()->ClearTransform();
		G()->SetOpacity(opac);
	}
	
}
void ItemBox::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_anim.UpdateAnimObject();
	_anim_light.UpdateAnimObject();
	if (_choosen)
	{
        _target_x = _x;
        _target_y = _y;
		_scale += 0.025;
		if (_scale >= 1.0f)
		{
			_scale = 1.0f;
		}
		_glow1_rotate += 2;
		_glow2_rotate += 3;
		if (_glow1_rotate >= 360)
		{
			_glow1_rotate -= 360;
		}
		if (_glow2_rotate >= 360)
		{
			_glow2_rotate -= 360;
		}
		if (_count_frame_openning >= 20)
		{
			_glow_opac += 5;
		}
		
		if (_glow_opac >= 100)
		{
			_glow_opac = 100;
		}
	}
	else
	{
		if (!_scale_max)
		{
			_scale += 0.07;
			if (_scale >= 1.2f)
			{
				_scale_max = true;
			}
		}
		else 
		{
			_scale -= 0.04;
			if (_scale <= 1.0f)
			{
				_scale = 1.0f;
				if (_state == ITEM_STATE_INIT)
				{
					_state = ITEM_STATE_NORMAL;
				}
			}
		}
	}
	if (_state < ITEM_STATE_FLY_TO_END)
	{
		_opac += 10;
		if (_opac >= 100)
		{
			_opac = 100;
		}
		if (_choosen)
		{
			game->_openning_opac += 5;
			if (game->_openning_opac >= 50)
			{
				game->_openning_opac = 50;
			}
		}
	}
	else
	{
		if (_state < ITEM_STATE_FORCE_CLOSE)
		{
			_opac -= 5;
			if (_opac <= 0)
			{
				_opac = 0;
			}
		}
		
		if (_state == ITEM_STATE_FLY_TO_END)
		{
			game->_openning_opac -= 5;
			if (game->_openning_opac <= 0)
			{
				game->_openning_opac = 0;
			}
		}
	}
	float item_scroll_speed = _dis_with_screen_center / 16;
	if (!CHECK_POINT_IN_CIRCLE(_x, _y, _target_x, _target_y, item_scroll_speed))
	{
		//printf("\n _x = %f -- _y = %f", _x, _y);
		_is_scrolling = true;
		float angle = CMath::ANGLE(_x, _y, _target_x, _target_y);
		_x += item_scroll_speed * CMath::COS(angle);
		_y += item_scroll_speed * CMath::SIN(angle);
		SetPos(_x, _y);
	}
	else
	{
		_is_scrolling = false;
		_x = _target_x;
		_y = _target_y;
		/*_scale_center_x = _target_x;
		_scale_center_y = _target_y;*/
		if (_choosen)
		{
			if (_state == ITEM_STATE_NORMAL)
			{
					SetState(ITEM_STATE_OPENNING);
					
			}
		}
		SetPos(_x, _y);
	}
	
	switch (_state)
	{
	case ITEM_STATE_NORMAL:
		break;
	case ITEM_STATE_OPENNING:
		if (_anim._current_aframes == 8)
		{
			//game->_effect_open_box_item.Init(SPRITEID_HUD_CHEST, 0, 13, 16, TYPE_RENDER_ANIM);
			//game->_effect_open_box_item.Fire(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2 - 50, 200, 10, 40,20,100);
			GAME()->PlaySFX(SFX_TREASURE_OPEN);
			_state = ITEM_STATE_OPENNED;
			_font_reward_scale = 1.0f;
            
            
            _reward_scroll_x = _x;
            _reward_scroll_y = _y - 50;
            _reward_scale_x = _x;
            _reward_scale_y = _y - 50;
		}
		/*if (_anim.IsCurrentAnimStop())
		{
			_state = ITEM_STATE_OPENNED;
			_font_reward_scale = 1.0f;
		}*/
		break;
	case ITEM_STATE_OPENNED:
		_count_frame_openning++;
		//if (_type != ITEM_TYPE_HERO)
		{
			_reward_scale += 0.05;
		}
		if (_count_frame_openning <= 20)
		{
			_reward_scroll_y -= 8;
		}
		if (_reward_scale >= 0.7f)
		{
			_reward_scale = 0.7f;
		}
		if (_count_frame_openning >= 60)
		{
			
			_state = ITEM_STATE_FLY_TO_END;
			_reward_scale_x = _scale_center_x;
			_reward_scale_y = _scale_center_y;
			_glow_hero_scale = 0;
			_glow_hero_scale_y = 0;
			_reward_scroll_speed = CMath::DISTANCE(_reward_scroll_x, _reward_scroll_y, _scale_center_x, _scale_center_y) / 10;
		}
		break;
	case ITEM_STATE_FLY_TO_END:
	{
		if (!CHECK_POINT_IN_CIRCLE(_reward_scroll_x, _reward_scroll_y, _scale_center_x, _scale_center_y, _reward_scroll_speed))
		{
			float angle = CMath::ANGLE(_reward_scroll_x, _reward_scroll_y, _scale_center_x, _scale_center_y);
			_reward_scroll_x += _reward_scroll_speed*CMath::COS(angle);
			_reward_scroll_y += _reward_scroll_speed*CMath::SIN(angle);
		}
		else
		{
			
			_reward_scroll_x = _scale_center_x;
			_reward_scroll_y = _scale_center_y;
			_state = ITEM_STATE_END;
		}
		_reward_scale -= 0.03;
		if (_reward_scale <= 0.6f)
		{
			_reward_scale = 0.6f;
		}
		
		_font_reward_scale -= 0.035;
		if (_font_reward_scale <= 1.0f)
		{
			_font_reward_scale = 1.0f;
		}
	}
		break;
	case ITEM_STATE_END:
		if (_reward_scale <= 0.6f)
		{
			_reward_scale = 0.6f;
		}
		_font_reward_scale = 1.0f;
		break;
	case ITEM_STATE_FORCE_OPEN:

		break;
	case ITEM_STATE_FORCE_CLOSE:
		_opac -= 5;
		//_scale += 0.05;
		/*if (_scale >= 0.6)
		{
			_scale = 0.6;
		}*/
		if (_opac <= 0)
		{
			_opac = 100;
			_count_frame_openning = 0;
			_reward_scale = 0;
			_glow_opac = 0;
			_glow1_rotate = 0;
			_glow2_rotate = 0;
			_reward_scale_max = false;
			_reward_scale_min = false;
			_glow_hero_scale = 0;
			_glow_hero_scale_y = 0;
			_reward_scroll_x = k_SCREEN_WIDTH / 2;
			_reward_scroll_y = k_SCREEN_HEIGHT / 2 - 50;
			_reward_scale_x = k_SCREEN_WIDTH / 2;
			_reward_scale_y = k_SCREEN_HEIGHT / 2 - 50;
			_state = ITEM_STATE_NORMAL;
		}
		_reward_scale -= 0.05;
		if (_reward_scale <= 0)
		{
			_reward_scale = 0;
		}
		_glow_opac -= 10;
		if (_glow_opac <= 0)
		{
			_glow_opac = 0;
		}
		_font_reward_scale = 1.0f;
		break;
	default:
		break;
	}
	//printf("\n _anim.GetCurrentAnim() = %d -- state = %d", _anim.GetCurrentAnim(),_state);
	if (_anim.GetCurrentAnim() != _state && _state <= ITEM_STATE_OPENNED)
	{
		if (_state == ITEM_STATE_OPENNING)
		{
			_anim.SetAnim(_state, false);
		}
		else
		{
			if (_state == ITEM_STATE_INIT)
			{
				_anim.SetAnim(ITEM_STATE_NORMAL, true);
			}
			else
			{
				_anim.SetAnim(_state, true);
			}
			
		}
	}
	if (_state == ITEM_STATE_FORCE_CLOSE)
	{
		if (_anim.GetCurrentAnim() != ITEM_STATE_NORMAL)
		{
			_anim.SetAnim(ITEM_STATE_NORMAL, true);
		}
	}
}
void ItemBox::SetPos(float x, float y)
{
	_x = x;
	_y = y;
	_anim.SetPos(_x, _y + 50);
	_anim_light.SetPos(_x, _y + 50);
}
void ItemBox::SetTarget(float x, float y)
{
	_target_x = x;
	_target_y = y;
}

void ItemBox::SetScaleCenter(float x, float y)
{
	_scale_center_x = x;
	_scale_center_y = y;
}

float ItemBox::GetPosX()
{
	return _x;
}
float ItemBox::GetPosY()
{
	return _y;
}
float ItemBox::GetTargetX()
{
	return _target_x;
}
float ItemBox::GetTargetY()
{
	return _target_y;
}
int ItemBox::GetType()
{
	return _type;
}
int ItemBox::GetValue()
{
	return _value;
}
void ItemBox::SetType(int type)
{
	_type = type;
}
void ItemBox::SetValue(int value)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	_value = value;
	game->ConvertMoneyInbalace(_value, _value_text);
}

void ItemBox::SetState(int state)
{
	_state = state;
	if (_state == ITEM_STATE_FORCE_CLOSE)
	{
		_opac = 100;
		_scale = 0;
	}
}

int ItemBox::GetState()
{
	return _state;
}

void ItemBox::ForceOpenBox()
{
	if (!_reward_scale_max)
	{
		_reward_scale += 0.05;
		if (_reward_scale >= 0.7f)
		{
			_reward_scale_max = true;
		}
	}
	else
	{
		if (!_reward_scale_min)
		{
			_reward_scale -= 0.05;
			if (_reward_scale <= 0.5f)
			{
				_reward_scale_min = true;
			}
		}
		else
		{
			_reward_scale += 0.05;
			if (_reward_scale >= 0.6f)
			{
				_reward_scale = 0.6f;
			}
		}
	}
	_opac -= 5;
	if (_opac <= 0)
	{
		_opac = 0;
	}
}
