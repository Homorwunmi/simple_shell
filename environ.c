#include "shell.h"

/**
 * ReportEnvError - displays notification when
 * there are too many environment arguments.
 * @cmd_tokens: an array of command tokens.
 */
void ReportEnvError(char **cmd_tokens)
{
	char errorMsg[300] = "";

	_strcpy(errorMsg, "env issue: '");
	_strcat(errorMsg, cmd_tokens[1]);
	_strcat(errorMsg, "': Directory or file not found");
	write(STDOUT_FILLENO, errorMsg, _strlen(errorMsg));
	write(STDOUT_FILENO, "\N", 1);
}

/**
 * display_environment - showcase environment variables.
 * @input_tokens: tokenized user input.
 *
 * Return: 1 (Success).
 */
int display_environment(char **input_tokens)
{
	int idx = 0;

	if (input_tokens[1] != NULL)
	{
		ReportEnvError(input_tokens);
		return (1);
	}
	while (environ[idx] != NULL)
	{
		write(1, environ[idx], _strlen(environ[idx]));
		write(1, "\n", 1);
		idx++;
	}
	return (1);
}
