#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(int *buffer, unsigned int size)
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
		/* printf("%d", buffer[i]); */
		i++;
	}
	printf("\n");
}

/**
 * test_minequalsmax - checks that array_range
 *   properly returns an "array of 1"
 *   containing that single number
 *
 * Return: Boolean like (0 means success).
 */
int test_minequalsmax(void)
{
	int behaviour_as_expected;
	int *array_of_1;

	printf("\n Testing behaviour for min = max.\n");
	array_of_1 = array_range(777, 777);
	/* Cannot "get size" of dynamic array         */
	/*   so need to test the value directly here. */
	if (array_of_1 == NULL || *array_of_1 != 777)
	{
		printf("Unexpected behaviour for min = max.");
		behaviour_as_expected = 1;
	}
	else
	{
		behaviour_as_expected = 0;
		simple_print_buffer(array_of_1, 1);
	}
	return (behaviour_as_expected);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int *a;

	a = array_range(0, 10);
	simple_print_buffer(a, 11);
	free(a);

	/* Custom test added */
	test_minequalsmax();

	return (0);
}
