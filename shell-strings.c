#include "shell.h"

/**
 * compare_strings - Compares two strings up to n bytes.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes to be compared.
 *
 * Return: 0 if strings match up to n bytes, 1 otherwise.
 */
int compare_strings(char *s1, char *s2, size_t n)
{
	size_t idx;

	if (!s1 || !s2)
	return (1);

	for (idx = 0; idx < n; idx++)
	{
		if (s1[idx] != s2[idx])
		return (1);
	}
	return (0);
}

/**
 * compareStrings - compares two strings
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 0 if the strings are equal, a +ve value if s1 is greater,
 * and a -ve value if s2 is greater.
 */
int compareStrings(const char *s1, const char *s2)
{
    size_t idx;

    if (s1 == NULL && s2 == NULL)
        return (0);
    if (s1 == NULL)
        return (-1);
    if (s2 == NULL)
        return (1);

    for (idx = 0; s1[idx] != '\0' || s2[idx] != '\0'; idx++)
    {
        if (s1[idx] == '\0' && s2[idx] != '\0')
            return (-1);
        if (s1[idx] != '\0' && s2[idx] == '\0')
            return (1);
        if (s1[idx] > s2[idx])
            return (1);
        if (s1[idx] < s2[idx])
            return (-1);
    }
    return (0);
}


/**
 * string_dup - Creates a duplicate of the provided string.
 * @src: Source string to be duplicated.
 *
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *string_dup(char *src)
{
	int idx, length;
	char *dup_str;

	length = strlen(src);
	dup_str = malloc(sizeof(char) * (length + 1));
	/* +1 for the null terminator*/

	if (!dup_str)
	return (NULL);

	for (idx = 0; src[idx]; idx++)
	dup_str[idx] = src[idx];
	dup_str[idx] = '\0';

	return (dup_str);
}
