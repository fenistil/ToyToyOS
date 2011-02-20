#include "common.h"
#include "scrn.h"

u32int scrn_cursor_x;
u32int scrn_cursor_y;
u32int scrn_page;

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

void scrn_scroll(s8int page) {
	page = page;
}

void scrn_move_cursor(void) {

}
