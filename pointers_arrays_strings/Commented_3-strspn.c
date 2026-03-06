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
	c = 0;
	for (i = 0; s[i] != '\0' && substr_ended == 0; i++)
	{
		printf("Parsing character %c at index %d.\n", s[i], i);
		while (accept[c])
		{
			printf("  Comparing with acceptable char %c.\n", accept[c]);
			if (s[i] != accept[c])
			{
				printf("Found end!!\n");
				substr_ended = 1;
				break;
			}
			else
				substr_length++;
		}
	}
	return (substr_length);
}
