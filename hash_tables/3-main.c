#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;
	printf("=== START of Exo 03 ===\n");

	printf("= Creating hash_table =\n");
	ht = hash_table_create(1024);

	printf("= Trying to set a new node inside.\n");
	hash_table_set(ht, "betty", "cool");

	printf("= Trying to set two nodes with colliding hash inside.\n");
	hash_table_set(ht, "hetairas",  "First inside");
	hash_table_set(ht, "mentioner", "Second coming");

	printf("=== END of Exo 03 ===\n");
	
	return (EXIT_SUCCESS);
}
