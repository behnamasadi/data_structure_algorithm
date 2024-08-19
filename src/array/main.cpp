

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>

// https://www.geeksforgeeks.org/array-data-structure-guide/?ref=shm

template <typename T> void printArray(T arr[], std::size_t size) {
  for (std::size_t i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}
// https://www.geeksforgeeks.org/two-pointers-technique/?ref=roadmap
// https://www.youtube.com/watch?v=On03HWe2tZM
void arrayTwoPointer() {

  std::array<int, 6> arr = {10, 20, 35, 50, 75, 80};
  int target = 70;
  auto begin = arr.begin();
  auto end = arr.end();
  int rest;
  bool found = false;

  // while (!found) {
  while (begin < end) {
    auto sum = *begin + *end;

    if (sum == target) {
      std::cout << begin - arr.begin() << ", " << end - arr.begin()
                << std::endl;
      break;
    } else if (target >= sum) {
      begin++;
    } else {
      end--;
    }
  }
}

// https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/
void largestThreeDistinctElements() {

  std::vector<int> arr = {10, 4, 3, 50, 23, 90};

  int first, second, third;
  first = second = third = std::numeric_limits<int>::min();
  std::cout << third << std::endl;
  for (const auto &item : arr) {
    if (item > first) {
      third = second;
      second = first;
      first = item;
    } else if (item > second && item != first) {
      third = second;
      second = item;
    } else if (item > third && item != second && item != first) {
      third = item;
    }
  }

  std::cout << "Three largest elements are " << first << " " << second << " "
            << third << std::endl;

  std::nth_element(arr.begin(), arr.begin() + 0, arr.end(), std::greater{});

  std::cout << arr[0] << std::endl;

  std::nth_element(arr.begin(), arr.begin() + 1, arr.end(), std::greater{});
  std::cout << arr[1] << std::endl;

  std::nth_element(arr.begin(), arr.begin() + 2, arr.end(), std::greater{});
  std::cout << arr[2] << std::endl;
  // std::nth_element(arr.begin(), arr.begin() + 2, arr.end(), std::less{});

  // algorithms like partial sorting or using a priority queue could be
  // considered for performance optimizations.
}

// https://www.geeksforgeeks.org/move-zeroes-end-array/
void moveAllZeroesToEndOfArray() {}

void N_mostFrequentNumber() {

  std::vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
  int K = 2;
  std::hash<int> hash_table;
  hash_table(0) = 5;
}

int main() {

  std::array<int, 5> arr = {2, 34, 7, 8, 45};

  int n = 34;
  // std::binary_search()
  auto ix = std::find(arr.begin(), arr.end(), n);
  std::cout << *std::next(ix) << std::endl;

  std::cout << std::distance(arr.begin(), ix) << std::endl;

  std::sort(arr.begin(), arr.end(), std::greater{});

  std::cout << std::boolalpha
            << std::is_sorted(arr.begin(), arr.end(), std::greater{})
            << std::endl;

  // std::search
  // std::find_if
  // std::find_first_of
  //

  std::string s1, s2;

  s1 = "kuewgfwiefgywemnhyuewetiriwoedcebcoweofce";
  s2 = "ue";

  auto idx = std::search(s1.begin(), s1.end(),
                         std::boyer_moore_searcher(s2.begin(), s2.end()));

  std::cout << idx - s1.begin() << std::endl;

  //   const auto it =      std::search(haystack.begin(), haystack.end(),
  //   std::boyer_moore_searcher(needle.begin(), needle.end()));

  printArray(&s1[0], s1.size());

  std::nth_element(s1.begin(), s1.begin() + 2, s1.end(), std::less{});

  std::cout << s1[2] << std::endl;

  std::sort(s1.begin(), s1.end(), std::less{});

  printArray(&s1[0], s1.size());

  printArray(&arr[0], 5);

  auto first_even = std::find_if(
      arr.begin(), arr.end(), [](auto element) { return (element % 2 == 0); });

  std::cout << *first_even << std::endl;

  // std::stransform

  arrayTwoPointer();
  largestThreeDistinctElements();
}
