#include "main.h"
/*#include <stdio.h>*/
/**
 * char *_strncat - appends up to N bytes from src to dest.
 * @dest: pointer to an array of char (string)
 * @src: pointer to an array of char (string)
 * @n: int max number of chars to append (1 char =1 byte).
 *
 * Description: appends up to n chars of src to the end of dest
 *   without being preoccupied of neatly closing with nullbyte.
 * Return: pointer to character array.
 */
char *_strncat(char *dest, char *src, int n)
{
	/* Will be used instead of dest to keep the original address. */
	/* This time I use a single pointer for both phases, */
	/*   "set copy start" and "actually copy".           */
	char *copier;
	/* Used to parse src string and read its values. */
	char *reader;
	/* Used to keep track of copy and respect max. */
	int char_count;

	copier = dest;
	reader = src;

	/* Pushing "cursor" address up to the point where it targets */
	while ((*++copier))
	; /* This is honestly a stupid Betty constraint, actually LESS readable. */

	/* Using the nice trick I learned from previous exercises. */
	/* DO NOT forget to add a limit on str size!! xd */
	/* Otherwise immediate sanction: "stack smashing detected". */
	for (char_count = 0; char_count < n && *reader != '\0'; char_count++)
	{
		/* printf("Adding character %c ", *reader); */
		/* printf(" of ASCII number %d\n", (unsigned int)*reader); */
		*copier++ = *reader++;
		/* printf("Current last character of dest after copy is %c \n", *copier); */
		/* printf("Its ASCII is %d \n", (unsigned int)*copier); */
	}
	if (*copier != '\0')
	{
		/* printf("Entered 'last char not EOL', last char is %c", *copier); */
		*copier = '\0';
	}
	return (dest);
}
