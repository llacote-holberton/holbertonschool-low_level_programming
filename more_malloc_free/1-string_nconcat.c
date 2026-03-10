#include "main.h"
#include <stdlib.h>

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
	unsigned int total_length_without_EOL = 0; /* Size for concatenation */
	char *concatenated_string;						/* String created from concat. */
	unsigned int cp_idx = 0;					/* Cursor dedicated to copy/concat */
	unsigned int s1_length = 0;								/* Source string's length. */
	unsigned int s2_length = 0;			 /* Also needed to trim n if needed. */
	unsigned int i;												 /* Reusable generic iterator. */

	/* Covering NULL corner case, by setting them "empty" on the fly.    */
	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;

	/* Two different writings for & while to show same result. */
	for (s1_length = 0; s1[s1_length] != '\0'; s1_length++)
	;
	while (s2[s2_length] != '\0')
		s2_length++;

	/* Trimming n if greater than s2.length to avoid problems later. */
	n = (n < s2_length) ? n : s2_length;
	total_length_without_EOL = s1_length + n;
	;

	concatenated_string = (char *)malloc(total_length_without_EOL * sizeof(char));
	for (i = 0; s1[i] != '\0'; i++)
	{ /* Recopying s1 without EOL */
		concatenated_string[cp_idx] = s1[i];
		cp_idx++;
	}
	for (i = 0; i < n; i++)
	{ /* Appending "up to n" chars of s2. */
		concatenated_string[cp_idx] = s2[i];
		cp_idx++;
	}
	/* We "reaffect" since it's not a problem even if it was affected. */
	concatenated_string[cp_idx] = '\0';

	return (concatenated_string);
}
