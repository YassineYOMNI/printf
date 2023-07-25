#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int print_pointer(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	char more = 0, pad = ' ';
	int n = BUFF_SIZE - 2, length = 2, pad_alpha = 1;
	unsigned long address;
	char on_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	ingre[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	address = (unsigned long)addrs;

	while (address > 0)
	{
		ingre[n--] = on_to[address % 16];
		address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		more = '+', length++;
	else if (flags & F_SPACE)
		more = ' ', length++;

	n++;

	return (write_pointer(ingre, n, length,
		width, flags, pad, more, pad_alpha));
}
