// FIXME: your file license if you have one

#include "MyHidlCallback.h"

namespace com::xyz::hardware::myhidl::implementation {

// Methods from ::com::xyz::hardware::myhidl::V1_0::IMyHidlCallback follow.
Return<void> MyHidlCallback::onRequest(uint32_t param1, ::com::xyz::hardware::myhidl::V1_0::ResponseCode param2, const hidl_string& param3) {
    // TODO implement
    return Void();
}

Return<void> MyHidlCallback::onError(const hidl_string& val) {
    // TODO implement
    return Void();
}

Return<void> MyHidlCallback::notify(uint32_t param1, const hidl_string& param2, const ::com::xyz::hardware::myhidl::V1_0::StructFoo& param3) {
    // TODO implement
    return Void();
}

Return<void> MyHidlCallback::getValue(uint32_t val, getValue_cb _hidl_cb) {
    // TODO implement
    return Void();
}

Return<void> MyHidlCallback::getValueExtra(uint32_t val, getValueExtra_cb _hidl_cb) {
    // TODO implement
    return Void();
}


// Methods from ::com::xyz::hardware::myhidl::V1_1::IMyHidlCallback follow.
Return<void> MyHidlCallback::onRequestExt(uint32_t param1, ::com::xyz::hardware::myhidl::V1_0::ResponseCode param2, const hidl_string& param3) {
    // TODO implement
    return Void();
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

//IMyHidlCallback* HIDL_FETCH_IMyHidlCallback(const char* /* name */) {
    //return new MyHidlCallback();
//}
//
}  // namespace com::xyz::hardware::myhidl::implementation
