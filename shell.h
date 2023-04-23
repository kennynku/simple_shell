#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

extern char **environ;

void prompt1(void);
void prompt2(void);
char *read_command(void);
char **tokenizer(char *command);
char **reallocate(char **pointer, size_t *size);
int print_env(void);
int _strcmp(char *s1, char *s2);

#endif /* MAIN_H*/
