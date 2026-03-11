#include <stdlib.h> /* Used for constants */
#include <stdio.h>  /* Used for printing to user screen */
#include <string.h> /* Used for string search and convertion */
#include "3-calc.h" /* Calculator custom functions */

/**
 * main - Brain of the calculator program.
 * @argc: int - "Built-in" counter of provided arguments (program name = 1st)
 * @argv: char[] - "Built-in" array of strings containing
 *   all recognized arguments (separator being space by default).
 *
 * Description: Parses input, asks which operation to make
 *   to get_op_func and calls resulting one.
 *
 * Return: int as...
 *  1) Normal process would just print result then "return 0" by convention.
 *  2) We arbitrarily use exit with integers to report failures explicitely.
 *     @fixme define constants for error codes.
 */
int main(int argc, char **argv) /* could have written *argv[] */
{
	/* @note could have used argv[x] directly but feels more readable */
	/*   to use dedicated variables to hold provided arguments. */
	int num1;
	int num2;
	char operator;
	char *error_msg = "Error\n";
	char *valid_operators = "-+*/%";

	/* Stop immediately if number of arguments isn't exactly 4: */
	/* program name "built-in" PLUS "actual arguments" being    */
	/* first number, operator and second number. */
	if (argc != 4)
	{
		printf("%s", error_msg);
		exit(98);
	}

	/* Check operator is valid otherwise useless to pursue. */
	/* Reminder: *argv[2] == argv[2][0] == **(argv + 2) giving CHAR */
	/*   argv[2] == *(argv + 2) giving STRING */
	operator = (char)argv[2][0]; /* Don't forget string is array itself! */
	/* I find this cleaner than a if with chain of OR inside */
	/* @warning re-reading directives: probably supposed to be done in get_op. */
	if (strchr(valid_operators, operator) == NULL)
	{
		printf("%s", error_msg);
		exit(99);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	printf("Expression provided: %d %c %d.\n", num1, operator, num2);

	/* Are left a) finding right function to call b) calling it    */
	/* c) print result if ok, exit with right error codes if NULL. */

	return (0);
}


/*
 * ===== MAIN FILE =====
 * Content and coding restrictions
 * - You are not allowed to code any other function than main in this file
 * - You are not allowed to directly call from the main function any of
 *   op_add, op_sub*, op_mul, op_div or op_mod functions.
 * - You have to use atoi to convert arguments to int
 * - You are not allowed to use any kind of loop
 * - You are allowed to use a maximum of 3 if statements
 *
 * => This time we don't maintain the interface with user active
 *   until quitting, it's just a "one-time execution" .
 *
 * -- Additional information on behaviour --
 * The program prints the result of the operation, followed by a new line
 * You can assume that the result of all operations can be stored in an int
 * If number of arguments is wrong,
 *   print Error with new line then exit with the status 98.
 * if operator is none of the above,
 *   print Error with new line then exit with the status 99.
 * if user tries to divide (/ or %) by 0,
 *   print Error with new line then exit with the status 100.
 */
