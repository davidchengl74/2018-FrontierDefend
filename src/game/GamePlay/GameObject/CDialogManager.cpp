#include "pch.h"
#include "CDialogManager.h"
#include "../../GameCore/CGame.h"
void CDialogManager::Update()
{
	for (int i = 0; i < MAX_DIALOG_NUMS; i++)
	{
		if (_dialog[i].GetState() != STATE_NOTUSE)
		{
			_dialog[i].Update();
		}
	}
}
void CDialogManager::Render(float x, float y)
{
	
	for (int i = 0; i < MAX_DIALOG_NUMS; i++)
	{
		if (_dialog[i].GetState() != STATE_NOTUSE)
		{
			if (_dialog[i].GetState() == STATE_CLOSE)
			{
				if (_dialog[i]._main_opac > 0)
				{
					_dialog[i]._main_opac -= 5;
				}
				else
				{
					_dialog[i]._main_opac = 0;
				}
			}
			else
			{
				if (_dialog[i]._main_opac < 70)
				{
					_dialog[i]._main_opac += 5;
				}
				else
				{
					_dialog[i]._main_opac = 70;
				}
			}
			
			G()->SetOpacity(_dialog[i]._main_opac);
			G()->SetColor(0xff000000);
			G()->FillFullScreen(true);
			G()->SetOpacity(100);
			_dialog[i].Render(x,y);
		}
	}
}
void CDialogManager::Add(int context, int type, int typetransaction, const char* title, const char* body, float x, float y)
{
	TDGame *game = (TDGame*)GAME()->_current_game;
	game->_dialog_process_type = -1;
	_opac = 0;
	for (int i = 0; i < MAX_DIALOG_NUMS; i++)
	{
		if (_dialog[i].GetState() == STATE_NOTUSE)
		{
			_dialog[i].Init(context, type, typetransaction, title, body, x, y);
			break;
		}
	}
}
bool CDialogManager::isOpenDialog()
{
	for (int i = 0; i < MAX_DIALOG_NUMS; i++)
	{
		if (_dialog[i].GetState() != STATE_NOTUSE)
		{
			return true;
		}
	}
	return false;
}