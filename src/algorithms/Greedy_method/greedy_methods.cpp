#include <algorithm>
#include <iostream>
#include <memory>
#include <iterator>
#include <map>
#include <queue>
#include <vector>

namespace Huffman
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

namespace JobSequence
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

	void JobSequenceWithDeadlines(std::vector < job >& jobsList, std::vector < job >& optimaljobsList)
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

namespace Dijkstra 
{
	struct edge 
	{
		std::string id;//id of the node at the end of the edge.
		double weight;
	};

	struct node 
	{	
		std::string id;
		std::vector<std::shared_ptr<node>> neighbours;
		std::vector<double> weights;
		std::vector<bool> visitedEgdes;
	};

	struct path
	{
		std::vector<std::shared_ptr<node>> waypoints;
		double pathCost = 0;

		void print() 
		{
			std::cout << "Path is: ";
			for (size_t i = 0; i < waypoints.size(); i++) 
			{
				std::cout << waypoints[i]->id << " ";
			}
			//std::cout <<  std::endl;
			std::cout << "and the cost is: " << pathCost << std::endl;
		}
	};

	//void printQueue(std::priority_queue<path> queue)
	//{
	//	while (!queue.empty()) 
	//	{
	//		std::vector<std::shared_ptr<node>> waypoints = queue.top().waypoints;
	//		for (size_t i = 0; i < waypoints.size(); i++)
	//		{
	//			std::cout << waypoints[i]->id << " ";
	//		}
	//		queue.pop();
	//	}
	//	std::cout << '\n';
	//}

	void dijkstraPathsFinder(std::shared_ptr<node> start, std::shared_ptr<node> goal)
	{
		// Using lambda to compare elements.
		auto cmp = [](path left, path right) { return left.pathCost > right.pathCost; };
		std::priority_queue<path, std::vector<path>, decltype(cmp)> queue(cmp);
		std::map<std::pair<std::string, std::string>, bool> visitedEdges;
		path currentPath;
		currentPath.waypoints.push_back(start);
		queue.push(currentPath);
		while (!queue.empty())
		{
			path shortestPath=queue.top();
			if ( shortestPath.waypoints.back()->id.compare(goal->id) ==0 )
			{
				std::cout<<"Shortest path is:" <<std::endl;
				shortestPath.print();
				break;
			}
			queue.pop();
			std::shared_ptr<node> lastNodeInPath=shortestPath.waypoints.back();
			for (size_t i = 0; i < lastNodeInPath->neighbours.size(); i++) 
			{

				std::shared_ptr<node> neighbourToDiscover = lastNodeInPath->neighbours[i];
				std::string  lastNodeInPathID= lastNodeInPath->id;
				std::string neighbourID=  neighbourToDiscover->id;

				if (!visitedEdges[std::make_pair(lastNodeInPathID, neighbourID)]) 
				{
					visitedEdges[ std::make_pair(lastNodeInPathID, neighbourID) ] = true;
					visitedEdges[std::make_pair(neighbourID, lastNodeInPathID )] = true;

					path newPath = shortestPath;
					newPath.waypoints.push_back(lastNodeInPath->neighbours[i]);
					newPath.pathCost += lastNodeInPath->weights[i];
					queue.push(newPath);
				}
			}
		}


	}
}

