*This project has been created as part of the 42 curriculum by hadrider*

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of unique integers using only two stacks (A and B) and 11 specific operations, printing every operation used to stdout. The challenge is to sort with the fewest operations possible.

The 11 operations are:
- sa / sb / ss — swap the top two elements of stack A, B, or both
- pa / pb — push the top element from one stack onto the other
- ra / rb / rr — rotate: top element goes to the bottom
- rra / rrb / rrr — reverse rotate: bottom element comes to the top

The program handles all edge cases: non-numeric input, duplicates, values outside int range, and already-sorted input all produce either an error message or no output.

## How the Algorithm Works

**Step 1 — Indexing:** Before sorting, every value is replaced by its rank (0 = smallest, n-1 = largest). This makes all comparisons clean and consistent regardless of the actual input values. A copy of the array is sorted using selection sort, then each element is replaced by its position in that sorted copy.

**Step 2 — Small sort (2 to 5 elements):** The algorithm finds the minimum element in stack A, calculates whether rotating forward (ra) or backward (rra) reaches it faster, rotates it to the top, and pushes it to B. This repeats until 3 elements remain. Those 3 are sorted using hardcoded cases that cover all 6 possible orderings in at most 2 operations. Everything is then pushed back from B to A.

**Step 3 — Chunk sort (more than 5 elements):** The ranks are divided into windows of size 20 (for up to 100 elements) or 35 (for up to 500 elements). Stack A is scanned repeatedly and each element is pushed to B if its rank falls inside the current window. Elements below the window floor get pushed and immediately rotated to the bottom of B with rb, so that larger ranks stay near the top of B for later. Elements above the ceiling are skipped with ra and handled in a future pass. Once A is empty, the pull-back phase grabs the largest rank remaining in B, rotates B in the shortest direction to bring it to the top, and pushes it to A. Because the largest goes first it sinks to the bottom of A. The smallest goes last and stays on top. Stack A ends up sorted.

## Instructions

```
make
./push_swap 3 2 1 5 4
ARG="3 2 1 5 4"; ./push_swap $ARG | ./checker_linux $ARG
ARG="3 2 1 5 4"; ./push_swap $ARG | wc -l
make fclean
```

Error cases the program handles:
```
./push_swap 1 2 abc        # non-numeric → Error
./push_swap 1 1 2          # duplicate   → Error
./push_swap 1 2147483648   # overflow    → Error
./push_swap                # no args     → no output
./push_swap 0 1 2 3        # sorted      → no output
```

## Resources

- 42 push_swap subject PDF
- Selection sort algorithm — used to build the rank table in index.c

**AI usage:** Used to understand and clarify how the operations and the algorithm work.