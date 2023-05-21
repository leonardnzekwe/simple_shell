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

/**
 * _strdup - string duplication function
 * @str: string paramter to duplicaate
 * Return: dup
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	/* Length of the string including null character */
	len = _strlen(str) + 1;

	/* Allocate memory for the duplicate string */
	dup = (char *)malloc(len * sizeof(char));
	if (dup != NULL)
	{
		/* Copy the contents of the source string to the duplicate */
		_strcpy(dup, str);
	}
	return (dup);
}
