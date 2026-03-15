#include <stdarg.h> /* Required for variadic usage. */
#include <stdio.h>  /* Required for printf. */
#include "variadic_functions.h"

/**
 * print_numbers - Prints a sequence of n integers with separator.
 * @separator: character used to separate the numbers.
 * @n: unsigned integer giving amount of numbers to sum.
 *
 * Description: prints a sequence of n given numbers using
 *   provided separator.
 *
 * Return: void.
 *
 * Additional directives
 *  You are allowed to use printf
 *  If separator is NULL, don't print it        *
 *  Print a new line at the end of your function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	/* Using variadic requires specific and precise process. */
	/* Define a va_list type variable */
	va_list numbers;

	/* And a classic generic iterator. */
	unsigned int i;

	if (n == 0)
	{
		printf("\n");
		return;
	}

	/* We must "start variadic parse" by giving last named argument */
	va_start(numbers, n);
	/* Since here we have number of arguments given let's use for. */
	for (i = 1; i <= n; i++)
	{
		/* Va_arg reads the next argument in list with provided type */
		printf("%d", va_arg(numbers, int));
		if (i < n && separator != NULL)
			printf("%s", separator);
	}
	va_end(numbers);
	printf("\n");
}
