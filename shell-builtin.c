#include "shell.h"

/**
 * execute_builtin_commands - Handle execution of certain built-in commands.
 * @args: An array of user-provided command arguments.
 * @name: Name of the shell program (unused in current logic).
 * @buf: Buffer containing the user's input.
 *
 * Return: 1 if a built-in command was executed, 0 otherwise.
 */
int execute_builtin_commands(char **args, char *name, char *buf)
{
	int line = 0;
	int index = 0;
	int status = 0; /* Default exit status */

	(void)name;

	if (args[0] == NULL)
	{
		return (line);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1]) /* If an argument is provided to exit */
		{
			status = atoi(args[1]); /* Convert string to integer */
			if (status < 0)
			{
				write(1, "Invalid exit status\n", 20);
				return (line); /* Continue shell execution */
			}
		}
		free(args);
		free(buf);
		exit(status); /* Exit with provided status, or 0 if none given */
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[index] != NULL)
		{
			write(1, environ[index], strlen(environ[index]));
			write(1, "\n", 1);
			index++;
		}
		free(args);
		line  = 1;
	}
	return (line);
}
