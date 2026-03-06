#include <stdio.h>

/**
 * main - Re-prints all received arguments line per line.
 * @argc: number of arguments
 * @argv: array of strings which are the different arguments
 *
 * Description: prints all on-call received arguments
 *   one per line.
 *
 * Return: always 0 (success).
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
