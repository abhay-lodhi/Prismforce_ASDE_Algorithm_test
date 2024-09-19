# Chakravyuha Escape Problem

## Problem Statement

Abhimanyu is trapped in a Chakravyuha with 11 circles, each guarded by an enemy. He needs to fight or skip enemies to escape, with the following constraints:

- Each circle is guarded by an enemy with a given power level.
- Abhimanyu starts with an initial power `p`.
- He has the ability to skip up to `a` enemies.
- He can recharge his power up to `b` times.

The goal is to determine whether Abhimanyu can cross all 11 circles and escape.

## Input Format

For the input:
- The first line contains 11 integers, representing the power levels of enemies in each of the 11 circles. Each integer `ki` denotes the power of the enemy in the `i-th` circle.
- The second line contains three integers:
  - `p` — the initial power Abhimanyu starts with.
  - `a` — the number of times Abhimanyu can skip fighting enemies.
  - `b` — the number of times Abhimanyu can recharge his power.

## Output Format

For the output:
- Output `YES` if Abhimanyu can cross all 11 circles successfully. 
- Output `NO` if it is impossible for him to escape the Chakravyuha.

## Constraints (Assumed)

- Each enemy power level `ki` will be a positive integer.
- `p`, `a`, and `b` are also positive integers.

## Test Case 1

### Input  
1 2 4 4 5 6 8 8 9 10 11  
20 2 3  

### Output  
YES  


## Test Case 2

### Input  
12 25 30 20 15 50 60 70 80 90 100  
50 1 2  

### Output
NO  


## Solution Explanation

The solution uses a recursive backtracking approach with memoization to determine if Abhimanyu can successfully navigate through the Chakravyuha. Here are the key points of the implementation:

1. **Dynamic Programming (DP) Initialization**: 
   - A 5D vector `dp` is used for memoization, allowing the storage of previously computed states to avoid redundant calculations.

2. **Base Conditions**:
   - If Abhimanyu's current power drops below 0 during the battle, he fails.
   - If he reaches beyond the 11th circle, he wins.

3. **Current Power Check**:
   - For each circle, we check if Abhimanyu's current power is sufficient to defeat the enemy. If not, he has the option to skip or recharge.

4. **Recursive Exploration**:
   - The `backTrack` function recursively explores paths, including fighting enemies, skipping circles, and recharging powers.

5. **Early Exit**:
   - If Abhimanyu has 11 or more skips, he can skip all circles and escape.
   - Additionally, Abhimanyu can skip or recharge a maximum of 11 times, as there are only 11 circles. Therefore, any additional skips or recharges beyond this point do not provide additional benefits.

6. **Final Output**:
   - After evaluating the test case, the program outputs whether Abhimanyu can escape the Chakravyuha.



