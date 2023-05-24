#include "main.h"

/**
 * char_print - character printing
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * c - int parameter to print promoted from char
 * char is promoted to int when passed to the elipses
 */

void char_print(char __attribute__ ((unused)) flag, va_list args,
		int *count, char __attribute__ ((unused)) space)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	(*count)++;
}

/**
 * string_print - string printing function
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * s - string (char *) parameter to print
 */

void string_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	char *s;
	char *null;
	int i, j;

	null = "(null)";
	s = va_arg(args, char *);
	if (s == NULL)
	{
		for (j = 0; null[j] != '\0'; j++)
		{
			_putchar(null[j]);
			(*count)++;
		}
		return;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		(*count)++;
	}
}

/**
 * bin_print - decimal (base 2) printing function
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * b - binary (unsigned int) parameter passed
 */

void bin_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int b, i, b_len, num;
	int j;
	char *digits;

	b = va_arg(args, unsigned int);
	num = b; /* hold the value of b before passing it to count logic */
	/* count number of digits */
	b_len = 0;
	while (b / 2 != 0)
	{
		b_len++;
		b = b / 2;
	}
	b_len++;
	/* dynamically allocate memory for digits array */
	digits = malloc(sizeof(char) * (b_len + 1));
	if (digits == NULL)
	{
		return;
	}
	/* convert integer to string of binary digits */
	i = 0;
	while (num / 2 != 0)
	{
		digits[i] = (num % 2) + '0';
		num = num / 2;
		i++;
	}
	digits[i] = (num % 2) + '0';
	/* print binary digits in reverse order */
	for (j = i; j >= 0; j--)
	{
		_putchar(digits[j]);
		(*count)++;
	}
	free(digits);
}

/**
 * oct_print - unsigned integer printing function in octal format (base 8)
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * o - unsigned integer (unsigned int) parameter to print in octal format
 */

void oct_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int o, i, o_len, num;
	int j;
	char *digits;

	o = va_arg(args, unsigned int);
	num = o; /* hold the value of u b4 passing it to count */
	/* count number of digits */
	o_len = 0;
	while (o / 8 != 0)
	{
		o_len++;
		o = o / 8;
	}
	o_len++;
	/* dynamically allocate memory for digits array */
	digits = malloc(sizeof(char) * (o_len + 1));
	if (digits == NULL)
		return;
	/* convert unsigned int to str of digits in octal fmt */
	i = 0;
	while (num / 8 != 0)
	{
		digits[i] = (num % 8) + '0';
		num = num / 8;
		i++;
	}
	digits[i] = (num % 8) + '0';
	if (flag == '#' && num != 0)
	{ _putchar('0');
		(*count)++; }
	/* print digits in reverse order */
	for (j = i; j >= 0; j--)
	{
		_putchar(digits[j]);
		(*count)++;
	}
	free(digits);
}

/**
 * uint_print - unsigned integer printing function
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * u - unsigned integer (unsigned int) parameter to print
 */

void uint_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int u, i, u_len, num;
	int j;
	char *digits;

	u = va_arg(args, unsigned int);
	num = u; /* hold the value of u before passing it to count logic */
	/* count number of digits */
	u_len = 0;
	while (u / 10 != 0)
	{
		u_len++;
		u = u / 10;
	}
	u_len++;
	/* dynamically allocate memory for digits array */
	digits = malloc(sizeof(char) * (u_len + 1));
	if (digits == NULL)
		return;
	/* convert unsigned integer to string of digits */
	i = 0;
	while (num / 10 != 0)
	{
		digits[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	digits[i] = (num % 10) + '0';
	/* print digits in reverse order */
	for (j = i; j >= 0; j--)
	{
		_putchar(digits[j]);
		(*count)++;
	}
	free(digits);
}
