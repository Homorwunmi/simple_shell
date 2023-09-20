#include "shell.h"

/**
 * tokenize - Splits a string into tokens based on delimiters.
 * @input: The input string to be tokenized.
 * Return: An array of pointers to the tokens.
 */

char **tokenize(char *input)
{
	const int MAX_TOKENS = 25;
	char **tokens = NULL;
	int index = 0;
	char *token = NULL;
	char *delimiter = " \n";

	tokens = malloc(sizeof(char *) * MAX_TOKENS);

	if (!tokens)
		return (NULL);

	token = strtok(input, delimiter);

	while (token && index < MAX_TOKENS - 1)
	{
		tokens[index++] = token;
		token = strtok(NULL, delimiter);
	}
	tokens[index] = NULL;
	return (tokens);
}
