#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	print_all("ceis", 'B', 3, "stSchool");

	/* Custom tests */
	printf("\nTest NULL format\n");
	print_all(NULL, "Null format should print only a newline");

	printf("\nTest non-NULL but empty format\n");
	print_all("", "Empty format should print only a newline");

	printf("\nTest no valid format\n");
	print_all("xyz", "Ryo Saeba", "City Hunter");

	printf("\nTest long mixed sequence\n");
	print_all("ssisf", "Devil's number", "is supposedly", 666, "and his riches are", 56.764);

	printf("\nTest wrong association, inverted ones\n");
	print_all("is", "Lucky number", 777);

	return (0);
}
