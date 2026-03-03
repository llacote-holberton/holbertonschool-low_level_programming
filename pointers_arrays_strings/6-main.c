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

	str = "0123456789";
	/* Expected: "02468" (\n) */
	puts2(str);
	return (0);
}
