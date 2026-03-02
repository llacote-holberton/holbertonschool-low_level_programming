#include "main.h"
/* #include <stdio.h> */
/**
 * _puts - prints a string with newline on standard output.
 * @str: pointer to array of char
 * Description: prints a string followed by newline.
 * Return: void.
 */
void _puts(char *str)
{
	/*
	 * Char being always "a single byte" AND memory being sized in bytes,
	 *   we can just use basic incrementation.
	 * @note using a "dedicated cursor" to keep the original pointer
	 *   "in place" as I feel directly modifying it may be a bad practice.
	 */
	char *cursor;

	cursor = str;
	while (*cursor != '\0')
	{
		_putchar(*cursor);
		++cursor;
	}
	_putchar('\n');
	/* printf("Cursor address is %p\n", cursor); */
	/* printf("String address is %p\n", str); */
}

