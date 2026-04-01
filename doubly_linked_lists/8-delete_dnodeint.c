#include <stddef.h> /* Required for size_t var type  */
#include "lists.h"  /* Required for custom structure */
#include <stdlib.h> /* Required for malloc function. */

/**
 * delete_dnodeint_at_index - Deletes node at given index.
 * @head: provided "double pointer" to first element of double-linked list.
 * @index: the index of the node to delete (count starting from 0).
 *
 * Return: 1 if node found and deleted successfully, -1 otherwise.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node_to_delete = NULL;
	unsigned int tmp_index = 0;
	int deletion_successful = -1;

	/* Pointer must targets a list pointer. */
	if (head == NULL || *head == NULL)
		return (deletion_successful);

	/* Must be able to "reach" the desired index for insertion. */
	node_to_delete = *head;
	while (tmp_index <= index)
	{
		/* Once we found we must FIRST "unlink" before deleting. */
		if (tmp_index == index)
		{
			/* 1. Use the chaining to avoid temporary placeholder. */
			if (node_to_delete->next != NULL)
				node_to_delete->next->prev = node_to_delete->prev;
			if (node_to_delete->prev != NULL)
				node_to_delete->prev->next = node_to_delete->next;
			else
				*head = node_to_delete->next;
			/* if (index == 0) USELESS better with else */

			/* 2. Delete the node */
			free(node_to_delete);
			deletion_successful = 1;
			/* 3. DO NOT forget to update head if deleted was first! */

			break;
		}
		if (node_to_delete->next == NULL)
			break;
		node_to_delete = node_to_delete->next;
		tmp_index++;
	}
	return (deletion_successful);
}

