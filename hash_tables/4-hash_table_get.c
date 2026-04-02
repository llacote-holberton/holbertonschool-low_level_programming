#include <stdlib.h>         /* Required for malloc and free */
#include <string.h>         /* Required for strdup */
#include "hash_tables.h"

/**
 * hash_table_get - gets the value of element matching key in table.
 * @ht: hash table to add an element to.
 * @key: string used to generate hash value
 *
 * Return: value stored in "keyed element" or NULL if not found.
 *
 * Additional informations
 * - Key can not be an empty string
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int bucket_index;
	hash_node_t *bucket_node = NULL;

	/* @note: key == "" doesn't work because compares addresses */
	if (ht == NULL || key == NULL || key[0] == '\0')
		return (NULL);

	/* FIRST try and find existing node to update case arising. */
	bucket_index = hash_djb2((const unsigned char *)key) % ht->size;
	/* Comparing each node at a time while crossing list. */
	bucket_node = ht->array[bucket_index];
	while (bucket_node && strcmp(bucket_node->key, key))
		bucket_node = bucket_node->next;

	return ((bucket_node) ? bucket_node->value : NULL);
	/* If we reached this it means no matching node found in loop. */

}
