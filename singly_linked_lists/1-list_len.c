#include "lists.h"
#include <stddef.h>    /* Required for var type 'size_t' */
#include <stdio.h>     /* Required for printf            */

/**
 * list_len - Returns the number of elements of provided list.
 * @h: pointer to a list of nodes of type list_t
 * Return: number of nodes as "special positive integer".
 */
size_t list_len(const list_t *h)
{
	int count = 0;
	const list_t *n = h;

	if (n == NULL)
		return (count);
	/* Each cycle pointer's target changes to next node. */
	while (n)
	{
		count++;
		/* Not sure if breaking in case chain is "broken " is the */
		/*   right way to handle it, but seems logical for me.    */
		if (!(n->next))
			break;
		n = n->next;
	}
	return (count);
}
