#include "main.h"
#include <stdio.h>
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
	/* If I wanted to be really explicit I'd also declare   */
	/*   an intermediate pointer to "separate" both roles.  */
	char *writer;

	copy_start_cursor = dest;
	reader = src;

	/* printf("Current state of dest:   %p\n", dest); */
	/* printf("Current state of cursor: %p\n", copy_start_cursor); */

	/* Pushing "cursor" address up to the point where it targets */
	/*   the cell containing the "EOL" character which we will overwrite */
	/* @note I MUST use pre-increment otherwise I would end up "past EOL"*/
	while((*++copy_start_cursor));
	writer = copy_start_cursor;
	/* printf("Current state of writer: %p\n", writer); */
	/* printf("New state of cursor:     %p\n", copy_start_cursor); */
	/* Only way to display a character even '\0' is to ask for its ASCII number */
	/* printf("%d\n", (unsigned char)*copy_start_cursor); */
	
	/* printf("Starting the copy:     %p\n", copy_start_cursor); */
	/* Using the nice trick I learned from previous exercises. */
	while( (*writer++ = *reader++) != '\0');
	/* printf("Dest now should be:     %s\n", dest); */
	
	return dest;
}


/* 
 * @note kept to remember that it is complexifying for nothing.
 * We can directly use pointers "both sides"
 * as long as we can maintain a simultaneous increment 
 * Will be used instead of dest to keep the original address. 
 * char *cursor;
 * Used to parse src string and read its values.
 * int reader;
 * Used to set the starter point then affect src chars. *
 * If I wanted to be really explicit I'd also declare   *
 *   an intermediate pointer to "separate" both roles.  *
 * int writer;
 *
 * cursor = dest;
 * writer = 0;
 *
 * printf("Current state of dest:   %p\n", dest);
 * printf("Current state of cursor: %p\n", cursor);
 * printf("Current number of writer: %i\n", writer);
 * 
 * * Pushing "cursor" address up to the point where it targets *
 *   the cell containing the "EOL" character which we will overwrite *
 * @note I MUST use pre-increment otherwise I would end up "past EOL"*
 * while((*++cursor));
 * for (reader = 0; src[reader] != '\0'; reader++ )
 * {
 *   printf("%c, ", src[reader]);
 *   cursor[reader] = src[reader]; 
 * }
 * printf("String of dest is now %s", dest);
 */
