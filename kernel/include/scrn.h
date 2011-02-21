#ifndef _SCRN_H
#define _SCRN_H

#define WHITE 0xF
#define GRAY 0x7
#define BLACK 0x0
#define BLUE 0x1
#define RED 0x4
#define MAG 0x5

#define VIDEO_MEMORY (s16int_t *)0xB8000;

u32int_t scrn_cursor_x;
u32int_t scrn_cursor_y;
u8int_t scrn_color;

void scrn_init(void);
void scrn_putc(s8int_t);
void scrn_clear(void);
void scrn_puts(s8int_t *);
void scrn_scroll(void);
void scrn_move_cursor(void);
void scrn_set_textcolor(s8int_t, s8int_t);

#endif
