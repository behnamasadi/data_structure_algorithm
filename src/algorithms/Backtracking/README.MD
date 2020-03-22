# Backtracking 
This strategy uses the brute force approach and eliminate undesired solution and only pick the desired solution. It is similar to 
dynamic programming but in dynamic programming, we were looking for an optimal solution but in "Backtracking" we are looking for all valid solutions.
`combination` and `permutation` are example of the problems that can be solved by backtracking and the solutions can be represented 
in the ** state space tree**. We use DFS traverse to create the tree.

## Example 1 : Three chair color
Selecting colors red, blue and green for three chairs:

```
                             O
                        /    |    \  
                       R     G      B
                      / \   / \    / \                       
                     G  B   R  B  G   R 
                     |  |   |  |  |   |
                     B  G   B  R  R   G                      
```
Usually there are some constraints that limits some solution, for instance imaging the constraint is the color green should be always in center:



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
Placing 4 Queens in 4x4 chessboard 

## Example 3: Sum of Subsets
You have the following numbers:  
`5,10,12,13,15,18`  
you should a subset of them such that total sum is exactly 30.

## Example 4: Graph Coloring Problem

## Example 5: 0/1 Knapsack problem
Brute Force solution will give us all possible solution but we can use Backtracking to optimize the Brute Force solution.
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
In the tree representation, we can do DFS of tree. If we reach a point where a solution no longer is feasible, there is no need to continue exploring. 


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
Hamiltonian cycle is a graph cycle (i.e., closed loop) through a graph that visits each node exactly once. It is a NP hard problem.
If there is a articulation point in a graph then hamiltonian cycle doesn't exist in that graph. If there is also pendant vertex 
the hamiltonian cycle doesn't exist.

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
1) 3 is an articulation point
2) `e`and `f` are pendant vertices.



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
┌                    ┐
|0   1   1   0   1   |
|1   0   1   1   1   |
|1   1   0   1   0   |
|0   1   1   0   1   |
|1   1   0   1   0   |
└                    ┘
```














