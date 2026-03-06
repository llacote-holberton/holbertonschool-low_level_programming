#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: pointer to an array of char (string)
 * @s2: pointer to an array of char (string)
 *
 * Description: compares two strings char per char
 *   and returns the difference in "ASCII coding value"
 *   of the first "non-identical pair"
 *   (implying negative is 1st shorter length,
 *    0 if fully identical, positive if 2nd shorter).
 * Return: integer which is ASCII value difference.
 */
int _strcmp(char *s1, char *s2)
{
	int ascii_difference;
	/* As usual we don't want to alter the original strings */
	/* So we make pointer copies. */
	char *sc1;
	char *sc2;

	/* Algorithm: we parse two chains side by side */
	/*   and must "break" as soon as we find a difference */
	sc1 = s1;
	sc2 = s2;
	/* We MUST also break when getting an EOL to avoid errors. */
	while
	(
		(ascii_difference = *sc1 - *sc2) == 0
	  && (*sc1 != '\0' && *sc2 != '\0')
	)
	{
		sc1++;
		sc2++;
	}

	return (ascii_difference);
}
