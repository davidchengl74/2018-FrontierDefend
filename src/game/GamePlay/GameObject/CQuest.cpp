#include "pch.h"
#include "../../GameCore/CGame.h"


CQuest::CQuest()
{
}

CQuest::~CQuest()
{
}

void CQuest::Init(int id, int group, int nummax, float x, float y, bool completed, bool daily)
{
	if (id < 0 || group < 0)
	{
		return;
	}
	TDGame*game = (TDGame*)GAME()->_current_game;
	int param_name = CGameDesign::FileQuest::CSheetNormal_Quest::Quest_name;
	int param_value = CGameDesign::FileQuest::CSheetNormal_Quest::Value;
	int param_rw_coin = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_coins;
	int param_rw_gem = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_gems;
	int param_type = CGameDesign::FileQuest::CSheetNormal_Quest::Type;
    int param_archiveid = CGameDesign::FileQuest::CSheetNormal_Quest::Achievement_ID;
	_has_daily_quest = daily;
	int questindex = game->GetQuestIndex(group, id,_has_daily_quest);
	_quest_group_id = group;
	_quest_id = id;
	if (_has_daily_quest)
	{
		questindex = _quest_id;
	}
	_is_completed = completed;
	_num_quest = nummax;
	_x = x;
	_y = y;
	_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
	_scale_text_button = 1.0f;
	_has_touch = false;
	_is_new = false;
	_level = 0;
	_type = game->GetDesignQuestValue(questindex, param_type, _has_daily_quest);
	_value1 = game->_user.GetQuestCurrentValue(group - 1, game->_user._quest_current[group - 1], _has_daily_quest);
	_reward_coin = 0;
	_reward_gem = 0;
	_reward_coin = game->GetDesignQuestValue(questindex, param_rw_coin, _has_daily_quest);
	_reward_gem = game->GetDesignQuestValue(questindex, param_rw_gem, _has_daily_quest);
	
	_value2 = game->GetDesignQuestValue(questindex, param_value, _has_daily_quest);
	sprintf(_name, "%s", game->GetDesignQuestString(questindex, param_name, _has_daily_quest));
    sprintf(_archivement, "%s", game->GetDesignQuestString(questindex, param_archiveid, _has_daily_quest));
	_spriteid = 0;
	_frameid = 0;
	_touch_y = 0;
	_touch_x = 0;
	_button_reward.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
	_button_reward.SetAnim(SPRITEID_HUD_MAINMENU, 103);
	_button_reward.SetPos(_x, _y);
	int posx = _button_reward.TZ_GetX() + _button_reward.TZ_GetWidth() - 37;
	int posy = _button_reward.TZ_GetY() + _button_reward.TZ_GetHeight()/2 + 5;
	_notify_reward.Init(SPRITEID_HUD_MAINMENU, -1, 98, posx, posy, 0);
	if (!_is_completed)
	{
		_button_reward.SetState(BUTTON_STATE_LOCK);
	}
	else
	{
		_notify_reward.Active();
	}
	for (int i = 0; i < _num_quest;i++)
	{
		int mk_star_w = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleWidth(114, 0);
		int mw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(58);
		int posx = mk_star_w/2 + i*(mk_star_w + 4);
		int posy = 42;
		int state = EFFECT_STAR_STATE_NORMAL;
		if (id > i)
		{
			state = EFFECT_STAR_STATE_END;
		}
		_star_list[i].Init(_x - mw / 2 + 146 + posx, _y + posy, state);
	}
	_shake_x = 0;
	_shake_y = 0;
	int param_frameid = CGameDesign::FileSpriteManager::CSheetSprite_Relic::SpriteId;
	int param_bg_frame = CGameDesign::FileSpriteManager::CSheetSprite_Relic::BackgroundID;
	int spriteindex = game->GetDesignQuestSpriteIndex(_name);
	_frameid = game->GetDesignQuestSprite(spriteindex, param_frameid);
	_bg_id = game->GetDesignQuestSprite(spriteindex, param_bg_frame);
	game->_anim_network_quest.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_MAINMENU), SPRITEID_HUD_MAINMENU);
	game->_anim_network_quest.SetAnim(125, true);
	game->_anim_network_quest.SetPos(0, 0);

	game->ConvertMoneyInbalace(_reward_coin, _reward_coin_text);
	game->ConvertMoneyInbalace(_reward_gem, _reward_gem_text);
	game->ConvertMoneyInbalace(_value1, _value1_text);
	game->ConvertMoneyInbalace(_value2, _value2_text);
}
void CQuest::Render(float x, float y, int opac)
{
	if (_quest_id < 0 || _quest_group_id < 0)
	{
		return;
	}
	x += _shake_x;
	y += _shake_y;
	TDGame*game = (TDGame*)GAME()->_current_game;
	int mw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(58);
	if (_type == 0)
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 58, _x + x, _y + y);
	}
	else
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 59, _x + x, _y + y);
	}
	
	_button_reward.SetPos(_x + x, _y + y);
	
	if (_button_reward._state != BUTTON_STATE_HIDE)
	{
		_button_reward.Render(G());
	}
	bool network = true;
