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
void countSortAlgorithm(T* array, size_t size)
{
    T *max_value=std::max_element( array, array+size);


    std::vector<T> count_vec(*max_value+1,0);
    for(size_t i=0;i<size;i++)
    {
       count_vec[array[i]]++;
    }
    size_t i=0,j=0;
    while(j<(*max_value)+1)
    {
        if(count_vec[j]>0)
        {
            array[i++]=j;
            count_vec[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int num_repeat;
    int array_size;
    std::cin>>num_repeat;
    int *data;
    int index=0;
    while(num_repeat>0)
    {
        std::cin>>array_size;
        data=new int[array_size];
        index=0;
        while(array_size-index>0)
        {
            std::cin>>data[index];
            index++;

        }
        num_repeat--;
        //printArray(data,array_size);
        std::cin>>index;
        countSortAlgorithm(data,array_size);
        //printArray(data,array_size);
        std::cout<< data[index-1]<<std::endl;
    }

    return 0;
}
