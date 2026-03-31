#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * get_dnodeint_at_index - Grabs a given node amongst a list.
 * @head: provided pointer to the first element of double-linked list.
 * @index: position of element in the list (starting from 0).
 *
 * Return: the address of found element, or NULL if does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;
	dlistint_t *searcher = NULL;

	if (head == NULL)
		return (NULL);

	searcher = head;
	while (count <= index)
	{
		/* @warning: START WITH "RETURN" IF REACHED INDEX!! */
		if (count == index)
			break;
		/* Case: list broken before we reached required index */
		if (searcher->next == NULL && count < index)
		{
			/* NOTE: technically covers case "does not exist at index" ? */
			searcher = NULL;
			break;
		}
		count++;
		searcher = searcher->next;
	}
	return (searcher);
}

/*
 * === BRAINSTORMING / PROTOTYPES / SELF-TEACHING NOTES ===
 *
 * WORKING IN BEST CASE BUT FLAWED: goes "one beyond what's required".
 * while (count <= index)
 * {
 * Case: list broken before we reached required index
 * if (searcher->next == NULL && count < index)
 * return (NULL);
 * printf("Searcher address: previously %p. ", (void *) searcher);
 * searcher = searcher->next;
 * printf("Now: %p.\n", (void *) searcher);
 * count++;
 * }
 */
