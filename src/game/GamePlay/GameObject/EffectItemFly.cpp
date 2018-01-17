#include "pch.h"
#include "../../GameCore/CGame.h"

CItemFly::CItemFly()
{

}

CItemFly::~CItemFly()
{

}


void CItemFly::Init(int sprite, int frame, int valmin, float speed)
{
	_spriteid = sprite;
	_frameid = frame;
	_value_min = valmin;
	_speed = speed;
}
void CItemFly::Active(int type, float x, float y, float tarx, float tary, int value)
{
	_type = type;
	_x = x;
	_y = y;
	_targetx = tarx;
	_targety = tary;
	_value = value;
	_count_frame_hold = 0;
	_alphax = CMath::RANDOM(80, 100);
	_alphay = CMath::RANDOM(320, 345);
	_speed = CMath::RANDOM(10, 15);
	_delta = 0;
	_state = ITEMS_DROP;
}
void CItemFly::Render()
{
	if (_state >= ITEMS_DROP)
	{
		GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x, _y);
	}
}
void CItemFly::Update()
{
	switch (_state)
	{
	case ITEMS_DROP:
	{

					   if (_alphax < 85)
					   {
						  _alphax += 1;
					   }
					   else if (_alphax > 100)
					   {
						   _alphax -= 1;
					   }
					   _alphay += 2;
					   if (_alphay >= 360)
					   {
						   _alphay = 0;
					   }
					   if (_alphay == 0)
					   {
						   _delta += 2;
					   }

					   _y += _speed*CMath::SIN(_alphay + _delta / 4);
					   if (_y >= _targety - _speed)
					   {
						   _count_frame_hold++;
						   _y = _targety;
						   if (_count_frame_hold >= 60)
						   {
							   _state = ITEMS_FLY;
							   if (_type == ITEMS_TYPE_COIN)
							   {
								   int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(0, 0);
								   int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(0, 0);
								   _targetx = x;
								   _targety = y;
							   }
							   if (_type == ITEMS_TYPE_GEM)
							   {
								   int x = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterX(4, 0);
								   int y = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleCenterY(4, 0);
								   _targetx = x;
								   _targety = y;
							   }
						   }
					   }
					   else
					   {
						   _x += _speed*CMath::COS(_alphax);
					   }
	}
		break;
	case ITEMS_FLY:
	{
					  float angle = CMath::ANGLE(_x, _y, _targetx, _targety);
					  _x += 20 * CMath::COS(angle);
					  _y += 20 * CMath::SIN(angle);
					  if (CHECK_POINT_IN_CIRCLE(_x, _y, _targetx, _targety, 20))
					  {
						  if (_type == ITEMS_TYPE_COIN)
						  {
							  //_user.AddCoin(_arr_item[i]._value);
							  //_effect_scale_icon_coin_start = true;
						  }

						  if (_type == ITEMS_TYPE_GEM)
						  {
							 // _effect_scale_icon_gem_start = true;
						  }
						 _state = ITEMS_EMPTY;
					  }
	}
		break;
	default:
		break;
	}
}
void CItemFly::ForceEnd()
{

}