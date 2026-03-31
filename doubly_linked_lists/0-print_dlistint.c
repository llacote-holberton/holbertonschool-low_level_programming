#include <stddef.h> /* Required for size_t var type  */
#include <stdio.h>  /* Required for printf function  */
#include "lists.h"  /* Required for custom structure */

/**
 * print_dlistint - Prints all elements of provided double list.
 * @h: provided double-linked list.
 *
 * Return: number of elements of the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t list_size = 0;
	const dlistint_t *parser;

	/* Usual guard clause */
	if (h == NULL)
		return (list_size);

	parser = h;
	while (parser)
	{
		printf("%d\n", parser->n);
		list_size++;
		parser = parser->next;
	}

	return (list_size);
}
