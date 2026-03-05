#include "main.h"
#define NULL ((void *)0)

/**
 * *_strchr - finds the first occurence of c in s.
 * @s: pointer to array of characters we want to convert
 * @c: character.
 *
 * Description: search for c character in provided string
 *   and returns a pointer to that address or null.
 * Return: address of found char or null if coulnd't be found.
 */
char *_strchr(char *s, char c)
{
	char *first_found;
	char *parser;

	parser = s;
	first_found = NULL;
	while (*parser)
	{
		if (*parser == c)
		{
			first_found = parser;
			/* MUST break because character may appear again */
			break;
		}
		parser++;
	}

	return (first_found);
}
