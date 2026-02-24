#include "main.h"

/**
 * _abs - returns absolute value of an integer.
 * @n: Random signed integer number.
 * Description: tests the given number, outputs its sign (or 0 if 0)
 *   and returns value with matching sign.
 * Return: ternary integer (-1, 0, 1).
 *
 * @note it is authorized to "add a name" to a parameter in function's
 *   actual implementation prototype when not defined in header.
 *   AND required anyways if we want to use it.
 */
int _abs(int n)
{
	/*
	 * Mathematically the easiest way to get the absolute is
	 *   IF >=0 to just return it as is
	 *   OR ONLY IF to multiply it by -1 IF it is negative.
	 */
	return ((n >= 0) ? n : n * (-1));
}

