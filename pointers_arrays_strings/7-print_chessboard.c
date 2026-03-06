#include "main.h"
#define NULL ((void *)0)

/**
 * print_chessboard - prints a provided 2d array representing chessboard.
 * @a: pointer to two-dimensional array of numbers of size 8 each dimension.
 *
 * Description: finds the first occurrence of asubstring needle
 *   in the string haystack. The terminating null bytes (\0) are not compared.
 *
 * Return: pointer to char OR NULL if not found.
 *
 */
void print_chessboard(char (*a)[8])
{
	int board_side = 8;
	int column_number;
	int row_number;

	for (column_number = 0; column_number <  board_side; column_number++)
	{
		for (row_number = 0; row_number < board_side; row_number++)
			_putchar(a[column_number][row_number]);
		_putchar('\n');
	}
}
