#include "main.h"
/**
 * print_rev - prints a string with newline on standard output.
 * @s: pointer to array of char
 * Description: prints a string followed by newline.
 * Return: void.
 */
void print_rev(char *s)
{

	int cursor;

	cursor = 0;

	while (s[cursor])
	{
		/* We increment the ADDRESS by 1 which works */
		/*   because characters take only 1 byte.    */
		cursor++;
	}
	/* @IMPORTANT REQUIRED to "remove" the '\0' as it would */
	/*   otherwise mess the character count (64 expected).  */
	--cursor;
	while (cursor >= 0)
	{
		_putchar(s[cursor]);
		--cursor;
	}
	_putchar('\n');
}
