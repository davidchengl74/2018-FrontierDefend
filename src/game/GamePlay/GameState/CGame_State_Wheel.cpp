#include "pch.h"
#include "../../GameCore/CGame.h"
#if defined (ANDROID_OS)
bool CGame::_ask_notification = false;
#else
 bool CGame::_ask_notification = true;
#endif
 
void TDGame::WheelRender(float x, float y, int opac)
{
	G()->SetOpacity(opac);
	_wheel_button[WHEEL_BUTTON_SPIN].SetPos(k_SCREEN_WIDTH / 2 + x, k_SCREEN_HEIGHT / 2 + y);
	int bt_mx = _wheel_button[WHEEL_BUTTON_SPIN].GetCenterX();
	int bt_my = _wheel_button[WHEEL_BUTTON_SPIN].GetCenterY();
	float scale_text = 1.0f;
	if (_wheel_button[WHEEL_BUTTON_SPIN]._state == BUTTON_STATE_SELECT)
	{
		scale_text = 1.1f;
	}
	if (_wheel_state < WHEEL_STATE_CLAIM)
	{
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 0, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		G()->SetRotate(-_wheel_rotate, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 1, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		G()->ClearRotate();
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 2, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		for (int i = 0; i < WHEEL_NUM_BUTTON; i++)
		{
			if (_wheel_button[i]._state != BUTTON_STATE_HIDE)
			{
				_wheel_button[i].Render(G());
			}
			_wheel_button[i].Update();
		}
		if (_num_wheel_render > 0)
		{
			if (_wheel_button[WHEEL_BUTTON_SPIN]._state == BUTTON_STATE_LOCK)
			{
				G()->SetColorMask(0xff847868);
			}
			G()->SetScale(scale_text, scale_text, bt_mx, bt_my);
			if (_user._num_wheel_spin_premium > 0)
			{
				GET_SPRITE(SPRITEID_FONT_SPIN_GOLD)->DrawAnsiTextFormat(G(), bt_mx, bt_my + 45, _HCENTER | _TOP, ":%d", _num_wheel_render);
			}
			else if (_user._num_wheel_spin_free > 0)
			{
				GET_SPRITE(SPRITEID_FONT_SPIN_GREEN)->DrawAnsiTextFormat(G(), bt_mx, bt_my + 45, _HCENTER | _TOP, ":%d", _num_wheel_render);
			}
			G()->ClearScale();
			G()->ClearColorMask();
		}
		if (_num_wheel_spin_available <= 0)
		{
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 465, _HCENTER | _VCENTER, "Next free spins after Battle %02d", _wheel_free_battle_target);
		}
		else
		{
			int opac_main = CMath::SIN(_wheel_count_frame_render) * 100 + 30;
			G()->SetOpacity(opac*0.01f*opac_main);
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 465, _HCENTER | _VCENTER, "%s", "Spin to get the boosters!");
			if (_num_wheel_render > 1)
			{
				GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 500, _HCENTER | _VCENTER, "(You have %02d spins)", _num_wheel_render);
			}
			else if (_num_wheel_render > 0)
			{
				GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 500, _HCENTER | _VCENTER, "(You have %02d spin)", _num_wheel_render);
			}
			G()->SetOpacity(opac);
		}
		_wheel_light.DrawAnimObject(G());
	}
	else
	{
		if (_num_wheel_spin_available <= 0)
		{
			
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 465, _HCENTER | _VCENTER, "Next free spins after Battle %02d", _wheel_free_battle_target);
		}
		else
		{
			int opac_main = CMath::SIN(_wheel_count_frame_render)*100 + 30;
			G()->SetOpacity(opac*0.01f*opac_main);
			GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 465, _HCENTER | _VCENTER, "%s", "Spin to get the boosters!");
			if (_num_wheel_render > 1)
			{
				GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 500, _HCENTER | _VCENTER, "(You have %02d spins)", _num_wheel_render);
			}
			else if (_num_wheel_render > 0)
			{
				GET_SPRITE(SPRITEID_FONT_WAVE)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 500, _HCENTER | _VCENTER, "(You have %02d spin)", _num_wheel_render);
			}
			G()->SetOpacity(opac);
		}
		float scale_spin = 1.0f;
		if (_wheel_state == WHEEL_STATE_FORCE_END)
		{
			scale_spin = _wheel_scale;
		}
		G()->SetScale(scale_spin, scale_spin, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 0, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		G()->SetRotate(-_wheel_rotate, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 1, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		G()->ClearRotate();
		GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 2, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
		
		_wheel_button[WHEEL_BUTTON_SPIN].Render(G());
		
		if (_num_wheel_render > 0)
		{
			if (_wheel_button[WHEEL_BUTTON_SPIN]._state == BUTTON_STATE_LOCK)
			{
				G()->SetColorMask(0xff847868);
			}
			if (_user._num_wheel_spin_premium > 0)
			{
				GET_SPRITE(SPRITEID_FONT_SPIN_GOLD)->DrawAnsiTextFormat(G(), bt_mx, bt_my + 45, _HCENTER | _TOP, ":%d", _num_wheel_render);
			}
			else if (_user._num_wheel_spin_free > 0)
			{
				GET_SPRITE(SPRITEID_FONT_SPIN_GREEN)->DrawAnsiTextFormat(G(), bt_mx, bt_my + 45, _HCENTER | _TOP, ":%d", _num_wheel_render);
			}
			G()->ClearColorMask();
		}
		
		G()->ClearScale();
		if (_wheel_state != WHEEL_STATE_FORCE_END)
		{
			G()->SetScale(_wheel_scale, _wheel_scale, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
			GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 8, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
			GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01)->DrawFrame(G(), 17, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
			GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 - 80, _HCENTER | _VCENTER, "%s", "YOU HAVE RECEIVED");
			if (_wheel_type_reward == WHEEL_TYPE_REWARD_COIN)
			{
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2, _HCENTER | _VCENTER, "%s ;", _wheel_reward_text);
				//GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2, _HCENTER | _VCENTER, "%d ;", _wheel_reward);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_GEM)
			{
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2, _HCENTER | _VCENTER, "%s :", _wheel_reward_text);
				//GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2, _HCENTER | _VCENTER, "%d :", _wheel_reward);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_ATT)
			{
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 43, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 60, _HCENTER | _VCENTER, "Auto Attack x%s", _wheel_reward_text);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_MASS)
			{
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 52, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 60, _HCENTER | _VCENTER, "Mass. Auto x%s", _wheel_reward_text);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_SKILL)
			{
				GET_SPRITE(SPRITEID_HUD_DAILY_REWARD)->DrawFrame(G(), 44, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
				GET_SPRITE(SPRITEID_FONT_LUCKY_WHEEL)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 60, _HCENTER | _VCENTER, "Auto Skill x%s", _wheel_reward_text);
			}
			else
			{
				//_wheel_relic.Render(x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
				GET_SPRITE(_wheel_relic._spriteid)->DrawFrame(G(), _wheel_relic._frameid, x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2);
				int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
				GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), x + k_SCREEN_WIDTH / 2, y + k_SCREEN_HEIGHT / 2 + 75, _HCENTER | _VCENTER, "%s", _wheel_relic._name);
				GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
			}
			_wheel_button[WHEEL_BUTTON_CLAIM].Render(G());
			
			_wheel_light.DrawAnimObject(G());
			G()->ClearScale();
		}
		for (int i = 0; i < WHEEL_NUM_BUTTON; i++)
		{
			_wheel_button[i].Update();
		}
	}
	
	_wheel_reward_fire.Render(0, 0, opac);
	G()->SetOpacity(100);
}
void TDGame::WheelUpdate()
{
	if (_sub_state == k_INIT)
	{
		
		if (_user._num_wheel_spin_premium > 0)
		{
			_num_wheel_render = _user._num_wheel_spin_premium;
		}
		else
		{
			_num_wheel_render = _user._num_wheel_spin_free;
		}
		_wheel_count_frame_render = 0;
		_wheel_rotate_speed = 0.1f;
		_wheel_rotate_delta = 0;
		_wheel_rotate = 0;
		_wheel_scale = 0;
		_wheel_scale_max = false;
		_wheel_reward = 0;
		ConvertMoneyInbalace(_wheel_reward, _wheel_reward_text);
		_wheel_rotate_target = 0;
		_wheel_num_rotate = 0;
		_main_opac_change_state = 0;
		_wheel_touch_id = -1;
		_wheel_type_reward = WHEEL_TYPE_REWARD_NONE;
		_wheel_state = WHEEL_STATE_INIT;
		for (int i = 0; i < WHEEL_NUM_BUTTON;i++)
		{
			_wheel_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
			_wheel_button[i].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, i * 4);
			_wheel_button[i].SetPos(k_SCREEN_WIDTH/2, k_SCREEN_HEIGHT/2);
		}
        printf("\n _wheel_has_value:%d",_wheel_has_value);
        printf("\n _user._num_wheel_spin_premium:%d",_user._num_wheel_spin_premium);
        printf("\n _user._num_wheel_spin_free:%d",_user._num_wheel_spin_free);
		_wheel_button[WHEEL_BUTTON_CLAIM].SetState(BUTTON_STATE_HIDE);
		if (!_wheel_has_value)
		{
			_wheel_button[WHEEL_BUTTON_SPIN].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 37);
			//_wheel_button[WHEEL_BUTTON_SPIN].SetState(BUTTON_STATE_LOCK);
		}
		else
		{
			if (_user._num_wheel_spin_premium > 0)
			{
				_wheel_button[WHEEL_BUTTON_SPIN].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 37);
			}
			else if (_user._num_wheel_spin_free > 0)
			{
				_wheel_button[WHEEL_BUTTON_SPIN].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 33);
			}
		}
		_wheel_reward_fire.Init(SPRITEID_HUD_MAINMENU, 84, 1, 150, 0, false, 1.5f);
		_wheel_light.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_LUCKY_WHEEL_01), SPRITEID_HUD_LUCKY_WHEEL_01);
		_wheel_light.SetAnim(8, true);
		_wheel_light.SetPos(k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
		_sub_state = k_LOOP;
#if defined (ANDROID_OS)
		if (_auto_hold_key >= 0)
		{
			int index_inbattle = CheckHeroIDInBattle(_ingame_hero_button[_auto_hold_key]._heroID);
			_hero_inbattle_arr[index_inbattle]._is_max_speed = false;
			_auto_hold_key = -1;
		}
#endif
	}
	_num_wheel_spin_available = _user._num_wheel_spin_free + _user._num_wheel_spin_premium;
	//printf("\n update");
	//printf("\n _wheel_type_reward = %d - _wheel_rotate_target = %f", _wheel_type_reward, _wheel_rotate_target);
	_wheel_light.UpdateAnimObject();
	if (_wheel_state == WHEEL_STATE_INIT)
	{
		_wheel_count_frame_render += 2;
		if (_wheel_count_frame_render > 180)
		{
			_wheel_count_frame_render += -180;
		}
	}
	else
	{
		_wheel_count_frame_render = 90;
	}
	
	switch (_wheel_state)
	{
	case WHEEL_STATE_INIT:
		if (_main_opac_change_state <= 100)
		{
			_main_opac_change_state += 10;
			if (_main_opac_change_state >= 100)
			{
				_main_opac_change_state = 100;
			}
		}
		if (_ingame_fill_opac<100)
		{
			_ingame_fill_opac += 10;
			if (_ingame_fill_opac >= 100)
			{
				_ingame_fill_opac = 100;
			}
		}
        /*
        if(_ingame_fill_opac >= 100 && _main_opac_change_state >= 100)
        {
            if(_wheel_has_value)
            {
                int wheel_index = WheelGetRandomReward();
                _wheel_num_rotate = CMath::RANDOM(5, 10);
                _wheel_rotate_target = wheel_index * 40 + CMath::RANDOM(1, 39);
                
                if (_wheel_type_reward == WHEEL_TYPE_REWARD_COIN)
                {
                    int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
                    INT_TIME reward_coin = GetDesignTreasure(_battle_current, param_coin,false);
                    _wheel_reward *= reward_coin;
                }
                _wheel_state = WHEEL_STATE_SPIN_START;
                PLAY_SFX(SFX_WHEEL);
            }
        }*/
		break;
	case WHEEL_STATE_SPIN_START:
		if (_wheel_button[WHEEL_BUTTON_SPIN]._state != BUTTON_STATE_LOCK)
		{
			_wheel_button[WHEEL_BUTTON_SPIN].SetState(BUTTON_STATE_LOCK);
		}
		_wheel_rotate_delta += _wheel_rotate_speed;
		_wheel_rotate += _wheel_rotate_delta;
		if (_wheel_num_rotate > 0)
		{
			if (_wheel_rotate >= 360)
			{
				_wheel_rotate -= 360;
				_wheel_num_rotate--;
			}
			if (_wheel_num_rotate <= 0)
			{
				_wheel_state = WHEEL_STATE_SPIN_END;
			}
		}
		_count_frame_hold_end = 0;
		break;
	case WHEEL_STATE_SPIN_END:
		if (_wheel_rotate_delta >= 1.5f)
		{
			_wheel_rotate_delta *= 0.99f;
		}
		if (_wheel_rotate_delta <= 1.5f)
		{
            _wheel_rotate_delta -= 0.005f;
			if (_wheel_rotate >= _wheel_rotate_target - 1 && _wheel_rotate <= _wheel_rotate_target + 1)
			{
				_wheel_rotate_delta = 0;
				
				if (_count_frame_hold_end == 0)
				{
					float angle = (int)(_wheel_rotate) % 40;
					float posx = k_SCREEN_WIDTH / 2 + 160 * CMath::COS(-angle/2 - 90);
					float posy = k_SCREEN_HEIGHT / 2 + 160 * CMath::SIN(-angle/2 - 90);
					//printf("\n posx = %f,posy = %f - _wheel_rotate = %f", posx, posy, angle);
					_wheel_reward_fire.Active(posx, posy, 6, 10, 1, 0, 1.0f, 100);
					GAME()->PlaySFX(SFX_CHEST_ACQUIRED);
				}
				_count_frame_hold_end++;
				if (_count_frame_hold_end >= 90)
				{
					_wheel_scale = 0;
					_wheel_scale_max = false;
					_wheel_state = WHEEL_STATE_CLAIM;
					
					if (_wheel_button[WHEEL_BUTTON_CLAIM]._state == BUTTON_STATE_HIDE)
					{
						_wheel_button[WHEEL_BUTTON_CLAIM].SetState(BUTTON_STATE_NORMAL);
					}
                    /*
                    if (Device::IsNetworkAvailable())
                    {
                        PineAdBox::ShowAdvertFullScreen();
                       
                    }*/
				}
			}
			else
			{
				
				if (_wheel_rotate_delta < 1.0f)
				{
					_wheel_rotate_delta = 1.0f;
				}
			}
            //printf("\n _wheel_rotate_delta = %f", _wheel_rotate_delta);
		}
		_wheel_rotate += _wheel_rotate_delta;
		if (_wheel_rotate >= 360.0)
		{
			_wheel_rotate -= 360.0;
		}
		break;
	case WHEEL_STATE_CLAIM:
		if (!_wheel_scale_max)
		{
			_wheel_scale += 0.1f;
			if (_wheel_scale >= 1.2f)
			{
				_wheel_scale_max = true;
			}
		}
		else
		{
			_wheel_scale -= 0.05f;
			if (_wheel_scale < 1.0f)
			{
				_wheel_scale = 1.0f;
			}
		}
		break;
	case WHEEL_STATE_POP_UP_END:
		if (_wheel_scale > 0)
		{
			_wheel_scale -= 0.1f;
			if (_wheel_scale <= 0)
			{
				_wheel_scale = 0;
				_wheel_state = WHEEL_STATE_INIT;
				if (_num_wheel_spin_available > 0)
				{
					if (_wheel_button[WHEEL_BUTTON_SPIN]._state == BUTTON_STATE_LOCK)
					{
						_wheel_button[WHEEL_BUTTON_SPIN].SetState(BUTTON_STATE_NORMAL);
					}
					if (_wheel_button[WHEEL_BUTTON_CLAIM]._state != BUTTON_STATE_HIDE)
					{
						_wheel_button[WHEEL_BUTTON_CLAIM].SetState(BUTTON_STATE_HIDE);
					}
				}
				else
				{
					_wheel_button[WHEEL_BUTTON_SPIN].SetAnim(SPRITEID_HUD_LUCKY_WHEEL_01, 37);
					if (_wheel_button[WHEEL_BUTTON_SPIN]._state == BUTTON_STATE_LOCK)
					{
						_wheel_button[WHEEL_BUTTON_SPIN].SetState(BUTTON_STATE_NORMAL);
					}
					if (_wheel_button[WHEEL_BUTTON_CLAIM]._state != BUTTON_STATE_HIDE)
					{
						_wheel_button[WHEEL_BUTTON_CLAIM].SetState(BUTTON_STATE_HIDE);
					}
				}
				
			}
		}
		break;
	case WHEEL_STATE_REINIT:
		break;
	case WHEEL_STATE_END:
	case WHEEL_STATE_FORCE_END:
		if (_main_opac_change_state > 0)
		{
			_main_opac_change_state -= 10;
			if (_main_opac_change_state <= 0)
			{
				_main_opac_change_state = 0;
			}
		}
		if (_wheel_scale > 0)
		{
			_wheel_scale -= 0.1f;
			if (_wheel_scale <= 0)
			{
				_wheel_scale = 0;
				SetState(k_GS_PLAYGAME);
                ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
				_sub_state = k_LOOP;
				ClearAllTouchUp(TOUCH_TYPE_INGAME);
				/*if (!_user._is_notify && CGame::_ask_notification && _num_wheel_spin_available <= 0)
				{
					CGame::_ask_notification = false;
					char text[256];
					sprintf(text, "%s", "Do you want us to notify when the Wheel is ready?");
					_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_NOTIFY, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
				}*/
            }
		}
		break;
	default:
		break;
	}
	if (!WheelUpdateTouch())
	{
		if (_num_wheel_spin_available <= 0)
		{
			for (int i = GAME()->_num_touches - 1; i >= 0; i--)
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (_wheel_touch_id == -1 && _wheel_state == WHEEL_STATE_INIT)
					{
						_wheel_state = WHEEL_STATE_FORCE_END;
						_wheel_scale = 1.0f;
					}
				}
			}
		}
	}
	_wheel_reward_fire.Update();
}
bool TDGame::WheelUpdateTouch()
{
	if (_dialogMng.isOpenDialog())
	{
		return true;
	}
#if !defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		if (_wheel_state == WHEEL_STATE_CLAIM)
		{
			if (_wheel_type_reward == WHEEL_TYPE_REWARD_RELIC)
			{
				//_items_relics[_user._quest_num_relics_own].Init(SPRITEID_HUD_ITEM, _wheel_relic._group, _wheel_relic._id, 0, 0, false);
				ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
				_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
				ModifyInfo(_wheel_relic._group, _wheel_relic._id);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_GEM)
			{
				_user.AddGem(_wheel_reward);
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_ATT)
			{
				_user._auto_attack_free += _wheel_reward;
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_MASS)
			{
				_user._num_mass_auto_free += _wheel_reward;
			}
			else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_SKILL)
			{
				_user._auto_skill_free += _wheel_reward;
			}
			else
			{
				_user.AddCoin(_wheel_reward, true);
			}
			if (_user._num_wheel_spin_premium > 0)
			{
				_user._num_wheel_spin_premium--;
			}
			else
			{
				if (_user._num_wheel_spin_free > 0)
				{
					_user._num_wheel_spin_free--;
				}
			}
			_num_wheel_spin_available = _user._num_wheel_spin_premium + _user._num_wheel_spin_free;
			if (_user._num_wheel_spin_premium > 0)
			{
				_num_wheel_render = _user._num_wheel_spin_premium;
			}
			else
			{
				_num_wheel_render = _user._num_wheel_spin_free;
			}

			GAME()->_isBackkeyPress = false;
			_wheel_state = WHEEL_STATE_POP_UP_END;
			_user.WheelReset();
			_user.UserDataSave();
		}
		else
		{
			if (_num_wheel_spin_available <= 0)
			{
				_wheel_state = WHEEL_STATE_FORCE_END;
				_wheel_scale = 1.0f;
				GAME()->_isBackkeyPress = false;
			}
		}
		return true;
	}
