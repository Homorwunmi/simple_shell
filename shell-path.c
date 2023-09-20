#include "shell.h"

/**
 * get_env_path - Retrieves and duplicates the environment PATH.
 * Return: A string of the PATH variable or NULL if not found.
 */
char *get_env_path(void)
{
	int a;
	char *duplicate = NULL;

	for (a = 0; environ[a] != NULL; a++)
	{
		if (strncmp(environ[a], "PATH", 4) == 0)
		duplicate = strdup(environ[a]);
	}
	/*Free this return value if it's not NULL */
	return (duplicate);
}
