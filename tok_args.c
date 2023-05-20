#include "main.h"

/**
 * tok_args - function that tokenise arguments
 * @line_buffer: line buffer parameter
 * @line_buffer_dup: line buffer copy parameter
 * @arg_count: custom argument count
 * @arg_vector: custom argument vector
 * Return: (0)
 */

int tok_args(char *line_buffer, char *line_buffer_dup,
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
		free(line_buffer);
		free(line_buffer_dup);
		exit(1);
	}

	/* store tokenized arguments */
	token = strtok(line_buffer_dup, delimiter);
	while (token != NULL)
	{
		(*arg_vector)[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	(*arg_vector)[i] = NULL;

	return (0);
}
