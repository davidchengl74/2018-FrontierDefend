//Pine-entertainment
//Android Framework
//duy.nguyen 2014 - 2015

package pine.core.Actions;

import java.lang.*;
import android.app.Activity;
import android.util.Log;

import com.tapdaq.sdk.Tapdaq;
import pine.core.Tapdaq.RewardedVideoListener;
import pine.core.TapdaqManager;

public class ActionTapdaqRewardedVideoAdsShow implements Action {
	ActionTapdaqRewardedVideoAdsShowArg Arg = null;
	Activity CurrentActivity = null;

	public ActionTapdaqRewardedVideoAdsShow(ActionTapdaqRewardedVideoAdsShowArg arg, Activity activity) {
		Arg = arg;
		CurrentActivity = activity;
	}

	public void act() {
		if (Arg == null || CurrentActivity == null) {
			return;
		}
		Arg.onBegin();
		if (Tapdaq.getInstance().isRewardedVideoReady(CurrentActivity, "rewardVideo")) {
			try {
				Tapdaq.getInstance().showRewardedVideo(CurrentActivity, "rewardVideo", new RewardedVideoListener());
			}catch (Exception ex)
			{
				TapdaqManager.onVideoCompleted(false, true);
				Log.i("DEBUG", "Show tapdaq rewarded video Ads fail with exception: " + ex.getMessage());
			}
		} else {
			Log.i("DEBUG", "Tapdaq rewarded video Ads is not ready");
			Arg.onCancel();
		}
	}
}