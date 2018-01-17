#if !defined(_H_ADMOB_MANAGER)
#define _H_ADMOB_MANAGER
#include "DataType/CType.h"

#define COUNT_FOR_PREPARE_REWARDED_VIDEO_ADS 100

class PineAdmobAsync{
private:
	PineServiceHandle _svc_interstitial_prepare, _svc_interstitial_show,
					_svc_banner_prepare, _svc_banner_show, _svc_banner_hide,
					_svc_rewarded_video_prepare, _svc_rewarded_video_show;
	bool _is_request_prepare;
	char _curr_unit_id [255];
public :
	enum enumAdmobUpdateResult {
		NOTHING = 0,
		PREPARE_ADS_SUCCESS,
		PREPARE_ADS_FAIL,
		PREPARE_VIDEO_SUCCESS,
		PREPARE_VIDEO_FAIL,
		SHOW_ADS_SUCCESS,
		SHOW_ADS_FAIL,
		SHOW_VIDEO_SUCCESS,
		SHOW_VIDEO_FAIL,
		SHOW_VIDEO_CRASH,
	};
	bool _need_prepare_rewarded_video_ads;
	int _count_frame_for_prepare_rewarded_video_ads;
	PineAdmobAsync();
	void setUnitId(const char* ad_unit_id);
	void prepareInterstitial();
	void showInterstitial();
	void prepareBanner();
	void showBanner();
	void hideBanner();
	void prepareRewardedVideo();
	void showRewardedVideo();
	bool isInterstitialReady();
	bool isRewardedVideoReady();
	bool isBannerReady();
	bool isShowBanner();
	bool isTurnoff();
	enumAdmobUpdateResult update();
};
#endif