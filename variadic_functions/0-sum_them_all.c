#include <stdarg.h> /* Required for variadic usage. */

/**
 * sum_them_all - Aggregates the sum of given n integers.
 * @n: unsigned integer giving amount of numbers to sum.
 *
 * Description: reads a number of extra arguments known
 *   from the first to aggregate and return their total sum.
 *
 * Return: integer (sum of all numbers)
 *
 * Additional directives
 *   If n == 0, return 0
 */
int sum_them_all(const unsigned int n, ...)
{
	/* Using variadic requires specific and precise process. */
	/* Define a va_list type variable */
	va_list numbers;
	/* Define a variable of coherent type to "read" parameters */
	/* Here we know to expect int. I think... */
	/* int current; */
	/* Also variable to hold aggregate. */
	int total;
	/* And a classic generic iterator. */
	unsigned int i;

	total = 0;
	if (n == 0)
		return (total);

	/* We must "start variadic parse" by giving last named argument */
	va_start(numbers, n);
	/* Since here we have number of arguments given let's use for. */
	for (i = 1; i <= n; i++)
	{
		/* Va_arg reads the next argument in list with provided type */
		total += (va_arg(numbers, int));
	}
	return (total);
}
