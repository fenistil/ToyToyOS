#include "common.h"
#include "scrn.h"

u32int scrn_cursor_x;
u32int scrn_cursor_y;
u32int scrn_page;
u8int scrn_color;

void scrn_init() {
	scrn_cursor_x = 0;
	scrn_cursor_y = 0;
	scrn_page = 0;
	scrn_set_textcolor(BLACK, WHITE);
}

void scrn_putc(s8int c) {
	s16int *vid = VIDEO_MEMORY;
	vid += scrn_cursor_y * 80 + scrn_cursor_x;
	switch (c) {
	case '\n':
		scrn_cursor_y++;
		break;
	case '\t':
		if (scrn_cursor_x + 4 > 78) {
			scrn_cursor_x = 0;
			scrn_cursor_y++;
		} else {
			while ((scrn_cursor_x + 1) % 4 != 0) {
				scrn_cursor_x++;
			}
			scrn_cursor_x++;
		}
		break;
	default:
		*vid = c | scrn_color << 8;
		if (scrn_cursor_x + 1 > 78) {
			scrn_cursor_x = 0;
			scrn_cursor_y++;
		} else {
			scrn_cursor_x++;
		}
		break;
	}
	scrn_scroll();
	//scrn_move_cursor();
}

void scrn_clear(void) {
	u16int *vid = (u16int *) VIDEO_MEMORY;
	kmemsetw(vid, ' ' | 0x0, 80 * 25);
}

void scrn_puts(s8int *str) {
	int i;
	while (str[i] != '\0') {
		scrn_putc(str[i]);
		i++;
	}
}

void scrn_scroll() {
	int a,b = 2;
	if ( 1 == 1 ) {
		a = b;
	}

}

void scrn_move_cursor(void) {
	u16int cursorLocation = scrn_cursor_y * 80 + scrn_cursor_x;
	outb(0x3D4, 14);
	outb(0x3D5, cursorLocation >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, cursorLocation);
}

void scrn_set_textcolor(s8int bg, s8int fg) {
	scrn_color = bg << 4 | fg;
}
