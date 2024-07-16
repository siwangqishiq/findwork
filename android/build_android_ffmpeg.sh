#!/bin/bash

NDK=/d/ndk/android-ndk-r21e-windows-x86_64/android-ndk-r21e
API=23
TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/windows-x86_64
CPU=armv7-a
PREFIX=$(pwd)/build_android/$CPU
SYSROOT=$TOOLCHAIN/sysroot

function build_ffmpeg {
    ./configure \
        --prefix=$PREFIX \
        --target-os=android \
        --arch=arm \
        --cpu=$CPU \
        --cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
        --sysroot=$SYSROOT \
        --cc=$TOOLCHAIN/bin/armv7a-linux-androideabi$API-clang \
        --cxx=$TOOLCHAIN/bin/armv7a-linux-androideabi$API-clang++ \
        --disable-static \
        --enable-shared \
        --disable-doc \
        --disable-ffplay \
        --disable-ffmpeg \
        --disable-ffprobe \
        --disable-symver \
        --disable-debug \
        --enable-cross-compile \
        --disable-programs

    make -j8
    make install
}

build_ffmpeg


