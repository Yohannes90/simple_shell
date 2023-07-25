#include "shell.h"

/**
 * get_function - selects correct function to perform the task
 * @s: operator passed as argument to the program
 *
 * Return: pointer to function corresponding to built in function
 */
int (*get_function(char *s))(char **args)
{
	builtin list[] = {
		{"cd", sh_cd},
		{"help", sh_help},
		{"exit", sh_exit},
		{"env", sh_env},
		{"setenv", sh_setenv},
		{"unsetenv", sh_unsetenv},
		{NULL, NULL}
	};
	int i = 0;

	while (list[i].builtin_str != NULL && strcmp(s, list[i].builtin_str) != 0)
	{
		i++;
	}

	return (list[i].builtin_func);
}

/**
 * execute - maps if command is a process or builtin
 * @args: arguments to execute
 *
 * Return: function or process if successful or else -1
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (-1);
	}
	if (get_function(args[0]) == NULL)
	{
		return (new_process(args));
	}
	return (get_function(args[0])(args));
}
