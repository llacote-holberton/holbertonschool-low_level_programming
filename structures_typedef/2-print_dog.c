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
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
