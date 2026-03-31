#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * add_dnodeint_end - Adds a new node as the new list's tail.
 * @head: provided pointer to head pointer of double-linked list.
 * @n: number to set as member n of the new node's structure.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *list_parser;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*head)
	{
		list_parser = *head;
		while (list_parser->next)
			list_parser = list_parser->next;

		new_node->prev = list_parser;
		/* *head-> DOESN'T WORK AS I WANT BECAUSE OPERATOR PRIORITY*/
		list_parser->next = new_node;
	}
	else
	*head = new_node;

	return (new_node);
}
