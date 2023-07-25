#include "shell.h"

/**
 * new_process - create a new process
 * @args: array of strings that contain command
 *
 * Return: -1 if success, 0 otherwise
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: failed to fork child process\n");
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("error");
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
