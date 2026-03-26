#include "lists.h"
#include <stddef.h>    /* Required for var type 'size_t' */
#include <stdlib.h>    /* Required for malloc            */
#include <string.h>    /* Required for strdup            */
/* #include <stdio.h>                                    */

/**
 * free_list - Frees the nodes of provided list.
 * @head: pointer to a list of nodes of type list_t
 * Return: nothing.
 *
 */
void free_list(list_t *head)
{
	/* Logically since this kind of list is "forward" */
	/*   we should be able to make some kind of loop. */
	/* We just need a "temporary pointer" I suspect.  */
	list_t *current;

	/* Causes memory leak because my logic is flawed I don't actually */
	/* Enter the "last item" because the next is NULL. Obviously. :/  */
	/* while (head && head->next) */
	while (head != NULL) /* Might as well go for explicit writing now */
	{
		/* KEPT Because printing pointers in this context is hell. Need example. */
		/* printf("\n\nHEAD pointer is currently %p.\n", (void *)&head);         */
		/* printf("\n\nNEXT pointer is currently %p.\n", (void *)&(head->next)); */
		current = head;      /* Affecting "current" for cleanup. */
		head = head->next;   /* Moving "head" makes "current" exclusive owner.     */
		/* @warning DO NOT DO THIS as free always empties "what pointer targets"   */
		/*   NOT pointer's memory itself. So this makes head a dangling pointer.   */
		/* free(current->next); */
		free(current->str);
		free(current);
	}
}
