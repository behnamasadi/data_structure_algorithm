
# Divide and conquer

It is a strategy for solving problems. If a problem of size `n` and it is large you can divide it into `k` small sub-problems. 
Solve sub-problems separately and combine them to get the solution for main problem. If sub-problems, divide it again and again 
until it is easily solved.


The sub-problems should be the same as main problem, for instance if the main problem is sorting the sub-problems should be 
sorting as well. If task are different for each sub-problems then it is not divide-and-conquer. This strategy is recursive in nature.
You also need some solution to combine the solution from sub-problems, if you can't find a solution, you can not use divide-and-conquer
strategy.

Example of problems thatg can be solved with divide and conquer:
1) Binary Search.  
2) Finding Max/ Min.  
3) Merge Sort.  
4) Quick Sort.  
5) Strassen Matrix Multiplication.  

## Strassen Matrix Multiplication  
In **divide and conquer** and divide problems into sub-problems and if sub-problem is small enough we solve it and then we merge the results. Consider matrix multiplication, it has three loops:

A<sub>MXO</sub>*B<sub>OXN</sub>=C<sub>MXN</sub>

```
for(i=0;i<M;i++)
{
	for(j=0;j<N;j++)
	{
		C[i,j]=0;
		for(k=0;k<O;k++)
		{
			C[i,j]=C[i,j]+A[i,k]*B[k,j];
		}
	}
}
```
we can just compute these three loops if they are small enough, i,e. in order of 2:

```
C[1,1]=A[1,1]*B[1,1] + A[1,2]*B[2,1];
C[1,2]=A[1,1]*B[1,2] + A[1,2]*B[2,2];
C[2,1]=A[2,1]*B[1,1] + A[2,2]*B[1,2];
C[2,2]=A[2,1]*B[1,2] + A[2,2]*B[2,2];
```
So we divide our matrices until they are `2x2`. If their dimensions is not in order 2, we pad some zero elements.

```
┌               ┐ ┌               ┐
|a11 a12 a13 a14| |b11 b12 b13 b14|
|a21 a22 a23 a24| |b21 b22 b23 b24|
|a31 a32 a33 a34|*|b31 b32 b33 b34|
|a41 a42 a43 a44| |b41 b42 b43 b44|
└               ┘ └               ┘

A11 represent the following:
    ┌       ┐
    |a11 a12|
A11=|a21 a22|
    └       ┘
Then our matrix multiplication is:

┌       ┐ ┌       ┐
|A11 A12| |B11 B12|
|A21 A22|*|B21 B22|
└       ┘ └       ┘

or

┌                                      ┐
|A11*B11 + A12*B21    A11*B12 + A12*B22|
|A21*B11 + A22*B21    A21*B12 + A22*B22|
└                                      ┘
```

### Matrix Multiplication Algorithm

```
MM(A,B,n)
{
	if(n<=2)
	{
		C[1,1]=A[1,1]*B[1,1] + A[1,2]*B[2,1];
		C[1,2]=A[1,1]*B[1,2] + A[1,2]*B[2,2];
		C[2,1]=A[2,1]*B[1,1] + A[2,2]*B[1,2];
		C[2,2]=A[2,1]*B[1,2] + A[2,2]*B[2,2];
	}
	else
	{
		MM(A11,B11,n/2) + MM(A12,B21,n/2);
		MM(A11,B12,n/2) + MM(A12,B22,n/2);
		MM(A21,B11,n/2) + MM(A22,B21,n/2);
		MM(A21,B12,n/2) + MM(A22,B22,n/2);
	}
}

```






