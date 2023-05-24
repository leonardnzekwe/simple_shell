#include "main.h"

/**
 * tok_path - path tokenisation function
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_dup: line_buffer_dup parameter to be freed on failure
 * @command_path: command full path parameter
 * Return: Success (0)
 */

int tok_path(char **command_path, char **arg_vector,
	char *line_buffer, char *line_buffer_dup)
{
	char *path_env = NULL;
	char *path_env_dup = NULL;
	char *path_token = NULL;

	path_env = _getenv("PATH");
	path_env_dup = _strdup(path_env);
	if (path_env_dup == NULL)
	{
		free_mem(arg_vector, line_buffer, line_buffer_dup);
		exit(EXIT_FAILURE);
	}

	path_token = _strtok(path_env_dup, ":");
	while (path_token != NULL)
	{
		free(*command_path);
		*command_path = NULL;
		*command_path = (char *)malloc(_strlen(path_token) +
			_strlen(arg_vector[0]) + 2);
		if (*command_path == NULL)
		{
			free(path_env_dup);
			free_mem(arg_vector, line_buffer, line_buffer_dup);
			exit(EXIT_FAILURE);
		}

		/* Create the full path to the command */
		_strcpy(*command_path, path_token);
		_strcat(*command_path, "/");
		_strcat(*command_path, arg_vector[0]);

		if (access(*command_path, F_OK) == 0)
		{
			break; /* stop searching */
		}
		path_token = _strtok(NULL, ":");
	}
	free(path_env_dup);
	return (0);
}
