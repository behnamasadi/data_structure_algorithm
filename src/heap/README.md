

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

Following table shows indexes of other nodes for the i'th node, i.e., `Arr[i]`:  

- **Root Element**: `Arr[0]`
- **Left Child of `i`**: `Arr[(2 * i) + 1]`
- **Right Child of `i`**: `Arr[(2 * i) + 2]`
- **Parent of `i`**: `Arr[(i - 1) / 2]`




## Operations on Heap 

### 1. Creating a Heap
Creating a min heap or max heap involves inserting elements one by one into the heap while maintaining the heap property. Here's how to create both types of heaps by insertion:


###1.1 Steps to Create a Min Heap by Insertion

A **min heap** is a binary tree where the value of each node is less than or equal to the values of its children.

1. **Start with an Empty Heap:**
   - Begin with an empty binary tree (array representation is often used).

2. **Insert the Element:**
   - Insert the new element at the end of the tree (as the last element in the array).

3. **Heapify Up (Bubble Up):**
   - Compare the inserted element with its parent node.
   - If the inserted element is smaller than its parent, swap them.
   - Continue this process (bubble up) until the heap property is restored (the inserted element is not smaller than its parent).
   - If the inserted element becomes the root, stop the process.

4. **Repeat:**
   - Repeat the insertion and heapify up process for each element until all elements are inserted and the heap property is maintained.

### Example for Min Heap:
Let's insert the following numbers into both a min heap and a max heap: `{7, 10, 5, 3, 4, 15, 2}`. I'll show the heap array at each step.


1. **Insert 7**:
   - Heap: `[7]`
  
2. **Insert 10**:
   - Heap: `[7, 10]` (No change needed as 10 > 7)

3. **Insert 5**:
   - Heap: `[5, 10, 7]` (5 < 7, so swap 5 and 7)

4. **Insert 3**:
   - Heap: `[3, 5, 7, 10]` (3 < 10, swap 3 and 10, then  3 < 5, so swap 3 and 5)

5. **Insert 4**:
   - Heap: `[3, 4, 7, 10, 5]` (4 < 5, so swap 4 and 5)

6. **Insert 15**:
   - Heap: `[3, 4, 7, 10, 5, 15]` (No change needed as 15 > 7)

7. **Insert 2**:
   - Heap: `[2, 4, 3, 10, 5, 15, 7]` (2 < 3, swap 2 and 3, then swap 2 and 4)

- **Min Heap:** `[2, 4, 3, 10, 5, 15, 7]`


```
       2
     /   \
    4     3
   / \   / \
 10   5 15  7
```



### Steps to Create a Max Heap by Insertion

A **max heap** is a binary tree where the value of each node is greater than or equal to the values of its children.

1. **Start with an Empty Heap:**
   - Begin with an empty binary tree (array representation is often used).

2. **Insert the Element:**
   - Insert the new element at the end of the tree (as the last element in the array).

3. **Heapify Up (Bubble Up):**
   - Compare the inserted element with its parent node.
   - If the inserted element is larger than its parent, swap them.
   - Continue this process (bubble up) until the heap property is restored (the inserted element is not larger than its parent).
   - If the inserted element becomes the root, stop the process.

4. **Repeat:**
   - Repeat the insertion and heapify up process for each element until all elements are inserted and the heap property is maintained.

### Example for Max Heap:
1. **Insert 7**:
   - Heap: `[7]`
  
2. **Insert 10**:
   - Heap: `[10, 7]` (10 > 7, so swap 10 and 7)

3. **Insert 5**:
   - Heap: `[10, 7, 5]` (No change needed as 5 < 10)

4. **Insert 3**:
   - Heap: `[10, 7, 5, 3]` (No change needed as 3 < 7)

5. **Insert 4**:
   - Heap: `[10, 7, 5, 3, 4]` (No change needed as 4 < 7)

6. **Insert 15**:
   - Heap: `[15, 10, 5, 3, 4, 7]` (15 > 10, swap 15 and 10)

7. **Insert 2**:
   - Heap: `[15, 10, 7, 3, 4, 5, 2]` (No change needed as 2 < 5)
   
- **Max Heap:** `[15, 10, 7, 3, 4, 5, 2]`   
### Notes:
- The heap property (min or max) must be maintained after every insertion.
- In an array representation, the parent of any node at index `i` can be found at index `(i - 1) / 2`, and the children can be found at indices `2i + 1` (left child) and `2i + 2` (right child).

```
       15
      /   \
     10    7
    / \   / \
   3   4 5   2
```


### 2. Delete
From the root you can only delete the root.
After deleting the root, put the last element in the array representation in  the root and compare the value with its children
if the node is smaller than it's children swap it with max (in a max heap) value and continue repeating the same with the swapped node.

Initial Max Heap: `[ 15, 10, 7, 3, 4, 5, 2 ]`

### First Deletion:
1. **Remove the root (15)** and replace it with the last element (2):
   [ 2, 10, 7, 3, 4, 5 ]

2. **Heapify** to restore the Max Heap property:
   - Swap 2 with 10 (largest child):
   [ 10, 2, 7, 3, 4, 5 ]
   - Swap 2 with 4 (largest child):
   [ 10, 4, 7, 3, 2, 5 ]
   
   **Resulting Max Heap after first deletion:**
   [ 10, 4, 7, 3, 2, 5 ]

### Second Deletion:
1. **Remove the root (10)** and replace it with the last element (5):
   [ 5, 4, 7, 3, 2 ]

2. **Heapify** to restore the Max Heap property:
   - Swap 5 with 7 (largest child):
   [ 7, 4, 5, 3, 2 ]

   **Resulting Max Heap after second deletion:**
   [ 7, 4, 5, 3, 2 ]

So after deleting the root element two times, the Max Heap becomes: `[ 7, 4, 5, 3, 2 ]`

Deleting a key also takes `O(Logn)` time.

### 3. Inplace heap creation()
Just call insert elements one by one for inserting elements.

## Applications of Heaps 
1. **Heap Sort**: Heap Sort uses Binary Heap to sort an array in `O(nLogn)` time.

2. **Priority Queue**: Priority queues can be efficiently implemented using Binary Heap because it supports
`insert()`, `delete()` and `extractmax()`, `decreaseKey()` operations in `O(logn)` time.
Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3. **Graph Algorithms**: The priority queues are especially used in graph Algorithms like `Dijkstra’s Shortest Path` and `Prim’s Minimum Spanning Tree`.

4. **K’th Largest Element** in an array.

5. **Sort an almost sorted** array.

6. **Merge K sorted** arrays.
    
    
### When to Use a Heap
- **Priority Queues:** When you need to manage a collection of items with priority levels, such as in a scheduling system.
- **Efficient Min/Max Extraction:** When you need to repeatedly access the minimum or maximum element in a collection.
- **Real-Time Streaming Data:** When you need to maintain a dynamically changing set of data (like the median).
- **Graph Algorithms:** When you need efficient nearest-node selection, such as in Prim's or Dijkstra's algorithm.

### When Not to Use a Heap
- **Random Access Required:** If you need fast random access to elements (heaps are inefficient at this because they don’t support direct access to elements other than the root).
- **Sorted Data Required:** If you need data in sorted order, a balanced binary search tree (like `std::set` or `std::map`) or a sorting algorithm might be more appropriate.
- **Simple Data Structures:** If you only need basic insertions, deletions, or searches without the need for priority ordering, simpler structures like arrays or linked lists might be more efficient.
    
