#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h> /* Required for Betty to understand struct. */

/* Externally provided replacement for putchar. */
int _putchar(char c);
/* C - VarFuncs - Exo 00 */
int sum_them_all(const unsigned int n, ...);
/* C - VarFuncs - Exo 01 */
void print_numbers(const char *separator, const unsigned int n, ...);
/* C - VarFuncs - Exo 02 */
void print_strings(const char *separator, const unsigned int n, ...);
/* C - VarFuncs - Exo 03 */
void print_all(const char * const format, ...);
/**
 * struct printers - Used to make indirection
 *   between a "formatter id" character
 *   and the appropriate dedicated function.
 * @id: character recognized as "supported format id".
 * @printer: pointer to function able to print variables
 *   of the associated type.
 */
typedef struct printers
{
	char id;
	void (*printer)(va_list);
} P;
/* Reminder: specific syntax to signal pointer to FUNCTION*/
/* ALSO DON'T FORGET THE RETURN TYPE!! */
/* AND the parameters (probably pointer to va_list ?) */
/* NOTE: specifically for va_list the syntax "va_list *" */
/* is NOT expected as it is handled in a custom way.  */
/* Passing "by value" creates a copy of the inner pointers */
/*   but not of the whole list. */
/* It could be useful to explicitely pass "by pointer" ONLY */
/* If we wanted to ensure that the caller gets the "updated pointer". */

#endif
