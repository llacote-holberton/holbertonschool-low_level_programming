#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a dog's information.
 * @d: struct pointer for that new dog's info file.
 *
 * Description: fills up info for a given dog.
 *
 * Return: void.
 *
 * Additional directives
 * If an element of d is NULL, print (nil) instead
 *   (ex if name is NULL, print Name: (nil)).
 * If d is NULL print nothing.
 *
 */
void print_dog(struct dog *d)
{
	char *undef_msg = "(nil)";
	/* Same as previous, should always check we do get */
	/*   an actual pointer to work with. */
	/* I think however checking pointers for inner members is not */
	/*   required in context since printf can work with NULL AFAIK. */
	if (d != NULL)
	{
		/* Using ternary conditions as imo more readable here than many IF. */
		/* Especially since we want to print something whatever happens.    */
		printf("Name: %s\n", (d->name == NULL) ? undef_msg : d->name);
		printf("Age: %.1f\n", d->age); /* Float cannot be NULL */
		printf("Owner: %s\n", (d->owner == NULL) ? undef_msg : d->owner);
	}
}
