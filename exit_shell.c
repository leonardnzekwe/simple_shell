#include "main.h"

/**
 * exit_shell - shell exit function
 * @prompt_count: keeps count of prompt loop
 * @exe: executable file name
 * @arg_count: custom argument count
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter
 * @line_buffer_dup: line buffer duplicate parameter
 */

void exit_shell(int prompt_count, char *exe, int arg_count, char **arg_vector,
		char *line_buffer, char *line_buffer_dup)
{
	int exit_status = 0;
	int i = 0;

	/* duplicate and tokenise the line_buffer arguments */
	dup_args(line_buffer, &line_buffer_dup);
	tok_args(line_buffer, line_buffer_dup, &arg_count, &arg_vector);
	/* Check if there is a status parameter */
	if ((arg_count > 1) && (arg_vector[1] != NULL))
	{
		while (arg_vector[1][i] != '\0')
		{
			if (_isdigit(arg_vector[1][i]) == 0)
			{
				_printf("%s: %d: %s: Illegal number: %s\n",
					exe, prompt_count, arg_vector[0], arg_vector[1]);
				exit(2);
			}
			i++;
		}
		exit_status = _atoi(arg_vector[1]);
		if (exit_status < 0)
		{
			_printf("%s: %d: %s: Illegal number: %s\n",
				exe, prompt_count, arg_vector[0], arg_vector[1]);
			exit(2);
		}
	}
	free_mem(arg_vector, line_buffer, line_buffer_dup);
	exit(exit_status);
}
