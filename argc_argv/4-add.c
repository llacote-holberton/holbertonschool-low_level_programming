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
 * Return: 0 (success) or 1 (error).
 *
 * @note we assume that user input will respect intended type
 *   aka signed number.
 *
 * ----  ADDITIONAL INFORMATION
 * Write a program that adds positive numbers.
 *    Print the result, followed by a new line
 *    If no number is passed to the program, print 0, followed by a new line.
 *    If one of the number contains symbols that are not digits,
 *      print Error, followed by a new line, and return 1.
 *    You can assume that numbers and the addition of all the numbers
 *      can be stored in an int.
 *
 *
 */
int main(int argc, char *argv[])
{
	int sum_result = 0;
	int error_found = 0;
	int i; /* Argument index */
	int c; /* Character comparator index */

	if (argc - 1 == 0) /* No need to do anything if no args */
		printf("0\n");
	else
	{
		for (i = 1; error_found == 0 && i < argc; i++)
		{
			for (c = 0; argv[i][c] != '\0'; c++)
			{
				if (argv[i][c] < '0' || argv[i][c] > '9')
				{
					error_found = 1;
					break;
				}
			}
			if (!error_found)
				sum_result += atoi(argv[i]);
		}
	}
	if (error_found)
		printf("Error\n");
	else
		printf("%d\n", sum_result);

	return (error_found);
}

/* I'd like to make an array of int to directly   */
/*   convert and store each "validated parameter" */
/*   but not confident enough yet. I'll try once  */
/*   I have a "passing solution". */
