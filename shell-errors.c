#include "shell.h"

/**
 * print_error - Prints a custom error message to standard error.
 * @prog_name: Name of the program.
 * @cmd_count: Command count.
 * @cmd: Command input by the user.
 */

void print_error(char *prog_name, int cmd_count, char *cmd)
{
	print_string(prog_name);
	print_string(": ");
	print_char(cmd_count + '0');
	print_string(": ");
	print_string(cmd);
	print_string(": not found\n");
}

/**
 * print_string - Prints a string.
 * @str: The string to be printed.
 */

void print_string(char *str)
{
	while (*str)
	{
		print_char(*str++);
	}
}

/**
 * print_char - Prints a character to standard error.
 * @character: The character to be printed.
 * Return: The number of bytes written.
 */

int print_char(char character)
{
	return (write(2, &character, 1));
}
