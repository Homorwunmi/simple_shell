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
void remove_comment(char *line);
char **tokenize(char *input_str);
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
int tokenize_directory_paths(char *paths, char **path_tokens);
char *find_cmd_path(char *paths, char *cmd);
char *fetch_path_env(void);
int execute_full_command(char **args, char **argv, char *command_path);
int run_command(char **cmd_args, char **cmd_argv);
int handle_builtin_commands(char **args, char *progname, char *buffer);
void print_environment(char **env);
void execute_builtin_env(char **env);
int process_builtin_commands(char **args, char *buffer);
void _start(void);

/* functions to print errors */
void free_str_array(int total, char *string_set[]);
void display_custom_error(char *prog_name, int cmd_seq, char *user_cmd);
void output_string(char *txt);
int output_char(char char_to_display);

#endif /* SHELL_H */
