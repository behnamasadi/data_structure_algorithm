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
int main() {

  string str = "MCMXCIV";
  //   std::cout << str.substr(0, 4) << std::endl;
  Solution13 s;
  std::cout << s.romanToInt(str) << std::endl;

  //   std::map<string, int> numbers = {{"A", 1}, {"B", 5}};
  //   std::cout << numbers["C"] << std::endl;

  return 0;
}
