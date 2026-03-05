#include "main.h"

/**
 * *_memcpy - copies "byte from byte".
 * @dest: pointer to array of characters we want to convert
 * @src: pointer to array of characters to overwrite with
 * @n: number of bytes (characters here) to overwrite.
 *
 * Description: overwrites part of string "as bytes"
 *   because modifies pointed address byte per byte.
 * Return: address of modified string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	/* This time we parse with "dynamic access by offset" */
	/*   to keep our pointer intact. */
	if (n > 0)
	{
		for (i = 0; i < n ; i++)
			dest[i] = src[i];
	}

	return (dest);
}
