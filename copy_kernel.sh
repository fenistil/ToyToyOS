#!/bin/bash

sudo mount floppy.img floppy_mount/ -t ext2 -o loop
cp kernel/kernel.bin floppy_mount/boot/
sudo umount floppy_mount/
