#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = nullptr;
    right = nullptr;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == nullptr) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }
  int depth, max_depth;
  Solution() {
    max_depth = 0;
    depth = 0;
  }
  void dfs(Node *root) {
    depth++;
    max_depth = std::max(max_depth, depth);
    // Write your code here.
    std::cout << root->data << std::endl;
    for (int i = 0; i < 1; i++) {
      if (root->left != nullptr)
        height(root->left);
      if (root->right != nullptr)
        height(root->right);
    }
    depth--;
  }
  int height(Node *root) {
    dfs(root);
    return max_depth - 1;
  }

}; // End of Solution

int main() {

  Solution myTree;
  Node *root = nullptr;

  int t;
  int data;

  //    std::cin >> t;

  //    while(t-- > 0) {
  //        std::cin >> data;
  //        root = myTree.insert(root, data);
  //    }

  for (auto data : {3, 2, 1, 4, 5, 6, 7})
    root = myTree.insert(root, data);

  int height = myTree.height(root);
  std::cout << height;

  return 0;
}
