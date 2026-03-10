#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

/**
 * test_null_host - checks that the new function
 *   behaves as expected when providing NULL string
 *   as first parameter.
 *
 * Return: Boolean like (0 is success).
 */
static bool test_null_host(void)
{
	char *null_host = NULL;
	char *concat_with_null_host;
	char *standard = "I'm a string and I'm tight!";
	size_t copy_length = (size_t)strlen(standard);

	concat_with_null_host = string_nconcat(null_host, standard, copy_length);

	return ((bool)(copy_length == strlen(concat_with_null_host)));
}

/**
 * test_null_append - checks that the new function
 *   behaves as expected when providing NULL string
 *   for second parameter.
 *
 * Return: Boolean like (0 is success).
 */
static int test_null_append(void)
{
	char *null_append = NULL;
	char *concat_with_null_append;
	char *standard = "I'm a string and I'm tight!";
	size_t copy_length = (size_t)strlen(standard);
	concat_with_null_append = string_nconcat(standard, null_append, copy_length);
	/* Technically bad practice because I must keep the variable until return */
	/*   so I cannot free it beforehand? */
	return ((bool)(copy_length == strlen(concat_with_null_append)));

}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *concat;

	concat = string_nconcat("Best ", "School !!!", 6);
	printf("%s\n", concat);
	free(concat);

	if (! test_null_host())
		printf("Concat with null host should have worked but failed.");
	if (! test_null_append())
		printf("Concat with null append should have worked but failed.");
	
	return (0);
}
