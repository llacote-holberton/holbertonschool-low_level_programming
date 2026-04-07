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
	res = append_text_to_file(av[1], av[2]);
	printf("-> %i)\n", res);

	printf("Appending on file with name from CLI argument: %s", av[1]);
	printf("   \n and content as follows:\n---\n %s\n---\n", av[2]);
	res = append_text_to_file(av[1], av[2]);
	printf("  -> Expected return code: depends. Actual: %i.\n", res);

	printf("Appending to file with no content: %s.\n", "test_Emptyfile");
	res = append_text_to_file("tests/test_Emptyfile", NULL);
	printf("  -> Return code: Expected? 1. Actual? %i.\n", res);

	printf("Trying append on file but no filename provided.\n");
	res = append_text_to_file(NULL, "No filename provided");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	printf("Trying append on unaccessible file 'test_ForbiddenAccess'.\n");
	res = append_text_to_file("test_ForbiddenAccess", "Unauthorized (octal 000)");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	printf("Trying append on unwritable file 'test_ReadonlyFile'.\n");
	res = append_text_to_file("test_ReadonlyFile", "Unauthorized (octal 400)");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	printf("Trying append on file in non-existing subdir.\n");
	res = append_text_to_file("tests/subdir/burrowedfile", "Deep inside tree!");
	printf("  -> Return code: Expected? -1. Actual? %i.\n", res);

	return (0);
}
