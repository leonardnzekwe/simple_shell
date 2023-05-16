#include "main.h"

/**
 * exe_args - argument execution function
 * @cmd: command name
 * @arg_vector: custom argument vector
 * @arg_count: custom argument count
 * Return: Success (0)
 */

int exe_args(char *cmd, char **arg_vector, int arg_count)
{
	int arg_exe;
	pid_t process_id;
	pid_t my_pid, sh_pid;
	int i;

	i = 0;
	while (arg_vector[i] != NULL)
	{
		printf("You entered in index [%d]: %s\n", i, arg_vector[i]);
		i++;
	}
	printf("Arg count: %d\n", arg_count);
	if (arg_count > 0)
	{
		/* using execve to execute commands */
		printf("------------------------\n");
		sh_pid = getppid();
		printf("Parent Process id is %u\n", sh_pid);
		process_id = fork();
		if (process_id == -1)
		{
			perror(cmd);
			exit(1);
		}
		else if (process_id == 0)
		{
			my_pid = getpid();
			printf("Child Process id is %u\n", my_pid);
			printf("------------------------\n");
			printf("----Output Begin----\n");
			arg_exe = execve(arg_vector[0], arg_vector, NULL);
			if (arg_exe == -1)
			{
				perror(cmd);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
		printf("----Output End----\n");
	}
	return (0);
}
