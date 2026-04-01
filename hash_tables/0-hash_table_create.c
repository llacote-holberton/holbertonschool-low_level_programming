#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Initializes a hash table.
 * @size: size of the hash table array.
 *
 * Return: pointer to newly created hash table if successful,
 *         NULL otherwise.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	/* We want a table of pointers. */
	/* We know that pointers must be explicitely set to NULL */
	/*   when "not used" (yet) to avoid "dangling pointers". */
	/* So instead of using malloc then a loop to "fill in"   */
	/*   we directly use calloc which autofills with 0...    */
	/* Which in C for a pointer, is evaluated to NULL.       */
	hash_table_t *new_ht = NULL;

	if (size == 0)
		return (NULL);
	/* @warning plug the brain and read struct file properly... */
	/* new_ht = calloc(size, sizeof(hash_table_t)); */
	/* Logically no need to make "if" since we return just after. */
	/* If alloc failed then new_ht will be NULL all the same. */
	new_ht = malloc(sizeof(hash_table_t));
	if (!new_ht)
		return (NULL);
	/* Affect raw data now while we sure it exists */
	new_ht->size = size;
	/* @warning table of POINTERS don't forget the * */
	new_ht->array = calloc(size, sizeof(hash_node_t *));
	if (new_ht->array == NULL)
	{
		free(new_ht);
		new_ht = NULL;
	}
	return (new_ht);
}
