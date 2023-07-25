#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @list: Lista of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(ingre);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
