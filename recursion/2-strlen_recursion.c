#include "main.h"
#include <stdio.h>

/**
 * _strlen_recursion - recursively counts string length
 * @s: string to print.
 *
 * Return: integer (string length WITHOUT EOL).
 */
int _strlen_recursion(char *s)
{
	/* @warning CANNOT USE A VARIABLE */
	/*   because it would be reinitialized? */
	/*   at least I don't know how to propagate it. */
	/* Cannot compile if we don't explicitely initialize it either */
	/*
	 * Logic is...
	 * 1/ We must recursively "advance" a cursor to count chars.
	 * 2/ we must break AND return immedidately when reaching '\0'.
	 * => Question is how to keep the count since we only have one argument
	 *   and are forbidden from using global variables.
	 * => First attempt: define length at 0 when reaching "\0"
	 *    and have piled up calls just "increment" length before returning.
	 */
	if (*s == '\0')
	{
		return (0);
	}
	/* @important trick here is a logical one. */
	/* IF we "passed" the break condition on first call */
	/* THEN it means we have at least ONE character.    */
	/* SO we can use a "static" 1 as a base and just the return */
	/*   of subsequents call to it. */
	return (1 += _strlen_recursion(s + 1));
	/* Logic detailed on a 3 characters string "hi!" */
	/*
	 * Call 1: s points to [0], read "h", != 0, skip break.
	 *   -> return 1 + (compute length from s[1] onwards) => on hold.
	 * Call 2: s points to [1] read "i", skip break
	 *   -> return 1 + (compute length from s[2] onwards) => on hold.
	 * Call 3: s points to [2] read "!", skip break
	 *   -> return 1 + (compute length from s[3] onwards) => on hold.
	 * Call 4: s points to [3] read '\0' BREAK recursion, returns 0.
	 * => Full recursion stack ends up being in reverse
	 *   0 (C4 end) => 1 + 0 (C3 end) => 1 + 1 (C2 end) => 1 + 2 (C1 end)
	 * => 3 final value.
	 */
}

/*
 * === BRAINSTORM AND SELF-TEACHING NOTES ===
 *
 * THIS VERSION DOESN'T WORK.
 * int length;
 * if (*s == '\0')
 * {                                          *
 * length = 0;
 * return (length); Same with 0 directly.
 * }
 * return (length = _strlen_recursion(s + 1));
 * Doesn't work either because compiler doesn't want
 *   code where length may be used without having been initialized.
 * return (length += _strlen_recursion(s + 1));
 *
 * => Always return just 0.
 */

