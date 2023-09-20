#include "shell.h"

/**
 * _strncmp - Compares two strings up to n bytes.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes to be compared.
 * Return: 0 if strings match up to n bytes, 1 otherwise.
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t a;

	if (!s1 || !s2)
	return (1);

	for (a = 0; a < n; a++)
	{
		if (s1[a] != s2[a])
		return (1);
	}
	return (0);
}

/**
 * _strdup - Creates a duplicate of the given string.
 * @str: String to be duplicated.
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	int a, len;
	char *duplicate;

	len = strlen(str);
	duplicate = malloc(sizeof(char) * (len + 1));
	/* +1 for the null terminator*/

	if (!duplicate)
	return (NULL);

	for (a = 0; str[a]; a++)
	duplicate[a] = str[a];
	duplicate[a] = '\0';

	return (duplicate);
}
