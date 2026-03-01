# Overview
This program is a simple arithmetic computer
  allowing you to choose one of the four basic operations
  (add, subtract, multiply, divide) on two numbers.
  Negative and positive floating numbers are supported
  from 1.2E-38 to 3.4E+38.

# How to run
## Prerequisites
You must have the packages/tools related to C
  installed on your system, as well as a "compiler"
  (program used to "prepare" this tool for your machine).
In case that helps here are online resources to install
  those tools depending on your operating system
  * Windows: https://learn.microsoft.com/en-us/cpp/build/walkthrough-compile-a-c-program-on-the-command-line?view=msvc-170
     and https://nullprogram.com/blog/2016/06/13/
  * Mac: https://www.cs.auckland.ac.nz/~paul/C/Mac/
  * Linux (deb package system): https://jvns.ca/blog/2025/06/10/how-to-compile-a-c-program/

# 1. Downloading
If you have git and are comfortable with command line,
  you can simply open one and go to the directory in which you want calculator to be.
  Then run (without the quotes) "git clone <FIXME URL>"
Otherwise you can simply download a zip containing all projects file
  by following this url: <FIXME> then unfolding it where you want on your computer.

## 2. Compiling
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## 3. Starting program
Open a terminal place yourself in the directory in which you have downloaded/extracted
  the project then compiled an executable, and just type "calculator" (without quotes)...

## 4. Exiting program
The soft way is choosing option "0" in the menu to stop cleanly.
You can also use "force-close" shortcut of your terminal if in a hurry. ;)
(Ctrl+C on most Linux shells).

# How to use
Once you run the program, just...
1. Select the desired operation by typing the digit
   associated to it.
2. Enter the first number to work upon.
3. Enter the second number.
4. Repeat until satisfied, choose "0" on main menu to exit.

Please note that this program expects...
- A single digit for menu choice.
- Two numbers within the covered range.
