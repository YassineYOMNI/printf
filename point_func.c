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
	void *addrs = va_arg(list, void *);

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

        str = va_arg(list, char *);

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
/**
 * print_rot13str - Print a string in rot13.
 * @list: List of arguments
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
*/
int print_rot13str(va_list list, char ingre[],
        int flags, int width, int precision, int size)
{
        char x;
        char *str;
        unsigned int i, j;
        int count = 0;
        char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

        str = va_arg(list, char *);
        UNUSED(ingre);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        if (str == NULL)
                str = "(AHYY)";
        for (i = 0; str[i]; i++)
{
                for (j = 0; input[j]; j++)
			{
                        if (input[j] == str[i])
                        {
                                x = output[j];
                                write(1, &x, 1);
                                count++;
                                break;
                        }
                }
                if (!input[j])
                {
                        x = str[i];
                        write(1, &x, 1);
                        count++;
                }
        }
        return (count);
}
