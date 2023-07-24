#include "main.h"
void print_ing(char ingre[], int *lenb );
/**
 * print_ing - prints the content of the buffer
 * @ingre: array of chars
 * @lenb: represents the length
*/
void print_ing(char ingre[], int *lenb)
{
	if (*lenb > 0)
		write(1, &ingre[0], *lenb);

	*lenb = 0;
}

/**
 * _printf - print formatted string
 * @format: the formatted string
 *
 * Return: the string length
 */
int	_printf(const char *format, ...)
{
	int i, j = 0, jp = 0;
	int len, lenw, lenp, lens, lenb = 0;
	va_list	args;

	char ingre[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
        for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			ingre[lenb++] = format[i];
			if (lenb == BUFF_SIZE)
				print_ing(ingre, &lenb);
			jb++;
		}
		else
		{
			print_ing(ingre, &lenb);
			len = get_flags(format, &i);
			lenw = get_width(format, &i, args);
			lenp = get_precision(format, &i, args);
			lens = get_size(format, &i);
			++i;
			j = handle_print(format, &i, ingre,len, lenw, lenp, lens);
			if (j == -1)
				return(-1);
			jp += j;
	}
        print_ing(ingre, &lenb);
	va_end(args);
	return (jp);
}
