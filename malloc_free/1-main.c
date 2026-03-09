#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/* Personal addition for "NULL" testing */
#include <sys/resource.h>

/**
 * test_low_memory - checks that the new function
 *   behaves as expected when asking more memory
 *   than what is available (must return NULL).
 *
 * Return: Boolean like (0 is success).
 */
static int test_low_memory(void)
{
	/* Personal addition to test malloc failure */
	struct rlimit lim;
	char *oversized_source;
	char *oversized_copy;
	unsigned int oversized = 100000;
	unsigned int i;
	/* End personal addition */

	lim.rlim_cur = 1 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");
	oversized_source = (char *)malloc(oversized);
	if (!oversized_source)
	{
		perror("malloc failed");
		printf("Couln't check behaviour, not enough memory.\n");
		return (1);
	}
	else
		for (i = 0; i < oversized; i++)
			oversized_source[i] = 'a';
	oversized_copy = _strdup(oversized_source);
	free(oversized_source);
	if (oversized_copy != NULL)
	{
		printf("Oversized copy happened, was supposed to fail for lack of memory.");
		return (1);
	}
	else
	{
		printf("Oversized copy of %d char failed not enough memory! \n", oversized);
		printf("String duplication behaviour CONFORM for oversized string.\n");
		return (0);
	}
}

/**
 * test_empty_source - checks that the new function
 *   behaves as expected when giving empty string
 *   (should work as it is a valid case).
 * Return: Boolean like (0 is success).
 */
static int test_empty_source(void)
{
	char *empty_string = "";
	char *copy = _strdup(empty_string);
	int length;

	/* Test case failed, should have copied. */
	if (copy == NULL)
		return (1);
	while (copy[length++] != '\0')
	;
	/* Test case failed, should be only 1 char (EOL)*/
	if (length != 1 || copy[length] != '\0')
		return (1);
	printf("String duplication behaviour CONFORM for empty string.\n");
	return (0);
}

/**
 * test_null_source - checks that the new function
 *   behaves as expected when giving "NULL" source
 *   (should return NULL as well).
 * Return: Boolean like (0 is success).
 */
static int test_null_source(void)
{
	char *null_string = NULL;
	char *copy = _strdup(null_string);

	if (copy != NULL)
		return (1);
	printf("String duplication behaviour CONFORM for NULL string.\n");
	return (0);
}



/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s;

	s = _strdup("Duplicated");
	if (s == NULL)
	{
		printf("failed to allocate memory\n");
		return (1);
	}
	printf("%s\n", s);
	free(s);

	/* Personal custom test cases */
	test_low_memory();
	test_empty_source();
	test_null_source();

	return (0);
}
