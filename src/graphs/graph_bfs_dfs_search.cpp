#include <iostream>
#include <queue>
#include <stack>
#include "matrix.hpp"


template <typename T>
void BFS(T startingVertex, Matrix<T> &graphMatrix)
{
	Array<T> litsOfVisitedVertices;

	size_t n = graphMatrix.size();
	litsOfVisitedVertices.resize(graphMatrix.size(), 0);
	litsOfVisitedVertices[startingVertex ] = 1;

	std::cout<< "Vertex: "<< startingVertex +1<<std::endl;
	T u;
	std::queue<T> queue;
	queue.push(startingVertex);
	while(!queue.empty())
	{
		u = queue.front();
		queue.pop();
		for (T v=0;v<n;v++) 
		{
			if (graphMatrix[u][v] == 1 && litsOfVisitedVertices[v] == 0) 
			{
				std::cout<< "Vertex: " << v+1 <<std::endl;
				litsOfVisitedVertices[v] = 1;
				queue.push(v);
			}
		}
	}

}


template <typename T>
void DFSRecursion(T startingVertex, Matrix<T>& graphMatrix, Array<T> &litsOfVisitedVertices)
{
	if (litsOfVisitedVertices[startingVertex] == 0) 
	{
		std::cout<< "Vertex: " << startingVertex + 1 <<std::endl;
		litsOfVisitedVertices[startingVertex] = 1;
		for (int v = 0; v < litsOfVisitedVertices.size(); v++) 
		{
			if (graphMatrix[startingVertex][v] == 1)
				DFSRecursion(v, graphMatrix, litsOfVisitedVertices);
		}
	}
	
}

template <typename T>
void DFS(T startingVertex, Matrix<T>& graphMatrix)
{
	Array<T> litsOfVisitedVertices;
	size_t n = graphMatrix.size();
	litsOfVisitedVertices.resize(graphMatrix.size(), 0);
	DFSRecursion(startingVertex, graphMatrix, litsOfVisitedVertices);
}

int main() 
{
	
	Matrix<int> graph_matrix;
	graph_matrix.resize(7,std::vector<int>(7,0));

/*
		 1-----2
		 | \   |
		 |  \  |
		 |   \ |
		 4-----3
		  \   /
		   \ /
			5
		   / \
		  /   \
		 6     7
*/
	//1->2
	graph_matrix[0][1] = 1;
	//1->3
	graph_matrix[0][2] = 1;
	//1->4
	graph_matrix[0][3] =1;


	//2->1
	graph_matrix[1][0] = 1;
	//2->3
	graph_matrix[1][2] = 1;


	//3->2
	graph_matrix[2][1] = 1;
	//3->1
	graph_matrix[2][0] = 1;
	//3->4
	graph_matrix[2][3] = 1;


	//4->3
	graph_matrix[3][2] = 1;
	//4-5
	graph_matrix[3][4] = 1;

	
	//5-3
	graph_matrix[4][2] = 1;
	//5-4
	graph_matrix[4][3] = 1;
	//5-6
	graph_matrix[4][5] = 1;
	//5-7
	graph_matrix[4][6] = 1;
	//6-5
	graph_matrix[5][4] = 1;
	//7-5
	graph_matrix[6][4] = 1;

	//printVector(graph_matrix[1]);

	int startingVertex = 5;
	std::cout << "Starting Vertex is: "<< startingVertex << std::endl;
	int startingVertexIndex=startingVertex - 1;

	std::cout << "BFS Traversal "  << std::endl;
	BFS(startingVertexIndex, graph_matrix);

	std::cout << "Starting Vertex is: " << startingVertex << std::endl;

	std::cout << "DFS Traversal " << std::endl;
	DFS(startingVertexIndex, graph_matrix);

}
