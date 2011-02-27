CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs -I./include

OBJ_DIR=objs/
CSOURCES=$(wildcard *.c)
OBJS=$(addprefix $(OBJ_DIR), $(subst .c,.o,$(CSOURCES)))

all: kernel.bin

kernel.bin: $(OBJS) boot.o descriptors_asm.o
	ld -T linker.ld $(OBJ_DIR)boot.o $(OBJS) $(OBJ_DIR)descriptors_asm.o -o $@

$(OBJS): $(CSOURCES)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$@))

boot.o: boot.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

descriptors_asm.o: descriptors_asm.s
	nasm -f elf -o $(OBJ_DIR)$@ $<

clean:	
	rm $(OBJ_DIR)*.o	
	rm `ls kernel.bin`

run:
	bochs -q -f `pwd`/../bochrc.txt
	
test:
	echo $(patsubst %.o,%.c,$(subst $(OBJ_DIR),,$(OBJS)))
