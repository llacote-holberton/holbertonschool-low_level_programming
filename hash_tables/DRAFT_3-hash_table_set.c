#include <stdlib.h>         /* Required for malloc and free */
#include <string.h>         /* Required for strdup */
#include "hash_tables.h"

#include <stdio.h>   /*@temporary */

/**
 * find_bucket_tail - Finds the first empty slot in a bucket.
 * @bucket_list: head of a list of nodes stored inside a given bucket.
 *
 * Return: pointer to the last existing node in that bucket.
 */
hash_node_t *find_bucket_tail(hash_node_t *bucket_list)
{
	hash_node_t *tail = NULL;

	if (bucket_list != NULL)
	{
		while (bucket_list->next)
			bucket_list = bucket_list->next;
		tail = bucket_list;
	}
	return (tail);
}

/**
 * create_hash_node - Creates a new node to insert.
 * @key: string used to generate hash value
 * @value: string to affect as node member.
 *
 * Return: pointer to the newly created node or NULL if failure.
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	char *copy_of_value;
	char *copy_of_key;

	/* @note: key == "" doesn't work because compares addresses */
	if (key == NULL || key[0] == '\0' || value == NULL)
		return (NULL);

	/* First ensure we have enough memory for everything. */
	copy_of_key = strdup(key);
	if (!copy_of_key)
		return (NULL);

	copy_of_value = strdup(value);
	if (!copy_of_value)
	{
		free(copy_of_key);
		return (NULL);
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(copy_of_key);
		free(copy_of_value);
		return (NULL);
	}

	new_node->next  = NULL;
	new_node->key   = copy_of_key;
	new_node->value = copy_of_value;

	return (new_node);
}

/**
 * hash_table_set - adds an element inside hash table.
 * @ht: hash table to add an element to.
 * @key: string used to generate hash value
 * @value: string to affect as node member.
 *
 * Return: boolean like (1 = success, 0 = failure).
 *
 * Additional informations
 * - Key can not be an empty string
 * - Value must be duplicated. value can be an empty string
 * - If collision, addition is "head first" (beginning of the list).
 *   "Collision samples" hereunder
 *   hetairas|mentioner, heliotropes|neurospora,depravement|serafins,
 *   stylist|subgenera, joyful|synaphea, redescribed|urites, dram|vivency
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned int successful_insertion = 0;
	hash_node_t *new_node = NULL;
	char *copy_of_value;
	char *copy_of_key;
	unsigned int bucket_index;
	hash_node_t *bucket_tail = NULL;

	/* @note: key == "" doesn't work because compares addresses */
	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (successful_insertion);

	/* First ensure we have enough memory for everything. */
	copy_of_value = strdup(value);
	if (!copy_of_value)
		return (successful_insertion);
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(copy_of_value);
		return (successful_insertion);
	}
	printf("In SET: address of new_node is %p.\n", (void *)new_node);
	new_node->key = key;
	new_node->value = copy;
	new_node->next = NULL /* @warning DON'T FORGET to avoid dangling pointer. */
	/* Now try to insert. */
	bucket_index = hash_djb2(key) % ht->size;
	bucket_tail = find_bucket_tail(ht[bucket_index]);
	if (bucket_tail)
		bucket_tail->next = new_node;
	else
		ht[bucket_index] = new_node;
	successful_insertion = 1;

	return (successful_insertion);
}
