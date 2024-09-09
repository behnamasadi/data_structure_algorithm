
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;
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

/*
https://leetcode.com/problems/lemonade-change/
860. Lemonade Change

*/

class Solution860 {
public:
  bool lemonadeChange(vector<int> &bills) {
    int fives = 0;
    int tens = 0;
    int twenties = 0;

    for (const auto &bill : bills) {
      if (bill == 5)
        fives++;
      else if (bill == 10) {
        if (fives >= 1) {
          tens++;
          fives--;
        } else {
          return false;
        }

      } else // (bill == 20)
      {
        if (tens >= 1 && fives >= 1) {
          tens--;
          fives--;
        } else if (fives >= 3) {
          fives = fives - 3;
        } else
          return false;
      }
    }
    return true;
  }
};

/*
88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150


https://www.youtube.com/watch?v=P1Ic85RarKY
*/
class Solutio88 {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    int nums1_current_index = m + n - 1;
    int num1_pointer = m - 1;
    int num2_pointer = n - 1;

    while (num1_pointer >= 0 && num2_pointer >= 0) {
      if (nums2[num2_pointer] >= nums1[num1_pointer]) {
        nums1[nums1_current_index] = nums2[num2_pointer];
        num2_pointer--;
      } else {
        nums1[nums1_current_index] = nums1[num1_pointer];
        num1_pointer--;
      }
      nums1_current_index--;
    }
    // fill the nums1 with leftover nums2 elements for instance for the case
    // nums1=[2,2,3] and nums2=[1,5,6]
    while (num2_pointer >= 0) {
      nums1[nums1_current_index] = nums2[num2_pointer];
      num2_pointer--;
      nums1_current_index--;
    }

    /*

     int nums1_current_index = m + n - 1;
     int num1_pointer = m - 1;
     int num2_pointer = n - 1;

     // Traverse both arrays starting from the end
     while (num2_pointer >= 0) {
       // If nums1 is exhausted or nums2's element is greater, copy nums2's
       // element
       if (num1_pointer < 0 ||
           (num2_pointer >= 0 && nums2[num2_pointer] >= nums1[num1_pointer])) {
         nums1[nums1_current_index] = nums2[num2_pointer];
         num2_pointer--;
       } else {
         // Otherwise, copy nums1's element
         nums1[nums1_current_index] = nums1[num1_pointer];
         num1_pointer--;
       }
       nums1_current_index--;
     }
 */
  }
};

/*

https://leetcode.com/problems/permutation-in-string/description/
567. Permutation in String
https://www.youtube.com/watch?v=UbyhOgBN834

https://www.youtube.com/watch?v=quSfR-uwkZU
*/

class Solution567 {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size())
      return false;

    // Arrays to store the frequency counts of characters in s1 and the current
    // window of s2
    std::vector<int> s1Count(26, 0), s2Count(26, 0);

    // Fill frequency array for s1 and the first window of s2
    for (int i = 0; i < s1.size(); ++i) {
      s1Count[s1[i] - 'a']++;
      s2Count[s2[i] - 'a']++;
    }

    // Helper function to compare the two frequency arrays
    auto matches = [](const std::vector<int> &a, const std::vector<int> &b) {
      for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i])
          return false;
      }
      return true;
    };

    // Check the first window
    if (matches(s1Count, s2Count))
      return true;

    // Now slide the window over s2
    for (int i = s1.size(); i < s2.size(); ++i) {
      // Add the new character to the window
      s2Count[s2[i] - 'a']++;
      // Remove the old character from the window
      s2Count[s2[i - s1.size()] - 'a']--;

      // Check if the current window matches the frequency array of s1
      if (matches(s1Count, s2Count))
        return true;
    }

    return false;
  }
};

/*
128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

*/

