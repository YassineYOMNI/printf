#include "main.h"
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int handle_num(char c, char ingre[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	ingre[i++] = c;
	ingre[i] = '\0';

	if (width > 1)
	{
		ingre[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			ingre[BUFF_SIZE - i - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &ingre[0], 1) +
					write(1, &ingre[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &ingre[BUFF_SIZE - i - 1], width - 1) +
					write(1, &ingre[0], 1));
	}
	return (write(1, &ingre[0], 1));
}


/**
 * write_number - Prints a string
 * @is_neg: Lista of arguments
 * @n: char types.
 * @ingre: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int write_number(int is_neg, int n, char ingre[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - n - 1;
	char pad = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_neg)
		extra_c = '-';
	else if (flags & F_PLUS)
		extra_c = '+';
	else if (flags & F_SPACE)
		extra_c = ' ';

	return (write_num(n, ingre, flags, width, precision,
		length, pad, extra_c));
}

/**
 * write_num - Write a number using a buffer
 * @n: Index at which the number starts on the buffer
 * @ingre: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pad: Padding char
 * @more: Extra char
 * Return: Number of printed chars.
*/
int write_num(int n, char ingre[],
	int flags, int width, int prec,
	int length, char pad, char more)
{
	int i, pad_alpha = 1;

	if (prec == 0 && n == BUFF_SIZE - 2 && ingre[n] == '0' && width == 0)
		return (0); 
	if (prec == 0 && n == BUFF_SIZE - 2 && ingre[n] == '0')
		ingre[n] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		ingre[--n] = '0', length++;
	if (more != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			ingre[i] = pad;
		ingre[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (more)
				ingre[--n] = more;
			return (write(1, &ingre[n], length) + write(1, &ingre[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (more)
				ingre[--n] = more;
			return (write(1, &ingre[1], i - 1) + write(1, &ingre[n], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (more)
				ingre[--pad_alpha] = more;
			return (write(1, &ingre[pad_alpha], i - pad_alpha) +
				write(1, &ingre[n], length - (1 - pad_alpha)));
		}
	}
	if (more)
		ingre[--n] = more;
	return (write(1, &ingre[n], length));
}

/**
 * unsigned_num - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @n: Index at which the number starts in the buffer
 * @ingre: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
*/
int unsigned_num(int is_neg, int n,
	char ingre[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - n - 1, i = 0;
	char pad = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && n == BUFF_SIZE - 2 && ingre[n] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		ingre[--n] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			ingre[i] = pad;

		ingre[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &ingre[n], length) + write(1, &ingre[0], i));
		}
		else
		{
			return (write(1, &ingre[0], i) + write(1, &ingre[n], length));
		}
	}

	return (write(1, &ingre[n], length));
}

/**
 * write_pointer - Write a memory address
 * @ingre: Arrays of chars
 * @n: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Char representing the padding
 * @more: Char representing extra char
 * @pad_alpha: Index at which padding should start
 * Return: Number of written chars.
*/
int write_pointer(char ingre[], int n, int length,
	int width, int flags, char pad, char more, int pad_alpha)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			ingre[i] = pad;
		ingre[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			ingre[--n] = 'x';
			ingre[--n] = '0';
			if (more)
				ingre[--n] = more;
			return (write(1, &ingre[n], length) + write(1, &ingre[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			ingre[--n] = 'x';
			ingre[--n] = '0';
			if (more)
				ingre[--n] = more;
			return (write(1, &ingre[3], i - 3) + write(1, &ingre[n], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (more)
				ingre[--pad_alpha] = more;
			ingre[1] = '0';
			ingre[2] = 'x';
			return (write(1, &ingre[pad_alpha], i - pad_alpha) +
				write(1, &ingre[n], length - (1 - pad_alpha) - 2));
		}
	}
	ingre[--n] = 'x';
	ingre[--n] = '0';
	if (more)
		ingre[--n] = more;
	return (write(1, &ingre[n], BUFF_SIZE - n - 1));
}

