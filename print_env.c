#include "main.h"

/**
 * print_env - a function that prints the environment
 * Return: success (0)
 */

int print_env(void)
{
	/* Get the environment variables */
	char **env_ptr = environ;
	char *env = NULL;
	int env_len = 0;
	/* Print the environment variables */
	while (*env_ptr != NULL)
	{
		env = *env_ptr;
		env_len = _strlen(env);
		write(1, env, env_len);
		write(1, "\n", 1);
		env_ptr++;
	}
	return (0);
}
