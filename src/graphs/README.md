
# Graph Representation
**1) Adjacency Matrix**  
**2) Adjacency List**  
**3) Compact List**  
### 1-a) Adjacency Matrix (Undirected Graph)
```
G=(V,E)
|V|=5
|E|=7
         1-----2
         | \   |
         |  \  |
         |   \ |
         4-----3
          \   /
           \ /
            5
 1 2 3 4 5
┌          ┐
|0 1 1 1 0 | 1
|1 0 1 0 0 | 2
|1 1 0 1 1 | 3
|1 0 1 0 1 | 4
|0 0 1 1 0 | 5
└          ┘
```
### 1-b) Adjacency Matrix (Directed Graph)
```
		 1----→2
		 | ↖   |
		 |  \  |
		 ↓   \ ↓
		 4----→3
 1 2 3 4
┌        ┐
|0 1 0 1 | 1
|0 0 1 0 | 2
|1 0 0 0 | 3
|0 0 1 0 | 4
└        ┘
```


#### Pros
1) Representation is easier to implement and follow.  
2) Removing an edge takes `O(1)` time.  
3) Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done `O(1)`.  
#### Cons
1) Consumes more space `O(V^2)`. Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is `O(V^2)` time.

Number of elements `N^2`
Any algorithm on a graph in matrix form has `O(N^2)`
### 1-c) Cost Adjacency Matrix
```
            9
         1-----2
         | \4  |
       6 |  \  | 5
         |  8\ |
         4-----3
          \   /
         2 \ / 7
            5
 1 2 3 4 5
┌          ┐
|0 1 1 1 0 | 1
|1 0 1 0 0 | 2
|1 1 0 1 1 | 3
|1 0 1 0 1 | 4
|0 0 1 1 0 | 5
└          ┘
```
Number of elements `N^2`
Any algorithm on a graph in matrix form has `O(N^2)`
### 2-a) Adjacency List (Undirected Graph)
```
1 -> 2 -> 3 -> 4
2 -> 1 -> 3
3 -> 1 -> 2 3 -> 5
4 -> 1 -> 4 -> 5
5 -> 3 -> 4
```
Number of elements `|V|+2|E|=N+2e`  
Time Complexity: `O(N)`.
### 2-b) Adjacency List (Directed Graph)
```
		 1----→2
		 | ↖   |
		 |  \  |
		 ↓   \ ↓
		 4----→3
```
This will only show out going edges:
```
1 -> 2 -> 4
2 -> 3
3 -> 1 
4 -> 3 
```
To have in going edges, we create an inverse adjacency list:
```
1 -> 3
2 -> 1
3 -> 2 -> 4
4 -> 1
```
### 2-c) Cost Adjacency List
In the list alongside the edge we store the weight
```
1 -> 2|9 -> 3|4 -> 4|6
2 -> 1| -> 3|
3 -> 1| -> 2| -> 3| -> 5|
4 -> 1| -> 4| -> 5|
5 -> 3| -> 4|
```
### 3) Compact List
```
         1-----2
         | \   |
         |  \  |
         |   \ |
         4-----3
          \   /
           \ /
            5
            
Vertices:   7  10 12 16 19    2  3  4  1  3  1  2  3   4   1  3  5  3  4
indices: 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14  15  16 17 18 19 20
            └1  2  3  4  5 ┘  └  1  ┘  └ 2 ┘ └     3    ┘  └   4  ┘ └ 5 ┘ 
```            
Number of elements `|V|+2|E|=N+2e`
The space consumed by a graph in compact is linear, O(N).



# Tree
A graph without any cycle is a tree.

```
    1-----2
    | \   |
    |  \  |
    |   \ |
    4-----3
     \   /
      \ /
       5
      / \
     /   \
    6     7
```         
We convert the graph into tree and if we have edge that creates a loop, we user "..." to represent that edge.
There can be different BFS.
BFS Spanning Tree:
```
           1
        /  |  \
       2...3...4  
       |   .
       | . 
       5
     /   \
    6     7
```    
**BFS**: Level order traversal: `1,2,3,4,5,6,7`
BFS Spanning Tree:
```
       1
     /  |  \
    4...2...3.
   / ..........
  /		   
  5		   
 / \
7   6
```  
  
**BFS**: Level order traversal: `1,4,2,6,3,5,7,6`  
**DFS**: In-order traversal: `1,4,5,7,6,2,3`  
#### BFS Terms
**1) Visiting:** Going to a particular vertex.  
**2) Exploring:** Visiting all adjacent vertices.  
#### DFS Terms
**1) Visited:** If all neighbors of a vertex has been visited.  
**2) Exploring:** Visiting all adjacent vertices.  
Time taken: O(N)






### Spanning Tree
A spanning tree is a subset of Graph G, which has all the vertices covered with minimum possible number of edges.
Hence, a spanning tree does not have cycles and it cannot be disconnected.
Total number of edges is  number of vertices -1.
By this definition, we can draw a conclusion that every connected and undirected Graph G has at least one spanning tree. 
A disconnected graph does not have any spanning tree, as it cannot be spanned to all its vertices.
Spanning tree is basically used to find a minimum path to connect all nodes in a graph. Common application of spanning trees are −
1) Civil Network Planning  
2) Computer Network Routing Protocol  
3) Cluster Analysis  
```
|V|=4
|E|=6

      1----2    
      |\   |
      |  \ |
      3----4
      
      1----2
      |    
      |    
      3----4
      
      1----2
           |
           |
      3----4
      
      1----2
       \    
         \  
      3----4
```      
How many spanning tree could be there?
### Minimum Spanning Tree (MST)

