# Overview

calc.out executable is made from compiling the set of 3-* files
  in order to provide a simple command-line calculator.

# Compiling
You must have gcc installed.
Compiling command is as follows.
`gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc.out`

# How to use
Run the program by going into the folder where you compiled the executable then
  type the program name followed by an integer, one of the supported operators
  (+, -, '*', '/', '%') then another integer number, ending with <Enter>.
Please pay attention to the following limitations.
1. Only integer numbers are supported.
2. Program expects exactly this syntax for its parameters:
   integer1 operator integer 2 (so exactly 3 inputs).
3. Only the aforementioned operators are supported.
4. The operators *, / and % must be enclosed in simple quotes in order to
   avoid their interpretation by your shell.

# Source structure
- 3-calc.h is the custom header holding all the functions prototypes and structures/types definitions.
- 3-main.c is the primary entry point and "orchestrator" of the process.
- 3-get_op_func.c is the "switch controller" which will determine which "command" to pass to the calculator.
- 3-op_functions.c is the file defining the actual arithmetic operations.

# Project Instructions
Write a program that performs simple operations.

## General instructions
- You are allowed to use the standard library
- Usage: calc num1 operator num2
- You can assume num1 and num2 are integers, so use the atoi function to convert them from the string input to int
- operator is one of the following:
- +: addition
- -: subtraction
- *: multiplication
- /: division
- %: modulo
- The program prints the result of the operation, followed by a new line
- You can assume that the result of all operations can be stored in an int
- if the number of arguments is wrong, print Error, followed by a new line, and exit with the status 98
- if the operator is none of the above, print Error, followed by a new line, and exit with the status 99
- if the user tries to divide (/ or %) by 0, print Error, followed by a new line, and exit with the status 100

## File specific instructions

### 3-calc.h
- Nothing special. Although the use of following template is recommended for structures definitions.
```
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

```

### 3-op_functions.c
This file should contain the 5 following functions (not more):

- op_add: returns the sum of a and b. Prototype: int op_add(int a, int b);
- op_sub: returns the difference of a and b. Prototype: int op_sub(int a, int b);
- op_mul: returns the product of a and b. Prototype: int op_mul(int a, int b);
- op_div: returns the result of the division of a by b. Prototype: int op_div(int a, int b);
- op_mod: returns the remainder of the division of a by b. Prototype: int op_mod(int a, int b);

### 3-get_op_func.c
This file should contain the function that selects the correct function to perform the operation asked by the user. You're not allowed to declare any other function.

- Prototype: int (*get_op_func(char *s))(int, int);
- where s is the operator passed as argument to the program
- This function returns a pointer to the function that corresponds to the operator given as a parameter. Example: get_op_func("+") should return a pointer to the function op_add
- You are not allowed to use switch statements
- You are not allowed to use for or do ... while loops
- You are not allowed to use goto
- You are not allowed to use else
- You are not allowed to use more than one if statement in your code
- You are not allowed to use more than one while loop in your code
- If s does not match any of the 5 expected operators (+, -, *, /, %), return NULL
- You are only allowed to declare these two variables in this function:

### 3-main.c
This file should contain your main function only.

- You are not allowed to code any other function than main in this file
- You are not allowed to directly call op_add, op_sub, op_mul, op_div or op_mod from the main function
- You have to use atoi to convert arguments to int
- You are not allowed to use any kind of loop
- You are allowed to use a maximum of 3 if statements
