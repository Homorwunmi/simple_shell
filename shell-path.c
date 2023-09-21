#include "shell.h"

/**
 * fetch_path_env - Retrieves and clones the environment's PATH.
 * Return: A string representing the PATH variable or NULL if absent.
 */
char *fetch_path_env(void)
{
	int idx;
	char *clonedPath = NULL;

	for (idx = 0; environ[idx] != NULL; idx++)
	{
		if (compare_strings(environ[a], "PATH", 4) == 0)
		{
			clonedPath = string_dup(&environ[idx][5]);
			break; /*Exit loop once PATH is found*/
		}
	}
	/*Free this return value if it's not NULL */
	return (clonedPath);
}