class Solution128 {
public:
  int longestConsecutive(vector<int> &nums) {

    if (nums.empty())
      return 0;

    std::unordered_set<int> nums_set(nums.begin(), nums.end());

    int longest_consecutive_sequence = 0;
    int current_consecutive_sequence = 0;

    // for (const auto &num : nums)
    for (const auto &num : nums_set)

    {
      // check if i is the start of series:
      if (nums_set.find(num - 1) == nums_set.end()) {
        int start = num;
        current_consecutive_sequence = 1;

        /*
        This woulnd't work if the size of array is 1 i.e. nums={0}
        The condition check and the increment (start++) happen almost
        simultaneously due to the use of the postfix increment operator ++.
        */
        // while (nums_set.find(++start) != nums_set.end()) {

        while (nums_set.find(++start) != nums_set.end()) {
          current_consecutive_sequence++;
        }

        longest_consecutive_sequence = std::max(current_consecutive_sequence,
                                                longest_consecutive_sequence);
      }
    }
    return longest_consecutive_sequence;
  }

  /*
    int longestConsecutive(vector<int> &nums) {
      if (nums.empty())
        return 0;

      unordered_set<int> numSet(nums.begin(), nums.end());
      int longestStreak = 0;

      for (int num : numSet) {
        // Check if it is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
          int currentNum = num;
          int currentStreak = 1;

          // Increment currentNum while its next consecutive number is in the
    set while (numSet.find(currentNum + 1) != numSet.end()) { currentNum++;
            currentStreak++;
          }

          // Update the longest streak found
          longestStreak = max(longestStreak, currentStreak);
        }
      }

      return longestStreak;
    }
    */
};

/*
Encode and Decode Strings - Leetcode 271
https://www.youtube.com/watch?v=B1k_sxOSgv8

https://algo.monster/liteproblems/271
*/

class Solution659 {
public:
  std::vector<std::string> encodeDecodeString(std::vector<std::string> &words) {
    std::stringstream ss;
    for (const auto &word : words) {
      ss << word.size() << word << "#";
    }
    std::cout << ss.str() << std::endl;
    return std::vector<std::string>();
  }
};

/*
https://leetcode.com/problems/contains-duplicate/description/

217. Contains Duplicate
*/

class Solution217 {
public:
  bool containsDuplicate(vector<int> &nums) {

    return nums.size() !=
           std::unordered_set<int>(nums.begin(), nums.end()).size();

    // std::unordered_set<int> nums_set(nums.begin(), nums.end());

    // if (nums.size() != nums_set.size())
    //   return true;
    // else
    //   return false;
  }
};

/*
167. Two Sum II - Input Array Is Sorted

there is exactly one solution.

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

*/
class Solution167 {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    // there is exactly one solution.
    // if (numbers.size() < 2)
    //   return {};

    int numbers_r = numbers.size() - 1;
    int numbers_l = 0;

    while (numbers_l < numbers_r) {
      if (target == numbers[numbers_r] + numbers[numbers_l]) {
        break;
      } else if (target - numbers[numbers_l] < numbers[numbers_r])
        numbers_r--;
      else {
        numbers_l++;
      }
    }

    return {numbers_l + 1, numbers_r + 1};
  }
};

/*

https://leetcode.com/problems/3sum/
15. 3Sum

*/

class Solution15 {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    // std::map<int, int> nums_map; //(nums.begin(), nums.end());
    // for (const auto &num : nums) {
    //   // nums_map.insert(std::pair)
    //   nums_map[num]++;
    // }

    // // map is always ordered, now we can do a two sum
    // int target = 0;
    // for (const auto &num : nums_map) {

    //   //target = num;
    // }

    return {{}};
  }
};

/*
https://leetcode.com/problems/trapping-rain-water/description/
42. Trapping Rain Water
https://www.youtube.com/watch?v=ZI2z5pq0TqA&t=327s

*/

