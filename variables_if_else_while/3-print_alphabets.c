#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints whole ASCII alphabet letters aggregated on a line.
 * Description: prints the alphabet first lower-case then upper-case
 *   in a continuous string.
 *   Mixing two ways as a demonstration of how different approaches can
 *     lead to same effective result.
 *
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;
	char letter;

	for (character_code = 97; character_code < 97 + 26; character_code++)
		putchar(character_code);
	/*
	 * Trying out an alternative way even though that's technically less efficient
	 *   than reusing character_code, thanks to Sagal teaching me that
	 *   you can also make comparisons on character sets.
	 * After some search, explanation (IIUC) is that compiler replaces
	 *   on the fly the "character letter" by its ASCII decimal value.
	 * Also using the chance to try out 'while' loop syntax.
	 */
	letter = 'A';
	while (letter <= 'Z')
		putchar(letter++);
	putchar('\n');

	return (0);
}
