#ifndef _DESCRIPTORS_H
#define _DESCRIPTORS_H

/*
 * IRQ Numbers and what they do by default:
 * 0: System timer
 * 1: Keyboard controller
 * 2:
 * 3: COM2
 * 4: COM1
 * 5: LPT 2/Sound card
 * 6: floppy
 * 7: LPT 1/Sound Card
 * 9:
 * 10:
 * 11:
 * 12: mouse/PS2 connector
 * 13: math coproc, floating point unit, inter process interrupt
 * 14: primary ATA
 * 15: secondary ATA
 */

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

struct idt_entry_struct
{
   u16int_t base_lo;             // The lower 16 bits of the address to jump to when this interrupt fires.
   u16int_t sel;                 // Kernel segment selector.
   u8int_t  always0;             // This must always be zero.
   u8int_t  flags;               // More flags. See documentation.
   u16int_t base_hi;             // The upper 16 bits of the address to jump to.
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
   u16int_t limit;
   u32int_t base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

typedef struct registers
{
   u32int_t ds;                  // Data segment selector
   u32int_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   u32int_t int_no, err_code;    // Interrupt number and error code (if applicable)
   u32int_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

void init_descriptor_tables(void);

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

/* IRQ functions */
extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();


#endif
