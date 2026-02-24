#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	/* @note Should be 0 (false), ASCII value 72. */
	r = _islower('H');
	_putchar(r + '0');
	/* @note Should be 1 (true), ASCII value 111. */
	r = _islower('o');
	_putchar(r + '0');
	/* @note Should be 1 (true), ASCII char l. */
	r = _islower(108);
	_putchar(r + '0');
	_putchar('\n');
	return (0);
}
