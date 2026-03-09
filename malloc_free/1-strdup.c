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

	/* Choosing "guard clause" syntax here to stress that */
	/*   we don't even try to process anything. */
	if (str == NULL)
		return (NULL);

	/* This under uses post-increment trick to allow "one more" */
	/* loop before breaking with condition "current equals EOL" */
	while (str[length++] != '\0')
	;
	/* printf("\nOriginal is...\n  %s \n ", (length < 100) ? str : "too big!"); */
	/* printf("  Its length WITH EOL is %d\n", length); */

	string_copy = (char *)malloc(length * (sizeof(char)));
	if (string_copy != NULL)
	{
		for (cpidx = 0; cpidx < length; cpidx++)
			string_copy[cpidx] = str[cpidx];
		/* printf("String copy is %s and has length %d \n", string_copy, cpidx); */
	}
	return (string_copy);
}

/* BRAINSTORM / DEV COMMENTS */
/* Fist we get length of original string */
/* Note that I assume that it is properly terminated. */
/* Approach put away because does not include the EOL char */
/* for (length = 0; str[length] != '\0'; length++); */
/* We need to use the "while" to have a way to */
/*   "integrate" the increment into the condition itself */
/*   so we can use the "post-increment" trick */
/* Apparently this works too, interesting */
/* for (length = 0; str[length++] != '\0'; */
/* WRONG LOGIC!! Doesn't block "empty string" BUT, since */
/*   empty string has EOL (length = 1) does NOT cover NULL either. */
/* if (length == 0) */
/*	string_copy = NULL; */
/*else */
/* ... ... ... */
