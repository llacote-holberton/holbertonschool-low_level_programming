#include "main.h"

/**
 * main - Prints alphabet without using standard library.
 * Description: prints alphabet using nested custom functions.
 *   in the list of files to aggregate when running compilation.
 * Return: Always 0.
 */
int main(void)
{
	print_alphabet();
	return (0);
}

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
