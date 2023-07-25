#include "main.h"

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int print_non_printable(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	int i = 0, set = 0;
	char *str = va_arg(list, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (print_gain(str[i]))
			ingre[i + set] = str[i];
		else
			set += hexa_append(str[i], ingre, i + set);

		i++;
	}
ingre[i + set] = '\0';

	return (write(1, ingre, i + set));
}
