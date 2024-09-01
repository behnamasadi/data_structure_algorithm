
#include <algorithm>
#include <iostream>
#include <vector>

/*
27. Remove Element
https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution27 {
public:
  int removeElement(std::vector<int> &nums, int val) {

    int head = 0;
    int tail = nums.size() - 1;
    while (head <= tail) {
      if (nums[head] == val) {
        if (nums[tail] != val) {
          std::swap(nums[head], nums[tail]);
        }
        tail--;
      } else {
        head++;
      }
    }
    return head;
  }
};

/*
26. Remove Duplicates from Sorted Array

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/
class Solution26 {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty())
      return 0;

    // The pointer for the next unique element position
    int uniqueIndex = 1;

    // Start from the second element and iterate through the array
    for (int i = 1; i < nums.size(); ++i) {
      // If the current element is not equal to the previous element, it's
      // unique
      if (nums[i] != nums[i - 1]) {
        // Place it at the uniqueIndex and move the uniqueIndex forward
        nums[uniqueIndex] = nums[i];
        uniqueIndex++;
      }
    }
    return uniqueIndex;
  }
};

/*

https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
169. Majority Element

*/

class Solution169 {
public:
  int majorityElement(std::vector<int> &nums) {
    // int candid_index = 0;
    // int vote = 0;
    // for (std::size_t i = 0; i < nums.size(); i++) {
    //   if (nums[i] == nums[candid_index]) {
    //     vote++;
    //   } else {
    //     vote--;
    //   }
    //   if (vote == 0) {
    //     candid_index = i;
    //     vote++;
    //   }
    // }
    // return nums[candid_index];

    // Boyer-Moore Voting Algorithm,
    int candidate = nums[0];
    int vote = 0;

    for (int num : nums) {
      if (vote == 0) {
        candidate = num;
      }
      vote += (num == candidate) ? 1 : -1;
    }

    return candidate;
  }
};

/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
28. Find the Index of the First Occurrence in a String
*/

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    // Boyer–Moore string-search
    return 0;
  }
};

template <typename T> void printVec(std::vector<T> &vec) {
  for (const auto &i : vec)
    std::cout << i << " ";
}

/*
189. Rotate Array
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

https://www.youtube.com/watch?v=BHr381Guz3Y

*/

class Solution189 {
public:
  void rotate(std::vector<int> &nums, int k) {
    /*
    k=2
    1 2 3 , 4 5

    we can do it in the following steps:

    5 4 , 3 2 1

    now reverse the two pieces again

    4 5 , 1 2 3

    */
    k = k % nums.size();
    int begin = 0;
    int end = nums.size() - 1;
    while (begin < end) {
      std::swap(nums[begin], nums[end]);
      begin++;
      end--;
    }

    begin = 0;
    end = k - 1;

    while (begin < end) {
      std::swap(nums[begin], nums[end]);
      begin++;
      end--;
    }

    begin = k;
    end = nums.size() - 1;

    while (begin < end) {
      std::swap(nums[begin], nums[end]);
      begin++;
      end--;
    }
  }
};

/*

14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150


*/
class Solution14 {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {

    int index = 0;

    char c = strs[0][index];
    for (int i = 1; i < strs.size(); i++) {
      if (c != strs[i][index]) {
        break;
      }
    }
    return strs[0].substr(0, index);
  }
};

/*
https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150
58. Length of Last Word

*/

class Solution58 {
public:
  int lengthOfLastWord(std::string s) {
    int start_at_end = s.size() - 1;
    int length = 0;
    while (start_at_end >= 0 && s[start_at_end] == ' ') {
      start_at_end--;
    }
    while (start_at_end >= 0 && s[start_at_end] != ' ') {
      start_at_end--;
      length++;
    }

    // int length = 0;
    // int i = s.size() - 1;

    // while (i >= 0 && s[i] == ' ') {
    //   i--;
    // }

    // while (i >= 0 && s[i] != ' ') {
    //   length++;
    //   i--;
    // }

    // return length;

    return length;
  }
};

/*
13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution13 {
public:
  int romanToInt(std::string s) {
    // Define a map for Roman numeral values
    std::unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                           {'L', 50},  {'C', 100}, {'D', 500},
                                           {'M', 1000}};

    int total = 0;
    int prev_value = 0;

    // Iterate through the Roman numeral string from left to right
    for (char c : s) {
      int current_value = roman[c];

      // If the previous value is smaller, subtract twice the previous value
      // (because it was already added once in the previous iteration)
      if (prev_value < current_value) {
        total += current_value - 2 * prev_value;
      } else {
        total += current_value;
      }

      // Update the previous value to the current one
      prev_value = current_value;
    }

    return total;
  }
};

int main() {
  Solution27 s;
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  //   int counter = 3;
  //   std::cout << nums[counter--] << std::endl;

  //   int val = 12;

  //   std::cout << s.removeElement(nums, val) << std::endl;
  //   printVec(nums);
  //   std::cout << "\n";

  nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  auto last = std::unique(nums.begin(), nums.end());
  for (auto it = nums.begin(); it != last; it++) {
    std::cout << *it << " ";
  }

  std::cout << "\n";
  nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  Solution189 s198;
  s198.rotate(nums, k);

  for (auto it = nums.begin(); it != nums.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << "\n";
  //   nums = {2, 2, 1, 1, 1, 2, 2};

  nums = {3, 2, 3};

  Solution169 s169;

  std::cout << "Majority Element is:" << s169.majorityElement(nums) << "\n";

  Solution14 s14;
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  std::cout << "longest common prefix is:" << s14.longestCommonPrefix(strs)
            << "\n";

  std::string str = "   fly me   to   the moon  ";
  str = "Hello World";
  str = "luffy";
  Solution58 s58;

  std::cout << "length of last word: " << s58.lengthOfLastWord(str) << "\n";
}
