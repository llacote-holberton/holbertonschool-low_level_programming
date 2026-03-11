/* This file should hold (only) the functions */
/*   actually doing the arithmetic operations. */

/**
 * op_add - Returns sum of two provided integer addends.
 * @a: int - First addend.
 * @b: int - Second addend.
 *
 * Return: integer.
 * Note: paired with "+" string operator.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Returns difference of a (minuend) and b (subtrahend).
 * @a: int - Minuend (number to substract from).
 * @b: int - Substrahend (number to be subtracted).
 *
 * Return: integer.
 * Note: paired with "-" string operator.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Returns product of two provided integer factors.
 * @a: int - First factor.
 * @b: int - Second factor.
 *
 * Return: integer.
 * Note: paired with "*" string operator.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Returns quotient of a (dividend) and b (divisor).
 * @a: int - Dividend.
 * @b: int - Divisor.
 *
 * Return: integer.
 * Note: paired with "/" string operator.
 */
int op_div(int a, int b)
{
	/* @warning MUST BE TAKEN CARE OF "UPSTREAM" */
	/*   (in get_op_func) as... */
	/* Directives impose program to return NULL then exit */
	/* BUT we declare prototype as returning int */
	/* BUT NULL is not int it's void. */
	/* if (b == 0) return (NULL); */
	return (a / b);
}

/**
 * op_mod - Returns remainder of a (dividend) and b (divisor).
 * @a: int - Dividend.
 * @b: int - Divisor.
 *
 * Return: integer.
 * Note: paired with "%" string operator.
 */
int op_mod(int a, int b)
{
	/* Confer above comment */
	/* if (b == 0) return (NULL); */
	return (a % b);
}
