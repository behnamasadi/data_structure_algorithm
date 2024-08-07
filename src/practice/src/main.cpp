#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <random>
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
}