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

	 // Number of vertices in the graph 
 #define V 9 
 // A utility function to print the constructed distance array 
 void  printSolution(int dist[], int n) 
 { 
     printf("Vertex   Distance from Source\n"); 
     for (int i = 0; i < V; i++) 
         printf("%d \t\t %d\n", i, dist[i]); 
 }
 
 
   
 // A utility function to find the vertex with minimum distance value, from 
 // the set of vertices not yet included in shortest path tree 
 int minDistance(int dist[], bool sptSet[]) 
 { 
     // Initialize min value 
     int min = INT_MAX, min_index; 
   
     for (int v = 0; v < V; v++) 
         if (sptSet[v] == false && dist[v] <= min) 
             min = dist[v], min_index = v; 
   
     return min_index; 
 } 
 
   
 // Function that implements Dijkstra's single source shortest path algorithm 
 // for a graph represented using adjacency matrix representation 
 void dijkstra(int graph[V][V], int src) 
 { 
     int dist[V]; // The output array.  dist[i] will hold the shortest 
     // distance from src to i 
   
     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < V; i++) 
         dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V - 1; count++) { 
         // Pick the minimum distance vertex from the set of vertices not 
         // yet processed. u is always equal to src in the first iteration. 
         int u = minDistance(dist, sptSet); 
   
         // Mark the picked vertex as processed 
         sptSet[u] = true; 
   
         // Update dist value of the adjacent vertices of the picked vertex. 
         for (int v = 0; v < V; v++) 
   
             // Update dist[v] only if is not in sptSet, there is an edge from 
             // u to v, and total weight of path from src to  v through u is 
             // smaller than current value of dist[v] 
             if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                 && dist[u] + graph[u][v] < dist[v]) 
                 dist[v] = dist[u] + graph[u][v]; 
     } 
   
     // print the constructed distance array 
     printSolution(dist, V); 
 } 
   
 void  dijkstraExample()
 {
    /* Let us create the example graph discussed above */
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                         { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                         { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                         { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                         { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                         { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                         { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
   
     dijkstra(graph, 0);     
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
