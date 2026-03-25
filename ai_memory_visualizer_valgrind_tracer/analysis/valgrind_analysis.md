# Overview

This report focuses on reporting, for each of the available programs,
  the errors Valgrind could find using the following command.
  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./program_name
  
# Stack_example.c

## Program goal
This program aims to show how recursion piles up "copies" of functions with each call,
  each copy having its own values for parameters and local variables, and how
  the program runs recursion by first "constructing the pile" then "depiling copies one by one".

# Problems identified by Valgrind
NONE.
----
HEAP SUMMARY:
==9==     in use at exit: 0 bytes in 0 blocks
==9==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==9== 
==9== All heap blocks were freed -- no leaks are possible
==9== 
==9== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
----

# Heap_example.c

## Program goal
This program is designed to demonstrate a certain memory leak by trying to create 2 instances
  of a "Person" structure and printing their information BUT only freeing "Bob" when all runs correctly.

# Problems identified by Valgrind
MEMORY LEAK, of type "leak due to lost ownership".

----
==23== HEAP SUMMARY:
==23==     in use at exit: 6 bytes in 1 blocks
==23==   total heap usage: 5 allocs, 4 frees, 1,066 bytes allocated
==23== 
==23== Searching for pointers to 1 not-freed blocks
==23== Checked 105,456 bytes
==23== 
==23== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==23==    at 0x48417B4: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==23==    by 0x1091CD: person_new (heap_example.c:21)
==23==    by 0x1092AE: main (heap_example.c:51)
==23== 
==23== LEAK SUMMARY:
==23==    definitely lost: 6 bytes in 1 blocks
==23==    indirectly lost: 0 bytes in 0 blocks
==23==      possibly lost: 0 bytes in 0 blocks
==23==    still reachable: 0 bytes in 0 blocks
==23==         suppressed: 0 bytes in 0 blocks
==23== 
==23== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
----

# Aliasing_example.c

## Program goal

This program demonstrates the concept of pointer aliasing and the associated risks of use-after-free errors, by...
Creating an array of integers on the heap, assigning two different pointers to it, freeing one...
Then trying to continue accessing same memory with the other. 
This shows how aliasing can lead to dangling pointers and undefined behavior.

# Problems identified by Valgrind
USE AFTER FREE caused by "early free" from a making "sibling pointer b" dangling.

----
==33== HEAP SUMMARY:
==33==     in use at exit: 0 bytes in 0 blocks
==33==   total heap usage: 2 allocs, 2 frees, 1,044 bytes allocated
==33== 
==33== All heap blocks were freed -- no leaks are possible
==33== 
==33== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
==33== 
==33== 1 errors in context 1 of 3:
==33== Invalid read of size 4
==33==    at 0x1092DB: main (aliasing_example.c:45)
==33==  Address 0x4a3a48c is 12 bytes inside a block of size 20 free'd
==33==    at 0x484417B: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x109289: main (aliasing_example.c:38)
==33==  Block was alloc'd at
==33==    at 0x48417B4: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x1091A0: make_numbers (aliasing_example.c:12)
==33==    by 0x10922A: main (aliasing_example.c:30)
==33== 
==33== 
==33== 1 errors in context 2 of 3:
==33== Invalid write of size 4
==33==    at 0x1092CD: main (aliasing_example.c:44)
==33==  Address 0x4a3a48c is 12 bytes inside a block of size 20 free'd
==33==    at 0x484417B: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x109289: main (aliasing_example.c:38)
==33==  Block was alloc'd at
==33==    at 0x48417B4: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x1091A0: make_numbers (aliasing_example.c:12)
==33==    by 0x10922A: main (aliasing_example.c:30)
==33== 
==33== 
==33== 1 errors in context 3 of 3:
==33== Invalid read of size 4
==33==    at 0x1092AD: main (aliasing_example.c:42)
==33==  Address 0x4a3a488 is 8 bytes inside a block of size 20 free'd
==33==    at 0x484417B: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x109289: main (aliasing_example.c:38)
==33==  Block was alloc'd at
==33==    at 0x48417B4: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==33==    by 0x1091A0: make_numbers (aliasing_example.c:12)
==33==    by 0x10922A: main (aliasing_example.c:30)
==33== 
==33== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

----
# Problems identified by Valgrind
DEREFERENCE TO NULL caused by requiring a heap allocation of 0 for an array then trying to "write into it".

# Crash_example.c

## Program goal
This program "normally" aims at creating an array of numbers.
But its code was flawed on purpose to demonstrate how a dereference to NULL pointer can cause a crash.
In detail, it tries to allocate an array of integers with n = 0, which causes malloc to return NULL.
Logically making any subsequent access through the pointer triggering a segmentation fault.

----
=39== Invalid write of size 4
==39==    at 0x109242: main (crash_example.c:32)
==39==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==39== 
==39== 
==39== Process terminating with default action of signal 11 (SIGSEGV): dumping core
==39==  Access not within mapped region at address 0x0
==39==    at 0x109242: main (crash_example.c:32)
==39==  If you believe this happened as a result of a stack
==39==  overflow in your program's main thread (unlikely but
==39==  possible), you can try to increase the size of the
==39==  main thread stack using the --main-stacksize= flag.
==39==  The main thread stack size used in this run was 8388608.
==39== 
==39== HEAP SUMMARY:
==39==     in use at exit: 1,024 bytes in 1 blocks
==39==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==39== 
==39== Searching for pointers to 1 not-freed blocks
==39== Checked 105,408 bytes
==39== 
==39== 1,024 bytes in 1 blocks are still reachable in loss record 1 of 1
==39==    at 0x48417B4: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==39==    by 0x48CA8CB: _IO_file_doallocate (filedoalloc.c:101)
==39==    by 0x48D809F: _IO_doallocbuf (genops.c:347)
==39==    by 0x48D809F: _IO_doallocbuf (genops.c:342)
==39==    by 0x48D7477: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
==39==    by 0x48D663D: _IO_new_file_xsputn (fileops.c:1243)
==39==    by 0x48D663D: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
==39==    by 0x48CCA47: puts (ioputs.c:40)
==39==    by 0x109216: main (crash_example.c:27)
==39== 
==39== LEAK SUMMARY:
==39==    definitely lost: 0 bytes in 0 blocks
==39==    indirectly lost: 0 bytes in 0 blocks
==39==      possibly lost: 0 bytes in 0 blocks
==39==    still reachable: 1,024 bytes in 1 blocks
==39==         suppressed: 0 bytes in 0 blocks
==39== 
==39== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
==39== 
==39== 1 errors in context 1 of 1:
==39== Invalid write of size 4
==39==    at 0x109242: main (crash_example.c:32)
==39==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==39== 
==39== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
----
