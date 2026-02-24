#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints lower-case alphabet in reverse order.
 * Description: prints the lower-case ASCII alphabet in reverse order.
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;

	for (character_code = 122; character_code > 122 - 26; character_code--)
		putchar(character_code);
	putchar('\n');

	return (0);
}
