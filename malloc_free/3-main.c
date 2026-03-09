#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/* Personal addition for "NULL" testing */
#include <sys/resource.h>
/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
	int w;
	int h;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			printf("%d ", grid[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
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
	int **oversized_table;
	unsigned int oversized = 60000;

	lim.rlim_cur = 2 * 1024 * 1024;
	lim.rlim_max = 50 * 1024 * 1024;
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");
	oversized_table = alloc_grid(oversized, oversized);
	if (oversized_table != NULL)
	{
		printf("Creation for oversized %d should have failed", oversized);
		return (1);
	}
	return (0);
}

/**
 * test_zero_parameter - checks that the new function
 *   behaves as expected when asking more memory
 *   than what is available (must return NULL).
 *
 * Return: Boolean like (0 is success).
 */
static int test_zero_parameter(void)
{
	int **table;

	table = alloc_grid(0, 666);
	if (table != NULL)
	{
		printf("Creation for height 0 should have failed.");
		return (1);
	}
	table = alloc_grid(666, 0);
	if (table != NULL)
	{
		printf("Creation for width 0 should have failed.");
		return (1);
	}

	return (0);
}

/**
 * test_negative_parameter - checks that the new function
 *   behaves as expected when asking more memory
 *   than what is available (must return NULL).
 *
 * Return: Boolean like (0 is success).
 */
static int test_negative_parameter(void)
{
	int **table;

	table = alloc_grid(-666, 777);
	if (table != NULL)
	{
		printf("Creation for NEGATIVE height should have failed.");
		return (1);
	}
	table = alloc_grid(777, -666);
	if (table != NULL)
	{
		printf("Creation for NEGATIVE width should have failed.");
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
	int **grid;

	grid = alloc_grid(6, 4);
	if (grid == NULL)
	{
		return (1);
	}
	print_grid(grid, 6, 4);
	printf("\n");
	grid[0][3] = 98;
	grid[3][4] = 402;
	print_grid(grid, 6, 4);

	test_negative_parameter();
	test_zero_parameter();
	test_low_memory();

	return (0);
}
