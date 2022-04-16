#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int f = 0;
	int l = 0;
	char *t;
	va_list start;

	va_start(start, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				_putchar(va_arg(start, int));
				f++;
			}
			else if (*format == 's')
			{
				t = va_arg(start, char*);
				while (t[l] != '\0')
				{
					_putchar(t[l]);
					l++;
					f++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				f++;
			}
			format++;
		}
		_putchar(*format);
		format++;
		f++;
	}
	va_end(start);
	return (f);
}
