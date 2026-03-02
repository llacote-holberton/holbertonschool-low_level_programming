#include "main.h"
/**
 * rev_string - reverses a string "in-place".
 * @s: pointer to array of char
 * Description: fully reverse the order of characters
 *   in a string, in-place (directly modify it).
 * Return: void.
 */
void rev_string(char *s)
{
	int start; /* Used for "bottom-up" direction */
	int end;   /* Used for "top-down"  direction */
	char temp; /* Used to temporarily hold during swap */
	/*
	 * IF we start "each array" from opposite ends
	 * AND increment one while decrement the other
	 * they should "cross" without problem... I hope? xd
	 */
	start = 0;
	end = 0;
	while (s[end])
		end++;
	--end;

	/* Does it work whether lenght is even or odd? */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		--end;
		++start;
	}
}


/*
 * BRAINSTORM
 *
 * Start is the same as previous program, we need
 *  to know the "end" of array to have its length.
 * cursor = 0;
 * while (s[*cursor])
 *   cursor++;
 * --cursor;
 * Change is now. We want to "reverse"
 * Easiest way would be to fully create a new array
 *   then affect it as a full replacement directly.
 * Like (didn't test but should work)...
 *
 * char *reverse;
 * int i = 0;
 * while (cursor >=0)
 * {
 *   reverse[i] = s[cursor];
 *   ++i;
 *   --cursor;
 * }
 * while(reverse[i])
 *   s[i] = reverse[i];
 *   i++;
 * AND NOT FORGET TO "close" the string
 * s[i] = '\0';
 */
