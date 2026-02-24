#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the sequence of digits in a readable way.
 * Description: prints the sequence of digits separated by ', '.
 * Return: always 0 whatever resulting output is.
 */
int main(void)
{
	/* Using while for a change */
	int digit;

	digit = 0;
	while (digit <= 9)
	{
		putchar(digit + 48);
		if (digit < 9)
		{
			putchar(',');
			putchar(' ');
		}
		digit++;
	}

	return (0);
}
