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
	new_ht = calloc(size, sizeof(hash_table_t));
	/* Logically no need to make "if" since we return just after. */
	/* If alloc failed then new_ht will be NULL all the same. */
	return (new_ht);
}
