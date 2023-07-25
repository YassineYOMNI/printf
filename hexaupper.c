#include "main.h"

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_hexadecimal(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	return (hexa_seen(list, "0123456789abcdef", ingre,
		flags, 'x', width, precision, size));
}

/**
 * hexa_seen_upper - Prints an unsigned number in upper hexadecimal notation
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int hexa_seen_upper(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	return (hexa_seen(list, "0123456789ABCDEF", ingre,
		flags, 'X', width, precision, size));
}
