#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - says whether stored number is positive or negative.
 * Description: determines the "signed range" of a n variable.
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	int n;
	int last_digit;
	char *text;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* @note needs to get "absolute value" to stay within exercise's frame. */
	last_digit = n % 10;
	if (last_digit == 0)
		text = "and is 0";
	else if (last_digit <= 5)
		text = "and is less than 6 and not 0";
	else
		text = "and is greater than 5";
	/* Beware format choice, using "%u" leads to incoherent display. */
	printf("Last digit of %d is %d %s\n", n, last_digit, text);

	return (0);
}
