#include "main.h"

/**
 * _islower - checks if provided input is lowercase character.
 * @c: Character's ASCII value to be checked.
 * Description: tests if input matches a lowercase character,
 *   with binary return (1 = success).
 * Return: boolean.
 */
int _islower(int c)
{
	/* @note boundaries are inclusive ('a' and 'z')*/
	int lower_boundary;
	int upper_boundary;

	lower_boundary = 97;
	upper_boundary = lower_boundary + 26;
	return (lower_boundary <= c && c <= upper_boundary);
}
