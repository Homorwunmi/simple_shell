#include "shell.h"

/**
 * execute_command - Executes a specified command.
 * @args: The command to execute
 * (typically the first element of the user arguments).
 * @argv: Array of command line arguments used for error reporting.
 * Return: Status of the executed command or error code.
 */
int execute_command(char **args, char **argv)
{
	pid_t num;
	int status;

	num = fork();
	if (num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (num == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		errno = status;

		/* Free the dynamically allocated array of strings */
		free(args);
	}

	return (status);
}
