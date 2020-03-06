#include <string>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <vector>
namespace chaining
{

class hash
{
    int bucket;
    std::vector<std::list<int> > table;
public:
    hash(int bucket)
    {
        this->bucket=bucket;
        table.resize(bucket);
    }
    
    int hashfunction(int entry)
    {
        return (entry%bucket);
    }
    
    void insert(int entry)
    {
        int index=hashfunction(entry);
        table[index].push_back(entry);
    }
    
    void remove(int entry)
    {
        int index=hashfunction(entry);
        table[index].remove(entry);

    }
    
    void printTable()
    {
        for(std::size_t i=0;i<table.size();i++)
        {
            std::cout<<"[" <<i<< "]:";
            
            for(std::list<int>::iterator it=table[i].begin();it!=table[i].end() ;it++)
            {
                std::cout<<"->"  <<*it; 
            }
            std::cout<<"\n";
        }
    }
    
};

}

namespace openAddressing 
{
    //https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
    class linearProbing{};
}

void chainingHashExample()
{
    // array that contains keys to be mapped 
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 

    // insert the keys into the hash table 
    chaining::hash h(7);   // 7 is count of buckets in 
    // hash table 
    for (int i = 0; i < n; i++)  
        h.insert(a[i]);   

    // display the Hash table 
    h.printTable(); 
    
    // delete 12 from hash table 
    std::cout<<"removing 12" <<std::endl;
    h.remove(12); 

    // display the Hash table 
    h.printTable();     
}


int main()
{


    return 0;
    
}
