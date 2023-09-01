// FIXME: your file license if you have one

#include <log/log.h>
#include <android/log.h>
#include "MyHidl.h"

namespace com::xyz::hardware::myhidl::implementation {

#define UNUSED(x) (void)(x)

MyHidl* MyHidl::sInstance = nullptr;
sp<V1_0::IMyHidlCallback> MyHidl::mCallback_1_0 = nullptr;
sp<V1_1::IMyHidlCallback> MyHidl::mCallback_1_1 = nullptr;
sp<V1_2::IMyHidlCallback> MyHidl::mCallback_1_2 = nullptr;

myhidl_callbacks_t MyHidl::sHalCallbacks = {
    .on_request = onRequest,
    .on_error = onError,
    .notify = notify,
    .get_value = getValue,
    .get_value_extra = getValueExtra,
    .on_request_ext = onRequestExt,
    .output_data = outputData,
};

MyHidl::MyHidl() : mDevice(nullptr) {
    sInstance = this;

    mDevice = openHal();
    if (!mDevice) {
        ALOGE("Can't open HAL module");
    }
}

MyHidl::~MyHidl() {
    if (nullptr == mDevice) {
        ALOGE("No valid device");
        return;
    }

    int err;
    if (0 != (err = mDevice->common.close(reinterpret_cast<hw_device_t*>(mDevice)))) {
        ALOGE("Can't close module, error: %d", err);
        return;
    }
    mDevice = nullptr;
}

myhidl_device_t* MyHidl::openHal() {
    int err;
    const hw_module_t* hw_module = nullptr;
    if (0 != (err = hw_get_module(MYHIDL_HARDWARE_MODULE_ID, &hw_module))) {
        ALOGE("Can't open MYHIDL_HARDWARE_MODULE_ID HW module, error: %d", err);
        return nullptr;
    }

    if (nullptr == hw_module) {
        ALOGE("No valid hardware module");
        return nullptr;
    }

    myhidl_module_t const *module = reinterpret_cast<const myhidl_module_t*>(hw_module);
    if (nullptr == module->common.methods->open) {
        ALOGE("No valid open method");
        return nullptr;
    }

    hw_device_t* device = nullptr;

    if (0 != (err = module->common.methods->open(hw_module, nullptr, &device))) {
        ALOGE("Can't open methods, error: %d", err);
        return nullptr;
    }

    myhidl_device_t* myhidl_device = reinterpret_cast<myhidl_device_t*>(device);

    if (0 != (err = myhidl_device->init(myhidl_device, &sHalCallbacks))) {
        ALOGE("Can't init hal module, error: %d", err);
        return nullptr;
    }

    return myhidl_device;
}

V1_2::IMyHidl* MyHidl::getInstance(void) {
    if (!sInstance) {
        sInstance = new MyHidl();
    }
    return sInstance;
}

// Methods from ::com::xyz::hardware::myhidl::V1_0::IMyHidl follow.
Return<bool> MyHidl::subscribe_1_0(const sp<V1_0::IMyHidlCallback>& callback) {
    std::lock_guard<std::mutex> lock(mCallbackMutex_1_0);
    if (callback == nullptr) {
        ALOGE("callback is null pointer!");
        return bool{false};
    }

    if (nullptr != mCallback_1_0) {
        ALOGW("%s called more than once", __func__);
        mCallback_1_0->unlinkToDeath(mDeathRecipient_1_0);
    }

    mCallback_1_0 = callback;
    callback->linkToDeath(mDeathRecipient_1_0, 0/*cookie*/);
    return bool {true};
}

Return<bool> MyHidl::subscribe_1_1(const sp<V1_1::IMyHidlCallback>& callback) {
    std::lock_guard<std::mutex> lock(mCallbackMutex_1_1);
    if (callback == nullptr) {
        ALOGE("callback is null pointer!");
        return bool{false};
    }

    if (nullptr != mCallback_1_1) {
        ALOGW("%s called more than once", __func__);
        mCallback_1_1->unlinkToDeath(mDeathRecipient_1_1);
    }

    mCallback_1_1 = callback;
    callback->linkToDeath(mDeathRecipient_1_1, 0/*cookie*/);
    return bool {true};
}

Return<bool> MyHidl::subscribe_1_2(const sp<V1_2::IMyHidlCallback>& callback) {
    std::lock_guard<std::mutex> lock(mCallbackMutex_1_2);
    if (callback == nullptr) {
        ALOGE("callback is null pointer!");
        return bool{false};
    }

    if (nullptr != mCallback_1_2) {
        ALOGW("%s called more than once", __func__);
        mCallback_1_2->unlinkToDeath(mDeathRecipient_1_2);
    }

    mCallback_1_2 = callback;
    callback->linkToDeath(mDeathRecipient_1_2, 0/*cookie*/);
    return bool {true};
}

void MyHidl::handleHidlDeath() {
    ALOGW("service noticed HIDL death.");
    mCallback_1_0 = nullptr;
    mCallback_1_1 = nullptr;
    mCallback_1_2 = nullptr;
}

Return<bool> MyHidl::setFunc(int32_t val) {
    return mDevice->setFunc(mDevice, val);
}

Return<int32_t> MyHidl::getFunc() {
    return mDevice->getFunc(mDevice);
}
 
Return<void> MyHidl::functionFoo(uint32_t param1, const V1_0::StructFoo& param2, functionFoo_cb _hidl_cb) {
    UNUSED(param1);
    UNUSED(param2);
    UNUSED(_hidl_cb);
    return Void();
}

Return<uint32_t> MyHidl::functionBar(uint64_t param1, const hidl_string& param2) {
    UNUSED(param2);
    return mDevice->functionBar(mDevice, param1);
}

Return<V1_0::ResponseCode> MyHidl::functionOrr(V1_0::RequestCode req) {
    UNUSED(req);
    return V1_0::ResponseCode {};
}

Return<uint32_t> MyHidl::functionPss(uint32_t param1, const hidl_vec<uint8_t>& param2) {
    UNUSED(param2);
    return mDevice->functionPss(mDevice, param1);
}

Return<void> MyHidl::functionQtt(const hidl_vec<uint8_t>& val, functionQtt_cb _hidl_cb) {
    UNUSED(val);
    int length = 32;
    std::vector<uint8_t> v_result;
    uint8_t * buffer = mDevice->functionQtt(mDevice);

    v_result.resize(length);
    v_result.assign(buffer, buffer + length);
    _hidl_cb((hidl_vec<uint8_t>)v_result);
    return Void();
}


// Methods from ::com::xyz::hardware::myhidl::V1_1::IMyHidl follow.
Return<void> MyHidl::functionExt(const hidl_string& argv, functionExt_cb _hidl_cb) {
    UNUSED(argv);
    char *retString = mDevice->functionExt(mDevice);
    _hidl_cb(hidl_string(retString));
    return Void();
}

void MyHidl::onRequest(uint32_t param1, const ResponseCode param2, const char* param3) {
    if (mCallback_1_0 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return;
    }

    android::hardware::hidl_string string;
    string.setToExternal(param3, strlen(param3));
    auto ret = mCallback_1_0->onRequest(param1, (V1_0::ResponseCode)param2, string);
    if (!ret.isOk()) {
        ALOGE("%s: Unable to invoke callback", __func__);
    }
}

void MyHidl::onError(const char* val) {
    if (mCallback_1_0 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return;
    }

    android::hardware::hidl_string string;
    string.setToExternal(val, strlen(val));
    auto ret = mCallback_1_0->onError(string);
    if (!ret.isOk()) {
        ALOGE("%s: Unable to invoke callback", __func__);
    }
}

void MyHidl::notify(uint32_t param1, const char* param2, const StructFoo param3) {
    if (mCallback_1_0 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return;
    }

    V1_0::StructFoo foo;
    foo.id = param3.id;
    foo.name = param3.name;
    auto ret = mCallback_1_0->notify(param1, param2, foo);
    if (!ret.isOk()) {
        ALOGE("%s: Unable to invoke callback", __func__);
    }
}

string MyHidl::getValue(string val) {
    if (mCallback_1_0 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return string("");
    }

    char* retStr;
    mCallback_1_0->getValue(val, [&](const hidl_string& ret_val) {
            memcpy((void *)retStr, ret_val.c_str(), ret_val.size());
        });

    return string(retStr);
}

StructFoo MyHidl::getValueExtra(uint32_t val) {
    StructFoo ret;
    memset(&ret, 0, sizeof(StructFoo));

    if (mCallback_1_0 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return ret;
    }

    mCallback_1_0->getValueExtra(val, [&](const V1_0::StructFoo& retVal) {
            memcpy(&ret, &retVal, sizeof(StructFoo));
        });

    return ret;
}

void MyHidl::onRequestExt(uint32_t param1, string param2) {
    if (mCallback_1_1 == nullptr) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return;
    }

