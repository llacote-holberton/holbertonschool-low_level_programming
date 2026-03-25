# Exo 00 Walkthrough

## Line 1 — TAG_ACC (32-bit)

### Goal
Where / when:
    Inside the function derive_key(...)
    Immediately after the loop that iterates over the decoded tag finishes
    Before the code combines the accumulator with user_pin and g_state

What to record:
    The value of the local variable: x

Write it as 0x????????.

### How to

We need a "breakpoint". Either on the last line inside the loop affecting x (77)
  Or at the line which affects x afterwards (81).
  Depending on whether the breakpoint stops BEFORE or AFTER 
  the execution of the target line instructions.
  => It's "BEFORE" so line 81 is the right one.
Then we "just" need to get x's value with gdb command "print x"
  while the program is "paused".
For the given input 123456 we get "$1 = 4075762699".
Value is required as hexadecimal so we just need to convert it.
Because I'm lazy xd I used an online tool.
=> "0xF2F5C8EB". 0xf2ef340b 0xf2ef340b

## Line 2 — KEY (32-bit)

### Goal
Where / when:
    Still inside derive_key(...)
    Immediately before the function returns

What to record:

    The value that will be returned by derive_key(...)
    The local variable holding that value: x

Write it as 0x????????.

### How to

This time there is a subtility. We'll need to set a breakpoint 
  "right on the return line" for the derive_key function (86).
BUT because breakpoint stops execution before processing target line,
  we need to make the program progress "just one more step" so that line
  is processed but run is paused just afterwards (although technically
  it's not required since that line just returns x, it does not modify it).
  => Using gdb command "next" should do that. Then we can just "print x" again.
  $2 = 1151060034
  AND this time I discovered you can force it to print directly as hexadecimal by appending '/x'
  (so print/x <variablename)
=> "0x447BC832" (ou "0x449bc842" si imprimé avec l'option /x direct).

## Line 3 — ACC_AFTER_I0 (32-bit)

### Goal
Where / when:
    Inside the function compute_target(...)
    During the loop
    At the end of the iteration where: i == 0
    After the accumulator has been fully updated for that iteration

What to record:
    The value of the local variable: acc

Write it as 0x????????.

### How-to
This time we want to "catch" the actual value of a runtime which is
  modified several times over in a loop. Just after "the first cycle is complete".
Several methods.
1/ Put a break on the "for loop declaration" (89), and use "next" once to "run the first cycle"
     then program will pause just before "i = 1" cycle starts (but technically we're already 
     at i = 1 I think?)
2/ Put a "watch" on i so the program stops each time it's incremented, and print acc manually.
3/ Discovered thanks to IA that GDB has built-in "scripting" so accepts expression
   (was also "explained" in official doc technically but I didn't get it at the time).
   so can use conditional to put a breakpoint on the loop's final line 
   which will be "triggered" ONLY when i (still) equals 0 exactly.
   break 104 if i == 0
   But it's complex because local variables are not known by GDB until actually in loop.
4/ COULDN'T MAKE IT WORK AS INTENDED: good compromise: breakpoint on loop line (99), 
     then display/x acc then next to "finish iteration i = 0" and have 
		 the "final value of acc for that cycle" displayed in hexa.
=> In the end the only thing which worked was putting one break on compute_target
   AND display i AND display/x acc AND spamming 'next' until we got back on for declaration
	 just before i was incremented to 1.
=> "0x65735aa6"
