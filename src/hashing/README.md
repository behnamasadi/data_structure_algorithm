- [x] Finish my changes
- [ ] This page needs some clean up.

# Hashing
1) It is useful for searching.
2) Linear search `O(N)`
3) Binary search (keys must be sorted) `O(Log2(N))` hash search `O(1)`

```
Key Space            Hash Table

                       ┌ ┐0
                       |-|1
                       |-|2
┌  ┐  /--------------->|-|3
|9 | /                 |-|4
|3 |/                  |-|5
|6 |------------------>|-|6
|10|---------------\   |-|7
|15|                \  |-|8
|9 |                 \ |-|9
|4 |                  \|-|10
└  ┘                   |-|11
                       |-|12
                       |-|13
                       |-|14
                       |-|15
                       |-|16
                       |-|17
                       └ ┘
```


### Mapping Functions
1) One-One i.e `H(x)=x`
2) One-Many
3) Many-One i.e `H(x)=mode(x,m)=x%m`
4) Many-Many

Ideal hash function has one-one function
Insertion: `O(1)`  
Delete: `O(1)`  
Search: `O(1)`    

Cons: lot of space required.


## Collision
**Open hashing:** We will consume more space than hash space that we have.
## Chaining

`H(x)=x%10`

Our hash table is a head pointer to a linked list. The keys must be inserted in a sorted order.

```
Keys           Hash Table

16               0┌ ┐      
12               1|-|
25               2|-| -> 12 -> 122
39               3|-|
6                4|-|
122              5|-| -> 5 -> 25 -> 75
5                6|-| -> 6 -> 16
68               7|-|
75               8|-| -> 68
                 9|-| -> 39
                10└ ┘
```
#### Search
`key 75 -> H(75)=5`

#### Loading Factor:  
```
(Number of Keys)/(Size of Hash Table)

N=100, Size_of_Hash_Table=10

λ=Loading Factor=100/10
```
Analysis of hash table is based on loading factor, it means at each location we expecting 10 keys.

In chaining it could be greater than 1. For Linear probing, the size of the table isfixed therefore
the loading factor is smaller than 1. Loading factor should not exceed 0.5. At most half the table should be filled.
The reason is, keeping  searching fast. We stopped searching when we reached an empty cell.

```
Avgsuccessfull search: t=(1/λ)ln(1/(1/1-λ))
Avgsuccessfull unsearch:t=1/(1/1-λ)
```
#### Drawback of linear probing:
Waste of space (half of the space is free)
primary clustreing: A block of clustres formed.  

Deletion: need rehashing. When we delete an elements, we might create a gap. If the following elemnt is not on its owns cell
Sometimes we have to relocated the following. elemnts (remember the stop criteria for search)  
That's why deletion is not recomanded. So we take everything out and put them back again.
We can simply put flag for deletion.


#### Quadratic Probing:
To avoid formation of blocks of elements, 

```
                 0┌  ┐      
                 1|--|
                 2|--|
23               3|23|
43               4|43|
12               5|--|
27               6|--|
                 7|13|
                 8|27|
                 9|--|
                10└  ┘

Avgsuccessfull search: t=-ln(1-λ)/λ
Avgsuccessfull unsearch:t=1/(1/1-λ)
```



### Double Hashing
```
H1(x)=x%10
H2(x)=R- (x%R)
H(X)=(H1(X)+i*H2(X))%10
```
R is last prime number.  
It should never give 0.    
It should utilize free spaces.  
```
R=7
H(5)=5
H(25)=5 collision --> H(25)=(H1(25)+1*H2(25))%10=(5+1*( 7 - ( 25%7 ) )  )%10=8
H(15)=5 collision --> H(15)=(H1(15)+1*H2(15))%10=(5+1*( 7- ( 15%7 ) ) )%10=6

                 0┌15┐      
                 1|--|
                 2|35|
5                3|  |
25               4|95|
15               5|5 |
35               6|--|
95               7|  |
                 8|25|
                 9|--|
                10└  ┘
```

### Hashing Functions
1) Mod
2) MidSquare
3) Folding


Search: 
    Successful search: 1 Operation for computing hash + Avg time for fining the key=1 + (λ/2)
    UnSuccessful search: 1 Operation for computing hash + time for fining the key= 1+ λ




Closed Hashing: We only use the hash space that we have, we don't increase the space.

2)Open Addressing: If there is a collision, we store the key in some free space in the
hash space using one of the following methods:
a) Linear Probing
b) Quadratic Probing
c) Double Hashing

3)Modulo (%) Hash Function  




4)Drawbacks
Size that the array take might much bigger than number of keys (elements) and lots of space wasted.
5)Solutions

Imaging you need to store some data about employees info, phone, name, address, etc
solution:


1)Array:
    search take linear time
    In sorted array search can be done in O(Log(n)) using binary search tree but insert and delete operations are expensive
    
2)Linked List:
    search take linear time
    
3)Balance BST:
    Insertion: O(Log(n))
    Delete: O(Log(n))
    Search: O(Log(n))
    
    First problem with this solution is extra space required is huge. For example if phone number is n digits, we need O(m * 10n) space for table where m is size of a pointer to record. Another problem is an integer in a programming language may not store n digits.

    
4)Direct Access Table:
    Insertion: O(1)
    Delete: O(1)
    Search: O(1)
    cons: lot of space
5)Hash Table
    Hashing is an improvement over Direct Access Table. The idea is to use hash function that converts a given phone number or any other key to a smaller number and uses the small number as index in a table called hash table.
    
    Insertion: O(1)
    Delete: O(1)
    Search: O(1)

    
A good hash function should have following properties
1) Efficiently computable.
2) Should uniformly distribute the keys (Each table position equally likely for each key)

Collision Handling:
    1)Chaining:
    The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.
    2)Open Addressing: 
    In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we one by one examine table slots until the desired element is found or it is clear that the element is not in the table. (linear, quadratic and double probing).
    


Hash Function Ideas:
 Keys should be uniformly distributed.
 If you are using linear probing, then the size of the hash table  should be double of the keys. loading factor shoudl be less than 0.5
	Mode
	Mid square
	Folding
String keys can be written with their ascii number and then perform folding

    
hash-table-vs-stl-map
https://www.geeksforgeeks.org/hash-table-vs-stl-map/
*/
