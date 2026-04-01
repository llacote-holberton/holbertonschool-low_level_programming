# Overview

This directory will be used to explore hash tables
  and their various uses.

# Rules
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called hash_tables.h
- Don't forget to push your header file
- All your header files should be include guarded

# Exercises
0. >>> ht = {} (`0-hash_table_create.c`)
1. djb2 (`1-djb2.c`)
2. key -> index (`2-key_index.c`)
3. >>> ht['betty'] = 'cool' (`33-hash_table_set.c`)
4. >>> ht['betty'] (`4-hash_table_get.c`)
5. >>> print(ht) (`5-hash_table_print.c`)
6. >>> del ht (`6-hash_table_delete.c`)
