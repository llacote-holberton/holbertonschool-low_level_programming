#include <stdlib.h>
/* #include <stdio.h> */

/**
 * array_iterator - triggers a requested process on an array.
 * @array: pointer to array of integers
 * @size: size in bytes, by convention, number of elements here.
 * @action: pointer to a function processing an integer
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	/* We want to process all elements of an array. */
	/* Since its size is given we can go for simple loop. */
	int i;
	/* NOTE: if size was "actual size in bytes" we would need to compute */
	/*   number of elements. We could make the maths in the loop */
	/*   but it means it would be remade each cycle. So... */
	/* Better to use a dedicated variable then */
	/* int items_count; */
	/* items_count = size / (sizeof(int)); */

	/* BUT here we KNOW because we have access to "main" code */
	/*   that it's actually "the number of elements" which is provided. */
	/* So we can use size directly. */
	for (i = 0; i < (int)size; i++)
	{
		/* printf("Current targeted cell is %d with number %d.\n", i, array[i]); */
		action(array[i]);
	}
}
