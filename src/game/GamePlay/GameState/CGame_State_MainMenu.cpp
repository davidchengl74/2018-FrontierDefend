#include "pch.h"
#include "../../GameCore/CGame.h"
extern "C" void OS_SetAdboxActive(bool isThread);
extern "C" void ServerADVERTStart();
void TDGame::MainMenuRender(float x, float y, int opac)
{
	G()->SetOpacity(opac);
	G()->SetScale(GAME()->_game_context.ScaleOut, GAME()->_game_context.ScaleOut, k_SCREEN_WIDTH / 2, k_SCREEN_HEIGHT / 2);
	GET_SPRITE(SPRITEID_HUD_SPLASH_SCREEN_01)->DrawFrame(G(), 0, x, y);
	G()->ClearScale();
	_anim_logo.DrawAnimObject(G());
	_anim_logo.UpdateAnimObject();
	if (_anim_logo.IsCurrentAnimStop())
	{
		_anim_logo.SetAnim(5, true);
	}
	for (int i = 0; i < MAIN_MENU_NUM_BUTTON; i++)
	{
		if (_mainmenu_button[i]._state != BUTTON_STATE_HIDE)
		{
			_mainmenu_button[i].Render(G());
		}
		_mainmenu_button[i].Update();
	}
	G()->SetOpacity(100);
}
void TDGame::MainMenuUpdate()
{
	if (_sub_state == k_INIT)
	{
        //text code begin
        ///char text[256];
        ///sprintf(text, "%s", "Do you want us to notify when the Wheel is ready?");
        ///_dialogMng.Add(DIALOG_CONTEXT_CONFIRM_NOTIFY, DIALOGTYPE_YESNO, ZOOM_IN_OUT_TRANSACTION, "", text, 0, 0);
       
        ///test code end

#ifdef MAC_OS
        OS_SetAdboxActive(true);
#endif
		_mainmenu_just_in = true;
		_main_opac_change_state = 0;
		for (int i = 0; i < MAIN_MENU_NUM_BUTTON; i++)
		{
			_mainmenu_button[i].Init(BUTTON_STATE_NORMAL, 0, 0, A_HVCENTER, 0);
			_mainmenu_button[i].SetAnim(SPRITEID_HUD_SPLASH_SCREEN_01, i * 4);
			_mainmenu_button[i].SetPos(0, 0);
		}
		if (_bg_music_current == -1)
		{
			_bg_change_music = false;
			_bg_music_current = BGM_BATTLE_2;//CMath::RANDOM(BGM_BATTLE_1, BGM_BATTLE_3);
			GAME()->StopCurrentMusic();
			//GAME()->LoadMusic(_bg_music_current);
		}
		if (GAME()->_musicEnable)
		{
            GAME()->LoadMusic(_bg_music_current);
			GAME()->PlayCurrentMusic(-1);
		}
		_anim_logo.SetAnimSprite(GET_SPRITE(SPRITEID_HUD_SPLASH_SCREEN_01), SPRITEID_HUD_SPLASH_SCREEN_01);
		_anim_logo.SetAnim(4, false);
		_anim_logo.SetPos(0, 0);
		_sub_state = k_LOOP;
		if (_user._tutorial_completed)
		{
			_time_showads_count = 0;
		}
		else
		{
			_time_showads_count = TIME_SHOWADS_ARCHIVE * 60;
		}
		
#if GAME_SUPPORT
#if !SUPPORT_CHECK_SAVE
#if !SUPPOR_IS_READ
        if(SUPPORT_COIN > 0)
        {
            _user.SetCoin(SUPPORT_COIN);
        }
        if(SUPPORT_GEM > 0)
        {
            _user.SetGem(SUPPORT_GEM);
        }
        
        if(SUPPORT_BATTLE >= 0)
        {
            _battle_current = SUPPORT_BATTLE;
        }
        
        if(SUPPORT_HERO_ID >= 0)
        {
            //printf("\n SUPPORT_HERO_ID: %d",SUPPORT_HERO_ID);
            UnlockNewHero(SUPPORT_HERO_ID);
        }
        if(SUPPORT_RELIC_ID >= 0)
        {
            
        }
        if(SUPPORT_COIN_COLLECTED > 0)
        {
            _user._quest_num_coin_collected+=SUPPORT_COIN_COLLECTED;
        }
        _user._quest_num_coin_collected+=1;
        _user.UserDataSave();
#endif
#endif
#endif
        //cheat test build
/*if(_battle_current < NUM_MAX_BATTLE_VERSION_1 && _user._tutorial_completed)
{
    _battle_current = NUM_MAX_BATTLE_VERSION_1;
    _user.AddCoin(30000000, true);
    _user.AddGem(500);
}*/
        /*_user.AddCoin(20000000, true);
        _user.UserDataSave();*/
        //end cheat
	}
    /*if(_user._tutorial_completed)
    {
        if(!_user.CheckHeroColleted(HERO_ID_SANTA))
        {
            _user.AddGem(5000);
            _user.AddCoin(20000000, true);
            _user.UserDataSave();
			UnlockNewHero(HEROES_UNLOCK_TYPE_EVENT_XMAS);
        }
    }*/
	MainMenuUpdateTouch();
}
bool TDGame::MainMenuUpdateTouch()
{
	bool ret = false;
	int index = -1;
	for (int i = 0; i < MAIN_MENU_NUM_BUTTON; i++)
	{
		if (_mainmenu_button[i]._state == BUTTON_STATE_ACTIVE)
		{
			ret = true;
			index = i;
			break;
		}
	}
	if (ret)
	{
		if (_mainmenu_button[index].NeedAction())
		{
			//printf("\n index = %d ", index);
			switch (index)
			{
			case MAIN_MENU_BUTTON_START:
			{
#ifdef MAC_OS
#if ADD_ADVERT
                ServerADVERTStart();
#endif
#endif
				SetState(k_GS_PLAYGAME);
                ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
				_user._watch_ad_time = time(NULL) + _time_waiting_free_gift*0.6f;
				//_watch_ads_time.setDateBYSecond(_user._watch_ad_time - time(NULL));
			}
				break;
			default:
				break;
			}

			for (int i = 0; i < MAIN_MENU_NUM_BUTTON; i++)
			{
				if (_mainmenu_button[i]._state != BUTTON_STATE_LOCK && _mainmenu_button[i]._state != BUTTON_STATE_HIDE)
				{
					_mainmenu_button[i].SetState(BUTTON_STATE_NORMAL);
				}
			}
			return true;
		}
	}
	bool pressed = false;
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		for (int touch = 0; touch < MAIN_MENU_NUM_BUTTON; touch++)
		{
			if (_mainmenu_button[touch]._state == BUTTON_STATE_LOCK || _mainmenu_button[touch]._state == BUTTON_STATE_HIDE)
			{
				continue;
			}
			int x = _mainmenu_button[touch].TZ_GetX();
			int y = _mainmenu_button[touch].TZ_GetY();
			int w = _mainmenu_button[touch].TZ_GetWidth();
			int h = _mainmenu_button[touch].TZ_GetHeight();
			Button *button = &_mainmenu_button[touch];
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
