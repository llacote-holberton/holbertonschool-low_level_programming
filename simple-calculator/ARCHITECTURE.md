# Overview
This doc will...
1) Hold the "brainstorm" notes during architecture design.
2) Will hold structured documentation about final architecture
     once it's decided.

## BRAINSTORM

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
    AND REDIRECT depending on context and choice.
