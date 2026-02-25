#include "main.h"

/**
 * print_line - Print n times '_' character on a line.
 * @n: integer number.
 * Description: repeats printing '_' n times in a row.
 * Return: void
 */
void print_line(int n)
{
	while (n > 0)
	{
		_putchar('_');
		--n;
	}
	_putchar('\n');
}
