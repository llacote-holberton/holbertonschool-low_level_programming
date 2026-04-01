#include "hash_tables.h"

/**
 * key_index - returns the index of a given key.
 * @key: string used to generate hash value
 * @size: size of hash table required to know how to compute "buckets".
 *
 * Return: number indicating position of element matching key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int key_hash = 0;
	/* Seems logical to me to skip those cases. */
	if (size == 0 || key == (unsigned char *)"")
		return (0);

	/* Need to cast because prototype signatures requires it. */
	key_hash = hash_djb2(key);
	/* Cell is usually computed through the way of modulo. */
	return (key_hash % size);
}
