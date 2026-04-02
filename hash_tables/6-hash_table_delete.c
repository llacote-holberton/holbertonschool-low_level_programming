#include <stdlib.h>         /* Required for malloc and free */
#include <string.h>         /* Required for strdup */
#include "hash_tables.h"
#include <stdio.h>          /* Required for printf */

/**
 * hash_table_delete - fully delete and frees hash table.
 * @ht: hash table to delete and free.
 *
 * Return: nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current = NULL;
	hash_node_t *previous = NULL;
	unsigned int i = 0;

	if (!ht)
		return;

	while (i < ht->size)
	{
		if (ht->array[i])
		{
			current = ht->array[i];
			while (current->next)
			{
				previous = current;
				current = current->next;
				/* @warning DO NOT FORGET TO FREE THE DUPLICATED STRINGS */
				free(previous->key);
				free(previous->value);
				free(previous);
			}
			free(current->key);
			free(current->value);
			free(current);
		}
		ht->array[i] = NULL;
		i++;
	}
	/* @warning DO NOT FORGET TO FREE THE ARRAY ITSELF*/
	free(ht->array);
	free(ht);
}
