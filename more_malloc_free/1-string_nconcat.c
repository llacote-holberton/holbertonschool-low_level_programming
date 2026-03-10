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
	unsigned int total_length_without_EOL = 0;
	/* String created from concat. */
	char *concatenated_string;
	/* Cursor dedicated to copy/concat */
	unsigned int cp_idx = 0;
	/* Source string's length. */
	unsigned int s1_length = 0;
	/* We actually also need s2 length in fact, I think,   */
	/*   so we know if we have or not to manually add EOL. */
	unsigned int s2_length = 0;
	/* Reusable generic iterator. */
	unsigned int i;

	/* Covering NULL strings corner case, by        */
	/*   affecting them "empty" strings on the fly. */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* First we must know length of first string WITHOUT EOL */
	/*  so we can deduce total space to reserve by adding n. */
	/* WRONG!! As the condition is evaluated BEFORE increment */
	/*   BUT DOESN'T BLOCK IT since increment is "within" it! */
	/* So it would "count the EOL" and we don't want it. */
	/*while (s1[s1_length++] != '\0'); */
	/* With a FOR the condition is evaluated separately         */
	/*   and the increment comes AFTER the "for body" is parsed */
	/*   so since for "" the condition is FALSE immediately     */
	/*   we stop the loop before even the first increment.      */
	for (s1_length = 0; s1[s1_length] != '\0'; s1_length++)
		;
	/* OR we can just make a "regular while" */
	while (s2[s2_length] != '\0') 
		s2_length++;
	
	
	/* realloc is forbidden so we use malloc to make full copy.   */
	/* n is given by copy so we can modify it without scrupules.  */
	/* "Adjusting it" to set a hard limit avoiding later problems */
	/*   if "initial n" > s2.length (writing "beyond s2 EOL").    */
	n = (n < s2_length) ? n : s2_length;
	total_length_without_EOL = s1_length + n;
	;
	printf("\n\nS1 is: %s with length %d\nS2 is: %s with length %d\n, N chars to copy is: %d\n", s1, s1_length, s2, s2_length, n);
	printf("Concat String length is %d.\n", total_length_without_EOL);
	concatenated_string = (char *)malloc(total_length_without_EOL * sizeof(char));

	for (i = 0; s1[i] != '\0'; i++)
	{
		concatenated_string[cp_idx] = s1[i];
		cp_idx++;
	}
	/* Tried to do something smart and failed miserably. xd */
	/* while (cp_idx < total_length_without_EOL) */
	/* concatenated_string[cp_idx] = s2[cp_idx - total_length_without_EOL]; */
	for (i = 0; i < n; i++)
	{
		concatenated_string[cp_idx] = s2[i];
		/* concatenated_string[cp_idx] = s2[cp_idx - total_length_without_EOL]; */
		cp_idx++;
	}
	/* We "reaffect" since it's not a problem even if it was affected. */
	concatenated_string[cp_idx] = '\0';
	printf("Final string is %s with length including EOL %d\n\n", concatenated_string, cp_idx);
	
	return concatenated_string;
}
