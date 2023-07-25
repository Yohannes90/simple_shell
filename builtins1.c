#include "shell.h"

/**
 * sh_env - prints the current enviroment
 * @args: unused attribute
 *
 * Return: 0 if successful.
 */
int sh_env(__attribute__((unused))char **args)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * sh_cd - change working directory to the specified directory
 * @args: string of arguments to specify directory to change to
 *
 * Return: 0 if successful, or 1 if not
 */
int sh_cd(char **args)
{
	static char *oldpwd;
	char *dir = args[1];
	char *pwd;

	if (dir == NULL)
	{
		dir  = getenv("HOME");
	}
	if (dir == NULL)
	{
		printf("sh: cd HOME not set\n");
		return (1);
	}
	else if (strcmp(dir, "-") == 0)
	{
		if (oldpwd == NULL)
		{
			printf("sh: cd OLDPWD not set\n");
			return (1);
		}
		dir = oldpwd;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	if (chdir(dir) != 0)
	{
		perror("chdir");
		free(pwd);
		return (1);
	}
	if (oldpwd)
	{
		free(oldpwd);
	}
	oldpwd = pwd;
	return (0);
}

/**
 * sh_help - prints help message to user
 * @args: unused attribute
 *
 * Return: Always 0.
 */
int sh_help(__attribute__((unused))char **args)
{
	printf("Type command names and arguments then hit enter.\n");
	printf("Use the man command for information on other commands.\n");
	return (0);
}

/**
 * sh_exit - exits program
 * @args: exit status(if any)
 *
 * Return: exit with status(if any) else
 */
int sh_exit(char **args)
{
	int status;

	if (args[1] == NULL)
	{
		exit(0);
	}
	else
	{
		status = atoi(args[1]);
		exit(status);
	}
}
