#include "pch.h"
#include "../../GameCore/CGame.h"

void TDGame::GameOverRender(float x, float y, int opac)
{
	G()->SetOpacity(_gameover_fill_opac*0.8f);
	G()->SetColor(0xff000000);
	G()->FillFullScreen(true);
	G()->SetOpacity(opac);
	G()->SetRotate(_gameover_defeat_rotate, k_SCREEN_WIDTH / 2 - 40, y + _gameover_defeat_posy);
	GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02)->DrawFrame(G(), 0, x + k_SCREEN_WIDTH / 2 - 40, y + _gameover_defeat_posy);
	G()->ClearRotate();
	_gameover_character1.SetPos(_gameover_character_posx1  + x, _gameover_character_posy + y);
	G()->SetScale(1.5f, 1.5f, _gameover_character_posx1 + x, _gameover_character_posy + y);
	_gameover_character1.DrawAnimObject(G());
	G()->ClearScale();
	_gameover_character1.UpdateAnimObject();
	_gameover_character2.SetPos(_gameover_character_posx2 + x - 40, _gameover_character_posy + y);
	if (_gameover_character2.GetCurrentAnim()!= 0)
	{
		G()->SetScale(1.5f, 1.5f, _gameover_character_posx2 + x - 40, _gameover_character_posy + y);
	}
	_gameover_character2.DrawAnimObject(G());
	G()->ClearScale();
	_gameover_character2.UpdateAnimObject();
	if (_gameover_character2.GetCurrentAnim() == 0)
	{
		/*_gameover_defeat_smoke.SetPos(_gameover_character_posx2 + x - 20, _gameover_character_posy + y);
		_gameover_defeat_smoke.DrawAnimObject(G());
		_gameover_defeat_smoke.UpdateAnimObject();*/
		int mx = GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02)->GetFModuleCenterX(0, 1);
		int my = GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02)->GetFModuleCenterY(0, 1);
		_gameover_defeat_smoke_left.SetPos(_gameover_character_posx2 + x - 20, _gameover_character_posy + y);
		_gameover_defeat_smoke_left.DrawAnimObject(G());
		_gameover_defeat_smoke_left.UpdateAnimObject();
		mx = GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02)->GetFModuleCenterX(0, 2);
		my = GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02)->GetFModuleCenterY(0, 2);
		_gameover_defeat_smoke_right.SetPos(_gameover_character_posx2 + x - 20, _gameover_character_posy + y);
		_gameover_defeat_smoke_right.DrawAnimObject(G());
		_gameover_defeat_smoke_right.UpdateAnimObject();
	}
	G()->SetOpacity(_gameover_touch_opac);
    ItemsRender(-_shake_effectx, -_shake_effecty);
	int spacing = GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = 2;
	GET_SPRITE(SPRITEID_FONT_BATTLE)->DrawAnsiTextFormat(G(), k_SCREEN_WIDTH/2, 7*k_SCREEN_HEIGHT/10, _HCENTER, "Tap to retry");
	GET_SPRITE(SPRITEID_FONT_BATTLE)->_char_spacing = spacing;
	G()->SetOpacity(opac);
	G()->SetOpacity(_gameover_change_state_opac);
	G()->SetColor(0xffffffff);
	G()->FillFullScreen(true);
	G()->SetOpacity(100);
}
void TDGame::GameOverUpdate()
{
	if (_sub_state == k_INIT)
	{
		_just_lose = true;
		_gameover_touch_id = -1;
		_gameover_close = false;
		_gameover_state = GAME_OVER_STATE_INIT;
		_gameover_defeat_rotate_speed = 0/*CMath::RANDOM(0,1)*2 - 1*/;
		_gameover_change_state_opac = 0;
		_gameover_defeat_posy = -200;
		_gameover_defeat_rotate = 0;
		_gameover_defeat_rotate_frame_speed = 90;
		_gameover_character_posx1 = -100 + _point_o.X;
		_gameover_character_posx2 = -k_SCREEN_WIDTH / 2 + _point_o.X;
		_gameover_fill_opac = 0;
		_gameover_touch_opac = 0;
		_gameover_defeat_posy_scrollback = 0.0f;
		_gameover_character_posy = k_SCREEN_HEIGHT/2;
		LoadSpriteOptimize(SPRITEID_MONSTER_THIEF_01,false,false);
		LoadSpriteOptimize(SPRITEID_HERO_SWORDSMAN_01,false,false);
		_gameover_character1.SetAnimSprite(GET_SPRITE(SPRITEID_MONSTER_THIEF_01), SPRITEID_MONSTER_THIEF_01);
		_gameover_character1.SetAnim(12,true);
		_gameover_character1.SetPos(_gameover_character_posx1 , _gameover_character_posy);
		_gameover_character2.SetAnimSprite(GET_SPRITE(SPRITEID_HERO_SWORDSMAN_01), SPRITEID_HERO_SWORDSMAN_01);
		_gameover_character2.SetAnim(HERO_ANIM_RUN ,true);
		_gameover_character2.SetPos(_gameover_character_posx2 , _gameover_character_posy);

		_gameover_defeat_smoke.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_LEVELUP_CASTLE_01), SPRITEID_EFFECT_LEVELUP_CASTLE_01);
		_gameover_defeat_smoke.SetAnim(0, false);
		_gameover_defeat_smoke.SetPos(0, 0);

		_gameover_defeat_smoke_left.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02), SPRITEID_EFFECT_DEFEAT_CASTLE_02);
		_gameover_defeat_smoke_left.SetAnim(2, false);
		_gameover_defeat_smoke_left.SetPos(0, 0);
		_gameover_defeat_smoke_right.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02), SPRITEID_EFFECT_DEFEAT_CASTLE_02);
		_gameover_defeat_smoke_right.SetAnim(1, false);
		_gameover_defeat_smoke_right.SetPos(0, 0);

		_gameover_anim_castle_die_stone.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_01), SPRITEID_EFFECT_DEFEAT_CASTLE_01);
		_gameover_anim_castle_die_stone.SetAnim(CMath::RANDOM(0,1), false);
		_gameover_anim_castle_die_stone.SetPos(125 + _point_o.X, 450 + CMath::RANDOM(0, 10) * 5 + _point_o.Y);
		_gameover_anim_castle_die_stone1.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_01), SPRITEID_EFFECT_DEFEAT_CASTLE_01);
		_gameover_anim_castle_die_stone1.SetAnim(CMath::RANDOM(0, 1), false);
		_gameover_anim_castle_die_stone1.SetPos(125 + _point_o.X, 450 + CMath::RANDOM(0, 10) * 5 + _point_o.Y);
		
		_gameover_anim_castle_die_smoke.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_01), SPRITEID_EFFECT_DEFEAT_CASTLE_01);
		_gameover_anim_castle_die_smoke.SetAnim(2, true);
		_gameover_anim_castle_die_smoke.SetPos(40 + _point_o.X, 605 + _point_o.Y);
		_gameover_anim_castle_die_smoke1.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_01), SPRITEID_EFFECT_DEFEAT_CASTLE_01);
		_gameover_anim_castle_die_smoke1.SetAnim(2, true);
		_gameover_anim_castle_die_smoke1.SetPos(130 + _point_o.X, 590 + _point_o.Y);
		_gameover_anim_castle_die_smoke2.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_01), SPRITEID_EFFECT_DEFEAT_CASTLE_01);
		_gameover_anim_castle_die_smoke2.SetAnim(2, true);
		_gameover_anim_castle_die_smoke2.SetPos(230 + _point_o.X, 580 + _point_o.Y);
		_gameover_frame_render_anim = 0;
		_effect_castle_die_scrolly = 1.0f;
		ItemForceEnd();
		_user._play_times_retry++;
		_sub_state = k_LOOP;
		GAME()->PlaySFX(SFX_GATE_DOWN);
        _count_times_showAds++;
	}
	if (_gameover_state > GAME_OVER_STATE_INIT)
	{
		if (_gameover_character_posx1 < 2 * k_SCREEN_WIDTH)
		{
			_gameover_character_posx1 += 3;
			if (_gameover_character_posx2 >= 180 + _point_o.X)
			{
				_gameover_character_posx1 += 8;
				if (_gameover_character1.GetCurrentAnim() == 12)
				{
					_gameover_character1.SetAnim(13, true);
				}
			}
		}
		if (_gameover_character_posx2 >= 200 + _point_o.X)
		{
			_gameover_character_posx2 += 3;
		}
	}
	if (_gameover_frame_render_anim < 500)
	{
		_gameover_frame_render_anim++;
	}
	ItemsUpdate();
