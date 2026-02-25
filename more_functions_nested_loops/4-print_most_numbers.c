#include "main.h"

/**
 * print_most_numbers - Prints digits except 2 and 4.
 * Description: prints characters from [0-9] set
 *   in ascending order as a single aggregate string
 *   EXCLUDING '2' and '4' (because why not ;)).
 * Return: boolean (1 = success)
 */
void print_most_numbers(void)
{
	/* Going for (I think) the most concise version allowed. */
	char digit;

	for (digit = '0'; digit <= '9'; digit++)
		if (digit != '2' && digit != '4')
			_putchar(digit);
	_putchar('\n');
}
