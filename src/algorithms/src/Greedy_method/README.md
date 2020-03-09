# Greedy Algorithms

A greedy algorithm is any algorithm that follows the problem-solving heuristic of making at each point the locally optimal choice 
in order to find a global optimum. In many problems, a greedy strategy typically does not provide an optimal solution, but a greedy 
heuristic may generate locally optimal solutions in a reasonable amount that approximates a globally optimal solution.

Greedy is an algorithmic method that constructs a piece by piece solution, always selecting the next piece that provides the most 
apparent and immediate benefit. So the problems where the locally optimal option often leads to a global solution are best suited for Greedy.


Strategies for solving optimisation problem:
1) Greedy method.
2) Dynamic Programming.
3) Branch and Bound.


greedy algorithms have five components:

A candidate set, from which a solution is created
A selection function, which chooses the best candidate to be added to the solution
A feasibility function, that is used to determine if a candidate can be used to contribute to a solution
An objective function, which assigns a value to a solution, or a partial solution, and
A solution function, which will indicate when we have discovered a complete solution



## Example 1: Job Sequence With Deadlines Problem 

| Jobs     | J1  | J2  | J3  | J4 | J5 |
| ---      | --- | --- | --- |--- |--- |
| Profit   | 20  |  15 |  10 | 5  | 1  |
| Deadline |  2  |  2  |  1  | 3  | 3  | 


Each job take 1 unit of time and should be finished before the deadline. For instance if we start with `J2`, one unite of time will be spent, so we can not take `J3` as the deadline has gone.







## Example 2: Knapsack problem
### 0-1 knapsack problem
### bounded knapsack problem (BKP)
### unbounded knapsack problem (UKP) 


## Example 3: Huffman Coding

## Example 4: Minimum Spanning Trees

## Example 5: Prims 

## Example 6: Kruskals


Refs: [1](https://www.geeksforgeeks.org/greedy-algorithms/)
