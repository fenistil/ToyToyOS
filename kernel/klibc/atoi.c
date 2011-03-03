#include "klibc/atoi.h"

s32int_t atoi(const s8int_t *s) {
	int i, n, sign;
	// check for sign
	for (i = 0; (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i]
			!= '\0'; i++)
		//	skip white chars
		;

	//	determine the sign if we have any
	if (s[i] == '+' || s[i] == '-')
		sign = s[i++] == '-' ? -1 : 1;

	//	convert the string to int
	for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + s[i] - '0';

	return sign * n;
}
