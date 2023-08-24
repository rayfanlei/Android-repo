#!/bin/bash
CURRENT_DIR=$(pwd)
export ANDROID_BUILD_TOP=$CURRENT_DIR/../../..
export PATH=$PATH:$ANDROID_BUILD_TOP/out/soong/host/linux-x86/bin/

LOC=$ANDROID_BUILD_TOP/vendor/xyz/hardware/interfaces/myhidl/1.0/default
PACKAGE=com.xyz.hardware.myhidl@1.0
SS=com.xyz.hardware:vendor/xyz/hardware/interfaces
TT=android.hidl:system/libhidl/transport

hidl-gen -L hash -r$SS -r$TT $PACKAGE

LOC=$ANDROID_BUILD_TOP/vendor/xyz/hardware/interfaces/myhidl/1.1/default
PACKAGE=com.xyz.hardware.myhidl@1.1
SS=com.xyz.hardware:vendor/xyz/hardware/interfaces
TT=android.hidl:system/libhidl/transport

hidl-gen -L hash -r$SS -r$TT $PACKAGE
