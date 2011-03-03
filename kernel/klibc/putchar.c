#include "klibc/putchar.h"

s8int_t putchar(const s8int_t c) {
	s16int_t *vid = VIDEO_MEMORY;
	vid += scrn_cursor_y * 80 + scrn_cursor_x;
	*vid = c | scrn_color << 8;
	if (scrn_cursor_x + 1 > 78) {
		scrn_cursor_x = 0;
		scrn_cursor_y++;
	} else {
		scrn_cursor_x++;
	}
	scrn_scroll();
	scrn_move_cursor();
	return c;
}
