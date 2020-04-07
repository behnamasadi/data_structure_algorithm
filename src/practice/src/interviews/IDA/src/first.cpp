#include <iostream>
#include <algorithm>
#include <vector>
#include <string>



//
// Character Filter
//
// (C) By Autonomous Intelligent Driving GmbH
//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

class AlphaNumericPredicate {
    // Fill implementation here
};

template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator filter(InputIterator first, InputIterator last,
                      OutputIterator result,
                      UnaryPredicate predicate,
                      size_t history_size)
{
    // Fill implementation here
    
    for(std::string::iterator it=first;it!=last;it++)
    {
        //if(  it-history_size  )
        
         //std::distance(it,std::begin(source)-2 )
        
        
        if(std::distance(it,it-history_size ) <0 )
            std::cout<<*it;
        else if(*it  !=  *(it-history_size) )
        {
                std::cout<<*it;
        }
        
    }
    return result;
}

//
// Filter string. Helper for mapping binary blobs to strings.
//
std::string filter_string(std::string source, size_t history_size)
{
source.erase( filter(std::begin(source), std::end(source), std::begin(source),AlphaNumericPredicate{}, history_size), 
                 
              std::end(source));
    return source;
}

//
// Main entry point.
//
int main()
{
//     while (!std::cin.eof())
//     {
//         size_t history_size = 0;
//         std::cin >> history_size;
//         std::string source;
//         std::getline(std::cin, source);
//         std::cout << filter_string(source, history_size) << std::endl;
//     }
//     return 0;
    
    std::string source="abcdefg";
    
    
    //source.erase(std::end(source) , std::end(source));
//     source.erase(std::begin(source)-1 , std::end(source));
//     std::cout<<source  <<std::endl;
    
   // std::cout<<source.at( std::distance(std::begin(source),std::begin(source)-2 )    )  <<std::endl;
    
    
     //std::cout<<std::distance(std::begin(source),std::begin(source)-2 )      <<std::endl;
    
     
     //std::cout<< *(std::begin(source)-2)       <<std::endl;
    
     
    //std::cout<<source.substr( source.begin(), 2 )<<std::endl; 
    
    
}
