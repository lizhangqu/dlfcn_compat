#include <dlfcn_compat.h>
#include "include/dlfcn_nougat.h"
#include <sys/system_properties.h>
#include <stdlib.h>
#include <dlfcn.h>

static int SDK_INT = -1;

extern "C" {

int get_sdk_level() {
    if (SDK_INT > 0) {
        return SDK_INT;
    }
    char sdk[PROP_VALUE_MAX] = {0};;
    __system_property_get("ro.build.version.sdk", sdk);
    SDK_INT = atoi(sdk);
    return SDK_INT;
}


int dlclose_compat(void *handle) {
    if (get_sdk_level() >= 24) {
        return fake_dlclose(handle);
    } else {
        return dlclose(handle);
    }
}

void *dlopen_compat(const char *filename, int flags) {
    if (get_sdk_level() >= 24) {
        return fake_dlopen(filename, flags);
    } else {
        return dlopen(filename, flags);
    }
}

void *dlsym_compat(void *handle, const char *symbol) {
    if (get_sdk_level() >= 24) {
        return fake_dlsym(handle, symbol);
    } else {
        return dlsym(handle, symbol);
    }
}

const char *dlerror_compat() {
    if (get_sdk_level() >= 24) {
        return fake_dlerror();
    } else {
        return dlerror();
    }
}
}