#endif
	bool ret = false;
	int index = -1;
	for (int i = 0; i < WHEEL_NUM_BUTTON; i++)
	{
		if (_wheel_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_wheel_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case WHEEL_BUTTON_SPIN:
			{
				if (_num_wheel_spin_available > 0)
				{
					int wheel_index = WheelGetRandomReward();
					_wheel_num_rotate = CMath::RANDOM(5, 10);
					_wheel_rotate_target = ((wheel_index - 1) * 40 + CMath::RANDOM(1, 39) + 360) % 360;
					//printf("\n _wheel_type_reward = %d - wheel_index = %d", _wheel_type_reward, wheel_index);
					if (_wheel_type_reward == WHEEL_TYPE_REWARD_COIN)
					{
						int param_coin = CGameDesign::FileTreasure::CSheetSheet1::coins;
						INT_TIME reward_coin = GetDesignTreasure(_battle_current, param_coin, false);
						_wheel_reward *= reward_coin;
						ConvertMoneyInbalace(_wheel_reward, _wheel_reward_text);
					}
					_num_wheel_render--;
					_wheel_state = WHEEL_STATE_SPIN_START;
					GAME()->PlaySFX(SFX_WHEEL);
				}
				else
				{
					char text[256];
					sprintf(text, "%s", "Do you want to buy 3 Premium Spins by $0.99?");
					_dialogMng.Add(DIALOG_CONTEXT_PURCHASE_MORE_WHEEL, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
					char title[128];
					char decs[1024];
					sprintf(title, "%s", "Premium-Wheel View");
					sprintf(decs, "%s", "Premium-Wheel View");
					char type[128];
					sprintf(type, "%s", "iap_promo_logs");
					#if defined (MAC_OS) || (ANDROID_OS)
					PDEBUG("\n logContent title:%s --- decs:%s --- type:%s", title, decs,type);
					Device::GA_LogContents(title, decs,type);
					#endif
				}
			}
				
				break;
			case WHEEL_BUTTON_CLAIM:
				if (_wheel_type_reward == WHEEL_TYPE_REWARD_RELIC)
				{
					//_items_relics[_user._quest_num_relics_own].Init(SPRITEID_HUD_ITEM, _wheel_relic._group, _wheel_relic._id, 0, 0, false);
					ModifyRelicItems(_wheel_relic._group, _wheel_relic._id, false);
					_user.AddNewRelics(_wheel_relic._id, _wheel_relic._group);
					ModifyInfo(_wheel_relic._group, _wheel_relic._id);
				}
				else if (_wheel_type_reward == WHEEL_TYPE_REWARD_GEM)
				{
					_user.AddGem(_wheel_reward);
				}
				else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_ATT)
				{
					_user._auto_attack_free += _wheel_reward;
				}
				else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_MASS)
				{
					_user._num_mass_auto_free += _wheel_reward;
				}
				else if (_wheel_type_reward == WHEEL_TYPE_REWARD_AUTO_SKILL)
				{
					_user._auto_skill_free += _wheel_reward;
				}
				else
				{
					_user.AddCoin(_wheel_reward,true);
				}
				if (_user._num_wheel_spin_premium > 0)
				{
					_user._num_wheel_spin_premium--;
				}
				else
				{
					if (_user._num_wheel_spin_free > 0)
					{
						_user._num_wheel_spin_free--;
					}
				}
				_num_wheel_spin_available = _user._num_wheel_spin_premium + _user._num_wheel_spin_free;
				if (_user._num_wheel_spin_premium > 0)
				{
					_num_wheel_render = _user._num_wheel_spin_premium;
				}
				else
				{
					_num_wheel_render = _user._num_wheel_spin_free;
				}
				/*if (_num_wheel_spin_available > 0)
				{
					_wheel_state = WHEEL_STATE_POP_UP_END;
				}
				else
				{
					_wheel_state = WHEEL_STATE_END;
				}*/
				_wheel_state = WHEEL_STATE_POP_UP_END;
				_user.WheelReset();
				_user.UserDataSave();
                    
                    
                
                  
				break;
			default:
				break;
			}

			for (int i = 0; i < WHEEL_NUM_BUTTON; i++)
			{
				if (_wheel_button[i]._state != BUTTON_STATE_LOCK && _wheel_button[i]._state != BUTTON_STATE_HIDE)
				{
					_wheel_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < WHEEL_NUM_BUTTON; touch++)
		{
			if (_wheel_button[touch]._state == BUTTON_STATE_LOCK || _wheel_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _wheel_button[touch].TZ_GetX();
			int y = _wheel_button[touch].TZ_GetY();
			int w = _wheel_button[touch].TZ_GetWidth();
			int h = _wheel_button[touch].TZ_GetHeight();
			Button *button = &_wheel_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d",touch);
						button->SetState(BUTTON_STATE_SELECT);
						GAME()->PlaySFX(SFX_BUTTON);
						button->_touch_id = TOUCHS(i)->_id;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						pressed = true;
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (button->IsAction(TOUCHS(i)->_id))
					{
						button->SetState(BUTTON_STATE_ACTIVE);
						pressed = true;
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
						button->SetState(BUTTON_STATE_NORMAL);
						button->_touch_id = -1;
					}
					pressed = true;
				}
			}
		}
	}
	return pressed;
}
int TDGame::WheelGetRandomReward()
{
	int wheel_index = 0;
	int rand = CMath::RANDOM(1, 100);
	int total = _game_design.General.SheetWheel.int32Value._totalData;
	int param_rate = CGameDesign::FileGeneral::CSheetWheel::Rate;
	int param_value = CGameDesign::FileGeneral::CSheetWheel::Value;
	int param_type = CGameDesign::FileGeneral::CSheetWheel::Type;
	int percen = 0;
	bool is_relic = RandomRelics();
	for (int i = 0; i < total; i++)
	{
		int per_up = GetDesignWheelInfo(i, param_rate);
		if (rand > percen && rand <= percen + per_up)
		{
			_wheel_reward = GetDesignWheelInfo(i, param_value);
			_wheel_type_reward = GetDesignWheelInfo(i, param_type);
			wheel_index = i;
			if (_wheel_type_reward == WHEEL_TYPE_REWARD_RELIC)
			{
				if (!is_relic)
				{
					_wheel_reward = GetDesignWheelInfo(i-1, param_value);
					_wheel_type_reward = GetDesignWheelInfo(i-1, param_type);
					wheel_index = i-1;
				}
			}
			break;
		}
		percen += per_up;
	}
	ConvertMoneyInbalace(_wheel_reward, _wheel_reward_text);
	return wheel_index;
}

