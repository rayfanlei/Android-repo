This is an example of how to create HIDL service and HAL shared library.

Step 1: create hal file.
    xyz/hardware/interfaces/myhidl/1.0
    xyz/hardware/interfaces/myhidl/1.1
Step 2: create makefile.
    enter scripts folder
    run update-makefiles.sh
Step 3: create hash file
    run auto-hash.sh
    copy print out content and save to current.txt
Step 4: generate makefile, cpp and java files
    run auto-gen.sh

Comments:
Struct MyHidl derived from V1_1::IMyHidl who was created in intermediate files when building
out/soong/.intermediates/vendor/xyz/hardware/interfaces/myhidl/1.1/com.xyz.hardware.myhidl@1.1_genc++_headers/gen/com/xyz/hardware/myhidl/1.1/IMyHidl.h
V1_1::IMyHidl derived from V1_0::IMyHidl 
out/soong/.intermediates/vendor/xyz/hardware/interfaces/myhidl/1.0/com.xyz.hardware.myhidl@1.0_genc++_headers/gen/com/xyz/hardware/myhidl/1.0/IMyHidl.h
V1_0::IMyHidl derived from ::android::hidl::base::V1_0::IBase

manifest.xml is hidl interface manifest file
compatibility_matrix.xml is compatibility matrix file, it should appended by DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE

Sepolicy:
Append to hwservice_contexts
    com.xyz.hardware.myhidl::IMyHidl    u:object_r:hal_myhidl_hwservice:s0
Append to file_contexts
    /(vendor|system/vendor)/bin/hw/com.xyz.hardware.myhidl@1.1-service    u:object_r:hal_myhidl_exec:s0
Append to attributes
    # hal myhidl
    attribute hal_myhidl;
    attribute hal_myhidl_client;
    attribute hal_myhidl_server;
Create hal_myhidl.te
    # HwBinder IPC from client to server, and callbacks
    binder_call(hal_myhidl_client, hal_myhidl_server);
    binder_call(hal_myhidl_server, hal_myhidl_client);

    add_hwservice(hal_myhidl_server, hal_myhidl_hwservice);
    allow hal_myhidl_client hal_myhidl_hwservice:hwservice_manager find;
    allow shell vendor_file:file { getattr };
    allow shell hal_myhidl_hwservice:hwservice { find };
Create hal_myhidl_default.te
    type hal_myhidl_default, domain,coredomain;
    hal_server_domain(hal_myhidl_default, hal_myhidl)

    type hal_myhidl_default_exec, exec_type, file_type;
    init_daemon_domain(hal_myhidl_default)

