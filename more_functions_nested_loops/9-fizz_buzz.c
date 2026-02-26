#include "main.h"
#include <stdio.h>

/**
 * fizz_buzz -Prints the famous FizzBuzz.
 * Description: prints a continuous sequence of numbers
 *   from 1 to 100, separated with spaces
 *   BUT replacing on the fly
 *   - Every multiple of 3 by Fizz
 *   - Every multiple of 5 by Buzz
 *   - Every multiple of both by FizzBuzz.
 *
 * Return: void
 */
void fizz_buzz(void)
{
	int start;
	int end;
	int current;

	start = 1;
	end = 100;
	for (current = start; current <= end; current++)
	{
		/* @note could use chained ternaries but hard to read */
		int multiple_of_3;
		int multiple_of_5;

		multiple_of_3 = (current % 3 == 0);
		multiple_of_5 = (current % 5 == 0);

		/*
		 * Here could use chained ternaries but in the end
		 * if/else still more readable and as efficient
		 * (or maybe more because no multi-level evaluation)
		 * There is probably a more efficient way though
		 *   since technically Fizz Buzz is just the "junction"
		 *   of the unit cases 3 (Fizz) and 5 (Buzz).
		 */
		if (multiple_of_3 && multiple_of_5)
			printf("FizzBuzz");
		else if (multiple_of_5)
			printf("Buzz");
		else if (multiple_of_3)
			printf("Fizz");
		else
			printf("%d", current);
		if (current < end)
			printf(" ");
	}
	printf("\n");
}


/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	/* Original version */
	/*fizz_buzz();*/

	/*
	 * After trying, thanks to printf managing "empty strings"
	 *   we can go for a much more concise writing.
	 * Although this time I don't try to make
	 *   something "industrializable".
	 */
	int current;

	for (current = 1; current <= 100; current++)
	{
		printf((current % 3 == 0) ? "Fizz" : "");
		printf((current % 5 == 0) ? "Buzz" : "");
		/* No better way to do? */
		if (current % 3 != 0 && current % 5 != 0)
			printf("%d", current);
		printf((current != 100) ? " " : "");
	}
	printf("\n");

	return (0);
}
