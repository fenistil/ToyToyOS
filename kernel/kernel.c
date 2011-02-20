#include "common.h"
#include "scrn.h"

int kmain() {
	scrn_init();
	scrn_clear();

	scrn_puts("\nHello World, this rocks! And more!");

	/* infinite loop */
	for( ;; );

	return 0xDEADBABA;
}
