#include "main.h"
/**
 * leet - "Translates" a string into "1337" (leet) language.
 * @string_to_alter: pointer to an array of chars
 *
 * Description: Replaces letters a, A, e, E, o, O, t, T, l, L
 *   with 4, 4, 3, 3, 0, 0, 7, 7, 1, 1 respectively.
 *   Uses a static lookup table built once on first call.
 *
 * Return: pointer to modified string.
 *
 * ---- SPECIAL CONSTRAINTS -----
 *  You can only use one if in your code
 *  You can only use two loops in your code*
 *  You are not allowed to use s.w.i.t.c.h
 *  You are not allowed to use any ternary operation*
 */
char *leet(char *string_to_alter)
{
	static int vocabulary[256];
	static int initialized;
	char *cursor;
	char *triggers     = "aAeEoOtTlL";
	char *replacements = "4433007711";
	int i;
	
	if (!initialized)
	{
		for (i = 0; triggers[i] != '\0'; i++)
			vocabulary[(unsigned int)triggers[i]] = replacements[i];
		initialized = 1;
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
