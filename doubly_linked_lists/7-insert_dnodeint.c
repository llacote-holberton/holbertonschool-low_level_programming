#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * insert_dnodeint_at_index - Inserts a new node at given index.
 * @h: provided pointer to the pointer to first element of double-linked list.
 * @idx: the index at which the new node must be inserted.
 * @n: number to affect as member of new node.
 *
 * Return: address of the new node of NULL if impossible to create.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *idx_searcher = NULL;
	unsigned int tmp_idx = 0;
	dlistint_t *tmp_previous = NULL;

	/* Pointer must targets a list pointer. */
	if (h == NULL)
		return (NULL);
	/* LIST must not be empty in the first place EXCEPT if target index is 0. */
	/* SO WE DELEGATE TO OUR custom "add in first place". */
	/* if (*h == NULL && idx > 0) */
	/*   return (NULL); */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Must be able to "reach" the desired index for insertion. */
	idx_searcher = *h;
	while (tmp_idx <= idx)
	{
		/* Let's be smart, easier (I think) to stop at n-1 */
		/* EXCEPT it wouldn't cover case "insert at index 0". */
		if (tmp_idx == idx)
		{
			/* 1. Create new node. */
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				break;
			new_node->n = n;
			/* 2. Gets the "previous" */
			tmp_previous = idx_searcher->prev;
			/* 3. Link both sides. */
			tmp_previous->next = new_node;
			new_node->prev = idx_searcher->prev;
			new_node->next = idx_searcher;
		}
		idx_searcher = idx_searcher->next;
		tmp_idx++;
	}
	return (new_node);
}

