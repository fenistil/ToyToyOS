CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -nostdlib --freestanding -nostartfiles -nodefaultlibs -I../include
LIBFLAGS=-static 

all: printf.o screen.o putchar.o atoi.o atof.o strlen.o itoa.o _itoa.o strcpy.o
	ld -r printf.o screen.o putchar.o atoi.o atof.o strlen.o itoa.o _itoa.o strcpy.o -o klibc.o 

printf.o: printf.c 
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	find ./ -name "*.o" -exec rm '{}' \;
	
.PHONY: all
	
