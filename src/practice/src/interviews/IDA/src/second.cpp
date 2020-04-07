#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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

        
        if(std::distance(first,it-history_size ) <0 )
            std::cout<<*it;
        else 
        {
            std::string tmp(it-history_size,it);   
            //std::cout<<tmp<<std::endl;
            
            if(tmp.find(*it) != std::string::npos)
            {
                
            }else
            {
                std::cout<<*it;
            }
                
        }
        
    }
    return result;
}

int main()
{
    
    std::string source="Mamma";
    
//     if(source.find("a") != std::string::npos)
//         std::cout<< "found"  <<std::endl;
//     else
//         std::cout<< "!found"  <<std::endl;
    std::size_t history_size=3;
    
    
    
    
    filter(std::begin(source), std::end(source), std::begin(source),AlphaNumericPredicate{}, history_size);
    
    
    
}
