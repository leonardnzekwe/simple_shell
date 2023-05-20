#include "main.h"

/**
 * _strcmp - string compare function
 * @str1: first string
 * @str2: second string
 * Return: Success (0)
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
