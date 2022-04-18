#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - clone of the function printf in stdio.h
 * @format: the string to be printed along with format specifiers preceded by %
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap; /* Contains the list of arguments passed after format */
	int i; /* Used to loop through all characters in format */
	int l = 0;
	int k = 0;
	char *t;
	char *memory;

	va_start(ap, format);
	memory = malloc(sizeof(char) * 1500);

	if (format == NULL)
		return (0);

	for (i = 0; format[i] != 0; i++, k++)
	{
		if (format[i] != '%')
		{
			memory[k] = format[i];
			continue;
		}
		if (format[i] == '%')
                {
                        i++;
                        k++;
                        if (format[i] == 'c')
                        {
                                memory[k] = va_arg(ap, int);
                                continue;
                        }
                        else if (format[i] == 's')
                        {
                                t = va_arg(ap, char*);
                                while (t[l] != '\0')
                                {
                                        memory[k] = t[l];
                                        l++;
                                        k++;
                                }
                                l = 0;
                                continue;
                        }
                        else if (format[i] == '%')
                        {
                                memory[k] = '%';
                        }
                }
	}
	write(1, memory, k);
	va_end(ap);
	free(memory);
	return (k);
}
