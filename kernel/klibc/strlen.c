#include "klibc/strlen.h"

u32int_t strlen(s8int_t *s) {
	int i = 0;
	while(s[i] != '\0')
		++i;
	return i;
}
