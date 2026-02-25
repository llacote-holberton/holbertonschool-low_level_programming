#include "main.h"

/**
 * print_numbers - Prints the characters from digits set.
 * Description: prints characters from [0-9] set
 *   in ascending order as a single aggregate string.
 * Return: boolean (1 = success)
 */
void print_numbers(void)
{
	/* Going for (I think) the most concise version allowed. */
	char digit;

	for (digit = '0'; digit <= '9'; digit++)
		_putchar(digit);
	_putchar('\n');
}
