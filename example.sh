#!/bin/bash

# Check Installation supports this example
checkinstall.exe -p install.pkg --nobanner || exit

cd application
make clean
cd ../module
make clean
cd ..

CROSS=OR1K

make -C application CROSS=${CROSS}

# generate and compile the iGen created module
make -C module 

# run the module using the harness
harness.exe --modulefile module/model.${IMPERAS_SHRSUF} \
            --program twoProcessorShared/P0=application/master.${CROSS}.elf \
            --program twoProcessorShared/P1=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P2=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P3=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P4=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P5=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P6=application/slave.${CROSS}.elf \
            --program twoProcessorShared/P7=application/slave.${CROSS}.elf \
            $* --imperasintercepts --parallelmax
