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
	char *characters_set;
	int set_size;
	int pointer;
	/*
	 * Method 1 which would definitely work
	 * @note mixing both writings to stress that compiler
	 *   converts letter in its decimal ASCII value
	 * int character_code;
	 *
	 * for (character_code = 97; character_code < 97 + 26; character_code++)
	 * if(character_code != 101 && character_code != 'q')
	 * putchar(character_code);*
	 */
	/* Method 2 which is probably less efficient, but just for fun */
	characters_set = "abcdfghijklmnoprstuvwxyz";
	set_size = (int) strlen(characters_set);
	/* @note storing length in a variable to avoid redundant calls in loop */
	/* @note requires casting into int because strlen gives a size_t type value */
	for (pointer = 0; pointer < set_size; pointer++)
		putchar(characters_set[pointer]);
	putchar('\n');
	return (0);
}
