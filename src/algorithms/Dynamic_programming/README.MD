# Dynamic Programming
Dynamic Programming is an optimization over plain recursion by using memorization. Basically, if we have already computed the value of the function for
the sub-problem, we use it and don't recompute it again. There are two main approaches for storing sub-problem solutions: tabulation and memoization.


For example, for computing Fibonacci Numbers,
Simple recursion:

```cpp
int fibonacci(int n)
{
    if(n<=1)
        return n;
    return (fibonacci(n-1)+fibonacci(n-2));
}
```
       
Here we compute values two times, if we store them we don't need to call the function again. 
 
With Dynamic Programming

```cpp
int fibonacci(size_t n)
{
    std::vector<size_t> f;
    f.resize(n, 0);
    f[0] = 0;
    f[1] = 1;
    for (size_t i = 2; i < n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n-1];
}
```


## Tabulation vs Memoization

1) Tabulation: Bottom Up
2) Memoization: Top Down

### Tabulation (Bottom Up)

```cpp
size_t fibonacciRecursiveTabular(size_t n)
{
    std::vector<size_t> f;
    f.resize(n+1, 0);
    f[0] = 0;
    f[1] = 1;
    for (size_t i = 2; i < n+1; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
```

### Memoization (Top Down)

```
std::vector<size_t> fibonacci(20, 0);
size_t fibonacciRecursiveMemoization(size_t n)
{
    if (n <= 1) 
    {
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        return fibonacci[n];
    }
    if (fibonacci[n]) 
    {
        return fibonacci[n];
    }

    fibonacci[n] = fibonacciRecursiveMemoization(n - 1) + fibonacciRecursiveMemoization(n - 2);
    return fibonacci[n];
}
```



|                     | Tabulation  | Memoization  |
| -------------       |-------------| -----|
| State               | State transition is difficult to think.| State transition is difficult to think.     |
| Code                | When code has lot of conditions it gets complicated. | Code is less complicated.     |
| Speed               | Fast as we directly states via table          | Slow, since lots of recursions are required to get the previous state     |
| Sub-problem solving | If all sub-problems must be solved, tabulation outperforms  a top-down memoized by a constant factor. | If some sub-problem needs not to be solved at all, the memoized solution has the advantage of solving only those sub0problems that are required.|
| Table Entries       | All entries are filled one by one | Not all entries are necessarily filled. The table is filled on demand.|






## Coin problem
In this problem we are interested to make a sum of money `x` with a set of coins values `{c1,c2,...ck}` by using the minimum number of coins.
A simple greedy algorithm to the problem always selects the largest possible coin, until the required sum of money has been constructed.
It turns out that if the coins are the euro coins, the greedy algorithm always works.

In the general case, the coin set can contain any coins and the greedy algorithm does not necessarily produce an optimal solution.

For example if the coins are `{1,3,4}` and the target sum is 6, the greedy algorithm produces the solution `4+1+1` while the optimal solution is `3+3`.

```cpp
solve(amount)=min number of coins
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

```cpp
solve(x) = min(solve(x−1)+1, solve(x−3)+1, solve(x−4)+1)

```
The general case for this function would be:

```
c[]={c1,c2,...ck}

solve(x) =∞                          if x<0

solve(x) =0                          if x=0

solve(x) =min(u, solve(x-c[i]) +1)   if x>0
```

Tip: the min of several items in a list can be written as follows;
```
c[]={c1,c2,...ck}
min_value=min(c1,c2,...ck)

u=INF
for (c<sub>i</sub> in c)
    u=min(c<sub>i</sub>,u)
min_value=u
```


## 0-1 Knapsack Problem
Restricts the number of copies of each kind of item to zero or one. Items are **NOT** divisible and you can only carry one instance of an item.
In the optiml solution either an item would be included or excluded. 
Therefore, the maximum value that can be obtained from n items is max of following two values:
1) Maximum value obtained by n-1 items and W weight (excluding nth item).
2) Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).


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

| 3 | 7 | 9 | 2 | 7 |
|---|---|---|---|---|
| 9 | 8 | 3 | 5 | 5 |
| 1 | 7 | 9 | 8 | 5 |
| 3 | 8 | 6 | 4 | 10|
| 6 | 3 | 9 | 7 | 8 |


## MultiStage Graph

## Floyd Warshall Algorithm (All Pairs Shortest Path )

## Bellman Ford Algorithm (Single Source Shortest Path )

## Traveling Salesman Problem
Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city.

```
		 1←---→2
		 ↑ ↖ ↗ ↑
		 |  X  |
		 ↓↙  ↘ ↓
		 4←---→3
