#include <stdlib.h>
/* #include <stdio.h> */

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
	int match_idx;   /* Generic iterator index. */
	int match_found; /* "Truthful value" (>0 is success).  */

	match_found = -1;
	if (size <= 0)
		return (match_found);

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
	while (match_found <= 0 && match_idx < size)
	{
		/* printf("Processing %d of index %d.\n", array[match_idx], match_idx); */
		match_found = cmp(array[match_idx]);
		/* printf("Result of comparison is %d.\n", match_found); */
		if (!(match_found > 0))
			match_idx++;
	}
	return (match_idx);
}




/**
 * int_matching_value - triggers a requested process on an array.
 * @array: pointer to array of integers
 * @size: size in integer.
 * @cmp: pointer to a function processing an integer
 *
 * Return: First number found matching the comparison expression.
 *
 */
int int_matching_value(int *array, int size, int (*cmp)(int))
{
	int i;              /* Generic iterator index. */
	int matched_number; /* Number to return (-1 is no match). */
	int match_found;    /* "Truthful value" (>0 is success).  */
	/* Initializing to -1 since "default return" should be "false". */
	matched_number = -1;

	if (size <= 0)
		return (matched_number);

	/*
	 * We want to process an array to find the first element
	 *   which would match the requested comparison.
	 * As the array size is given, we can make a loop which
	 *   should break whichever happens first.
	 * - Parsed the whole array without finding a match.
	 * - OR found a match.
	 */
	i = 0;
	/* This logic may bite me if we search -1 as an actual number. */
	while (matched_number == -1 && i < size)
	{
		/* printf("Processing number %d of index %d.\n", array[i], i); */
		/* YES ACTUALLY IS STUPID BECAUSE SOME FUNCTIONS WILL RETURN 0. */
		match_found = cmp(array[i]);
		/* printf("Result of comparison is %d.\n", match_found); */
		if (match_found > 0)
			matched_number = array[i];
		i++;
	}
	return (matched_number);
}
