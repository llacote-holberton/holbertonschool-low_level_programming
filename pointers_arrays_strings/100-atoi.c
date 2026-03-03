#include "main.h"
/**
 * _atoi - converts given string into an integer.
 * @s: pointer to array of characters we want to convert
 *
 * Description: "converts" a string in parameter
 *   by returning the first number it contains (or 0).
 * Return: integer as converted string.
 *
 * Official command documentation
 *  https://www.ibm.com/docs/fr/i/7.6.0
 *    ?topic=functions-atoi-convert-character-string-integer
 *
 * ------ ADDITIONAL INFORMATION -----
 * Special rules
 * - The number in the string can be preceded by infinite number of characters.
 * - You need to take into account all the - and + signs before it.
 * - If there are no numbers in the string, the function must return 0
 * - You are not allowed to use 'long' type.
 * - You are not allowed to declare new variables of "type" array.
 * - You are not allowed to hard-code special values.
 * - We will use the -fsanitize=signed-integer-overflow gcc flag
 *     to compile your code.
 *
 * NOTE: from the examples given in the provided main we can infer that...
 *  a) ONLY the FIRST NUMBER FOUND is relevant, we can ditch others.
 *  b) We must "squash" the +- signs found "on the way" to get the final sign.
 *
 * What is the goal?
 * 1/ To parse the string UNTIL we find ONE NUMBER
 *   (meaning sequence of digits separated by non-digit characters)
 * 2/ To assign to it the sign resulting of all the "signs"
 *    read along on the way (with default being no sign so positive).
 */
int _atoi(char *s)
{
	/* Used to traverse the provided array */
	int cursor;
	/* Used to "aggregate" number of negative signs */
	int is_negative;
	/* Used to stop parsing once first number "entirely found" */
	int is_number_finished;
	/* First found number with its computed sign */
	int s_as_number;

	cursor = 0;
	is_negative = 0;
	is_number_finished = 0;
	s_as_number = 0;

	while (s[cursor] && is_number_finished == 0)
	{
		/* @note there is certainly a better/smarter way... */
		is_negative += (s[cursor] == '-') ? 1 : (s[cursor] == '+' ? -1 : 0);
		if (s[cursor] >= '0' && s[cursor] <= '9')
		{
			while (s[cursor] >= '0' && s[cursor] <= '9')
				/* @note "smarter way" using post-increment */
				/*  to read value *before* moving cursor"   */
				s_as_number = (s_as_number * 10) + (s[cursor++] - '0');
			if (is_negative > 0)
				s_as_number = -s_as_number;
			is_number_finished = 1;
		}
		cursor++;
	}

	return (s_as_number);
}
