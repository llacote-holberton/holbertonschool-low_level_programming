#include "main.h"

/**
 * print_square - Prints a square of size side using '#'.
 * @size: integer number.
 * Description: prints a square made of #,
 *   with a side length equal to size given.
 * Return: void
 */
void print_square(int size)
{

	if (size > 0)
	{
		int width;
		int height;

		for (height = 1; height <= size; height++)
		{
			for (width = 1; width <= size; width++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
