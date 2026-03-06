#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints a provided 2d array representing chessboard.
 * @a: pointer to two-dimensional array of numbers of size 8 each dimension.
 * @size: square side's length.
 *
 * Description: finds the first occurrence of asubstring needle
 *   in the string haystack. The terminating null bytes (\0) are not compared.
 *
 * Return: pointer to char OR NULL if not found.
 *
 * NOTE: standard library use allowed here.
 * IMPORTANT We get a "flattened array" which has been filled
 * row by row. For example if array[2][2] = { {1, 2}, {10, 20}}
 *   flattened version would be 1, 2, 10, 20, 3, 30.
 *   Primary diagonal would be 1 + 20 so array[0][0] + array[1][1]
 *  and secondary 2 + 10 so array[0][1] + array[1][0]
 */
void print_diagsums(int *a, int size)
{
	int col_idx;
	int row_idx;
	int primary_diagonal_sum = 0;
	int secondary_diagonal_sum = 0;

	/* Get the sum of primary diagonal */
	/*
	 * Since i = j BUT we access flattened array
	 *   we must "jump" cells for column index to represent
	 *   "going back to the start of a new row"
	 *   so for example if we want to get the 3rd "diagonal point"
	 *   (index = 2) meaning array[2][2] in flattened it woud be
	 *   (index * n) + index.
	 */
	for (col_idx = 0; col_idx < size; col_idx++)
	{
		/* Useless inner loop since we can compute row index with column one. */
		/* Technically we could even do without this variable */
		/*   but I feel it is more readable like this. */
		row_idx = col_idx;
		primary_diagonal_sum += a[(col_idx * size + row_idx)];
	}

	/* For secondary diagonal, we use the mathematical truth  */
	/*  i + j = n - 1 to deduce the index j value j = n -1 -i */
	for (col_idx = 0 ; col_idx < size; col_idx++)
	{
		row_idx = size - 1 - col_idx;
		secondary_diagonal_sum += a[(col_idx * size + row_idx)];
	}
	/* printf("   Primary diagonal TOTAL equals %d.\n", primary_diagonal); */
	/* printf("   Secondary diagonal TOTAL equals %d.\n", secondary_diagonal); */
	printf("%d, %d\n", primary_diagonal_sum, secondary_diagonal_sum);
}

/* ======================== ALGORITHM DETAIL =========================== */
/* Write a function that prints the sum of the two diagonals             */
/*   of a square matrix of integers.  */
/* => We must identify which numbers form each of the two diagonals      */
/* => Then print the sum of each                                         */
/* First "primary" diagonal: from top left to bottom right: easy to find */
/* at least in a perfect square: points have identical coordinates       */
/* on both dimensions so i = j; */
/* For the "secondary diagonal" we have to use mathematical expression   */
/*   which states that indexes's sum is constant "across the diagonal"   */
/*   and equal to n -1 so i + j = n - 1                                  */
