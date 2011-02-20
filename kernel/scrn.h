#ifndef _SCRN_H
#define _SCRN_H

#include "common.h" /* for the typedefs */

#define VIDEO_MEMORY (s16int *)0xB8000;

volatile u32int scrn_cursor_x;
volatile u32int scrn_cursor_y;
volatile u32int scrn_page;

void scrn_init(void);
void scrn_putc(s8int);
void scrn_clear(void);
u32int scrn_puts(s8int *);
void scrn_scroll(s18int);
void scrn_move_cursor(void);

#endif
