#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	printf("Testing 1, should return 0 (NOT a prime)\n");
	r = is_prime_number(1);
	printf("%d\n", r);

	printf("Testing 1024, should return 0 (NOT a prime)\n");
	r = is_prime_number(1024);
	printf("%d\n", r);

	printf("Testing 16, should return 0 (NOT a prime)\n");
	r = is_prime_number(16);
	printf("%d\n", r);

	printf("Testing 17, should return 1 (PRIME)\n");
	r = is_prime_number(17);
	printf("%d\n", r);

	printf("Testing 25, should return 0 (NOT a prime)\n");
	r = is_prime_number(25);
	printf("%d\n", r);

	printf("Testing -1, should return 0 (NOT a prime)\n");
	r = is_prime_number(-1);
	printf("%d\n", r);

	printf("Testing 113, should return 1 (PRIME)\n");
	r = is_prime_number(113);
	printf("%d\n", r);

	printf("Testing 7919, should return 1 (PRIME)\n");
	r = is_prime_number(7919);
	printf("%d\n", r);

	return (0);
}
