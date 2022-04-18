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
	int char_count = 0; /* Total number of chars printed to stdout */
	va_list ap; /* Contains the list of arguments passed after format */
	int i; /* Used to loop through all characters in format */
	int l = 0;
	char *t;
	char *memory;

	va_start(ap, format);
	memory = malloc(sizeof(char) * 200000);
	for (i = 0; format[i] != '\0'; i++, char_count++)
	{
		
		if (format[i] == '%')
                {
                        i++;
                        char_count++;
                        if (format[i] == 'c')
                        {
                                memory[char_count] = va_arg(ap, int);
                        }
                        else if (format[i] == 's')
                        {
                                t = va_arg(ap, char*);
                                while (t[l] != '\0')
                                {
                                        memory[char_count] = t[l];
                                        l++;
                                        char_count++;
                                }
                                l = 0;
                        }
                        else if (format[i] == '%')
                        {
                                memory [char_count] = '%';
                        }
                }
                memory[char_count] = format[i];
	}
	write(1, memory, char_count);
	free(memory);
	va_end(ap);
	return (char_count);
}