    auto ret = mCallback_1_1->onRequestExt(param1, param2);
    if (!ret.isOk()) {
        ALOGE("%s: Unable to invoke callback", __func__);
    }
}

Return<bool> MyHidl::inputData(const hidl_vec<uint8_t>& val) {
    size_t size_val = val.size();
    if (size_val <= 0) {
        ALOGE("%s Invalid size %zu", __func__, size_val);
        return {false};
    }

    uint8_t *p_val = new uint8_t[size_val];
    if (nullptr == p_val) {
        ALOGE("%s Insufficient memory!", __func__);
        return {false};
    }

    copy(val.begin(), val.end(), p_val);
    bool ret = mDevice->inputData(mDevice, p_val, size_val);
    delete []p_val;
    return ret;
}

void MyHidl::outputData(uint8_t* const message, uint32_t const length) {
    if (nullptr == mCallback_1_2) {
        ALOGE("%s: Callback Interface configured incorrectly", __func__);
        return;
    }
    if (nullptr == message || length == 0) {
        ALOGE("%s: Invalid input parameters. message:[%p], length:[%d]",
                __func__, message, length);
        return;
    }

    std::vector<uint8_t> msg_vec;
    msg_vec.resize(length);
    msg_vec.assign(message, message + length);
    auto ret = mCallback_1_2->outputData((hidl_vec<uint8_t>)msg_vec);
    if (!ret.isOk()) {
        ALOGE("%s: Unable to invoke callback", __func__);
    }
}

// Methods from ::android::hidl::base::V1_0::IBase follow.

//IMyHidl* HIDL_FETCH_IMyHidl(const char* /* name */) {
    //return new MyHidl();
//}
//
}  // namespace com::xyz::hardware::myhidl::implementation
