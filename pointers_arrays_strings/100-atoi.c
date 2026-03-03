#include "main.h"
#include <stdio.h>
/**
 * _atoi - converts given string into an integer.
 * @s: pointer to array of characters we want to convert
 * 
 * Description: converts a string in parameter 
 *   in an integer number  (with which rules??).
 * Return: integer as converted string.
 * 
 * Special rules
 * The number in the string can be preceded by an infinite number of characters
 * You need to take into account all the - and + signs before the number            *
 * If there are no numbers in the string, the function must return 0
 * You are not allowed to use long
 * You are not allowed to declare new variables of "type" array
 * You are not allowed to hard-code special values
 * We will use the -fsanitize=signed-integer-overflow gcc flag to compile your code.
 * @note: from the examples given in the provided main we can infer that...
 *  a) ONLY the FIRST NUMBER FOUND is relevant, we can ditch others.
 *  b) We must "squash" the +- signs found "on the way" to get the final sign.
 */
int _atoi(char *s)
{
	/* Variable used to traverse the provided array */
	int cursor;
	
	int is_negative; /* Too bad we cannot use boolean */
	/* First found number with its computed sign*/
	int s_as_number;
	int is_number_finished; /* "boolean like" */

	/* 
	 * What is the goal?
	 * 1/ To parse the string UNTIL we find ONE NUMBER
	 *   (meaning sequence of digits separated by non-digit characters)
	 * 2/ To assign to it the sign resulting of all the "signs"
	 *    read along on the way (with default being no sign so positive).
	 */
	cursor = 0;
	is_negative = 0;
	s_as_number = 0;
	is_number_finished = 0;
	
	printf("String parsed: %s\n", s);
	while (s[cursor] && is_number_finished == 0)
	{
		printf("%c ", s[cursor]);
		/* How to achieve 2? */
		/* By "aternating" a "truth statement" */
		is_negative += (s[cursor] == '-') ? 1 : (s[cursor] == '+' ? -1 : 0);
		/*printf("is_negative value is %d\n", is_negative);*/
		/* FOUND the start of our number!! */
		if(s[cursor] >= '0' && s[cursor] <= '9')
		{
			while (is_number_finished == 0) 
			{
				printf("\nDigit found: %c \n", s[cursor]);
				if(s[cursor] < '0' || s[cursor] > '9')
				{
					printf("Character not a digit found: %c !!\n", s[cursor]);
					/* Not using "break;" because we want to also break the */
					/*  higher level loop so we need an info to "bubble up". */
					is_number_finished = 1;
				}
				if (! is_number_finished) cursor++;
			}
		}
		cursor++;
	}
	printf("END OF PARSE\n");
	

	return (s_as_number);
}

/*
 * VERSION 1: works but "naive" and a bit verbose.
 *
 * int cursor;
 * cursor = 0;
 * while (src[cursor])
 * {
 *   dest[cursor] = src[cursor];
 *   cursor++;
 * }
 * dest[cursor + 1] = '\0';
 * return (dest);
 */

/*
 * V2 - Smart and concise - Why and how does it work?
 * It works because...
 * a) Code directly uses the "current cursor index"
 *    to affect the value of target cell in source array
 *    inside the cell of same index in destination array.
 *    Basically we moved the "body of v1 loop"
 *      as part of the condition.
 * b) Because we put that affectation in parenthesis
 *    it becomes an expression to be evaluated.
 * c) The "evaluation" of an affectation returns
 *     the last value affected, thus the actual value
 *     that was just copied.
 * d) Because the affectation is made *before*
 *     the condition is evaluated once again,
 *     on the cycle where cell content of src is '\0'
 *     it is affected inside dest as well.
 * e) Loop exits cleanly because right *after* this affectation
 *     the first part of condition is '\0' so '\0' == '\0' -> TRUE.
 * NOTE: this is smart and concise but far less readable for
 *   unseasoned devs. Kept for reference as useful in complex codes.
 * while ((dest[cursor] = src[cursor]) != '\0')
 * cursor++;*
 * return (dest);*
 */
