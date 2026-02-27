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
 * main - Calculator's orchestrator
 * @note for now no parameter identified
 * Description: program allowing simple arithmetics
 *   with 2 parameters through CLI.
 * Return: int (0 = success)
 */
int main(void)
{
	ui_display_menu();
	return (0);
}
