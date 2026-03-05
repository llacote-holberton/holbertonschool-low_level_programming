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

	char *cursor;
	char *triggers     = "aAeEoOtTlL";
	char *replacements = "4433007711";
	int i;

	cursor = string_to_alter;

	while (*cursor != '\0')
	{
		for (i = 0; trigger[i] != '\0'; i++)
		{
			if (*cursor == triggers[i])
				*cursor = replacements[i];
		}
		cursor++;
	}
	return (string_to_alter);
}
