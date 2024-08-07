
# Terminology
1) Root  
2) Parent  
3) Child  
4) Sibling: Children of same parent.  
5) Descendants: For any node, it's children and their children that can be reached from that node.  
6) Ancestor: For any node, all nodes from that node to the root.  
7) Degree of a node: number of direct children of a node.  
8) Internal (non-leaf, non-terminal)/ External (leaf/ terminal) Node:node with degree of zero are
external and with degree bigger than zero are internal.  
9) Levels: Root at level 1, it children at level 2, ....  
10) Height: Starting from 0 onward  
11) Forest: Collection of trees  
For every tree n node, n-1 edge  
```
                                         Levels:      Height:
                          A             |level 1     |    0
                       /  |  \          |            |
                      B   C  D          |level 2     |    1
                     / \   / | \        |            |
                    E   F  G H  I       |level 3     |    2
                       / \   |          |            |
                      J   K  L          |level 4     |    3
                      |     / \         |            |
                      M    N   O        |level 5     |    4
```                      
# Search Trees
1) Binary Search Tree
2) B/B+ Tree

## Binary Search Tre
A tree with degree of 2, every node can have 0,1 or 2 child  
1) How many binary tree from `n` nodes?
```
T(3)=5
n=3
    O
   /
  O
 /
O
    O
   /
  O
   \
    O
    O
   / \
  O   O
    O
     \
      O
     /
    O
    O
     \
      O
       \
        O
```        

T(4)=14  
`T(n)=Catalan Number=Combinations(2*n,n)/(n+1)=(2*n)!/((n+1)!n!)`  
Let say we have `n` distinct number to build a BST, if we choose `i'th` number as root, then there are `i-1` number smaller than that (which can form tree on left child) and `n-i` number larger than that (which can form tree on the right side), so total number of tree would be 
```
t(n-i)*t(i-1)
```
but this i could be any number so we need to sum it up for all numbers:

```
t(n)=Σt(n-i)*t(i-1)
```
for `i=1...n`

Proof:
first lets review geometric progression:
```
sum(a, ar, ar^2, ar^3, ar^4, ar^2, ... ,ar^n )
=a + ar + ar^2 + ar^3 ... + ar^n
=(1-r)*(a + ar + ar^2 ... + ar^n)/(1-r)
=(a + ar + ar^2 + ar^3 + ar^4 + ar^2 + ar^n + -ra - ar^2 - ar^3 - ar^4 - ar^5+ + - ar^n+1)/(1-r)
=(a-ar^n+1)/(1-r)
=a(1-r^n+1)/(1-r)
```


2) How many binary tree from `n` nodes?  
We build a binary search tree and then we have `n!` possible permutation for filling up the nodes for a binary tree, so:  
```
  total number of binary tree with n nodes=n!* total number of binary search tree with n nodes.
```
which is `n! * Combinations(2*n,n)/(n+1)`  

3) How many binary tree with `n` unlabeled nodes with max height? 
Max height for `n` node is  `n-1`. Nodes are unlabled and every node can only have one child (either on the left or right), then for every node
we have either a left or right child, so in total:  

Number of trees with max height: 2<sup>(n-1)</sup>


4) If we know height of a tree ( height=H ) find max and min number of nodes.  
Min number of node: only 1 node at each level: `n=H+1`  
Max number of node: complete number of nodes at each level n=2<sup>0</sup> + 2<sup>1</sup> + ... 2<sup>H</sup>=2<sup>(H+1)</sup>-1  

5)  If n nodes are gives what would be min/ max height of a tree?  

Max of height: `H=n-1`  
Min of height: `H=log2(n+1)-1`  


6) Relation between number of external nodes and internal nodes 
```
deg(0) external node
deg(1) deg(2) internal node
deg(0)=deg(2)+1
```
7) Strict (Proper) VS Full  tree VS complete  
Please read the corresponding section under the tree creation
## Binary Tree Properties:

1) The maximum number of nodes at level ‘l’, `2^(l-1).`  
Maximum number of nodes = 2^(h – 1).
Here h is height of a tree. Height is considered
as is maximum number of nodes on root to leaf path  

2) Minimum possible `height =  ceil(Log2(n+1))`  

3) In Binary tree, number of leaf nodes is always one more than nodes with two children.  

4) Time Complexity of Tree Traversal: `O(n)`  

## Binary Search Tree
In Binary Search Tree is a Binary Tree with following additional properties:  

