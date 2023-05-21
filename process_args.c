#include "main.h"

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
