#include "common.h"

void outb(u16int port, u8int value) {
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port) {
	u8int ret;
	asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u16int inw(u16int port) {
	u16int ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u16int *kmemsetw(u16int *dest, s16int val, s32int times) {
	s32int i;
	for (i = 0; i < times; dest[i] = val, i++)
		;
	return dest;
}

u8int *kmemset(u8int *dest, s8int val, s32int times) {
	s32int i;
	for (i = 0; i < times; dest[i] = val, i++)
		;
	return dest;
}

u8int *kmemcpy(u8int *dest, u8int *src, s32int times) {
	s32int i;
	for (i = 0; i < times; dest[i] = src[i], i++)
		;
	return dest;
}
