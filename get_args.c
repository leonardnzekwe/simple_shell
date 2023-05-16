#include "main.h"

/**
 * get_args - Get Arguments
 * @cmd: command name
 * Return: On Success (0)
 */

int get_args(char *cmd)
{
	int arg_count = 0;
	char **arg_vector = NULL;
	ssize_t num_char_read;
	char *line_buffer = NULL;
	char *line_buffer_cpy = NULL;
	size_t buffer_size = 0;

	while (1)
	{
		/* Check & Print "$ " only if input is from a terminal */
		if (isatty(STDIN_FILENO) != 0)
		{
			printf("$ ");
		}
		num_char_read = getline(&line_buffer, &buffer_size, stdin);
		if (num_char_read == -1)
		{
			/* catch getline() failure scenarios */
			check_get_args(line_buffer);
		}
		else
		{
			cpy_args(line_buffer, &line_buffer_cpy);
			tok_args(line_buffer, line_buffer_cpy, &arg_count, &arg_vector);

			/* getline() succeded */
			if (arg_count > 1)
				dprintf(2, "%s: No such file or directory\n", cmd);
			else
				exe_args(cmd, arg_vector, arg_count, line_buffer, line_buffer_cpy);
		}
		free(line_buffer_cpy);
		free(arg_vector);
	}
	free(line_buffer);
	return (0);
}
