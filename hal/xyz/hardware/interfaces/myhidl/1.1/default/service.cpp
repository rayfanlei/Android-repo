#include <log/log.h>
#include <android/log.h>
#include <hidl/LegacySupport.h>
#include <com/xyz/hardware/myhidl/1.1/IMyHidl.h>
#include "MyHidl.h"
 
#undef LOG_TAG
#define LOG_TAG "com.xyz.hardware.myhidl@1.1-service"

using com::xyz::hardware::myhidl::V1_1::IMyHidl;
using com::xyz::hardware::myhidl::implementation::MyHidl;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::sp;
 
int main() {
    android::sp<IMyHidl> svc = MyHidl::getInstance();

    configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (svc != nullptr) {
        if (::android::OK != svc->registerAsService()) {
            ALOGD("Starting the service");
            return 1;
        }
    } else {
        ALOGE("Can't create instance of service, nullptr");
    }

    joinRpcThreadpool();

    return 0; // should never get here
}
