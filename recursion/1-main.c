#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	_print_rev_recursion("\nColton Walker");

	/* Custom tests */
	printf("\n\nCustom tests \n\n");

	printf("\n1. Alphabet start in order by providing inverse\n> ");
	_print_rev_recursion("hgfedcba");

	printf("\n2. Hello\n> ");
	_print_rev_recursion("Hello");

	printf("\n3. Empty string\n> ");
	_print_rev_recursion("");

	printf("\n4. Complex string\n> ");
	_print_rev_recursion("\nWhen logic is good, output is too ;)");

	return (0);
}
