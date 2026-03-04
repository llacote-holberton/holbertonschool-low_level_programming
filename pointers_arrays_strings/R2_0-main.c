#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;
	printf("Start of main c 1st display\n");
	printf("%s\n", s1);
	printf("%s", s2);
	printf("END of main c FIRST display\n");

	ptr = _strcat(s1, s2);
	printf("\nSTART of main c 2ND display\n");

	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);
	printf("\nEND of main c SECOND display\n");

	return (0);
}
