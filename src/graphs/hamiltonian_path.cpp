#include <vector>
#include <iostream>

/*
TODO: Hamiltonian Cycle
https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/
https://www.youtube.com/watch?v=dQr4wZCiJJ4

*/

template
<typename T>
class AdjacencyMatrix
{
public:
    std::vector<std::vector<T>> data;
    int n;
    std::vector<T> path;

    AdjacencyMatrix( int n)
    {
        this->n=n;
        data=std::vector(n,std::vector(n,T(0)));
        path=std::vector(n,T(-1));
        path[0]=0;
    }

    void addEdge(int from,int to, T weight=1)
    {
        data[from][to]=weight;
        data[to][from]=weight;
    }

    void printMatrix()
    {
        for(size_t m=0;m<data.size();m++)
        {
            for(size_t n=0;n<data[0].size();n++)
            {
                std::cout<<data[m][n]<<" ";
            }
            std::cout<<"\n";
        }
    }

    void printHamiltonPath()
    {
        for(size_t m=0;m<path.size();m++)
        {
            std::cout<<path[m]<<" ";
            std::cout<<"\n";
        }
    }

    void hamiltonPath(int k)
    {
        do
        {
            nextVertex(k);
            if(path[k]==0)
                return ;
            if(k==n)
                printHamiltonPath();
            else
                hamiltonPath(k+1);
        }while(true);
    }
    bool vertexIsAlreadyInPath(int k)
    {
        for(int j=0;j<k-1;j++)
        {
            if(path[j]==path[k])
                return true;
        }
        return false;
    }

    void nextVertex(int k)
    {
        do
        {
            path[k]=path[k]+1 %(n+1);
            if(path[k]==0)
                return;
            if(data[path[k-1] ][path[k]]!=0 )//if there is an edge
            {

                for(int j=0;j<k-1;j++)
                {
                    if(path[j]==path[k])
                        break;
                }
                //if(j==k)
                {
                    if( (k==n)&& data[path[n-1] ][path[0]]!=0 )
                        return;
                }




            }


        }while(true);

    }
};



int main()
{

/*

Graph
             --------------
            /              \
           0-----------1     \
           |          /|       \
           |        /  |         2
           |      /    |       /
           |    /      |     /
           |  /        |   /
           |/          | /
           4-----------3


Adjacency Matrix:

       0  1  2  3  4
      ┌              ┐
    0 |0  1  1  0  1 |
    1 |1  0  1  1  1 |
    2 |1  1  0  1  0 |
    3 |0  1  1  0  1 |
    4 |1  1  0  1  0 |
      └              ┘
*/

    AdjacencyMatrix<int> adjacencyMatrix(5);
    adjacencyMatrix.data[0]={0 , 1 , 1 , 0 , 1};
    adjacencyMatrix.data[1]={1 , 0 , 1 , 1 , 1};
    adjacencyMatrix.data[2]={1 , 1 , 0 , 1 , 0};
    adjacencyMatrix.data[3]={0 , 1 , 1 , 0 , 1};
    adjacencyMatrix.data[4]={1 , 1 , 0 , 1 , 0};
    adjacencyMatrix.printMatrix();
    //data=std::vector(n,std::vector(n,T(0)));
    int startingVertex=1;
    adjacencyMatrix.hamiltonPath(startingVertex);

}
