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

	/* Pointer must targets a list pointer. */
	if (h == NULL)
		return (NULL);
	/* LIST must not be empty in the first place EXCEPT if target index is 0. */
	/* Our custom add function does the required checks for it. */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Must be able to "reach" the desired index for insertion. */
	idx_searcher = *h;
	while (tmp_idx <= idx && idx_searcher)
	{
		/* 0. Push through while we didn't reach index (if exists). */
		if (tmp_idx != idx)
		{
			idx_searcher = idx_searcher->next;
			tmp_idx++;
			continue;
		}
		/* 1. Create new node. */
		new_node = malloc(sizeof(dlistint_t));
		if (new_node == NULL)
			break;
		/* 2. Affects "internal data". */
		new_node->n = n;
		/* 3. Rework the "links" with chaining directly */
		new_node->next = idx_searcher;
		new_node->prev = idx_searcher->prev;
		idx_searcher->prev->next = new_node;
		idx_searcher->prev = new_node;
		/* @note order must be exactly this to not lose infos. */
		break;
	}
	return (new_node);
}

