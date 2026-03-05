#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello";
	char *f;
	char *not_here;

	f = _strchr(s, 'l');

	if (f != NULL)
	{
		printf("%s\n", f);
	}

	not_here = _strchr(s, 'z');
	if (not_here != NULL)
		printf("%s\n", not_here);
	else
		printf("Character z not found!\n");

	return (0);
}
