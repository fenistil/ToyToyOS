CC=gcc
CFLAGS=-c -g3 -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs
OBJS=kernel.o boot.o common.o scrn.o

all: kernel.bin

kernel.bin: $(OBJS)
	ld -T linker.ld $(OBJS) -o $@

kernel.o: kernel.c
	$(CC) $(CFLAGS) -o $@ $<

boot.o: boot.s
	nasm -f elf -o $@ $<

common.o: common.c
	$(CC) $(CFLAGS) -o $@ $<

scrn.o: scrn.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm `ls *.o`
	rm `ls kernel.bin`

run:
	bochs -q -f `pwd`/../bochrc.txt
