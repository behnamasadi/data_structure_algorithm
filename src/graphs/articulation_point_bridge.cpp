/*
Refs:
1) https://www.youtube.com/watch?v=V6kRqdtM_Uk
2) https://www.youtube.com/watch?v=aZXi1unBdJA
3) https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T> class AdjacencyList {
public:
  std::vector<std::vector<T>> data;
  AdjacencyList(size_t m) { data = std::vector(m, std::vector<T>()); }
  void addEdge(size_t from, size_t to) {
    data[from].push_back(to);
    data[to].push_back(from);
  }
  void print() {
    for (size_t m = 0; m < data.size(); m++) {
      std::cout << m << "->";
      for (size_t n = 0; n < data[m].size(); n++) {
        std::cout << data[m][n] << "->";
      }
      std::cout << "nullptr\n";
    }
  }
};

template <typename T> struct Edge {
  Edge(T from, T to) {
    this->to = to;
    this->from = from;
  }
  T to, from;
};

std::vector<int> lows, ids;
std::vector<bool> visited;
int id = 0;

template <typename T>
void dfs(size_t at, int parent, AdjacencyList<T> graphadjacencyList,
         std::vector<Edge<T>> &bridges) {
  visited[at] = true;
  lows[at] = ids[at] = id++;
  std::cout << "visiting " << at << " coming from: " << parent << std::endl;
  for (auto neighbour : graphadjacencyList.data[at]) {
    std::cout << "visiting neighbours of " << at
              << ", neighbour id:" << neighbour << std::endl;

    // avoid returning to parnet
    if (neighbour == parent) {
      std::cout << neighbour << " is parent of " << at << std::endl;
      continue;
    }

    if (!visited[neighbour]) {
      dfs(neighbour, at, graphadjacencyList, bridges);
      lows[at] = std::min(lows[at], lows[neighbour]);
      if (ids[at] < lows[neighbour]) {

        Edge<T> edge(at, neighbour);
        bridges.push_back(edge);
      }
    } else {
      std::cout << "node id: " << neighbour << " has been already visited"
                << std::endl;
      lows[at] = std::min(lows[at], ids[neighbour]);
    }
  }
}

template <typename T>
std::vector<Edge<T>> findBridges(AdjacencyList<T> adjacencyList) {
  std::vector<Edge<T>> bridges;

  size_t n = adjacencyList.data.size();

  lows.resize(n);
  ids.resize(n);
  visited = std::vector(n, false);
  for (size_t i = 0; i < n; i++) {
    if (!visited[i])
      dfs(i, -1, adjacencyList, bridges);
  }
  return bridges;
}

int main() {
  std::cout << "Our Graph is:" << std::endl;
  std::cout << R"(
                  0
                /   \
               1----- 2
                   /   \
                  5     3
                 / \     \
                /   6     4
               /     \
              8-------7
               )"
            << std::endl;

  std::cout << "Adjacency List of our Graph is:" << std::endl;

  AdjacencyList<int> graphAdjacencyList(9);
  graphAdjacencyList.addEdge(0, 1);
  graphAdjacencyList.addEdge(0, 2);
  graphAdjacencyList.addEdge(1, 2);
  graphAdjacencyList.addEdge(2, 3);
  graphAdjacencyList.addEdge(3, 4);
  graphAdjacencyList.addEdge(2, 5);
  graphAdjacencyList.addEdge(5, 6);
  graphAdjacencyList.addEdge(6, 7);
  graphAdjacencyList.addEdge(7, 8);
  graphAdjacencyList.addEdge(8, 5);

  graphAdjacencyList.print();

  std::vector<Edge<int>> bridges = findBridges(graphAdjacencyList);
  for (Edge edge : bridges) {
    std::cout << "Edge From: " << edge.from << " To " << edge.to
              << " is a brdige" << std::endl;
  }

  for (size_t i = 0; i < lows.size(); i++) {
    std::cout << "node id: " << ids[i] << " lowest link value: " << lows[i]
              << std::endl;
  }
}
