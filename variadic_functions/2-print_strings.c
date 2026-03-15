#include <stdarg.h> /* Required for variadic usage. */
#include <stdio.h>  /* Required for printf. */
#include "variadic_functions.h"

/**
 * print_strings - Prints a sequence of n strings with separator.
 * @separator: character used to separate the numbers.
 * @n: unsigned integer giving amount of strings to print.
 *
 * Description: prints a sequence of n given numbers using
 *   provided separator.
 *
 * Return: void.
 *
 * Additional directives
 * - You are allowed to use printf.
 * - If separator is NULL, don't print it.
 * - If one of the string is NULL, print (nil) instead.
 * - Print a new line at the end of your function.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	/* Variadic list of strings */
	va_list string_components;
	/* List cursor */
	char *current;
	/* Iterator */
	unsigned int i;

	if (n > 0)
	{
		va_start(string_components, n);
		i = 1;
		do {
			current = va_arg(string_components, char *);
			printf("%s", (current != NULL) ? current : "(nil)");
			printf("%s", (separator != NULL && i < n) ? separator : "");
			i++;
		} while (i <= n);
	}
	printf("\n");
}
