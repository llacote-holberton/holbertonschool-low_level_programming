# Overview
This doc will...
1) Hold the "brainstorm" notes during architecture design.
2) Will hold structured documentation about final architecture
     once it's decided.

# Architecture

## Code structure
* Single calculator.c file
* Requires standard libraries <stdio.h> and <stdbool.h>.
* Single function to make all four arithmetic operations.
* Dedicated function to check and validate user input.

# Naming conventions
* is_*: logical statement returning (function) or
        holding (variable) a boolean expressing
        whether a statement is truthful.
* get_*: gets user input for a given functional scope.
* ui_*: user interface related functions.

# Architecture decisions

## Unified computer for arithmetic operations
Topic: choosing between "unit functions" and
  "centralized computation".
Choice made: centralized computation.
Reason: Betty coding style standards impose no more than
  5 functions per file. AND exercice constraints imposed
  having only a single source file, no custom headers.

## Naming the variables holding numbers to operate upon
Topic: deciding on best compromise between...
  * "explicit name" (ex number1/number2),
  * "concise name" (ex n1/n2),
  * "name harmonized with user interface" (A & B).
Choice made: A & B.

## Unrestricted size of user input reading for menu choice
Topic: deciding whether to put a length constraint
  on scanf's reading of user input when scanning menu choice.
Choice made: no restriction.
Reason: putting a length restriction just affects the reading
  but does not automatically empties the buffer, thus leaving
  remaining characters to be read on next scanf attempt
  therefore inducing confusion.
NOTE: decision may be re-evaluated once I know how to
  "flush" (empty) the buffer manually.

## Scanning user input with dedicated function
Topic: deciding how to manage user input in
  two different "contexts" (choosing operation from menu
  OR grabbing numbers to operate upon), between...
  * Parameterized "ux orchestrator" (function with "modes")
  * Dedicated functions to check and validate input
      for each context.
	* Other
Choice made: other: just one dedicated function for menu choice,
  scan for numbers to compute is made directly in the "computer".
Reason: making a parameterized function seemed overkill,
  yet the limitation on how many functions in single file
  drived to this hybrid choice.

## Restricting scanf to integer for menu choice
Topic: deciding the type of variable storing
  the user input while on "main menu".
  * Int: just integer
  * Decimal: wider range of supported values
Choice made: integer
Reason: because far enough considering
  the narrow range of "supported values" (0 to 4 included)
  to "choose action with a digit" so no reason to go broader.
NOTE: decision could be challenged if in the future
  program evolved.

## Using a constant array to display menu
Topic: deciding how best to generate the display
  of the menu, between simple sequence of printf,
  basic looped array or something smarter/more complex.
Choice made: simple constant array of strings which is
  iterated over.
Reason: seemed the best compromise between simplicity,
  efficiency and extensibility. Defined as constant
	to raise error in case of any attempt to modify
	as this is not wanted.
NOTE: decision would have been slightly different IF
  I had free reign on how to structure menu
  because then I could put "Exit" (associated with 0)
  as first index then have technical indexes matching
  "operation choice digits" which would have been practical
	for a number of things (-> single "Source of Truth").

# Useful DX documentation resources

## About grabbing user input (scanf)
- https://www.geeksforgeeks.org/c/scanf-in-c/
- https://cplusplus.com/reference/cstdio/scanf/

## About defining arrays
- https://www.geeksforgeeks.org/c/array-of-strings-in-c/

## About getting the length of an array (no built-in -_-)
- https://www.geeksforgeeks.org/c/length-of-array-in-c/

# BRAINSTORM

### Business goals
As a user, I want to...
- Be able to order simple
    arithmetic operations on two random numbers.
- Be able to tell the computer which operation
    I want to do each time.
- Be able to tell the computer which numbers
    to work upon each time.

As a developer, I want to...
- Ensure the program won't fail because of...
  * Insufficient input (one or two numbers missing).
  * Invalid operation selected.
  * Invalid operande given (not a number).
  * Trying an invalid operation (like division by zero).

### Technical constraints
- Only standard C libraries allowed.
- Only scanf allowed for getting user input.

### Architecture of functions
- Function to display menu
  * All items inside?
    -> Consider a function OR a loop dedicated to storing the array
- Function to get user input
    AND test it to check numbers
- Function to make the operations

### Self-learning Notebook

## Using scanf

ScanF requires 2 things.
- A variable declared to "store" the input
  (note: scanf will need to have the *address*
   of variable given instead of value).
- Also needs a variable to store the return code
    to check that value matched supported format.

## Using arrays
- There are two ways to define arrays with each its own syntax.
  * type variablename[x][y][z][a][b] (one [] for each table dimension)
		THEN individual (sub)cell affectation.
	*  type *variablename[] = {value1, value2, value3 etc};
- The explicit size multidimensional definition is great for homogeneous sets of data
    as we can define "strict minimum" width for all thus constraining memory print as much as possible.
  The array of pointers is the best for heterogeneous sizes or yet undefined length.
