#include "main.h"

/**
 * main - Entry Point of the Program
 * @ac: main command line arguments count
 * @av: main command line arguments vector
 * Return: On Success (0)
 */

int main(int ac, char **av)
{
	char *cmd = av[0];

	if (ac > 1)
	{
		av = av + 1;
		ac = ac - 1;
		exe_args(cmd, av, ac, NULL, NULL);
	}
	else
	{
		get_args(cmd);
	}
	return (0);
}
