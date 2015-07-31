# toolchain file for building a 32bit version on a 64bit host

# Usage:
# cmake -DCMAKE_TOOLCHAIN_FILE=linux_arm_toolchain.cmake 

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
#set(CMAKE_SYSTEM_PROCESSOR "i686")
set(CMAKE_SYSTEM_PROCESSOR "armv7")
set(CMAKE_C_COMPILER "arm-hisiv100nptl-linux-gcc")
set(CMAKE_CXX_COMPILER "arm-hisiv100nptl-linux-g++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g" CACHE STRING "c++ flags")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -g" CACHE STRING "c flags")
