#!/bin/bash

sudo mount floppy.img floppy_mount/ -t ext2 -o loop
sleep 2
cp kernel/kernel.bin floppy_mount/boot/ -v
sleep 2
sudo umount floppy_mount/
