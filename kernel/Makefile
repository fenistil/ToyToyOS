CC=gcc
CFLAGS=-c -g3 -Wall -Wextra -Werror -nostdlib -nostartiles -nodefaultlibs
OBJS=kernel.o boot.o

all: kernel.bin

kernel.bin: $(OBJS)
	LD -T linker.ld $(OBJS) -o $@

kernel.o: kernel.c
	$(CC) $(CFLAGS) -o $@ $<

boot.o: boot.s
	nasm -f elf -o $@ $<

clean:
	rm `ls *.o`
	rm `ls kernel.bin`

run:
	bochs -q -f `pwd`/../bochrc.txt
