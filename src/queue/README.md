# Queue
Queue is a logical data structure based on `FIFO`
Queue has two end:
1) Front end  
2) Rare end  
Insertion done in rare end.
Deletion done from front end.

## Queue ADT
#### Data:
1) Space for storing the data.
2) Pointer for front end.
3) Pointer for rare end.
#### Operation:
1) enqueue(): insertion into end
2) dequeue(): deletion from front
3) isEmpty()
4) isFull()
5) first()
6) last()

Queue can be implemented via two physical data structure.
1) Array
2) Linked list
3) Two stacks

### Implementing Queue With Arrays
1) Queue using single pointer
We need a fixed size array. only 1 pointer to the rare of the array (initially pointing at -1), with insertion pointer will be increased pointing to
the rare, so insertion has constant time O(1). After deletion from  front, all elements should be shifted
so we don't have empty element in the array. Deletion is order of O(n).

2) Queue using two pointer
We need a fixed size array. 2 pointers pointing front and rare, initially pointing at -1. After inserion we increase rare pointer. For deletion
we delete from top and increase front pointer. Insert and dlete have constant time O(n).

If front and rare are equal queue is empty.
If rare value is equal size of the array queue is full.

#### Darwback of Implementing Queue With Arrays 
With a aueue using two pointer if we delete from queue, we can not use deleted element, because the front is
pointing to somewhere in the middle of the queue. Also with single pointer we have to shift elements everytime we
delete something from queue.

Solutions:
1) Resetting pointers:
At anytime if the queue is empty (front==equal), bring front and rare pointer to the begining (set to -1).
But if queue has some elemnets and it is not empty but rare has reached the end of the queue we still can not use
deleted spaces.

2) Circular queue
Two pointers, initially pointing at 0, we insert elements and delete, when rare pointer is pointing to end of the array
and we need to insert, we set the rare pointer to the 1, and we insert again until the rare is just behind the front.
Then we announce the queue is full. so we use size-1 element from our array.


new pointer poistion=(pointer+1)mode (size)


Empty:
When both fron and rare are null.

After insertion of the first element, both front and rare will point at the inserted element.

Full:
There is no limit for the size of the queue unless there is no memory, so when requesting
for new memory return NULL the the queue is full.
insertion and deleteion is O(1).

#### Implementing queue with linked list


#### Implementing queue with two stacks 
so we build two stacks, If we have insertion we push elemnts into left one, if we have deleteion,
we transfer everything from left stack to right stack. One the stack on the left got empty and we had
deletion, we repeate transfering everything from left stack to the right one.


### Double Ended Queue (DEQueue) 
It is based on FIFO. it could be implemeneted using array or queue.

In a normal Queue:
front is used deletion.
end is used for insertion


In a DEQueue:
front and are being used for deletion and insertion.



### Priority Queue 
There are two method to implement priority queue:
1) Limited set of priority

is mainly used is operating systems, for instance process or thread can have priority, in linux between 0 to 19

https://askubuntu.com/questions/656771/process-niceness-vs-priority

Example:
We have 3 priority level, 1 is highest, 3 is lowest. We also have the following elements:
```
A B C D E F G H I J
1 1 2 3 2 1 2 3 2 2
```
So to implmenet this, we take 3 queues:
```
Q1: A B F
Q2: C E G I
Q3: D H
```
If you want to delete, you have to delete from Q1 untill it is empty, then you can deleting from Q2 and so on.

2) Element priority
The element itself determine its priority.
Elements: 4,12,5,6,9,12,6


Priority queues can be efficiently implemented using "Binary Heap" because it supports
insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time.
Binomoial Heap and Fibonacci Heap are variations of Binary Heap.
These variations perform union also efficiently.

Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.
