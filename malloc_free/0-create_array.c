#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates a repetition of specific char.
 * @size: positive integer
 * @c: character to fill memory with.
 *
 * Description: creates a repetition of a specific character.
 * Return: pointer to array or NULL if either provided size is 0
 *   OR the memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	/* Loop iterator */
	unsigned int i = 0;
	/* Pointer to new array */
	char *sequence = (char *)malloc(size * (sizeof(char)));

	if (size == 0)
		return (NULL);

	if (sequence != NULL)
	{
		while (i < size)
		{
			sequence[i] = c;
			i++;
		}
	}
	return (sequence);
}
