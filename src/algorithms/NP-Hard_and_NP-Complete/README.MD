# P (polynomial) vs NP (non-deterministic polynomial) vs NP Complete vs NP Hard
Let's define some term first:

## Nondeterministic algorithm
A nondeterministic algorithm is an algorithm that, even for the same input, can exhibit different behaviors on different runs.
Examples are a concurrent algorithm can perform differently on different runs (due to a race condition) or a probabilistic algorithm's behaviors
 depends on a random number generator.  
We will be using non-deterministic algorithms only at the level of pseudo-code.

The language of non-deterministic algorithms consists of six reserved words: choose, pick, fail, succeed, either/or . These are defined as follows:

1) **choose** X satisfying P(X). Consider alternatively all possible values of X that satisfy P(X), and proceed in the code. One can imagine the code as forking at this point, with a separate thread for each possible value of X. If any of the threads succeed, then the choice succeeds. If a choose operator in thread T generates subthreads T1 ... Tk, then T succeeds just if at least one of T1 ... Tk succeeds.
2) If thread T reaches the statement "choose X satisfying P(X)" and there is no X that satisfied P(X), then T fails.

3) **pick** X satisfying P(X). Find any value V that satisfies P(V) and assign X := V. This does not create a branching threads.
4) **fail** The current thread fails.
5) **succeed** The current thread succeeds and terminates.
6) **either** S1 **or** S2 **or** S3 ... **or** Sk. Analogous to choose. Create k threads T1 ... Tk where thread Ti executes statement Si and continues.


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

## Polynominal Time
P is polynomial complexity, or O(n<sup>k</sup>) for some non-negative real number k, such as O(1), O(n<sup>1/2</sup>), O(n<sup>2</sup>), O(n<sup>3</sup>), etc. 
If a problem belongs to P, then there exists at least one algorithm that can solve it from scratch in polynomial time.

Examples of P problems:

1) Linear Search-O(n)
2) Binary Search-O(log( n))
3) Insertion Sort-O(n^2)
4) Mege Sort-O(nlog(n))
5) Matrix Multipication O(n^3)


## Non-deterministic Polynomial
NP is the class of decision problems which can be solved in polynomial time by a non-deterministic Turing machine. Equivalently, it is the class of problems which can be verified in polynomial time by a deterministic Turing machine. 


1) 0/1 Knapsack-O(2^n)
2) Traveling Salesman-O(2^n)
3) Graph coloring-O(2^n)
4) Hamilton Cycle-O(2^n)
5) Subset sum problem-O(2^n)

## Non-deterministic Polynomial Hard
NP-hard is the class of decision problems to which all problems in NP can be reduced to in polynomial time by a deterministic Turing machine.

## Non-deterministic Polynomial Complete
NP-complete is the intersection of NP-hard and NP. Equivalently, NP-complete is the class of decision problems in NP to which all other problems in NP can be reduced to in polynomial time by a deterministic Turing machine.


Refs: [1](https://cs.nyu.edu/courses/spring03/G22.2560-001/nondet.html)
