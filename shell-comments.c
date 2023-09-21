#include "shell.h"

/**
 * remove_comment - Removes comment within a given input string
 * comments are detected by the character (#).
 * @line: The input string to be cleaned from comments.
 * An unescaped # character is considered a comment.
 * Otherwise, it's treated as a regular character.
 */
void remove_comment(char *line)
{
	int txt = 0;

	while (line[txt])
	{
		if (txt > 0 && line[txt] == '#' && line[txt - 1] != ' ')
		{
			line[txt] = '\0';
			break;
		}
		if (line[txt] == '#')
		{
			line[txt] = '\0';
			break;
		}
		txt++;
	}
}
