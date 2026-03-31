#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */
#include <stdio.h>

/**
 * add_dnodeint - Adds a new node as the new list's head.
 * @head: provided pointer to head pointer of double-linked list.
 * @n: number to set as member n of the new node's structure.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	if (*head)
	{
		new_node->next = *head;
		/* *head-> DOESN'T WORK AS I WANT BECAUSE OPERATOR PRIORITY*/
		(*head)->prev = new_node;
	}
	/* else NO NEED SINCE IN BOTH CASES WE NEED TO UPDATE HEAD POINTER. */
		/* @warning DOES NOT WORK BECAUSE I affect "local copy". */
		/* head = &new_node; */
		/* To mofify caller copy I need to dereference "first dimension" */
		/*   THEN for the actual "header pointer" affect it the address  */
		/*   of the new structure I created (so give it whatever my )    */
		/*   struct pointer new_node points to. */
	*head = new_node;

	return (new_node);
}
