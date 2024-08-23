# Backtracking 
This strategy uses the brute force approach to eliminate undesired solutions and only pick the desired solution. It is similar to 
dynamic programming but in dynamic programming, we were looking for an optimal solution but in "Backtracking" we are looking for all valid solutions.
`combination` and `permutation` are examples of the problems that can be solved by backtracking and the solutions can be represented.
in the **state space tree**. We use DFS traverse to create the tree.

## Example 1: Three chair color
Selecting colors red, blue, and green for three chairs:

```
                             O
                        /    |    \  
                       R     G      B
                      / \   / \    / \                       
                     G  B   R  B  G   R 
                     |  |   |  |  |   |
                     B  G   B  R  R   G                      
```
Usually, there are some constraints that limit some solutions, for instance imaging the constraint is the color green should be always in the center:



```
                             O
                        /    |    \  
                       R     G      B
                      / \   / \    / \                       
                     G  x  x   x  G   x 
                     |            |    
                     B            R                          
```
## Example 2: N Queen Problem
Placing 4 Queens on a `4x4` chessboard.

## Example 3: Sum of Subsets
You have the following numbers:  
`5,10,12,13,15,18`  

You should make a subset of them such that the total sum is exactly 30.

## Example 4: Graph Coloring Problem

## Example 5: 0/1 Knapsack problem
Brute Force solution will give us all possible solutions but we can use Backtracking to optimize the Brute Force solution.
Knapsack capacity is 10.

| Item name | Weight  | Value |
| ----------|---------| ----- |
| A         | 2       | 40    |
| B         | 3.14    | 50    | 
| C         | 1.98    | 100   | 
| D         | 5       | 95    |
| E         | 3       | 30    |


Brute force Tree:

```
                                         A
                                   /          \
                                  /            \
                                 /              \
                                /                \
                               /                  \
                              B                    B
                            /  \                 /  \
                           C    C               C     C
                         /  \  /  \           /  \   /  \
                        D   D  D  D           D   D  D   D
                       /\  /\ /\  /\         /\  /\ /\   /\
                      E E E E E E E E       E E E E E E  E E
                     /\/\/\/\/\/\/\ /\     /\/\/\/\/\/\ /\ /\   

```  
In the tree representation, we can do `DFS` of a tree. If we reach a point where a solution no longer is feasible, there is no need to continue exploring. 


Backtracking Tree:

```
                                         A
                                   /          \
                                  /            \
                                 /              \
                                /                \
                               /                  \
                              B                    B
                            /  \                 /  \
                           C    C               C     C
                         /  \  /  \           /  \   /  \
                        D   D  D  D           D   D  D   D
                       /\  /\ /\  /\         /\  /\ /\   /\
                        E   E E E E E         E E E E E  E E
                        \  /\ \/\/\ /\       /\  \/\/\/\ /\ /\   

```  

## Example 6: Hamiltonian Cycle
The Hamiltonian cycle is a graph cycle (i.e., closed-loop) through a graph that visits each node exactly once. It is an `NP-hard` problem.
If there is an articulation point in a graph then the Hamiltonian cycle doesn't exist in that graph. The articulation point in a connected graph is a single point that removing it  would split the graph into 2 or more components.

If there is also a **pendant vertex**. Pendant vertices are the vertices that have degree 1 (Degree = number of edges connected to a vertex).
The Hamiltonian cycle doesn't exist.

```
              1       5                        a  
            /   \   / |                      /   \ 
           /     \ /  |                     /     \
          2       3   |                    b       c 
           \     / \  |                     \     /   
            \   /   \ |                      \   /
              4       6                        d
                                              / \
                                             e   f
```
1) The node `3` is an articulation point
2) Nodes `e` and `f` are pendant vertices.



Graph
```
|-----------|
|           |
|           |
0-------1\  |
|       | \ |
|       |  2
|       | /
4-------3/
```

Adjacency Matrix
```
 0   1   2   3   4
┌                    ┐
|0   1   1   0   1   | 0
|1   0   1   1   0   | 1
|1   1   0   1   0   | 2
|0   1   1   0   1   | 3
|1   0   0   1   0   | 4
└                    ┘
```


## When to use Backtracking Algorithm

**1. Permutation or Combination Problems:**
When you need to generate all possible permutations or combinations of a set of elements, For example, solving puzzles like Sudoku, and N-Queens

**2. Decision Problems: **
When you need to find a feasible solution or not, rather than generating all possible solutions. Backtracking can be used to efficiently solve problems like graph coloring or finding a Hamiltonian cycle in a graph.

**3. Constraint Satisfaction Problems: **
 problem that can be broken down into smaller decisions, each with constraints, where choices made need to satisfy specific conditions or constraints, like scheduling or resource allocation problems.
 - Allocating personnel to specific tasks based on their skills and availability.
 - Prioritizing tasks based on their importance and allocating resources accordingly.


[Ref](https://intellipaat.com/blog/backtracking-algorithm/#:~:text=For%20example%2C%20solving%20Sudoku%20or,problems%20by%20exploring%20solution%20spaces.)

## List of Problems on Backtracking Algorithm

[complete list](https://www.geeksforgeeks.org/backtracking-algorithms/)









