package com.xyz.myhidlsvcclient.demo;

import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import vendor.xyz.hardware.myhidlsvc.V1_1.IMyHidlSvc;

public class MainActivity extends AppCompatActivity {
    private final String TAG = "Ray MainActivity";

    private TextView mView;
    private String mString = "";
    private IMyHidlSvc mClient = null;
    public static String errorMsg = "Empty";

    @Override
    public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
        mView = findViewById(R.id.txt_view);
    }

	@Override
	public void onResume() {
		super.onResume();

        if (getService()) {
            mString += "Get IMyHidlSvc service successfully!\n";
        } else {
            mString += "Failed to get IMyHidlSvc service!\n";
        }

        if (subscribe()) {
            mString += "subscribe callback successfully!\n";
        } else {
            mString += "Failed to subscribe callback!\n";
        }

        int ret = getFunction();
        mString += "getFunc return " + ret + "\n";
        mString += errorMsg;

        mView.setText(mString);
	}

    private boolean getService() {
        try {
            mClient = IMyHidlSvc.getService();
            return (mClient != null);
        } catch (RemoteException e) {
            Log.e(TAG, "Failed to get IMyHidlSvc service!", e);
        }

        return false;
    }

    private boolean subscribe() {
        MyHidlSvcClientCallback callback = new MyHidlSvcClientCallback();
        try {
            mClient.subscribe(callback);
            Log.d(TAG, "Register call back successfully!, sCallback = " + callback);
            return true;
        } catch (RemoteException e) {
            Log.e(TAG, "Failed to register call back!", e);
        }

        return false;
    }

    private int getFunction() {
        int ret = 0;
        try {
            ret = mClient.getFunc();
        } catch (RemoteException e) {
            Log.e(TAG, "Failed to call getFunc!", e);
        }

        return ret;
    }
}
