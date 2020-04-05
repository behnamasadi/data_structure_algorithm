# Complexity Theory

Complexity theory is about grouping problem together based on their difficulties.
Depending on computational times, algorithms are clustered into two groups:
1) Problems whose solutions time are bounded by polynominal of small degree. i.e.sprting `O(nlog(n))`. (or more accuretly can be decided in polynominal)
2) Problems whose best-known algorithm are non-polynominal. i.e Traveling Salesman `O(2^n * n^2)` or Knapsack `O(2^n/2)`

## Decision Problem: 
Is a question which the answer is either yes or no, for example if a number if prime or list of movies are sorted 


## Polynominal Time
P is a complexity class that represents the set of all decision problems that can be solved in polynomial time.
P is polynomial complexity, or O(n<sup>k</sup>) for some non-negative real number k, such as O(1), O(n<sup>1/2</sup>), O(n<sup>2</sup>), O(n<sup>3</sup>), etc. 
If a problem belongs to P, then there exists at least one algorithm that can solve it from scratch in polynomial time.

Examples of P problems:

* Linear Search `O(n)`
* Binary Search `O(log( n))`
* Insertion Sort `O(n^2)`
* Mege Sort `O(nlog(n))`
* Matrix Multipication `O(n^3)`


## Non-deterministic Algorithm
A non-deterministic algorithm is an algorithm that, even for the same input, can exhibit different behaviors on different runs.
Examples are a concurrent algorithm can perform differently on different runs (due to a race condition) or a probabilistic algorithm's behaviors
 depends on a random number generator.  
We will be using non-deterministic algorithms only at the level of pseudo-code.

The language of non-deterministic algorithms has several reserved words/ functions: choise()/ choose(), fail(), succeed(). These are defined as follows:

1) **choose():** Arbitrarily choosses one element from set S.
4) **fail():** Signal an unsuccessfull solution.
5) **succeed():** Signal a successfull solution.

### Search Algorithm Example

The following search algorithm has complexity of `O(1)`, if the key that we searchig for exist in the array it return successs otherwise failiure.
```
Algorithm Search(array, size, key)
{
        j= choose();
        if(key=array[j])
        {
                write(j);
                succeed();
        }
        write(0);
        fail();
}
```

### Sort Algorithm Example
An other example, sorrting an array ascendingly:

```
Algorithm sort(array, size)
{
        for(i 1 to n)
                B[i]=0;
        fo(i 1 to n)
        {
                j=choose(); //this should correctly find the location of elemnt array[j] in an ascending order
                if(B[j] != 0) // this means we have already place some element in B[j] which is wrong
                {
                        fail();
                }
                B[j]=array[i]
        }

        fo(i 1 to n-1)
        {
                if B[i]>B[i+1] 
                        fail();
        }
        succeed();
}

```
Time complexity of this algorithm is `O(N)`. NP complete problems have non polynominal complexity. Non-deterministic algorithms can turn NP-complete complexity into order of polynominal.

## Non-deterministic Polynomial
NP is the class of decision problems which can be solved in polynomial time by a non-deterministic **turing machine**. Equivalently, it is the class of problems which can be verified in polynomial time by a deterministic **turing machine**. 



It is easy to see that there NP-Hard problems that are not NP-complete. Only a descision problmen can be NP-Complete. however an optimisation
 problem can be NP-hard.


Solve: 
        For instance given all pieces of a puzzle, is a given solution is correct? very easy just by looking
Verify:
        For instance given all pieces of a puzzle, is the set a complete puzzle? not easy

SAT is the hardest problem in NP. SAT encapsulate all problems in NP and is able to represent all problems in NP
Any problem in NP can be transformed into SAT

All problems in NP-complete are the same since they can all be used to solve each other.

* Sudoko
* Rubik Cube
* Jigsaw
* Mario
* Register Allocation
* Protein Structure Prediction
* Edit Distace

### Non-deterministic Polynomial Complete
A problem that is NP-Complete has the property that it can be solved in polynominal time if and only of all other NP-complete problems can also be solved in polynominal time. NP-complete is the intersection of NP-hard and NP. Equivalently, NP-complete is the class of decision problems in NP to which all other problems in NP can be reduced to in polynomial time by a deterministic **turing machine**.

### Examples
* Boolean satisfiability problem (SAT) consist of the following:
1) Variables:X1,X2, X3 {true/1, 0,false}
2) Operator "not" ~
3) Operator "and" /\
4) Opeartor "or": \/

A boolean formula with `N` variables X1, X2,..,XN, Can you set the variables to a combination of true/ false so that the formula becomes true.

`(X1 /\ X2) \/ (X1 /\ ~X1) \/ X2`

X1:0
X2:1

* Knapsack
* Traveling Salesman
* Graph Coloring
* Hamilton Cycle
* Subset Sum() 
        - Selecting a subset of number from a random list such that adds up to zero.
* Vertex Cover
* Clique


* 3-SAT Problem
This is the problem where in we are given a conjunction (ANDs) of 3-clause disjunctions (ORs), statements of the form.

```
(x_v11 OR x_v21 OR x_v31) AND 
(x_v12 OR x_v22 OR x_v32) AND 
...                       AND 
(x_v1n OR x_v2n OR x_v3n)
```
where each x_vij is a boolean variable or the negation of a variable from a finite predefined list (x_1, x_2, ... x_n).
It can be shown that every NP problem can be reduced to 3-SAT


### Non-deterministic Polynomial Hard
NP-hard is the class of decision problems to which all problems in NP can be reduced to in polynomial time by a deterministic Turing machine.
If an NP-Hard problem can be solved in ploynominal time, then all NP-complete problems can be solved in polynominal time.
Optimisation problem, i.e. Knapsack



## EXPTIME

Beyond P and NP there are some problems that hard to solve and verify the solution. Given a random chessboard it's not clear what would be 
the best move. Also its not obvious to verify if the move was the correct one.  
* Checkers
* Chess
* Go
* Succinct Circuits
* Halt in K




## Reduction
Problem `A` reduces into problem `B`, if we can use a solution for problem `B` to solve problem `A`, meaning that A is no harder than B.
We do this by a quick conversion from problem A to problem B, use the B solver to solve the problem and finally use that solution for problem A.




Refs: [1](https://cs.nyu.edu/courses/spring03/G22.2560-001/nondet.html),
      [2](https://www.youtube.com/watch?v=OY41QYPI8cw)
