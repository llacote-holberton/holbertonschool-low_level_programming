#include <stdlib.h>
#include "dog.h"

/**
 * copy_string - prints a dog's information.
 * @source: string to copy.
 *
 * Description: copies a string.
 *
 * Return: string (copy of source).
 *
 */
static char *copy_string(char *source)
{
	char *copy;
	int length;
	int i;

	if (source == NULL)
		source = "";

	length = 1; /* To account for the EOL. */
	for (i = 0; source[i] != '\0'; i++)
		length++;
	copy = malloc(length * sizeof(char));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		copy[i] = source[i];

	return (copy);
}

/**
 * print_dog - prints a dog's information.
 * @name: string for dog name.
 * @age: float for its age.
 * @owner: string for his best Human friend.
 *
 * Description: fills up info for a given dog.
 *
 * Return: dog_t (dog struct).
 *
 */
dog_t *new_dog(char *name, float age, char *owner)
{

	/* @important MUST define a POINTER to struct     */
	/*   and therefore make its memory alloc manually */
	/*   in order for variable to survive and be able */
	/*   to be returned for it to be used elsewhere.  */
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name  = copy_string(name);
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	new_dog->owner = copy_string(owner);
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	new_dog->age = age;

	return (new_dog);
}

/* ===== DRAFT & SELF-TEACHING NOTES =====*/
/* Hereunder actually useless since I created a copy function. */
/* Generic iterator to copy the strings. */
/* int i;                                */
/* Temporary variables to copy provided infos. */
/* char *birthname;                            */
/* char *current_owner;                        */

/* IMPORTANT NOTE ABOUT "defining struct" vs "defining pointers". */
/* New dog to be "born". */
/* @WARNING! DOING THIS defines a LOCAL VARIABLE */
/* Consequences... */
/* 1/ Required space allocated automatically   */
/* 2/ Memory reserved in stack, not heap.      */
/* 3/ Lifespan ONLY DURING FUNCTION EXECUTION. */
/* dog_t new_dog; */

