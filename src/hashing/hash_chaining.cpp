#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T> class chainingHash {
  size_t moduloValue;
  std::vector<std::list<T>> hashTable;

private:
  void sortedInsert(std::list<T> &hashTableEntry, const T &value) {
    hashTableEntry.insert(
        std::lower_bound(hashTableEntry.begin(), hashTableEntry.end(), value),
        value);
  }

public:
  chainingHash(const size_t moduloValue) {
    this->moduloValue = moduloValue;
    hashTable.resize(moduloValue);
  }

  size_t hashFunction(const T value) { return (value % moduloValue); }
  void insert(const T value) {
    size_t hashTableIndex = hashFunction(value);

    sortedInsert(hashTable[hashTableIndex], value);
  }
  void search(const T value) {}
  void remove(const T value) {
    size_t hashTableIndex = hashFunction(value);
    hashTable[hashTableIndex].remove(value);
  }

  void printHashTable(std::string delimiter = "->") {
    for (std::size_t i = 0; i < hashTable.size(); i++) {
      for (typename std::list<T>::iterator it = hashTable[i].begin();
           it != hashTable[i].end(); it++) {
        std::cout << *it << delimiter;
      }
      std::cout << "nullptr\n";
    }
  }
};

int main() {
  // std::list<int > hash_table_element;
  // my_list.insert()
  // std::lower_bound(hash_table_element.begin(), hash_table_element.end())

  chainingHash<int> c(10);
  c.insert(12);
  c.insert(25);
  c.insert(22);
  c.insert(3);
  c.insert(32);
  c.insert(7);
  c.insert(1);
  c.insert(14);
  c.printHashTable();
  return 0;
}
