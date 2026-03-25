# Overview

This report focuses on explaining why the program crash_example.c
  ends with a segmentation fault.

## Crash_example.c's goal
This program "normally" aims at creating an array of numbers.
But its code was flawed on purpose to demonstrate how a dereference to NULL pointer can cause a crash.
In detail, it tries to allocate an array of integers with n = 0, which causes malloc to return NULL.
Logically making any subsequent access through the pointer triggering a segmentation fault.

# Detailed explanation

## Root cause
Root cause "in execution" is in main function, the line 25. 
```    int n = 0;```
As it ends up "requiring a table of 0 cells to be created" on line 30 of source code:
```nums = allocate_numbers(n);```
Then trying to access some cell of it.

Root cause **"in conception"** however rather lies within this line 32
```    nums[0] = 42;```
  as it tries to access a cell without first checking whether
  pointer's target actually exists.
Because allocate_numbers does include a guard clause to prevent "table 0 cell" creation,
  returning NULL in that case.

## Full causal chain
1. int n = 0;                      → requests an array of zero size when calling allocate_numbers.
2. allocate_numbers(n) sees n is 0 → returns NULL pointer.
3. nums in main() points to null   → dangling pointer.
4. main() attempts to dereference pointer to write inside
          → CPU detects memory address invalid for write access.
          → Segmentation fault occurs, program crashes.

NOTE: free(nums) is never reached because execution stops at the fault.

## Error categorization
- Type	Deterministic crash due to NULL pointer dereference
- Memory issue	Accessing memory that is not allocated (NULL)
- Causal origin	Logical error in pointer handling / allocation check

## Review of IA help
IA helped in providing an overview of the program's behaviour and
  made relevant assumptions on execution problems and their root causes.
However it failed giving me the correct amount of memory used in some instances
  and "best-guessed" what would Valgrind produce without knowing the exact context of execution
	(compilation options for program, Valgrind options for analysis run).
It also gave a definite opinion "program always crashes" when actually in some configurations
  of CPUs / compilations / malloc implementations some safeguards may exist to not return NULL.
