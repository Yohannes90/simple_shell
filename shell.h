#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
#define BUFSIZE 1024
extern char **environ;


char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int new_process(char **args);
char *read_stream(void);

int sh_cd(char **args);
int sh_help(__attribute__((unused))char **args);
int sh_exit(char **args);
int sh_env(char **args);
int sh_setenv(char **args);
int sh_unsetenv(char **args);

/**
 * struct builtin - Struct builtin
 *
 * @builtin_str: The command entered
 * @builtin_func: The function called to handle the command
 */
typedef struct builtin
{
	char *builtin_str;
	int (*builtin_func)(char **);
} builtin;

int (*get_function(char *s))(char **args);

#endif
