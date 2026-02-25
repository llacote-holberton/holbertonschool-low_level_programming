#include "main.h"

/**
 * print_diagonal - Print n times '\' character on a line.
 * @n: integer number.
 * Description: repeats printing '\' n times in a row
 *   with proper spacing to create a visual diagonal.
 * Return: void
 */
void print_diagonal(int n)
{

	if (n > 0)
	{
		int line;
		int spacing;

		/*
		 * Went for do while at first with inner for but ended up
		 *   with reverse diagonal... So back to basics which work.
		 */
		for (line = 1; line <= n; line++)
		{
			for (spacing = 0; spacing < (line - 1); spacing++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
