#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 * @ac: number of command line arguments.
 * @av: list of the provided arguments themselves.
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	ssize_t n;

	if (ac != 2)
	{
		/* File Requiescat has 468 characters in total. */
		dprintf(2, "Usage: %s filename\n", av[0]);
		exit(1);
	}
	printf("\n=== STARTING TESTS (which expect file with max 1000 chars) ===\n");
	/* Try to read 0 characters (should return 0). */
	printf("\nTry to read 0 chars.\n");
	n = read_textfile(av[1], 0);
	printf("(n should be 0): %li\n\n", n);
	/* Try to read 114 chars (source big enough) should return 114. */
	n = read_textfile(av[1], 114);
	printf("(Tried reading 114 -> n equals: %li)\n", n);
	/* Try to read 1024 chars (beyond source size) should return 468. */
	n = read_textfile(av[1], 1024);
	printf("\n(Tried reading 1024 char -> should be file max: %li)\n\n", n);
	/* Try to read 2000 characters (over source size). */
	n = read_textfile(av[1], 2000);
	printf("\n(Tried reading 2000 chars, n should be file max: %li)\n\n", n);

	/* Try to read NULL file (should return 0). */
	n = read_textfile(NULL, 100);
	printf("\n(read from non-existent file -> should be 0): %li\n\n", n);
	/* Try to read Non-existing file (should return 0). */
	n = read_textfile("file_does_not_exist.txt", 100);
	printf("\n(read from non-existent file -> should be 0): %li\n\n", n);

	return (0);
}
