// FIXME: your file license if you have one

#pragma once

#include <vendor/xyz/hardware/myhidlsvc/1.0/IMyHidlSvcClientCallback.h>
#include <vendor/xyz/hardware/myhidlsvc/1.1/IMyHidlSvcClientCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

using namespace ::vendor::xyz::hardware::myhidlsvc;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct MyHidlSvcClientCallback : public V1_0::IMyHidlSvcClientCallback {
    // Methods from ::vendor::xyz::hardware::myhidlsvc::V1_0::IMyHidlSvcClientCallback follow.
    Return<void> onRequest(uint32_t param1, ::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode param2, const hidl_string& param3);
    Return<void> onError(const hidl_string& val);
    Return<void> notify(uint32_t param1, const hidl_string& param2, const ::vendor::xyz::hardware::myhidlsvc::V1_0::SturctFoo& param3);
    Return<void> getValue(uint32_t val, getValue_cb _hidl_cb);
    Return<void> getValueExtra(uint32_t val, getValueExtra_cb _hidl_cb);

    // Methods from ::vendor::xyz::hardware::myhidlsvc::V1_1::IMyHidlSvcClientCallback follow.
    Return<void> onRequestExt(uint32_t param1, ::vendor::xyz::hardware::myhidlsvc::V1_0::ResponseCode param2, const hidl_string& param3);
};
