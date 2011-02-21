#ifndef _COMMON_H
#define _COMMON_H

/* some typedefs */
typedef unsigned int u32int_t;
typedef int s32int_t;
typedef unsigned short u16int_t;
typedef short s16int_t;
typedef unsigned char u8int_t;
typedef char s8int_t;

u16int_t *kmemsetw(u16int_t *, s16int_t, s32int_t);
u8int_t *kmemset(u8int_t *, s8int_t, s32int_t);
u8int_t *kmemcpy(u8int_t *, u8int_t *, s32int_t);
void outb(u16int_t, u8int_t);
u8int_t inb(u16int_t);
u16int_t inw(u16int_t);

#endif
