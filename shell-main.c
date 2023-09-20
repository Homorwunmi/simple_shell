#include "shell.h"

/**
 * prompt_if_interactive - Display prompt if in interactive mode.
 * @mode: Mode of operation.
 */
void prompt_if_interactive(int mode)
{
	if (mode)
		write(1, "$ ", 2);
}

/**
 * handle_invalid_command - Handle when command is invalid.
 * @args: Arguments.
 * @progname: Program name.
 * @count: Command count.
 *
 * Return: Error number.
 */
int handle_invalid_command(char **args, char *progname, int count)
{
	char cmdc = count + '0';

	print_error(progname, cmdc, args[0]);
	free(args);
	return (127);
}


/**
 * main - Main function for shell.
 * @argc: Argument count.
 * @argv: Argument values.
 *
 * Return: Error number.
 */
int main(int argc, char **argv)
{
	int mode = isatty(0), count = 0;
	char *buffer = NULL, **args = NULL, *fullcmd = NULL;
	size_t buff_Size = 0;
	ssize_t num;

	(void)argc;
	while (1)
	{
		count++;
		prompt_if_interactive(mode);
		num = getline(&buffer, &buff_Size, stdin);
		if (num == -1)
		{
			free(buffer);
			exit(errno);
		}
		truncate_at_comment(buffer);
		args = tokenize(buffer);
		if (!args[0])
		{
			free(args);
			continue;
		}
		if (access(args[0], X_OK) == -1 &&
				execute_builtin_commands(args, argv[0], buffer) != 1)
		{
			fullcmd = find_command_path(get_env_path(), args[0]);
			if (!fullcmd)
			{
				errno = handle_invalid_command(args, argv[0], count);
				continue;
			}
			execute_full_command(args, argv, fullcmd);
			continue;
		}
		execute_command(args, argv);
	}
	return (errno);
}
