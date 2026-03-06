#include <stdio.h>
#include <stdlib.h> /* Required to have "string to int" utility */

/**
 * main - Prints the result of the multiplication of two numbers.
 * @argc: number of arguments
 * @argv: array of strings which are the different arguments
 *
 * Description: multiplies the two numbers provided by
 *   program call and prints the result.
 *   Warns of error if program does not receive
 *     exactly two integer numbers.
 *
 * @note we assume that user input will respect intended type
 *   aka signed number.
 *
 * Return: always 0 (success).
 */
int main(int argc, char *argv[])
{
	/* Since program name always included we must offset condition. */
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	/* Going for lazy ultra compact without even intermediate variables */
	/* BECAUSE we are not expected to check paramters's type (yet).     */
	/* So we can just use "convert to int" standard atoi() function     */
	printf("%d\n", (atoi(argv[1]) * atoi(argv[2])));

		return (0);
}
