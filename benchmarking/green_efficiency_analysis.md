# Overview
This file holds an explanation
  of how a performance analysis was conducted
	and which lessons can be taken away from it.

# Measurement Methodology
The three programs each explore a different approach.
1. The first (baseline_loop) targets the performance at linear scale
  of a simple sequential loop summing up the reminder of i divided by 3
  where i goes from 0 up to N (here 100000000).
  => This helps determine CPU performance for complexity type O(n).
2. The second (comparison_algorithms) compares two ways to write
    a process ending with the same effective result, with one
    obviously less effective than other, to get an idea of how
    nesting structures can impact performance.
	1. Using a nested loop (not sure why someone would choose this though
       for this simple task of checking whether n is multiple of 2).
	2. Using a single loop.
3. The third simulates a more complex program divided in
    several "phases" (initializing dataset, processing dataset,
    creating a "checksum" as a "string imprint" of the process)
    to approach the kind of structure real-world applications may have.
    It monitors the execution time of each phase to help determine
    "pain points" in execution thus areas to focus upon for performance optimization.

# Observed Performance Differences
1. The first program shows the variations which can happen from external influences.
	From the 5 runs (added 2 more runs to check hypothesis)...  
	  Best: 0.075333 Worst: 0.077155 Average: 0.075333.  
	  We can infer a minor gain (~1.5%) which may come from system having already program in CPU cache?  
	Although the number of runs is far insufficient to make a real assertion, and I could observe
	  a regression when chaining up additional runs. So at best we could say can expect up to 2-3%
	  gain "in optimal conditions" compared to "average or worse" conditions.
2. Second shows how much good design can improve performance,
    with the "single loop" version taking ~0.004% of the time required for nested loop
    (~0.00004 second vs 1.11000 second on average).

3. Third shows that the first phase is the most expensive taking
    roughly twice as long as process and four times as long as reduce.

# Relation Between Runtime and Energy Consumption
There is theorically a relationship between runtime and energy consumption
  but we cannot infer anything as simple as "more runtime = bad" from these experiments
  as...
  1. They span over too short a time to really matter.
  2. We have no way of knowing (as-is) the specifications of the processor
       or the frequency at which it was put to run program (which has a huge impact
       on direct power consumption and indirect through heat dissipation): a longer runtime
       at lower frequency may or not be better than shorter runtime at higher frequency.

# Limitations of the Experiment
This experiment is enough to stress that a good architecture is the first and
  paramount vector of efficiency. But it is not enough...
  * To determine how much an algorithm really holds its ground "at large scale":
    - Volume of iterations for 2nd and 3rd program are relatively small
    - Data is built "linearly" with simple expression for second program
    - Programs only work on "basic data types".
  * To represent a realistic situation, as the programs are extremely narrow in
      their scope, whether...
	- Relative to their input (generated input with simple process
        vs externally grabbed through filesystem or network,
        simple data types, limited "size" of each data piece).
	- Relative to their process (very simple logic overall).
	- Relative to their output (simple terminal printf, no writing in file or pushing on network).

# Practical Engineering Takeaway
1. Good architecture is paramount and should always be top 1 priority
   * Always evaluate complexity "in big O notation".
   * Always try to pursue O(1) complexity (constant time/complexity irrelevant of input size)
     of 0(log (n)) when variable input size for a process.
2. Identifying "components" of a program and measuring their performances regularly
     help checking whether design is good enough and where to try and improve.
