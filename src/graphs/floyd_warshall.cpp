#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

template
<typename T>
class Matrix
{
public:
    size_t n;
    std::vector<std::vector<T>>data;
    Matrix(size_t n)
    {
        this->n=n;
        T inf = std::numeric_limits<T>::infinity();
        data=std::vector(n, std::vector(n,inf));
    }

    void print()
    {

            for(size_t i=0;i<n;i++)
            {
                for(size_t j=0;j<n;j++)
                {
                    std::cout<<data[i][j]<<" ";
                }
                std::cout<<"\n";
            }
    }


    //Single Source Shortest Path to All
    void FloydWarshall( )
    {
        for(size_t k=0;k<n;k++)
        {
            std::cout << "A["<<k<<"]" << '\n';
            for(size_t i=0;i<n;i++)
            {
                for(size_t j=0;j<n;j++)
                {
                    data[i][j]=std::min(data[i][j], data[i][k] +data[k][j]);
                }

            }

            print();
            std::cout << "================================" << '\n';
        }
    }

};

//TODO Shortest Path (Floyd-Warshall)
//https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm#Path_reconstruction

int main()
{

/*

Let say we have the following graph:
         ◄----8------
         1-------3--►2
        | ▲⬉         |
        | |  \       |2
        | 2    5     |
        7 |      \   |
        ▼ ▼       \  ▼
         4◄---1----- 3

The adjacency matrix for this graph is the following,

   1  2  3  4
  ┌            ┐
1 |0  3  ∞  7  |
2 |8  0  2  ∞  |
3 |5  ∞  0  1  |
4 |2  ∞  ∞  0  |
  └            ┘
*/




    double inf = std::numeric_limits<double>::infinity();

    Matrix<double> adjacencyMatrix(4);



    adjacencyMatrix.data[0][0]=0;
    adjacencyMatrix.data[0][1]=3;
    adjacencyMatrix.data[0][3]=7;

    adjacencyMatrix.data[1][0]=8;
    adjacencyMatrix.data[1][1]=0;
    adjacencyMatrix.data[1][2]=2;

    adjacencyMatrix.data[2][0]=5;
    adjacencyMatrix.data[2][2]=0;
    adjacencyMatrix.data[2][3]=1;

    adjacencyMatrix.data[3][0]=2;
    adjacencyMatrix.data[3][3]=0;


    std::cout << "Adjacency Matrix: " << '\n';
    adjacencyMatrix.print();

    adjacencyMatrix.FloydWarshall();

    std::cout << "Solution is:" << '\n';

    adjacencyMatrix.print();


    return 0;
}




