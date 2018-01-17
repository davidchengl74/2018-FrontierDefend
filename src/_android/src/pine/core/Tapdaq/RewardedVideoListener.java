package pine.core.Tapdaq;

import android.util.Log;

import com.tapdaq.sdk.common.TMAdError;
import com.tapdaq.sdk.listeners.TMAdListener;
import com.tapdaq.sdk.model.rewards.TDReward;

import java.util.Locale;

import pine.core.TapdaqManager;

public class RewardedVideoListener extends TMAdListener {

    @Override
    public void didLoad() {
        Log.i("DEBUG", "Java tapdaq video callback load success!");
        TapdaqManager.onVideoLoaded(true);
    }

    @Override
    public void didFailToLoad(TMAdError error)
    {
        Log.i("DEBUG", "Java tapdaq video callback load fail! error: " + error.getErrorMessage());
        TapdaqManager.onVideoLoaded(false);
    }

    @Override
    public void didDisplay() {
        Log.i("DEBUG", "Java tapdaq video callback displayed!");
        TapdaqManager.onVideoShow();
    }

    @Override
    public void didClose() {
        Log.i("DEBUG", "Java tapdaq video callback closed!");
        TapdaqManager.onVideoCompleted(true, false);
    }

    @Override
    public void didVerify(TDReward reward) {
        Log.i("DEBUG", String.format(Locale.ENGLISH, "didVerify: ID: %s, Tag: %s. Reward: %s. Value: %f. Valid: %b. Custom Json: %s", reward.getEventId(), reward.getTag(), reward.getName(), reward.getValue(), reward.isValid(), reward.getCustom_json().toString()));
        TapdaqManager.onVideoCompleted(true, false);
    }

    @Override
    public void didRewardFail(TMAdError error) {
        super.didRewardFail(error);
        Log.i("DEBUG", "didRewardFail " + error.getErrorMessage());
    }

    @Override
    public void onUserDeclined() {
        Log.i("DEBUG", "onUserDeclined");
        TapdaqManager.onVideoCompleted(false, false);
    }

    @Override
    public void didEngagement() {
        Log.i("DEBUG", "didEngagement");
    }

    @Override
    public void didComplete() {
        Log.i("DEBUG", "didComplete");
        TapdaqManager.onVideoCompleted(true, false);
    }

    @Override
    public void didClick() {
        Log.i("DEBUG", "didClick");
    }

    @Override
    public void didRefresh() {
        Log.i("DEBUG", "didRefresh");
    }
}