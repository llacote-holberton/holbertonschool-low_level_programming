#include <stdio.h>

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
 * get_menu_choice - Grabs & validate user input
 * @note for now no parameter identified
 * Description: grabs user_input and checks
 *   it is of expected type.
 * Return: int (-1 = error, as 0 can be a valid input here)
 */
int get_menu_choice(void)
{
	/*
	 * @note: defined as an "int" type because coherent with
	 *   the functional scope in which this value will be used
	 *   ([0..4] only supported choices).
	 */
	int user_input;
	/* @note used to check whether input is usable. */
	int validation_code;

	/* @note going for %i because seems more appropriate than %d */
	validation_code = scanf("%d", &user_input);
	if (validation_code <= 0)
		return (-1);
	else
		return (user_input);
}

/**
 * operate - Execute an arithmetic operation on 2 numbers.
 * @user_choice: int
 * Description: grabs
 * Return: int (0 = success)
 */
int operate(int user_choice)
{
	/*
	 * @note would have normally called them n1 and n2
	 *   but since we display "A" and "B"...
	 */
	int A;
	int B;
	int valid_A;
	int valid_B;
	int result;

	printf("A: ");
	valid_A = scanf("%d", &A);
	printf("B: ");
	valid_B = scanf("%d", &B);
	if (valid_A > 0 && valid_B > 0)
	{
		switch (user_choice)
		{
			case 1: /* "Add" */
				result = A + B;
				break;
			case 2: /* "Substract" */
				result = A - B;
				break;
			case 3: /* "Multiply" */
				result = A * B;
				break;
			case 4: /* "Divide" */
				result = (B != 0) ? A / B : 0;
				break;
		}
		printf("Result: %d", result);
	}
	return (0);
}

/* === MAIN === */

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
		user_choice = get_menu_choice();
		printf("Choice: %i\n", user_choice);
		/* @note had to cut dedicated function so went for shortest */
		if (user_choice > 0 && user_choice <= 4)
			operate(user_choice);
		/* @warning missing part: properly "give hand back to user". */
		else if(user_choice != 0)
		{
			printf("Invalid choice\n");
			/*
			 * Manual buffer wash by "reading without storing"
			 *   whatever may be left in the input buffer to start fresh.
			 * The "\n" must be "eaten" specifically so scanf considers
			 *   we "read a single character" otherwise \n would be treated as a
			 *   sort of "joker" saying "ignore any kind of space until next non space"
			 * The "*" just AFTER % indicates we want to read without storing.
			 * ^\n is a regular expression (different syntax than pearl though IIRC)
			 * meaning "any character which is not a newline one"
			 */
			scanf("%*[^\n]"); /* [\n] = regex meaning "anything except newline". */
			scanf("%*c");	/* Consumes a character which is the left over newline */
			printf("\n");
		}
	} while (user_choice != 0);

	printf("Bye!\n");
	return (0);
}
