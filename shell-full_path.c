#include "shell.h"

/**
 * tokenize_directory_paths - Divides the directories string into an array.
 * @paths: A colon-separated string of directories.
 * @path_tokens: An array to store the resulting tokens.
 *
 * Return: The number of tokens.
 */
int tokenize_directory_paths(char *paths, char **path_tokens)
{
	int idx = 0;
	char *token = NULL;

	token = strtok(paths, ":");

	while (token)
	{
		path_tokens[idx++] = token;
		token = strtok(NULL, ":");
	}
	path_tokens[idx] = NULL;
	return (idx);
}

/**
 * find_cmd_path - Identifies the valid path of the
 * command in given directories.
 * @paths: A colon-separated string of directories in
 * search for the command.
 * @cmd: The command name to identify.
 *
 * Return: A dynamically allocated string showing the
 * full path to the command or NULL if unavailable.
 */
char *find_cmd_path(char *paths, char *cmd)
{
	int token_count;
	int idx;
	size_t path_size;
	char **path_tokens = NULL, *pathname = NULL;

	if (!paths)
		return (NULL);
	paths = strchr(paths, '=');

	if (paths)
		paths++;
	path_tokens = malloc(sizeof(char *) * 40);

	if (!path_tokens)
		return (NULL);

	token_count = tokenize_directory_paths(paths, path_tokens);

	for (idx = 0; idx < token_count; idx++)
	{
		path_size = strlen(path_tokens[idx]) + strlen(cmd) + 2;
		pathname = malloc(path_size);

		if (!pathname)
			continue;
		sprintf(pathname, "%s/%s", path_tokens[idx], cmd);

		if (access(pathname, X_OK) == 0)
		{
			free(path_tokens);
			return (pathname);
		}
		free(pathname);
	}
	free(path_tokens);
	return (NULL);
}
