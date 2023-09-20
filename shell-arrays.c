#include "shell.h"

/**
 * free_string_array - Frees a dynamically allocated array of strings.
 * @size: Number of elements in the array.
 * @strings: Array of dynamically allocated strings to be freed.
 */
void free_string_array(int size, char *strings[])
{
	int a;

	if (strings)
	{
		for (a = 0; a < size; a++)
		{
			free(strings[a]);
		}
		free(strings);
	}
}
