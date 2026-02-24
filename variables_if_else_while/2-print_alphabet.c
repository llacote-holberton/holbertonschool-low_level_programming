#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints a-z letters aggregated on a line.
 * Description: prints the lower-case ASCII alphabet in a continuous string.
 * Probably many ways. The one I chose is using a loop incrementing a "counter"
 *   which will stay within a number range matching
 *   the ASCII range of a-z character set.
 * There were probably other ways with arrays or printf
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;

	for (character_code = 97; character_code < 97 + 26; character_code++)
		putchar(character_code);
	putchar('\n');

	return (0);
}
