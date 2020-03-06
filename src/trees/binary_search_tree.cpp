#include <algorithm>
#include <memory>
#include <iostream>


#include <vector>
#include <string>
#include <sstream>
#include <random>





template <typename T>
class Node
{
public:
    std::shared_ptr<Node> left,right;
    T value;
	size_t height;
	Node(T value) :value(value), height(0) {}
	Node() :height(0) {}
};


template <typename T>
class BinarySearchTree
{
public:
    std::shared_ptr<Node<T>> root;
    BinarySearchTree(){}

    std::shared_ptr<Node<T>> search(std::shared_ptr<Node<T>> node,T key)
    {
        if(node==nullptr)
            return node;
        if (key==node->value)
        {
            return node;
        }
        else if (key>node->value)
        {
            return search(node->right, key);
        }
        else
        {
            return search(node->left, key);
        }

    }

    void iterativeInsert(T key )
    {
        if(root==nullptr)
        {
            root.reset(new Node<T>(key));
            root->value=key;
            return;
        }
        std::shared_ptr<Node<T> > node=root;//this var is for starting search
        std::shared_ptr<Node<T> > r;// this var keeps the correct location for node to be inserted

        while(node!=nullptr)
        {
            r=node;
            if(key<node->value)
            {
               node=node->left;
            }
            else if(key>node->value)
            {
                node=node->right;
            }
            else
            {
                return;
            }
        }

        node.reset(new Node<T>(key));
        node->value=key;

        if(key<r->value)
        {
           r->left=node;
        }
        else if(key>r->value)
        {
            r->right=node;
        }

		updateHeight(root);
    }
    
	size_t getHeight(std::shared_ptr<Node<T>> node)
	{
		size_t height = 0;
		if (node != nullptr && node.use_count() > 0)
			return node->height;
		return height;
	}

	size_t updateHeight(std::shared_ptr<Node<T>> node)
	{
		if (node != nullptr)
		{
			node->height = 1 + std::max(updateHeight(node->left), updateHeight(node->right));
			return node->height;
		}
		else
			return 0;
	}

	size_t getBalance(std::shared_ptr<Node<T>> N)
	{
		if (N == nullptr)
			return 0;

		//size_t left_height, right_height;
		//left_height = getHeight(N->left);
		//right_height = getHeight(N->right);
		std::cout << "node:" << N->value << " left height: " << getHeight(N->left) << " right height: " << getHeight(N->right) << std::endl;
		//return (left_height - right_height) ;
		return (getHeight(N->left) - getHeight(N->right));
	}

	/*
	Node* newNode(int key)
	{
		Node* node = new Node();
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->height = 1; // new node is initially 
						  // added at leaf  
		return(node);
	}

	Node* recursiveInsert(Node* node, int key)
	{
		// 1. Perform the normal BST insertion
		if (node == NULL)
			return(newNode(key));

		if (key < node->key)
			node->left = recursiveInsert(node->left, key);
		else if (key > node->key)
			node->right = recursiveInsert(node->right, key);
		else // Equal keys are not allowed in BST  
			return node;

		//2. Update height of this ancestor node
		node->height = 1 + std::max(height(node->left),
			height(node->right));
	}
	*/
	void printGivenLevel(std::shared_ptr<Node<T> > root, int level)
	{
		if (root == nullptr)
			return;
		if (level == 1)
		{
			std::cout << "value: " << root->value << " height: " << root->height << " balance:" << getBalance(root) << std::endl;
		}

		else if (level > 1)
		{
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}

	void printLevelOrder(std::shared_ptr<Node<T> > root)
	{
		int h = getHeight(root);
		int i;
		for (i = 1; i <= h; i++)
			printGivenLevel(root, i);
	}

	void insert(T key)
	{
		iterativeInsert( key);
	}

};

int main()
{
/*
                  30
              /       \
             20        40
            /  \      /  \ 
          10   25    35   50
            \
            15
*/

    BinarySearchTree<int> bst;
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(50);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
	bst.insert(15);
    std::cout<< bst.root->left->value  <<std::endl;

	bst.printLevelOrder(bst.root);

	std::cout << bst.root->height<< std::endl;
	std::cout << bst.root->left->height << std::endl;
	std::cout << bst.root->left->left->height << std::endl;
	std::cout << bst.root->left->right->height << std::endl;
	std::cout << bst.root->right->height << std::endl;

	std::cout << bst.getBalance(bst.root->right) << std::endl;

    
}
