#include "klibc/screen.h"
#include "common.h"

u32int_t scrn_cursor_x;
u32int_t scrn_cursor_y;
u32int_t scrn_page;
u32int_t scrn_color;

void scrn_move_cursor() {
	u16int_t cursorLocation = scrn_cursor_y * SCRN_WIDTH + scrn_cursor_y;
	outb(0x3D4, 14);
	outb(0x3D5, cursorLocation >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, cursorLocation);
}

void scrn_set_textcolor(s8int_t bg, s8int_t fg) {
	scrn_color = bg << 4 | fg;
}

void scrn_init() {
	scrn_cursor_x = 0;
	scrn_cursor_y = 0;
	scrn_page = 0;
	scrn_set_textcolor(BLACK, WHITE);
	scrn_move_cursor();
}

void scrn_clear() {
	u16int_t *vid = (u16int_t *) VIDEO_MEMORY;
	kmemsetw(vid, ' ' | 0x0, 80 * 25);
}

void scrn_scroll() {
	s32int_t i;
	u16int_t blank = 0;
	s16int_t *video;
	video = VIDEO_MEMORY;
	if (scrn_cursor_y >= SCRN_HEIGHT) {
		for (i = 0; i < (SCRN_HEIGHT-1) * SCRN_WIDTH; i++) {
			video[i] = video[i + SCRN_WIDTH];
		}
		for (i = (SCRN_HEIGHT-1) * SCRN_WIDTH; i < SCRN_HEIGHT * SCRN_WIDTH; i++) {
			video[i] = blank;
		}
		scrn_cursor_y = SCRN_HEIGHT-1;
		scrn_cursor_x = 0;
	}
}
