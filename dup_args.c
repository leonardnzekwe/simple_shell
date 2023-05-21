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
