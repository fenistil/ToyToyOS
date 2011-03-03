#include "klibc/atof.h"

double atof(const s8int_t *s) {
	int i, sign;
	double val, power;
	// check for sign
	for (i = 0; (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i]
			!= '\0'; i++)
		//	skip white chars
		;

	//	determine the sign if we have any
	if (s[i] == '+' || s[i] == '-')
		sign = s[i++] == '-' ? -1 : 1;

	//	convert the string to int
	for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
		val = 10 * val + s[i] - '0';

	if(s[i] == '.')
		i++;

	for(power = 1; s[i] >= '0' && s[i] <= '9'; i++){
		val = 10*val+s[i]-'0';
		power *= 10;
	}

	return sign*val/power;
}
