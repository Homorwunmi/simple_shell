#include "shell.h"

/**
 * run_full_cmd - Executes a specified full command.
 * @cmd_args: Arguments for the command
 *	(first element usually represents the command itself).
 * @cmd_argv: Array of initial command line arguments for error notifications.
 * @full_cmd_path: Full path of the command to be initiated.
 *
 * Return: Status of the initiated command or error code.
 */
int run_full_cmd(char **cmd_args, char **cmd_argv, char *full_cmd_path)
{
	pid_t childProcess;
	int cmd_status;

	childProcess = fork();
	if (childProcess < 0)
	{
		perror(full_cmd_path);
		exit(-1);
	}
	else if (childProcess == 0)
	{
		execve(full_cmd_path, cmd_args, environ);
		perror(cmd_argv[0]);
		exit(2);
	}
	else
	{
		wait(&cmd_status);
		if (WIFEXITED(status))
			cmd_status = WEXITSTATUS(cmd_status);

		errno = cmd_status;

		free(full_cmd_path);
		free(cmd_args);
	}

	return (cmd_status);
}
