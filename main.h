#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct printHandler - struct for agrupate
 * %d, %c, etc... formatters
 * @c: character
 * @f: character func
 *
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list);
} ph;

int _printf(const char *format, ...);
int (*get_print(char c))(va_list);
int _putchar(char c);
int _puts(char *str);
char *string_to_base(unsigned long int num, int base, bool uppercase);
/** prints text*/
int print_char(va_list);
int print_string(va_list);
int print_reverse_string(va_list);
/** print mememory address */
int print_address(va_list);
/** prints nums*/
int print_int(va_list);
int print_unsigned(va_list);
/** prints basics*/
int print_hexa(va_list);
int print_octal(va_list);
int print_binary(va_list);
int print_percent(va_list);
int print_hexa_in_uppercase(va_list);
/** utilities */
int count_digits(int i);
void print_number(int n);
void print_rev_recursion(char *s);

#endif
