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

	/**
	 * Method 1, works but basic and verbose
	 */
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}


}
