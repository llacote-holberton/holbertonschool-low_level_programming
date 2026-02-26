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
	/*fizz_buzz();*/

	/*
	 * Thanks to ChatGPT for making me discover the fact
	 *   that printf returns number of printed characters.
	 * Giving a precious information to use to know
	 *   whether we should print the number itself
	 *   without re-evaluating its divisions.
	 * Not sure it's actually much more efficient
	 *   in performance though.
	 *
	 */
	int current;
	int printed;

	for (current = 1; current <= 100; current++)
	{
		/*
		 * FUN FACT: printed (logically) keeps existing
		 *   at same address for whole loop so it NEEDS
		 *   to be reset at each loop start (duh me).
		 */
		printed = 0;
		printed += printf((current % 3 == 0) ? "Fizz" : "");
		printed += printf((current % 5 == 0) ? "Buzz" : "");
		if (printed == 0)
			printf("%d", current);
		printf((current != 100) ? " " : "");
	}
	printf("\n");

	return (0);
}

/*
 * After trying, thanks to printf managing "empty strings"
 *   we can go for a much more concise writing.
 * Although this time I don't try to make
 *   something "industrializable".
 */
/*
 * Method without ultimate trick from ChatGPT
 * int current;
 *
 * for (current = 1; current <= 100; current++)
 * {
 * printf((current % 3 == 0) ? "Fizz" : "");
 * printf((current % 5 == 0) ? "Buzz" : "");
 *
 * if (current % 3 != 0 && current % 5 != 0)
 * printf("%d", current);
 * printf((current != 100) ? " " : "");
 * }
 */
