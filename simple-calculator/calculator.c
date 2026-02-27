#include <stdio.h>
/* Custom functions definition*/

/**
 * ui_display_menu - Renders primary menu.
 * Description: displays the "primary" menu
 *   allowing user to choose operation to run
 *   or to exit program.
 * Return: int (0 = success)
 */
int ui_display_menu(void)
{
	const char *welcome = "\n=== Welcome to this simple calculator! ;) ===\n";
	/*
	 * Using an array because seems the most logical for a
	 *   "set" of values which we know we will iterate over.
	 * Making it a constant because it has no meaning allowing it
	 *   to be modified (imo).
	 * Using a "pointers" array instead of "2d array"
	 *   because seems better practice for strings of varying length.
	 * Confer https://www.geeksforgeeks.org/c/array-of-strings-in-c/
	 * @note different syntax than other languages!!!
	 *   MUST (IIUC) specify * AND [] AND use {} for content!
	 */
	const char *menu_items[] = {
		/* @note probably smarter way to store with nested array. */
		"Simple Calculator",
		"1) Add",
		"2) Subtract",
		"3) Multiply",
		"4) Divide",
		"0) Quit"
	};

	/* @note does not know for how how to get array size */
	const int menu_lines = 6;
	int i;

	printf("%s", welcome);
	for (i = 0; i < menu_lines; i++)
		printf("%s\n", menu_items[i]);

	return (0);
}


/**
 * check_menu_choice - Grabs & validate user input
 * @note for now no parameter identified
 * Description: grabs user_input and checks
 *   it is of expected type.
 * Return: int (-1 = error, as 0 can be a valid input here)
 */
int check_menu_choice(void)
{
	/*
	 * @note had thought of adding a "modes" parameter
	 *   to cover both cases of "choosing menu option"
	 *   and "providing numbers to compute"
	 *   but in fact it's easier and possibly cleaner
	 *   to just make two separate functions.
	 * int check_user_input(char *mode) {}
	 * const *modes = { "operation", "operandes" };
	 */
	/* https://www.geeksforgeeks.org/c/scanf-in-c/ */
	/*
	 * Needs to have a variable declared to "store" the input.
	 * Defined as an "int" type because the functional scope of
	 *   our program is limited to "choosing action with a digit"
	 *   and "providing numbers to compute upon"
	 *   so it is ok NOT accepting anything "broader".
	 */
	int user_input;
	/*
	 * Also needs a variable to store the return code
	 *   from scanf so we know if the read input could
	 *   correctly be interpreted as an integer or not.
	 */
	int validation_code;

	/* https://cplusplus.com/reference/cstdio/scanf/ */
	/* @note going for %i because seems more appropriate than %d */
	/*
	 * @note NOT restricting size to "1 digit" since
	 * function dedicated to menu choice
	 * BUT setting "%1d" just limits the READ instead of defining
	 *   an "input constraint".
	 */
	validation_code = scanf("%d", &user_input);
	if (validation_code <= 0)
		return (-1);
	else
		return (user_input);
}

/**
 * main - Calculator's orchestrator
 * @note for now no parameter identified
 * Description: program allowing simple arithmetics
 *   with 2 parameters through CLI.
 * Return: int (0 = success)
 */
int main(void)
{
	int user_choice;

	ui_display_menu();
	do {
		user_choice = check_menu_choice();
		printf("Choice: %i\n", user_choice);
	} while (user_choice != 0);

	printf("Bye!\n");
	return (0);
}
