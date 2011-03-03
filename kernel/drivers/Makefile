CC=gcc
CFLAGS=-c -g -Wall -Wextra -Werror -nostdlib -nostartfiles -nodefaultlibs -I../include

OBJ_DIR=objs/
CSOURCES=keyboard.c
OBJS=keyboard.o

keyboard.o: keyboard.c
	$(CC) $(CFLAGS) $< -o $@