#include "main.h"
#include <stdio.h>
/**
 * *_strcpy - fully copies provided string to buffer.
 * @dest: pointer to array of characters we want to overwrite.
 * @src: pointer to array of characters we want to copy.
 * Description: prints the requested number of elements
 *   grabbed from provided array of integers,
 *   in a human readable way.
 * Return: pointer to destination array.
 */
char *_strcpy(char *dest, char *src)
{
	int cursor;

	/* Can it be as simple as just */
	/*   reaffecting the target address of dest */
	/*   to point on the same one as src? */
	/* NO as exercise requires explicitely to COPY. */
	cursor = 0;

	/*
	 * printf("Pointer of dest is currently %p\n", dest);
	 * printf("Content of dest is currently %s\n", dest);
	 * printf("Pointer of src  is currently %p\n", src);
	 */
	while (src[cursor])
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	dest[cursor + 1] = '\0';
	/* printf("Content of dest is now %s\n", dest); */

	return (dest);
}
