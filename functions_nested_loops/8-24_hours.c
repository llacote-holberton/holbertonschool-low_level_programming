#include "main.h"

/**
 * jack_bauer - prints a day's time minute by minute.
 *
 * Description: prints every minute of a 24-hour formatted day
 *   on a single line.
 * Algorithm: we want to print something which depends on
 *   two "revolving" values with deterministic ranges
 *   (because we all know how human count time :).
 * Simplest way to do it that I see is using
 *   one loop for hour, one nested loop for minutes,
 *   and print inside of it.
 *
 * Return: ternary integer (-1, 0, 1).
 *
 */
void jack_bauer(void)
{
	int minutes;
	int hours;

	/*
	 * @note I could have defined directly the "ASCII base values" = 48
	 *   like for hour = 48; hour < (48 + 24); hour++
	 *   but for once I considered maybe the following was clearer.
	 */
	for (hours = 0; hours < 24; hours++)
	{
		for (minutes = 0; minutes < 60; minutes++)
		{
			/*
			 * I had the general idea of combining "powers" with modulo to retrieve
			 *   Nth digit but the wrong logic xd. You must *divide* and not multiply.
			 *   => Dividing by power of 10 puts every digit "I don't want"
			 *   behind the dot; thus making the digit I want
			 *   the "unit" digit so targetable by modulo.
			 */
			/* @note must compute on the fly to not erase actual variable value */
			/*
			 * @important WRONG LOGIC! We want an "extra char" EVEN for single digits.
			 * if (hour >= 10)
			 *	_putchar('0' + (hour / 10) % 10);
			 */
			_putchar((hours >= 10) ? ('0' + ((hours / 10)) % 10) : '0');
			_putchar('0' + hours % 10);
			_putchar(':');

			_putchar((minutes >= 10) ? ('0' + ((minutes / 10)) % 10) : '0');
			_putchar('0' + minutes % 10);
			_putchar('\n');
		}
	}
	/**/

}

/*
 * NOTE
 * _putchar((hours >= 10) ? ('0' + ((hours / 10)) % 10) : '0');
 * Technically works as long as I put a "fallback value",
 *   plain empty single quotes NOT accepted.
 * _putchar((minute >= 10) ? ((minute / 10)) % 10 : '');
 * Using double quotes generates an error "argument 1 of _putchar
 *   transforms a pointer into int without transtype"
 * Trying to cast it "as int" gets errors "transtyping into
 *   an int of different size"
 * _putchar((minute >= 10) ? (int) ((minute / 10) % 10) : (int) "");
 *
 */
