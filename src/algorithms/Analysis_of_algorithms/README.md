# Analysis of Algorithms

## Asymptotic analysis
Asymptotic analysis a method of describing limiting behavior. In asymptotic analysis we evaluate the performance of an algorithm
 in terms of input size. We calculate, how does the time (or space) taken by an algorithm increases with the input size.

We can have three cases to analyze an algorithm:
1) Worst Case
2) Average Case
3) Best Case


The following 3 asymptotic notations are mostly used to represent time complexity of algorithms.

1) **Big O Notation** : The Big O notation defines an upper bound of an algorithm.

2) **Θ Theta notation**: The theta notation bounds a functions from above and below, so it defines exact asymptotic behavior.

3) **Ω Notation**: The omega notation provides an asymptotic lower bound.

## Analysis of Loops

### O(1)
Time complexity of a function (or set of statements) is considered as O(1) if it doesn’t contain loop, recursion and call 
to any other non-constant time function.

Examples:
**O(1)**:
```
std::swap(a,b)
```

**O(1)**:
```
void func(int n)
{

   for (int i = 1; i <= c; i++) {  
        // some O(1) expressions
   }
}
```


### O(n)
Time Complexity of a loop is considered as `O(n)` if the loop variables is incremented / decremented by a constant amount. 
For example following functions have `O(n`) time complexity.

```
void func(int n)
{
   // Here c is a positive integer constant   
   for (int i = 1; i <= n; i += c) 
   {  
        // some O(1) expressions
   }

   for (int i = n; i > 0; i -= c) 
   {
        // some O(1) expressions
   }
}
```

### O(n^c)
Time complexity of nested loops is equal to the number of times the innermost statement is executed. For example the following sample
 loops have `O(n^2)` time complexity:

```
void func(int n)
{  
   for (int i = 1; i <=n; i += c) {
       for (int j = 1; j <=n; j += c) {
          // some O(1) expressions
       }
   }

   for (int i = n; i > 0; i -= c) {
       for (int j = i+1; j <=n; j += c) {
          // some O(1) expressions
   }

}
```

### O(Logn)
Time Complexity of a loop is considered as` O(Logn)` if the loop variables is divided / multiplied by a constant amount.
Please note in the case of division, loop is downward and start at `n`. 

```
void func(int n)
{ 
   for (int i = 1; i <=n; i *= c) 
   {
       // some O(1) expressions
   }
   for (int i = n; i > 0; i /= c) 
   {
       // some O(1) expressions
   }

}
```


### O(LogLogn)
Time Complexity of a loop is considered as `O(LogLogn)` if the loop variables is reduced / increased exponentially by a constant amount.

```
void func(int n)
{ 
   // Here c is a constant greater than 1   
   for (int i = 2; i <=n; i = pow(i, c)) 
   { 
       // some O(1) expressions
   }
   //Here fun is sqrt or cuberoot or any other constant root
   for (int i = n; i > 1; i = fun(i)) 
   { 
       // some O(1) expressions
   }
}
```

### Multiple consecutive loops

When there are consecutive loops, we calculate time complexity as sum of time complexities of individual loops.

```
void func(int n)
{ 
   for (int i = 1; i <=m; i += c) 
   {  
        // some O(1) expressions
   }
   for (int i = 1; i <=n; i += c) 
   {
        // some O(1) expressions
   }
}
```   
Time complexity of above code is `O(m) + O(n)` which is `O(m+n)`.

## Complexity of recursive functions
### Master Theorem For Subtract and Conquer Recurrences

Let `T(n)` be a function defined on positive n as following:

```
T(n)<= c,              if n<=1
T(n)<=aT(n-b)+f(n)     n>1
```

for some constants `c, a>0, b>0, k>=0` and function `f(n)`. If `f(n)` is O(n<sup>k</sup>), then

1. If a<1 then T(n) = O(n<sup>k</sup>)
2. If a=1 then T(n) = O(n<sup>k+1</sup>)
3. if a>1 then T(n) = O(n<sup>k</sup>a<sup>n/b</sup>)


```
T(n) = aT(n-b) + f(n)
T(n-b) = aT(n-2b) + f(n-b)
T(n-2b) = aT(n-3b) + f(n-2b)
```


T(n-b) = a<sup>2</sup>T(n-3b) + af(n-2b) + f(n-b)  
T(n) = a<sup>3</sup>T(n-3b) + a<sup>2</sup>f(n-2b) + af(n-b) + f(n)  
T(n) = Σ<sub>i=0 to n</sub> a<sup>i</sup>f(n-ib) + constant, where f(n-ib) is O(n-ib)  
T(n) = O(n<sup>k</sup> Σ<sub>i=0 to n/b</sub> a<sup>i</sup> )  

Therefore:

If a<1 then Σ<sub> i=0 to n/b</sub> a<sup>i</sup> = O(1), T(n) = O(n<sup>k</sup>)

If a=1 then Σ<sub> i=0 to n/b </sub>a<sup>i</sup> = O(n), T(n) = O(n<sup>k+1</sup>)

If a>1 then Σ<sub>i=0 to n/b</sub> a<sup>i</sup> = O(a<sup>n/b</sup>), T(n) = O(n<sup>k</sup>a<sup>n/b</sup>)

### Example 1

```
T(n) =    3T(n-1), n>0
T(n) =    c,       n<=0
```
`a=3`, `b=1`, `f(n)=0` so `f(n)` is `O(n<sup>k</sup>)` and `k=0`;

Since `a>0`, T(n) = O(n<sup>k<sup>a<sup>n/b</sup>)
T(n)= 3n


### Example 2

```
T(n) =   T(n-1) + n(n-1), if n>=2
T(n) =   1, if n=1
```
`a=1`, `b=1`, `f(n)=n(n-1)` so `k=2`;

T(n)= O(n<sup>3</sup>)

### Example 3
fibonacci number:
```
T(n) = T(n-1) + T(n-2)
```
In the worst case `T(n-1)=T(n-2)` so the fibonacci can  can be rewritten as:

```
T(n) = 2T(n-1)
```

`f(n) = O(1)`, `k=0`, `a=2`, `b=1`  
T(n) = O(2<sup>n</sup>)


### Master Theorem for Divide and Conquer Recurrences 


Let `T(n)` be a function defined on positive n as following:

```
T(n)<= c,              if n<=1
T(n)<=aT(n/b)+f(n)     n>1
```

The running time is in the following form :

T(n)=aT(n/b)+Θ(n<sup>k</sup>Log<sup>p</sup>n )

Then, 

1) if a > b<sup>k</sup>, then T(n) = θ(nlogba)


2) if a = bk, then
(a) if p > -1, then T(n) = θ(nlogba logp+1n)
(b) if p = -1, then T(n) = θ(nlogba loglogn)
(c) if p < -1, then T(n) = θ(nlogba)


3) if a < bk, then
(a) if p >= 0, then T(n) = θ(nk logpn)
(b) if p < 0, then T(n) = θ(nk)


### Example 1
### Example 2
### Example 3
### Example 4


Ref: [1](https://www.geeksforgeeks.org/master-theorem-subtract-conquer-recurrences/),
[2](https://www.geeksforgeeks.org/advanced-master-theorem-for-divide-and-conquer-recurrences/),
[3](https://www.eecis.udel.edu/~saunders/notes/recurrence-relations.pdf),
[4](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))
