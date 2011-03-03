#include "klibc/itoa.h"

u32int_t itoa(s32int_t n, s8int_t * s) {
	int i, sign, len;
	s8int_t c;
	sign = n;
	if(n < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n%10 + '0';
	}while((n/=10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
//	reverse the num
	len = i;
	for(i = 0; i < (s32int_t)(len/2); i++) {
		c = s[i];
		s[i] = s[len -i];
		s[len-i] = c;
	}

	return len;

}
