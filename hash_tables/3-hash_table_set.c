#include <stdlib.h>         /* Required for malloc and free */
#include <string.h>         /* Required for strdup */
#include "hash_tables.h"

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
 * find_matching - Returns existing node with matching key or NULL.
 * @bucket_list: head of a list of nodes stored inside a given bucket.
 * @key: business identifier of the content.
 *
 * Return: pointer to a node with matching key if it exists, or NULL.
 */
hash_node_t *find_matching(hash_node_t *bucket_list, const char *key)
{
	hash_node_t *current = bucket_list;

	/* Guard clause for no node or unexploitable key. */
	if (!current || !key || key[0] == '\0')
		return (NULL);

	/* Comparing each node at a time while crossing list. */
	while (current)
	{
		/* "Breaks and return" as soon as found match. */
		if (strcmp(current->key, key) == 0)
			return (current);
		/* Or go to the next item in list and loop over. */
		current = current->next;
	}

	/* If we reached this it means no matching node found in loop. */
	return (NULL);
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
	char *copy_of_value = NULL;
	char *copy_of_key = NULL;

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
	const unsigned int success = 1;
	const unsigned int failure = 0;

	hash_node_t *new_node = NULL;
	unsigned int bucket_index;
	hash_node_t *existing_node = NULL;
	char *new_value = NULL;

	/* @note: key == "" doesn't work because compares addresses */
	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (failure);

	/* FIRST try and find existing node to update case arising. */
	bucket_index = hash_djb2((const unsigned char *)key) % ht->size;
	existing_node = find_matching(ht->array[bucket_index], key);
	if (existing_node)
	{
		/* @warning direct affectation of copy creates leak for preexisting value */
		new_value = strdup(existing_node->value);
		if (new_value)
		{
			free(existing_node->value);
			existing_node->value = new_value;
			return (success);
		}
		else
			return (failure);
	}
	else
	{
		/* Ensure enough memory to create+affect before inserting at bucket start. */
		new_node = create_hash_node(key, value);
		if (!new_node)
			return (failure);

		new_node->next = ht->array[bucket_index];
		ht->array[bucket_index] = new_node;
		return (success);
	}
}
