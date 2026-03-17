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
	/*
	 * My own very flawed version copy/paste from previous.
	 * if (n < 0)
	 * return (-1);
	 * if (n == 0 || n == 1)
	 *   return (n);
	 * if (candidate * candidate == n)
	 *   return (candidate);
	 * if (candidate >= n)
	 *   return (-1);
	 * return (sqrt_searcher(n, (candidate + 1)));
	 */
	/* Much better version from IA which covers all cases */
	/* Covers even negative numbers since (-*- = +). */
	if (candidate * candidate > n)
		return (candidate - 1);
	return (sqrt_searcher(n, candidate + 1));
}

/**
 * is_multiple_of_x - checks if clean division from n by x.
 * @n: integer - number to check whether prime one.
 * @x: integer - number to try "clean division" with.
 * Return: boolean-like integer (1 equals "remainder left").
 *
 * NOTE: 0 meaning "success or is multiple of" is actually
 *   good convention here since it aligns with the kind of return
 *   that we want in caller: if there is remainder then n is NOT
 *   a multiple of x so "increased chance" that n is prime.
 */
int is_multiple_of_x(int n, int x)
{
	/* This time we recurse by diminishing x */
	/*   until we reach 1 at which point we break. */
	/* Going this approach because starting from   */
	/*   "Closest integer to square root of n" is  */
	/*   the only way I see right now to iterate   */
	/*   recursively. */
	/* I think order of IFs is mandatory here. */
	/* <= 1 preferred to == 1 to prevent "division by zero" */
	if (x <= 1)
		/* Then we tried all prime numbers between 1 */
		/*   and "initial x" without finding any     */
		/*   "clean multiple relationship".          */
		/* So n is prime. */
		return (1);
	if (n % x == 0)
		/* No remainder means n is NOT prime. */
		return (0);
	/* Still not sure, pursuing with "lesser x". */
	return (is_multiple_of_x(n, x - 1));
}

/**
 * is_prime_number - evaluates if given integer is prime.
 * @n: integer - number to check whether prime one.
 *
 * Return: boolean-like integer (1 equals "number is prime").
 */
int is_prime_number(int n)
{
	int n_sqrt;
	/*
	 * Definition of prime number is "a number which
	 *   it is only divisble by 1 and by itself.".
	 * SINCE (square root of N) * (square root of N) = N
	 * AND SINCE non-prime X can be written as A * B
	 * THEN at least A OR B must be inferior to square root of N.
	 * CONSEQUENTLY we must only test if N is dividable by any
	 * of the prime numbers between 1 and square root of N.
	 */
	/* 1 is NOT prime because it has only ONE unique diviser.         */
	/* "Convention chosen" to not break the theorem which states that */
	/* "Any integer > 1 has JUST ONE WRITING as a factor of prime numbers." */
	if (n <= 1)
		return (0);
	/* First "evacuating" the simple cases */
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13)
		return (1);
	/* Reusing previous function, might as well. :) */
	n_sqrt = sqrt_searcher(n, 0);
	/* @warning stupid mistake, useless AND can provoke divide by 0 */
	/*  return (is_multiple_of_x(n, n_sqrt / 10)); */
	return (is_multiple_of_x(n, n_sqrt));
}

/*
 * BRAINSTORM AND SELF-TEACHING NOTES
 *
 * IMPORTANT: in the category "what happens when you suck in maths"
 * I present "discover the far simpler and more efficient algorithm
 *   you could have discovered if you had the brainpower for it."
 *
 * Solution provided by IA. Not that far from what I reached
 *   but showing I still went "from the wrong way".
 * => Putting it here as a reminder, but I commit to my work. xd
 *
 * int is_prime_recursive(int n, int x)
 * {
 *   if (x * x > n)
 *     return (1);
 *   if (n % x == 0)
 *     return (0);
 *   return (is_prime_recursive(n, x + 1));
 * }
 */
