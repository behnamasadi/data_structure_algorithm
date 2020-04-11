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
void mergeSortedArrays(T* first, std::size_t firstSize, T* second, std::size_t secondSize, T* final)
{
    size_t i,j,k;
    i=0;
    j=0;
    k=0;
    while( (i<firstSize )&& (j<secondSize))
    {
        if(first[i]<second[j] )
        {
            final[k]=first[i];
            i++;
        }
        else
        {
            final[k]=second[j];
            j++;
        }
        k++;
    }
    while(i<firstSize)
    {
        final[k]=first[j];
        i++;
        k++;
    }
    while(j<secondSize)
    {
        final[k]=second[j];
        j++;
        k++;
    }
}


template <typename T>
void mergeSortedArrays(T* array, size_t low, size_t mid, size_t high)
{
    size_t i,j,k;
    i=low;
    j=mid+1;
    k=0;
    std::vector<T> final;
    final.resize(high-low+1);
    while( (i<=mid )&& (j<=high))
    {
        if(array[i]<array[j] )
        {
            final[k]=array[i];
            i++;
        }
        else
        {
            final[k]=array[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        final[k]=array[j];
        i++;
        k++;
    }
    while(j<=high)
    {
        final[k]=array[j];
        j++;
        k++;
    }


    i=low;
    while(i<=high)
    {
        array[i]=final[i-low];
        i++;
    }


}


template
<typename T>
void merging(T* array,  size_t low, size_t mid, size_t high)
{
    size_t i, j, k;
    i = low;
    j = mid+1;
    k = 0;
    std::vector<T> B;
    size_t arraySize = high - low + 1;
    B.resize(arraySize);
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            B[k] = array[i];
            i++;
        }
        else
        {
            B[k] = array[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = array[j];
        j++;
        k++;
    }
    for (i=low;i<=high;i++)
    {
        array[i] = B[i- low];
    }
}


template <typename T>
void mergeSort(T* array, size_t low, size_t high)
{
    size_t mid=(low+high)/2;
    if(low<high)
    {
        mergeSort(array, low,mid );
        mergeSort(array, mid+1, high);
        //std::cout<<"low: "  << low<<" mid: "<<mid<<" high: "<<high  <<std::endl;
        //mergeSortedArrays(array, low, mid, high  );
        merging(array, low, mid, high  );
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

    /**/
    std::vector<int> array={2,5,7,9,11 ,6,8,15,18};
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

    return 0;
}
