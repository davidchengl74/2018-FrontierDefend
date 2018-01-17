#define MAX_TOUCHES 					10

// hardware type

#define DEVICE_IPHONE				0
#define DEVICE_IPHONE_3G			1
#define DEVICE_IPOD					2
#define DEVICE_IPHONE_3GS			3
#define DEVICE_IPOD_4				4
#define DEVICE_IPHONE_4G			5
#define DEVICE_IPAD					6
#define DEVICE_SIMULATOR			7

#define UNIVERSAL_BUILD				0

#define DEFAULT_SCR_W				480
#define DEFAULT_SCR_H				320
#define DEFAULT_DIV_W				480
#define DEFAULT_DIV_H				320

#define D4_SCR_W					480
#define D4_SCR_H					320
#define D4_DIV_W					480
#define D4_DIV_H					320

#define IPAD_SCR_W					1024
#define IPAD_SCR_H					768
#define IPAD_DIV_W					1024
#define IPAD_DIV_H					768
#define ADD_ADVERT	0
#define FREE_GAME_OF_THEDAY         0
#define ADD_PICK_IMAGE              1

#define PICK_STATE_NONE             0
#define PICK_STATE_TAKE_PICTURE     1
#define PICK_STATE_CHOICE_PICTURE   2
#define ENABLE_SERVER_PUSH_NOTIFICATION 0
#define IS_DEVELOPMENT_VERSION 1

#define USE_GL_SCALE

#define APPLE_ID 1040462294
#define ADVERT_APPLE_ID APPLE_ID

#define GAME_CENTER_FRIEND_NUM 1

#define CA_CERT_PATH        (GetBundlePath())
#if defined(IS_DEVELOPMENT_VERSION)

#define RSA_CLIENT_CERT     GetRealFilePath("apns-dev-cert.pem")
#define RSA_CLIENT_KEY      GetRealFilePath("apns-dev-key.pem")


#define APPLE_HOST          "gateway.sandbox.push.apple.com"
#define APPLE_PORT          2195

#define APPLE_FEEDBACK_HOST "feedback.sandbox.push.apple.com"
#define APPLE_FEEDBACK_PORT 2196
#else

#define RSA_CLIENT_CERT     GetRealFilePath("apns-production-cert.pem")
#define RSA_CLIENT_KEY      GetRealFilePath("apns-production-key.pem")


#define APPLE_HOST          "gateway.push.apple.com"
#define APPLE_PORT          2195

#define APPLE_FEEDBACK_HOST "feedback.push.apple.com"
#define APPLE_FEEDBACK_PORT 2196
#endif

#define USE_NEW_SYSTEM_VIEW_IOS_7_8 1
#define IOS8_MASTER_W (750.0f)
#define IOS8_MASTER_H (1334.0f)


#if defined (ANDROID_OS)
#define ADD_CHARTBOOST 0
#define ADD_ADVERT 0
#define ADD_IADVERT 0
#define USE_ADBOX 0
#define ADD_ADMOB   0
#else
#define ADD_CHARTBOOST 0
#define ADD_ADVERT 1
#define ADD_IADVERT 1
#define USE_ADBOX 1
#define ADD_ADMOB   1
#endif
#define ADBOX_CONFIG_FILE "adbox.config"
#define CHARTBOOST_CONFIG_FILE "chartboost.config"
#define TAG_LINE "PineEntertainment"
#define SERVER_ADS_START_IN_LOADING 1
#define USE_PINESOCIAL  1
#define ADD_GAMECENTER  1
#define ADD_TWITTER     0
#define ADD_FACEBOOK    0
#define ADD_IAP         1

#define FACEBOOK_URL    "https://www.facebook.com/topebox/"
#define TWITTER_URL "https://www.twitter.com/PineGames"

#define USE_PINESOCIAL_AT_ID_STRING		1

#define FACEBOOK_TRANSFER_IAP       (0)
#define FACEBOOK_API                (20)

#define FACEBOOK_PERMISSION [@"email",@"basic_info"]
#define FACEBOOK_PERMISSION_FOR_STREAM [@"email",@"basic_info",@"publish_actions"]
#define FACEBOOOKAUDIENCE ACFacebookAudienceEveryone

#define PURCHASE_FUNC(x,y) {CGame::_this->PurchaseIAP(x,y);}

#define ADD_SCREEN_CAPTUREVIEW 1
#define FPS_VIDEO_RECORD 30
#define CAPTURE_VIDEO_W 480
#define CAPTURE_VIDEO_H 640


#define ADS_VERSION     "100"

#define ADD_VUNGLEADS   0
#define ADD_PINE_ADVERT 1
#define VUNGLE_ID_DEFAULT   "1040462294"

#define ADD_VIDEO_REWARD        0
#define ADD_UNITYADS            0
#define ADD_ADMOB_VIDEO_ADS     1
#define ADMOB_IOS_VIDEO_ADS_ID "ca-app-pub-6305464951596521/7002940292"
#define UNITY_ADS_ID_DEFAULT "83654"
#define ADD_VUNGLE_TO_MEDIATION 1
#define ADMOB_INTERSTITIAL_ID "ca-app-pub-6305464951596521/9446592698"
#define CHARTBOOST_ID1_DEFAULT "56307b670d602531cf053255"
#define CHARTBOOST_ID2_DEFAULT "15282cd7a7aab7ce5163b713e9fb2f8282bcfe4c"
#define ADMOB_ID1_DEFAULT "6305464951596521"
#define ADMOB_ID2_DEFAULT "9446592698"
#define BANNER_XY CGPointMake(0,(IOS8_MASTER_H-100))
#define BANNER_WH CGSizeMake(IOS8_MASTER_W,100)// for portrail

#define USE_PINESTORE   1

#define PROCESSING_DIALOG_YESNO(context,index) {((TDGame*)CGame::_this->_current_game)->ProcessingDialogYesNo(context,index);}
#define PROCESSING_DIALOG_OK(context)	{((TDGame*)CGame::_this->_current_game)->ProcessingDialogOK(context);}

#define ONLY_SUPPORT_KEYBOARD_ABC 1
#define MAX_CHANNEL         5

#if defined (ANDROID_OS)
#define GP_LEADERBOARD_ID "CgkI3czn-vwTEAIQAQ"
#endif

#if defined _WINDOWS
#else
#define ADD_GOOGLE_ANALYTICS 1
#endif