```

Adjacency matrix `M`:

```
   1  2  3  4
  ┌           ┐
1 |0  10 15 20| 
2 |5  0  9  10| 
3 |6  13 0  12| 
4 |8  8  9  0 | 
  └           ┘
```


Cost(1,{2,3,4})=min{dist<sub>1→K</sub> +Cost(K,{2,3,4}-{K} )  }

- dist<sub>1→K</sub>: we get this from above matrix
- `{2,3,4}-{K}`: means remain set minus the the vertex `K` (we have to remove `K`)


or in general form:

Cost(i,S)=min{dist<sub>i→K</sub> +Cost(K,S-{K} )  }


```
                                    1
                               /    |    \
                              2     3      4
                            /  \   / \    /  \  
                           3   4  2   4   2   3
                           |   |  |   |   |   |
                           4   3  4   2   3   2
                           |   |  |   |   |   |
                           1   1  1   1   1   1 
```
If we solve the problem from bottom:
```
Cost(4,{∅})= M41 =8 
Cost(3,{∅})= M31 =6  
Cost(2,{∅})= M21 =5  
```
If we go one level higher:

```
Cost(3,{4})=dist<3_4> + Cost(4,{∅})=12+8=20  
Cost(4,{3})=dist<4_3> + Cost(3,{∅})=9+6=15  

Cost(2,{4})=dist<2_4> + Cost(4,{∅})=10+8=18  
Cost(4,{2})=dist<4_2> + Cost(2,{∅})=8+5=13  

Cost(2,{3})=dist<2_3> + Cost(3,{∅})=9+6=15  
Cost(3,{2})=dist<3_2> + Cost(2,{∅})=13+5=18  
```
one level higher:
```
Cost(2,{3,4})=min( dist<2_3> + Cost(3,{4}) +  dist<2_4> + Cost(4,{3}) )=min( 9+20, 10+15 )=25

Cost(3,{2,4})=min( dist<3_2> + Cost(2,{4}) +  dist<3_4> + Cost(4,{2}) )=min( 13+18, 12+13 )=25

Cost(4,{2,3})=min( dist<4_2> + Cost(2,{3}) +  dist<4_3> + Cost(3,{2}) )=min( 8+15, 9+18  )=23
```
one level higher:
```
Cost(1,{2,3,4})=min( dist<1_2> + Cost(2,{3,4}) +  dist<1_3> + Cost(3,{2,4}) ,  dist<1_4> + Cost(4,{2,3})  )=min(10+25,15+25,20+25 )=35
```

## Levenshtein Distance

## Matrix Chain Multiplication
Suppose we need to calculate the following matrix multiplication:

A<sub>5x4</sub>B<sub>4x6</sub>C<sub>6x2</sub>D<sub>6x2</sub>  

We know that the total number of multiplications that we have to do to calculate 

A<sub>5x4</sub>B<sub>4x6</sub>C<sub>6x2</sub> is `5x4x6=120`.

We can do it in different orders:  
`((AxB)xC)xD` or `(AxB)x(CxD)`



If we show it in the form of binary tree with three node (because of three) multipication:
```
     O
   /   \
  O     O
 / \   / \
A   B C   D
```
or 

```
        O
      /   \
     O     O
   /   \
  O     C
 / \  
A   B 
```
For `n` nodes tottal number of trees:

`(2n)!/((n+1)!n!)` or `C(2n,n)/(n+1)`

to solve the best order for multipication, we create two tables:


1)Multiplication table

M[1,2]=A<sub>1</sub> x A<sub>2</sub>

M[1,3]=min ( (A<sub>1</sub> x A<sub>2</sub>)x A<sub>2</sub>  ,  A<sub>1</sub> x (A<sub>2</sub> x A<sub>2</sub> ) )


M[1,3]=min (  M[1,1] + M[2,3] +5x4x2 , M[1,2] + M[3,3] + 5*6*2 )      


M[1,3]=min (0,48+40, 120+0+60)=88


M[2,4]=min ( A<sub>2</sub> x (A<sub>3</sub> x A<sub>4</sub> ) , (A<sub>2</sub> x A<sub>3</sub>)x A<sub>4</sub>  )


M[2,4]=min (  M[2,2] + M[3,4] +4x6x7 , M[2,3] + M[4,4] + 4*2*7 )     

M[2,4]=min (  0+84+168 , 48+0+56) = 104


|   | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 | 0 |120|   |   |
| 2 | x | 0 | 48|   | 
| 3 | x | x | 0 | 84| 
| 4 | x | x | x | 0 | 







Refs: [1](https://cses.fi/book.html),
      [2](https://www.geeksforgeeks.org/tabulation-vs-memoization/)
      [3](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
