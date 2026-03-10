#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory.
 * @b: positive integer indicating size of memory requested.
 *
 * Description: Allocates memory of given size with malloc.
 * Return: void pointer to allocated memory.
 *
 */
void *malloc_checked(unsigned int b)
{
	int *reserved_memory;

	/* Not sure if force typecast still required. */
	reserved_memory = (int *)malloc(b);
	if (reserved_memory == NULL)
		exit(98);

	return (reserved_memory);
}
