#include "main.h"

/**
 * dup_args - function to duplicate arguments
 * @line_buffer: line buffer paramter
 * @line_buffer_dup: line buffer duplication parameter
 * Return: Success (0)
 */

int dup_args(char *line_buffer, char **line_buffer_dup)
{
	*line_buffer_dup = _strdup(line_buffer);
	if (*line_buffer_dup == NULL)
	{
		free(line_buffer);
		exit(1);
	}
	return (0);
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
