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
		/*
		 * for (line = 1; line <= size; line++)
		 * {
		 * for (spacing = size; spacing < (line - 1); spacing--)
		 * _putchar(' ');
		 * for (spacing = 0; spacing < line; spacing++)
		 * _putchar('#');
		 * _putchar('\n');
		 * }
		 */
		/* This seems the case where a decrement is useful*/
		int line;
		int spacing;
		int pixels;
		/*
		 * Went for do while at first with inner for but ended up
		 *   with reverse diagonal... So back to basics which work.
		 */
		line = size;
		do {
			spacing = line - 1;
			/* Needs to compensate the previous "offset". */
			pixels = size - line + 1;

			for (; spacing > 0; spacing--)
				_putchar(' ');
			for (; pixels > 0; pixels--)
				_putchar('#');
			_putchar('\n');
			--line;
		} while (line > 0);
	}
	else
		_putchar('\n');
}
