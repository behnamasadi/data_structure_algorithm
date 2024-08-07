
# Row Major VS Column Major


### Logical Address

```
a3x4
---------------------------------
|  a00  |  a01  |  a02  |  a03  |
---------------------------------
|  a10  |  a11  |  a12  |  a13  |
---------------------------------
|  a20  |  a21  |  a22  |  a33  |
---------------------------------
```
Address in memory stores in array form, so it could be any of these:

### Row Major

```
-------------------------------------------------------------------------------------------------
|  a00  |  a01  |  a02  |  a03  |  a10  |  a11  |  a02  |  a12  |  a22  |  a03  |  a13  |  a33  |
-------------------------------------------------------------------------------------------------
└            Row 0              ┘└             Row 1            ┘└              Row 2           ┘
```
for a `mxn` array:
```
Address(a[i][j])=Base_Address +[i*n+j]*Number_of_Bytes
```


### N Dimentional Array (Row Major):
for a array of shape: `d1xd2xd3xd4`

```
Address(A[i][j][k][l])=Base_Address + [i*d2*d3*d4 + j*d3*d4 + k*d4 + l ]*Number_of_Bytes
                      =Base_Address + [ [ [i*d2 + j]*d3  + k]*d4 + l ]*Number_of_Bytes
```



C/C++ use row major for storing 2D arrays.

**If we use index from 1 onward** we have to use the following formula which has 2 operation more:
```
Address(a[i][j])=Base_Address +[(i-1)*n+(j-1)]*Number_of_Bytes
```
### Column Major

```
-------------------------------------------------------------------------------------------------
|  a00  |  a10  |  a20  |  a01  |  a11  |  a21  |  a12  |  a13  |  a20  |  a21  |  a22  |  a33  |
-------------------------------------------------------------------------------------------------
└         Col 0         ┘└        Col 1        ┘└         Col 2        ┘└         Col 3        ┘
```

for a `mxn` array:
`Address(a[i][j])=Base_Address +[j*m+i]*Number_of_Bytes`


=> O(n)
### N Dimentional Array (Col Major):
```
Address(A[a][b][c][d])=Base_Address + [d*d3*d2*d1 + c*d2*d1 + b*d1 + a ]*Number_of_Bytes
```
### Array Abstract Data type (Representation of data and set of operation on data )
1) Insert  
2) Delete  
3) Search  
I) Linear Search   
Successful: `best:O(1) worst:O(n) avg: O(n)=(1+2+3+...+n)/n=(n*(n+1)/2)/n=(n+1)/2`
Unsuccessful: O(n)  
II) Binary Search  
