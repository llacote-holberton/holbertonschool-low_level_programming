#include <stdio.h>

/**
 * main - Just prints program's filename.
 * @argc: number of arguments
 * @argv: array of strings which are the different arguments
 *
 * Description: prints the filename under which
 *   present code was executed.
 *
 * Return: always 0 (success).
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}
