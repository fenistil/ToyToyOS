#!/bin/bash

sudo mount floppy.img floppy_mount/ -t ext2 -o loop
sleep 3
cp kernel/kernel.bin floppy_mount/boot/ -v
sleep 5
sudo umount floppy_mount/
