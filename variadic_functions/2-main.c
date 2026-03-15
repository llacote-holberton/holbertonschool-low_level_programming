#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("\n== Regular use. ==\n");
	print_strings(", ", 2, "Jay", "Django");

	/* Custom tests */

	/* NULL separator */
	printf("\n==Variant: NULL separator. ==\n");
	print_strings(NULL, 2, "Jay", "Django");

	/* NULL string */
	printf("\n==Variant: big separator and NULL for first component. ==\n");
	print_strings(" -separator- ", 2, NULL, "First string NULL");

	/* Empty separator */
	printf("\n==Variant: Empty separator. ==\n");
	print_strings("", 2, "Empty", "Separator");

	/* Long sequence*/
	printf("\n==Regular use, extended. ==\n");
	print_strings(" | ", 7, "Jay", "Django", "Reinhardt",
								"Jazz", "is", "Good", "Music");

	return (0);
}
