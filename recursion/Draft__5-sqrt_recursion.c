#include "main.h"
#include <stdio.h>

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: integer - number to compute squared root from.
 *
 * Return: integer (square root).
 *
 * Additional information
 * - If n does not have a natural square root, 
 *   the function should return -1
 */
int _sqrt_recursion(int n)
{
	/* Many ways to find a square root. */
	/* One way to make it iteratively with some precision is */
	/* next_Y ​= 2Y + X / Y where X is base number. */
	/* (got from IA, I couldn't find this myself too bad in maths). */
	/* We also know that, by definition, "square root * square root" */
	/*   equals base number. Meaning we got a "break point". */
	/* Problem here is I don't see we can do without having 2nd variable. */
	/* => Use "static" cf https://www.w3schools.com/c/ref_keyword_static.phpv*/
	static int init = 1;
	static int root;
	printf("N is %d\n", n);
	
	
	if (n < 0)
	{
		printf("N is negative!\n");
		return (-1);
	}
	if (n == 0 || n == 1)
	{
		printf("N is 0 or 1!!\n");
		return (n);
		
	}

	if(init == 1)
	{
		printf("Initializing root.");
		
		root = 0;
		init = 0;
	}

	printf("Root is now %d.\n", root);
	
	
	if (root * root >= n)
	{
		printf("Root found for n:%d, it is %d.\n", n, root);
		init = 1;
		return (root);
	}
	return _sqrt_recursion(++root);
}

/* === BRAINSTORM AND SELF-TEACHING NOTES */
/*
 * v0.5 DOESN'T WORK BECAUSE...
 * a) I don't cover neatly the case of "square not integer"
 * b) I don't reset root between several calls to function.
 * => Must use a trick similar to the "separator variable"
 *    "set after first round" by using an "init variable"
 *    used as a boolean to reinitialize root.
 * 
 * 	static int root = 0;
 * 
 * if (n < 0)                     *
 * return (-1);
 * if (n == 0 || n == 1)
 * return (n);
 * if (root * root == n)
 * {
 * printf("Root found for n:%d, it is %d.\n", n, root);
 * return (root);
 * }
 * printf("Root now equals %d\n", root);
 * return _sqrt_recursion(++root);
 */
