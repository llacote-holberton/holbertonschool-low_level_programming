#include "main.h"

/**
 * *_memset - mimics official memset function.
 * @s: pointer to array of characters we want to convert
 * @b: byte as character to overwrite with
 * @n: number of bytes (characters here) to overwrite.
 *
 * Description: "resets" part of a string
 *   by overwriting a portion with given character.
 * Return: address of modified string
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	/* This time we parse with "dynamic access by offset" */
	/*   to keep our pointer intact. */
	if (n > 0)
	{
		for (i = 0; i < n ; i++)
			s[i] = b;
	}

	return (s);
}
