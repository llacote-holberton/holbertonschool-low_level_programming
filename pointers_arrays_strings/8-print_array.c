#include "main.h"
#include <stdio.h>
/**
 * print_array - neatly prints elements of an array of integers.
 * @a: pointer to array of integers from which we want to print elements.
 * @n: integer indicating the number of elements to print from the start.
 * Description: prints the requested number of elements
 *   grabbed from provided array of integers,
 *   in a human readable way.
 * Return: void.
 */
void print_array(int *a, int n)
{
	int cursor;

	/* Simple guard clause for useless calls. */
	if (n == 0) return;
	/* @note I make the (presomptuous?) assumption */
	/*   that a non-empty array is provided */

	cursor = 0;
	do {
		printf("%d", a[cursor]);
		++cursor;
		if (cursor < n)
			printf(", ");
	} while (cursor < n);
	printf("\n");
}

