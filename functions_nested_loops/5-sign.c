#include "main.h"

/**
 * print_sign - outputs and returns something depending on input number's sign.
 * @n: Random signed integer number.
 * Description: tests the given number, outputs its sign (or 0 if 0)
 *   and returns value with matching sign.
 * Return: ternary integer (-1, 0, 1).
 */
int print_sign(int n)
{
	/*
	 * Method 2 which uses a switch (my initial goal)
	 *   but with a twist which I honestly wouldn't have thought alone
	 */
	int eval_result;
	/*
	 * @note this is the nice trick to affect a result variable in a oneliner.
	 * BECAUSE we exactly want it to have either -1, 0 or 1
	 *   (otherwise this wouldn't work).
	 * Basically we make a substraction, on the fly,
	 *   of the result of two separate evaluations which each
	 *   will return either 1 (true) or 0 (false).
	 * Order of evaluations and choice of operator are
	 *   intimately correlated if we want to return 1 for positive numbers.
	 */
	eval_result = (n > 0) - (n < 0);
	switch (eval_result)
	{
		case 1:
			_putchar('+');
			break;
		case 0:
			_putchar('0');
			break;
		case -1:
			_putchar('-');
	}
	return (eval_result);
}


/*
 * Method 1, works but basic and verbose
 * if (n > 0)
 * {
 * putchar('+');
 * return (1);
 * }
 * else if (n == 0)
 * {
 * _putchar('0');
 * return (0);
 * }
 * else
 * {
 * _putchar('-');
 * return (-1);
 * }
 */
