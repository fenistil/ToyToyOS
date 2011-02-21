#include "common.h"
#include "scrn.h"
#include "descriptors.h"

int kmain() {
	scrn_init();
	scrn_clear();
	init_descriptor_tables();

	asm volatile("int $0x3");
	asm volatile("int $0xF");

	/* infinite loop */
	for( ;; );

	return 0xDEADBABA;
}
