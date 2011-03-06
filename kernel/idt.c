#include "common.h"
#include "idt.h"
#include "gdt.h"

extern void idt_flush(u32int_t);

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

static isr_t interrupt_handlers[256];

void idt_set_gate(u8int_t num, u32int_t base, u16int_t sel,
		u8int_t flags) {
	idt_entries[num].base_lo = base & 0xFFFF;
	idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

	idt_entries[num].sel = sel;
	idt_entries[num].always0 = 0;
	// We must uncomment the OR below when we get to using user-mode.
	// It sets the interrupt gate's privilege level to 3.
	idt_entries[num].flags = flags /* | 0x60 */;
}

void init_idt() {
	int i;

	idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;
	idt_ptr.base = (u32int_t) &idt_entries;

	for (i = 0; i < 256; i++){
		idt_entries[i].always0 = 0;
		idt_entries[i].base_hi = 0;
		idt_entries[i].base_lo = 0;
		idt_entries[i].flags = 0;
		idt_entries[i].sel = 0;
	}

	/* register IDTs */

	idt_set_gate(0, (u32int_t) isr0, 0x08, 0x8E);
	idt_set_gate(1, (u32int_t) isr1, 0x08, 0x8E);
	idt_set_gate(2, (u32int_t) isr2, 0x08, 0x8E);
	idt_set_gate(3, (u32int_t) isr3, 0x08, 0x8E);
	idt_set_gate(4, (u32int_t) isr4, 0x08, 0x8E);
	idt_set_gate(5, (u32int_t) isr5, 0x08, 0x8E);
	idt_set_gate(6, (u32int_t) isr6, 0x08, 0x8E);
	idt_set_gate(7, (u32int_t) isr7, 0x08, 0x8E);
	idt_set_gate(8, (u32int_t) isr8, 0x08, 0x8E);
	idt_set_gate(9, (u32int_t) isr9, 0x08, 0x8E);
	idt_set_gate(10, (u32int_t) isr10, 0x08, 0x8E);
	idt_set_gate(11, (u32int_t) isr11, 0x08, 0x8E);
	idt_set_gate(12, (u32int_t) isr12, 0x08, 0x8E);
	idt_set_gate(13, (u32int_t) isr13, 0x08, 0x8E);
	idt_set_gate(14, (u32int_t) isr14, 0x08, 0x8E);
	idt_set_gate(15, (u32int_t) isr15, 0x08, 0x8E);
	idt_set_gate(16, (u32int_t) isr16, 0x08, 0x8E);
	idt_set_gate(17, (u32int_t) isr17, 0x08, 0x8E);
	idt_set_gate(18, (u32int_t) isr18, 0x08, 0x8E);
	idt_set_gate(19, (u32int_t) isr19, 0x08, 0x8E);
	idt_set_gate(20, (u32int_t) isr20, 0x08, 0x8E);
	idt_set_gate(21, (u32int_t) isr21, 0x08, 0x8E);
	idt_set_gate(22, (u32int_t) isr22, 0x08, 0x8E);
	idt_set_gate(23, (u32int_t) isr23, 0x08, 0x8E);
	idt_set_gate(24, (u32int_t) isr24, 0x08, 0x8E);
	idt_set_gate(25, (u32int_t) isr25, 0x08, 0x8E);
	idt_set_gate(26, (u32int_t) isr26, 0x08, 0x8E);
	idt_set_gate(27, (u32int_t) isr27, 0x08, 0x8E);
	idt_set_gate(28, (u32int_t) isr28, 0x08, 0x8E);
	idt_set_gate(29, (u32int_t) isr29, 0x08, 0x8E);
	idt_set_gate(30, (u32int_t) isr30, 0x08, 0x8E);
	idt_set_gate(31, (u32int_t) isr31, 0x08, 0x8E);

	/* remap PIC interrupts from 0-15 to 32-47 */

	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0x0);
	outb(0xA1, 0x0);

	/* new PIC interrupts handers */
	idt_set_gate(32, (u32int_t) irq0, 0x08, 0x8E);
	idt_set_gate(33, (u32int_t) irq1, 0x08, 0x8E);
	idt_set_gate(34, (u32int_t) irq2, 0x08, 0x8E);
	idt_set_gate(35, (u32int_t) irq3, 0x08, 0x8E);
	idt_set_gate(36, (u32int_t) irq4, 0x08, 0x8E);
	idt_set_gate(37, (u32int_t) irq5, 0x08, 0x8E);
	idt_set_gate(38, (u32int_t) irq6, 0x08, 0x8E);
	idt_set_gate(39, (u32int_t) irq7, 0x08, 0x8E);
	idt_set_gate(40, (u32int_t) irq8, 0x08, 0x8E);
	idt_set_gate(41, (u32int_t) irq9, 0x08, 0x8E);
	idt_set_gate(42, (u32int_t) irq10, 0x08, 0x8E);
	idt_set_gate(43, (u32int_t) irq11, 0x08, 0x8E);
	idt_set_gate(44, (u32int_t) irq12, 0x08, 0x8E);
	idt_set_gate(45, (u32int_t) irq13, 0x08, 0x8E);
	idt_set_gate(46, (u32int_t) irq14, 0x08, 0x8E);

	idt_flush((u32int_t) &idt_ptr);
}


void init_descriptor_tables() {
	init_gdt();
	init_idt();
}

void isr_handler(registers_t regs) {
	regs = regs;
}

void irq_handler(registers_t regs) {
	if (regs.int_no >= 40) {
		// reset slave
		outb(0xA0, 0x20);
	}
	// always reset master PIC
	outb(0x20, 0x20);
	if(interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}

void register_interrupt_handler(u8int_t n, isr_t handler) {
	interrupt_handlers[n] = handler;
}
