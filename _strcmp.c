#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to first string to be compared
 * @s2: pointer to second string to be compared
 *
 * Return: 0(if same), other number(if different)
 */
int _strcmp(char *s1, char *s2)
{
	int length = 0;
	int i = 0;

	while (s1[i++])
	{
		length++;
	}
	for (i = 0; i < length; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}
