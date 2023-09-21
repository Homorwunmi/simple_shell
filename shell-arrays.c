#include "shell.h"

/**
 * free_str_array - Frees memory of a dynamically allocated string set.
 * @total: Total number of elements in the array.
 * @string_set: Array of dynamically allocated strings to be freed.
 */
void free_str_array(int total, char *string_set[])
{
	int i;

	if (string_set)
	{
		for (i = 0; i < total; i++)
		{
			free(string_set[i]);
		}
		free(string_set);
	}
}
