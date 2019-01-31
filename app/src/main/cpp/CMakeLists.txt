cmake_minimum_required(VERSION 3.6)
project(dlfcn_compat_sample)

###dlfcn
set(dlfcn_compat_root_dir ${CMAKE_SOURCE_DIR}/../../../../dlfcn)
add_subdirectory(${dlfcn_compat_root_dir} dlfcn)
include_directories(
         ${dlfcn_compat_root_dir}/include/
)



set(DLOPEN_COMPAT_FILES ${CMAKE_SOURCE_DIR}/sample.cpp)

add_library(dlfcn_compat_sample SHARED ${DLOPEN_COMPAT_FILES})
target_link_libraries(dlfcn_compat_sample
        dlfcn_compat_static
        log
)
