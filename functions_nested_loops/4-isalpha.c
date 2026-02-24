#include "main.h"

/**
 * _isalpha - checks if provided input is a letter.
 * @c: Character's ASCII value to be checked.
 * Description: tests if input matches one character
 *   inside [A-Za-z] set, with binary return (1 = success).
 * Return: boolean.
 */
int _isalpha(int c)
{
	/* @note boundaries are inclusive ('a' and 'z')*/
	int uppercase_floor;
	int lowercase_floor;
	int is_letter;

	/* Useful reference https://devdocs.io/c/language/ascii */
	uppercase_floor = 65;
	lowercase_floor = 97;
	is_letter =
	(
		/* @note beware of using the right logic when combining conditions */
		(uppercase_floor <= c && c <= uppercase_floor + 26)
		|| (lowercase_floor <= c && c <= lowercase_floor + 26)
	) ? 1 : 0;
	return (is_letter);
}
