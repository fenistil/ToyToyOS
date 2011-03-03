#include "klibc/_itoa.h"

inline u32int_t _itoa(s32int_t n, s8int_t * s, s8int_t base) {
	s32int_t i, backup, len;
	s32int_t divisor;
	s8int_t c;

	backup = n;
	if (n < 0)
		n = -n;

	//	decimal conversion
	if (base == 'd') {
		divisor = 10;
	}else if (base == 'x') {
		divisor = 16;
	}

	i = 0;
	do {
		s[i] = n % divisor + '0';
		if(base == 'x' && s[i] > '9')
			s[i] += 7;
		i++;
	} while ((n /= divisor) > 0);


	if (backup < 0)
		s[i++] = '-';

	//	reverse the num
	len = i;
	for (i = 0; i < (s32int_t) (len / 2); i++) {
		c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
	}
	s[len] = '\0';

	return len;

}
