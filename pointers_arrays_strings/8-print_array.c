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

	/*
	 * Better since shorter and easier to read
	 *   while maintaining the "guard clause"
	 *   (don't run if n equals 0).
	 */
	for (cursor = 0; cursor < n; cursor++)
	{
		printf("%d", a[cursor]);
		/* A bit more readable that way to keep         */
		/*  the loop increment "isolated" as last step. */
		/* But requires a slightly different condition than before. */
		if (cursor < n - 1)
			printf(", ");
	}
	printf("\n");
}

/*
 * VERSION 1: working but too convoluted.
 *
 * int cursor;
 *
 * if (n == 0) return;
 * cursor = 0;
 * do {
 *   printf("%d", a[cursor]);
 *   ++cursor;
 *   if (cursor < n)
 *     printf(", ");
 * } while (cursor < n);
 * printf("\n");
 */
