#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - pops a new dog.
 * @d: struct pointer for that new dog's info file.
 * @name: string for dog name.
 * @age: float for its age.
 * @owner: string for his best Human friend.
 *
 * Description: fills up info for a given dog.
 *
 * Return: void.
 *
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	/* Mixing up the two ways of accessing a struct member  */
	/*   on purpose to show both work and their own syntax. */

	/* Using the "raw" syntax we must use parenthesis to force */
	/* the dereference symbol to apply ONLY to the pointer itself.  */
	/* Otherwise with the priority order, the "member access" is    */
	/*   "applied first" in the evaluation thus program understands */
	/*   it should try to dereference "dog.name" which doesn't work.*/
	(*d).name = name;
	/* That is why C provides a shorter and simpler, dedicated syntax. */
	/* Which therefore ONLY works "from pointers". */
	d->age = age;
	d->owner = owner;
}
