#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * generate_list - Generates a doubly linked list and prints it.
 * @head: pointer to the pointer to the first element of the list.
 */
void generate_list(dlistint_t **head)
{
	add_dnodeint_end(head, 0);
	add_dnodeint_end(head, 1);
	add_dnodeint_end(head, 2);
	add_dnodeint_end(head, 3);
	add_dnodeint_end(head, 4);
	add_dnodeint_end(head, 98);
	add_dnodeint_end(head, 402);
	add_dnodeint_end(head, 1024);
}

/**
 * delete_n_times - Deletes node at index 0 n times.
 * @head: pointer to the pointer to the first element of the list.
 * @n: number of times to delete.
 */
void delete_n_times(dlistint_t **head, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		delete_dnodeint_at_index(head, 0);
		printf("-----------------\n");
		if (*head != NULL)
			print_dlistint(*head);
	}
}

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;

	head = NULL;
	printf("Initial list.\n");
	generate_list(&head);
	print_dlistint(head);
	printf("-----------------\n");
	delete_dnodeint_at_index(&head, 5);
	print_dlistint(head);
	printf("-----------------\n");
	delete_n_times(&head, 18);
	return (EXIT_SUCCESS);
}
