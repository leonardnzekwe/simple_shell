#include "main.h"

/**
 * check_get_args - function that checks and catches get_args error
 * @line_buffer: line buffer passed as parameter
 * Return: Success (0)
 */

int check_get_args(char *line_buffer)
{
	if (line_buffer != NULL)
	{
		/* (CTRL + D) or end-of-file reached */
		if (line_buffer[0] == '\0')
		{
			/* End of file reached */
			free(line_buffer);
			exit(0);
		}
		else
		{
			/* An error occurred during input */
			free(line_buffer);
			exit(1);
		}
	}
	else
	{
		/* Memory allocation failed */
		free(line_buffer);
		exit(1);
	}
	return (0);
}
