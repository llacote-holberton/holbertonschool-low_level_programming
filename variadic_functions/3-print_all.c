#include <stdarg.h> /* Required for variadic usage. */
#include <stdio.h>  /* Required for printf. */
#include "variadic_functions.h"

/**
 * print_character - Prints a single character
 *   reading the next variadic parameter of given list.
 * @print_components: variadic list to pick component from.
 */
void print_character(va_list print_components)
{
	/* @warning: 'char' and 'short' are "promoted" to int type */
	/*   when read through va_arg, so need to be re-converted. */
	printf("%c", (char)va_arg(print_components, int));
}

/**
 * print_integer - Prints a single integer number
 *   reading the next variadic parameter of given list.
 * @print_components: variadic list to pick component from.
 */
void print_integer(va_list print_components)
{
	printf("%d", va_arg(print_components, int));
}

/**
 * print_float - Prints a single float number
 *   reading the next variadic parameter of given list.
 * @print_components: variadic list to pick component from.
 */
void print_float(va_list print_components)
{
	/* @warning: 'float' is "promoted" to double type */
	/*   when read through va_arg AND printf can use it with %f */
	/*   SO contrarily to previous case this time we "follow" it. */
	printf("%f", va_arg(print_components, double));
}

/**
 * print_string - Prints a single string
 *   reading the next variadic parameter of given list.
 * @print_components: variadic list to pick component from.
 */
void print_string(va_list print_components)
{
	/* @warning: 'char' and 'short' are "promoted" to int type */
	/*   when read through va_arg, so need to be re-converted. */
	printf("%s", va_arg(print_components, char *));
}

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
	int f; /* Format iterator */
	int p; /* Printers parser */

	P supported_printers[5] = {
		{'c', print_character},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	/* Not explicit in directives but logical to me */
	if (format != NULL)
	{
		va_start(print_components, format);
		f = 0;
		while (format[f] != '\0')
		{
			p = 0;
			/* while p < 4 BAAAD */
			/* Another alternative: calculating size of printers with sizeof. */
			while (supported_printers[p].id != '\0')
			{
				if (format[f] == supported_printers[p].id)
				{
					printf("%s", (f != 0) ? ", " : "");					
					supported_printers[p].printer(print_components);
					break;
				}
				p++;
			}
			f++;
		}
		printf("\n");
	}
}

/* ==== BRAINSTORM AND SELF-TEACHING NOTES ==== */
/*
 * Biggest problem here is/was to know how to pass format
 *   and "type of next variadic parameter".
 * 1/ There is NO way to pass the interpolation type
 *   dynamically to va_arg because it's set during
 *   compiling time.
 * 2/ We cannot chain up IF because of exercice constraint.
 * 3/ Using a table with ASCII as index and "format" as value
 *    would allow providing "printf's template" dynamically
 *    but does nothing for that problem.
 * => We need an "indirection" which takes care of both
 *   "associated format" AND "associated type".
 * BUT even a struct with member "template" and member
 *   "type" wouldn't work because it would still be
 *   "providing type value dynamically".
 * => Hint here is "no more than 5 functions by file".
 * => The ONLY way that I see is making dedicated functions
 *    AND using a structure to make the indirection when
 *    a character in format match supported operations.
 */
