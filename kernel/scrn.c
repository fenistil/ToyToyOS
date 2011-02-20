#include "scrn.h"


void scrn_init() {
	scrn_cursor_x = 0;
	scrn_cursor_y = 0;
	scrn_page = 0;
}

void scrn_putc(s8int c) {
	c = c;
}

void scrn_clear(void) {

}

u32int scrn_puts(s8int *str) {
	str = str;
	return 0;
}

void scrn_scroll(s18int page) {
	page = page;
}

void scrn_move_cursor(void) {

}
