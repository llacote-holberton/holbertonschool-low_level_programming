#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - triggers a requested process on an array.
 * @array: pointer to array of integers
 * @size: size in integer.
 * @cmp: pointer to a function processing an integer
 *   to compare it with an arithmetic rule.
 *
 * Return: INDEX of first number found matching the comparison expression.
 *
 * Additional notes
 * - return value 0 from inner comparison function
 *   is not considered valid.
 * - "false" value (no match found) should be -1.
 * - if size <= 0 return -1 immediately as (logically)
 *     there is nothing to compare.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	/* Index of match (case arising) also used as iterator index. */
	int match_idx;

	if (size <= 0)
		return (-1);

	/*
	 * We want to process an array to find the first element
	 *   which would match the requested comparison.
	 * As the array size is given, we can make a loop which
	 *   should break whichever happens first.
	 * - Parsed the whole array without finding a match.
	 * - OR found a match.
	 */
	match_idx = 0;
	/* This logic works only as long as we pass functions  */
	/*   which guarantee passing 0 or negative on failure. */
	while (match_idx < size)
	{
		/* Apparently this is wrong we have to cover case of */
		/*   comparison function returning negative value.   */
		if (cmp(array[match_idx]) != 0)
			return (match_idx);
		match_idx++;
	}
	return (-1);
}
