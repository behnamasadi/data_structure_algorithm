#include "matrix.hpp"
#include <limits>

//TODO Minimum Spanning Tree
void primeMinimumSpanningTree()
{

}

int main() 
{
	size_t numberOfVertices=7;
	Matrix<int> graph_cost;

	std::numeric_limits<int>::has_infinity == true;

	graph_cost.resize(numberOfVertices, Array<int>(numberOfVertices, std::numeric_limits<int>::max()));
	//graph_cost.resize(numberOfVertices, Array<int>(numberOfVertices, std::numeric_limits<int>::infinity()));

	

	Array<int> nearest;
	nearest.resize (numberOfVertices, std::numeric_limits<int>::infinity());
	Matrix<int> t;
	t.resize(2, Array<int>(numberOfVertices-1,0)   );
	

	//Matrix<int> graph_cost2 = { { 0, 2, 0, 6, 0 },
	//					{ 2, 0, 3, 8, 5 },
	//					{ 0, 3, 0, 0, 7 },
	//					{ 6, 8, 0, 0, 9 },
	//					{ 0, 5, 7, 9, 0 } };


	//1 -> 2 25
	graph_cost[0][1] =25;
	//1 -> 6 5
	graph_cost[0][5] =5;

	//2 -> 1 25
	graph_cost[1][0] =25 ;
	//2 -> 7 10
	graph_cost[1][6] =10 ;
	//2 -> 3 12
	graph_cost[1][2] =12 ;

	//3 -> 2 12
	graph_cost[2][1] =12 ;
	//3 -> 4 8
	graph_cost[2][3] =8 ;

	//4 -> 3 8
	graph_cost[3][2] =8 ;
	//4 -> 5 16
	graph_cost[3][4] = 16;
	//4 -> 7 14
	graph_cost[3][6] = 14;

	//5 -> 4 16
	graph_cost[4][3] =16 ;
	//5 -> 7 18
	graph_cost[4][6] =18 ;
	//5 -> 6 20
	graph_cost[4][5] =20 ;

	//6 -> 1 5
	graph_cost[5][0] =5;
	//6 -> 5 20 
	graph_cost[5][4] =20;


	//7 -> 2 10
	graph_cost[6][1] =10 ;
	//7 -> 4 14
	graph_cost[6][3] =14 ;
	//7 -> 5 18
	graph_cost[6][4] =18 ;


	//printMatrix(graph_cost, " , ");




	//double max = std::numeric_limits<double>::max();
	//double inf = std::numeric_limits<double>::infinity();

	//if (inf > max)
	//	std::cout << inf << " is greater than " << max << '\n';


}
