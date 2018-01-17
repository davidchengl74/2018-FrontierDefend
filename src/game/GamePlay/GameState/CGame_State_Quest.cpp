#include "pch.h"
#include "../../GameCore/CGame.h"

void TDGame::QuestRender(float x, float y, int opac)
{
	G()->SetOpacity(_ingame_menu_fill_opac);
	G()->SetColor(0xff000000);
	G()->FillFullScreen(true);
	G()->SetOpacity(opac);
	GET_SPRITE(SPRITEID_HUD_MAINMENU)->DrawFrame(G(), 112, 0, 0);
	G()->SetClip(0, 44, k_SCREEN_WIDTH, k_SCREEN_HEIGHT - 91);
	for (int i = 0; i < _quest_info_num; i++)
	{
		_quest_info[i].Render(0 + x, y - _quest_menu_scroll.GetCurrent(),opac);
	}
	G()->ClearClip();
	for (int i = 0; i < NUM_BUTTON_QUEST; i++)
	{
		_quest_button[i].Render(G());
		_quest_button[i].Update();
	}
#if defined (ANDROID_OS)
#else
	int spacing = GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_HUD)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH / 2 + x, 25, _HCENTER | _VCENTER, "USER_ID: %s", _user.GetUserID());
	GET_SPRITE(SPRITEID_FONT_HUD)->_char_spacing = spacing;
