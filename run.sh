#!/usr/bin

sudo losetup /dev/loop0 floppy.img
bochs -q
