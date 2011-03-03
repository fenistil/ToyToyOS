#include "common.h"
#include "scrn.h"

/*static u32int_t scrn_cursor_x;
static u32int_t scrn_cursor_y;
static u32int_t scrn_page;
static u8int_t scrn_color;*/

/*inline void scrn_move_cursor(void);
 inline void scrn_scroll(void);*/

/*void scrn_move_cursor(void) {
	u16int_t cursorLocation = scrn_cursor_y * 80 + scrn_cursor_x;
	outb(0x3D4, 14);
	outb(0x3D5, cursorLocation >> 8);
	outb(0x3D4, 15);
	outb(0x3D5, cursorLocation);
}*/

/*void scrn_init() {
	scrn_cursor_x = 0;
	scrn_cursor_y = 0;
	scrn_page = 0;
	scrn_set_textcolor(BLACK, WHITE);
	scrn_move_cursor();
}*/

/*void scrn_scroll(void) {
	s32int_t i;
	u16int_t blank = 0;
	s16int_t *video;
	video = VIDEO_MEMORY;
	if (scrn_cursor_y >= 25) {
		for (i = 0; i < 24 * 80; i++) {
			video[i] = video[i + 80];
		}
		for (i = 24 * 80; i < 25 * 80; i++) {
			video[i] = blank;
		}
		scrn_cursor_y = 24;
		scrn_cursor_x = 0;
	}
}*/

/*void scrn_putc(s8int_t c) {
	s16int_t *vid = VIDEO_MEMORY;
	vid += scrn_cursor_y * 80 + scrn_cursor_x;
	switch (c) {
	case '\n':
		scrn_cursor_y++;
		scrn_cursor_x = 0;
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
	scrn_move_cursor();
}*/

/*void scrn_clear(void) {
	u16int_t *vid = (u16int_t *) VIDEO_MEMORY;
	kmemsetw(vid, ' ' | 0x0, 80 * 25);
}*/

/*void scrn_puts(s8int_t *str) {
	u32int_t i = 0;
	while (str[i] != '\0') {
		scrn_putc(str[i]);
		i++;
	}
}*/

/*void scrn_set_textcolor(s8int_t bg, s8int_t fg) {
	scrn_color = bg << 4 | fg;
}*/

/*void scrn_put_dec(s32int_t dec) {
	s8int_t digits[10];
	s32int_t i;
	for (i = 0; i < 10; i++) {
		digits[i] = (dec % 10) + '0';
		dec = (s32int_t) (dec / 10);
	}
	for (i = 9; i >= 0; i--) {
		if (digits[i] != '0') {
			scrn_putc(digits[i]);
		}
	}
}*/
