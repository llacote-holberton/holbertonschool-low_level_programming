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
 * Official command documentation
 *  https://www.ibm.com/docs/fr/i/7.6.0
 *    ?topic=functions-atoi-convert-character-string-integer
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
		/* printf("%c ", s[cursor]); */
		/* How to achieve 2? */
		/* By "aternating" a "truth statement" */
		is_negative += (s[cursor] == '-') ? 1 : (s[cursor] == '+' ? -1 : 0);
		/*printf("is_negative value is %d\n", is_negative);*/
		/* FOUND the start of our number!! */
		if(s[cursor] >= '0' && s[cursor] <= '9')
		{
			/* @note also more intuitive now that I see it: even though */
			/*   it "feels redundant" with above it is NOT as it "switches mode" */
			/*   from "simple branching" into "conditional loop". */
			/* It's also more cohesive with the functional logic  */
			/*   as it will naturally stop "before entering body again" */
			/*   as soon as the last digit will have been passed. */
			while (s[cursor] >= '0' && s[cursor] <= '9')
			{
				/*printf("\nDigit found: %c \n", s[cursor]);*/
				/* Must first use the current digit BEFORE incrementing pointer */
				s_as_number = (s_as_number * 10) + (s[cursor] - '0');
				/* printf("Number is now %d\n", s_as_number); */
				cursor++;
			}
			printf("\nFinal value of Number is: %d\n", s_as_number);
			/* Feels like the most appropriate "moment" to affect the sign. */
			/* printf("Final value of is_negative value is %d\n", is_negative); */
			if(is_negative > 0)
				s_as_number = -s_as_number;
			/* While this would technically not necessary anymore  */
			/*   if we wanted to agggregate ALL digits of a string */
			/*   as we ONLY want the FIRST complete number is is   */
			/*   still required to "end reading immediately after".*/
			is_number_finished = 1;
		}
		cursor++;
	}
	printf("END OF PARSE\n\n");
	

	return (s_as_number);
}

/* ==== SELF-LEARNING COMMENTS */
/*
 * INNER LOOP V1
 * Was "functional" BUT the way I dissociated
 *   incrementation and number construction
 *   and made the latter before the check ended up
 *   adding non digits to the number construction
 *   leading to unpredictable behaviour.
 * => It is mandatory to "tie up" number construction and
 *    cursor increment as "an atomic operation".
 * => V1.5 "wrapped both" in an ELSE counterpart to the if.
 *
 * if(s[cursor] >= '0' && s[cursor] <= '9')
 *
 * while (is_number_finished == 0)
 * {
 * if(s[cursor] < '0' || s[cursor] > '9')
 * {
 * is_number_finished = 1;
 * }
 * if (! is_number_finished) cursor++;
 *
 * Arrays are forbidden, so we must construct number
 * "sequentially".
 * Since we read from left to right, and read a character
 *   "which represents a digit" we must...
 * a)  "Push" the existing digit(s) "on the left" to free up the
 *     "unit" column, so multiply existing result by 10.
 * b) Add to that the actual value represented by the digit
 *
 * s_as_number = (s_as_number * 10) + (s[cursor] - '0');
 * printf("\nDigit found: %c \n", s[cursor]);
 * printf("Number is now %d\n", s_as_number);
 * }
 * }
 *
 * VERSION 1.5 condensed
 * if(s[cursor] >= '0' && s[cursor] <= '9')
 *
 * while (is_number_finished == 0)
 * {
 *   if(s[cursor] < '0' || s[cursor] > '9')
 *     is_number_finished = 1;
 *   else
 *   {
 *     s_as_number = (s_as_number * 10) + (s[cursor] - '0');
 *     cursor++;
 *   }
 * }
 * if (! is_number_finished) cursor++;
 */
