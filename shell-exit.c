#include "shell.h"

/**
 * custom_exit - Exits the shell with a customed exit status.
 * @args: Array of tokens containing the exit status.
 *
 * Return: 0 (Success)
 */
int custom_exit(char **args)
{
	int status = 0;

	/* If an exit status is provided, validate and set it.*/
	if (args[1] != NULL)
	{
		if (compare_strings(args[1], "0") == 0)
		{
			status = 0;
		}
		else
		{
			status = atoi(args[1]);
			if (status <= 0)
			{
				write(STDERR_FILENO, "Invalid exit status\n", 20);
				return (1);
			}
		}
	}

	exit(status);
}
