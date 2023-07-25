#include "main.h"
void print_ing(char ingre[], int *lenb);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int i, print = 0, chars_print = 0;
int flags, width, precision, size, lenb = 0;
va_list args;
char ingre[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(args, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
ingre[lenb++] = format[i];
if (lenb == BUFF_SIZE)
print_ing(ingre, &lenb);
/* write(1, &format[i], 1);*/
chars_print++;
}
else
{
print_ing(ingre, &lenb);
flags = get_flags(format, &i);
width = get_width(format, &i, args);
precision = get_precision(format, &i, args);
size = get_size(format, &i);
++i;
print = handle_printed(format, &i, args, ingre,
flags, width, precision, size);
if (print == -1)
return (-1);
chars_print += print;
}
}
print_ing(ingre, &lenb);
va_end(args);
return (chars_print);
}
/**
 * print_ing - Prints the contents of the buffer if it exist
 * @ingre: Array of chars
 * @lenb: Index at which to add next char, represents the length.
*/
void print_ing(char ingre[], int *lenb)
{
if (*lenb > 0)
write(1, &ingre[0], *lens);
*lenb = 0;
}
