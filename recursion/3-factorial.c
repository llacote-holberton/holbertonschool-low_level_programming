#include "main.h"

/**
 * factorial - recursively counts string length
 * @n: number of which we want the factorial number.
 *
 * Return: integer (factorial result).
 *
 * Additional information
 * - If n < 0, function should return -1 for error.
 * - Factorial of 0 is 1.
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	/* Following the same logic as before in naive version. */
	return (n * factorial(n - 1));
}
