#include "shell.h"

/**
 * tokenize_directories - Tokenizes the directories string into an array.
 * @directories: A colon-separated string of directories.
 * @dir_tokens: An array to store the tokens.
 * Return: The number of tokens.
 */
int tokenize_directories(char *directories, char **dir_tokens)
{
	int index = 0;
	char *token = NULL;

	token = strtok(directories, ":");

	while (token)
	{
		dir_tokens[index++] = token;
		token = strtok(NULL, ":");
	}
	dir_tokens[index] = NULL;
	return (index);
}

/**
 * find_command_path - Searches for a valid path of the
 * command in provided directories.
 * @directories: A colon-separated string of directories in
 * which to search for the command.
 * @command: The command name to search for.
 * Return: A dynamically allocated string with the
 * full path to the command or NULL if not found.
 */
char *find_command_path(char *directories, char *command)
{
	int num_tokens;
	int index;
	size_t path_length;
	char **dir_tokens = NULL, *pathname = NULL;

	if (!directories)
		return (NULL);
	directories = strchr(directories, '=');

	if (directories)
		directories++;
	dir_tokens = malloc(sizeof(char *) * 40);

	if (!dir_tokens)
		return (NULL);

	num_tokens = tokenize_directories(directories, dir_tokens);

	for (index = 0; index < num_tokens; index++)
	{
		path_length = strlen(dir_tokens[index]) + strlen(command) + 2;
		pathname = malloc(path_length);

		if (!pathname)
			continue;
		sprintf(pathname, "%s/%s", dir_tokens[index], command);

		if (access(pathname, X_OK) == 0)
		{
			free(dir_tokens);
			return (pathname);
		}
		free(pathname);
	}
	free(dir_tokens);
	return (NULL);
}
