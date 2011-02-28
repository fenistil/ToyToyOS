#include "scrn.h"
#include "idt.h"
#include "timer.h"

int kmain() {
	scrn_init();
	scrn_clear();
	//issue break every 10ms
	init_timer(100);
	init_descriptor_tables();

	//asm volatile("int $0x28");

	/* infinite loop */
	for( ;; );

	return 0xDEADBABA;
}
