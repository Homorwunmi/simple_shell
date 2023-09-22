#include "shell.h"

/**
 * SetEnvVar - establishes environment variables.
 * @args: tokenized input.
 *
 * Return: Always 1 (Success).
 */
int SetEnvVar(char **args)
{
	int idx = 0;
	char newEnvVar[MAX_LINE], *newEnvPtr;

	if (!args[1])
	{
		print_env(args);
		return (1);
	}
	while (environ[idx])
	{
		if (strncmp(environ[idx], args[1],calc_strlen(args[1])) == 0)
		{
			free(environ[idx]);
			strcpy(environ[idx], args[1]);
			strcat(environ[idx], "=");
			strcat(environ[idx], args[2]);
			return (1);
		}
		idx++;
	}
	strcpy(newEnvVar, args[1]);
	strcat(newEnvVar, "=");
	if (args[2])
		strcat(newEnvVar, args[2]);

	newEnvPtr = malloc(calc_strlen(newEnvVar) + 1);
	if (!newEnvPtr)
	{
		write(STDERR_FILENO, "Setting failed", 16);
		return (1);
	}
	strcpy(newEnvPtr, newEnvVar);
	environ[idx] = newEnvPtr;
	environ[idx + 1] = NULL;
	free(newEnvPtr);
	return (1);
}

/**
 * ModifyEnv - updates an existing environment variable's value.
 * @newVal: the new value.
 * @args: tokenized command.
 *
 * Return: 1 (if it exists and updated).
 */
int ModifyEnv(char *newVal, char **args)
{
	char **tempEnv;

	tempEnv = environ;
	while (*tempEnv)
	{
		if (strncmp(*tempEnv, args[1], calc_strlen(args[1])) == 0 &&
				(*tempEnv)[calc_strlen(args[1])] == '=')
		{
			*tempEnv = newVal;
			return (1);
		}
		tempEnv++;
	}
	return (0);
}

/**
 * UnsetEnv - removes an environment variable.
 * @args: tokenized input.
 *
 * Return: update_environment.
 */
int UnsetEnv(char **args)
{
	int idx = 0, k = 0;

	if (!args[1])
	{
		write(STDERR_FILENO, "Removal failed", 14);
		return (1);
	}
	while (environ[idx])
	{
		if (strncmp(environ[idx], args[1], calc_strlen(args[1])) == 0)
			break;
		idx++;
	}
	if (!environ[idx])
	{
		write(STDERR_FILENO, "Removal failed", 14);
		return (1);
	}
	while (environ[k])
		k++;
	k--;
	environ[idx] = environ[k];
	environ[k] = NULL;
	return (1);
}

/**
 * RunBuiltinCmds - verifies and runs built-in commands.
 * @args: tokenized string.
 *
 * Return: 1 if built-in command executed, -1 otherwise.
 */
int RunBuiltinCmds(char **args)
{
	int idx;
	char *builtinCmds[] = {"setenv", "env", "exit", "unsetenv"};
	typedef int (*BuiltinCmdFunc)(char **);
	BuiltinCmdFunc builtinCmdFunctions[5] = {SetEnvVar,
		print_env, custom_exit, UnsetEnv};

	for (idx = 0; idx < 4; idx++)
	{
		if (strcmp(builtinCmds[idx], args[0]) == 0)
			return ((*builtinCmdFunctions[idx])(args));
	}
	return (-1);
}
