#include "shell.h"

/**
 * main - runs our shell interactively or non interactively
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("#cisfun$ ");
			line = read_line();
		}
		else
		{
			line = read_stream();/*Read input stream*/
		}
		args = split_line(line);/*Split line into arguments*/
		status = execute(args);/*Execute the command with arguments*/

		free(line);/* Free the memory allocated for line*/
		free(args);/* Free the memory allocated for args*/
	} while (status < 1);
	return (0);
}

