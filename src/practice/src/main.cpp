#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <random>
#include <stack>
#include <vector>

template <typename T> void printArray(T arr[], size_t size, size_t start = 0) {
  for (std::size_t i = start; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

int adder(int a, int b) { return a + b; }

template <typename T> void insertionSort(T arr[], size_t size) {}

typedef int (*fn_ptr)(int, int);

int some_func(int a, int b, fn_ptr fn) { return fn(a, b); }

template <typename T> struct array {
  int m_size;
  T *data;
  array(size_t size) : m_size(size) { data = new T(m_size); }
  ~array() { delete[] data; }
};

template <typename T> struct node {
  T value = std::numeric_limits<T>::min();
  node *left_child;
  node *right_child;
  void insert(T key) {}
};

int main() {

  int (*myfn_ptr)(int, int);

  fn_ptr myfn = adder;

  myfn_ptr = adder;

  std::cout << myfn_ptr(2, 3) << std::endl;

  int a = 2;
  int b = 3;

  std::cout << some_func(2, 3, adder) << std::endl;

  // std::function<int,int

  array<int> my_array(7);

  my_array.data[0] = 0;
  my_array.data[1] = 1;
  my_array.data[2] = 5;
  my_array.data[4] = 7;
  my_array.data[5] = 3;

  // std::sort(my_array.data[0], my_array.data[5]);

  // std::iterator

  std::vector<int> arr = {-1, -14, 4, 3, 12, 5, 90, 6, 1, 11, 7, 17, 0};
  printArray(&arr[0], arr.size());
  for (std::size_t i = 0; i < 10; i++) {
    std::next_permutation(arr.begin(), arr.end());

    printArray(&arr[0], arr.size());
  }
  std::size_t half_length = arr.size() / 2;
  std::cout << half_length << ": " << arr[half_length] << std::endl;

  std::nth_element(arr.begin(), arr.begin() + half_length, arr.end(),
                   std::greater{});

  std::cout << half_length << ": " << arr[half_length] << std::endl;
  printArray(&arr[0], arr.size());
  auto median = arr[half_length];

  node<int> *root = new node<int>;
  root->value = median;
  node<int> *t = root;
  arr.erase(arr.begin() + half_length);
  for (const auto &item : arr) {
    if (item > t->value) {

    } else {
    }
  }
  std::string str = {"{(a+b)*(c-d)}/e"};
  std::stack<char> match;
  std::string specia_char_opening = {"{(["};
  std::string specia_char_closing = {"})]"};
  std::size_t last_open;
  for (const auto &c : str) {
    std::cout << c << " ";
    // std::search(specia_char_opening.begin(), specia_char_opening.end(),
    //             c.begin(), c.end());
    std::size_t open = specia_char_opening.find(c);
    std::size_t close = specia_char_closing.find(c);
    if (open != std::string::npos) {
      match.push(c);
      last_open = open;

    } else if (close != std::string::npos) {
      if (close == last_open)
        match.pop();
    }
  }
  std::cout << match.size() << "\n";
}