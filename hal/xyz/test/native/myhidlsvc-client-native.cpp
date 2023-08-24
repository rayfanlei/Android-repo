#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <android-base/strings.h>
#include <vendor/xyz/hardware/myhidlsvc/1.1/IMyHidlSvc.h>
#include <hidl/Status.h>
#include <hidl/LegacySupport.h>
#include <hidl/HidlSupport.h>
#include "MyHidlSvcClientCallback.h"

using namespace ::vendor::xyz::hardware::myhidlsvc;
using ::android::sp;

int main(int argc, char**argv) {
    sp<V1_1::IMyHidlSvc> service = V1_1::IMyHidlSvc::getService();

    V1_0::IMyHidlSvcClientCallback *callback = new MyHidlSvcClientCallback();
    std::cout << "before subscribe" << std::endl;
    bool retBool = service->subscribe(callback);
    std::cout << "subscribe return " << retBool << std::endl;

    std::cout << "before getFunc return " << std::endl;
    int32_t retInt = service->getFunc();
    std::cout << "getFunc return " << retInt << std::endl;

    return 0;
}
