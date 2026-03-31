#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *node;

	head = NULL;
	printf("=== Start of exo 05 ===\n");
	printf("= Creating list. =\n");
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	add_dnodeint_end(&head, 98);
	add_dnodeint_end(&head, 402);
	add_dnodeint_end(&head, 1024);
	printf("= Printing list. =\n");
	print_dlistint(head);
	printf("= Trying to grab item of index 5. =\n");
	node = get_dnodeint_at_index(head, 5);
	printf("%d\n", node->n);
	printf("= Freeing memory. =\n");
	free_dlistint(head);
	head = NULL;
	printf("=== END ===\n");
	return (EXIT_SUCCESS);
}
