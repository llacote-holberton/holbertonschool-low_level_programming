#include "main.h"
/* @note for this exercice standard library is allowed */
#include <stdio.h>

/* Additional constant because I feel it's cleaner */
static const int end = 98;

/**
 * print_to_98 - lists natural numbers until reaching 98
 * @start: integer
 * Description: sequences a numbering range
 *   between "start" number (function parameter)
 *   and 98 (should be a constant?),
 *   separated by comma and space for readability.
 * Return: void
 */
void print_to_98(int start)
{
	while (start != end)
	{
		printf("%d, ", start);
		/*
		 * I feel not good practice to not use dedicated counter
		 *   but for this simple exercice deemed acceptable.
		 */
		/*
		 * DOES NOT WORK because "operation on start can be undefined"
		 * -> I in|decrement AFTER re-affecting so I end up not changing.
		 * start = (start > end) ? start-- : start++;
		 * Even that is not "guaranteed to work" because technically
		 *   this makes two affectations in a row on the same variable.
		 * start = (start > end) ? --start : ++start;
		 * At least in C versions anterior to C17, the ops order is not strict.
		 */
		start += (start > end) ? -1 : +1;
		/*
		 * ONLY the version above is reliable because
		 * a) start is only (re)affected once
		 * b) the condition is evaluated separately
		 * So no risk or evaluation order ambiguity.
		 */
	}
	printf("%d\n", end);
}