1) The left subtree of a node contains only nodes with keys less than the node’s key.
2) The right subtree of a node contains only nodes with keys greater than the node’s key.
3) The left and right subtree each must also be a binary search tree.

## Time Complexities:   

1) Search :  `O(h)`
2) Insertion : `O(h)`
3) Deletion : `O(h)`
4) Extra Space : `O(n)` for pointers



If Binary Search Tree is Height Balanced,
then `h = O(Log n)`

Examples of self-balancing BSTs are AVL Tree and Red-Black.
In self-balancing BSTs height of BST remains O(Log n)

## Binary Heap
A Binary Heap is a Binary Tree with following properties.
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.  

2) A Binary Heap is either Min Heap or Max Heap. Every node is bigger (smaller)  than of its children. Order for letf or right child is not important (left and right child should be only smaller than the parents).  In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap. It is mainly implemented using array.

Get Minimum in Min Heap: `O(1)` [Or Get Max in Max Heap]
Extract Minimum Min Heap: `O(Log n)` [Or Extract Max in Max Heap]
Decrease Key in Min Heap: `O(Log n)`  [Or Extract Max in Max Heap]
Insert: `O(Log n)`
Delete: `O(Log n)`



```
                    9
                  /   \
                8       6
              /  \    /   \
             7    4  5     2
            / \  /
           0   3 1
```

We can use an array to represent a binary heap, the children of every node is at `array[2*i]` and `array[2*i+1]`. Creating of tree is by insertion.

### Insertion
```
place the new element at end of the array.
element_index=array.size()-1

parent_index = element_index / 2;
while (array[parent_index] < array[element_index])
{
    swap(array[parent_index] , array[element_index]);
    element_index = parent_index;
    parent_index = element_index / 2;
}
```
Example:  
Let say we have the following number and we want to insert them into heap:  
`6, 8, 2, 10, 0, 2, 2, 1, 0 `

Inserting 6: 

Heap: 
```
┌---┐  
| 6 |   
└---┘  
```
Inserting 8:  

Heap:  
```
┌-------┐  
| 6 | 8 |  
└-------┘  
┌-------┐  
| 8 | 5 |  
└-------┘  
```
Inserting 2:  

Heap: 
```
┌-----------┐  
| 8 | 6 | 2 |  
└-----------┘  
```
Inserting 2:  

Heap:
```
┌----------------┐  
| 8 | 6 | 2 | 10 |  
└----------------┘  
┌----------------┐  
| 8 | 10 | 2 | 6 |  
└----------------┘  
┌----------------┐  
| 10 | 8 | 2 | 6 |  
└----------------┘  
```
Inserting 0:  

Heap:  
```
┌--------------------┐  
| 10 | 8 | 2 | 6 | 0 |  
└--------------------┘  
```
### Deletion
We only delete from top of the heap. Then we move the last element in the array of heap to the top and we compare it with it children. We pick the max value of its children and we descend it down we repeat it recursively.

# Tree Traversals
```
                       A
                     /   \
                   B       C
                  / \     / \
                 D   E   F   G
 ```

### Pre-order:
Visit a node, perform pre-order on the left subtree then perform pre-order on the right subtree.
```
A,(L),(R)
A,(B,D,E),(R)
A,(B,D,E),(C,F,G)
A,B,D,E,C,F,G
```
#### Algorithm Pre-order Traverse Recursivly
```
preOrderRecursively( node)
{
	if (node != nullptr)
	{
		std::cout << node->value << " ";
		preOrderRecursively(node->left);
		preOrderRecursively(node->right);
	}
}
```


#### Algorithm Pre-order Traverse Iteratively

Please note that this is Pre-order Traverse Node,L,R but first we push into stack R and then L
```
stack.push(root);
while(!stack.empty())
{
    processing_node=stack.top();
    std::cout << processing_node->value << " ";
    stack.pop();
    if(processing_node->right!=nullptr)
        stack.push(processing_node->right);
    if(processing_node->left!=nullptr)
        stack.push(processing_node->left);
}
```



### In-order:
Perform in-order on the left subtree, Visit the node then perform in-order on the right subtree.
```
(L),A,(R)
(D,B,E),A,(R)
(D,B,E),A,(F,C,G)
D,B,E,A,F,C,G
```

#### Algorithm In-order Traverse Recursivly

```
inOrderRecursively(node)
{
	if (node != nullptr)
	{
		inOrderRecursively(node->left);
		std::cout << node->value << " ";
		inOrderRecursively(node->right);
	}
}

```

