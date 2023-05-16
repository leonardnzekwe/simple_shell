#include "main.h"

/**
 * exe_args - argument execution function
 * @cmd: command name
 * @arg_vector: custom argument vector
 * @arg_count: custom argument count
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_cpy: line_buffer_cpy parameter to be freed on failure
 * Return: Success (0)
 */

int exe_args(char *cmd, char **arg_vector, int arg_count,
	char *line_buffer, char *line_buffer_cpy)
{
	int arg_exe;
	pid_t process_id;
	int i;

	i = 0;
	while (arg_vector[i] != NULL)
	{
		i++;
	}
	if (arg_count > 0)
	{
		/* using execve to execute commands */
		process_id = fork();
		if (process_id == -1)
		{
			perror(cmd);
			free(line_buffer);
			free(line_buffer_cpy);
			free(arg_vector);
			exit(1);
		}
		else if (process_id == 0)
		{
			arg_exe = execve(arg_vector[0], arg_vector, NULL);
			if (arg_exe == -1)
			{
				perror(cmd);
				free(line_buffer);
				free(line_buffer_cpy);
				free(arg_vector);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
