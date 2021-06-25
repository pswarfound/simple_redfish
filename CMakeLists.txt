cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

if (TRUE)
#if (FALSE)
    set(ARCH x86_64)
else()
    set(ARCH arm)
    set(TOOLCHAIN_PATH /mnt/ram0/bmc/work/workspace/tools/arm-soft-linux-gnueabi/bin/)
    set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}arm-soft-linux-gnueabi-gcc)
endif()

message(${ARCH})

project(simple_redfish
    VERSION 1.0.0 
    LANGUAGES C
)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

add_subdirectory(src)
add_subdirectory(test)