#include "matrix.hpp"
#include <limits>
#include <queue>
#include <algorithm>

template
<typename T>
struct Edge
{
    Edge( size_t from,size_t to, T weight )
    {
        this->to=to;
        this->from=from;
        this->weight=weight;
    }
    size_t to, from;
    T weight;
};

template
<typename T>
class AdjacencyMatrix
{

    public:
    std::vector<std::vector<T>> data;
    AdjacencyMatrix(size_t m, size_t n)
    {
        data=std::vector(m,std::vector(n,T(0)));
    }
    void addEdge(size_t from,size_t to, T weight=1)
    {
        data[from][to]=weight;
        data[to][from]=weight;
    }

    std::vector<Edge<T>> getVertexEdges(size_t vertexIndex)
    {
        std::vector<Edge<T>> edges;
        for(size_t j=0;j<data[vertexIndex].size();j++)
        {
            //std::cout<< i<< ","<< j<<" ";
            if(data[vertexIndex][j]!=0)
            {
                Edge<T> edge(vertexIndex,j,data[vertexIndex][j]);
                edges.push_back(edge);
            }
        }
            //std::cout<< std::endl;

        return edges;
    }


    std::vector<Edge<T>> getEdges()
    {
        std::vector<Edge<T>> edges;

        for(size_t i=0;i<data.size();i++)
        {
            for(size_t j=i;j<data[i].size();j++)
            {
                //std::cout<< i<< ","<< j<<" ";
                if(data[i][j]!=0)
                {
                    Edge<T> edge(i,j,data[i][j]);
                    edges.push_back(edge);
                }
            }
            //std::cout<< std::endl;
        }
        return edges;
    }



    void print()
    {
        for(size_t m=0;m<data.size();m++)
        {
            for(size_t n=0;n<data[0].size();n++)
            {
                std::cout<<data[m][n]<<"  ";
            }
            std::cout<<"\n";
        }
    }
};


//https://www.youtube.com/watch?v=jsmMtJpPnhU
//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
void lazyPrimeMinimumSpanningTree()
{


    std::cout<<"Our Graph is:" <<std::endl;
    std::cout<<R"(
               10
         1 --------- 4
       / |           | \
   10 /  |           |  \8
     /   |3         1|   \
    /    |           |    \
   0--1--2-----8-----5--9---7
    \    |         / |    /
     \   |       /   |   /
     4\  |2   2/    6|  /12
       \ |   /       | /
         3 /---------6
                7


               )" <<std::endl;


    size_t numberOfNodes=8;
    AdjacencyMatrix<double> graph(numberOfNodes,numberOfNodes);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,1);
    graph.addEdge(0,3,4);
    //graph.addEdge(1,4,10);
    graph.addEdge(1,4,0.01);
    graph.addEdge(1,2,3);
    graph.addEdge(2,5,8);
    graph.addEdge(2,3,2);
    graph.addEdge(3,6,7);
    graph.addEdge(3,5,2);
    graph.addEdge(4,5,1);
    graph.addEdge(4,7,8);
    graph.addEdge(5,6,6);
    graph.addEdge(5,7,9);
    graph.addEdge(6,7,12);
    graph.print();

    std::vector<bool> visited(numberOfNodes,false);


    auto cmp = [](Edge<double> left, Edge<double> right) { return (left.weight) > (right.weight);};
    std::priority_queue<Edge<double>, std::vector<Edge<double>>, decltype(cmp)> edges_queue(cmp);






    /*
    for(auto edge:graph.getEdges())
    {
        std::cout<<"From: " <<edge.from <<" To: "<<edge.to<<" Weight: " <<edge.weight <<std::endl;
    }
    */


    std::vector<Edge<double>> vertex_edges=graph.getVertexEdges(0);

     std::vector<Edge<double>>::iterator min_edge=std::min_element(vertex_edges.begin(),vertex_edges.end(),cmp);

     int next_visiting_vertex=min_edge->to;
     vertex_edges.erase(min_edge);

    for(auto edge:graph.getVertexEdges(0) )
    {
        edges_queue.push(edge);
    }

    while(!edges_queue.empty())
    {
        //std::cout<< edges_queue.top().weight  <<std::endl;
        //std::cout<< visited[edges_queue.top().to] <<std::endl;
        if(!visited[next_visiting_vertex])
        {
            visited[next_visiting_vertex]=true;
            std::vector<Edge<double>> vertex_edges=graph.getVertexEdges(next_visiting_vertex);
            std::vector<Edge<double>>::iterator min_edge=std::min_element(vertex_edges.begin(),vertex_edges.end(),cmp);


        }
        else
        {
            edges_queue.pop();
        }
    }





}

//https://www.youtube.com/watch?v=xq3ABa-px_g
//https://www.youtube.com/watch?v=eB61LXLZVqs
void eagerPrimeMinimumSpanningTree()
{

}
int main()
{
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
    lazyPrimeMinimumSpanningTree();


}
