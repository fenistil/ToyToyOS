#include "common.h"

void outb(u16int_t port, u8int_t value) {
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int_t inb(u16int_t port) {
	u8int_t ret;
	asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u16int_t inw(u16int_t port) {
	u16int_t ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u32int_t *kmemsetww(u32int_t *dest, s32int_t val, s32int_t times) {
	s32int_t i;
	for (i = 0; i < times; dest[i] = val, i++)
		;
	return dest;
}

u16int_t *kmemsetw(u16int_t *dest, s16int_t val, s32int_t times) {
	s32int_t i;
	for (i = 0; i < times; dest[i] = val, i++)
		;
	return dest;
}

u8int_t *kmemset(u8int_t *dest, s8int_t val, s32int_t times) {
	s32int_t i;
	for (i = 0; i < times; dest[i] = val, i++)
		;
	return dest;
}

u8int_t *kmemcpy(u8int_t *dest, u8int_t *src, s32int_t times) {
	s32int_t i;
	for (i = 0; i < times; dest[i] = src[i], i++)
		;
	return dest;
}
