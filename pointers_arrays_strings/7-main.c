#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str;
	char *odd_length;

	str = "0123456789";
	/* Expected "56789" */
	puts_half(str);
	/* 15 char: 7 digits AND 8 char */
	odd_length = "1234567abcdefgh";
	/* Expected "abcdefgh" because of directive */
	/* IF odd length then print last half of (length+1) */
	puts_half(odd_length);
	return (0);
}
