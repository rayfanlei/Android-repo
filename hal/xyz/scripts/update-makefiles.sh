#!/bin/bash
CURRENT_DIR=$(pwd)
export ANDROID_BUILD_TOP=$CURRENT_DIR/../../..
export PATH=$PATH:$ANDROID_BUILD_TOP/out/soong/host/linux-x86/bin/
source $ANDROID_BUILD_TOP/system/tools/hidl/update-makefiles-helper.sh

do_makefiles_update \
  "com.xyz.hardware:vendor/xyz/hardware/interfaces" \
  "android.hidl:system/libhidl/transport"

# com.xyz.hardware   is package name
# vendor/xyz/hardware/interfaces   is file path name
