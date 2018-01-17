#include "pch.h"
#include "CDialog.h"
#include "../../GameCore/CGame.h"
CDialog::CDialog()
{
	_state = STATE_NOTUSE;
	float _x = 0;
	float _y = 0;
}
void CDialog::Init(int context, int type, int typetransaction, const char* title, const char* body, float x, float y, bool swap)
{
	_main_opac = 0;
	_context = context;
	_type = type;
	_typetransaction = typetransaction;
	_x = x;
	_y = y;
	sprintf(_title, "%s", title);
	sprintf(_body, "%s", body);
	_touch_close_id = -1;
	_touch_out_touchid = -1;
	if (GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01) == NULL)
	{
		GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_LUCKY_WHEEL_01,true,!CGame::_this->_isNeedOptimize);
	}
	if (type == DIALOGTYPE_YESNO)
	{
        
		
		if (_context == DIALOG_CONTEXT_PRESTIGE
			|| _context == DIALOG_CONTEXT_VIEW_PRESTIGE)
		{
			for (int i = 0; i < 2; i++)
			{
				_yesno[i].Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
				_yesno[i].SetAnim(SPRITEID_HUD_DATA_MENU_PRESTIGE, i * 4);
				_yesno[i].SetPos(0, 0);
			}
		}
		else if (_context == DIALOG_CONTEXT_REVIVE_BY_ADS || _context == DIALOG_CONTEXT_REVIVE_BY_GEM )
		{
			for (int i = 0; i < 2; i++)
			{
				_yesno[i].Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
				_yesno[i].SetAnim(SPRITEID_HUD_DATA_MENU_PRESTIGE, i * 12);
				_yesno[i].SetPos(0, 0);
			}
		}
		else if (_context == DIALOG_CONTEXT_RELIC_SPECIAL || _context == DIALOG_CONTEXT_PURCHASE_MORE_WHEEL)
		{
			for (int i = 0; i < 2; i++)
			{
				_yesno[i].Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
				_yesno[i].SetAnim(SPRITEID_HUD_DATA_MENU_PRESTIGE, i * 16);
				_yesno[i].SetPos(0, 0);
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				_yesno[i].Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
				_yesno[i].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 9 + i * 4);
				_yesno[i].SetPos(0, 0);
			}
			if (swap)
			{
				float dx = CMath::ABSOLUTE_VALUE((_yesno[0].TZ_GetX() - _yesno[1].TZ_GetX()));
				_yesno[0].SetPos(dx, 0);
				_yesno[1].SetPos(-dx, 0);
			}
		}
	}
	else
	{
		if (_context == DIALOG_CONTEXT_100_BATTLE)
		{
			_ok.Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
			_ok.SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 17);
			_ok.SetPos(0, 0);
		}
		else if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_SPEC)
		{
			_ok.Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
			_ok.SetAnim(SPRITEID_HUD_DAILY_REWARD, 4);
			_ok.SetPos(0, 0);
		}
		else if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_OFF)
		{
			_ok.Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
			_ok.SetAnim(SPRITEID_HUD_DAILY_REWARD, 4);
			_ok.SetPos(0, 0);
		}
		else if (_context == DIALOG_CONTEXT_PRESTIGE
			|| _context == DIALOG_CONTEXT_VIEW_PRESTIGE)
		{
			_ok.Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
			_ok.SetAnim(SPRITEID_HUD_DATA_MENU_PRESTIGE, 4);
			_ok.SetPos(0, 0);
		}
		else
		{
			_ok.Init(BUTTON_STATE_NORMAL, x, y, A_HVCENTER);
			_ok.SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 0);
			_ok.SetPos(0, 0);
		}
		
	}
	//GAME()->LoadSpriteCurrentVer(SPRITEID_HUD_LUCKY_WHEEL_01);
	_state = STATE_OPEN;
	if (_typetransaction == ZOOM_IN_OUT_TRANSACTION)
	{
		_scale= 0;
		_cenX = Button::GetFrameX(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) + Button::GetFrameWidth(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) / 2;
		_cenY = Button::GetFrameY(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) + Button::GetFrameHeight(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) / 2;
	}
	else
	{
		_opa = 0;
	}
	
}
int CDialog::GetState()
{
	return _state;
}
void CDialog::Update()
{
	switch (_typetransaction)
	{
	case ZOOM_IN_OUT_TRANSACTION:
		UpdateZoomTransaction();
		break;
	case OPACITY_TRANSACTION:
		UpdateOpacityTransaction();
		break;
	}
}
void CDialog::UpdateZoomTransaction()
{
	switch (_state)
	{
	case STATE_OPEN:
		_scale += 0.1f;
		if (_scale >= 1.0f)
		{
			_scale = 1.0f;
			_state = STATE_NORMAL;
		}
		break;
	case STATE_NORMAL:
		switch (_type)
		{
		case DIALOGTYPE_OK:
			if (_context == DIALOG_CONTEXT_PRESTIGE
				|| _context == DIALOG_CONTEXT_VIEW_PRESTIGE)
			{
				if (!UpdateTouchOK())
				{
					UpdateTouchOut();
				}
			}
			else
			{
				UpdateTouchOK();
			}
			break;
		case DIALOGTYPE_YESNO:
			UpdateTouchYesNo();
			break;
		}

		break;
	case STATE_CLOSE:
		_scale -= 0.1f;
		if (_scale <= 0.0f)
		{
			_scale = 0.0f;
			_state = STATE_NOTUSE;
		}
		break;
	}
}
void CDialog::UpdateOpacityTransaction()
{
	switch (_state)
	{
	case STATE_OPEN:
		_opa += 5.0f;
		if (_opa >= 100.0f)
		{
			_opa = 100.0f;
			_state = STATE_NORMAL;
		}
		break;
	case STATE_NORMAL:
		switch (_type)
		{
		case DIALOGTYPE_OK:
			if (_context == DIALOG_CONTEXT_PRESTIGE
				|| _context == DIALOG_CONTEXT_VIEW_PRESTIGE)
			{
				if (!UpdateTouchOK())
				{
					UpdateTouchOut();
				}
			}
			else
			{
				UpdateTouchOK();
			}
			
			break;
		case DIALOGTYPE_YESNO:
			UpdateTouchYesNo();
			break;
		}

		break;
	case STATE_CLOSE:
		_opa -= 5.0f;
		if (_opa <= 0.0f)
		{
			_opa = 0.0f;
			_state = STATE_NOTUSE;
		}
		break;
	}
}
void CDialog::Render(float x,float y)
{
	TDGame*game = (TDGame*)(GAME()->_current_game);
	if (_typetransaction == ZOOM_IN_OUT_TRANSACTION)
	{
		if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_SPEC || _context == DIALOG_CONTEXT_IAP_DISCOUNT_OFF
			|| _context == DIALOG_CONTEXT_REWARD_EARNING_OFF || _context == DIALOG_CONTEXT_REVIVE_BY_ADS
			|| _context == DIALOG_CONTEXT_REVIVE_BY_GEM)
		{
			G()->SetScale(_scale, _scale, _x + x, _y + y);
		}
		else
		{
			G()->SetScale(_scale, _scale, _cenX + x, _cenY + y);
		}
		
	}
	else
	{
		G()->SetOpacity(_opa);
	}
	if (_context == DIALOG_CONTEXT_100_BATTLE)
	{
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 34, _x + x, _y + y);
	}
	else if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_SPEC)
	{
		G()->SetScale(_scale*5.5f, _scale*5.5f, _x + x, _y + y);
		G()->SetRotate(GAME()->_frame_counter, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();

		G()->SetRotate(-(GAME()->_frame_counter*0.6f), _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y );
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 33, _x + x, _y + y);
		float posx = 0;
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(33, 1) + 55;
		int line = GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(7);
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(), posx + x, posy + y, k_SCREEN_WIDTH / 2 - 60, _HCENTER, "Don't miss this chance to have these awesome items");
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(line);
		
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 29, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 32, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 34, _x + x, _y + y);
		G()->ClearScale();
		int sec = (game->_iap_dis_cur_timer / 60) % 60 ;
		int min = ((game->_iap_dis_cur_timer / 60) / 60) % 60;
		int hour = ((game->_iap_dis_cur_timer / 60) / 60) / 60;
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(34, 0);
		int spacing = GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = 3;
		G()->SetScale(_scale*1.5f, _scale*1.5f, _x + x, _y + y + posy);
		GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), _x + x, _y + y + posy, _HCENTER | _VCENTER, "%02d:%02d:%02d", hour, min, sec);
		G()->ClearScale();
		
		GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = spacing;
		G()->SetScale(_scale, _scale, _x + x, _y + y + posy);
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(32,4);
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(32, 4);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 10, _HCENTER | _VCENTER, "%d", game->_iap_dis_autoatt);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 44, _HCENTER | _VCENTER, "Auto Attack");
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(32, 5);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 10, _HCENTER | _VCENTER, "%d", game->_iap_dis_autoskill);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 44, _HCENTER | _VCENTER, "Auto Skill");
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(32, 6);
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(32, 6);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(),posx + x, posy + y - 10, _HCENTER | _VCENTER, "%s", game->_iap_dis_coin_text);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 44, _HCENTER | _VCENTER, "Coins");
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(32, 7);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y - 10, _HCENTER | _VCENTER, "%d", game->_iap_dis_gem);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y- 44, _HCENTER|_VCENTER, "Gems");
		
	}
	else if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_OFF)
	{
		G()->SetScale(_scale*5.5f, _scale*5.5f, _x + x, _y + y);
		G()->SetRotate(GAME()->_frame_counter, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();

		G()->SetRotate(-(GAME()->_frame_counter * 0.6f), _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 33, _x + x, _y + y);
		float posx = 0;
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(33, 1) + 75;
		int line = GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(7);
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(), posx + x, posy + y,k_SCREEN_WIDTH/2 - 60, _HCENTER, "Don't miss your chance to have this limited discount!");
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(line);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 29, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 31, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 34, _x + x, _y + y);

		
		int sec = (game->_iap_dis_100_timer / 60) % 60 ;
		int min = ((game->_iap_dis_100_timer / 60) / 60) % 60;
		int hour = ((game->_iap_dis_100_timer / 60) / 60) / 60;

		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(34, 0);
		int spacing = GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_WAVE)->_char_spacing = 3;
		G()->ClearScale();
		G()->SetScale(_scale*1.5f, _scale*1.5f, _x + x, _y + y + posy);
		GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), _x + x, _y + y + posy, _HCENTER | _VCENTER, "%02d:%02d:%02d", hour, min, sec);
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(31, 2);
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(31, 2);
		if (game->_user._user_iap_level == CUser::enumiAPLevel::iAP_LEVEL_FREE)
		{
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y + 5, _HCENTER, "Worth 1.99$");
		}
		else if (game->_user._user_iap_level == CUser::enumiAPLevel::iAP_LEVEL_PREMIUM)
		{
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y + 5, _HCENTER, "Worth 9.99$");
		}
		else if (game->_user._user_iap_level == CUser::enumiAPLevel::iAP_LEVEL_ROYAL)
		{
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y + 5, _HCENTER, "Worth 19.99$");
		}
		GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), posx + x, posy + y + 260, _HCENTER | _VCENTER, "%d Gems", game->_iap_dis_gem);
	}
	else if (_context == DIALOG_CONTEXT_WATCH_ADS)
	{
		
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 8, _x + x, _y + y);
		float yy = Button::GetFrameY(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) + Button::GetFrameHeight(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) / 2 - 60;
		float xx = 0;
		int line_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing;
		int char_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 10;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
		yy = -120;
		if (_context >= DIALOG_CONTEXT_INVITATION_GIFT_1 && _context <= DIALOG_CONTEXT_INVITATION_GIFT_3)
		{
			yy = -90;
		}
		if (strcmp(_title, "NULL") != 0)
		{
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x, _y + y + yy, 400, _HCENTER | _VCENTER, "YOU HAVE RECEIVED");
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 1;
		}
		yy = -5;

		if (strstr(_title, "Auto Attack") != NULL)
		{
			GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 43, _x + x , _y + y + yy);
			xx = 15;
			yy = 30;
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy, 420, _LEFT | _VCENTER, _body);
		}
		else if (strstr(_title, "Auto Skill") != NULL)
		{
			GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 44, _x + x, _y + y + yy);
			xx = 15;
			yy = 30;
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy, 420, _LEFT | _VCENTER, _body);
		}
		else if (strstr(_title, "Double Coin") != NULL)
		{
			G()->SetScale(_scale*1.3f, _scale*1.3f, _x + x, _y + y + yy);
			GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 149, _x + x, _y + y + yy);
			G()->ClearScale();
			G()->SetScale(_scale, _scale, _cenX + x, _cenY + y);
			xx = 0;
			yy = 30;
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy, 420, _HCENTER | _VCENTER, _body);
		}
		else
		{
			xx = 0;
			yy = -10;
			switch (game->_free_gift_type)
			{
			case TDGame::enumFreeGiftType::FREE_GIFT_TYPE_COIN1:
				G()->SetScale(_scale*0.7f, _scale*0.7f, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 28, _x + x + xx, _y + y + yy + 160);
				G()->ClearScale();
				G()->SetScale(_scale, _scale, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy - 50, 420, _HCENTER | _VCENTER, "%s", _body);
				break;
			case TDGame::enumFreeGiftType::FREE_GIFT_TYPE_COIN2:
				G()->SetScale(_scale*0.7f, _scale*0.7f, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 29, _x + x + xx, _y + y + yy + 160);
				G()->ClearScale();
				G()->SetScale(_scale, _scale, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy - 45, 420, _HCENTER | _VCENTER, "%s", _body);
				
				break;
			case TDGame::enumFreeGiftType::FREE_GIFT_TYPE_COIN3:
				G()->SetScale(_scale*0.7f, _scale*0.7f, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 30, _x + x + xx, _y + y + yy + 160);
				G()->ClearScale();
				G()->SetScale(_scale, _scale, _cenX + x, _cenY + y);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy - 55, 420, _HCENTER | _VCENTER, "%s", _body);
				
				break;
			case TDGame::enumFreeGiftType::FREE_GIFT_TYPE_GEM:
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy, 420, _HCENTER | _VCENTER, "%s :",_body);
				break;
			default:
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + xx, _y + y + yy, 420, _HCENTER | _VCENTER, _body);
				break;
			}
			
		}
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = line_space;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = char_space;
	}
	else if (_context == DIALOG_CONTEXT_REWARD_EARNING_OFF)
	{
		y -= 40;
		G()->SetScale(_scale*5.0f, _scale*5.0f, _x + x, _y + y);
		G()->SetRotate(GAME()->_frame_counter, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 22, _x + x, _y + y);
		G()->ClearRotate();
		G()->SetScale(_scale*1.3f, _scale*1.3f, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 8, _x + x, _y + y);
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 17, _x + x, _y + y - 50);
		GET_SPRITE(SPRITEID_HUD_CHESTS)->DrawFrame(G(), 29, _x + x, _y + y - 30);

		int line_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing;
		int char_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 10;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x , _y + y - 145, 400, _HCENTER | _VCENTER, _title);

		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x + 20, _y + y, 420, _LEFT | _VCENTER,"+%s", game->_reward_earning_off_text);

		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x , _y + y + 65, 450, _HCENTER | _VCENTER, _body);
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = line_space;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = char_space;
		y += 40;
	}
	else if (_context == DIALOG_CONTEXT_PRESTIGE)
	{
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 0, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 8, _x + x - 50, _y + y - 16);
		int mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(8, 0) - 50;
		int my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(8, 0) - 16;
		GET_SPRITE(SPRITEID_FONT_LV_GOD_BLESSED_I6)->DrawAnsiTextFormat(G(), _x + x + mx + 20, _y + y + my + 28, _HCENTER | _VCENTER, ":%d", game->_reset_level_skip_next);
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 21, _x + x + mx, _y + y + my + 60);

		int char_space = GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing = 2;
		mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(0, 4);
		my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(0, 4);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->DrawAnsiTextFormat(G(), _x + x + mx , _y + y + my , _LEFT , "%s ;", game->_reset_gem_reward_text);

		mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(0, 5);
		my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(0, 5);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->DrawAnsiTextFormat(G(), _x + x + mx , _y + y + my , _LEFT, "%s :", game->_reset_coin_reward_text);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing = char_space;
		//GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x, _y + y, 420, _HCENTER | _VCENTER, game->_reset_des);
	}
	else if (_context == DIALOG_CONTEXT_VIEW_PRESTIGE)
	{
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 0, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 8, _x + x - 50, _y + y - 16);
		int mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(8, 0) - 50;
		int my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(8, 0) - 16;
		GET_SPRITE(SPRITEID_FONT_LV_GOD_BLESSED_I6)->DrawAnsiTextFormat(G(), _x + x + mx + 20, _y + y + my + 28, _HCENTER | _VCENTER, ":%d", game->_reset_level_skip_next);
		GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 21, _x + x + mx, _y + y + my + 60);

		int char_space = GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing = 2;
		mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(0, 4);
		my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(0, 4);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->DrawAnsiTextFormat(G(), _x + x + mx, _y + y + my, _LEFT, "%s ;", game->_reset_gem_reward_text);

		mx = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterX(0, 5);
		my = GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->GetFModuleCenterY(0, 5);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->DrawAnsiTextFormat(G(), _x + x + mx, _y + y + my, _LEFT, "%s :", game->_reset_coin_reward_text);
		GET_SPRITE(SPRITEID_FONT_PRESTIGE_NUMBER_I6)->_char_spacing = char_space;
		
	}
	else if (_context == DIALOG_CONTEXT_REVIVE_BY_ADS|| _context == DIALOG_CONTEXT_REVIVE_BY_GEM)
	{
		/*G()->SetScale(_scale*5.5f, _scale*5.5f, _x + x, _y + y);
		G()->SetRotate(GAME()->_frame_counter, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();

		G()->SetRotate(-(GAME()->_frame_counter * 0.6f), _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();
		G()->ClearScale();*/
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 33, _x + x, _y + y);
		float posx = 0;
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(33, 1) + 125;
		int line = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->SetLineSpacing(7);
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiPageFormat(G(), posx + x, posy + y, k_SCREEN_WIDTH / 2 , _HCENTER, "Do you want to heal your castle and fight the boss again?");
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->SetLineSpacing(line);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 48, _x + x, _y + y);
		G()->ClearScale();
		G()->SetScale(_scale*2.5f, _scale*2.5f, _x + x, _y + y + 50);
		GET_SPRITE(SPRITEID_HUD_GEMSHOP)->DrawFrame(G(), 11, _x + x, _y + y + 50);
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y);
	}
	else if (_context == DIALOG_CONTEXT_RELIC_SPECIAL)
	{
		G()->SetScale(_scale*5.5f, _scale*5.5f, _x + x, _y + y);
		G()->SetRotate(GAME()->_frame_counter, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();

		G()->SetRotate(-(GAME()->_frame_counter * 0.6f), _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, _x + x, _y + y);
		G()->ClearRotate();
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 33, _x + x, _y + y);
		float posx = 0;
		float posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(33, 1) + 75;
		int line = GET_SPRITE(SPRITEID_FONT_HUD)->_line_spacing;
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(7);
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(), posx + x, posy + y, k_SCREEN_WIDTH / 2 - 60, _HCENTER, "Don't miss your chance to have this limited discount!");
		GET_SPRITE(SPRITEID_FONT_HUD)->SetLineSpacing(line);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 50, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 47, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 34, _x + x, _y + y);
		posx = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterX(31, 2);
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(31, 2);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx + x, posy + y + 5, _HCENTER, "Worth  %d ;", game->_relic_special_cost);
		//G()->SetScale(_scale, _scale, posx + x + 10, posy + y + 85);
		G()->SetRotate(GAME()->_frame_counter*0.45f, posx + x + 10, posy + y + 85);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 39, posx + x + 10, posy + y + 85);
		G()->ClearRotate();
		//G()->ClearScale();
		G()->SetScale(_scale*0.8f, _scale*0.8f, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_ITEM)->DrawFrame(G(), game->_relic_special_frameid, posx + x + 10, posy + y + 65);
		G()->ClearScale();
		G()->SetScale(_scale, _scale, _x + x, _y + y);
		GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 51, _x + x + 5, _y + y + 40);
		
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, posx + x - 100, posy + y + 200);
		GET_SPRITE(game->_hero_inbattle_arr[game->_relic_special_heroindex].GetSpriteID())->DrawFrame(G(),4, posx + x - 100, posy + y + 200);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, posx + x - 100, posy + y + 200);
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), posx + x - 155, posy + y + 200 + 85, _LEFT, "ATK: %lld", game->_hero_inbattle_arr[game->_relic_special_heroindex].GetTotalDamage());
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224 + game->_hero_inbattle_arr[game->_relic_special_heroindex].GetNumStars(), posx + x - 100, posy + y + 200 - 55);

		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 71, posx + x + 115, posy + y + 200);
		GET_SPRITE(game->_hero_inbattle_arr[game->_relic_special_heroindex].GetSpriteID())->DrawFrame(G(), 4, posx + x + 115, posy + y + 200);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, posx + x + 115, posy + y + 200);
		GET_SPRITE(SPRITEID_FONT_PLUS_DAME)->DrawAnsiTextFormat(G(), posx + x + 60 + 56, posy + y + 200 + 85, _LEFT, "%lld", game->_hero_inbattle_arr[game->_relic_special_heroindex].GetTotalDamageHightRar());
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), posx + x + 60, posy + y + 200 + 85, _LEFT, "%s" ,"ATK:");
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 224 + game->_hero_inbattle_arr[game->_relic_special_heroindex].GetNumStars() + 1, posx + x + 115, posy + y + 200 - 55);
		int cost_dis = game->_relic_special_cost / 2;
		posy = GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->GetFModuleCenterY(34, 0);
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + x, _y + y + posy, _HCENTER | _VCENTER, "Superb discount with ONLY %d ;", cost_dis);
	}
	else if (_context == DIALOG_CONTEXT_PURCHASE_MORE_WHEEL)
	{
		int line_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing;
		int char_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 10;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 8, _x + x, _y + y);
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiPageFormat(G(), _x + x, _y + y - 130, 400, _HCENTER | _VCENTER, "%s", _body);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 40, _x + x, _y + y);
		GET_SPRITE(SPRITEID_FONT_SPIN_GOLD)->DrawAnsiTextFormat(G(), _x + x, _y + y + 45, _HCENTER | _TOP, ":%d", 3);
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = line_space;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = char_space;
	}
	else
	{
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 8, _x + x, _y + y);
		float yy = Button::GetFrameY(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) + Button::GetFrameHeight(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), 0) / 2 - 60;

		int line_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing;
		int char_space = GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 10;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 2;
		yy = -120;
		if (_context >= DIALOG_CONTEXT_INVITATION_GIFT_1 && _context <= DIALOG_CONTEXT_INVITATION_GIFT_3)
        {
            yy = -90;
        }
		if (strcmp(_title, "NULL") != 0)
		{
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x, _y + y + yy, 400, _HCENTER | _VCENTER, _title);
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = 1;
		}
		yy = -10;
        if(_context >= DIALOG_CONTEXT_OFFLINE_REWARD1 && _context <= DIALOG_CONTEXT_OFFLINE_REWARD4)
        {
            GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 20;
        }
		if (_context == DIALOG_CONTEXT_DAILY_REWARD)
		{
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = 20;
		}
		if (_context == DIALOG_CONTEXT_OFFLINE_EARNING_PRO)
		{
			yy = -35;
		}
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), _x + x, _y + y + yy, 420, _HCENTER | _VCENTER, _body);
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_line_spacing = line_space;
		GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->_char_spacing = char_space;
	}
	
	switch (_context)
	{
	case DIALOG_CONTEXT_INVITATION_GIFT_1:
	case DIALOG_CONTEXT_INVITATION_GIFT_2:
	case DIALOG_CONTEXT_INVITATION_GIFT_3:
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 17, _x + x, _y + y);
		break;
	default:
		break;
	}
	if (_type == DIALOGTYPE_YESNO)
	{
		float posy_extra = 0;
		if (_context == DIALOG_CONTEXT_RELIC_SPECIAL)
		{
			posy_extra = 55;
		}
		else if (_context == DIALOG_CONTEXT_PURCHASE_MORE_WHEEL)
		{
			posy_extra = -165;
		}
		for (int i = 0; i < 2; i++)
		{
			_yesno[i].SetPos(_x + x, _y + y + posy_extra);
		}
		if (_context != DIALOG_CONTEXT_PRESTIGE && _context != DIALOG_CONTEXT_REVIVE_BY_ADS && _context != DIALOG_CONTEXT_REVIVE_BY_GEM 
			&& _context != DIALOG_CONTEXT_RELIC_SPECIAL && _context != DIALOG_CONTEXT_PURCHASE_MORE_WHEEL)
		{
			int dx = _yesno[0].TZ_GetX() - _yesno[1].TZ_GetX();
			dx = CMath::ABSOLUTE_VALUE(dx);
			//printf("\n dx = %d",dx);
			_yesno[0].SetPos(-dx + _x + x, _y + y);
			_yesno[1].SetPos(dx + _x + x, _y + y);
		}

		for (int i = 0; i < 2; i++)
		{
			_yesno[i].Update();
			_yesno[i].Render(G());
		}
		float scale = 1.0f*_scale;
		if (_yesno[1]._state == BUTTON_STATE_SELECT)
		{
			scale = 1.2f*_scale;
		}
		if (_context == DIALOG_CONTEXT_REVIVE_BY_ADS)
		{

			//render price
			float posx = _yesno[1].GetCenterX();
			float posy = _yesno[1].GetCenterY() -5;
			G()->SetScale(scale, scale, posx + 30, posy);
			GET_SPRITE(SPRITEID_HUD_DATA_MENU_PRESTIGE)->DrawFrame(G(), 10, posx + 50, posy);
			G()->ClearScale();
		}
		else if (_context == DIALOG_CONTEXT_REVIVE_BY_GEM)
		{
			//render price
			float posx = _yesno[1].GetCenterX();
			float posy = _yesno[1].GetCenterY();
			G()->SetScale(scale, scale, posx + 35, posy);
			GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 49, posx + 55, posy);
			G()->ClearScale();
		}
	}
	else
	{
		float posy_ex = 0;
		if (_context == DIALOG_CONTEXT_VIEW_PRESTIGE)
		{
			//posy_ex += 175;
			_ok.SetState(BUTTON_STATE_LOCK);
		}
		_ok.SetPos(_x + x, _y + y + posy_ex);
		_ok.Update();
		_ok.Render(G());
		float scale = 1.4f*_scale;
		if (_ok._state == BUTTON_STATE_SELECT)
		{
			scale = 1.55f*_scale;
		}
		
		if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_SPEC)
		{
			
			//render price
			float posx = _ok.GetCenterX();
			float posy = _ok.GetCenterY() + 24;
			G()->SetScale(scale, scale, posx, posy);
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx, posy, _HCENTER, "%s", game->_iap_dis_price);
			G()->ClearScale();
		}
		else if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_OFF)
		{
			//render price
			float posx = _ok.GetCenterX();
			float posy = _ok.GetCenterY() + 24;
			G()->SetScale(scale, scale, posx, posy) ;
			GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), posx, posy, _HCENTER, "%s", game->_iap_dis_price);
			G()->ClearScale();
		}
		else if (_context == DIALOG_CONTEXT_VIEW_PRESTIGE)
		{
			float posx = _ok.GetCenterX();
			float posy = _ok.GetCenterY() - 14;
			GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextPageFormatCustomColor(G(), posx, posy, 200, _HCENTER | _VCENTER, _body);
		}
	}
	if (_typetransaction == ZOOM_IN_OUT_TRANSACTION)
	{
		G()->ClearScale();
	}
	else
	{
		G()->SetOpacity(_opa);
	}
}
bool CDialog::UpdateTouchYesNo()
{
	bool ret = false;
	int index = -1;
#if !defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		PROCESSING_DIALOG_YESNO(_context, 0);
		_state = STATE_CLOSE;
		GAME()->_isBackkeyPress = false;
	}
