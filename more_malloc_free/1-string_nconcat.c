#include "main.h"
#include <stdlib.h>

/* @REMOVE BEFORE COMMIT */
#include <stdio.h>

/**
 * string_nconcat - partially concatenates two strings
 * @s1: string (pointer to array of char)
 * @s2: string (pointer to array of char)
 * @n: positive integer
 * Description: creates a new string composed of s1
 *   onto which up to "n" or "length" chars of s2 are appended,
 *   whichever is shorter.
 * Return: pointer to new string.
 * 
 * Additional information
 *   - NULL strings must be processed as "empty strings".
 *   - Must return NULL if failure.
 *   - Must stop at "full s2 length" if n > s2.length
 *       (no filling extra space).
 *   - New string must be properly terminated with EOL.
 *
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	/* Size for concatenation */
	unsigned int concat_string_length = 0;
	/* String created from concat. */
	char *concatenated_string;
	/* Cursor dedicated to copy/concat */
	unsigned int cp_idx = 0;
	/* Source string's length. */
	unsigned int s1_length = 0;
	/* We actually also need s2 length in fact, I think,   */
	/*   so we know if we have or not to manually add EOL. */
	unsigned int s2_length_including_EOL = 0;
	/* Reusable generic iterator. */
	unsigned int i;

	if (n == 0)
	{
		concatenated_string = s1;
		return concatenated_string;
	}
	/* First we must know length of first string WITHOUT EOL */
	/*  so we can deduce total space to reserve by adding n. */
	/* Does it work with NULL string? */
	if (s1 != NULL)
		while (s1[++s1_length])
		;
	if(s2 != NULL)
		while (s2[s2_length_including_EOL++])
		;
	/* @remove before commit */
	printf("Number of chars to copy is %d.\n", n);
	printf("Source string s1 is: %s \n", s1);
	printf("  and its length WITHOUT EOL is %d. \n", s1_length);
	printf("Source string s2 is: %s \n", s2);
	printf("  and its length WITH EOL is %d. \n", s2_length_including_EOL);

	/* realloc is forbidden so we use malloc to make full copy. */
	concat_string_length = (n < s2_length_including_EOL) 
		? s1_length + n + 1 
		: s1_length + s2_length_including_EOL
	;
	printf("Contact String length is %d.\n", concat_string_length);
	concatenated_string = (char *)malloc(concat_string_length * sizeof(char));

	for (i = 0; s1[i] != '\0'; i++)
	{
		concatenated_string[cp_idx] = s1[i];
		cp_idx++;
	}
	/* Tried to do something smart and failed miserably. xd */
	/* while (cp_idx < concat_string_length) */
	/* concatenated_string[cp_idx] = s2[cp_idx - concat_string_length]; */
	for (i = 0; i < n; i++)
	{
		printf("S2 index should be %d \n", concat_string_length - cp_idx);
		concatenated_string[cp_idx] = s2[i];
		/* concatenated_string[cp_idx] = s2[cp_idx - concat_string_length]; */
		cp_idx++;
	}
	/* We "reaffect" since it's not a problem even if it was affected. */
	concatenated_string[cp_idx] = '\0';

	return concatenated_string;
}
