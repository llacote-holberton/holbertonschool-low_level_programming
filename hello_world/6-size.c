#include <stdio.h>

/**
 * main - Shows the size in bytes of variables types.
 *
 * Description: uses sizeof to show types's size which can
 *   vary depending on target architecture at compiler time.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("Size of a char: %lu byte(s)\n",    sizeof(char));
	printf("Size of an int: %lu byte(s)\n",     sizeof(int));
	printf("Size of a long int: %lu byte(s)\n", sizeof(long int));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(long long int));
	printf("Size of a float: %lu byte(s)\n", sizeof(float));

	return (0);

}
