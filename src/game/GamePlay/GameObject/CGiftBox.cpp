#include "pch.h"
#include "../../GameCore/CGame.h"

CGiftBox::CGiftBox()
{
}

CGiftBox::~CGiftBox()
{
}

void CGiftBox::Init(int type, int value, int timehold, float speed,int num)
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	
	_x = 0 + game->_point_o.X;
	_y = 200 + game->_point_o.Y;
	_tarx = 0;
	_tary = 0;
	_state = GIFT_BOX_STATE_NORMAL;
	_count_frame_hold = timehold;
	_anim.SetAnimSprite(GET_SPRITE(SPRITEID_FAIRY_01), SPRITEID_FAIRY_01);
	_anim.SetAnim(0, true);
	_anim.SetPos(_x, _y);
	_speed = speed;
	_angle = CMath::RANDOM(1, 360);
	_num_gift_target = num;
	for (int i = 0; i < GIFT_BOX_NUM_PARTICAL_SHADOW; i++)
	{
		_partical_end[i].Init(SPRITEID_FAIRY_01, 6, 0.01f, 3);
	}
	_gift_touch_id = -1;
	_fly_with_sin = CMath::RANDOM(0, 1);
	_speed_angle = 0;
	game->GiftRewardInit();
	for (int i = 0; i < GIFT_BOX_NUM_TYPE; i++)
	{
		_gift[i]._type = GIFT_BOX_TYPE_NONE;
		_gift[i]._value = 0;
	}
	int indexrw = RandomRewardIndex();
	for (int i = 0; i < GIFT_BOX_NUM_TYPE; i++)
	{
		_gift[i]._type = i;
		_gift[i]._value = game->GetDesignFairyReward(indexrw,i+1);
	}
	_has_live = false;
}
void CGiftBox::Active(float tarx, float tary)
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	_tarx = tarx + game->_point_o.X;
	_tary = tary + game->_point_o.Y;
	_state = GIFT_BOX_STATE_START;
	_count_frame_hold = FPS_MAX*game->GetDesignGeneralInfo(DESIGN_GENERAL_FAIRY_TIME);
	_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
	_speed_angle = CMath::RANDOM(-3, 3)/2.0f;
	_has_is_screem = false;

}
void CGiftBox::Render(float x, float y)
{
	
	if (_state == GIFT_BOX_STATE_NORMAL || _state == GIFT_BOX_STATE_FREE)
	{
		return;
	}
	_anim.SetPos(_x + x, _y + y);
	for (int i = 0; i < GIFT_BOX_NUM_PARTICAL_SHADOW; i++)
	{
		_partical_end[i].Render(x, y);
	}
	_anim.DrawAnimObject(G());
}
void CGiftBox::Update()
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	if (_state == GIFT_BOX_STATE_NORMAL || _state == GIFT_BOX_STATE_FREE)
	{
		if (_has_live)
		{
			_count_frame_hold--;
			if (_count_frame_hold <= 0)
			{
				/*int tarx = CMath::RANDOM(5, 8)*(int)(k_SCREEN_WIDTH / 10);
				int tary = CMath::RANDOM(3, 5)*(int)(k_SCREEN_HEIGHT / 10);*/
				int tarx = game->_screen_width - 200;
				int tary = k_SCREEN_HEIGHT/3;
				Active(tarx, tary);
				_has_live = false;
			}
		}
		return;
	}
	_anim.UpdateAnimObject();
	for (int i = 0; i < GIFT_BOX_NUM_PARTICAL_SHADOW; i++)
	{
		_partical_end[i].Update();
	}
	AddShadow(_x + CMath::RANDOM(-5, 5) * 2, _y + CMath::RANDOM(-5, 5) * 2,0);
	//AddShadow(_x + CMath::RANDOM(-5, 5) * 2, _y + CMath::RANDOM(-5, 5) * 2);
	switch (_state)
	{
	case GIFT_BOX_STATE_START:
		_count_frame_hold--;
		if (CHECK_POINT_IN_CIRCLE(_x, _y, _tarx, _tary, _speed))
		{
			if (_count_frame_hold > 0)
			{
				if (_x > k_SCREEN_WIDTH/2)
				{
					_tarx = CMath::RANDOM(0, _x - k_SCREEN_WIDTH/2);
				}
				else
				{
					_tarx = CMath::RANDOM(game->_screen_width - _x, game->_screen_width);
				}
				_tary = CMath::RANDOM(1, 2)*(int)(k_SCREEN_HEIGHT / 10);
				float dis = CMath::DISTANCE(_x, _y, _tarx, _tary);
				if (dis <= 200)
				{
					_tarx = 0;
					_tary = 100;
				}
				_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
				_speed_angle = CMath::RANDOM(-3, 3) / 2.0f;
			}
		}
		else
		{
			/*_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
			float disx = _tarx - _x;
			float disy = _tary - _y;
			float speed_deltax = disx * 4 / 100.0f;
			float speed_deltay = disy / 100.0f;
			_x += _speed*CMath::COS(_angle) + speed_deltax;
			_y += _speed*CMath::SIN(_angle) + speed_deltay;*/
			_x += _speed*CMath::COS(_angle);
			_y += _speed*CMath::SIN(_angle);
			/*if (_fly_with_sin)
			{
				_x += _speed*CMath::COS(_angle);
				_y += _speed*CMath::SIN(_angle);
			}
			else
			{
				_x += _speed*CMath::COS(_angle);
				_y += _speed*CMath::SIN(_angle);
			}*/
		}
		if (_x > 0 && _y > 0)
		{
			_has_is_screem = true;
		}
		_angle -= _speed_angle;
		if (_has_is_screem)
		{
			if (_x <= 0)
			{
				_x = 0;
			}
			if (_y <= 0)
			{
				_y = 0;
			}
			if (_angle <= 0 || _y >= _tary || _y <= 100 || _x <= 0 || _x >= game->_screen_width)
			{
				if (_x > k_SCREEN_WIDTH / 2)
				{
					_tarx = CMath::RANDOM(0, _x - k_SCREEN_WIDTH / 2);
				}
				else
				{
					_tarx = CMath::RANDOM(game->_screen_width - _x, game->_screen_width);
				}
				_tary = CMath::RANDOM(1, 2)*(int)(k_SCREEN_HEIGHT / 10);
				float dis = CMath::DISTANCE(_x, _y, _tarx, _tary);

				if (dis <= 200)
				{
					_tarx = 0;
					_tary = 0;
				}
				
				_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
				_speed_angle = CMath::RANDOM(-3, 3) / 2.0f;
			}
		}
		
		//_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
		if (_count_frame_hold <= 0)
		{
			_state = GIFT_BOX_STATE_END;
			_tarx = k_SCREEN_WIDTH + 100;
			_tary = CMath::RANDOM(1, 4)*(int)(k_SCREEN_HEIGHT / 10);
			_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
			_speed *= 4;
		}
		UpdateTouch();
		break;
	case GIFT_BOX_STATE_OPEN:
		if (_anim.GetCurrentAnim() == 0)
		{
			_anim.SetAnim(1, false);
			for (int i = 0; i < _num_gift_target; i++)
			{
				int button_index = INGAME_BUTTON_SKILL1;
				if (_gift[GIFT_BOX_TYPE_AUTO_ATT]._value > 0)
				{
					button_index = INGAME_BUTTON_AUTO1;
				}
				if (_gift[GIFT_BOX_TYPE_AUTO_SKILL]._value > 0)
				{
					button_index = INGAME_BUTTON_SKILL1;
				}
				int mx = game->_ingame_button[i + button_index].TZ_GetX() + 4;
				int my = game->_ingame_button[i + button_index].TZ_GetY();
				int mw = game->_ingame_button[i + button_index].TZ_GetWidth();
				int mh = game->_ingame_button[i + button_index].TZ_GetHeight();
				int tarx = mx + mw / 2;
				int tary = my + mh - 10;
				if (_gift[GIFT_BOX_TYPE_DOUBLE_COIN]._value > 0)
				{
					tarx = k_SCREEN_WIDTH - 45 - game->_point_o.X;
					if (game->_user._has_double_coin)
					{
						tarx -= 90;
					}
					if (game->_user._iap_starter_double_coin_time > 0)
					{
						tarx -= 90;
					}
					tary = 220 + game->_point_o.Y;
				}
				if (game->_ingame_hero_button[i]._heroID >= 0)
				{
					game->GiftRewardActive(_x + 25, _y + 5, tarx, tary, 0);
				}
			}
		}
		else
		{
			if (_anim.IsCurrentAnimStop())
			{
				_anim.SetAnim(0, true);
				_state = GIFT_BOX_STATE_END;
				_tarx = game->_screen_width + 100;
				_tary = CMath::RANDOM(1, 4)*(int)(k_SCREEN_HEIGHT / 10);
				_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
				_speed *= 2;
				
			}
		}
		break;
	case GIFT_BOX_STATE_END:
		if (CHECK_POINT_IN_CIRCLE(_x,_y,_tarx,_tary,_speed))
		{
			_state = GIFT_BOX_STATE_FREE;
		}
		else
		{
			/*_angle = CMath::ANGLE(_x, _y, _tarx, _tary);
			float disx = _tarx - _x;
			float disy = _tary - _y;
			float speed_deltax = disx * 4 / 100.0f;
			float speed_deltay = disy / 100.0f;
			_x += _speed*CMath::COS(_angle) + speed_deltax;
			_y += _speed*CMath::SIN(_angle) + speed_deltay;*/
			_x += _speed*CMath::COS(_angle);
			_y += _speed*CMath::SIN(_angle);
		}
		break;
	default:
		break;
	}
	
}
bool CGiftBox::UpdateTouch()
{
	TDGame* game = (TDGame*)GAME()->_current_game;
	bool pressed = false;

	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		int x = _x - 100;
		int y = _y - 100;
		int w = 200;
		int h = 200;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_gift_touch_id == -1)
				{
					_state = GIFT_BOX_STATE_OPEN;
					_gift_touch_id = TOUCHS(i)->_id;
					//PLAY_SFX(SFX_FAIRY_TAP);
					game->TouchEffectFireAdd(TOUCHS(i)->x, TOUCHS(i)->y);
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
				
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_gift_touch_id == TOUCHS(i)->_id)
				{
					_gift_touch_id = -1;
				}
			}
			if (_gift_touch_id != -1)
			{
				pressed = true;
			}
		}
		else
		{
			if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_gift_touch_id == TOUCHS(i)->_id)
				{
					_gift_touch_id = -1;
					pressed = true;
				}
			}
		}
	}
	return pressed;
}

