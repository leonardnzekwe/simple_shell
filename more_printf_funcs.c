#include "main.h"

/**
 * hex_print - hexadecimal (base 16) printing function (lowercase)
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * hex - hexadecimal (unsigned int) parameter passed
 */

void hex_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int hex, i, hex_len, num;
	int j;
	char hex_digits[] = "0123456789abcdef";
	char *hex_str;

	hex = va_arg(args, unsigned int);
	num = hex; /* hold the value of hex b4 passing it to count */
	/* count number of digits */
	hex_len = 0;
	while (hex / 16 != 0)
	{ hex_len++;
		hex = hex / 16; }
	hex_len++;
	/* dynamically allocate memory for digits array */
	hex_str = malloc(sizeof(char) * (hex_len + 1));
	if (hex_str == NULL)
		return;
	/* convert unsigned int to str of digits in hexadecimal fmt */
	i = 0;
	while (num / 16 != 0)
	{ hex_str[i] = hex_digits[num % 16];
		num = num / 16;
		i++; }
	hex_str[i] = hex_digits[num % 16];
	if (flag == '#' && num != 0)
	{ _putchar('0');
		_putchar('x');
		(*count) += 2; }
	/* print digits in reverse order */
	for (j = i; j >= 0; j--)
	{ _putchar(hex_str[j]);
		(*count)++; }
	free(hex_str);
}

/**
 * cap_hex_print - hexadecimal (base 16) printing function (uppercase)
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * cap_hex - cap_hexadecimal (unsigned int) parameter passed
 */

void cap_hex_print(char flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned int cap_hex, i, cap_hex_len, num;
	int j;
	char cap_hex_digits[] = "0123456789ABCDEF";
	char *cap_hex_str;

	cap_hex = va_arg(args, unsigned int);
	num = cap_hex; /* hold the value of cap_hex b4 passing it to count */
	/* count number of digits */
	cap_hex_len = 0;
	while (cap_hex / 16 != 0)
	{
		cap_hex_len++;
		cap_hex = cap_hex / 16;
	}
	cap_hex_len++;
	/* dynamically allocate memory for digits array */
	cap_hex_str = malloc(sizeof(char) * (cap_hex_len + 1));
	if (cap_hex_str == NULL)
		return;
	/* convert unsigned int to str of digits in cap_hexadecimal fmt */
	i = 0;
	while (num / 16 != 0)
	{
		cap_hex_str[i] = cap_hex_digits[num % 16];
		num = num / 16;
		i++;
	}
	cap_hex_str[i] = cap_hex_digits[num % 16];
	if (flag == '#' && num != 0)
	{ _putchar('0');
		_putchar('X');
		(*count) += 2; }
	/* print digits in reverse order */
	for (j = i; j >= 0; j--)
	{
		_putchar(cap_hex_str[j]);
		(*count)++;
	}
	free(cap_hex_str);
}

/**
 * str_hex_print - prints a string
 * With non-printable characters as hexadecimal (uppercase)
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * str - string (char *) parameter passed
 */

void str_hex_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
			{
				_putchar('0');
				_printf("%X", str[i]);
			}
			else
			{
				_printf("%X", str[i]);
			}
			(*count) += 4;
		}
		else
		{
			_putchar(str[i]);
			(*count)++;
		}
	}
}

/**
 * ptr_print - print memory address in hexadecimal format
 * @flag: flag characters for non-custom conversion specifiers
 * @args: variable argument list
 * @count: pointer to integer to store the count of characters printed
 * @space: space character for non-custom conversion specifiers
 * ptr - pointer (void *) parameter passed
 */

void ptr_print(char __attribute__ ((unused)) flag, va_list args,
	int *count, char __attribute__ ((unused)) space)
{
	unsigned long int ptr, ptr_value;
	int i, j, ptr_len;
	char hex_digits[] = "0123456789abcdef";
	char *nil = "(nil)";
	char *hex_str;

	ptr = (unsigned long int)va_arg(args, void *);
	if (ptr != 0)
	{
		ptr_value = ptr; /* hold the value of hex b4 passing it to count */
		/* count number of digits */
		ptr_len = 0;
		while (ptr / 16 != 0)
		{ ptr_len++;
			ptr = ptr / 16; }
		ptr_len++;
		/* dynamically allocate memory for hex string */
		hex_str = malloc(sizeof(char) * (ptr_len + 1));
		if (hex_str == NULL)
			return;
		/* convert pointer value to hexadecimal string */
		i = 0;
		while (ptr_value / 16 != 0)
		{ hex_str[i] = hex_digits[ptr_value % 16];
			ptr_value = ptr_value / 16;
			i++; }
		hex_str[i] = hex_digits[ptr_value % 16];
		/* print the pointer address with leading "0x" */
		_putchar('0');
		_putchar('x');
		(*count) += 2;
		/* print digits in reverse order */
		for (j = i; j >= 0; j--)
		{ _putchar(hex_str[j]);
			(*count)++; }
		free(hex_str);
	}
	else
		zero(nil, count);
}

/**
 * zero - helper function to ptr_print
 * prints the nill when ptr is 0
 * @nil: (nil) parameter to print
 * @count: pointer to integer to store the count of characters printed
 */

void zero(char *nil, int *count)
{
	int k;

	for (k = 0; nil[k] != '\0'; k++)
	{
		_putchar(nil[k]);
		(*count)++;
	}
}
