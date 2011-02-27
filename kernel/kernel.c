#include "common.h"
#include "scrn.h"
#include "descriptors.h"

int kmain() {
	scrn_init();
	scrn_clear();
	init_descriptor_tables();


	asm volatile("int $0x3");

	scrn_puts("Testing IRQs\n");

	//asm volatile("int $0x28");

	/* infinite loop */
	for( ;; );

	return 0xDEADBABA;
}
