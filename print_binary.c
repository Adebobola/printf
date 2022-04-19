#include "main.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be printed in binary
 * @printed: hold the number of characters printed
 */

void print_binary(unsigned int c)
{
	int l = 0;
        if (c > 1)
        {
                l++;
                l += print_unsignedToBinary(c / 2);
                putchar((c%2) + '0');
        }
        else
        {
                l++;
                putchar(c + '0');
        }
	return(l);
}
