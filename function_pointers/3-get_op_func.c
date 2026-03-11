/* This file should hold (only) the one function */
/*   determining requested operation (if supported) */
/*
 * === SPECIFIC DIRECTIVES ===
 * - Prototype: int (*get_op_func(char *s))(int, int);
 * - where s is the operator passed as argument to the program
 * - This function returns a pointer to the function
 *    that corresponds to the operator given as a parameter.
 *    Example: get_op_func("+") should return a pointer to the function op_add
 * - You are not allowed to use switch statements
 * - You are not allowed to use for or do ... while loops
 * - You are not allowed to use goto
 * - You are not allowed to use else
 * - You are not allowed to use more than one if statement.
 * - You are not allowed to use more than one while loop in your code
 * - If s does not match any of the 5 expected operators
 *      (+, -, *, /, %), return NULL
 * - You are only allowed to declare these two variables in this function:
 *
 */
#include "3-calc.h" /* REQUIRED for file to "know" our custom type. */
#include <stddef.h> /* Required for NULL constant */
#include <string.h> /* Required to compare string easily */
#include <stdio.h>  /* @temporary */

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
	/* Imposed (only) variables */
	/* Table of structs allowing indirections */
	/*   to arithmetic functions depending on operator. */
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
		/* printf("Checks op %s at %lu.\n", ops[i].op, (unsigned long)ops[i].f); */
		/* @warning works well here because unique character in string both cases */
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
			/* I really dislike returns "buried so deep" but no choice. */
			/* Considering the constraints on loops and if...*/
		i++;
	}
	return (NULL);
}
