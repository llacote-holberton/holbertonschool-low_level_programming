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
 *
 * @warning Check number 8 FAILED on checker (output in one case).
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
	/* Must also support the "searched char is EOL"! */
	/* And logically only way without changing whole structure */
	/*   is once we have parser at the end of the string. */
	if (c == '\0')
		first_found = parser;

	return (first_found);
}
