#include "main.h"

/**
 * exe_args - argument execution function
 * @exe: executable file name
 * @prompt_count: keeps count of prompt loop
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_dup: line_buffer_dup parameter to be freed on failure
 * @cmd: command parameter (the first index of the argument vector)
 * Return: Success (0)
 */

int exe_args(char *exe, int prompt_count, char *cmd, char **arg_vector,
		char *line_buffer, char *line_buffer_dup)
{
	int arg_exe;
	pid_t process_id;

	/* Check if the cmd exists in PATH */
	if (access(cmd, F_OK) != -1 && _getenv("PATH1") == NULL)
	{
		process_id = fork(); /* Command exists, execute it */
		if (process_id == -1)
		{
			perror(exe);
			free(cmd);
			free_mem(arg_vector, line_buffer, line_buffer_dup);
			exit(EXIT_FAILURE);
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
				free_mem(arg_vector, line_buffer, line_buffer_dup);
		}
		else
			parent_wait(cmd, arg_vector, line_buffer, line_buffer_dup);
	}
	else
	{
		path_err(exe, prompt_count, arg_vector, line_buffer, line_buffer_dup);
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

/**
 * parent_wait - function that waits on the child process
 * @cmd: command parameter to be freed
 * @arg_vector: custom argument vector to be freed
 * @line_buffer: line_buffer parameter to be freed
 * @line_buffer_dup: line_buffer_dup parameter to be freed
 * Return: Success (0)
 */

int parent_wait(char *cmd, char **arg_vector,
	char *line_buffer, char *line_buffer_dup)
{
	int cmd_exit_status = 0;

	wait(&cmd_exit_status);
	if (WIFEXITED(cmd_exit_status))
	{
		WEXITSTATUS(cmd_exit_status);
	}
	if (cmd_exit_status != 0 && isatty(STDIN_FILENO) == 0)
	{
		free(cmd);
		free_mem(arg_vector, line_buffer, line_buffer_dup);
		exit(2);
	}
	free_mem(arg_vector, line_buffer, line_buffer_dup);

	return (0);
}
