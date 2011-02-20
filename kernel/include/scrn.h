#ifndef _SCRN_H
#define _SCRN_H

#define VIDEO_MEMORY (s16int *)0xB8000;

u32int scrn_cursor_x;
u32int scrn_cursor_y;
u32int scrn_page;

void scrn_init(void);
void scrn_putc(s8int);
void scrn_clear(void);
u32int scrn_puts(s8int *);
void scrn_scroll(s8int);
void scrn_move_cursor(void);

#endif
