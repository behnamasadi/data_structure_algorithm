#include <algorithm>
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>


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
private:

	struct cell_display {
		std::string   valstr;
		bool     present;
		cell_display() : present(false) {}
		cell_display(std::string valstr) : valstr(valstr), present(true) {}
	};

	using display_rows = std::vector< std::vector< cell_display > >;

	display_rows get_row_display()
	{
		// start off by traversing the tree to
		// build a vector of vectors of Node pointers
		std::vector<std::shared_ptr<Node<T>> > traversal_stack;
		std::vector< std::vector< std::shared_ptr<Node<T>> > > rows;
		if (!root) return display_rows();

		std::shared_ptr< Node<T>> p = root;
		//const int max_depth = root->max_depth();
		size_t max_depth = getHeight(root);
		rows.resize(max_depth);
		int depth = 0;
		for (;;) {
			// Max-depth Nodes are always a leaf or null
			// This special case blocks deeper traversal
			if (depth == max_depth - 1) {
				rows[depth].push_back(p);
				if (depth == 0) break;
				--depth;
				continue;
			}

			// First visit to node?  Go to left child.
			if (traversal_stack.size() == depth) {
				rows[depth].push_back(p);
				traversal_stack.push_back(p);
				if (p) p = p->left;
				++depth;
				continue;
			}

			// Odd child count? Go to right child.
			if (rows[depth + 1].size() % 2) {
				p = traversal_stack.back();
				if (p) p = p->right;
				++depth;
				continue;
			}

			// Time to leave if we get here

			// Exit loop if this is the root
			if (depth == 0) break;

			traversal_stack.pop_back();
			p = traversal_stack.back();
			--depth;
		}

		// Use rows of Node pointers to populate rows of cell_display structs.
		// All possible slots in the tree get a cell_display struct,
		// so if there is no actual Node at a struct's location,
		// its boolean "present" field is set to false.
		// The struct also contains a string representation of
		// its Node's value, created using a std::stringstream object.
		display_rows rows_disp;
		std::stringstream ss;
		for (const auto& row : rows) {
			rows_disp.emplace_back();
			for (std::shared_ptr<Node<T>> pn : row) {
				if (pn) {
					ss << pn->value;
					rows_disp.back().push_back(cell_display(ss.str()));
					ss = std::stringstream();
				}
				else {
					rows_disp.back().push_back(cell_display());
				}
			}
		}
		return rows_disp;
	}

	static void trim_rows_left(std::vector<std::string>& rows) {
		if (!rows.size()) return;
		auto min_space = rows.front().length();
		for (const auto& row : rows) {
			auto i = row.find_first_not_of(' ');
			if (i == std::string::npos) i = row.length();
			if (i == 0) return;
			if (i < min_space) min_space = i;
		}
		for (auto& row : rows) {
			row.erase(0, min_space);
		}
	}

	std::vector<std::string> row_formatter(const display_rows& rows_disp) const {
		using s_t = std::string::size_type;

		// First find the maximum value string length and put it in cell_width
		s_t cell_width = 0;
		for (const auto& row_disp : rows_disp) {
			for (const auto& cd : row_disp) {
				if (cd.present && cd.valstr.length() > cell_width) {
					cell_width = cd.valstr.length();
				}
			}
		}

		// make sure the cell_width is an odd number
		if (cell_width % 2 == 0) ++cell_width;

		// formatted_rows will hold the results
		std::vector<std::string> formatted_rows;

		// some of these counting variables are related,
		// so its should be possible to eliminate some of them.
		s_t row_count = rows_disp.size();

		// this row's element count, a power of two
		s_t row_elem_count = 1 << (row_count - 1);

		// left_pad holds the number of space charactes at the beginning of the bottom row
		s_t left_pad = 0;

		// Work from the level of maximum depth, up to the root
		// ("formatted_rows" will need to be reversed when done)
		for (s_t r = 0; r < row_count; ++r) {
			const auto& cd_row = rows_disp[row_count - r - 1]; // r reverse-indexes the row
			// "space" will be the number of rows of slashes needed to get
			// from this row to the next.  It is also used to determine other
			// text offsets.
			s_t space = (s_t(1) << r) * (cell_width + 1) / 2 - 1;
			// "row" holds the line of text currently being assembled
			std::string row;
			// iterate over each element in this row
			for (s_t c = 0; c < row_elem_count; ++c) {
				// add padding, more when this is not the leftmost element
				row += std::string(c ? left_pad * 2 + 1 : left_pad, ' ');
				if (cd_row[c].present) {
					// This position corresponds to an existing Node
					const std::string& valstr = cd_row[c].valstr;
					// Try to pad the left and right sides of the value string
					// with the same number of spaces.  If padding requires an
					// odd number of spaces, right-sided children get the longer
					// padding on the right side, while left-sided children
					// get it on the left side.
					s_t long_padding = cell_width - valstr.length();
					s_t short_padding = long_padding / 2;
					long_padding -= short_padding;
					row += std::string(c % 2 ? short_padding : long_padding, ' ');
					row += valstr;
					row += std::string(c % 2 ? long_padding : short_padding, ' ');
				}
				else {
					// This position is empty, Nodeless...
					row += std::string(cell_width, ' ');
				}
			}
			// A row of spaced-apart value strings is ready, add it to the result vector
			formatted_rows.push_back(row);

			// The root has been added, so this loop is finsished
			if (row_elem_count == 1) break;

			// Add rows of forward- and back- slash characters, spaced apart
			// to "connect" two rows' Node value strings.
			// The "space" variable counts the number of rows needed here.
			s_t left_space = space + 1;
			s_t right_space = space - 1;
			for (s_t sr = 0; sr < space; ++sr) {
				std::string row;
				for (s_t c = 0; c < row_elem_count; ++c) {
					if (c % 2 == 0) {
						row += std::string(c ? left_space * 2 + 1 : left_space, ' ');
						row += cd_row[c].present ? '/' : ' ';
						row += std::string(right_space + 1, ' ');
					}
					else {
						row += std::string(right_space, ' ');
						row += cd_row[c].present ? '\\' : ' ';
					}
				}
				formatted_rows.push_back(row);
				++left_space;
				--right_space;
			}
			left_pad += space + 1;
			row_elem_count /= 2;
		}

		// Reverse the result, placing the root node at the beginning (top)
		std::reverse(formatted_rows.begin(), formatted_rows.end());

		return formatted_rows;
	}

