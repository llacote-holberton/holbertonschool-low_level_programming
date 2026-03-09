#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/* Personal addition for "NULL" testing */
#include <sys/resource.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	/* Personal addition to test malloc failure */
	struct rlimit lim;
	char *oversized_source;
	char *oversized_copy;
	unsigned int oversized = 100000;
	unsigned int i;
	/* End personal addition */
	char *s;

	s = _strdup("Duplicated");
	if (s == NULL)
	{
		printf("failed to allocate memory\n");
		return (1);
	}
	printf("%s\n", s);
	free(s);

	lim.rlim_cur = 1 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");
	oversized_source = (char *)malloc(oversized);
	if (!oversized_source)
	{
		perror("malloc failed");
		return (1);
	}
	else
		for (i = 0; i < oversized; i++)
			oversized_source[i] = 'a';
	oversized_copy = _strdup(oversized_source);
	if (oversized_copy == NULL)
		printf("Oversized copy of %d char failed not enough memory! \n", oversized);
	return (0);
}
