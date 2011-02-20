#ifndef _COMMON_H
#define _COMMON_H

/* some typedefs */
typedef unsigned 	int 	u32int;
typedef				int		s32int;
typedef unsigned	short	u16int;
typedef 			short	s16int;
typedef unsigned	char	u8int;
typedef				char	s8int;

u16int *kmemsetw(u16int *, s16int, s32int);
u8int *kmemset(u8int *, s8int, s32int);
u8int *kmemcpy(u8int *, u8int *, s32int);
void outb(u16int, u8int);
u8int inb(u16int);
u16int inw(u16int);

#endif
