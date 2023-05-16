#include "main.h"

/**
 * tok_args - function that tokenise arguments
 * @cmd: command name
 * @line_buffer: line buffer parameter
 * @line_buffer_cpy: line buffer copy parameter
 * @arg_count: custom argument count
 * @arg_vector: custom argument vector
 * Return: (0)
 */

int tok_args(char *cmd, char *line_buffer, char *line_buffer_cpy,
		int *arg_count, char ***arg_vector)
{
	char *delimiter;
	char *token;
	int i;

	i = 0;
	*arg_count = 0;
	delimiter = " \n";

	/* count number of tokenized args */
	token = strtok(line_buffer, delimiter);
	while (token != NULL)
	{
		token = strtok(NULL, delimiter);
		(*arg_count)++;
	}

	*arg_vector = malloc(sizeof(char *) * (*arg_count + 1));
	if (*arg_vector == NULL)
	{
		perror(cmd);
		exit(1);
	}

	/* store tokenized arguments */
	token = strtok(line_buffer_cpy, delimiter);
	while (token != NULL)
	{
		(*arg_vector)[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	(*arg_vector)[i] = NULL;

	return (0);
}
