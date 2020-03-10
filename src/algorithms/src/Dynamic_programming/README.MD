# Dynamic Programming
Dynamic Programming is an optimization over plain recursion by using memorization. Basically, if we have already computed the value of the function for
the sub-problem, we use it and don't recompute it again. There are two main approaches for storing sub-problem solutions: tabulation and memoization.

## Tabulation vs Memoization

1) Tabulation: Bottom Up
2) Memoization: Top Down



## Coin problem
In this problem we are interested to make a sum of money `x` with a set of coins values `{c1,c2,...ck}` by using the minimum number of coins.
A simple greedy algorithm to the problem always selects the largest possible coin, until the required sum of money has been constructed.
It turns out that if the coins are the euro coins, the greedy algorithm always works.

In the general case, the coin set can contain any coins and the greedy algorithm does not necessarily produce an optimal solution.

For example if the coins are `{1,3,4}` and the target sum is 6, the greedy algorithm produces the solution `4+1+1` while the optimal solution is `3+3`.

```
solve(amount)=min nummber of coins
solve(0)  = 0
solve(1)  = 1
solve(2)  = 2
solve(3)  = 1
solve(4)  = 1
solve(5)  = 2
solve(6)  = 2
solve(7)  = 2
solve(8)  = 2
solve(9)  = 3
solve(10) = 3
```
For instance `solve(10)` means `3+3+4`. Recursive formula to calculate the minimum number of coins:

```
solve(x) = min(solve(x−1)+1, solve(x−3)+1, solve(x−4)+1)

```
The genral case for this function would be:

```
c[]={c1,c2,...ck}

solve(x) =∞                          if x<0

solve(x) =0                          if x=0

solve(x) =min(u, solve(x-c[i]) +1)   if x>0
```




## 0-1 Knapsack Problem
Restricts the number of copies of each kind of item to zero or one. Items are **NOT** divisible and you can only carry one instance of an item.

## Paths in the grid
Finding a path in an `Y × X` grid from the upper-left corner to the lower-right corner. We are only allowed  to move right or down.
Every cell in the grid has a cost, the goal is to find the most costly path.

```
1,1  1,2 .... 1,X
2,1  2,2 .... 2,X
.
.
.
Y,1  Y,2 .... Y,X
```
Example of the costs map:
```
3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
```
*/

## Levenshtein Distance

Refs (1)[https://cses.fi/book.html]