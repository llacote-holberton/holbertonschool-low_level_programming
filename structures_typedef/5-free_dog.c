#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees the given dog.
 * @d: pointer to dog struct.
 *
 * Description: "frees" the given dog
 *   (honestly a better analogy would be that
 *    we euthanasiate it, but shhhhhh.)
 *
 * Return: nothing.
 *
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		/* Must first free all data from "inner pointers". */
		free(d->name);
		free(d->owner);
		/* Age is a float constant cannot be freed. */
		/* free(d->age); */

		/* We can finally free the struct itself. */
		free(d);
	}
}
