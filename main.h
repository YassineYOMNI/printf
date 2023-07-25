#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct yas - Structure
 * @yas: The format.
 * @yn: The function associated.
*/ 
struct yas
{
	char yas;
	int (*yn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct yas yas_t - Struct op
 * @yas: The format.
 * @yas_t: The function associated.
*/
typedef struct yas yas_t;

int _printf(const char *format, ...);
int handle_printed(const char *yas, int *i,
va_list args, char ingre[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int char_print(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_string(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_percent(va_list list, char ingre[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_num(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_binary(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_octal(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list list, char ingre[],
	int flags, int width, int precision, int size);
int hexa_seen_upper(va_list list, char ingre[],
	int flags, int width, int precision, int size);

int hexa_seen(va_list list, char on_to[],
char ingre[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list list, char ingre[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list list, char ingre[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int rev_string(va_list list, char ingre[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13str*/
int print_rot13str(va_list list, char ingre[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_num(char c, char ingre[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int n, char ingre[],
	int flags, int width, int precision, int size);
int write_num(int n, char ingre[], int flags, int width, int precision,
	int length, char pad, char more);
int write_pointer(char ingre[], int n, int length,
	int width, int flags, char pad, char more, int pad_alpha);

int unsigned_num(int is_neg, int n,
char ingre[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int print_gain(char);
int hexa_append(char, char[], int);
int is_digit(char);

long int number_convert(long int num, int size);
long int unsigned_size(unsigned long int num, int size);

#endif /* MAIN_H */
