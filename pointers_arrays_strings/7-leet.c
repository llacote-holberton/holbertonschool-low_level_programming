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
 *  You can only use one IF in your code
 *  You can only use two loops in your code*
 *  You are not allowed to use s.w.i.t.c.h
 * (warning: checker makes basic grep to check conditions are fulfilled
 *  so the w.o.r.d above had to be "spelled like that" otherwise FAIL.)
 *  You are not allowed to use any ternary operation*
 * 
 * NOTE: the difference of performance between this version and 
 *   "nested loops to, inside first string parse, compare and replace"
 *   the target characters...
 * Is currently infinitesimal because the vocabulary is recreated each time.
 *   it would need to be statically declared and initialized (wich a state
 *   checked on function start) to start making a difference, and it would
 *   still only start feeling significant at big scale (>1m char strings)
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
