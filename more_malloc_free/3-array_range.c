#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an incremental sequence of numbers.
 * @min: integer, start (included) of sequence.
 * @max: integer, end (included) of sequence.
 * Description: creates an incremental sequence of numbers
 *   from start to end, both outer bounds included.
 *
 * Return: pointer to array of integers.
 *
 * Additional information
 * - Sequence includes all nubmers (increment by 1).
 * - If min > max should return NULL.
 *   (implication: min = max means return pointer to single int.)
 * - IF malloc fails should return NULL.
 */
int *array_range(int min, int max)
{
	int *numbers_sequence;
	int *sequencer;
	unsigned int size; /* Required for betty style */

	if (min > max)
		return (NULL);

	/* Woulnd't have realized the problem without IA help honestly. */
	/* Problem if not forcing unsigned is: when min is "deep in negative" */
	/*   while also having max "big enough" since substracting negative" "*/
	/*   is actually adding, with a regular (signed) int we end up with   */
	/*   a number far exceeding the maximum value that int can hold. */
	size = (unsigned int)(max - min + 1);
	/* Adding one because bounds are included so we must cover min=max. */
	numbers_sequence = (int *)malloc(sizeof(int) * size);
	if (numbers_sequence == NULL)
		return (NULL);

	/* We can directly use min because no other use left for it. */
	sequencer = numbers_sequence;
	while (min <= max)
	{
		*sequencer = min;
		sequencer++;
		min++;
	}

	return (numbers_sequence);
}
