#include <stdlib.h>


/**
 * print_name - prints a name from delegation.
 * @name: name of the person
 * @f: pointer to a printer function
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	/* We want to call the function given as parameter. */
	/* Since the pointer targets the code at given address     */
	/*   the syntax to call it is the same as if we directly   */
	/*   called the "desired function" with proper parameters. */
	f(name);
}
