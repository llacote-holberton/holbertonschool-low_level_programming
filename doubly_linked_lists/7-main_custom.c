
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
 
/**
 * main - Extensive test for insert_dnodeint_at_index.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *node;

	/* --- Case 1: NULL pointer as head --- */
	printf("=== Case 1: NULL pointer as head ===\n");
	node = insert_dnodeint_at_index(NULL, 0, 42);
	printf("Result (expect NULL): %s\n", node == NULL ? "NULL" : "NOT NULL");
	printf("\n");

	/* --- Case 2: Empty list, idx == 0 --- */
	printf("=== Case 2: Empty list, idx == 0 ===\n");
	head = NULL;
	node = insert_dnodeint_at_index(&head, 0, 42);
	printf("Result (expect 42 as only node):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 3: Empty list, idx > 0 --- */
	printf("=== Case 3: Empty list, idx > 0 ===\n");
	head = NULL;
	node = insert_dnodeint_at_index(&head, 3, 42);
	printf("Result (expect NULL): %s\n", node == NULL ? "NULL" : "NOT NULL");
	printf("\n");

	/* --- Case 4: Single node list, insert at idx == 0 --- */
	printf("=== Case 4: Single node list, insert at idx == 0 ===\n");
	head = NULL;
	add_dnodeint_end(&head, 100);
	node = insert_dnodeint_at_index(&head, 0, 42);
	printf("Result (expect 42 then 100):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 5: Single node list, insert at idx == 1 (end) --- */
	printf("=== Case 5: Single node list, insert at idx == 1 ===\n");
	head = NULL;
	add_dnodeint_end(&head, 100);
	node = insert_dnodeint_at_index(&head, 1, 42);
	printf("Result (expect 100 then 42):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 6: Single node list, idx out of bounds --- */
	printf("=== Case 6: Single node list, idx out of bounds ===\n");
	head = NULL;
	add_dnodeint_end(&head, 100);
	node = insert_dnodeint_at_index(&head, 5, 42);
	printf("Result (expect NULL): %s\n", node == NULL ? "NULL" : "NOT NULL");
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 7: Normal list, insert in the middle --- */
	printf("=== Case 7: Normal list, insert in the middle (idx 3) ===\n");
	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	add_dnodeint_end(&head, 4);
	printf("Before:\n");
	print_dlistint(head);
	node = insert_dnodeint_at_index(&head, 3, 4096);
	printf("After (expect 4096 at idx 3):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 8: Normal list, insert at idx == 0 --- */
	printf("=== Case 8: Normal list, insert at idx == 0 ===\n");
	head = NULL;
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	add_dnodeint_end(&head, 3);
	printf("Before:\n");
	print_dlistint(head);
	node = insert_dnodeint_at_index(&head, 0, 4096);
	printf("After (expect 4096 at idx 0):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");

	/* --- Case 9: Normal list, insert at last valid idx (end) --- */
	printf("=== Case 9: Normal list, insert at end (idx == size) ===\n");
	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	printf("Before:\n");
	print_dlistint(head);
	node = insert_dnodeint_at_index(&head, 3, 4096);
	printf("After (expect 4096 at end):\n");
	print_dlistint(head);
	free_dlistint(head);
	head = NULL;
	printf("\n");
 
	/* --- Case 10: Normal list, idx out of bounds --- */
	printf("=== Case 10: Normal list, idx out of bounds ===\n");
	head = NULL;
	add_dnodeint_end(&head, 0);
	add_dnodeint_end(&head, 1);
	add_dnodeint_end(&head, 2);
	node = insert_dnodeint_at_index(&head, 10, 4096);
	printf("Result (expect NULL): %s\n", node == NULL ? "NULL" : "NOT NULL");
	free_dlistint(head);
	head = NULL;
	printf("\n");

	return (EXIT_SUCCESS);
}
