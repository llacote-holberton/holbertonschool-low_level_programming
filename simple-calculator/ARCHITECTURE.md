# Overview
This doc will...
1) Hold the "brainstorm" notes during architecture design.
2) Will hold structured documentation about final architecture
     once it's decided.

# Architecture

## Code structure
* Single calculator.c file
* Requires standard libraries <stdio.h> (<stdbool.h> was ininitally included but then removed).
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
- https://web.archive.org/web/20250417094758/https://www.sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
- https://koor.fr/C/cstdio/fscanf.wp
- https://www.freecodecamp.org/news/using-scanf-in-c/
- https://linux.die.net/man/3/scanf

## About defining arrays
- https://www.geeksforgeeks.org/c/array-of-strings-in-c/

## About getting the length of an array (no built-in -_-)
- https://www.geeksforgeeks.org/c/length-of-array-in-c/

