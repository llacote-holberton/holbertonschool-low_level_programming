#include "lists.h"
#include <stddef.h>    /* Required for var type 'size_t' */
#include <stdio.h>     /* Required for printf            */

/**
 * print_list - Exposes content of nodes from given list.
 * @h: pointer to a list of nodes of type list_t
 * Return: number of nodes as "special positive integer".
 *
 * Additional info
 *  - If str is NULL, print [0] (nil)
 *  - Exceptionally printf is allowed.
 *  - Expected format is as follows
 *    "
 */
size_t print_list(const list_t *h)
{
	int count = 0;
	/* @warning: const protects the CONTENT TARGETED */
	/*   NOT the pointer itself. So we can use const */
	/*   and still run across the list of nodes.     */
	const list_t *n = h;

	if (n == NULL)
		return (count);
	/* Each cycle pointer's target changes to next node. */
	while (n != NULL)
	{
		if (n->str)
			printf("[%u] %s\n", n->len, n->str);
		else
			printf("[0] (nil)\n");
		n = n->next;
		count++;
	}

	return (count);
}
