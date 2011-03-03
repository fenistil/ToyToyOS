#include "scrn.h"
#include "idt.h"
#include "timer.h"
#include "klibc/printf.h"
#include "klibc/screen.h"
#include "klibc/putchar.h"
#include "klibc/itoa.h"

/* The symbol table for a.out. */
typedef struct aout_symbol_table {
	u32int_t tabsize;
	u32int_t strsize;
	u32int_t addr;
	u32int_t reserved;
} aout_symbol_table_t;

/* The section header table for ELF. */
typedef struct elf_section_header_table {
	u32int_t num;
	u32int_t size;
	u32int_t addr;
	u32int_t shndx;
} elf_section_header_table_t;

typedef struct multiboot_info {
	u32int_t flags;
	u32int_t mem_lower;
	u32int_t mem_upper;
	u32int_t boot_device;
	u32int_t cmdline;
	u32int_t mods_count;
	u32int_t mods_addr;
	union {
		aout_symbol_table_t aout_sym;
		elf_section_header_table_t elf_sec;
	} u;
	u32int_t mmap_length;
	u32int_t mmap_addr;
} multiboot_info_t;

int kmain(u32int_t magic, u32int_t addr) {
	multiboot_info_t *mbi;
	if (magic != 0x2BADB002) {
		printf("Something has been screwed up! Halting!\n");
		for (;;)
			;
	}

	putchar('a');
	scrn_init();
	scrn_clear();
	//issue break every 20ms
	init_timer(50);
	init_descriptor_tables();
	printf("Descriptor tables have been initialized...\n");

	// get memory information
	mbi = (multiboot_info_t *) addr;
	printf("\nMemory installed: %dMB\n", (mbi->mem_upper+64)/1024);


	/* infinite loop */
	for (;;)
		;

	return 0xDEADBABA;
}
