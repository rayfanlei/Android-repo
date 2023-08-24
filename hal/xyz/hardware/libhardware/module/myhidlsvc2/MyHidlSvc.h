// FIXME: your file license if you have one

#pragma once

#include <android/log.h>
#include <vendor/xyz/hardware/myhidlsvc/1.1/IMyHidlSvc.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace vendor::xyz::hardware::myhidlsvc::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct MyHidlSvc : public V1_1::IMyHidlSvc {
public:
    MyHidlSvc();
    ~MyHidlSvc();

    static V1_1::IMyHidlSvc* getInstance(void);

    // Methods from ::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvc follow.
    Return<bool> subscribe(const sp<::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvcClientCallback>& callback) override;
    Return<bool> setFunc(int32_t val) override;
    Return<int32_t> getFunc() override;
    Return<void> functionFoo(uint32_t param1, const ::vendor::xyz::hardware::myhidlsvc::V1_0::SturctFoo& param2, functionFoo_cb _hidl_cb) override;
    Return<uint32_t> functionBar(uint64_t param1, const hidl_string& param2) override;
    Return<::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode> functionOrr(::vendor::xyz::hardware::myhidlsvc::V1_0::RequestCode req) override;
    Return<uint32_t> functionPss(uint32_t param1, const hidl_vec<uint8_t>& param2) override;
    Return<void> functionQtt(const hidl_vec<uint8_t>& val, functionQtt_cb _hidl_cb) override;

    // Methods from ::vendor::xyz::hardware::myhidlsvc::V1_1::IMyHidlSvc follow.
    Return<void> functionExt(const hidl_string& argv, functionExt_cb _hidl_cb) override;

private:
    static MyHidlSvc* sInstance;

    std::mutex mClientCallbackMutex;
    sp<V1_0::IMyHidlSvcClientCallback> mClientCallback;
};

}  // namespace vendor::xyz::hardware::myhidlsvc::implementation
