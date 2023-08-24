#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <log/log.h>

#include <hardware/hardware.h>
#include <../../include/hardware/myhidlsvc.h>

#undef LOG_TAG
#define LOG_TAG "MyHidlSvcHal"

static int myhidlsvc_close(hw_device_t *dev)
{
    if (dev) {
        free(dev);
        return 0;
    } else {
        return -1;
    }
}

static bool setFuncImpl(struct myhidlsvc_device __unused *dev, int32_t val) {
    int32_t v = val;
    ALOGV("%d", v);
    return true;
}

static int32_t getFuncImpl(struct myhidlsvc_device __unused *dev) {
    return 0;
}

static uint32_t functionBarImpl(struct myhidlsvc_device __unused *dev, uint64_t param1) {
    uint32_t v = (uint32_t)param1;
    ALOGV("%d", v);
    return 0;
}

static uint32_t functionPssImpl(struct myhidlsvc_device __unused *dev, uint32_t param1) {
    uint32_t v = param1;
    ALOGV("%d", v);
    return 0;
}

static uint8_t* functionQttImpl(struct myhidlsvc_device __unused *dev) {
    return NULL;
}

static char* functionExtImpl(struct myhidlsvc_device __unused *dev) {
    return NULL;
}

static int myhidlsvc_open(const hw_module_t* module, const char __unused *id,
                            hw_device_t** device)
{
    if (device == NULL) {
        ALOGE("NULL device on open");
        return -EINVAL;
    }

    myhidlsvc_device_t *dev = malloc(sizeof(myhidlsvc_device_t));
    memset(dev, 0, sizeof(myhidlsvc_device_t));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = MYHIDLSVC_MODULE_API_VERSION_1_1;
    dev->common.module = (struct hw_module_t*) module;
    dev->common.close = myhidlsvc_close;

    dev->setFunc = setFuncImpl;
    dev->getFunc = getFuncImpl;
    dev->functionBar = functionBarImpl;
    dev->functionPss = functionPssImpl;
    dev->functionQtt = functionQttImpl;
    dev->functionExt = functionExtImpl;

    *device = (hw_device_t*) dev;
    return 0;
}

static struct hw_module_methods_t myhidlsvc_module_methods = {
    .open = myhidlsvc_open,
};

myhidlsvc_module_t HAL_MODULE_INFO_SYM = {
    .common = {
        .tag                = HARDWARE_MODULE_TAG,
        .module_api_version = MYHIDLSVC_MODULE_API_VERSION_1_1,
        .hal_api_version    = HARDWARE_HAL_API_VERSION,
        .id                 = MYHIDLSVC_HARDWARE_MODULE_ID,
        .name               = "MyHidlSvc HAL",
        .author             = "The Android Open Source Project",
        .methods            = &myhidlsvc_module_methods,
    },
};
