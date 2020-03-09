#include <algorithm>
#include <iostream>
#include <memory>
#include <iterator>
#include <map>
#include <queue>

namespace huffman
{
    class node
    {
    public:
        std::shared_ptr<node> left,right;
        std::map<std::string, int> data;

    };

}



template <typename T>
typename T::iterator min_map_element(T& m)
{
    return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; });
}


void huffmanCoding()
{
    std::map<std::string, int> inputList;

    /*
    auto cmp=[](std::pair<std::string,int> &left,std::pair<std::string,int> &right){ return (left.second>right.second) ;};
    auto inputList=std::map<std::string, int, decltype(cmp)  >(cmp);
    */
    inputList.insert(std::make_pair("E",2));
    inputList.insert(std::make_pair("A",3));
    inputList.insert(std::make_pair("D",4));
    inputList.insert(std::make_pair("B",5));
    inputList.insert(std::make_pair("C",6));

    std::map<std::string, int>::iterator first_min=min_map_element(inputList);


    inputList.erase(first_min);


    std::map<std::string, int>::iterator second_min=min_map_element(inputList);
    inputList.erase(second_min);

    std::cout<<first_min->first <<std::endl;
    std::cout<<second_min->first <<std::endl;

    huffman::node nodeEA;

//     nodeEA.left.reset(new huffman::node());
//     nodeEA.right.reset(new huffman::node());
//     nodeEA.data.insert(std::make_pair(first_min->first+second_min->first,first_min->second+second_min->second));


    inputList.insert(std::make_pair(first_min->first+second_min->first,first_min->second+second_min->second));

        std::cout<<inputList[first_min->first+second_min->first] <<std::endl;
}

void jobSequenceWithDeadlines()
{

}
int main()
{
    huffmanCoding();
    return 0;
}
