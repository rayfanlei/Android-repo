// FIXME: your file license if you have one

#include <log/log.h>
#include <android/log.h>
#include "MyHidlSvc.h"

namespace vendor::xyz::hardware::myhidlsvc::implementation {

MyHidlSvc *MyHidlSvc::sInstance = nullptr;

MyHidlSvc::MyHidlSvc() : mClientCallback(nullptr) {
    sInstance = this;
}

MyHidlSvc::~MyHidlSvc() {
    ALOGV("~MyHidlSvc()");
}

V1_1::IMyHidlSvc* MyHidlSvc::getInstance(void) {
    if (!sInstance) {
      sInstance = new MyHidlSvc();
    }
    return sInstance;
}
// Methods from ::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvc follow.
Return<bool> MyHidlSvc::subscribe(const sp<::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvcClientCallback>& callback) {
    // TODO implement
    return bool {};
}

Return<bool> MyHidlSvc::setFunc(int32_t val) {
    // TODO implement
    return bool {};
}

Return<int32_t> MyHidlSvc::getFunc() {
    // TODO implement
    return int32_t {};
}

Return<void> MyHidlSvc::functionFoo(uint32_t param1, const ::vendor::xyz::hardware::myhidlsvc::V1_0::SturctFoo& param2, functionFoo_cb _hidl_cb) {
    // TODO implement
    return Void();
}

Return<uint32_t> MyHidlSvc::functionBar(uint64_t param1, const hidl_string& param2) {
    // TODO implement
    return uint32_t {};
}

Return<::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode> MyHidlSvc::functionOrr(::vendor::xyz::hardware::myhidlsvc::V1_0::RequestCode req) {
    // TODO implement
    return ::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode {};
}

Return<uint32_t> MyHidlSvc::functionPss(uint32_t param1, const hidl_vec<uint8_t>& param2) {
    // TODO implement
    return uint32_t {};
}

Return<void> MyHidlSvc::functionQtt(const hidl_vec<uint8_t>& val, functionQtt_cb _hidl_cb) {
    // TODO implement
    return Void();
}


// Methods from ::vendor::xyz::hardware::myhidlsvc::V1_1::IMyHidlSvc follow.
Return<void> MyHidlSvc::functionExt(const hidl_string& argv, functionExt_cb _hidl_cb) {
    // TODO implement
    return Void();
}

}  // namespace vendor::xyz::hardware::myhidlsvc::implementation
