package pine.core.Actions;

import pine.core.*;
import 	android.util.Log;
import android.os.Bundle;

	
import android.app.Activity;
import android.content.Context;
import org.json.JSONObject;

import org.json.JSONException;

public class ActionFacebookRequestPostPermission implements Action{
	ActionArg Arg = null;
	public ActionFacebookRequestPostPermission(ActionArg arg){
		Arg = arg;
	}
	public void act(){
		if(Arg == null){
			Log.i("Debug", "action post facebook error");
			return;
		}
		Arg.onBegin();
		final ActionFacebookRequestPostPermissionArg arg = (ActionFacebookRequestPostPermissionArg)Arg;
        FacebookManager.requestPostPermission(arg);
		
	}
}