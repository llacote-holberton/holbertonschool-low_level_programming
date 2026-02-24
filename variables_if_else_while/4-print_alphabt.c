#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - prints nearly whole lowercase alphabet EXCEPT 'q' and 'e'.
 * Description: prints lower-case alphbet apart from 'e' and 'q'
 *   which are skipped for no reason, poor them.
 *
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;

	for (character_code = 97; character_code < 97 + 26; character_code++)
		if (character_code != 101 && character_code != 'q')
		putchar(character_code);
	putchar('\n');

	return (0);
}
