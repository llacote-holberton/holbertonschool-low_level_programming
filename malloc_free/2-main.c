#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/* Personal addition for "NULL" testing */
#include <sys/resource.h>
#include <string.h>

/**
 * test_empty_strings - checks that the new function
 *   behaves as expected when giving empty string
 *   (should work as it is a valid case).
 * Return: Boolean like (0 is success).
 */
static int test_empty_strings(void)
{
	char *empty_s  = "";
	char *filled_s = "I should be there.";
	char *concat_s1_empty = str_concat(empty_s, filled_s);
	char *concat_s2_empty = str_concat(filled_s, empty_s);
	char *concat_all_empty = str_concat(empty_s, empty_s);

	/* Test case failed, should have copied. */
	if (concat_s1_empty == NULL || strcmp(concat_s1_empty, filled_s) != 0)
	{
		printf("Test concatenating with empty string as first parameter failed.\n");
		return (1);
	}
	if (concat_s2_empty == NULL || strcmp(concat_s2_empty, filled_s) != 0)
	{
		printf("Test concatenating with empty string as second parameter failed.\n");
		return (1);
	}
	if (concat_all_empty == NULL || strcmp(concat_all_empty, "") != 0)
	{
		printf("Test concatenating with only empty strings failed.\n");
		return (1);
	}
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
	char *null_s  = NULL;
	char *filled_s = "I should be there.";
	char *concat_s1_null = str_concat(null_s, filled_s);
	char *concat_s2_null = str_concat(filled_s, null_s);
	char *concat_all_null = str_concat(null_s, null_s);

	/* Test case failed, should have copied. */
	if (concat_s1_null == NULL || strcmp(concat_s1_null, filled_s) != 0)
	{
		printf("Test concatenating with NULL string as first parameter failed.\n");
		return (1);
	}
	if (concat_s2_null == NULL || strcmp(concat_s2_null, filled_s) != 0)
	{
		printf("Test concatenating with NULL string as second parameter failed.\n");
		return (1);
	}
	if (concat_all_null == NULL || strcmp(concat_all_null, "") != 0)
	{
		printf("Test concatenating with only NULL strings failed.\n");
		return (1);
	}
	return (0);
}




/**
 * test_low_memory - checks that the new function
 *   behaves as expected when asking more memory
 *   than what is available (must return NULL).
 *
 * Return: Boolean like (0 is success).
 */
static int test_low_memory(void)
{
	struct rlimit lim;
	char *oversized_s1;
	char *oversized_s2;
	char *oversized_fuse;
	unsigned int oversized = 60000;
	unsigned int i;

	lim.rlim_cur = 2 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");
	oversized_s1 = (char *)malloc(oversized);
	oversized_s2 = (char *)malloc(oversized);

	/* Guard clause with early return so ELSE not needed. */
	if (!oversized_s1 || !oversized_s2)
	{
		printf("Couldn't allocate memory for either Oversized 1 or Oversized 2.\n");
		return (1);
	} /* else */
	for (i = 0; i < oversized; i++)
	{
		oversized_s1[i] = 'a';
		oversized_s2[i] = 'z';
	}
	oversized_fuse = str_concat(oversized_s1, oversized_s2);
	free(oversized_s1);
	free(oversized_s2);
	if (oversized_fuse == NULL)
	{
		printf("Oversized copy of %d char failed, not enough memory! \n", oversized);
		return (1);
	}
	else /* Not strictly required but more readable IMO. */
	{
		free(oversized_fuse);
		return (0);
	}
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s;

	s = str_concat("Best ", "School");
	if (s == NULL)
	{
		printf("failed\n");
		return (1);
	}
	printf("%s\n", s);
	free(s);

	test_empty_strings();
	test_null_source();
	test_low_memory();

	return (0);
}
