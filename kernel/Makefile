CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs -I./include

OBJ_DIR=objs/
CSOURCES=$(wildcard *.c)
OBJS=$(addprefix $(OBJ_DIR), $(subst .c,.o,$(CSOURCES)))

all: kernel.bin

kernel.bin: $(OBJS) boot.o gdt_s.o idt_s.o
	ld -T linker.ld $(OBJ_DIR)boot.o $(OBJS) $(OBJ_DIR)gdt_s.o $(OBJ_DIR)idt_s.o -o $@

$(OBJS): $(CSOURCES)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$@))

boot.o: boot.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

idt_s.o: idt_s.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

gdt_s.o: gdt_s.s	
	nasm -f elf -o $(OBJ_DIR)$@ $<	

clean:	
	rm $(OBJ_DIR)*.o	
	rm `ls kernel.bin`

run:
	bochs -q -f `pwd`/../bochrc.txt
	
test:
	echo $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$(OBJS)))
