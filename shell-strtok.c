#include "shell.h"

/**
 * char_is_delimiter - Verifies if a given character 'ch' is a of delimiter.
 * @ch: Character to verify.
 * @delims: String containing all delimiter characters.
 *
 * Return: 1 if 'ch' is among the delimiters, otherwise 0.
 */
int char_is_delimiter(char *ch, const char *delims)
{
	int idx = 0;

	if (ch == NULL || delims == NULL)
		return (0);

	while (delims[idx] != '\0')
	{
		if (*ch == delims[idx])
			return (1);
		idx++;
	}
	return (0);
}

/**
 * modified_strtok - Breaks the string into tokens using specified delimiters.
 * @str: The string intended for tokenization.
 * @delims: Delimiter characters.
 *
 * Return: Pointer to the next available token or NULL if there are none left.
 */
char *modified_strtok(char *str, const char *delims)
{
	static char *remainder; /* keeps track of string left after tokenized*/
	char *token_start, *token_end;

	if (str != NULL)
		remainder = str;

	if (remainder == NULL || *remainder == '\0')
		return (NULL);

	token_start = remainder;
	token_end = strpbrk(remainder, delims);

	if (token_end)
	{
		*token_end = '\0';
		remainder = token_end + 1;
	}
	else
	{
		remainder = NULL;
	}

	while (char_is_delimiter(remainder, delims) && remainder)
	{
		remainder++;
	}

	return ((*token_start) ? token_start : NULL);
}
