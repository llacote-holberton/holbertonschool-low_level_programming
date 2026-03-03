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
	char *cursor;
	/*
	 * How does it work?
	 * It works (ONLY) because of the fixed and specific
	 *   order in which the C compiler "reads" the line
	 *   and "processes" the various operators which compose it.
	 * This uses the following concepts.
	 * 1/ Deferencement (*pointer_name): telling compiler that we
	 *   want to access the VALUE held at the address the pointer targets.
	 * 2/ Affectation returns, which is the value affected
	 * 3/ Post-incrementation, which is about raising the "value" by 1
	 *    AFTER having read and returned it in the expression
	 *    (so only next time it is accessed will it give the updated value).
	 * 5/ "Lvalue" vs "Rvalue": when encountering an operator of affectation
	 *    compiler will ALWAYS consider right expression as "VALUE to read"
	 *    AND left expression as "CONTAINER to put value into".
	 * 4/ Most importantly operator precedence
	 *    "accessor" >> ++ (because put on its right) >> * dereference)
	 *
	 * So what happens in a cycle
	 * 1) mypointer++ Returns "current address" THEN increments dest
	 * 2) "*" targets this "current address" to either...
	 *    - Give the memory container for that address (if on left of =)
	 *        AND is a "valid lvalue" (expression which matches a container)
	 *    - Give the value contained at this address (if on right of =)
	 * => "Reads the value of cell with "current index" in src, affects it in
	 *     the cell of "current index" in dest, just before incrementing the index
	 *     on both sides simultaneously.
	 *    THEN returns the affected value to evaluate if "should continue?" which
	 *     will return TRUE for anything beyond 0, '\0' or "false" (<stdbool.h>).
	 * => Also works cleanly for the last index holding the '\0' BECAUSE
	 *    it is the result of its affectation itself which stops the loop
	 * NOTE: we use "cursor" as intermediate to "write over desired memory zone"
	 *   while keeping the original "starting address" untouched.
	 */
	cursor = dest;
	while ((*cursor++ = *src++)) /* @note betty requires ; on newline, berk. */
	;
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
 * while ((dest[cursor] = src[cursor]) != '\0')
 * cursor++;*
 * return (dest);*
 */
