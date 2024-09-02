#include <algorithm>
#include <iostream>
#include <limits>
#include <math.h>
#include <stdio.h>
#include <vector>

// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
namespace KnapsackProblem {
struct item {
  double weight;
  double value;
  std::string name;
};

double knapSackNaiveRecursive(int bagCapacity, std::vector<item> &items,
                              int n) {

  // Base Case
  if (n == 0 || bagCapacity == 0)
    return 0;

  // If weight of the nth item is more
  // than Knapsack capacity W, then
  // this item cannot be included
  // in the optimal solution
  if (items[n - 1].weight > bagCapacity)
    return knapSackNaiveRecursive(bagCapacity, items, n - 1);

  // Return the maximum of two cases:
  // (1) nth item included
  // (2) not included
  else
    return std::max(items[n - 1].value +
                        knapSackNaiveRecursive(
                            bagCapacity - items[n - 1].weight, items, n - 1),
                    knapSackNaiveRecursive(bagCapacity, items, n - 1));
}

void zeroOneKnapsackProblem() {
  std::vector<item> items = {{1, 10, "A"}, {1, 20, "B"}, {1, 30, "C"}};
  double bagCapacity = 8;
  knapSackNaiveRecursive(bagCapacity, items, items.size());
}
} // namespace KnapsackProblem

int c[] = {1, 3, 4}; // value of coins
int k = 3;           // number of coins that we have

/*

solve(x) = min(solve(x−1)+1, solve(x−3)+1, solve(x−4)+1)

The d[20] array is for memorization, for instance if we computed
minimumNumberOfCoins(3), we put this value in d[3] and we don't compute it
again, we just use d[3] instead of minimumNumberOfCoins(3)
*/

std::vector<int> d(20, 0);

int minimumNumberOfCoins(int x) {
  /*
  since we have +1 in {minimumNumberOfCoins(x-c[i]) +1} if we return
  std::numeric_limits<int>::max() then std::numeric_limits<int>::max()+1 will
  overflow and it will give us a minus number
  */

  if (x < 0)
    return std::numeric_limits<int>::max() - 1;
  if (x == 0)
    return 0;
  if (d[x])
    return d[x];
  int u = std::numeric_limits<int>::max() - 1;

  /*
      Tip: the min of several items in a list can be written as follows;

      c[]={c1,c2,...ck}
      min_value=min(c1,c2,...ck)

      u=INF
      for (ci in c)
              u=min(ci,u)
      min_value=u
  */

  for (int i = 0; i < k; i++) {
    u = std::min(u, minimumNumberOfCoins(x - c[i]) + 1);
  }
  d[x] = u;
  return d[x];
}

void MultiStageGraph() {}

/*
3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8
*/

int grid[5][5] = {{3, 7, 9, 2, 7},
                  {9, 8, 3, 5, 5},
                  {1, 7, 9, 8, 5},
                  {3, 8, 6, 4, 10},
                  {6, 3, 9, 7, 8}};
int memo[5][5]{{-1, -1, -1, -1, -1},
               {-1, -1, -1, -1, -1},
               {-1, -1, -1, -1, -1},
               {-1, -1, -1, -1, -1},
               {-1, -1, -1, -1, -1}};

std::vector<int> x_solution, y_solution;

int optimalPathOnCostMap(int y, int x) {
  if ((x == 0) && (y == 0)) {
    memo[y][x] = grid[0][0];
  } else if (x == 0) {
    if (memo[y][x] < 0) {
      memo[y][x] = optimalPathOnCostMap(y - 1, x) + grid[y][x];
    }
  } else if (y == 0) {
    if (memo[y][x] < 0) {
      memo[y][x] = optimalPathOnCostMap(y, x - 1) + grid[y][x];
    }
  } else if (memo[y][x] < 0) {
    memo[y][x] = std::max(optimalPathOnCostMap(y, x - 1),
                          optimalPathOnCostMap(y - 1, x)) +
                 grid[y][x];
  }
  return memo[y][x];
}

// Levenshtein distance in c

int LevenshteinDistance(const char *s, int len_s, const char *t, int len_t) {
  int cost;

  /* base case: empty strings */
  if (len_s == 0)
    return len_t;
  if (len_t == 0)
    return len_s;

  /* test if last characters of the strings match */
  if (s[len_s - 1] == t[len_t - 1])
    cost = 0;
  else
    cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char
   * from both */
  return std::min(std::min(LevenshteinDistance(s, len_s - 1, t, len_t) + 1,
                           LevenshteinDistance(s, len_s, t, len_t - 1) + 1),
                  LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost);
}

