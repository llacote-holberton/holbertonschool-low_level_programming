#include "main.h"
#include <stdio.h>

/**
 * _puts_recursion - prints given string through recursion.
 * @s: string to print.
 *
 * Return: Always 0.
 */
void _puts_recursion(char *s)
{
	/* This "strategy" is the only valid one for correct behaviour */
	/* Stating first the "last case" with its associated process. */
	if (*s == '\0')
	{
		_putchar('\n');
		/* DO NOT forget to "break" otherwise the program would pursue */
		return;
	}
	/* Then describing the "ongoing" process including recursion. */
	_putchar(*s);
	_puts_recursion(++s);
}

/* === BRAINSTORMING AND SELF-TEACHING NOTES */
/*
 * V0.5 DID NOT work correctly because printed as many \n
 *   as characters. Logically.
 * {
 * if (*s != '\0')
 * {
 * _putchar(*s);
 * _puts_recursion(++s);
 * }
 * _putchar('\n');
 * }
 *
 * Because here we didn't "tie" the newline to the
 *   "breaking case" of the recursion loop.
 */
