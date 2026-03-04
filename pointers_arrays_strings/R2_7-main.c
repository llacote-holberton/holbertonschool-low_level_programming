#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\n";
	char *p;
	printf("Initial string hereafter.\n");
	printf("%s", s);
	p = leet(s);
	printf("Strings post-treatment hereafter.\n");
	printf("%s", p);
	printf("%s", s);
	return (0);
}
