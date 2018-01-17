#include "pch.h"
#include "../../GameCore/CGame.h"

extern "C" bool OS_IsLogginFacebook();

#if defined (_WINDOWS_PHONE8) || defined(_WIN8) || defined(ANDROID_OS)
extern "C" void getUniqueIDForDevice(char * uid);
extern "C" int AsynCheckAccountServer(PineServiceHandle* handle, const char* account_id);
extern "C" void AsynCreateNewAccount(PineServiceHandle* handle);
extern "C" void OS_AsynGetAvatarURLFB(PineServiceHandle* handle, PineAccountInfo* acc_info);
extern "C" void AsynSyncSaveFromServer(PineServiceHandle* handle);
extern "C" void AsynSyncSaveToServer(PineServiceHandle* handle);
extern "C" void DownloadAvatar(PineServiceHandle* handle,const char* url, const char *filename, float w, float h);
#else
extern "C" int GetServerSaveStatus();
extern "C" bool SynSaveFromServer();
extern "C" void SynSaveToServer();
extern "C" void OS_DeleteFile(const char *file_name);
extern "C" void getUniqueIDForDevice(char * uid);
extern "C" bool SetServerTime(Pine_Date_Time &time);
extern "C" bool checkServerRealIsAble();
#endif
extern "C" bool GetInvitedId(char *invitedId);
extern "C" bool GetInvitionFriends();
extern "C" int InputInvitetionCode(char *inviteCode);
bool CServerThread::AddCommand(enumTypeCommand typeCommand)
{
  
	for (int i = 0; i < MAX_COMMAND_IN_THREAD; i++)
	{
		if (_command[i]._stateCommand == enumStateCommand::COMMAND_STATE_NONE)
		{
			_command[i]._stateCommand = enumStateCommand::COMMAND_STATE_INIT;
			_command[i]._typeCommand = typeCommand;
			return true;
		}
	}

	return false;
}

bool CServerThread::AlreadyHasCommand(enumTypeCommand typeCommand)
{
    for (int i = 0; i < MAX_COMMAND_IN_THREAD; i++)
    {
        if (_command[i]._typeCommand == typeCommand)
        {
            return true;
        }
    }
    return false;
}

void CServerThread::ClearAllCommand()
{
    return;
   for (int i = 0; i < MAX_COMMAND_IN_THREAD; i++)
   {
       _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_NONE;
       _command[i]._typeCommand = enumTypeCommand::COMMAND_TYPE_NONE;
   }
}

void CServerThread::EndCommand(int i)
{
	_command[i]._typeCommand = enumTypeCommand::COMMAND_TYPE_NONE;
    _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_NONE;
	
}

bool CServerThread::IsSynSaveComplete()
{
    if (_isNetworkAvailable)
    {
        if (_isSynSaveComplete)
        {
            return true;
        }
    }
    return false;
}

bool CServerThread::IsLoadAllFriendCompelete()
{
	if (!_isInitGC || !_isInitFB)
	{
		return false;
	}
    if (_isInitGC && !_isLoadFriendGCComplete)
    {
        return false;
    }
    
    if (_isInitFB && !_isLoadFriendFBComplete)
    {
        return false;
    }
    
    return true;
}

void CServerThread::UpdateTimeSynSaveToserver()
{
#if !GAME_SUPPORT
	TDGame*game = (TDGame*)(GAME()->_current_game);
    //if (IsLoadAllFriendCompelete())
    if (IsSynSaveComplete())
    {
        if (_timeDelaySynSaveToServer > 0)
        {
            _timeDelaySynSaveToServer -= DT();
            //printf("\n _timeDelaySynSaveToServer = %lld",_timeDelaySynSaveToServer);
            if (_timeDelaySynSaveToServer <= 0)
            {
#if defined (MAC_OS)
				//GAME()->_serverThread._isNetworkAvailable = checkServerRealIsAble();
				if (GAME()->_serverThread._isNetworkAvailable)
				{
					_timeDelaySynSaveToServer = CMath::RANDOM(TIME_DELAY_SYNSAVE_TO_SERVER, TIME_DELAY_SYNSAVE_TO_SERVER1);
					AddCommand(enumTypeCommand::COMMAND_TYPE_CHECK_STATUS);
					_isSynSaveComplete = false;
				}
#endif
            }
        }
    }
#endif
}

