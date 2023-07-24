#include "main.h"

/**
 * _isspace - functions that checks if a char is a white-space char
 * @character: a char to be matched with the white-space chars
 * Return: matched char
 */

int _isspace(int character)
{
	return (character == ' ' || character == '\t' || character == '\n' ||
		character == '\v' || character == '\f' || character == '\r');
}

/**
 * _putchar - char printing function
 * @c: character to print
 * Return: ? success (0) : failure (-1)
 */

int _putchar(char c)
{
	/* modified to print to stderr (2) */
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 * Return: 1 if character is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1); /* Character is a digit */
	}
	return (0); /* Character is not a digit */
}
