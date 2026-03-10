#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees up a given 2d array.
 * @grid: double pointer targeting its 1st dimension.
 * @height: integer describing height (number of rows).
 *
 * Description: Frees up a given two-dimensional array
 *   whichever its type.
 * Return: pointer to array or NULL if fails.
 *
 */
void free_grid(int **grid, int height)
{
	/* Classic safeguard */
	if (grid == NULL)
		return;
	if (height == 0)
		return;
	/* We logically need to free memory "from inside digging up" */
	/*  because otherwise if we tried "top down" (1st level, 2nd */
	/*  etc) we wouldn't know "where" sublevels to free are.     */

	/* ALSO IMPORTANT: how to free depends on how table was created.  */
	/* If I had kept my first version which created "rows" one by one */
	/* I would have needed to make a loop to individually target each */
	/*   "pointer to row" to free the related memory area.            */
	/* Since in my 2nd version of alloc_grid I make a single alloc    */
	/*   for all rows "as a whole contiguous block" I can afford to   */
	/*   only make a single call targeting the pointer of first row   */
	/*   because (apparently, I don't fully understand why) program   */
	/*   "knows" that it's the whole area to free. */
	/* ANSWER FROM IA (yeah, shame on me): it's because a bit like    */
	/*   journalized filesystems malloc keeps a "log" of memory alloc */
	/*   "by blocks" = "at this address I've been asked to reserve    */
	/*   N bytes".                                                    */
	/*   example 0x2000  [metadata: size = 240 bytes]                 */
	/*           0x2008  ← pointeur retourné par malloc*              */
	/* So technically, only the "starting address" is needed to       */
	/*   free memory (which IIRC implies that I could wrongly)        */
	/*   "free unknown / unown" memory if I targeted random address   */
	/*   and stumbled upon an address matching the start of a block.  */
	free(grid[0]);
	/* IA Warned me also that some exercises may suppose that rows    */
	/*   have been allocated individually, and that seems to be       */
	/*   the case here. I'll see if I have to rework both codes...    */
	free(grid);
}