#### Algorithm In-order Traverse Iteratively



### Post-order:
perform post-order on the left subtree, perform post-order on the right subtree, then visit the node.
```
(L),(R),A
(D,E,B),(R),A
(D,E,B),(F,G,C),A
D,E,B,F,G,C,A
```
### Level-order:
Levels by level.
```
A,B,C,D,E,F,G
```



# Binary Search Tree
It's a binary tree that all the elemnt on evry node are smaller than that node and all the node on the right side are bigger than that node.
**Binary search tree is usefull for searching.**
**Heap is usefull for sorting.**
#### Propeties
1) Binary search tree shouldn't have duplicates.
2) If we traverse the tree inorder, the output is a sorted array.
```
                        30
                     /     \
                   15       50
                  /  \     /  \
                 10   20  40   60
```
Inorder traverse:
```(left)30(right)
10, 15, 20, 30, 40, 50, 60
```

Binary search usually represented with linked representation.  
`log2(n) < Height of the BST < n`  
Inorder traverse of BST will give you a sorted array.  
#### Insertion
Just compare the value of new node with value of root, if it is smaller recursively call the function
with the left else with the right node until the node is pinting nullptr.
#### Creating
creating takes `nlog2(n)`
#### Deletion
Let say we have the following tree, and we want to delete some nodes:
```
                       30
                     /     \
                   20       40
                  /  \     /  \
                 10   25  35   45
                              /
                             42
                               \
                               43
```                               
If the node has no child just remove it from the tree, and make the parent to point to nullptr.  
Example deleting 25:
```
                       30
                     /     \
                   20       40
                  /       /  \
                 10      35   45
                              /
                             42
                               \
                               43
```                               
If the node has children, and you remove it you have to replace its empty space with node from either
left or right, then you need to recursively update the tree which is expensive.
Alternatively, you can replace the deleted node with it's immediate in-order predecessor or in-order successor.
you can choose eiter left or right one. Preferably select the one which has the highest subtree.
in-order traverse of the tree is:
```
(),30,()
10, 20, 25, 30, 35, 40, ()
10, 20, 25, 30, 35, 40, (), 45
10, 20, 25, 30, 35, 40, 42, 43, 45
                       30
                     /     \
                   20       40
                  /  \     /  \
                 10   25  35   45
                              /
                             42
                               \
                               43
```                               
After deleting 30
```
                       25
                     /     \
                   20       40
                  /        /  \
                 10       35   45
                              /
                             42
                               \
                               43
```                               
or
```
                       35
                     /     \
                   20       40
                  /  \        \
                 10   25       45
                              /
                             42
                               \
                               43
```                               
To find the immediate in-order predecessor or in-order successor we don't have to traverse the tree,
To find in-order predecessor, just go left, then select right nodes all the way down.
To find in-order successor, just go right, then select left nodes all the way down.
To delete 40, if we choose in-order successor, which 42, that one has child, so we have
to recursively update that one as well.
Removing 40, replacing it with 42
```
                       30
                     /     \
                   20       42
                  /  \     /  \
                 10   25  35   45
                              /
                               \
                               43
```                               
Updating removed place of 42 with 43
```
                       30
                     /     \
                   20       42
                  /  \     /  \
                 10   25  35   45
                              /
                             43
```                             
Deletion complexity time: we need `log2(n)` to the value and we might need several updated which depends on
the height of the tree which `log2(n)`.



# Tree Creation
How to generate a binary tree using linked represenation?
Binary tree has two represenation array and linked list. To create a tree in Linked
representation we need a queue data structre.
```
                       30
                     /     \
                   20       40
                  /  \     /  \
                 10   25  35   45
                              /
                             42
                               \
                               43
```                               
1) Create root node and an empty queue, putthe address of the root node in the queue.  
2) Reapting process:  
Take the top element from queue and make a temporarily pointer to that.
Check if node has left child, if it has set it to the temporarily pointer and
point to parent this newly created node. Put the address of the new node into the queue.
As If the node has a right child and repeate the same process.
3) Take next address from queue and make the pointer to that and repeat 2.  


# Representation For a Binary Tree
There are two main representation for a binary tree
1) Array
2) Linked
### Array
```
                       A
                     /   \
                   B       C
                  / \     / \
                 D   E   F   G
```

Array: `A B C D E F G`
Index: `1 2 3 4 5 6 7`

Every element left child `2*i`
Every element right child `2*i+1`

