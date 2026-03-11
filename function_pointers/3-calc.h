#ifndef CALC_H
#define CALC_H

/* ========== Structures and constants ========== */
/**
 * struct op - Structure associating an "arithmetic operator" string
 *   (array of char) with a function dedicated to execute
 *   the actual matching calculus.
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

/* Could use enum but not sure if allowed and not familiar with. */
/* Apparently all the "inner define" are included in the "global #ifnotdef" */
#define ERROR__INVALID_NUMBER_OF_ARGUMENTS 98 /* @warning no end ';'. */
#define ERROR__UNSUPPORTED_OPERATION       99
#define ERROR__DIVISION_BY_ZERO           100

/* ========== Functions ========== */

/* === Orchestrating functions === */

/* Checks provided operator to determine requested operation if supported. */
int (*get_op_func(char *s))(int, int);

/* === Unit functions - Arithmetic operations === */
/* Paired with string "+" (Sum). */
int op_add(int a, int b);
/* Paired with string "-" (Difference). */
int op_sub(int a, int b);
/* Paired with string "*" (Product). */
int op_mul(int a, int b);
/* Paired with string "/" (Quotient). */
int op_div(int a, int b);
/* Paired with string "%" (Remainder). */
int op_mod(int a, int b);

#endif


