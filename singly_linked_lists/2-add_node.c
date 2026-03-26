#include "lists.h"
#include <stddef.h>    /* Required for var type 'size_t' */
#include <stdlib.h>    /* Required for malloc            */
#include <string.h>    /* Required for strdup            */

/**
 * add_node - Adds a new "starting node" upon provided list.
 * @head: pointer to a list of nodes of type list_t
 * @str: string for the new node to add.
 * Return: address of the new element or NULL if failure somewhere.
 *
 * Additional info
 *  - Provided str needs to be duplicated.
 *  - Exceptionally strdup is allowed.
 *
 * NOTE IMPORTANT: parameter head is a double pointer because,
 *   if we made it a "simple pointer to the list's head",
 *   it would be given as a str_copy. So even if we changed
 *   what it points to, it wouldn't affect the "original pointer".
 * However, making it **head means we give the ADDRESS at which the
 *   head pointer is stored, meaning the function access the "original pointer"
 *     directly in its body so it can change what it points to.
 */
list_t *add_node(list_t **head, const char *str)
{
	/* @warning REMEMBER a POINTER to object is needed not object itself! */
	list_t *new_node;    /* Declaring future new node.            */
	char *str_copy;     /* Using intermediate var for str member */
	int   str_len;      /* Using to count str size   (no EOL).   */

	/* To add an element at the start basically process is... */
	/* 0. Check we have a valid list given otherwise no point continuing.    */
	if (!head)
		return (NULL);

	/* 1. Create the new element and affect its members if successful.       */
	/* First manage the string duplicate, no point continuing if this fails. */
	str_copy = (str) ? strdup(str) : NULL;
	if (!str_copy)
		return (NULL);
	/* Then create the node and affect its members. */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = str_copy;
	for (str_len = 0; str_copy[str_len]; str_len++)
	;
	new_node->len = str_len;
	/* 2. Make its "next member" point on what is the current start.         */
	/*    Meaning "point on address head is currently pointing to".          */
	/* @warning "head" is pointer to pointer, we need the address pointed to */
	/*   so we need to dereference head. */
	new_node->next = *head;
	/* 3. Update the "head pointer" to point on "the new first element".     */
	/*    Note same as above: not head but *head. */
	*head = new_node;

	/* Same here, we need to return an address to a list start so *head for  */
	/*   address of the pointer head points to. */
	return (new_node);
}
