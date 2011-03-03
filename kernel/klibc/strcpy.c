#include "klibc/strcpy.h"

s8int_t * strcpy(s8int_t *dst, const s8int_t *src) {
	s32int_t i = 0;

	while(src[i] != '\0'){
		dst[i] = src[i];
		i++;
	}
	dst[i+1] = '\0';

	return dst;
}
