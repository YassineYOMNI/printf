#include "main.h"


/**
 * rev_string - Prints reverse string.
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
*/

int rev_string(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(ingre);
        UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(ingre, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
