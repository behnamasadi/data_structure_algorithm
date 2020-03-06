/*
For every tree n node, n-1 edge
Terminology:
1)Root
2)Parent
3)Child
4)Sibling: Children of same parent
5)Descendants: For any node, it's children and their children that can be reached from that node
6)Ancestor: For any node, all nodes from that node to the root.
7)Degree of a node: number of direct children of a node.
8)Internal (non-leaf, non-terminal)/ External (leaf/ terminal) Node:node with degree of zero are
external and with degree bigger than zero are internal.
9)Levels: Root at level 1, it childeren at level 2, ....
10)Height: Starting from 0 onward
11)Forest: Collection of trees
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


Binary Tree
A tree with degree of 2, every node can have 0,1 or 2 child
******************* How many binary tree from <n> unlabeled nodes*******************
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



T(4)=14
T(n)=Catalan Number=Combinations(2*n,n)/(n+1)

Proof:
first lets review geometric progression:

sum(a, ar, ar^2, ar^3, ar^4, ar^2, ... ,ar^n )
=a + ar + ar^2 + ar^3 ... + ar^n
=(1-r)*(a + ar + ar^2 ... + ar^n)/(1-r)
=(a + ar + ar^2 + ar^3 + ar^4 + ar^2 + ar^n + -ra - ar^2 - ar^3 - ar^4 - ar^5+ + - ar^n+1)/(1-r)
=(a-ar^n+1)/(1-r)
=a(1-r^n+1)/(1-r)




******************* How many binary tree from <n> unlabeled nodes with max height *******************
Since height is n-1 and every node with max height can only one child (either on the left or right)
Then we have:
Number of trees with max height: 2^(n-1)


******************* How many binary tree from <n> unlabeled nodes *******************
n! * Combinations(2*n,n)/(n+1)

******************* If we know height of a tree ( height=H )  find max and min number of nodes *******************

Min number of node n=H+1
Max number of node n=2^0 + 2^1 + ... 2^H=2^(H+1)-1

*******************  If n nodes are gives what would be min/ max height of a tree *******************

Min of height H=log2(n+1)-1
Max of height H=n-1

******************* Relation between number of external nodes and internal nodes *******************
deg(0) external node
deg(1) deg(2) internal node

deg(0)=deg(2)+1

******************* Strict (Proper) and Full *******************
Strict (Proper): A node can have 0 or 2 children.

      min                        max
       O                           O
      / \                        /   \
     O   O                      O     O
    / \                        / \   / \
   O   O                      O  O   O   O
  / \                        / \/ \ / \ / \
 O   O                      O  OO O O O O  O

Full: A tree with height H having maximum number of nodes.

if n is given
Min of height H=log2(n+1)-1
Max of height H= ciel[n-1/2]

if H is given
Min number of node n= 2*H+1
Max number of node n= 2^(H+1)-1


Number of external nodes=Number of internal nodes + 1

******************* M-ary Tree/ Strict M-ary Tree *******************
M is degree of tree, degree means every node in tree can have at most M children

3-ary Tree {0,1,2,3}
Strict 3-ary Tree {0,3}


for Strict M-ary:
if n is given
Min of height H=logm(n*(m-1)+1)-1
Max of height H= ciel[n-1/m]

if H is given
Min number of node n= m*H+1
Max number of node n= (m^(H+1)-1)/(m-1)

External nodes= (m-1)*(internal node)+1
*/


/*
h is the height of the tree.


                       -1
                      /  \
                     3     7
                    / \   / \
                   4  1   5
*/

/*

Binary Tree Properties:

    1)The maximum number of nodes at level ‘l’ = 2^(l-1).
    Maximum number of nodes = 2^(h – 1).
    Here h is height of a tree. Height is considered
    as is maximum number of nodes on root to leaf path

    2)Minimum possible height =  ceil(Log2(n+1))

    3)In Binary tree, number of leaf nodes is always one
    more than nodes with two children.

    4)Time Complexity of Tree Traversal: O(n)



Binary Search Tree
In Binary Search Tree is a Binary Tree with following additional properties:
    1) The left subtree of a node contains only nodes with keys less than the node’s key.
    2) The right subtree of a node contains only nodes with keys greater than the node’s key.
    3) The left and right subtree each must also be a binary search tree.

Time Complexities:

    1)Search :  O(h)
    2)Insertion : O(h)
    3)Deletion : O(h)
    4)Extra Space : O(n) for pointers

    h: Height of BST
    n: Number of nodes in BST

    If Binary Search Tree is Height Balanced,
    then h = O(Log n)

    Self-Balancing BSTs such as AVL Tree, Red-Black
    Tree and Splay Tree make sure that height of BST
    remains O(Log n)


Binary Heap
A Binary Heap is a Binary Tree with following properties.
    1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
    2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap. It is mainly implemented using array.

Get Minimum in Min Heap: O(1) [Or Get Max in Max Heap]
Extract Minimum Min Heap: O(Log n) [Or Extract Max in Max Heap]
Decrease Key in Min Heap: O(Log n)  [Or Extract Max in Max Heap]
Insert: O(Log n)
Delete: O(Log n)
*/


/*
                    9
                  /   \
                8       6
              /  \    /   \
             7    4  5     2
            / \  /
           0   3 1



*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <cmath>


void binaryHeapExample()
{

//https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/
    std::vector<int> data={0,1,2,3,4,5,6,7,8,9};

    // min heap
    std::make_heap(data.end(),data.begin());

    //min heap
//    std::make_heap(data.begin(),data.end());
//    for(auto d:data)
//        std::cout<<d <<std::endl;


    int height =  ceil(log2(data.size()+1));
    std::cout<<height <<std::endl;


    for(std::size_t i=0;2*i+1<data.size();i++)
    {
        std::cout<<"Node: " <<data[i] <<std::endl;
        if(2*i+1<data.size())
            std::cout<<"left child:"  << data[2*i+1]<<std::endl;
        if(2*i+2<data.size())
            std::cout<<"right child:"<<data[2*i+2] <<std::endl;

    }




}



int main()
{
}
