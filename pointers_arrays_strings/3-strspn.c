#include "main.h"
#define NULL ((void *)0)
#include <stdio.h>

/**
 * _strspn - gets length of substring from string start.
 * @s: pointer to array of characters we want to search.
 * @accept: pointer to array of characters accepted
 *
 * Description: search for a substring in provided string
 *   which only contains characters from a given set.
 * Return: positive integer.
 *
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int substr_length = 0;
	unsigned int substr_ended = 0;
	int i;
	int c;

	/* We want to parse string UNTIL we find */
	/* ONE character which isn't "acceptable" */
	for (i = 0; s[i] != '\0' && substr_ended == 0; i++)
	{
		c = 0;
		while (accept[c])
		{
			if (s[i] == accept[c])
			{
				substr_length++;
				break;
			}
			c++;
		}
		/* My algorithm is not intuitive. */
		/* There is probably a simpler/more readable way. */
		if (accept[c] == '\0')
			substr_ended = 1;
	}
	return (substr_length);
}
