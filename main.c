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

	/* command line args */
	if (ac > 1)
	{
		av = av + 1;
		ac = ac - 1;
		exe_args(exe, av, ac, NULL, NULL);
	}
	else
	{
		/* input not from command line */
		get_args(exe);
	}
	return (0);
}
