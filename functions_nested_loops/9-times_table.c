#include "main.h"

/**
 * times_table - prints the multiplication tables.
 *
 * Description: prints the multiplication tables
 *   from 0 to 9,
 *   one line for each value of first operande,
 *   starting with 0.
 * Algorithm
 *   - One loop taking care of each line
 *   - One loop taking care of within line maths.
 *   - Dedicated function for printing computations.
 *   - Dedicated function for printing line
 * @note choosing to add extra functions to keep
 *   the nested loops concise therefore readable.
 * Return: void
 */
void times_table(void)
{
	int base;
	int multiplier;
	int result;
	int limit;

	/*
	 * @note: could have put the "0 table"
	 * outside of loop for better perf (avoid some tests)
	 *   but would have created redundant code.
	 * Since it would only make a difference for millions of ops
	 *   (I think), I go for the more readable approach.
	 */
	/* Added mid-dev to have a way to know "end of line" */
	limit = 9;
	for (base = 0; base <= limit; base++)
	{
		/*
		 * @essential! Only way to have "conditional print of separator"
		 *   without hardcoding the condition is
		 *   NOT "print separator after number except for last of line"
		 *   BUT "print separator BEFORE number EXCEPT for the FIRST of line."
		 */
		_putchar('0');
		/* _putchar(','); */
		/** For now we write all in, we'll report later in functions */
		for (multiplier = 1; multiplier < 10; multiplier++)
		{
			result = (base == 0 || multiplier == 0) ? 0 : base * multiplier;
			if (multiplier > 0)
				_putchar(',');
			print_number(result);
			/* @note very brittle, hardcodes the function limit!!*/
			/*
			 * if (multiplier != limit)
			 * _putchar(',');
			 */
		}
		_putchar('\n');
	}
}

/**
 * print_number - prints positive numbers < 100.
 * @number: positive integer to print.
 * Description: prints positive numbers inferior to 100
 *   padded onto 3 characters, and returns it in case of.
 * Return: void.
 */
void print_number(int number)
{
	/* Count digits, stupid brittle style */
	/*
	 * Kept to remind me of thinking BEFORE writing. xd
	 * int spacing;
	 * if (number < 10)
	 * spacing = 2;
	 * else if (number < 100)
	 * spacing = 1;
	 * else
	 * spacing = 0;
	 * _putchar(' ');
	 * while (spacing > 0)
	 * {
	 * _putchar(' ');
	 * spacing--;
	 * }
	 */
	/* Prints "hundreds digit" (always space since under 100) */
	_putchar(' ');
	/* Prints "tens digit" (always space since under 100) */
	_putchar((number >= 10) ? ('0' + ((number / 10)) % 10) : ' ');
	/* Prints "ones digit" (always space since under 100) */
	_putchar('0' + (number  % 10));

}