int main()
{
    {
        //std::vector < job > jobsList = { {"3",10,3}, {"1",20,2},{"4",5,3} ,{"2",15,2}, {"5",1,3} };
        std::vector < JobSequence::job > jobsList = { {"a",100,2}, {"b",19,1}, {"c",27,2},{"d",25,1}, {"e",15,3}};
        std::vector < JobSequence::job > optimaljobsList;
        std::cout <<"Input job list" << std::endl;
        JobSequence::printJobList(jobsList);
        JobSequenceWithDeadlines(jobsList, optimaljobsList);
        std::cout << "Optimal job list" << std::endl;
        JobSequence::printJobList(optimaljobsList);
        //c a e
    }

    {
		std::string huffmanString = "BCCABBDDAECCBBAEDDCC";
		std::map<  std::string, int > charFrequency;
		for (size_t i = 0; i < huffmanString.size(); i++)
		{
			charFrequency[std::string(1, huffmanString[i])]++;
		}

		std::vector<Huffman::node> nodes;
		for (std::map< std::string, int >::iterator it = charFrequency.begin(); it != charFrequency.end(); it++)
		{
			Huffman::node charNode;
			charNode.str = it->first;
			charNode.frequency = it->second;
			nodes.push_back(charNode);
		}



		while (nodes.size() > 2)
		{
			std::vector<Huffman::node>::iterator firstMinPtr = Huffman::nodeListMinElement(nodes);
			Huffman::node firstMin = *(firstMinPtr);
			nodes.erase(firstMinPtr);


			std::vector<Huffman::node>::iterator secondMinPtr = Huffman::nodeListMinElement(nodes);
			Huffman::node secondtMin = *(secondMinPtr);
			nodes.erase(secondMinPtr);

			Huffman::node pairedNode;
			pairedNode.frequency = secondtMin.frequency + firstMin.frequency;
			pairedNode.str = firstMin.str + secondtMin.str;

		}
    }
    

	{ 

		using namespace Dijkstra;
		/*
			 6        3
		   A ----- B ----- C
		   |       |       |
		   |       |       |
		  3|      1|      1|
		   |       |       |
		   D ----- E ----- F
		   |   1   |  7    |
		  9|       |       |7
		   |      4|       |
		   |       |       |
		   G ----- H ----- I
			  2       5
		
		*/

		std::shared_ptr<node> A(new node);
		A->id = "A";

		std::shared_ptr<node> B(new node);
		B->id = "B";

		std::shared_ptr<node> C(new node);
		C->id = "C";

		std::shared_ptr<node> D(new node);
		D->id = "D";

		std::shared_ptr<node> E(new node);
		E->id = "E";

		std::shared_ptr<node> F(new node);
		F->id = "F";

		std::shared_ptr<node> G(new node);
		G->id = "G";

		std::shared_ptr<node> H(new node);
		H->id = "H";

		std::shared_ptr<node> I(new node);
		I->id = "I";

		//  A --6--> B
		A->neighbours.push_back(B);
		A->weights.push_back(6);

		//  B --6--> A
		B->neighbours.push_back(A);
		B->weights.push_back(6);


		//  A --3--> D
		A->neighbours.push_back(D);
		A->weights.push_back(3);

		//  D --3--> A
		D->neighbours.push_back(A);
		D->weights.push_back(3);

		// B --3--> C
		B->neighbours.push_back(C);
		B->weights.push_back(3);
		
		// C --3--> B
		C->neighbours.push_back(B);
		C->weights.push_back(3);



		// C --1--> F
		C->neighbours.push_back(F);
		C->weights.push_back(3);

		// F --1--> C
		F->neighbours.push_back(C);
		F->weights.push_back(1);


		// B --1--> E
		B->neighbours.push_back(E);
		B->weights.push_back(1);

		// E --1--> B
		E->neighbours.push_back(B);
		E->weights.push_back(1);


		// D --1--> E
		D->neighbours.push_back(E);
		D->weights.push_back(1);

		// E --1--> D
		E->neighbours.push_back(D);
		E->weights.push_back(1);

		// D --9--> G
		D->neighbours.push_back(G);
		D->weights.push_back(9);

		// G --9--> D
		G->neighbours.push_back(D);
		G->weights.push_back(9);

		// E --4--> H
		E->neighbours.push_back(H);
		E->weights.push_back(4);


		// H --4--> E
		H->neighbours.push_back(E);
		H->weights.push_back(4);


		// G --2--> H
		G->neighbours.push_back(H);
		G->weights.push_back(2);

		// H --2--> G
		H->neighbours.push_back(G);
		H->weights.push_back(2);


		// E --7--> F
		E->neighbours.push_back(F);
		E->weights.push_back(7);

		// F --7--> E
		F->neighbours.push_back(E);
		F->weights.push_back(7);


		// F --7--> I
		F->neighbours.push_back(I);
		F->weights.push_back(7);


		// I --7--> F
		I->neighbours.push_back(F);
		I->weights.push_back(7);

		// I --5--> H
		I->neighbours.push_back(H);
		I->weights.push_back(5);

		// H --5--> I
		H->neighbours.push_back(I);
		H->weights.push_back(5);

		dijkstraPathsFinder(A, I);


	}

	



    return 0;
}
