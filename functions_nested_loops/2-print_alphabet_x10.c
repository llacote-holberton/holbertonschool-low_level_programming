#include "main.h"

/**
 * print_alphabet_x10 - prints a-z alphabet 10 times in a row.
 * Description: uses custom unit function to print
 *   a-z letters set in alphabetical order,
 *   on ten consecutive rows.
 * Return: void.
 */
void print_alphabet_x10(void)
{
	int number_of_lines;
	int current_line;
	int character_code;
	/* Using "letter-based" syntax for a change */
	number_of_lines = 10;
	current_line = 1;
	do {
		for (character_code = 'a'; character_code <= 'z'; character_code++)
			_putchar(character_code);
		_putchar('\n');
		current_line++;
	} while (current_line <= number_of_lines);

}
