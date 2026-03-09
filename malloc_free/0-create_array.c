#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates a repetition of specific char.
 * @size: positive integer
 * @c: character to fill memory with.
 *
 * Description: Takes an array of numbers with its length
 *   and uses it to reverse.
 * Return: pointer to array or NULL if fails.
 */
char *create_array(unsigned int size, char c)
{
	/* Loop iterator */
	unsigned int i = 0;
	/* Pointer to new array */
	char *sequence = (char *)malloc(size * (sizeof(char)));

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