bool TDGame::RandomRelics()
{
	bool ret = true;
	int total_hero_relic = _game_design.Relics_design.SheetHero_Relics.int32Value._totalData;
	int total_weapon_relic = _game_design.Relics_design.SheetWeapon_Relics.int32Value._totalData;
	int total_enemy_relic = _game_design.Relics_design.SheetEnemy_Relics.int32Value._totalData;

	int arr_relic_id[NUM_MAX_ITEM_RELICS];
	int paramid = CGameDesign::FileRelics_design::CSheetHero_Relics::ID;
	int id = 0;
	int num_relic = 0;
	for (int i = 0; i < total_hero_relic; i++)
	{
		id = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, paramid);
		int paraminterid = CGameDesign::FileRelics_design::CSheetHero_Relics::Hero_ID;
		int interactive_id = GetDesignRelics(i, ITEMRELIC_GROUP_HERO, paraminterid);
		if (!_user.CheckHeroColleted(interactive_id))
		{
			continue;
		}
		if (!_user.CheckRelicsCollected(ITEMRELIC_GROUP_HERO, id))
		{
			arr_relic_id[num_relic] = id;
			num_relic++;
		}
	}
	
	for (int i = 0; i < total_weapon_relic; i++)
	{
		id = GetDesignRelics(i, ITEMRELIC_GROUP_WEAPON, paramid);
		int param_interid = CGameDesign::FileRelics_design::CSheetWeapon_Relics::Weapon_ID;
		int id_interactive = GetDesignRelics(i, ITEMRELIC_GROUP_WEAPON, param_interid);
		if (id_interactive>0)
		{
			if (_weapon[id_interactive - 2].IsLock())
			{
				continue;
			}
		}
		if (!_user.CheckRelicsCollected( ITEMRELIC_GROUP_WEAPON,id))
		{
			arr_relic_id[num_relic] = id + 1000;
			num_relic++;
		}
	}
	for (int i = 0; i < total_enemy_relic; i++)
	{
		id = GetDesignRelics(i, ITEMRELIC_GROUP_ENEMY, paramid);
		if (!_user.CheckRelicsCollected( ITEMRELIC_GROUP_ENEMY,id))
		{
			arr_relic_id[num_relic] = id + 10000;
			num_relic++;
		}
	}
	if (num_relic <= 0)
	{
		ret = false;
		return ret;
	}
	int index = CMath::RANDOM(0, num_relic - 1);
	int group_summon = 0;
	int id_summon = arr_relic_id[index];
	if (id_summon < 1000)
	{
		group_summon = ITEMRELIC_GROUP_HERO;
		id_summon;
	}
	else if (id_summon < 10000)
	{
		group_summon = ITEMRELIC_GROUP_WEAPON;
		id_summon -= 1000;
	}
	else
	{
		group_summon = ITEMRELIC_GROUP_ENEMY;
		id_summon -= 10000;
	}
	if (id_summon >= 0)
	{
		_wheel_relic.Init(SPRITEID_HUD_ITEM, group_summon, id_summon, 0, 0, false);
	}
	return ret;
}

bool TDGame::WheelIsReady()
{
	bool ret = false;
	/*if (_wheel_time.isNullDay() && _menu_button[MENU_BUTTON_WHEEL]._state != BUTTON_STATE_LOCK && _menu_button[MENU_BUTTON_WHEEL]._state != BUTTON_STATE_HIDE)
	{
		if (_effect_notify_menu_button[MENU_BUTTON_WHEEL]._state == NOTIFY_STATE_NONE)
		{
			_effect_notify_menu_button[MENU_BUTTON_WHEEL].Active();
		}
		ret = true;
	}
	else
	{
		if (_effect_notify_menu_button[MENU_BUTTON_WHEEL]._state == NOTIFY_STATE_ACTIVE)
		{
			_effect_notify_menu_button[MENU_BUTTON_WHEEL].Disable();
		}
		ret = false;
	}*/
	if (_battle_current >= _wheel_free_battle_target)
	{
		_user._num_wheel_spin_free = 2;
		_wheel_free_battle_target = ((_battle_current/5)*5) + 5;
        _user.UserDataSave();
	}
	if (_user._num_wheel_spin_free > 0 || _user._num_wheel_spin_premium > 0)
	{
		ret = true;
        TDGame::_auto_wheel = true;
	}
	return ret;
}
