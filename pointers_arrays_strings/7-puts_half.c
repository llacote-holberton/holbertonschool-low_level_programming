#include "main.h"
/**
 * puts_half - prints only second half of provided string.
 * @str: pointer to array of char
 * Description: only displays one on two characters of provided
 *   string starting with the first. Ends with newline.
 * Return: void.
 */
void puts_half(char *str)
{
	/*  Variable used to get total string length */
	/*  And being used as a "cursor" to travers as well. */
	int cursor;
	/* Variable which will hold starting position to "print" half" */
	int half_start;
	/* Get the total length */
	cursor = 0;
	while (str[cursor])
		cursor++; /* "Moves temporary pointer" while counting length. */
	--cursor;  /* Remove the "jump" made for endofstring char '\0'. */
	half_start = (cursor % 2 == 0) ? cursor / 2 : (cursor + 1) / 2;
	while (str[half_start])
	{
		_putchar(str[half_start]);
		++half_start;
	}
	_putchar('\n');
}

