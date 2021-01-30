#!/usr/bin/env bash

function help() {
    echo "Options:"
    echo "--fs_only  / -f: Setup and flash filesystem only, use for SRAM and EXTMEM builds."
    echo "--fs_swmem / -s: Setup and flash filesystem and swmem data, use for SWMEM builds."
    return
}

if [ $# == 1 ]
then
    if [ "$1" == "--help" ] || [ "$1" == "-h" ]
    then
        help
    elif [ "$1" == "--fs_only" ] || [ "$1" == "-f" ]
    then
        ./create_fs.sh
        xflash --quad-spi-clock 50MHz --factory ../bin/cifar10.xe --boot-partition-size 0x100000 --data ./fat.fs
    elif [ "$1" == "--fs_swmem" ] || [ "$1" == "-s" ]
    then
        echo "NOT YET TESTED!"
        echo "Create filesystem..."
        ./create_fs.sh
        pushd ./
        cd ../bin/$2
        echo "Extract swmem..."
        xobjdump --strip cifar10.xe
        xobjdump --split cifar10.xb
        cp image_n0c1.swmem ../../filesystem_support
        popd
        echo "Combine filesystem and swmem..."
        cat fat.fs | dd of=image_n0c1.swmem bs=1 seek=1048576 conv=notrunc

        echo "Flash device..."
        xflash --write-all image_n0c1.swmem --target-file ../XCORE-AI-EXPLORER.xn
        echo "Done"
    else
        help
    fi
else
    help
fi
