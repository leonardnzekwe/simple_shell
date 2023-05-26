#include "main.h"

/**
 * tok_path - path tokenisation function
 * @exe: executable file name
 * @prompt_count: keeps count of prompt loop
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_dup: line_buffer_dup parameter to be freed on failure
 * @command_path: command full path parameter
 * Return: Success (0)
 */

int tok_path(char *exe, int prompt_count, char **command_path,
	char **arg_vector, char *line_buffer, char *line_buffer_dup)
{
	char *path_env = NULL;
	char *path_env_dup = NULL;
	char *path_token = NULL;

	path_env = _getenv("PATH");
	if (path_env == NULL) /* check if _getenv failed */
	{
		path_err(exe, prompt_count, arg_vector, line_buffer, line_buffer_dup);
	}
	path_env_dup = _strdup(path_env);
	if (path_env_dup == NULL) /* check if _strdup failed */
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
			break; /* stop searching */
		path_token = _strtok(NULL, ":");
	}
	free(path_env_dup);
	return (0);
}

/**
 * path_err - path err catch function
 * @exe: executable file name
 * @prompt_count: keeps count of prompt loop
 * @arg_vector: custom argument vector
 * @line_buffer: line_buffer parameter to be freed on failure
 * @line_buffer_dup: line_buffer_dup parameter to be freed on failure
 * Return: Success (0)
 */

int path_err(char *exe, int prompt_count,
	char **arg_vector, char *line_buffer, char *line_buffer_dup)
{
	_printf("%s: %d: %s: not found\n", exe, prompt_count, arg_vector[0]);
	if (isatty(STDIN_FILENO) == 0) /* Check mode of interactivity */
	{
		free_mem(arg_vector, line_buffer, line_buffer_dup);
		exit(127);
	}
	free_mem(arg_vector, line_buffer, line_buffer_dup);
	return (0);
}
