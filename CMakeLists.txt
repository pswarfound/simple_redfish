cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)


SET(ARCH "x86_64" CACHE STRING "")

message(${ARCH})
if (${ARCH} STREQUAL "arm")
    set(ARCH arm)
    set(TOOLCHAIN_PATH /mnt/ram0/bmc2/work/workspace/tools/arm-soft-linux-gnueabi/bin/)
    set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}arm-soft-linux-gnueabi-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}arm-soft-linux-gnueabi-g++)
endif()

project(simple_redfish
    VERSION 1.0.0
)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)