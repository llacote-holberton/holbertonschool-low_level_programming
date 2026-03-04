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
	/* Set of ASCII characters considered separators */
	/* Using a truth table now that I do how to make one easily in C. */
	/* Confer https://en.wikipedia.org/wiki/Truth_table. */
	/* Principle: initialize a table with "falsy values" (0). */
	/* Size is on purpose: it matches the ASCII (Extended) encoding table. */
	int separators_table[256] = {0};
	/* Then we just need to fill in with "truthful values" for separators. */
	/* Because character is just an ASCII number, we can directly type it  */
	/*   "as cell index" and C reads its numerical value so no need to know it! */
	/* Confer https://www.rapidtables.com/code/text/ascii-table.html */
	/* To avoid "losing" lines "for Betty" we use the "original" string.*/
	char *separators = " \t\n,;.!?'\"(){}";

	while (*separators != '\0')
	{
		/* Type conversion mandatory to avoid compilation warning as error. */
		separators_table[(unsigned int)*separators] = 1;
		separators++;
	}
	/* THIS is easier since we get an automatic end of line */
	cursor = string_to_alter;
	/* @warning Assumption that we start sentence with a new word */
	is_new_word_starting = 1;
	/* @warning CANNOT put the "is lowercase" check at this level */
	/*   otherwise would (logically) stop at first non-lowercase. */
	while (*cursor != '\0')
	{
		/* Contrarily to v2 we separate the two verifications */
		/* Wouldn't have found this logic without IA as I didn't see the point. */
		/* Point is to avoid potential out of bound access of the "cursor + 1" version. */

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


/*
 * VERSION 2 */
 /* Pointer used to parse* and hydrate string. */
 /* char *cursor; */
 /* Set of ASCII characters considered separators */
 /* Using a truth table now that I do how to make one easily in C. */
 /* Confer https://en.wikipedia.org/wiki/Truth_table. */
 /* Principle: initialize a table with "falsy values" (0). */
 /* Size is on purpose: it matches the ASCII (Extended) encoding table. */
 /* int separators_table[256] = {0}; */
 /* Then we just need to fill in with "truthful values" for separators. */
 /* Because character is just an ASCII number, we can directly type it  */
 /*   "as cell index" and C reads its numerical value so no need to know it! */
 /* Confer https://www.rapidtables.com/code/text/ascii-table.html */
 /* To avoid "losing" lines "for Betty" we use the "original" string.*/
 /* char *separators = " \t\n,;.!?'\"(){}"; */
 /* while (*separators != '\0') */
 /*{ */
	 /* Type conversion mandatory to avoid compilation warning as error. */
	/* separators_table[(unsigned int)*separators] = 1; */
	/* separators++; */
 /*} */
 /* THIS is easier since we get an automatic end of line */
 /*cursor = string_to_alter; */
 /* @warning CANNOT put the "is lowercase" check at this level */
 /*   otherwise would (logically) stop at first non-lowercase. */
 /*while (*cursor != '\0') */
 /*{ */
	 /* Much simpler than v1 now, but we still have the "nesteed control". */
	 /* 0 is interpreted as false, anything else as true */
	/* if (separators_table[(unsigned int)*cursor]) */
	/*	 if (*(cursor + 1) >= 'a' && *(cursor + 1) <= 'z') */
	/*		 *(cursor + 1) = *(cursor + 1) + ('A' - 'a'); */
	/* cursor++; */
 /* } */
 /* return (string_to_alter);
  */


/*
 * V1 VERY DIRTY
 *
 * Set of ASCII characters considered separators
 */
/* Could probably also use ASCII numbers range but */
/* Using an explicit set is easier and more readable. */
/* ONLY valid way for a oneliner. */
/* ACTUALLY not the easiest */
/* char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}' }; */
/* THIS is easier since we get an automatic end of line */
/* char *separators = " \t\n,;.!?'\"(){}"; */
/* cursor = string_to_alter; */
/* @warning CANNOT put the "is lowercase" check at this level */
/*   otherwise would (logically) stop at first non-lowercase. */
/* while (*cursor != '\0')
* {
*/	/* printf("Current character is '%c'.\n", *cursor); */
	/* @note I think it's slightly better to "modify the next" */
	/*   because otherwise we would "re-check" a character we  */
	/*   just checked in the previous loop cycle. */
	/* Maybe easier/faster to just use a massive switchcase? */
/*	separator_checker = separators;
	while (*separator_checker != '\0')
	{
		printf("  Comparing char %c with separator %c.\n", *cursor, *separator_checker);
		if
			(
				*cursor == *separator_checker
				&& *(cursor + 1) >= 'a'
			&& *(cursor + 1) <= 'z'
			)
			{
				*(cursor + 1) = *(cursor + 1) + ('A' - 'a');
				break;
			}
			else
				separator_checker++;
	}
	cursor++;
}
return (string_to_alter);
*/
