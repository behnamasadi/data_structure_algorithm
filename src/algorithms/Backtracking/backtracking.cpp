#include <algorithm>
#include <iostream>
#include <memory>
#include <iterator>
#include <map>
#include <queue>
#include <cassert>

//https://www.geeksforgeeks.org/0-1-knapsack-using-branch-and-bound/
//https://www.geeksforgeeks.org/branch-and-bound-algorithm/
//https://www.geeksforgeeks.org/implementation-of-0-1-knapsack-using-branch-and-bound/
namespace KnapsackProblem
{
	void zeroOneKnapsackProblem()
	{

	}
}


template
<typename T>
void printArray(T arr[], std::size_t size)
{
   for (std::size_t i= 0; i < size; i++)
       std::cout<<arr[i]<<" ";
   std::cout<<std::endl;
}

template <typename T>
void permutation(std::vector<T> v)
{
    std::sort(v.begin(), v.end());
    do {
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
}

bool increase(std::vector<bool>& bs)
{
    for (std::size_t i = 0; i != bs.size(); ++i) {
        bs[i] = !bs[i];
        if (bs[i] == true) {
            return true;
        }
    }
    return false; // overflow
}

template <typename T>
void powerSet(const std::vector<T>& v)
{
    std::vector<bool> bitset(v.size());

    do {
        for (std::size_t i = 0; i != v.size(); ++i) {
            if (bitset[i]) {
                std::cout << v[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (increase(bitset));
}


template <typename T>
void combination(const std::vector<T>& v, std::size_t count)
{
    assert(count <= v.size());
    std::vector<bool> bitset(v.size() - count, 0);
    bitset.resize(v.size(), 1);

    do {
        for (std::size_t i = 0; i != v.size(); ++i) {
            if (bitset[i]) {
                std::cout << v[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (std::next_permutation(bitset.begin(), bitset.end()));
}

std::string digit_in_binary_form(unsigned x)
{
    std::string s;
    do
    {
        s.push_back('0' + (x & 1));
    } while (x >>= 1);
    std::reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::vector<char> vc{ 'A', 'B', 'C', 'D' };
    std::cout << "The set is:"<<std::endl;
    printArray(&vc[0],vc.size());
    std::cout << "------Permutation----------"<<std::endl;
    permutation(vc);
    std::cout << "------Combinations----------"<<std::endl;
    combination(vc, 3);
    std::cout << "------Power set----------"<<std::endl;
    powerSet(vc);
    std::cout << "------Binary----------"<<std::endl;
    std::cout << digit_in_binary_form(25)<<std::endl;
    return 0;
}
