#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	print_numbers(", ", 4, 0, 98, -1024, 402);
	/* Custom tests WILL IGNORE THE NUMBERS PAST 0 */
	print_numbers("", 1, 0, -666, -1024, 402);
	/* With decent number */
	print_numbers("", 4, 3, -666, -1024, 402);
	/* With actual NULL */
	print_numbers(NULL, 4, 3, -666, 1024, 402);
	return (0);
}
