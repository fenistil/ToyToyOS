#include "klibc/putchar.h"

s8int_t putchar(const s8int_t c) {
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
	return c;
}
