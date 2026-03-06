#include <stdio.h>

/**
 * main - Just prints number of arguments provided.
 * @argc: number of arguments
 * @argv: array of strings which are the different arguments
 *
 * Description: prints the number of arguments provided
 *   when calling the program.
 * NOTE that we put aside the "always there" argument
 *   which is the first, name under which program was called.
 *
 * Return: always 0 (success).
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	/* @note we count "exploitable arguments which means        */
	/*   that we don't want to count the program's name itself. */
	printf("%d\n", argc - 1);

	return (0);
}
