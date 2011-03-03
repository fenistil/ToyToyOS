#ifndef _H_STDARG
#define _H_STDARG

typedef __builtin_va_list va_list;
#define va_start(v,l)		__builtin_va_start((v), (l))
#define va_end				__builtin_va_end
#define va_arg				__builtin_va_arg
#define __va_copy(d, s)		__builtin_va_copy((d), (s))

#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L
#define va_copy(d,s)	__va_copy(d,s)
#endif


#endif
