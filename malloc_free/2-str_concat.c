#include "main.h"
#include <stdlib.h>
/* @Comment before commit */
/* #include <stdio.h> */

/**
 * str_concat - concatenates two strings cleanly.
 * @s1: string to append upon (pointer to array of char)
 * @s2: string to "attach after" (pointer to array of char)
 *
 * Description: Cleanly concatenates two strings
 *   by "resetting" the EOL properly to make one string.
 * Return: pointer to array or NULL if fails.
 *
 * ADDITIONAL NOTES:
 *   a) NULL should be treated as empty string.
 *   b) Function still assumes that strings
 *        are properly terminated.
 */
char *str_concat(char *s1, char *s2)
{
	/* Reusable iterator to parse s1 and s2 (count then copy) */
	int i = 0;
	/* Total length WITHOUT EOL (added on the fly in malloc). */
	int fused_length = 0;
	/* Append process index */
	int appender;
	/* Pointer to created fusion */
	char *fused_string;

	if (s1 != NULL)
		for (i = 0; s1[i] != '\0'; i++)
			fused_length++;
	if (s2 != NULL)
		for (i = 0; s2[i] != '\0'; i++)
			fused_length++;

	if (fused_length == 0)
		fused_string = NULL;
	else /* Adding one to account for the EOL to append at the end. */
		fused_string = (char *)malloc((fused_length + 1) * (sizeof(char)));
	if (fused_string != NULL)
	{
		appender = 0;
		for (i = 0; s1[i] != '\0'; i++)
		{
			fused_string[appender] = s1[i];
			appender++;
		}
		for (i = 0; s2[i] != '\0';)
		{
			/* printf("Printing character %c at fused pos %d \n", s2[i], appender); */
			fused_string[appender] = s2[i];
			appender++;
			i++;
		}
		/* Finishing fused string properly. */
		fused_string[appender] = '\0';
		/* printf("Final state of fused_string: %s.\n", fused_string); */
	}
	return (fused_string);
}

/* ==== BRAINSTORM NOTES === */
/* Dropped this because ultimately we have no use for */
/*  those intermediate variables if all goes well. */
/* Used to get length of string to append onto */
/* int s1_length = 0; */
/* Making separate variable for clarity and simplicity */
/* int s2_length = 0; */
/* Because we want to "overwrite" EOL of first string */
/*   this time I choose to count length without EOL and "add 1" afterwards. */
