#ifndef _H_GDT
#define _H_GDT

#include "common.h"

struct gdt_entry_struct {
	u16int_t limit_low;
	u16int_t base_low;
	u8int_t base_middle;
	u8int_t access;
	u8int_t granularity;
	u8int_t base_high;
}__attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct {
	u16int_t limit;
	u32int_t base;
}__attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

void init_gdt();

#endif