Every element parent: `ciel[i/2]`

How to put elements in the array?
Levele by level (BFS Traverse)

### Linked list

### Full vs Complete Binary Tree
Full: A tree with height H having maximum number of nodes.
Full nodes: `n=2^(H+1)-1`

```
                      Full
                       A
                     /   \
                   B       C
                  / \     / \
                 D   E   F   G
```

Array: `A B C D E F G`
Index: `1 2 3 4 5 6 7`



Complete: Every node has 2 or 0 children.

```

    Complete                   Not Complete
        A                            A
      /   \                        /   \
     B     C                      B     C
    / \   /                      /       \
   D   E F                      D         E
```


If there is no blank space ( in between elemnets) in the array represenation then it is complete

Complete:
 `A B C D E F`
 `1 2 3 4 5 6`

Not Complete:
 `A B C D - - E`
 `1 2 3 4 5 6 7`

A complete binary tree of height H, will be full binary tree up to height H-1, and on the last level
elements will be filled from left to right, without skipping any elemnts.

### Strict (Proper) vs Complete Binary Tree 
```

  strict, not complete         complete, strict       complete, not strict      not complete, not strict
        A                            A                         A                           A
      /   \                        /   \                     /   \                       /   \
     B     C                      B     C                   B     C                     B     C
          / \                    / \                       /                                 /
         D   E                  D   E                     D                                 D


strict, not complete:
 A B C - - D E
 1 2 3 4 5 6 7

complete, strict:
 A B C D E
 1 2 3 4 5 6 7

complete, not strict
 A B C D
 1 2 3 4

not complete, not strict
 A B C - - D
 1 2 3 4 5 6
```

 
**Strict (Proper):**   
A node can have 0 or 2 children.

```
      min                        max
       O                           O
      / \                        /   \
     O   O                      O     O
    / \                        / \   / \
   O   O                      O  O   O   O
  / \                        / \/ \ / \ / \
 O   O                      O  OO O O O O  O
 ```
 
**Full:**   
A tree with height H having maximum number of nodes.
if n is given
Min of height `H=log2(n+1)-1`  
Max of height `H= ciel[n-1/2]`  
if H is given
Min number of node `n= 2*H+1`  
Max number of node `n= 2^(H+1)-1`  
Number of external nodes=Number of internal nodes + 1  

8) M-ary Tree/ Strict M-ary Tree   
M is degree of tree, degree means every node in tree can have at most M children
3-ary Tree {0,1,2,3}
Strict 3-ary Tree {0,3}
for Strict M-ary:
if n is given
Min of height `H=logm(n*(m-1)+1)-1`  
Max of height `H= ciel[n-1/m]`  
if H is given
Min number of node `n= m*H+1`  
Max number of node `n= (m^(H+1)-1)/(m-1)`  
External `nodes= (m-1)*(internal node)+1`  

h is the height of the tree.
```
                       -1
                      /  \
                     3     7
                    / \   / \
                   4  1   5
```


## B/B+ Trees

```
    _ _______ _
   /  \_____/  \ 
  /  / \ _ / \  \
 /  /  /   \  \  \
/__/__/     \__\__\
\  \  \     /  /  /
 \  \  \ _ /  /  /
  \  \ /___\ /  /
   \_ /_____\_ / 
            
```



The B-tree generalizes the binary search tree, allowing for nodes with more than two children. Unlike other self-balancing binary search trees, 
the B-tree is well suited for storage systems that read and write relatively large blocks of data, such as discs.
In most of the self-balancing search trees it is assumed that everything is in main memory. 
In practice,  huge amount of data that cannot fit in main memory. When the number of keys is high, the data is read from disk in the form of blocks. 
Disk access time is very high compared to main memory access time. The main idea of using B-Trees is to reduce the number of disk accesses. 
Most of the tree operations (search, insert, delete, max, min, ..etc ) require `O(h)` disk accesses where `h` is the height of the tree. 

B-tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, 
insertions, and deletions in logarithmic time.

The height of B-Trees is kept low by putting maximum possible keys in a B-Tree node. Generally, a B-Tree node size is kept equal to the 
disk block size. Since h is low for B-Tree, total disk accesses for most of the operations are reduced significantly compared to 
balanced Binary Search Trees like AVL Tree, Red-Black Tree, ..etc.