public:
    std::shared_ptr<Node<T>> root;
	std::queue< std::shared_ptr<Node<T>> > levelOrderQeue;
    
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

	size_t getBalanceFactor(std::shared_ptr<Node<T>> N)
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
			std::cout << "value: " << root->value << " height: " << root->height << " balance:" << getBalanceFactor(root) << std::endl;
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

	void printTree()
	{
		size_t d = getHeight(root) ;

		// If this tree is empty, tell someone
		if (d == 0) {
			std::cout << " <empty tree>\n";
			return;
		}

		// This tree is not empty, so get a list of node values...
		const auto rows_disp = get_row_display();
		// then format these into a text representation...
		auto formatted_rows = row_formatter(rows_disp);
		// then trim excess space characters from the left sides of the text...
		trim_rows_left(formatted_rows);
		// then dump the text to cout.
		for (const auto& row : formatted_rows) {
			std::cout << ' ' << row << '\n';
		}
	}

	void createTree()
	{
		std::cout << "Creating a binary tree based on level order traverse, enter -1 if a node doesn't have left(right) child" << std::endl;
		std::cout << "enter value for root:" << std::endl;

		int x;
		std::queue<std::shared_ptr< Node<T> > > queue;
		root.reset(new Node<T>);

		std::cin >> x;
		root->value = x;
		queue.push(root);
		std::shared_ptr< Node<T> > node;
		while (!queue.empty())
		{
			node = queue.front();
			queue.pop();
			std::cout << "enter left child of:" << node->value << std::endl;
			std::cin >> x;
			if (x != -1)
			{
				std::shared_ptr<Node<T>> leftNode(new Node<T>);
				leftNode->value = x;
				node->left = leftNode;
				queue.push(leftNode);
			}

			std::cout << "enter right child of:" << node->value << std::endl;
			std::cin >> x;
			if (x != -1)
			{
				std::shared_ptr<Node<T>> rightNode(new Node<T>);
				rightNode->value = x;
				node->right = rightNode;
				queue.push(rightNode);
			}
		}
	}

	void preOrderRecursively(std::shared_ptr<Node<T>> node)
	{
		if (node != nullptr)
		{
			std::cout << node->value << " ";
			preOrderRecursively(node->left);
			preOrderRecursively(node->right);
		}
	}

	void postOrderRecursively(std::shared_ptr<Node<T>> node)
	{
		if (node != nullptr)
		{
			postOrderRecursively(node->left);
			postOrderRecursively(node->right);
			std::cout << node->value << " ";
		}
	}

	void postOrderIteratively(std::shared_ptr<Node<T>> node)
	{
		std::stack<std::shared_ptr<Node<T>>> stack;

		if (node != nullptr)
		{
			stack.push(node);
			std::cout << node->value << std::endl;
			if (node->left != nullptr)
			{
				stack.push(node->left);
			}

			if (node->right != nullptr)
			{

			}


		}


	}

	void preOrderIteratively(std::shared_ptr<Node<T>> node)
	{
        std::stack<std::shared_ptr<Node<T>> > stack;
        stack.push(node);
        while(!stack.empty())
        {
            std::shared_ptr<Node<T>> processing_node=stack.top();
            std::cout << processing_node->value << " ";
            stack.pop();
            if(processing_node->right!=nullptr)
                stack.push(processing_node->right);
            if(processing_node->left!=nullptr)
                stack.push(processing_node->left);
        }
	}

	void inOrderRecursively(std::shared_ptr<Node<T>> node)
	{
		if (node != nullptr)
		{
			inOrderRecursively(node->left);
			std::cout << node->value << " ";
			inOrderRecursively(node->right);
		}
	}

    void inOrderIteratively(std::shared_ptr<Node<T>> node)
    {
//        std::stack<std::shared_ptr<Node<T>> > stack;
//        stack.push(node);
//        while(!stack.empty())
//        {
//            std::shared_ptr<Node<T>> processing_node=stack.top();
//            stack.pop();
//            if(processing_node->left!=nullptr)
//            {
//                stack.push(processing_node->left);
//                processing_node=processing_node->left;
//            }
//            processing_node=stack.top();
//            stack.pop();
//            std::cout << processing_node->value << " ";

//            if(processing_node->right!=nullptr)
//            {
//                stack.push(processing_node->right);

//            }
//        }
    }

	void levelOrderRecursively(std::shared_ptr<Node<T>> node)
	{
		if (node != nullptr)
		{
			if (node->left != nullptr)
				levelOrderQeue.push(node->left);
			if (node->right != nullptr)
				levelOrderQeue.push(node->right);


			if (!levelOrderQeue.empty())
			{
				node = levelOrderQeue.front();
				std::cout << node->value << " ";
				levelOrderQeue.pop();
				levelOrderRecursively(node);
			}

		}
	}

	void levelOrder(std::shared_ptr<Node<T>> node)
	{
		std::queue<std::shared_ptr<Node<T> > > queue;
		std::cout << node->value << " ";
		queue.push(node);

		while (!queue.empty())
		{
			node = queue.front();
			queue.pop();
			if (node->left != nullptr)
			{
				std::cout << node->left->value << " ";
				queue.push(node->left);
			}
			if (node->right != nullptr)
			{
				std::cout << node->right->value << " ";
				queue.push(node->right);
			}
        }std::cout << "\n";
	}

	void heightRecursively(std::shared_ptr<Node<T>> node)
	{
		//if (node != nullptr)
		//{
		//	current_height++;
		//	max_height = std::max(current_height, max_height);

		//	heightRecursively(node->left);
		//	heightRecursively(node->right);

		//}
		//current_height--;
	}

	int height(std::shared_ptr<Node<T>> node)
	{
		int x = 0, y = 0;
		if (node == nullptr)
			return 0;

		x = height(node->left);
		y = height(node->right);

		if (x > y)
			return x + 1;
		else
			return y + 1;
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

	std::cout << bst.getBalanceFactor(bst.root->right) << std::endl;

	bst.printTree();

    std::shared_ptr<BinarySearchTree<int>> tree=std::make_shared<BinarySearchTree<int>>(bst);
	std::cout << "Traversing Level Order" << std::endl;
	tree->levelOrder(tree->root);

	std::cout << "Traversing Level Order(Recursively)" << std::endl;
	tree->levelOrderRecursively(tree->root);
	std::cout << "\n";

	std::cout << "Traversing Pre-Order(Recursively)" << std::endl;
	tree->preOrderRecursively(tree->root);
	std::cout << "\n";

    std::cout << "Traversing Pre-Order(Iteratively)" << std::endl;
    tree->preOrderIteratively(tree->root);
    std::cout << "\n";


	std::cout << "Traversing In-Order(Recursively)" << std::endl;
	tree->inOrderRecursively(tree->root);
	std::cout << "\n";


    std::cout << "Traversing In-Order(Iteratively)" << std::endl;
    tree->inOrderIteratively(tree->root);
    std::cout << "\n";



	std::cout << "Traversing Post-Order(Recursively)" << std::endl;
	tree->postOrderRecursively(tree->root);
	std::cout << "\n";


	std::cout << "The height of the tree is:" << std::endl;
	std::cout << tree->height(tree->root) << std::endl;

	std::cout << "The height of the tree (Recursively) is:" << std::endl;
	tree->heightRecursively(tree->root);
	//std::cout << tree->max_height << std::endl;




    std::shared_ptr<BinarySearchTree<int>> tree2(new BinarySearchTree<int>);
    tree2->createTree();

}
