#include "main.h"
/**
 * print_rev - prints a string with newline on standard output.
 * @s: pointer to array of char
 * Description: prints a string followed by newline.
 * Return: void.
 */
void print_rev(char *s)
{
	/*
	 * To print reverse we must know the length.
	 * So first must find the length THEN we can just "get pointer and end"
	 * then decrement to print characters sequentially.
	 */
	int cursor;

	cursor = 0;
	/*
	 * Must first find the length, no way around "reading all".
	 * BECAUSE '\0' is equated to 0 as a character number
	 * AND because "0" is evaluated to "false" in conditions
	 *   it is possible to write while (*string) instead of
	 *   while (*string != '\0')
	 * BUT now that we remove the intermediate "length"
	 * We do NOT want to move "original pointer address" for string
	 * HENCE HAVE TO use the "dynamic address computation" style.
	 */
	while (s[cursor])
	{
		/* We increment the ADDRESS by 1 which works */
		/*   because characters take only 1 byte.    */
		cursor++;
	}
	do {
		_putchar(s[cursor]);
		--cursor;
	} while (cursor >= 0);
	_putchar('\n');
}

