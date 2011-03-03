#include "timer.h"
#include "idt.h"
#include "klibc/printf.h"

u32int_t tick = 0;

static void timer_callback(registers_t regs) {
	tick++;
	regs = regs;
}

void init_timer(u32int_t freq) {
	register_interrupt_handler(IRQ_TIMER, &timer_callback);

	u32int_t divisor = 1193182 / freq;

	outb(0x43, 0x36);
	u8int_t l = (u8int_t)(divisor & 0xFF);
	u8int_t h = (u8int_t)((divisor >> 8) & 0xFF);

	outb(0x40, l);
	outb(0x40, h);
}
