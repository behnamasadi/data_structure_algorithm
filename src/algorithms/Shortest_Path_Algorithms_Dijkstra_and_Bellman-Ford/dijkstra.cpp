// #include <iostream> 
// #include <limits.h>
// 
// 
// // Number of vertices in the graph 
// #define V 9 
// // A utility function to print the constructed distance array 
// void  printSolution(int dist[], int n) 
// { 
//     printf("Vertex   Distance from Source\n"); 
//     for (int i = 0; i < V; i++) 
//         printf("%d \t\t %d\n", i, dist[i]); 
// }
// 
// 
//   
// // A utility function to find the vertex with minimum distance value, from 
// // the set of vertices not yet included in shortest path tree 
// int minDistance(int dist[], bool sptSet[]) 
// { 
//     // Initialize min value 
//     int min = INT_MAX, min_index; 
//   
//     for (int v = 0; v < V; v++) 
//         if (sptSet[v] == false && dist[v] <= min) 
//             min = dist[v], min_index = v; 
//   
//     return min_index; 
// } 
// 
//   
// // Function that implements Dijkstra's single source shortest path algorithm 
// // for a graph represented using adjacency matrix representation 
// void dijkstra(int graph[V][V], int src) 
// { 
//     int dist[V]; // The output array.  dist[i] will hold the shortest 
//     // distance from src to i 
//   
//     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
//     // path tree or shortest distance from src to i is finalized 
//   
//     // Initialize all distances as INFINITE and stpSet[] as false 
//     for (int i = 0; i < V; i++) 
//         dist[i] = INT_MAX, sptSet[i] = false; 
//   
//     // Distance of source vertex from itself is always 0 
//     dist[src] = 0; 
//   
//     // Find shortest path for all vertices 
//     for (int count = 0; count < V - 1; count++) { 
//         // Pick the minimum distance vertex from the set of vertices not 
//         // yet processed. u is always equal to src in the first iteration. 
//         int u = minDistance(dist, sptSet); 
//   
//         // Mark the picked vertex as processed 
//         sptSet[u] = true; 
//   
//         // Update dist value of the adjacent vertices of the picked vertex. 
//         for (int v = 0; v < V; v++) 
//   
//             // Update dist[v] only if is not in sptSet, there is an edge from 
//             // u to v, and total weight of path from src to  v through u is 
//             // smaller than current value of dist[v] 
//             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
//                 && dist[u] + graph[u][v] < dist[v]) 
//                 dist[v] = dist[u] + graph[u][v]; 
//     } 
//   
//     // print the constructed distance array 
//     printSolution(dist, V); 
// } 
//   
// void  dijkstraExample()
// {
//    /* Let us create the example graph discussed above */
//     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
//                         { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
//                         { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
//                         { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
//                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
//                         { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
//                         { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
//                         { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
//                         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
//   
//     dijkstra(graph, 0);     
// }
// 
// 
// int main()
// {
//    dijkstraExample(); 
// }


#include <iostream>
#include <vector>
#include <string>
#include <list>
 
#include <limits> // for numeric_limits
 
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>
 
 
typedef int vertex_t;
typedef double weight_t;
 
const weight_t max_weight = std::numeric_limits<double>::infinity();
 
struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};
 