### Properties of B-Tree
A B-tree of order `t` is a tree which satisfies the following properties:
Every node has at most `t` children.
A non-leaf node with `k` children contains at most `k-1` key.
The root has at least two children if it is not a leaf node.
Every non-leaf node (except root) has at least `ciel(m/2)` children.
All leaves are at same level.
1) All leaves are at same level.
2) A B-Tree is defined by the term minimum degree `t`. The value of t depends upon disk block size.
3) Every node except root must contain at least `t-1` keys. Root may contain minimum 1 key.
4) All nodes (including root) may contain at most `2t – 1` keys.
5) Number of children of a node is equal to the number of keys in it plus 1.
6) All keys of a node are sorted in increasing order. The child between two keys `k1` and `k2` contains all keys in the range from `k1` and `k2`.
7) B-Tree grows and shrinks from the root which is unlike Binary Search Tree. Binary Search Trees grow downward and also shrink from downward.
8) Like other balanced Binary Search Trees, time complexity to search, insert and delete is` O(Logn)`.

### Operations on B-Tree

#### Insertion

1) Insertion will be always done at the leaves. Find the leaf node where the item should be inserted.
2) If the leaf can accommodate another item, insert the item into correct location.
3) If the node is full,  split the node into two. Promote the mdeian into parent node, and repeat the same with parent.
```
20 30 40 50 60 10 15 70 80

Inserting 20:

        20
        
Inserting 30:

        20 | 30    

Inserting 40:

               30 | x     
           /           \
      20 | x          40 | x
      
      
Inserting 50:

               30 | x     
           /           \
      20 | x          40 | 50


Inserting 60:

               30 | 50     
           /      |    \ 
      20 | x   40 | x    60 | x        
                      

Inserting 10:

               30 | 50     
           /      |    \ 
      10 | 20  40 | x    60 | x 
                


Inserting 15:

               30 | x     
            /          \ 
         15 | x          50 | x 
        /      \        /      \
    10 | x   20 | x  40 | x  60 | x    
        
Inserting 70:

               30 | x     
            /          \ 
         15 | x          50 | x 
        /      \        /      \
    10 | x   20 | x  40 | x  60 | 70    


Inserting 80:

                 30 | x     
             /            \ 
         15 | x          50 | 70 
        /      \        /   |   \
    10 | x   20 | x  40|x 60|x  80|x        

Inserting 90:

                30 | x     
            /           \ 
         15 | x          50 | 70 
        /      \        /   |   \
    10 | x   20 | x  40|x 60|x  80|90        
```
#### Deletion

Durig the deleteion various cases might occures:
Deleteion of a leaf node:
1)Simply delete.
2)Delete and merge.
3)Borrow.

Deletion of a non leaf node:

```
Deleting 90:

                30 | x     
            /            \ 
         15 | x          50 | 70 
        /      \        /   |   \
    10 | x   20 | x  40|x 60|x  80|x    

now if we delete 80:

                30 | x     
            /            \ 
         15 | x          50 | x 
        /      \        /   |   
    10 | x   20 | x  40|x 60|70  

But if we delete 60 instead:

                30 | x     
            /            \ 
         15 | x          50 | x 
        /      \        /   
    10 | x   20 | x  40|70  
```

#### Search

#### Traverse



## Self-balancing Binary Search tree
Examples of self-balancing search trees:
* 2–3 tree
* AVL tree
* Red–black tree


### AVL tree

An AVL tree (named after inventors Adelson-Velsky and Landis)  is a self balancing binary tree. The height of the tree is balanced using balance factor.
We calculate it for evey **node** in the tree and the value should be `-1, 0 or 1`.
The reason for balancing the height of the  tree is to keep the time complexity operation in order of `O(log(n))`.

#### Complexity of binary search trees
 
| Operations | Average | Worst |
| --- | --- | --- |
| Insert | O(log(n)) | O(n) |
| Delete | O(log(n)) | O(n) |
| Remove | O(log(n)) | O(n) |
| Search | O(log(n)) | O(n) |
 
If you tree is imbalanced like the following tree, time complexity of all operations becames linear (worst case).

```
    10
      \
       20       
         \
          30
            \
            40
```

so we keep the height balance to make the time complexity in order of `O(log(n))`.

#### Balance Factor

```
Balance Factor=Height of Left Subtree - Height of Right Subtree
BF=HL-HR={-1,0,1}
```

