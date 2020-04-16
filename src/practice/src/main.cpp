#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <map>

template
<typename T>
void printArray(T arr[], size_t size, size_t start=0)
{
    for (std::size_t i= start; i < size; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

template
<typename T>
void insertionSort(T arr[], size_t size)
{

}

int main1()
{
//    std::multimap<int,int> array;
//    std::pair<int,int> valueindex;
//    std::vector <int> vec={34, 8, 10, 3, 2, 80, 30, 33, 1};
//    for(int i=0;i<vec.size();i++)
//    {
//        valueindex.first=i;
//        valueindex.second=vec[i];
//        array.insert(valueindex);
//    }

//    for(std::multimap<int,int>::iterator it=array.begin();it!=array.end();it++)
//    {
//        std::cout<<it->first <<", " <<it->second    <<std::endl;
//    }

//    std::sort(vec.begin(),vec.end());


    /*
    std::vector<int> array={6,2,5,7,18,9,11,8,15};
    printArray(&array[0], array.size());

    printArray(&array[0], array.size());

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(array.begin(),array.end(),g);
    */
    return 0;
}

int main()
{
}


int main3()
{
    std::map<char,char> collections;
    collections['!']='!';
    collections['$']='$';
    collections['#']='#';

    if(collections['!']==NULL)
        std::cout<< "xxx" <<std::endl;

    //std::map::at()

}
