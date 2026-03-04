#include "main.h"

/**
 * char reverse_array - reverses a numbers array of length n.
 * @a: pointer to an array of integers
 * @n: array length which must be provided as no way to know.
 *
 * Description: Takes an array of numbers with its length
 *   and uses it to reverse.
 * Returns: nothing.
 */
void reverse_array(int *a, int n)
{
	/* Because we have array length given explicitely */
	/*   and it's passed by copy, it's much easier. */


	/* Used as intermediate during the swap */
	int placeholder;
	/* We must have the "end" of an array.*/
	/* int *swapper_end; */
	/* But also a regular parser; */
	/* int *swapper_start; */
	/* Because we have length we can also deduce the middle */
	/*   so we can probably use only one index cursor. */
	int i;

	/*
	 * Instead of "while n > 0" and swapping "all the way"
	 *   since we swap "start and end" in same array
	 *   we actually have "length / 2" cycles to run
	 */
	for (i = 0; i <= n / 2; i++)
	{
		placeholder = a[i];
		/* @warning never forget the difference */
		/*   between "array start" (index 0) and length (n). */
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = placeholder;
	}
}
