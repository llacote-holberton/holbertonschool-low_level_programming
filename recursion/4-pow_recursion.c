#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y.
 * @x: integer - base
 * @y: integer - power.
 *
 * Return: integer (factorial result).
 *
 * Additional information
 * - If y is lower than 0, the function should return -1.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	/* Following the same logic as before in naive version. */
	return (x * _pow_recursion(x, y - 1));
}
