#include "shell.h"

/**
 * display_error - Outputs a custom error message to standard error.
 * @prog_name: Name of the program.
 * @cmd_seq: Command count.
 * @user_cmd: Command entered by the user.
 */

void display_error(char *prog_name, int cmd_seq, char *user_cmd)
{
	output_string(prog_name);
	output_string(": ");
	output_char(cmd_seq + '0');
	output_string(": ");
	output_string(user_cmd);
	output_string(": not found\n");
}

/**
 * output_string - Prints a string.
 * @txt: The string to be printed.
 */

void output_string(char *txt)
{
	while (*txt)
	{
		output_char(*txt++);
	}
}

/**
 * output_char - Prints a character to standard error.
 * @char_to_display: The character to be printed.
 * Return: The number of bytes written.
 */

int output_char(char char_to_display)
{
	return (write(2, &char_to_dispaly, 1));
}
