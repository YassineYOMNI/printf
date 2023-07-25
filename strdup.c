#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @yas: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @n: index
 * @ingre: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
*/
int handle_printed(const char *yas, int *n, va_list args, char ingre[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, chars_print = -1;
	yas_t yas_kind[] = {
		{'c', char_print}, {'s', print_string}, {'%', print_percent},
		{'i', print_num}, {'d', print_num}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', hexa_seen_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', rev_string}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; yas_kind[i].yas != '\0'; i++)
		if (yas[*n] == yas_kind[i].yas)
			return (yas_kind[i].yn(args, ingre, flags, width, precision, size));

	if (yas_kind[i].yas == '\0')
	{
		if (yas[*n] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (yas[*n - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*n);
			while (yas[*n] != ' ' && yas[*n] != '%')
				--(*n);
			if (yas[*n] == ' ')
				--(*n);
			return (1);
		}
		unknow_len += write(1, &yas[*n], 1);
		return (unknow_len);
	}
	return (chars_print);
}
