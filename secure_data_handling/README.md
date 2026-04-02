# Overview

This directory will be used to learn how to secure
  some provided code by using Valgrind and GDB to analyse
  flaws and correct them as needed.

Source code can be downloaded from here
https://github.com/hbtn-edu/public_resources/tree/main/3777-secure_data_handling_lab

# Rules
Confer details on https://intranet.hbtn.io/projects/3777 
(too many rules to recopy)

In summary...
- Only session.c and store.c must be modified.
  Other must stay untouched whether to fix or improve them.
  Except headers if really necessary (like adding subfunction I suppose).
- CLI command and API behaviour must stay unchanged.
- Once modifications are finished program must be free of any risk or flaw whether speaking of  
  memory leaks, dangling pointers, use after free, double free etc.

