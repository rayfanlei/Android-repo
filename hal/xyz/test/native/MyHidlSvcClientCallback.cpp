// FIXME: your file license if you have one

#include <log/log.h>
#include <android/log.h>
#include "MyHidlSvcClientCallback.h"

// Methods from ::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvcClientCallback follow.
Return<void> MyHidlSvcClientCallback::onRequest(uint32_t param1, ::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode param2, const hidl_string& param3) {
    // TODO implement
    return Void();
}

Return<void> MyHidlSvcClientCallback::onError(const hidl_string& val) {
    ALOGD("Receive %s", val.c_str());

    return Void();
}

Return<void> MyHidlSvcClientCallback::notify(uint32_t param1, const hidl_string& param2, const ::vendor::xyz::hardware::myhidlsvc::V1_0::SturctFoo& param3) {
    // TODO implement
    return Void();
}

Return<void> MyHidlSvcClientCallback::getValue(uint32_t val, getValue_cb _hidl_cb) {
    // TODO implement
    return Void();
}

Return<void> MyHidlSvcClientCallback::getValueExtra(uint32_t val, getValueExtra_cb _hidl_cb) {
    // TODO implement
    return Void();
}


// Methods from ::vendor::xyz::hardware::myhidlsvc::V1_1::IMyHidlSvcClientCallback follow.
Return<void> MyHidlSvcClientCallback::onRequestExt(uint32_t param1, ::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode param2, const hidl_string& param3) {
    // TODO implement
    return Void();
}
