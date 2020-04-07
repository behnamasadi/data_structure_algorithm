#include <iostream>
#include <string>

using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };




template <typename T> struct Traits;
// Define specializations for the Traits class template here.
template <> struct Traits <Fruit> 
{
    //static std::vector<std::string>  enumValue={"apple", "orange", "pear"};
    static std::string name(int index)
    {
        std::string strVal;
        switch(index)
        {
            case 0:
                strVal="apple";
                break;
            case 1:
                strVal="orange";
                break;
            case 2:
                strVal="pear";
                break;
            default:
                strVal="unknown";
                break;
        }
        return strVal;
             
    }

};


template <> struct Traits <Color> 
{
    //static std::vector<std::string> enumValue={"red", "green", "orange"};
          
    static std::string name(int index)
    {
        std::string strVal;
        switch(index)
        {
            case 0:
                strVal="red";
                break;
            case 1:
                strVal="green";
                break;
            case 2:
                strVal="orange";
                break;
            default:
                strVal="unknown";
                break;
        }
        return strVal;
             
    }
};




int main()
{
    
    int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
