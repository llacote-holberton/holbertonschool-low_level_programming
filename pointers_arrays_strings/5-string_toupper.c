#include "main.h"

/**
 * char *string_toupper - puts all chars of string in uppercase.
 * @string_to_alter: pointer to an array of chars
 *
 * Description: Transforms character string at given pointer
 *   in uppercase characters.
 * Return: pointer to modified string.
 */
char *string_toupper(char *string_to_alter)
{
	char *modifier;

	modifier = string_to_alter;
	/* @warning CANNOT put the "is lowercase" check at this level */
	/*   otherwise would (logically) stop at first non-lowercase. */
	while (*modifier != '\0')
	{
		if (*modifier >= 'a' && *modifier <= 'z')
		{
			*modifier = *modifier + ('A' - 'a');
		}
		modifier++;
	}
	return (string_to_alter);
}
