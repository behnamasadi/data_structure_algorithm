#include <vector>
#include <algorithm>
#include <iostream>
#include <random>


template
<typename T>
void printArray(T arr[], size_t size, size_t start=0)
{
    for (std::size_t i= start; i < size; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}


template <typename T>
void countSort(std::vector<T> &array)
{
    size_t tempArraySize=*(std::max_element(array.begin(),array.end()))+1;

    std::vector<T> tempArray(tempArraySize,-1);
    for(size_t i=0;i<array.size();i++)
    {
        tempArray[array[i]]=1;
    }
    size_t j=0;
    for(size_t i=0;i<tempArraySize;i++)
    {
        if(tempArray[i]>0)
        {
            array[j]=i;
            j++;
        }

    }



}

int main()
{
    /*
    std::vector<int> first={2,5,7,9,11};
    std::vector<int> second={6,8,15,18};
    std::vector<int> final(first.size()+second.size());
    mergeSortedArrays(&first[0], first.size(), &second[0],second.size() , &final[0]);
    printArray(&final[0],final.size());
    */


    std::vector<int> array={2,5,7,9,11 ,6,8,15,18};
    /*
    size_t low=0;
    size_t mid=4;
    size_t high=8;
    mergeSortedArrays(&array[0], low, mid, high);
    printArray(&array[0],array.size());



    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(array.begin(),array.end(),g);
    printArray(&array[0],array.size());
    mergeSort(&array[0], 0, array.size()-1);
    printArray(&array[0],array.size());
    */

    printArray(&array[0],array.size());
    countSort(array);
    printArray(&array[0],array.size());

    return 0;
}
