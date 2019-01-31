#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <dlfcn.h>
#include "dlfcn_compat.h"

#define LOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, "dlfcn_sample", fmt, ##__VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL Java_io_github_lizhangqu_dlfcn_sample_NativeBridge_dlfcnTest(
        JNIEnv *env,
        jclass clazz) {

    void *handle = dlopen_compat("libutils.so", RTLD_NOW);

    if (!handle) {
        LOGE("cannot load libutils.so\n");
        return;
    }


    // Constructor:  android::String8::String8(char const*)
    // The first argument is a pointer where "this" of a new object is to be stored.

    void (*create_string)(void **, const char *) =
    (typeof(create_string)) dlsym_compat(handle, "_ZN7android7String8C1EPKc");

    // Member function:  size_t android::String8::getUtf32Length() const
    // The argument is a pointer to "this" of the object

    size_t(*get_len)(void * *) =
            (typeof(get_len)) dlsym_compat(handle, "_ZNK7android7String814getUtf32LengthEv");

    // Destructor:  android::String8::~String8()

    void (*delete_string)(void **) =
    (typeof(delete_string)) dlsym_compat(handle, "_ZN7android7String8D1Ev");

    // All required library addresses known now, so don't need its handle anymore

    dlclose_compat(handle);

    if (!create_string || !get_len || !delete_string) {
        LOGE("required functions missing in libutils.so\n");
        return;
    }

    // Fire up now.

    void *str8 = 0;
    const char *str = "Hello, world!";

    create_string(&str8, str);
    if (!str8) {
        LOGE("failed to create string\n");
        return;
    }

    size_t len = get_len(&str8);
    LOGE("%s: length = %d", str, (int) len);

    delete_string(&str8);


}
