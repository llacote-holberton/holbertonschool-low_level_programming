# BRAINSTORM

NOTE: those are personal thoughts and notes,
  irrelevant for users apart from sheer curiosity.
  Left here because preferred

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
