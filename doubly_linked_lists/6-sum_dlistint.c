#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * sum_dlistint - Aggregates numbers of every item in a list.
 * @head: provided pointer to the first element of double-linked list.
 *
 * Return: aggregated sum of all numbers held in list items,
 *   or 0 if list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *aggregator = NULL;

	if (head != NULL)
	{
		aggregator = head;
		while (aggregator)
		{
			total += aggregator->n;
			aggregator = aggregator->next;
		}
	}

	return (total);
}

/*
 * === BRAINSTORMING PROTOTYPES AND SELF-TEACHING ===
 *
 * VERSION WORKS BUT A BIT VERBOSE AND MULTIPLE EXIT POINTS.
 * if (head == NULL)
 * return (total)*;
 * aggregator = head;
 * while (aggregator)
 * {
 * total += aggregator->n;
 * aggregator = aggregator->next;
 * }
 * return (total);
 */
