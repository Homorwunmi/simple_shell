#include "shell.h"

/**
 * execute_full_command - Executes a specified full command.
 * @args: The command arguments
 *	(first element typically contains the command itself).
 * @argv: Array of original command line arguments (used for error reporting).
 * @command_path: Full path of the command to execute.
 * Return: Status of the executed command or error code.
 */
int execute_full_command(char **args, char **argv, char *command_path)
{
	pid_t num;
	int status;

	num = fork();
	if (num < 0)
	{
		perror(command_path);
		exit(-1);
	}
	else if (num == 0)
	{
		execve(command_path, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		/* Correct conversion of the child process's exit status */
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		errno = status;

		free(command_path);
		free(args);
	}

	return (status);
}
