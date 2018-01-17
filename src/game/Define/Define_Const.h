//FPS
#define FPS_MAX						70
#define FPS_DELAY_TIME				(1000/CGame::_this->FPS_LIMIT)

//Game State
#define k_GS_LOGO					1
#define k_GS_PLAYGAME				2
#define k_GS_EXAMPLE				3
#define k_GS_INGAME_MENU			4
#define k_GS_MENU					5
#define k_GS_QUEST					6
#define k_GS_OPEN_BOX				7
#define k_GS_WHEEL					8
#define k_GS_GAME_OVER				9
#define k_GS_MAIN_MENU				10
//Game Sub State
#define k_INIT						1
#define k_FIRST_TIME				2
#define k_LOOP						3
#define k_DESTROY					4
#define k_EFFECT_UNLOAD				5

#define k_MACHINE_FAKE_OUT			5
#define k_MACHINE_WIN				6

/*************************Topebox promo***********************/
#define FIREBASE_CONFIG_SAVE_FILE_NAME	"android.config"
#define FIREBASE_BUTKET_URL  "gs://topeboxads-fe304.appspot.com"
#define TIME_REMOTE_CONFIG		(5*60)
#define TIME_SHOW_CLOSE_BANNER_TOPEBOX		(3*60)	
#define ADD_REMOTE_CONFIG           1
#define TIME_DELAY_SHOW_TOPEBOX_ADS			8*60*60;
#define FIREBASE_ICON			"https://firebasestorage.googleapis.com/v0/b/topeboxads-fe304.appspot.com/o/TopeAds%2FSkyDancer%2Fconfig%2Fandroid.config?alt=media&token=5d5fd3f6-5fc1-4b20-bbe2-144d38ac0187"
#define FB_ICON_CHEAT		0
