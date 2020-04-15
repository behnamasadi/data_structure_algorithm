#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void printArray(T  array, std::size_t arraySize)
{
    for(std::size_t i=0;i<arraySize;i++)
        std::cout<< array[i]<<std::endl;
}


template
<typename T>
void countSortAlgorithm(std::vector<T>& A )
{
    size_t A_size=A.size();
    T max_value=(*std::max_element( A.begin(), A.end()));


    std::vector<T> C(max_value+1,0);
    std::vector<T> B(A_size,0);
    for(size_t i=0;i<A_size;i++)
    {
       C[A[i]]++;
    }

    for(size_t i=1;i<=max_value;i++)
    {
       C[i]=C[i]+C[i-1];
    }

    for(int i=A_size-1;i>=0;i--)
    {
       C[A[i]]--;
       B[C[A[i]]]=A[i];
    }
    A=B;

}

void KthSmallestElement()
{
    int num_repeat;
    int array_size;
    std::cin>>num_repeat;
    //int *data;
    std::vector<int> data;
    int index=0;
    while(num_repeat>0)
    {
        std::cin>>array_size;
        //data=new int[array_size];
        data.resize(array_size);
        index=0;
        while(array_size-index>0)
        {
            std::cin>>data[index];
            index++;

        }
        num_repeat--;
        //printArray(data,array_size);
        std::cin>>index;
        countSortAlgorithm(data);
        //printArray(data,array_size);
        std::cout<< data[index-1]<<std::endl;
    }

}

template
<typename T>
void insertionSortAlgorithm(T arr[], size_t size)
{
    for(size_t i=1;i<size;i++)
    {
        T key=arr[i];
        size_t j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
            printArray( arr,   size);
        }
        arr[j+1]=key;
    }
}


void NearlySortedAlgorithm()
{
    int num_repeat;
    int array_size;
    std::cin>>num_repeat;
    //int *data;
    std::vector<int> data;
    int index=0;
    while(num_repeat>0)
    {
        std::cin>>array_size;
        //data=new int[array_size];
        data.resize(array_size);
        index=0;
        while(array_size-index>0)
        {
            std::cin>>data[index];
            index++;

        }
        num_repeat--;
        //printArray(data,array_size);
        std::cin>>index;
        countSortAlgorithm(data);
        //printArray(data,array_size);
        std::cout<< data[index-1]<<std::endl;
    }
}

int main()
{

    return 0;
}