To calculate the height you must count the levels.
```
        2-2: X
           /   \            
     1-1: X     X: 1-0
         / \   /
     0: X  0:X X: 0
        
        
        
        
              X:2-2
             / \
        1-0:X   X:0-1
           /     \
        0:X       X:0
          
          

          3-1:X
             / \
        2-0:X   X: 0
           /     
          X:1-0
         /
        X:0
        
        
         4-1: X
             / \
        3-0:X   X
           /     
      0-2:X      
           \
            X:1-0
           /            
          X:0
          
```
#### Balancing the B-Tree (Rotation for Insertion)
To balance the tree, after insertion of a new node, we compute the height and if the balance factor is bigger than 1 (or smaller than -1), 
we have to rotate the tree. Since we check the height immediatly after insertion, only one of these case might happen:

1)LL (left of left) imbalance: This happenes when inserting new node in left side of a left node;

```
Left Left Case : balance > 1 && key < node->left->key

node->  O: 2-0 <- balance
       /          
      O           
     /            
    O <- newly inserted node 
    
    
    
Initial tree:

       30:1-0
      /
     20 0
 
We insert 10:

       30: 2-0
      /
     20 :1-0
    /
   10:0
   
Now it is imbalance, to balance it, we put our finger over imbalance node, 30, in this case, imagine all nodes are connected through a thread and 
we pull the thread from the right side (clockwise).

       
  
Right (clockwise) rotation:

      20 :1-1
    /   \
   10:0 30: 0    
    


T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2

    
```


2)LR (left of right) imbalance
 
``` 
Left Right Case: balance > 1 && key > node->left->key 

node->  O : 2-0 <- balance
       /          
      O           
       \         
        O   <- newly inserted node      



Initial tree:

       30: 1-0
      /
    10: 0

We insert 20:          


       30: 0-2
     /
    10: 0-1 
     \
      20: 0 
      
First we rotate around 10:


      30
     /
    20
   /
  10

Now we rotate around 30:

      20
     /  \
    10   30




     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2

```     


3)RR (right of right) imbalance

```    
Right Right Case: balance < -1 && key > node->right->key

        O : 0-2 <- balance
         \          
          O           
           \         
            O   <- newly inserted node 


Initial tree:

       10:0-1
         \
          20: 0


We insert 30:

       10: 0-2
         \
          20: 0-1
           \
           30 :0             


Left (anti-clockwise) rotation:

      20 :1-1
    /   \
   10:0 30: 0




  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4            

```


4)RL (right of left ) imbalance
```
Right Left Case: balance < -1 && key < node->right->key

        O : 0-2 <- balance
         \          
          O           
         /         
        O     <- newly inserted node 
        
        
Initial tree:

       10: 0-1
         \
          30: 0

We insert 20:          


       10: 0-2
         \
          30: 1-0          
         /
        20: 0 
        
        
First we rotate around 30:

       10: 0-2
         \
          20: 0-1          
           \
           30: 0 
           
Now we rotate around 10:

      20
     /  \
    10   30        

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
        
```



# Red-Black Tree
Red-Black Tree is a self-balancing Binary Search Tree (BST). Most of operations on BST (e.g., search, max, min,... ) take `O(h)` time where `h`
 is the height of the BST. The expense of these activities may become `O(n)`  for a unbalanced (skewed) Binary tree. 
If we balance the BST cost of operations has upper bound of `O(Logn)`.

The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. 
So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred.

Most of the self-balancing BST library functions like map and set in C++ use Red Black Tree
It is used to implement CPU Scheduling Linux. Completely Fair Scheduler uses it.


## Properties of Red-Black Tree

1) Every node has a color either red or black.

2) Root of tree is always black.

3) There are no two adjacent red nodes (A red node cannot have a red parent or red child).

4) Every path from a node (including root) to any of its descendant nullptr node has the same number of black nodes.



```
          B(20)                               B(20) 
       /         \                        /         \
     R(10)      R(30)                   R(10)       R(30)  
    /    \     /     \                 /    \      /     \
 nullptr  nullptr    nullptr nullptr             nullptr   nullptr  nullptr   nullptr

```
## Operations
To balance a Red-Black tree, we use the following operations:
1) Recoloring
2) Rotation



Online visualization for [B-tree](https://www.cs.usfca.edu/~galles/visualization/BTree.html)  
Refs: [1](https://www.tutorialspoint.com/cplusplus-program-to-implement-avl-tree),
      [2](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/),
      [3](https://gist.github.com/Harish-R/097688ac7f48bcbadfa5),
      [4](https://math.stackexchange.com/questions/337842/simplifying-catalan-number-recurrence-relation),
      [5](https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-with-n-keys/)




