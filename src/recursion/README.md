## Type of recursion
### Tail Recursion 
if the recursive function that calls itself is the last statement in the function. After that call
the function is not performing anything. Tail recursion can be easily written iteratively and which is more efficient.

### Head Recursion
if the function that calls itself does not perform any calculation before calling itself and does the job only after return.
You can not easily write a Head Recursion function interactively.

### Tree Recursion
Linear recursion: If a recursive function only calls itself once, it is  linear recursive function. In tree recursion, a function calls
itself more than once. For instance of it calls itself 2 times, totall number calls would be like a binary tree, so it would 

`Total number of calls: sum (1+2+4+ ...2^n)=2^(n+1)-1`


### Indirect Recursion
If some functions call each other in way that forms a cycle it is an indirect recursion.

`A->B->C->A`

### Nested Recursion
A recursive function calls a function with the function as input parameter.

