#include "main.h"
#include <stdio.h>
/**
 * print_rev - prints a string with newline on standard output.
 * @str: pointer to array of char
 * Description: prints a string followed by newline.
 * Return: void.
 */
void print_rev(char *s)
{
	/*
	 * To print reverse we must know the length.
	 * So first must find the length 
	 * THEN we can just "get pointer and end"
	 * then decrement to print characters sequentially.
	 */
	char *cursor;
	int length;

	/* @note must be EXACTLY THIS AS
	 *   we want the "cursor" pointer
	 *   to point to "the first character of string s"
	 *   so the writing *cursor = *s would not work (IIUC).
	 */
	cursor = s;
	length = 0;
	/*
	 * Must first find the length, no way around "reading all".
	 * BECAUSE '\0' is equated to 0 as a character number
	 * AND because "0" is evaluated to "false" in conditions
	 *   it is possible to write while (*cursor) instead of
	 *   while (*cursor != '\0')
	 */
	while (*cursor)
	{
		/* We increment the ADDRESS by 1 which works */
		/*   because characters take only 1 byte.    */
		cursor++;
		printf("Cursor adddress is %p \n\t and its character is %c. \n", cursor, *cursor);
		++length;
	}
	--cursor; /* Backtracking once to be just before the '\0'. */
	do {
		_putchar(s[length]);
		--length;
	} while (length >= 0);
	_putchar('\n');
}

