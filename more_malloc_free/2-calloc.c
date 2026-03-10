#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array.
 * @nmemb: positive integer, number of elements.
 * @size: positive integer, size of each element.
 * Description: creates an array with parameterized
 *   elements of set size.
 *
 * Return: void pointer to initialized array.
 *
 * Additional information
 * - The memory is set to zero.
 * - If nmemb or size is 0, then _calloc returns NULL.
 * - If malloc fails, then _calloc returns NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *initialized;
	/* Using a void pointer is impossible so to fill in with 0 */
	/*  the only way is to use a dedicated "filler pointer".   */
	/* And SINCE we want to fill in all bytes with 0 the best  */
	/*   (only?) way is to use a "char pointer" since it makes */
	/*   us fill byte by byte (1 char = 1 byte).               */
	char *filler;
	/* Instead of a classic for we go for a variant here */
	/* Using a dedicated variable for "total allocation size". */
	/* As we need to know it anyways later to "fill it with 0" */
	size_t total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;
	initialized = malloc(total_size);
	if (initialized == NULL)
		return (NULL);

	/* Using a variant which should work     */
	/*   with an intuitive ending condition. */
	/* Compact writing but makes brain knots */
	/* while (total_size--) */
	filler = initialized;
	while (total_size > 0)
	{
		/* Filling current address then pushing forward. */
		*filler = 0;
		filler++;
		/* Decrementing total_size directly... */
		/* a) To avoid needing a distinct "temp" variable.         */
		/* b) Because we can alter it, served its initial purpose. */
		total_size--;
	}

	return (initialized);
}
