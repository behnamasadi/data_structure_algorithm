#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class node
{
public:
    std::vector<std::shared_ptr<node> > leaves;
    double data;
};

void populateTree(std::shared_ptr<node> rootNodePtr)
{
/*
                   -1
                  /   \
                3       7
              /  \    /
             4    1  5
*/

    rootNodePtr->data=-1;
    std::shared_ptr<node>  leftNodePtr,rightNodePtr;
    std::shared_ptr<node>  leftNode1stKidPtr,leftNode2ndtKidPtr, rightNode1stKidPtr;

    leftNodePtr.reset(new node) ;
    rightNodePtr.reset(new node);
    rootNodePtr->leaves.push_back(leftNodePtr);
    rootNodePtr->leaves.push_back(rightNodePtr);

    leftNodePtr->data=3;
    rightNodePtr->data=7;

    leftNode1stKidPtr.reset(new node);
    leftNode2ndtKidPtr.reset(new node);
    rightNode1stKidPtr.reset(new node);

    leftNode1stKidPtr->data=4;
    leftNode2ndtKidPtr->data=1;
    rightNode1stKidPtr->data=5;

    leftNodePtr->leaves.push_back(leftNode1stKidPtr);
    leftNodePtr->leaves.push_back(leftNode2ndtKidPtr);

    rightNodePtr->leaves.push_back(rightNode1stKidPtr);

}

void DFS(std::shared_ptr<node> rootNode)
{
    std::cout<<rootNode->data <<std::endl;
    for(auto n:rootNode->leaves)
        DFS(n);
}

void BFS(std::shared_ptr<node> rootNode)
{

    for(auto n:rootNode->leaves)
        std::cout<<n->data <<std::endl;

    for(auto n:rootNode->leaves)
        BFS(n);
}
int main()
{
    std::shared_ptr<node> tree(new node);
    populateTree(tree);
    DFS(tree);
    BFS(tree); 
}
