#include <algorithm>
#include <iostream>
#include <queue>
#include <memory>
#include <stack>
/*
If there are n nodes, then there are n+1 null pointers
so total nuber of calls are n+n+1=2n+1
Because nodes ate the end of tree have 2 nulls and those in the middle only one

The size of occupied in the stack would be height of tree +2


*/

template <typename T>
struct Node
{
    /*left and right will be automaticaly set to nullptr by std::shared_ptr
    so we dont need to set them to nullptr
    */
    std::shared_ptr<Node> left, right;
    T key;

};

template <typename T>
class Tree
{
public:
    std::shared_ptr<Node<T>> root;
    std::queue< std::shared_ptr<Node<T>> > levelOrderQeue;
    int max_height;
    int current_height;
    Tree()
    {
        max_height=-1;
        current_height=0;
    }

    void createTree()
    {
        std::cout<<"Creating a binary tree based on level order traverse, enter -1 if a node doesnt have left(right) child"<<std::endl;
        std::cout<<"enter value for root:"<<std::endl;

        int x;
        std::queue<std::shared_ptr< Node<T> > > queue;
        root.reset(new Node<T>);

        std::cin>>x;
        root->key=x;
        queue.push(root);
        std::shared_ptr< Node<T> > node;
        while(!queue.empty())
        {
            node=queue.front();
            queue.pop();
            std::cout<<"enter left child of:"<<node->key <<std::endl;
            std::cin>>x;
            if(x!=-1)
            {
                std::shared_ptr<Node<T>> leftNode(new Node<T>);
                leftNode->key=x;
                node->left=leftNode;
                queue.push(leftNode);
            }

            std::cout<<"enter right child of:"<<node->key <<std::endl;
            std::cin>>x;
            if(x!=-1)
            {
                std::shared_ptr<Node<T>> rightNode(new Node<T>);
                rightNode->key=x;
                node->right=rightNode;
                queue.push(rightNode);
            }
        }
    }

    void preOrderRecursively(std::shared_ptr<Node<T>> node)
    {
        if(node!=nullptr)
        {
            std::cout<<node->key  <<" ";
            preOrderRecursively(node->left);
            preOrderRecursively(node->right);
        }
    }

    void postOrderRecursively(std::shared_ptr<Node<T>> node)
    {
        if(node!=nullptr)
        {
            postOrderRecursively(node->left);
            postOrderRecursively(node->right);
            std::cout<<node->key  <<" ";
        }
    }

    void postOrderIteratively(std::shared_ptr<Node<T>> node)
    {
        std::stack<std::shared_ptr<Node<T>>> stack;

        if(node!=nullptr)
        {
            stack.push(node);
            std::cout<<node->key <<std::endl;
            if(node->left!=nullptr)
            {
                stack.push(node->left);
            }

            if(node->right!=nullptr)
            {

            }


        }


    }

    void preOrderIteratively(std::shared_ptr<Node<T>> node)
    {

    }

    void inOrderIteratively(std::shared_ptr<Node<T>> node)
    {

    }

    void inOrderRecursively(std::shared_ptr<Node<T>> node)
    {
        if(node!=nullptr)
        {
            inOrderRecursively(node->left);
            std::cout<<node->key  <<" ";
            inOrderRecursively(node->right);
        }
    }

    void levelOrderRecursively(std::shared_ptr<Node<T>> node)
    {
        if(node!=nullptr)
        {
            if(node->left!=nullptr)
                levelOrderQeue.push(node->left);
            if(node->right!=nullptr)
                levelOrderQeue.push(node->right);


            if(!levelOrderQeue.empty())
            {
                node=levelOrderQeue.front();
                std::cout<<node->key  <<" ";
                levelOrderQeue.pop();
                levelOrderRecursively(node);
            }

        }
    }

    void levelOrder(std::shared_ptr<Node<T>> node)
    {
        std::queue<std::shared_ptr<Node<T> > > queue;
        std::cout<<node->key  <<" ";
        queue.push(node);

        while(!queue.empty())
        {
            node=queue.front();
            queue.pop();
            if(node->left!=nullptr)
            {
                std::cout<<node->left->key  <<" ";
                queue.push(node->left);
            }
            if(node->right!=nullptr)
            {
                std::cout<<node->right->key  <<" ";
                queue.push(node->right);
            }
        }
    }

    void heightRecursively(std::shared_ptr<Node<T>> node)
    {
        if(node!=nullptr)
        {
            current_height++;
            max_height=std::max(current_height,max_height);

            heightRecursively(node->left);
            heightRecursively(node->right);

        }
        current_height--;
    }

    int height(std::shared_ptr<Node<T>> node)
    {
        int x=0,y=0;
        if(node==nullptr)
            return 0;

        x=height(node->left);
        y=height(node->right);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
};

int main()
{
    std::shared_ptr<Tree<int>> tree(new Tree<int>);
    tree->createTree();

    std::cout<<"Traversing Level Order" <<std::endl;
    tree->levelOrder(tree->root);

    std::cout<<"Traversing Level Order(Recursively)" <<std::endl;
    tree->levelOrderRecursively(tree->root);
    std::cout<<"\n";

    std::cout<<"Traversing Pre-Order(Recursively)" <<std::endl;
    tree->preOrderRecursively(tree->root);
    std::cout<<"\n";

    std::cout<<"Traversing In-Order(Recursively)" <<std::endl;
    tree->inOrderRecursively(tree->root);
    std::cout<<"\n";

    std::cout<<"Traversing Post-Order(Recursively)" <<std::endl;
    tree->postOrderRecursively(tree->root);
    std::cout<<"\n";


    std::cout<<"The height of the tree is:" <<std::endl;
    std::cout<<tree->height(tree->root)<<std::endl;

    std::cout<<"The height of the tree (Recursively) is:" <<std::endl;
    tree->heightRecursively(tree->root);
    std::cout<<tree->max_height <<std::endl;


}
