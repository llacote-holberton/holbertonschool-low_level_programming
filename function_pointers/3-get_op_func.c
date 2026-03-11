/* Confer 3-README.md for special directives. */
#include "3-calc.h" /* REQUIRED for file to "know" our custom type. */
#include <stddef.h> /* Required for NULL constant */
#include <string.h> /* Required to compare string easily */

/**
 * get_op_func - Returns pointer to the adequate arithmetic function.
 * @s: string - Operator.
 *
 * Return: a pointer to a function which is...
 *   taking two integers as parameters.
 *   returning an int.
 */
int (*get_op_func(char *s))(int, int)
{
	/* Table of structs allowing indirections to        */
	/*   arithmetic functions depending on operator.    */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;
	/* The logic here is finding whether given operator */
	/*   matches the "op" member of one of the structs in our */
	/*   "supported operations" array of "op structures". -  */
	i = 0;
	while (ops[i].op != NULL)
	{
		/* @warning works well here because unique character in string both cases */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
			/* I really dislike returns "buried so deep" but no choice because */
			/*   of imposed directives on loops/conditions/variables uses...   */
		i++;
	}
	return (NULL);
}
