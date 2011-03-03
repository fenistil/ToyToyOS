CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -nostdlib --freestanding -nostartfiles -nodefaultlibs -I./include

OBJ_DIR=objs/
CSOURCES=$(wildcard *.c)
OBJS=$(addprefix $(OBJ_DIR), $(subst .c,.o,$(CSOURCES))) drivers/keyboard.o

all: kernel.bin

kernel.bin: $(OBJS) boot.o gdt_s.o idt_s.o drivers klibc klibc/klibc.o
	ld -T linker.ld $(OBJ_DIR)boot.o $(OBJS) klibc/klibc.o $(OBJ_DIR)gdt_s.o $(OBJ_DIR)idt_s.o -o $@

$(OBJS): $(CSOURCES)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$@))

boot.o: boot.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

idt_s.o: idt_s.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

gdt_s.o: gdt_s.s	
	nasm -f elf -o $(OBJ_DIR)$@ $<	
	
drivers:
	`cd keyboard && make && cd ..`
	
klibc/klibc.o:
	$(MAKE) -C klibc 
	
clean:	
	find ./ -name "*.o" -exec rm '{}' \;
	find ./ -name kernel.bin -exec rm '{}' \;

run:
	bochs -q -f `pwd`/../bochrc.txt
	
test:
	echo $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$(OBJS)))
