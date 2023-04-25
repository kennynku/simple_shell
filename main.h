#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int command_checker(char **cmd, char *buf);
void user_prompt(void);
void signal_handler(int m);
char **shell_tokenizer(char *line);
char *path_tester(char **path, char *command);
char *append_path_utility(char *path, char *command);
int execute_builtin(char **command, char *line);
void exit_command_handler(char **command, char *line);

void print_env_var(void);

/* string handlers */
int _compare_strings(char *s1, char *s2);
int _sting_length(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_sting_duplicate(char *s);
char *_find_character(char *s, char c);

void execution(char *cp, char **cmd);
char *track_path(void);

/* helper function for efficient free */
void free_input_buffer(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* MAIN_H */
