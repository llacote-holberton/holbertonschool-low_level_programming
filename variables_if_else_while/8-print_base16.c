#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the base16 characters.
 * Description: prints characters used to describe hexadecimal (base 16).
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int character_code;
	int zero_ascii;
	int a_ascii;
	int pointer;

	/*
	 * The method from before would have NOT worked since 0-9 and a-f
	 *   are NOT contiguous numbers in the ASCII correspondance table.
	 * However using an explicit char array would have.
	 * BUT I tried to find a smarter way.
	 * Ended up asking ChatGPT which proposed this, which was
	 *   hard to understand at first...
	 * Idea is basically, since 0-9 ranges from 48 to 67
	 *   THEN we need to "jump" to 97-102 for a-f,
	 *   to conditionally add a value
	 *   depending on "pointer" value.
	 * @note actually what IA suggested was smarter than my method
	 *   but mine works and I fully understand it so...
	 */
	character_code = 0;
	zero_ascii = 48;
	a_ascii = 97;

	for (pointer = 0; pointer < 16; pointer++)
	{
		if (pointer < 10)
			character_code = zero_ascii + pointer;
		else
			character_code = a_ascii + (pointer - 10);
		putchar(character_code);
	}
	putchar('\n');

	return (0);
}
