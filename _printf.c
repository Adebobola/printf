#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list start;

	va_start (start, format);
	int f = 0;
	int l = 0;
	char *t;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(start, int));
				f++;
			}
			else if (*format == 's')
			{
				t = va_arg(start, char*);
				while (t[l] != '\0')
				{
					putchar(t[l]);
					l++;
					f++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				f++;
			}
			format++;
		}
		putchar(*format);
		format++;
		f++;
	}
	va_end (start);
	return (f);
}
