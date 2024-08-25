#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

struct edge {

  int from;
  int to;
  float cost;
  bool operator<(const edge &other) {
    return cost > other.cost; // Note: This is flipped for min-heap in
                              // std::priority_queue
  }
};

typedef std::list<edge> NodeNeighbours;

class Node {
public:
  int id;
  NodeNeighbours neighbours;

  Node(int id) : id(id) {}
};

class Graph {
public:
  std::vector<Node> nodes;
  Graph(int num_nodes) {
    nodes.reserve(num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
      nodes.emplace_back(i);
    }
  }

  void add_edge(int from, int to, float cost) {
    nodes[from].neighbours.push_back({from, to, cost});
  }
};

const int UNDEFINED = -1;

void dijkstra(Graph &graph, int startNodeIdex) {
  std::vector<int> distanceFromStart(graph.nodes.size(),
                                     std::numeric_limits<int>::infinity());

  std::vector<int> previous(graph.nodes.size(), UNDEFINED);

  // std::priority_queue<edge>;

  distanceFromStart[startNodeIdex] = 0;
}

int main() {

  std::vector<int> nodes = {1, 2, 3, 4, 5, 6};
  std::vector<int> visitd_nodes(nodes.size(), 0);

  /*
  This is the matrix representation of the graph
        0   1   2   3   4   5
    0   -   7   9   -   -   14
    1   7   -  10  15   -   -
    2   9   10  -  11   -   -
    3   -   15  11  -   6   -
    4   -   -   -   6   -   9
    5   14  -   -   -   9   -
  */

  Graph graph(5);

  graph.add_edge(0, 1, 7);
  graph.add_edge(0, 2, 9);
  graph.add_edge(0, 5, 14);

  graph.add_edge(1, 0, 7);
  graph.add_edge(1, 2, 10);
  graph.add_edge(1, 3, 15);

  graph.add_edge(2, 0, 9);
  graph.add_edge(2, 1, 10);
  graph.add_edge(2, 3, 11);

  graph.add_edge(3, 1, 5);
  graph.add_edge(3, 2, 11);
  graph.add_edge(3, 4, 6);

  graph.add_edge(4, 3, 6);
  graph.add_edge(4, 5, 9);

  graph.add_edge(5, 0, 14);
  graph.add_edge(5, 4, 9);

  return 0;
}