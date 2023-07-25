#include "shell.h"

/**
 * sh_setenv - sets enviroment variables
 * @args: arguments provided Variable and Value
 *
 * Return: 0 if successful, or 1 if not
 */
int sh_setenv(char **args)
{
	int status;

	if (args[1] == NULL || args[2] == NULL)
	{
		printf("setenv: provide proper arguments (setenv VARIABLE VALUE)\n");
		return (1);
	}
	status = setenv(args[1], args[2], 1);
	if (status != 0)
	{
		printf("setenv: Error while setting enviroment variable\n");
		return (1);
	}
	return (0);
}

/**
 * sh_unsetenv - unsets/removes enviroment variables
 * @args: arguments provided Variable(to be removed)
 *
 * Return: 0 if successful, or 1 if not
 */
int sh_unsetenv(char **args)
{
	int status;

	if (args[1] == NULL)
	{
		printf("unsetenv: provide proper arguments (unsetenv VARIABLE)\n");
		return (1);
	}
	if (getenv(args[1]) == NULL)
	{
		printf("unsetenv:  No such environment variable\n");
		return (1);
	}
	status = unsetenv(args[1]);
	if (status != 0)
	{
		printf("unsetenv: Error while unsetting enviroment variable\n");
		return (1);
	}
	return (0);
}