#endif
	for (int i = 0; i < 2; i++)
	{
		if (_yesno[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_yesno[index].NeedAction())
		{
			PROCESSING_DIALOG_YESNO(_context, index);
			_state = STATE_CLOSE;
			if (index == 0)
			{
				GAME()->PlaySFX(SFX_BUTTON);
			}
			else
			{
				GAME()->PlaySFX(SFX_BUTTON);
			}
			for (int i = 0; i < 2; i++)
			{
				if (_yesno[i]._state != BUTTON_STATE_LOCK && _yesno[i]._state != BUTTON_STATE_HIDE)
				{
					_yesno[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			//CGame::_this->ClearAllTouch();
		}
		return true;
	}
	bool pressed = false;
	for (int i = CGame::_this->_num_touches - 1; i >= 0; i--)
	{
			for (int touch = 0; touch < 2; touch++)
			{
				if (_yesno[touch]._state == BUTTON_STATE_LOCK || _yesno[touch]._state == BUTTON_STATE_HIDE)
				{
					continue;
				}
				int x = _yesno[touch].TZ_GetX();
				int y = _yesno[touch].TZ_GetY();
				int w = _yesno[touch].TZ_GetWidth();
				int h = _yesno[touch].TZ_GetHeight();
				Button *button = &_yesno[touch];
				if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
				{
					if (TOUCHS(i)->_state == TOUCH_DOWN)
					{
						if (button->_touch_id == -1)
						{
							button->SetState(BUTTON_STATE_SELECT);
							button->_touch_id = TOUCHS(i)->_id;
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_DRAG)
					{
						if (button->IsAction(TOUCHS(i)->_id))
						{
							button->SetState(BUTTON_STATE_SELECT);
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_UP)
					{
						if (button->IsAction(TOUCHS(i)->_id))
						{
							button->SetState(BUTTON_STATE_ACTIVE);
							
						}
					}
					if (button->_touch_id != -1)
					{
						pressed = true;
					}
				}
				else
				{
					if (TOUCHS(i)->_state == TOUCH_UP)
					{
						if (button->IsAction(TOUCHS(i)->_id))
						{
							button->_touch_id = -1;
							button->SetState(BUTTON_STATE_NORMAL);
						}

					}
				}
			}
		}
	return pressed;
}
bool CDialog::UpdateTouchOK()
{
	bool ret = false;
	int index = -1;
#if ! defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		_state = STATE_CLOSE;
		PROCESSING_DIALOG_OK(_context);
		_ok.SetState(BUTTON_STATE_NORMAL);
		GAME()->_isBackkeyPress = false;
	}
#endif
	if (_ok._state == BUTTON_STATE_ACTIVE)
	{
		ret = true;
		
	}

	if (ret)
	{
		if (_ok.NeedAction())
		{
			_state = STATE_CLOSE;
			
			if (_ok._state != BUTTON_STATE_LOCK && _ok._state != BUTTON_STATE_HIDE)
			{
				PROCESSING_DIALOG_OK(_context);
				_ok.SetState(BUTTON_STATE_NORMAL);
				GAME()->PlaySFX(SFX_BUTTON);
			}

			
		
			//CGame::_this->ClearAllTouch();
		}
		return true;
	}
	bool pressed = false;
	for (int i = CGame::_this->_num_touches - 1; i >= 0; i--)
	{
		if (TOUCHS(i)->_flag)
		{
			
			{
				if (_ok._state == BUTTON_STATE_LOCK || _ok._state == BUTTON_STATE_HIDE)
				{
					continue;
				}
				int x = _ok.TZ_GetX();
				int y = _ok.TZ_GetY();
				int w = _ok.TZ_GetWidth();
				int h = _ok.TZ_GetHeight();
				Button *button = &_ok;
				if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
				{
					
					if (TOUCHS(i)->_state == TOUCH_DOWN)
					{
						if (button->_touch_id == -1)
						{
							button->SetState(BUTTON_STATE_SELECT);
                            button->_touch_id = TOUCHS(i)->_id;
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_DRAG)
					{
						if (button->IsAction(TOUCHS(i)->_id))
						{
							button->SetState(BUTTON_STATE_SELECT);
						}
					}
					else if (TOUCHS(i)->_state == TOUCH_UP)
					{
						if (button->IsAction(TOUCHS(i)->_id))
						{
							button->_touch_id = -1;
							button->SetState(BUTTON_STATE_ACTIVE);
							pressed = true;
							if (_context == DIALOG_CONTEXT_REWARD_EARNING_OFF)
							{
								PDEBUG("\n OK press");
								GAME()->ShowAds();
							}
						}
					}
					if (button->_touch_id != -1)
					{
						pressed = true;
					}
				}
				else
				{
					
					if (button->IsAction(TOUCHS(i)->_id))
					{
						if (TOUCHS(i)->_state == TOUCH_UP)
						{
							button->_touch_id = -1;
							button->SetState(BUTTON_STATE_NORMAL);
							pressed = true;
						}
					}
					else
					{
						if (_context == DIALOG_CONTEXT_IAP_DISCOUNT_OFF || _context == DIALOG_CONTEXT_IAP_DISCOUNT_SPEC)
						{
							if (TOUCHS(i)->_state == TOUCH_DOWN)
							{
								if (_touch_close_id == -1)
								{
									_touch_close_id = TOUCHS(i)->_id;
								}
							}
							else if (TOUCHS(i)->_state == TOUCH_DRAG)
							{
							}
							else if (TOUCHS(i)->_state == TOUCH_UP)
							{
								if (_touch_close_id == TOUCHS(i)->_id)
								{
									_touch_close_id = -1;
									_state = STATE_CLOSE;
									pressed = true;
								}
							}
							if (button->_touch_id != -1)
							{
								pressed = true;
							}
						}
					}
				}
			}
		}
	}
	return pressed;
}

bool CDialog::UpdateTouchOut()
{
	TDGame*game = (TDGame*)(GAME()->_current_game);
	bool pressed = false;
	for (int i = CGame::_this->_num_touches - 1; i >= 0; i--)
	{
		if (TOUCHS(i)->_flag)
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				if (_touch_out_touchid == -1)
				{
					_touch_out_touchid = TOUCHS(i)->_id;
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
						
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (_touch_out_touchid == TOUCHS(i)->_id)
				{
					_touch_out_touchid = -1;
					pressed = true;
					_state = STATE_CLOSE;
				}
			}
			if (_touch_out_touchid != -1)
			{
				pressed = true;
			}
		}
	}
	return pressed;
}
