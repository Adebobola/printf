#include "main.h"
/**
 * _printf - replicate prinft
 *
 * @format: format printf
 * Return: Always 0
 */
int _printf(const char *format, ...)
{

	int (*printer)(va_list);
	int length = 0;
	va_list content;

	va_start(content, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;

			printer = get_print(*format);

			if (printer)
			{
				length += printer(content);
			}
			else
			{
				length += _putchar('%');
				length += _putchar(*format);
			}
		}
		else
		{
			length += _putchar(*format);
		}
	}
	va_end(content);

	return (length);
}
