#include "main.h"

/**
 * hexa_seen - Prints a hexadecimal number in lower or upper
 * @list: Lista of arguments
 * @on_to: Array of values to map the number to
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int hexa_seen(va_list list, char on_to[], char ingre[],
	int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = unsigned_size(num, size);

	if (num == 0)
		ingre[i--] = '0';

	ingre[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		ingre[i--] = on_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		ingre[i--] = flag_ch;
		ingre[i--] = '0';
	}

	i++;

	return (unsigned_num(0, i, ingre, flags, width, precision, size));
}
