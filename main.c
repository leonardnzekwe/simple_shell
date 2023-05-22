#include "main.h"

/**
 * main - Entry Point of the Program
 * @ac: main command line arguments count
 * @av: main command line arguments vector
 * Return: On Success (0)
 */

int main(int ac, char **av)
{
	/* store the exe filename */
	char *exe = av[0];

	if (ac > 1)
	{
		/* too many command line args */
		write(STDOUT_FILENO, "Usage: simple_shell\n", 21);
	}
	else
	{
		/* Register signal handler for SIGINT (Ctrl+C) */
		signal(SIGINT, sigint_handler);

		/* Read, Evaluate, Print & Loop */
		/* REPL BASE FUNCTION */
		get_args(exe);
	}

	return (0);
}

/**
 * sigint_handler - function that handles signals
 * @signum: signal number
 */

void sigint_handler(int __attribute__ ((unused)) signum)
{
	/* Reprompt */
	write(STDOUT_FILENO, "\n$ ", 3);
}
