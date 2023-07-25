#include "main.h"

/**
 * print_num - Print int
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_num(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int y = va_arg(list, long int);
	unsigned long int num;

	y = number_convert(y, size);

	if (y == 0)
		ingre[i--] = '0';

	ingre[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)y;
if (y < 0)
	{
		num = (unsigned long int)((-1) * y);
		is_neg = 1;
	}

	while (num > 0)
	{
		ingre[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_neg, i, ingre, flags, width, precision, size));
}
