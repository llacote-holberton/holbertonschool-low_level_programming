#include "main.h"
#include <stdio.h>
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

	/*printf("\n\n ORIGINAL version of dest: %s\n", dest);
	printf("\n\n String to COPY FROM: %s\n", src);*/
	
	/* Pushing "cursor" address up to the point where it targets */
	/* This time we want to OVERWRITE, *not* APPEND */
	/* while ((*++copier)); */ 
	/* Using the nice trick I learned from previous exercises. */
	/* DO NOT forget to add a limit on str size!! xd */
	/* Otherwise immediate sanction: "stack smashing detected". */
	/*printf("\nSTART COPY \n");
	printf("  At start copier address is %p.\n", copier);*/
	for (char_count = 0; char_count < n; ++char_count)
	{
		/*printf("Character count is now %d. \n", char_count);*/
		
		/* This time we want an "adaptative" behaviour depending on */
	  /*  the relationship between str.length and n               */
		/*  so we'll need to "get" its length at some point. */
		
		/* if ( *reader == '\0' ) {} */ /* Wrong approach */
		/* Since character = 1 byte we should get the length */
		/*   by sustracting address of reader with address of src. */
		/* 
		 * Actually (after asking confirmation/explanation) it's the 
		 *   difference in "number of elements" directly, and work only
		 *   because we made the two pointers start at the same place (obviously).
		 */
		/* STRICT inferiority BECAUSE the nth cycle is the "branching one" */
		while ( (reader - src) < n )
		{
			/*printf("Still copying \n");
			printf("Before copy reader - src equals %d\n", (int)(reader - src));
			printf("  Adding character %c \n", *reader); */
			*copier++ = *reader++;
			/*printf("AFTER COPY Reader - src equals %d\n", (int)(reader - src));*/
			++char_count;
		}
		/* Nth case management  */
		/* (I feel it's bad to have this case "inside" the global loop) */
		if( (reader - src) == n )
		{
			/*printf("Processing the special case str length = n \n");
			printf(" Character at length = n is %c \n", *reader);*/
			if(*reader == '\0')
				*copier = *reader;
		}
		else
		{
			*++copier = '\0';
		}
	}
	/*printf("Final character count is %d.\n", char_count);
	printf("\nEND OF COPY\n");
	printf("New version of dest: %s\n\n", dest);*/
	return (dest);
}
