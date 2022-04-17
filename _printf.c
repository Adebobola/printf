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
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			char_count++;
			continue;
		}
		if (format[i] == '%')
                {
                        i++;
                        if (format[i] == 'c')
                        {
                                putchar(va_arg(ap, int));
                                char_count++;
                        }
                        else if (format[i] == 's')
                        {
                                t = va_arg(ap, char*);
                                while (t[l] != '\0')
                                {
                                        putchar(t[l]);
                                        l++;
                                        char_count++;
                                }
                        }
                        else if (format[i] == '%')
                        {
                                putchar('%');
                                char_count++;
                        }
                }
		if (format[i + 1] == '\0')
		{
			return (char_count);
		}
	}
	return (char_count);
}
