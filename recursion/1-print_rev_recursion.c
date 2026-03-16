#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - recursively print a string in reverse.
 * @s: string to print.
 *
 * Return: Always 0.
 */
void _print_rev_recursion(char *s)
{
	/* This "strategy" is the only valid one for correct behaviour */
	/* Stating first the "last case" with its associated process. */
	if (*s == '\0')
	{
		/* @warning BAD because means it's put "on top of the recursion stack" */
		/*   so will be printed before everything else (first "depiled").      */
		/* _putchar('\n'); */
		/* DO NOT forget to "break" otherwise the program would pursue */
		return;
	}
	/* Then describing the "ongoing" process including recursion. */
	/* @warning: ++s made "miss" last character (moving pointer before print). */
	/* @warning: s++ made infinite recursion (logically). */
	_print_rev_recursion(s + 1);
	_putchar(*s);
	/* @warning CANNOT WORK, logically, since we return just before. */
	/* if(*s == '\0')    */
	/*   _putchar('\n'); */
	/* So the neat devious trick is to check "the cell after current". */
	/*   That way we "add" the '\n AFTER all the recursive calls BUT  */
	/* BEFORE unpiling so it will end last as expected. */
	/* ACTUALLY DOESN'T WORK EITHER IT TRUNCATES OUTPUT. */
	/* if (s[1] == '\0')*/
	/* _putchar('\n'); */
}

/* === BRAINSTORM AND SELF-TEACHING NOTES === */
/*
 * WARNING: Only ONE good method (at least for this exercise)
 *   to make the recursion properly.
 * ESSENTIAL thing to understand is: recursion makes a new "living copy"
 *   of the function with a copy of variables provided as parameters.
 * => s variable is a new copy for each call.
 * => Calling with s++ would create an infinite recursion because, we create
 *    a new copy of _print_rev_recursion with a copy of current pointer
 *    BEFORE moving it. So technically it's always the same target address.
 * => Calling with ++s works because we actually move pointer before calling
 *    BUT with current writing we make the recursive call BEFORE printing so we
 *    "offset" the whole print sequence from the first character.
 * => Calling with s+1 works perfectly because we keep the "current pointer"
 *      consistent for the putchar which comes next in the same "loop cycle"
 *      YET give a "forward address" for the call of next recursion.
 */
