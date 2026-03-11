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
 */
void print_dog(struct dog *d)
{
	printf("Name: %s\nAge: %.1f\nOwner: %s\n", d->name, d->age, d->owner);
}
