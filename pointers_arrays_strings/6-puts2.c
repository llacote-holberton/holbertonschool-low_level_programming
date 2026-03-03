#include "main.h"
/**
 * puts2 - displays "even index" characters.
 * @str: pointer to array of char
 * Description: only displays one on two characters of provided
 *   string starting with the first. Ends with newline.
 * Return: void.
 */
void puts2(char *str)
{
	/* If I'm right it's just a simple        */
	/*   matter of parsing array with pointer */
	/*   and only printing if index is even.  */
	int cursor;
	/* First, let's cover the case I didn't cover before */
	/* if(str == NULL) *//* Not sure if allowed to add <stddef.h> */
	/*	return; */
	/* Attempting a for loop, will it work?   */
	/* It does work BUT it is intrinsically limited */
	/*   by the assumption that provided string has a */
	/*   terminating '\0'; */
	/* @note by convention when targeting endofline */
	/*   always write it as '\0' and not '0' */
	for (cursor = 0; str[cursor] != '\0'; cursor++)
		if (cursor % 2 == 0)
			_putchar(str[cursor]);
	_putchar('\n');
}

