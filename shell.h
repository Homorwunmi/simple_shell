#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <sys/stat.h>

#define MAX_INPUT_LENGTH 100

/* Global Variables */
extern char **environ;
void print_env(void);
void truncate_at_comment(char *input);
char **tokenize(char *input);
int execute_full_command(char **args, char **argv, char *command_path);
char *string_dup(char *src);
int compare_strings(char *s1, char *s2, size_t n);
int handle_builtin_commands(char **args, char *name, char *buf);
void executeShellPrompt(int interactiveMode);
void processInput(char *inputLine, char **av);
int main(int ac, char **av);
void fixComments(char *inputLine);
char **tokenizeInput(char *inputLine);
void handleNonExecutable(char **arguments, char **av, char *inputLine);
void executeExecutable(char **arguments, char **av);
int manage_invalid_command(char **args, char *progname, int count);
void display_prompt(int mode);
int process_shell(char *buffer, char **argv, int count);
char *find_command_path(char *directories, char *command);
char *get_env_path(void);
int execute_full_command(char **args, char **argv, char *command_path);
int execute_command(char **args, char **argv);
int handle_builtin_commands(char **args, char *progname, char *buffer);
void print_environment(char **env);
void execute_builtin_env(char **env);
int process_builtin_commands(char **args, char *buffer);
void _start(void);

/* functions to print errors */
void free_string_array(int size, char *strings[]);
void print_error(char *prog_name, int cmd_count, char *cmd);
void print_string(char *str);
int print_char(char character);

#endif /* SHELL_H */
