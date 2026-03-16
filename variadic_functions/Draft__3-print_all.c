#include <stdarg.h> /* Required for variadic usage. */
#include <stdio.h>  /* Required for printf. */
#include "variadic_functions.h"

/**
 * print_all - Prints components depending on their format.
 * @format: string providing expected format for components to print,*
 *   char by char.
 *
 * Description: prints a sequence of components formatted
 *   depending on the given matching format in order.
 * Return: void.
 *
 * Additional directives
 * where format is a list of types of arguments passed to the function
 * c : char                                     *
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead
 * any other char should be ignored
 * You are not allowed to use for, goto, ternary operator, else, do ... while
 * You can use a maximum of 2 while loops AND 2 if.
 * You can declare a maximum of 9 variables
 * You are allowed to use printf
 * Print a new line at the end of your function
 */
void print_all(const char * const format, ...)
{
	/* Variadic list of components */
	va_list print_components;
	char *allowed_formatters = "cifs";
	int cursor; /* Iterator to read "format" from input */
	int a; /* Iterator to compare with allowed formats */
	/*char template[];*/ /* NOT as literal because we'll reset it each time. */
	/* Variables defined to indirect the type on va_arg*/
	char *c;
	char *i;
	char *f;
	char *s;
	/* Use table instead? With ASCII as index? And content being format? */

	/* Not explicit in directives but logical to me */
	if (format != NULL)
	{
		c = "%c";
		i = "%d";
		f = "%f";
		s = "%s";

		va_start(print_components, format);
		/* While we have a character in format, AND  */
		/*   it matches an allowed formatter, THEN   */
		/*   we read and print the matching argument */
		cursor = 0;
		while (format[cursor] != '\0')
		{
			a = 0;
			while (allowed_formatters[a] != '\0')
			{
				if (format[cursor] == allowed_formatters[a])
				{
					/* I feel I need to use pointers but not sure how */
					/* Compiler error "expected specifier-qualifier-list so () won't work. "*/
					printf("@fixme how to format", va_arg(print_components, *(format[cursor])))
					/* Print separator if not last item */
					printf("%s", (format[cursor] != '\0') ? ", " : "");
					break;
				}
				a++;
			}
			cursor++;
		}
		printf("\n");
		/* GRRR COMPILER */
		printf("%s%s%s%s", c, i, s, f);

	}
}


/* ==== BRAINSTORM AND SELF-TEACHING NOTES ==== */