```
          2
      1-------2
      |\4    /| 
      | \   / |
      |  \ /  | 6
    5 |  /\   |
      | /1 \  |
      |/    \ |
      3-------4
	      3
          
          2
      1-------2
      |
      |
      |
    5 |
      |
      |
      3-------4
          3
          
Cost:10
		   
      1       2
      |       |
      |       |
      |       | 6
    5 |       |
      |       |
      |       |
      3-------4
         3
         
Cost:14
```
### Algorithm for Finding Minimum Spanning Tree 
**1) Prim's lazy MST Algorithm.**  
**2) Prim's eager MST Algorithm.**  
**3) Kruskal's MST Algorithm.** 
### Prim's lazy MST Algorithm
### Prim's eager MST Algorithm
### Kruskal's MST Algorithm
1) Select a minimum cost edge from graph.  
2) Select a minimum cost edge from graph such that it connected to the previously selected edge.  
Time complexity: `(|V|-1)*|E|=n*e=O(N^2)`   
If you use a heap for finding the minimum, time complexity would be `(|V|-1)*log(|E|) =O(NLog(n))`  
Vertices: `1,2,3,4,5,6,7`
```
                     (1) 
                 5 /    \  25
                 /        \
               (6)         (2)
                |      10 / |
                |       /   |
              20|    (7)    |12
                | 18/ |     |
                (5)/  |    (3)
                  \ 14|   /
               16  \  | /  8
                    (4)
Costs:
 1  2  3  4  5  6  7
┌                   ┐
|                   | 1
|                   | 2
|                   | 3
|                   | 4
|                   | 5
|                   | 6
└                   ┘ 7
```
### Directed Graph
**Self loop:** If a vertex has an edge from itself to itself.  
**Parallel edges**  
**Indegree:** number of edges come into graph.  
**Outdegree:** number of edges come out of graph.  
**Adjacent Vertices:** If two vertices are connected via an edge.  

### Simple Digraph
Directed graph with loop and self edges.  
### Non-directed (undirected) Graph
Degree: number of edges connected to a vertex.  
### Non-connected Graph
graph with more than component.  
**Articulation point(Cut Vertex):** The vertices that if you remove them (along the connected edges connected),
the graph became a non-connected graph.

3 and 0 are articulation points.
```
1---0-----3
|  /      |
| /       |
|/        |
2         4
```

1 is an articulation points.
```
0\         /3\ 
|  \     /     \
|    \1/         \5
|    /|\         /
|  /  |  \     /
2/    |    \4/
      |
      |
      6
```

**Bridge:** The edges that if you remove them, the graph became a non-connected graph.

**Bridge Algorithm:**  
Start DFS traverse at any arbitrary node. DFS search will transform ur undirected edge into directed edges.   
Assign two variable to each node: `ID` and `Lowest Link`.  
`ID` is a unique number that increase after visitig each node.  
`Lowest Link` is the smallest value of node ID rechable from that node (including the ID of the node itself).  
During DFS search, bridges will be found where the ID of the node your edge is coming from is less than the `Lowest Link` value of the node your edge is going to.
That means there is no way back to the node that you came from.

`A (IDs: Lowest Link values)  -----> B(IDs: Lowest Link values)`

If (A.ID< B.Lowest Link) Then A->B is a bidge.

Our Graph is:  

```
                  A
                /   \
               B----- C
                   /   \
                  F     D
                 / \     \
                /   G     E
               /     \
              I-------H
```


The values written in the node is (Assigned IDs: Lowest Link values)  

```
                  0:0
                ↙   ↖
               1:0--→ 2:0
                   ↙   ↘
                  5:5   3:3
                 ↗ ↘     ↘
                /   6:5    4:4
               /     ↘
              8:5←----7:5
```



### Connected Graph Bi-Connecte Component
It can not be divided into components if you remove any edges.
### Strongly Connected Graph 
You can reach any vertexes from any other one. 
### Connected VS Strongly connected.
**Path:** Set of all vertices between two vertices.  
**Cycle:** Path from a vertex to itself.  

### Directed Acyclic Graph DAG
Directed graph without any cycles.
We can arrange all vertices of a directed acyclic graph linearly in asingle line such that the edge are going only in forward direction topological ordering of vertices.

### Shortest Path (Floyd-Warshall)
 
### Cycle detection (Brent's algorithm)

▲ ▼ ► ◄ ↘ ↖ ↙ ↗ ↑ ↓ ← → ↗ ↖ ↘ ↙ ↖ ➚ ➘  ⤸ ⤹ ⤺ ⤻ ⤶ ⤷ ↷ ↶ ↻ ↺
Arrow key ascii list: https://www.alt-codes.net/arrow_alt_codes.php


