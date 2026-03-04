#include "main.h"
#include <stdio.h>
/**
 * char *cap_string - capitalizes all words of a string.
 * @string_to_alter: pointer to an array of chars
 *
 * Description: Uppercases the first letter of every word
 *   of the provided string.
 * Return: pointer to modified string.
 */
char *cap_string(char *string_to_alter)
{
	/* Pointer used to parse and hydrate string. */
	char *cursor;
	/* "Truthful statement" variable. */
	int is_new_word_starting;
	/* Set of ASCII characters considered separators "as truthful table". */
	int separators_table[256] = {0};
	char *separators = " \t\n,;.!?'\"(){}";

	while (*separators != '\0')
	{
		/* Type conversion mandatory to avoid compilation warning as error. */
		separators_table[(unsigned int)*separators] = 1;
		separators++;
	}
	cursor = string_to_alter;
	/* @warning Assumption that we start sentence with a new word */
	is_new_word_starting = 1;
	/* @warning CANNOT put the "is lowercase" check at this level */
	/*   otherwise would (logically) stop at first non-lowercase. */
	while (*cursor != '\0')
	{
		/* Wouldn't have found this v3 without IA as I didn't see the point which  */
		/*  is to avoid potential out of bound access of the "cursor + 1" version. */

		/* Announce "new word starts next char" ONLY when meeting separator. */
		if (separators_table[(unsigned int)*cursor])
			is_new_word_starting = 1;
		/* When meeting other character combine state and "char nature" */
		/*   to decide whether to uppercase, if yes reset the state. */
		else
		{
			if (is_new_word_starting && *cursor >= 'a' && *cursor <= 'z')
				*(cursor) = *(cursor) + ('A' - 'a');
			/* MUST be reset whether we "uppercased or not" to cover */
			/*   case of current character already uppercase. */
			is_new_word_starting = 0;
		}
		cursor++;
	}
	return (string_to_alter);
}
