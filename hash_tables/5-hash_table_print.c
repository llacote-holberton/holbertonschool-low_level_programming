#include <stdlib.h>         /* Required for malloc and free */
#include <string.h>         /* Required for strdup */
#include "hash_tables.h"
#include <stdio.h>          /* Required for printf */

/**
 * hash_table_print - prints infos of hash_nodes in a table.
 * @ht: hash table to parse.
 *
 * Return: nothing.
 *
 * Additional informations
 * - Don't print anything if ht is NULL
 *   (meaning print newline if ht "just empty"?)
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int iterator = 0;
	hash_node_t *bucket = NULL;
	unsigned int first_item = 1;

	if (!ht)
		return;

	putchar('{');
	fflush(stdout);
	/* @warning be smart think that buckets may be empty even the first!!*/
	/* while (ht->array[iterator] && iterator < ht->size) */
	while (iterator < ht->size)
	{

		bucket = ht->array[iterator];
		/* Subloop in case we have a list */
		while (bucket)
		{
			printf("%s", (first_item) ? "" : ", ");
			first_item = 0;
			printf("'%s': '%s'", bucket->key, bucket->value);
			bucket = bucket->next;
		}
		iterator++;
	}
	printf("}\n");
}
