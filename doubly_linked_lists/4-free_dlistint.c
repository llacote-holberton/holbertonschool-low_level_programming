#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * free_dlistint - Frees all members of a given list.
 * @head: provided pointer to the first element of double-linked list.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = NULL; /* Used to free without losing link. */

	if (head == NULL)
		return;

	/* Rewind if need be to the actual start of list. */
	/* Stupid me, obviously infinite loop... -_- */
	/* while (head)       */
	/*	if (head->prev)   */
	while (head && head->prev)
		head = head->prev;

	/* Then start freeing one by one */
	while (head)
	{
		current = head;
		/* Case current head isn't "first element" */
		/* USELESS: freed automatically as part of struct's memory area. */
		/* if (head->prev != NULL) head->prev = NULL; */
		/* Case current head isn't last element */
		/* WRONG: must advance in ALL cases otherwise double free. */
		/* if (head->next != NULL) head = head->next */

		head = head->next;
		free(current);
	}
}
