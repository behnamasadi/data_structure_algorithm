# Special Matrices
### 1) Diagonal
```
A[i,j]=0 if i!=j
A[i,j]=non-zero if i=j
```

### 2) Lower Triangular
```
A[i,j]=0 if i<j
A[i,j]=non-zero if i>=j
```
Total number of elements:
`N^2 - N*(N+1)/ = N*(N-1)/2`

if we store the matrix in row major form: 
`Index(A[i,j])=j-1+ i*(i-1)/2`

### 3) Upper Triangular
```
A[i,j]=non-zero if i<=j
A[i,j]=0 if i>j
```

if we store the matrix in row major form: 

```
┌                    ┐
|a00 a01 a02 a03 a04 |
|0   a11 a12 a13 a14 |
|0   0   a22 a23 a24 |
|0   0   0   a33 a34 |
|0   0   0   0   a44 |
└                    ┘
Row majoring
  0   1   2   3   4     5   6   7   8     9   10  11   12  13    14
┌--------------------------------------------------------------------┐
|a00 a01 a02 a03 a04 | a11 a12 a13 a14 | a22 a23 a24 | a33 a34 | a44 |
└--------------------------------------------------------------------┘
└       Row 0        ┘└      Row 1     ┘└    Row 2   ┘└  Row 3 ┘└Row4┘

A mxn

Address(A[i][j])=Base_Address + N + N-1 + N-2 + ... + N-(i-1) + (j-i)
                =Base_Address + i*N - (i-1)(i)/2 +(j-i)
```

Explenation:
`(j-i)`, because the abount of columns that we have to go forward is dependent on the
row number, for instnce compare the location of `a03` with `a13` and `a23`.


if we store the matrix in column major form:   

`Index(A[i,j])=N + N-1 + N-2 +N-(j-2)+(i-j) = N*(j-1)-(j-2)*(j-1)/2 + (i-j)`

### 4) Symmetric
```
A[i,j]=A[j,i]
```
It can be represented as either lower or upper triangular matrix.

### 5) Tridiagonal

```
┌               ┐
|x x 0 0 0 0 0 0|
|x x x 0 0 0 0 0|
|0 x x x 0 0 0 0|
|0 0 x x x 0 0 0|
|0 0 0 x x x 0 0|
|0 0 0 0 x x x 0|
|0 0 0 0 0 x x X|
|0 0 0 0 0 0 x x|
└               ┘

A[i,j]=non-zero if |i-j|<=1
```

Total number of elements `N+N-1+N-1=3*N-2`


### 6) Band  
 Band matrix is a sparse matrix whose non-zero entries are only on diagonal band, and zero or more diagonals on either side.
 Matrix A has lower bandwidth `p` if `aij=0` for `i>j+p` and upper bandwidth q if  `aij=0` for `j>i+q`
 Matrix has lower bandwidth `3` and upper bandwidth `1`
 ```
┌              ┐
|x x 0 0 0 0 0 |
|x x x x 0 0 0 |
|x x x x x 0 0 |
|0 x x x x x 0 |
|0 0 x x x x x |
|0 0 0 x x x x |
|0 0 0 0 x x x |
└              ┘
```
Example: `A5x7` upper triangular matrix with `p=0`, `q=6`

```
┌             ┐
|x x x x x x x|
|0 x x x x x x|
|0 0 x x x x x|
|0 0 0 x x x x|
|0 0 0 0 x x x|
└             ┘
 
 ```
 
### 7) Toeplitz
```
┌          ┐
|a b c d e |
|f a b c d |
|g f a b c |
|h g f a b |
|i h g f a |
└          ┘
A[i,j]=A[i-1,j-1]


  0   1   2   3   4    5   6   7   8 
┌-------------------------------------┐
| a   b   c   d   e  | f   g   h   i  |
└-------------------------------------┘
└       Row         ┘└      Col      ┘

For elements in upper triangular:
A[i,j]=Base_Address + j-i

For elements in lower triangular:
A[i,j]=Base_Address + N+ i-j-1

```
We only need to store the first row and the first column.

### 8) Sparse Matrix

Its a matrix than number of zero elements are more than the number of non zero elements.
Instead of storing all values in a matrix for we can only store non-zero elements.
There are several approaches:

**1) Coordinate list/ 3 column representation**  
**2) Compressed sparse rows**  
**3) Sparse Matrix using Linked List**  

#### 1) Coordinate list/ 3 column representation
```
 1 2 3 4 5 6 7 8 9
┌                 ┐
|0 0 0 0 0 0 0 3 0| 1
|0 0 8 0 0 1 0 0 0| 2
|0 0 0 0 0 0 0 0 0| 3
|4 0 0 0 0 0 0 0 0| 4
|0 0 0 0 0 0 0 0 0| 5
|0 0 2 0 0 0 0 0 0| 6
|0 0 0 6 0 0 0 0 0| 7
|0 9 0 0 5 0 0 0 0| 8
└                 ┘
```
First row: number of rows in matrix, number of cols in matrix, number of non-zero elements.
```
row  |  column  |  element
 8   |    8     |    8
 1   |    8     |    3
 2   |    3     |    8
 2   |    6     |    1
 4   |    1     |    4
 6   |    3     |    2
 7   |    4     |    6
 8   |    2     |    9
 8   |    5     |    5
```

Addition of two sparse matrices in coordinate list:
iterate over rows,   
1) If row index in first matrix is smaller, copy it to the output matrix, increase the value of iterator for first matrix.
2) If row index in first matrix is bigger, copy the value from the second matrix to the output matrix, increase the value of the iterator of the first matrix.
3) If the row numbers are matching, check the communal numbers and follow the same policy but for columns from `step 1` and `step 2`.
If the column number are also matching add them and put the in the output matrix.

#### 2) Compressed sparse rows
We use 3 array to represent the matrix:

1) Array list of non-zero elements:
`[3 8 1 4 2 6 9 5]`

2) Array for rows, an element for every row (also an extra 0 at the beginning), the value increase for every element accumulatively:
```
IA=[0 1 3 3 4 4 5 6 8]
    
```

3) Array for columns, every element point to the index column of elements in the matrix
```
IJ=[8 3 6 1 3 4 2 5] <=column of the elements in the matrix.
    3 8 1 1 2 6 9 5 <=value of the elements in the matrix.
```



#### 3) Sparse Matrix using Linked List

