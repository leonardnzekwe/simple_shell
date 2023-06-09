#include "main.h"

/**
 * get_args - Get Arguments
 * @exe: executable file name
 * Return: On Success (0)
 */

int get_args(char *exe)
{
	int prompt_count = 0;

	while (1)
	{
		int arg_count = 0;
		ssize_t num_char_read = 0;
		size_t buffer_size = 0;
		char **arg_vector = NULL;
		char *line_buffer = NULL;
		char *line_buffer_dup = NULL;
		char *command_path = NULL;

		prompt_count++;
		if (isatty(STDIN_FILENO) != 0) /* Check mode of interactivity */
			write(STDOUT_FILENO, "$ ", 3);
		num_char_read = get_line(&line_buffer, &buffer_size);
		if (num_char_read == -1) /* getline() failed */
			check_get_args(line_buffer, buffer_size);
		else if (num_char_read == 0) /* No Read */
		{
			free(line_buffer);
			exit(EXIT_SUCCESS);
		}
		else if (_strncmp(line_buffer, "exit", 4) == 0) /*exit*/
			exit_shell(prompt_count, exe, arg_count,
				arg_vector, line_buffer, line_buffer_dup);
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
			process_args(exe, prompt_count, arg_count, arg_vector, line_buffer,
				line_buffer_dup, command_path);
	} return (0);
}

/**
 * check_get_args - function that checks and catches get_args error
 * @line_buffer: line buffer passed as parameter
 * @buffer_size: buffer size passed as parameter
 * Return: Success (0)
 */

int check_get_args(char *line_buffer, size_t buffer_size)
{
	/* catch getline() failure scenarios */
	if (line_buffer == NULL || buffer_size == 0)
	{
		/* Memory allocation failed */
		exit(EXIT_FAILURE);
	}
	else
	{
		/* End of File (CTRL + D) */
		if (isatty(STDIN_FILENO) != 0) /* Check mode of interactivity */
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(line_buffer);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
