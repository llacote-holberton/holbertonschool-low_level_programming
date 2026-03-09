#include "main.h"
#include <stdlib.h>
/* @Comment before commit */
/* #include <stdio.h> */

/**
 * _strdup - duplicates a string in new memory area.
 * @str: string to copy (pointer to array of char)
 *
 * Description: Takes a pointer to a string to
 *   duplicate it in another area of memory.
 * Return: pointer to array or NULL if fails.
 */
char *_strdup(char *str)
{
	/* Used to get length of string to copy */
	int length = 0;
	/* Copy iterator index */
	int cpidx;
	/* Pointer to created copy */
	char *string_copy;

	/* Fist we get length of original string */
	/* Note that I assume that it is properly terminated. */
	/* Approach put away because does not include the EOL char */
	/* for (length = 0; str[length] != '\0'; length++); */
	/* We need to use the "while" to have a way to */
	/*   "integrate" the increment into the condition itself */
	/*   so we can use the "post-increment" trick */
	while (str[length++] != '\0')
	;
	/* This above allows "one more loop" before breaking */
	/* Apparently this works too, interesting */
	/* for (length = 0; str[length++] != '\0'; */
	/* printf("Original string is... \n   %s \n ", str); */
	/* printf("  Its length WITH EOL is %d\n", length); */
	if (length == 0)
		string_copy = NULL;
	else
		string_copy = (char *)malloc(length * (sizeof(char)));
	if (string_copy != NULL)
	{
		for (cpidx = 0; cpidx < length; cpidx++)
			string_copy[cpidx] = str[cpidx];
	}
	return (string_copy);
}
