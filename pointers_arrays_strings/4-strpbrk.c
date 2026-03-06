#include "main.h"
#define NULL ((void *)0)

/**
 * *_strpbrk - gets position of first occurence of char in a set.
 * @s: pointer to string (array of characters) we want to search.
 * @accept: pointer to array of characters accepted
 *
 * Description: search for a substring in provided string
 *   stopping at first found occurence and returning its address.
 * Return: pointer to char OR NULL if not found.
 *
 */
char *_strpbrk(char *s, char *accept)
{
	/* Pointer to first occurence of searched "char set". */
	char *first_occurence = s;
	/* Truthful value used to set the state "first occurence found". */
	/* int found = 0; */
	/* Truthful value used to set the state "still not found". */
	int still_searching = 1;
	/* Cursor for "accept table" cycling searchs. */
	int c;

	while (still_searching == 1 && *first_occurence)
	{
		for (c = 0; accept[c] != '\0' ; c++)
		{
			if (*first_occurence == accept[c])
			{
				still_searching = 0;
				break;
			}
		}
		first_occurence += still_searching;
	}
	if (still_searching)
		first_occurence = NULL;
	return (first_occurence);
}
