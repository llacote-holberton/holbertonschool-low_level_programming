# Overview

This report focuses on analyzing, for each of the available programs,
  how the stack and heap memory are used, which flaws or risks have been identified,
  and how one could correct them later.
While confronting AI's ability to help diagnose but also sometimes mislead developer
  on root causes or ways to fix.
As such, each program will be treated separately, with the following inner structure.

Variables management (memory repartition in stack / heap / other, lifetime).
Memory ownership management

# Stack_example.c

## Program goal
This program aims to show how recursion piles up "copies" of functions with each call,
  each copy having its own values for parameters and local variables, and how
  the program runs recursion by first "constructing the pile" then "depiling copies one by one".

## Variables management
All of the following variables are allocated in Stack, so automatically allocated on function instanciation
  and freed when function instance's ends its execution.
The "max simultaneous copies" designates how many copies of a variable exist at once "at worst"
  which is the moment where recursion "stacking phase" just achieved ("recursion stack peak").

| Variable Name | Total copies | Max simultaneous copies |
|--             |--            |--                       |
| Depth         | 12           | 5                       |
| Max_depth     | 4            | 4                       |
| Label         | 8            | 5                       |
| Local_int     | 8            | 5                       |
| Local_buff    | 8            | 5                       |

To note, "enter" and "exit" are literal strings so constants created in a specific space,
  which is neither stack nor heap but "static memory" (read-only data segment, shortname ro_data).

Also, when AI was asked to count simultaneous copies, it indicated 8 instead of 12 for the Depth variable
  as it apparently didn't properly take into account the ones for walk_path calls upon first ask.

## Memory consumption 

On assumption of x86-64 architecture with default compilation, program will use 
Minimum	~64 octets
Average	~120–180 octets
Maximum	208 octets

## Ownership management

As each function gets a new instance of pointer we could fear ownership ambiguity
  BUT since both instanciated pointers AND the data they point to are on stack
  the related memory is automatically managed so no trouble, program knows when to
  free the memory for the pointed data itself (and all local variables are freed
  when the "frame function" ends).

## Step by step Memory Map
Cf source file memory-maps__diagram-source__stack_example_v4.mermaid
and the related view https://mermaid.ai/d/d4ae71f1-62dc-4689-a35c-7f6913c153eb

## Confirmed or potential security/performance risks
None identified

# Heap_example.c

## Program goal
This program is designed to demonstrate a certain memory leak by trying to create 2 instances
  of a "Person" structure and printing their information BUT only freeing "Bob" when all runs correctly.

## Variables management
The only variables stored in Heap are the structures for Alice & Bob Person instances.
Everything else (pointers, other local variables) are stored in the Stack.
There are problems in their lifecycle, confer related section.

## Memory consumption

On assumption of x86-64 architecture with default compilation, program will use 
Structure each uses 24 bytes because...
- Pointers use 8 bytes each straight, and one member is a pointer.
- Name strings are less than 8 characters (EOL included) but memory system will "complete" to keep "allocation alignement"
  so the member uses 8 bytes.
- Same with the age member (integer 4 bits, but probably padding to keep alignement)
So program will consume 48 bytes of heap memory maximum, with 8 left-over because of partial free.
Program will also consume a minimum of 16+24+8 = 48 bytes for local variables.

## Ownership management
There is an ownership ambiguity caused by the fact that two different functions manage creation and liberation
  BUT the "liberation one" doesn't properly free everything in the structure before freeing structure itself.

## Step by step Memory Map
Confer the relatd diagram.

## Confirmed or potential security/performance risks
Two problems of memory leaks, as there isn't proper free of "all" of the structures created in two instances.
- When either one couldn't be instanciated (the existing one does not free the "name" member). 
- Or when both were instanciated (Bob is explicitely "liberated fully, not Alice).

# Aliasing_example.c

## Program goal

This program demonstrates the concept of pointer aliasing and the associated risks of use-after-free errors, by...
Creating an array of integers on the heap, assigning two different pointers to it, freeing one...
Then trying to continue accessing same memory with the other. 
This shows how aliasing can lead to dangling pointers and undefined behavior.

## Variables management
The integer array arr allocated inside make_numbers() resides on the heap, as it is allocated using malloc().
Local variables i and arr inside make_numbers(), and a, b, n in main(), are stored on the stack.
There is no simulteanous copies as no recursion and single call.

## Memory consumption
The program allocates an array of n = 5 integers on the heap: 5 × sizeof(int) = 20 bytes.
Stack usage is minimal (~32–48 bytes) for local variables a, b, n and function call overhead.
There is no memory leak identified.

## Ownership management
There is an ambiguity problem (although easily identifiable here considering small code)
  with two pointers targeting the same pointer. Even though technically a is the one which
  "keeps" responsability in practice, if b is initialized ownership should be "transferred" to it.

## Step by step Memory Map
1. make_numbers(n) allocates arr on heap, returns pointer to a.
2. b = a creates an alias; both pointers point to the same heap memory.
3. Accessing a[2] or b[2] is valid.
4. free(a) releases the heap memory.
5. b is now dangling, any read/write through b is undefined behavior.
6. b is never freed but since it was a dangling pointer there is no memory leak technically.
   "Just" undefined behaviour in current code.

## Confirmed or potential security/performance risks
Pointer b becomes dangling after a which targeted same memory block 
  has been "freed" on line 38 of source, leading to undefined behaviour.
This is called the risk of "use-after-free" or in this specific case "aliasing risk".

# Crash_example.c

## Program goal
This program "normally" aims at creating an array of numbers.
But its code was flawed on purpose to demonstrate how a dereference to NULL pointer can cause a crash.
In detail, it tries to allocate an array of integers with n = 0, which causes malloc to return NULL.
Logically making any subsequent access through the pointer triggering a segmentation fault.

## Variables management
Apart from the following, all variables are stored in Stack.
The pointer nums would normally reference heap memory, but because code "runs" with 0 as array size, 
  in this case, malloc(0) returns NULL, so no heap memory is actually allocated.

## Memory consumption

Stack usage is minimal (~32–48 bytes) for local variables and function call overhead.
Heap usage is 0 bytes because allocation was skipped.
Total program memory footprint is therefore only stack + static code + I/O buffers.

## Ownership management
No risk identified.

## Step by step Memory Map
1. allocate_numbers(n) sees n = 0 and returns NULL.
2. nums in main() receives this NULL pointer.
3. nums[0] = 42 attempts to dereference NULL, causing a segmentation fault.

No heap memory is allocated; no free() is actually required, but the program crashes before reaching free.

## Confirmed or potential security/performance risks
Deterministic crash due to NULL pointer dereference.
