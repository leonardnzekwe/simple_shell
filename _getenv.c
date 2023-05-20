#include "main.h"

/**
 * _getenv - function to get environment variables
 * @name: environment variable name
 * Return: NULL
 */

char *_getenv(const char *name)
{
	int i;
	char *variable;
	char *value;
	size_t name_len;

	if (name == NULL || _strlen(name) == 0)
	{
		/* Invalid name */
		return (NULL);
	}
	/* Iterate over each environment variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		variable = environ[i];

		/* Find the position of the '=' character */
		value = _strchr(variable, '=');

		/* Calculate the length of the variable name */
		name_len = value - variable;

		if (value != NULL)
		{
			if (name_len == _strlen(name) && _strncmp(variable, name, name_len) == 0)
			{
				/* Return the value after '=' */
				return (value + 1);
			}
		}
	}
	/* Environment variable not found */
	return (NULL);
}
