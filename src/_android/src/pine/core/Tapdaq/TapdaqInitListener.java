package pine.core.Tapdaq;
import 	android.util.Log;
import com.tapdaq.sdk.listeners.TMInitListener;

import pine.core.TapdaqManager;

public class TapdaqInitListener extends TMInitListener {

    public void didInitialise() {
        super.didInitialise();
        TapdaqManager.onInitSuccess();
        Log.i("DEBUG","Tapdaq init success");
    }
}