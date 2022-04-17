#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *_printf - produces output according to a format
 *@format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int f = 0;
	int l = 0;
	char *t;
	va_list start;

	va_start(start, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				_putchar(va_arg(start, int));
				f++;
				format++;
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
				format++;
			}
			else if (*format == '%')
			{
				_putchar('%');
			}
		}
		_putchar(*format);
		format++;
		f++;
	}
	f--;
	va_end(start);
	return (f);
}
