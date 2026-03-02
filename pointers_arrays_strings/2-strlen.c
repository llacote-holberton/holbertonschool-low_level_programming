/*#include <stdio.h>*/
/**
 * _strlen - counts and returns length of given string.
 * @s: string (array of n char).
 * Description: determines the length of string.
 * @note Method of dividing array's total byte size
 *   by the size a single char takes CANNOT WORK HERE
 *   BECAUSE an array is NEVER given as is as function parameter,
 *   even if "written as is" (like (char myarray[]))
 *   IT WILL ALWAYS be transformed into a pointer.
 *   => Information on size/length is lost SO
 *      NO OTHER WAY than to parse the array
 *      whatever the method chosen to calculate length.
 * Return: integer.
 */
int _strlen(char *s)
{
	/*
	 * @note must use one of the methods given from
	 * https://www.geeksforgeeks.org/c
	 *   /c-program-to-print-the-length-of-a-string-using-pointers/
	 */

	/* The most intuitive for me to "reinvent" is counting */
	/*   by moving pointer in array until I find the '\0'  */

	int str_length;
	/* Still required to "hop" from char to char in array. */
	int char_size;
	/* @note defining a pointer of pointer to keep the original. */
	char *cursor;

	cursor = s;
	char_size = sizeof(char);
	str_length = 0;

	while (*cursor != '\0')
	{
		++str_length;
		cursor += char_size;
	}
	/* printf("Cursor string is %s\n", cursor); */
	/* printf("Cursor char is %c\n", *cursor); */
	/* printf("Char size is %d byte(s)\n", char_size); */
	/* printf("Length is counted at %d\n", str_length); */

	return (str_length);
}

/*
 * PUT OUTSIDE FUNCTION because Betty counts comment lines
 *   in a function's body :/
 * @important CANNOT WORK because we only have a pointer
 *   so we simply cannot access "the array as a whole".
 * int char_size;
 * int length;
 * char_size = sizeof(char);
 * printf("Char size in bytes is %d\n", char_size);
 * printf("String is %s\n", s);
 * length = (sizeof(s) / sizeof(char_size));  -> Returns 2
 * length = (sizeof(*s) / sizeof(char_size)); -> Returns 0
 * printf("Length is %d\n", length);
 */
