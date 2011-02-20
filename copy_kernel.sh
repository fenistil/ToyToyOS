#!/bin/bash

mount floppy.imh floppy_mount/ -t ext2 -o loop
cp kernel/kernel.bin floppy_mount/boot/
umount floppy_mount/
