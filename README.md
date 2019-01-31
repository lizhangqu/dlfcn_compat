### Thanks

Android N的实现来自 https://github.com/avs333/Nougat_dlfunctions

做了一点优化处理
 - 支持除arm之外的CPU架构以支持模拟器，x86，x86_64经过验证没问题，mips和mips64可编译但没经过验证。
 - 支持传递文件名而非绝对路径
 - 不需要进行版本特判，统一使用compat函数，内部进行逻辑分发
    
### 技术原理

见美团的《Android远程调试的探索与实现》相关文章中"符号化"和"突破7.0动态链接的限制"两部分

[Android远程调试的探索与实现](https://tech.meituan.com/2017/07/20/android-remote-debug.html)


### 使用方式

引入cmake

```
set(dlfcn_compat_root_dir /path/to/dlfcn)
add_subdirectory(${dlfcn_compat_root_dir} dlfcn)
include_directories(
         ${dlfcn_compat_root_dir}/include/
)
```

链接静态库

```
target_link_libraries(yourSharedLibrary
        dlfcn_compat_static
)
```

引入头文件

```
#include "dlfcn_compat.h"
```

相关函数

```
extern "C" {

void *dlopen_compat(const char *filename, int flags);

void *dlsym_compat(void *handle, const char *symbol);

int dlclose_compat(void *handle);

const char *dlerror_compat();

int get_sdk_level();

}
```

sample 见 app/src/main/cpp/sample.cpp