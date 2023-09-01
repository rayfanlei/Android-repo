#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include <string>

#include <log/log.h>

#include <hardware/hardware.h>
#include <../../include/hardware/myhidl.h>

using namespace std;

#undef LOG_TAG
#define LOG_TAG "MyHidlHal"

myhidl_callbacks_t* sCallbacks = nullptr;

static bool init(struct myhidl_device __unused *dev, myhidl_callbacks_t* callbacks) {
    sCallbacks = callbacks;
    return true;
}

static int closeImpl(hw_device_t *dev)
{
    if (dev) {
        free(dev);
        return 0;
    } else {
        return -1;
    }
}

static bool setFuncImpl(struct myhidl_device __unused *dev, int32_t val) {
    int32_t v = val;
    ALOGV("%d", v);
    return true;
}

static int32_t getFuncImpl(struct myhidl_device __unused *dev) {
    return 0;
}

static uint32_t functionBarImpl(struct myhidl_device __unused *dev, uint64_t param1) {
    uint32_t v = (uint32_t)param1;
    ALOGV("%d", v);
    return 0;
}

static uint32_t functionPssImpl(struct myhidl_device __unused *dev, uint32_t param1) {
    uint32_t v = param1;
    ALOGV("%d", v);
    return 0;
}

static uint8_t* functionQttImpl(struct myhidl_device __unused *dev) {
    return NULL;
}

static char* functionExtImpl(struct myhidl_device __unused *dev) {
    return NULL;
}

static bool inputDataImpl(struct myhidl_device __unused *dev, uint8_t* value, uint32_t size) {
    if (nullptr == value || size <= 0) {
        ALOGE("Invalid input parameters!");
        return false;
    }

    return false;
}

static int myhidlsvc_open(const hw_module_t* module, const char __unused *id,
                            hw_device_t** device)
{
    if (device == NULL) {
        ALOGE("NULL device on open");
        return -EINVAL;
    }

    myhidl_device_t* dev = (myhidl_device_t*)malloc(sizeof(myhidl_device_t));
    memset(dev, 0, sizeof(myhidl_device_t));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = MYHIDL_MODULE_API_VERSION_1_2;
    dev->common.module = (struct hw_module_t*) module;
    dev->common.close = closeImpl;

    dev->setFunc = setFuncImpl;
    dev->getFunc = getFuncImpl;
    dev->functionBar = functionBarImpl;
    dev->functionPss = functionPssImpl;
    dev->functionQtt = functionQttImpl;
    dev->functionExt = functionExtImpl;
    dev->inputData = inputDataImpl;

    *device = (hw_device_t*) dev;
    return 0;
}

static struct hw_module_methods_t myhidlsvc_module_methods = {
    .open = myhidlsvc_open,
};

myhidl_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag                = HARDWARE_MODULE_TAG,
        .module_api_version = MYHIDL_MODULE_API_VERSION_1_2,
        .hal_api_version    = HARDWARE_HAL_API_VERSION,
        .id                 = MYHIDL_HARDWARE_MODULE_ID,
        .name               = "MyHidlSvc HAL",
        .author             = "The Android Open Source Project",
        .methods            = &myhidlsvc_module_methods,
    },
};
