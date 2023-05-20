#include "main.h"

/**
 * _strlen - string length function
 * @str: string to get its length
 * Return: length
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - string copy function
 * @dest: destination string
 * @src: source string
 * Return: dest
 */

char *_strcpy(char *dest, const char *src)
{
	char *destPtr = dest;

	while (*src != '\0')
	{
		*destPtr = *src;
		destPtr++;
		src++;
	}
	/* Add null character at the end */
	*destPtr = '\0';
	return (dest);
}

/**
 * _strchr - string character search function
 * @str: string to search
 * @c: character to find
 * Return: NULL
 */

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	/* Handle the case when the character is not found */
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

/**
 * _strncmp - string compare with nth times function
 * @str1: first string
 * @str2: second string
 * @n: number of times to compare
 * Return: Success (0)
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		/* If either string reaches the null character, break the loop */
		if (*str1 == '\0' || *str2 == '\0')
		{
			break;
		}
		str1++;
		str2++;
	}
	return (0);
}

/**
 * _strcat - string concatenation function
 * @dest: destination string
 * @src: source string
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	char *dest_ptr = dest;

	/* Find the end of the destination string */
	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}
	/* Append characters from the source string to the destination string */
	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	/* Add null character at the end */
	*dest_ptr = '\0';
	return (dest);
}
