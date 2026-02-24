#include "main.h"

/**
 * print_last_digit - prints and returns last digit of an integer.
 * @n: Random signed integer number.
 * Description: extracts the last digit of a given number
 *   to both print and return it.
 *
 * Return: ternary integer (-1, 0, 1).
 *
 */
int print_last_digit(int n)
{
	int last_digit;

	/*
	 * Contrarily to previous project's exercise
	 *   this time apparently we do want unsigned digit.
	 */
	last_digit = _abs(n % 10);
	_putchar('0' + last_digit);
	return (last_digit);
}

/**
 * _abs - returns absolute value of an integer.
 * @n: Random signed integer number.
 * Description: exploits the sign of a given number.
 * Return: ternary integer (-1, 0, 1).
 *
 */
int _abs(int n)
{
	return ((n >= 0) ? n : n * (-1));
}
