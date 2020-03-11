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



