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


Greedy Algorithm makes the optimal choice at each step as it attempts to find the overall optimal way to solve the entire problem. 
Greedy algorithms are quite successful in some problems, such as Huffman encoding Dijkstra's algorithm, which is used to find the 
shortest path through a graph.
However, in many problems, a greedy strategy does not produce an optimal solution.

Path with the largest sum:

```
                  7
               /     \                  
              3      12 
            /   \   /   \  
           99   8   5    6

```
Greedy algorithms solution: `7,12,6`.  
Optimal Solution: `7,3,99`.



Greedy algorithms have five components:

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

Solution:
First sort the jobs by the profit (descendingly), then try to fit the jobs in the schedule as late as possible, conditioning that time slot is still free.






## Example 2: knapsack Problem

Collect a set of items such that total weight is not more than the size of the bag and the value is maximized.

| Object| 1  | 2 | 3  | 4 | 5 | 6  | 7 | 
| ---   |--- |---|--- |---|---|--- |---|
| Value | 10 | 5 | 15 | 7 | 6 | 18 | 3 |
| Weight| 2  | 3 | 5  | 7 | 1 | 4  | 1 |

```
┌       ┐
|       |
|  15   |
|  KG   |
|       |
|       |
└       ┘
```
There are various version of this problem:
1) Items are divisible or not divisible.
2) More than one instance of an item could be selected.

The Greedy approach works only for fractional knapsack problem and may not produce correct result for 0/1 knapsack.
### Fractional Knapsack Problem

With the greedy algorithm, we divide the value by weight and we start adding from highest profitable until the bag reaches its limit.

| Object| 1  | 2   | 3  | 4 | 5 | 6    | 7 | 
| ---   |--- |---  |--- |---|---|---   |---|
| Value | 10 | 5   | 15 | 7 | 6 | 18   | 3 |
| Weight| 2  | 3   | 5  | 7 | 1 | 4    | 1 |
|Ratio:V/W| 5  | 1.6 | 3  | 1 | 6 | 4.5  | 3 |
|       |  1 |  0  | 1  | 0 | 1 | 1    | 1 |
|   X   | x1 | x2  | x3 | x4|x5 | x6   |x7 |

### 0-1 Knapsack Problem
Restricts the number of copies of each kind of item to zero or one. Items are **NOT** divisible and you can only carry one instance of an item.


### Bounded knapsack Problem (BKP)

Removes the restriction that there is only one of each item, but restricts the number of copies of each kind of item to a maximum non-negative 
integer value `c`.

### Unbounded Knapsack Problem (UKP) 
places no upper bound on the number of copies of each kind of item and can be formulated as above except for that the only restriction
 on is that it is a non-negative integer.



## Example 3: Huffman Coding

Suppose you use 8-bit data to store a character and you want to send the following message:  
`BCCABBDDAECCBBAEDDCC`  
So you need to send `20x8` bits of data since you have only 5 symbols, and you can count them with 3 bits of data you can represent your characters with 3  bits, so then you can send only `20x3` bits. 

In Huffman coding first, we count the frequency of characters in the string, then we sort them based on their frequency and we build the tree
by pairing the two most smallest items:

```



        20 
      /   \
     /     \ 
    9       \
   / \       \
  5   \       11
/   \  \    /   \
2   3   4   5    6
E   A   D   B    C   
```


| Char| count | code |
| --- | ---   | ---  |
| A   |  3    |  001 |
| B   |  5    |  10  |
| C   |  6    |  11  |
| D   |  4    |  01  |
| E   |  2    |  000 |




## Example 4: Minimum Spanning Trees

## Example 5: Prims 

## Example 6: Kruskals


## Example 5: Dijkstra and A Star
In BFS search we visit all the nodes level by level, until we find the goal node, so it is kind of bruteforce. 
We use a queue and begin from start node. We insert children ofthat node in the queue, we pop the first element from the head of queue and we continue
until we reach the goal. Since we might have loops in graph we also have to check if a node has been visited earlier so we don't insert it again.

```
  procedure BFS(G, start_v) is
      let Q be a queue
      label start_v as discovered
      Q.enqueue(start_v)
      while Q is not empty do
          v := Q.dequeue()
          if v is the goal then
              return v
          for all edges from v to w in G.adjacentEdges(v) do
             if w is not labeled as discovered then
                 label w as discovered
                 w.parent := v
                 Q.enqueue(w)
```
In Dijkstra, we use priority queue instead and we don't queit once we found goal node (because there might be a better path to the goal) but we 
stop once the queu is empty. 
```
     6        3
   A ----- B ----- C
   |       |       |
   |       |       |   
  3|      1|      1|  
   |       |       |
   D ----- E ----- F
   |   1   |  7    |
  9|       |       |7
   |      4|       | 
   |       |       | 
   G ----- H ----- I
      2       5
```   

Refs: [1](https://www.geeksforgeeks.org/greedy-algorithms/),
      [2](https://www.youtube.com/watch?v=bRvs8rOQU-Q),
      [3](https://web.stanford.edu/class/archive/cs/cs106x/cs106x.1192/lectures/Lecture23/Lecture23.pdf)