#if defined (MAC_OS)
	/*network = GAME()->_serverThread._isNetworkAvailable;
	if (game->_is_hacked_time)
	{
		network = false;
	}*/
#endif
	if (!network && _has_daily_quest)
	{
		if (_button_reward._state != BUTTON_STATE_LOCK)
		{
			_button_reward.SetState(BUTTON_STATE_LOCK);
		}
	}
	else
	{
		_notify_reward.Render(x, y);
	}
	_button_reward.Update();
	
	GET_SPRITE(SPRITEID_HUD_ITEM)->DrawFrame(G(), _bg_id, _x + x - mw / 2 + 73, _y + y + 3);
	GET_SPRITE(SPRITEID_HUD_QUEST_ICON)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
	int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	char text[256];
	int lenght = sprintf(text, "%s", _name);
	int text_w = (GET_SPRITE(SPRITEID_FONT_HUD))->GetTextWidth(GET_SPRITE(SPRITEID_FONT_HUD)->StringToUnichar(text), 0, lenght);
	int text_h = -4 + (text_w / 330) * 20;
	if (_quest_group_id != 8)
	{
		GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), _x - mw / 2 + 146 + x, _y + text_h + y, _LEFT, "%s/%s", _value1_text, _value2_text);
	}
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiPageFormat(G(), _x - mw / 2 + 146 + x, _y - 32 + y, 330, _LEFT, "%s", _name);
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
	G()->SetScale(_scale_text_button, _scale_text_button, _x + x + mw / 2 - 110, _y + y);
	spacing = GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = 1;
	if (_reward_gem <= 0)
	{
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %s", _reward_coin_text);
		//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, ": %d", _reward_coin);
	}
	else
	{
		GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, "; %s", _reward_gem_text);
		//GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y - 34 + y, _HCENTER, "; %d", _reward_gem);
	}
	
	GET_SPRITE(SPRITEID_FONT_SHOPCOIN)->_char_spacing = spacing;
	spacing = GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_LEVELUP)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_LEVELUP)->DrawAnsiTextFormat(G(), _x + mw / 2 - 110 + x, _y + y + 18, _HCENTER, "REWARD");
	G()->ClearScale();
	//GET_SPRITE(_spriteid)->DrawFrame(G(), _frameid, _x + x - mw / 2 + 73, _y + y + 3);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 72, _x + x - mw / 2 + 73, _y + y + 3);
	if (!network && _has_daily_quest)
	{
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 143, _x + x, _y + y);
		game->_anim_network_quest.SetPos(_x + x - mw / 2 + 12, _y + y - 56);
		game->_anim_network_quest.DrawAnimObject(G());
		game->_anim_network_quest.UpdateAnimObject();
	}
	
	if (_type == 0)
	{
		for (int i = 0; i < _num_quest; i++)
		{
			if (_star_list[i]._state <= EFFECT_STAR_STATE_END)
			{
				_star_list[i].Render(x, y,opac);
			}
		}
		for (int i = 0; i < _num_quest; i++)
		{
			if (_star_list[i]._state > EFFECT_STAR_STATE_END)
			{
				_star_list[i].Render(x, y,opac);
			}
		}
	}
	
}
void CQuest::Modify()
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int param_name = CGameDesign::FileQuest::CSheetNormal_Quest::Quest_name;
	int param_archiveid = CGameDesign::FileQuest::CSheetNormal_Quest::Achievement_ID;
	int param_value = CGameDesign::FileQuest::CSheetNormal_Quest::Value;
	int param_rw_coin = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_coins;
	int param_rw_gem = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_gems;
	int param_type = CGameDesign::FileQuest::CSheetNormal_Quest::Type;
	_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
	_scale_text_button = 1.0f;
	_has_touch = false;
	_is_new = false;
	_reward_coin = 0;
	_reward_gem = 0;
	_touch_y = 0;
	_touch_x = 0;
	if (_has_daily_quest)
	{
		//_quest_id = -1;
		_quest_id = game->_daily_quest_current;
		if (_quest_id >= game->_game_design.Quest.SheetDaily_Quest.int32Value._totalData)
		{
			_quest_id = -1;
			_num_quest = 0;
			return;
		}
		else
		{
            
			_quest_group_id = game->_user._daily_quest_group_current;
			_num_quest = 1;
			//_num_quest = game->_game_design.Quest.SheetDaily_Quest.int32Value._totalData;
            //printf("\n _quest_group_id = %d - _num_quest = %d",_quest_group_id,_num_quest);
			_is_completed = game->_user._daily_quest_completed;
			_value1 = game->_user.GetQuestCurrentValue(_quest_group_id - 1, game->_user._quest_current[_quest_group_id - 1], _has_daily_quest);
			_value2 = game->GetDesignQuestValue(_quest_id, param_value, _has_daily_quest);
			_reward_coin = game->GetDesignQuestValue(_quest_id, param_rw_coin, _has_daily_quest);
			_reward_gem = game->GetDesignQuestValue(_quest_id, param_rw_gem, _has_daily_quest);
			game->ConvertMoneyInbalace(_reward_coin, _reward_coin_text);
			game->ConvertMoneyInbalace(_reward_gem, _reward_gem_text);
			game->ConvertMoneyInbalace(_value1, _value1_text);
			game->ConvertMoneyInbalace(_value2, _value2_text);
            //printf("\n _value1 = %lld - _value2 = %lld",_value1,_value2);
			sprintf(_name, "%s", game->GetDesignQuestString(_quest_id, param_name, _has_daily_quest));
			sprintf(_archivement, "%s", game->GetDesignQuestString(_quest_id, param_archiveid, _has_daily_quest));
		}
        //printf("\n_quest_id = %d",_quest_id);
	}
	else
	{
		_quest_id = game->_user._quest_current[_quest_group_id - 1];
		int questindex = game->GetQuestIndex(_quest_group_id, _quest_id, _has_daily_quest);
		_is_completed = game->_user.CheckQuestCompleted(_quest_group_id - 1, _quest_id, _has_daily_quest);
		_num_quest = game->GetNumOfQuest(_quest_group_id);
		_value1 = game->_user.GetQuestCurrentValue(_quest_group_id - 1, game->_user._quest_current[_quest_group_id - 1], _has_daily_quest);
		_reward_coin = game->GetDesignQuestValue(questindex, param_rw_coin, _has_daily_quest);
		_reward_gem = game->GetDesignQuestValue(questindex, param_rw_gem, _has_daily_quest);
		
		_value2 = game->GetDesignQuestValue(questindex, param_value, _has_daily_quest);
		sprintf(_name, "%s", game->GetDesignQuestString(questindex, param_name, _has_daily_quest));
		sprintf(_archivement, "%s", game->GetDesignQuestString(questindex, param_archiveid, _has_daily_quest));
		game->ConvertMoneyInbalace(_reward_coin, _reward_coin_text);
		game->ConvertMoneyInbalace(_reward_gem, _reward_gem_text);
		game->ConvertMoneyInbalace(_value1, _value1_text);
		game->ConvertMoneyInbalace(_value2, _value2_text);
	}
	if (!_is_completed)
	{
		_button_reward.SetState(BUTTON_STATE_LOCK);
		_notify_reward.Disable();
        //printf("\n _is_completed = %d",_is_completed);
	}
	else
	{
		_notify_reward.Active();
        //printf("\n not _is_completed = %d",_is_completed);
	}
}
void CQuest::Update()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	switch (_scale_text_button_state)
	{
	case EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL:
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_START:
		if (_scale_text_button < 1.15f)
		{
			_scale_text_button = 1.15f;
		}
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_END:
		if (_scale_text_button > 1.0f)
		{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
			/*_scale_text_button -= 0.015f;
			if (_scale_text_button <= 1.0f)
			{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
			}*/
		}
		break;
	case EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END:
		if (_scale_text_button > 1.0f)
		{
			_scale_text_button = 1.0f;
			_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
		}
		break;
	default:
		break;
	}
	_notify_reward.Update();
	bool effect_star_completed = true;
	bool has_shake = false;
	for (int i = 0; i < _num_quest; i++)
	{
		_star_list[i].Update();
		if (_star_list[i]._state > EFFECT_STAR_STATE_END)
		{
			effect_star_completed = false;
		}
		if (_star_list[i]._state == EFFECT_STAR_STATE_HOLD)
		{
			has_shake = true;
		}
	}
	if (has_shake && !_has_daily_quest)
	{
		_shake_x = CMath::RANDOM(-5, 5);
		_shake_y = CMath::RANDOM(-3, 3);
	}
	else
	{
		_shake_x = 0;
		_shake_y = 0;
	}
	
	if (effect_star_completed)
	{
		if (_has_daily_quest)
		{
			if (_quest_id == -1)
			{
				game->QuestRemoveIndex(_quest_group_id, true);
			}
		}
		else
		{
			if (game->_user._quest_current[_quest_group_id - 1] >= _num_quest)
			{
				game->QuestRemoveIndex(_quest_group_id, false);
			}
		}
	}
	if (game->_quest_menu_scroll._isScroll)
	{
		return;
	}
	_has_touch = UpdateTouch();
	if (!_has_touch)
	{
	}
}
bool CQuest::UpdateTouch()
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	bool ret = false;
	int index = -1;
	bool pressed = false;
	if (_button_reward._state == BUTTON_STATE_ACTIVE)
	{
		if (_button_reward.NeedAction())
		{
			/*if (_type == 0)
			{
				game->_user.AddCoin(_reward);
			}
			else
			{
				game->_user.AddGem(_reward);
			}*/
			game->_user.AddCoin(_reward_coin,true);
			game->_user.AddGem(_reward_gem);
			GAME()->PlaySFX(SFX_COLLECT_REWARD);
			int starindex = _quest_id;
			if (_has_daily_quest)
			{
				starindex = 0;
			}
			_star_list[starindex].Active();
			//printf("\n _quest_group_id = %d,_has_daily_quest = %d, starindex = %d", _quest_group_id, _has_daily_quest, starindex);
			game->_user.SetQuestComplete(_quest_group_id - 1,_has_daily_quest);
#if defined (MAC_OS)
            //printf("\n _archivement = %s",_archivement);
            // disable achivement ios
            /*if(strcmp(_archivement, "NONE") != 0)
            {
                //printf("\n submit achivement complete");
                PineGameCenterController::SubmitAchivement(100, _archivement, true);
            }*/
            
#else
#endif
			Modify();
			game->_user.UserDataSave();
			if (_button_reward._state != BUTTON_STATE_LOCK && _button_reward._state != BUTTON_STATE_HIDE)
			{
				_button_reward.SetState(BUTTON_STATE_NORMAL);
			}
			return true;
		}
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		if (_button_reward._state == BUTTON_STATE_LOCK || _button_reward._state == BUTTON_STATE_HIDE)
		{
			continue;
		}
		int x = _button_reward.TZ_GetX();
		int y = _button_reward.TZ_GetY();
		int w = _button_reward.TZ_GetWidth();
		int h = _button_reward.TZ_GetHeight();
		Button *button = &_button_reward;
		if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
		{
			if (TOUCHS(i)->_state == TOUCH_DOWN)
			{
				//printf("\n touch down buy button = %d", button->_touch_id);
				if (button->_touch_id == -1)
				{
					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_START;
					button->SetState(BUTTON_STATE_SELECT);
					button->_touch_id = TOUCHS(i)->_id;
					_touch_y = TOUCHS(i)->y;
					_touch_x = TOUCHS(i)->x;
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_DRAG)
			{
				if (button->IsAction(TOUCHS(i)->_id))
				{
					float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
					if (dis >= 5)
					{
						button->_touch_id = -1;
						button->SetState(BUTTON_STATE_NORMAL);
						pressed = false;
						_touch_y = 0;
						_touch_x = 0;
						_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END;
						if (game->_quest_menu_scroll._touch_id == -1)
						{
							game->_quest_menu_scroll._last_touch_y = TOUCHS(i)->y;
							game->_quest_menu_scroll.Set();
							game->_quest_menu_scroll.SetState(0);
							game->_quest_menu_scroll._offset_y = 0;
							game->_quest_menu_scroll._isScroll = true;
							game->_quest_menu_scroll._touch_id = TOUCHS(i)->_id;
						}
					}
				}
			}
			else if (TOUCHS(i)->_state == TOUCH_UP)
			{
				if (button->IsAction(TOUCHS(i)->_id))
				{
					button->SetState(BUTTON_STATE_ACTIVE);
					pressed = true;
					_touch_y = 0;
					_touch_x = 0;
					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
				}
			}
			if (button->IsAction(TOUCHS(i)->_id))
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
					pressed = true;
					_touch_y = 0;
					_touch_x = 0;
					_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_END;
				}
				else if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					float dis = CMath::DISTANCE(_touch_x, _touch_y, TOUCHS(i)->x, TOUCHS(i)->y);
					if (dis >= 5)
					{
						button->_touch_id = -1;
						button->SetState(BUTTON_STATE_NORMAL);
						pressed = false;
						_touch_y = 0;
						_touch_x = 0;
						_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_FORCE_END;
						if (game->_quest_menu_scroll._touch_id == -1)
						{
							game->_quest_menu_scroll._last_touch_y = TOUCHS(i)->y;
							game->_quest_menu_scroll.Set();
							game->_quest_menu_scroll.SetState(0);
							game->_quest_menu_scroll._offset_y = 0;
							game->_quest_menu_scroll._isScroll = true;
							game->_quest_menu_scroll._touch_id = TOUCHS(i)->_id;
						}
					}
				}
			}
		}
	}
	return pressed;
}
void CQuest::Modify(int id, int group, int nummax, bool completed, bool daily)
{
	TDGame*game = (TDGame*)GAME()->_current_game;
	int param_name = CGameDesign::FileQuest::CSheetNormal_Quest::Quest_name;
	int param_value = CGameDesign::FileQuest::CSheetNormal_Quest::Value;
	int param_rw_coin = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_coins;
	int param_rw_gem = CGameDesign::FileQuest::CSheetNormal_Quest::Reward_gems;
	int param_type = CGameDesign::FileQuest::CSheetNormal_Quest::Type;
	_has_daily_quest = daily;
	int questindex = game->GetQuestIndex(group, id, _has_daily_quest);

	_quest_group_id = group;
	_quest_id = id;
	_is_completed = completed;
	_num_quest = nummax;
	_scale_text_button_state = EFFECT_SCALE_TEXT_BUTTON_STATE_NOTMAL;
	_scale_text_button = 1.0f;
	_has_touch = false;
	_is_new = false;
	_type = game->GetDesignQuestValue(questindex, param_type, _has_daily_quest);
	_value1 = game->_user.GetQuestCurrentValue(group - 1, game->_user._quest_current[group - 1], _has_daily_quest);
	_reward_coin = 0;
	_reward_gem = 0;
	_reward_coin = game->GetDesignQuestValue(questindex, param_rw_coin, _has_daily_quest);
	_reward_gem = game->GetDesignQuestValue(questindex, param_rw_gem, _has_daily_quest);
	
	_value2 = game->GetDesignQuestValue(questindex, param_value, _has_daily_quest);
	sprintf(_name, "%s", game->GetDesignQuestString(questindex, param_name, _has_daily_quest));
	_button_reward.Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
	_button_reward.SetAnim(SPRITEID_HUD_MAINMENU, 103);
	_button_reward.SetPos(_x, _y);
	int posx = _button_reward.TZ_GetX() + _button_reward.TZ_GetWidth() - 37;
	int posy = _button_reward.TZ_GetY() + _button_reward.TZ_GetHeight() / 2 + 5;
	_notify_reward.Init(SPRITEID_HUD_MAINMENU, -1, 98, posx, posy, 0);
	if (!_is_completed)
	{
		_button_reward.SetState(BUTTON_STATE_LOCK);
	}
	else
	{
		_notify_reward.Active();
	}
	for (int i = 0; i < _num_quest; i++)
	{
		int mk_star_w = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFModuleWidth(114, 0);
		int mw = GET_SPRITE(SPRITEID_HUD_MAINMENU)->GetFrameWidth(58);
		int posx = mk_star_w / 2 + i*(mk_star_w + 4);
		int posy = 42;
		int state = EFFECT_STAR_STATE_NORMAL;
		if (id > i)
		{
			state = EFFECT_STAR_STATE_END;
		}
		_star_list[i].Init(_x - mw / 2 + 146 + posx, _y + posy, state);
	}
	_shake_x = 0;
	_shake_y = 0;
	int param_frameid = CGameDesign::FileSpriteManager::CSheetSprite_Relic::SpriteId;
	int param_bg_frame = CGameDesign::FileSpriteManager::CSheetSprite_Relic::BackgroundID;
	int spriteindex = game->GetDesignQuestSpriteIndex(_name);
	_frameid = game->GetDesignQuestSprite(spriteindex, param_frameid);
	_bg_id = game->GetDesignQuestSprite(spriteindex, param_bg_frame);
	game->ConvertMoneyInbalace(_reward_coin, _reward_coin_text);
	game->ConvertMoneyInbalace(_reward_gem, _reward_gem_text);
	game->ConvertMoneyInbalace(_value1, _value1_text);
	game->ConvertMoneyInbalace(_value2, _value2_text);
}
void CQuest::SetPos(float x, float y)
{
	_x = x;
	_y = y;
	_button_reward.SetPos(_x, _y);
	for (int i = 0; i < _num_quest; i++)
	{
		_star_list[i].SetPos(_star_list[i]._x, _y + 42);
	}
}
void CQuest::Star::Init(float x, float y, int state)
{
	_x = x;
	_y = y;
	_state = state;
	_scale = 1.0f;
	_opac = 100;
	_count_frame_hold = 0;
}
void CQuest::Star::Render(float x, float y, int opac)
{
	
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 114, x + _x, y + _y);
	if (_state > EFFECT_STAR_STATE_NORMAL)
	{
		G()->SetOpacity(_opac);
		G()->SetScale(_scale, _scale, x + _x, y + _y);
		GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 117, x + _x, y + _y);
		G()->ClearScale();
		G()->SetOpacity(opac);
	}
}
void CQuest::Star::Update()
{
	switch (_state)
	{
	case EFFECT_STAR_STATE_NORMAL:
		break;
	case EFFECT_STAR_STATE_START:
		/*if (_scale < 2.0f)
		{
			_scale += 0.15f;
			if (_scale >= 2.0f)
			{
				_state = EFFECT_STAR_STATE_ZOOM_IN;
			}
		}*/
		if (_scale > 0.85f)
		{
			_scale -= 0.75f;
			if (_scale < 0.85f)
			{
				_scale = 0.85f;
				_state = EFFECT_STAR_STATE_HOLD;
			}
		}
		if (_opac < 100)
		{
			_opac += 8;
			if (_opac >= 100)
			{
				_opac = 100;
			}
		}
		break;
	case EFFECT_STAR_STATE_HOLD:
		_count_frame_hold++;
		if (_count_frame_hold >= 10)
		{
			_state = EFFECT_STAR_STATE_ZOOM_IN;
		}
		break;
	case EFFECT_STAR_STATE_ZOOM_IN:
		/*if (_scale > 0.9f)
		{
			_scale -= 0.1f;
			if (_scale <= 0.9f)
			{
				_state = EFFECT_STAR_STATE_ZOOM_OUT;
			}
		}*/
		if (_scale < 1.15f)
		{
			_scale += 0.06f;
			if (_scale > 1.15f)
			{
				_state = EFFECT_STAR_STATE_ZOOM_OUT;
			}
		}
		break;
	case EFFECT_STAR_STATE_ZOOM_OUT:
		/*if (_scale < 1.0f)
		{
			_scale += 0.05f;
			if (_scale >= 1.0f)
			{
				_state = EFFECT_STAR_STATE_END;
			}
		}*/
		if (_scale > 1.0f)
		{
			_scale -= 0.1f;
			if (_scale < 1.0f)
			{
				_scale = 1.0f;
				_state = EFFECT_STAR_STATE_END;
			}
		}
		break;
	case EFFECT_STAR_STATE_END:
		_scale = 1.0f;
		break;
	default:
		break;
	}
}
void CQuest::Star::Active()
{
	_state = EFFECT_STAR_STATE_START;
	_scale = 10.0f;
	_opac = 0;
	_count_frame_hold = 0;
}
void CQuest::Star::SetPos(float x, float y)
{
	_x = x;
	_y = y;
}

void CQuest::Reset()
{
	_quest_group_id = -1;
	_quest_id = -1;
	_is_completed = false;
	_num_quest = 0;
	_x = 0;
	_y = 0;
}