#if ADD_ADVERT
    if (GAME()->_advert.HasPopup())
    {
        return;
    }
#endif
    switch (_gameover_state)
	{
	case GAME_OVER_STATE_INIT:
		if (_effect_castle_die_scrolly >= k_SCREEN_HEIGHT/2)
		{
			if (_gameover_fill_opac<100)
			{
				_gameover_fill_opac += 10;
				if (_gameover_fill_opac >= 100)
				{
					_gameover_fill_opac = 100;
					if (_wave_current >= 10)
					{
						if (!ReviveActive())
						{
							_gameover_state = GAME_OVER_STATE_RUN;
						}
					}
					else
					{
						_gameover_state = GAME_OVER_STATE_RUN;
					}
				}
			}
		}
		else
		{
			_effect_castle_die_scrolly *= 1.04f;
			_effect_castle_die_shakex = CMath::RANDOM(-4, 4);
			_effect_castle_die_shakey = CMath::RANDOM(-4, 4);
		}
		
		break;
	case GAME_OVER_STATE_RUN:
		if (_gameover_character_posx2 < k_SCREEN_WIDTH/2)
		{
			_gameover_character_posx2 += 5;
		}
		if (_gameover_character_posx2 >= k_SCREEN_WIDTH/2 - 130)
		{
			_gameover_state = GAME_OVER_STATE_DEFEAT;
		}
		break;
	case GAME_OVER_STATE_DEFEAT:
		if (_gameover_character_posx2 < k_SCREEN_WIDTH / 2)
		{
			_gameover_character_posx2 += 5;
		}
		if (_gameover_character_posx2 >= k_SCREEN_WIDTH / 2)
		{
			_gameover_character_posx2 = k_SCREEN_WIDTH / 2;
		}
		if (_gameover_defeat_posy < k_SCREEN_HEIGHT/2)
		{
			if (_gameover_defeat_posy_scrollback == 0)
			{
				_gameover_defeat_posy += 40;
			}
			_gameover_defeat_rotate += _gameover_defeat_rotate_speed;
		}
		if (_gameover_defeat_posy >= k_SCREEN_HEIGHT / 2 && _gameover_defeat_posy_scrollback == 0.0f)
		{
			_gameover_defeat_posy = k_SCREEN_HEIGHT / 2;
			_gameover_defeat_posy_scrollback = 5.0f;
			//_gameover_defeat_rotate -= 10;
			_gameover_defeat_rotate_speed = CMath::RANDOM(0, 1) - 0.5;
			_gameover_character2.SetAnimSprite(GET_SPRITE(SPRITEID_EFFECT_DEFEAT_CASTLE_02), SPRITEID_EFFECT_DEFEAT_CASTLE_02);
			_gameover_character2.SetAnim(0, true);
			_gameover_character2.SetPos(_gameover_character_posx2 - k_SCREEN_WIDTH / 2 - 100, _gameover_character_posy);
			GAME()->PlaySFX(SFX_DEFEAT_DIE);
		}
		if (_gameover_defeat_posy_scrollback > 0)
		{
			_gameover_defeat_posy_scrollback -= 0.4f;
			_gameover_defeat_posy -= _gameover_defeat_posy_scrollback;
		}
		if (_gameover_defeat_posy_scrollback < 0)
		{
			_gameover_defeat_posy_scrollback = 0;
			_gameover_state = GAME_OVER_STATE_HOLD;
			
			
        }
		break;
	case GAME_OVER_STATE_HOLD:
		if (_gameover_character_posx2 < k_SCREEN_WIDTH / 2)
		{
			_gameover_character_posx2 += 5;
		}
		if (_gameover_character_posx2 >= k_SCREEN_WIDTH / 2)
		{
			_gameover_character_posx2 = k_SCREEN_WIDTH / 2;
		}
		if (_gameover_defeat_posy_scrollback < 10)
		{
			_gameover_defeat_posy_scrollback += 0.4f;
			_gameover_defeat_rotate += _gameover_defeat_rotate_speed;
		}
		_gameover_defeat_posy += _gameover_defeat_posy_scrollback;
		if (_gameover_defeat_posy >= k_SCREEN_HEIGHT / 2 )
		{
			_gameover_defeat_posy = k_SCREEN_HEIGHT / 2;
			_gameover_defeat_rotate = 0;
		}
		_gameover_defeat_rotate_frame_speed++;
		if (_gameover_defeat_rotate_frame_speed >= 90)
		{
			if (_gameover_defeat_rotate_frame_speed %2 == 0)
			{
				_gameover_defeat_rotate = CMath::RANDOM(-2, 3);
			}
			if (_gameover_defeat_rotate_frame_speed >= 160)
			{
				//_gameover_defeat_rotate_frame_speed = -CMath::RANDOM(30,90);
				_gameover_defeat_rotate = 0;
			}
		}
		else
		{
			_gameover_defeat_rotate = 0;
		}
		_gameover_touch_opac += 5;
		if (_gameover_touch_opac>=100)
		{
			_gameover_touch_opac = 100;
		}
		break;
	case GAME_OVER_STATE_END:
		if (_gameover_character_posx2 >= k_SCREEN_WIDTH / 2)
		{
			_gameover_character_posx2 = k_SCREEN_WIDTH / 2;
		}
		if (_gameover_change_state_opac < 100)
		{
			_gameover_change_state_opac += 8;
			if (_gameover_change_state_opac >= 100)
			{
				_gameover_change_state_opac = 100;
				SetState(k_GS_PLAYGAME);
                ClearAllTouchUp(TOUCH_TYPE_FREE_GIFT);
				ClearAllTouchUp(TOUCH_TYPE_INGAME);
				if (_user._tutorial_step == TUTORIAL_STEP_MENU_RELIC)
				{
					if (_battle_current >= 9)
					{
						_tutorial_buy_relic_ready = true;

					}
				}
			}
		}
		break;
	default:
		break;
	}
	GameOverUpdateTouch();
}
bool TDGame::GameOverUpdateTouch()
{
    bool ret = false;
	
	if (_has_watched_ads &&
#if defined (ANDROID_OS)
		GAME()->_on_video_ads_reward)
#else
		PineAdBox::showAdState == SHOW_AD_COMPLETED)
#endif
	{
		PineAdBox::showAdState = SHOW_AD_NONE;
		_gameover_state = GAME_OVER_STATE_END;
		_has_watched_ads = false;

#if defined (ANDROID_OS)
		PDEBUG("On double reward");
		GAME()->_on_video_ads_reward = false;
#endif

	}
	else if (_has_watched_ads &&
#if defined (ANDROID_OS)
		!GAME()->_is_waiting_for_reward && !GAME()->_on_video_ads_reward)
#else
		PineAdBox::showAdState == SHOW_AD_CANCEL)
#endif
	{
		PDEBUG("Set watched ads to false");
		_has_watched_ads = false;
	}
	if (_dialogMng.isOpenDialog() || _has_watched_ads)
	{
		return ret;
	}
	for (int i = GAME()->_num_touches - 1; i >= 0; i--)
	{
		if (TOUCHS(i)->_state == TOUCH_DOWN)
		{
			if (_gameover_touch_id == -1 && _gameover_state >= GAME_OVER_STATE_HOLD)
			{
				_has_revive_in_battle = false;
				_gameover_state = GAME_OVER_STATE_END;
				_gameover_touch_id = TOUCHS(i)->_id;
				ret = true;
			}
		}
	}
	return ret;
}
