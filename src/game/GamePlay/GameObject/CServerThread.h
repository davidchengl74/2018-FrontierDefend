#ifndef _CSERVER_THREAD_H
#define _CSERVER_THREAD_H

#define MAX_COMMAND_IN_THREAD		5

#define TIME_DELAY_SYNSAVE_TO_SERVER    (5*60*1000)
#define TIME_DELAY_SYNSAVE_TO_SERVER1    (10*60*1000)

#if defined (_WINDOWS_PHONE8) || defined(_WIN8)
//#include "../GamePlay/GameObject/AccountManager.h"
//#include "../Lib/PineSocialAsync.h"

// fix to build android
#include "./AccountManager.h"
#include "../../Lib/PineSocialAsync.h"

#endif
class  CServerThread
{
public:
#if defined (MAC_OS)
    PineGameCenterController GameCenter;
#endif
	CServerThread()
	{
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
        _isFristCheckStatus = true;
		_gcSocial = NULL;
		_fbSocial = NULL;
        _isSynSaveComplete = false;
        _idStringLogin[0] = '\0';
        _userNameLogin[0] = '\0';
        _timeDelaySynSaveToServer = CMath::RANDOM(TIME_DELAY_SYNSAVE_TO_SERVER,TIME_DELAY_SYNSAVE_TO_SERVER1);
        


#if defined (_WINDOWS_PHONE8) || defined(_WIN8) || defined(ANDROID_OS)
		_num_full = 0;
		_left_id = 0;
		_count = 0;
		num = 0;
#endif
	};

	enum enumTypeCommand
	{
		COMMAND_TYPE_NONE,
        COMMAND_TYPE_INIT_GC,
        COMMAND_TYPE_INIT_FB,
		COMMAND_TYPE_LOAD_INFO_FB,
        COMMAND_TYPE_NETWORK_ERROR,
		COMMAND_TYPE_LOAD_GC_FRIEND,
		COMMAND_TYPE_LOAD_FB_FRIEND,
		COMMAND_TYPE_CHECK_GC_ID_IN_SERVER,
		COMMAND_TYPE_CHECK_FB_ID_IN_SERVER,
        COMMAND_TYPE_CHECK_STATUS,
        COMMAND_TYPE_SYN_SAVE_FROM_SERVER,
        COMMAND_TYPE_SWAP_SAVE_FROM_SERVER,
        COMMAND_TYPE_SYN_SAVE_TO_SERVER,
        COMMAND_TYPE_DOWNLOAD_AVATAR,
		COMMAND_TYPE_DOWNLOAD_AVATAR_VISIT_FRIEND,
        COMMAND_TYPE_GENERAL_TEXTURE_AVATAR,
        COMMAND_TYPE_VISIT_FRIENDLIST,
        COMMAND_TYPE_VISIT_RANDOM,
		COMMAND_TYPE_LOAD_PK_DATA,
        COMMAND_TYPE_SUBMIT_LEADERBOARD,
        COMMAND_TYPE_CHECK_SERVER_NETWORK,
        COMMAND_TYPE_GET_INVITATION_CODE,
        COMMAND_TYPE_POST_INVITATION_CODE,
        COMMAND_TYPE_GET_NUM_INVITATION,
        
	};

	enum enumStateCommand
	{
		COMMAND_STATE_NONE,
		COMMAND_STATE_INIT,
		COMMAND_STATE_PROCESSING,
	};

    enum enumServerStatus
    {
        SERVER_STATUS_ERROR,
        SERVER_STATUS_NO_RECORD,
        SERVER_STATUS_LOCAL_IS_NEW,
        SERVER_STATUS_SERVER_IS_NEW,
        SERVER_STATUS_SWAP_ACCOUNT,
    };
    
	struct structCommnad
	{
		enumTypeCommand _typeCommand;
		enumStateCommand _stateCommand;
	};

	structCommnad _command[MAX_COMMAND_IN_THREAD];

	//var server
	bool _isNetworkAvailable;
	bool _isInitGC, _isLoadFriendGCComplete;
	bool _isInitFB, _isLoadFriendFBComplete;
    bool _isSynSaveComplete;
    bool _isFristCheckStatus;
    char _idStringLogin[SOCIAL_ID_STRING_LENGTH];
    char _userNameLogin[SOCIAL_ID_STRING_LENGTH];
    long long _timeDelaySynSaveToServer;
    
	PineSocial *_gcSocial, *_fbSocial;

	bool AddCommand(enumTypeCommand typeCommand);
	void EndCommand(int index);
    void ClearAllCommand();

	void ServerRun();
    
    char _urlForOdata[1024];
    
    bool IsSynSaveComplete();
    bool IsLoadAllFriendCompelete();
    
    void GoToLoadingMain();
    
    void UpdateTimeSynSaveToserver();
    
    bool AlreadyHasCommand(enumTypeCommand typeCommand);


    void VisitPeople(bool IsRandom);



	//porting 
#if defined (_WINDOWS_PHONE8) || defined(_WIN8)
		PineSocialAsync _social;
		AccountManager _acc_mng;
		PineServiceHandle _svc_acc_login, _svc_acc_load, _svc_check_server_able, _svc_load_friends, _svc_check_acc_server,
			_svc_create_new_acc, _svc_get_avatar_url, _svc_syn_save_from_server, _svc_syn_save_to_server, _svc_random, 
			_svc_data_from_friend, _svc_check_fb_id_server, _svc_download_avatar, _svc_iap,_svc_post_photo,_svc_data_pk;
			

		PineAccountIdList _list_friends_fb;
		
		//random 
		
		int _random_type;
		char _random_id[255], _random_avatar[255], _random_username[255];

		int _num_full;
		int _left_id;
		int _count;
		bool _check_;
		int num;

		bool _loaded_store;
#endif



};

#endif
