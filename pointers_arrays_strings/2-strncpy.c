#include "main.h"
/* #include <stdio.h> */
/**
 * char *_strncpy - copies n chars of 2nd string onto 1st with filling '\0'.
 * @dest: pointer to an array of char (string)
 * @src: pointer to an array of char (string)
 * @n: int max number of chars to copy (1 char =1 byte).
 *
 * Description: copies up to n chars of src to the end of dest
 *   AND...
 *   0) IF src.length = n
 *   => We includde its EOL character.
 *   1) ELSE IF src.length < n
 *   => complements any "missing cell" with
 *     null-byte characters to end up with desired length
 *     "dest.updated_length = dest.length + n".
 *   2) ELSE IF src.length > n
 *   => We DON'T terminate the string with "EOL" char.
 *      (Arbitrary choice to match official function behaviour).
 * Return: pointer to character array.
 */
char *_strncpy(char *dest, char *src, int n)
{
	/*  Used to "set copy start" and "actually copy".   */
	char *copier;
	/* Used to parse src string and read its values. */
	char *reader;
	/* Used to keep track of copy and respect max. */
	int char_count;

	copier = dest;
	reader = src;

	/* ACTUALLY it's much simpler to just separate in two phases */
	/*   so two distinct loops. */
	/* While actually makes conditional logic easier to read here imo. */
	char_count = 0;

	/* @note MUST stop when "meeting" \0 otherwise we go into random address! */
	/* (reader - src) would work but since we use char_count elsewhere... */
	while ((char_count) < n && *reader != '\0')
	{
		*copier++ = *reader++;
		++char_count;
	}
	/* Nth case management useless since we stop first loop just before now. */
	/*
	 * if (*reader == '\0')
	 * {
	 *   copier = *reader;
	 *   ++char_count;
	 * }
	 */
	while (char_count < n)
	{
		*copier++ = '\0';
		++char_count;
	}
	/* printf("Final character count is %d.\n", char_count); */
	/* printf("New version of dest: %s\n\n", dest); */

	return (dest);
}