void CServerThread::GoToLoadingMain()
{
    TDGame*game = (TDGame*)(GAME()->_current_game);
    //reset server Thread
    for (int i = 0; i < MAX_COMMAND_IN_THREAD; i++)
    {
        _command[i]._typeCommand = enumTypeCommand::COMMAND_TYPE_NONE;
        _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_NONE;
    }
    
    _isNetworkAvailable = false;
    _isInitGC = false;
    _isLoadFriendGCComplete = false;
    _isInitFB = false;
    _isLoadFriendFBComplete = false;
    _isSynSaveComplete = false;
    _idStringLogin[0] = '\0';
    _userNameLogin[0] = '\0';
    _isFristCheckStatus = true;
    game->SetState(k_GS_LOGO);
    //game

}
/*wp8 android rule
COMMAND_TYPE_INIT_FB
	COMMAND_TYPE_CHECK_STATUS
		COMMAND_TYPE_CHECK_STATUS (STATE_PROCESSING) - CREATE NEW ACC
			
		COMMAND_TYPE_SYN_SAVE_TO_SERVER

		COMMAND_TYPE_SYN_SAVE_FROM_SERVER

		COMMAND_TYPE_SWAP_SAVE_FROM_SERVER

	COMMAND_TYPE_NETWORK_ERROR

*/
/**
    COMMAND_TYPE_INIT_GC
        COMMAND_TYPE_NETWORK_ERROR
        COMMAND_TYPE_CHECK_STATUS
            COMMAND_TYPE_SYN_SAVE_TO_SERVER
                COMMAND_TYPE_INIT_FB
            COMMAND_TYPE_SYN_SAVE_FROM_SERVER
                COMMAND_TYPE_INIT_FB
            COMMAND_TYPE_SWAP_SAVE_FROM_SERVER
                //reset
 
 
    COMMAND_TYPE_INIT_FB
        COMMAND_TYPE_LOAD_GC_FRIEND
            COMMAND_TYPE_LOAD_FB_FRIEND
                COMMAND_TYPE_CHECK_GC_ID_IN_SERVER
                    COMMAND_TYPE_CHECK_FB_ID_IN_SERVER
 
**/
extern "C" void OS_AdBoxDownloadFile();
void CServerThread::ServerRun()
{
    TDGame*game = (TDGame*)(GAME()->_current_game);
    
#if defined (MAC_OS)
	while (GAME() != NULL && !GAME()->_isExit)
#endif
	{
		for (int i = 0; i < MAX_COMMAND_IN_THREAD; i++)
		{			
			//PDEBUG("command %d\n_command[i]._stateCommand = %d", i, _command[i]._stateCommand );
			if (_command[i]._stateCommand == enumStateCommand::COMMAND_STATE_INIT)
			{
                //printf("\n_command[%d]._typeCommand = %d",i,_command[i]._typeCommand);

				switch (_command[i]._typeCommand)
				{
                    case COMMAND_TYPE_INIT_GC:
#if defined (MAC_OS)
                        GameCenter.Init();
#endif
                        _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_PROCESSING;
                        break;
                    case COMMAND_TYPE_SUBMIT_LEADERBOARD:
#if defined (MAC_OS)
                        PineGameCenterController::SubmitMyScore("TTD_TopScore", game->_battle_current+1);
#endif
                        _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_PROCESSING;
                        break;
                    case COMMAND_TYPE_CHECK_SERVER_NETWORK:
						GAME()->CheckICloud();
                         _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_PROCESSING;
                        break;
                    case COMMAND_TYPE_SYN_SAVE_TO_SERVER:
                        GAME()->SaveToICloud();
#if !defined (ANDROID_OS)
                        GAME()->_serverThread.AddCommand(CServerThread::enumTypeCommand::COMMAND_TYPE_SUBMIT_LEADERBOARD);
#endif
                         _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_PROCESSING;
                        break;
                    case COMMAND_TYPE_SWAP_SAVE_FROM_SERVER:
                        GAME()->LoadFromICloud();
                       // game->_user.UserDataSave();
                        _command[i]._stateCommand = enumStateCommand::COMMAND_STATE_PROCESSING;
                        game->SetState(k_GS_MAIN_MENU);
                        break;
                        default:
                        EndCommand(i);
                        break;
                }
			}
			else if (_command[i]._stateCommand == enumStateCommand::COMMAND_STATE_PROCESSING)
			{
				switch (_command[i]._typeCommand)
				{
                        default:
                         EndCommand(i);
                        break;
                }
            }
		}
#if defined (_WINDOWS_PHONE8) || defined(_WIN8) || defined(ANDROID_OS)

#else
		CGame::_this->Sleep(20);
#endif
		
	}
}


void CServerThread::VisitPeople(bool IsRandom)
{
    if(IsRandom)
    {
        
    }
    else
    {
        
    }
}
