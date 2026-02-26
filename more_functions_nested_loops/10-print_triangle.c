#include "main.h"
#include <stdio.h>

/**
 * print_triangle - Prints a triangle of size side using '#'.
 * @size: integer number.
 * Description: prints a triangle made of #,
 *   with a side length equal to size given.
 * Return: void
 */
void print_triangle(int size)
{
	if (size > 0)
	{

		int line;
		int spacing;
		int pixels;
		/*
		 * Spacing + Pixels must equal size since
		 *   we print triangle "in a square".
		 * SO if we start printing spaces
		 *   AND increment instead of decrement
		 * We can directly deduce a "limit"
		 *   to use to print the '#'.
		 * For line 1 of 10 must have 1 ending #.
		 * For line 4 of 10 must have 4 ending #.
		 * So pixels = line "number".
		 * So spacing = size - line number;
		 */
		line = 1;
		do {
			for (spacing = 1 ; spacing <= size - line; spacing++)
				_putchar('.');
			for (pixels = 1; pixels <= line; pixels++)
				_putchar('#');
			_putchar('\n');
			line++;
		} while (line <= size);
	}
	else
		_putchar('\n');
}
