#include "main.h"

/**
 * char *_strcat - concatenates 2 strings.
 * @dest: pointer to an array of char (string)
 * @src: pointer to an array of char (string)
 *
 * Description: appends src to the end of dest
 *   while "moving" the end of line character.
 * Return: void.
 */
char *_strcat(char *dest, char *src)
{
	/* Will be used instead of dest to keep the original address. */
	/* Technically I could have used "writer" directly but I feel */
	/* Having an intermediate is more readable*/
	char *copy_start_cursor;
	/* Used to parse src string and read its values. */
	char *reader;
	/* Used to set the starter point then affect src chars. */
	char *writer;

	/* Initizaliing inner pointers for which we have "starts" known. */
	copy_start_cursor = dest;
	reader = src;

	/* Pushing "cursor" address up to the point where it targets */
	/*   the cell containing the "EOL" character which we will overwrite */
	/* @note I MUST use pre-increment otherwise I would end up "past EOL"*/
	while ((*++copy_start_cursor))
	; /* This is honestly a stupid Betty constraint, actually LESS readable. */
	writer = copy_start_cursor;

	/* Using the nice trick I learned from previous exercises. */
	while ((*writer++ = *reader++) != '\0')
	; /* Same. */

	return (dest);
}
