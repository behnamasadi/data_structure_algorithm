#include <iostream>
#include <map>
#include <vector>

// https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0

int main() {

  std::vector<char> collection = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};

  int num_repeat;
  int array_size;
  std::cin >> num_repeat;
  std::map<char, char> bolts, nuts;
  char item;
  int index = 0;
  while (num_repeat > 0) {
    std::cin >> array_size;

    index = 0;
    while (array_size - index > 0) {
      std::cin >> item;
      bolts[item] = item;
      index++;
    }
    index = 0;
    while (array_size - index > 0) {
      std::cin >> item;
      nuts[item] = item;
      index++;
    }

    for (size_t i = 0; i < collection.size(); i++) {
      if (bolts[collection[i]] != NULL) {
        std::cout << bolts[collection[i]] << " ";
      }
    }
    std::cout << "\n";
    for (size_t i = 0; i < collection.size(); i++) {
      if (nuts[collection[i]] != NULL) {
        std::cout << nuts[collection[i]] << " ";
      }
    }

    std::cout << "\n";
    bolts.clear();
    nuts.clear();
    num_repeat--;
  }
}
