#include "main.h"

/* @note with current definition will break at 100 */
static const int max = 14;
static const int lines = 10;
/**
 * more_numbers - Repeats 0-14 sequence on 10 lines.
 * Description: repeats printing the
 *   numbers sequence from 0 to 14 on ten lines in a row.
 * Return: void
 */
void more_numbers(void)
{
	/* Going for (I think) the cleanest version. */
	int number;
	int remaining;

	remaining = lines;
	while (remaining > 0)
	{
		for (number = 0; number <= max; number++)
		{
			if (number >= 10 && number < 100)
				_putchar(('0' + ((number / 10)) % 10));
			_putchar('0' + (number % 10));
		}
		_putchar('\n');
		--remaining;
	}
}
