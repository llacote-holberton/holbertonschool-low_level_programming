#include <stdio.h>

/**
 * main - counts from 0 to 9 on standard output (display).
 * Description: prints single digits from 0 to 9.
 *
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;

	for (character_code = 48; character_code < 48 + 10; character_code++)
		putchar(character_code);
	putchar('\n');

	return (0);
}
