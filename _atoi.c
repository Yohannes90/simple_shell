#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted to an integer
 *
 * Return: ni (converted integer)
 */
int _atoi(char *s)
{
	int c, min, isi;
	unsigned int ni;

	c = 0;
	ni = 0;
	min = 1;
	isi = 0;
	while (s[c])
	{
		if (s[c] == '-')
		{
			min *= -1;
		}
		while (s[c] >= '0' && s[c] <= '9')
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}
		if (isi == 1)
		{
			break;
		}
		c++;
	}
	ni *= min;
	return (ni);
}
