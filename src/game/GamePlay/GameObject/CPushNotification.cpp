#include "pch.h"
#include "../../GameCore/CGame.h"
#include "../../GameCore/Os_Functions.h"

void CPushNotification::AddNotification(BYTE type)
{
    TDGame*game = (TDGame*)(GAME()->_current_game);
    INT_TIME time = 0;
	bool addPush = false;
	switch (type)
	{
	case CPushNotification::NOTIFICATION_WHEEL_READY:
            time = game->_wheel_time.GetTotalSecond();
            if(time > 0 && game->_user._tutorial_completed)
            {
                addPush = true;
                sprintf(_notifiction[_numNotification]._text, "Your daily reward is ready to collect!");
				time += 60;
            }
#if defined (ANDROID_OS)
			OS_SetLocalNotification(0, "Your daily reward is ready to collect!", "Your daily reward is ready to collect!", time);
#endif
		break;
        case CPushNotification::NOTIFICATION_COME_BACK_1DAYS:
            time = 1*24*60*60;
            addPush = true;
            sprintf(_notifiction[_numNotification]._text, "Your daily reward is ready to collect!");
			time += 60;
#if defined (ANDROID_OS)
			OS_SetLocalNotification(1, "Your daily reward is ready to collect!", "Your daily reward is ready to collect!", time);
#endif
            break;
        case CPushNotification::NOTIFICATION_COME_BACK_2DAYS:
            time = 2*24*60*60;
            addPush = true;
            sprintf(_notifiction[_numNotification]._text, "Your daily reward is ready to collect!");
			time += 60;
#if defined (ANDROID_OS)
			OS_SetLocalNotification(2, "Your daily reward is ready to collect!", "Your daily reward is ready to collect!", time);
#endif
            break;
		case CPushNotification::NOTIFICATION_COME_BACK_5DAYS:
			time = 5 * 24 * 60 * 60;
			addPush = true;
			sprintf(_notifiction[_numNotification]._text, "Your daily reward is ready to collect!");
			time += 60;
#if defined (ANDROID_OS)
			OS_SetLocalNotification(3, "Your daily reward is ready to collect!", "Your daily reward is ready to collect!", time);
#endif
            break;
		case CPushNotification::NOTIFICATION_COME_BACK_10DAYS:
			time = 10 * 24 * 60 * 60;
			addPush = true;
			sprintf(_notifiction[_numNotification]._text, "Your daily reward is ready to collect!");
			time += 60;
#if defined (ANDROID_OS)
			OS_SetLocalNotification(4, "Your daily reward is ready to collect!", "Your daily reward is ready to collect!", time);
#endif
			break;
	}
	if (addPush)
	{
		_notifiction[_numNotification]._type = type;
		_notifiction[_numNotification]._timePush = time;
		//printf("\n Notification[%d]: %lld => %s -- type = %d", _numNotification, _notifiction[_numNotification]._timePush, _notifiction[_numNotification]._text,_notifiction[_numNotification]._type);
		_numNotification++;
	}	
}
bool CPushNotification::HasNotification(BYTE type)
{
	for (int i = 0; i < _numNotification; i++)
	{
		if (_notifiction[i]._type == type)
		{
			return true;
		}
	}
	return false;
}
INT_TIME CPushNotification::GetMaxTimePush(BYTE type)
{
	INT_TIME max = 0;
	for (int i = 0; i < _numNotification; i++)
	{
		if (_notifiction[i]._type == type)
		{
			if (max < _notifiction[i]._timePush)
			{
				max = _notifiction[i]._timePush;
			}
		}
	}
	return max;
}
void CPushNotification::PushNotification()
{
	_numNotification = 0;
	AddNotification(CPushNotification::NOTIFICATION_WHEEL_READY);
    AddNotification(CPushNotification::NOTIFICATION_COME_BACK_1DAYS);
    AddNotification(CPushNotification::NOTIFICATION_COME_BACK_2DAYS);
	AddNotification(CPushNotification::NOTIFICATION_COME_BACK_5DAYS);
	AddNotification(CPushNotification::NOTIFICATION_COME_BACK_10DAYS);
}

void CPushNotification::Reset()
{
    for (int i = 0; i < _numNotification; i++)
    {
        _notifiction[i]._timePush = 0;
        //_notifiction[i]._type = -1;
    }
    _numNotification = 0;
}
