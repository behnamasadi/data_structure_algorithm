#include <iostream>
#include <vector>

template <typename T> class AdjacencyMatrix {
  std::vector<std::vector<T>> data;

public:
  AdjacencyMatrix(size_t m, size_t n) {
    data = std::vector(m, std::vector(n, T(0)));
  }
  void addEdge(size_t from, size_t to, T weight = 1) {
    data[from][to] = weight;
    // data[to][from]=weight;
  }

  void print() {
    for (size_t m = 0; m < data.size(); m++) {
      for (size_t n = 0; n < data[0].size(); n++) {
        std::cout << data[m][n] << " ";
      }
      std::cout << "\n";
    }
  }
};

template <typename T> class AdjacencyList {
  std::vector<std::vector<T>> data;

public:
  AdjacencyList(size_t m) { data = std::vector(m, std::vector<T>()); }
  void addEdge(size_t from, size_t to) { data[from].push_back(to); }
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

int main() {

  std::cout << R"(
0-------1
|       |\
|       | \
|       |  2
|       | /
4-------3/
)" << std::endl;

  AdjacencyMatrix<int> graphAdjacencyMatrix(5, 5);
  graphAdjacencyMatrix.addEdge(0, 1);
  graphAdjacencyMatrix.addEdge(0, 4);

  graphAdjacencyMatrix.addEdge(1, 2);
  graphAdjacencyMatrix.addEdge(1, 3);
  graphAdjacencyMatrix.addEdge(1, 0);

  graphAdjacencyMatrix.addEdge(2, 1);
  graphAdjacencyMatrix.addEdge(2, 3);

  graphAdjacencyMatrix.addEdge(3, 1);
  graphAdjacencyMatrix.addEdge(3, 2);
  graphAdjacencyMatrix.addEdge(3, 4);

  graphAdjacencyMatrix.addEdge(4, 0);
  graphAdjacencyMatrix.addEdge(4, 3);

  std::cout << "Graph Adjacency Matrix:" << std::endl;

  graphAdjacencyMatrix.print();
  AdjacencyList<int> graphAdjacencyList(5);
  graphAdjacencyList.addEdge(0, 1);
  graphAdjacencyList.addEdge(0, 4);

  graphAdjacencyList.addEdge(1, 2);
  graphAdjacencyList.addEdge(1, 3);
  graphAdjacencyList.addEdge(1, 0);

  graphAdjacencyList.addEdge(2, 1);
  graphAdjacencyList.addEdge(2, 3);

  graphAdjacencyList.addEdge(3, 1);
  graphAdjacencyList.addEdge(3, 2);
  graphAdjacencyList.addEdge(3, 4);

  graphAdjacencyList.addEdge(4, 0);
  graphAdjacencyList.addEdge(4, 3);

  std::cout << "Graph Adjacency List:" << std::endl;
  graphAdjacencyList.print();
}
