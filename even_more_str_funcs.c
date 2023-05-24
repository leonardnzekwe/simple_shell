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
	return (write(1, &c, 1));
}
