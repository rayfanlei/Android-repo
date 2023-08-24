#!/bin/bash
CURRENT_DIR=$(pwd)
export ANDROID_BUILD_TOP=$CURRENT_DIR/../../..
export PATH=$PATH:$ANDROID_BUILD_TOP/out/soong/host/linux-x86/bin/

LOC=$ANDROID_BUILD_TOP/vendor/xyz/hardware/interfaces/myhidl/1.1/default
PACKAGE=com.xyz.hardware.myhidl@1.1
SS=com.xyz.hardware:vendor/xyz/hardware/interfaces
TT=android.hidl:system/libhidl/transport

#Generate C++ files
hidl-gen -o $LOC -Lc++-impl -r$SS -r$TT $PACKAGE
echo End of generate C++ files

#Generate java files
hidl-gen -o $LOC -Ljava-impl -r$SS -r$TT $PACKAGE
echo End of generate java files

#Generate Android.bp for C++ files
hidl-gen -o $LOC -Landroidbp-impl -r$SS -r$TT $PACKAGE
echo End of generate Android.bp file
