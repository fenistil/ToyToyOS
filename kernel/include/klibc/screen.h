#ifndef _H_SCREEN
#define _H_SCREEN

#include "common.h"

#define VIDEO_MEMORY (s16int_t *)0xB8000;
#define SCRN_WIDTH 80
#define SCRN_HEIGHT 25

#define WHITE 0xF
#define GRAY 0x7
#define BLACK 0x0
#define BLUE 0x1
#define RED 0x4
#define MAG 0x5

extern u32int_t scrn_cursor_x;
extern u32int_t scrn_cursor_y;
extern u32int_t scrn_page;
extern u32int_t scrn_color;

void scrn_init();
void scrn_set_textcolor(s8int_t, s8int_t);
void scrn_clear();
void scrn_scroll();
void scrn_move_cursor();

#endif