#endif
	
	G()->SetOpacity(100);
}
void TDGame::QuestUpdate()
{
	if (_sub_state == k_INIT)
	{
		_quest_info_num = 0;
		_open_box_close = false;
		_open_box_fill_opac = 0;
		_main_opac_change_state = 0;
		_ingame_menu_fill_opac = 0;
#if defined (MAC_OS) || defined (ANDROID_OS)
#else
		/*_wave_current = 10;
		_battle_current = 29;*/
		//_user._daily_quest_num = 1000000;
#endif
		for (int i = 0; i < NUM_BUTTON_QUEST; i++)
		{
			_quest_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
			_quest_button[i].SetAnim(SPRITEID_HUD_MAINMENU, 99 + i * 4);
			_quest_button[i].SetPos(0, 0);
		}
		bool quest_completed = _user.CheckQuestCompleted(_user._daily_quest_group_current , _daily_quest_current, true);
		if (!_user._daily_quest_completed && _daily_quest_current < _game_design.Quest.SheetDaily_Quest.int32Value._totalData)
		{
			_quest_info[_quest_info_num].Init(_daily_quest_current, _user._daily_quest_group_current, 1, k_SCREEN_WIDTH / 2, 130, quest_completed, true);
			_quest_info_num++;
		}
		for (int i = 0; i < _num_max_quest; i++)
		{
			int x = k_SCREEN_WIDTH / 2;
			int y = 130 + _quest_info_num * (INGAME_MENU_ITEM_HEIGHT + 5);
			int quest_current = -1;
            if(i == 14)
            {
                continue;
            }
			for (int j = 0; j < NUM_MAX_QUEST_IN_GROUP; j++)
			{
				if (!_user._quest_completed[i][j])
				{
					quest_current = j;
					break;
				}
			}
			
			if (quest_current >= 0)
			{
				int nummax = GetNumOfQuest(i + 1);
				quest_completed = _user.CheckQuestCompleted(i, quest_current,false);
				if (quest_current < nummax && quest_completed)
				{
					_quest_info[_quest_info_num].Init(quest_current, i + 1, nummax, x, y, quest_completed,false);
					_quest_info_num++;
				}
			}
		}
		for (int i = 0; i < _num_max_quest; i++)
		{
			int x = k_SCREEN_WIDTH / 2;
			int y = 130 + _quest_info_num * (INGAME_MENU_ITEM_HEIGHT + 5);
			int quest_current = -1;
            if(i == 14)
            {
                continue;
            }
			for (int j = 0; j < NUM_MAX_QUEST_IN_GROUP; j++)
			{
				if (!_user._quest_completed[i][j])
				{
					quest_current = j;
					break;
				}
			}
			if (quest_current >= 0)
			{
				int nummax = GetNumOfQuest(i + 1);
				quest_completed = _user.CheckQuestCompleted(i, quest_current,false);
				if (quest_current < nummax && !quest_completed)
				{
					_quest_info[_quest_info_num].Init(quest_current, i + 1, nummax, x, y, quest_completed,false);
					_quest_info_num++;
				}
			}
		}
		_quest_menu_scroll.Init(0, _quest_info_num*INGAME_MENU_ITEM_HEIGHT - 6 * INGAME_MENU_ITEM_HEIGHT, 3);
		ArchievementSubmit();
		_sub_state = k_LOOP;
		
		
		
	}
	if (_open_box_close)
	{
		if (_open_box_fill_opac > 0)
		{
			_open_box_fill_opac -= 7;
			if (_open_box_fill_opac <= 0)
			{
				SetState(k_GS_PLAYGAME);
                ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
				_sub_state = k_LOOP;
				ClearAllTouchUp(TOUCH_TYPE_INGAME);
				_main_opac_change_state = 0;
			}
		}
		_main_opac_change_state -= 10;
		_ingame_menu_fill_opac -= 8;
	}
	else
	{
		_open_box_fill_opac += 7;
		if (_open_box_fill_opac >= 85)
		{
			_open_box_fill_opac = 85;
		}
		_main_opac_change_state += 10;
		if (_main_opac_change_state >= 100)
		{
			_main_opac_change_state = 100;
		}
		_ingame_menu_fill_opac += 8;
		if (_ingame_menu_fill_opac > 80)
		{
			_ingame_menu_fill_opac = 80;
		}
	}
	if (!QuestUpdateTouch())
	{
		for (int i = 0; i < _quest_info_num; i++)
		{
			_quest_info[i].Update();
		}
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			int x = 0;
			int y = 0;
			int w = k_SCREEN_WIDTH;
			int h = k_SCREEN_HEIGHT;
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (_quest_menu_scroll._touch_id == -1)
					{
						_quest_menu_scroll._last_touch_y = TOUCHS(i)->y;
						_quest_menu_scroll.Set();
						_quest_menu_scroll.SetState(0);
						_quest_menu_scroll._offset_y = 0;
						_quest_menu_scroll._isScroll = true;
						_quest_menu_scroll._touch_id = TOUCHS(i)->_id;
					}
				}
			}
		}
	}
	if (_quest_menu_scroll._isScroll)
	{
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			int x = 0;
			int y = 0;
			int w = k_SCREEN_WIDTH;
			int h = k_SCREEN_HEIGHT;
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DRAG)
				{
					if (_quest_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						float deltaY = TOUCHS(i)->y - _quest_menu_scroll._last_touch_y;
						_quest_menu_scroll._last_touch_y = TOUCHS(i)->y;
						_quest_menu_scroll.AddOffset(-deltaY);
						_quest_menu_scroll.ValidateRangeExt();
						_quest_menu_scroll.ForceToTarget();
						_quest_menu_scroll.SetState(1);
						if (_quest_menu_scroll._offset_y < CMath::ABSOLUTE_VALUE(deltaY))
						{
							_quest_menu_scroll._offset_y = CMath::ABSOLUTE_VALUE(deltaY);
						}
					}
				}
				else if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_quest_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						if (_quest_menu_scroll._offset_y > 2)
						{
							_quest_menu_scroll._offset_y = 0;
						}
						if (!_quest_menu_scroll._collided)
						{
							_quest_menu_scroll.End();
						}
						_quest_menu_scroll.SetState(2);
						_quest_menu_scroll._isScroll = false;
						_quest_menu_scroll._touch_id = -1;
					}
				}
			}
			else
			{
				if (TOUCHS(i)->_state == TOUCH_UP)
				{
					if (_quest_menu_scroll._touch_id == TOUCHS(i)->_id)
					{
						if (_quest_menu_scroll._offset_y > 2)
						{
							_quest_menu_scroll._offset_y = 0;
						}
						if (!_quest_menu_scroll._collided)
						{
							_quest_menu_scroll.End();
						}
						_quest_menu_scroll.SetState(2);
						_quest_menu_scroll._isScroll = false;
						_quest_menu_scroll._touch_id = -1;
					}
				}
			}
		}
	}
	else
	{
		for (int i = GAME()->_num_touches - 1; i >= 0; i--)
		{
			int x = 0;
			int y = 0;
			int w = 0;
			int h = 0;
			x = _point_o.X;
			y = _point_o.Y;
			w = CMath::ABSOLUTE_VALUE(_point_o.X);
			h = _screen_height;
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					_open_box_close = true;
				}
			}
			x = k_SCREEN_WIDTH;
			y = _point_o.Y;
			w = CMath::ABSOLUTE_VALUE(_point_o.X);
			h = _screen_height;
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					_open_box_close = true;
				}
			}
		}
	}
	_quest_menu_scroll.Update();
}
bool TDGame::QuestUpdateTouch()
{
#if !defined (MAC_OS)
	if (GAME()->_isBackkeyPress)
	{
		_open_box_close = true;
		GAME()->_isBackkeyPress = false;
		return true;
	}
#endif
	bool ret = false;
	int index = -1;
	for (int i = 0; i < NUM_BUTTON_QUEST; i++)
	{
		if (_quest_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_quest_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case QUEST_BUTTON_CLOSE:
				_open_box_close = true;
				
				break;
			default:
				break;
			}
			for (int i = 0; i < NUM_BUTTON_QUEST; i++)
			{
				if (_quest_button[i]._state != BUTTON_STATE_LOCK && _quest_button[i]._state != BUTTON_STATE_HIDE)
				{
					_quest_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < NUM_BUTTON_QUEST; touch++)
		{
			if (_quest_button[touch]._state == BUTTON_STATE_LOCK || _quest_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _quest_button[touch].TZ_GetX() - 30;
			int y = _quest_button[touch].TZ_GetY() - 20;
			int w = _quest_button[touch].TZ_GetWidth() + 50;
			int h = _quest_button[touch].TZ_GetHeight() + 50;
			Button *button = &_quest_button[touch];
			if (CHECK_POINT_IN_RECT(TOUCHS(i)->x, TOUCHS(i)->y, x, y, w, h))
			{
				if (TOUCHS(i)->_state == TOUCH_DOWN)
				{
					if (button->_touch_id == -1)
					{
						//printf("\n touch = %d", touch);
						button->SetState(BUTTON_STATE_SELECT);
						button->_touch_id = TOUCHS(i)->_id;
						GAME()->PlaySFX(SFX_BUTTON);
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
				}
			}
		}
	}
	return pressed;
}

void TDGame::QuestRemoveIndex(int group, bool daily)
{
	int index = -1;
	if (daily)
	{
		if (_quest_info[0]._has_daily_quest)
		{
			_quest_info[0]._has_daily_quest = false;
			
			for (int i = 0; i < _quest_info_num - 1; i++)
			{
				_quest_info[i].Modify(_quest_info[i + 1]._quest_id, _quest_info[i + 1]._quest_group_id, _quest_info[i + 1]._num_quest, _quest_info[i + 1]._is_completed, _quest_info[i + 1]._has_daily_quest);
			}
			_quest_info_num--;
		}
	}
	else
	{
		for (int i = 0; i < _quest_info_num; i++)
		{
			if (!_quest_info[i]._has_daily_quest)
			{
				if (_quest_info[i]._quest_group_id == group)
				{
					index = i;
				}
			}
		}
		for (int i = index; i < _quest_info_num - 1; i++)
		{
			_quest_info[i].Modify(_quest_info[i + 1]._quest_id, _quest_info[i + 1]._quest_group_id, _quest_info[i + 1]._num_quest, _quest_info[i + 1]._is_completed, _quest_info[i + 1]._has_daily_quest);
		}
		_quest_info_num--;
	}
}

void TDGame::DailyQuestAdd(int group)
{
	if (group == _user._daily_quest_group_current)
	{
		_user._daily_quest_num++;
	}
}
void TDGame::QuestReset()
{
	for (int i = 0; i < _num_max_quest; i++)
	{
		_quest_info[i].Reset();
	}
	_quest_info_num = 0;
}
