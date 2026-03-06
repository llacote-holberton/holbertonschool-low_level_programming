#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = "hello, world";
	char *f = "world";
	char *t;
	char *accept = "xyz";
	char *absent;

	/* Expected "world". */
	t = _strstr(s, f);
	printf("%s\n", t);
	/* Expected NULL */
	absent = _strstr(s, accept);
	printf("%s\n", absent ? absent : "NULL");

	return (0);
}
