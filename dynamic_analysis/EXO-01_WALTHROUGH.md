# Exo 01 Walkthrough

## Line 1 — TGT_PRE_BRANCH (32-bit)

### Goal

Where / when:
    Inside the function validate(...)
    Immediately after the call to compute_target(k) returns
    Before the conditional branch that checks (tgt & 1u) modifies tgt

What to record:
    The current value of the local variable: tgt

Write it as 0x????????.

### How to
This seems simple enough? Just make a break on line 115
  since it pauses before processing the target line.
  then print/x tgt
=> $1 = 0x6366889b

## Line 2 — TGT_POST_BRANCH (32-bit)

### Goal

Where / when:
    Still inside validate(...)
    Immediately after the (tgt & 1u) branch has executed and tgt has been updated
    Before mask and sig are computed

What to record:
    The value of: tgt

Write it as 0x????????.

### How to
Either just chain several "next" from the previous breakpoint.
Or just add a breakpoint on line 122.
=> $2 = 0xa7c1c047


## Line 3 — MASK (16-bit)

### Goal

Where / when:
    Inside validate(...)
    Right before the function returns
    After mask has been computed

What to record:
    The value of: mask

Write it as 0x????.

### How to
Break at 123 for earliest, or 125.
Then print/x mask
=> $3 = 0xa245

## Line 4 — SIG (16-bit)

### Goal

Where / when:
    Same point as Line 3 (right before return)
    After sig has been computed

What to record:
    The value of: sig

Write it as 0x????.

### How to
Break at 125 then print/x sig
=> $4 = 0x9d24
