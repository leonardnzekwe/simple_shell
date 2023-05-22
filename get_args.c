#include "main.h"

/**
 * get_args - Get Arguments
 * @exe: executable file name
 * Return: On Success (0)
 */

int get_args(char *exe)
{
	while (1)
	{
		int arg_count = 0;
		ssize_t num_char_read = 0;
		size_t buffer_size = 0;
		char **arg_vector = NULL;
		char *line_buffer = NULL;
		char *line_buffer_dup = NULL;
		char *command_path = NULL;

		if (isatty(STDIN_FILENO) != 0) /* Check mode of interactivity */
			write(STDOUT_FILENO, "$ ", 3);
		num_char_read = get_line(&line_buffer, &buffer_size);
		if (num_char_read == -1) /* getline() failed */
			check_get_args(line_buffer);
		else if (_strncmp(line_buffer, "exit", 3) == 0) /*exit*/
		{
			exit_shell(arg_count, arg_vector, line_buffer, line_buffer_dup);
		}
		else if (num_char_read == 4 && _strcmp(line_buffer, "env\n") == 0) /*env*/
		{
			print_env(); /* print environment */
			free(line_buffer);
		}
		else if (num_char_read == 1 && line_buffer[0] == '\n') /* no line input */
		{
			free(line_buffer);
			continue; /* no further processing, restart the loop */
		}
		else /* getline() succeded */
		{
			process_args(exe, arg_count, arg_vector, line_buffer,
				line_buffer_dup, command_path);
		}
	}
	return (0);
}

/**
 * check_get_args - function that checks and catches get_args error
 * @line_buffer: line buffer passed as parameter
 * Return: Success (0)
 */

int check_get_args(char *line_buffer)
{
	/* catch getline() failure scenarios */
	if (line_buffer == NULL)
	{
		/* Memory allocation failed */
		exit(1);
	}
	else
	{
		/* End of File (CTRL + D) */
		free(line_buffer);
		exit(1);
	}
	return (0);
}
