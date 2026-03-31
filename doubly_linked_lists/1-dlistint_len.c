#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */

/**
 * dlistint_len - Returns n° of elements of provided double list.
 * @h: provided double-linked list.
 *
 * Return: number of elements of the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t list_size = 0;
	const dlistint_t *parser;

	/* Usual guard clause */
	if (h == NULL)
		return (list_size);

	parser = h;
	while (parser)
	{
		list_size++;
		parser = parser->next;
	}

	return (list_size);
}
