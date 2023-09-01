// FIXME: your file license if you have one

#pragma once

#include <com/xyz/hardware/myhidl/1.1/IMyHidlCallback.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace com::xyz::hardware::myhidl::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct MyHidlCallback : public V1_1::IMyHidlCallback {
    // Methods from ::com::xyz::hardware::myhidl::V1_0::IMyHidlCallback follow.
    Return<void> onRequest(uint32_t param1, ::com::xyz::hardware::myhidl::V1_0::ResponseCode param2, const hidl_string& param3) override;
    Return<void> onError(const hidl_string& val) override;
    Return<void> notify(uint32_t param1, const hidl_string& param2, const ::com::xyz::hardware::myhidl::V1_0::StructFoo& param3) override;
    Return<void> getValue(uint32_t val, getValue_cb _hidl_cb) override;
    Return<void> getValueExtra(uint32_t val, getValueExtra_cb _hidl_cb) override;

    // Methods from ::com::xyz::hardware::myhidl::V1_1::IMyHidlCallback follow.
    Return<void> onRequestExt(uint32_t param1, ::com::xyz::hardware::myhidl::V1_0::ResponseCode param2, const hidl_string& param3) override;

    // Methods from ::android::hidl::base::V1_0::IBase follow.

};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IMyHidlCallback* HIDL_FETCH_IMyHidlCallback(const char* name);

}  // namespace com::xyz::hardware::myhidl::implementation
