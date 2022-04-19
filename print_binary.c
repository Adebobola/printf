#include "main.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be printed in binary
 * @printed: hold the number of characters printed
 */

int print_binary(unsigned int c)
{
	int l = 0;
	unsigned int m = c;
        if (c > 1)
        {
                l++;
		m = m / 2;
                l += print_unsignedToBinary(m);
                _putchar((c%2) + '0');
        }
        else
        {
                l++;
                _putchar(c + '0');
        }
	return(l);
}
