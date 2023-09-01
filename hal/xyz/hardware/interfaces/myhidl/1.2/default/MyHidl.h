// FIXME: your file license if you have one

#pragma once

#include <android/log.h>
#include <com/xyz/hardware/myhidl/1.0/types.h>
#include <com/xyz/hardware/myhidl/1.2/IMyHidl.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <../../../../libhardware/include/hardware/myhidl.h>

namespace com::xyz::hardware::myhidl::implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_death_recipient;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
using ::android::wp;

struct MyHidl : public V1_2::IMyHidl {
    public:
        MyHidl();
        ~MyHidl();

        static V1_2::IMyHidl* getInstance(void);

        // Methods from ::com::xyz::hardware::myhidl::V1_0::IMyHidl follow.
        Return<bool> subscribe_1_0(const sp<V1_0::IMyHidlCallback>& callback) override;
        Return<bool> subscribe_1_1(const sp<V1_1::IMyHidlCallback>& callback) override;
        Return<bool> subscribe_1_2(const sp<V1_2::IMyHidlCallback>& callback) override;
        Return<bool> setFunc(int32_t val) override;
        Return<int32_t> getFunc() override;
        Return<void> functionFoo(uint32_t param1, const V1_0::StructFoo& param2, functionFoo_cb _hidl_cb) override;
        Return<uint32_t> functionBar(uint64_t param1, const hidl_string& param2) override;
        Return<V1_0::ResponseCode> functionOrr(V1_0::RequestCode req) override;
        Return<uint32_t> functionPss(uint32_t param1, const hidl_vec<uint8_t>& param2) override;
        Return<void> functionQtt(const hidl_vec<uint8_t>& val, functionQtt_cb _hidl_cb) override;

        // Methods from ::com::xyz::hardware::myhidl::V1_1::IMyHidl follow.
        Return<void> functionExt(const hidl_string& argv, functionExt_cb _hidl_cb) override;

        // Methods from ::com::xyz::hardware::myhidl::V1_2::IMyHidl follow.
        Return<bool> inputData(const hidl_vec<uint8_t>& val) override;

        // Methods from ::android::hidl::base::V1_0::IBase follow.

    private:
        static myhidl_device_t* openHal();
        static void onRequest(uint32_t param1, const ResponseCode param2, const char* param3);
        static void onError(const char* val);
        static void notify(uint32_t param1, const char* param2, const StructFoo param3);
        static string getValue(string val);
        static StructFoo getValueExtra(uint32_t val);
        static void onRequestExt(uint32_t param1, string param2);
        static void outputData(uint8_t* const message, uint32_t const length);

        static myhidl_callbacks_t sHalCallbacks;
        static sp<V1_0::IMyHidlCallback> mCallback_1_0;
        static sp<V1_1::IMyHidlCallback> mCallback_1_1;
        static sp<V1_2::IMyHidlCallback> mCallback_1_2;

        class MyHidlDeathRecipient : public hidl_death_recipient {
            public:
                MyHidlDeathRecipient(const sp<MyHidl> myhidl) : mMyHidl(myhidl) {
                }

                virtual void serviceDied(uint64_t /*cookie*/,
                        const wp<::android::hidl::base::V1_0::IBase>& /*who*/) {
                    mMyHidl->handleHidlDeath();
                }
            private:
                sp<MyHidl> mMyHidl;
        };

        void handleHidlDeath();

        static MyHidl* sInstance;
        sp<MyHidlDeathRecipient> mDeathRecipient_1_0;
        sp<MyHidlDeathRecipient> mDeathRecipient_1_1;
        sp<MyHidlDeathRecipient> mDeathRecipient_1_2;
        std::mutex mCallbackMutex_1_0;
        std::mutex mCallbackMutex_1_1;
        std::mutex mCallbackMutex_1_2;
        myhidl_device_t* mDevice;
};

// FIXME: most likely delete, this is only for passthrough implementations
// extern "C" IMyHidl* HIDL_FETCH_IMyHidl(const char* name);

}  // namespace com::xyz::hardware::myhidl::implementation
