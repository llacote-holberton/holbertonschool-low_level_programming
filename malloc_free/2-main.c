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

	test_low_memory();

	return (0);
}
