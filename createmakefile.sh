#!/bin/bash
cmake -DCMAKE_TOOLCHAIN_FILE=./cmake/linux_arm_toolchain.cmake -DWITH_OPENSSL=Off 
#cmake -DCMAKE_TOOLCHAIN_FILE=./cmake/linux_x86_toolchain.cmake 
