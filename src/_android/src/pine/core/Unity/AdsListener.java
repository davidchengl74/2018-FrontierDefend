package pine.core.Unity;


import android.util.Log;

// unity3d ads
import com.unity3d.ads.UnityAds;
import com.unity3d.ads.IUnityAdsListener;
import com.unity3d.ads.*;

import pine.core.UnityAdsManager;

public class AdsListener implements IUnityAdsListener
{
	@Override
	public void onUnityAdsReady(final String zoneId) {
		Log.i("DEBUG", "unity ads ready zoneid = " + zoneId);
	}

	@Override
	public void onUnityAdsStart(String zoneId) {
		Log.i("DEBUG", "unity ads started");
	}

	@Override
	public void onUnityAdsFinish(String zoneId, UnityAds.FinishState result) {
		Log.i("DEBUG", "unity ads finished result: " + result.toString() + "; zoneid = " + zoneId);
		if (result == UnityAds.FinishState.COMPLETED) {
			UnityAdsManager.onVideoCompleted();
		}
		else{
			UnityAdsManager.onUserSkipVideo();
		}
	}

	@Override
	public void onUnityAdsError(UnityAds.UnityAdsError error, String message) {
		Log.i("DEBUG", "unity ads error: "+ error + " - " + message);
	}
}