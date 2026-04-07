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
	int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s filename text\n", av[0]);
		exit(1);
	}
	printf("\n======= START TESTS =======\n");
	printf("---- Reminder: code returns 1 on success, -1 on failure ----\n");
	printf("---- WARNING: a writable 'tests' sub-directory must exist. ----\n");

	printf("Creating file with name from CLI argument: %s", av[1]);
	printf("   \n and content as follows:\n---\n %s\n---\n", av[2]);
	res = create_file(av[1], av[2]);
	printf("  -> Expected return code: depends. Actual: %i.\n", res);

	printf("(Re)creating file with no content: %s.\n", "test_Emptyfile");
	res = create_file("tests/test_Emptyfile", NULL);
	printf("  -> Return code: Expected? 1. Actual? %i.\n", res);

	printf("Creating/truncating file but no filename provided.\n");
	res = create_file(NULL, "No filename provided");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	printf("Trying to affect file 'test_ForbiddenAccess' (no permission).\n");
	res = create_file("test_ForbiddenAccess", "Unauthorized (octal 000)");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	printf("Creating/truncating file in non-existing subdir.\n");
	res = create_file("tests/subdir/burrowedfile", "Deep inside the tree!");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	return (0);
}
