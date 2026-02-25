#include "main.h"
/* @note for this exercice standard library is allowed */
#include <stdio.h>

/* Additional constant because I feel it's cleaner */
static const int ceiling = 98;

/**
 * print_to_98 - lists natural numbers up to 98
 * @floor: integer
 * Description: sequences a numbering range
 *   between "floor" number (function parameter)
 *   and 98 (should be a constant?),
 *   separated by comma and space for readability.
 * Return: void
 */
void print_to_98(int floor)
{
	while (floor < ceiling)
	{
		printf("%d, ", floor);
		/*
		 * I feel not good practice to not use dedicated counter
		 *   but for this simple exercice deemed acceptable.
		 */
		floor++;
	}
	printf("%d\n", ceiling);
}

