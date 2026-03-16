#include <stdarg.h> /* Required for variadic usage. */
#include <stdio.h>  /* Required for printf. */
#include "variadic_functions.h"

/* Static keyword only applies to "storage" aka actual variables. */
struct printers 
{
	char id;
	/* Reminder: specific syntax to signal pointer to FUNCTION*/
	/* ALSO DON'T FORGET THE RETURN TYPE!! */
	/* AND the parameters (probably pointer to va_list ?) */
	/* NOTE: specifically for va_list the syntax "va_list *" */
	/* is NOT expected as it is handled in a custom way.  */
	/* Passing "by value" creates a copy of the inner pointers */
	/*   but not of the whole list. */
	/* It could be useful to explicitely pass "by pointer" ONLY */
	/* If we wanted to ensure that the caller gets the "updated pointer". */
	void (*printer)(va_list);
};

/**
 * print_character - Prints a single character
 *   reading the next variadic parameter of given list.
 */
void print_character(va_list print_components)
{
	/* @warning: 'char' and 'short' are "promoted" to int type */
	/*   when read through va_arg, so need to be re-converted. */
	printf("%c", (char)va_arg(print_components, int));
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
	/* Format iterator */
	int cursor;

	struct printers supported_printers[1] = {
		{'c', print_character}
	};

	/* Not explicit in directives but logical to me */
	if (format != NULL)
	{

		va_start(print_components, format);
		/* While we have a character in format, AND  */
		/*   it matches an allowed formatter, THEN   */
		/*   we read and print the matching argument */
		cursor = 0;
		while (format[cursor] != '\0')
		{
			if (format[cursor] == 'c')
				supported_printers[0].printer(print_components);
			/*
			 * a = 0;
			 * while (allowed_formatters[a] != '\0')
			 * {
			 *   if (format[cursor] == allowed_formatters[a])
			 *   {
			 *     break;
			 *   }
			 * a++;
			 * }
			 */
			cursor++;
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
