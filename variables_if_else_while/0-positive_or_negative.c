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
	/*
	 * Using dedicated variables brings little value here
	 *   since very simple structure and sentences.
	 * char *positive = " is positive";
	 * char *zero     = " is zero";
	 * char *negative = " is negative";
	 */
	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive\n", n);
	else if (n < 0)
		printf("%d is negative\n", n);
	else
		printf("%d is zero\n", n);
	return (0);
}
