#ifndef __MYHIDL_H__
#define __MYHIDL_H__

#include <hardware/hardware.h>

using namespace std;

#define MYHIDL_MODULE_API_VERSION_1_2 HARDWARE_MODULE_API_VERSION(1, 2)
#define MYHIDL_HARDWARE_MODULE_ID "myhidl"

enum RequestCode: uint32_t {
  REQ_UNKNOWN = 1,
  REQ_OK,
  REQ_ENOENT,
  REQ_EINTR,
  REQ_EIO,
};

enum ResponseCode: uint32_t {
  RSP_UNKNOWN = 1,
  RSP_OK,
  RSP_ENOENT,
  RSP_EINTR,
  RSP_EIO,
};

struct StructFoo {
    uint32_t id;
    string name;
};

typedef void (*ptr_on_request)(uint32_t param1, const ResponseCode param2, const char* param3);
typedef void (*ptr_on_error)(const char* val);
typedef void (*ptr_notify)(uint32_t param1, const char* param2, const StructFoo param3);
typedef string (*ptr_get_value)(string val);
typedef StructFoo (*ptr_get_value_extra)(uint32_t val);
typedef void (*ptr_on_request_ext)(uint32_t param1, string param2);
typedef void (*ptr_output_data)(uint8_t* const message, uint32_t const length);

typedef struct MyHidl_Callbacks {
    ptr_on_request on_request;
    ptr_on_error on_error;
    ptr_notify notify;
    ptr_get_value get_value;
    ptr_get_value_extra get_value_extra;
    ptr_on_request_ext on_request_ext;
    ptr_output_data output_data;
} myhidl_callbacks_t;

typedef struct myhidl_device {
    struct hw_device_t common;

    bool (*init)(struct myhidl_device *dev, myhidl_callbacks_t* callbacks);
    bool (*setFunc)(struct myhidl_device *dev, int32_t val);
    int32_t (*getFunc)(struct myhidl_device *dev);
    char* (*functionFoo)(struct myhidl_device *dev, uint32_t param1, const StructFoo param2);
    uint32_t (*functionBar)(struct myhidl_device *dev, uint64_t param1);
    ResponseCode functionOrr(RequestCode req);
    uint32_t (*functionPss)(struct myhidl_device *dev, uint32_t param1);
    uint8_t* (*functionQtt)(struct myhidl_device *dev);
    char* (*functionExt)(struct myhidl_device *dev);
    bool (*inputData)(struct myhidl_device* dev, uint8_t* value, uint32_t size);

} myhidl_device_t;

typedef struct myhidl_module {
    struct hw_module_t common;
} myhidl_module_t;

#endif  /* __MYHIDL_H__ */
