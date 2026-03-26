#include "lists.h"
#include <stddef.h>    /* Required for var type 'size_t' */
#include <stdlib.h>    /* Required for malloc            */
#include <string.h>    /* Required for strdup            */

/**
 * add_node_end - Adds a new "ending node" upon provided list.
 * @head: pointer to a list of nodes of type list_t
 * @str: string for the new node to add.
 * Return: address of the new node if successful, NULL otherwise.
 *
 * Additional info
 *  - Provided str needs to be duplicated.
 *  - Exceptionally strdup is allowed.
 *
 * NOTE IMPORTANT: function is similar in process to add_node
 *   as far as the "creation and affectation logic" goes.
 * What changes is the "existing node" used as reference
 *   AND how the "linking" between existing and new is made.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL;  /* Declaring future new node.            */
	char *str_copy;           /* Using intermediate var for str member */
	int   str_len;            /* Using to count str size   (no EOL).   */
	list_t *last_node = NULL; /* Using temp var to not mess with list start. */

	/* 0. Check we have a valid list given otherwise no point continuing.    */
	if (!head)
		return (NULL);

	/* 1. Start by finding the tail element of list, might as well do it now */
	/*     since we will use it during new_node creation. We can't use head  */
	/*     directly because it would potentially mess caller's process later.*/
	/* @warning: stop BEFORE last_node "follows" the last pointer to NULL    */
	/* for (last_node = *head; last_node; last_node = last_node->next)       */
	if (*head != NULL)
	{
		for (last_node = *head; last_node->next != NULL; last_node = last_node->next)
		;
	}

	/* 2. Create the new element and affect its members if successful.       */
	str_copy = (str) ? strdup(str) : NULL;
	if (!str_copy)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str_copy;
	for (str_len = 0; str_copy[str_len]; str_len++)
	;
	new_node->len = str_len;
	new_node->next = NULL; /* Added "at list end" so logic. */

	/* 3. Make the "link".         */
	if (last_node)    /* Otherwise given list is empty so new_node is 1st    */
		last_node->next = new_node;
	else /* @warning don't forget to cover the case "list initially empty". */
		*head = new_node;

	return (new_node);
}
