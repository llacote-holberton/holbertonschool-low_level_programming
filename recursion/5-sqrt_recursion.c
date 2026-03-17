#include "main.h"
#include <stdio.h>

/**
 * sqrt_searcher - evaluates if one int is square of other.
 * @n: integer - number to compute squared root from.
 * @candidate: current number to evaluate as square root.
 *
 * Return: integer (square root).
 */
int sqrt_searcher(int n, int candidate)
{
	/* Found square root! */
	if (candidate * candidate == n)
		return (candidate);
	/* Need to break if candidate reached N!! */
	/* And since "parent" (caller) function is designed to */
	/*  directly "propagate return" from here upstream    */
	/*  AND if no root return -1 it's what we return here. */
	if (candidate >= n)
		return (-1);
	/* Note that technically order of the ifs should not matter */
	/* (I think) since mutually exclusive "ranges"...   HOWEVER */
	/* the recursive call MUST (obviously) be the last return.  */
	return (sqrt_searcher(n, (candidate + 1)));
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: integer - number to compute squared root from.
 *
 * Return: integer (square root).
 *
 * Additional information
 * - If n does not have a natural square root,
 *   the function should return -1
 *
 * NOTE: tried really hard a version without another
 *   function used to hold and adjust "root" but failed.
 *   Confer draft file for why it cannot work.
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
	/* Using static doesn't work, so has to use "helper". */

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (sqrt_searcher(n, 0));
}

/* === BRAINSTORM AND SELF-TEACHING NOTES */
/*
 * v0.6 didn't work better using another static
 *   "init" doens't help in the end.
 *
 * v0.5 DOESN'T WORK BECAUSE...
 * a) I don't cover neatly the case of "square not integer"
 * b) I don't reset root between several calls to function.
 * => Must use a trick similar to the "separator variable"
 *    "set after first round" by using an "init variable"
 *    used as a boolean to reinitialize root.
 *
 * static int root = 0;
 *
 * if (n < 0)
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
