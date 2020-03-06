

# Heap
Heap is a complete binary tree. It means if you represent it as an array there should be no blank element in the array. In other words, in height-1 level in the tree, it is a full tree, and in the last level, the nodes are populated from left to right.
Mostly heap is implemented using arrays. Heap could be max or min. duplicated elements are also allowed. Max (Min) heap: every element is greater (smaller) than its child and all decedents.

Examples of Min Heap:
```

            10                      10
         /      \               /       \
       20        100          15         30
      /                      /  \        /  \
    30                     40    50    100   40
```
Examples of Max Heap:
```
                                   17
                                /       \
                              15         10
                             /  \        /
                            6    10     7
```
Since heap is a complete binary tree, the height of the tree will be always `log2(n)`.

Heap is **NOT** made for searching purposes!

Following table shows indexes of other nodes for the ith node, i.e., `Arr[i]`:  
`Arr[i/2]`:	            returns the parent node.  
`Arr[2*i]`:	returns the left child node.  
`Arr[2*i+1]`:	returns the right child node.   

 ## Operations on Heap 

### 1) insert()
In a max heap, we add a new key at the end of the tree (last index in the array representation, let say at m).
If the new key is greater than its parent (`array[m/2]`), we swap the values and check again, until it is not
bigger than it's parent.
Inserting a new key takes `O(Logn)` time.

Lets say we want to insert 40 into this tree:
```
                30
             /       \
           20          15
          /  \        /  \
         5    10     12   6
```
Array representation:
```
Elements:   30 20 15 5  10 12 6
Index:      1  2  3  4  5  6  7
```
We add 40, and we compare it with its parent 8/2
```
Elements:   30 20 15 5  10 12 6  40
Index:      1  2  3  4  5  6  7  8
```
it is bigger than its parent:
 `40 > array[8/2]=5`
so we swap them: `swap(40,5)`
```
Elements:   30 20 15 40 10 12 6  5
Index:      1  2  3  4  5  6  7  8
```
again it is bigger than its parent:
`40 > array[4/2]=20`
so we swap them: `swap(40,20)`
```
Elements:   30 40 15 20 10 12 6  5
Index:      1  2  3  4  5  6  7  8
```
again it is bigger than its parent:
`40 > array[2/1]=30`
so we swap them: `swap(40,30)`
```
Elements:   40 30 15 20 10 12 6  5
Index:      1  2  3  4  5  6  7  8
```
done.

### 2) delete():
From the root you can only delete the root.
After deleting the root, put the last element in the array representation in  the root and compare the value with its children
if the node is smaller than it's children swap it with max value and continue repeting the same with the swaped node.

Deleting a key also takes `O(Logn)` time.

### 3) inplace heap creation()
Just call insert elements one by one for inserting elements.

## Applications of Heaps 
1) **Heap Sort**: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) **Priority Queue**: Priority queues can be efficiently implemented using Binary Heap because it supports
insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time.
Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) **Graph Algorithms**: The priority queues are especially used in graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

4) Many problems can be efficiently solved using heaps:
    - K’th Largest Element in an array.-
    - Sort an almost sorted array.
    - Merge K sorted arrays.
