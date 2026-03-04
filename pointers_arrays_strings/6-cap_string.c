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
	char *separator_checker;
	/* Set of ASCII characters considered separators */
	/* Could probably also use ASCII numbers range but */
	/* Using an explicit set is easier and more readable. */
	/* ONLY valid way for a oneliner. */
	/* ACTUALLY not the easiest */
	/* char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}' }; */
	/* THIS is easier since we get an automatic end of line */
	char *separators = " \t\n,;.!?'\"(){}";
	cursor = string_to_alter;
	/* @warning CANNOT put the "is lowercase" check at this level */
	/*   otherwise would (logically) stop at first non-lowercase. */
	while (*cursor != '\0')
	{
		/* printf("Current character is '%c'.\n", *cursor); */
		/* @note I think it's slightly better to "modify the next" */
		/*   because otherwise we would "re-check" a character we  */
		/*   just checked in the previous loop cycle. */
		/* Maybe easier/faster to just use a massive switchcase? */
		separator_checker = separators;
		while (*separator_checker != '\0')
		{
			/* printf("  Comparing char %c with separator %c.\n", *cursor, *separator_checker); */
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
}