class Solution42 {
public:
  int trap(vector<int> &height) {

    int sum = 0;

    std::vector<int> max_height_lefts(height.size(), 0);
    std::vector<int> max_height_rights(height.size(), 0);

    int max_height_left = 0;
    int max_height_right = 0;
    int max_height_index = 0;

    for (int i = 0; i < max_height_lefts.size(); i++) {
      if (height[i] > max_height_left) {
        max_height_left = height[i];
        max_height_index = i;
      }
      max_height_lefts[i] = max_height_index;
    }

    max_height_right = 0;
    for (int i = max_height_lefts.size(); i > 0; i--) {
      if (height[i] > max_height_right) {
        max_height_right = height[i];
        max_height_index = i;
      }
      max_height_rights[i] = max_height_index;
    }

    for (const auto &h : max_height_lefts) {
      std::cout << h << ",";
    }

    std::cout << std::endl;

    for (const auto &h : max_height_rights) {
      std::cout << h << ",";
    }

    std::cout << std::endl;

    // for (int i = 0; i < height.size(); i++) {

    //   int val = std::min(max_height_left, max_height_right) - height[0];
    //   std::max(0, val);
    // }

    return sum;
  }
};

int main() {

  ///////////////////////////// Solution27 /////////////////////////////

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

  ///////////////////////////// Solution198 /////////////////////////////

  Solution189 s198;
  s198.rotate(nums, k);

  for (auto it = nums.begin(); it != nums.end(); it++) {
    std::cout << *it << " ";
  }

  std::cout << "\n";
  //   nums = {2, 2, 1, 1, 1, 2, 2};

  ///////////////////////////// Solution169 /////////////////////////////
  Solution169 s169;
  nums = {3, 2, 3};

  std::cout << "Majority Element is:" << s169.majorityElement(nums) << "\n";

  ///////////////////////////// Solution14 /////////////////////////////

  Solution14 s14;
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  std::cout << "longest common prefix is:" << s14.longestCommonPrefix(strs)
            << "\n";

  ///////////////////////////// Solution158 /////////////////////////////

  Solution58 s58;
  std::string str = "   fly me   to   the moon  ";
  str = "Hello World";
  str = "luffy";

  std::cout << "length of last word: " << s58.lengthOfLastWord(str) << "\n";

  ///////////////////////////// Solution88 /////////////////////////////

  Solutio88 s88;
  // std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  //  int m = 3;
  std::vector<int> nums1;
  nums1.resize(1);
  int m = 0;
  // std::vector<int> nums2 = {2, 5, 6};
  // int n = 3;
  std::vector<int> nums2 = {1};
  int n = 1;

  s88.merge(nums1, m, nums2, n);

  std::cout << "merged array: \n";
  for (const auto &s : nums1) {
    std::cout << s << " ";
  }
  std::cout << "\n";
  ///////////////////////////// Solution567 /////////////////////////////

  std::string s1 = "ab";
  std::string s2 = "eidbaooo";
  Solution567 s567;
  s567.checkInclusion(s1, s2);

  ///////////////////////////// Solution128 /////////////////////////////

  Solution128 s128;

  // nums = {100, 4, 200, 1, 3, 2};
  nums = {0};

  cout << "The length of the longest consecutive elements sequence is "
       << s128.longestConsecutive(nums) << endl;

  ///////////////////////////// Solution659 /////////////////////////////

  Solution659 s659;
  std::vector<std::string> input = {"lint", "code", "love", "you"};
  std::vector<std::string> output = {"lint", "code", "love", "you"};

  s659.encodeDecodeString(input);
  ///////////////////////////// Solution217 /////////////////////////////

  Solution217 s217;
  nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  // nums = {1, 2, 3, 4};
  std::cout << std::boolalpha << s217.containsDuplicate(nums) << std::endl;

  ///////////////////////////// Solution167 /////////////////////////////

  Solution167 s167;

  std::vector<int> numbers = {1, 2, 7, 11, 15};
  // numbers = {2, 3, 4};
  int target = 9;

  auto twosums = s167.twoSum(numbers, target);
  std::cout << "Two Sum II:" << twosums[0] << "," << twosums[1] << std::endl;

  ///////////////////////////// Solution15  /////////////////////////////

  Solution15 s15;

  nums = {-1, 0, 1, 2, -1, -4};
  s15.threeSum(nums);

  ///////////////////////////// Solution42  /////////////////////////////
  Solution42 s42;
  std::vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  s42.trap(heights);

  return 0;
}
