#include <stdio.h>
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;
	/* @note Should be 8 */
	print_last_digit(98);
	/* @note Should be 0 */
	print_last_digit(0);
	/* @note Should be -4 */
	r = print_last_digit(-1024);
	/* @note Displays '44' ??? (48 + -4) */
	_putchar('0' + r);
	_putchar('\n');
	return (0);
}
