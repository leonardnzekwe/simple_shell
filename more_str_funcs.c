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

/**
 * _memcpy - function that copies a block of mem from one location to another
 * @destination: a ptr to the mem location where the copied data will be stored
 * It should be large enough to hold num bytes.
 * @source: a ptr to the memory location from where the data will be copied
 * @num: specifies the number of bytes to be copied
 * Return: a ptr to the destination memory location
 */

void *_memcpy(void *destination, const void *source, size_t num)
{
	size_t i;
	unsigned char *dest = (unsigned char *)destination;
	const unsigned char *src = (const unsigned char *)source;

	for (i = 0; i < num; i++)
	{
		dest[i] = src[i];
	}
	return (destination);
}

/**
 * _strtok - string tokenisation function
 * @str: string to tokenise
 * @delimiters: delimiters parameter
 * Return: Success (next_token)
 */

char *_strtok(char *str, const char *delimiters)
{
	static char *next_token;  /* Keeps track of the next token */
	char *current_token = NULL;
	/* If str is not NULL, set it as the new string to tokenize */
	if (str != NULL)
	{
		next_token = str;
	}
	else if (next_token == NULL)
	{
		return (NULL);  /* No more tokens, return NULL */
	}
	/* Skip leading delimiters */
	while (*next_token != '\0' && _strchr(delimiters, *next_token) != NULL)
	{
		next_token++;
	}

	if (*next_token == '\0')
	{
		return (NULL);  /* No more tokens, return NULL */
	}
	current_token = next_token;  /* Start of the current token */
	/* Find the end of the current token */
	while (*next_token != '\0' && _strchr(delimiters, *next_token) == NULL)
	{
		next_token++;
	}
	/* Set the end of the current token to '\0' and update next_token */
	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}
	return (current_token);
}

/**
 * _atoi - convert a str representation of an int
 * To its corresponding int value
 * @str: string to be converted
 * Return: int value of str
 */

int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;
	/* Handle leading whitespace */
	while (str[i] == ' ')
	{
		i++;
	}
	/* Handle optional sign */
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	/* Convert digits to integer */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