void CGiftBox::AddShadow(float x, float y, int type)
{
	switch (type)
	{
	case 0:
		for (int i = 0; i < GIFT_BOX_NUM_PARTICAL_SHADOW; i++)
		{
			if (_partical_end[i].IsFree())
			{
				_partical_end[i].Active(x, y, 0.7f, 100);
				break;
			}
		}
		break;
	case 1:
		for (int i = 0; i < GIFT_BOX_NUM_PARTICAL_SHADOW; i++)
		{
			if (_partical_gift[i].IsFree())
			{
				_partical_gift[i].Active(x, y, 0.7f, 100);
				break;
			}
		}
		break;
	default:
		break;
	}
	
}
void CGiftBox::Reset()
{

}

int CGiftBox::RandomRewardIndex()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int rand = CMath::RANDOM(1, 100);
	int total = game->_game_design.General.SheetFairy_design.int32Value._totalData;
	int param_percent = CGameDesign::FileGeneral::CSheetFairy_design::Rate;
	int percent = 0;
	int index = -1;
	for (int i = 0; i < total; i++)
	{
		int per_up = game->GetDesignFairyReward(i, param_percent);
		if (rand > percent && rand <= percent + per_up)
		{
			index = i;
			break;
		}
		percent += per_up;
	}
	return index;
}