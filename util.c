#include "main.h"

/**
 * print_gain - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
*/
int print_gain(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa_append - Append ascci in hexadecimal code to buffer
 * @ingre: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCCI CODE.
 * Return: Always 3
*/
int hexa_append(char ascii_code, char ingre[], int i)
{
	char on_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	ingre[i++] = '\\';
	ingre[i++] = 'x';

	ingre[i++] = on_to[ascii_code / 16];
	ingre[i] = on_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * number_convert - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num
*/
long int number_convert(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * unsigned_size - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
*/
long int unsigned_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
