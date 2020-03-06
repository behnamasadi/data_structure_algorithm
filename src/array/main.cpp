#include <iostream>

template
<typename T>
class Array 
{
public:
    //T* data;
    T data[50];
    std::size_t  size, lenght;
    
    Array() {}

    int binarySearch( T key, std::size_t low, std::size_t high)
    {
        while (low < high)
        {
            std::size_t mid = (low + high) / 2;
            if (key == data[mid])
            {
                return mid;
            }
            else if (key < data[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
    bool isSorted()
    {
        for (std::size_t i = 0; i < lenght; i++) 
        {
            if (data[i] > data[i + 1])
                return false;
        }
        return true;
    }



};
int main()
{
    //Array<int> arr = { {2,34,7,8,45},20,5 };
    //int* p = {2,34,7,8,45 };
}
