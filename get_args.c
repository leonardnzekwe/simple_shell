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

		/* Check for interactive and non-interative modes */
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 3);
		num_char_read = getline(&line_buffer, &buffer_size, stdin);
		if (num_char_read == -1) /* getline() failed */
			check_get_args(line_buffer);
		else if (num_char_read == 5 && _strcmp(line_buffer, "exit\n") == 0) /*exit*/
		{
			free(line_buffer);
			exit(0); /* no further processing, end the loop */
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

/**
 * process_args - process the arguments obtained from getline()
 * @exe: executable file name
 * @arg_count: custom argument count
 * @line_buffer: line buffer parameter
 * @line_buffer_dup: line buffer duplication buffer
 * @arg_vector: custom argument vector
 * @command_path: command full path parameter
 * Return: Success (0)
 */

int process_args(char *exe, int arg_count, char **arg_vector,
	char *line_buffer, char *line_buffer_dup, char *command_path)
{
	dup_args(line_buffer, &line_buffer_dup);
	tok_args(line_buffer, line_buffer_dup, &arg_count, &arg_vector);
	if (arg_count > 0)
	{
		if (access(arg_vector[0], F_OK) == 0)
			exe_args(exe, arg_vector[0], arg_vector, line_buffer, line_buffer_dup);
		else
		{
			tok_path(&command_path, arg_vector, line_buffer, line_buffer_dup);
			exe_args(exe, command_path, arg_vector, line_buffer, line_buffer_dup);
			free(command_path);
		}
	}
	return (0);
}
