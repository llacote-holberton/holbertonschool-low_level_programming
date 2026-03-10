#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Added as requirement for RLIMIT_AS */
#include <sys/resource.h>


/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (i % 10)
		{
			printf(" ");
		}
		if (!(i % 10) && i)
		{
			printf("\n");
		}
		printf("0x%02x", buffer[i]);
		i++;
	}
	printf("\n");
}

/**
 * test_null_nmemb - checks that the new function
 *   behaves as expected when providing 0
 *   as 1st parameter.
 *
 * Return: Boolean like (0 is success).
 */
static int test_null_nmemb(void)
{
	int *should_return_null;

	should_return_null = _calloc(0, 5);
	if (should_return_null != NULL)
	{
		printf("_calloc with nmemb 0 should have returned NULL!");
		free(should_return_null);
		return (1);
	}
	return (0);
}

/**
 * test_null_size - checks that the new function
 *   behaves as expected when providing NULL string
 *   for second parameter.
 *
 * Return: Boolean like (0 is success).
 */
static int test_null_size(void)
{
	int *should_return_null;

	should_return_null = _calloc(5, 0);
	if (should_return_null != NULL)
	{
		printf("_calloc with size 0 should have returned NULL!");
		free(should_return_null);
		return (1);
	}
	return (0);
}

/**
 * test_insufficient_memory - checks that the new function
 *   behaves as expected when trying to reserve space
 *   for array beyond what's still available in memory.
 *
 * Return: Boolean like (0 is success).
 */
static int test_insufficient_memory(void)
{
	int *should_return_null;
	struct rlimit lim;
	unsigned int oversized = 60000;

	lim.rlim_cur = 2 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");

	should_return_null = _calloc(oversized, oversized);
	if (should_return_null != NULL)
	{
		printf("_calloc with oversized params should have returned NULL!");
		free(should_return_null);
		return (1);
	}
	return (0);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *a;

	a = _calloc(98, sizeof(char));
	strcpy(a, "Best");
	strcpy(a + 4, " School! :)\n");
	a[97] = '!';
	simple_print_buffer(a, 98);
	free(a);

	/* Custom added tests. */
	test_null_nmemb();
	test_null_size();
	test_insufficient_memory();

	return (0);
}
