#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @list: List  of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int print_unsigned(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = unsigned_size(num, size);

	if (num == 0)
		ingre[i--] = '0';

	ingre[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		ingre[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (unsigned_num(0, i, ingre, flags, width, precision, size));
}
