#include "klibc/printf.h"
#include "scrn.h"

#define null_out(b, l) { int dz; for(dz = 0; dz < l; b[dz] = '\0', dz++ ); }

s32int_t printf(const s8int_t * fmt, ...) {
	u32int_t i, j;
	va_list args;
	s8int_t buf[20];
	s32int_t total_printouts = 0;

	va_start(args, fmt);

	/*tmp = va_arg(args, s8int_t * );
	 tmp2 = va_arg(args, int);*/

	i = 0;
	while (fmt[i] != '\0') {
		if (fmt[i] == '%') {
			i++;
			switch (fmt[i++]) {
			case 'd':
				null_out(buf, 20)
				;
				itoa(va_arg(args, s32int_t), buf);
				j = 0;
				while (buf[j] != '\0') {
					putchar(buf[j]);
					total_printouts++;
					j++;
				}
				break;
			case 'x':
				null_out(buf, 20)
				;
				_itoa(va_arg(args, s32int_t), buf, 'x');
				if(buf[0] == '-') {
					putchar('-');
					total_printouts++;
					j = 1;
				}else{
					j = 0;
				}
				putchar('0');
				total_printouts++;
				putchar('x');
				total_printouts++;
				while (buf[j] != '\0') {
					putchar(buf[j]);
					total_printouts++;
					j++;
				}
				break;
			case 's':
				null_out(buf, 20)
				;
				strcpy(buf, va_arg(args, s8int_t *) );
				j = 0;
				while (buf[j] != '\0') {
					putchar(buf[j]);
					total_printouts++;
					j++;
				}
				break;
			case '%':
				putchar('%');
				break;
			}
		} else {
			putchar(fmt[i]);
			i++;
		}

	}

	va_end(args);

	return total_printouts;
}
