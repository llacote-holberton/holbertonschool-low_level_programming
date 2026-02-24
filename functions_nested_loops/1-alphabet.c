#include "main.h"

/**
 * print_alphabet - prints a-z letters in order.
 * Description: uses custom unit function to print
 *   a-z letters set in alphabetical order, followed
 *   by a new line.
 * Return: void.
 */
void print_alphabet(void)
{
	int character_code;
	/* Using "letter-based" syntax for a change */
	for (character_code = 'a'; character_code <= 'z'; character_code++)
		_putchar(character_code);
	_putchar('\n');
}
