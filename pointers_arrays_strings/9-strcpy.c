#include "main.h"
#include <stdio.h>
/**
 * *_strcpy - fully copies provided string to buffer.
 * @dest: pointer to array of characters we want to overwrite.
 * @src: pointer to array of characters we want to copy.
 * Description: prints the requested number of elements
 *   grabbed from provided array of integers,
 *   in a human readable way.
 * Return: pointer to destination array.
 */
char *_strcpy(char *dest, char *src)
{
	int cursor;

	/* Can it be as simple as just */
	/*   reaffecting the target address of dest */
	/*   to point on the same one as src? */
	/* NO as exercise requires explicitely to COPY. */
	cursor = 0;

	/*
	 * V2 - Smart and concise - Why and how does it work?
	 * It works because...
	 * a) Code directly uses the "current cursor index"
	 *    to affect the value of target cell in source array
	 *    inside the cell of same index in destination array.
	 *    Basically we moved the "body of v1 loop"
	 *      as part of the condition.
	 * b) Because we put that affectation in parenthesis
	 *    it becomes an expression to be evaluated.
	 * c) The "evaluation" of an affectation returns
	 *     the last value affected, thus the actual value
	 *     that was just copied.
	 * d) Because the affectation is made *before*
	 *     the condition is evaluated once again,
	 *     on the cycle where cell content of src is '\0'
	 *     it is affected inside dest as well.
	 * e) Loop exits cleanly because right *after* this affectation
	 *     the first part of condition is '\0' so '\0' == '\0' -> TRUE.
	 * NOTE: this is smart and concise but far less readable for
	 *   unseasoned devs. Kept for reference as useful in complex codes.
	 */
	while ((dest[cursor] = src[cursor]) != '\0')
		cursor++;
	return (dest);
}

/*
 * VERSION 1: works but "naive" and a bit verbose.
 *
 * int cursor;
 * cursor = 0;
 * while (src[cursor])
 * {
 *   dest[cursor] = src[cursor];
 *   cursor++;
 * }
 * dest[cursor + 1] = '\0';
 * return (dest);
 */
