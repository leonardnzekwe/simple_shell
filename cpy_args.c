#include "main.h"

/**
 * cpy_args - function to copy arguments
 * @line_buffer: line buffer paramter
 * @line_buffer_cpy: line buffer copy parameter
 * Return: Success (0)
 */

int cpy_args(char *line_buffer, char **line_buffer_cpy)
{
	int i = 0;
	int len = 0;

	/* find the length of line_buffer */
	while (line_buffer[len] != '\0')
	{
		len++;
	}

	*line_buffer_cpy = malloc(len + 1);
	if (*line_buffer_cpy == NULL)
	{
		exit(1);
	}

	/* copy the line_buffer */
	while (line_buffer[i] != '\0')
	{
		(*line_buffer_cpy)[i] = line_buffer[i];
		i++;
	}
	(*line_buffer_cpy)[i] = '\0';

	return (0);
}
