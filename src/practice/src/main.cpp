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

struct Node {
  int index = 0;
  Node *next = nullptr;
};

/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150
 */
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int max_profit = 0;
    std::size_t buy_day = 0;
    for (std::size_t day = 1; day < prices.size(); day++) {
      if (prices[buy_day] > prices[day]) {
        buy_day = day;
      }
      if (prices[day] - prices[buy_day] > max_profit) {
        max_profit = prices[day] - prices[buy_day];
      }
    }
    return max_profit;
  }
};

/*
https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution2 {
public:
  int majorityElement(std::vector<int> &nums) {
    std::map<int, int> count;
    int max = 0;
    int max_element = -1;
    for (const auto &n : nums) {
      count[n]++;
      // std::cout << "n: " << n << " count[" << n << "]: " << count[n] <<
      // std::endl;

      if (count[n] > max) {
        // std::cout << "n: " << n << std::endl;
        max_element = n;
        max = count[n];
      }
    }
    return max_element;
  }
};

/*
class Solution3 {
public:
  int majorityElement(std::vector<int> &nums) {
    // https://www.youtube.com/watch?v=onHcrX-Xv9Y&t=14s
    int max = 0;
    int max_element = -1;
    for (const auto &n : nums) {

      // std::cout << "n: " << n << " count[" << n << "]: " << count[n] <<
      // std::endl;

      if (count[n] > max) {
        // std::cout << "n: " << n << std::endl;
        max_element = n;
        max = count[n];
      }
    }
    return max_element;
  }
};
*/

// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
// https://www.youtube.com/watch?v=Lsh9wWPrK3Y

bool canConstruct(std::string ransomNote, std::string magazine) {
  // std::map<>
  for (const auto &c : magazine) {
  }
}

int main() {

  // std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  // Solution s1;
  // std::cout << s1.maxProfit(prices) << std::endl;

  // std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

  std::vector<int> nums = {3, 3, 4};

  Solution2 s2;
  std::cout << s2.majorityElement(nums) << std::endl;

  Node node1, node3, node5, node7, node9;

  node1.index = 1;
  node1.next = &node3;

  node3.index = 3;
  node3.next = &node5;

  node5.index = 5;
  node5.next = &node7;

  node7.index = 7;
  node7.next = &node9;

  node9.index = 9;

  // Node *node = &node1;
  // while (node->next != nullptr) {
  //   node=node->next;
  //   std::cout << "node:" << node->index << std::endl;
  // }

  // int (*myfn_ptr)(int, int);

  // fn_ptr myfn = adder;

  // myfn_ptr = adder;

  // std::cout << myfn_ptr(2, 3) << std::endl;

  // int a = 2;
  // int b = 3;

  // std::cout << some_func(2, 3, adder) << std::endl;

  // // std::function<int,int

  // array<int> my_array(7);

  // my_array.data[0] = 0;
  // my_array.data[1] = 1;
  // my_array.data[2] = 5;
  // my_array.data[4] = 7;
  // my_array.data[5] = 3;

  // // std::sort(my_array.data[0], my_array.data[5]);

  // // std::iterator

  // std::vector<int> arr = {-1, -14, 4, 3, 12, 5, 90, 6, 1, 11, 7, 17, 0};
  // printArray(&arr[0], arr.size());
  // for (std::size_t i = 0; i < 10; i++) {
  //   std::next_permutation(arr.begin(), arr.end());

  //   printArray(&arr[0], arr.size());
  // }
  // std::size_t half_length = arr.size() / 2;
  // std::cout << half_length << ": " << arr[half_length] << std::endl;

  // std::nth_element(arr.begin(), arr.begin() + half_length, arr.end(),
  //                  std::greater{});

  // std::cout << half_length << ": " << arr[half_length] << std::endl;
  // printArray(&arr[0], arr.size());
  // auto median = arr[half_length];

  // node<int> *root = new node<int>;
  // root->value = median;
  // node<int> *t = root;
  // arr.erase(arr.begin() + half_length);
  // for (const auto &item : arr) {
  //   if (item > t->value) {

  //   } else {
  //   }
  // }
  // std::string str = {"{(a+b)*(c-d)}/e"};
  // std::stack<char> match;
  // std::string specia_char_opening = {"{(["};
  // std::string specia_char_closing = {"})]"};
  // std::size_t last_open;
  // for (const auto &c : str) {
  //   std::cout << c << " ";
  //   // std::search(specia_char_opening.begin(), specia_char_opening.end(),
  //   //             c.begin(), c.end());
  //   std::size_t open = specia_char_opening.find(c);
  //   std::size_t close = specia_char_closing.find(c);
  //   if (open != std::string::npos) {
  //     match.push(c);
  //     last_open = open;

  //   } else if (close != std::string::npos) {
  //     if (close == last_open)
  //       match.pop();
  //   }
  // }
  // std::cout << match.size() << "\n";

  std::vector<int> arr = {15, 30, 20, 40, 5, 6, 10, 12};
}
