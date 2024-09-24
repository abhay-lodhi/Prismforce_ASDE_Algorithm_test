# Chakravyuha Escape Problem

## Problem Statement

Imagine Abhimanyu trapped in a Chakravyuha with 11 circles, each surrounded by different enemies. Abhimanyu is located in the innermost circle and must cross all 11 circles to reach the Pandavas' army.

### Given:
- Each circle is guarded by a different enemy, with powers represented as \( k1, k2, k11 \).
- Abhimanyu starts from the innermost circle with an initial power \( p \).
- He has the ability to skip fighting enemies up to \( a \) times.
- He can recharge his power up to \( b \) times.
- Battling an enemy in each circle will result in a loss of power equal to the enemy's power.
- If Abhimanyu enters a circle with energy less than the respective enemy's power, he will lose the battle.
- Enemies in circles 3 \( k3 \) and 7 \( k7 \) have the ability to regenerate themselves once, recovering half of their initial power, and can attack Abhimanyu from behind if he battles in the subsequent circle.

### Objective:
Determine whether Abhimanyu can successfully cross all 11 circles and escape the Chakravyuha.

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
  
   **************Look for the full solution's code in ASDE_Algorithm_Test.cpp file *********************

## Time Complexity

The time complexity of this algorithm is O(n * p * a * b) , where:
- \( n \) is the number of circles (11 in this case),
- \( p \) is the initial power level,
- \( a \) is the maximum number of skips,
- \( b \) is the maximum number of recharges.

This complexity arises because we explore all possible states combining the power levels, skips, and recharges for each circle.

## Space Complexity

The space complexity of this algorithm is  O(n * p * a * b)  as well, primarily due to the storage used for the memoization table `dp`. This is necessary to keep track of previously computed states and avoid redundant calculations.

---
