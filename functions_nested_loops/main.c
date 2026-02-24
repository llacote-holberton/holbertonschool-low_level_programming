#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;
	/* @note Should be 1 (true), ASCII value 72. */
	r = _isalpha('H');
	_putchar(r + '0');
	/* @note Should be 1 (true), ASCII char 111. */
	r = _isalpha('o');
	_putchar(r + '0');
	/* @note Should be 1 (true), ASCII letter l. */
	r = _isalpha(108);
	_putchar(r + '0');
	/* @note Should be 0 (false), ASCII value 59. */
	r = _isalpha(';');
	_putchar(r + '0');
	_putchar('\n');
	return (0);
}
