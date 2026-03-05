#include "main.h"

/**
 * char *leet - "Translates" a string into "1337" (leet) language.
 * @string_to_alter: pointer to an array of chars
 *
 * Description: Uppercases the first letter of every word
 *   of the provided string.
 * Return: pointer to modified string.
 *
 * ---- SPECIAL CONSTRAINTS -----
 *  You can only use one if in your code
 *  You can only use two loops in your code*
 *  You are not allowed to use s.w.i.t.c.h
 * (warning: checker makes basic grep to check conditions are fulfilled
 *  so the w.o.r.d above had to be "spelled like that" otherwise FAIL.)
 *  You are not allowed to use any ternary operation*
 */
char *leet(char *string_to_alter)
{
	/* Pointer used to parse and hydrate string. */
	char *cursor;
	int vocabulary[256] = {0};
	char *triggers     = "aAeEoOtTlL";
	char *replacements = "4433007711";
	/* Loop incrementer */
	int i;

	/* IIUC benefit of this kind of loop over while *pointer */
	/*  is that we "dynamically jump to cell through offset" */
	/*  so the actual pointer is *not* moved. */
	for (i = 0; triggers[i] != '\0'; i++)
	{
		vocabulary[(unsigned int)triggers[i]] = replacements[i];
	}
	cursor = string_to_alter;
	while (*cursor != '\0')
	{
		if (vocabulary[(unsigned int)*cursor])
			*cursor = vocabulary[(unsigned int)*cursor];
		cursor++;
	}

	return (string_to_alter);
}
