#include "main.h"

/**
 * char_print - Prints a char
 * @list: List  of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int char_print(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);
return (handle_num(c, ingre, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @list: List a of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list list, char ingre[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(list, char *);

	UNUSED(ingre);
UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

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

/**
 * print_binary - Prints an unsigned number
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list list, char ingre[],
        int flags, int width, int precision, int size)
{
        unsigned int k, l, i, sum;
        unsigned int b[32];
        int count;
        UNUSED(ingre);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);
k = va_arg(list, unsigned int);
        l = 2147483648;
        b[0] = k / l;
        for (i = 1; i < 32; i++)
        {
                l /= 2;
                b[i] = (k / l) % 2;
        }
        for (i = 0, sum = 0, count = 0; i < 32; i++)
        {
                sum += b[i];
                if (sum || i == 31)
                {
			char z = '0' + b[i];
write(1, &z, 1);
                        count++;
                }
        }
        return (count);
}
