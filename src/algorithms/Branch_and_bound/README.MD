# Branch and Bound
In this approach, which is generally used for solving combinatorial optimization problems we use BFS traverse to create the **state space tree**. 
it is useful for solving optimization problem (only minimization problem). 


## Example 1: Job Assignment

|Person name|Cost Job 1|Cost  Job 2|Cost Job 3  |Cost Job 4 |
| ----------|--------- | -----     | -----      | -----     | 
| A         | 9        | 2         | 7          |   8       |
| B         | 6        | 4         | 3          |   7       |
| C         | 5        | 8         | 1          |   8       |
| D         | 7        | 6         | 9          |   4       |

Assign jobs to poeple such that job cost would get minimized conditioning only one job get assigned to 1 person. To find a lower bound we pick the minimum cost
for all individual (we might vilate the constraint one job for one person, but it is okay since its not a solution, just a lower bound).

Lower Bound=(lowest cost for person A)+(lowest cost for person B)+(lowest cost for person C)+(lowest cost for person D)= 2+3+1+4

```
                                                                    2+3+1+4                                                            
                                                   /           |               |            \   
                                                 A<-Job 1     A<-Job 2     A<-Job 3       A<-Job 4
                                              LB=9+3+1+4      LB=2+3+1+4   LB=2+3+1+4     LB=8+31+6
```
So now we start traversing the tree by BFS search, and put the node in the priority queue..

```
                                                                    2+3+1+4                                                            
                                                   /           |               |            \   
                                                 A<-Job 1     A<-Job 2     A<-Job 3       A<-Job 4
                                              LB=9+3+1+4      LB=2+3+1+4   LB=2+3+1+4     LB=8+31+6
                                                            /     |      \
                                                          B<-1   B<-3    B<-4     
                                                        LB=13    LB=14   LB=17
```

We exand the `A<-2` and `B<-1`

```
                                                                    2+3+1+4                                                            
                                                   /           |               |            \   
                                                 A<-Job 1     A<-Job 2     A<-Job 3       A<-Job 4
                                              LB=9+3+1+4      LB=2+3+1+4   LB=2+3+1+4     LB=8+31+6
                                                            /     |      \
                                                          B<-1   B<-3    B<-4     
                                                        LB=13    LB=14   LB=17
                                                       /    \ 
                                                      C<-3  C<-4
                                                      D<-4  D<-3
                                                   Cost:13  Cost:25 
```
Now since we have a valid solution with cost 13, we don't continue any node with lower bound more than that.

## Example 2: 0/1 Knapsack problem


In **Branch and Bound** we find upper bound (or lower bands) for our branches, and if they are worse than a valid solution we don't continue that branch.
We put our branches in a priorety queue and pop next ranch from it. At the begining we need upper bounds (lower bounds). These could be an invalid estimate 
and should be computed quickly.

Let say we have the following items:  

| Item name | Weight  | Value | Value/ Weight|
| ----------|---------| ----- | -----        |
| A         | 4       | 40    | 10           |
| B         | 7       | 42    | 6            |
| C         | 5       | 25    | 5            |
| D         | 3       | 12    | 4            |


Knapsack capacity: 10

We use the Value/ Weight to estimate the upper bound. For instance if we include item A, the remain capacity is `6=10-4`, so at best we can fill the rest of teh bag 
with `remain capacity* best available  value/weight =6*6` so in total the best value would be `76=40+6*6`.


Branch and Bound tree
```
                                         A
                                   /          \
                                  /            \
                                 /              \
                                /                \
                               /                  \
                              B UB=76,v=4,w=4       B UB=60, w=0,v=0
                            /  \                  /  \
                      W=11  X    C UP=70,v=4,w=4 C     C
                               /  \            /  \   /  \
                               D   D           D   D  D   D
                              /\              /\  /\ /\   /\
                        W=12 X W=9,V=65
```  

## Example 3: Traveling Salesman Problem


Refs: [1](https://www.youtube.com/watch?v=zkCpOmNM-RQ)
