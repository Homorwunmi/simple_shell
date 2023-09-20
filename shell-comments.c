#include "shell.h"

/**
 * truncate_at_comment - Truncates the string at the first unescaped
 * comment character (#).
 * @input: The string in which to search and truncate at the comment character.
 * If # is preceded by a non-space character, it's considered a comment.
 * Otherwise, it's treated as a regular character.
 */
void truncate_at_comment(char *input)
{
	int text = 0;

	while (input[text])
	{
		if (text > 0 && input[text] == '#' && input[text - 1] != ' ')
		{
			input[text] = '\0';
			break;
		}
		if (input[text] == '#')
		{
			input[text] = '\0';
			break;
		}
		text++;
	}
}
