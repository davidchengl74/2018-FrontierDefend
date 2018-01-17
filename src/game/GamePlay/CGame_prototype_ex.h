/**
*	will be included in CGame.h
*	specific vars and methods for gameplay
*/

public:
// game state
	
	
	
private:
	
public:



	

//Save System.
void GameDataLoad();
void GameDataSave();
void GameDataDefault();
void GameDataToBuffer();
void GameLoadDataFromBuffer();

BYTE red, green, blue, alpha;
#define GAME_FILE	"pinerecord.dat"

#define GAME_VERSION				100

#define GAME_DATA_VERSION			(0)

#define GAME_DATA_LENGTH				(GAME_DATA_VERSION + 4)



char _buffer_save[GAME_DATA_LENGTH];
int _game_version;
int _rate;

//PineHighScore _pineHighScore;

int _check_syn_save_complete;
void CheckAndSynSave();
#define SYN_SAVE_NONE (0)
#define SYN_SAVE_PROCESSING (1)

int  _syn_save_state;
int  _syn_save_step;
int  _syn_time_out;
bool  _can_submit;
bool  UpdateSynSave();
void SubmitHighScore();
bool _newScore;
bool _call_submit_score;
int _online_score;

#define PROCESSING_VIEW_TYPE_NONE       0
#define PROCESSING_VIEW_TYPE_GC         1
#define PROCESSING_VIEW_TYPE_IAP        2
#define PROCESSING_VIEW_CHECK_NETWORK   3
#define PROCESSING_VIEW_TYPE_SYNC_SAVE	4

int _processing_view_type;
int _processing_time_out;
bool _is_purchase_procesing;
int _purchase_procesing_opac;
int _purchase_effect_rotate1;
int _purchase_effect_rotate2;
CAnimObject _anim_loading;
int _loading_count_frame;
void RenderLoadingPurchase(float x, float y);

#if !defined (ANDROID_OS)
CServerThread _serverThread;
#endif
Pine_Date_Time _current_time;
Pine_Date_Time _server_time;
PineStore _pineStore;

 long _sys_begin_second;
 long _sys_millisecond;
 long _game_millisecond;
 long _sys_second;

void UnloadGameBackground();
bool LoadGameForceground();

bool _needresume_when_playing;


void PurchaseIAP(const char* strID, enumIAPResponseStatus sucessed);

int  _frame_auto_stop;
PineImage _image;
PineGame *_main_game;
PineGame  *_feature_game;
PineGame    *_current_game;

bool _isNeedOptimize;

//quoc.nguyen
INT_TIME _oldMillisecond;
INT_TIME _oldFrameDT;
INT_TIME _oldLastTimeFrame;
void SynDTtimeOldFunction();

static bool _force_start;

static int _last_auto_key;
static int _auto_block_frame;
static int _frame_to_show_ads_after_interupt;
PineImage _logo;
PineImage _red_warning;
static bool _ask_notification;

#if !defined (MAC_OS)
bool			_isBackkeyPress;
int				_waitForProcessBackkeyCount;
#if defined(ANDROID_OS)
//async tasks
CAsyncTasks _async_task_manager;
// admod
#define AD_MODE_PLAY_MAX 2
//PineAdmobAsync _admob_manager;
PineTapdaqAsync _tapdaq_manager;
PineUnityAdsAsync _unity_manager;
int _admob_play_count;
// unity ads
PineUnityAdsAsync _unityads_manager;
// Vungle ads
//PineAdsVungleAsync _adsVungle_manager;

INT_TIME _time_start_wait_for_reinit_ads;
bool _on_show_video_ads = false;
bool _on_video_ads_reward = false;
bool _is_waiting_for_reward = false;

int _show_ads_count;
int _show_unity_video_ads_count;
int _is_initAds = false;
INT_TIME _time_first_show_unity_video_ads;
#define TIME_WAIT_FOR_REINIT_ADS 10*1000

BoardScoreItem		_gameBoardScoreItem;
#endif
#endif

bool _is_cancel_show_ads_on_resume = false;

void ResetValueICloud();
void SaveToICloud();
void RewriteToICloud();
int CheckCanPushDataSave();
void LoadFromICloud();
void DefaultICloud();
void CheckICloud();
int _icloud_state;
bool _will_show_dialog_ask_save;
#define ICLOUD_STATE_NODATA      -2
#define ICLOUD_STATE_DISCONECT   -3
#define ICLOUD_STATE_OLD_VERSION -1
#define ICLOUD_STATE_NEW_VERSION 0
#define ICLOUD_STATE_READY_SYNS  1

bool IsAndroidVersion;
void GooglePlayShowLeaderBoard();
void GooglePlayShowAchievement();
void GooglePlaySynDriver();
void GooglePlaySubmitAchievement(int index);

/***********************Topebox promo********************/
TopeBox_PromoGame _topebox_game;
bool is_config_downloaded;
bool is_disable_promo;
bool is_renderd_promo;
bool is_showing_ads;
bool _can_showads;
int time_delay_get_config;

bool InitAds();
bool HasAds();
bool HasVideoAds();
bool HasVideoSkippableAds();
bool HasBannerAds();
void ShowAds();
void ShowVideoAds();
void ShowSkippableVideoAds();
void ShowBannerAds();
void HideBannerAds();

void PrepareAndShowVideoAds();
void PrepareAndShowInterstitial();

void UpdateAds();

