#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	n = _strlen_recursion("Corbin Coleman");
	printf("%d\n", n);

	/* Custom tests */
	printf("\n'Empty' string should end with n = 0.\n");
	n = _strlen_recursion("");
	printf("%d\n", n);

	printf("\n'Four' should end with n = 4\n");
	n = _strlen_recursion("Four");
	printf("%d\n", n);

	return (0);
}
