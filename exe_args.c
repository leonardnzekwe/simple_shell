#include "main.h"

/**
 * exe_args - argument execution function
 * @exe: executable file name
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_dup: line_buffer_dup parameter to be freed on failure
 * @cmd: command parameter (the first index of the argument vector)
 * Return: Success (0)
 */

int exe_args(char *exe, char *cmd, char **arg_vector,
		char *line_buffer, char *line_buffer_dup)
{
	int arg_exe;
	pid_t process_id;

	/* Check if the command exists in PATH */
	if (access(cmd, F_OK) != -1)
	{
		/* Command exists, execute it */
		process_id = fork();
		if (process_id == -1)
		{
			perror(exe);
			free_mem(arg_vector, line_buffer, line_buffer_dup);
			exit(1);
		}
		else if (process_id == 0)
		{
			arg_exe = execve(cmd, arg_vector, environ);
			if (arg_exe == -1)
			{
				perror(exe);
				free_mem(arg_vector, line_buffer, line_buffer_dup);
			}
			else
			{
				free_mem(arg_vector, line_buffer, line_buffer_dup);
			}
		}
		else
		{
			wait(NULL);
			free_mem(arg_vector, line_buffer, line_buffer_dup);
		}
	}
	else
	{
		perror(exe);
		free_mem(arg_vector, line_buffer, line_buffer_dup);
	}
	return (0);
}

/**
 * free_mem - dynamically allocated memory free function
 * @arg_vector: custom argument vector to be freed
 * @line_buffer: line_buffer parameter to be freed
 * @line_buffer_dup: line_buffer_dup parameter to be freed
 * Return: Success (0)
 */

int free_mem(char **arg_vector, char *line_buffer, char *line_buffer_dup)
{
	free(arg_vector);
	free(line_buffer_dup);
	free(line_buffer);
	return (0);
}
