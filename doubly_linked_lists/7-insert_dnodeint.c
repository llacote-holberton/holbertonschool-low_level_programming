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

	/* 0. New architecture: we "push near index" first. Then assess situation. */
	idx_searcher = *h;
	while (tmp_idx < idx - 1 && idx_searcher)
	{
		idx_searcher = idx_searcher->next; /* Should "stop at index -1". */
		tmp_idx++; /* Will end "== idx -1" if no "reaching list end early"... */
	}

	/* Loop end before tmp_idx "reached" goal == index is beyond list. */
	if (tmp_idx != idx - 1)
		return (NULL);
	/* 1. Create new node and affect internal data if goes well. */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	/* 2. Rework the "links" with chaining directly */
	/* AND because we stopped at "i -1" it is easier. */
	new_node->next = idx_searcher->next;
	new_node->prev = idx_searcher;
	/* @warning because change of logic must check not null! */
	if (idx_searcher->next) /* Meaning idx_searcher was not last of list. */
		idx_searcher->next->prev = new_node;
	idx_searcher->next = new_node;
		/* @note order must be exactly this to not lose infos. */

	return (new_node);
}

