#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * _printf - clone of the function printf in stdio.h
 * @format: the string to be printed along with format specifiers preceded by %
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_count = 0; /* Total number of chars printed to stdout */
	va_list ap; /* Contains the list of arguments passed after format */
	int i; /* Used to loop through all characters in format */
	int l = 0;
	char *t;

	va_start(ap, format);

	if (format == NULL)
		return (0);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			char_count++;
			continue;
		}
		if (format[i] == '%')
                {
                        i++;
                        if (format[i] == 'c')
                        {
                                _putchar(va_arg(ap, int));
                                char_count++;
                        }
                        else if (format[i] == 's')
                        {
                                t = va_arg(ap, char*);
                                while (t[l] != '\0')
                                {
                                        _putchar(t[l]);
                                        l++;
                                        char_count++;
                                }
				l = 0;
                        }
			else if (format[i] == '%')
                        {
                                _putchar('%');
                                char_count++;
                        }
                }
		if (format[i + 1] == '\0')
		{
			break;
		}
	}
	return (char_count);
}
