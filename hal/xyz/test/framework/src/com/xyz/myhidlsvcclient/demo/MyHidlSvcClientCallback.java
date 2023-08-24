// FIXME: your file license if you have one

package com.xyz.myhidlsvcclient.demo;

import android.util.Log;
import vendor.xyz.hardware.myhidlsvc.V1_1.IMyHidlSvcClientCallback;

class MyHidlSvcClientCallback extends IMyHidlSvcClientCallback.Stub {
    private final String TAG = "Ray MyHidlSvcClientCallback";

    // Methods from vendor.xyz.hardware.myhidlsvc.V1_0.IMyHidlSvcClientCallback follow.
    @Override
    public void onRequest(int param1, int param2, String param3)
            throws android.os.RemoteException {
        // TODO: Implement
    }

    @Override
    public void onError(String val)
            throws android.os.RemoteException {
        Log.d(TAG, "onError is called, val is " + val);
        MainActivity.errorMsg = val;
    }

    @Override
    public void notify(int param1, String param2, vendor.xyz.hardware.myhidlsvc.V1_0.SturctFoo param3)
            throws android.os.RemoteException {
        // TODO: Implement
    }

    @Override
    public java.util.ArrayList<Byte> getValue(int val)
            throws android.os.RemoteException {
        // TODO: Implement
        java.util.ArrayList<Byte> retVal = new java.util.ArrayList<Byte>();
        return retVal;
    }

    @Override
    public String getValueExtra(int val)
            throws android.os.RemoteException {
        // TODO: Implement
        String retVal = new String();
        return retVal;
    }

    // Methods from vendor.xyz.hardware.myhidlsvc.V1_1.IMyHidlSvcClientCallback follow.
    @Override
    public void onRequestExt(int param1, int param2, String param3)
            throws android.os.RemoteException {
        // TODO: Implement
    }

}