// Levenshtein distance in c++

size_t LevenshteinDistance(std::string s, std::string t) {
  size_t cost;

  /* base case: empty strings */
  if (s.length() == 0)
    return t.length();
  if (t.length() == 0)
    return s.length();

  /* test if last characters of the strings match */
  if (s.at(s.length() - 1) == t.at(t.length() - 1))
    cost = 0;
  else
    cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char
   * from both */

  return std::min(
      std::min(LevenshteinDistance(s.substr(0, s.size() - 1), t) + 1,
               LevenshteinDistance(s, t.substr(0, t.size() - 1)) + 1),
      LevenshteinDistance(s.substr(0, s.size() - 1),
                          t.substr(0, t.size() - 1)) +
          cost);
}

size_t fibonacciRecursiveTabular(size_t n) {
  std::vector<size_t> f;
  f.resize(n + 1, 0);
  f[0] = 0;
  f[1] = 1;
  for (size_t i = 2; i < n + 1; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

std::vector<size_t> fibonacci(20, 0);
size_t fibonacciRecursiveMemoization(size_t n) {
  if (n <= 1) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    return fibonacci[n];
  }
  if (fibonacci[n]) {
    return fibonacci[n];
  }

  fibonacci[n] = fibonacciRecursiveMemoization(n - 1) +
                 fibonacciRecursiveMemoization(n - 2);
  return fibonacci[n];
}

size_t factorielRecursiveTabular(size_t n) {
  std::vector<size_t> f;
  f.resize(n + 1, 0);
  f[0] = 1;
  for (size_t i = 1; i < n + 1; i++) {
    f[i] = f[i - 1] * i;
  }
  return f[n];
}

std::vector<size_t> factoriel(20, 0);
size_t factorielRecursiveMemoization(size_t n) {
  if (n == 0)
    return 1;
  if (factoriel[n])
    return factoriel[n];
  factoriel[n] = factorielRecursiveMemoization(n - 1) * n;
  return factoriel[n];
}

// seam carving

namespace SingleSourceShortestPath {
void BellmanFord() {}
} // namespace SingleSourceShortestPath

namespace AllPairsShortestPath {
void FloydWarshall() {}
} // namespace AllPairsShortestPath

int main() {
  size_t n = 10;
  std::cout << "******************************** Factoriel "
               "********************************"
            << std::endl;
  std::cout << n << "!=" << factorielRecursiveTabular(n) << std::endl;

  std::cout << n << "!=" << factorielRecursiveMemoization(n) << std::endl;

  std::cout << "******************************** Fibonacci "
               "********************************"
            << std::endl;
  std::cout << "fibonacci(" << n << ")=" << fibonacciRecursiveTabular(10)
            << std::endl;
  std::cout << "fibonacci(" << n << ")=" << fibonacciRecursiveMemoization(10)
            << std::endl;

  std::cout << "******************************** Coin Example "
               "********************************"
            << std::endl;
  std::cout << "The minimum number of coins from the set {1,3,4} to sum up "
               "value of 12 is:"
            << std::endl;
  std::cout << minimumNumberOfCoins(12) << std::endl;

  std::cout << "******************************** Levenshtein Distance "
               "********************************"
            << std::endl;

  //  calling c-style string function
  //    char* s="saturday";
  //    char* t="sunday";
  //    std::cout<<LevenshteinDistance(s,8,t,6)<<std::endl;

  std::string s = "saturday";
  std::string t = "sunday";
  std::cout << "The Levenshtein distance between " << s << " and " << t
            << " is:" << std::endl;
  std::cout << LevenshteinDistance(s, t) << std::endl;

  std::cout << "******************************** Optimal Path On Cost Map "
               "********************************"
            << std::endl;
  std::cout << "maximum sum on a path from the upper-left corner to the "
               "lower-right corner is:"
            << std::endl;
  std::cout << optimalPathOnCostMap(4, 4) << std::endl;

  std::cout << "******************************** Costs On Cost Map "
               "********************************"
            << std::endl;
  for (std::size_t y = 0; y < 5; y++) {
    for (std::size_t x = 0; x < 5; x++) {
      std::cout << memo[y][x] << "|";
    }
    std::cout << "\n";
    std::cout << "---------------" << std::endl;
  }

  { KnapsackProblem::zeroOneKnapsackProblem(); }

  return 0;
}
