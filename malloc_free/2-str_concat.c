#include "main.h"
#include <stdlib.h>
/* @Comment before commit */
 #include <stdio.h> 

/**
 * str_concat - concatenates two strings cleanly.
 * @s1: string to append upon (pointer to array of char)
 * @s2: string to "attach after" (pointer to array of char)
 * 
 * Description: Cleanly concatenates two strings
 *   by "resetting" the EOL properly to make one string.
 * NOTE: NULL should be treated as empty string.
 * Return: pointer to array or NULL if fails.
 */
char *str_concat(char *s1, char *s2)
{

	/* Reusable iterator to parse s1 and s2 (count then copy) */
	int i;
	/* Total length including EOL */
	int fused_length = 0;
	/* Append process index */
	int appender;
	/* Pointer to created fusion */
	char *fused_string;

	/* Fist we get length of both strings */
	/* @fixme add guard clauses for s1 or s2 equals NULL */
	/* Note that I still assume that its are properly terminated. */
	for (i = 0; s1[i] != '\0'; i++)
		fused_length++;
	printf("S1 is '%s' \n of length WITHOUT EOL %d. \n", s1, fused_length); 
	/* This time I use variant to include the EOL. */
	for (i = 0; s2[i++] != '\0';)
		fused_length++;
	printf("S2 is '%s' \n of length WIT EOL %d. \n", s2, i); 
	printf("Total length of fused string with EOL is %d. \n", fused_length); 
	
	if (fused_length == 0)
		fused_string = NULL;
	else
		fused_string = (char *)malloc(fused_length * (sizeof(char)));
	if (fused_string != NULL)
	{
		appender = 0;
		for (i = 0; s1[i] != '\0'; i++)
		{
			printf("Printing character %c at fused pos %d \n", s1[i], appender);
			fused_string[appender] = s1[i];
			appender++;
		}
		printf("Current state of fused_string: %s.\n", fused_string);
		for (i = 0; s2[i] != '\0';)
		{
			printf("Printing character %c at fused pos %d \n", s2[i], appender);
			fused_string[appender] = s2[i];
			appender++;
			i++;
		}
		printf("Final state of fused_string: %s.\n", fused_string);
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
