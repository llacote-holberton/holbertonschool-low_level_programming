#include "main.h"
#include <stdlib.h>
/* @Comment before commit */
#include <stdio.h>
/**
 * alloc_grid - initializes a 2d array of 0 digits.
 * @width: integer describing width of 2d array.
 * @height: integer describing height of 2d array.
 *
 * Description: Creates a two-dimensional array of integers
 *   filled with 0.
 * Return: pointer to array or NULL if fails.
 *
 */
int **alloc_grid(int width, int height)
{
	int **integers_table;
	int i, j; /* Filler iterators */
	/* Guard clause because invalid "input" for process. */
	if (!(width > 0) || !(height > 0))
		return (NULL);

	/* Initializing the first dimension which is "height"! */
	/* BEWARE of SizeOF's type! NOT 'int' BUT 'int*'   */
	integers_table = (int **)malloc(height * sizeof(int *));
	/* Guard against insufficient memory on 1st dimension */
	if (integers_table == NULL)
		return (NULL);
	/* Better to allocate all data space in one go but. */
	/*   I don't fully understand the logic yet. */
	/* int *blocks; */
	/* blocks = (int*)malloc(height * width * sizeof(int)); */
	/* THIS I understand fully now. */
	for (i = 0; i < height; i++)
	{
		/* We must create the blocks*/
		integers_table[i] = (int *)malloc(width * sizeof(int));
		if (integers_table[i] != NULL)
			for (j = 0; j < width; j++)
				integers_table[i][j] = 0;
	}
	/* Problem of this is... We can have a "partial table" */
	/* Initialized for nothing as we "fail at some point". */

	return (integers_table);
}

/*
 * int **new_array;
 * int total_elements;
 * int i, j;
 * if (!(width > 0) || !(height > 0))
 *   return (NULL);
 * total_elements = width * height;
 * printf("Total elements is %d.\n", total_elements);
 * new_array = (int **)malloc(total_elements * sizeof(int));
 * if (new_array != NULL)
 * for (i = 0; i < width; i++)
 *   for (j = 0; j < height; j++)
 *   {
 *     printf("Filling cell x = %d, y = %d. \n", i, j);
 *     new_array[i][j] = 0;
 *   }
 * WILL PRODUCE SEGMENTATION FAULT.
 * LOGICALLY: because this code...
 * 1/ Didn't initialize the column's "adresses"
 *    (those are pointers so they each must have
 *     "their own dedicated memory") and couldn't precise
 *    that the first level is "composed of pointers to integers".
 * 2/ Because no "structure" system was targeting random addresses.
 * => There simply is no way to "allocate all dimensions at once".
 * 3/ ON TOP OF THAT I was mixing up data and pointers...
 *  POINTERS (columns) NEED THEIR OWN SPACE to store blocks (width) !!!
 */
