cmake_minimum_required(VERSION 3.6)
project(dlfcn_compat_static)

set(dlfcn_compat_static_sources
        ${CMAKE_CURRENT_SOURCE_DIR}/dlfcn_compat.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/dlfcn_nougat.cpp)

set(dlfcn_compat_static_header
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

include_directories(
        ${dlfcn_compat_static_header}
)

 message(STATUS "dlfcn_compat_static_sources=${dlfcn_compat_static_sources}")
 message(STATUS "dlfcn_compat_static_header=${dlfcn_compat_static_header}")

add_library(dlfcn_compat_static STATIC ${dlfcn_compat_static_sources})
target_link_libraries(dlfcn_compat_static log)
