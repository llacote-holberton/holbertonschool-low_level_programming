#include <stdio.h>
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	/* @note Should be 1 */
	r = _abs(-1);
	printf("%d\n", r);
	/* @note Should be 0 */
	r = _abs(0);
	printf("%d\n", r);
	/* @note Should be 1 */
	r = _abs(1);
	printf("%d\n", r);
	/* @note Should be 98 */
	r = _abs(-98);
	printf("%d\n", r);
	return (0);
}
