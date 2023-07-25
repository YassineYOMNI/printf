#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
*/
int get_flags(const char *format, int *i)
{
	int j, recurr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
      for (recurr_i = *i + 1; format[recurr_i] != '\0'; recurr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[recurr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = recurr_i - 1;

	return (flags);
}
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 * Return: Precision.
*/
int get_precision(const char *format, int *i, va_list args)
{
	int recurr_i = *i + 1;
	int precision = -1;

	if (format[recurr_i] != '.')
		return (precision);

/*	precision = 0;*/

	for (recurr_i += 1; format[recurr_i] != '\0'; recurr_i++)
	{
		if (is_digit(format[recurr_i]))
		{
			precision *= 10;
			precision += format[recurr_i] - '0';
		}
		else if (format[recurr_i] == '*')
		{
			recurr_i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = recurr_i - 1;

	return (precision);
}
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
*/
int get_size(const char *format, int *i)
{
	int recurr_i = *i + 1;
	int size = 0;

	if (format[recurr_i] == 'l')
		size = S_LONG;
	else if (format[recurr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = recurr_i - 1;
	else
		*i = recurr_i;

	return (size);
}
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 * Return: width.
*/
int get_width(const char *format, int *i, va_list args)
{
	int recurr_i;
	int width = 0;

	for (recurr_i = *i + 1; format[recurr_i] != '\0'; recurr_i++)
	{
		if (is_digit(format[recurr_i]))
		{
			width *= 10;
			width += format[recurr_i] - '0';
		}
		else if (format[recurr_i] == '*')
		{
			recurr_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = recurr_i - 1;

	return (width);
}