typedef std::vector<std::vector<neighbor> > adjacency_list_t;
 
 
void DijkstraComputePaths(vertex_t source,
                          const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous)
{
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
 
    while (!vertex_queue.empty()) 
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());
 
        // Visit each edge exiting u
	const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++)
        {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
	    if (distance_through_u < min_distance[v]) {
	        vertex_queue.erase(std::make_pair(min_distance[v], v));
 
	        min_distance[v] = distance_through_u;
	        previous[v] = u;
	        vertex_queue.insert(std::make_pair(min_distance[v], v));
 
	    }
 
        }
    }
}
 
 
std::list<vertex_t> DijkstraGetShortestPathTo(
    vertex_t vertex, const std::vector<vertex_t> &previous)
{
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}
 
 
int main()
{
//     // remember to insert edges both ways for an undirected graph
//     adjacency_list_t adjacency_list(6);
//     // 0 = a
//     adjacency_list[0].push_back(neighbor(1, 7));
//     adjacency_list[0].push_back(neighbor(2, 9));
//     adjacency_list[0].push_back(neighbor(5, 14));
//     // 1 = b
//     adjacency_list[1].push_back(neighbor(0, 7));
//     adjacency_list[1].push_back(neighbor(2, 10));
//     adjacency_list[1].push_back(neighbor(3, 15));
//     // 2 = c
//     adjacency_list[2].push_back(neighbor(0, 9));
//     adjacency_list[2].push_back(neighbor(1, 10));
//     adjacency_list[2].push_back(neighbor(3, 11));
//     adjacency_list[2].push_back(neighbor(5, 2));
//     // 3 = d
//     adjacency_list[3].push_back(neighbor(1, 15));
//     adjacency_list[3].push_back(neighbor(2, 11));
//     adjacency_list[3].push_back(neighbor(4, 6));
//     // 4 = e
//     adjacency_list[4].push_back(neighbor(3, 6));
//     adjacency_list[4].push_back(neighbor(5, 9));
//     // 5 = f
//     adjacency_list[5].push_back(neighbor(0, 14));
//     adjacency_list[5].push_back(neighbor(2, 2));
//     adjacency_list[5].push_back(neighbor(4, 9));
//  
//     std::vector<weight_t> min_distance;
//     std::vector<vertex_t> previous;
//     DijkstraComputePaths(0, adjacency_list, min_distance, previous);
//     std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
//     std::list<vertex_t> path = DijkstraGetShortestPathTo(4, previous);
//     std::cout << "Path : ";
//     std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
//     std::cout << std::endl;

// a 0
// b 1
// c 2
// d 3
// e 4
// f 5
// g 6
// h 7
// i 8 

    adjacency_list_t adjacency_list(9);
// 0 = a
// g.add_edge('a','b',weight=4)
// g.add_edge('a','h',weight=8)

    adjacency_list[0].push_back(neighbor(1, 4));
    adjacency_list[0].push_back(neighbor(7, 8));

// 1 = b
// g.add_edge('b','a',weight=4)
// g.add_edge('b','c',weight=8)
// g.add_edge('b','h',weight=11)
    adjacency_list[1].push_back(neighbor(0, 4));
    adjacency_list[1].push_back(neighbor(2, 8));
    adjacency_list[1].push_back(neighbor(7, 11));

    

// 2 = c
// g.add_edge('c','b',weight=8)
// g.add_edge('c','d',weight=7)
// g.add_edge('c','f',weight=4)
// g.add_edge('c','i',weight=2)
    adjacency_list[2].push_back(neighbor(1, 8));
    adjacency_list[2].push_back(neighbor(3, 7));
    adjacency_list[2].push_back(neighbor(5, 4));
    adjacency_list[2].push_back(neighbor(8, 2));



// 3 = d
// g.add_edge('d','d',weight=7)
// g.add_edge('d','e',weight=9)
// g.add_edge('d','f',weight=14)
    adjacency_list[3].push_back(neighbor(3, 7));
    adjacency_list[3].push_back(neighbor(4, 9));
    adjacency_list[3].push_back(neighbor(5, 14));


// 4 = e
// g.add_edge('e','d',weight=9)
// g.add_edge('e','f',weight=10)
    adjacency_list[4].push_back(neighbor(3, 9));
    adjacency_list[4].push_back(neighbor(5, 10));

    
// 5 = f
// g.add_edge('f','c',weight=4)
// g.add_edge('f','d',weight=14)
// g.add_edge('f','e',weight=10)
// g.add_edge('f','g',weight=2)
   
    
    adjacency_list[5].push_back(neighbor(2, 4));
    adjacency_list[5].push_back(neighbor(3, 14));
    adjacency_list[5].push_back(neighbor(4, 10));
    adjacency_list[5].push_back(neighbor(6, 2));


// 6 = g
// g.add_edge('g','f',weight=2)
// g.add_edge('g','h',weight=1)
// g.add_edge('g','i',weight=6)
    adjacency_list[6].push_back(neighbor(5, 2));
    adjacency_list[6].push_back(neighbor(7, 1)); 
    adjacency_list[6].push_back(neighbor(8, 6)); 

    
// 7 = h
// g.add_edge('h','a',weight=8)
// g.add_edge('g','b',weight=11)
// g.add_edge('h','g',weight=1)
// g.add_edge('h','i',weight=7)
    adjacency_list[7].push_back(neighbor(0, 9));
    adjacency_list[7].push_back(neighbor(1, 9));    
    adjacency_list[7].push_back(neighbor(6, 9));    
    adjacency_list[7].push_back(neighbor(8, 9));    
    

// 8 = i
// g.add_edge('i','c',weight=2)
// g.add_edge('i','g',weight=6)
// g.add_edge('i','h',weight=7)
    adjacency_list[8].push_back(neighbor(2, 2));
    adjacency_list[8].push_back(neighbor(6, 6));
    adjacency_list[8].push_back(neighbor(7, 7));

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    DijkstraComputePaths(0, adjacency_list, min_distance, previous);
    std::cout << "Distance from 0 to 5: " << min_distance[5] << std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPathTo(5, previous);
    std::cout << "Path : ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
