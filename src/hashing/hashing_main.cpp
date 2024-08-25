#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>
namespace chaining {

class hash {
  int bucket;
  std::vector<std::list<int>> table;

public:
  hash(int bucket) {
    this->bucket = bucket;
    table.resize(bucket);
  }

  int hashfunction(int entry) { return (entry % bucket); }

  void insert(int entry) {
    int index = hashfunction(entry);
    table[index].push_back(entry);
  }

  void remove(int entry) {
    int index = hashfunction(entry);
    table[index].remove(entry);
  }

  void printTable() {
    for (std::size_t i = 0; i < table.size(); i++) {
      std::cout << "[" << i << "]:";

      for (std::list<int>::iterator it = table[i].begin(); it != table[i].end();
           it++) {
        std::cout << "->" << *it;
      }
      std::cout << "\n";
    }
  }
};

} // namespace chaining

namespace openAddressing {
// https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
class linearProbing {};
} // namespace openAddressing

void chainingHashExample() {
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a) / sizeof(a[0]);

  // insert the keys into the hash table
  chaining::hash h(7); // 7 is count of buckets in
  // hash table
  for (int i = 0; i < n; i++)
    h.insert(a[i]);

  // display the Hash table
  h.printTable();

  // delete 12 from hash table
  std::cout << "removing 12" << std::endl;
  h.remove(12);

  // display the Hash table
  h.printTable();
}

int main() {
  std::hash<int> int_hasher;
  //   std::hash<float> int_hasher;

  std::hash<std::string> str_hasher;

  // int_hasher[3];
  //   std::size_t hash_value = int_hasher(45886.783);
  std::size_t hash_value = int_hasher(45886);

  std::cout << hash_value << std::endl;

  std::cout << str_hasher("bcergerggd") << std::endl;

  std::map<int, int> counter;

  std::vector<int> arr = {5, 3, 2, 4, 2, 3, 9, 8, 2, 12};
  for (const auto &a : arr) {
    counter[a]++;
  }
  // int_hasher(a);

  for (const auto &c : counter) {
    std::cout << c.first << ":" << c.second << std::endl;
  }

  std::unordered_map<int, std::string> my_map = {
      {1, "one"}, {2, "two"}, {3, "three"}};

  std::cout << "Number of buckets in my_map: " << my_map.bucket_count()
            << std::endl;
  std::cout << "Current load factor in my_map: " << my_map.load_factor()
            << std::endl;
  std::cout << "Max load factor in my_map: " << my_map.max_load_factor()
            << std::endl;

  return 0;
}
