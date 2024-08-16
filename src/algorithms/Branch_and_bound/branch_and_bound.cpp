#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

template <typename T> struct cell {
  T value;
  bool visited = false;
  bool operator<(cell<T> other) { return value < other.value; }
  // comp()
};

void assigningJobsToPeople() {

  /*
  |Person name|Cost Job 1|Cost  Job 2|Cost Job 3  |Cost Job 4 |
  | ----------|--------- | -----     | -----      | -----     |
  | A         | 9        | 2         | 7          |   8       |
  | B         | 6        | 4         | 3          |   7       |
  | C         | 5        | 8         | 1          |   8       |
  | D         | 7        | 6         | 9          |   4       |
  */

  std::vector<std::vector<cell<int>>> table;
  // A
  table.push_back({{9, false}, {2, false}, {7, false}, {8, false}});
  // B
  table.push_back({{6, false}, {4, false}, {3, false}, {7, false}});
  // C
  table.push_back({{5, false}, {8, false}, {1, false}, {8, false}});
  // D
  table.push_back({{7, false}, {6, false}, {9, false}, {4, false}});

  // calculate lower bound

  // Number of columns
  size_t num_columns = table[0].size();
  // Number of rows
  size_t num_rows = table.size();

  // Vector to store the minimum values for each column
  std::vector<cell<int>> min_elements(
      num_columns, cell<int>(std::numeric_limits<int>::max()));

  std::min_element(table.begin(), table.end(),
                   [](cell<int> rhs, cell<int> lhs) { return true; });
}

int main() { return 0; }