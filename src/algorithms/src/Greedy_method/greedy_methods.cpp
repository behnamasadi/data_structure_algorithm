#include <algorithm>
#include <iostream>
#include <memory>
#include <iterator>
#include <map>
#include <queue>
#include <vector>

namespace huffman
{
    class node
    {
    public:
        std::shared_ptr<node> left,right;
        std::string str;
        size_t frequency=0;
    };

    bool nodeComparison(node &lhs, node &rhs)
    {
        return lhs.frequency < rhs.frequency;
    }


	template <typename T>
	typename T::iterator nodeListMinElement(T& m)
	{
		return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.frequency < r.frequency; });
	}

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


namespace jobSequence
{
	struct job
	{
		std::string id;
		size_t profit;
		size_t deadline;
	};

	bool jobcomparison(job& lhs, job& rhs)
	{
		return lhs.profit > rhs.profit;
	}

	void printJobList(std::vector < job >& jobsList)
	{
		for (std::size_t i = 0; i < jobsList.size(); i++)
		{
			std::cout << "job id :" << jobsList[i].id << " job profit : " << jobsList[i].profit << " job deadline: " << jobsList[i].deadline << std::endl;

		}
	}

	void jobSequenceWithDeadlines(std::vector < job >& jobsList, std::vector < job >& optimaljobsList)
	{

		std::sort(jobsList.begin(), jobsList.end(), jobcomparison);
		//    printJobList(jobsList);
		std::vector<bool> occupied(jobsList.size(), false);

		for (size_t i = 0; i < jobsList.size(); i++)
		{
			for (int j = std::min(jobsList.size() - 1, jobsList[i].deadline); j >= 0; j--)
			{
				if (!occupied[j])
				{
					occupied[j] = true;
					optimaljobsList.push_back(jobsList[i]);
					break;
				}
			}
		}
	}
}


namespace KnapsackProblem
{
	//https://www.geeksforgeeks.org/fractional-knapsack-problem/
	void fractionalKnapsackProblem() 
	{

	}

}

int main()
{
    {
        //std::vector < job > jobsList = { {"3",10,3}, {"1",20,2},{"4",5,3} ,{"2",15,2}, {"5",1,3} };
        std::vector < jobSequence::job > jobsList = { {"a",100,2}, {"b",19,1}, {"c",27,2},{"d",25,1}, {"e",15,3}};
        std::vector < jobSequence::job > optimaljobsList;
        std::cout <<"Input job list" << std::endl;
        jobSequence::printJobList(jobsList);
        jobSequenceWithDeadlines(jobsList, optimaljobsList);
        std::cout << "Optimal job list" << std::endl;
        jobSequence::printJobList(optimaljobsList);
        //c a e
    }

    {
		std::string huffmanString = "BCCABBDDAECCBBAEDDCC";
		std::map<  std::string, int > charFrequency;
		for (size_t i = 0; i < huffmanString.size(); i++)
		{
			charFrequency[std::string(1, huffmanString[i])]++;
		}

		std::vector<huffman::node> nodes;
		for (std::map< std::string, int >::iterator it = charFrequency.begin(); it != charFrequency.end(); it++)
		{
			huffman::node charNode;
			charNode.str = it->first;
			charNode.frequency = it->second;
			nodes.push_back(charNode);
		}



		while (nodes.size() > 2)
		{
			std::vector<huffman::node>::iterator firstMinPtr = huffman::nodeListMinElement(nodes);
			huffman::node firstMin = *(firstMinPtr);
			nodes.erase(firstMinPtr);


			std::vector<huffman::node>::iterator secondMinPtr = huffman::nodeListMinElement(nodes);
			huffman::node secondtMin = *(secondMinPtr);
			nodes.erase(secondMinPtr);

			huffman::node pairedNode;
			pairedNode.frequency = secondtMin.frequency + firstMin.frequency;
			pairedNode.str = firstMin.str + secondtMin.str;

		}
    }
    

    return 0;
}
