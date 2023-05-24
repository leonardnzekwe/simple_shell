#include "main.h"

/**
 * process_args - process the arguments obtained from getline()
 * @exe: executable file name
 * @prompt_count: keeps count of prompt loop
 * @arg_count: custom argument count
 * @line_buffer: line buffer parameter
 * @line_buffer_dup: line buffer duplication buffer
 * @arg_vector: custom argument vector
 * @command_path: command full path parameter
 * Return: Success (0)
 */

int process_args(char *exe, int prompt_count, int arg_count, char **arg_vector,
	char *line_buffer, char *line_buffer_dup, char *command_path)
{
	if (is_all_white_space(line_buffer) == 1)
	{
		free(line_buffer);
		exit(EXIT_SUCCESS);
	}
	dup_args(line_buffer, &line_buffer_dup);
	tok_args(line_buffer, line_buffer_dup, &arg_count, &arg_vector);
	if (arg_count > 0)
	{
		if (access(arg_vector[0], F_OK) == 0)
			exe_args(exe, prompt_count, arg_vector[0],
				arg_vector, line_buffer, line_buffer_dup);
		else
		{
			tok_path(&command_path, arg_vector, line_buffer, line_buffer_dup);
			exe_args(exe, prompt_count, command_path,
				arg_vector, line_buffer, line_buffer_dup);
			free(command_path);
		}
	}
	return (0);
}

/**
 * is_all_white_space - function that checks if str is all white space
 * @line_buffer: line_buffer string input to be checked
 * Return: All whitespace (1) ? Non-whitespace (0)
 */

int is_all_white_space(const char *line_buffer)
{
	while (*line_buffer)
	{
		if (!_isspace((unsigned char)*line_buffer))
		{
			return (0);  /* Non-whitespace character found */
		}
		line_buffer++;
	}
	return (1);  /* All characters are whitespace */
}
