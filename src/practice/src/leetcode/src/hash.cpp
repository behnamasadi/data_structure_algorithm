#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
13. Roman to Integer
*/
class Solution13 {
public:
  int romanToInt(string s) {
    /*
    int sum = 0;
    std::map<std::string, int> romanNumerals = {
        {"I", 1},   {"V", 5},    {"X", 10},  {"L", 50}, {"C", 100},
        {"D", 500}, {"M", 1000}, {"IV", 4},  {"IX", 9}, {"XL", 40},
        {"XC", 90}, {"CD", 400}, {"CM", 900}};

    int i = 0;
    int length = s.size();

    while (i < length) {
      if (i < length - 1 && romanNumerals.count(s.substr(i, 2))) {
        sum += romanNumerals[s.substr(i, 2)];
        i += 2;
      } else {
        sum += romanNumerals[s.substr(i, 1)];
        i++;
      }
  }

  return sum;
  */

    /**/
    unordered_map<char, int> romanValues = {{'I', 1},   {'V', 5},   {'X', 10},
                                            {'L', 50},  {'C', 100}, {'D', 500},
                                            {'M', 1000}};

    int result = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
      // If the current value is less than the next value, subtract it
      if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
        result -= romanValues[s[i]];
      } else {
        result += romanValues[s[i]];
      }
    }

    return result;
  }
};

/*

https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
202. Happy Number
*/

class Solution202 {
public:
  int sum_of_squares(int n) {
    int sum = 0;

    while (n) {
      sum = sum + pow((n % 10), 2);
      n = n / 10;
    }

    return sum;
  }
  bool isHappy(int n) {

    // std::map<int, int> table;
    // while (table.count(n) == 0) {
    //   if (n == 1)
    //     return true;
    //   auto sq = sum_of_squares(n);
    //   table.insert(std::pair(n, sq));
    //   n = sq;
    // }
    // return false;
    auto slow = n;
    auto fast = sum_of_squares(n);
    while (slow != fast) {
      slow = sum_of_squares(slow);
      fast = sum_of_squares(sum_of_squares(fast));
    }
    return (slow == 1) ? true : false;
  }
};

int main() {

  string str = "MCMXCIV";
  //   std::cout << str.substr(0, 4) << std::endl;
  Solution13 s;
  std::cout << s.romanToInt(str) << std::endl;

  //   std::map<string, int> numbers = {{"A", 1}, {"B", 5}};
  //   std::cout << numbers["C"] << std::endl;

  //   std::cout << numbers["C"] << std::endl;

  // std::cout << sum_of_squares(12) << std::endl;
  Solution202 s202;
  std::cout << std::boolalpha << s202.isHappy(19) << std::endl;
  return 0;
}
