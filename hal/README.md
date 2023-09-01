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
Create hal_myhidl.te
    type hal_myhidl_exec, exec_type, vendor_file_type, file_type;
    type hal_myhidl_hwservice,  hwservice_manager_type;
    type hal_myhidl, domain;
    net_domain(hal_myhidl)
    domain_auto_trans(shell, hal_myhidl_exec, hal_myhidl)
    init_daemon_domain(hal_myhidl)
    hwbinder_use(hal_myhidl)

    #allow hal_myhidl self:capability { setuid setgid net_raw chown fsetid net_admin sys_module fsetid sys_nice };
    get_prop(hal_myhidl, hwservicemanager_prop)
    add_hwservice(hal_myhidl, hal_myhidl_hwservice)
    allow shell hal_myhidl_hwservice:hwservice_manager find;
    binder_call(hal_myhidl, system_app)

