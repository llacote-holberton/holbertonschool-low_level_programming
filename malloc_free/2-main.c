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
	char *oversized_s1;
	char *oversized_s2;
	char *oversized_fuse;
	unsigned int oversized = 100000;
	unsigned int i;
	/* End personal addition */
	char *s;

	s = str_concat("Best ", "School");
	if (s == NULL)
	{
		printf("failed\n");
		return (1);
	}
	printf("%s\n", s);
	free(s);

	lim.rlim_cur = 1 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");
	oversized_s1 = (char *)malloc(oversized);
	oversized_s2 = (char *)malloc(oversized);

	if (!oversized_s1 || !oversized_s2)
		return (1);
	else
		for (i = 0; i < oversized; i++)
		{
			oversized_s1[i] = 'a';
			oversized_s2[i] = 'z';
		}
	oversized_fuse = str_concat(oversized_s1, oversized_s2);
	if (oversized_fuse == NULL)
		printf("Oversized copy of %d char failed not enough memory! \n", oversized);
	return (0);
}
